/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO 
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   j2me_msg_util.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements J2ME message handler utilities
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "jam_msg_handler.h"
#include "jam_internal.h"
#include "jma_internal.h"
#include "jnw_internal.h"
#include "j2me_trace.h"

#include "JavaAgencyDef.h"
#include "JavaAgencyGProt.h"
#include "JavaAgencyProt.h"
#include "wgui_categories.h"
#include "MMI_features.h"
#include "gdi_include.h"
#include "jvm_interface.h"
#include "jvm_internal.h"
#include "jam_internal.h"
#include "gdi_image_gif.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#include "drm_def.h"
#endif /* __DRM_SUPPORT__ */ 
#include "GlobalDefs.h"
#include "mexe_struct.h"
#ifdef WAP_SEC_SUPPORT
#include "wps_struct.h"
#endif 
#include "FileManagerDef.h"
#include "app_str.h"
#include "cbm_api.h"
#include "abm_soc_enums.h"
#include "Dtcntsrvgprot.h"
#include "Browsersrvgprot.h"
#include "SimCtrlSrvGprot.h"
#include "jam_mvm_manager.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "mmi_rp_srv_filemanager_def.h"
static kal_bool g_jam_get_jar_url_check_exist = KAL_FALSE;
extern mmi_java_nw_cntx g_mmi_java_nw_cntx;

kal_bool g_jam_is_get_jar_url = KAL_FALSE;

extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
#ifdef BROWSER_SUPPORT
srv_brw_profile_content_struct g_jam_install_profie_content;
#endif
kal_bool g_jam_brw_profile_is_success = KAL_FALSE;
extern kal_bool g_mmi_java_is_no_network_usable;

kal_int32 jam_bg_call_init(void)
{
#ifdef __MMI_BACKGROUND_CALL__
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_APP_EXIT_QUERY,jam_PR_outgoing_call_deleted_CB,NULL);
#endif 
    return J2ME_NO_ERROR;
}
kal_int32 jam_bg_call_deinit(void)
{
#ifdef __MMI_BACKGROUND_CALL__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_APP_EXIT_QUERY,jam_PR_outgoing_call_deleted_CB,NULL);
#endif 
    return J2ME_NO_ERROR;
}
kal_int32 jam_backlight_init(void)
{
    if(g_mmi_java_bk_light)
    {
        jam_set_bk_status(KAL_TRUE);
    }
    return J2ME_NO_ERROR;
}
kal_int32 jam_backlight_deinit(void)
{
    if(g_mmi_java_bk_light)
    {
        jam_set_bk_status(KAL_FALSE);
    }
    return J2ME_NO_ERROR;
}
kal_int32 jam_ca_list_init(void)
{
    return J2ME_NO_ERROR;
}
kal_int32 jam_ca_list_deinit(void)
{
    free_jam_ca_list();
    return J2ME_NO_ERROR;
}
/*****************************************************************************
 * FUNCTION
 *  get_ucs2_len
 * DESCRIPTION
 *  Use this function to get the length of a UCS2String
 * PARAMETERS
 *  ucs2string      [?]     [?]
 * RETURNS
 *  length
 *****************************************************************************/
kal_uint32 get_ucs2_len(kal_wchar *ucs2string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (ucs2string[i] != 0)
    {
        i++;
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  trans_ucs2_to_utf8
 * DESCRIPTION
 *  Use this function to transform a UCS2 string into utf8 string
 * PARAMETERS
 *  utf8            [?]     [?]
 *  ucs2string      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void trans_ucs2_to_utf8(kal_char *utf8, kal_wchar *ucs2string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (ucs2string[i] != 0)
    {
        utf8[i] = (kal_char) ucs2string[i];
        i++;
    }
    utf8[i] = 0;    /* null terminator */
}


/*****************************************************************************
 * FUNCTION
 *  trans_utf8_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2string      [?]     [?]
 *  utf8            [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void trans_utf8_to_ucs2(kal_wchar *ucs2string, kal_char *utf8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (utf8[i] != 0)
    {
        ucs2string[i] = (kal_wchar) utf8[i];
        i++;
    }
    ucs2string[i] = 0;  /* null terminator */
}

/*****************************************************************************
 * FUNCTION
 *  get_dec_len
 * DESCRIPTION
 *  Use get_dec_len to get charactor number of a integer, and
 *  use trans_dec_to_ascii to translate integer to charactors.
 * PARAMETERS
 *  dec     [IN]        
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 get_dec_len(kal_uint32 dec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (dec > 0)
    {
        dec /= 10;
        i++;
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  trans_dec_to_ascii
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dec_buffer      [?]         [?]
 *  dec             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void trans_dec_to_ascii(kal_char *dec_buffer, kal_uint32 dec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;
    kal_uint32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        kal_uint32 dec_digit = dec % 10;

        dec /= 10;
        dec_buffer[i] = 0x30 + dec_digit;
        i++;
    } while (dec > 0);
    dec_buffer[i] = 0;
    /* inverse charactors of decimal */
    index = 0;
    i--;
    while (index < i)
    {
        int tempValue;

        tempValue = dec_buffer[i];
        dec_buffer[i] = dec_buffer[index];
        dec_buffer[index] = tempValue;
        index++;
        i--;
    }
}

/*****************************************************************************
 * FUNCTION
 *  find_mids_info_by_id
 * DESCRIPTION
 *  input a midlet suite id and get the corresponding midlet suite info
 * PARAMETERS
 *  type                [IN]        
 *  mids_id             [IN]        
 *  always_getlist      [IN]        
 * RETURNS
 *  mids_list_info_struct *
 *****************************************************************************/
