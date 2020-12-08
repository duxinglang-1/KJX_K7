/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   pmg_fs.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for Push storage operations.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "msf_cfg.h"
//#include "msf_core.h"
#include "msf_int.h"
#include "msf_mem.h"
//#include "msf_dcvt.h"
#include "msf_log.h"
//#include "msf_pipe.h"
#include "msf_file.h"
//#include "msf_chrs.h"
//#include "msf_errc.h"
#include "msf_def.h"

#include "pmg_if.h"
#include "pmg_fs.h"
#include "pmg_main.h"
#include "pmg_msg.h"

//suggested add

   // #include "wps_trc.h"
    #include "pmg_struct.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"
    #include "string.h"

#define PMG_FS_PATH                 "/pmg"
#define PMG_FS_MSG_FILENAME         "/pmg/msg.dat"
#define PMG_FS_BLOCK_HEADER_SIZE 5
/*
 * size of a standard message without info-item
 * * 4*4 = 4 * 4 bytes data
 * * 6*1 = 6 * 1 byte data
 * * 5 = zero-terminate for 5 strings
 * * 5*2 = 5 * 2 bytes string length
 * * 2 = 1 * 2 bytes info-items count
 */
#define PMG_FS_MAX_STD_MSG_SIZE     ((4*4) +                  \
                                     (6*1) +                  \
                                     PMG_MAX_MSG_SIID_CHARS + \
                                     PMG_MAX_MSG_TEXT_CHARS + \
                                     PMG_MAX_ADDR_CHARS +     \
                                     PMG_MAX_ADDR_CHARS +     \
                                     PMG_MAX_MSG_HREF_CHARS + \
                                     PMG_FS_BLOCK_HEADER_SIZE +                      \
                                     (5*2) +                  \
                                     2)
#define PMG_FS_MSG_FILE_INIT_SIZE   (PMG_FS_MAX_STD_MSG_SIZE * 8)

#define PMG_FS_MSG_FILE_INCREMENT_SIZE  PMG_FS_MAX_STD_MSG_SIZE

#define PMG_FS_FREE_BLOCK   0xFF
#define PMG_FS_USED_BLOCK   0xBB

typedef void (*pfBlockProc) (void *blockData, long blockOffset, long blockSize);

#define PMG_FS_PACK_DATA(type, srcData, ptrBuffer) do { \
    if (ptrBuffer) {                                    \
      memcpy(*ptrBuffer, &srcData, sizeof(type));       \
      (*ptrBuffer) += sizeof(type);                     \
    }                                                   \
    return sizeof(type);                                \
  } while (0)

#define PMG_FS_UNPACK_DATA(type, outputData, ptrSrcBuffer) do { \
    memcpy(outputData, *ptrSrcBuffer, sizeof(type));            \
    (*ptrSrcBuffer) += sizeof(type);                            \
  } while (0)

typedef struct pmg_fs_block_st
{
    struct pmg_fs_block_st *prev;
    struct pmg_fs_block_st *next;
    long offset;
    long size;
} pmg_fs_block_t;

typedef struct pmg_fs_context_st
{
    int pmg_fs_msg_file;
    pmg_fs_block_t *pmg_fs_msg_free_blocks;
    pmg_fs_block_t *pmg_fs_msg_used_blocks;
}pmg_fs_context_t;

static pmg_fs_context_t g_pmg_fs_cntx = {0};

static void pmg_fs_reset_file(int fileHandle);
static void pmg_fs_parse_blocks(int fileHandle, pfBlockProc func);

extern int HDIa_fileOpenExt(MSF_UINT8 modId, MSF_BOOL isBlocking, const char *fileName, int mode, long size);

