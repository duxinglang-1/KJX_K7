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
 * vmgettag.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * gettag
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__
#include "vmgettag.h"
#include "vmlog.h"
#include "vmsys.h"
#include <string.h>
#include "vmio.h"
#include "vmcert.h"
#include "vmstdlib.h"
#include "vmdl.h"
#include "vmmem.h"
#include "vmopt.h"
#include "vmpromnginner.h"

//#define __MMI_MRE_SWLA_DEBUG__

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_MRE_SWLA_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define MRE_SWLA_START(_symbol_)
#define MRE_SWLA_STOP(_symbol_)
#endif


#define BUFFER_SIZE	512
#define PADDINGLEN	10
#define TAG_LIST_SIZE 10

typedef struct sign_t{
    int tag_num;
    int size;
}sign_t;

typedef struct tag_list_t{
    void* tag_ptr;
    VMINT size;
	VMWSTR file_name;
}tag_list_t;

static tag_list_t tag_list[TAG_LIST_SIZE] = {0};

#ifdef WIN32
#define __packed
#endif


#define		MEM_SECURE_GAP 			2

VMINT vm_get_vm_tag_from_rom(VMUINT8* rom, int tag_num, void* buf , int* buf_size);
static VMINT vm_get_vm_tag_from_file(short* filename,int tag_num, void* buf ,int* buf_size);


static VMINT vm_get_multi_tags_from_file( short* filename, MULTI_TAG * tag_req );
static VMINT vm_get_multi_tags_from_rom( VMUINT8* rom, MULTI_TAG * tag_req );
    
static VMUCHAR * catch_tag_by_id( VMUCHAR * src, VMINT 	id, 	VMINT * len, VMINT src_len );

static VMINT vm_get_tag_by_id_rom(VMUINT8* rom, int tag_num, void* buf , int* buf_size, int lang_id );
static VMINT vm_get_tag_by_id_file(short* filename,int tag_num, void* buf ,int* buf_size, int lang_id );

static VMINT vm_get_vm_tag_by_id_internal( VMINT lang_id_ex, VMCHAR * buf_ex, VMINT * buf_size_ex );

extern VMINT SearchTagByID( VMINT tag, VMCHAR * tags_buf, VMCHAR ** tag_buf );

extern void vm_get_tag_deinit(VMINT handle);
extern VMINT vm_get_tag(VMINT handle, VMINT tag_num, void* buf ,VMINT* buf_size);
extern VMINT vm_get_tag_init_internal(short* filename, VMBOOL internal);

#ifdef __MRE_CORE_SM__
extern _vm_sm_t * _vm_sm_list_find(VMINT type, VMINT value);
#endif
extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);