mids_list_info_struct *find_mids_info_by_id(kal_uint32 mids_id, kal_bool always_getlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    kal_int32 mids_start_indx;
    mids_list_info_struct *mids_info_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (always_getlist || (saved_mids_listfile_ptr == NULL) ||
        /* Reduced information */
        (saved_mids_listfile_ptr->mids_info_list == NULL) ||
        (mids_id <= saved_mids_listfile_ptr->mids_avail_indx) ||
        (mids_id > saved_mids_listfile_ptr->mids_avail_indx + saved_mids_listfile_ptr->mids_avail_count))
    {
        jam_parse_midslistfile((mids_id - 1), 1, &saved_mids_listfile_ptr, 0);
        if (saved_mids_listfile_ptr)
        {
            return saved_mids_listfile_ptr->mids_info_list;
        }
    }

    if (saved_mids_listfile_ptr)
    {
        mids_info_ptr = saved_mids_listfile_ptr->mids_info_list;
        mids_start_indx = saved_mids_listfile_ptr->mids_avail_indx;

        /* Find specific mids info */
        for (i = 1; i < mids_id - mids_start_indx && mids_info_ptr; i++)
        {
            mids_info_ptr = mids_info_ptr->mids_list_info_next;
        }
    }

    return mids_info_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  find_mid_info_by_id
 * DESCRIPTION
 *  find midlet information by a midlet suite information and a MIDlet ID
 * PARAMETERS
 *  mids_info_ptr       [?]         [?]
 *  mid_id              [IN]        
 * RETURNS
 *  mid_struct *
 *****************************************************************************/
mid_struct *find_mid_info_by_id(mids_list_info_struct *mids_info_ptr, kal_uint32 mid_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    mid_struct *mid_info_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mid_info_ptr = mids_info_ptr->mid_info.mid_list;
    for (i = 1; i < mid_id && mid_info_ptr; i++)
    {
        mid_info_ptr = mid_info_ptr->mid_next;
    }
    return mid_info_ptr;
}
/*****************************************************************************
 * FUNCTION
 * jam_set_get_jar_url_check_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jad_file_name       [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
void jam_set_get_jar_url_check_exist(kal_bool setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    g_jam_get_jar_url_check_exist = setting;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
 * FUNCTION
 *  get_jar_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jad_file_name       [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_wchar *get_jar_url(kal_wchar *jad_file_name, kal_int32 *error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* read MIDlet-Jar-URL: in jad file */
    kal_uint32 size;
    kal_int32 handle;
    kal_char *jadContent = NULL;
    kal_int32 scanPos = 0;
    kal_char *jar_url = NULL;
    kal_wchar *return_jar_url = NULL;
    kal_uint32 tempSize = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_is_get_jar_url = KAL_TRUE;
#ifdef __DRM_SUPPORT__
    handle = DRM_open_file(jad_file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
#else 
    handle = FS_Open(jad_file_name, FS_READ_ONLY | FS_OPEN_SHARED);
#endif 
    if (handle < 0)
    {
        *error_code = DISK_OPERATION_FAIL;
        goto END_FUN;
    }
#ifdef __DRM_SUPPORT__
    if (DRM_file_size(handle, &size) != FS_NO_ERROR)
#else 
    if (FS_GetFileSize(handle, &size) != FS_NO_ERROR)
#endif 
    {
    #ifdef __DRM_SUPPORT__
        DRM_close_file(handle);
    #else 
        FS_Close(handle);
    #endif 
        if(error_code)
        {
            *error_code = DISK_OPERATION_FAIL;
        }
        goto END_FUN;
    }

    jadContent = jvm_malloc(size + 1);
    if (jadContent == NULL)
    {
    #ifdef __DRM_SUPPORT__
        DRM_close_file(handle);
    #else 
        FS_Close(handle);
    #endif 
        if(error_code)
        {
            *error_code = J2ME_INSUFFICIENT_MEMORY;
        }
        goto END_FUN;
    }
#ifdef __DRM_SUPPORT__
    if ((DRM_read_file(handle, jadContent, sizeof(char) * size, &tempSize) != FS_NO_ERROR) || tempSize != size)
#else 
    if ((FS_Read(handle, jadContent, sizeof(char) * size, &tempSize) != FS_NO_ERROR) || tempSize != size)
#endif 
    {
    #ifdef __DRM_SUPPORT__
        DRM_close_file(handle);
    #else 
        FS_Close(handle);
    #endif 
        jvm_free(jadContent);
        if(error_code)
        {
            *error_code = DISK_OPERATION_FAIL;
        }        
        goto END_FUN;
    }
#ifdef __DRM_SUPPORT__
    DRM_close_file(handle);
#else 
    FS_Close(handle);
#endif 
    handle = 0;
    while (strncmp(jadContent + scanPos, "MIDlet-Jar-URL:", 15) && scanPos < size)
    {
        while (jadContent[scanPos] != '\n' && scanPos < size)
        {
            scanPos++;
        }
        if (jadContent[scanPos] == 0x0d || jadContent[scanPos] == 0x0a)     /* 0x0d, 0x0a */
        {
            scanPos++;
        }
    }

    if (scanPos >= size)
    {   /* the JAD does not have the MIDlet-Jar-URL attribute */
        goto END_FUN;
    }

    scanPos += 15;  /* MIDlet-Jar-URL: */
    while (jadContent[scanPos] == 0x20 && scanPos < size)   /* delete space */
    {
        scanPos++;
    }

    jar_url = jadContent + scanPos;

    while (jadContent[scanPos] != 0x0d && jadContent[scanPos] != 0x0a && scanPos < size)
    {
        scanPos++;
    }

    /* trim the empty space */
    while (jadContent[scanPos - 1] == ' ')
    {
        scanPos--;
    }

    jadContent[scanPos] = 0;    /* add NULL terminator */

    /* not end with .jar */
    if (strncmp(jadContent + scanPos - 4, ".jar", 4) != 0 &&
        strncmp(jadContent + scanPos - 4, ".Jar", 4) != 0 && strncmp(jadContent + scanPos - 4, ".JAR", 4) != 0 &&
        strncmp(jadContent + scanPos - 4, ".dcf", 4) != 0 && strncmp(jadContent + scanPos - 4, ".DCF", 4) != 0)
    {
        goto END_FUN;
    }

    while (jadContent[scanPos] != '/' && jadContent[scanPos] != '\\' && jadContent + scanPos > jar_url)
    {
        scanPos--;
    }

    if (jadContent[scanPos] == '/' || jadContent[scanPos] == '\\')
    {
        scanPos++;
    }

    jar_url = jadContent + scanPos;

    scanPos = get_ucs2_len(jad_file_name) - 1;

    while (jad_file_name[scanPos] != '\\' && scanPos >= 0)
    {
        scanPos--;
    }

    if (jad_file_name[scanPos] == '\\')
    {
        scanPos++;
    }
    else
    {
        scanPos = 0;
    }

    size = strlen(jar_url);

    if (((size + scanPos) << 1) + 2 < 1024)
    {   /* limit the size */
        return_jar_url = (kal_wchar*) get_ctrl_buffer(((size + scanPos) << 1) + 2);
        memcpy(return_jar_url, jad_file_name, scanPos << 1);
        trans_utf8_to_ucs2(return_jar_url + scanPos, jar_url);

        /* test file exist */
        if (g_jam_get_jar_url_check_exist)
        {
            g_jam_get_jar_url_check_exist = KAL_FALSE;
            handle = FS_Open(return_jar_url, FS_READ_ONLY | FS_OPEN_SHARED);
            if (handle <= 0)
            {
                free_ctrl_buffer(return_jar_url);
                return_jar_url = NULL;
                goto END_FUN;
            }
            FS_Close(handle);
        }
    }
 END_FUN:
    if(jadContent)
    {
        jvm_free(jadContent);
        jadContent = NULL;
    }
    g_jam_is_get_jar_url = KAL_FALSE;
    return return_jar_url;
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_mids_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jad_file_name       [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_wchar *jam_get_mids_name(kal_wchar *jad_file_name, kal_int32 length_limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* read MIDlet-Jar-URL: in jad file */
    kal_uint32 size;
    kal_int32 handle;
    kal_char *jadContent;
    kal_int32 scanPos = 0;
    kal_char *mids_name;
    kal_wchar *return_mids_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    handle = DRM_open_file(jad_file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
#else 
    handle = FS_Open(jad_file_name, FS_READ_ONLY | FS_OPEN_SHARED);
#endif 
    if (handle != NULL)
    {
        kal_uint32 tempSize = 0;

    #ifdef __DRM_SUPPORT__
        if (DRM_file_size(handle, &size) != FS_NO_ERROR)
    #else 
        if (FS_GetFileSize(handle, &size) != FS_NO_ERROR)
    #endif 
        {
        #ifdef __DRM_SUPPORT__
            DRM_close_file(handle);
        #else 
            FS_Close(handle);
        #endif 
            return NULL;
        }

        jadContent = jam_listmem_malloc(size + 1);
        if (jadContent == NULL)
        {
        #ifdef __DRM_SUPPORT__
            DRM_close_file(handle);
        #else 
            FS_Close(handle);
        #endif 
            return NULL;
        }
    #ifdef __DRM_SUPPORT__
        if ((DRM_read_file(handle, jadContent, sizeof(char) * size, &tempSize) != FS_NO_ERROR) || tempSize != size)
    #else 
        if ((FS_Read(handle, jadContent, sizeof(char) * size, &tempSize) != FS_NO_ERROR) || tempSize != size)
    #endif 
        {
        #ifdef __DRM_SUPPORT__
            DRM_close_file(handle);
        #else 
            FS_Close(handle);
        #endif 
            jam_listmem_free(jadContent);
            return NULL;
        }
    #ifdef __DRM_SUPPORT__
        DRM_close_file(handle);
    #else 
        FS_Close(handle);
    #endif 
        while (strncmp(jadContent + scanPos, "MIDlet-Name:", 12) && scanPos < size)
        {
            while (jadContent[scanPos] != '\n' && scanPos < size)
            {
                scanPos++;
            }
            if (jadContent[scanPos] == 0x0d || jadContent[scanPos] == 0x0a)     /* 0x0d, 0x0a */
            {
                scanPos++;
            }
        }

        if (scanPos >= size)
        {   /* the JAD does not have the MIDlet-Jar-URL attribute */
            jam_listmem_free(jadContent);
            return NULL;
        }

        scanPos += 12;  /* MIDlet-Jar-URL: */
        while (jadContent[scanPos] == 0x20 && scanPos < size)   /* delete space */
        {
            scanPos++;
        }

        mids_name = jadContent + scanPos;

        while (jadContent[scanPos] != 0x0d && jadContent[scanPos] != 0x0a && scanPos < size)
        {
            scanPos++;
        }

        /* trim the empty space */
        while (jadContent[scanPos - 1] == ' ')
        {
            scanPos--;
        }

        jadContent[scanPos] = 0;    /* add NULL terminator */

        size = strlen(mids_name);

        if (length_limit!= 0 && size > length_limit)
        {
            size = length_limit;
        }
        return_mids_name = (kal_wchar*) get_ctrl_buffer((size << 1) + 2);
        mmi_chset_utf8_to_ucs2_string((kal_uint8*)return_mids_name,(size+1)<<1,(kal_uint8 *)mids_name);
        jam_listmem_free(jadContent);
        return return_mids_name;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jam_modify_jar_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jad_file_name       [?]     [?]
 *  url                 [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jam_modify_jar_url(kal_wchar *jad_file_name, kal_char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size;
    kal_int32 handle;
    kal_char *jadContent;
    kal_int32 scanPos = 0;
    kal_char *jar_url;
    kal_int32 sizeOfURL;
    kal_int32 extraSize;
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (url == NULL)
    {
        return -1;
    }

    sizeOfURL = strlen(url);
    handle = FS_Open(jad_file_name, FS_READ_ONLY | FS_OPEN_SHARED);
    if (handle != NULL)
    {
        kal_uint32 tempSize = 0;

        if (FS_GetFileSize(handle, &size) != FS_NO_ERROR)
        {
            FS_Close(handle);
            return -1;
        }

        jadContent = jvm_malloc(size + 1);
        if ((FS_Read(handle, jadContent, sizeof(char) * size, &tempSize) != FS_NO_ERROR) || tempSize != size)
        {
            FS_Close(handle);
            jvm_free(jadContent);
            return -1;
        }

        FS_Close(handle);
        while (strncmp(jadContent + scanPos, "MIDlet-Jar-URL:", 15) && scanPos < size)
        {
            while (jadContent[scanPos] != '\n' && scanPos < size)
            {
                scanPos++;
            }
            if (jadContent[scanPos] == 0x0d || jadContent[scanPos] == 0x0a)     /* 0x0d, 0x0a */
            {
                scanPos++;
            }
        }

        if (scanPos >= size)
        {   /* the JAD does not have the MIDlet-Jar-URL attribute */
            jvm_free(jadContent);
            return -1;
        }

        scanPos += 15;  /* MIDlet-Jar-URL: */
        while (jadContent[scanPos] == 0x20 && scanPos < size)   /* delete space */
        {
            scanPos++;
        }

        jar_url = jadContent + scanPos;

        while (jadContent[scanPos] != 0x0d && jadContent[scanPos] != 0x0a && scanPos < size)
        {
            scanPos++;
        }

        extraSize = sizeOfURL - (kal_int32) (&jadContent[scanPos] - jar_url);

        if (extraSize < 0)
        {
            while (scanPos < size)
            {
                (jar_url + sizeOfURL)[i++] = jadContent[scanPos++];
            }
        }
        else if (extraSize > 0)
        {
            kal_int32 scanEnd = scanPos;

            scanPos = size;
            while (scanPos >= scanEnd)
            {
                jadContent[scanPos + extraSize] = jadContent[scanPos];
                scanPos--;
            }
        }

        for (i = 0; i < sizeOfURL; i++)
        {
            jar_url[i] = url[i];
        }

        handle = FS_Open(jad_file_name, FS_CREATE_ALWAYS);
        if (handle != NULL)
        {
            if (FS_Write(handle, jadContent, sizeof(char) * (size + extraSize), &tempSize) != FS_NO_ERROR ||
                tempSize != size + extraSize)
            {
                jvm_free(jadContent);
                FS_Close(handle);
                return -1;
            }
            jvm_free(jadContent);
            FS_Close(handle);
            return 0;
        }
    }
    return -1;
}
kal_int32 get_str_id_by_error_code(kal_int32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 MMIStringID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_code)
    {
        case OLD_VERSION:
            MMIStringID = STR_JAVA_ERROR_CODE_OLD_VERSION;
            break;

        case ALREADY_INSTALLED:
            MMIStringID = STR_JAVA_ERROR_CODE_ALREADY_INSTALLED;
            break;

        case NEW_VERSION:
            MMIStringID = STR_JAVA_ERROR_CODE_NEW_VERSION;
            break;

        case INVALID_JAD_URL:
            MMIStringID = STR_JAVA_ERROR_CODE_NOT_FOUND;
            break;

        case MISSING_PROVIDER_CERT:
        case MISSING_SUITE_NAME:
        case MISSING_VENDOR:
        case MISSING_VERSION:
        case MISSING_JAR_URL:
        case MISSING_JAR_SIZE:
        case MISSING_SUITE_INSTALL_NOTIFY:
        case MISSING_DELETE_NOTIFY:
            MMIStringID = STR_JAVA_ERROR_CODE_MISSING_INFO_JAD;
            break;

        case MISSING_CONFIGURATION:
        case MISSING_PROFILE:
            MMIStringID = STR_JAVA_ERROR_CODE_MISSING_INFO_JAR;
            break;

        case INVALID_KEY:
        case INVALID_VALUE:
        case INVALID_VERSION:
        case PUSH_FORMAT_FAILURE:
        case PUSH_CLASS_FAILURE:
        case MISMATCH_RUNTIME_EXEC_ENV:
            MMIStringID = STR_JAVA_ERROR_CODE_INVALID_JAD;
            break;

        case DEVICE_INCOMPATIBLE:
            MMIStringID = STR_JAVA_ERROR_CODE_DEVICE_INCOMPATIBLE;
            break;

        case JAD_MOVED:
            MMIStringID = STR_JAVA_ERROR_CODE_JAD_MOVED;
            break;

        case INSUFFICIENT_STORAGE:
            /* MMIStringID = STR_GLOBAL_NOT_ENOUGH_MEMORY; */
            /* modify to not display actually insufficient size */
            MMIStringID = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;

        case JAR_NOT_FOUND:
            MMIStringID = STR_JAVA_ERROR_CODE_JAR_NOT_FOUND;
            break;

        case INVALID_JAR_URL:
            MMIStringID = STR_JAVA_ERROR_CODE_INVALID_JAR_URL;
            break;

        case CORRUPT_JAR:
            MMIStringID = STR_JAVA_ERROR_CODE_CORRUPT_JAR;
            break;

        case SUITE_NAME_MISMATCH:
        case VERSION_MISMATCH:
        case VENDOR_MISMATCH:
        case JAR_SIZE_MISMATCH:
        case ATTRIBUTE_MISMATCH:
            MMIStringID = STR_JAVA_ERROR_CODE_INFO_MISMATCH;
            break;

        case CORRUPT_PROVIDER_CERT:
        case INVALID_PROVIDER_CERT:
        case CORRUPT_SIGNATURE:
        case INVALID_SIGNATURE:
        case UNSUPPORTED_CERT:
        case UNKNOWN_CA:
        case EXPIRED_PROVIDER_CERT:
        case EXPIRED_CA_KEY:
            MMIStringID = STR_JAVA_ERROR_CODE_VERIFY_FAILED;
            break;

        case AUTHORIZATION_FAILURE:
            MMIStringID = STR_JAVA_ERROR_CODE_AUTHORIZATION_FAILURE;
            break;

        case PUSH_DUP_FAILURE:
            MMIStringID = STR_JAVA_ERROR_CODE_PUSH_DUP_FAILURE;
            break;

        case PUSH_PROTO_FAILURE:
            MMIStringID = STR_JAVA_ERROR_CODE_PUSH_PROTO_FAILURE;
            break;

        case TRUSTED_OVERWRITE_FAILURE:
            MMIStringID = STR_JAVA_ERROR_CODE_TRUSTED_OVERWRITE_FAILURE;
            break;

        case DEFAULT_GAME:
            MMIStringID = STR_JAVA_ERROR_CODE_DEFAULT_GAME;
            break;

        case DISK_OPERATION_FAIL:
            MMIStringID = STR_JAVA_ERROR_CODE_DISK_OP_FAILURE;
            break;

        case USER_CANCEL:
        case J2ME_USER_CANCEL:
            MMIStringID = STR_JAVA_ERROR_CODE_CANCEL;
            break;

        case PUSH_INSTALL:
            MMIStringID = STR_JAVA_PUSH_INSTALL;
            break;

        case NORMAL_INSTALL:
            MMIStringID = STR_JAVA_NORMAL_INSTALL;
            break;

        case INSTALL_NA:
            MMIStringID = STR_JAVA_INSTALL_NA;
            break;

        case TOO_MANY_MID:
            MMIStringID = STR_JAVA_TOO_MANY_MID;
            break;

        case AUTHORIZED_BY:
            MMIStringID = STR_JAVA_INFO_AUTH;
            break;

        case OVER_MAX_INSTALL:
            MMIStringID = STR_JAVA_ERROR_CODE_OVER_MAX_INSTALL;
            break;

        case POST_ERROR:
            MMIStringID = STR_JAVA_ERROR_CODE_POST_ERROR;
            break;

    #ifdef __DRM_SUPPORT__
        case DRM_PROHIBIT:
            MMIStringID = STR_GLOBAL_DRM_PROHIBITED;
            break;
    #endif /* __DRM_SUPPORT__ */ 
        case COMMAND_OK:
            MMIStringID = STR_GLOBAL_OK;
            break;

        case COMMAND_CANCEL:
            MMIStringID = STR_GLOBAL_CANCEL;
            break;

        case COMMAND_BACK:
            MMIStringID = STR_GLOBAL_BACK;
            break;

        case COMMAND_DONE:
            MMIStringID = STR_GLOBAL_DONE;
            break;

        case COMMAND_SAVE:
            MMIStringID = STR_GLOBAL_SAVE;
            break;

        case COMMAND_OPTIONS:
            MMIStringID = STR_GLOBAL_OPTIONS;
            break;

        case MIDLET_RUNNING:
            MMIStringID = STR_JAVA_ERROR_CODE_MIDLET_RUNNING;
            break;

        case STRING_DATE:
            MMIStringID = STR_GLOBAL_DATE;
            break;
        case STRING_TIME:
            MMIStringID = STR_GLOBAL_TIME;
            break;
        case WRITE_PROTECTION:
            MMIStringID = STR_JAVA_ERROR_CODE_WRITE_PROTECTION;
            break;
        case J2ME_INSUFFICIENT_MEMORY:
        case MEMORY_ALLACTION_FAILURE:
            MMIStringID = STR_GLOBAL_INSUFFICIENT_MEMORY;
            break;
        case ROOT_DIR_FULL:
            MMIStringID = FMGR_FS_ROOT_DIR_FULL_TEXT;
            break;
        case JAVA_NO_CARD:
            MMIStringID = STR_JAVA_ERROR_CODE_NO_CARD;
            break;
        case INCORRECT_MIDLET_DATA:
            MMIStringID = STR_JAVA_ERROR_CODE_INCORRECT_MIDLET_DATA;
            break;
        case DISK_NOT_FOUND_WHEN_UPDATE:
            MMIStringID = STR_JAVA_ERROR_DISK_NOT_FOUND_WHEN_UPDATE;
            break;
        case DEFAULT_GAME_CAN_NOT_UPDATE:
            MMIStringID = STR_JAVA_DEFAULT_GAME_CAN_NOT_UPDATE;
            break;
        case INSTALL_UNTRUSTED_MIDS_CONFIRM:
            MMIStringID = STR_JAVA_INSTALL_UNTRUSTED_MIDS_CONFIRM;
            break;
        case UPDATE_NOT_NEW_VERSION:
            MMIStringID = STR_JAVA_INSTALL_UPDATE_NOT_NEW_VERSION;
            break;
        case UPDATE_LOCAL_INSTALL:
            MMIStringID = STR_JAVA_INSTALL_UPDATE_LOCAL_INSTALL;
            break;
        case DRM_NO_RIGHT:
            MMIStringID = STR_JAVA_INSTALL_DRM_NO_RIGHT;
            break;
        case J2ME_VM_IS_BUSY:
            MMIStringID = STR_JAVA_VM_BUSY;
            break;
        default:
            MMIStringID = STR_JAVA_ERROR_CODE_UNKNOWN_FAILURE;
            break;
    }
    return MMIStringID;

}

/*****************************************************************************
 * FUNCTION
 *  get_string_by_error_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_wchar *get_string_by_error_code(kal_int32 error_code)
{
    return (kal_wchar*) get_string((kal_uint16)get_str_id_by_error_code(error_code));
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_permission_string
 * DESCRIPTION
 *  The entry function to get user's permission to use Network or some
 *  resource.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_wchar *jam_get_permission_string(kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_java_permission_strid(index);

    return (kal_wchar*) get_string((kal_uint16) str_id);
}


/*****************************************************************************
 *  Java network
 *****************************************************************************/
kal_semid g_jam_nw_sem;    
kal_uint32 J2ME_active_nw_acc_id[MAX_VM_INSTANCE_NUM];

extern srv_dtcnt_prof_proxy_info_cnf_struct net_prof[MAX_VM_INSTANCE_NUM];
extern srv_dtcnt_prof_proxy_info_cnf_struct net_prof_temp;
extern srv_dtcnt_prof_proxy_info_cnf_struct net_prof_install;
extern kal_uint32 g_jam_install_acc_id;

#define SETTING_EXCLUDE_CRC(__setting_ptr__)                          \
    (((kal_uint32*)(__setting_ptr__)) + 1)

#define JAVA_SETTING_SIZE (sizeof(jam_mids_network_struct))
#define JAVA_SETTING_SIZE_CRC (JAVA_SETTING_SIZE - sizeof(kal_uint32))

/*****************************************************************************
 * FUNCTION
 *  jam_nw_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool jam_nw_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_FUNC, JAM_NW_ENTER); 
    if(kal_take_sem(g_jam_nw_sem, KAL_NO_WAIT) == KAL_SEM_NOT_AVAILABLE)
    {
        return KAL_FALSE;
    }
    return KAL_TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_leave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void jam_nw_leave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_FUNC, JAM_NW_LEAVE); 
    kal_give_sem(g_jam_nw_sem);

}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_crc_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 jam_nw_crc_check(kal_uint32 got_crc, void* buff, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 err_code = NW_OP_NO_ERR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(got_crc != jvm_util_update_crc(0, (kal_char*)buff, size))
    {
        err_code |= NW_OP_ERR_FILE_INCORRECT_PARAM;        
 	}  
    kal_trace(TRACE_FUNC, JAM_NW_CRC_CHECK, err_code); 
    return err_code;

}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_access_and_check_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 jam_nw_access_and_check_size(kal_int32 handle, kal_uint32 size, void* buf, kal_bool is_read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 byte;
    kal_uint32 err_code = NW_OP_NO_ERR;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(is_read)
    {

        if ((FS_Read(handle, (void*)buf, size, &byte)) < 0)
        {           
            err_code |= NW_OP_ERR_FILE_READ_FAIL;                
        }   
        if(byte != size)     
        {
            err_code |= NW_OP_ERR_FILE_INCORRECT_FORMAT;         
        }	
    }            
    else
    {

        if ((FS_Write(handle, (void*)buf, size, &byte)) < 0)
        {           
            err_code |= NW_OP_ERR_FILE_WRITE_FAIL;                
        }   
        if(byte != size)     
        {
            err_code |= NW_OP_ERR_FILE_INCORRECT_FORMAT;         
        }	        
    }   
    kal_trace(TRACE_FUNC, JAM_NW_ACCESS_AND_CHECK_SIZE,err_code);     
    return err_code;
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_open_and_check_sizes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  [ret]  the size of file if file is open successly
 *****************************************************************************/
static kal_int8 jam_nw_open_and_check_size(kal_char *mids_storage, kal_int32* fhandler, kal_uint32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    kal_int32 setting_handle = -1;
    kal_uint32 setting_file_size;
    kal_uint8 sim_index = g_mmi_java_nw_cntx.sim_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JAM_NW_OPEN_AND_CHECK_SIZE,mode);  
    jam_nw_adp_sim_id(&sim_index, BIT_TO_INTEGER1);
    kal_wsprintf(WCHARFilename_JAM, "%c:\\@java\\%s_nw%d.bin", work_sys_dir_path[0],mids_storage,sim_index);    
    setting_handle = FS_Open((U16*) WCHARFilename_JAM, mode);
    (*fhandler)  = setting_handle; 
    
	if (setting_handle < 0)
	{
	    return -1;
    }
    FS_GetFileSize(setting_handle, &setting_file_size);    
    kal_trace(TRACE_FUNC, JAM_NW_OPEN_AND_CHECK_SIZE_RET, setting_file_size);   
    return setting_file_size;

}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_reset_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool jam_nw_reset_setting(kal_char *mids_storage)
{
}



/*****************************************************************************
 * FUNCTION
 *  jam_nw_mids_get_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jam_nw_mids_get_connection(kal_char *mids_storage, jam_mids_network_struct* da_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 setting_handle = -1;
    kal_int32 setting_handle_global = -1;

    kal_uint32 err_code = NW_OP_NO_ERR;
    kal_int8 ret;
   jam_mids_network_struct setting;       


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(mids_storage == NULL)
        return;
    kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION); 
    if(!jam_nw_enter())
    {
        err_code |= NW_OP_ERR_BUSY;
        kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION_RET,err_code); 
        return err_code;        
    }  
    
    if((ret = jam_nw_open_and_check_size(mids_storage,&setting_handle, FS_READ_ONLY)) < 0)
    {
        err_code |= NW_OP_ERR_FILE_NOTFOUND;
        goto finalize;            
    }
    else
   {           
        if(ret == JAVA_SETTING_SIZE)
        {            
            kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION_USE_LOCAL); 
            err_code |=jam_nw_access_and_check_size(setting_handle, JAVA_SETTING_SIZE, (void*) &setting, KAL_TRUE);
            err_code |= jam_nw_crc_check(setting.CRC , (void *)SETTING_EXCLUDE_CRC(&setting), JAVA_SETTING_SIZE_CRC);                    
            
            if(err_code | NW_OP_NO_ERR)
            {            
                goto finalize;            
            }
            da_ptr->account_id = setting.account_id;
            kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION_RESULT, setting.account_id); 
            goto finalize;
            
        }
        else /* error */
        {        
            err_code |= NW_OP_ERR_FILE_INCORRECT_FORMAT;        
            goto finalize;        
        }    
   }

finalize:
    if(err_code & NW_OP_ERR_FILE_INCORRECT_FORMAT)
    {
        jam_nw_reset_setting(mids_storage);    
    }
    FS_Close(setting_handle_global);
    FS_Close(setting_handle); 
    jam_nw_leave();
    kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION_RET,err_code); 
    return err_code;        
  
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_tck_get_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jam_nw_tck_get_connection(jam_mids_network_struct* connection_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 setting_handle_global;

    kal_uint32 err_code = NW_OP_NO_ERR;
   jam_mids_network_struct setting;       

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION); 
    if(!jam_nw_enter())
    {
        err_code |= NW_OP_ERR_BUSY;
        kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION_RET,err_code); 
        return err_code;        
    }  
	 if(jam_nw_open_and_check_size("global",&setting_handle_global, FS_READ_ONLY) < 0)
	{
		err_code |= NW_OP_ERR_FILE_NOTFOUND;
		goto finalize;                  
	}
	else
	{
		err_code |= jam_nw_access_and_check_size(setting_handle_global, JAVA_SETTING_SIZE, (void*) &setting, KAL_TRUE);
		err_code |= jam_nw_crc_check(setting.CRC , (void *)SETTING_EXCLUDE_CRC(&setting), JAVA_SETTING_SIZE_CRC);

		if(err_code | NW_OP_NO_ERR)
		{            
			goto finalize;            
		}   
			connection_ptr->account_id = setting.account_id;
			kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION_RESULT, setting.account_id); 
		}	
finalize:
    FS_Close(setting_handle_global);
    jam_nw_leave();
    kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION_RET,err_code); 
    return err_code;        
}


