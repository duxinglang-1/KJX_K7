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
 *  vapp_sns_utility.cpp
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

#ifndef __VAPP_SNS_UTILITY_H__
#define __VAPP_SNS_UTILITY_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vfx_mc_include.h"
#include "vcp_include.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvGprot.h"
#include "SnsSrvDefs.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define SNS_IMG(_type)  vapp_sns_get_external_img_id((SnsExternalImgEnum)(_type))
#define SNS_STR(_type)  vapp_sns_get_external_str_id((SnsExternalStrEnum)(_type))
#define SNS_CLR(_type)  vapp_sns_get_external_clr_id((SnsExternalClrEnum)(_type))
#define SNS_EVT(_type)  vapp_sns_get_external_event_id((SnsExternalEventEnum)(_type))


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
enum SnsExternalEventEnum
{
    SNS_EXT_EVENT_SRV_APPMGR_UPDATE_BADGE,
    SNS_EXT_EVENT_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE,
    SNS_EXT_EVENT_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME,
    SNS_EXT_EVENT_ASM_CANCELED,
    SNS_EXT_EVENT_ASM_PREPARED,
    SNS_EXT_EVENT_ASM_FREE_REQ,
    SNS_EXT_EVENT_ASM_FORCE_FREE,
    SNS_EXT_EVENT_DELETE_DANGLE_GROUP_REQ,
    SNS_EXT_EVENT_END
};

enum SnsExternalImgEnum
{   
    SNS_EXT_VCP_IMG_BUTTON_DELETE,
    SNS_EXT_VCP_IMG_LIST_MENU_TOP_SHADOW_U,
    SNS_EXT_VCP_IMG_FORM_SEP_LINE,
    SNS_EXT_VCP_IMG_FORM_HIGHLIGHTED_CELL_BG,
    SNS_EXT_VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE,
    SNS_EXT_VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE,
    SNS_EXT_IMG_GLOBAL_QUESTION,
    SNS_EXT_IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_OK,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_PREVIEW,
    SNS_EXT_VCP_IMG_SEGMENT_BUTTON_LEFT_N,
    SNS_EXT_VCP_IMG_SEGMENT_BUTTON_LEFT_P,
    SNS_EXT_VCP_IMG_SEGMENT_BUTTON_LEFT_H,
    SNS_EXT_VCP_IMG_SEGMENT_BUTTON_LEFT_D,
    SNS_EXT_VCP_IMG_SEGMENT_BUTTON_RIGHT_N,
    SNS_EXT_VCP_IMG_SEGMENT_BUTTON_RIGHT_P,
    SNS_EXT_VCP_IMG_SEGMENT_BUTTON_RIGHT_H,
    SNS_EXT_VCP_IMG_SEGMENT_BUTTON_RIGHT_D,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD,
    SNS_EXT_VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND,
    SNS_EXT_IMG_ID_VAPP_GALLERY_SHT_LOADING_ICON,
    //Add external image id before end enum
    SNS_EXT_IMG_END
};

enum SnsExternalStrEnum
{    
    SNS_EXT_STR_GLOBAL_REPLY,
    SNS_EXT_STR_GLOBAL_SEND,
    SNS_EXT_STR_GLOBAL_ERROR,
    SNS_EXT_STR_GLOBAL_MANUAL,
    SNS_EXT_STR_GLOBAL_SAVE,
    SNS_EXT_STR_GLOBAL_SETTINGS,
    SNS_EXT_STR_GLOBAL_UNSELECT_ALL,
    SNS_EXT_STR_GLOBAL_SELECT_ALL,
    //SNS_EXT_VCP_STR_TOOL_BAR_OK,
   // SNS_EXT_VCP_STR_TOOL_BAR_CANCEL,
    SNS_EXT_STR_GLOBAL_CANCEL,
    SNS_EXT_STR_GLOBAL_OPEN,
    //SNS_EXT_VCP_STR_TOOL_BAR_DELETE,
    //SNS_EXT_VCP_STR_TOOL_BAR_ADD,
    SNS_EXT_STR_GLOBAL_DELETE,
    SNS_EXT_STR_GLOBAL_OK,
    SNS_EXT_STR_GLOBAL_SENT,
    SNS_EXT_STR_GLOBAL_ADD,
    SNS_EXT_STR_GLOBAL_UPLOAD,
    SNS_EXT_STR_GLOBAL_REPLACE,
    SNS_EXT_STR_GLOBAL_NOT_SUPPORTED,
    SNS_EXT_STR_GLOBAL_RECIPIENTS,
    SNS_EXT_STR_GLOBAL_SAVED,
    SNS_EXT_STR_GLOBAL_FAILED_TO_SAVE,
    SNS_EXT_STR_GLOBAL_SAVING,
    SNS_EXT_STR_ID_VCUI_SSO_LOGOUT,
    //Add external string id before end enum
    SNS_EXT_STR_END
};

