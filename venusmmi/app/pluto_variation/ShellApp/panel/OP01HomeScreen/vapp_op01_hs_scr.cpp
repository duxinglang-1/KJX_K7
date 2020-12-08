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
 *  Vapp_op01_hs_scr.cpp
 *
 * Project:
 * --------
 *  Venus OP01 Homescreen
 *
 * Description:
 * ------------
 *  OP01 Homescreen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__

#include "vfx_uc_include.h"
#include "mmi_rp_app_venus_shell_op01_hs_def.h"
#include "vapp_op01_hs_scr.h"
#include "OP01HomeScreen/vadp_v2p_op01_hs.h"
#include "trc/vadp_app_trc.h"
#include "GUI\vadp_p2v_theme_info.h"

#include "vapp_wallpaper_kit.h"
#include "mmi_rp_srv_wallpaper_def.h"
#include "GlobalResDef.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "CustThemesRes.h"  /* UI_filled_area */
#include "fat_fs.h"         /* file system */
#include "DRM_gprot.h"
#include "PhoneSetupGprots.h"
#include "wgui.h"

#ifdef __MMI_OP01_DCD_V30__
#include "DCDV30Gprot.h"
#endif

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Class VappOp01HsScr
 *****************************************************************************/

VfxBool VappOp01HsScr::s_bootupInit = VFX_TRUE;
const VfxS32 VappOp01HsScr::s_penOffsetThreshold = 15;
VappOp01HsScr *gVappOp01HsScrObj;

VappOp01HsScr::VappOp01HsScr() :
    m_wallpaper(NULL),
    m_virConrol(NULL),
    m_networkInfo(NULL),
    m_idleModeText(NULL),
    m_dateTime(NULL),
    m_hintNum(0),
    m_searchButton(NULL),
    m_wlanButton(NULL),
    m_shctBar(NULL),
#ifdef __MMI_OP01_DCD_V30__
    m_dcdBar(NULL),
#endif
    m_timerResumeWallpaper(NULL),
    m_longPressEnable(VFX_FALSE),
    m_isRecvPenDown(VFX_FALSE)
{
    for (VfxS32 i = 0; i < 3; i++)
    {
        m_hintBox[i] = NULL;
    }
}

VfxSize VappOp01HsScr::getScreenSize()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;

    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    return VfxSize(main_screen_size.width, main_screen_size.height);
}

void VappOp01HsScr::initWallpaper()
{
    // wallpaper is created in suspended state
    // it will resume on enter view
    VFX_OBJ_CLOSE(m_wallpaper);
    m_wallpaper = VappWallpaperKit::createWallpaper(this, VAPP_WALLPAPER_SRC_HOMESCREEN, 1);
        
    // Create a virtual control to let homescreen receive pen event,
    // then homescreen's onPenInput() can be invoked
    VFX_OBJ_CREATE(m_virConrol, VfxControl, this);
    m_virConrol->setBounds(0, 0, getScreenSize().width, getScreenSize().height);
}

void VappOp01HsScr::deinitWallpaper()
{
    if (m_virConrol)
    {
        VFX_OBJ_CLOSE(m_virConrol);
    }
    
    if(m_wallpaper)
    {
        VFX_OBJ_CLOSE(m_wallpaper);
    }
}

void VappOp01HsScr::onResumeWallpaper(VfxTimer *timer)
{
    resumeLiveWallpaper();

    VFX_OBJ_CLOSE(m_timerResumeWallpaper);
}