void jam_nw_adp_sim_id(kal_uint8* sim_id,jam_sim_trans_type type)
{
    kal_int32 cnt = 0;
    switch(type)
    {
        case INTEGER0_TO_BIT:
            *sim_id = 1<<(*sim_id);
            break;
        case BIT_TO_INTEGER0:
            while(*sim_id>>1!=0)
            {
                (*sim_id) >>=1; 
                cnt++;
            }
            (*sim_id) = cnt;
            break;
        case INTEGER1_TO_BIT:
            --(*sim_id);
            *sim_id = 1<<(*sim_id);
            break;
        case BIT_TO_INTEGER1:
            while(*sim_id!=0)
            {
                (*sim_id) >>=1; 
                cnt++;
            }
            (*sim_id) = cnt;            
            break;
        default:
            break;
    }
}


kal_uint8 jam_mvm_get_valid_sim_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 sim_id = CBM_SIM_ID_SIM1;
    kal_bool is_valid = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    sim_id = jam_nw_get_sim_id(jam_mvm_get_storage_name_by_vm_id(vm_id));
    if ((sim_id == CBM_SIM_ID_SIM1 && srv_sim_ctrl_is_available(MMI_SIM1))
#if (MMI_MAX_SIM_NUM >= 2)
        || (sim_id == CBM_SIM_ID_SIM2 && srv_sim_ctrl_is_available(MMI_SIM2))
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        || (sim_id == CBM_SIM_ID_SIM3 && srv_sim_ctrl_is_available(MMI_SIM3))
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        || (sim_id == CBM_SIM_ID_SIM4 && srv_sim_ctrl_is_available(MMI_SIM4))
#endif
        )
    {
        is_valid = KAL_TRUE;
    }
    if (!is_valid)
    {
        sim_id =  srv_sim_ctrl_get_one_available_sim();
        jam_nw_adp_sim_id(&sim_id, BIT_TO_INTEGER0);
    }
    return sim_id;
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_get_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/    
kal_uint8 jam_nw_get_sim_id(kal_char *mids_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 sim_id = CBM_SIM_ID_SIM1;
    kal_int32 vm_id = jam_mvm_get_vm_id(mids_storage, -1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    kal_trace(TRACE_FUNC, JAM_NW_GET_SIM_ID); 
    
    if (vm_id != INVALIDE_VM_ID)
    {
        sim_id = cbm_get_sim_id(jam_mvm_get_account_id(vm_id));
    }
    return sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_mids_set_bearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/ 
kal_uint8 jam_nw_mids_set_bearer(jam_mids_network_struct* network,kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_FUNC, JAM_NW_MIDS_SET_BEARER); 
    
    kal_trace(JAM_JAVAAGENCY_GROUP, JAM_NW_MIDS_SET_BEARER_ACCT_PRINT,network->account_id);    
    if((g_mmi_java_nw_cntx.sim_index |SRV_DTCNT_SIM_TYPE_NONE) == 0)
    {
         J2ME_active_nw_acc_id[vm_id] =
        cbm_encode_data_account_id(
            CBM_DEFAULT_ACCT_ID,
            SRV_DTCNT_SIM_TYPE_NONE,
            jam_get_app_id(vm_id),
            KAL_FALSE);
    }
    else
    {
        J2ME_active_nw_acc_id[vm_id] = network->account_id; 
    }
    kal_trace(JAM_JAVAAGENCY_GROUP, JAM_NW_MIDS_SET_BEARER_J2ME_active_nw_acc_id_PRINT,vm_id,J2ME_active_nw_acc_id[vm_id]);
}

#ifdef BROWSER_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  jam_nw_mids_set_proxy_for_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/ 
kal_uint8 jam_nw_set_proxy_for_install(kal_uint32 acc_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_bool abort_received = KAL_FALSE;      
    module_type mod_id;
    ilm_struct send_ilm;    
    srv_dtcnt_prof_proxy_info_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    kal_trace(TRACE_FUNC, JAM_NW_MIDS_SET_BEARER_CONTENT);     
    req = construct_local_para(sizeof(srv_dtcnt_prof_proxy_info_req_struct), TD_CTRL);
    req->acc_id = acc_id;
    req->idx = SRV_DTCNT_ACCOUNT_PRIMARY;
    
     send_ilm.src_mod_id = MOD_JAM;
     send_ilm.dest_mod_id = MOD_MMI;
     send_ilm.local_para_ptr = (local_para_struct*) req;
     send_ilm.peer_buff_ptr = NULL;
     send_ilm.msg_id = MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_REQ;
     send_ilm.sap_id = J2ME_MMI_SAP;

     mod_id = stack_get_active_module_id();
     if (mod_id != MOD_JAM)
     {
         jvm_send_and_get_next_event(&send_ilm, KAL_TRUE, MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF, KAL_FALSE, KAL_TRUE, &abort_received);
     }
     else
     {
         msg_send(&send_ilm);
         get_next_event(KAL_TRUE, MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF, KAL_FALSE, KAL_TRUE, &abort_received);
     }    
     if (net_prof_temp.result == 1 )/* query successful */
     {
 
        net_prof_install = net_prof_temp;
     }
     else
     {
            memset(&net_prof_install, 0, sizeof(srv_dtcnt_prof_proxy_info_cnf_struct));
            net_prof_install.px_info.acc_id = cbm_encode_data_account_id(
                CBM_INVALID_NWK_ACCT_ID,
                0,
                0,
                KAL_FALSE);
     } 
    kal_trace(TRACE_FUNC, JAM_NW_MIDS_SET_BEARER_CONTENT_DONE);     
     }
#endif
     

/*****************************************************************************
 * FUNCTION
 *  jam_nw_mids_set_bearer_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/ 
kal_uint8 jam_nw_mids_set_bearer_content(kal_uint32 account_id,kal_bool is_bearer_fallback,kal_int32 vm_id)
    {    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_bool abort_received = KAL_FALSE;      
    module_type mod_id;
    ilm_struct send_ilm;    
    srv_dtcnt_prof_proxy_info_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
/* fatman */    
    kal_trace(TRACE_FUNC, JAM_NW_MIDS_SET_BEARER_CONTENT);     
    
    req = construct_local_para(sizeof(srv_dtcnt_prof_proxy_info_req_struct), TD_CTRL);
    req->acc_id = account_id;

    req->idx = SRV_DTCNT_ACCOUNT_PRIMARY;

    send_ilm.src_mod_id = MOD_JAM;
    send_ilm.dest_mod_id = MOD_MMI;
    send_ilm.local_para_ptr = (local_para_struct*) req;
    send_ilm.peer_buff_ptr = NULL;
    send_ilm.msg_id = MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_REQ;
    send_ilm.sap_id = J2ME_MMI_SAP;

    mod_id = stack_get_active_module_id();
    if (mod_id != MOD_JAM)
    {
        jvm_send_and_get_next_event(&send_ilm, KAL_TRUE, MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF, KAL_FALSE, KAL_TRUE, &abort_received);
    }
    else
    {
        msg_send(&send_ilm);
        get_next_event(KAL_TRUE, MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF, KAL_FALSE, KAL_TRUE, &abort_received);
    }
     //if (net_prof_temp.result == 1 )/* query successful */
    {
        net_prof[vm_id] = net_prof_temp;
        net_prof[vm_id].px_info.acc_id = J2ME_active_nw_acc_id[vm_id];
        kal_trace(TRACE_FUNC,JAM_NW_MIDS_SET_BEARER_CONTENT_RET,net_prof[vm_id].px_info.acc_id);
    }
    /*else
    {
        memset(&net_prof[vm_id], 0, sizeof(srv_dtcnt_prof_proxy_info_cnf_struct));
        net_prof[vm_id].px_info.acc_id = J2ME_active_nw_acc_id[vm_id];
        J2ME_active_nw_acc_id[vm_id] = 255;
    }*/            
    kal_trace(TRACE_FUNC, JAM_NW_MIDS_SET_BEARER_CONTENT_DONE);         
}  
/*****************************************************************************
 * FUNCTION
 *  jam_nw_init_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jam_nw_init_setting(jam_mids_network_struct* setting_ptr,kal_int32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U8 app_id = jam_get_app_id(0);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    kal_trace(TRACE_FUNC, JAM_NW_INIT_SETTING);   
    setting_ptr->account_id = 
    cbm_encode_data_account_id(
        CBM_DEFAULT_ACCT_ID,
        sim_id,
        g_mmi_java_app_id,
        KAL_FALSE);
}


void jam_nw_set_profile_file_name(WCHAR *setting_file, kal_int32 index, kal_char* mids_storage)
{
        kal_wsprintf(setting_file, "%c:\\@java\\%s_nw%d.bin",work_sys_dir_path[0], mids_storage,index+1);    
}


kal_uint32 jam_nw_create_setting(kal_char *mids_storage, jam_mids_network_struct* setting_ptr, kal_char* preferred_con_profile, kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_int32 setting_handle = -1;
    kal_uint32 err_code = NW_OP_NO_ERR; 
    kal_uint32 acc_id = 0;
    kal_uint32 ori_acct_id;
    kal_bool always_ask;
    kal_uint8 app_id;
    cbm_sim_id_enum sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    kal_trace(TRACE_FUNC, JAM_NW_CREATE_SETTING); 
    if(!jam_nw_enter())
    {
        err_code |= NW_OP_ERR_BUSY;
        kal_trace(TRACE_FUNC, JAM_NW_CREATE_SETTING_RET, err_code); 
        return err_code;        
    }   

    jam_nw_set_profile_file_name(WCHARFilename_JAM,index,mids_storage);
    setting_handle = FS_Open((U16*) WCHARFilename_JAM, FS_CREATE_ALWAYS | FS_COMMITTED);
    if (setting_handle < 0)
    {
        err_code |= NW_OP_ERR_FILE_NOTFOUND;
        jam_nw_leave();
        FS_Close(setting_handle);
        kal_trace(TRACE_FUNC, JAM_NW_CREATE_SETTING_RET, err_code);         
        return err_code;
    }  
    jam_nw_init_setting(setting_ptr,index); 
    
    if(strcmp(mids_storage,"global")!=0)
    {

        if(preferred_con_profile!=0)
        {
            if(SRV_DTCNT_RESULT_SUCCESS == srv_dtcnt_get_acc_id_by_apn((S8 * )preferred_con_profile, &acc_id))
            {
                cbm_decode_data_account_id(
                    acc_id,
                    &sim_id,
                    &app_id,
                    &always_ask,
                    &ori_acct_id);
                setting_ptr->account_id = 
                cbm_encode_data_account_id(
                    ori_acct_id,
                    sim_id,
                    g_mmi_java_app_id,
                    always_ask);
            }
        }
    }

    setting_ptr->CRC = 
    jvm_util_update_crc(0, (kal_char*)SETTING_EXCLUDE_CRC(setting_ptr), JAVA_SETTING_SIZE_CRC);

    err_code |=jam_nw_access_and_check_size(setting_handle, 
                                            JAVA_SETTING_SIZE, 
                                            (void*)setting_ptr, 
                                            KAL_FALSE);        
    FS_Close(setting_handle);    
    jam_nw_leave();    
    kal_trace(TRACE_FUNC, JAM_NW_CREATE_SETTING_RET, err_code);     
    return err_code;             
}
/*****************************************************************************
 * FUNCTION
 *  jam_nw_delete_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jam_nw_delete_setting(kal_char *mids_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_uint32 err_code = NW_OP_NO_ERR;
    kal_uint32 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    kal_trace(TRACE_FUNC, JAM_NW_DELETE_SETTING); 
    if(!jam_nw_enter())
    {
        err_code |= NW_OP_ERR_BUSY;
        kal_trace(TRACE_FUNC, JAM_NW_DELETE_SETTING_RET); 
        return err_code;        
    }  
    for(index = 1;index<=MMI_SIM_TOTAL;index++)
    {
        kal_wsprintf(WCHARFilename_JAM, "%c:\\@java\\%s_nw%d.bin\0", work_sys_dir_path[0],mids_storage,index);    
        if(FS_Delete(WCHARFilename_JAM) < 0)
        {
            err_code |= NW_OP_ERR_FILE_DEL_FAIL;
        }
    }
    jam_nw_leave();
    kal_trace(TRACE_FUNC, JAM_NW_DELETE_SETTING_RET); 
    return err_code;                 
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_get_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/

kal_uint32 jam_nw_get_setting(kal_char *mids_storage, jam_mids_network_struct* setting_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 setting_handle = -1;
    kal_int32 setting_file_size;
    kal_uint32 err_code = NW_OP_NO_ERR;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_FUNC, JAM_NW_GET_SETTING); 
    
    if(!jam_nw_enter())
    {
        err_code |= NW_OP_ERR_BUSY;
        kal_trace(TRACE_FUNC, JAM_NW_GET_SETTING_RET); 
        return err_code;        
    }   
            
    if((setting_file_size = jam_nw_open_and_check_size(mids_storage,&setting_handle, FS_READ_ONLY)) < 0)
    {
        err_code |= NW_OP_ERR_FILE_NOTFOUND;
        goto finalize;                  
    }       
    else if(setting_file_size == JAVA_SETTING_SIZE)
    {
        err_code |= jam_nw_access_and_check_size(setting_handle, JAVA_SETTING_SIZE, (void*)setting_ptr, KAL_TRUE);
        err_code |= jam_nw_crc_check(setting_ptr->CRC , (void *)SETTING_EXCLUDE_CRC(setting_ptr), JAVA_SETTING_SIZE_CRC);
        
        if(err_code | NW_OP_NO_ERR)
        {            
            goto finalize;            
        }        
    }
    else /* error */
    {
	    err_code |= NW_OP_ERR_FILE_INCORRECT_FORMAT;
    } 