enum SnsExternalClrEnum
{
    SNS_EXT_CLR_COSMOS_TEXT_MAIN,
    SNS_EXT_CLR_COSMOS_TEXT_SUB,
    SNS_EXT_CLR_COSMOS_TEXT_LINK,
    SNS_EXT_VCP_COL_LIST_MENU_LOWLIGHT_TEXT,
    SNS_EXT_VCP_COL_LIST_MENU_DISABLE_FG,
    SNS_EXT_CLOR_END
};

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  vapp_sns_is_only_profile_page
 * DESCRIPTION
 * This function is used check whether only contain profile tab page or not
 * PARAMETERS
 *  providerId      : [IN] sns provider id
 * RETURNS
 *  VfxBool
 *****************************************************************************/
extern VfxBool vapp_sns_is_only_profile_page(VfxU32 providerId);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_show_balloon
 * DESCRIPTION
 * This function is used to get service error string by error code.
 * PARAMETERS
 *  errorCode       : [IN] the error code from sns service
 * RETURNS
 *  VfxResId
 *****************************************************************************/ 
extern VfxResId vapp_sns_get_error_string(VfxS32 errorCode);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_show_balloon
 * DESCRIPTION
 *  This function is show a balloon to notify user error occurred.
 * PARAMETERS
 *  errorCode       : [IN] the error code from sns service
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void vapp_sns_show_balloon(VfxS32 errorCode);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_is_browser_support
 * DESCRIPTION
 *  This function is used to check is browser support or not.
 * PARAMETERS
 *  NULL
 * RETURNS
 *  VfxBool
 *****************************************************************************/ 
extern VfxBool vapp_sns_is_browser_support();

/*****************************************************************************
 * FUNCTION
 *  vapp_sns_go_to_url
 * DESCRIPTION
 *  This function is start broswer.
 * PARAMETERS
 *  url
 * RETURNS
 *  url
 *****************************************************************************/ 
extern VfxS32 vapp_sns_go_to_url(kal_uint8 *url);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_get_external_event_id
 * DESCRIPTION
 *  This function is get external event id.
 * PARAMETERS
 *  event type
 * RETURNS
 *  resource id
 *****************************************************************************/ 
extern U32 vapp_sns_get_external_event_id(SnsExternalEventEnum type);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_get_external_img_id
 * DESCRIPTION
 *  This function is get external image id.
 * PARAMETERS
 *  event type
 * RETURNS
 *  resource id
 *****************************************************************************/ 
extern U32 vapp_sns_get_external_img_id(SnsExternalImgEnum type);


/*****************************************************************************
 * FUNCTION
 *  vapp_sns_get_external_str_id
 * DESCRIPTION
 *  This function is get external string id.
 * PARAMETERS
 *  event type
 * RETURNS
 *  resource id
 *****************************************************************************/ 
extern U32 vapp_sns_get_external_str_id(SnsExternalStrEnum type);

/*****************************************************************************
 * FUNCTION
 *  vapp_sns_get_external_clr_id
 * DESCRIPTION
 *  This function is get external color id.
 * PARAMETERS
 *  event type
 * RETURNS
 *  resource id
 *****************************************************************************/ 
extern U32 vapp_sns_get_external_clr_id(SnsExternalClrEnum type);


#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /*__VAPP_SNS_UTILITY_H__*/
