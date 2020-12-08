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
 *  MREPushUISrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MRE Push Service implement file.
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "vmswitch.h" 
#ifdef __MRE_SAL_PN__
#include "MREPushSrvProt.h"
#include "vmcert.h"
#include "vmgettag.h"
#include "Conversions.h"
#include "MRESrvGProt.h"
#include "mdi_audio.h"
#include "vmstatusbar.h"
#include "app_str.h"
#include "gui_data_types.h"
static srv_mre_mpr_pending_popup mpr_popup[MAX_PENDING_POPUP_COUNT];
static srv_mre_mpr_status_icon mpr_icon[4];
extern MMI_BOOL mre_push_usb_ms_mode;
extern MMI_BOOL mre_push_dev_plug_out;
extern srv_mre_appmgr_push_payload_ram_struct  push_cache; 

static MMI_BOOL srv_mre_is_app_in_rom(WCHAR* app_name);
extern VMINT vm_statusbar_get_unused_iconid(void);
extern void *_vm_kernel_malloc(int size);
extern void _vm_kernel_free(void* ptr);
extern int vm_res_get_image_and_size_from_rom(short * filename, unsigned long image_id, void** buff, unsigned long *size);
extern int vm_res_get_image_and_size_from_file(short * filename, unsigned long image_id, void* buff, unsigned long *size);
extern int vm_statusbar_get_by_handle_icon_id(int icon_id);
extern MMI_BOOL vm_statusbar_set_handle(int icon_id, int icon_handle);
extern void wgui_status_icon_bar_change_icon_image_ex(S32 icon_id, PU8 image_data);
extern VMINT vm_res_get_string_and_size_from_file(VMWSTR filename, VMUINT32 string_id, void *buff, VMUINT32 *size);
extern VMINT vm_res_get_string_and_size_from_rom(VMWSTR filename, VMUINT32 string_id, void **buff, VMUINT32 *size);
extern srv_mre_launch_app_result_enum srv_mre_launch_app_ex(U16 *app_path, srv_mre_launch_app_cb_t app_cb);
extern mmi_ret srv_mre_push_receiver_file_read(U32 AppId,srv_mre_appmgr_push_installed_info_struct* read_info,MMI_BOOL flag);
extern mmi_ret srv_mre_push_receiver_file_write(U32 AppId,srv_mre_appmgr_push_installed_info_struct* write_info,MMI_BOOL flag);
extern VMINT vm_res_generate_image_filename(VMWSTR filename, VMUINT32 image_id, VMWSTR image_filename);
extern VMINT vm_res_generate_audio_filename(VMWSTR filename, VMUINT32 audio_id, VMWSTR audio_filename);
extern VMINT vm_res_get_audio_and_size_from_file(VMWSTR filename, VMUINT32 audio_id, void *buff, VMUINT32 *size);
extern void vm_pmng_set_push_app_flag(U32 index);
extern VMINT vm_res_get_audio_and_size_from_rom(VMWSTR filename, VMUINT32 audio_id, void **buff, VMUINT32 *size);
extern UI_string_type get_string(UI_string_ID_type stringID);
extern MMI_BOOL vm_statusbar_unset_handle(VMINT icon_id, VMINT icon_handle);
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  info     : [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT srv_mre_push_receiver_get_statusbar(U32 appId)
{
	VMINT unused_iconid = 0;
	unused_iconid = vm_statusbar_get_unused_iconid();
	
	return unused_iconid;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  info     : [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static U8* srv_mre_push_receiver_query_default_app_icon(WCHAR* app_path, U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *imgBuffer = NULL, *tmp_ptr = NULL;
    VMUINT ab2_support=0;
    U32 img_size = 0, new_size = 0;
    S32 tag_size = sizeof(VMUINT);
    U32 width_height;
    S32 width = 0;
	S32 height = 0; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((!srv_mre_get_app_image(app_path, NULL, &img_size)) || (img_size == 0))
	{
		return imgBuffer;
	}

    if (vm_get_vm_tag((short *)app_path, VM_CE_INFO_ADV_ICON, &ab2_support, &tag_size) == GET_TAG_TRUE)
    {
        MPR_TRACE2(TRC_MPR_97b42ac8440d4b7aa30af23d0f2b2eb6, 1, ab2_support);
        if (ab2_support == 1)
        {
            new_size = img_size;
        }
        else
        {
            new_size = img_size + 8;
        }
    }
    else
    {
        MPR_TRACE2(TRC_MPR_97b42ac8440d4b7aa30af23d0f2b2eb6, 2, ab2_support);
        return imgBuffer;
    }

	//if( NULL == (imgBuffer = (U8*) _vm_kernel_malloc(img_size + 8)))
	if( NULL == (imgBuffer = (U8*) _vm_kernel_malloc(new_size)))
	{
		return imgBuffer;
	}

    if (ab2_support == 1)
    {
        tmp_ptr = imgBuffer;
    }
    else
    {
        tmp_ptr = imgBuffer + 8;
    }
	if(!srv_mre_get_app_image(app_path, tmp_ptr, &img_size))
	{
		_vm_kernel_free(imgBuffer);
        imgBuffer = NULL;
		return imgBuffer;
	}

    if (ab2_support == 0)
    {
    	gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_GIF, imgBuffer + 8, img_size, &width, &height);
    	width_height  = ((width & 0XFFF) << 12) | (height & 0XFFF);

    	imgBuffer[0] = IMAGE_TYPE_GIF;
    	imgBuffer[1] = 1;
    	imgBuffer[2] = (img_size & 0xff);
    	imgBuffer[3] = ((img_size & 0xff00) >> 8);
    	imgBuffer[4] = ((img_size & 0xff0000) >> 16);
    	imgBuffer[5] = (width_height & 0xff);
    	imgBuffer[6] = ((width_height & 0xff00) >> 8);
    	imgBuffer[7] = ((width_height & 0xff0000) >> 16);
    }
    (*size) = img_size;
    return imgBuffer;
}

S32 srv_mre_push_receiver_show_status_icon(U32 app_id,WCHAR* app_path, WCHAR* app_name, U32 icon_res, U8 **buffer, S32 *size)
{
    //U16 image_type = GDI_IMAGE_TYPE_INVALID;
	int icon_id =0;
   // int  tag_size = 4;//ab2_support = 0,
	S32 len = 0, query_ret = 0;//width = 0, height = 0, 
	//U32 width_height;
	//int is_find = 0;
	int i = 0;
	U32 img_size = 0;
	U8 *img_ptr = NULL, *tmp_img_ptr = NULL;
    srv_mre_appmgr_app_type_enum app_type;
    char *app_name_c;

    /* Get icon */
    len = mmi_ucs2strlen((const CHAR*)app_name);
    app_name_c = (char*)OslMalloc((len+1));
    memset(app_name_c, 0, (len+1));
    mmi_ucs2_n_to_asc((CHAR*)app_name_c, (CHAR*)app_name, len*sizeof(WCHAR));
    app_type = srv_mre_appmgr_get_app_type(app_name_c);
    OslMfree(app_name_c);
    switch (app_type)
    {
        case SRV_MRE_APPMGR_APP_TYPE_ROM:
        {
            /* Case pre-buildin MRE App so use raw data */
            query_ret = vm_res_get_image_and_size_from_rom((short *)app_path, icon_res,(void **)(&tmp_img_ptr), (unsigned long *)(&img_size));
            MPR_TRACE4(TRC_MPR_c8bf9a0e34714e4eae9014e84cbbba7f, 1, icon_res, query_ret, img_size);
            if (query_ret)
            {
                img_ptr = (U8*)_vm_kernel_malloc(img_size);
                MPR_TRACE4(TRC_MPR_c8bf9a0e34714e4eae9014e84cbbba7f, 2, icon_res, ((img_ptr == NULL)? 0 : 1), img_size);
                if (img_ptr) memcpy(img_ptr, tmp_img_ptr, img_size);
            }
            else
            {
                /* Can't get image resource so use default App icon */
                img_ptr = srv_mre_push_receiver_query_default_app_icon(app_path, &img_size);
            }
            break;
        }
        default:
        {
            /* Case others so user path */
            query_ret = vm_res_get_image_and_size_from_file((short *)app_path, icon_res, NULL, (unsigned long *)(&img_size));
            MPR_TRACE4(TRC_MPR_c8bf9a0e34714e4eae9014e84cbbba7f, 3, icon_res, query_ret, img_size);
            if (query_ret)
            {
                /* Got size */
                img_ptr = (U8*)_vm_kernel_malloc(img_size);
                MPR_TRACE4(TRC_MPR_c8bf9a0e34714e4eae9014e84cbbba7f, 4, icon_res, ((img_ptr == NULL)? 0 : 1), img_size);
                query_ret = vm_res_get_image_and_size_from_file((short *)app_path, icon_res, img_ptr, (unsigned long *)(&img_size));
                MPR_TRACE4(TRC_MPR_c8bf9a0e34714e4eae9014e84cbbba7f, 5, icon_res, query_ret, img_size);
            }
            if (!query_ret)
            {
                /* Can't get image resource so use default App icon */
                img_ptr = srv_mre_push_receiver_query_default_app_icon(app_path, &img_size);
            }
            break;
        }
    }

    (*buffer) = img_ptr;
    (*size) = img_size;

	for (i = 0; i < 4; i++)
	{
		if (mpr_icon[i].app_id == app_id)
		{
			//is_find =1;
            icon_id = mpr_icon[i].icon_id;
            if(img_ptr!=NULL)
          {
            _vm_kernel_free((void *)(vm_statusbar_get_by_handle_icon_id(icon_id)));
          	vm_statusbar_set_handle(icon_id, (int)img_ptr);
        	wgui_status_icon_bar_change_icon_image_ex((S32)icon_id, img_ptr);
          }
            MPR_TRACE3(TRC_MPR_b8f2a27be97942db9d46a45e6d39f664, 1, app_id, icon_id);
			return icon_id;
		}
	}

	icon_id = srv_mre_push_receiver_get_statusbar(app_id);
    MPR_TRACE3(TRC_MPR_b8f2a27be97942db9d46a45e6d39f664, 2, app_id, icon_id);
	if (icon_id == STATUS_ICON_MRE_DEFAULT)
	{
		return 0;
	}

	vm_statusbar_set_handle(icon_id, (int)img_ptr);
	wgui_status_icon_bar_change_icon_image_ex((S32)icon_id, img_ptr);

    for (i = 0; i < 4; i++)
	{
		if (mpr_icon[i].icon_id == 0)
		{
			mpr_icon[i].app_id 	= app_id;
			mpr_icon[i].icon_id = icon_id;
			break;
		}
	}

    return icon_id;
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
#endif
}
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  info     : [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
void srv_mre_push_receiver_clear_popup(U32 app_id)
{
	int i = 0;

	for (i = 0; i < sizeof(mpr_popup)/sizeof(srv_mre_mpr_pending_popup); i++)
	{
		if (mpr_popup[i].popup_id != GRP_ID_INVALID && mpr_popup[i].app_id == app_id)
		{
			mpr_popup[i].popup_id = GRP_ID_INVALID;
			break;
		}
	}
}

#define SRV_MRE_PRINTF1(b, l, s, a1) srv_mre_printf(b, l, s, a1)
#define SRV_MRE_PRINTF2(b, l, s, a1, a2) srv_mre_printf(b, l, s, a1, a2)
#define SRV_MRE_PRINTF3(b, l, s, a1, a2, a3) srv_mre_printf(b, l, s, a1, a2, a3)


static void srv_mre_printf (char *buffer, S32 buffer_size, char *format,...)
{
    va_list args;
    va_start (args, format);    
    vsnprintf(buffer, buffer_size - 1, format, args);
    va_end(args);
}

MMI_BOOL srv_mre_convert_string(WCHAR* app_path, srv_pns_msg_mps_struct *mps, char* buffer, S32 buffer_size, MMI_BOOL convert_main, MMI_BOOL in_rom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S8 i = 0;
    MMI_BOOL result = MMI_FALSE;
    S32 len = 0, buffer_len = 0, res_len = 0, query_res = 0;
    char *pBuffer = NULL, *res_str = NULL, *res_str_t = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        MPR_TRACE1(TRC_MPR_3054ed7eb4634c53b6222df11b6aba5d, buffer_size);
        if (mps == NULL || buffer == NULL || buffer_size < 2)
        {
            break;
        }

        buffer_len = (buffer_size - 2)/2;
        if (convert_main)
        {
            /* Get main text */
            if (mps->main[0] != 0 && mps->mainLen > 0)
            {
                /* This is a string */
                len = (mps->mainLen <= buffer_len)? mps->mainLen : buffer_len;
                MPR_TRACE2(TRC_MPR_b364871056d9495abe2ed54028ed01e5, len, mps->mainLen);
                mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)mps->main, (char*)buffer, (buffer_size - 2));
                result = MMI_TRUE;
            }
            else
            {
                /* Get string from resource id */
                if (in_rom)
                {
                    query_res = vm_res_get_string_and_size_from_rom((VMWSTR)app_path, mps->mainResId, (void **)(&res_str_t), (VMUINT32 *)(&res_len));
                    MPR_TRACE4(TRC_MPR_10626f7398f84e4f96fbc7a120ca6e33, 1, mps->mainResId, query_res, res_len);
                    
                }
                else
                {
                    query_res = vm_res_get_string_and_size_from_file((VMWSTR)app_path, mps->mainResId, NULL, (VMUINT32 *)(&res_len));
                    MPR_TRACE4(TRC_MPR_10626f7398f84e4f96fbc7a120ca6e33, 2, mps->mainResId, query_res, res_len);
                    if (query_res)
                    {
                        res_str_t = (char*)OslMalloc((res_len+1)*sizeof(WCHAR));
                        memset(res_str_t, 0, (res_len+1)*sizeof(WCHAR));
                        query_res = vm_res_get_string_and_size_from_file((VMWSTR)app_path, mps->mainResId, res_str_t, (VMUINT32 *)(&res_len));
                        MPR_TRACE4(TRC_MPR_10626f7398f84e4f96fbc7a120ca6e33, 3, mps->mainResId, query_res, res_len);
                    }
                }
                if (query_res)
                {
                    /* UCS2 to ASC */
                    res_str = (char*)OslMalloc((res_len+1)*3);
                    memset(res_str, 0, (res_len+1)*3);
                    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)res_str_t, (char*)res_str, (res_len)*3);
                }
                if (!in_rom && res_str_t)
                {
                    OslMfree(res_str_t);
                }
                MPR_TRACE1(TRC_MPR_bc4f5d389386455db682192f7af8e43a, mps->main_args_num);
                if (mps->main_args_num == 0)
                {
                    /* Get string from main_res then convert to ucs2 directly */
                    if (query_res)
                    {
                        len = (res_len <= buffer_len)? res_len : buffer_len;
                        mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)res_str, (char*)buffer, (buffer_size-2));
                        result = MMI_TRUE;
                    }
                }
                else
                {
                    /* Get string from main_res  */
                    if (query_res)
                    {
                        pBuffer = (char*)OslMalloc(SRV_PNS_MAX_MSGBODY_SIZE);
                        memset(pBuffer, 0, SRV_PNS_MAX_MSGBODY_SIZE);
                        switch (mps->main_args_num)
                        {
                            case 1:
                                SRV_MRE_PRINTF1(pBuffer, SRV_PNS_MAX_MSGBODY_SIZE, res_str, mps->main_args[0]);
                                break;
                            case 2:
                                SRV_MRE_PRINTF2(pBuffer, SRV_PNS_MAX_MSGBODY_SIZE, res_str, mps->main_args[0], mps->main_args[1]);
                                break;
                            case 3:
                                SRV_MRE_PRINTF3(pBuffer, SRV_PNS_MAX_MSGBODY_SIZE, res_str, mps->main_args[0], mps->main_args[1], mps->main_args[2]);
                                break;
                        }
                        len = (strlen(pBuffer) <= buffer_len)? strlen(pBuffer) : buffer_len;
                        mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)pBuffer, (char*)buffer, (buffer_size-2));
                        OslMfree(pBuffer);
                        result = MMI_TRUE;
                    }
                }

                if (res_str) OslMfree(res_str);
            }
        }
        else
        {
            /* Get hint text */
            if (mps->hint[0] != 0 && mps->hintLen > 0)
            {
                /* This is a string */
                len = (mps->hintLen <= buffer_len)? mps->hintLen : buffer_len;
                mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)mps->hint, (char*)buffer, len*2);
                result = MMI_TRUE;
            }
            else
            {
                /* Get string from resource id */
                if (in_rom)
                {
                    query_res = vm_res_get_string_and_size_from_rom((VMWSTR)app_path, mps->hintResId, (void **)(&res_str_t),(VMUINT32 *)(&res_len));
                    
                }
                else
                {
                    query_res = vm_res_get_string_and_size_from_file((VMWSTR)app_path, mps->hintResId, NULL, (VMUINT32 *)(&res_len));
                    if (query_res)
                    {
                        res_str_t = (char*)OslMalloc((res_len+1)*sizeof(WCHAR));
                        memset(res_str_t, 0, (res_len+1)*sizeof(WCHAR));
                        query_res = vm_res_get_string_and_size_from_file((VMWSTR)app_path, mps->hintResId, res_str_t, (VMUINT32 *)(&res_len));
                    }
                }
                if (query_res)
                {
                    /* UCS2 to ASC */
                    res_str = (char*)OslMalloc((res_len+1));
                    memset(res_str, 0, (res_len+1));
                    mmi_ucs2_n_to_asc(res_str, res_str_t, res_len*sizeof(WCHAR));
                }
                if (!in_rom && res_str_t)
                {
                    OslMfree(res_str_t);
                }
                if (mps->hint_args_num == 0)
                {
                    /* Get string from hint_res then convert to ucs2 directly */
                    if (query_res)
                    {
                        len = (res_len <= buffer_len)? res_len : buffer_len;
                        app_asc_str_n_to_ucs2_str((kal_int8*)buffer, (kal_int8*)res_str, len);
                        result = MMI_TRUE;
                    }
                }
                else
                {
                    /* Get string from hint_res  */
                    if (query_res)
                    {
                        pBuffer = (char*)OslMalloc(SRV_PNS_MAX_MSGBODY_SIZE);
                        memset(pBuffer, 0, SRV_PNS_MAX_MSGBODY_SIZE);
                        switch (mps->hint_args_num)
                        {
                            case 1:
                                SRV_MRE_PRINTF1(pBuffer, SRV_PNS_MAX_MSGBODY_SIZE, res_str, mps->hint_args[0]);
                                break;
                            case 2:
                                SRV_MRE_PRINTF2(pBuffer, SRV_PNS_MAX_MSGBODY_SIZE, res_str, mps->hint_args[0], mps->hint_args[1]);
                                break;
                            case 3:
                                SRV_MRE_PRINTF3(pBuffer, SRV_PNS_MAX_MSGBODY_SIZE, res_str, mps->hint_args[0], mps->hint_args[1], mps->hint_args[2]);
                                break;
                        }
                        len = (strlen(pBuffer) <= buffer_len)? strlen(pBuffer) : buffer_len;
                        app_asc_str_n_to_ucs2_str((kal_int8*)buffer, (kal_int8*)pBuffer, len);
                        OslMfree(pBuffer);
                        result = MMI_TRUE;
                    }
                }
                if (res_str) OslMfree(res_str);
            }
        }
    } while(0);

    MPR_TRACE1(TRC_MPR_bd885f84c1824414a3ec9fe9999e1cd8, result);
    return result;
}