finalize:
    if(err_code & NW_OP_ERR_FILE_INCORRECT_FORMAT)
    {
        jam_nw_reset_setting(mids_storage);
    }            
    FS_Close(setting_handle);        
    jam_nw_leave();    
    kal_trace(TRACE_FUNC, JAM_NW_GET_SETTING_RET);     
    return err_code;       
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_set_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/ 

kal_uint32 jam_nw_set_setting(kal_char *mids_storage, jam_mids_network_struct* setting_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint32 err_code = NW_OP_NO_ERR;
    kal_int32 setting_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_FUNC, JAM_NW_SET_SETTING,setting_ptr->Use_default); 
    if(!jam_nw_enter())
    {
        err_code |= NW_OP_ERR_BUSY;
        kal_trace(TRACE_FUNC, JAM_NW_SET_SETTING_RET, err_code); 
        return err_code;        
    }  

    if(jam_nw_open_and_check_size(mids_storage,&setting_handle, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_COMMITTED) < 0)
    {
        err_code |= NW_OP_ERR_FILE_NOTFOUND;                
    }      

    setting_ptr->CRC = 
    jvm_util_update_crc(0, (kal_char*)SETTING_EXCLUDE_CRC(setting_ptr), JAVA_SETTING_SIZE_CRC);       
    err_code |=jam_nw_access_and_check_size(setting_handle, JAVA_SETTING_SIZE, (void*)setting_ptr, KAL_FALSE); 
    FS_Close(setting_handle);    
    jam_nw_leave();   
    kal_trace(TRACE_FUNC, JAM_NW_SET_SETTING_RET, err_code); 
    return err_code;       
}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_dtcnt_update_conn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/ 
kal_int8 jam_nw_dtcnt_update_conn(srv_dtcnt_acct_update_ind_evt_struct update_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int8 err_code = NW_OP_NO_ERR;
    FS_DOSDirEntry info;
    WCHAR name_pattern[MAX_WCHAR_FILENAME_LEN];
    WCHAR filename[MAX_WCHAR_FILENAME_LEN];
    kal_int32 setting_handle = -1;
    kal_uint32 setting_file_size;
    kal_int32 handle;    
    jam_mids_network_struct setting;

    kal_uint32 ori_acct_id;
    kal_bool always_ask;
    kal_uint8 app_id;
    cbm_sim_id_enum sim_id;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(JAM_JAVAAGENCY_GROUP,JAM_NW_DTCNT_UPDATE_CONN_START,update_info.sim_id,update_info.sim_id_old,update_info.acc_id);
    if(update_info.sim_id == update_info.sim_id_old)
        return NW_OP_NO_ERR;
    
    if(!jam_nw_enter())
    {
        err_code |= NW_OP_ERR_BUSY;
        kal_trace(TRACE_FUNC, JAM_NW_UPDATE_PROFILE_RET, err_code); 
        return err_code;        
    }  
    
    kal_wsprintf(name_pattern, "%c:\\@java\\*_nw?.bin",work_sys_dir_path[0]);
    kal_trace(TRACE_FUNC, JAM_NW_UPDATE_PROFILE_LOCAL); 
    /* find all local setting and update it if it use itself setting */
    if ((handle = FS_FindFirst(
                    (UI_string_type) name_pattern,
                    0,
                    0,
                    &info,
                    (WCHAR*) filename,
                    MAX_WCHAR_FILENAME_LEN)) >= 0)
    {
        do
        {
            WCHAR full_filename[MAX_WCHAR_FILENAME_LEN];

            kal_wsprintf(full_filename, "%c:\\@java\\",work_sys_dir_path[0]);
            mmi_wcscat(full_filename,filename); 

            setting_handle = FS_Open((U16*) full_filename, FS_READ_WRITE);
            if (setting_handle < 0)
            {
                err_code |= NW_OP_ERR_FILE_NOTFOUND;
                jam_nw_leave();
                kal_trace(TRACE_FUNC, JAM_NW_UPDATE_PROFILE_RET, err_code); 
                FS_Close(setting_handle);   
                break;
            } 
			
            FS_GetFileSize(setting_handle, &setting_file_size);
            memset(&setting, 0, sizeof(jam_mids_network_struct));

            err_code |= jam_nw_access_and_check_size(setting_handle, setting_file_size, (void*)&setting, KAL_TRUE);
            err_code |= jam_nw_crc_check(setting.CRC , (void *)SETTING_EXCLUDE_CRC(&setting), JAVA_SETTING_SIZE_CRC);            

            if(err_code | NW_OP_NO_ERR)
            {
                FS_Close(setting_handle);   
                break;
            }  
            cbm_decode_data_account_id(
                setting.account_id,
                &sim_id,
                &app_id,
                &always_ask,
                &ori_acct_id);
            if(ori_acct_id == update_info.acc_id)
            {
            setting.account_id = 
            cbm_encode_data_account_id(
                update_info.acc_id,
                update_info.sim_id -1,
                jam_get_app_id(0),
                KAL_FALSE);
            }
		
            FS_Seek(setting_handle, 0, FS_FILE_BEGIN);

            setting_file_size = JAVA_SETTING_SIZE;
            setting.CRC= jvm_util_update_crc(0, (kal_char*)SETTING_EXCLUDE_CRC(&setting), JAVA_SETTING_SIZE_CRC);                   
            err_code |=jam_nw_access_and_check_size(setting_handle, setting_file_size, (void*)&setting, KAL_FALSE);                
            
            if(err_code | NW_OP_NO_ERR)
            {
                FS_Close(setting_handle);   
                break;
            } 			
            FS_Close(setting_handle);   
        } while (FS_FindNext(handle, &info, (WCHAR*) filename, MAX_WCHAR_FILENAME_LEN) >= 0);
    }
    else
    {
        err_code |= handle;
    }  
    if(err_code & NW_OP_ERR_FILE_INCORRECT_FORMAT)
    {
        //jam_nw_reset_setting(mids_storage);        
    }    
    FS_FindClose(handle);    
    FS_Close(setting_handle);    
    jam_nw_leave();   
    kal_trace(TRACE_FUNC, JAM_NW_UPDATE_PROFILE_RET, err_code); 
    return err_code;     
}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_dtcnt_delete_conn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/ 
kal_bool jam_nw_dtcnt_delete_conn(srv_dtcnt_acct_delete_ind_evt_struct delete_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint32 err_code = NW_OP_NO_ERR;
    FS_DOSDirEntry info;
    WCHAR name_pattern[MAX_WCHAR_FILENAME_LEN];
    WCHAR filename[MAX_WCHAR_FILENAME_LEN];
    kal_int32 setting_handle = -1;
    kal_uint32 setting_file_size;
    kal_int32 handle;    
    jam_mids_network_struct setting;
    kal_int32 delcount = 0;
    kal_uint32 ori_acct_id;
    kal_bool always_ask;
    kal_uint8 app_id;
    cbm_sim_id_enum sim_id;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(JAM_JAVAAGENCY_GROUP,JAM_NW_DTCNT_DELETE_CONN);
    if(!jam_nw_enter())
    {
        err_code |= NW_OP_ERR_BUSY;
        kal_trace(TRACE_FUNC, JAM_NW_UPDATE_PROFILE_RET, err_code); 
        return err_code;        
    }  
    
    kal_wsprintf(name_pattern, "%c:\\@java\\*_nw?.bin",work_sys_dir_path[0]);
    kal_trace(TRACE_FUNC, JAM_NW_UPDATE_PROFILE_LOCAL); 
    /* find all local setting and update it if it use itself setting */
    if ((handle = FS_FindFirst(
                    (UI_string_type) name_pattern,
                    0,
                    0,
                    &info,
                    (WCHAR*) filename,
                    MAX_WCHAR_FILENAME_LEN)) >= 0)
    {
        do
        {
            WCHAR full_filename[MAX_WCHAR_FILENAME_LEN];

            kal_wsprintf(full_filename, "%c:\\@java\\",work_sys_dir_path[0]);
            mmi_wcscat(full_filename,filename); 

            setting_handle = FS_Open((U16*) full_filename, FS_READ_WRITE);
            if (setting_handle < 0)
            {
                err_code |= NW_OP_ERR_FILE_NOTFOUND;
                jam_nw_leave();
                kal_trace(TRACE_FUNC, JAM_NW_UPDATE_PROFILE_RET, err_code); 
                FS_Close(setting_handle);   
                break;
            } 
			
            FS_GetFileSize(setting_handle, &setting_file_size);
            memset(&setting, 0, sizeof(jam_mids_network_struct));

            err_code |= jam_nw_access_and_check_size(setting_handle, setting_file_size, (void*)&setting, KAL_TRUE);
            err_code |= jam_nw_crc_check(setting.CRC , (void *)SETTING_EXCLUDE_CRC(&setting), JAVA_SETTING_SIZE_CRC);            

            if(err_code | NW_OP_NO_ERR)
            {
                FS_Close(setting_handle);   
                break;
            }  
            
            cbm_decode_data_account_id(
                setting.account_id,
                &sim_id,
                &app_id,
                &always_ask,
                &ori_acct_id);
            for( delcount = 0; delcount < delete_info.del_num; delcount++ )
            {
                if(ori_acct_id == delete_info.acc_id[delcount])
                {
                    jam_nw_init_setting(&setting, sim_id);
                }
            }
	
            FS_Seek(setting_handle, 0, FS_FILE_BEGIN);
            setting_file_size = JAVA_SETTING_SIZE;
            setting.CRC= jvm_util_update_crc(0, (kal_char*)SETTING_EXCLUDE_CRC(&setting), JAVA_SETTING_SIZE_CRC);                   
            err_code |=jam_nw_access_and_check_size(setting_handle, setting_file_size, (void*)&setting, KAL_FALSE);                
            
            if(err_code | NW_OP_NO_ERR)
            {
                FS_Close(setting_handle);   
                break;
            } 			
            FS_Close(setting_handle);   
        } while (FS_FindNext(handle, &info, (WCHAR*) filename, MAX_WCHAR_FILENAME_LEN) >= 0);
    }      
    else
    {
        err_code |= handle;
    }
    if(err_code & NW_OP_ERR_FILE_INCORRECT_FORMAT)
    {
        //jam_nw_reset_setting(mids_storage);        
    }    
    FS_FindClose(handle);    
    FS_Close(setting_handle);    
    jam_nw_leave();   
    kal_trace(TRACE_FUNC, JAM_NW_UPDATE_PROFILE_RET, err_code); 
    return err_code;   
}


