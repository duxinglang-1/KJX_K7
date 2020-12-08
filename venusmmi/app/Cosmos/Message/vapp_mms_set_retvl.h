/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_mms_set_cm.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MMSSETTING_RETVL_H__
#define __VAPP_MMSSETTING_RETVL_H__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_navi_title_bar.h"
#include "mmi_rp_vapp_mms_def.h"


 extern "C" {
   #include "MmsSrvGprot.h"
 }

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/



#ifdef __MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__				 
class VappMMSSetRetvlHomePage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMMSSetRetvlHomePage);

//Declaration
private:


	VfxU32 m_selectedIndex;
	VcpListMenu *m_menu;
	VcpTitleBar *m_titleBar;
	srv_mms_nvram_retrieval_settings_struct *m_retvlSet;

// Constructor/Destructors
public:
	VappMMSSetRetvlHomePage(){}

// Override
public:
	virtual void onInit();
	virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onEnter(VfxBool isBackward);
	virtual void onRotate(
    const VfxScreenRotateParam &param 
	);
	virtual void setMenu(VcpListMenu *menu);

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const;
	virtual VfxU32 getCount() const;

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
	void updateItem(VfxU32 index);

	virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
		{return VFX_TRUE;}	

	//Methods
public:
	 void onTapItem(VcpListMenu *menu,VfxU32 index);

	    VfxSignal2 <
        VcpGroupListMenu *, // Sender
        VcpMenuPos         // List item position
    > m_signalMMSSettingRefresh;

};
#endif

#ifdef __MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__				
class VappMMSSetRetvlRoamPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMMSSetRetvlRoamPage);

//Declaration
private:


	VfxU32 m_selectedIndex;
	VcpListMenu *m_menu;
	VcpTitleBar *m_titleBar;
	srv_mms_nvram_retrieval_settings_struct *m_retvlSet;

// Constructor/Destructors
public:
	VappMMSSetRetvlRoamPage(){}

// Override
public:
	virtual void onInit();
	virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onEnter(VfxBool isBackward);
	virtual void onRotate(
    const VfxScreenRotateParam &param 
	);
	virtual void setMenu(VcpListMenu *menu);

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const;
	virtual VfxU32 getCount() const;

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
	void updateItem(VfxU32 index);

	virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
		{return VFX_TRUE;}	

	//Methods
public:
	 void onTapItem(VcpListMenu *menu,VfxU32 index);


	    VfxSignal2 <
        VcpGroupListMenu *, // Sender
        VcpMenuPos         // List item position
    > m_signalMMSSettingRefresh;

};
#endif

#endif /* __MMI_MMS_2__  */
#endif /* __VAPP_MMSSETTING_RETVL_H__ */

