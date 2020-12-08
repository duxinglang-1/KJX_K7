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
 *  vapp_dialer_cp.h
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
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DIALER_CP_H__
#define __VAPP_DIALER_CP_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_menu_popup.h"
#include "vfx_timer.h"
#include "mmi_rp_srv_phb_def.h"
#include "vapp_dialer_core.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define DIALER_DISTANCE_BETWEEN_EACH_COMPONENT (4)
#define DILAER_GROUP_BUTTON_LARGE_PARTE (25)
#define DIALER_BACKSPACE_BUTTON_WIDTH (40)
#define DIALER_COMPONENT_HEIGHT (40)
#define NVRAM_DIALER_PREFER_SIM NVRAM_PHB_SPEAK_NAME_ON_OFF

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpImageButtionLongPress
 *****************************************************************************/
class VcpImageButtonLongPress : public VcpImageButton
{
public:
    VfxSignal2 <VfxObject*, VfxId> m_longPressed;

protected:
    virtual VfxBool onPenInput(VfxPenEvent &event);
};


/***************************************************************************** 
 * Class DialerLayout
 *****************************************************************************/
class DialerLayout
{
public:
    U16 m_keypadLeftMargin;
    U16 m_keypadKeyWidth;
    U16 m_keypadMiddleWidthMargin;
    U16 m_keypadRightMargin;

    U16 m_keypadUpMargin;
    U16 m_keypadKeyHeight;
    U16 m_keypadMiddleHeightMargin;
    U16 m_keypadDownMargin;

    U16 m_editLeftMargin;
    U16 m_editContactWidth;
    U16 m_editBoxWidth;
    U16 m_editBoxBackSpaceMargin;
    U16 m_editBackSpaceWidth;
    U16 m_editRightMargin;

    U16 m_editUpMargin;
    U16 m_editBoxHeight;
    U16 m_editDownMargin;

public:
    void initClassicDialer();
    void initEditBeforeCall();
};


/***************************************************************************** 
 * Class DialBtnLayout
 *****************************************************************************/
class DialBtnLayout
{
public:
    U16 m_dialLeftMargin;
    U16 m_dialRightMargin;
    U16 m_dialerGapMargin;

    U16 m_dialerUpMargin;
    U16 m_dialerBtnHeight;
    U16 m_dialerDownMargin;
};


#ifdef __MMI_VIDEO_TELEPHONY__
/***************************************************************************** 
 * Class VcpDialerButtonContent
 *****************************************************************************/
class VcpDialerButtonContent : public VfxFrame
{
public:
    VcpDialerButtonContent();
    VcpDialerButtonContent(const VfxWString &value, VfxS32 id);
    VfxU32 getWidth();
    void setIsDisabled(VfxBool value);

protected:
    virtual void onInit();

private:
    VfxTextFrame  *m_frmText;
    VfxImageFrame *m_dialFrame;
    VfxWString     m_string;
    VfxS32         m_imageId;
    DialerLayout   m_layout;

#if defined(__MMI_MAINLCD_480X800__)
    const static VfxU32 m_dialerImageHeight = 50;
#elif defined(__MMI_MAINLCD_320X480__)
    const static VfxU32 m_dialerImageHeight = 30;
#else
    const static VfxU32 m_dialerImageHeight = 25;
#endif
};
#endif /* __MMI_VIDEO_TELEPHONY__ */


/***************************************************************************** 
 * Class VcpGroupButton
 *****************************************************************************/
class VcpGroupButton : public VfxControl
{
public:
    enum VcpGroupButtonTypeEnum
    {
        VCP_BUTTON_NONE,
        VCP_BUTTON_SIM1 = MMI_SIM1,
        VCP_BUTTON_SIM2 = MMI_SIM2,
        VCP_BUTTON_SIM3 = MMI_SIM3,
        VCP_BUTTON_SIM4 = MMI_SIM4,
        VCP_BUTTON_VIDEO_CALL,
        VCP_BUTTON_ALL_TYPE,
        VCP_BUTTON_EMERGENCY
    };

// Constructor / Destructor
public:
    // Default constructor
    VcpGroupButton():m_type(VCP_BUTTON_NONE),
                         m_simNum(1),
                         m_videoCall(VFX_FALSE),
                         m_callButton(NULL),
                         m_btnEmergencyCall(NULL),
                    #ifdef __MMI_VIDEO_TELEPHONY__
                         m_btnVideoCall(NULL),
                    #endif
                         m_layout(){}
    VcpGroupButton(DialBtnLayout layout, VcpGroupButtonTypeEnum type, mmi_sim_enum sim_type);

