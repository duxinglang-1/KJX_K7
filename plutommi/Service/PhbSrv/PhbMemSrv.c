/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *  PhbMemSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PHBMEMSRV_C
#define PHBMEMSRV_C


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "kal_release.h"
#include "custom_phb_config.h"
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "string.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */
/* Use U32 to be 4-byte aligned */
static U32 srv_phb_mem_pool[MMI_PHB_MEM_SIZE / 4];
static KAL_ADM_ID srv_phb_mem_id = NULL;
static S32 min_left_size = MMI_PHB_MEM_SIZE;

//#define PHB_MEM_DEBUG_ON

#ifdef PHB_MEM_DEBUG_ON
#include "FileMgrSrvGProt.h"
#include "kal_internal_api.h"

typedef struct
{
    void *ptr;
    U32 line;
    U32 size;
    U32 seq;
    CHAR filename[16];
} phb_mem_debug_record;

#define PHB_MEM_DEBUG_TBL_SIZE (1000)

static phb_mem_debug_record phb_mem_debug_tbl[PHB_MEM_DEBUG_TBL_SIZE];
static U32 g_phb_mem_debug_seq;
static U32 g_phb_mem_debug_count;
static MMI_BOOL g_phb_mem_on = MMI_TRUE;

#endif

/* Declare your local function here */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_mem_total_left_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_phb_mem_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 leftSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_mem_id != 0)
    {
        leftSize = (S32)kal_adm_get_total_left_size(srv_phb_mem_id);
    }
    return leftSize;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_mem_check_integrity
 * DESCRIPTION
 *  Allocates memory blocks.
 * PARAMETERS
 *  void
 *  size(?)     [IN]        The size of the (continuous) memory block to allocate.(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_mem_check_integrity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EXT_ASSERT(srv_phb_mem_id, 0, 0, 0);
 #ifdef PHB_MEM_CHECK_ON
    if (srv_phb_mem_id)
    {
        void *corrupted_mem_address = NULL;
        corrupted_mem_address = kal_adm_check_integrity(srv_phb_mem_id);
        if (corrupted_mem_address)
        {
            EXT_ASSERT(0, (int)corrupted_mem_address, (int)srv_phb_mem_total_left_size(), 0);
        }
    }
#endif /* PHB_MEM_CHECK_ON */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_mem_is_adm
 * DESCRIPTION
 * PARAMETERS
 *  address     [IN]        
 * RETURNS
 *****************************************************************************/
static MMI_BOOL srv_phb_mem_is_adm(U32 address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start = (U32)srv_phb_mem_pool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (address >= start && address <= start + sizeof(srv_phb_mem_pool))
    {
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_MEM_ADM, address);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_MEM_CTR, address);
        return MMI_FALSE;
    }
}

#ifdef PHB_MEM_DEBUG_ON
/*****************************************************************************
 * FUNCTION
 *  phb_mem_debug_find_rec
 * DESCRIPTION
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *****************************************************************************/
S32 phb_mem_debug_find_rec(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < PHB_MEM_DEBUG_TBL_SIZE; i++)
    {
        if (phb_mem_debug_tbl[i].ptr == ptr)
        {

            return i;
        }
    }
    return -1;
}




/*****************************************************************************
 * FUNCTION
 *  phb_mem_debug_add_rec
 * DESCRIPTION
 * PARAMETERS
 *  ptr             [?]         
 *  size            [IN]        
 *  filename        [IN]        
 *  line            [IN]        
 * RETURNS
 *****************************************************************************/
S32 phb_mem_debug_add_rec(void *ptr, kal_int32 size, const char *filename, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = phb_mem_debug_find_rec(NULL);

    if (index >= 0)
    {
        strncpy(phb_mem_debug_tbl[index].filename, filename, 15);
        phb_mem_debug_tbl[index].filename[15] = 0;
        phb_mem_debug_tbl[index].line = line;
        phb_mem_debug_tbl[index].ptr = ptr;
        phb_mem_debug_tbl[index].size = size;
        phb_mem_debug_tbl[index].seq = g_phb_mem_debug_seq++;
        g_phb_mem_debug_count++;
        return 0;
    }
    else
    {
        ASSERT(0);
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  phb_mem_debug_del_rec
 * DESCRIPTION
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *****************************************************************************/
S32 phb_mem_debug_del_rec(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = phb_mem_debug_find_rec(ptr);
    if (index >= 0)
    {
        memset(&phb_mem_debug_tbl[index], 0, sizeof(phb_mem_debug_record));
        g_phb_mem_debug_count--;
        return 0;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  phb_mem_debug_on
 * DESCRIPTION
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *****************************************************************************/
void srv_phb_mem_debug_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_mem_on)
    {
        g_phb_mem_on = MMI_FALSE;
    }
    else
    {
        g_phb_mem_on = MMI_TRUE;
    }
    g_phb_mem_debug_seq = 0;
    g_phb_mem_debug_count = 0;
    kal_prompt_trace(MOD_PHB, "[srvphb] g_phb_mem_on = %d", g_phb_mem_on);
}


/*****************************************************************************
 * FUNCTION
 *  phb_mem_debug_on
 * DESCRIPTION
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *****************************************************************************/
void srv_phb_mem_debug_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_mem_on)
    {
        S32 i;
        WCHAR Path[80];
        FS_HANDLE handle;
        U8 temp[100];
        S32 len;
        kal_wsprintf(Path, "%c:\\~phb_debug.temp", SRV_FMGR_PUBLIC_DRV);
        FS_Delete(Path);
        handle = FS_Open(Path, FS_CREATE | FS_READ_WRITE);
        len = sprintf(temp, "%s      %s      %s     %s \r\n", "seq", "size", "line", "file_name");
        FS_Write(handle, temp, len, &len);
        
        for (i = 0; i < PHB_MEM_DEBUG_TBL_SIZE; i++)
        {
            if (phb_mem_debug_tbl[i].ptr != NULL)
            {
                kal_prompt_trace(MOD_PHB, "[srvphb] mem print : file = %s, line = %d, size = %d, seq = %d",
                                phb_mem_debug_tbl[i].filename,
                                phb_mem_debug_tbl[i].line,
                                phb_mem_debug_tbl[i].size,
                                phb_mem_debug_tbl[i].seq);
                len = sprintf(temp, "%5d    %6d    %5d    %s \r\n",
                            phb_mem_debug_tbl[i].seq,
                            phb_mem_debug_tbl[i].size,
                            phb_mem_debug_tbl[i].line,
                            phb_mem_debug_tbl[i].filename);
                FS_Write(handle, temp, len, &len);
            }
        }
        FS_Close(handle);
    }
}