void jam_nw_select_prefer_setting(void)
{
    srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_NONE;
    srv_dtcnt_get_sim_preference(&simType);
    kal_trace(JAM_JAVAAGENCY_GROUP, JAM_MVM_VM_NW_PROFILE_INIT,simType);  
    g_mmi_java_nw_cntx.sim_index &= NW_SIM_ID_DEFAULT;
    g_mmi_java_nw_cntx.sim_index  |= 1<<( (simType-1)>0?simType-1:0);
}


/*****************************************************************************
 * FUNCTION
 *	jam_mvm_get_account_id
 *
 *   Unified Entry to get the profile for Midlet and Installer. 20110913::Modified by Dongdong
 * DESCRIPTION
 *	
 * PARAMETERS
 *	vm_id				[IN]		
 *	profile struct			[IN]		
 *		  
 * RETURNS
 *	
 *****************************************************************************/

kal_uint32 jam_mvm_get_account_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
	srv_dtcnt_sim_type_enum sim_type;
    /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/  
	if (vm_id == J2ME_HTTP_INSTALL_APP_ID)
	{
		srv_dtcnt_get_sim_preference(&sim_type);
		g_jam_install_acc_id = 
			cbm_encode_data_account_id(
			CBM_DEFAULT_ACCT_ID,
			(sim_type - 1)>0?sim_type-1:0,
			g_mmi_java_install_app_id,
			KAL_FALSE);
		return g_jam_install_acc_id;
	}
	else
	{
		return J2ME_active_nw_acc_id[vm_id];
    }
}