    //override
    virtual void onInit();
    void setBtnStype(VcpGroupButtonTypeEnum type = VCP_BUTTON_NONE);
    void refleshComboBtn();
    void setPreferSIM(mmi_sim_enum type);
    mmi_sim_enum getPreferSIM();

public:
    VfxSignal1 <VcpGroupButtonTypeEnum> m_signalCallButtonPress;

private:
    VcpGroupButtonTypeEnum  m_type;
    U32                     m_simNum;
    VfxBool                 m_videoCall;
    VcpComboButton         *m_callButton;
    VcpImageButton         *m_btnEmergencyCall;
#ifdef __MMI_VIDEO_TELEPHONY__
    VcpImageButton         *m_btnVideoCall;
    VcpDialerButtonContent *m_videoFrame;
#endif /* __MMI_VIDEO_TELEPHONY__ */
    DialBtnLayout           m_layout;
    VcpMenuPopup           *m_menu;
    mmi_sim_enum            m_preferSIM;

private:
    mmi_sim_enum getSingleInsertSIM();
    void placeVideoCall();
    void placeCallButton();
    void placeComponent();
    void setComponentAction();
    void onChildBtnClick(VcpButton* obj, VfxId id);
    void onBtnClick(VfxObject *obj, VfxId id);
#ifdef __MMI_VIDEO_TELEPHONY__
    void onVideoClick(VfxObject *obj, VfxId id);
#endif
    void onEmergencyClick(VfxObject *obj, VfxId id);
    VcpGroupButton::VcpGroupButtonTypeEnum getPreferType(mmi_sim_enum sim_type);
    void simChoosePopup();
    void onMenuClick(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);
};


/***************************************************************************** 
 * Class VcpDialerPad
 *****************************************************************************/
class VcpDialerPad : public VfxControl
{
public:
    enum VcpDialerButtonTypeEnum
    {
        VCP_BUTTON_DIALER_1 = 0,
        VCP_BUTTON_DIALER_2,
        VCP_BUTTON_DIALER_3,
        VCP_BUTTON_DIALER_4,
        VCP_BUTTON_DIALER_5,
        VCP_BUTTON_DIALER_6,
        VCP_BUTTON_DIALER_7,
        VCP_BUTTON_DIALER_8,
        VCP_BUTTON_DIALER_9,
        VCP_BUTTON_DIALER_STAR,
        VCP_BUTTON_DIALER_0,
        VCP_BUTTON_DIALER_POUND,
        VCP_BUTTON_DIALER_END,
    };

    enum VappDialerTypeEnum
    {
        VCP_DIALER_CLASSIC,
        VCP_DIALER_EDIT_BEFORE_CALL,
        VCP_DIALER_EMERGENCY,
        VCP_DIALER_NEW_CALL,
        VCP_DIALER_END
    };

    VcpDialerPad(){}
    VcpDialerPad(VappDialerTypeEnum type, mmi_sim_enum m_simType);

public:
    virtual void onInit();
    void registerExtraControl();
    void unRegisterExtraControl();
    VcpTextEditor *getEditBox();
    //void setBtnNormal();
    void refleshDialer();
    mmi_sim_enum getPreferSIM();

public:
    VfxSignal2 <VcpDialerButtonTypeEnum, VfxWChar *> m_signalDialerLongPress;
    VfxSignal1 <VfxWChar *>                          m_signalSaveToContactClick;
    VfxSignal2 <VcpDialerButtonTypeEnum, VfxWChar *> m_signalDialerPress;
    VfxSignal1 <VcpTextEditor *>                     m_signalDialerStringChanged;

public:
    VcpGroupButton          *m_dialButton;
    VappDialerTypeEnum       m_type;

private:
    VfxControl              *m_dialerImage[12];
    VfxControl              *m_speedDial[12];
    VfxTextFrame            *m_dialerText[12];
	VfxTextFrame 			*m_dialerSubText[12] ;
    VfxTextFrame            *m_dialerPlus;
    VcpImageButton          *m_btnDialer[12];
    VcpImageButtonLongPress *m_btnBackSpace;
    VcpButton               *m_btnSaveToContact;
    VcpTextEditor           *m_editBox;
    VfxWChar                 m_inputBuffer[41];
    DialerLayout             m_layout;
    VfxTextFrame            *m_titleText;
    mmi_sim_enum             m_simType;
    VfxTimer                *m_timer;
    VfxBool                  m_isLongPress;

private:
    void titleInit();
    void placeDialer();
#ifdef __MMI_PHB_SPEED_DIAL__
    void placeSpeedDialList();
#endif /* __MMI_PHB_SPEED_DIAL__ */
    void placeComponent();
    void setComponentAction();
    void onBtnClick(VfxObject *obj, VfxId id);
    void keyTonePlay(VcpImageButton* obj);
    void onBtnStateChange(VcpImageButton* obj, VcpImageButtonStateEnum state);
    VfxKeyCodeEnum getKeyCode(VfxId id);
    VfxU16 getToneID(VfxId id);
    void onBtnBackSpaceClick(VcpImageButton* btn, VcpImageButtonStateEnum state);
    void onBackSpaceLongPress(VfxObject *obj, VfxId id);
    void onBtnSaveToContactClick(VfxObject *obj, VfxId id);
    void onEditContentChange(VcpTextEditor *edit_box);
    void setLayoutType();
    void setBG();
    void setDialBtn();
    void onBtnLongPress(VfxObject* obj, VfxId id);
    //void onTimerNotify(VfxTimer *timer);
    static void onTimerNotify();
    void onTimerNotifyRepeat();
};

#endif /* __VAPP_DIALER_CP_H__ */