/*****************************************************************************
 * FUNCTION
 *  vm_get_vm_tag_from_rom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rom             [?]         
 *  tag_num         [IN]        
 *  buf             [?]         
 *  buf_size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_vm_tag_from_rom(VMUINT8* rom, int tag_num, void* buf , int* buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8* tmp = rom;
    VMINT curr_tag = 0;
    VMINT tag_len = 0;

    const VMUINT8 exec_flag[] = {0xB4, 0x56, 0x44, 0x45, 0x30, 0x31};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tmp)
    {
        VMUINT8 *rom_head = rom + sizeof(VMUINT), *tag_head = NULL;
        VMUINT rom_size = (*(__packed VMUINT*)rom);
        VMINT cert_size = 0;
		VMUINT8 *type = NULL;
	
		type = rom_head + rom_size - 8;

		if(type == NULL)
		{
			return GET_TAG_ERROR;
		}
		else
		{
			if(*type == 1)
				cert_size = sizeof(MRECertHead_Ex);
			else
				cert_size = sizeof(MRECertHead);
		}
		
        if (rom_size <= cert_size + 6)
            return GET_TAG_NOT_FOUND;
        
        tmp = rom_head + rom_size - cert_size - 6;
        if(!memcmp(tmp, exec_flag, 6 ))
            return GET_TAG_ERROR;
        
        tag_head = rom_head + (*((__packed VMUINT*)(rom_head + rom_size - (sizeof(VMINT) + 8))));
        tmp = tag_head;

        while (tmp + 8 <= (rom_head + rom_size - cert_size - 6))
        {
            curr_tag = *(__packed VMINT*)tmp;
            tmp += sizeof(int);
            
            tag_len = *(__packed VMINT*)tmp;
            tmp += sizeof(int);

            if( tmp + tag_len > rom + rom_size )
                return GET_TAG_ERROR;
            
            if (tag_len <= 0)
            {
                if (curr_tag == VM_CE_INFO_END)
                    return GET_TAG_NOT_FOUND;
                else if (tag_len < 0)
                {
                    return GET_TAG_ERROR;
                }
            }

            if (curr_tag == tag_num)
            {
                if (buf)
                {
                    if (!buf_size)
                        return GET_TAG_ERROR;	

                    if (*buf_size < tag_len)
                        return GET_TAG_INSUFFICIENT_BUF;
                        
                    memcpy(buf, tmp, tag_len);
                    return GET_TAG_TRUE;
                }
                else
                {
                    if (!buf_size)
                        return GET_TAG_ERROR;
                        
                    *buf_size = tag_len;
                    return GET_TAG_TRUE;
                }	
            }
            
            tmp += tag_len;
        }
    }

    return GET_TAG_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_vm_tag_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]         
 *  tag_num         [IN]        
 *  buf             [?]         
 *  buf_size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_get_vm_tag_from_file(short* filename,int tag_num, void* buf ,int* buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( buf_size == NULL )
        return GET_TAG_ERROR;

	if(tag_list[0].file_name != NULL)
	{
		if(wstrcmp(tag_list[0].file_name, filename) == 0)
		{
			return vm_get_tag(0, tag_num, buf, buf_size);
		}
		else
		{
			vm_get_tag_deinit(0);
		}
	}

	ret = vm_get_tag_init_internal(filename, TRUE);
		
	if( ret>= 0)
	{
		return vm_get_tag(0, tag_num, buf, buf_size);
	}
	else
	{
		return GET_TAG_ERROR;
	}
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_vm_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]         
 *  tag_num         [IN]        
 *  buf             [?]         
 *  buf_size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_vm_tag(short* filename,int tag_num, void* buf ,int* buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8* rom_data = NULL;
    VMINT ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M40");
    if ((rom_data = vm_get_execrom_ptr(filename)) != NULL)
    {
        ret = vm_get_vm_tag_from_rom(rom_data - 4, tag_num, buf, buf_size);
    }
    else
    {
        ret = vm_get_vm_tag_from_file(filename, tag_num, buf, buf_size);
    }
    MRE_SWLA_STOP("M40");
	  MMI_TRACE(MMI_MRE_TRC_MOD_VMGETTAG, TRC_MRE_VMGETTAG_01, tag_num, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_multi_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     
 *  tag_req         [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_multi_tags( short* filename,   MULTI_TAG * tag_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8* 	rom_data = NULL;
    VMINT ret = -1;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M41");
    if ((rom_data = vm_get_execrom_ptr(filename)) != NULL)
    {        
        ret = vm_get_multi_tags_from_rom(rom_data - 4, tag_req );
    }
    else
    {   
        ret = vm_get_multi_tags_from_file(filename, tag_req );
    }
    MRE_SWLA_STOP("M41");
	MMI_TRACE(MMI_MRE_TRC_MOD_VMGETTAG, TRC_MRE_VMGETTAG_02, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_multi_tags_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     
 *  tag_req         [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_get_multi_tags_from_file( short* filename, MULTI_TAG * tag_req )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMFILE	file;
    
    VMINT		offset = 0, i = 0;
    VMUINT		file_size = 0;	
    VMCHAR 		tag_flag[CERT_HEAD_LEN+1];
    VMINT pos;
    
    VMUINT		nread = 0;

    VMUCHAR * 	tags_buf = NULL;
	VMUINT8 type = 0;
	VMINT cert_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( filename == NULL || tag_req == NULL || (vm_wstrlen(filename) == 0) )
        return GET_TAG_ERROR;
    
    
    if ((file = vm_file_open(filename, MODE_READ, TRUE)) >= 0) 
    {

        if( vm_file_getfilesize( file, &file_size ) != 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;		
        }
    
        memset( tag_flag, 0x00, CERT_HEAD_LEN+1 );
		
        if( vm_file_seek(file,-8,BASE_END) != 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;				
        }
		
        if( vm_file_read(file, &type, 1, &nread ) == 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;				
        }

		if(type == 1)
			cert_size = sizeof(MRECertHead_Ex);
		else
			cert_size = sizeof(MRECertHead);

        pos = cert_size + CERT_HEAD_LEN;
		
        if( vm_file_seek(file,-(pos),BASE_END) != 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;				
        }
        
        if( vm_file_read(file, tag_flag, CERT_HEAD_LEN, &nread ) == 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;				
        }
        
        if( memcmp( tag_flag, "\xB4VDE10", CERT_HEAD_LEN ) )
        {            
            vm_file_close(file);
            return GET_TAG_ERROR;
        }
        pos = sizeof(VMINT)+RESERVED_BYTES_NUM;
        if( vm_file_seek(file,-(pos),BASE_END) != 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;				
        }
        
        if( vm_file_read(file, (VMCHAR *)&offset, sizeof(VMINT), &nread ) == 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;				
        }

        if( offset < 0 || (VMINT)file_size-offset < 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;				
        }			

        if( vm_file_seek(file, offset, BASE_BEGIN ) != 0 )
        {
            vm_file_close(file);
            return GET_TAG_ERROR;				
        }			

        tags_buf = (VMUCHAR *)vm_malloc( file_size - offset );
        if( tags_buf == NULL )
        {
            vm_file_close( file );
            return GET_TAG_ERROR;
        }
        
        memset( tags_buf, 0x00, file_size-offset );
        if( vm_file_read( file, tags_buf, file_size-offset, &nread ) == 0 )
        {
            vm_free( tags_buf );
            tags_buf = NULL;

            vm_file_close( file );

            return GET_TAG_ERROR;			
        }
        else
        {
            if( nread != (file_size-offset) )
            {
                vm_free( tags_buf );
                tags_buf = NULL;

                vm_file_close( file );

                return GET_TAG_ERROR;			
            }	
        }
    }
    else
        return GET_TAG_FILE_ERROR;

    vm_file_close( file );

    i = 0;
    while( i<MULTI_TAG_MAX &&  tag_req->tag_id[i] )
    {
        tag_req->tag_content[i] = catch_tag_by_id( tags_buf, tag_req->tag_id[i], &tag_req->tag_len[i], file_size-offset );

        i++;
    }

    vm_free( tags_buf );
    tags_buf = NULL;	
    
    return GET_TAG_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_multi_tags_from_rom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rom         [?]     
 *  tag_req     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_get_multi_tags_from_rom( VMUINT8* rom, MULTI_TAG * tag_req )
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8* tmp = rom;
    VMINT  i = 0;
    VMUINT8 *rom_head = NULL, *tag_head = NULL;
    VMUINT rom_size = NULL, temp_len = 0;	

    const VMUINT8 exec_flag[] = {0xB4, 0x56, 0x44, 0x45, 0x30, 0x31};
	VMINT cert_size = 0;
	VMUINT8 *type = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( rom == NULL || tag_req == NULL )
        return GET_TAG_ERROR;
        
    rom_head = rom + sizeof(VMUINT);
	
    memcpy( (VMUCHAR *)&rom_size, rom, sizeof(VMUINT) );

	type = rom_head + rom_size - 8;
	
	if(type == NULL)
	{
		return GET_TAG_ERROR;
	}
	else
	{
		if(*type == 1)
			cert_size = sizeof(MRECertHead_Ex);
		else
			cert_size = sizeof(MRECertHead);
	}

	
    if (rom_size <= cert_size + CERT_HEAD_LEN)
        return GET_TAG_NOT_FOUND;
    
    tmp = rom_head + rom_size - cert_size - CERT_HEAD_LEN;
	
    if(!memcmp(tmp, exec_flag, CERT_HEAD_LEN ))
        return GET_TAG_ERROR;
    
    memcpy( (VMUCHAR *)&temp_len, rom_head + rom_size - (sizeof(VMINT) + RESERVED_BYTES_NUM), sizeof(VMUINT) );
    //tag_head = rom_head + (*((VMUINT*)(rom_head + rom_size - (sizeof(VMINT) + RESERVED_BYTES_NUM))));
    tag_head = rom_head + temp_len;
    tmp = tag_head;

    if( tag_head < rom_head )
        return GET_TAG_ERROR;		

    i = 0;
    while( i<MULTI_TAG_MAX && tag_req->tag_id[i])
    {
        tag_req->tag_content[i] = catch_tag_by_id( tmp, tag_req->tag_id[i], &tag_req->tag_len[i], rom_size -(tag_head - rom_head) );
        i++;
    }
    
    return GET_TAG_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  catch_tag_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [?]         
 *  id          [IN]        
 *  len         [?]         
 *  src_len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMUCHAR * catch_tag_by_id( VMUCHAR * src, VMINT 	id, 	VMINT * len, VMINT src_len )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT		tag, tag_len;
    VMINT		pos = 0;
//	VMINT 		res_code = 0;

    VMUCHAR * 		dest = NULL;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( src == NULL || len == NULL )
        return NULL;

    *(len) = 0;

    memcpy( (VMUCHAR *)&tag, src+pos, sizeof(VMINT) );
    pos += sizeof(VMINT);
	
    while( tag )
    {        
        memcpy( (VMUCHAR *)&tag_len, src+pos, sizeof(VMINT) );
        pos += sizeof(VMINT);

        if( pos + tag_len > src_len )
            return NULL;
        
        if( tag == id )
        {
            dest = (VMUCHAR *)vm_malloc( tag_len + MEM_SECURE_GAP  );
            if( dest == NULL )
                return NULL;
            else
            {            
                memset( dest, 0x00, tag_len+MEM_SECURE_GAP );
                memcpy( dest, src+pos, tag_len );

                *(len) = tag_len;

                return dest;
            }
        }
        else
        {
            if( tag != VM_CE_INFO_PAY )
                pos += tag_len;
        }

        tag = 0;
        tag_len = 0;
        memcpy( (VMUCHAR *)&tag, src+pos, sizeof(VMINT) );
        pos += sizeof(VMINT);
        
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_tag_by_lang_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]         
 *  tag_num         [IN]        
 *  buf             [?]         
 *  buf_size        [?]         
 *  lang_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_tag_by_lang_id( short* filename, int tag_num, void* buf, int* buf_size, int lang_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8* rom_data = NULL;
    VMINT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M42");
    if( tag_num < VM_CE_INFO_LIST_START || tag_num > VM_CE_INFO_LIST_END )
        return GET_TAG_NOT_A_LIST_TAG;

    if ((rom_data = vm_get_execrom_ptr(filename)) != NULL)
    {
        ret = vm_get_tag_by_id_rom(rom_data - 4, tag_num, buf, buf_size, lang_id );
    }
    else
    {
        ret = vm_get_tag_by_id_file(filename, tag_num, buf, buf_size, lang_id );
    }	
    MRE_SWLA_STOP("M42");
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_tag_by_id_rom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rom             [?]         
 *  tag_num         [IN]        
 *  buf             [?]         
 *  buf_size        [?]         
 *  lang_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_get_tag_by_id_rom(VMUINT8* rom, int tag_num, void* buf , int* buf_size, int lang_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT			buf_size_tag = *buf_size;
    VMINT			result = GET_TAG_TRUE;
//	VMCHAR *	str_buf = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VMCHAR *     str_buf = NULL; */

    /* get the tag */
    result = vm_get_vm_tag_from_rom( rom, tag_num, buf, &buf_size_tag );
    if( result != GET_TAG_TRUE )
        return result;
        
    if( buf == NULL && buf_size_tag )
    {
        *buf_size = buf_size_tag;
        
        return result;
    }
    
    return vm_get_vm_tag_by_id_internal( lang_id, buf, buf_size );
        
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_tag_by_id_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]         
 *  tag_num         [IN]        
 *  buf             [?]         
 *  buf_size        [?]         
 *  lang_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_get_tag_by_id_file(short* filename,int tag_num, void* buf ,int* buf_size, int lang_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT			buf_size_tag = *buf_size;
    VMINT			result = GET_TAG_TRUE;
//	VMCHAR *	str_buf = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VMCHAR *     str_buf = NULL; */

    /* get the tag */
    result = vm_get_vm_tag_from_file( filename, tag_num, buf, &buf_size_tag );
    if( result != GET_TAG_TRUE )
        return result;
        
    if( buf == NULL && buf_size_tag )
    {
        *buf_size = buf_size_tag;
        
        return result;
    }
    
    return vm_get_vm_tag_by_id_internal( lang_id, buf, buf_size );	
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_vm_tag_by_id_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang_id_ex      [IN]        
 *  buf_ex          [?]         
 *  buf_size_ex     [?]         
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_get_vm_tag_by_id_internal( VMINT lang_id_ex, VMCHAR * buf_ex, VMINT * buf_size_ex )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT			lang_len = 0;
    VMCHAR *	str_buf = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the content by ID */
    lang_len = SearchTagByID( lang_id_ex, buf_ex, &str_buf );
    if( str_buf && lang_len )
    {
        VMCHAR *		lang_buf = NULL;
        
        lang_buf = (VMCHAR *)vm_malloc( lang_len + 4 );
        if( lang_buf == NULL )
            return GET_TAG_INSUFFICIENT_BUF;

        //catch the dest string		
        memset( lang_buf, 0x00, lang_len+4 );	
        memcpy( lang_buf, str_buf, lang_len );
        
        //move the dest string	
        memset( buf_ex, 0x00, *buf_size_ex );
        memcpy( buf_ex, lang_buf, lang_len );
        
        *buf_size_ex = lang_len;
        
        vm_free( lang_buf );
        
        return GET_TAG_TRUE;
    }
    else
        return GET_TAG_LANG_NOT_FOUND;	
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_multi_tags_by_lang_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]         
 *  tag_req         [?]         
 *  lang_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_multi_tags_by_lang_id( short* filename, MULTI_TAG * tag_req, int lang_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT					i = 0, j = 0;
    MULTI_TAG *		tag_temp = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tag_temp = (MULTI_TAG *)vm_malloc( sizeof(MULTI_TAG) );
    if( tag_temp == NULL )
        return GET_TAG_INSUFFICIENT_BUF;
    
    //catch the tags
    if( vm_get_multi_tags( filename, tag_temp ) == GET_TAG_ERROR )
        return GET_TAG_ERROR;
    
    for( i=0, j=0; i<MULTI_TAG_MAX; i++ )
    {
        VMINT			tag_id = tag_temp->tag_id[i], tag_len_cur = tag_temp->tag_len[i];
        VMCHAR *	tag_content_cur = (VMCHAR *)tag_temp->tag_content[i];
        
        if( (tag_id >= VM_CE_INFO_LIST_START) && (tag_id <= VM_CE_INFO_LIST_END) && tag_len_cur && tag_content_cur )
        {
            VMINT		content_size = 0;

            tag_req->tag_id[j] = tag_id;
            tag_req->tag_len[j] = tag_temp->tag_len[j];
            tag_req->tag_content[j] = tag_temp->tag_content[j];			
            
            content_size = tag_req->tag_len[j];
            
            vm_get_vm_tag_by_id_internal( lang_id, (VMCHAR *)tag_req->tag_content[j], &content_size );
            
            if( tag_req->tag_content[j] == NULL )
            {
                tag_req->tag_id[j] = VM_CE_INFO_END;
                tag_req->tag_len[j] = 0;
                tag_req->tag_content[j] = NULL;							
            }
            else
            {
                tag_req->tag_len[j] = content_size;
                j++;
            }
        }
        
        if( tag_content_cur )
            vm_free( tag_content_cur );		
    }
    
    vm_free( tag_temp );
    
    if( j==0 )
        return GET_TAG_LANG_NOT_FOUND;
    
    return GET_TAG_TRUE;
}