/*****************************************************************************
 * FUNCTION
 *	jam_mvm_get_network_profile_by_vm_id
 *
 *   Unified Entry to get the profile for Midlet and Installer. 20110913::Modified by Dongdong
 * DESCRIPTION
 *	
 * PARAMETERS
 *	vm_id				[IN]		
 *	profile struct			[IN]		
 *		  
 * RETURNS
 *	
 *****************************************************************************/

srv_dtcnt_prof_proxy_info_cnf_struct* jam_mvm_get_network_profile_by_vm_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_dtcnt_prof_proxy_info_cnf_struct* prof = NULL;

    /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/  
	if (vm_id == J2ME_HTTP_INSTALL_APP_ID)
	{
		return &net_prof_install;
	}
	else
	{
        prof = &net_prof[vm_id];
        return prof;
    }
}

kal_int32 jam_mvm_vm_nw_profile_deinit(kal_int32 vm_id)
{
    return J2ME_NO_ERROR;
}
kal_int32 jam_mvm_vm_nw_profile_init(kal_int32 vm_id)
{
    if (!g_mmi_java_is_no_network_usable)
    {   
        jam_mids_network_struct connection = {0};
        kal_char* mids_storage_name = NULL;
        if(jam_mvm_get_java_mode()== JAVA_NORMAL_MODE)
        {
            mids_storage_name = jam_mvm_get_storage_name_by_vm_id(vm_id);
            jam_nw_select_prefer_setting();
        }
        else
        {
            mids_storage_name = "global";
            jam_nw_tck_get_connection(&connection);
        }
        jam_nw_mids_get_connection(mids_storage_name,&connection); 
        jam_nw_mids_set_bearer(&connection,vm_id);
    }
    else
    {
        J2ME_active_nw_acc_id[vm_id] = 255;    
    }
    return J2ME_NO_ERROR;
}
kal_int32 jam_mvm_network_deinit(void)
{    
    jnw_network_finalize();
    return J2ME_NO_ERROR;
}
kal_int32 jam_mvm_network_init(void)
{
    jnw_network_initialize();
    return J2ME_NO_ERROR;
}

