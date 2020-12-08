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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_nmgr_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *    This file is used to provide nmgr global popup service
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_global_popup.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef void (* PopupEnterCallBackPtr) (VfxS32 handle, void *userData); 

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_nmgr_global_popup_show_confirm_one_button_id
 * DESCRIPTION
 *  This function is used to show a confirm popup with one button.
 *  The string is from the resource id.
 *  The display behavior of the global popup will be controlled by NMGR
 * PARAMETERS
 *  scenID         :  [IN]  the scenario which the global popup will have
 *  type           :  [IN]  the popup type
 *  textResId      :  [IN]  the string resource id of the title
 *  btnText1ResId  :  [IN]  the string resource id of the button
 *  type1          :  [IN]  the type of the button
 *  callback       :  [IN]  the callback function of the pop up
 *  userData       :  [IN]  the user data of the popup
 * RETURNS
 *  The screen group id which the global popup belong to
 * EXAMPLE
 * <code>
 *  
 *  void *arg = mmi_malloc(10);
 *  vapp_nmgr_global_popup_show_confirm_one_button_id(
 *       MMI_SCENARIO_ID_DEFAULT,
 *       VCP_POPUP_TYPE_FAILURE, 
 *       STR_GLOBAL_ABORT,
 *       STR_GLOBAL_OK,
 *       VCP_POPUP_BUTTON_TYPE_NORMAL,
 *       callBackOneBtnId,
 *       arg);
 *
 *  void callBackOneBtnId(VfxId id, void *userData)
 *  {
 *      switch (id)
 *      {
 *           case VCP_CONFIRM_POPUP_BUTTON_USER_1:
 *           {
 *               //TO DO: handle button click here
 *               break;
 *           }
 *
 *           case VCP_POPUP_BUTTON_NO_PRESSED:
 *           {
 *               //TO DO: handle the case for back key, end key
 *               //and someone invoke vapp_nmgr_global_popup_cancel
 *               break;
 *           }
 *      }
 *      //free the resource if the user data is dynamically allocated.
 *      mmi_mfree(userData);          
 *  }
 * </code>
 *****************************************************************************/
VfxS32 vapp_nmgr_global_popup_show_confirm_one_button_id(
        mmi_scenario_id scenID,
        VcpPopupTypeEnum type, 
        VfxResId textResId, 
        VfxResId btnText1ResId, 
        VcpPopupButtonTypeEnum type1,
        PopupCallBackPtr callBack,
        void *userData);
        

/*****************************************************************************
 * FUNCTION
 *  vapp_nmgr_global_popup_show_confirm_two_button_id
 * DESCRIPTION
 *  This function is used to show a confirm popup with two button.
 *  The string is from the resource id.
 *  The display behavior of the global popup will be controlled by NMGR
 * PARAMETERS
 *  scenID         :  [IN]  the scenario which the global popup will have
 *  type           :  [IN]  the popup type
 *  textResId      :  [IN]  the string resource id of the title
 *  btnText1ResId  :  [IN]  the string resource id of the button 1
 *  btnText2ResId  :  [IN]  the string resource id of the button 2
 *  type1          :  [IN]  the type of the button 1
 *  type2          :  [IN]  the type of the button 2
 *  callBack       :  [IN]  the callback function of the popup
 *  userData       :  [IN]  the user data of the popup
 * RETURNS
 *  The screen group id which the global popup belong to
 * EXAMPLE
 * <code>
 *  
 *  void *arg = mmi_malloc(10);
 *  vapp_nmgr_global_popup_show_confirm_two_button_id(
 *       MMI_SCENARIO_ID_DEFAULT,
 *       VCP_POPUP_TYPE_FAILURE, 
 *       STR_GLOBAL_ABORT,
 *       STR_GLOBAL_OK,
 *       STR_GLOBAL_CANCEL,
 *       VCP_POPUP_BUTTON_TYPE_NORMAL,
 *       VCP_POPUP_BUTTON_TYPE_NORMAL,
 *       callBackTwoBtnId,
 *       arg);
 *
 *
 *  void callBackTwoBtnId(VfxId id, void *userData)
 *  {
 *      switch (id)
 *      {
 *           case VCP_CONFIRM_POPUP_BUTTON_USER_1:
 *           {
 *               //TO DO: handle button1 click here
 *               break;
 *           }
 *
 *           case VCP_CONFIRM_POPUP_BUTTON_USER_2:
 *           {
 *               //TO DO: handle button2 click here
 *               break;
 *           }
 *
 *           case VCP_POPUP_BUTTON_NO_PRESSED:
 *           {
 *               //TO DO: handle the case for back key, end key
 *               //and someone invoke vapp_nmgr_global_popup_cancel
 *               break;
 *           }
 *      }
 *      //free the resource if the user data is dynamically allocated.
 *      mmi_mfree(userData);     
 *  }
 * </code>
 *****************************************************************************/        