VMINT vm_get_tag(VMINT handle, VMINT tag_num, void* buf ,VMINT* buf_size)
{
	VMUINT8* tmp;
    VMINT curr_tag = 0;
    VMINT tag_len = 0;
	VMUINT8* end;
	
	if((handle < 0)||(handle >= TAG_LIST_SIZE))
	{
		buf = NULL;
		*buf_size = 0;
		return GET_TAG_ERROR;
	}

	tmp = tag_list[handle].tag_ptr;
	end = (VMUINT8*)tag_list[handle].tag_ptr + tag_list[handle].size;
	
	while (tmp + 8 <= end)
    {
        curr_tag = *(__packed VMINT*)tmp;
        tmp += sizeof(int);
        
        tag_len = *(__packed VMINT*)tmp;
        tmp += sizeof(int);

        if( tmp + tag_len > end )
            return GET_TAG_ERROR;
        
        if (tag_len <= 0)
        {
            if (curr_tag == VM_CE_INFO_END)
                return GET_TAG_NOT_FOUND;
            else if (tag_len < 0)
            {
                return GET_TAG_ERROR;
            }
        }

        if (curr_tag == tag_num)
        {
            if (buf)
            {
                if (!buf_size)
                    return GET_TAG_ERROR;	

                if (*buf_size < tag_len)
                    return GET_TAG_INSUFFICIENT_BUF;
                    
                memcpy(buf, tmp, tag_len);
                return GET_TAG_TRUE;
            }
            else
            {
                if (!buf_size)
                    return GET_TAG_ERROR;
                    
                *buf_size = tag_len;
                return GET_TAG_TRUE;
            }	
        }
        
        tmp += tag_len;
    }
	return GET_TAG_ERROR;
}


static VMINT vm_get_tag_init_internal(short* filename, VMBOOL internal)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	VMFILE	file;
	VMINT		offset = 0;
	VMUINT		file_size = 0;	
	VMINT		pos;
	VMCHAR		tag_flag[7];
	VMINT		tag = VM_CE_INFO_END;
	VMINT		res_code = GET_TAG_ERROR;
	VMUINT		nread = 0, tag_buffer_pos = 0;
	VMCHAR	*	tag_buffer = NULL;
	VMINT i;
	VMINT cert_size = 0;
	VMUINT8 type = 0;
		
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if ((file = vm_file_open(filename, MODE_READ, TRUE)) >= 0) 
	{
	
		if( vm_file_seek(file,-12,BASE_END) == 0 )
		{
			if( vm_file_read(file, (VMCHAR *)&offset, sizeof(VMINT), &nread ) == 0)
			{
				vm_file_close( file );
				return	GET_TAG_CACHE_ERROR;
			}
		}
		else
		{
			vm_file_close( file );
			return	GET_TAG_CACHE_ERROR;
		}
		
		if( vm_file_getfilesize( file, &file_size ) == 0 )
		{
			
			if(file_size>offset)
			{
				tag_buffer = (VMCHAR *)_vm_kernel_malloc( file_size-offset );

				if( tag_buffer != NULL )
				{
					memset( tag_buffer, 0x00, file_size-offset );
					
					if( vm_file_seek(file, offset, BASE_BEGIN ) != 0 )
					{
						vm_file_close( file );
						return GET_TAG_CACHE_ERROR;
					}
					
					if( vm_file_read( file, tag_buffer, file_size-offset, &nread ) == 0 )
					{
						memset( tag_buffer, 0x00, file_size-offset );

						_vm_kernel_free( tag_buffer );
						tag_buffer = NULL;	
					}
					else
					{
						if( nread != (file_size-offset) )
						{
							memset( tag_buffer, 0x00, file_size-offset );
							_vm_kernel_free( tag_buffer );
							tag_buffer = NULL;
						}
						else
						{
							VMUINT8 type = tag_buffer[file_size - offset - 8];
							
							if(type == 1)
								cert_size = sizeof(MRECertHead_Ex);
							else
								cert_size = sizeof(MRECertHead);

							pos = cert_size + 6;
							
							if( memcmp( &tag_buffer[file_size - offset - pos], "\xB4VDE10", 6 ) )
							{
								vm_file_close(file);
								_vm_kernel_free( tag_buffer );
								return GET_TAG_CACHE_ERROR;
							}	

							memset( &tag_buffer[file_size - offset - pos], 0x00, pos );

							tag_buffer_pos = 0;
						}
					}
				}
			}

		}
		else
		{
			vm_file_close( file );
			return GET_TAG_CACHE_ERROR;
		}
	}
	else
	{
		return GET_TAG_FILE_ERROR;
	}
	
	vm_file_close( file );

	if(tag_buffer != NULL)
	{
		if(internal)
		{
			tag_list[0].tag_ptr = tag_buffer;
			tag_list[0].size = file_size-offset-cert_size;
			tag_list[0].file_name = (VMWSTR)_vm_kernel_calloc(MAX_APP_NAME_LEN * 2);

		if(tag_list[0].file_name != NULL)
		{
			wstrcpy(tag_list[0].file_name,filename);
		}

		return 0;
	}
	
	for(i=1; i<TAG_LIST_SIZE; i++)
	{
		if(tag_list[i].tag_ptr == NULL)
		{
			tag_list[i].tag_ptr = tag_buffer;
			tag_list[i].size = file_size-offset-cert_size;
			tag_list[i].file_name = NULL;
			break;
		}
	}

	if(i == TAG_LIST_SIZE)
	{
			return GET_TAG_CACHE_ERROR;
		}
		else
		{
			return i;
		}
	}

	return GET_TAG_CACHE_ERROR;
}

VMINT vm_get_tag_init(short* filename)
{
	return vm_get_tag_init_internal(filename, FALSE);
}

void vm_get_tag_deinit(VMINT handle)
{
	if(handle >= 0)
	{
		tag_list[handle].size = 0;
		
		if(tag_list[handle].tag_ptr != NULL)
		{
			_vm_kernel_free(tag_list[handle].tag_ptr);
			tag_list[handle].tag_ptr = NULL;
		}
		
		if( tag_list[handle].file_name != NULL )
		{	
			_vm_kernel_free(tag_list[handle].file_name);
			tag_list[handle].file_name = NULL;
		}
	}
}



VMINT vm_get_curr_app_cert_id(void)
{
	
	VMINT currAppR9 = vm_get_running_app_sb();
	_vm_pcb_t* pcb = NULL;
	VMINT cert_id = -1;
	VMINT buf_size = 4;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) == NULL)
	{
#ifdef __MRE_CORE_SM__
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr)
		{
			vm_get_vm_tag(sm_ptr->fullFileName,VM_CE_INFO_CERT_ID,&cert_id, &buf_size);
		}
#endif
	}
	else
	{
		vm_get_vm_tag(pcb->fullFileName,VM_CE_INFO_CERT_ID,&cert_id, &buf_size);
	}
	
	MMI_TRACE(MMI_MRE_TRC_MOD_VMGETTAG, TRC_MRE_VMGETTAG_03, cert_id);

	return cert_id;
}

void* vm_get_vm_tag_ptr_and_size(VMWSTR filename, VMINT* tag_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(tag_list[0].file_name == NULL)
	{
		vm_get_tag_init_internal(filename, TRUE);
	}
	else if(wstrcmp(tag_list[0].file_name, filename) != 0)
	{
		vm_get_tag_deinit(0);
		vm_get_tag_init_internal(filename, TRUE);
	}
	
	*tag_size = tag_list[0].size - 6;
	return tag_list[0].tag_ptr;
}


#endif /* __MRE_CORE_BASE__ */

