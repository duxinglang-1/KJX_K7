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
 * mma_um.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions which are used by Unified MMS application, Unified Message and Unified Message Composer.
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
 * removed!
 * removed!
 * removed!
 *
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
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_UM_C
#define _MMA_UM_C

#include "mmi_platform.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "custom_wap_config.h"
#include "stack_ltlcom.h"

#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "mms_api.h"
#include "mma_api.h"
#include "mmsadp.h"
#include "wapadp.h"
#include "app_str.h"
#include "conversions.h"

/* DRM */
#include "drm_def.h"
#include "drm_gprot.h"
/* PlutoMMI */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_features.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"

#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"



/* APPLIB */
#include "app_mine.h"
#include "WguiCategoryGprot.h"
#ifdef __MMI_MMS_IN_UM__
//#include "UMGProt.h"
#include "UmSrvGprot.h"
#endif 

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
//#include "UCMGProt.h" 
#include "UcmSrvGprot.h"
#endif

#include "UcAppGprot.h"
#include "MmsSrvGprot.h"
#include "UcSrvGprot.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGProt.h"
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __WIFI_SUPPORT__
/* WLAN includes */
#include "NetworkSetupDefs.h"
#endif /* __WIFI_SUPPORT__ */ 

#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
#include "wapprofileSrvgprot.h"
#include "WAPProfileSrvType.h"
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_cmmn.h"   /* MSF: MSF common functions, e.g. string handling */
#include "msf_pipe.h"   /* MSF: Pipe handling */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_chrs.h"   /* MSF: Charset handling */

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "stk_if.h"     /* STK: WSP/HTTP Stack signals and types */
#else
#include "nts_if.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#include "mms_cfg.h"    /* MMS: Configuration definitions */
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_if.h"     /* MMS: Exported signal interface */
#include "mconfig.h"
#include "msig.h"
#include "mmem.h"
#include "mmsl_if.h"
#include "fldmgr.h"

#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"

/* MMA services */
#include "mma_def.h"
#include "mma_env.h"
#include "mma_cfg.h"
#include "mma_main.h"
#include "mma_msgmgr.h"
#include "mma_mime.h"
#include "mma_interface.h"
#include "mma_utilities.h"
#include "mma_msg_struct.h"
#include "mma_sendrecv.h"
#include "mms_aApp.h"
#include "mmi_rp_srv_mms_def.h"
#include "mmi_rp_file_type_def.h"
#ifdef __MMI_VCARD__
#include "vcard_lib.h"
#endif // __MMI_VCARD__

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "msm.h"
#endif

#ifdef MMS_SUPPORT
#define IS_EMAIL(x) (strchr(x, '@') != NULL)
/* Refer to Sls_if.c */
#define SLS_SMIL_START      "<smil>\n"
#define SLS_SMIL_END        "</smil>\n"
#define SLS_HEAD_START      "<head>\n"
#define SLS_HEAD_END        "</head>\n"
#define SLS_BODY_START      "<body>\n"
#define SLS_BODY_END        "</body>\n"
#define SLS_PAR_START       "<par dur=\"%dms\">\n"
#define SLS_PAR_END         "</par>\n"

#define SLS_TEXT_T1         "<text src=\"%s\" region=\"%s\" "
#define SLS_TEXT_T2         "begin=\"%lums\" "
#define SLS_TEXT_T3         "end=\"%lums\" "
#define SLS_TEXT_T4         "dur=\"%lums\" "
#define SLS_TEXT_T5         "<param name=\"foreground-color\" value=\"%s\" />\n"
#define SLS_TEXT_T6         "/>\n"
#define SLS_TEXT_T7         ">\n"
#define SLS_TEXT_T8         "<param name=\"textsize\" value=\"%s\" />\n"
#define SLS_TEXT_T9         "</text>\n"
#define SLS_IMAGE_T1        "<img src=\"%s\" region=\"%s\" "
#define SLS_IMAGE_T2         "begin=\"%lums\" "
#define SLS_IMAGE_T3         "end=\"%lums\" "
#define SLS_IMAGE_T4         "dur=\"%lums\" "
#define SLS_IMAGE_T5        "/>\n"
#define SLS_VIDEO_T1        "<video src=\"%s\" region=\"%s\" "
#define SLS_VIDEO_T2        "begin=\"%lums\" "
#define SLS_VIDEO_T3        "end=\"%lums\" "
#define SLS_VIDEO_T4        "dur=\"%lums\" "
#define SLS_VIDEO_T5        "/>\n"
#define SLS_AUDIO_T1         "<audio src=\"%s\" "
#define SLS_AUDIO_T2         "begin=\"%lums\" "
#define SLS_AUDIO_T3         "end=\"%lums\" "
#define SLS_AUDIO_T4         "dur=\"%lums\" "
#define SLS_AUDIO_T5        "/>\n"
#define SLS_REF_T1         "<ref src=\"%s\" "
#define SLS_REF_T2         "begin=\"%lums\" "
#define SLS_REF_T3         "end=\"%lums\" "
#define SLS_REF_T4         "dur=\"%lums\" "
#define SLS_REF_T5        "/>\n"
#define SLS_LAYOUT_START    "<layout>\n"
#define SLS_LAYOUT_END      "</layout>\n"
#define SLS_ROOT_LAYOUT_T1  "<root-layout width=\""
#define SLS_ROOT_LAYOUT_T2  "\" height=\""
#define SLS_ROOT_LAYOUT_T3  "\" background-color=\""
#define SLS_ROOT_LAYOUT_T4  "\"/>\n"
#define SLS_REGION_T1       "<region id=\""
#define SLS_REGION_T2       "\" width=\""
#define SLS_REGION_T3       "\" height=\""
#define SLS_REGION_T4       "\" left=\""
#define SLS_REGION_T5       "\" top=\""
#define SLS_REGION_T6       "\" fit=\""
#define SLS_REGION_T7       "\" />\n"

#define SLS_FIT_FILL   "fill"
#define SLS_FIT_HIDDEN "hidden"
#define SLS_FIT_MEET   "meet"
#define SLS_FIT_SCROLL "scroll"
#define SLS_FIT_SLICE  "slice"

#define SLS_INTSZ           (MSF_INT32)12
#define SLS_UINTSZ          (MSF_INT32)SLS_INTSZ
#define COLOR_RGB_STR       "#RRGGBB"

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
#define SRV_UC_INVALID_VALUE (0xFFFFFFFF)
#endif
extern kal_mutexid mma_ctrl_mutex;

#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
#if ((defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) && !defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
extern U32 srv_uc_convert_to_mms_expiry_time(srv_uc_expiry_time_enum uc_expiry_time);

extern U32 srv_uc_convert_to_mms_delivery_time(srv_uc_delivery_time_enum uc_delivery_time);
#endif
#endif

extern kal_wchar* get_string(mmi_rp_srv_mms_str_enum i);

/*****************************************************************************
 * FUNCTION
 *  mma_unicode_to_utf8_len
 * DESCRIPTION
 *  Get UTF8 string len from UCS2 string.
 * PARAMETERS
 *  ucs2        [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 mma_um_unicode_to_utf8_len(kal_wchar *ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar temp;
    kal_int32 length = 0;
    kal_wchar *str = ucs2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	temp = *str;
    while (temp != NULL)
    {
        temp = *str;
        if (temp < (kal_wchar) 0x80)
            length += 1;
        else if (temp < (kal_wchar) 0x800)
            length += 2;
        else
            length += 3;
        str++;
    }
    return length;
}


/*****************************************************************************
 * FUNCTION
 *  mma_um_ucs2_to_utf8_string
 * DESCRIPTION
 *  Get UTF8 string from UCS2 string, caller should release the returned UTF8 string
 * PARAMETERS
 *  ucs2_str        [IN]        
 * RETURNS
 *  UTF8 string
 *****************************************************************************/
char *mma_um_ucs2_to_utf8_string(const kal_wchar *ucs2_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *utf8_str = NULL;
    long src_len = (long)app_ucs2_strlen((kal_int8*) ucs2_str) * ENCODING_LENGTH;
    long dst_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst_len = (long)mma_um_unicode_to_utf8_len((kal_wchar*) ucs2_str);
    if (src_len > 0)
    {
        utf8_str = (char*)OslMalloc(dst_len + 1);
        memset(utf8_str, 0, dst_len + 1);
        msf_charset_ucs2le_to_utf8((const char*)ucs2_str, &src_len, utf8_str, &dst_len);
    }
    return utf8_str;
}


/*****************************************************************************
 * FUNCTION
 *  mma_um_charset_utf8_to_ucs2le
 * DESCRIPTION
 *  Get UCS2 string from UTF8 string, caller should release the returned UCS2 string
 * PARAMETERS
 *  ucs2_str        [IN]        
 * RETURNS
 *  UTF8 string
 *****************************************************************************/
kal_uint8* mma_um_charset_utf8_to_ucs2le ( const char *src_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *dest_buffer = NULL;
    long dest_len = 0, src_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_len = strlen(src_str);
    src_len++;

    dest_len = src_len * ENCODING_LENGTH;

    dest_buffer = (char*)OslMalloc(dest_len);
    memset(dest_buffer, 0, dest_len);
    if (dest_buffer)
    {
		msf_charset_utf8_to_ucs2le(src_str, &src_len, dest_buffer, &dest_len);
    }
    
    return (kal_uint8 *)dest_buffer;
}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mma_um_drm_check_right
 * DESCRIPTION
 *  Check if DRM right is valid for a processed DRM file
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_um_drm_check_right(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *mime = NULL;
    kal_bool is_valid_right = KAL_FALSE;
    applib_mime_type_enum drmGType = MIME_TYPE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filename);
    mime = (char*)DRM_get_content_type(0, (kal_wchar*) filename);
    drmGType = mma_get_mime_group_from_mime_type(mime);

    if (drmGType == MIME_TYPE_TEXT || drmGType == MIME_TYPE_IMAGE || drmGType == MIME_TYPE_AUDIO ||
        drmGType == MIME_TYPE_VIDEO)
    {
        kal_uint8 permission = (kal_uint8) ((drmGType == MIME_TYPE_TEXT || drmGType == MIME_TYPE_IMAGE) ?
                                            DRM_PERMISSION_DISPLAY : DRM_PERMISSION_PLAY);
        FS_HANDLE fh = DRM_open_file((kal_wchar *)filename, FS_READ_ONLY, permission);
        if (fh >= FS_NO_ERROR)
        {
            is_valid_right = DRM_validate_permission(fh, NULL, permission);
            DRM_close_file(fh);
        }
    }

    return is_valid_right;
}


/*****************************************************************************
 * FUNCTION
 *  mma_drm_get_method_type
 * DESCRIPTION
 *  Get DRM method for a processed DRM file, ex. files in file manager
 * PARAMETERS
 *  fh          [IN] DRM_open_file() return value. If < 0, use filepath instead
 *  filename        [IN]        
 * RETURNS
 *  mma_drm_method_enum
 *****************************************************************************/