kal_int32 jam_mvm_vm_network_deinit(kal_int32 vm_id)
{
    jnw_http_finalize(vm_id);
    j2me_deactivate_socket(vm_id);
    return J2ME_NO_ERROR;
}
kal_int32 jam_mvm_vm_network_init(kal_int32 vm_id)
{
    jnw_http_initialize(vm_id);
    return J2ME_NO_ERROR;
}


void jam_create_mids_nw_setting(char* storage_name,char* preferred_con_profile, int* error_code)
{
    int ret = J2ME_NO_ERROR;
    int count = 0;
    int idx = 0;
    jam_mids_network_struct mids_nw_setting = {0};


    for(idx = 0; idx< MMI_SIM_TOTAL; idx++)
    while((ret = jam_nw_create_setting(storage_name, &mids_nw_setting,preferred_con_profile,idx)) == NW_OP_ERR_BUSY)
    {
        count++;
        kal_sleep_task(10);
        if(count == 10)
        {
            *error_code = DISK_OPERATION_FAIL;
            return;
        }
    }
    if(J2ME_NO_ERROR != ret){
        *error_code = DISK_OPERATION_FAIL;
    }else{
        *error_code = J2ME_NO_ERROR;
    }
    #ifdef MIDP_FILE_DEBUG
    sprintf(_kvmLogStr, "[ERROR] create nw setting:%s  error code =%d",storage_name, error_code);
    Kputs(_kvmLogStr);
    #endif
}