/*****************************************************************************
 * FUNCTION
 *  pmg_fs_init
 * DESCRIPTION
 *  initialise PMG's filesystem component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_fs_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MSF_FILE_MKDIR(PMG_FS_PATH);

    g_pmg_fs_cntx.pmg_fs_msg_free_blocks = 0;
    g_pmg_fs_cntx.pmg_fs_msg_used_blocks = 0;
    g_pmg_fs_cntx.pmg_fs_msg_file = 0;

    pmg_init_done(PMG_INIT_FS);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_open
 * DESCRIPTION
 *  open the push message data file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_fs_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MSF_FILE_EXIST(PMG_FS_MSG_FILENAME) <= 0)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_FS_E3CE7448F0E4F97EB399ED9E70262B44,
                           "PMG: message file doesnt exist, create new file\n"));
#ifdef OBIGO_Q03C
        g_pmg_fs_cntx.pmg_fs_msg_file = MSF_FILE_OPEN(
                            MSF_MODID_PMG,                        
                            PMG_FS_MSG_FILENAME,
                            MSF_FILE_SET_CREATE | MSF_FILE_SET_RDWR | HDI_FILE_SET_CUSTOM_BLOCKING,
                            PMG_FS_MSG_FILE_INIT_SIZE);
#else /* this is for Q05A */
       g_pmg_fs_cntx.pmg_fs_msg_file = MSF_FILE_OPEN_EXT(
                            MSF_MODID_PMG,
                            TRUE,
                            PMG_FS_MSG_FILENAME,
                            MSF_FILE_SET_CREATE | MSF_FILE_SET_RDWR,
                            PMG_FS_MSG_FILE_INIT_SIZE);