void VappOp01HsScr::initNetworkInfo()
{
    // Operator name and status
    VFX_OBJ_CREATE(m_networkInfo, VappOp01HsNwInfo, this);    
    m_networkInfo->setPos(VfxPoint(LEFT_MARGIN, MMI_STATUS_BAR_HEIGHT + TOP_MARGIN));
    m_networkInfo->setBounds(0, 0, getScreenSize().width - (LEFT_MARGIN << 1), DATE_TIME_POS_Y - MMI_STATUS_BAR_HEIGHT - (TOP_MARGIN << 1) + 3);
    
    VdatNetworkInfo *networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    networkSrv->m_signalNameChanged.connect(this, &VappOp01HsScr::onNetworkNameChanged);
    networkSrv->m_signalStatusChanged.connect(this, &VappOp01HsScr::onNetworkStatusChanged);

    // Update here, otherwise the text will appear later when the home screen is shown.
    onNetworkNameChanged(networkSrv);
    onNetworkStatusChanged(networkSrv);
}

void VappOp01HsScr::deinitNetworkInfo()
{
    // Disconnect signal for network operator name and status
    VdatNetworkInfo *networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);    
    networkSrv->m_signalStatusChanged.disconnect(this, &VappOp01HsScr::onNetworkStatusChanged);
    networkSrv->m_signalNameChanged.disconnect(this, &VappOp01HsScr::onNetworkNameChanged);

    VFX_OBJ_CLOSE(m_networkInfo);
}

void VappOp01HsScr::onNetworkNameChanged(VdatNetworkInfo *networkSrv)
{
    if (m_networkInfo != NULL)
    {
        m_networkInfo->setNetworkName(networkSrv->getName());
    }
}

void VappOp01HsScr::onNetworkStatusChanged(VdatNetworkInfo *networkSrv)
{
    if (m_networkInfo != NULL)
    {
        m_networkInfo->setNetworkStatus(networkSrv->getStatus());
    }
}

void VappOp01HsScr::initIdleModeText()
{
    VFX_OBJ_CREATE(m_idleModeText, VappOp01HsIdleModeText, this);
    m_idleModeText->setPos(0, IDLE_MODE_TEXT_POS_Y);

    VdatNetworkInfo *networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    networkSrv->m_signalIdleModeTextChanged.connect(this, &VappOp01HsScr::onIdleModeTextChanged);
    networkSrv->m_signalIdleModeIconChanged.connect(this, &VappOp01HsScr::onIdleModeIconChanged);

    // Update here; or the text will appear later when the home screen is shown.
    onIdleModeTextChanged(networkSrv);
    onIdleModeIconChanged(networkSrv);
}

void VappOp01HsScr::deinitIdleModeText()
{
    // Disconnect signal for network operator name and status
    VdatNetworkInfo *networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);

    networkSrv->m_signalIdleModeTextChanged.disconnect(this, &VappOp01HsScr::onIdleModeTextChanged);
    networkSrv->m_signalIdleModeIconChanged.disconnect(this, &VappOp01HsScr::onIdleModeIconChanged);

    VFX_OBJ_CLOSE(m_idleModeText);
}

void VappOp01HsScr::onIdleModeTextChanged(VdatNetworkInfo *networkSrv)
{
    m_idleModeText->setIdleModeText(networkSrv->getIdleModeText());
}

void VappOp01HsScr::onIdleModeIconChanged(VdatNetworkInfo *networkSrv)
{
    m_idleModeText->setIdleModeIcon(networkSrv->getIdleModeIcon());
}

void VappOp01HsScr::initDateTime()
{
    VFX_OBJ_CREATE(m_dateTime, VappOp01HsDateTime, this);
    m_dateTime->setAnchor(1, 0);
    m_dateTime->setPos(getScreenSize().width - RIGHT_MARGIN, DATE_TIME_POS_Y);
}

void VappOp01HsScr::deinitDateTime()
{
    VFX_OBJ_CLOSE(m_dateTime);
}

