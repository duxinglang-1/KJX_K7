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
 *  MMIThemesGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMITHEME_GPROT_H
#define MMITHEME_GPROT_H

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_theme_from_fmgr
 * DESCRIPTION
 *  This function activates theme from file manager
 * PARAMETERS
 *  theme_type : [IN]Downloaded phone or card    
 *  drv_letter : [IN]Drive letter
 *  theme_name_p : [IN]Name of the theme    
 *  is_short : [IN]The name is long or short    
 * RETURNS
 *  theme error code
 * RETURN VALUES
 *  theme error code activate result
 *****************************************************************************/
extern S32 mmi_tm_activate_theme_from_fmgr(tm_theme_type_enum theme_type, 
                                          S8 drv_letter, 
                                          U8 *theme_name_p,
                                          MMI_BOOL is_short);

/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_if_file_alrdy_exist_in_fm
 * DESCRIPTION
 *  Check if file Already exists in File manager.
 * PARAMETERS
 *  file_path : [IN]Path
 *  file_name : [IN]File name
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/                                         
extern void mmi_ta_check_if_file_alrdy_exist_in_fm(CHAR* file_path, CHAR* file_name);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_tm_init_theme_usb_mode_plugin_callback
 * DESCRIPTION
 *  Init usb mode plugin callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_tm_init_theme_usb_mode_plugin_callback(void);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_tm_init_theme_usb_mode_plugout_callback
 * DESCRIPTION
 *  Init usb mode plugout callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_tm_init_theme_usb_mode_plugout_callback(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_theme
 * DESCRIPTION
 *  This function activates theme at the time of theme selection
 * PARAMETERS
 *  theme_id : [IN]theme id to activate
 * RETURNS
 *  theme error code
 * RETURN VALUES
 *  theme error code of activation result 
 *****************************************************************************/
extern S32  mmi_tm_activate_theme(U32 theme_id);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  mmi_ta_da_oma_install_check_hdlr
 * DESCRIPTION
 *  Its a OMA download callback function and called by download agent 
 *    for validating the theme descriptor file
 * PARAMETERS
 *  param : [IN]dd_file
 * RETURNS
 *  check result
 * RETURN VALUES
 *  TRUE : descriptor file contains valid info
 *  FALSE : descriptor file contains in-valid info
 *****************************************************************************/
MMI_BOOL mmi_ta_da_oma_install_check_hdlr(void *param);



/*****************************************************************************
 * FUNCTION
 *  mmi_tm_handle_theme_activation_error_status
 * DESCRIPTION
 *  This function handles error status at the time of theme activation
 * PARAMETERS
 *  status : [IN]status error code type
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_tm_handle_theme_activation_error_status(S32 status);


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_theme_activate_hdlr
 * DESCRIPTION
 *  Activate currently highlighted theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_fmgr_theme_activate_hdlr(void);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */


#ifdef __MMI_THEMES_V2_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_theme_v2_notify_hdlr
 * DESCRIPTION
 *  File manage theme notify handler
 * PARAMETERS
 *  notify_flag : [IN]filemgr notify
 *	para : [IN]path struct
 * RETURNS
 *  operation result
 * RETURN VALUES
 *  MMI_TRUE : Operation succsss
 *  MMI_FALSE : Operation failed
 *****************************************************************************/
extern BOOL mmi_fmgr_theme_v2_notify_hdlr(U32 notify_flag, void* para);
#endif

#endif /* MMITHEME_GPROT_H */ 