void srv_mre_push_receiver_show_warning()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_alert_struct *alert = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alert = (mmi_frm_nmgr_alert_struct*)OslMalloc(sizeof(mmi_frm_nmgr_alert_struct));
    memset(alert, 0, sizeof(mmi_frm_nmgr_alert_struct));

    alert->app_id = 0;
    alert->scen_id = MMI_SCENARIO_ID_MRE_PUSH;
    alert->event_type = MMI_EVENT_MRE_PUSH;
    /*fill in the notification information, if your app?|s notification can be controlled by NSS, your UI mask must include icon, status bar and popup*/
    alert->ui_mask = MMI_FRM_NMGR_UI_POPUP_MASK;
    /*Once the NSS is not support , NMGR will take the behavior mask as its behavior guildline*/
    alert->behavior_mask = FORCE_POPUP;

    alert->popup_para.image_type = MMI_NMGR_IMG_RES_ID;
    alert->popup_para.image.id = IMG_GLOBAL_WARNING;
    alert->popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE;
    alert->popup_para.popup_string = (WCHAR*)GetString(STR_ID_LAUNCH_FAIL);
    alert->popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_OK);

    mmi_frm_nmgr_alert(alert);

    if (alert) OslMfree(alert);
}

static void srv_mre_push_launch_cb(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
    MPR_TRACE2(TRC_MPR_166be444de2146db8c5fa64f942a5de4, 1, evt);
    if (SRV_MRE_LAUNCH_APP_ASM_READY == evt)
    {
        srv_mre_launch_app_result_enum result;
        result = srv_mre_launch_app_ex(app_path,srv_mre_push_launch_cb);
        MPR_TRACE2(TRC_MPR_166be444de2146db8c5fa64f942a5de4, 2, result);
        if (SRV_MRE_LAUNCH_APP_SYS_ASYN_ASM != result && SRV_MRE_LAUNCH_APP_SUCCESS != result)
        {
        	/*
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_FAILURE,
            	                     (WCHAR*)GetString(STR_ID_LAUNCH_FAIL));
            */
            srv_mre_push_receiver_show_warning();
        }
    }
}