void VappOp01HsScr::initHintBox()
{
    VfxS32 posY = HINT_BOX_POS_Y;
    VfxS32 posX = 0;
    
    VfxS32 num = vadp_v2p_hs_get_unread_mms_number();
    if (num != 0)
    {
        VFX_OBJ_CREATE(m_hintBox[TYPE_MMS], VappOp01HsHintBox, this);
        posX = LEFT_MARGIN + m_hintBox[TYPE_MMS]->getBounds().getWidth();
        m_hintBox[TYPE_MMS]->setPos(posX, posY);
        m_hintBox[TYPE_MMS]->setAnchor(1.0f, 1.0f);
        m_hintBox[TYPE_MMS]->setHintType(VappOp01HsHintBox::HINT_TYPE_MMS);    
        m_hintBox[TYPE_MMS]->setHintStr(num);

        m_hintNum++;
        posY -= m_hintBox[TYPE_MMS]->getBounds().getHeight() + LINE_GAP;
    }

    num = vadp_v2p_hs_get_unread_sms_number();
    if (num != 0)
    {
        VFX_OBJ_CREATE(m_hintBox[TYPE_SMS], VappOp01HsHintBox, this);
        posX = LEFT_MARGIN + m_hintBox[TYPE_SMS]->getBounds().getWidth();
        m_hintBox[TYPE_SMS]->setPos(posX, posY);
        m_hintBox[TYPE_SMS]->setAnchor(1.0f, 1.0f);
        m_hintBox[TYPE_SMS]->setHintType(VappOp01HsHintBox::HINT_TYPE_SMS);
        m_hintBox[TYPE_SMS]->setHintStr(num);

        m_hintNum++;
        posY -= m_hintBox[TYPE_SMS]->getBounds().size.height + LINE_GAP;
    }

    num = vadp_v2p_hs_get_unread_call_number();
    if (num != 0)
    {
        VFX_OBJ_CREATE(m_hintBox[TYPE_CALL], VappOp01HsHintBox, this);
        posX = LEFT_MARGIN + m_hintBox[TYPE_CALL]->getBounds().getWidth();
        m_hintBox[TYPE_CALL]->setPos(posX, posY);
        m_hintBox[TYPE_CALL]->setAnchor(1.0f, 1.0f);
        m_hintBox[TYPE_CALL]->setHintType(VappOp01HsHintBox::HINT_TYPE_CALL);
        m_hintBox[TYPE_CALL]->setHintStr(num);

        m_hintNum++;
    }
}

void VappOp01HsScr::deinitHintBox()
{
    for (VfxS32 i = 2; i >=0; i--)
    {
        VFX_OBJ_CLOSE(m_hintBox[i]);
    }

    // Because VappOp01HsScr's constructor is invoked only once from power on,
    // the m_hintNum will be added after going back from other screen.
    // This will cause hintbox position wrong.
    m_hintNum = 0;
}