VfxS32 vapp_nmgr_global_popup_show_confirm_two_button_id(
        mmi_scenario_id scenID,
        VcpPopupTypeEnum type, 
        VfxResId textResId, 
        VfxResId btnText1ResId, 
        VfxResId btnText2ResId,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2,
        PopupCallBackPtr callBack,
        void *userData);

/*****************************************************************************
 * FUNCTION
 *  vapp_nmgr_global_popup_show_command_id
 * DESCRIPTION
 *  This function is used to show a command popup.
 *  The string is from the resource id.
 *  The display behavior of the global popup will be controlled by NMGR
 * PARAMETERS
 *  scenID         :  [IN]  the scenario which the global popup will have
 *  textResId      :  [IN]  the string resource id of the title
 *  callBack       :  [IN]  the callback function of the popup
 *  enterFunc      :  [IN]  enter function of the command popup
 *  userData       :  [IN]  the user data of the popup
 * RETURNS
 *  The screen group id which the global popup belong to
 * EXAMPLE
 * <code>
 *  
 *  void *arg = mmi_malloc(10);
 *  vapp_nmgr_global_popup_show_command_id(
 *       MMI_SCENARIO_ID_DEFAULT,
 *       STR_GLOBAL_ABORT,
 *       callBackCmdBtnId,
 *       enterFuncCmdId,
 *       arg);
 *
 *
 *  void enterFuncCmdId(VfxS32 handle, void *userData)
 *  {
 *      vcp_global_popup_show_command_add_id(handle, 'BUT1', STR_GLOBAL_1, VCP_POPUP_BUTTON_TYPE_NORMAL);
 *      vcp_global_popup_show_command_add_id(handle, 'BUT2', STR_GLOBAL_2, VCP_POPUP_BUTTON_TYPE_NORMAL);
 *      vcp_global_popup_show_command_add_id(handle, 'BUT3', STR_GLOBAL_3, VCP_POPUP_BUTTON_TYPE_NORMAL);
 *      vcp_global_popup_show_command_add_id(handle, 'BUT4', STR_GLOBAL_4, VCP_POPUP_BUTTON_TYPE_NORMAL);
 *  }
 *
 *  void callBackCmdBtnId(VfxId id, void *userData)
 *  {
 *      switch (id)
 *      {
 *          case 'BUT1':
 *          {
 *              //TO DO: handle button1 click here
 *
 *              break;
 *          }
 *
 *          case 'BUT2':
 *          {
 *              //TO DO: handle button2 click here
 *
 *              break;
 *          }
 *
 *          case 'BUT3':
 *          {
 *              //TO DO: handle button3 click here
 *
 *              break;
 *          }
 *
 *          case 'BUT4':
 *          {
 *              //TO DO: handle button4 click here
 *
 *              break;
 *          }
 *
 *          case VCP_POPUP_BUTTON_NO_PRESSED:
 *          {
 *              //TO DO: handle the case for back key, end key
 *              //and someone invoke vapp_nmgr_global_popup_cancel
 *
 *              break;
 *          }
 *      }
 *      //free the resource if the user data is dynamically allocated.
 *      mmi_mfree(userData);     
 *  }
 * </code>
 *****************************************************************************/         
VfxS32 vapp_nmgr_global_popup_show_command_id(
        mmi_scenario_id scenID,
        VfxResId textResId, 
        PopupCallBackPtr callBack,
        PopupEnterCallBackPtr enterFunc,
        void *userData);