static mmi_ret srv_mre_push_nmgr_proc(mmi_event_struct *evt)
{
    if(evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH ||
       evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {
       //APP LAUNCH
       U32 app_id = 0;
	   U32  custom_key_flag = 0;
       srv_mre_nmgr_data_struct *data = (srv_mre_nmgr_data_struct*)evt->user_data;
       srv_mre_appmgr_push_installed_info_struct* fileStoreInfo = NULL;
      if(mre_push_usb_ms_mode||mre_push_dev_plug_out)
      {
		  srv_mre_push_receiver_show_warning();
      }
       if (data)
       {
           app_id = data->app_id;
           if (data->img_buffer != NULL)
           {
               _vm_kernel_free(data->img_buffer);
               MPR_TRACE1(TRC_MPR_5c2fb2d2bc9b4504ad2d406fd965d184, 1);
           }
       }
       
       fileStoreInfo = (srv_mre_appmgr_push_installed_info_struct*)OslMalloc(sizeof(srv_mre_appmgr_push_installed_info_struct));
       memset(fileStoreInfo, 0, sizeof(srv_mre_appmgr_push_installed_info_struct));
       srv_mre_push_receiver_file_read(app_id, fileStoreInfo,MMI_TRUE);
       /* launch MER App*/
	    if(push_cache.app_id==app_id &&push_cache.app_payload.payload_count>0)
	   {
			U32 i=push_cache.app_payload.payload_count-1;
       		vm_pmng_set_push_app_flag(push_cache.app_payload.multiple_payload[i].query_index); 
			custom_key_flag = srv_pns_has_custom_payload((char *)(push_cache.app_payload.multiple_payload[i].payload)); // call aidan's function to judge
      }
       if(evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH)
       { //message without custom-key
       	    if(custom_key_flag==0)
			{
				((fileStoreInfo->click_rate).textpreview_launch_count) ++;
			}
			else//with custom-key
			{
				((fileStoreInfo->click_rate).textpreview_launch_has_custom_key_count) ++;
			}
       	}
       else
       {   //message without custom-key 
		   if(custom_key_flag==0)
			{
				((fileStoreInfo->click_rate).popup_launch_count) ++;
		   }
			else//with custom-key
			{
				((fileStoreInfo->click_rate).popup_launch_has_custom_key_count) ++;
		   }
       }
	   srv_mre_push_receiver_file_write(app_id, fileStoreInfo,MMI_FALSE);
       srv_mre_launch_app_ex((WCHAR*)(fileStoreInfo->app_path), srv_mre_push_launch_cb);
       OslMfree(fileStoreInfo);
       MPR_TRACE1(TRC_MPR_5c2fb2d2bc9b4504ad2d406fd965d184, 2);
    }   
    else if(evt->evt_id == EVT_ID_NMGR_ALERT_END)
    {         //Alert is completed
              // Once the text preview completed and user did not tap it during the text preview notification          
              // NMGR will send this event to this callback
              // Once user tap the cancel button or home, back key during the  popup notification          
              // NMGR will send this event to this callback
              // App can free resource here (Ex. for MRE to free image buffer or sound buffer), but you should not call cancel alert here
       srv_mre_nmgr_data_struct *data = (srv_mre_nmgr_data_struct*)evt->user_data;
       if (data && data->img_buffer != NULL)
       {
           _vm_kernel_free(data->img_buffer);
           MPR_TRACE1(TRC_MPR_e046f5bdb098496cb93d7c00157246fd, 1);
       }
       MPR_TRACE1(TRC_MPR_e046f5bdb098496cb93d7c00157246fd, 2);
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  info     : [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static void srv_mre_setup_alert_icon_with_app_icon(mmi_frm_nmgr_alert_struct* alert, WCHAR* app_path, U8* buffer, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ab2_support = 0;
    S32 tag_size = sizeof(int);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_get_vm_tag((short *)app_path, VM_CE_INFO_ADV_ICON, &ab2_support, &tag_size) == GET_TAG_TRUE)
    {
        MPR_TRACE2(TRC_MPR_97b42ac8440d4b7aa30af23d0f2b2eb6, 3, ab2_support);
        /* This is new version,  */
        alert->status_bar_para.image_type = MMI_NMGR_IMG_DATA_BUFF;
        alert->status_bar_para.image.data = buffer;

        alert->popup_para.image_type = MMI_NMGR_IMG_DATA_BUFF;
        alert->popup_para.image.data = buffer;
    }
    else
    {
        MPR_TRACE2(TRC_MPR_97b42ac8440d4b7aa30af23d0f2b2eb6, 4, ab2_support);
    }
}

static MMI_BOOL srv_mre_is_app_in_rom(WCHAR* app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_rom = MMI_FALSE;
    S32 len = 0;
    char *app_name_c;
    srv_mre_appmgr_app_type_enum app_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((const CHAR*)app_name);
    app_name_c = (char*)OslMalloc((len+1));
    memset(app_name_c, 0, (len+1));
    mmi_ucs2_n_to_asc((CHAR*)app_name_c, (CHAR*)app_name, len*sizeof(WCHAR));
    app_type = srv_mre_appmgr_get_app_type(app_name_c);
    OslMfree(app_name_c);
    switch (app_type)
    {
        case SRV_MRE_APPMGR_APP_TYPE_ROM:
        {
            is_rom = MMI_TRUE;
            break;
        }
        default:
        {
            break;
        }
    }

    MPR_TRACE1(TRC_MPR_6f4971c0253d47af960940bcb1739627, is_rom);
    return is_rom;
}

void srv_mre_push_receiver_show_popup_wrapper(U32 ori_app_id, U32 app_id, WCHAR *app_path, WCHAR* app_name,char *msg_body,MMI_BOOL prefer_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error_state = 0, *imgBuffer = NULL, *sndBuffer = NULL;
    MMI_BOOL convert_result = MMI_FALSE, in_rom = MMI_FALSE;
   // int ab2_support = 0;len = 0, 
    S32 status_icon_id, img_size = 0, query_res = 0,  action_size = 0;
    VMUINT32 snd_size = 0;
    //srv_pns_result result = SRV_PNS_NO_ERROR;
   // char *icon_path = NULL, *snd_path = NULL, *strBuffer = NULL, *res_name = NULL;
    char *strBuffer = NULL;
	WCHAR *icon_path=NULL,*snd_path=NULL,*res_name=NULL;
    mmi_frm_nmgr_alert_struct *alert = NULL;
    mmi_mpr_popup_message_struct *mpsPtr;
	//srv_mre_appmgr_push_payload_info_struct *payload;
    srv_mre_nmgr_data_struct user_data;
    char action[SRV_PNS_ACTION_TEXT_MAX_LEN*sizeof(WCHAR)], *action_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alert = (mmi_frm_nmgr_alert_struct*)OslMalloc(sizeof(mmi_frm_nmgr_alert_struct));
    mpsPtr = (mmi_mpr_popup_message_struct*)OslMalloc(sizeof(mmi_mpr_popup_message_struct));
    //payload = (srv_mre_appmgr_push_payload_info_struct*)OslMalloc(sizeof(srv_mre_appmgr_push_payload_info_struct));
    strBuffer = (char*)OslMalloc(SRV_PNS_MAX_MSGBODY_SIZE*sizeof(WCHAR));
    memset(alert, 0, sizeof(mmi_frm_nmgr_alert_struct));
    memset(mpsPtr, 0, sizeof(mmi_mpr_popup_message_struct));
	//memset(payload,0, sizeof(srv_mre_appmgr_push_payload_info_struct));
    memset(strBuffer,0, SRV_PNS_MAX_MSGBODY_SIZE*sizeof(WCHAR));
    memset(&user_data, 0, sizeof(srv_mre_nmgr_data_struct));

    do {
        // load last message from file
    	//if (srv_mre_load_last_message(payload, app_id) == MMI_FALSE) 
      //  {
         //   error_state = 1;
         //   break;
       // }

        // parsing push message
	    if (srv_pns_get_mps_info(msg_body, &mpsPtr->pns_msg_mps) != SRV_PNS_NO_ERROR)
        {
            error_state = 2;
            break;
        }

        status_icon_id = srv_mre_push_receiver_show_status_icon(app_id, app_path, app_name, mpsPtr->pns_msg_mps.icon, &imgBuffer, &img_size);
        if (status_icon_id == 0)
        {
            user_data.img_buffer = imgBuffer;
            MPR_TRACE0(TRC_MPR_17f466700c3648e6bd69af154332a390);
        }
        user_data.app_id = ori_app_id;
        /* Fill alert structure */
        alert->app_id = app_id;
        alert->scen_id = MMI_SCENARIO_ID_MRE_PUSH;
        alert->event_type = MMI_EVENT_MRE_PUSH;
        /*fill in the notification information, if your app?|s notification can be controlled by NSS, your UI mask must include icon, status bar and popup*/
        alert->ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
        /*Once the NSS is not support , NMGR will take the behavior mask as its behavior guildline*/
        alert->behavior_mask = (prefer_popup)? PREFER_POPUP : PREFER_STATUS_BAR; // or PREFER_STATUS_BAR. PREFER_ICON_ONLY
        
        /*fill in the status bar information*/
        alert->status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
        /*the image icon is used for text preview, can be different from popup*/
        /*Please check the ID with Shuaihui Ren to make sure if the icon can fit your requirement*/
        in_rom = srv_mre_is_app_in_rom(app_name);
        MPR_TRACE1(TRC_MPR_6919a80c24134158953b65801822b68d, mpsPtr->pns_msg_mps.icon);
        if (mpsPtr->pns_msg_mps.icon != 0)
        {
            /* get icon buffer from res and if buffer is null, to clear MMI_FRM_NMGR_UI_STATUS_ICON_MASK */
            if (imgBuffer == NULL)
            {
                alert->ui_mask &= ~(MMI_FRM_NMGR_UI_STATUS_ICON_MASK);
            }
            else
            {
                if (in_rom)
                {
                    /* Case pre-buildin MRE App so use raw data */
                    srv_mre_setup_alert_icon_with_app_icon(alert, app_path, imgBuffer, img_size);
                }
                else
                {
                    /* Case others so user path */
                    res_name = (WCHAR*)OslMalloc(SRV_FMGR_PATH_BUFFER_SIZE);
                    //memset(res_name, 0, SRV_FMGR_PATH_BUFFER_SIZE);
                    query_res = vm_res_generate_image_filename((VMWSTR)app_path, mpsPtr->pns_msg_mps.icon,(VMWSTR)res_name);
                    MPR_TRACE1(TRC_MPR_9be12bcb56714334958d3f868d7f3ddb, query_res);
                    if (query_res)
                    {
                        icon_path = (WCHAR *)OslMalloc(SRV_FMGR_PATH_BUFFER_SIZE);
                        //memset(icon_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);
                        kal_wsprintf((WCHAR*)icon_path, "%c%w",SRV_MRE_APPMGR_PRELOAD_DRV,SRV_MRE_APPMGR_IMG_FOLDER);
                        //app_ucs2_strcat((kal_int8*)icon_path, (const kal_int8*)SRV_MRE_APPMGR_IMG_FOLDER);
                        if (mmi_wcslen(icon_path)+mmi_wcslen(res_name) <= SRV_FMGR_PATH_MAX_LEN)
                        {
                            mmi_wcscat(icon_path, res_name);
                            if (srv_fmgr_fs_path_exist(icon_path) == 0)
                            {
                                alert->status_bar_para.image_type = MMI_NMGR_IMG_FILE_PATH;
                                alert->status_bar_para.image.file_path = icon_path;

                                alert->popup_para.image_type = MMI_NMGR_IMG_FILE_PATH;
                                alert->popup_para.image.file_path = icon_path;
                            }
                            else
                            {
                                /* Can't get image resource so use default App icon */
                                srv_mre_setup_alert_icon_with_app_icon(alert, app_path, imgBuffer, img_size);
                            }
                        }
                    }
                    else
                    {
                        /* Can't get image resource so use default App icon */
                        srv_mre_setup_alert_icon_with_app_icon(alert, app_path, imgBuffer, img_size);
                    }
                    OslMfree(res_name);
                }
            }
        }
        else
        {
            srv_mre_setup_alert_icon_with_app_icon(alert, app_path, imgBuffer, img_size);
        }

        MPR_TRACE1(TRC_MPR_72e19ed14b8e4b969826c1655df64cd3, mpsPtr->pns_msg_mps.sound);
        if (mpsPtr->pns_msg_mps.sound != 0)
        {
            if (in_rom)
            {
                /* Case pre-buildin MRE App so use raw data */
                /* Todo: Get sound buffer via resource id */
                query_res = vm_res_get_audio_and_size_from_rom((VMWSTR)app_path, mpsPtr->pns_msg_mps.sound, (void **)&sndBuffer, (VMUINT32 *)&snd_size);
                MPR_TRACE3(TRC_MPR_6b70f5569b7d4b9a99a4a4ae55006aeb, query_res, ((sndBuffer == NULL)? 0 : 1), snd_size);
                if (query_res)
                {
                    alert->snd_para.sound_type = MMI_NMGR_SND_RAW_DATA_BUFF;
                    alert->snd_para.sound.raw_data.buff = sndBuffer;
                    alert->snd_para.sound.raw_data.size = snd_size;
                    alert->snd_para.sound.raw_data.format = MDI_FORMAT_WAV;
                }
            }
            else
            {
                /* Case others so user path */
                res_name = (WCHAR *)OslMalloc(SRV_FMGR_PATH_BUFFER_SIZE);
                //memset(res_name, 0, SRV_FMGR_PATH_BUFFER_SIZE);
                query_res = vm_res_generate_audio_filename((VMWSTR)app_path, mpsPtr->pns_msg_mps.sound, (VMWSTR)res_name);
                MPR_TRACE1(TRC_MPR_e75448f38d4a40eb8d8d09b827d179fe, query_res);
                if (query_res)
                {
                    snd_path = (WCHAR *)OslMalloc(SRV_FMGR_PATH_BUFFER_SIZE);
                    //memset(snd_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);
                    kal_wsprintf(snd_path, "%c%w",SRV_MRE_APPMGR_PRELOAD_DRV,SRV_MRE_APPMGR_IMG_FOLDER);
                    //app_ucs2_strcat((kal_int8*)snd_path, (const kal_int8*)SRV_MRE_APPMGR_IMG_FOLDER);
                    if (mmi_wcslen(snd_path)+mmi_wcslen(res_name) <= SRV_FMGR_PATH_MAX_LEN)
                    {
                        mmi_wcscat(snd_path,res_name);
                        alert->snd_para.sound_type = MMI_NMGR_SND_FILE_PATH;
                        alert->snd_para.sound.file_path = snd_path;
                    }
                }
                OslMfree(res_name);
            }
        }
        convert_result = srv_mre_convert_string(app_path, &mpsPtr->pns_msg_mps, strBuffer, SRV_PNS_MAX_MSGBODY_SIZE*sizeof(WCHAR), MMI_TRUE, in_rom);
        if (!convert_result)
        {
            app_ucs2_strcpy((kal_int8*)strBuffer, (const kal_int8*)L"");
        }
        alert->status_bar_para.display_string = (WCHAR*)strBuffer;
        /*fill in the popup information*/    
        alert->popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
        /*the image icon is used for popup, can be different from text preview*/
        alert->popup_para.popup_string = (WCHAR*)strBuffer;
        memset(&action, 0, SRV_PNS_ACTION_TEXT_MAX_LEN*sizeof(WCHAR));
        MPR_TRACE2(TRC_MPR_7bfa4960bb414d15b2260b982c99e65a, mpsPtr->pns_msg_mps.actionLen, mpsPtr->pns_msg_mps.actionResId);
        if (mpsPtr->pns_msg_mps.actionLen > 0)
        {
            /* Action is string */
            mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)mpsPtr->pns_msg_mps.action, (char*)action, (SRV_PNS_ACTION_TEXT_MAX_LEN-1)*sizeof(WCHAR));
            alert->popup_para.popup_button_string = (WCHAR*)action;
        }
        else if (mpsPtr->pns_msg_mps.actionResId > 0)
        {
            /* It's res */
            if (in_rom)
            {
                query_res = vm_res_get_string_and_size_from_rom((VMWSTR)app_path, mpsPtr->pns_msg_mps.actionResId, (void **)(&action_p), (VMUINT32 *)(&action_size));
                MPR_TRACE3(TRC_MPR_d845643fcb394da9ad3e05a93f57b9b4, 1, query_res, action_size);
                if (query_res)
                {
                    alert->popup_para.popup_button_string = (WCHAR*)action_p;
                }
                else
                {
                    alert->popup_para.popup_button_string = (WCHAR*)get_string(STR_GLOBAL_VIEW);
                }
            }
            else
            {
                query_res = vm_res_get_string_and_size_from_file((VMWSTR)app_path, mpsPtr->pns_msg_mps.actionResId, NULL, (VMUINT32 *)&action_size);
                MPR_TRACE3(TRC_MPR_d845643fcb394da9ad3e05a93f57b9b4, 2, query_res, action_size);
                if (query_res)
                {
                    action_p = (char*)OslMalloc((action_size+1)*sizeof(WCHAR));
                    memset(action_p, 0, (action_size+1)*sizeof(WCHAR));
                    query_res = vm_res_get_string_and_size_from_file((VMWSTR)app_path, mpsPtr->pns_msg_mps.actionResId, action_p, (VMUINT32 *)&action_size);
                    MPR_TRACE3(TRC_MPR_d845643fcb394da9ad3e05a93f57b9b4, 3, query_res, action_size);
                    if (query_res)
                    {
                        alert->popup_para.popup_button_string = (WCHAR*)action_p;
                    }
                }
                else
                {
                    alert->popup_para.popup_button_string = (WCHAR*)get_string(STR_GLOBAL_VIEW);
                }
            }
            
        }
        else
        {
            alert->popup_para.popup_button_string = (WCHAR*)get_string(STR_GLOBAL_VIEW);
        }
        /*fill in the status bar icon information*/
        if (status_icon_id != 0)
        {
            alert->status_bar_icon_para.icon_id = status_icon_id;
        }
        else
        {
            alert->ui_mask &= ~(MMI_FRM_NMGR_UI_STATUS_ICON_MASK);
            alert->status_bar_icon_para.icon_id = STATUS_ICON_INVALID_ID;
        }
        /*fill in the app launch callback*/
        alert->app_proc_para.scrn_group_proc= &srv_mre_push_nmgr_proc;
        alert->app_proc_para.user_data = (void*)&user_data;  
        alert->app_proc_para.data_size = sizeof(srv_mre_nmgr_data_struct);
        mmi_frm_nmgr_alert(alert);
    } while (0);

    if (alert) OslMfree(alert);
    if (mpsPtr) OslMfree(mpsPtr);
   // if (payload) OslMfree(payload);
    if (strBuffer) OslMfree(strBuffer);
    if (icon_path) OslMfree(icon_path);
    if (snd_path) OslMfree(snd_path);
    if (!in_rom && action_p) OslMfree(action_p);
    MPR_TRACE1(TRC_MPR_490e6f4006e149aaa97837a8a81521a8, error_state);
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
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  info     : [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
void srv_mre_push_receiver_show_status_icon_only(U32 app_id, WCHAR* app_path, WCHAR* app_name, U32 icon_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *imgBuffer;
    S32 status_icon_id, img_size = 0;
    mmi_frm_nmgr_alert_struct alert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status_icon_id = srv_mre_push_receiver_show_status_icon(app_id, app_path, app_name, icon_res, &imgBuffer, &img_size);
    MPR_TRACE4(TRC_MPR_e6833433a5084374a945b609d204fe5b, app_id, icon_res, status_icon_id, img_size);
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   
    alert_info.app_id = app_id;
    alert_info.behavior_mask = FORCE_ICON_ONLY;
    //alert_info.status_bar_icon_para.icon_id = STATUS_ICON_UNREAD_VOICE;
    if (status_icon_id != 0)
    {
        alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
        alert_info.status_bar_icon_para.icon_id = status_icon_id;
    }
    else
    {
        alert_info.status_bar_icon_para.icon_id = STATUS_ICON_INVALID_ID;
    }
    mmi_frm_nmgr_alert(&alert_info);
}
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  info     : [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
void srv_mre_push_receiver_hide_status_icon(U32 app_id)
{
	int i = 0;
	int img_ptr = 0;
    NMGR_HANDLE hdlr;

	for (i = 0; i < 4; i++)
	{
		if (mpr_icon[i].app_id == app_id)
		{
			ASSERT(mpr_icon[i].icon_id != 0);

			//wgui_status_icon_bar_hide_icon(mpr_icon[i].icon_id);
			hdlr = mmi_frm_nmgr_compose_alert_handle(app_id, MMI_EVENT_MRE_PUSH, mpr_icon[i].icon_id);
            mmi_frm_nmgr_alert_cancel(hdlr);
			
			img_ptr = vm_statusbar_get_by_handle_icon_id(mpr_icon[i].icon_id);
			_vm_kernel_free((void*)img_ptr);
			
			vm_statusbar_unset_handle(mpr_icon[i].icon_id,0);
			mpr_icon[i].app_id = 0;
			mpr_icon[i].icon_id = 0;
			break;
		}
	}
}
#endif