void VappOp01HsScr::updateHintBox(VfxS32 id, VfxS32 num)
{
    switch (id)
    {
        case BUTTON_TYPE_SMS:
        {
            if (m_hintBox[TYPE_SMS] != NULL)
            {
                m_hintBox[TYPE_SMS]->setHintStr(num);
            }
            else
            {
                if (vadp_v2p_hs_get_unread_sms_number() != 0)
                {
                    VFX_OBJ_CREATE(m_hintBox[TYPE_SMS], VappOp01HsHintBox, this);
                    VfxS32 posX = LEFT_MARGIN + m_hintBox[TYPE_SMS]->getBounds().getWidth();
                    VfxS32 posY = HINT_BOX_POS_Y - (m_hintBox[TYPE_SMS]->getBounds().size.height + LINE_GAP) * m_hintNum;
                    m_hintBox[TYPE_SMS]->setPos(posX, posY);
                    m_hintBox[TYPE_SMS]->setAnchor(1.0f, 1.0f);
                    m_hintBox[TYPE_SMS]->setHintType(VappOp01HsHintBox::HINT_TYPE_SMS);
                    m_hintBox[TYPE_SMS]->setHintStr(num);

                    m_hintNum++;
                }
            }
            break;
        }

        case BUTTON_TYPE_MMS:
        {
            if (m_hintBox[TYPE_MMS] != NULL)
            {
                m_hintBox[TYPE_MMS]->setHintStr(num);
            }
            else
            {
                if (vadp_v2p_hs_get_unread_mms_number() != 0)
                {
                    VFX_OBJ_CREATE(m_hintBox[TYPE_MMS], VappOp01HsHintBox, this);
                    VfxS32 posX = LEFT_MARGIN + m_hintBox[TYPE_MMS]->getBounds().getWidth();
                    VfxS32 posY = HINT_BOX_POS_Y - (m_hintBox[TYPE_MMS]->getBounds().size.height + LINE_GAP) * m_hintNum;
                    m_hintBox[TYPE_MMS]->setPos(posX, posY);
                    m_hintBox[TYPE_MMS]->setAnchor(1.0f, 1.0f);
                    m_hintBox[TYPE_MMS]->setHintType(VappOp01HsHintBox::HINT_TYPE_MMS);
                    m_hintBox[TYPE_MMS]->setHintStr(num);

                    m_hintNum++;
                }
            }
            break;
        }

        case BUTTON_TYPE_CALL:
        {
            if (m_hintBox[TYPE_CALL] != NULL)
            {
                m_hintBox[TYPE_CALL]->setHintStr(num);
            }
            else
            {
                if (vadp_v2p_hs_get_unread_call_number() != 0)
                {
                    VFX_OBJ_CREATE(m_hintBox[TYPE_CALL], VappOp01HsHintBox, this);
                    VfxS32 posX = LEFT_MARGIN + m_hintBox[TYPE_CALL]->getBounds().getWidth();
                    VfxS32 posY = HINT_BOX_POS_Y - (m_hintBox[TYPE_CALL]->getBounds().size.height + LINE_GAP) * m_hintNum;
                    m_hintBox[TYPE_CALL]->setPos(posX, posY);
                    m_hintBox[TYPE_CALL]->setAnchor(1.0f, 1.0f);
                    m_hintBox[TYPE_CALL]->setHintType(VappOp01HsHintBox::HINT_TYPE_CALL);
                    m_hintBox[TYPE_CALL]->setHintStr(num);

                    m_hintNum++;
                }
            }
            break;
        }

        default:
            break;
    }
}

void VappOp01HsScr::initSearchButton()
{
    VFX_OBJ_CREATE(m_searchButton, VappOp01HsSearchButton, this);
    m_searchButton->setPos(getScreenSize().width - RIGHT_MARGIN, BUTTON_POS_Y);
    m_searchButton->setAnchor(1.0, 1.0);
}

void VappOp01HsScr::deinitSearchButton()
{
    VFX_OBJ_CLOSE(m_searchButton);
}

void VappOp01HsScr::initWlanButton()
{
    VfxS32 wlanStatus = vadp_v2p_hs_get_wlan_state();

    VFX_OBJ_CREATE_EX(m_wlanButton, VappOp01HsWlanSwitch, this, (wlanStatus));
    if (m_searchButton == NULL)
    {
        m_wlanButton->setPos(getScreenSize().width - RIGHT_MARGIN, BUTTON_POS_Y);
    }
    else
    {
        VfxS32 posX = m_searchButton->getPos().x - m_searchButton->getBounds().getWidth() - LINE_GAP;
        m_wlanButton->setPos(posX, BUTTON_POS_Y);
    }
    m_wlanButton->setAnchor(1.0f, 1.0f);
}

void VappOp01HsScr::deinitWlanButton()
{
    VFX_OBJ_CLOSE(m_wlanButton);
}

void VappOp01HsScr::updateWlanButton()
{
    if (m_wlanButton != NULL)
    {
        m_wlanButton->updateButton();
    }
}

void VappOp01HsScr::initShctBar()
{
    VFX_OBJ_CREATE(m_shctBar, VappOp01HsShctBar, this);
    m_shctBar->setPos(0, SHCT_BAR_POS_Y);
}

