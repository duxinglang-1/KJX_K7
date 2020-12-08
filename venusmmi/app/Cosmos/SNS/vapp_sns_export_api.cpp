/*  Copyright Statement:
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_sns_export_api.cpp
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__ 
#include "vfx_datatype.h"
#include "vapp_sns_utility.h"

#ifdef __cplusplus
extern "C"
#endif
{
#include "Browser_api.h"
#include "NativeAppFactorySrvGprot.h"
#include "AppMgrSrvGprot.h"
#include "mmi_rp_srv_venuS_component_segment_button_def.h"
#include "mmi_rp_vapp_gallery_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_form_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "mmi_rp_vapp_sns_sso_common_def.h"
#include "GlobalResDef.h"
#ifdef __cplusplus
}
#endif

VfxBool vapp_sns_is_browser_support()
{
#ifdef BROWSER_SUPPORT    
    return VFX_TRUE;
#endif
    return VFX_FALSE;
}

VfxS32 vapp_sns_go_to_url(kal_uint8 *url)
{
#ifdef BROWSER_SUPPORT 
    return wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)url);
#endif

    return 0;
}

U32 vapp_sns_get_external_event_id(SnsExternalEventEnum type)
{
    switch (type)
    {
        case SNS_EXT_EVENT_SRV_APPMGR_UPDATE_BADGE:
            return EVT_ID_SRV_APPMGR_UPDATE_BADGE;

	    case SNS_EXT_EVENT_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE:
            return EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE;

	    case SNS_EXT_EVENT_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME:
		    return EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME;

	    case SNS_EXT_EVENT_ASM_CANCELED:
		    return EVT_ID_ASM_CANCELED;

	    case SNS_EXT_EVENT_ASM_PREPARED:
		    return EVT_ID_ASM_PREPARED;

	    case SNS_EXT_EVENT_ASM_FREE_REQ:
		    return EVT_ID_ASM_FREE_REQ;

	    case SNS_EXT_EVENT_ASM_FORCE_FREE:
		    return EVT_ID_ASM_FORCE_FREE;

	    case SNS_EXT_EVENT_DELETE_DANGLE_GROUP_REQ:
		    return EVT_ID_DELETE_DANGLE_GROUP_REQ;
    }

    return 0;
}

U32 vapp_sns_get_external_img_id(SnsExternalImgEnum type)
{
    switch (type)
    {   
        case SNS_EXT_VCP_IMG_BUTTON_DELETE:
            return VCP_IMG_BUTTON_DELETE;
                 
        case SNS_EXT_VCP_IMG_LIST_MENU_TOP_SHADOW_U:
            return VCP_IMG_LIST_MENU_TOP_SHADOW_U;
            
        case SNS_EXT_VCP_IMG_FORM_SEP_LINE:
            return VCP_IMG_FORM_SEP_LINE;
            
        case SNS_EXT_VCP_IMG_FORM_HIGHLIGHTED_CELL_BG:
            return VCP_IMG_FORM_HIGHLIGHTED_CELL_BG;
            
        case SNS_EXT_VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE:
            return VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE;
            
        case SNS_EXT_VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE:
            return VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE;

	    case SNS_EXT_IMG_GLOBAL_QUESTION:
		    return IMG_GLOBAL_QUESTION;
            
        case SNS_EXT_IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON:
            return IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON;

        case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING:
            return VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING;

        case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_PREVIEW:
            return VCP_IMG_TOOL_BAR_COMMON_ITEM_PREVIEW;
            
        case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL:
            return VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL;
            
        case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL:
            return VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL;

        case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_OK:
            return VCP_IMG_TOOL_BAR_COMMON_ITEM_OK;

        case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL:
            return VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL;

        case SNS_EXT_VCP_IMG_SEGMENT_BUTTON_LEFT_N:
            return VCP_IMG_SEGMENT_BUTTON_LEFT_N;
            
        case SNS_EXT_VCP_IMG_SEGMENT_BUTTON_LEFT_P:
            return VCP_IMG_SEGMENT_BUTTON_LEFT_P;

        case SNS_EXT_VCP_IMG_SEGMENT_BUTTON_LEFT_H:
            return VCP_IMG_SEGMENT_BUTTON_LEFT_H;

        case SNS_EXT_VCP_IMG_SEGMENT_BUTTON_LEFT_D:
            return VCP_IMG_SEGMENT_BUTTON_LEFT_D;

        case SNS_EXT_VCP_IMG_SEGMENT_BUTTON_RIGHT_N:
            return VCP_IMG_SEGMENT_BUTTON_RIGHT_N;

        case SNS_EXT_VCP_IMG_SEGMENT_BUTTON_RIGHT_P:
            return VCP_IMG_SEGMENT_BUTTON_RIGHT_P;

        case SNS_EXT_VCP_IMG_SEGMENT_BUTTON_RIGHT_H:
            return VCP_IMG_SEGMENT_BUTTON_RIGHT_H;

        case SNS_EXT_VCP_IMG_SEGMENT_BUTTON_RIGHT_D:
            return VCP_IMG_SEGMENT_BUTTON_RIGHT_D;

        case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD:
            return VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD;

        case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND:
            return VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND;

        case SNS_EXT_IMG_ID_VAPP_GALLERY_SHT_LOADING_ICON:
            return IMG_ID_VAPP_GALLERY_SHT_LOADING_ICON;

	    case SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE:
	        return VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE;
        //Add your external img id transfer rule here
        default:
            VFX_ASSERT(0);
    }

    return 0;
}

U32 vapp_sns_get_external_str_id(SnsExternalStrEnum type)
{
    switch (type)
    {          
        case SNS_EXT_STR_GLOBAL_REPLY:
            return STR_GLOBAL_REPLY;
            
        case SNS_EXT_STR_GLOBAL_SEND:
            return STR_GLOBAL_SEND;
            
        case SNS_EXT_STR_GLOBAL_ERROR:
            return STR_GLOBAL_ERROR;
        
        case SNS_EXT_STR_GLOBAL_MANUAL:
            return STR_GLOBAL_MANUAL;

         case SNS_EXT_STR_GLOBAL_SAVE:
	   return STR_GLOBAL_SAVE;

        case SNS_EXT_STR_GLOBAL_SETTINGS:
            return STR_GLOBAL_SETTINGS;
            
        case SNS_EXT_STR_GLOBAL_UNSELECT_ALL:
            return STR_GLOBAL_UNSELECT_ALL;
            
        case SNS_EXT_STR_GLOBAL_SELECT_ALL:
            return STR_GLOBAL_SELECT_ALL;
            
        //case SNS_EXT_VCP_STR_TOOL_BAR_OK:
          //  return VCP_STR_TOOL_BAR_OK;

        //case SNS_EXT_VCP_STR_TOOL_BAR_CANCEL:
           // return VCP_STR_TOOL_BAR_CANCEL;

        case SNS_EXT_STR_GLOBAL_CANCEL:
            return STR_GLOBAL_CANCEL;

        case SNS_EXT_STR_GLOBAL_OPEN:
            return STR_GLOBAL_OPEN;

       // case SNS_EXT_VCP_STR_TOOL_BAR_DELETE:
         //   return VCP_STR_TOOL_BAR_DELETE;

      // case SNS_EXT_VCP_STR_TOOL_BAR_ADD:
          //  return VCP_STR_TOOL_BAR_ADD;

        case SNS_EXT_STR_GLOBAL_DELETE:
            return STR_GLOBAL_DELETE;

        case SNS_EXT_STR_GLOBAL_OK:
            return STR_GLOBAL_OK;

        case SNS_EXT_STR_GLOBAL_SENT:
            return STR_GLOBAL_SENT;

        case SNS_EXT_STR_GLOBAL_ADD:
            return STR_GLOBAL_ADD;

        case SNS_EXT_STR_GLOBAL_UPLOAD:
            return STR_GLOBAL_UPLOAD;

        case SNS_EXT_STR_GLOBAL_REPLACE:
            return STR_GLOBAL_REPLACE;

        case SNS_EXT_STR_GLOBAL_NOT_SUPPORTED:
            return STR_GLOBAL_NOT_SUPPORTED;

        case SNS_EXT_STR_GLOBAL_RECIPIENTS:
            return STR_GLOBAL_RECIPIENTS;
			
	    case SNS_EXT_STR_GLOBAL_SAVED:
  	        return STR_GLOBAL_SAVED;
	   
	    case SNS_EXT_STR_GLOBAL_FAILED_TO_SAVE:
	        return STR_GLOBAL_FAILED_TO_SAVE;
	   
	    case SNS_EXT_STR_GLOBAL_SAVING:
	        return STR_GLOBAL_SAVING;

        case SNS_EXT_STR_ID_VCUI_SSO_LOGOUT:
            return STR_ID_VCUI_SSO_LOGOUT;
            
        //Add your external str id transfer rule here
        default:
            VFX_ASSERT(0);

    }

    return 0;
}

U32 vapp_sns_get_external_clr_id(SnsExternalClrEnum type)
{
    switch (type)
    {
        case SNS_EXT_CLR_COSMOS_TEXT_MAIN:
            return CLR_COSMOS_TEXT_MAIN;

        case SNS_EXT_CLR_COSMOS_TEXT_SUB:
            return CLR_COSMOS_TEXT_SUB;

        case SNS_EXT_CLR_COSMOS_TEXT_LINK:
            return CLR_COSMOS_TEXT_LINK;

        case SNS_EXT_VCP_COL_LIST_MENU_LOWLIGHT_TEXT:
            return VCP_COL_LIST_MENU_LOWLIGHT_TEXT;
            
        case SNS_EXT_VCP_COL_LIST_MENU_DISABLE_FG:
            return VCP_COL_LIST_MENU_DISABLE_FG;

        default:
            VFX_ASSERT(0);
    }

    return 0;
}


#endif /* __SOCIAL_NETWORK_SUPPORT__ */