/*****************************************************************************
 * FUNCTION
 *  vapp_nmgr_global_popup_show_confirm_one_button_str
 * DESCRIPTION
 *  This function is used to show a confirm popup with one button.
 *  The string is from the reference of VfxWString.
 *  The display behavior of the global popup will be controlled by NMGR
 * PARAMETERS
 *  scenID         :  [IN]  the scenario which the global popup will have
 *  type           :  [IN]  the popup type
 *  text           :  [IN]  the reference VfxWString of the title
 *  btnText1       :  [IN]  the reference VfxWString of the button
 *  type1          :  [IN]  the type of the button
 *  callback       :  [IN]  the callback function of the pop up
 *  userData       :  [IN]  the user data of the popup
 * RETURNS
 *  The screen group id which the global popup belong to
 * EXAMPLE
 * <code>
 *  
 *  void *arg = mmi_malloc(10);
 *  VfxWString title(VFX_WSTR_RES(STR_GLOBAL_ABORT));
 *  VfxWString btnText(VFX_WSTR_RES(STR_GLOBAL_OK));
 *
 *  vapp_nmgr_global_popup_show_confirm_one_button_str(
 *       MMI_SCENARIO_ID_DEFAULT,
 *       VCP_POPUP_TYPE_FAILURE, 
 *       title,
 *       btnText,
 *       VCP_POPUP_BUTTON_TYPE_NORMAL,
 *       callBackOneBtnStr,
 *       arg);
 *
 *  void callBackOneBtnStr(VfxId id, void *userData)
 *  {
 *      switch (id)
 *      {
 *           case VCP_CONFIRM_POPUP_BUTTON_USER_1:
 *           {
 *               //TO DO: handle button click here
 *               break;
 *           }
 *
 *           case VCP_POPUP_BUTTON_NO_PRESSED:
 *           {
 *               //TO DO: handle the case for back key, end key
 *               //and someone invoke vapp_nmgr_global_popup_cancel
 *               break;
 *           }
 *      }
 *      //free the resource if the user data is dynamically allocated.
 *      mmi_mfree(userData);          
 *  }
 * </code>
 *****************************************************************************/        
VfxS32 vapp_nmgr_global_popup_show_confirm_one_button_str(
        mmi_scenario_id scenID,
        VcpPopupTypeEnum type, 
        const VfxWString &text, 
        const VfxWString &btnText1, 
        VcpPopupButtonTypeEnum type1,
        PopupCallBackPtr callBack,
        void *userData);
        

/*****************************************************************************
 * FUNCTION
 *  vapp_nmgr_global_popup_show_confirm_two_button_str
 * DESCRIPTION
 *  This function is used to show a confirm popup with two button.
 *  The string is from the reference of VfxWString.
 *  The display behavior of the global popup will be controlled by NMGR
 * PARAMETERS
 *  scenID         :  [IN]  the scenario which the global popup will have
 *  type           :  [IN]  the popup type
 *  text           :  [IN]  the string reference of VfxWString of the title
 *  btnText1       :  [IN]  the string reference of VfxWString of the button 1
 *  btnText2       :  [IN]  the string reference of VfxWString of the button 2
 *  type1          :  [IN]  the type of the button 1
 *  type2          :  [IN]  the type of the button 2
 *  callBack       :  [IN]  the callback function of the popup
 *  userData       :  [IN]  the user data of the popup
 * RETURNS
 *  The screen group id which the global popup belong to
 * EXAMPLE
 * <code>
 *  
 *  void *arg = mmi_malloc(10);
 *  VfxWString title(VFX_WSTR_RES(STR_GLOBAL_ABORT));
 *  VfxWString btnText1(VFX_WSTR_RES(STR_GLOBAL_OK));
 *  VfxWString btnText2(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
 *
 *  vapp_nmgr_global_popup_show_confirm_two_button_str(
 *       MMI_SCENARIO_ID_DEFAULT,
 *       VCP_POPUP_TYPE_FAILURE, 
 *       title,
 *       btnText1,
 *       btnText2,
 *       VCP_POPUP_BUTTON_TYPE_NORMAL,
 *       VCP_POPUP_BUTTON_TYPE_NORMAL,
 *       callBackTwoBtnStr,
 *       arg);
 *
 *
 *  void callBackTwoBtnStr(VfxId id, void *userData)
 *  {
 *      switch (id)
 *      {
 *           case VCP_CONFIRM_POPUP_BUTTON_USER_1:
 *           {
 *               //TO DO: handle button1 click here
 *               break;
 *           }
 *
 *           case VCP_CONFIRM_POPUP_BUTTON_USER_2:
 *           {
 *               //TO DO: handle button2 click here
 *               break;
 *           }
 *
 *           case VCP_POPUP_BUTTON_NO_PRESSED:
 *           {
 *               //TO DO: handle the case for back key, end key
 *               //and someone invoke vapp_nmgr_global_popup_cancel
 *               break;
 *           }
 *      }
 *      //free the resource if the user data is dynamically allocated.
 *      mmi_mfree(userData);     
 *  }
 * </code>
 *****************************************************************************/         
VfxS32 vapp_nmgr_global_popup_show_confirm_two_button_str(
        mmi_scenario_id scenID,
        VcpPopupTypeEnum type, 
        const VfxWString &text, 
        const VfxWString &btnText1, 
        const VfxWString &btnText2, 
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2,
        PopupCallBackPtr callBack,
        void *userData);

/*****************************************************************************
 * FUNCTION
 *  vapp_nmgr_global_popup_show_command_str
 * DESCRIPTION
 *  This function is used to show a command popup.
 *  The string is from the reference of the VfxWString.
 *  The display behavior of the global popup will be controlled by NMGR
 * PARAMETERS
 *  scenID         :  [IN]  the scenario which the global popup will have
 *  text           :  [IN]  the string reference of VfxWString of the title
 *  callBack       :  [IN]  the callback function of the popup
 *  userData       :  [IN]  the user data of the popup
 * RETURNS
 *  The screen group id which the global popup belong to
 * EXAMPLE
 * <code>
 *  
 *  void *arg = mmi_malloc(10);
 *  VfxWString title(VFX_WSTR_RES(STR_GLOBAL_ABORT));
 *  vapp_nmgr_global_popup_show_command_str(
 *       MMI_SCENARIO_ID_DEFAULT,
 *       title,
 *       callBackCmdBtnStr,
 *       arg);
 *
 *
 *  void enterFuncCmdStr(VfxS32 handle, void *userData)
 *  {
 *      VfxWString btn1Text(VFX_WSTR_RES(STR_GLOBAL_1));
 *      VfxWString btn2Text(VFX_WSTR_RES(STR_GLOBAL_2));
 *      VfxWString btn3Text(VFX_WSTR_RES(STR_GLOBAL_3));
 *      VfxWString btn4Text(VFX_WSTR_RES(STR_GLOBAL_4));
 *      vcp_global_popup_show_command_add_id(handle, 'BUT1', STR_GLOBAL_1, VCP_POPUP_BUTTON_TYPE_NORMAL);
 *      vcp_global_popup_show_command_add_id(handle, 'BUT2', STR_GLOBAL_2, VCP_POPUP_BUTTON_TYPE_NORMAL);
 *      vcp_global_popup_show_command_add_id(handle, 'BUT3', STR_GLOBAL_3, VCP_POPUP_BUTTON_TYPE_NORMAL);
 *      vcp_global_popup_show_command_add_id(handle, 'BUT4', STR_GLOBAL_4, VCP_POPUP_BUTTON_TYPE_NORMAL);
 *  }
 *
 *  void callBackCmdBtnStr(VfxId id, void *userData)
 *  {
 *      switch (id)
 *      {
 *          case 'BUT1':
 *          {
 *              //TO DO: handle button1 click here
 *
 *              break;
 *          }
 *
 *          case 'BUT2':
 *          {
 *              //TO DO: handle button2 click here
 *
 *              break;
 *          }
 *
 *          case 'BUT3':
 *          {
 *              //TO DO: handle button3 click here
 *
 *              break;
 *          }
 *
 *          case 'BUT4':
 *          {
 *              //TO DO: handle button4 click here
 *
 *              break;
 *          }
 *
 *          case VCP_POPUP_BUTTON_NO_PRESSED:
 *          {
 *              //TO DO: handle the case for back key, end key
 *              //and someone invoke vapp_nmgr_global_popup_cancel
 *
 *              break;
 *          }
 *      }
 *      //free the resource if the user data is dynamically allocated.
 *      mmi_mfree(userData);     
 *  }
 * </code>
 *****************************************************************************/          
VfxS32 vapp_nmgr_global_popup_show_command_str(
        mmi_scenario_id scenID,
        const VfxWString &text, 
        PopupCallBackPtr callBack,
        PopupEnterCallBackPtr enterFunc,
        void *userData);

/*****************************************************************************
 * FUNCTION
 *  vapp_nmgr_global_popup_cancel
 * DESCRIPTION
 *  This function is used to close global popup
 * PARAMETERS
 *  handle         :  [IN]  the handle of global popup
 * RETURNS
 *  void
 *****************************************************************************/        
void vapp_nmgr_global_popup_cancel(VfxS32 handle);