#ifdef BROWSER_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  jam_nw_reserve_profile_content
 * DESCRIPTION
 *  Get proxy for Java install
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/ 
void jam_nw_reserve_profile_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    cbm_account_info_struct acct_info;
    /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/   
    if (cbm_decode_data_account_id_ext(g_jam_install_profie_content.data_account_primary_id, &acct_info) == CBM_OK)
    {    
	acct_info.app_id = g_mmi_java_install_app_id;
	cbm_encode_data_account_id_ext(
		g_jam_install_profie_content.data_account_primary_id,
		&g_jam_install_acc_id,
		&acct_info);
    }
    
   net_prof_install.px_info.acc_id = g_jam_install_acc_id;
   memcpy(net_prof_install.px_info.px_addr, g_jam_install_profie_content.proxy_ip, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN+1);
   memcpy(net_prof_install.px_info.px_authpw, g_jam_install_profie_content.password, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1);
   memcpy(net_prof_install.px_info.px_authid, g_jam_install_profie_content.username, SRV_DTCNT_PROF_MAX_PX_NAME_LEN + 1);
   net_prof_install.px_info.px_port = g_jam_install_profie_content.proxy_port;
   memcpy(net_prof_install.px_info.px_startpage, g_jam_install_profie_content.url, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
   switch(g_jam_install_profie_content.conn_type)
    {
        case SRV_BRW_PROF_CONN_TYPE_NONE:
            net_prof_install.px_info.px_service =  SRV_DTCNT_PROF_PX_SRV_NONE;
            break;
        case SRV_BRW_PROF_CONN_TYPE_HTTP:
            net_prof_install.px_info.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
            break;
        case SRV_BRW_PROF_CONN_TYPE_CONNECTION_OREINTED:
            net_prof_install.px_info.px_service = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
            break;
        case SRV_BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE:
            net_prof_install.px_info.px_service = SRV_DTCNT_PROF_PX_SRV_CL_WSP;
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_get_proxy_for_install
 * DESCRIPTION
 *  Get proxy for Java install
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/ 
kal_bool jam_nw_get_proxy_for_install(kal_bool *is_success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    ilm_struct send_ilm;
    module_type mod_id;
    kal_bool abort = KAL_FALSE;
    srv_dtcnt_prof_proxy_info_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    req = construct_local_para(sizeof(srv_dtcnt_prof_proxy_info_req_struct), TD_CTRL);
    req->acc_id = g_jam_install_acc_id;
    req->idx = SRV_DTCNT_ACCOUNT_PRIMARY;
    
    send_ilm.src_mod_id = MOD_JAM;
    send_ilm.dest_mod_id = MOD_MMI;
    send_ilm.local_para_ptr = (local_para_struct*) req;
    send_ilm.peer_buff_ptr = NULL;
    send_ilm.msg_id = MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_REQ;
    send_ilm.sap_id = J2ME_MMI_SAP;    
    
    net_prof_temp.result = 0;		
    mod_id = stack_get_active_module_id();
    if (mod_id != MOD_JAM)
    {
        jvm_send_and_get_next_event(&send_ilm, KAL_TRUE, MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF, KAL_FALSE, KAL_TRUE, &abort);
    }
    else
    {
        msg_send(&send_ilm);
        get_next_event(KAL_TRUE, MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF, KAL_FALSE, KAL_TRUE, &abort);
    }
    if (net_prof_temp.result == 1 )/* query successful */
    {
        net_prof_install = net_prof_temp;
        net_prof_install.px_info.acc_id = g_jam_install_acc_id;
        *is_success = KAL_TRUE;
    }
    else
    {
        memset(&net_prof_install, 0, sizeof(srv_dtcnt_prof_proxy_info_cnf_struct));	
        g_jam_install_acc_id = 255;
        *is_success = KAL_FALSE;
    }
    return abort;
}
#else
kal_bool jam_nw_get_proxy_for_install(kal_bool *is_success)
{
    return KAL_FALSE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  jam_nw_is_default_network_setting_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/ 
kal_bool jam_nw_is_default_network_setting_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_int32 setting_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    jam_nw_set_profile_file_name(WCHARFilename_JAM, 0, "global");
    setting_handle = FS_Open((U16*) WCHARFilename_JAM, FS_READ_ONLY);
    FS_Close(setting_handle);
    if (setting_handle >= FS_NO_ERROR)
    {       
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

