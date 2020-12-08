/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  Vapp_cbs_setting_page.h
 *
 * Project:
 * --------
 *  App CBS
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
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CBS_SETTING_PAGE_H__
#define __VAPP_CBS_SETTING_PAGE_H__
#include "mmi_features.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/
 #include "vapp_cbs_iprot.h"
#include "vapp_sms_setting_scrn.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define ITEM_NUM_FOR_ONE_SIM  (4)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Class Xyz
 ****************************************************************************/
 /***************************************************************************** 
  * Setting pages 
  *****************************************************************************/
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
#endif
 class VappCbsSettingPage : public VfxPage,public IVcpGroupListMenuContentProvider
 {
	
 public:
 	 VappCbsSettingPage();
	 virtual VfxU32 getCount(VfxU32 group) const;
	 virtual VfxU32 getGroupCount() const;
	 virtual VfxBool getItemText(
		 VcpMenuPos pos,					
		 VcpListMenuFieldEnum fieldType,  
		 VfxWString &text,				  
		 VcpListMenuTextColorEnum &color  
		 );
	 virtual VfxBool getItemIsDisabled(
		 VcpMenuPos pos   // [IN] position of the item
		 ) const;
	 virtual VfxBool getItemImage(
		 VcpMenuPos pos,				  // [IN] the position of item
		 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
		 VfxImageSrc &image 			  // [OUT] the image resource
		 );
	 virtual VfxBool getItemIsHighlightable(
		 VcpMenuPos pos   // [IN] position of the item
		 ) const;
	 virtual VcpListMenuCellBaseControl* getItemCustomControl(
		 VcpMenuPos pos,								  // [IN] position of the item
		 VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
		 VfxFrame *parentFrame							  // [IN] parent frame of the custom content frame
		 );
 	 //static void switchActivationCallback(cbsCallbackStruct *callbackData);
 
 protected:
	 virtual void onInit();
	 virtual void onDeinit();
	 virtual void onQueryRotateEx(VfxScreenRotateParam &param);
 
 private:
	  void getGroupNumber();
	  void onItemTapped(VcpGroupListMenu *sender, VcpMenuPos pos);
  #if 0
/* under construction !*/
  #endif
	  void activationSwitched(VfxObject *sender, VfxBool isChecked);
	  void OnSRSwitchUnmovable();
	  static mmi_ret onFlightModeSwitchProc(mmi_event_struct *evt);
 
 private:
	 enum
	 {
		 ITEM_ID_ACTIVATION,
		 ITEM_ID_CHANNEL,
		 ITEM_ID_LANGUAGE
	 };
 
	 VcpGroupListMenu *m_ListMenu;
	 VappSmsSettingSwitchCp *m_listMenuControl[MMI_MAX_SIM_NUM];
	 VfxBool m_isNosimInsert;
	 VfxS32 m_groupNumber;
	 VfxS32 m_groupToSimIndex[MMI_MAX_SIM_NUM];
	 static const VfxS32 m_GroupItemCnt = 3;
 };

#endif /* __VAPP_CBS_SETTING_PAGE_H__ */