#endif /* OBIGO_Q03C */
        pmg_fs_reset_file(g_pmg_fs_cntx.pmg_fs_msg_file);
    }
    else
    {
#ifdef OBIGO_Q03C
        g_pmg_fs_cntx.pmg_fs_msg_file = MSF_FILE_OPEN(
                            MSF_MODID_PMG,
                            PMG_FS_MSG_FILENAME,
                            MSF_FILE_SET_RDWR | HDI_FILE_SET_CUSTOM_BLOCKING,
                            PMG_FS_MSG_FILE_INIT_SIZE);
#else  /* this is for Q05A */
       g_pmg_fs_cntx.pmg_fs_msg_file = MSF_FILE_OPEN_EXT(
                            MSF_MODID_PMG,
                            TRUE,
                            PMG_FS_MSG_FILENAME,
                            MSF_FILE_SET_RDWR,
                            PMG_FS_MSG_FILE_INIT_SIZE);
#endif /* OBIGO_Q03C */    
    }
    pmg_fs_parse_blocks(g_pmg_fs_cntx.pmg_fs_msg_file, pmg_msg_parse_msg_file_block);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_reset_file
 * DESCRIPTION
 *  reset push message data file
 * PARAMETERS
 *  fileHandle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_fs_reset_file(int fileHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long blockSize;
    char freeBlock = (char)PMG_FS_FREE_BLOCK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calc allowable size */
    blockSize = MSF_FILE_SEEK(fileHandle, 0, MSF_FILE_SEEK_END);
    blockSize = blockSize - PMG_FS_BLOCK_HEADER_SIZE;   /* 1 header, 1 block len */

    /* write header */
    MSF_FILE_SEEK(fileHandle, 0, MSF_FILE_SEEK_SET);
    MSF_FILE_WRITE(fileHandle, (void*)&freeBlock, 1);
    MSF_FILE_WRITE(fileHandle, (void*)&blockSize, sizeof(long));
    MSF_FILE_FLUSH(fileHandle);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_add_block_to_list
 * DESCRIPTION
 *  add a block to list of file blocks
 * PARAMETERS
 *  head        [IN]        
 *  offset      [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_fs_add_block_to_list(pmg_fs_block_t **head, long offset, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* size = size of usable data in block, excluding headers */
    pmg_fs_block_t *crtBlock;
    pmg_fs_block_t *newBlock = pmg_mem_alloc(sizeof(pmg_fs_block_t));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newBlock->offset = offset;
    newBlock->size = size;

    if (!*head)
    {
        newBlock->prev = 0;
        newBlock->next = 0;
        *head = newBlock;
    }
    else
    {
        crtBlock = *head;
        while (crtBlock->next && crtBlock->offset < newBlock->offset)
            crtBlock = crtBlock->next;

        if (!(crtBlock->next) && crtBlock->offset < newBlock->offset)
        {
            crtBlock->next = newBlock;
            newBlock->prev = crtBlock;
            newBlock->next = 0;
            return;
        }

        newBlock->prev = crtBlock->prev;
        newBlock->next = crtBlock;
        if (crtBlock->prev)
            crtBlock->prev->next = newBlock;
        else
            *head = newBlock;
        crtBlock->prev = newBlock;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_remove_block_from_list
 * DESCRIPTION
 *  remove block from list of file blocks
 * PARAMETERS
 *  head        [IN]        
 *  block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_fs_remove_block_from_list(pmg_fs_block_t **head, pmg_fs_block_t *block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (block->prev)
        block->prev->next = block->next;
    if (block->next)
        block->next->prev = block->prev;

    if (block == *head)
    {
        if (block->next)
            *head = block->next;
        else
            *head = 0;
    }

    block->prev = 0;
    block->next = 0;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_find_block
 * DESCRIPTION
 *  find a block from list of file blocks
 * PARAMETERS
 *  head        [IN]        
 *  offset      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pmg_fs_block_t *pmg_fs_find_block(pmg_fs_block_t **head, long offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_block_t *crtBlock;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    crtBlock = *head;
    while (crtBlock)
    {
        if (crtBlock->offset == offset)
            return crtBlock;
        crtBlock = crtBlock->next;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_find_min_fit_free_block
 * DESCRIPTION
 *  find a smallest file block that is greater than the specified size
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pmg_fs_block_t *pmg_fs_find_min_fit_free_block(long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_block_t *crtBlock;
    pmg_fs_block_t *suitedBlock;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    suitedBlock = 0;
    crtBlock = g_pmg_fs_cntx.pmg_fs_msg_free_blocks;
    while (crtBlock)
    {
        if (crtBlock->size > size && (!suitedBlock || suitedBlock->size > crtBlock->size))
            suitedBlock = crtBlock;
        crtBlock = crtBlock->next;
    }
    return suitedBlock;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_parse_blocks
 * DESCRIPTION
 *  parse blocks from files with the specified block processing function
 * PARAMETERS
 *  fileHandle      [IN]        
 *  func            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_fs_parse_blocks(int fileHandle, pfBlockProc func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long blockOffset;
    long blockSize = 0;
    char blockType;
    void *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    blockOffset = 0;
    while (MSF_FILE_SEEK(fileHandle, blockOffset, MSF_FILE_SEEK_SET) >= 0)
    {
        if (MSF_FILE_READ(fileHandle, &blockType, 1) < 0)
            break;

        if (blockType != (char)PMG_FS_FREE_BLOCK && blockType != (char)PMG_FS_USED_BLOCK)
        {
            MSF_FILE_CLOSE(fileHandle);
            MSF_FILE_REMOVE(PMG_FS_MSG_FILENAME);
            ASSERT(0);
        }

        MSF_FILE_READ(fileHandle, &blockSize, sizeof(long));
	    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG,
                   PMG_PHS_REQ_FILE_SIZE, "PMG: Requested File Size: %d", (MSF_INT32)blockSize));
    
		if (blockSize == 0)
		{
			//kal_wap_trace(MOD_WAP, TRACE_INFO, (S8*) "PMG: [pmg_fs_parse_blocks] file content is invalid = %d", 1);
			break;
		}

        if (blockType == (char)PMG_FS_USED_BLOCK)
        {
            pmg_fs_add_block_to_list(&g_pmg_fs_cntx.pmg_fs_msg_used_blocks, blockOffset, blockSize);

            data = pmg_mem_alloc(blockSize);
            MSF_FILE_READ(fileHandle, data, blockSize);

            func(data, blockOffset, blockSize);
            PMG_MEM_FREE(data);
        }
        else
        {
            pmg_fs_add_block_to_list(&g_pmg_fs_cntx.pmg_fs_msg_free_blocks, blockOffset, blockSize);
        }

        blockOffset += blockSize + PMG_FS_BLOCK_HEADER_SIZE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_pack_int
 * DESCRIPTION
 *  encode "int" data
 * PARAMETERS
 *  data            [IN]        
 *  ptrBuffer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int pmg_fs_pack_int(int data, char **ptrBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_FS_PACK_DATA(int, data, ptrBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_unpack_int
 * DESCRIPTION
 *  decode "int" data
 * PARAMETERS
 *  ptrSrcBuffer        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int pmg_fs_unpack_int(char **ptrSrcBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_FS_UNPACK_DATA(int, &tmp, ptrSrcBuffer);

    return tmp;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_pack_uint32
 * DESCRIPTION
 *  encode "unsigned int" data
 * PARAMETERS
 *  data            [IN]        
 *  ptrBuffer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MSF_UINT32 pmg_fs_pack_uint32(MSF_UINT32 data, char **ptrBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_FS_PACK_DATA(MSF_UINT32, data, ptrBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_unpack_uint32
 * DESCRIPTION
 *  decode "unsigned int" data
 * PARAMETERS
 *  ptrSrcBuffer        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MSF_UINT32 pmg_fs_unpack_uint32(char **ptrSrcBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_FS_UNPACK_DATA(MSF_UINT32, &tmp, ptrSrcBuffer);
    return tmp;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_pack_uint16
 * DESCRIPTION
 *  encode "unsigned short" data
 * PARAMETERS
 *  data            [IN]        
 *  ptrBuffer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int pmg_fs_pack_uint16(MSF_UINT16 data, char **ptrBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_FS_PACK_DATA(MSF_UINT16, data, ptrBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_unpack_uint16
 * DESCRIPTION
 *  decode "unsigned short" data
 * PARAMETERS
 *  ptrSrcBuffer        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MSF_UINT16 pmg_fs_unpack_uint16(char **ptrSrcBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT16 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_FS_UNPACK_DATA(MSF_UINT16, &tmp, ptrSrcBuffer);
    return tmp;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_pack_uint8
 * DESCRIPTION
 *  encode "unsigned char" data
 * PARAMETERS
 *  data            [IN]        
 *  ptrBuffer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int pmg_fs_pack_uint8(MSF_UINT8 data, char **ptrBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_FS_PACK_DATA(MSF_UINT8, data, ptrBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_unpack_uint8
 * DESCRIPTION
 *  decode "unsigned char" data
 * PARAMETERS
 *  ptrSrcBuffer        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MSF_UINT8 pmg_fs_unpack_uint8(char **ptrSrcBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_FS_UNPACK_DATA(MSF_UINT8, &tmp, ptrSrcBuffer);
    return tmp;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_pack_string
 * DESCRIPTION
 *  encode "string" data
 * PARAMETERS
 *  data            [?]         
 *  ptrBuffer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int pmg_fs_pack_string(char *data, char **ptrBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = (data ? strlen(data) : 0);
    if (ptrBuffer)
    {
        pmg_fs_pack_uint16((MSF_UINT16) len, ptrBuffer);

        if (len)
        {
            memcpy(*ptrBuffer, data, len);
            (*ptrBuffer) += len;
        }
    }
    return len + sizeof(MSF_UINT16);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_unpack_string
 * DESCRIPTION
 *  decode "string" data
 * PARAMETERS
 *  ptrSrcBuffer        [IN]        
 *  outputStrLen        [?]         
 * RETURNS
 *  
 *****************************************************************************/
static char *pmg_fs_unpack_string(char **ptrSrcBuffer, int *outputStrLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    char *str = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = (int)pmg_fs_unpack_uint16(ptrSrcBuffer);
    if (len)
    {
        str = pmg_mem_alloc((len + 1) * sizeof(char));
        memset(str, 0, (len + 1) * sizeof(char));
        memcpy(str, *ptrSrcBuffer, len);
        (*ptrSrcBuffer) += len;
    }

    if (outputStrLen)
        *outputStrLen = len;

    return str;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_pack_infoitems
 * DESCRIPTION
 *  encode "info items" data
 * PARAMETERS
 *  numInfoItems        [IN]        
 *  head                [?]         
 *  ptrBuffer           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int pmg_fs_pack_infoitems(int numInfoItems, pmg_fs_msg_file_infoitem_t *head, char **ptrBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int infoLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infoLen += pmg_fs_pack_uint16((MSF_UINT16) numInfoItems, ptrBuffer);
    while (head)
    {
        infoLen += pmg_fs_pack_string(head->infoClass, ptrBuffer);
        infoLen += pmg_fs_pack_string(head->infoText, ptrBuffer);

        head = head->next;
    }
    return infoLen;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_unpack_infoitems
 * DESCRIPTION
 *  decode "info items" data
 * PARAMETERS
 *  ptrSrcBuffer            [IN]        
 *  outputNumInfoItems      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static pmg_fs_msg_file_infoitem_t *pmg_fs_unpack_infoitems(char **ptrSrcBuffer, int *outputNumInfoItems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int numInfoItems;
    pmg_fs_msg_file_infoitem_t *head = 0;
    pmg_fs_msg_file_infoitem_t *last = 0;
    pmg_fs_msg_file_infoitem_t *crt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numInfoItems = (int)pmg_fs_unpack_uint16(ptrSrcBuffer);
    if (outputNumInfoItems)
        *outputNumInfoItems = numInfoItems;

    while ((numInfoItems -= 1) >= 0)
    {
        crt = pmg_mem_alloc(sizeof(pmg_fs_msg_file_infoitem_t));
	memset(crt, 0, sizeof(pmg_fs_msg_file_infoitem_t));
        crt->infoClass = pmg_fs_unpack_string(ptrSrcBuffer, 0);
        crt->infoText = pmg_fs_unpack_string(ptrSrcBuffer, 0);

        crt->next = 0;
        if (!head)
        {
            head = last = crt;
        }
        else
            last->next = crt;
    }

    return head;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_release_infoitem
 * DESCRIPTION
 *  release a "info items" entry
 * PARAMETERS
 *  infoitem        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_fs_release_infoitem(pmg_fs_msg_file_infoitem_t *infoitem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PMG_MEM_FREE(infoitem->infoClass);
    PMG_MEM_FREE(infoitem->infoText);
    PMG_MEM_FREE(infoitem);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_release_infoitems
 * DESCRIPTION
 *  release list of "info items"
 * PARAMETERS
 *  head        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_fs_release_infoitems(pmg_fs_msg_file_infoitem_t *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_msg_file_infoitem_t *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (head)
    {
        tmp = head->next;
        pmg_fs_release_infoitem(head);
        head = tmp;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_pack_msg_data
 * DESCRIPTION
 *  encode "message" data
 * PARAMETERS
 *  data            [?]         
 *  ptrBuffer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int pmg_fs_pack_msg_data(pmg_fs_msg_file_data_t *data, char **ptrBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = 0;
    size += pmg_fs_pack_int(data->msgID, ptrBuffer);
    size += pmg_fs_pack_uint32(data->created, ptrBuffer);
    size += pmg_fs_pack_uint32(data->expired, ptrBuffer);
    size += pmg_fs_pack_uint32(data->arrived, ptrBuffer);
	size += pmg_fs_pack_uint32(data->sim_id, ptrBuffer);
    size += pmg_fs_pack_uint8(data->msgType, ptrBuffer);
    size += pmg_fs_pack_uint8(data->priority, ptrBuffer);
    size += pmg_fs_pack_uint8(data->read, ptrBuffer);

    size += pmg_fs_pack_uint8(data->smscType, ptrBuffer);
    size += pmg_fs_pack_uint8(data->fromType, ptrBuffer);

    size += pmg_fs_pack_string(data->siid, ptrBuffer);
    size += pmg_fs_pack_string(data->text, ptrBuffer);
    size += pmg_fs_pack_string(data->smsc, ptrBuffer);
    size += pmg_fs_pack_string(data->from, ptrBuffer);
    size += pmg_fs_pack_string(data->href, ptrBuffer);

    size += pmg_fs_pack_infoitems(data->numInfoItems, data->infoitems, ptrBuffer);

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_unpack_msg_data
 * DESCRIPTION
 *  decode "message" data
 * PARAMETERS
 *  ptrSrcBuffer        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pmg_fs_msg_file_data_t *pmg_fs_unpack_msg_data(char **ptrSrcBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_msg_file_data_t *msgData;
    int numInfoItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgData = pmg_mem_alloc(sizeof(pmg_fs_msg_file_data_t));
    memset(msgData, 0, sizeof(pmg_fs_msg_file_data_t));
    msgData->msgID = pmg_fs_unpack_int(ptrSrcBuffer);
    msgData->created = pmg_fs_unpack_uint32(ptrSrcBuffer);
    msgData->expired = pmg_fs_unpack_uint32(ptrSrcBuffer);
    msgData->arrived = pmg_fs_unpack_uint32(ptrSrcBuffer);
	msgData->sim_id =  pmg_fs_unpack_uint32(ptrSrcBuffer);
    msgData->msgType = pmg_fs_unpack_uint8(ptrSrcBuffer);
    msgData->priority = pmg_fs_unpack_uint8(ptrSrcBuffer);
    msgData->read = pmg_fs_unpack_uint8(ptrSrcBuffer);
  
    msgData->smscType = pmg_fs_unpack_uint8(ptrSrcBuffer);
    msgData->fromType = pmg_fs_unpack_uint8(ptrSrcBuffer);

    msgData->siid = pmg_fs_unpack_string(ptrSrcBuffer, 0);
    msgData->text = pmg_fs_unpack_string(ptrSrcBuffer, 0);
    msgData->smsc = pmg_fs_unpack_string(ptrSrcBuffer, 0);
    msgData->from = pmg_fs_unpack_string(ptrSrcBuffer, 0);
    msgData->href = pmg_fs_unpack_string(ptrSrcBuffer, 0);

    msgData->infoitems = pmg_fs_unpack_infoitems(ptrSrcBuffer, &numInfoItems);
    msgData->numInfoItems = (char)numInfoItems;

    return msgData;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_release_msg_data
 * DESCRIPTION
 *  release message data
 * PARAMETERS
 *  msgData     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_fs_release_msg_data(pmg_fs_msg_file_data_t *msgData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgData->siid)
        PMG_MEM_FREE(msgData->siid);
    if (msgData->text)
        PMG_MEM_FREE(msgData->text);
    if (msgData->smsc)
        PMG_MEM_FREE(msgData->smsc);
    if (msgData->from)
        PMG_MEM_FREE(msgData->from);
    if (msgData->href)
        PMG_MEM_FREE(msgData->href);
    pmg_fs_release_infoitems(msgData->infoitems);
    PMG_MEM_FREE(msgData);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_merge_free_blocks
 * DESCRIPTION
 *  merge neighbouring free blocks together
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_fs_merge_free_blocks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_block_t *block;
    pmg_fs_block_t *tmp;
    int fileHandle = g_pmg_fs_cntx.pmg_fs_msg_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    block = g_pmg_fs_cntx.pmg_fs_msg_free_blocks;
    while (block && block->next)
    {
        if (block->offset + block->size + PMG_FS_BLOCK_HEADER_SIZE == block->next->offset)
        {
            tmp = block->next;
            pmg_fs_remove_block_from_list(&g_pmg_fs_cntx.pmg_fs_msg_free_blocks, tmp);

            block->size = block->size + tmp->size + PMG_FS_BLOCK_HEADER_SIZE;  /* 5=headers in deleted block */
            MSF_FILE_SEEK(fileHandle, block->offset + 1, MSF_FILE_SEEK_SET);
            MSF_FILE_WRITE(fileHandle, (void*)&(block->size), sizeof(long));

            PMG_MEM_FREE(tmp);
            continue;
        }
        block = block->next;
    }
    MSF_FILE_FLUSH(fileHandle);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_erase_data
 * DESCRIPTION
 *  remove data from file at specified block offset
 * PARAMETERS
 *  offset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_fs_erase_data(long offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_block_t *block;
    int fileHandle = g_pmg_fs_cntx.pmg_fs_msg_file;
    char freeBlock = (char)PMG_FS_FREE_BLOCK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    block = pmg_fs_find_block(&g_pmg_fs_cntx.pmg_fs_msg_used_blocks, offset);
    if (block)
    {
        pmg_fs_remove_block_from_list(&g_pmg_fs_cntx.pmg_fs_msg_used_blocks, block);
        pmg_fs_add_block_to_list(&g_pmg_fs_cntx.pmg_fs_msg_free_blocks, block->offset, block->size);
        PMG_MEM_FREE(block);

        MSF_FILE_SEEK(fileHandle, offset, MSF_FILE_SEEK_SET);
        MSF_FILE_WRITE(fileHandle, (void*)&freeBlock, 1);

        pmg_fs_merge_free_blocks();
    }
    MSF_FILE_FLUSH(fileHandle);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_extend_file
 * DESCRIPTION
 *  extend file buffer size
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static long pmg_fs_extend_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fileHandle = g_pmg_fs_cntx.pmg_fs_msg_file;
    long oldsize;
    long newblocksize;
    char freeBlock = (char)PMG_FS_FREE_BLOCK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    oldsize = MSF_FILE_SEEK(fileHandle, 0, MSF_FILE_SEEK_END);

    MSF_FILE_SEEK(fileHandle, 0, MSF_FILE_SEEK_SET);
    if (MSF_FILE_SEEK(fileHandle, oldsize + PMG_FS_MSG_FILE_INCREMENT_SIZE, MSF_FILE_SEEK_SET) < HDI_FILE_OK)
    {
        return 0;
    }
    MSF_FILE_SEEK(fileHandle, 0, MSF_FILE_SEEK_SET);

    //if (MSF_FILE_SETSIZE(fileHandle, PMG_FS_MSG_FILE_INCREMENT_SIZE) == -1)
        //return 0;
    MSF_FILE_FLUSH(fileHandle);

    newblocksize = MSF_FILE_SEEK(fileHandle, 0, MSF_FILE_SEEK_END) - oldsize - PMG_FS_BLOCK_HEADER_SIZE;
    pmg_fs_add_block_to_list(&g_pmg_fs_cntx.pmg_fs_msg_free_blocks, oldsize, newblocksize);

    MSF_FILE_SEEK(fileHandle, oldsize, MSF_FILE_SEEK_SET);
    MSF_FILE_WRITE(fileHandle, (void*)&freeBlock, 1);
    MSF_FILE_WRITE(fileHandle, (void*)&newblocksize, sizeof(long));

    pmg_fs_merge_free_blocks();
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_write_data_to_disk
 * DESCRIPTION
 *  write raw data to disk
 * PARAMETERS
 *  offset      [IN]        
 *  data        [?]         
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static long pmg_fs_write_data_to_disk(long offset, void *data, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * offset: -1 = create new entry
     * * func returns new offset regardless whether an offset has been specified
     * *      returns -1 if not enough space in file
     */
    int fileHandle = g_pmg_fs_cntx.pmg_fs_msg_file;
    char freeBlock = (char)PMG_FS_FREE_BLOCK;
    char usedBlock = (char)PMG_FS_USED_BLOCK;
    pmg_fs_block_t *block;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_FS_32F21C8137553813D925CBFFE017C9D0,
                      "PMG: pmg_fs_write_data_to_disk(offset:%d, size:%d)\n", offset, size));

    /* delete old data on file */
    if (offset != -1)
        pmg_fs_erase_data(offset);

    /* write data to file */
    while ((block = pmg_fs_find_min_fit_free_block(size)) == 0)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_FS_9D86DA6226D4C4ED0D519A7C64C93459,
                          "PMG: pmg_fs_write_data_to_disk(offset:%d,size:%d) unable to find block with sufficient size\n",
                          offset, size));
        if (!pmg_fs_extend_file())
            return -1;
    }

    /* detach free block from list  */
    pmg_fs_remove_block_from_list(&g_pmg_fs_cntx.pmg_fs_msg_free_blocks, block);

    if (fileHandle <= 0)
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_FS_A53C1763A996ED1FADF0966AC23EFB86,
                          "PMG: pmg_fs_write_data_to_disk() Invalid filehandle(%d)!\n", fileHandle));

    /* put unused free block back to free list */
    if (block->size - PMG_FS_BLOCK_HEADER_SIZE > size)
    {
        long newOffset = block->offset + PMG_FS_BLOCK_HEADER_SIZE + size;
        long newSize = block->size - size - PMG_FS_BLOCK_HEADER_SIZE;

        MSF_FILE_SEEK(fileHandle, newOffset, MSF_FILE_SEEK_SET);
        MSF_FILE_WRITE(fileHandle, (void*)&freeBlock, 1);
        MSF_FILE_WRITE(fileHandle, (void*)&newSize, sizeof(long));

        pmg_fs_add_block_to_list(&g_pmg_fs_cntx.pmg_fs_msg_free_blocks, newOffset, newSize);
        block->size = size;
    }

    /* write new data to file */
    MSF_FILE_SEEK(fileHandle, block->offset, MSF_FILE_SEEK_SET);
    MSF_FILE_WRITE(fileHandle, (void*)&usedBlock, 1);
    MSF_FILE_WRITE(fileHandle, (void*)&block->size, sizeof(long));
    MSF_FILE_WRITE(fileHandle, (void*)data, size);

    pmg_fs_add_block_to_list(&g_pmg_fs_cntx.pmg_fs_msg_used_blocks, block->offset, block->size);

    MSF_FILE_FLUSH(fileHandle);
    offset = block->offset;
    PMG_MEM_FREE(block);
    return offset;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_write_msg_data
 * DESCRIPTION
 *  write message data to disk
 * PARAMETERS
 *  offset      [IN / OUT]        
 *  msgData     [?]         
 * RETURNS
 *  size
 *****************************************************************************/
long pmg_fs_write_msg_data(long *offset, pmg_fs_msg_file_data_t *msgData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * offset: -1 = create new entry
     * * func returns new offset regardless whether an offset has been specified
     * *      returns -1 if not enough space in file
     */
    long size;
    char *buffer;
    char *ptrBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* data packing */
    size = (long)pmg_fs_pack_msg_data(msgData, 0);
    buffer = pmg_mem_alloc(size);
    memset(buffer, 0, (int)size);

    ptrBuffer = buffer;
    pmg_fs_pack_msg_data(msgData, &ptrBuffer);
    *offset = pmg_fs_write_data_to_disk(*offset, (void*)buffer, size);

    PMG_MEM_FREE(buffer);
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_fs_read_raw_data
 * DESCRIPTION
 *  read raw data from file at specified block offset
 * PARAMETERS
 *  offset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *pmg_fs_read_raw_data(long offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_block_t *block;
    int fileHandle = g_pmg_fs_cntx.pmg_fs_msg_file;
    void *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    block = pmg_fs_find_block(&g_pmg_fs_cntx.pmg_fs_msg_used_blocks, offset);
    if (!block)
        return 0;

    data = pmg_mem_alloc(block->size);
    memset(data, 0, block->size);
    MSF_FILE_SEEK(fileHandle, offset + PMG_FS_BLOCK_HEADER_SIZE, MSF_FILE_SEEK_SET);
    MSF_FILE_READ(fileHandle, data, block->size);

    return data;
}