void VappOp01HsScr::deinitShctBar()
{
    VFX_OBJ_CLOSE(m_shctBar);
}

#ifdef __MMI_OP01_DCD_V30__
void VappOp01HsScr::initDCDBar()
{
    VFX_OBJ_CREATE(m_dcdBar, VappOp01HsDCDBar, this);
    m_dcdBar->setPos(0, DCD_BAR_POS_Y);
}

void VappOp01HsScr::deinitDCDBar()
{
    VFX_OBJ_CLOSE(m_dcdBar);
}

void VappOp01HsScr::updateDCDNewsImgArea()
{
    if (m_dcdBar != NULL)
    {
        m_dcdBar->updateDCDNewsImgArea();
    }
}

void VappOp01HsScr::updateDCDNewsContentArea()
{
    if (m_dcdBar != NULL)
    {
        m_dcdBar->updateDCDNewsContentArea();
    }
}

void VappOp01HsScr::updateDCDWhetherArea()
{
    if (m_dcdBar != NULL)
    {
        m_dcdBar->updateDCDWhetherArea();
    }
}
#endif

void VappOp01HsScr::suspendLiveWallpaper()
{
    if(m_wallpaper)
    {
        m_wallpaper->suspend();
    }
}

void VappOp01HsScr::resumeLiveWallpaper()
{
#ifdef __MMI_OP01_DCD_V30__
    if (m_wallpaper && !mmi_dcd_is_main_syncing())
#else
    if (m_wallpaper)
#endif
    {
        m_wallpaper->resume();
    }
}

void VappOp01HsScr::onSwitchBegin(VfxBool isSwitchOut)
{
    VFX_UNUSED(isSwitchOut);

    suspendLiveWallpaper();
}

void VappOp01HsScr::onSwitchEnd()
{
    resumeLiveWallpaper();
}

#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__)
void VappOp01HsScr::onCommandPopCallback(VfxObject *obj, VfxId id)
{
    if (id == WALLPAPER_GALLERY)
    {
        mmi_phnset_wallpaper_entry_system(GRP_ID_INVALID);
    }
    else if (id == WALLPAPER_FMGR)
    {
        mmi_phnset_wallpaper_entry_fmgr(GRP_ID_INVALID);
    }
    else if (id == WALLPAPER_LIVE)
    {
        mmi_phnset_wallpaper_entry_vui_live_wallpaper(GRP_ID_INVALID);
    }
    else
    {
        resumeLiveWallpaper();
    }
}

void VappOp01HsScr::showWallpaperConfirm(void)
{
    // Popup's parent must be VfxScreen
    VcpCommandPopup *cmdPopup;
    VFX_OBJ_CREATE(cmdPopup, VcpCommandPopup, findScreen());
    cmdPopup->setText(VFX_WSTR_RES(STR_GLOBAL_WALLPAPER));
    cmdPopup->addItem(WALLPAPER_LIVE, VFX_WSTR_RES(STR_ID_WALLPAPER_LIVE_WALLPAPER));
    cmdPopup->addItem(WALLPAPER_GALLERY, VFX_WSTR_RES(STR_ID_WALLPAPER_GALLERY));
    cmdPopup->addItem(WALLPAPER_FMGR,   VFX_WSTR_RES(STR_WALLPAPER_DOWNLOAD));
    cmdPopup->addItem(WALLPAPER_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    cmdPopup->m_signalButtonClicked.connect(this, &VappOp01HsScr::onCommandPopCallback);
    cmdPopup->setAutoDestory(VFX_TRUE);
    cmdPopup->show(VFX_TRUE);
}
#endif /* defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) */

VfxBool VappOp01HsScr::onPenInput(VfxPenEvent &event)
{
    // Let wallpaper receive the pen event.
    m_wallpaper->doPenInput(event);

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_longPressEnable = VFX_TRUE;
            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
        {
        #if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__)
            if(m_longPressEnable == VFX_TRUE)
            {
                VfxS32 diffX = event.pos.x - event.downPos.x;
                VfxS32 diffY = event.pos.y - event.downPos.y;
                VfxU32 offset = vfxSqrt(diffX * diffX + diffY * diffY);

                if(offset <= s_penOffsetThreshold)
                {
                    m_wallpaper->suspend();
                    showWallpaperConfirm();
                }
            }
        #endif
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
        #if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__)
            VfxS32 diffX = event.pos.x - event.downPos.x;
            VfxS32 diffY = event.pos.y - event.downPos.y;
            VfxU32 offset = vfxSqrt(diffX * diffX + diffY * diffY);

            if(offset > s_penOffsetThreshold)
            {
                m_longPressEnable = VFX_FALSE;
            }
        #endif /* defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) */
            break;
        }

        case VFX_PEN_EVENT_TYPE_UP:
            m_longPressEnable = VFX_FALSE;
            break;

        default:
            break;
    }

    return VFX_TRUE;
}