mma_drm_method_enum mma_um_drm_get_method_type(FS_HANDLE fh, const char *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_method_enum drmMethod = DRM_METHOD_NONE;
    kal_uint8 *filename_ucs2 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(fh >= 0 || filepath != NULL);
    if (fh >= 0)
    {
        drmMethod = DRM_get_object_method(fh, NULL);
    }
    else
    {
		filename_ucs2 = (kal_uint8 *)mma_um_charset_utf8_to_ucs2le(filepath);
        drmMethod = DRM_get_object_method(0, (kal_wchar *) filename_ucs2);
        if(filename_ucs2)
        {
            OslMfree(filename_ucs2);
        }
    }
    if ((drmMethod & DRM_METHOD_FORWARD_LOCK) == DRM_METHOD_FORWARD_LOCK)
    {
        return MMA_DRM_METHOD_FORWARD_LOCK;
    }
    else if ((drmMethod & DRM_METHOD_COMBINED_DELIVERY) == DRM_METHOD_COMBINED_DELIVERY)
    {
        return MMA_DRM_METHOD_COMBINED_DELIVERY;
    }
    else if ((drmMethod & DRM_METHOD_SEPARATE_DELIVERY) == DRM_METHOD_SEPARATE_DELIVERY)
    {
        return MMA_DRM_METHOD_SEPARATE_DELIVERY;
    }
    switch (drmMethod)
    {
        case DRM_METHOD_NONE:
            return MMA_DRM_METHOD_NONE;
        case DRM_METHOD_FORWARD_LOCK:
            return MMA_DRM_METHOD_FORWARD_LOCK;
        case DRM_METHOD_COMBINED_DELIVERY:
            return MMA_DRM_METHOD_COMBINED_DELIVERY;
        case DRM_METHOD_SEPARATE_DELIVERY:
            return MMA_DRM_METHOD_SEPARATE_DELIVERY;
        default:
            return MMA_DRM_METHOD_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_drm_get_content_type
 * DESCRIPTION
 *  Get mime type string for processed DRM file
 * PARAMETERS
 *  type            [IN]        
 *  fh          [IN] DRM_open_file() return value. If < 0, use filepath instead
 *  filename        [IN]        
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_um_drm_get_content_type(mma_drm_type_for_process_enum type, FS_HANDLE fh, const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *filename_ucs2 = NULL; /* translated UCS2 vitual file name */
    char *mime = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((fh >= 0 || filename != NULL) && (type == MMA_DRM_PROCESS_FORWARD_LOCK_CD || type == MMA_DRM_PROCESS_SEPERATE_DELIVERY));
    if (fh >= 0)
    {
        mime = (char *)DRM_get_content_type(fh, NULL);
    }
    else
    {
		filename_ucs2 = (kal_uint8 *)mma_um_charset_utf8_to_ucs2le(filename);
        mime = (char*)DRM_get_content_type(0, (kal_wchar*) filename_ucs2);
        if(filename_ucs2)
        {
            OslMfree(filename_ucs2);
        }
    }
    return mime;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mma_um_is_restricted_type
 * DESCRIPTION
 *  Check if the file is restricted type (Ref OMA-MMS-CONF-v1_2). For insertion check.
 *  We don't expect FL/CD object check.
 * PARAMETERS
 *  content_class       [IN]        
 *  filename            [IN]        
 * RETURNS
 *  TRUE: restricted; FALSE: non-restricted
 *****************************************************************************/
kal_bool mma_um_is_restricted_type(mms_content_class_enum content_class, FS_HANDLE fh, const char *filename, const char* mime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    const char *restricted_types = mma_get_restricted_attachment_type();
    const char *restricted_image_types = mma_get_restricted_image_type();
    const char *str_mime_type = NULL;
    kal_uint8 *filename_ucs2 = NULL; /* translated UCS2 file name */
#ifdef __DRM_SUPPORT__
    mma_drm_method_enum drmMethod = MMA_DRM_METHOD_NONE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filename != NULL);
	filename_ucs2 = (kal_uint8 *)mma_um_charset_utf8_to_ucs2le(filename);

    if (mma_get_mmi_file_size(-1, (const kal_wchar *)filename_ucs2) > mms_get_max_msg_size_in_restricted_mode())
    {
		if(filename_ucs2)
		{
			OslMfree(filename_ucs2);
		}
        return KAL_FALSE;
    }
    if(filename_ucs2)
    {
        OslMfree(filename_ucs2);
		filename_ucs2 = NULL;
    }
    if ((str_mime_type = mma_get_mime_type_from_filename_and_mime_string(filename, NULL)) == NULL)
    {
        return KAL_FALSE;
    }

#ifdef __DRM_SUPPORT__
    if (app_stricmp((kal_char*)str_mime_type, (kal_char*)MMA_MEDIA_TYPE_STRING_DRM2) == 0)     /* check *.dcf file or DRM segment in MMS */
    {
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
        drmMethod = mma_um_drm_get_method_type(fh, filename);
        if(drmMethod == MMA_DRM_METHOD_FORWARD_LOCK)
        {
            if (content_class == MMS_CONTENT_CLASS_TEXT || content_class == MMS_CONTENT_CLASS_IMAGE_BASIC)
            {
                return KAL_FALSE;
            }
            str_mime_type = mma_um_drm_get_content_type(MMA_DRM_PROCESS_FORWARD_LOCK_CD,fh, filename);
        }
        else
        {
            return KAL_FALSE;
        }
#else
        return KAL_FALSE;
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
    }
    else if (app_stricmp((kal_char*)str_mime_type, (kal_char*)MMA_MEDIA_TYPE_STRING_DRM1) == 0)        /* check *.dm file or DRM segment in MMS */
    {
        if (content_class == MMS_CONTENT_CLASS_TEXT || content_class == MMS_CONTENT_CLASS_IMAGE_BASIC)
        {
            return KAL_FALSE;
        }
        str_mime_type = mma_um_drm_get_content_type(MMA_DRM_PROCESS_FORWARD_LOCK_CD, fh, filename);    /* processed */
        drmMethod = mma_um_drm_get_method_type(fh, filename);
        if (drmMethod == MMA_DRM_METHOD_COMBINED_DELIVERY)
        {
            return KAL_FALSE;
        }
    }
    else    /* check normal extension files, ex. *.jpg, mostly processed file in File Manager */
    {
        drmMethod = mma_um_drm_get_method_type(fh, filename);
        if (drmMethod == MMA_DRM_METHOD_COMBINED_DELIVERY || drmMethod == MMA_DRM_METHOD_SEPARATE_DELIVERY)
        {
            return KAL_FALSE;
        }
        else if (drmMethod == MMA_DRM_METHOD_FORWARD_LOCK)
        {
            if (content_class == MMS_CONTENT_CLASS_TEXT || content_class == MMS_CONTENT_CLASS_IMAGE_BASIC)
            {
                return KAL_FALSE;
            }
            str_mime_type = mma_um_drm_get_content_type(MMA_DRM_PROCESS_FORWARD_LOCK_CD, fh, filename);
        }
    }

    if (str_mime_type == NULL)
    {
        return KAL_FALSE;
    }
#endif /* __DRM_SUPPORT__ */ 

    if (strstr(restricted_types, str_mime_type))
    {
        /* Image resolution check  */
        if (restricted_image_types != NULL && strstr(restricted_image_types, str_mime_type))
        {
#ifndef  __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__
            kal_int32 width = 0, height = 0, r_width = 0, r_height = 0;
#endif /*  __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__ */
            kal_uint8 *filename_ucs2 = NULL;
            kal_bool is_progressive;

#ifndef __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__
            mms_get_max_image_resolution_in_restricted_mode(&r_width, &r_height);
#endif /*  __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__ */
        #ifdef __DRM_SUPPORT__
            /* TODO: FL DRM image resolution check is absent. 
               Anyway, currently only editor use the function and FL object cannot be edited */
            if (drmMethod == MMA_DRM_METHOD_FORWARD_LOCK)
            {
                return KAL_TRUE;
            }
        #endif /* __DRM_SUPPORT__ */ 
			filename_ucs2 = (kal_uint8 *)mma_um_charset_utf8_to_ucs2le(filename);
#ifndef  __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__
            if (gdi_image_get_dimension_file((char *)filename_ucs2, &width, &height) != GDI_SUCCEED ||
                width * height > r_width * r_height)
            {
                if(filename_ucs2)
                {
				    OslMfree(filename_ucs2);
                }
                return KAL_FALSE;
            }
#endif  /*  __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__ */
            /* check image is progressive jpeg */
            if (gdi_image_jpeg_is_progressive((char *)filename_ucs2, &is_progressive) != GDI_SUCCEED ||
                is_progressive == TRUE)
            {
				if(filename_ucs2)
				{
					OslMfree(filename_ucs2);
				}
                return KAL_FALSE;
            }
            if(filename_ucs2)
            {
                OslMfree(filename_ucs2);
            }
        }
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_check_drm_type
 * DESCRIPTION
 *  Check object for DRM type
 * PARAMETERS
 *  filepath        [IN]        File Path
 * RETURNS
 *  mma_drm_type_enum : DRM Type
 *****************************************************************************/
mma_drm_type_enum mma_check_drm_type(const kal_wchar *filepath)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *utf8_filepath = NULL;
    mma_drm_type_enum drm_type = MMA_DRM_NONE;
    mma_drm_method_enum drmMethod = MMA_DRM_METHOD_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_filepath = mma_um_ucs2_to_utf8_string(filepath);
    drmMethod = mma_um_drm_get_method_type(-1, utf8_filepath);
    if (drmMethod == MMA_DRM_METHOD_NONE)
    {
        drm_type = MMA_DRM_NONE;
    }
    else if (drmMethod == MMA_DRM_METHOD_FORWARD_LOCK || drmMethod == MMA_DRM_METHOD_COMBINED_DELIVERY)
    {

        drm_type = MMA_DRM_FL_CD;
    }
    else
    {
        if (mma_um_drm_check_right((S8 *)filepath) == KAL_TRUE)
        {
            drm_type = MMA_DRM_SD;
        }
        else
        {
            drm_type = MMA_DRM_SD_NO_RIGHT;
        }
    }
    if(utf8_filepath)
    {
        OslMfree(utf8_filepath);
    }
    return drm_type;
#else /* __DRM_SUPPORT__ */ 
    return MMA_DRM_NONE;
#endif /* __DRM_SUPPORT__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mma_check_image_file
 * DESCRIPTION
 *  Check the image file is valid
 * PARAMETERS
 *  filepath        [IN]     UCS2 string
 * RETURNS
 *  
 *****************************************************************************/
static mma_result_enum mma_check_image_file(const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fmgr_ret = -1;
    kal_bool is_progressive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check image resolution */
#if 0	/*temporily commented for cosmos project*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* check image is a progressive jpeg */
    if (gdi_image_jpeg_is_progressive((PS8) filepath, &is_progressive) == GDI_SUCCEED &&
        is_progressive == TRUE)
    {
        return MMA_RESULT_OK;
    }
    
    /* Check if drawing the image succeed */
    if (gdi_image_check_image_file_valid((PS8) filepath) == TRUE)
    {
        return MMA_RESULT_OK;
    }

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UM_CHECK_IMG_FILE_DRAW_GDI_RETURN, "mma_check_image_file() draw: gdi_ret = %d\n", fmgr_ret));
    return MMA_RESULT_FAIL_FILE_CORRUPTED;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_home_directory
 * DESCRIPTION
 *  The function is used to get mms home directory
 * PARAMETERS
 *  buffer          [IN]         
 *  buffer_size     [IN]        
 * RETURNS
 *  KAL_FASLE, KAL_TRUE
 *****************************************************************************/
kal_bool mma_get_home_directory(kal_wchar *buffer, kal_uint32 buffer_size, kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar temp_path[32] = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == MMA_MSG_STORAGE_CARD1)
    {
        kal_wsprintf(temp_path, "%c:%s", SRV_FMGR_CARD_DRV,"\\@mms\\mms_pdu");
    }
    else
    {
#ifdef MMS_IN_LARGE_STORAGE
        kal_wsprintf(temp_path, "%c:%s", SRV_FMGR_PUBLIC_DRV,"\\@mms\\mms_pdu");
#else
        kal_wsprintf(temp_path, "%c:%s", SRV_FMGR_SYSTEM_DRV,"\\@mms\\mms_pdu");
#endif
    }
    
    if (buffer != NULL )
    {
        app_ucs2_strncpy(
            (kal_int8*) buffer,
            (kal_int8*) temp_path,
            (kal_uint8) (app_ucs2_strlen((kal_int8*) temp_path))); /*hack for App */

        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_msg_file_name
 * DESCRIPTION
 *  The function is used to get file name of one MMS message
 * PARAMETERS
 *  msg_id          [IN]        
 *  buffer          [IN]         
 *  buffer_size     [IN]        
 * RETURNS
 *  KAL_FASLE, KAL_TRUE
 *****************************************************************************/
kal_bool mma_get_msg_file_name(kal_uint32 msg_id, kal_wchar *buffer, kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_uint32 len = (kal_uint32) (strlen("XXX.s") + 1);
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (buffer != NULL)
    {
        kal_wsprintf(buffer, "%x.%c", MMA_TRANSLATE_MSG_ID(msg_id), (char)msg_info->suffix);

        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_request_id
 * DESCRIPTION
 *  This function is get unique request id
 * PARAMETERS
 *  void
 * RETURNS
 *  requrst id
 *****************************************************************************/
kal_uint32 mma_get_request_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    static kal_uint32 g_mms_mma_request_id = 0;

    kal_take_mutex(mma_ctrl_mutex);

    g_mms_mma_request_id++;
    kal_give_mutex(mma_ctrl_mutex);
    return g_mms_mma_request_id;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_box
 * DESCRIPTION
 *  This function is get MMA folder of one MMS message
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  requrst id
 *****************************************************************************/
mma_folder_enum mma_get_box(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list((MSF_UINT32) msg_id);
    if (msg_info != NULL)
    {
        return (mma_folder_enum)msg_info->folder;
    }
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    else if(MMSlib_isReportMsgId(msg_id))
    {
        return MMA_FOLDER_REPORT_BOX;
    }
#endif
    else
    {
        return MMA_FOLDER_NONE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_msg_type
 * DESCRIPTION
 *  This function is get MMA folder of one MMS message
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  msg_type
 *****************************************************************************/
kal_uint8 mma_get_mms_msg_type(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list((MSF_UINT32) msg_id);
    if (msg_info != NULL)
    {
        return msg_info->mms_msg_type;
    }
    else
    {
        return MMA_MSG_TYPE_UNSUPPORTED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_mms_corrupted
 * DESCRIPTION
 *  This function is to check whether mms is corrupted or not
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  kal_bool	TRUE -- msg corrupted, FALSE -- msg ok
 *****************************************************************************/
kal_bool mma_is_mms_corrupted(kal_uint32 msg_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list((MSF_UINT32) msg_id);
    if (msg_info != NULL)
    {
        if (FALSE == MMSlib_isValidMmsMSg_Ext1((MMA_TRANSLATE_MSG_ID(msg_id)), (MmsFileType)msg_info->suffix, 
                        (kal_uint8)mma_get_mms_type_message_storage(msg_id)))
        {
            return KAL_TRUE;
        }
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_storage
 * DESCRIPTION
 *  This function is get MMA folder of one MMS message
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  requrst id
 *****************************************************************************/
kal_uint8 mma_get_mms_storage(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(msg_id & 0X80000000)
    {
        return MMA_MSG_STORAGE_CARD1;
    }
    else
    {
        return MMA_MSG_STORAGE_PHONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_read_status
 * DESCRIPTION
 *  This function is get mms Read/Unread Status
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  kal_uint8      0 means Unread, 1 means Read
 *****************************************************************************/
kal_uint8 mma_get_mms_read_status(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return 1;        /* Send READ Status */
    }
    else if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
    {
        /* This mms is shown as READ mms */
        return 1;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    else
    {
        return msg_info->is_read;
    }
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_file_size
 * DESCRIPTION
 *  This function is too get the file size of the mms. Right now, this is used only for notification.
 * Will update it later to use it for general case.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
kal_uint32 mma_mms_get_msg_file_size(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;
    char msg_file_path[100] = {0,};
    WCHAR filepath_ucs2[100] = {0, };
    char mms_disk;
    long srcLen, destLen = 100;
    kal_uint32 totalFileSize = 0;
    int file_handle = -1;
    kal_uint32 mms_msg_id = 0;
    kal_uint8 mms_storage_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if(msg_info == NULL)
    {
        /* This should not be NULL */
        return 0;
    }
    mms_msg_id = MMA_TRANSLATE_MSG_ID(msg_id);
    mms_storage_type = (kal_uint8)mma_get_mms_type_message_storage(msg_id);
    memset(msg_file_path, 0x00, 100);
    memset(filepath_ucs2, 0x00, 100);

    mms_disk = MMSa_getDriveLetter(mms_storage_type);
    sprintf(msg_file_path, "%c:\\@mms\\mms_pdu\\%lx.%c", mms_disk, mms_msg_id, (char)MMS_SUFFIX_NOTIFICATION);
    srcLen = strlen(msg_file_path);
    msf_charset_utf8_to_ucs2le((char*)msg_file_path, &srcLen, (char*)filepath_ucs2, &destLen);

    file_handle = FS_Open((WCHAR*) filepath_ucs2, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_NO_DIR);
    if (file_handle < 0)
    {
        translateFileErrorToMmsError(file_handle);    /* To print the error log */
        return 0;    /* Return file size as zero */
    }
    FS_GetFileSize(file_handle, &totalFileSize);
    FS_Close(file_handle);
    return totalFileSize;
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_msg_attribute
 * DESCRIPTION
 *  This function is get message identifier from msg_box_type and msg_index
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_get_msg_attribute(kal_uint32 msg_id, mma_sync_msg_attribute_struct *msg_attribute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(msg_attribute == NULL)
    {
        ASSERT(0);
    }
    memset(msg_attribute, 0, sizeof(mma_sync_msg_attribute_struct));
	/* provide the storage irrespective of whether mms is valid or corrupted */
	msg_attribute->msg_storage = (kal_uint8)mma_get_message_storage(msg_id);

    /* check for the USB mode */
    if (mma_main_is_in_usb_mode() == TRUE)
    {
        return MMA_RESULT_FAIL_IN_USB_MODE;
    }
    
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    else if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
    {
        return MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE;
    }
    else
    {
        mma_result_enum result = MMA_RESULT_OK;
        mms_msg_info_property_struct *property_st = NULL;
        mms_msg_info_large_data_struct *large_data_st = NULL;
        
        /* read the checksum file & provide the data */
        property_st = (mms_msg_info_property_struct*)OslMalloc(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);
        large_data_st = (mms_msg_info_large_data_struct*)
                    OslMalloc(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);
        result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                property_st, large_data_st));
        if(result == MMA_RESULT_OK)
        {
            kal_uint32 from_addr_length = 0;
            /* Error Handling for the corrupt mms */
            if (FALSE == MMSlib_isValidMmsMSg_Ext1((MMA_TRANSLATE_MSG_ID(msg_id)), (MmsFileType)msg_info->suffix, 
                        (kal_uint8)mma_get_mms_type_message_storage(msg_id)))
            {
                OslMfree(property_st);
                OslMfree(large_data_st);
                return MMA_RESULT_FAIL_FILE_CORRUPTED;
            }
            /* fill the structure */
            msg_attribute->timestamp = property_st->receive_date;
		#ifdef __MMI_MMS_POSTCARD__
		    if((msg_info->folder == MMA_FOLDER_SENT) && (property_st->msg_type == MMA_MSG_TYPE_POSTCARD))
		    {
		        msg_attribute->timestamp = property_st->compose_date;
            }
        #endif /* __MMI_MMS_POSTCARD__ */
            msg_attribute->user_elements_size = property_st->user_elements_size;
			msg_attribute->date = property_st->compose_date;
            msg_attribute->expiry_date = property_st->expiry_date;
            if(msg_info->suffix == MMS_SUFFIX_NOTIFICATION)
            {
                msg_attribute->msg_size = mma_mms_get_msg_file_size(msg_id);
            }
            else
            {
                msg_attribute->msg_size = property_st->msg_size;
            }
            msg_attribute->is_follow_phone_mms_content_class = (kal_bool)property_st->is_follow_phone_mms_content_class;
            msg_attribute->is_forward_lock = (kal_bool)property_st->is_forward_lock;
			msg_attribute->is_read = (kal_bool)property_st->is_read;
            msg_attribute->is_lock_mode = (kal_bool)large_data_st->app_data[MMA_MSGMGR_LOCK_MODE_APP_DATA_POS];
	    msg_attribute->need_read_report = (kal_bool)property_st->need_read_report;
            from_addr_length = app_ucs2_strlen((const kal_int8*) large_data_st->from_address);
            if( from_addr_length > 0)
            {
                /* No need to check for MAX Address length. As here both have same max length */
                app_ucs2_strncpy(
                            (kal_int8*) msg_attribute->from_address,
                            (const kal_int8*)large_data_st->from_address,
                            from_addr_length);
            }
            
            msg_attribute->is_msg_corrupt = (kal_bool)large_data_st->app_data[MMA_MSGMGR_CORRUPT_MMS_POS];
            msg_attribute->msg_type = property_st->msg_type;
            msg_attribute->folder = property_st->folder;
            msg_attribute->msg_sim_id = msg_info->msg_sim_id;
            msg_attribute->from_address_type = large_data_st->from_address_type;
            msg_attribute->prev_folder = large_data_st->app_data[MMA_MSGMGR_PREV_FOLDER_POS];
			msg_attribute->msg_report_status = property_st->msg_report_status;
			if(property_st->suffix != MMS_SUFFIX_DELIVERYREPORT &&
				property_st->suffix != MMS_SUFFIX_READREPORT &&
				app_ucs2_strlen((const kal_int8*)large_data_st->subject) > 0)
            {
	            app_ucs2_strncpy(
                            (kal_int8*) msg_attribute->subject,
                            (const kal_int8*)large_data_st->subject,
                            MMA_MAX_SUBJECT_LEN - 1);
	        }
            else
            {
                kal_wchar *str = NULL;

	            if (property_st->suffix == MMS_SUFFIX_DELIVERYREPORT)
	            {
	                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
	            }
	            else if (property_st->suffix == MMS_SUFFIX_READREPORT)
	            {
	                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
	            }
                if (app_ucs2_strlen((const kal_int8*)str) > 0)
	            {
	                app_ucs2_strncpy(
                            (kal_int8*) msg_attribute->subject,
                            (const kal_int8*)str,
                            MMA_MAX_SUBJECT_LEN - 1);
	            }
		        if ((property_st->suffix == MMS_SUFFIX_DELIVERYREPORT) ||
                    (property_st->suffix == MMS_SUFFIX_READREPORT))
                {
                    app_ucs2_strncpy(
                            (kal_int8*) msg_attribute->reported_subject,
                            (const kal_int8*)large_data_st->subject,
                            MMA_MAX_SUBJECT_LEN - 1);
                }
            }
        }
        OslMfree(property_st);
        OslMfree(large_data_st);
		if(result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE)
		{
			/* Unsupported check is already checked. Now, this error come as USer have corrupt the File */
			result = MMA_RESULT_FAIL_FILE_CORRUPTED;
		}
        return result;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_msg_folder_count
 * DESCRIPTION
 *  This function is get the count of mms in different folders
 * PARAMETERS
 *  mma_mms_folder_mms_count_status_struct      [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_get_msg_folder_count(mma_mms_folder_mms_count_status_struct *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(count == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_PARAMETER;
    }
    memset(count, 0x00, sizeof(mma_mms_folder_mms_count_status_struct));
    /* check for error handling */
    if (mma_main_is_in_usb_mode() == TRUE)
    {
		/* return OK result with 0 count */
        return MMA_RESULT_OK;
    }
    mma_msgmgr_get_msg_folder_count(count);
    return MMA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_move_msg_to_folder
 * DESCRIPTION
 *  This function move the folder storage of a mms
 * PARAMETERS
 *  msg_id      [IN]
 *  folder_id   [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_move_msg_to_folder(kal_uint32 msg_id, kal_uint8 folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;
    mms_msg_info_large_data_struct *large_data_st = NULL;
    mms_msg_info_property_struct *property_st = NULL;
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for error handling */
    if (mma_main_is_in_usb_mode() == TRUE)
    {
        return MMA_RESULT_FAIL_IN_USB_MODE;
    }
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    if(msg_info->folder == folder_id)
    {
        return MMA_RESULT_OK;
    }
    if(mma_cvt_mma_folder_to_mms_folder((mma_folder_enum)folder_id) == -1)
    {
        return MMA_RESULT_FAIL_INVALID_FOLDER;
    }
    if ((mma_sendrecv_is_downloading(msg_id) || mma_sendrecv_is_sending(msg_id)) == TRUE)
    {
        return MMA_RESULT_FAIL_MSGID_IS_USING;
    }

    if (folder_id == MMA_FOLDER_USRDEF_TEMPLATE)
    {
        if (mma_msgmgr_get_msg_num_of_folder(MMA_FOLDER_USRDEF_TEMPLATE) >= MMA_MAX_USER_DEF_TEMPLATE_NUM)
        {
            return MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL;    
        }
    }
    /* Update in checksum file */
    large_data_st = (mms_msg_info_large_data_struct*)OslMalloc(sizeof(mms_msg_info_large_data_struct));                        
    property_st = (mms_msg_info_property_struct*)OslMalloc(sizeof(mms_msg_info_property_struct));
    
    result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id),
                (kal_uint8)mma_get_mms_type_message_storage(msg_id), property_st, large_data_st));

                            
    if(result == MMA_RESULT_OK)
    {
        if(folder_id == MMA_FOLDER_ARCHIVE)
        {
            large_data_st->app_data[MMA_MSGMGR_PREV_FOLDER_POS] = (kal_uint8)msg_info->folder;
        }
    #ifdef __MMI_MMS_POSTCARD__
        else if((folder_id == MMA_FOLDER_SENT) && (property_st->msg_type == MMA_MSG_TYPE_POSTCARD))
        {
			property_st->compose_date = MSF_TIME_GET_SECURE_CLOCK();
        }
    #endif /* __MMI_MMS_POSTCARD__ */
        property_st->folder = (MSF_UINT8)folder_id;
        msg_info->prev_folder = msg_info->folder;
        /* update the checksum of the property part */
        result = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id), (MmsFileType)msg_info->suffix,
            (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id), 
            property_st, large_data_st));
        /* update the mms folder status */
        if(result == MMA_RESULT_OK)
        {
            mma_msgmgr_update_mms_folder_status(msg_info, KAL_TRUE, msg_info->folder, (kal_uint8)folder_id);
            msg_info->folder = (MSF_UINT8)folder_id;
        }
    }
    OslMfree(property_st);
    OslMfree(large_data_st);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_delete_msg
 * DESCRIPTION
 *  This function is used to delete the mms
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_delete_msg(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    if (mma_main_is_in_usb_mode() == TRUE)
    {        
        return MMA_RESULT_FAIL_IN_USB_MODE;
    }
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check for the Memory Card mms in plug out state for which the delete req come */
    if((mma_get_message_storage(msg_id) == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
	{
		return MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT;
	}
#endif
    if(msg_info->is_rr_send || mma_sendrecv_is_downloading(msg_id) || mma_sendrecv_is_sending(msg_id))
	{
		return MMA_RESULT_FAIL_MSGID_IS_USING;
	}
    /* Check if the MMS is in waiting queue */
    if (!mma_sendrecv_remove_single_pending_send_node(msg_id))
    {
        /* not in sending list, check for downloading list */
        mma_sendrecv_remove_single_pending_download_node(msg_id);
    }
    /* Now delete the MMS */
    MMA_MSGMGR_MSG_SET_FLAG(msg_info->flag, MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT);
    MMA_MSGMGR_MSG_SET_FLAG(msg_info->flag, MMA_MSGMGR_MSG_OPER_DELETE);
    mma_msgmgr_update_mms_folder_status(msg_info, KAL_TRUE, msg_info->folder, 0);
    {
        /* Send the Sync delete req to MSGMGR */
        ilm_struct *ilm_ptr = NULL;
        mms_sync_delete_msg_ind_struct *sync_delete_msg_ind_input_p = NULL;

        sync_delete_msg_ind_input_p = (mms_sync_delete_msg_ind_struct*) construct_local_para(
                                            sizeof(mms_sync_delete_msg_ind_struct), TD_CTRL | TD_RESET);

        sync_delete_msg_ind_input_p->msg_id = msg_id;

        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_MMS;
        ilm_ptr->sap_id = (sap_type)0;
        ilm_ptr->msg_id = MSG_ID_MMI_MMS_SYNC_DELETE_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*) sync_delete_msg_ind_input_p;
        ilm_ptr->peer_buff_ptr = NULL;
        msg_send_ext_queue(ilm_ptr);
    }
    return MMA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_set_read_status
 * DESCRIPTION
 *  This function is used to set the read status flag of msg
 * PARAMETERS
 *  msg_id      [IN]
 *  is_read      [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_set_read_status(kal_uint32 msg_id, kal_bool is_read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    mma_msg_info_list_struct *msg_info = NULL;
    mms_msg_info_property_struct *property_st = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check for the Memory Card mms in plug out state for which the delete req come */
    if((mma_get_message_storage(msg_id) == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
	{
		return MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT;
	}
#endif
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    property_st = (mms_msg_info_property_struct*)OslMalloc(sizeof(mms_msg_info_property_struct));
    result = mma_msgmgr_set_read_status(msg_id, is_read, property_st);

    OslMfree(property_st);
    return result;
    
}

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mma_mms_set_lock_status
 * DESCRIPTION
 *  This function is used to set the lock/corrupt status flag of msg
 * PARAMETERS
 *  msg_id      [IN]
 *  is_read      [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_set_lock_status(kal_uint32 msg_id, kal_uint8 is_lock, kal_uint8 is_corrupt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    mms_msg_info_large_data_struct *large_data_st = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check for the Memory Card mms in plug out state for which this req come */
    if((mma_get_message_storage(msg_id) == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
	{
		return MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT;
	}
#endif
    large_data_st = (mms_msg_info_large_data_struct*)OslMalloc(sizeof(mms_msg_info_large_data_struct));
    result = mma_msgmgr_set_lock_status(msg_id, is_lock, is_corrupt, large_data_st);
    OslMfree(large_data_st);
    return result;
}
#endif /* __MMI_SLIM_MMS_2__ */
#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mma_mms_set_sim_status
 * DESCRIPTION
 *  This function is used to set the sim status flag of msg
 * PARAMETERS
 *  msg_id      [IN]
 *  sim_id      [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_set_sim_status(kal_uint32 msg_id, kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mma_result_enum result = MMA_RESULT_OK;
    mms_msg_info_property_struct *property_st = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check for the Memory Card mms in plug out state for which this req come */
    if((mma_get_message_storage(msg_id) == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
	{
		return MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT;
	}
#endif
    property_st = (mms_msg_info_property_struct*)OslMalloc(sizeof(mms_msg_info_property_struct));
    result = mma_msgmgr_set_sim_status(msg_id, sim_id, property_st);
    OslMfree(property_st);
    return result;
}
#endif

typedef void *(*umms_sync_op_mem_alloc_fn) (kal_uint32);
typedef void (*umms_sync_op_mem_free_fn) (void *);

/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_mms_msg_sync_info
 * DESCRIPTION
 *  This function is get message info in a sync behavior
 * PARAMETERS
 *  msg_id      [IN]
 *  wap_mma_get_mms_msg_info_struct  [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_get_mms_msg_sync_info(kal_uint32 msg_id, wap_mma_get_mms_msg_info_struct *mms_msg_info,
                                              umms_sync_op_mem_alloc_fn mem_alloc_fn,  umms_sync_op_mem_free_fn mem_free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mms_msg_info == NULL)
    {
        ASSERT(0);
    }
    memset(mms_msg_info, 0, sizeof(wap_mma_get_mms_msg_info_struct));
	/* provide the storage irrespective of whether mms is valid or corrupted */
	mms_msg_info->storage_type = (kal_uint8)mma_get_message_storage(msg_id);

    /* check for the USB mode */
    if (mma_main_is_in_usb_mode() == TRUE)
    {
        return MMA_RESULT_FAIL_IN_USB_MODE;
    }
    
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    else if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
    {
        return MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE;
    }
    else
    {
        mma_result_enum result = MMA_RESULT_OK;
        mms_msg_info_property_struct *property_st = NULL;
        mms_msg_info_large_data_struct *large_data_st = NULL;
        
        /* read the checksum file & provide the data */
        property_st = (mms_msg_info_property_struct*)mem_alloc_fn(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);
        large_data_st = (mms_msg_info_large_data_struct*)
                    mem_alloc_fn(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);
        result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                property_st, large_data_st));
        if(result == MMA_RESULT_OK)
        {
            kal_uint32 from_addr_length = 0;
            /* Error Handling for the corrupt mms */
            if (FALSE == MMSlib_isValidMmsMSg_Ext1((MMA_TRANSLATE_MSG_ID(msg_id)), (MmsFileType)msg_info->suffix, 
                        (kal_uint8)mma_get_mms_type_message_storage(msg_id)))
            {
                mem_free_fn(property_st);
                mem_free_fn(large_data_st);
                return MMA_RESULT_FAIL_FILE_CORRUPTED;
            }
            /* fill the structure */
            mms_msg_info->user_elements_size = property_st->user_elements_size;
            if(msg_info->suffix == MMS_SUFFIX_NOTIFICATION)
            {
                mms_msg_info->msg_size = mma_mms_get_msg_file_size(msg_id);
                mms_msg_info->msg_download_size = property_st->msg_size;
            }
            else
            {
                mms_msg_info->msg_size = property_st->msg_size;
            }
            mms_msg_info->date = property_st->compose_date;
            mms_msg_info->expiry_date = property_st->expiry_date;
            mms_msg_info->received_date = property_st->receive_date;
            mms_msg_info->need_read_report = (kal_bool)property_st->need_read_report;
			mms_msg_info->need_delivery_report = (kal_bool)property_st->need_delivery_report;
            mms_msg_info->isRead = (kal_bool)property_st->is_read;
            mms_msg_info->isForwardlock = (kal_bool)property_st->is_forward_lock;
            mms_msg_info->is_follow_phone_mms_content_class = (kal_bool)property_st->is_follow_phone_mms_content_class;
            
            mms_msg_info->msg_media_type = property_st->msg_media_type;
            mms_msg_info->from_address_type = large_data_st->from_address_type;
            mms_msg_info->msg_type = property_st->msg_type;
            mms_msg_info->msg_class = property_st->msg_class;
            mms_msg_info->priority = property_st->priority;
            mms_msg_info->sim_id = msg_info->msg_sim_id;
            mms_msg_info->msg_report_status = property_st->msg_report_status;
            memcpy((char*)mms_msg_info->app_data, (char*)large_data_st->app_data, MMS_MAX_APP_DATA_LENGTH);
            if(property_st->msg_type == MMA_MSG_TYPE_JAVA)
            {
                strncpy((char*)mms_msg_info->java_app_id, (char*)large_data_st->java_app_id, JSR_MAX_APP_ID_LENGTH);
            }
            from_addr_length = app_ucs2_strlen((const kal_int8*) large_data_st->from_address);
            if( from_addr_length > 0)
            {
                /* No need to check for MAX Address length. As here both have same max length */
                app_ucs2_strncpy(
                            (kal_int8*) mms_msg_info->from_address,
                            (const kal_int8*)large_data_st->from_address,
                            from_addr_length);
            }
            if(property_st->suffix != MMS_SUFFIX_DELIVERYREPORT &&
				property_st->suffix != MMS_SUFFIX_READREPORT &&
				app_ucs2_strlen((const kal_int8*)large_data_st->subject) > 0)
            {
	            app_ucs2_strncpy(
                            (kal_int8*) mms_msg_info->subject,
                            (const kal_int8*)large_data_st->subject,
                            MMA_MAX_SUBJECT_LEN - 1);
	        }
            else
            {
                kal_wchar *str = NULL;

	            if (property_st->suffix == MMS_SUFFIX_DELIVERYREPORT)
	            {
	                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
	            }
	            else if (property_st->suffix == MMS_SUFFIX_READREPORT)
	            {
	                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
	            }
                if (app_ucs2_strlen((const kal_int8*)str) > 0)
	            {
	                app_ucs2_strncpy(
                            (kal_int8*) mms_msg_info->subject,
                            (const kal_int8*)str,
                            MMA_MAX_SUBJECT_LEN - 1);
	            }
                if ((property_st->suffix == MMS_SUFFIX_DELIVERYREPORT) ||
                    (property_st->suffix == MMS_SUFFIX_READREPORT))
                {
                    app_ucs2_strncpy(
                            (kal_int8*) mms_msg_info->reported_subject,
                            (const kal_int8*)large_data_st->subject,
                            MMA_MAX_SUBJECT_LEN - 1);
                }
            }
        }
        mem_free_fn(property_st);
        mem_free_fn(large_data_st);
        /* Now fill the TO/CC/BCC details. Not for the RR/DR/Notification/Template mms */
        if((msg_info->suffix != MMS_SUFFIX_DELIVERYREPORT) && (msg_info->suffix != MMS_SUFFIX_READREPORT) && 
            (msg_info->suffix != MMS_SUFFIX_NOTIFICATION) && (msg_info->suffix != MMS_SUFFIX_TEMPLATE) && 
            (msg_info->folder != MMA_FOLDER_USRDEF_TEMPLATE) && (result == MMA_RESULT_OK))
        {
            MSF_UINT8 total_address = 0;
            MSF_UINT8 total_object = 0;
            mma_result_enum ret = MMA_RESULT_OK;
            mms_msg_addr_info_struct *addr_data = (mms_msg_addr_info_struct*)
                mem_alloc_fn(sizeof(mms_msg_addr_info_struct) * MMS_MAX_ADDR_COUNT);
            ret = translate_mms_result_to_mma(MMSlib_readAddrObjFile(MMA_TRANSLATE_MSG_ID(msg_id),
                                    (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                    &total_address, &total_object, addr_data, NULL, (mms_mem_alloc_fn)mem_alloc_fn, mem_free_fn));
            if((ret == MMA_RESULT_OK) && (total_address > 0))
            {
                kal_uint8 count = 0;
                //mms_msg_addr_info_struct *temp = addr_data;
				
                for(; (count < total_address) && (count < MMS_MAX_ADDR_COUNT); count++)
                {
                    mms_msg_info->address[count].addr_len = addr_data[count].addr_len;
                    mms_msg_info->address[count].addr_group = addr_data[count].addr_group;
                    mms_msg_info->address[count].addr_type = addr_data[count].addr_type;
                    app_ucs2_strncpy(
                            (kal_int8*) mms_msg_info->address[count].address,
                            (const kal_int8*)addr_data[count].address,
                            MMS_MAX_ADDR_DATA_LEN - 1);
                    if(addr_data[count].addr_group == MMA_ADDRESS_GROUP_TYPE_TO)
                    {
                        mms_msg_info->to_addr_count++;
                    }
                    else if(addr_data[count].addr_group == MMA_ADDRESS_GROUP_TYPE_CC)
                    {
                        mms_msg_info->cc_addr_count++;
                    }
                    else
                    {
                        mms_msg_info->bcc_addr_count++;
                    }
                }
            }
            mem_free_fn(addr_data);
        }
		if(result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE)
		{
			/* Unsupported check is already checked. Now, this error come as USer have corrupt the File */
			result = MMA_RESULT_FAIL_FILE_CORRUPTED;
		}
        return result;
    }
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_mms_msg_addr_info
 * DESCRIPTION
 *  This function is get message TO/CC/BCC address info in a sync behavior
 * PARAMETERS
 *  msg_id      [IN]
 *  mma_msg_addr_info_struct  [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_get_mms_msg_addr_info(kal_uint32 msg_id, mma_msg_addr_info_struct *mms_msg_addr_info,
                                              umms_sync_op_mem_alloc_fn mem_alloc_fn,  umms_sync_op_mem_free_fn mem_free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mms_msg_addr_info == NULL)
    {
        ASSERT(0);
    }
    memset(mms_msg_addr_info, 0, sizeof(mma_msg_addr_info_struct) * MMA_MAX_SUPPORT_ADDR_COUNT);
    /* check for the USB mode */
    if (mma_main_is_in_usb_mode() == TRUE)
    {
        return MMA_RESULT_FAIL_IN_USB_MODE;
    }
    
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    else if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
    {
        return MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE;
    }
    else if(msg_info->suffix != MMS_SUFFIX_SEND_REQ)
    {
        return MMA_RESULT_FAIL_INVALID_PARAMETER;
    }
    else
    {
        MSF_UINT8 total_address = 0;
        MSF_UINT8 total_object = 0;
        mma_result_enum ret = MMA_RESULT_OK;
        mms_msg_addr_info_struct *addr_data = (mms_msg_addr_info_struct*)
            mem_alloc_fn(sizeof(mms_msg_addr_info_struct) * MMS_MAX_ADDR_COUNT);
        ret = translate_mms_result_to_mma(MMSlib_readAddrObjFile(MMA_TRANSLATE_MSG_ID(msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                &total_address, &total_object, addr_data, NULL, (mms_mem_alloc_fn)mem_alloc_fn, mem_free_fn));
        if((ret == MMA_RESULT_OK) && (total_address > 0))
        {
            kal_uint8 count = 0;
            for(; (count < total_address) && (count < MMS_MAX_ADDR_COUNT); count++)
            {
                mms_msg_addr_info[count].addr_len = addr_data[count].addr_len;
                mms_msg_addr_info[count].addr_group = addr_data[count].addr_group;
                mms_msg_addr_info[count].addr_type = addr_data[count].addr_type;
                app_ucs2_strncpy(
                        (kal_int8*) mms_msg_addr_info[count].address,
                        (const kal_int8*)addr_data[count].address,
                        MMS_MAX_ADDR_DATA_LEN - 1);
            }
        }
        mem_free_fn(addr_data);
        return MMA_RESULT_OK;
    }
}
#endif  /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_msg_report_status_info
 * DESCRIPTION
 *  This function is get the report status for a SENT folder MMS in a sync behavior
 * PARAMETERS
 *  msg_id      [IN]
 *  mma_msg_addr_info_struct  [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_get_msg_report_status_info(kal_uint32 msg_id, wap_mma_mms_msg_report_status_struct *mms_msg_report_info,
                                                   umms_sync_op_mem_alloc_fn mem_alloc_fn, umms_sync_op_mem_free_fn mem_free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mms_msg_report_info == NULL)
    {
        ASSERT(0);
    }
    memset(mms_msg_report_info, 0, sizeof(wap_mma_mms_msg_report_status_struct));
    /* check for the USB mode */
    if (mma_main_is_in_usb_mode() == TRUE)
    {
        return MMA_RESULT_FAIL_IN_USB_MODE;
    }
    
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    else
    {
        MSF_UINT8 total_address = 0;
        MSF_UINT8 total_object = 0;
        mma_result_enum ret = MMA_RESULT_OK;
        mms_msg_addr_info_struct *addr_data = (mms_msg_addr_info_struct*)
            mem_alloc_fn(sizeof(mms_msg_addr_info_struct) * MMS_MAX_ADDR_COUNT);
        if(addr_data == NULL)
        {
            /* Memory Allocation get failed */
            return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;
        }
        ret = translate_mms_result_to_mma(MMSlib_readAddrObjFile(MMA_TRANSLATE_MSG_ID(msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                &total_address, &total_object, addr_data, NULL, (mms_mem_alloc_fn)mem_alloc_fn, mem_free_fn));
        if((ret == MMA_RESULT_OK) && (total_address > 0))
        {
            kal_uint8 count = 0;
            wap_mma_mms_msg_report_status_struct *temp_node = NULL;

            mms_msg_report_info->addr_len = addr_data[count].addr_len;
            mms_msg_report_info->addr_group = addr_data[count].addr_group;
            mms_msg_report_info->addr_type = addr_data[count].addr_type;
            mms_msg_report_info->rr_status = addr_data[count].rr_status;
            mms_msg_report_info->dr_status = addr_data[count].dr_status;
            app_ucs2_strncpy((kal_int8*) mms_msg_report_info->address,
                    (const kal_int8*)addr_data[count].address,
                    MMS_MAX_ADDR_DATA_LEN - 1);
            mms_msg_report_info->next = NULL;
            temp_node = mms_msg_report_info;
            count++;

            //temp_node = mms_msg_report_info->next;
            for(; (count < total_address) && (count < MMS_MAX_ADDR_COUNT); count++)
            {
                /* Application (Caller of this API will free this memory */
                temp_node->next = (wap_mma_mms_msg_report_status_struct*) mem_alloc_fn(sizeof(wap_mma_mms_msg_report_status_struct));
                temp_node->next->addr_len = addr_data[count].addr_len;
                temp_node->next->addr_group = addr_data[count].addr_group;
                temp_node->next->addr_type = addr_data[count].addr_type;
                temp_node->next->rr_status = addr_data[count].rr_status;
                temp_node->next->dr_status = addr_data[count].dr_status;
                app_ucs2_strncpy((kal_int8*) temp_node->next->address,
                        (const kal_int8*)addr_data[count].address,
                        MMS_MAX_ADDR_DATA_LEN - 1);
                temp_node->next->next = NULL;
                temp_node = temp_node->next;
            }
        }
        mem_free_fn(addr_data);
        return ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_report_status_and_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum mma_mms_get_report_status_and_address(kal_uint32 report_id, mma_mms_msg_report_info_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_msg_report_info_struct *report_data = NULL;
    kal_uint32 node_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(data);
    report_data = (mms_msg_report_info_struct*)OslMalloc(sizeof(mms_msg_report_info_struct));
    memset(data, 0x00, sizeof(mma_mms_msg_report_info_struct));
    if(report_data == NULL)
    { 
        /* Memory Allocation get failed */
        return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY; 
    }
    node_index = MMSlib_getReportMsgIndex(report_id);
    if(MMSlib_readReportInfoFileNode(MSF_MMS_STORAGE_PHONE, node_index, report_data) != MMS_RESULT_OK)
    {
        OslMfree(report_data);
        return MMA_RESULT_FAIL;
    }
    else
    {
        data->report_type = report_data->report_type;
        data->status = report_data->status;
        data->addr_type = report_data->addr_type;
        data->addr_len = app_ucs2_strlen((const kal_int8*)report_data->address);
        if (data->addr_len > 0)
        {
            app_ucs2_strncpy(
                    (kal_int8*) data->address,
                    (const kal_int8*)report_data->address,
                    MMA_MAX_ADDR_LEN - 1);
		}
    }
    OslMfree(report_data);
    return MMA_RESULT_OK;
}
#endif	/* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */


#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_report_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum mma_mms_get_report_address(kal_uint32 report_id, mma_msg_addr_info_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_msg_report_info_struct *addr_data = NULL;
    kal_uint32 node_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(addr);
    addr_data = (mms_msg_report_info_struct*)OslMalloc(sizeof(mms_msg_report_info_struct));
    memset(addr, 0x00, sizeof(mma_msg_addr_info_struct));
    if(addr_data == NULL)
    { 
        /* Memory Allocation get failed */
        return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY; 
    }
    node_index = MMSlib_getReportMsgIndex(report_id);
    if(MMSlib_readReportInfoFileNode(MSF_MMS_STORAGE_PHONE, node_index, addr_data) != MMS_RESULT_OK)
    {
        OslMfree(addr_data);
        return MMA_RESULT_FAIL;
    }
    else
    {
        addr->addr_type = addr_data->addr_type;
        addr->addr_len = app_ucs2_strlen((const kal_int8*)addr_data->address);
        if (addr->addr_len > 0)
        {
            app_ucs2_strncpy(
                    (kal_int8*) addr->address,
                    (const kal_int8*)addr_data->address,
                    MMA_MAX_ADDR_LEN - 1);
		}
    }
    OslMfree(addr_data);
    return MMA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_delete_report_msg
 * DESCRIPTION
 *  This function is used to delete the report mms entry
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_delete_report_msg(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *list_of_msg = NULL;
    MmsResult result = MMS_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_main_is_in_usb_mode() == TRUE)
    {        
        return MMA_RESULT_FAIL_IN_USB_MODE;
    }
    list_of_msg = OslMalloc(sizeof(kal_uint32) * 2);
    list_of_msg[0] = MMSlib_getReportMsgIndex(msg_id);
    result = MMSlib_deleteEntryFromReportInfoFile(1, list_of_msg);
    OslMfree(list_of_msg);
    return translate_mms_result_to_mma(result);
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_reset_unread_report_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mma_mms_reset_unread_report_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_msgmgr_reset_unread_report_count();
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_unread_report_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mma_mms_get_unread_report_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_msgmgr_get_unread_report_count();
}

#endif  /* __MMI_MMS_REPORT_BOX_SUPPORT__ */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_mms_Icon_sync_info
 * DESCRIPTION
 *  This function is get message info for the mms Icon in FTO
 * PARAMETERS
 *  msg_id      [IN]
 *  wap_mma_get_mms_msg_icon_info_struct  [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_get_mms_Icon_sync_info(kal_uint32 msg_id, wap_mma_get_mms_msg_icon_info_struct *mms_msg_icon_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mms_msg_icon_info == NULL)
    {
        ASSERT(0);
    }
    memset(mms_msg_icon_info, 0, sizeof(wap_mma_get_mms_msg_info_struct));
    
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    else
    {
        mms_msg_icon_info->msg_type = msg_info->mms_msg_type;
        mms_msg_icon_info->priority = msg_info->mms_priority;
        /* For Non-Dual build, by default, it is SIM1 */ 
        mms_msg_icon_info->sim_id = msg_info->msg_sim_id;
        return MMA_RESULT_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_get_mms_msg_thumbnail_info
 * DESCRIPTION
 *  This function is get message thumbnail info in a sync behavior
 * PARAMETERS
 *  msg_id      [IN]
 *  wap_mma_get_mms_thumbnail_info_struct  [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_mms_get_mms_msg_thumbnail_info(kal_uint32 msg_id, wap_mma_get_mms_thumbnail_info_struct *mms_msg_info,
                                              umms_sync_op_mem_alloc_fn mem_alloc_fn,  umms_sync_op_mem_free_fn mem_free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mms_msg_info == NULL)
    {
        ASSERT(0);
    }
    memset(mms_msg_info, 0, sizeof(wap_mma_get_mms_thumbnail_info_struct));

    /* check for the USB mode */
    if (mma_main_is_in_usb_mode() == TRUE)
    {
        return MMA_RESULT_FAIL_IN_USB_MODE;
    }
    
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    else if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
    {
        return MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE;
    }
    else
    {
        mma_result_enum result = MMA_RESULT_OK;
        mms_msg_info_property_struct *property_st = NULL;
        mms_msg_info_large_data_struct *large_data_st = NULL;
        
        /* read the checksum file & provide the data */
        property_st = (mms_msg_info_property_struct*)mem_alloc_fn(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);
        large_data_st = (mms_msg_info_large_data_struct*)mem_alloc_fn(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);
        result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                property_st, large_data_st));
        if(result == MMA_RESULT_OK)
        {
          //  kal_uint32 from_addr_length = 0;
            /* fill the structure */
            if(msg_info->suffix == MMS_SUFFIX_NOTIFICATION)
            {
                mms_msg_info->msg_download_size = property_st->msg_size;
            }
            if(property_st->suffix != MMS_SUFFIX_DELIVERYREPORT &&
				property_st->suffix != MMS_SUFFIX_READREPORT &&
				app_ucs2_strlen((const kal_int8*)large_data_st->subject) > 0)
            {
	            app_ucs2_strncpy(
                            (kal_int8*) mms_msg_info->subject,
                            (const kal_int8*)large_data_st->subject,
                            MMA_MAX_SUBJECT_LEN - 1);
	        }
            else
            {
                kal_wchar *str = NULL;

	            if (property_st->suffix == MMS_SUFFIX_DELIVERYREPORT)
	            {
	                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
	            }
	            else if (property_st->suffix == MMS_SUFFIX_READREPORT)
	            {
	                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
	            }
                if (app_ucs2_strlen((const kal_int8*)str) > 0)
	            {
	                app_ucs2_strncpy(
                            (kal_int8*) mms_msg_info->subject,
                            (const kal_int8*)str,
                            MMA_MAX_SUBJECT_LEN - 1);
	            }
            }
        }
        mem_free_fn(property_st);
        mem_free_fn(large_data_st);
        /* Now fill the Thumbnail detail of mms */
        if((msg_info->suffix != MMS_SUFFIX_DELIVERYREPORT) && (msg_info->suffix != MMS_SUFFIX_READREPORT) && 
            (msg_info->suffix != MMS_SUFFIX_NOTIFICATION) && (result == MMA_RESULT_OK))
        {
            MSF_UINT8 total_object = 0;
            mma_result_enum ret = MMA_RESULT_OK;
            mmsBodyObjectInfo *thumbnail_info = (mmsBodyObjectInfo*)mem_alloc_fn(sizeof(mmsBodyObjectInfo));
            ret = translate_mms_result_to_mma(MMSlib_readBodyObjFile(MMA_TRANSLATE_MSG_ID(msg_id),
                                    (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                    &total_object, thumbnail_info, (mms_mem_alloc_fn)mem_alloc_fn, mem_free_fn));
            if((ret == MMA_RESULT_OK) && (total_object > 0))
            {
                /* Check for the thumbnail information */
                mms_msg_info->thumbnail_info.body_type = (kal_uint8)thumbnail_info->body_data[0].body_type;
                mms_msg_info->thumbnail_info.body_size = (kal_uint32)thumbnail_info->body_data[0].body_size;
                mms_msg_info->thumbnail_info.body_offset = (kal_uint32)thumbnail_info->body_data[0].body_offset;
                mms_msg_info->thumbnail_info.body_name_len = thumbnail_info->body_data[0].body_name_len;
                mms_msg_info->thumbnail_info.is_drm = thumbnail_info->body_data[0].is_drm;
                if(mms_msg_info->thumbnail_info.body_name_len > 0)
                {
                    app_ucs2_strncpy(
                            (kal_int8*) mms_msg_info->thumbnail_info.body_name,
                            (const kal_int8*)thumbnail_info->body_data[0].body_name,
                            MMS_MAX_OBJECT_FILE_NAME_LEN - 1);
                }
            }
            mem_free_fn(thumbnail_info);
        }
        return(result);
    }    
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mma_get_max_slide_no
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mma_get_max_slide_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) wap_custom_get_max_mms_slide();
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_max_recipient_no
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mma_get_max_recipient_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) wap_custom_get_max_mms_address();
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_max_attachment_no
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mma_get_max_attachment_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) wap_custom_get_max_mms_attachment();
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_max_process_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mma_get_max_process_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) ((wap_custom_get_max_mms_msg_size() / 1024) * 300);     /* 30 seconds per 100KB */
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_text_type
 * DESCRIPTION
 *  The function is used to get restricte text mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_restricted_text_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return "text/plain,application/text";
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_image_type
 * DESCRIPTION
 *  The function is used to get restricte image mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_restricted_image_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum content_class = mms_get_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (content_class)
    {
        case MMS_CONTENT_CLASS_IMAGE_BASIC:
        case MMS_CONTENT_CLASS_IMAGE_RICH:
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
        case MMS_CONTENT_CLASS_VIDEO_RICH:
            return "image/jpeg,image/vnd.wap.wbmp,image/gif";
        case MMS_CONTENT_CLASS_TEXT:
        case MMS_CONTENT_CLASS_UNKNOWN:
        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_audio_type
 * DESCRIPTION
 *  The function is used to get restricte audio mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_restricted_audio_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum content_class = mms_get_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (content_class)
    {
        case MMS_CONTENT_CLASS_IMAGE_BASIC:
            return "audio/amr";
        case MMS_CONTENT_CLASS_IMAGE_RICH:
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
        case MMS_CONTENT_CLASS_VIDEO_RICH:
            return "audio/amr,audio/midi,audio/mid,x-music/x-midi,audio/sp-midi";
        case MMS_CONTENT_CLASS_TEXT:
        case MMS_CONTENT_CLASS_UNKNOWN:
        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_video_type
 * DESCRIPTION
 *  The function is used to get restricte video mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_restricted_video_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum content_class = mms_get_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (content_class)
    {
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
        case MMS_CONTENT_CLASS_VIDEO_RICH:
            return "video/3gpp,video/3gpp2,video/mpeg,video/mp4";
        case MMS_CONTENT_CLASS_TEXT:
        case MMS_CONTENT_CLASS_IMAGE_BASIC:
        case MMS_CONTENT_CLASS_IMAGE_RICH:
        case MMS_CONTENT_CLASS_UNKNOWN:
        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_restricted_attachment_type
 * DESCRIPTION
 *  The function is used to get restricte attachment mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_restricted_attachment_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum content_class = mms_get_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (content_class)
    {
        case MMS_CONTENT_CLASS_TEXT:
            return "text/plain,application/text";
        case MMS_CONTENT_CLASS_IMAGE_BASIC:
            return "text/plain,application/text,\
                image/jpeg,image/vnd.wap.wbmp,image/gif,\
                audio/amr,\
                text/x-vcard,text/x-vcalendar";
        case MMS_CONTENT_CLASS_IMAGE_RICH:
            return "text/plain,application/text,\
                image/jpeg,image/vnd.wap.wbmp,image/gif,\
                audio/amr,audio/midi,audio/mid,x-music/x-midi,audio/sp-midi,\
                text/x-vcard,text/x-vcalendar";
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
        case MMS_CONTENT_CLASS_VIDEO_RICH:
            return "text/plain,application/text,\
                image/jpeg,image/vnd.wap.wbmp,image/gif,\
                audio/amr,audio/midi,audio/mid,x-music/x-midi,audio/sp-midi,\
                video/3gpp,video/3gpp2,video/mpeg,video/mp4,\
                text/x-vcard,text/x-vcalendar";
        case MMS_CONTENT_CLASS_UNKNOWN:
        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_image_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const char *mma_get_image_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_mms_image_type();
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_text_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const char *mma_get_text_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_mms_text_type();
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_audio_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const char *mma_get_audio_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_mms_audio_type();
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_video_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const char *mma_get_video_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_mms_video_type();
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_attachment_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const char *mma_get_attachment_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_default_smil_bg_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mma_get_default_smil_bg_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (0x00FFFFFF);
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_default_smil_fg_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mma_get_default_smil_fg_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (0x00000000);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_text_uintvar_overhead_size
 * DESCRIPTION
 *  When UC calculate text size internally, it misses DataLen uintvar overhead added for multipart.
 *  The overhead value is the value incremented on mma_get_uintvar_length_bytes(0)
 * PARAMETERS
 *  utf8_byte_size      [IN]        UTF8 text object size
 * RETURNS
 *  overhead size in bytes
 *****************************************************************************/
kal_uint32 mma_uc_calc_text_uintvar_overhead_size(kal_uint32 utf8_byte_size)
{
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
#else /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
    return (mma_get_uintvar_length_bytes(utf8_byte_size) - mma_get_uintvar_length_bytes(0));
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_header_attribute_size
 * DESCRIPTION
 *  Calculate MMS header to/cc/bcc/subject field length
 * PARAMETERS
 *  attr        [IN]        
 *  data        [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 mma_uc_calc_header_attribute_size(mma_header_attr_enum attr, const kal_wchar *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;
    char *utf8_data = NULL;

#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    kal_uint32 i = 0;
    MmsCharset charset = MMS_US_ASCII;
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL || *data == L'\0')
    {
        return 0;
    }

    utf8_data = mma_um_ucs2_to_utf8_string(data);  /* work fine for ascii */
    if (utf8_data != NULL)
    {

        switch (attr)
        {
            case MMA_HEADER_ADDRESS:
        #ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
                if (IS_EMAIL(utf8_data))
                {
                    size = strlen(utf8_data) + 2;   /* 0x97 + [Email] + '\0' */
                }
                else
                {
                    /* UC use ASCII string to save phone number */
                    size = strlen((char*)utf8_data) + strlen("/TYPE=PLMN") + 2;    /* 0x97 + [#]/TYPE=PLMN + '\0' */
                }
        #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
                break;

            case MMA_HEADER_SUBJECT:
            #ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
                size = strlen(utf8_data);
            #else /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
                for (i = 0; *(utf8_data + i) != '\0'; i++)
                {
                    if ((unsigned char)*(utf8_data + i) > 0x7F)
                    {
                        charset = MMS_UTF8;
                    }
                }

                if (charset == MMS_US_ASCII)
                {
                    size = strlen(utf8_data) + 2;   /* 0x96 + [Subject] + '\0' */
                }
                else
                {
                    size += (strlen(utf8_data) + 3);    /* 0x96 + 0xea + [Subject] + '\0' */
                    size = ((unsigned char)*utf8_data > 0x7F) ? (size + 1) : size;  /* 0x96 + 0xea + (0x7F) + [Subject] + '\0' */

                    /* Value-length */
                    size += mma_get_value_length_bytes(size);   /* 0x96 + value-length + 0xea + (0x7F) + [Subject] + '\0' */
                }
            #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
                break;

            default:
                ASSERT(0);
        }
    
        OslMfree(utf8_data);
    }
    return size;

}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_image
 * DESCRIPTION
 *  Set the image filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_image(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET(filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
#ifdef GDI_USING_PNG
    FMGR_FILTER_SET(filter, FMGR_TYPE_PNG);
#endif 
#ifdef JPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif /* JPG_DECODE */ 
#ifdef SVG_SUPPORT
    FMGR_FILTER_SET(filter, FMGR_TYPE_SVG);
#endif 

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_image_restricted
 * DESCRIPTION
 *  Set the image filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_image_restricted(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    switch (mms_get_content_class())
    {

        case MMS_CONTENT_CLASS_VIDEO_RICH:
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
        case MMS_CONTENT_CLASS_IMAGE_RICH:
        case MMS_CONTENT_CLASS_IMAGE_BASIC:
            FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
            FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
            FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
    #ifdef JPG_DECODE
            FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
            FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
    #endif /* JPG_DECODE */ 
            break;
    }
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_audio
 * DESCRIPTION
 *  Set the audio filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_audio(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET(filter, FMGR_TYPE_IMY);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
    // FMGR_FILTER_SET(filter, FMGR_TYPE_VM);   /* cannot get duration */
#ifdef AAC_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AAC);
#endif 
#ifdef DAF_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_DAF);
#endif 
    
#ifdef  __RM_DEC_SUPPORT__
   FMGR_FILTER_SET(filter, FMGR_TYPE_RA); 
#endif
#ifdef AMRWB_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);
#endif 
#ifndef __CPU_ARM7TDMI__ /* MT6205B */
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFC);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AU);
    FMGR_FILTER_SET(filter, FMGR_TYPE_SND);
#endif /* __CPU_ARM7TDMI__ *//* MT6205B */ 
#if defined(M4A_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_M4A);
#endif 
#if defined(EXT_AUDIO_CHIP) || defined(MMF_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_MMF);
#endif 
#ifdef WMA_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_WMA);
#endif 
#ifdef MUSICAM_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP2);
#endif 

#if !defined (MP4_DECODE) && defined(__MMI_PURE_AUDIO__)
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif
#ifdef __APE_DECODE__
	    FMGR_FILTER_SET(filter, FMGR_TYPE_APE);
#endif

#ifdef __VORBIS_DECODE__
	    FMGR_FILTER_SET(filter, FMGR_TYPE_OGG);
#endif

#ifdef __FLAC_DECODE__ 
	    FMGR_FILTER_SET(filter, FMGR_TYPE_FLAC);
#endif	/* __FLAC_DECODE__ */

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_audio_restricted
 * DESCRIPTION
 *  Set the audio filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_audio_restricted(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    switch (mms_get_content_class())
    {
        case MMS_CONTENT_CLASS_VIDEO_RICH:
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
        case MMS_CONTENT_CLASS_IMAGE_RICH:
            FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
            FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);

        case MMS_CONTENT_CLASS_IMAGE_BASIC:
            FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
            break;
    }
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_video
 * DESCRIPTION
 *  Set the video filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_video(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
#ifdef __MMI_MMS_VIDEO_FEATURE__
#ifdef MP4_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif /* MP4_DECODE */ 
#ifdef __RM_DEC_SUPPORT__
    FMGR_FILTER_SET(filter, FMGR_TYPE_RV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_RM);
    FMGR_FILTER_SET(filter, FMGR_TYPE_RMVB);
#endif /* __RM_DEC_SUPPORT__ */ 

#ifdef __FLV_FILE_FORMAT_SUPPORT__
	 FMGR_FILTER_SET(filter, FMGR_TYPE_FLV); 				/*!< F4A Audio */
	 FMGR_FILTER_SET(filter, FMGR_TYPE_F4V);
#endif


#ifdef MJPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AVI);
#endif 
#ifdef __MKV_FILE_FORMAT_SUPPORT__ 
	    FMGR_FILTER_SET(filter, FMGR_TYPE_MKV);
	    FMGR_FILTER_SET(filter, FMGR_TYPE_WEBM);
#endif	/* __MKV_FILE_FORMAT_SUPPORT__ */

#endif
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_video_restricted
 * DESCRIPTION
 *  Set the video filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_video_restricted(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
#ifdef __MMI_MMS_VIDEO_FEATURE__
    switch (mms_get_content_class())
    {
        case MMS_CONTENT_CLASS_VIDEO_RICH:
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
    #ifdef MP4_DECODE
            FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
            FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
            FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
    #endif /* MP4_DECODE */ 

        case MMS_CONTENT_CLASS_IMAGE_RICH:
        case MMS_CONTENT_CLASS_IMAGE_BASIC:
            break;
    }
#endif
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_attachment
 * DESCRIPTION
 *  Set the attachment filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_attachment(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET_ALL(filter);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
    FMGR_FILTER_CLEAR(filter, FMGR_TYPE_DM);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_attachment_restricted
 * DESCRIPTION
 *  Set the attachment filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_attachment_restricted(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    switch (mms_get_content_class())
    {
        case MMS_CONTENT_CLASS_VIDEO_RICH:
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
    #ifdef MP4_DECODE
            FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
            FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
            FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
    #endif /* MP4_DECODE */ 

        case MMS_CONTENT_CLASS_IMAGE_RICH:
            FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
            FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);

        case MMS_CONTENT_CLASS_IMAGE_BASIC:
    #ifdef __MMI_EBOOK_READER__
            FMGR_FILTER_SET(filter, FMGR_TYPE_EBOOK_TXT);
    #endif 
            FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
            FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
            FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
    #ifdef JPG_DECODE
            FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
            FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
    #endif /* JPG_DECODE */ 
            FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
    #ifdef __MMI_VCARD__
            FMGR_FILTER_SET(filter, FMGR_TYPE_VCF);
    #endif 
    #ifdef __MMI_VCALENDAR__
            FMGR_FILTER_SET(filter, FMGR_TYPE_VCS);
    #endif 
            break;
    }

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter
 * DESCRIPTION
 *  Get free file space
 * PARAMETERS
 *  filter                      [IN]         
 *  media_type_to_insert        [IN]        
 * RETURNS
 *  free space(?)
 *****************************************************************************/
void mma_uc_set_file_mgr_filter(void *filter, mma_uc_filter_mode_enum media_type_to_insert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type_to_insert)
    {
        case MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE:
            mma_uc_set_file_mgr_filter_for_image((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE:
            mma_uc_set_file_mgr_filter_for_image_restricted((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE:
            mma_uc_set_file_mgr_filter_for_audio((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE:
            mma_uc_set_file_mgr_filter_for_audio_restricted((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE:
            mma_uc_set_file_mgr_filter_for_video((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE:
            mma_uc_set_file_mgr_filter_for_video_restricted((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE:
            mma_uc_set_file_mgr_filter_for_attachment((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_ATTACHMENT_RESTRICTED_MODE:
            mma_uc_set_file_mgr_filter_for_attachment_restricted((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_TEXT_OPEN_MODE:
        case MMA_UC_FILTER_MODE_TEXT_RESTRICTED_MODE:
            break;
    }

    return;
}


#ifdef __MMI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  mma_um_vcard_get_version
 * DESCRIPTION
 *  This function is to used to get the version of the Vcard. Only called from MMI Task
 * PARAMETERS      
 *  filepath                [IN]       
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_um_vcard_get_version(char *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VP_HANDLE vp;
    S32 fs_error;
    vcard_version_enum version;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vp = vcard_open_parser((U16*) filepath, VCARD_PROPERTY_NONE, &fs_error);
    if (!vp)
    {
        return MMA_RESULT_FAIL_FILE_CORRUPTED;
    }

    if(vcard_parse(vp, NULL) == VCARD_RESULT_FAIL)
    {
        vcard_close_parser(vp);
        return MMA_RESULT_FAIL_FILE_CORRUPTED;
    }

    version = vcard_get_parse_version(vp);
    vcard_close_parser(vp);
    if (version == VCARD_VERSION_3_0)
    {
        return MMA_RESULT_OK_WITH_WARNING_CONTENT;
    }
    else  /* VCARD_VERSION_2_1 */
    {
        /* Right now, ENUM have only two value. Need to check when Vcard add more ENUM entry */
        return MMA_RESULT_OK;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mma_uc_insert_object_check
 * DESCRIPTION
 *  This function is to
 * CALLS
 *  
 * PARAMETERS
 *  creation_mode           [IN]        
 *  filepath                [IN]        
 *  type                    [IN]        
 *  current_msg_size        [IN]        
 *  max_msg_size            [IN]        
 *  info                    [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_uc_insert_object_check(mma_insert_info_struct *insert_info,
        mma_insert_check_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = NULL;
    kal_uint32 add_size = 0;
    char *utf8_filepath = NULL;
	const char *mime = NULL;

#ifdef __DRM_SUPPORT__
    mma_drm_method_enum drmMethod = MMA_DRM_METHOD_NONE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_VIDEO_FEATURE__
    if (insert_info->insert_type == MMA_INSERT_VIDEO)
	{
		insert_info->insert_type = MMA_INSERT_ATTACHMENT;
	}
#endif

    memset(info, 0, sizeof(mma_insert_check_struct));
    utf8_filepath = mma_um_ucs2_to_utf8_string(insert_info->filepath);
	mime = mma_get_mime_type_from_filename_and_mime_string(utf8_filepath, NULL);
    info->result = KAL_TRUE;
    info->detail_result = MMA_RESULT_OK;
    {
        kal_wchar* extension = mms_get_file_extension(insert_info->filepath);
        if(extension && app_ucs2_strcmp((const kal_int8*)extension, (const kal_int8*)L"dm") == 0)
        {
            info->result = KAL_FALSE;
            info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
            goto check_end;
        }
    }
    file_handle = DRM_open_file((kal_wchar *)insert_info->filepath, FS_READ_ONLY, DRM_PERMISSION_NONE);
    if (file_handle < 0)
    {
        if (file_handle == FS_FILE_NOT_FOUND)
        {
            info->detail_result = MMA_RESULT_FAIL_FILE_NOT_FOUND;
        }
        else if (file_handle == FS_PATH_NOT_FOUND ||
			file_handle == FS_DRIVE_NOT_FOUND)
        {
            info->detail_result = MMA_RESULT_FAIL_FOLDER_NOT_FOUND;
        }
        else
        {
            info->detail_result = MMA_RESULT_FAIL_FILE_IO;
        }
        info->result = KAL_FALSE;
        goto check_end;
    }
    else if (mma_get_mmi_file_size(file_handle, insert_info->filepath) == 0)
    {
        info->result = KAL_FALSE;
        info->detail_result = MMA_RESULT_FAIL_FILE_EMPTY;
        goto check_end;
    }

    /* Check DRM type */
#ifdef __DRM_SUPPORT__
    drmMethod = mma_um_drm_get_method_type(file_handle, NULL);
    if (drmMethod == MMA_DRM_METHOD_NONE)
    {
        info->drm_type = MMA_DRM_NONE;
    }
    else if (drmMethod == MMA_DRM_METHOD_FORWARD_LOCK || drmMethod == MMA_DRM_METHOD_COMBINED_DELIVERY)
    {
        info->result = KAL_FALSE;
        info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
        info->drm_type = MMA_DRM_FL_CD;
        goto check_end;
    }
    else
    {
        if (mma_um_drm_check_right((S8*)insert_info->filepath) == KAL_TRUE)
        {
            info->drm_type = MMA_DRM_SD;
        }
        else
        {
            info->drm_type = MMA_DRM_SD_NO_RIGHT;
        }
    }
#else /* __DRM_SUPPORT__ */ 
    info->drm_type = MMA_DRM_NONE;
#endif /* __DRM_SUPPORT__ */ 

    /* Check insert type */
    if (insert_info->insert_type == MMA_INSERT_UNKNOWN)
    {
        const char *list = NULL;

        switch (insert_info->creation_mode)
        {
            case MMA_CREATION_MODE_FREE:
            case MMA_CREATION_MODE_WARNING:
                if (strstr(mma_get_text_type(), mime))
                {
                    insert_info->insert_type = MMA_INSERT_TEXT;
                }
                else if (strstr(mma_get_image_type(), mime))
                {
                    insert_info->insert_type = MMA_INSERT_IMAGE;
                }
                else if (strstr(mma_get_audio_type(), mime))
                {
                    insert_info->insert_type = MMA_INSERT_AUDIO;
                }
#ifdef __MMI_MMS_VIDEO_FEATURE__
                else if (strstr(mma_get_video_type(), mime))
                {
                    insert_info->insert_type = MMA_INSERT_VIDEO;
                }
#endif
                else
                {
#ifdef __MMI_VCARD__
                    if (insert_info->creation_mode == MMA_CREATION_MODE_WARNING && 
						strstr(mma_get_mms_vcard_type(), mime))
                    {
                        mma_result_enum result = MMA_RESULT_OK;
                        result = mma_um_vcard_get_version((S8*)insert_info->filepath);

                        if (result == MMA_RESULT_OK)
                        {
                            // Valid version
                        }
                        else if(result == MMA_RESULT_OK_WITH_WARNING_CONTENT)
                        {
                            info->detail_result = MMA_RESULT_OK_WITH_WARNING_CONTENT;
                        }
                        else
                        {
                            info->result = KAL_FALSE;
                            info->detail_result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                            goto check_end;
                        }
                    }
#endif // __MMI_VCARD__
                    insert_info->insert_type = MMA_INSERT_ATTACHMENT;
                }
                break;
            case MMA_CREATION_MODE_RESTRICTED:
                if ((list = mma_get_restricted_text_type()) != NULL && strstr(list, mime))
                {
                    insert_info->insert_type = MMA_INSERT_TEXT;
                }
                else if ((list = mma_get_restricted_image_type()) != NULL && strstr(list, mime))
                {
                    insert_info->insert_type = MMA_INSERT_IMAGE;
                }
                else if ((list = mma_get_restricted_audio_type()) != NULL && strstr(list, mime))
                {
                    insert_info->insert_type = MMA_INSERT_AUDIO;
                }
#ifdef __MMI_MMS_VIDEO_FEATURE__
                else if ((list = mma_get_restricted_video_type()) != NULL && strstr(list, mime))
                {
                    insert_info->insert_type = MMA_INSERT_VIDEO;
                }
#endif
                else if ((list = mma_get_restricted_attachment_type()) != NULL && strstr(list, mime))
                {
#ifdef __MMI_VCARD__
                   if (strstr(mma_get_mms_vcard_type(), mime))
                    {
                        mma_result_enum result = MMA_RESULT_OK;
                        result =  mma_um_vcard_get_version((S8*)insert_info->filepath);
                         if (result == MMA_RESULT_OK)
                        {
                            // Valid version
                        }
                        else if(result == MMA_RESULT_OK_WITH_WARNING_CONTENT)
                        {
                            info->result = KAL_FALSE;
                            info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
                            info->creation_mode_violate = KAL_TRUE;
                            goto check_end;
                        }
                        else
                        {
                            info->result = KAL_FALSE;
                            info->detail_result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                            goto check_end;
                        }
                    }
#endif // __MMI_VCARD__
                    insert_info->insert_type = MMA_INSERT_ATTACHMENT;
                }
                else
                {
                    info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
                    info->creation_mode_violate = KAL_TRUE;
                    goto check_end;
                }
                break;
            default:
                ASSERT(0);
                break;
        }
    }
#ifndef __MMI_MMS_VIDEO_FEATURE__
	if (insert_info->insert_type == MMA_INSERT_VIDEO)
	{
		insert_info->insert_type = MMA_INSERT_ATTACHMENT;
	}
/*#elif defined(__MMI_VIDEO_PLAY_SUPPORT__)
    // MMA will not put intelligence for Audio only video file
	if ((insert_info->insert_type ==  MMA_INSERT_AUDIO || insert_info->insert_type == MMA_INSERT_VIDEO) &&
        (mmi_ucs2str((S8*) insert_info->filepath, (S8*) L"3gp") != NULL || 
		mmi_ucs2str((S8*) insert_info->filepath, (S8*) L"mp4") != NULL))
    {
        if (mdi_audio_is_pure_audio((void*)insert_info->filepath) == KAL_TRUE)
        {
            insert_info->insert_type = MMA_INSERT_AUDIO;
        }
        else
        {
            insert_info->insert_type = MMA_INSERT_VIDEO;
        }
    }*/
#endif
    info->insert_type = insert_info->insert_type;   /* ? */

    /* Check size & creation mode */
    switch (insert_info->insert_type)
    {
        case MMA_INSERT_TEXT:            
        case MMA_INSERT_IMAGE:            
        case MMA_INSERT_AUDIO:           
        case MMA_INSERT_VIDEO:
        case MMA_INSERT_REF:
            add_size = mma_uc_calc_object_multipart_size(insert_info->filepath);
			if(insert_info->mms_type !=  MMA_MMS_TYPE_MIXED_MMS)
			{
                add_size += mma_uc_calc_object_smil_size(insert_info->insert_type, insert_info->filepath);
			}
            break;
        case MMA_INSERT_ATTACHMENT:
            add_size = mma_uc_calc_object_multipart_size(insert_info->filepath);
            break;
        default:
            ASSERT(0);
    }

#if defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) || defined(__MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__)
#ifndef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    if (srv_wap_prof_get_active_profile_connection_type((srv_wap_prof_app_id_enum) SRV_WAP_PROF_APPID_MMS) >
        SRV_WAP_PROF_CONN_TYPE_HTTP && insert_info->current_msg_size + add_size > MMA_MAX_WAP_CONN_MSG_SIZE)
    {
        info->result = KAL_FALSE;
        info->detail_result = MMA_RESULT_FAIL_WAP_CONN_MAX_MSG_SIZE_REACHED;
        info->oversize = KAL_TRUE;
        goto check_end;
    }
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

    switch (insert_info->creation_mode)
    {
        case MMA_CREATION_MODE_FREE:
            if (insert_info->current_msg_size + add_size > insert_info->max_msg_size)
            {
                info->result = KAL_FALSE;
                info->detail_result = MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
                info->oversize = KAL_TRUE;
                goto check_end;
            }
            else
            {
                info->oversize = KAL_FALSE;
            }
            info->creation_mode_violate = KAL_FALSE;
            break;

        case MMA_CREATION_MODE_WARNING:
            if (insert_info->current_msg_size + add_size > insert_info->max_msg_size)
            {
                info->result = KAL_FALSE;
                info->detail_result = MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
                info->oversize = KAL_TRUE;
                goto check_end;
            }
            else if (insert_info->current_msg_size + add_size > mms_get_max_msg_size_in_restricted_mode())
            {
                info->detail_result = MMA_RESULT_OK_WITH_WARNING_CONTENT;
            }
            info->oversize = KAL_FALSE;

            if (mma_um_is_restricted_type(mms_get_content_class(),  file_handle, utf8_filepath, mime) == KAL_FALSE)
            {
                info->detail_result = MMA_RESULT_OK_WITH_WARNING_CONTENT;
            }
#ifdef __MMI_VCARD__
			else if (strstr(mma_get_mms_vcard_type(), mime))
			{
				mma_result_enum result = MMA_RESULT_OK;
				result =  mma_um_vcard_get_version((S8*)insert_info->filepath);
                 if (result == MMA_RESULT_OK)
                {
                    // Valid version
                }
                else if(result == MMA_RESULT_OK_WITH_WARNING_CONTENT)
                {
                    info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_OK_WITH_WARNING_CONTENT;
                    info->creation_mode_violate = KAL_TRUE;
                    goto check_end;
                }
                else
                {
                    info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                    goto check_end;
                }
			} 
#endif // __MMI_VCARD__
            info->creation_mode_violate = KAL_FALSE;
            break;

        case MMA_CREATION_MODE_RESTRICTED:
            if (insert_info->current_msg_size + add_size > insert_info->max_msg_size)
            {
                info->result = KAL_FALSE;
                info->detail_result = MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
                info->oversize = KAL_TRUE;
                goto check_end;
            }
            if (insert_info->current_msg_size + add_size > mms_get_max_msg_size_in_restricted_mode())
            {
                info->result = KAL_FALSE;
                info->detail_result = MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED;
                info->oversize = KAL_TRUE;
                info->creation_mode_violate = KAL_TRUE;
                goto check_end;
            }
            else
            {
                info->oversize = KAL_FALSE;
            }

            if (mma_um_is_restricted_type(mms_get_content_class(),  file_handle, utf8_filepath, mime) == KAL_FALSE)
            {
					info->result = KAL_FALSE;
					info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
					info->creation_mode_violate = KAL_TRUE;
					goto check_end;
            }
#ifdef __MMI_VCARD__
			else if (strstr(mma_get_mms_vcard_type(), mime))
			{
				mma_result_enum result = MMA_RESULT_OK;
				result =  mma_um_vcard_get_version((S8*)insert_info->filepath);
                if (result == MMA_RESULT_OK)
                {
                    // Valid version
                }
                else if(result == MMA_RESULT_OK_WITH_WARNING_CONTENT)
                {
                    info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
                    info->creation_mode_violate = KAL_TRUE;
                    goto check_end;
                }
                else
                {
                    info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                    goto check_end;
                }
			}
#endif // __MMI_VCARD__
            else
            {
                  info->creation_mode_violate = KAL_FALSE;
               // goto check_end;
            }
            break;

        default:
            ASSERT(0);
    }


    /* Check validity of the media */
    if (info->drm_type == MMA_DRM_NONE)
    {
        switch (insert_info->insert_type)
        {
            case MMA_INSERT_IMAGE:
            {
                applib_mime_type_struct *mime_struct = NULL;
                mma_result_enum result = MMA_RESULT_OK;

                mime_struct = applib_mime_get_file_type((kal_wchar*) insert_info->filepath);
                if (mime_struct != NULL && mime_struct->mime_subtype != MIME_SUBTYPE_M3D && mime_struct->mime_subtype != MIME_SUBTYPE_SVG)
                {
                    if ((result = mma_check_image_file(insert_info->filepath)) != MMA_RESULT_OK)
                    {
                        info->result = KAL_FALSE;
                        info->detail_result = result;
                        goto check_end;
                    }
                }
            }
                break;
            case MMA_INSERT_AUDIO:
                break;
            case MMA_INSERT_VIDEO:
#ifndef __COSMOS_MMI_PACKAGE__
        #if defined(__MMI_VIDEO_PLAY_SUPPORT__)
            {
                if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE, NULL) > 0) 
                {
                    /* Currently in Video call */ 
					info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_FAIL_IN_VIDEO_CALL;
                    goto check_end;
                }
                else
                {
                    MDI_RESULT result_video = 0;
                    mdi_video_info_struct video_clip;

                    mdi_video_ply_enable_aud_only_video_clip();
                    result_video = mdi_video_ply_open_clip_file(0, (S8*) insert_info->filepath, &video_clip);
                    if (result_video != MDI_RES_VDOPLY_SUCCEED)
                    {
                        info->result = KAL_FALSE;
                        if (result_video == MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT)
                        {
                            info->detail_result = MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;
                        }
                        else
                        {
                            info->detail_result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                        }
                        goto check_end;
                    }
                    else
                    {
                        mdi_video_ply_close_clip_file();
                    }
                }
            }
        #endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) */ 
#endif
                break;
            default:
                break;

        }
    }

  check_end:
    if (file_handle >= 0)
    {
        DRM_close_file(file_handle);
    }
    if(utf8_filepath)
    {
        OslMfree(utf8_filepath);
    }
    return;
}

#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
 
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_header_attribute_addr_size_int
 * DESCRIPTION
 *  Internal function to calculate MMS header to/cc/bcc field length from UC structure
 * PARAMETERS
 *  type        [IN]        
 *  data        [IN]        
 *  attr(?)     [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
static kal_uint32 mma_uc_calc_header_attribute_addr_size_int(srv_uc_address_type_enum type, const kal_wchar *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;
    char *utf8_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_UC_ADDRESS_TYPE_PHONE_NUMBER:
            /* UC use ASCII string to save phone number */
            size = strlen((char*)data) + strlen("/TYPE=PLMN") + 2;     /* 0x97 + [#]/TYPE=PLMN + '\0' */
            break;

        case SRV_UC_ADDRESS_TYPE_EMAIL:
            if ((utf8_data = mma_um_ucs2_to_utf8_string(data)) != NULL)
            {
                size = strlen(utf8_data) + 2;   /* 0x97 + [Email] + '\0' */
                if(utf8_data)
                {
                    OslMfree(utf8_data);
                }
            }
            break;

        default:
            ASSERT(0);
    }

    return size;
}

#else /*for slim MMS __MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/

static kal_uint32 mma_mms_calc_header_attribute_addr_size_int(mma_addr_type_enum type, const kal_wchar *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;
    char *utf8_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMA_ADDR_TYPE_PHONE_NUMBER:
            /* UC use ASCII string to save phone number */
            size = strlen((char*)data) + strlen("/TYPE=PLMN") + 2;     /* 0x97 + [#]/TYPE=PLMN + '\0' */
            break;

        case MMA_ADDR_TYPE_EMAIL:
            if ((utf8_data = mma_um_ucs2_to_utf8_string(data)) != NULL)
            {
                size = strlen(utf8_data) + 2;   /* 0x97 + [Email] + '\0' */
                if(utf8_data)
                {
                    OslMfree(utf8_data);
                }
            }
            break;

        default:
            ASSERT(0);
    }

    return size;
}
#endif /*UC ON or SLIM MMS  __MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/

#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 



#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_header_size
 * DESCRIPTION
 *  Calculate MMS header size including
 *  - X-Mms-Message-Type: 8C 80
 *  - X-Mms-Transaction-Id: 98 XX XX XX XX XX XX XX XX XX XX 00  (possible longest length)
 *  - X-Mms-MMS_Version: 8D 9X
 *  - Date: 85 04 XX XX XX XX  (possible longest length)
 *  - From: 89 01 81
 *  - To: mma_uc_calc_header_attribute_addr_size_int()
 *  - Cc: mma_uc_calc_header_attribute_addr_size_int()
 *  - Bcc: mma_uc_calc_header_attribute_addr_size_int()
 *  - Subject: mma_uc_calc_header_attribute_size()
 *  - X-Mms-Expiry: 88 [Value-Length] 81 [Short-length] XX XX (XX)
 *  - X-Mms-Delivery-Time: 87 [Value-Length:05] 81 [Short-length:03] 01 51 80  (approximate: use 1 day as delivery time)
 *  - X-Mms-Sender-Visibility: 94 80
 *  - X-Mms-Priority: 8F 8X
 *  - X-Mms-Delivery-Report: 86 8X
 *  - X-Mms-Read-Report: 90 8X
 *  - Content-type: 84  [Value-Length:1D] B3 89 [MMS_MEDIA_TYPE_STRING_SMIL: application/smil] 00 8A 3C [MEAlib_getSmilContentId()] 3E 00
 *  - nEntries: [uintvar]
 * PARAMETERS
 *  input       [IN]        
 *  mms(?)      [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 mma_mms_calc_slim_msg_header_size(const void *input, mma_mms_type_enum mms_type)
{
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;
    mma_mms_description_struct *mms = (mma_mms_description_struct*) input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Subject */
    size += mma_uc_calc_header_attribute_size(MMA_HEADER_SUBJECT, (kal_wchar*) mms->header->header->subject.text);    
#else /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

    mma_mms_description_struct *mms = (mma_mms_description_struct*) input;
    mma_mms_addr_list_struct *addr = NULL;
    kal_uint32 size = 0, tmp_size = 0;

    /* X-Mms-Message-Type ~ From */
    size = 2 + 12 + 2 + 6 + 3;

    /* To */
    addr = mms->header->header->to;
    while (addr)
    {
        size += mma_mms_calc_header_attribute_addr_size_int((mma_addr_type_enum)addr->addr_type, (kal_wchar*) addr->address);
        addr = addr->next;
    }

    /* Cc */
    addr = mms->header->header->cc;
    while (addr)
    {
        size += mma_mms_calc_header_attribute_addr_size_int((mma_addr_type_enum)addr->addr_type, (kal_wchar*) addr->address);
        addr = addr->next;
    }

    /*Bcc*/
    addr = mms->header->header->bcc;
    while (addr)
    {
        size += mma_mms_calc_header_attribute_addr_size_int((mma_addr_type_enum)addr->addr_type, (kal_wchar*) addr->address);
        addr = addr->next;
    }

    /*Subject */
    size += mma_uc_calc_header_attribute_size(MMA_HEADER_SUBJECT, (kal_wchar*) mms->header->header->subject.text);

    /* X-Mms-Expiry */
    switch (mms->header->header->expiry_time)
    {
        case MMA_EXPIRY_1_HOUR:
            size += 6;  /* 88 [Value-Length:04] 81 [Short-length:02] XX XX */
            break;
        case MMA_EXPIRY_12_HOURS:
            size += 6;
            break;
        case MMA_EXPIRY_1_DAY:
            size += 7;  /* 88 [Value-Length:05] 81 [Short-length:03] XX XX XX */
            break;
        case MMA_EXPIRY_1_WEEK:
            size += 7;
            break;
        case MMA_EXPIRY_MAX:
            break;
    }

    /* X-Mms-Delivery-Time */
    switch (mms->header->header->delivery_time)
    {
        case MMA_DELIVERY_IMMEDIATE:
            break;
        case MMA_DELIVERY_1_HOUR:
            size += 6;  /* 87 [Value-Length:04] 81 [Short-length:02] XX XX */
            break;
        case MMA_DELIVERY_12_HOURS:
            size += 6;  /* 87 [Value-Length:04] 81 [Short-length:02] XX XX */
            break;
        case MMA_DELIVERY_24_HOURS:
            size += 7;  /* 87 [Value-Length:05] 81 [Short-length:03] XX XX XX */
            break;
    }

    /* X-Mms-Sender-Visibility */
	switch (mma_mms_convert_visibility_enum_value_to_bool((mma_mms_sender_visibility_enum)mms->header->header->visibility))
    {
        case FALSE:
            break;
        case TRUE:
            size += 2;  /* 94 80 */
            break;
    }

    /* X-Mms-Priority ~ X-Mms-Read-Report */
    size += (2 + 2 + 2);

    /* Content-type */
	if (mms_type != MMA_MMS_TYPE_MIXED_MMS)
	{
        tmp_size = 5 + strlen(MMS_MEDIA_TYPE_STRING_SMIL) + strlen(MMA_CFG_SMIL_CONTENT_ID) + strlen("<>");
        size += (1 + mma_get_uintvar_length_bytes(tmp_size) + tmp_size);
    
        /* nEntries */
        size += mma_get_uintvar_length_bytes(mms->body->obj_no + 1);    /* add SMIL part */
	}
	else
	{
		size += mma_get_uintvar_length_bytes(mms->body->obj_no);    
	}

#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

    /* Add Extra Header Size which server might add to PDU*/
    size += MMA_EXTRA_HEADER_BUFFER;
    return size;
}
#elif (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_header_size
 * DESCRIPTION
 *  Calculate MMS header size including
 *  - X-Mms-Message-Type: 8C 80
 *  - X-Mms-Transaction-Id: 98 XX XX XX XX XX XX XX XX XX XX 00  (possible longest length)
 *  - X-Mms-MMS_Version: 8D 9X
 *  - Date: 85 04 XX XX XX XX  (possible longest length)
 *  - From: 89 01 81
 *  - To: mma_uc_calc_header_attribute_addr_size_int()
 *  - Cc: mma_uc_calc_header_attribute_addr_size_int()
 *  - Bcc: mma_uc_calc_header_attribute_addr_size_int()
 *  - Subject: mma_uc_calc_header_attribute_size()
 *  - X-Mms-Expiry: 88 [Value-Length] 81 [Short-length] XX XX (XX)
 *  - X-Mms-Delivery-Time: 87 [Value-Length:05] 81 [Short-length:03] 01 51 80  (approximate: use 1 day as delivery time)
 *  - X-Mms-Sender-Visibility: 94 80
 *  - X-Mms-Priority: 8F 8X
 *  - X-Mms-Delivery-Report: 86 8X
 *  - X-Mms-Read-Report: 90 8X
 *  - Content-type: 84  [Value-Length:1D] B3 89 [MMS_MEDIA_TYPE_STRING_SMIL: application/smil] 00 8A 3C [MEAlib_getSmilContentId()] 3E 00
 *  - nEntries: [uintvar]
 * PARAMETERS
 *  input       [IN]        
 *  mms(?)      [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 mma_uc_calc_header_size(const void *input, mma_mms_type_enum mms_type)
{
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;
    srv_uc_msg_struct *mms = (srv_uc_msg_struct*) input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Subject */
    size += mma_uc_calc_header_attribute_size(MMA_HEADER_SUBJECT, (kal_wchar*) mms->subject);    
#else /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

    srv_uc_msg_struct *mms = (srv_uc_msg_struct*) input;
    srv_uc_addr_struct *addr = NULL;
    kal_uint32 size = 0, tmp_size = 0;

    /* X-Mms-Message-Type ~ From */
    size = 2 + 12 + 2 + 6 + 3;

    /* To */
    addr = mms->to_head;
    while (addr)
    {
        size += mma_uc_calc_header_attribute_addr_size_int(addr->type, (kal_wchar*) addr->addr);
        addr = addr->next;
    }

    /* Cc */
  /*  addr = mms->cc_head;
    while (addr)
    {
        size += mma_uc_calc_header_attribute_addr_size_int(addr->type, (kal_wchar*) addr->addr);
        addr = addr->next;
    }

     Bcc 
    addr = mms->bcc_head;
    while (addr)
    {
        size += mma_uc_calc_header_attribute_addr_size_int(addr->type, (kal_wchar*) addr->addr);
        addr = addr->next;
    }

     Subject */
    size += mma_uc_calc_header_attribute_size(MMA_HEADER_SUBJECT, (kal_wchar*) mms->subject);

    /* X-Mms-Expiry */
    switch (srv_uc_convert_to_mms_expiry_time((srv_uc_expiry_time_enum)mms->expiry_time))
    {
        case MMA_EXPIRY_1_HOUR:
            size += 6;  /* 88 [Value-Length:04] 81 [Short-length:02] XX XX */
            break;
        case MMA_EXPIRY_12_HOURS:
            size += 6;
            break;
        case MMA_EXPIRY_1_DAY:
            size += 7;  /* 88 [Value-Length:05] 81 [Short-length:03] XX XX XX */
            break;
        case MMA_EXPIRY_1_WEEK:
            size += 7;
            break;
        case MMA_EXPIRY_MAX:
            break;
}

    /* X-Mms-Delivery-Time */
    switch (srv_uc_convert_to_mms_delivery_time((srv_uc_delivery_time_enum)mms->delivery_time))
    {
        case MMA_DELIVERY_IMMEDIATE:
            break;
        case MMA_DELIVERY_1_HOUR:
            size += 6;  /* 87 [Value-Length:04] 81 [Short-length:02] XX XX */
            break;
        case MMA_DELIVERY_12_HOURS:
            size += 6;  /* 87 [Value-Length:04] 81 [Short-length:02] XX XX */
            break;
        case MMA_DELIVERY_24_HOURS:
            size += 7;  /* 87 [Value-Length:05] 81 [Short-length:03] XX XX XX */
            break;
    }

    /* X-Mms-Sender-Visibility */
    switch (mms->hide_sender)
    {
        case FALSE:
            break;
        case TRUE:
            size += 2;  /* 94 80 */
            break;
    }

    /* X-Mms-Priority ~ X-Mms-Read-Report */
    size += (2 + 2 + 2);

    /* Content-type */
	if (mms_type != MMA_MMS_TYPE_MIXED_MMS)
	{
        tmp_size = 5 + strlen(MMS_MEDIA_TYPE_STRING_SMIL) + strlen(MMA_CFG_SMIL_CONTENT_ID) + strlen("<>");
        size += (1 + mma_get_uintvar_length_bytes(tmp_size) + tmp_size);
    
        /* nEntries */
        size += mma_get_uintvar_length_bytes(mms->msg_body.obj_no + 1);    /* add SMIL part */
	}
	else
	{
		size += mma_get_uintvar_length_bytes(mms->msg_body.obj_no);    
	}

#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

    /* Add Extra Header Size which server might add to PDU*/
    size += MMA_EXTRA_HEADER_BUFFER;
    return size;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_slide_smil_size
 * DESCRIPTION
 *  This function is to calculate SMIL description size for slide (<par ...></par>)
 * CALLS
 *  
 * PARAMETERS
 *  sec     [IN]        
 * RETURNS
 *  smil description size
 *****************************************************************************/
kal_uint32 mma_uc_calc_slide_smil_size(kal_uint32 sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, buffer_len = 0;
    char *buffer = NULL, *tmp = NULL;
    char str[SLS_UINTSZ];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(str, "%d", (int)sec * MMA_1_SEC_IN_MSEC);
    ASSERT(strlen(str) < SLS_UINTSZ);
    buffer_len = strlen(SLS_PAR_START) + strlen(SLS_PAR_END) + strlen(str) + 1;
    tmp = (char*)OslMalloc(buffer_len);
    memset(tmp, 0, buffer_len);
    buffer = (char*)OslMalloc(buffer_len);
    memset(buffer, 0, buffer_len);
    sprintf(tmp, SLS_PAR_START, (int)sec * MMA_1_SEC_IN_MSEC);  /* <par dur="?000ms"> */
    strcpy(buffer, tmp);
    strcat(buffer, SLS_PAR_END);    /* </par> */
    size = strlen(buffer);
    if(tmp)
    {
        OslMfree(tmp);
    }
    if(buffer)
    {
        OslMfree(buffer);
    }
    return size;
}
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT

/*****************************************************************************
 * FUNCTION
 *  mma_uc_get_ascii_name
 * DESCRIPTION
 *  This function is used to generate a DUMMY NAME for non-ascii file names
 *  
 * PARAMETERS
 *  old_file_name            [IN]        
 *  *new_file_name        [OUT]        
 * RETURNS
 *  VOID
 *****************************************************************************/
static void mma_uc_get_ascii_name(const char *old_file_name, char **new_file_name)
{
    char *file_ext = strrchr(old_file_name, '.');

    if (file_ext)
    {
        *new_file_name = OslMalloc(strlen(DUMMY_NAME) + 2 + strlen(file_ext));
        sprintf(*new_file_name, "%s%s", DUMMY_NAME, file_ext);
    }
    else
    {
        *new_file_name = OslMalloc(strlen(DUMMY_NAME) + 2);
        sprintf(*new_file_name, "%s", DUMMY_NAME);
    }
    return;

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_smil_size_precise
 * DESCRIPTION
 *  This function is to calculate object SMIL description size, including being, end attributes
 *  ("alt" still not supported)
 * CALLS
 *  
 * PARAMETERS
 *  type            [IN]        
 *  filepath        [IN]        
 *  obj             [IN]         
 *  dur             [IN]        
 * RETURNS
 *  smil description size
 *****************************************************************************/
kal_uint32 mma_uc_calc_object_smil_size_precise(
            mma_insert_type_enum type,
            const kal_wchar *filepath,
            void *obj,
            kal_uint32 dur)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, buffer_len = 0;
    char *utf8_filepath = NULL, *buffer = NULL, *tmp = NULL;
    const char *utf8_filename = NULL, *t_region_name = NULL, *i_region_name = NULL;
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    kal_bool is_ascii_name = KAL_FALSE;
    char *temp_file_name = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_VIDEO_FEATURE__
    if (type == MMA_INSERT_VIDEO)
	{
		type = MMA_INSERT_ATTACHMENT;
	}
#endif
    if (type != MMA_INSERT_ATTACHMENT)
    {
        utf8_filepath = mma_um_ucs2_to_utf8_string(filepath);
        utf8_filename = mma_get_name_from_path(utf8_filepath);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT

        is_ascii_name = mma_is_ascii_string(utf8_filename);
        //If non_ascii name change to ascii name "XX.ext"
        if(!is_ascii_name)
        {
            mma_uc_get_ascii_name(utf8_filename, &temp_file_name);
        }
        else
        {
            temp_file_name = (char*)utf8_filename;
        }
#endif
        t_region_name = MMA_CFG_TEXT_REGION_NAME;
        i_region_name = MMA_CFG_IMAGE_REGION_NAME;
    }

    switch (type)
    {
        case MMA_INSERT_TEXT:
        {
            char str[8];
            mma_mms_slide_text_object_struct *text = (mma_mms_slide_text_object_struct*) obj;

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            buffer_len = sizeof(SLS_TEXT_T1) + sizeof(SLS_TEXT_T2) + sizeof(SLS_TEXT_T3) + sizeof(SLS_TEXT_T4) +
                sizeof(SLS_TEXT_T5) + sizeof(SLS_TEXT_T8) + sizeof(SLS_TEXT_T9) + strlen(temp_file_name) +
                strlen(t_region_name) + strlen(COLOR_RGB_STR) + 3 * SLS_INTSZ + 1;
#else
            buffer_len = sizeof(SLS_TEXT_T1) + sizeof(SLS_TEXT_T2) + sizeof(SLS_TEXT_T3) + sizeof(SLS_TEXT_T4) +
                sizeof(SLS_TEXT_T5) + sizeof(SLS_TEXT_T8) + sizeof(SLS_TEXT_T9) + strlen(utf8_filename) +
                strlen(t_region_name) + strlen(COLOR_RGB_STR) + 3 * SLS_INTSZ + 1;

#endif
            tmp = (char*)OslMalloc(buffer_len);
            memset(tmp, 0, buffer_len);
            buffer = (char*)OslMalloc(buffer_len);
            memset(buffer, 0, buffer_len);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            sprintf(tmp, SLS_TEXT_T1, temp_file_name, t_region_name);    /* <text src="??.??" region="Text" */
#else
            sprintf(tmp, SLS_TEXT_T1, utf8_filename, t_region_name);    /* <text src="??.??" region="Text" */
#endif
            strcpy(buffer, tmp);

            if (text)
            {
                /* begin, end */
                if (text->begin == 0 && text->end == dur)   /* same with slide time setting */
                {
                }
                else
                {
                    /* Sync with copyTimingAttrs() in Sls_if.c */
                    if (text->begin != SRV_UC_INVALID_VALUE && text->begin != 0)
                    {
                        sprintf(tmp, SLS_TEXT_T2, (unsigned long)text->begin * MMA_1_SEC_IN_MSEC);      /* begin="??ms" */
                        strcat(buffer, tmp);
                    }
                    if (text->end != SRV_UC_INVALID_VALUE && text->end != 0)
                    {
                        sprintf(tmp, SLS_TEXT_T3, (unsigned long)text->end * MMA_1_SEC_IN_MSEC);        /* end="??ms" */
                        strcat(buffer, tmp);
                    }
                }

                /* "alt" not suppported now */
            }

            /* Check if the color or text size parameter needs to be set */
            if (text == NULL || (SLS_COLOR_NOT_USED | text->fg_color) == SLS_COLOR_NOT_USED
                                                                        /* && SLS_TEXT_SIZE_DEFAULT == list->text.textSize */ )
                                                                        /* UC doesn't support text size setting */
            {
                strcat(buffer, SLS_TEXT_T6);    /* /> */
            }
            else
            {
                strcat(buffer, SLS_TEXT_T7);    /* > */
                if ((SLS_COLOR_NOT_USED | text->fg_color) != SLS_COLOR_NOT_USED)
                {
                    sprintf(str, "#%6x", text->fg_color);
                    sprintf(tmp, SLS_TEXT_T5, str);     /* <param name="foregroundcolor" value="#RRGGBB" /> */
                    strcat(buffer, tmp);
                }

                /* UC doesn't support text size setting
                   if (SLS_TEXT_SIZE_DEFAULT != list->text.textSize)
                   {
                   sprintf(tmp, SLS_TEXT_T8, sls_textSizeToStr(
                   list->text.textSize));
                   strcat(buffer, tmp);
                   } */

                strcat(buffer, SLS_TEXT_T9);    /* </text> */
            }
            size = strlen(buffer);
            break;
        }

        case MMA_INSERT_IMAGE:
        {
            mma_mms_slide_object_struct *image = (mma_mms_slide_object_struct*) obj;

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            buffer_len = sizeof(SLS_IMAGE_T1) + sizeof(SLS_IMAGE_T2) + sizeof(SLS_IMAGE_T3) + sizeof(SLS_IMAGE_T4) +
                strlen(temp_file_name) + strlen(i_region_name) + 2 * SLS_INTSZ + 1;
#else
            buffer_len = sizeof(SLS_IMAGE_T1) + sizeof(SLS_IMAGE_T2) + sizeof(SLS_IMAGE_T3) + sizeof(SLS_IMAGE_T4) +
                strlen(utf8_filename) + strlen(i_region_name) + 2 * SLS_INTSZ + 1;
#endif 
            tmp = (char*)OslMalloc(buffer_len);
            memset(tmp, 0, buffer_len);
            buffer = (char*)OslMalloc(buffer_len);
            memset(buffer, 0, buffer_len);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            sprintf(tmp, SLS_IMAGE_T1, temp_file_name, i_region_name);   /* <img src="??.??" region="Image" */
#else
            sprintf(tmp, SLS_IMAGE_T1, utf8_filename, i_region_name);   /* <img src="??.??" region="Image" */
#endif
            strcpy(buffer, tmp);
            if (image)
            {
                /* begin, end */
                if (image->begin == 0 && image->end == dur) /* same with slide time setting */
                {
                }
                else
                {
                    /* Sync with copyTimingAttrs() in Sls_if.c */
                    if (image->begin != SRV_UC_INVALID_VALUE && image->begin != 0)
                    {
                        sprintf(tmp, SLS_IMAGE_T2, (unsigned long)image->begin * MMA_1_SEC_IN_MSEC);    /* begin="??ms" */
                        strcat(buffer, tmp);
                    }
                    if (image->end != SRV_UC_INVALID_VALUE && image->end != 0)
                    {
                        sprintf(tmp, SLS_IMAGE_T3, (unsigned long)image->end * MMA_1_SEC_IN_MSEC);      /* end="??ms" */
                        strcat(buffer, tmp);
                    }
                }
                /* "alt" not suppported now */
            }

            strcat(buffer, SLS_IMAGE_T5);   /* /> */
            size = strlen(buffer);
            break;
        }

        case MMA_INSERT_AUDIO:
        {
            mma_mms_slide_object_struct *audio = (mma_mms_slide_object_struct*) obj;

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            buffer_len = sizeof(SLS_AUDIO_T1) + sizeof(SLS_AUDIO_T2) + sizeof(SLS_AUDIO_T3) + sizeof(SLS_AUDIO_T4) +
                strlen(temp_file_name) + 2 * SLS_INTSZ + 1;
#else
            buffer_len = sizeof(SLS_AUDIO_T1) + sizeof(SLS_AUDIO_T2) + sizeof(SLS_AUDIO_T3) + sizeof(SLS_AUDIO_T4) +
                strlen(utf8_filename) + 2 * SLS_INTSZ + 1;
#endif
            tmp = (char*)OslMalloc(buffer_len);
            memset(tmp, 0, buffer_len);
            buffer = (char*)OslMalloc(buffer_len);
            memset(buffer, 0, buffer_len);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            sprintf(tmp, SLS_AUDIO_T1, temp_file_name);  /* <audio src="??.??" /> */
#else
            sprintf(tmp, SLS_AUDIO_T1, utf8_filename);  /* <audio src="??.??" /> */
#endif
            strcpy(buffer, tmp);
            if (audio)
            {
                /* begin, end */
                if (audio->begin == 0 && audio->end == dur) /* same with slide time setting */
                {
                }
                else
                {
                    /* Sync with copyTimingAttrs() in Sls_if.c */
                    if (audio->begin != SRV_UC_INVALID_VALUE && audio->begin != 0)
                    {
                        sprintf(tmp, SLS_AUDIO_T2, (unsigned long)audio->begin * MMA_1_SEC_IN_MSEC);    /* begin="??ms" */
                        strcat(buffer, tmp);
                    }
                    if (audio->end != SRV_UC_INVALID_VALUE && audio->end != 0)
                    {
                        sprintf(tmp, SLS_AUDIO_T3, (unsigned long)audio->end * MMA_1_SEC_IN_MSEC);      /* end="??ms" */
                        strcat(buffer, tmp);
                    }
                }
                /* "alt" not suppported now */
            }

            strcat(buffer, SLS_AUDIO_T5);   /* /> */
            size = strlen(buffer);
            break;
        }

        case MMA_INSERT_VIDEO:
#ifdef __MMI_MMS_VIDEO_FEATURE__
        {
            mma_mms_slide_object_struct *video = (mma_mms_slide_object_struct*) obj;

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            buffer_len = sizeof(SLS_VIDEO_T1) + sizeof(SLS_VIDEO_T2) + sizeof(SLS_VIDEO_T3) + sizeof(SLS_VIDEO_T4) +
                strlen(temp_file_name) + strlen(i_region_name) + 2 * SLS_INTSZ + 1;
#else
            buffer_len = sizeof(SLS_VIDEO_T1) + sizeof(SLS_VIDEO_T2) + sizeof(SLS_VIDEO_T3) + sizeof(SLS_VIDEO_T4) +
                strlen(utf8_filename) + strlen(i_region_name) + 2 * SLS_INTSZ + 1;
#endif    
            tmp = (char*)OslMalloc(buffer_len);
            memset(tmp, 0, buffer_len);
            buffer = (char*)OslMalloc(buffer_len);
            memset(buffer, 0, buffer_len);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            sprintf(tmp, SLS_VIDEO_T1, temp_file_name, i_region_name);   /* <video src="??.??" region="Image" */
#else
            sprintf(tmp, SLS_VIDEO_T1, utf8_filename, i_region_name);   /* <video src="??.??" region="Image" */
#endif
            strcpy(buffer, tmp);
            if (video)
            {
                /* begin, end */
                if (video->begin == 0 && video->end == dur) /* same with slide time setting */
                {
                }
                else
                {
                    /* Sync with copyTimingAttrs() in Sls_if.c */
                    if (video->begin != SRV_UC_INVALID_VALUE && video->begin != 0)
                    {
                        sprintf(tmp, SLS_VIDEO_T2, (unsigned long)video->begin * MMA_1_SEC_IN_MSEC);    /* begin="??ms" */
                        strcat(buffer, tmp);
                    }
                    if (video->end != SRV_UC_INVALID_VALUE && video->end != 0)
                    {
                        sprintf(tmp, SLS_VIDEO_T3, (unsigned long)video->end * MMA_1_SEC_IN_MSEC);      /* end="??ms" */
                        strcat(buffer, tmp);
                    }
                }
                /* "alt" not suppported now */
            }

            strcat(buffer, SLS_VIDEO_T5);   /* /> */
            size = strlen(buffer);
            break;
        }
#endif

        case MMA_INSERT_ATTACHMENT:
            size = 0;
            break;

		case MMA_INSERT_REF:
    	{
        	mma_mms_slide_ref_object_struct *refs = (mma_mms_slide_ref_object_struct *) obj;
        	buffer_len = sizeof(SLS_REF_T1) + sizeof(SLS_REF_T2) + sizeof(SLS_REF_T3) + sizeof(SLS_REF_T4) + 
        	strlen(utf8_filename) + 2 * SLS_INTSZ + 1;
        	tmp = (char*)OslMalloc(buffer_len);
        	memset(tmp, 0, buffer_len);
        	buffer = (char*)OslMalloc(buffer_len);
        	memset(buffer, 0, buffer_len);
        	sprintf(tmp, SLS_REF_T1, utf8_filename);  /* <ref src="??.??" /> */
        	strcpy(buffer, tmp);
        	if (refs)
        	{
            	/* begin, end */
            	if (refs->begin == 0 && refs->end == dur)  /* same with slide time setting */
            	{
            	}
            	else
            	{
                	/* Sync with copyTimingAttrs() in Sls_if.c */
                	if (refs->begin != SRV_UC_INVALID_VALUE && refs->begin != 0)
                	{
                    	sprintf(tmp, SLS_REF_T2, (unsigned long)refs->begin * MMA_1_SEC_IN_MSEC);  /* begin="??ms" */
                    	strcat(buffer, tmp);
                	}
                	if (refs->end != SRV_UC_INVALID_VALUE && refs->end != 0)
                	{
                    	sprintf(tmp, SLS_REF_T3, (unsigned long)refs->end * MMA_1_SEC_IN_MSEC);  /* end="??ms" */
                    	strcat(buffer, tmp);
                	}
            	}
            	/* "alt" not suppported now */
        	}

        	strcat(buffer, SLS_REF_T5);  /* /> */
        	size = strlen(buffer);
        	ASSERT(size < buffer_len);
        	break;
    	}

        default:
            ASSERT(0);
    }

    if(tmp)
    {
        OslMfree(tmp);
    }
    if(buffer)
    {
        OslMfree(buffer);
    }
    if(utf8_filepath)
    {
        OslMfree(utf8_filepath);
    }
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    if(!is_ascii_name && temp_file_name)
    {
        OslMfree(temp_file_name);
    }
#endif   
    return size;

}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_smil_size
 * DESCRIPTION
 *  This function is to calculate object SMIL description size
 * CALLS
 *  
 * PARAMETERS
 *  type            [IN]        
 *  filepath        [IN]        
 * RETURNS
 *  smil description size
 *****************************************************************************/
kal_uint32 mma_uc_calc_object_smil_size(mma_insert_type_enum type, const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_uc_calc_object_smil_size_precise(type, filepath, NULL, 0);
}

#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__


/*****************************************************************************
 * FUNCTION
 *  mma_convert_to_mms_known_media_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_value     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MmsKnownMediaType mma_convert_to_mms_known_media_type(MmsKnownMediaType media_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsKnownMediaType mms_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((MmsKnownMediaType) media_value)
    {
        case MMS_TYPE_ANY_ANY:
        case MMS_TYPE_TEXT_ANY:
        case MMS_TYPE_TEXT_HTML:
        case MMS_TYPE_TEXT_PLAIN:
        case MMS_TYPE_TEXT_X_HDML:
        case MMS_TYPE_TEXT_X_TTML:
        case MMS_TYPE_TEXT_X_VCALENDAR:
        case MMS_TYPE_TEXT_X_VCARD:
        case MMS_TYPE_TEXT_VND_WAP_WML:
        case MMS_TYPE_TEXT_VND_WAP_WMLSCRIPT:
        case MMS_TYPE_TEXT_VND_WAP_CHANNEL:
        case MMS_TYPE_MULTIPART_ANY:
        case MMS_TYPE_MULTIPART_MIXED:
        case MMS_TYPE_MULTIPART_FORM_DATA:
        case MMS_TYPE_MULTIPART_BYTERANGES:
        case MMS_TYPE_MULTIPART_ALTERNATIVE:
        case MMS_TYPE_APP_ANY:
        case MMS_TYPE_APP_JAVA_VM:
        case MMS_TYPE_APP_X_WWW_FORM_URLENCODED:
        case MMS_TYPE_APP_X_HDMLC:
        case MMS_TYPE_APP_VND_WAP_WMLC:
        case MMS_TYPE_APP_VND_WAP_WMLSCRIPTC:
        case MMS_TYPE_APP_VND_WAP_CHANNELC:
        case MMS_TYPE_APP_VND_WAP_UAPROF:
        case MMS_TYPE_APP_VND_WAP_WTLS_CA_CERTIFICATE:
        case MMS_TYPE_APP_VND_WAP_WTLS_USER_CERTIFICATE:
        case MMS_TYPE_APP_X_X509_CA_CERT:
        case MMS_TYPE_APP_X_X509_USER_CERT:
        case MMS_TYPE_IMAGE_ANY:
        case MMS_TYPE_IMAGE_GIF:
        case MMS_TYPE_IMAGE_JPEG:
        case MMS_TYPE_IMAGE_TIFF:
        case MMS_TYPE_IMAGE_PNG:
        case MMS_TYPE_IMAGE_VND_WAP_WBMP:
        case MMS_VND_WAP_MULTIPART_ANY:
        case MMS_VND_WAP_MULTIPART_MIXED:
        case MMS_TYPE_APP_VND_WAP_MPART_FORM_DATA:
        case MMS_TYPE_APP_VND_WAP_MPART_BYTERANGES:
        case MMS_VND_WAP_MULTIPART_ALTERNATIVE:
        case MMS_TYPE_APP_XML:
        case MMS_TYPE_TEXT_XML:
        case MMS_TYPE_APP_VND_WAP_WBXML:
        case MMS_TYPE_APP_X_X968_CROSS_CERT:
        case MMS_TYPE_APP_X_X968_CA_CERT:
        case MMS_TYPE_APP_X_X968_USER_CERT:
        case MMS_TYPE_TEXT_VND_WAP_SI:
        case MMS_TYPE_APP_VND_WAP_SIC:
        case MMS_TYPE_TEXT_VND_WAP_SL:
        case MMS_TYPE_APP_VND_WAP_SLC:
        case MMS_TYPE_TEXT_VND_WAP_CO:
        case MMS_TYPE_APP_VND_WAP_COC:
        case MMS_VND_WAP_MULTIPART_RELATED:
        case MMS_TYPE_APP_VND_WAP_SIA:
        case MMS_TYPE_TEXT_VND_WAP_CONNECTIVITY_XML:
        case MMS_TYPE_APP_VND_WAP_CONNECTIVITY_WBXML:
        case MMS_TYPE_APP_VND_OMA_DRM_MESSAGE:
        case MMS_TYPE_APP_VND_OMA_DRM_CONTENT:
        case MMS_TYPE_APP_VND_OMA_DRM_R_XML:
        case MMS_TYPE_APP_VND_OMA_DRM_R_WBXML:

            mms_value = (MmsKnownMediaType) media_value;
            break;
        default:
            mms_value = MMS_TYPE_ANY_ANY;
            break;
    }

    return mms_value;

}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_multipart_header_size
 * DESCRIPTION
 *  Calculate multipart header size including
 *  - HeadersLen
 *  - Headers: ContentType
 *  * general form (Value-length, Media-type(value/string), Parameter(charset(only text, smil), Name))
 *  - Headers: Content Location, Content ID
 * PARAMETERS
 *  filename        [IN]        UTF8 encoding
 *  is_presentation_part        [IN]
 * RETURNS
 *  size in bytes
 *****************************************************************************/
static kal_uint32 mma_uc_calc_object_multipart_header_size(const char *filename, kal_bool is_presentation_part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 hd_size = 0, ct_size = 0;
    const char *mime = NULL;
    MmsKnownMediaType type = MMS_VALUE_AS_STRING;
    kal_bool is_smil = KAL_FALSE;
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    kal_bool is_ascii_name = KAL_FALSE;
    char *temp_file_name = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filename != NULL);
    mime = mma_get_mime_type_from_filename_and_mime_string(filename, NULL);
    is_smil = (kal_bool)(strcmp(MMS_MEDIA_TYPE_STRING_SMIL, mime) == 0);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    is_ascii_name = mma_is_ascii_string(filename);
    if(!is_ascii_name)
    {
        mma_uc_get_ascii_name(filename, &temp_file_name);
    }          
    else
    {
        temp_file_name = (char*) filename;
    }
#endif
    /* ContentType */
    /* Media-type */

    /*Currently we are writing the mime string (rather than the enum for the object mime type)in all scenerios
    so every time we have to add mime type length (rather than 1 for enum) so thereby commenting this check */

    type = mma_convert_to_mms_known_media_type((MmsKnownMediaType)mma_get_mmsKnownMediaType_from_mime_type(mime));
    if (type == MMS_TYPE_APP_VND_OMA_DRM_MESSAGE ||
        type == MMS_TYPE_APP_VND_OMA_DRM_CONTENT ||
        type == MMS_TYPE_APP_VND_OMA_DRM_R_XML ||
        type == MMS_TYPE_APP_VND_OMA_DRM_R_WBXML ||
        type == MMS_TYPE_ANY_ANY)
    {
        ct_size += (strlen(mime) + 1);  /* string */

    }
    else
    {
        ct_size += 1;   /* value */
    }   

    /* Parameter Charset */
    if (type == MMS_TYPE_TEXT_PLAIN || is_smil)
    {
        ct_size += 2;   /* 0x81 0x?? */
    }

    /* Parameter Name */
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    ct_size += (strlen(temp_file_name) + 2);  /* 0x85 + [name] + '\0' */
#else
    ct_size += (strlen(filename) + 2);  /* 0x85 + [name] + '\0' */
#endif

    /* Value-length */
    ct_size += mma_get_value_length_bytes(ct_size);
    hd_size += ct_size;

    /* Content Location: 0x8e + [name] + '\0' */
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    hd_size += (strlen(temp_file_name) + 2);
#else
    hd_size += (strlen(filename) + 2);
#endif

    /* Content ID: 0xc0 + '"' + '<' + [name] + '>' + '\0' */
    if (is_presentation_part)
    {
        hd_size += (strlen(MMA_CFG_SMIL_CONTENT_ID) + 5);
    }
    else
    {
#ifdef  MMA_NON_ASCII_NAME_CONV_SUPPORT
        hd_size += (strlen(temp_file_name) + 5);
#else
        hd_size += (strlen(filename) + 5);
#endif
    }

    /* HeadersLen */
    hd_size += mma_get_uintvar_length_bytes(hd_size);
#ifdef   MMA_NON_ASCII_NAME_CONV_SUPPORT
    if(!is_ascii_name && temp_file_name)
    {
        OslMfree(temp_file_name);
    }
#endif

    return hd_size;
}
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 


/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_multipart_size
 * DESCRIPTION
 *  Calculate multipart size including
 *  - header:
 *  + HeadersLen, Headers: mma_uc_calc_object_multipart_header_size()
 *  + DataLen
 *  - body:
 * PARAMETERS
 *  filepath        [IN]        UCS2 encoding
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 mma_uc_calc_object_multipart_size(const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, filesize = mma_get_mmi_file_size(-1, filepath);

#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    char *utf8_filepath = NULL;
    const char *utf8_filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DataLen */
    size += mma_get_uintvar_length_bytes(filesize);

    utf8_filepath = mma_um_ucs2_to_utf8_string(filepath);
    utf8_filename = mma_get_name_from_path(utf8_filepath);

    /* HeadersLen, Headers */
    size += mma_uc_calc_object_multipart_header_size(utf8_filename, KAL_FALSE);
    if(utf8_filepath)
    {
        OslMfree(utf8_filepath);
    }
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
    /* body */
    size += filesize;

    return size;
}

//#ifdef __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__


/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_overhead_size
 * DESCRIPTION
 *  Calculate object overhead size including
 *  - multipart header:
 *  + HeadersLen, Headers: mma_uc_calc_object_multipart_header_size()
 *  + DataLen
 *  - smil description size:
 * PARAMETERS
 *  type            [IN]        
 *  filename        [IN]        UCS2 encoding
 *  filesize        [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 mma_uc_calc_object_overhead_size(mma_insert_type_enum type, const kal_wchar *filename, kal_uint32 filesize, mma_mms_type_enum mms_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;

#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    char *utf8_filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DataLen */
    size += mma_get_uintvar_length_bytes(filesize);
    utf8_filename = mma_um_ucs2_to_utf8_string(filename);

    /* HeadersLen, Headers */
    size += mma_uc_calc_object_multipart_header_size(utf8_filename, KAL_FALSE);
    if(utf8_filename)
    {
        OslMfree(utf8_filename);
    }
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

    /* smil description size */
	if (mms_type != MMA_MMS_TYPE_MIXED_MMS)
	{
        size += mma_uc_calc_object_smil_size(type, filename);
	}

    return size;
}
//#endif /* __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__ */ 

/* msg size calculation for SLIM MMS with new defined common structures */
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_mms_calc_slim_msg_size
 * DESCRIPTION
 *  This function is to
 * CALLS
 *  
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 mma_mms_calc_slim_msg_size(const void *input, mma_mms_type_enum mms_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buffer[8];
    kal_uint32 size = 0, smil_size = 0;
    mma_mms_slide_struct *slide = NULL;
    mma_mms_object_struct *obj = NULL;
    mma_mms_description_struct *mms = (mma_mms_description_struct*) input;

    MsfSize screen_size = {0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = mma_mms_calc_slim_msg_header_size(mms, mms_type);//kuldeep have to made changes in this api also
	if(mms_type != MMA_MMS_TYPE_MIXED_MMS)
	{
#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        /* SMIL multipart header: HeadersLen, Headers */
        size += mma_uc_calc_object_multipart_header_size(MMA_CFG_SMIL_FILE_NAME, KAL_TRUE);
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

        /* SMIL body */
        smil_size = strlen(SLS_SMIL_START) + strlen(SLS_SMIL_END) + strlen(SLS_HEAD_START)
            + strlen(SLS_HEAD_END) + strlen(SLS_BODY_START) + strlen(SLS_BODY_END)
            + strlen(SLS_LAYOUT_START) + strlen(SLS_LAYOUT_END);
    
        /* SMIL body: <root-layout width="XXX" height="XXX"/> */
        screen_size = mma_get_screen_size();
        smil_size += (strlen(SLS_ROOT_LAYOUT_T1) + strlen(SLS_ROOT_LAYOUT_T2) + strlen(SLS_ROOT_LAYOUT_T4));
        sprintf(buffer, "%d", screen_size.width);
        smil_size += strlen(buffer);
        sprintf(buffer, "%d", screen_size.height);
        smil_size += strlen(buffer);
        smil_size += strlen(SLS_ROOT_LAYOUT_T3);
        sprintf(buffer, "%.6x", MMA_CFG_SMIL_BG_COLOR);
        smil_size += strlen(buffer) + 1;
    
        /* SMIL body: <region id="XXX" width="XX%" height="XX%" left="XX%" top="XX%" /> */
        smil_size += 2 * (strlen(SLS_REGION_T1) + strlen(SLS_REGION_T2) + strlen(SLS_REGION_T3) +
                          strlen(SLS_REGION_T4) + strlen(SLS_REGION_T5) + strlen(SLS_REGION_T6) + strlen(SLS_REGION_T7)) +
            strlen(SLS_FIT_MEET) + strlen(SLS_FIT_SCROLL);
        smil_size += (strlen(MMA_CFG_IMAGE_REGION_NAME) + strlen(MMA_CFG_TEXT_REGION_NAME));
        smil_size += 4* strlen("100%");  /* May not precise: +1 byte */
        smil_size += 4* strlen("0%");
    
        /* SMIL body: slide info */
        slide = mms->body->slides;
        while (slide)
        {
            mma_mms_slide_ref_object_struct *refs = slide->ref_items;
            
            smil_size += mma_uc_calc_slide_smil_size(slide->duration);
            if (slide->txt.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_TEXT,
                                slide->txt.object->file_name_ucs,
                                &slide->txt,
                                slide->duration);
            }
            if (slide->img.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_IMAGE,
                                slide->img.object->file_name_ucs,
                                &slide->img,
                                slide->duration);
            }
            if (slide->aud.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_AUDIO,
                                slide->aud.object->file_name_ucs,
                                &slide->aud,
                                slide->duration);
            }
            if (slide->vid.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_VIDEO,
                                slide->vid.object->file_name_ucs,
                                &slide->vid,
                                slide->duration);
            }
            while (refs)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(MMA_INSERT_REF, refs->object->file_name_ucs, refs, slide->duration);
                refs = refs->next;
            }
            slide = slide->next;
        }
        size += smil_size;
    
    #ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        /* SMIL multipart header: DataLen */
        size += mma_get_uintvar_length_bytes(smil_size);
    #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
	}
    /* multipart excepts SMIL, refer to  wap_mma_uc_calc_object_multipart_size() */
    obj = mms->body->objects;
    while (obj)
    {
    #ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        char *utf8_filename = NULL;

        utf8_filename = mma_um_ucs2_to_utf8_string((const kal_wchar*)obj->file_name_ucs);
        /* DataLen */
        size += mma_get_uintvar_length_bytes(obj->size);

        /* HeadersLen, Headers */
        size += mma_uc_calc_object_multipart_header_size((const char*)utf8_filename, KAL_FALSE);
        if(utf8_filename)
        {
            OslMfree(utf8_filename);
        }
    #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
        /* body */
        size += obj->size;

        obj = obj->next;
    }


    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UM_MMA_UC_CAL_MSG_SIZE, "(mmsadp.c) wap_mma_uc_calc_msg_size = %u\n", size)); 
    return size;
}
#elif (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_msg_size
 * DESCRIPTION
 *  This function is to
 * CALLS
 *  
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 mma_uc_calc_msg_size(const void *input, mma_mms_type_enum mms_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buffer[8];
    kal_uint32 size = 0, smil_size = 0;
    mma_mms_slide_struct *slide = NULL;
    mma_mms_object_struct *obj = NULL;
    srv_uc_msg_struct *mms = (srv_uc_msg_struct*) input;

    MsfSize screen_size = {0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = mma_uc_calc_header_size(mms, mms_type);
	if(mms_type != MMA_MMS_TYPE_MIXED_MMS)
	{
#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        /* SMIL multipart header: HeadersLen, Headers */
        size += mma_uc_calc_object_multipart_header_size(MMA_CFG_SMIL_FILE_NAME, KAL_TRUE);
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 

        /* SMIL body */
        smil_size = strlen(SLS_SMIL_START) + strlen(SLS_SMIL_END) + strlen(SLS_HEAD_START)
            + strlen(SLS_HEAD_END) + strlen(SLS_BODY_START) + strlen(SLS_BODY_END)
            + strlen(SLS_LAYOUT_START) + strlen(SLS_LAYOUT_END);
    
        /* SMIL body: <root-layout width="XXX" height="XXX"/> */
        screen_size = mma_get_screen_size();
        smil_size += (strlen(SLS_ROOT_LAYOUT_T1) + strlen(SLS_ROOT_LAYOUT_T2) + strlen(SLS_ROOT_LAYOUT_T4));
        sprintf(buffer, "%d", screen_size.width);
        smil_size += strlen(buffer);
        sprintf(buffer, "%d", screen_size.height);
        smil_size += strlen(buffer);
        smil_size += strlen(SLS_ROOT_LAYOUT_T3);
        sprintf(buffer, "%.6x", MMA_CFG_SMIL_BG_COLOR);
        smil_size += strlen(buffer) + 1;
    
        /* SMIL body: <region id="XXX" width="XX%" height="XX%" left="XX%" top="XX%" /> */
        smil_size += 2 * (strlen(SLS_REGION_T1) + strlen(SLS_REGION_T2) + strlen(SLS_REGION_T3) +
                          strlen(SLS_REGION_T4) + strlen(SLS_REGION_T5) + strlen(SLS_REGION_T6) + strlen(SLS_REGION_T7)) +
            strlen(SLS_FIT_MEET) + strlen(SLS_FIT_SCROLL);
        smil_size += (strlen(MMA_CFG_IMAGE_REGION_NAME) + strlen(MMA_CFG_TEXT_REGION_NAME));
        smil_size += 4* strlen("100%");  /* May not precise: +1 byte */
        smil_size += 4* strlen("0%");
    
        /* SMIL body: slide info */
        slide = mms->msg_body.slides;
        while (slide)
        {
            mma_mms_slide_ref_object_struct *refs = slide->ref_items;
            
            smil_size += mma_uc_calc_slide_smil_size(slide->duration);
            if (slide->txt.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_TEXT,
                                slide->txt.object->file_name_ucs,
                                &slide->txt,
                                slide->duration);
            }
            if (slide->img.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_IMAGE,
                                slide->img.object->file_name_ucs,
                                &slide->img,
                                slide->duration);
            }
            if (slide->aud.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_AUDIO,
                                slide->aud.object->file_name_ucs,
                                &slide->aud,
                                slide->duration);
            }
            if (slide->vid.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_VIDEO,
                                slide->vid.object->file_name_ucs,
                                &slide->vid,
                                slide->duration);
            }
            while (refs)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(MMA_INSERT_REF, refs->object->file_name_ucs, refs, slide->duration);
                refs = refs->next;
            }
            slide = slide->next;
        }
        size += smil_size;
    
    #ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        /* SMIL multipart header: DataLen */
        size += mma_get_uintvar_length_bytes(smil_size);
    #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
	}
    /* multipart excepts SMIL, refer to  wap_mma_uc_calc_object_multipart_size() */
    obj = mms->msg_body.objects;
    while (obj)
    {
    #ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        char *utf8_filename = NULL;

        utf8_filename = mma_um_ucs2_to_utf8_string((const kal_wchar*)obj->file_name_ucs);
        /* DataLen */
        size += mma_get_uintvar_length_bytes(obj->size);

        /* HeadersLen, Headers */
        size += mma_uc_calc_object_multipart_header_size((const char*)utf8_filename, KAL_FALSE);
        if(utf8_filename)
        {
            OslMfree(utf8_filename);
        }
    #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
        /* body */
        size += obj->size;

        obj = obj->next;
    }


    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UM_MMA_UC_CAL_MSG_SIZE, "(mmsadp.c) wap_mma_uc_calc_msg_size = %u\n", size)); 
    return size;

}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
/*end*/
#endif /* MMS_SUPPORT */ /* MMS_SUPPOTT */
#endif /* _MMA_UM_C */ /* __MMA_UM_C */