#endif /* PHB_MEM_DEBUG_ON */ 

#define EXTERNAL_FUNCTION
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_phb_mem_init
 * DESCRIPTION
 *  phonebook memory management init function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_MEM_INIT, MMI_PHB_MEM_SIZE);

    memset(srv_phb_mem_pool, 0, sizeof(srv_phb_mem_pool));

    srv_phb_mem_id = kal_adm_create(srv_phb_mem_pool, sizeof(srv_phb_mem_pool), NULL, KAL_FALSE);

    EXT_ASSERT(srv_phb_mem_id, 0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_mem_malloc
 * DESCRIPTION
 *  memory malloc function
 * PARAMETERS
 *  size                     : [IN]        buffer size to malloc
 *  type                     : [IN]        memory type
 * RETURNS
 *  void*
 * RETURN VALUES
 *  NULL               :          malloc fail
 *  other              :          buffer point
 *****************************************************************************/
void* srv_phb_mem_malloc_ext(S32 size, srv_phb_memory_type_enum type, const char* file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_MEM_MALLOC_MEM_ENTER, type, size);
    if (!size)
    {
        return NULL;
    }
    if (type == SRV_PHB_MEMORY_TYPE_CTR)
    {
        ptr = (kal_uint32*) get_ctrl_buffer_ext((kal_uint32)size, (kal_char*)file, (kal_uint32)line);
    }
    else
    {
        srv_phb_mem_check_integrity();
        ptr = (kal_uint32*) kal_adm_alloc(srv_phb_mem_id, (U32)size);
        
    #ifdef PHB_MEM_DEBUG_ON
        if (g_phb_mem_on)
        {
            phb_mem_debug_add_rec(ptr, size, basename((kal_char*) file), line);
        }
    #endif /* PHB_MEM_DEBUG_ON */ 
        if (ptr == NULL)
        {
        #ifdef PHB_MEM_DEBUG_ON
            srv_phb_mem_debug_print();
        #endif /* PHB_MEM_DEBUG_ON */ 
        
            if (srv_phb_mem_total_left_size() > size)
            {
                MMI_BOOL FRAGMENTATION = KAL_FALSE;

                kal_adm_print_log(srv_phb_mem_id);
                EXT_ASSERT(FRAGMENTATION, 0, 0, 0);  /* fragmentation */
            }
            else
            {
                MMI_BOOL OUT_OF_MEMORY = KAL_FALSE;

                kal_adm_print_log(srv_phb_mem_id);
                EXT_ASSERT(OUT_OF_MEMORY, 0, 0, 0);  /* out of memory */
            }
        }
        else
        {
            size = srv_phb_mem_total_left_size();
            if (size < min_left_size)
            {
                if (size < 0)
                {
                    /* should have memory corruption */
                    EXT_ASSERT(0, 0, 0, 0);
                }
                min_left_size = size;
                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_MEM_MIN_SIZE, min_left_size);
            }
        }
    }
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_MEM_MALLOC_MEM, ptr, size);

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_mem_free
 * DESCRIPTION
 *  memory free function
 * PARAMETERS
 *  memblock                   : [IN]        buffer point
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_mem_free_ext(void* memblock, const char* file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!memblock)
    {
        return;
    }
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_FREE_MEM, memblock);
    if (!srv_phb_mem_is_adm((U32)memblock))
    {
        free_ctrl_buffer_ext(memblock, (kal_char*)file, line);        
    }
    else
    {
        srv_phb_mem_check_integrity();
        kal_adm_free(srv_phb_mem_id, memblock);
        
    #ifdef PHB_MEM_DEBUG_ON
        if (g_phb_mem_on)
        {
            phb_mem_debug_del_rec(memblock);
        }
    #endif /* PHB_MEM_DEBUG_ON */ 
    }
}


#endif /* PHBMEMSRV_C */ 