void VappOp01HsScr::onInit()
{
    VappShellPanel::onInit();

    setBgColor(VFX_COLOR_BLACK);
}

void VappOp01HsScr::onDeinit()
{
    VappShellPanel::onDeinit();
}

void VappOp01HsScr::onInitView()
{
    VappShellPanel::onInitView();

    initWallpaper();

    initNetworkInfo();

    initIdleModeText();

    initDateTime();

    initHintBox();

    if (vadp_v2p_hs_is_search_box_enable())
    {
        initSearchButton();
    }

    if (vadp_v2p_hs_is_wlan_box_enable())
    {
        initWlanButton();
    }

    initShctBar();
}

void VappOp01HsScr::onDeinitView()
{
    deinitShctBar();
    
    if (vadp_v2p_hs_is_wlan_box_enable())
    {
        deinitWlanButton();
    }

    if (vadp_v2p_hs_is_search_box_enable())
    {
        deinitSearchButton();
    }

    deinitHintBox();

    deinitDateTime();

    deinitIdleModeText();

    deinitNetworkInfo();
    
    deinitWallpaper();

    VappShellPanel::onDeinitView();
}

void VappOp01HsScr::onEnterView()
{
    VappShellPanel::onEnterView();
    
    // suspend wallpaper until bootup initiation finished
    if(s_bootupInit == VFX_TRUE)
    {
        VFX_DEV_ASSERT(m_timerResumeWallpaper == NULL);
        VFX_OBJ_CREATE(m_timerResumeWallpaper, VfxTimer, this);       
        m_timerResumeWallpaper->setStartDelay(1000);
        m_timerResumeWallpaper->m_signalTick.connect(this, &VappOp01HsScr::onResumeWallpaper);
        m_timerResumeWallpaper->start();   
        s_bootupInit = VFX_FALSE;
    }
    else
    {
        resumeLiveWallpaper();
    }

#ifdef __MMI_OP01_DCD_V30__
	if (mmi_dcd_is_switch_on_ext())
	{
	    initDCDBar();
	}
#endif

    gVappOp01HsScrObj = this;
}

void VappOp01HsScr::onExitView(ShellExitCauseEnum cause)
{
#ifdef __MMI_OP01_DCD_V30__
	if (mmi_dcd_is_switch_on_ext())
	{
	    deinitDCDBar();
	}
#endif

    if(m_timerResumeWallpaper)
    {   
        // needs stop timer if timer is not timeout before exit HS
        if(m_timerResumeWallpaper->getIsEnabled())
        {
            m_timerResumeWallpaper->stop();
        }
        VFX_OBJ_CLOSE(m_timerResumeWallpaper);
    }
    suspendLiveWallpaper();

    VappShellPanel::onExitView(cause);

    gVappOp01HsScrObj = NULL;
}


#endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */
