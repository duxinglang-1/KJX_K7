/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   wap_cmmn_utils.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains common utility functions for WAP solutions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "wps_struct.h"
#include "das_struct.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "string.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "stack_msgs.h"

/*****************************************************************************
 * FUNCTION
 *  wap_prepare_root_folder
 * DESCRIPTION
 *  This function is to prepare the root folder for WAP solutions. If the folder
 *  exists but is not for the calling solution, it is deleted and recreated.
 * CALLS
 *  
 * PARAMETERS
 *  path           [IN]        WAP root folder path (length < 120)
 *  identifier     [IN]        string to identify the solution
 * RETURNS
 *  1 if the folder is created, 0 if nothing has been changed.
 *****************************************************************************/
int wap_prepare_root_folder(const WCHAR* path, const char *identifier)
{
    FS_HANDLE handle;
    char tmpsz[16] = "";
    WCHAR buf[128];
    UINT bytes;
    int ret;

    ASSERT(kal_wstrlen(path) < 120);
    ASSERT(strlen(identifier) < 16);

    /* Check if the folder exists or not */
    if (FS_GetAttributes(path) >= 0)
    {
        /* Folder exists, check whether the id file exists */
        memset(buf, 0, 128 * sizeof(WCHAR));
        kal_wstrcat(buf, path);
        kal_wstrcat(buf, (const WCHAR*)L"\\idz");

        if (FS_GetAttributes(buf) >= 0)
        {
            /* File exists, read the identifier in it */
            handle = FS_Open((const WCHAR*)buf, FS_OPEN_SHARED | FS_READ_ONLY);
            
            EXT_ASSERT(handle >= 0, handle, 0, 0);
            
            ret = FS_Read(handle, tmpsz, 16, &bytes);

            EXT_ASSERT(ret == FS_NO_ERROR, ret, 0, 0);

            FS_Close(handle);

            if(strcmp((const char *)tmpsz, identifier) == 0)
            {
#if 0
/* under construction !*/
/* under construction !*/
#else
                memset(buf, 0, 128 * sizeof(WCHAR));
                kal_wstrcat(buf, path);
                kal_wstrcat(buf, (const WCHAR*)L"\\msm");
                if (FS_GetAttributes(buf) >= 0)
                {
                    return 0;
                }
                else
                {
                    return 2;
                }
#endif
            }
        }
        goto RMDIR;
    }
    goto MKDIR;
      
RMDIR:
    /* Remove the folder sicne it's not for the current solution */
    FS_XDelete(path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);

MKDIR:
    /* Create the root folder */
    ret = FS_CreateDir(path);

    EXT_ASSERT(ret == FS_NO_ERROR, ret, 0, 0); 

    memset(buf, 0, 128 * sizeof(WCHAR));
    kal_wstrcat(buf, path);
    kal_wstrcat(buf, (const WCHAR*)L"\\idz");

    /* Create the identifier file here, and write the identifier */
    handle = FS_Open((const WCHAR*)buf, FS_CREATE | FS_READ_WRITE);
    
    EXT_ASSERT(handle >= 0, handle, 0, 0);
    
    ret = FS_Write(handle, (void *)identifier, strlen(identifier), &bytes);

    EXT_ASSERT(ret == FS_NO_ERROR, ret, 0, 0);

    FS_Close(handle);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  wps_pun_uint32
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op      [IN]        
 *  buf     [?]         
 *  p       [?]         
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 wps_pun_uint32(kal_uint8 op, kal_uint8 *buf, kal_uint32 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op)
    {
        case WPS_PUN_PACK:
            buf[0] = ((*p >> 24) & 0xff);
            buf[1] = ((*p >> 16) & 0xff);
            buf[2] = ((*p >> 8) & 0xff);
            buf[3] = *p & 0xff;
            break;
        case WPS_PUN_UNPACK:
            *p = (buf[0] << 24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];
            break;
    }
    return 4;
}


/*****************************************************************************
 * FUNCTION
 *  wps_pun_string
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op      [IN]        
 *  buf     [?]         
 *  p       [IN]        
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 wps_pun_string(kal_uint8 op, kal_uint8 *buf, kal_uint8 **p, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len == 0)
    {
        return 0;
    }

    switch (op)
    {
        case WPS_PUN_PACK:
            memcpy(buf, *p, len);
            break;
        case WPS_PUN_UNPACK:
            *p = buf;
            break;
    }
    return len;
}

/*****************************************************************************
 * FUNCTION
 *  wps_pun_string_array
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op      [IN]        
 *  buf     [?]         
 *  p       [IN]        
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 wps_pun_string_array(kal_uint8 op, kal_uint8 *buf, kal_uint8 *p, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len == 0)
    {
        return 0;
    }

    switch (op)
    {
        case WPS_PUN_PACK:
            memcpy(buf, p, len);
            break;
        case WPS_PUN_UNPACK:
            memcpy(p,buf, len);
             break;
    }
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  wps_pun_content
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op      [IN]        
 *  buf     [?]         
 *  p       [IN]        
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 wps_pun_content(kal_uint8 op, kal_uint8 *buf, wps_content_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int32 pos = 0;
	wps_content_t *c = (wps_content_t*)p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op)
    {
        case WPS_PUN_PACK:
				case WPS_PUN_UNPACK:
	    pos += wps_pun_uint32(op, buf + pos, &(c->contentTypelen));
            pos += wps_pun_string_array(op, buf + pos, c->contentType, c->contentTypelen);
	    pos += wps_pun_uint32(op, buf + pos, &(c->namelen));
	    pos += wps_pun_string_array(op, buf + pos, c->name, c->namelen);
	    pos += wps_pun_uint32(op, buf + pos, &(c->fileNamelen));
	    pos += wps_pun_string_array(op, buf + pos, c->fileName, c->fileNamelen);
						pos += wps_pun_uint32(op, buf + pos, &(c->charset));
						pos += wps_pun_uint32(op, buf + pos, &(c->dataType));
	    pos += wps_pun_uint32(op, buf + pos, &(c->dataLen));
	    pos += wps_pun_uint32(op, buf + pos, &(c->filepathNamelen));
	    pos += wps_pun_string_array(op, buf + pos, (kal_uint8 *)c->filepathName, c->filepathNamelen);
            break;
        case WPS_PUN_SIZE:
            pos += c->contentTypelen + c->namelen + c->fileNamelen +  c->filepathNamelen + sizeof(kal_uint32) + sizeof(kal_uint32) + sizeof(kal_uint32) 
                  + sizeof(kal_uint32) + sizeof(kal_uint32) + sizeof(kal_uint32) + sizeof(kal_uint32);
            break;
    }
    return pos;
}

/*****************************************************************************
 * FUNCTION
 *  wps_pun_multipart_content
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op      [IN]        
 *  buf     [?]         
 *  p       [IN]        
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 wps_pun_content_array(kal_uint8 op, kal_uint8 *buf, wps_content_t *p, kal_uint32 num_entires)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i, pos = 0;
	wps_content_t *c = (wps_content_t*)p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0; i<num_entires; i++)
    {
	    switch (op)
	    {
	        case WPS_PUN_PACK:
	        case WPS_PUN_SIZE:
	        case WPS_PUN_UNPACK:
	        	pos += wps_pun_content(op, buf + pos, &c[i]);
	        	break;
	    }
	  }
    return pos;
}



/*****************************************************************************
 * FUNCTION
 *  wps_pun_var_part
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  op          [IN]        
 *  msg_id      [IN]        
 *  p           [?]         
 *  buf         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 wps_pun_var_part(kal_uint8 op, kal_uint32 msg_id, void *p, kal_uint8 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_ID_WPS_SET_CHANNEL_REQ:
        {
            wps_set_channel_req_var_struct *v = (wps_set_channel_req_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->static_header_len));
                    pos += wps_pun_string(op, buf + pos, &(v->static_header), v->static_header_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->static_header_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_HTTP_REQ:
        {
            wps_http_req_var_struct *v = (wps_http_req_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->request_header_len));
                    pos += wps_pun_string(op, buf + pos, &(v->request_header), v->request_header_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->request_url_len));
                    pos += wps_pun_string(op, buf + pos, &(v->request_url), v->request_url_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->post_segment_len));
                    pos += wps_pun_string(op, buf + pos, &(v->post_segment), v->post_segment_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->num_entries));
		    pos += wps_pun_content_array(op, buf + pos, v->content, v->num_entries);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->request_header_len;
                    pos += sizeof(kal_uint32) + v->request_url_len;
                    pos += sizeof(kal_uint32) + v->post_segment_len;
                    pos += sizeof(kal_uint32) + wps_pun_content_array(op, buf + pos, v->content, v->num_entries);
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_HTTP_RSP:
        {
            wps_http_rsp_var_struct *v = (wps_http_rsp_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->new_url_len));
                    pos += wps_pun_string(op, buf + pos, &(v->new_url), v->new_url_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->reply_header_len));
                    pos += wps_pun_string(op, buf + pos, &(v->reply_header), v->reply_header_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->reply_segment_len));
                    pos += wps_pun_string(op, buf + pos, &(v->reply_segment), v->reply_segment_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->new_url_len;
                    pos += sizeof(kal_uint32) + v->reply_header_len;
                    pos += sizeof(kal_uint32) + v->reply_segment_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_var_struct *v = (wps_read_content_rsp_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->reply_segment_len));
                    pos += wps_pun_string(op, buf + pos, &(v->reply_segment), v->reply_segment_len);
                    break;
                case WPS_PUN_SIZE:
                    pos = sizeof(kal_uint32) + v->reply_segment_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_POST_CONTENT_RES:
        {
            wps_post_content_res_var_struct *v = (wps_post_content_res_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->post_segment_len));
                    pos += wps_pun_string(op, buf + pos, &(v->post_segment), v->post_segment_len);
                    break;
                case WPS_PUN_SIZE:
                    pos = sizeof(kal_uint32) + v->post_segment_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_CLEAR_REQ:
        {
            wps_clear_req_var_struct *v = (wps_clear_req_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf, &(v->cache_url_len));
                    pos += wps_pun_string(op, buf + pos, &(v->cache_url), v->cache_url_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->cache_url_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WAP_MMI_FILE_DL_IND:
        {
            wap_mmi_file_dl_var_struct *v = (wap_mmi_file_dl_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf + pos, &(v->header_len));
                    pos += wps_pun_string(op, buf + pos, &(v->header), v->header_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->content_len));
                    pos += wps_pun_string(op, buf + pos, &(v->content), v->content_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->header_len;
                    pos += sizeof(kal_uint32) + v->content_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        case MSG_ID_WPS_HTTP_AUTH_INFO:
        {
            wps_http_auth_info_var_struct *v = (wps_http_auth_info_var_struct*) p;

            switch (op)
            {
                case WPS_PUN_PACK:
                case WPS_PUN_UNPACK:
                    pos += wps_pun_uint32(op, buf + pos, &(v->url_len));
                    pos += wps_pun_string(op, buf + pos, &(v->url), v->url_len);
                    pos += wps_pun_uint32(op, buf+ pos, &(v->realm_len));
                    pos += wps_pun_string(op, buf + pos, &(v->realm), v->realm_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->username_len));
                    pos += wps_pun_string(op, buf + pos, &(v->username), v->username_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->password_len));
                    pos += wps_pun_string(op, buf + pos, &(v->password), v->password_len);
                    pos += wps_pun_uint32(op, buf+ pos, &(v->nonce_len));
                    pos += wps_pun_string(op, buf + pos, &(v->nonce), v->nonce_len);
                    pos += wps_pun_uint32(op, buf + pos, &(v->opaque_len));
                    pos += wps_pun_string(op, buf + pos, &(v->opaque), v->opaque_len);                    
                    pos += wps_pun_uint32(op, buf + pos, &(v->algorithm_len));
                    pos += wps_pun_string(op, buf + pos, &(v->algorithm), v->algorithm_len);
                    pos += wps_pun_uint32(op, buf+ pos, &(v->qop_len));
                    pos += wps_pun_string(op, buf + pos, &(v->qop), v->qop_len);
                    break;
                case WPS_PUN_SIZE:
                    pos += sizeof(kal_uint32) + v->url_len;
                    pos += sizeof(kal_uint32) + v->realm_len;
                    pos += sizeof(kal_uint32) + v->username_len;
                    pos += sizeof(kal_uint32) + v->password_len;
                    pos += sizeof(kal_uint32) + v->nonce_len;
                    pos += sizeof(kal_uint32) + v->opaque_len;
                    pos += sizeof(kal_uint32) + v->algorithm_len;
                    pos += sizeof(kal_uint32) + v->qop_len;
                    break;
                default:
                    return 0;
            }
            break;
        }
        
	case MSG_ID_WPS_SET_COOKIE_REQ:
	{
		wps_set_cookie_req_var_struct *v = (wps_set_cookie_req_var_struct*) p;
	
		switch (op)
		{
			case WPS_PUN_PACK:
			case WPS_PUN_UNPACK:
				pos += wps_pun_uint32(op, buf + pos, &(v->url_len));
				pos += wps_pun_string(op, buf + pos, &(v->url), v->url_len);
				pos += wps_pun_uint32(op, buf+ pos, &(v->name_len));
				pos += wps_pun_string(op, buf + pos, &(v->name), v->name_len);
				pos += wps_pun_uint32(op, buf + pos, &(v->value_len));
				pos += wps_pun_string(op, buf + pos, &(v->value), v->value_len);
				pos += wps_pun_uint32(op, buf + pos, &(v->domain_len));
				pos += wps_pun_string(op, buf + pos, &(v->domain), v->domain_len);
				pos += wps_pun_uint32(op, buf+ pos, &(v->path_len));
				pos += wps_pun_string(op, buf + pos, &(v->path), v->path_len);
				break;
			case WPS_PUN_SIZE:
				pos += sizeof(kal_uint32) + v->url_len;
				pos += sizeof(kal_uint32) + v->name_len;
				pos += sizeof(kal_uint32) + v->value_len;
				pos += sizeof(kal_uint32) + v->domain_len;
				pos += sizeof(kal_uint32) + v->path_len;
				break;
                         default:
                                return 0;
                  } 
                  break;
            }        
    }
    return pos;
}


