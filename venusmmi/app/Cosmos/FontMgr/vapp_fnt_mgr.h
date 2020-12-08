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
 *  vapp_fmgr.h
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
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FNT_MGR_PROT_H__
#define __VAPP_FNT_MGR_PROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Vcp_form.h"
#include "vfx_app.h"
#include "vfx_page.h"
#include "vcp_list_menu.h"
#include "vfx_main_scr.h"
#include "vfx_base_popup.h"
#include "vcp_slider.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/* External interface */
#ifdef __cplusplus
extern "C"
#endif
{
extern void vapp_fnt_mgr_launch(void);
#ifdef __cplusplus
}
#endif


class VappFontSettings;
class VappFontSettingsScreen;
class VappFontSettingsMainPage;
class VappFontSettingsOptionsPage;
class VappSetPriorityPopup;
class VappFontActivate;
class VappFontActivateScreen;
class VappFontDummy;
class VappFontDummyScreen;


/***************************************************************************** 
 * Class VappFontActivate
 *****************************************************************************/
class VappFontActivate : public VfxApp
{
    VFX_DECLARE_CLASS(VappFontActivate);

public:
    virtual void onInit(void);
    virtual void onDeinit(void);

    VappFontActivate();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *param);

public:
    VappFontActivateScreen *m_mainScr;
};


/***************************************************************************** 
 * Class VappFontActivateScreen
 *****************************************************************************/
class VappFontActivateScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappFontActivateScreen);

// Override
public:
    VappFontActivateScreen(void);
    virtual void on1stReady(void);
    virtual void onInit();
    virtual void onDeinit(void);

public:
    void setDisplayStyle(void);
    void activateFontConfirm(VfxObject* obj, VfxId id);
    void handleCardPlugOut(void);
    void showIndicatorPopup(void);
    void closeIndicatorPopup(void);
    void onPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state);

private:
    VcpConfirmPopup *confirm;
    VcpIndicatorPopup *m_indPopup;
};


/***************************************************************************** 
 * Class VappFontSettings
 *****************************************************************************/
class VappFontSettings : public VfxApp
{
    VFX_DECLARE_CLASS(VappFontSettings);

public:
    VappFontSettingsMainPage *m_mainPage;

public:
    virtual void onInit(void);
    virtual void onDeinit(void);

    VappFontSettings();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *param);
};



class VappFontSettingsMainPage : public VfxPage , public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappFontSettingsMainPage);

// Override
public:
    VcpListMenu *m_list;
    virtual VfxU32 getCount(void) const;
	virtual VfxBool getItemText(
        VfxU32 pos,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxBool getItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image
        );
	virtual void setMenu(VcpListMenu *menu);

// Variable
private: 
	VcpListMenu *m_List;

public:
    VappFontSettings* m_app;
public:
    VappFontSettingsMainPage();
    virtual void onInit(void);
    virtual void onExit(VfxBool isBackward);
    void onItemTap(VcpListMenu *sender, VfxU32 index);
    void drawMainPage(void);
    void updateList(void);
    void handleCardPlugOut(void);
};


/***************************************************************************** 
 * Class VappFontSettingsScreen
 *****************************************************************************/
class VappFontSettingsScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappFontSettingsScreen);

// Override
public:
    VappFontSettingsScreen(void);
    virtual void on1stReady(void);
    virtual mmi_ret onProc(mmi_event_struct *evt);

public:
    void addNewFont(void);
    void uninstallFont(void);
    void uninstallFontConfirm(VfxObject* obj, VfxId id);
    void activateFontConfirm(VfxObject* obj, VfxId id);
    void destroyConfirm(void);
    void closeFMGRCui(void);
    void closeOptionsPage(void);

public:
    VappFontSettingsMainPage *main_page;
    VappFontSettingsOptionsPage *options_page;
    void showInstallingIndicatorPopup(void);
    void showUninstallingIndicatorPopup(void);
    void showPriorityIndicatorPopup(void);
    void closeIndicatorPopup(void);
    void onInstallPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state);
    void onUninstallPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state);
    void onPriorityPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state);
    void changePriorityPopup(void);
    void changePriorityConfirm(VfxObject* obj, VfxId id);

private:
    mmi_id cui_gid;
    VcpConfirmPopup *confirm;
    VcpIndicatorPopup *m_indPopup;
};


class VappFontSettingsOptionsPage : public VfxPage , public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappFontSettingsOptionsPage);

// Override
public:
    VcpListMenu *m_list;
    virtual VfxU32 getCount(void) const;
	virtual VfxBool getItemText(
        VfxU32 pos,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxBool getItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image
        );
	virtual void setMenu(VcpListMenu *menu);
    virtual void onInit(void);
    virtual void onDeinit(void);
    void onItemTap(VcpListMenu *sender, VfxU32 index);

// Variable
private: 
	VcpListMenu *m_List;
    VappSetPriorityPopup *priPopup;

public:
    VappFontSettings* m_app;

public:
    VappFontSettingsOptionsPage();
    void changeFontPriority(void);
    void closePriPopup(void);

private:
    void drawMainPage(void);
    void onPriButtonClicked(VfxU8 pri);
};



/***************************************************************************** 
 * Class VappSetPriorityPopup
 *****************************************************************************/
class VappSetPriorityPopup : public VfxBasePopup
{
    VFX_DECLARE_CLASS(VappSetPriorityPopup);

private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        POPUP_WIDTH = 290,
        POPUP_HEIGHT = 161,
        UP_HEIGHT = 25,
        ICON_X = 11,
        ICON_Y = 49,
        BAR_LENGTH = 219,
        BAR_X = 50, 
        BAR_Y = 47,
        BTN_X = 11,
        BTN_Y = 100,
        BTN_WIDTH = 268,
        BTN_HEIGHT = 45,
        TEXT_FNT_SIZE = 15
#elif defined(__MMI_MAINLCD_480X800__)
        POPUP_WIDTH = 446,
        POPUP_HEIGHT = 226,
        UP_HEIGHT = 45,
        ICON_X = 21,
        ICON_Y = 68, //70
        BAR_LENGTH = 338,
        BAR_X = 87, 
        BAR_Y = 72,
        BTN_X = 21,
        BTN_Y = 131,
        BTN_WIDTH = 404,
        BTN_HEIGHT = 70,
        TEXT_FNT_SIZE = 24
#elif defined(__MMI_MAINLCD_240X400__)
        POPUP_WIDTH = 222,
        POPUP_HEIGHT = 130,
        UP_HEIGHT = 20,
        ICON_X = 8,
        ICON_Y = 34,
        BAR_LENGTH = 175,
        BAR_X = 39,
        BAR_Y = 36,
        BTN_X = 8,
        BTN_Y = 74,
        BTN_WIDTH = 206,
        BTN_HEIGHT = 40,
        TEXT_FNT_SIZE = 13
#else  //if defined(__MMI_MAINLCD_240X320__)
        POPUP_WIDTH = 222,
        POPUP_HEIGHT = 130,
        UP_HEIGHT = 20,
        ICON_X = 8,
        ICON_Y = 34,
        BAR_LENGTH = 175,
        BAR_X = 39,
        BAR_Y = 36,
        BTN_X = 8,
        BTN_Y = 74,
        BTN_WIDTH = 206,
        BTN_HEIGHT = 40,
        TEXT_FNT_SIZE = 13
#endif
    };

private:
    VfxTextFrame* m_priText;
    VfxU8 m_max;
    VfxU8 m_min;

public:
    VfxSignal1 <VfxU8> m_signalBtnClicked;
    VfxU8 m_pri;
    VfxTextFrame* pri_icon;
    VcpSlider* m_slider;
    //static VappSetPriorityPopup *m_self;

private:
    virtual void onInit(void);
    virtual void onDeinit(void);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    void onSliderMoved(VfxObject *obj, VfxFloat oldval, VfxFloat newval);
    void onButtonClicked(VfxObject *sender, VfxId id);
    void onDecreasePri(void);
    void onIncreasePri(void);

public:
    void setInitPri(VfxU8 vol);
    VfxU8 getPri(void);
    void setTitle(VfxResId id);
    VappSetPriorityPopup();
};


/***************************************************************************** 
 * Class VappFontDummy
 *****************************************************************************/
class VappFontDummy : public VfxApp
{
    VFX_DECLARE_CLASS(VappFontDummy);

public:
    virtual void onInit(void);
    virtual void onDeinit(void);

    VappFontDummy();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *param);
};


/***************************************************************************** 
 * Class VappFontDummyScreen
 *****************************************************************************/
class VappFontDummyScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappFontDummyScreen);

// Override
public:
    VappFontDummyScreen(void);
    virtual void on1stReady(void);
    virtual void onInit();
    virtual void onDeinit(void);
};

#endif /* __VAPP_FNT_MGR_PROT_H__ */

