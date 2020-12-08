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
 *  vapp_ncenter.cpp
 *
 * Project:
 * --------
 *  COSMOS Notification Center
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_ncenter_pure_key.h"

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_KEY_ONLY_NCENTER__)

#include "vfx_uc_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_softkey.h"

#include "vapp_ncenter_pure_key_system_cell.h"
#include "vapp_ncenter_pure_key_test_cell.h"
#include "vapp_ncenter_pure_key_quick_setting_cell.h"

#include "vfx_primitive_frame.h"
#include "vapp_launcher_gprot.h"

#include "vcp_global_popup.h"
#include "vapp_platform_context.h"
#include "vapp_ncenter_gprot.h"


extern "C" 
{
    #include "idleGprot.h"
    #include "wgui_categories_util.h"
    #include "mmi_common_app_trc.h"
    #include "vfx_adp_device.h"
    #include "BtcmSrvGprot.h" // for srv_bt_cm_get_power_status
    #include "DtcntSrvIprot.h" // for srv_dtcnt_wlan_init
    #include "mmi_rp_app_ncenter_def.h"
    #include "profilesSrvGprot.h"
    #include "mmi_frm_events_gprot.h"
    #include "GlobalResDef.h"
    #include "custom_events_notify.h"

    #ifdef  __MMI_NSS_SUPPORT__
    #include "NotificationSettingSrvGprot.h" //for NSS
    #endif

    #if defined(__MMI_VUI_COSMOS_CP__)
    #include "mmi_rp_app_cosmos_global_def.h"
    #endif

}


extern "C" void mmi_pen_send_event_to_new_screen(void);
extern "C" void vapp_ncenter_entry_small_screen(void);


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define TRACE(a) VFX_TRACE (a)

#define VAPP_NCENTER_Z_ORDER                    (5500)
#define VAPP_NCENTER_Y_VELOCITY_THRESHOLD       (150)
#define VAPP_NCENTER_INVALID_ID 0xFFFFFFFF


/***************************************************************************** 
 * Class VappNCenter 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNCenter", VappNCenter, VfxControl);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappNCenter);

VappNCenter::VappNCenter() :
    m_panel(NULL),
    m_enterTimer(NULL),
    m_leaveTimeline(NULL),
    m_eventCount(0),
    m_ongoingCount(0),
    m_panelContent(NULL),
    m_topRegion(NULL),
    m_bottomRegion(NULL),
    m_bottomHeight(0),
    m_topHeight(0),
    m_disableLeave(VFX_FALSE),
    m_disableDrag(VFX_FALSE),
    m_isInCallBack(VFX_FALSE),
    m_entered(VFX_FALSE),
    m_isOnAnim(VFX_FALSE),
    m_isDrag(VFX_FALSE),
    m_callbackNoti(NULL),
    m_noTextFrame(NULL),    
    m_quickSettingCell(NULL),
    m_softkeybar(NULL),
    m_darkScreen(NULL),
    m_emptyFrame(NULL),
    m_optionsMenu(NULL),
    m_optionsMenuBg(NULL),
    m_optionsMenuHighlight(NULL),
    m_screen_id(0),
    m_optionItemsNum(0),
    m_optionHighlightIndex(0),
    m_popup(NULL),
    m_popupBg(NULL),
#if !defined(__MMI_BASIC_UI_STYLE__)
    m_popupIcon(NULL),
#endif
    m_popupText(NULL),
    m_list(NULL),
    m_context(NULL),
    m_ncenterScrPtr(NULL),
    m_popupHandle(0),
    m_popupNoti(NULL)
{
    VfxS32 i;

    for (i = 0 ; i < VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM ; i ++)
    {
        m_optionsMenuText[i] = NULL;
        if ( i < VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM - 1)
        {
            m_optionsMenuDivideLine[i] = NULL;
        }
    }
};


#define VAPP_NCENTER_MEM_POOL 2
static VfxU32 g_vappNCenterMemPool[VAPP_NCENTER_MEM_POOL * 1024 / sizeof(VfxU32)];

void VappNCenter::onInit()
{
    VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    m_context->assignPool((VfxU8 *)g_vappNCenterMemPool, VAPP_NCENTER_MEM_POOL * 1024);
     
    VfxControl::onInit();    

    VFX_OBJ_CREATE(m_pAccessKeyMgr, VfxAccessKeyMgr, this);
    
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->addChildFrame(this);
    topLevel->m_signalActiveScreenBeforeEnter.connect(this, &VappNCenter::onActiveScreenEnter);
    topLevel->m_signalActiveScreenExit.connect(this, &VappNCenter::onActiveScreenExit);       

    setSize(getParentFrame()->getSize());
    setHidden(VFX_TRUE);
    setPosZ(VAPP_NCENTER_Z_ORDER);

    
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    nm->m_signalNStatus.connect(this, &VappNCenter::onNotificationChanged);    

}

void VappNCenter::emitEvent(VappNCenterEventEnum event)
{
    m_signalEvent.emit(event);

    mmi_group_event_struct evt;
    switch (event)
    {
        case VAPP_NCENTER_EVENT_ENTER:
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_NCENTER_ENTER);            
        }
            break;
        case VAPP_NCENTER_EVENT_ENTERED:
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_NCENTER_ENTERED);            
        }
            break;
        case VAPP_NCENTER_EVENT_EXIT:
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_NCENTER_EXIT);            
        }
            break;
        case VAPP_NCENTER_EVENT_EXITED:
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_NCENTER_EXITED);            
        }
            break;
        default:
            VFX_ASSERT(0);            
    }

    MMI_FRM_CB_EMIT_EVENT(&evt); //brocast to receiver
    
}


VfxS32 VappNCenter::getOptionsIndexByPos(VfxPoint pos)
{
    VfxS32 ret = -1;
    VfxS32 i;
    VfxS32 y_start = UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y - (VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*m_optionItemsNum);

    if ((pos.x < (VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_TEXT_OFFSET_X)) || (pos.x > (UI_device_width - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X)))
    {
        return -1;
    }

    for (i = 0; i < m_optionItemsNum; i++)
    {
        if ((pos.y > y_start + (i * VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT)) && (pos.y < (y_start + (i + 1) * VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT)))
        {
            ret = i;
            break;
        }
    }
    return ret;
}


VfxBool VappNCenter::optionsMenuPenHandler(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            {
                m_optionHighlightIndex = getOptionsIndexByPos(event.pos);
                if (m_optionHighlightIndex >= 0 && m_optionHighlightIndex < m_optionItemsNum)
                {
                    m_optionsMenuHighlight->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X, 
                        UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*(m_optionItemsNum - m_optionHighlightIndex) - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
                }
            }
            break;
            
        case VFX_PEN_EVENT_TYPE_ABORT:
            {
                
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            {
                if ((isInOptionsMenu() == VFX_TRUE) && 
                    (m_optionHighlightIndex >= 0 && m_optionHighlightIndex < m_optionItemsNum) &&
                    (m_optionHighlightIndex == getOptionsIndexByPos(event.pos)))
                {
                    onEventLsk(VCP_SOFTKEY_UP);
                }
            }
            break;
            
        default:
            break;
    }

    return VFX_TRUE;
}

VfxBool VappNCenter::onPenInput(VfxPenEvent &event)
{   

    //vfx_sys_mem_pool_status_struct output,old;
    //VFX_OBJ_GET_INSTANCE(VappPlatformContext)->statistics(old);

    if (isInRemindPopup() == VFX_TRUE || isInConfirmPopup() == VFX_TRUE)
    {
        return VFX_TRUE;
    }

    if (isInOptionsMenu() == VFX_TRUE)
    {
        return optionsMenuPenHandler(event);
    }
        
    if (m_panel)
    {
        switch (event.type)
        {
            case VFX_PEN_EVENT_TYPE_DOWN:
                {
                    VfxPoint dowmpt = event.getRelDownPos(this);

                    if (m_entered && dowmpt.y < getSize().height - m_bottom->getSize().height)
                    {
                        return VFX_FALSE;
                    }

                    if (m_entered)
                    {                                 
                        emitEvent(VAPP_NCENTER_EVENT_EXIT);
                    }
                    m_isDrag = VFX_TRUE;
                    m_softkeybar->setHidden(VFX_TRUE);

                    
                    m_originY = m_panel->getPos().y + m_panel->getSize().height;
                    
                    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                    topLevel->releaseFocus(m_list); //relase Focus to original holder when pen down

                }
                return VFX_TRUE;
            case VFX_PEN_EVENT_TYPE_ABORT:
            case VFX_PEN_EVENT_TYPE_UP:
                {
                    m_isInCallBack = VFX_FALSE;
                    m_panel->setAutoAnimate(VFX_TRUE);
                    m_bottom->setAutoAnimate(VFX_TRUE);
                    // use velocity to determine leave or not
                    VfxPoint dowmpt = event.getRelDownPos(this);
                    VfxPoint pt     = event.getRelPredictPos(this);
                    VfxS32   yv;
                    
                    if (event.timeStamp == event.downTimeStamp)
                    {
                        // means only tap
                        yv = 0;
                    }
                    else
                    {
                        yv = (1000 * (pt.y - dowmpt.y)) / (event.timeStamp - event.downTimeStamp);
                    }

                    if (yv > VAPP_NCENTER_Y_VELOCITY_THRESHOLD)
                    {
                        m_panel->setPos(0, 0);
                        m_panel->setSize(getSize());
                        setIsDisabled(VFX_TRUE);
                        m_list->setIsDisabled(VFX_TRUE);

                        VFX_OBJ_CREATE(m_enterTimer, VfxTimer, m_panel);
                        m_enterTimer->m_signalTick.connect(this, &VappNCenter::onEnterEnd);
                        m_enterTimer->setStartDelay(VfxAutoAnimate::getDuration());
                        m_enterTimer->start();
                    }
                    else if (yv < -1 * VAPP_NCENTER_Y_VELOCITY_THRESHOLD) 
                    {
                        leave();
                    }
                    else
                    {
                        if (pt.y > 0.5 * getSize().height)
                        {
                                m_panel->setPos(0, 0);
                            m_panel->setSize(getSize());
                            setIsDisabled(VFX_TRUE);
                            m_list->setIsDisabled(VFX_TRUE);

                            VFX_OBJ_CREATE(m_enterTimer, VfxTimer, m_panel);
                            m_enterTimer->m_signalTick.connect(this, &VappNCenter::onEnterEnd);
                            m_enterTimer->setStartDelay(VfxAutoAnimate::getDuration());
                            m_enterTimer->start();
                        }
                        else
                        {
                            leave();
                        }
                    }
                }
                break;
            case VFX_PEN_EVENT_TYPE_MOVE:
                {
                    VfxPoint dowmpt = event.getRelDownPos(this);
                    VfxPoint pt     = event.getRelPos(this);

                    VfxS32 newY = m_originY + (pt.y - dowmpt.y);
                    VfxS32 finalY;

                    VfxAutoAnimate::begin();
                    VfxAutoAnimate::setDisable(VFX_TRUE);

                    VfxS32 marginHeight = m_topHeight + m_bottomHeight;
                    VfxS32 formHeight = VFX_MIN(m_list->getContentSize().height, getSize().height - marginHeight);
                    if (!m_entered)
                    {
                        if(newY <= MMI_STATUS_BAR_HEIGHT)
                        {
                            m_panel->setSize(m_panel->getSize().width, formHeight + m_bottomHeight);
                            finalY = newY - (VAPP_NCENTER_BOTTOM_HEIGHT - MMI_STATUS_BAR_HEIGHT) - m_panel->getSize().height;
                            m_panel->setPos(0, finalY);
                        }
                        else if (newY > MMI_STATUS_BAR_HEIGHT && newY < VAPP_NCENTER_BOTTOM_HEIGHT)
                        {
                            m_panel->setSize(m_panel->getSize().width, marginHeight + formHeight);
                            finalY = newY - m_panel->getSize().height;
                            m_panel->setPos(0, finalY);
                        }
                        else if (newY >= VAPP_NCENTER_BOTTOM_HEIGHT && newY < marginHeight + formHeight && newY < getSize().height)
                        {
                            m_panel->setSize(m_panel->getSize().width, marginHeight + formHeight);
                            finalY = newY - m_panel->getSize().height;
                            m_panel->setPos(0, finalY);
                        }
                        else if (newY >= marginHeight + formHeight && newY < getSize().height)
                        {
                            m_panel->setPos(0, 0);
                            m_panel->setSize(m_panel->getSize().width, newY);
                        }
                        else
                        {
                            if (marginHeight + formHeight > getSize().height)
                            {
                                m_panel->setPos(0, getSize().height - marginHeight - formHeight);
                                m_panel->setSize(m_panel->getSize().width, marginHeight + formHeight);
                            }
                            else
                            {
                                finalY = getSize().height;
                                m_panel->setPos(0, 0);
                                m_panel->setSize(m_panel->getSize().width, finalY);
                            }                         
                        }
                    }
                    else
                    {
                        // only move position if already entered.
                        finalY = newY - m_originY;

                        if (finalY > 0)
                        {
                            finalY = 0;
                        }
                        
                        m_panel->setPos(0, finalY);
                        
                    }

                    VfxAutoAnimate::commit();
                }
                break;
            default:
                break;
        }
    }
    return VFX_TRUE;
}


VfxBool VappNCenter::onKeyInput(VfxKeyEvent &event)
{
    VfxBool ret = VFX_FALSE;

    if ((event.type == VFX_KEY_EVENT_TYPE_DOWN) || (event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (isInMainScreen() == VFX_TRUE)
        {
            switch (event.keyCode)
            {
                case VFX_KEY_CODE_VOL_UP:
                case VFX_KEY_CODE_ARROW_UP:
                {
                    if (m_quickSettingCell->isDisplayFocus() == VFX_FALSE)
                    {
                        if(m_list)
                        {
                            m_list->getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_UP);
                        }

                        /* highlight on the first item and move up */
                        if ((m_list->getLayout()->getFocusItem().group == 0) && (m_list->getLayout()->getFocusItem().pos == -1))
                        {
                            VfxRect rect = m_list->getRect();
                            if (m_quickSettingCell->isDisplayFocus() == VFX_FALSE)
                            {
                                m_quickSettingCell->setDisplayFocus(VFX_TRUE);
                                m_quickSettingCell->setFocusIndex(VappQuickSettingCell::VAPP_QSETTING_TOTAL - 2);
                            }
                            m_list->makeVisible(rect ,VFX_TRUE);
                        }
                    }
                    else
                    {
                        if (m_list && (m_eventCount + m_ongoingCount) > 0)
                        {
                            if (m_list->getLayoutNCenter()->getNextFocusItem((m_list->getLayout()->getCellCount(0) - 1), VcpBaseMenuLayout::NAV_DIR_UP) != (-1))
                            {
                                m_quickSettingCell->setDisplayFocus(VFX_FALSE);
                                m_list->getLayout()->setFocusItem(VcpMenuPos(0, (m_list->getLayout()->getCellCount(0))), VFX_TRUE);
                            }
                        }

                        if(m_list)
                        {
                            m_list->getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_UP);
                        }
                    }

                    ret = VFX_TRUE;
                }
                    break;

                case VFX_KEY_CODE_VOL_DOWN:
                case VFX_KEY_CODE_ARROW_DOWN:
                {
                    if (m_list && (m_eventCount + m_ongoingCount) > 0)
                    {
                        if ((m_list->getLayout()->getCellCount(0) - 1) == (m_list->getLayout()->getFocusItem().pos))
                        {
                            m_list->getLayout()->clearFocusItem();

                            VfxRect rect = m_list->getRect();
                            if (m_quickSettingCell->isDisplayFocus() == VFX_FALSE)
                            {
                                m_quickSettingCell->setDisplayFocus(VFX_TRUE);
                                m_quickSettingCell->setFocusIndex(0);
                            }
                            m_list->makeVisible(rect ,VFX_TRUE);
                        }
                        else
                        {
                            if(m_list)
                            {
                                m_list->getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_DOWN);
                            }   

                            if (m_list->getLayout()->getFocusItem().pos == -1)
                            {
                                m_list->getLayout()->clearFocusItem();

                                VfxRect rect = m_list->getRect();
                                if (m_quickSettingCell->isDisplayFocus() == VFX_FALSE)
                                {
                                    m_quickSettingCell->setDisplayFocus(VFX_TRUE);
                                    m_quickSettingCell->setFocusIndex(0);
                                }
                                m_list->makeVisible(rect ,VFX_TRUE);
                            }
                            else
                            {
                                if (m_quickSettingCell->isDisplayFocus() == VFX_TRUE)
                                {
                                    m_quickSettingCell->setDisplayFocus(VFX_FALSE);
                                }
                            }
                        }
                    }
                    ret = VFX_TRUE;
                }
                    break;

                case VFX_KEY_CODE_ARROW_LEFT:
                case VFX_KEY_CODE_ARROW_RIGHT:
                {
                    if (m_quickSettingCell->isDisplayFocus() == VFX_TRUE)
                    {
                        m_quickSettingCell->moveFocus(event.keyCode);
                        ret = VFX_TRUE;
                    }
                }
                    break;

                default:
                    break;        
            }

            /* change softkey */
            if (m_quickSettingCell->isDisplayFocus() == VFX_TRUE)
            {
                VfxResId lsk_id = m_quickSettingCell->getLSKStringID();
                m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(lsk_id), VFX_IMAGE_SRC_NULL);
            }
            else
            {
                m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
            }
        }
        else if (isInOptionsMenu() == VFX_TRUE)
        {
            switch (event.keyCode)
            {
                case VFX_KEY_CODE_VOL_UP:
                case VFX_KEY_CODE_ARROW_UP:
                {
                    optionsMenuItemMoveUp();
                    ret = VFX_TRUE;
                }
                    break;

                case VFX_KEY_CODE_VOL_DOWN:
                case VFX_KEY_CODE_ARROW_DOWN:
                {
                    optionsMenuItemMoveDown();
                    ret = VFX_TRUE;
                }
                    break;

                default:
                    break;        
            }
        }
    }
    else if (event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        if (event.keyCode == VFX_KEY_CODE_BACK)
        {
            leave();            
            ret = VFX_TRUE;
        }
    }
    if (ret == VFX_FALSE)
    {
        ret = VfxControl::onKeyInput(event);
    }

    return ret;
}

void VappNCenter::enter()
{
/*
    if (m_ghandle == NULL)
    {
        m_ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_NCENTER);
        m_nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING, m_ghandle, 0);
        vsrv_ncenter_set_ngroup_title_id(m_ghandle, (S32)STR_ID_VAPP_NCENTER_ONGOING);
        vsrv_ncenter_notify_notification(m_nhandle); 
    }
*/

    // hidden = true and no object is requesting leave
    if (getHidden() != VFX_FALSE && !m_callbackNoti)
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_ENTER);
        
        vfx_adp_srs_pause();
        

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        emitEvent(VAPP_NCENTER_EVENT_ENTER); // Entering NCenter
        
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->addChildFrame(this);
        setSize(getParentFrame()->getSize());     
        createSystemView();
        setHidden(VFX_FALSE);
        
        
        VfxS32 initHeight = getSize().height;
        if(m_list)
        {
            initHeight = VFX_MIN(initHeight, m_topHeight + m_list->getContentSize().height + m_bottomHeight);
        }
        
        m_panel->setSize(m_panel->getSize().width, initHeight);
        m_panel->setPos(VfxPoint(0, m_bottom->getSize().height - m_panel->getSize().height));
        m_list->setIsUnhittable(VFX_TRUE);

        capture();
        VfxAutoAnimate::commit();    

       
    }
}

void VappNCenter::leave()
{
    if (getHidden() == VFX_FALSE && m_panel)
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_LEAVE);

        setIsDisabled(VFX_TRUE);

        VFX_OBJ_CREATE(m_leaveTimeline, VfxPointTimeline, m_panel);



        m_leaveTimeline->setTarget(m_panel);
        m_leaveTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_leaveTimeline->setDurationTime(250);

        m_leaveTimeline->setIsFromCurrent(VFX_TRUE);
        m_leaveTimeline->setToValue(VfxPoint(0, 0 - m_panel->getSize().height));
        m_leaveTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_leaveTimeline->m_signalStopped.connect(this, &VappNCenter::onLeaveEnd); 
        m_leaveTimeline->start();

        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->releaseFocus(m_list);

        //timer new feature
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->blockAfterNextCommit(250, VfxCallback0(this, &VappNCenter::leaveInternal));

        m_softkeybar->setHidden(VFX_TRUE);

    }
/*
    if (m_ghandle)
    {
        vsrv_ncenter_close_ngroup(m_ghandle);
        vsrv_ncenter_close_notification(m_nhandle);
        m_ghandle = NULL;
        m_nhandle = NULL;
    }
*/
}


void VappNCenter::onLeaveEnd(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_ON_LEAVE_END);
    if (isCompleted) // if not completed, that means m_leaveTimeline's parent is closed
    {
        VFX_OBJ_CLOSE(m_leaveTimeline);
    }
}


void VappNCenter::onEnterEnd(VfxTimer *source)
{
    VFX_OBJ_CLOSE(m_enterTimer);
    
    if (getHidden() == VFX_FALSE)
    {
        VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
        nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_ENTERED, VSRV_NOTIFICATION_TYPE_CUSTOM);
        
        emitEvent(VAPP_NCENTER_EVENT_ENTERED);

        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->captureFocus(m_list); //key support
    
        m_list->setIsUnhittable(VFX_FALSE);
        m_list->setIsDisabled(VFX_FALSE);

        //restore cache mode                  
        VcpMenuRegionIter   itr(m_list->getLayout(), m_list->getRealContentRegion());
        while(!itr.isEnd())
        {
            VcpMenuPos p = itr.next();
            VfxFrame* c = m_list->getCellIfPresent(p.group, p.pos);       
            if (c)
            {
                c->setCacheMode(VFX_CACHE_MODE_AUTO);                       
            }
        }        

        setIsDisabled(VFX_FALSE);
        m_entered = VFX_TRUE;
        m_isDrag = VFX_FALSE;    
        m_softkeybar->setHidden(VFX_FALSE);
    }
}


void VappNCenter::onEventClearAll(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_ON_EVENT_CLEAR_ALL);
    VFX_UNUSED(sender);
    VFX_UNUSED(id);

    VfxList <VsrvNotification*> intentList;
    intentList.init(m_panel);

    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    VfxList <VsrvNGroup*>::It it;    
    for (it = nm->getNGroups(); !it.isNull(); ++it)  
    {                 
        VsrvNGroup* group = *it;        
        VfxList <VsrvNotification*>::It itt;        
        for (itt = group->getNotifications(); !itt.isNull(); ++itt)
        {
            VsrvNotification *noti = *itt;
            if (checkNotification(noti))
            {
                intentList.pushBack(noti);
            }                                                            
         }
     }                 
    
    VfxList <VsrvNotification*>::It itt;
    for (itt = intentList.begin(); !itt.isNull(); ++itt)
    {
        VsrvNotification* noti = *itt;
        VfxBool autoClose = noti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_CLEAR);
        nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLEAR, noti);
        if (autoClose)
        {
            nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, noti);
            VSRV_NOTIFICATION_CLOSE(noti);
        }        
    }    

    
}


vrt_allocator_handle VappNCenter::getAllocator()
{
    return m_context->getAllocator();
}

void VappNCenter::onEventLsk(VcpSoftkeyEventEnum event_type)
{
    VsrvNotification* noti = NULL;
    VsrvNotificationOngoing* noti_ongoing = NULL;
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);   
    VfxS32 item_idx;

    // select the options menu item     
    item_idx = m_list->getLayout()->getFocusItem().pos;
    if (item_idx >= 0)
    {
        noti = (VsrvNotification*)m_list->getItemId(item_idx);
    }

    if ((isInConfirmPopup() == VFX_TRUE) && (event_type == VCP_SOFTKEY_UP))
    {
        if (m_quickSettingCell->isDisplayFocus() == VFX_TRUE)
        {
#ifdef __MMI_WLAN_FEATURES__
            if ((m_quickSettingCell->getFocusIndex() + 1) == VappQuickSettingCell::VAPP_QSETTING_WIFI)
            {
                VappQuickSettingElement* element = m_quickSettingCell->findElementById(VappQuickSettingCell::VAPP_QSETTING_WIFI);
                element->showProcessInd();
                srv_dtcnt_wlan_init(NULL, NULL);
            }
#endif
#ifdef __MMI_BT_SUPPORT__
            if ((m_quickSettingCell->getFocusIndex() + 1) == VappQuickSettingCell::VAPP_QSETTING_BT)
            {
                VappQuickSettingElement* element = m_quickSettingCell->findElementById(VappQuickSettingCell::VAPP_QSETTING_BT);
                if (element->getCurrentIndicator() == 0)
                {
                    srv_bt_cm_switch_on(); 
                }
                else
                {
                    srv_bt_cm_switch_off();
                }
            }
#endif
            closePopup();
        }
        else
        {
            if (m_optionHighlightIndex == 1) //clesr notifacation item || close on-going item 
            {
                VfxBool autoClose = noti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE);
                closePopup();

                if (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING)
                {
                    vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_TERMINATE, noti);
                }
                else
                {
                    vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLEAR, noti);
                }
                if (autoClose)
                {
                    vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, noti);
                    VSRV_NOTIFICATION_CLOSE(noti);
                } 

                if (!m_panel)
                {
                    return;
                }
                
                // set highlight
                if (m_quickSettingCell)
                {
                    m_quickSettingCell->setDisplayFocus(VFX_TRUE);
                    m_quickSettingCell->setFocusIndex(0);
                }
                if (m_list)
                {
                    m_list->getLayout()->setFocusItem(VcpMenuPos(0, -1), VFX_FALSE);
                }
                if (m_softkeybar)
                {
                    m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(m_quickSettingCell->getLSKStringID()), VFX_IMAGE_SRC_NULL);
                }

                if (m_list && (m_eventCount + m_ongoingCount) > 0)
                {
                    m_list->getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_DOWN);
                    m_quickSettingCell->setDisplayFocus(VFX_FALSE);
                    m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
                }

            }
            else if ((m_optionHighlightIndex == 2) && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT))
            {
                onEventClearAll(NULL, 0);
                closePopup();
                
                // set highlight
                m_quickSettingCell->setDisplayFocus(VFX_TRUE);
                m_quickSettingCell->setFocusIndex(0);
                m_list->getLayout()->setFocusItem(VcpMenuPos(0, -1), VFX_FALSE);
                m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(m_quickSettingCell->getLSKStringID()), VFX_IMAGE_SRC_NULL);

                if (m_list && (m_eventCount + m_ongoingCount) > 0)
                {
                    m_list->getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_DOWN);
                    m_quickSettingCell->setDisplayFocus(VFX_FALSE);
                    m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
                }
            }
        }
    }
    else if ((isInRemindPopup() == VFX_TRUE) && (event_type == VCP_SOFTKEY_UP))
    {
        closePopup();
    }
    else if ((isInOptionsMenu() == VFX_TRUE) && (event_type == VCP_SOFTKEY_UP))
    {
        if (noti && nm->checkNotification(noti))
        {
            if (m_optionHighlightIndex == 0) //open
            {
                m_list->clearFocusItem();       
                if (noti->getAutoLaunch())
                {
                    requestLeave(noti);
                }
                else
                {
                    VfxBool autoClose = noti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TAP);
                    vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_TAP, noti);
                    if (autoClose)
                    {
                        vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, noti);
                        VSRV_NOTIFICATION_CLOSE(noti);
                    }
                }
                closeOptionsMenu();
            }
            else if (m_optionHighlightIndex == 1) //clesr notifacation item || close on-going item 
            {
                closeOptionsMenu();
                if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
                {
                    showPopup(VFX_WSTR_RES(STR_ID_VAPP_NCENTER_CLEAR_ASK), IMG_GLOBAL_QUESTION, STR_GLOBAL_YES, STR_GLOBAL_NO, VAPP_NCENTER_CONFIRM_POPUP);
                }
                else if (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING)
                {
                    noti_ongoing = (VsrvNotificationOngoing*)noti;
                    showPopup(noti_ongoing->getQuestionText(), IMG_GLOBAL_QUESTION, STR_GLOBAL_YES, STR_GLOBAL_NO, VAPP_NCENTER_CONFIRM_POPUP);
                }
            }
            else if ((m_optionHighlightIndex == 2) && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT))
            {
                closeOptionsMenu();
                showPopup(VFX_WSTR_RES(STR_ID_VAPP_NCENTER_CLEAR_ALL_ASK), IMG_GLOBAL_QUESTION, STR_GLOBAL_YES, STR_GLOBAL_NO, VAPP_NCENTER_CONFIRM_POPUP);
            }
        }
    }
    else if (event_type == VCP_SOFTKEY_UP) 
    {
        if (m_quickSettingCell->isDisplayFocus() == VFX_TRUE)// on quick setting
        {
            m_quickSettingCell->changeFocusItemState();
        }
        else
        {
            item_idx = m_list->getLayout()->getFocusItem().pos;
            if (item_idx >= 0)
            {
                noti = (VsrvNotification*)m_list->getItemId(item_idx);
            }
            if (noti)
            {
                if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
                {
                    showOptionsMenu(VAPP_NCENTER_OPTIONS_MENU_TYPE_3);
                }
                else if (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING)
                {
                    showOptionsMenu(VAPP_NCENTER_OPTIONS_MENU_TYPE_2);
                }
                m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_SELECT), VFX_IMAGE_SRC_NULL);
            }
        }
    }

}


void VappNCenter::onEventCsk(VcpSoftkeyEventEnum event_type)
{
    if (event_type == VCP_SOFTKEY_UP)
    {
        if ((isInConfirmPopup() == VFX_TRUE) || (isInRemindPopup() == VFX_TRUE) || 
            (isInOptionsMenu() == VFX_TRUE) || (m_quickSettingCell->isDisplayFocus() == VFX_TRUE))
        {
            onEventLsk(event_type);
        }
        else
        {
            m_screen_id = VAPP_NCENTER_OPTION_SCREEN;
            m_optionHighlightIndex = 0;
            onEventLsk(event_type);
            m_screen_id = VAPP_NCENTER_MAIN_SCREEN;
        }
    }
}


void VappNCenter::onEventRsk(VcpSoftkeyEventEnum event_type)
{
    if (isInConfirmPopup() == VFX_TRUE)
    {
        if (event_type == VCP_SOFTKEY_UP)
        {
            closePopup();
        }
    }
    else if (isInOptionsMenu() == VFX_TRUE)
    {
        if (event_type == VCP_SOFTKEY_UP)
        {
            closeOptionsMenu();
        }
    }
    else if (isInRemindPopup() == VFX_FALSE)
    {
        if (event_type == VCP_SOFTKEY_UP && m_isOnAnim == VFX_FALSE)
        {
            leave(); 
        }
    }
}



void VappNCenter::createSystemView()
{
    VfxS32 i = 0;
    
    m_screen_id = VAPP_NCENTER_MAIN_SCREEN;
    
    VFX_DEV_ASSERT(m_panel == NULL);
    
    VFX_OBJ_CREATE(m_panel, VfxFrame, m_ncenterScrPtr.get());
    addChildFrame(m_panel);

    m_panel->setBgColor(VAPP_NCENTER_CLR_BACKGROUND);
    m_panel->setSize(getSize().width, getSize().height);
    m_panel->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_panel->setAutoAnimate(VFX_TRUE);
   

    VFX_OBJ_CREATE(m_topRegion, VfxFrame, m_panel);
    m_topRegion->setSize(m_panel->getSize());

    VfxS32 h = onCreateContentTop(m_topRegion);
    if(h>0)
    {
        m_topRegion->setPos(0, 0);
        m_topRegion->setSize(m_panel->getSize().width, h);
        m_topRegion->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
        m_topHeight = h;
        h = -1;
    }

    m_bottomHeight = 0;

    VFX_OBJ_CREATE(m_bottomRegion, VfxFrame, m_panel);
    m_bottomRegion->setSize(m_panel->getSize());
    h = onCreateContentBottom(m_bottomRegion);
    if(h)
    {
        m_bottomRegion->setAnchor(0, 1);        
        m_bottomRegion->setPos(0, m_panel->getSize().height - VAPP_NCENTER_BOTTOM_HEIGHT);
        m_bottomRegion->setSize(m_panel->getSize().width, VAPP_NCENTER_BOTTOM_HEIGHT);
        m_bottomRegion->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_bottomHeight += h;
    }    


    // bottom 
    VFX_OBJ_CREATE(m_bottom, VfxFrame, m_panel);
    m_bottom->setPos(0, m_panel->getSize().height - VAPP_NCENTER_BOTTOM_HEIGHT);
    m_bottom->setSize(getSize().width, VAPP_NCENTER_BOTTOM_HEIGHT);
    m_bottom->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bottom->setImgContent(VfxImageSrc(VAPP_IMG_NCENTER_DRAG_BAR_BG));
    m_bottom->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);


    VFX_OBJ_CREATE(m_bottomImage, VfxImageFrame, m_bottom);
    m_bottomImage->setAnchor(0.5f, 0.5f);
    m_bottomImage->setPos(m_bottom->getSize().width/2, m_bottom->getSize().height/2);
    m_bottomImage->setSize(getSize().width, VAPP_NCENTER_BOTTOM_HEIGHT);
    m_bottomImage->setResId(VAPP_IMG_NCENTER_DRAG_BAR);
    m_bottomImage->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_MID);

    m_bottomHeight += VAPP_NCENTER_BOTTOM_HEIGHT;

    VFX_OBJ_CREATE(m_panelContent, VfxFrame, m_panel);
    m_panelContent->setAutoAnimate(VFX_TRUE);   
    m_panelContent->setPos(0, m_topHeight);    
    m_panelContent->setSize(m_panel->getSize().width, m_panel->getSize().height - m_topHeight - m_bottomHeight);
    m_panelContent->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);    

    onCreateContentView(m_panelContent);

    if (m_list && (m_eventCount + m_ongoingCount) > 0)
    {
        m_list->getLayout()->setFocusItem(VcpMenuPos(0, 1), VFX_FALSE);
    }
    else
    {
        m_quickSettingCell->setDisplayFocus(VFX_TRUE);
        m_quickSettingCell->setFocusIndex(0);
    }

    // softkey
    VFX_OBJ_CREATE(m_softkeybar, VcpSoftkey, m_bottom);
    m_softkeybar->setPos(VfxPoint(0, 1));
    m_softkeybar->setBounds(VfxRect(0, 0, UI_device_width, VAPP_NCENTER_BOTTOM_HEIGHT - 1));
    m_softkeybar->getCallback(VCP_SOFTKEY_LSK).connect(this, &VappNCenter::onEventLsk);
    m_softkeybar->getCallback(VCP_SOFTKEY_RSK).connect(this, &VappNCenter::onEventRsk);
    m_softkeybar->getCallback(VCP_SOFTKEY_CSK).connect(this, &VappNCenter::onEventCsk);
    m_softkeybar->setSoftkeyWidth(VCP_SOFTKEY_LSK, VAPP_NCENTER_SOFTKEY_WIDTH - (m_softkeybar->getBorderGap() + m_softkeybar->getShiftOffset()));
    m_softkeybar->setSoftkeyWidth(VCP_SOFTKEY_RSK, VAPP_NCENTER_SOFTKEY_WIDTH - m_softkeybar->getBorderGap());
    m_softkeybar->setBorderGap(VAPP_NCENTER_SOFTKEY_BAR_GAP);
    m_softkeybar->setHidden(VFX_TRUE);
    
    if ((m_eventCount + m_ongoingCount) > 0)
    {
        m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
    }
    else
    {
        m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(m_quickSettingCell->getLSKStringID()), VFX_IMAGE_SRC_NULL);
    }
    m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_GLOBAL_BACK), VFX_IMAGE_SRC_NULL);

    m_softkeybar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_softkeybar->setFont(VfxFontDesc(VAPP_NCENTER_SOFTKEY_FONT_SIZE));

    // option list
    VFX_OBJ_CREATE(m_darkScreen, VfxFrame, m_panel);
    m_darkScreen->setPos(VfxPoint(0, 0));
    m_darkScreen->setBounds(VfxRect(0, 0, UI_device_width, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT));
    m_darkScreen->setBgColor(VFX_COLOR_BLACK);
    m_darkScreen->setOpacity(0.5f);
    m_darkScreen->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_optionsMenu, VfxFrame, m_panel);
    m_optionsMenu->setPos(VfxPoint(0, 0));
    m_optionsMenu->setBounds(VfxRect(0, 0, UI_device_width, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT));
    m_optionsMenu->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_optionsMenuBg, VfxImageFrame, m_optionsMenu);
    m_optionsMenuBg->setResId(VAPP_IMG_NCENTER_OPTIONS_MENU_BG);
    m_optionsMenuBg->setOpacity(0.9f);
    m_optionsMenuBg->setPos(VfxPoint(0, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - 
        VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y*2));
    m_optionsMenuBg->setSize(UI_device_width, VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM + VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y*2);
    m_optionsMenuBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_optionsMenuHighlight, VfxImageFrame, m_optionsMenu);
    m_optionsMenuHighlight->setResId(VAPP_IMG_NCENTER_LIST_HIGHLIGHT_BACKGROUND);
    m_optionsMenuHighlight->setOpacity(0.9f);
    m_optionsMenuHighlight->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - 
        VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
    m_optionsMenuHighlight->setSize(UI_device_width - (VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X)*2, VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT - 1);
    m_optionsMenuHighlight->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    for (i = 0 ; i < VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM ; i++)
    {
        if ( i < VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM - 1)
        {
            VFX_OBJ_CREATE(m_optionsMenuDivideLine[i], VfxFrame, m_optionsMenu);
            m_optionsMenuDivideLine[i]->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X,UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - 
                VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*(VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM - i - 1) - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
            m_optionsMenuDivideLine[i]->setSize(UI_device_width - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X*2, 1);
            m_optionsMenuDivideLine[i]->setBgColor(VFX_COLOR_GREY);
            m_optionsMenuDivideLine[i]->setOpacity(0.7f);
            m_optionsMenuDivideLine[i]->setHidden(VFX_FALSE);
        }

        VFX_OBJ_CREATE(m_optionsMenuText[i], VfxTextFrame, m_optionsMenu);
        m_optionsMenuText[i]->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_TEXT_OFFSET_X,
            UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*(VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM - i) - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
        m_optionsMenuText[i]->setSize(UI_device_width - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X*2, VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT);
        m_optionsMenuText[i]->setAutoResized(VFX_FALSE);
        m_optionsMenuText[i]->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
        m_optionsMenuText[i]->setVerticalToCenter(VFX_TRUE);
        m_optionsMenuText[i]->setColor(VFX_COLOR_WHITE);
        m_optionsMenuText[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_OPTIONS_MENU_FONT_SIZE)));
    }

    // confirm popup
    VFX_OBJ_CREATE(m_popup, VfxFrame, m_panel);
    m_popup->setPos(VfxPoint(0, 0));
    m_popup->setBounds(VfxRect(0, 0, UI_device_width, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT));
    m_popup->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_popupBg, VfxImageFrame, m_popup);
    m_popupBg->setResId(VAPP_IMG_NCENTER_OPTIONS_MENU_BG);
    m_popupBg->setOpacity(0.9f);
    m_popupBg->setPos(VfxPoint(0, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - 
        VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*4 - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y*3));
    m_popupBg->setSize(UI_device_width, VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*4 + VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y*3);
    m_popupBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

#if !defined(__MMI_BASIC_UI_STYLE__)
    VFX_OBJ_CREATE(m_popupIcon, VfxAnimImageFrame, m_popup);
    m_popupIcon->setOpacity(0.9f);
    m_popupIcon->setPos(VfxPoint(0, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - 
        VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*4 - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y * 2));
    m_popupIcon->setSize(UI_device_width, VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*2);
#endif

    VFX_OBJ_CREATE(m_popupText, VfxTextFrame, m_popup);
    m_popupText->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_TEXT_OFFSET_X,
        UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*2));
    m_popupText->setSize(UI_device_width - (VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_TEXT_OFFSET_X)*2, VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*2);
    m_popupText->setAutoResized(VFX_FALSE);
    m_popupText->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_popupText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_popupText->setVerticalToCenter(VFX_TRUE);
    m_popupText->setColor(VFX_COLOR_WHITE);
    m_popupText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_OPTIONS_MENU_FONT_SIZE)));

    // empty frame
    VFX_OBJ_CREATE(m_emptyFrame, VfxFrame, m_panel);
    m_emptyFrame->setPos(VfxPoint(VAPP_NCENTER_SOFTKEY_WIDTH, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT));
    m_emptyFrame->setBounds(VfxRect(VAPP_NCENTER_SOFTKEY_WIDTH, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT,
        UI_device_width - VAPP_NCENTER_SOFTKEY_WIDTH*2, VAPP_NCENTER_BOTTOM_HEIGHT));
    m_emptyFrame->setOpacity(0.0f);
    m_emptyFrame->setHidden(VFX_FALSE);
}
    

VfxS32 VappNCenter::onCreateContentTop(VfxFrame* parent)
{
    VcpStatusIconBar *statusBar;
    VFX_OBJ_CREATE(statusBar, VcpStatusIconBar, parent);
    statusBar->setBgColor(VFX_COLOR_WHITE);
    statusBar->setSize(getSize().width, MMI_STATUS_BAR_HEIGHT); 

    return MMI_STATUS_BAR_HEIGHT;
}


VfxS32 VappNCenter::onCreateContentBottom(VfxFrame* parent)
{
    return -1; 
}

void VappNCenter::onCreateContentView(VfxFrame* parent)
{    
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_CONTENT, 0);

    VFX_ASSERT(m_list == NULL);      
        
    VFX_OBJ_CREATE(m_list, VappNCenterList, parent);
    m_list->setPos(0, 0);
    m_list->setSize(m_panelContent->getSize());
    m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->getFirstChildFrame()->setCacheMode(VFX_CACHE_MODE_PREVENT_PARENTS);

    VFX_OBJ_CREATE(m_quickSettingCell, VappQuickSettingCell, parent);
    m_quickSettingCell->setSize(getSize().width, m_quickSettingCell->getSize().height);
    m_list->addMarginItem(VCP_BASE_MENU_MARGIN_AREA_TOP, VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL, m_quickSettingCell);

    VfxList <VappNCenterGroupStruct> grouplist;
    grouplist.init(parent);

    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    VfxList <VsrvNGroup*>::It it;    
                    
    for (it = nm->getNGroups(); !it.isNull(); ++it)  
    {
        VsrvNGroup* group = *it;
        VfxList <VsrvNotification*>::It itt;        
        for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
        {
            VsrvNotification *noti = *itt;
            if (checkNotification(noti))
            {                    
                VfxList <VappNCenterGroupStruct>::It ittt;        
                for (ittt = grouplist.begin(); !ittt.isNull(); ++ittt)
                {
                    VappNCenterGroupStruct data = *ittt;                        
                    VfxDateTime::CompareEnum result = noti->getTimeStamp().compareWith(data.groupTimeStamp);
                    if (result != VfxDateTime::LESS)
                    {
                        break;             
                    }                         
                }

                VappNCenterGroupStruct data;
                data.group = group;
                data.groupTimeStamp = noti->getTimeStamp();

                if (ittt.isNull())
                {
                    grouplist.pushBack(data);
                }
                else
                {
                    grouplist.insert(ittt, data);        
                }
                break;
                
            }                
        }            
    }

    VfxId refId = VAPP_NCENTER_INVALID_ID;
    VfxId curOngoingNotiId = VAPP_NCENTER_INVALID_ID;
    VfxList <VappNCenterGroupStruct>::It ittt;

    m_ongoingId = VAPP_NCENTER_INVALID_ID;

/*
    for (ittt = grouplist.begin(); !ittt.isNull(); ++ittt)
    {
        VappNCenterGroupStruct gdata = *ittt;                        
        VsrvNGroup* group = gdata.group;

        if (APP_NCENTER == group->getId())
        {
            if (group->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
            {
                VappNCenterListCellStruct data;
                data.timeStamp = gdata.groupTimeStamp;
                data.type = VAPP_NCENTER_LIST_CELL_TYPE_HEADER;                        
                m_list->addItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
                m_ongoingId = (VfxId)group;
                
                MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_HEADER, group, group->getId(), group->getType());
                break;
            }
        }
    }
*/
    ittt = grouplist.begin();
    if (!ittt.isNull())
    {
        VappNCenterGroupStruct gdata = *ittt;                        

        VappNCenterListCellStruct data;
        data.timeStamp = gdata.groupTimeStamp;
        data.type = VAPP_NCENTER_LIST_CELL_TYPE_HEADER;                        
        m_list->addItem((VfxId)APP_NCENTER, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
        m_ongoingId = (VfxId)APP_NCENTER;
    }

    for (ittt = grouplist.begin(); !ittt.isNull(); ++ittt)
    {
        VappNCenterGroupStruct gdata = *ittt;                        
        VsrvNGroup* group = gdata.group;
        VfxBool isNotOnging = VFX_FALSE;

        if (APP_NCENTER != group->getId())
        {
            if (group->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
            {
                VappNCenterListCellStruct data;
                VfxList <VsrvNotification*>::It itt;

                data.timeStamp = gdata.groupTimeStamp;
                data.type = VAPP_NCENTER_LIST_CELL_TYPE_HEADER;    
                itt = group->getNotifications();
                if (!itt.isNull())
                {
                    VsrvNotification *noti = *itt;
                    if (checkNotification(noti) && (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING) && (m_ongoingId != VAPP_NCENTER_INVALID_ID))
                    {
                        if (curOngoingNotiId != VAPP_NCENTER_INVALID_ID)
                        {
                            m_list->addItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
                            refId = curOngoingNotiId;
                        }
                        else
                        {
                            m_list->addItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
                            refId = m_ongoingId;
                        }
                    }
                    else if (checkNotification(noti) && (noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM) && (m_ongoingId != VAPP_NCENTER_INVALID_ID))
                    {
                        VsrvNotificationCustom* cust = (VsrvNotificationCustom*)noti; 
                        if (cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING)
                        {
                            if (curOngoingNotiId != VAPP_NCENTER_INVALID_ID)
                            {
                                m_list->addItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
                                refId = curOngoingNotiId;
                            }
                            else
                            {
                                m_list->addItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
                                refId = m_ongoingId;
                            }
                        }
                        else
                        {
                            m_list->addItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
                            refId = (VfxId)group;
                        }
                    }
                    else
                    {
                        m_list->addItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
                        refId = (VfxId)group;
                    }
                }

                MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_HEADER, group, group->getId(), group->getType());
            }
            
            VfxList <VsrvNotification*>::It itt;
            for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
            {
                VsrvNotification *noti = *itt;
                if (checkNotification(noti))
                {
                    if ((noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING) && (m_ongoingId != VAPP_NCENTER_INVALID_ID))
                    {
                        if (curOngoingNotiId != VAPP_NCENTER_INVALID_ID)
                        {
                            refId = curOngoingNotiId;
                        }
                        else if (m_ongoingId != VAPP_NCENTER_INVALID_ID)
                        {
                            refId = m_ongoingId;
                        }
                        createCell(noti, refId);
                        refId = (VfxId) noti;    
                        curOngoingNotiId = (VfxId) noti;
                        m_ongoingId = (VfxId) noti;
                    }
                    else if ((noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM) && (m_ongoingId != VAPP_NCENTER_INVALID_ID))
                    {
                        VsrvNotificationCustom* cust = (VsrvNotificationCustom*)noti; 
                        if (cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING)
                        {
                            if (curOngoingNotiId != VAPP_NCENTER_INVALID_ID)
                            {
                                refId = curOngoingNotiId;
                            }
                            else if (m_ongoingId != VAPP_NCENTER_INVALID_ID)
                            {
                                refId = m_ongoingId;
                            }
                            createCell(noti, refId);
                            refId = (VfxId) noti;    
                            curOngoingNotiId = (VfxId) noti;
                            m_ongoingId = (VfxId) noti;
                        }
                        else
                        {
                            createCell(noti, (VfxId)group);
                            isNotOnging = VFX_TRUE;
                        }
                    }
                    else
                    {
                        createCell(noti, (VfxId)group);
                        isNotOnging = VFX_TRUE;
                    }
                }                            
            }     

            if (isNotOnging == VFX_FALSE)
            {
                m_list->removeItem((VfxId)group);
            }
            else
            {
                isNotOnging = VFX_FALSE;
            }
        }
    }

    if ((m_ongoingCount <= 0) && (m_ongoingId != VAPP_NCENTER_INVALID_ID))
    {
        m_list->removeItem((VfxId)m_ongoingId);
    }

    if (m_eventCount + m_ongoingCount > 0)
    {
        if (m_noTextFrame)
        {
            m_list->removeMarginItem(m_noTextFrame);
            VFX_OBJ_CLOSE(m_noTextFrame);
        } 
    }
    else
    {
        createNoTextFrame();
    }

    if (m_entered)
    {        
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->captureFocus(m_list); //key support
    }

}


void VappNCenter::createNoTextFrame()
{
    if (!m_noTextFrame)
    {
        VFX_OBJ_CREATE(m_noTextFrame, VfxTextFrame, m_list);
        m_noTextFrame->setString(VFX_WSTR_RES(STR_ID_VAPP_NCENTER_NO_NOTIFICATION));
        

    #if defined(__MMI_VUI_COSMOS_CP__)
        m_noTextFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
        m_noTextFrame->setFont(VFX_FONT_RES(FNT_COSMOS_TEXT_EMPTY));            
    #else /* defined(__MMI_VUI_COSMOS_CP__) */
        m_noTextFrame->setColor(VFX_COLOR_GREY);
    #endif /* defined(__MMI_VUI_COSMOS_CP__) */
        
        m_noTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);    
        m_noTextFrame->setSize(getSize().width, VAPP_NCENTER_EVENT_CELL_HEIGHT);
        m_noTextFrame->setVerticalToCenter(VFX_TRUE);
        m_noTextFrame->setAutoResized(VFX_FALSE);
        m_noTextFrame->setAutoAnimate(VFX_TRUE);
        m_list->addMarginItem(VCP_BASE_MENU_MARGIN_AREA_BOTTOM, VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL, m_noTextFrame); 
    }    
}



void VappNCenter::onCloseContentView(void)
{ 
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_CONTENT, 0);

    VFX_OBJ_CLOSE(m_noTextFrame);
    m_eventCount = 0;
    VFX_OBJ_CLOSE(m_quickSettingCell); 
    m_ongoingCount = 0; 

    if (m_list)
    {
       VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
       topLevel->releaseFocus(m_list);
    }
    VFX_OBJ_CLOSE(m_list);   
}

void VappNCenter::releaseSystemView()
{
    VfxS32 i;

    onCloseContentView();
    
    VFX_OBJ_CLOSE(m_leaveTimeline);
    VFX_OBJ_CLOSE(m_panelContent); 
    VFX_OBJ_CLOSE(m_softkeybar);
    for (i = 0 ; i < VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM ; i ++)
    {
        VFX_OBJ_CLOSE(m_optionsMenuText[i]);
        if ( i < VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM - 1)
        {
            VFX_OBJ_CLOSE(m_optionsMenuDivideLine[i]);
        }
    }
    VFX_OBJ_CLOSE(m_optionsMenuBg);
    VFX_OBJ_CLOSE(m_optionsMenuHighlight);
    VFX_OBJ_CLOSE(m_optionsMenu);
    VFX_OBJ_CLOSE(m_darkScreen);
    VFX_OBJ_CLOSE(m_emptyFrame);
    VFX_OBJ_CLOSE(m_popupText);
#if !defined(__MMI_BASIC_UI_STYLE__)
    VFX_OBJ_CLOSE(m_popupIcon);
#endif
    VFX_OBJ_CLOSE(m_popupBg);
    VFX_OBJ_CLOSE(m_popup);
    VFX_OBJ_CLOSE(m_panel);
}

void VappNCenter::requestLeave(VsrvNotification* noti)
{
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_REQUEST_LEAVE, noti, noti->getGroupId(), noti->getId(), noti->getType());
    
    m_callbackNoti = noti;
    leave();
}


void VappNCenter::onNotificationChanged(VsrvNotification* noti, VsrvNStatusType status)
{
    // won't update if hidden or there is a screen above NCenter (m_disableLeave is true)
    if (getHidden() == VFX_FALSE && (!m_disableLeave || status == VSRV_NSTATUS_CLOSE))
    {                       
        if (checkNotification(noti) || m_list->getItemIndex((VfxId)noti) >=0)
        { 
            VfxS32 item_idx = m_list->getLayout()->getFocusItem().pos;
            if (item_idx == m_list->getItemIndex((VfxId)noti) && (status == VSRV_NSTATUS_CLOSE))
            {
                if (isInRemindPopup() || isInConfirmPopup())
                {
                    closePopup();
                }
                else if (isInOptionsMenu())
                {
                    closeOptionsMenu();
                }
            }

            MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_NOTI_CHANGED, noti, status);      

            
            VfxBool refresh = VFX_FALSE;
            VfxBool create = VFX_FALSE;
            VfxId refId = VAPP_NCENTER_INVALID_ID;
            VsrvNGroup *group = noti->getGroup();
            VfxBool is_ongoing = VFX_FALSE;

            VfxS32 count = 0;
            VfxList <VsrvNotification*>::It itt;
            for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
            {
                VsrvNotification *n = (*itt);
                if (checkNotification(n) && (n->getType() != VSRV_NOTIFICATION_TYPE_ONGOING))
                {
                    if ((n->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM))
                    {
                        VsrvNotificationCustom* cust = (VsrvNotificationCustom*)n; 
                        if (cust->getCategory() != VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING)
                        {
                            count++;
                        }
                        else
                        {
                            is_ongoing = VFX_TRUE;
                        }
                    }
                    else
                    {
                        count++;
                    }
                    
                } 
                else
                {
                    is_ongoing = VFX_TRUE;
                }
            }   
            
            if (status == VSRV_NSTATUS_CREATE)
            {                                               
                if (count == 1 || is_ongoing)                
                {                       
                    create = VFX_TRUE;                               
                }                     
                else
                {               
                    refresh = VFX_TRUE;
                }
            }
            else if (status == VSRV_NSTATUS_UPDATE)
            {                                    
                VappNCenterListCellStruct* data = (VappNCenterListCellStruct*)m_list->getItemData((VfxId)noti);

                if (data)
                {
                    VfxDateTime::CompareEnum result = noti->getTimeStamp().compareWith(data->timeStamp);
                    if ((result == VfxDateTime::EQUAL || count == 1) && checkIsTheSameType(noti, data))
                    {
                        m_list->updateItem((VfxId)group);
                        m_list->updateItem((VfxId)noti);                                
                    }                              
                    else
                    {
                        if (count == 0)
                        {
                            m_list->removeItem((VfxId)group);                        
                            closeCell(noti);     
                            MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_HEADER, group, group->getId(), group->getType());                            
                        }
                        else if (count == 1)
                        {
                            create = VFX_TRUE;
                        }
                        else
                        {
                            closeCell(noti);                             
                            refresh = VFX_TRUE;                
                        }
                    }
                }
                else
                {
                    create = VFX_TRUE;
                }

                
            }                               
            else if (status == VSRV_NSTATUS_CLOSE)
            {     
                if (closeCell(noti))
                {
                    if (count == 1 && (noti->getType() != VSRV_NOTIFICATION_TYPE_ONGOING)) // this group will be closed
                    {
                        if((noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM) && 
                            ((VsrvNotificationCustom*)noti)->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING)
                        {
                            m_list->updateItem((VfxId)group);
                        }
                        else
                        {
                            m_list->removeItem((VfxId)group);
                        }
                        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_HEADER, group, group->getId(), group->getType());
                    }
                    else
                    {
                        m_list->updateItem((VfxId)group);
                    }                      
                }
            }

            if (create)
            {
                MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_NOTI_CHANGED_CREATE);      
                
                if (group->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
                {
                    VappNCenterListCellStruct data;
                    data.type = VAPP_NCENTER_LIST_CELL_TYPE_HEADER;                    
                    data.timeStamp = noti->getTimeStamp();
                    if (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING && m_ongoingId != VAPP_NCENTER_INVALID_ID)
                    {
                        if (m_ongoingCount == 0)
                        {
                            m_list->insertItem((VfxId)m_ongoingId, VAPP_NCENTER_CAPTION_HEIGHT, 0, &data, sizeof(data));  
                        }
                        refId = (VfxId)m_ongoingId;
                    }
                    else if(m_ongoingCount > 0)
                    {
                        m_list->insertItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, m_ongoingCount + 1, &data, sizeof(data));  
                        refId = (VfxId)group;
                    }
                    else
                    {
                        m_list->insertItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, 0, &data, sizeof(data));  
                        refId = (VfxId)group;
                    }

                    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_HEADER, group, group->getId(), group->getType());
                }   
                if (refId == VAPP_NCENTER_INVALID_ID)
                {
                    if (m_list->getCellCount() == 0)
                    {
                        createCell(noti, refId, VFX_FALSE);  // add to back                      
                    }
                    else
                    {
                        refId = m_list->getItemId(0);
                        createCell(noti, refId, VFX_TRUE);
                    }
                }
                else
                {
                    createCell(noti, refId, VFX_FALSE);  // add to back         
                }
            }

            
            if (refresh)
            {
                MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_NOTI_CHANGED_REFRESH);      

                m_list->updateItem((VfxId)group);
                VsrvNotification *target = noti->getPrevious();
                while(target)
                {
                    if (checkNotification(target))
                    {
                        break;                        
                    }
                    target = target->getPrevious();
                }
                if (target)
                {
                    createCell(noti, (VfxId)target, VFX_FALSE);                                        
                }
                else
                {
                    target = noti->getNext();
                    while(target)
                    {
                        if (checkNotification(target))
                        {
                            break;                        
                        }
                        target = target->getNext();
                    }
                    if (target)
                    {
                        createCell(noti, (VfxId)target, VFX_TRUE);                        
                    }
                }                
            }     

            if ((m_ongoingCount <= 0) && (m_ongoingId != VAPP_NCENTER_INVALID_ID))
            {
                m_list->removeItem((VfxId)APP_NCENTER);
            }

            if ((m_eventCount + m_ongoingCount) > 0)
            {
                if (m_noTextFrame)
                {
                    m_list->removeMarginItem(m_noTextFrame);
                    VFX_OBJ_CLOSE(m_noTextFrame);
                } 
                if (m_quickSettingCell->isDisplayFocus() == VFX_FALSE)
                {
                    VfxS32 new_item_index = m_list->getItemIndex((VfxId)noti);
                    if (status == VSRV_NSTATUS_CREATE && (new_item_index > 0) && 
                        isInRemindPopup() == VFX_FALSE && isInConfirmPopup() == VFX_FALSE && isInOptionsMenu() == VFX_FALSE)
                    {
                        m_list->getLayout()->setFocusItem(VcpMenuPos(0, new_item_index), VFX_FALSE);
                        m_list->getLayout()->update();
                    }
                    else
                    {
                        if ((m_list->getLayout()->getFocusItem().group == 0) && (m_list->getLayout()->getFocusItem().pos == -1))
                        {
                            m_quickSettingCell->setDisplayFocus(VFX_TRUE);
                            m_quickSettingCell->setFocusIndex(0);
                            m_list->getLayout()->setFocusItem(VcpMenuPos(0, -1), VFX_FALSE);
                            m_list->getLayout()->navDir(VcpBaseMenuLayout::NAV_DIR_DOWN);
                            m_quickSettingCell->setDisplayFocus(VFX_FALSE);
                            m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
                        }
                    }
                }
                else
                {
                    VfxS32 new_item_index = m_list->getItemIndex((VfxId)noti);
                    if (status == VSRV_NSTATUS_CREATE && (new_item_index > 0) && 
                        isInRemindPopup() == VFX_FALSE && isInConfirmPopup() == VFX_FALSE && isInOptionsMenu() == VFX_FALSE)
                    {
                        m_quickSettingCell->setDisplayFocus(VFX_FALSE);
                        m_list->getLayout()->setFocusItem(VcpMenuPos(0, new_item_index), VFX_FALSE);
                        m_list->getLayout()->update();
                        m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
                    }
                }
            }
            else
            {
                if (m_quickSettingCell->isDisplayFocus() == VFX_FALSE)
                {
                    m_quickSettingCell->setDisplayFocus(VFX_TRUE);
                    m_quickSettingCell->setFocusIndex(0);
                    m_list->getLayout()->setFocusItem(VcpMenuPos(0, -1), VFX_FALSE);
                    m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(m_quickSettingCell->getLSKStringID()), VFX_IMAGE_SRC_NULL);
                }

                createNoTextFrame();            
            }                
            m_list->makeVisible(m_list->getFocusItem(), VFX_TRUE);
        }   
    }  
}

VfxBool VappNCenter::checkIsTheSameType(VsrvNotification *noti, VappNCenterListCellStruct* data)
{
    if ((data->type == VAPP_NCENTER_LIST_CELL_TYPE_EVENT && noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT) ||
        (data->type == VAPP_NCENTER_LIST_CELL_TYPE_ONGOING && noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
        return VFX_TRUE;
    }
        
    if(noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM)
    {
        VsrvNotificationCustom* cust = (VsrvNotificationCustom*)noti;       
        if ((data->type == VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT && cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT) ||
            (data->type == VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING && cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING))        
        {
            return VFX_TRUE;
        }            
    }    

    return VFX_FALSE;
}



VfxBool VappNCenter::checkNotification(VsrvNotification *noti)
{
    U16 settingValue = 1;

#ifdef  __MMI_NSS_SUPPORT__
    //check APP's NSS setting
    mmi_srv_nss_get_setting(noti->getGroupId(), NSS_SETTING_NCENTER, &settingValue);
#endif

    VfxBool ret = VFX_FALSE;
          
    if ((settingValue || (noti->getFlag() & VSRV_NOTIFICATION_FLAG_NO_NSS)) && noti->getIsStable())
    {
        if(noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING)
        {
            ret = VFX_TRUE;
        }

        if(noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM)
        {
            VsrvNotificationCustom* cust = (VsrvNotificationCustom*)noti;
            if (cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT || cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING)
            {
                ret = VFX_TRUE;
            }            
        }
    }

    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CHECK_NOTIFICATION, noti, noti->getGroupId(), noti->getId(), noti->getType(), noti->getIsStable(), ret);
    
    return ret;
}


VfxBool VappNCenter::closeCell(VsrvNotification *noti)
{
    VfxBool ret = VFX_FALSE;
    
    VappNCenterListCellStruct* data = (VappNCenterListCellStruct*)m_list->getItemData((VfxId)noti);
    if (data)
    {
        VappNCenterListCellType type = data->type;
        VfxBool removed = m_list->removeItem((VfxId)noti);
        if (removed)
        {
            if (type == VAPP_NCENTER_LIST_CELL_TYPE_EVENT || type == VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT)
            {
               m_eventCount--;            
            }
            else if (type == VAPP_NCENTER_LIST_CELL_TYPE_ONGOING || type == VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING)
            {
                m_ongoingCount--;
            }            
            ret = VFX_TRUE;
        }    
        
    }    


    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_CELL, noti, noti->getGroupId(), noti->getId(), noti->getType());
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CELL_COUNT, m_eventCount, m_ongoingCount);

    return ret;    
}



VfxBool VappNCenter::createCell(VsrvNotification *noti, VfxId refId, VfxBool addBeforeRef)
{      
    VfxBool ret = VFX_FALSE;
    if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
    {
        m_eventCount++;                
        VappNCenterListCellStruct data;
        data.timeStamp = noti->getTimeStamp();
        data.type = VAPP_NCENTER_LIST_CELL_TYPE_EVENT;      
        if (refId == VAPP_NCENTER_INVALID_ID)
        {
            m_list->addItem((VfxId) noti, VAPP_NCENTER_ONGOING_CELL_HEIGHT, &data, sizeof(data));
        }
        else
        {
            m_list->insertItem((VfxId) noti, VAPP_NCENTER_ONGOING_CELL_HEIGHT, refId, addBeforeRef, &data, sizeof(data));
        } 

        ret = VFX_TRUE;
        
    }
    else if (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING)
    {
        m_ongoingCount++;
        VappNCenterListCellStruct data;
        data.timeStamp = noti->getTimeStamp();            
        data.type = VAPP_NCENTER_LIST_CELL_TYPE_ONGOING;      
        if (refId == VAPP_NCENTER_INVALID_ID)
        {
            m_list->addItem((VfxId) noti, VAPP_NCENTER_ONGOING_CELL_HEIGHT, &data, sizeof(data));
        }
        else
        {
            m_list->insertItem((VfxId) noti, VAPP_NCENTER_ONGOING_CELL_HEIGHT, refId, addBeforeRef, &data, sizeof(data));
        } 
        ret = VFX_TRUE;

    }
    else if (noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM)
    {            
        VsrvNotificationCustom *n = (VsrvNotificationCustom*) noti;

        VappNCenterListCellStruct data;
        data.timeStamp = noti->getTimeStamp();       

        if (n->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT)
        {
            data.type = VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT;
            m_eventCount++;                 
        }
        else if (n->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING)
        {
            data.type = VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING;
            m_ongoingCount++;
        } 
        
        VsrvNCell *cell = n->createView(VSRV_NVIEWER_TYPE_VAPP_NCENTER, m_list);
        VfxS32 h = cell->getSize().height;
        VFX_OBJ_CLOSE(cell);            


        
        if (refId == VAPP_NCENTER_INVALID_ID)
        {
            m_list->addItem((VfxId) noti, h, &data, sizeof(data));
        }
        else
        {
            m_list->insertItem((VfxId) noti, h, refId, addBeforeRef, &data, sizeof(data));
        }               
        ret = VFX_TRUE;        
    }

    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_CELL, noti, noti->getGroupId(), noti->getId(), noti->getType(), refId, addBeforeRef);
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CELL_COUNT, m_eventCount, m_ongoingCount);

    return ret;


}




void VappNCenter::onActiveScreenEnter(VfxWeakPtr<VfxScreen> scr)
{
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_ON_SCREEN_CHANGED, getHidden());

    if (getHidden() == VFX_FALSE)
    {
        if (m_disableLeave == VFX_FALSE)
        {            
            if (m_list)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->releaseFocus(m_list);
            }
            leaveInternal();
        }
        else
        {        
            if(m_callbackNoti == NULL)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->captureFocus(m_list);
            }
        }
    }
    m_disableLeave = VFX_FALSE;
}
 

void VappNCenter::onActiveScreenExit(VfxWeakPtr<VfxScreen> scr)
{
#ifdef __COSMOS_MMI_PACKAGE__
    // when drag it should leave immediately.
    if (m_isDrag)
    {
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->releaseFocus(m_list);

        leaveInternal();
    }
#else     
    if (m_ncenterScrPtr.get())
    {
        leaveInternal();
    }     
#endif        
}




void VappNCenter::leaveInternal()
{
    //m_panel->setPos(VfxPoint(0,  m_bottomHeight - m_panel->getSize().height));
    if (getHidden() == VFX_FALSE && m_isInCallBack == VFX_FALSE && m_list)
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_LEAVE_INTERNAL);

        vfx_adp_srs_resume();        

#ifdef __COSMOS_MMI_PACKAGE__
        wgui_status_icon_bar_leave_ncenter();
#endif

        setHidden(VFX_TRUE);    
        releaseSystemView();        
        removeFromParentFrame();

        setIsDisabled(VFX_FALSE);

        m_entered = VFX_FALSE;
        m_isDrag = VFX_FALSE;
        m_isInCallBack = VFX_FALSE;
        m_isOnAnim = VFX_FALSE;
        
        VfxTimer *leaveTimer;
        VFX_OBJ_CREATE(leaveTimer, VfxTimer, this); //use ncenter static memory
        leaveTimer->m_signalTick.connect(this, &VappNCenter::leaveInternalEx);
        leaveTimer->setStartDelay(1);
        leaveTimer->start();

/*
        if (m_ghandle)
        {
            vsrv_ncenter_close_ngroup(m_ghandle);
            vsrv_ncenter_close_notification(m_nhandle);
            m_ghandle = NULL;
            m_nhandle = NULL;
        }
*/
    }
}

void VappNCenter::leaveInternalEx(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_LEAVE_INTERNAL_EX);
        
    emitEvent(VAPP_NCENTER_EVENT_EXITED);   
    
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    if (m_callbackNoti)
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_AFTER_REQUEST_LEAVE, m_callbackNoti, m_callbackNoti->getAutoLaunch(), 
        m_callbackNoti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH), m_callbackNoti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_REQUEST_LEAVE));

        VsrvNotification* tmp = m_callbackNoti;
        m_callbackNoti = NULL;

        if (tmp->getAutoLaunch())
        {
            VfxBool autoClose = tmp->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH);
            nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_LAUNCH, tmp);
            if (autoClose)
            {
                nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, tmp);
                VSRV_NOTIFICATION_CLOSE(tmp);
            }
        }
        else
        {
            VfxBool autoClose = tmp->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_REQUEST_LEAVE);
            nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_AFTER_REQUEST_LEAVE, tmp);                       
            if (autoClose)
            {
                nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, tmp);
                VSRV_NOTIFICATION_CLOSE(tmp);
            }
        }
    }   
     
    nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_EXITED, VSRV_NOTIFICATION_TYPE_CUSTOM);
    
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_NCENTER);  

    
}


void VappNCenter::onTimer(VfxTimer* pTimer)
{
    VFX_OBJ_CLOSE(pTimer);

    if (m_softkeybar)
    {
        m_isOnAnim = VFX_FALSE;
        m_softkeybar->setHidden(VFX_FALSE);
    }
}


void VappNCenter::entryByKey(VfxU8 key_type)
{
    VfxS32 newY = UI_device_height;
    VfxS32 finalY;
    VfxTimer* pTimer;

    if (key_type == KEY_LONG_PRESS && m_panel)
    {
        VFX_OBJ_CREATE(pTimer, VfxTimer, this);
        pTimer->setStartDelay(150);
        pTimer->m_signalTick.connect(this,&VappNCenter::onTimer);
        m_isOnAnim = VFX_TRUE;
	
        m_panel->setAutoAnimate(VFX_TRUE);
        m_bottom->setAutoAnimate(VFX_TRUE);
        
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDuration(150);


        VfxS32 marginHeight = m_topHeight + m_bottomHeight;
        VcpBaseMenuLayout* layout = m_list->getLayout();
        VfxS32 formHeight = VFX_MIN(layout->getTotalLength(), getSize().height - marginHeight);

        if (m_entered)
        {                                 
            emitEvent(VAPP_NCENTER_EVENT_EXIT);
        }
        m_isDrag = VFX_TRUE;
        m_originY = m_panel->getPos().y + m_panel->getSize().height;
        
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->releaseFocus(m_list); //relase Focus to original holder when pen down

        if (!m_entered)
        {
            if (newY < marginHeight + formHeight && newY < getSize().height)
            {
                m_panel->setSize(m_panel->getSize().width, marginHeight + formHeight);
                finalY = newY - m_panel->getSize().height;
                m_panel->setPos(0, finalY);
            }
            else if (newY >= marginHeight + formHeight && newY < getSize().height)
            {
                m_panel->setPos(0, 0);
                m_panel->setSize(m_panel->getSize().width, newY);
            }
            else
            {
                if (marginHeight + formHeight > getSize().height)
                {
                    m_panel->setPos(0, getSize().height - marginHeight - formHeight);
                    m_panel->setSize(m_panel->getSize().width, marginHeight + formHeight);
                }
                else
                {
                    finalY = getSize().height;
                    m_panel->setPos(0, 0);
                    m_panel->setSize(m_panel->getSize().width, finalY);
                }                         
            }
        }
        else
        {
            // only move position if already entered.
            finalY = newY - m_originY;

            if (finalY > 0)
            {
                finalY = 0;
            }
            m_panel->setPos(0, finalY);
        }

        VfxAutoAnimate::commit();
        pTimer->start();
    }
    else if (key_type == KEY_EVENT_UP)
    {
        if (m_panel)
        {
            m_isInCallBack = VFX_FALSE;

            m_panel->setPos(0, 0);
            m_panel->setSize(getSize());
            setIsDisabled(VFX_TRUE);
            m_list->setIsDisabled(VFX_TRUE);

            VFX_OBJ_CREATE(m_enterTimer, VfxTimer, m_panel);
            m_enterTimer->m_signalTick.connect(this, &VappNCenter::onEnterEnd);
            m_enterTimer->setStartDelay(VfxAutoAnimate::getDuration());
            m_enterTimer->start();
        }
    }
}


void VappNCenter::optionsMenuItemMoveDown(void)
{
    if (m_optionHighlightIndex < (m_optionItemsNum - 1))
    {
        m_optionHighlightIndex++;
    }
    else
    {
        m_optionHighlightIndex = 0;
    }
    
    m_optionsMenuHighlight->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X, 
        UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*(m_optionItemsNum - m_optionHighlightIndex) - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
}


void VappNCenter::optionsMenuItemMoveUp(void)
{
    if (m_optionHighlightIndex > 0)
    {
        m_optionHighlightIndex--;
    }
    else
    {
        m_optionHighlightIndex = m_optionItemsNum - 1;
    }
    
    m_optionsMenuHighlight->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X, 
        UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*(m_optionItemsNum - m_optionHighlightIndex) - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
}


void VappNCenter::showOptionsMenu(VappNCenterOptionsMenuType type)
{
    VfxS32 i;
    VfxResId type_2[2] = {STR_GLOBAL_CLOSE, STR_GLOBAL_OPEN};
    VfxResId type_3[3] = {STR_ID_VAPP_NCENTER_CLEAR_ALL, STR_GLOBAL_CLEAR, STR_GLOBAL_OPEN};
    
    if (isInOptionsMenu() == VFX_TRUE)
    {
        return;
    }
    m_screen_id = VAPP_NCENTER_OPTION_SCREEN;

    // enable options frame
    m_darkScreen->setHidden(VFX_FALSE);
    m_optionsMenu->setHidden(VFX_FALSE);

    // change softkey
    m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_SELECT), VFX_IMAGE_SRC_NULL);

    if (type == VAPP_NCENTER_OPTIONS_MENU_TYPE_2)
    {
        m_optionItemsNum = 2;
    }
    else if (type == VAPP_NCENTER_OPTIONS_MENU_TYPE_3)
    {
        m_optionItemsNum = 3;
    }

    // resize options background
    m_optionsMenuBg->setPos(VfxPoint(0, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*m_optionItemsNum - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y*2));
    m_optionsMenuBg->setSize(UI_device_width, VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*m_optionItemsNum + VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y*2);
    
    // set default highlight position
    m_optionsMenuHighlight->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X, 
        UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*m_optionItemsNum - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
    m_optionHighlightIndex = 0;

    for (i = 0 ; i < m_optionItemsNum ; i++)
    {
        // set divide line
        if (i < (m_optionItemsNum - 1))
        {
            m_optionsMenuDivideLine[i]->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X,
                UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*(i + 1) - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
        }
    
        // set option menu text
        m_optionsMenuText[i]->setPos(VfxPoint(VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X + VAPP_NCENTER_OPTIONS_MENU_TEXT_OFFSET_X,
            UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT*(i + 1) - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y));
        if (type == VAPP_NCENTER_OPTIONS_MENU_TYPE_2)
        {
            m_optionsMenuText[i]->setString(VFX_WSTR_RES(type_2[i]));
        }
        else if (type == VAPP_NCENTER_OPTIONS_MENU_TYPE_3)
        {
            m_optionsMenuText[i]->setString(VFX_WSTR_RES(type_3[i]));
        }
    }

}


void VappNCenter::closeOptionsMenu(void)
{
    VfxS32 i;
    
    if (isInOptionsMenu() == VFX_FALSE)
    {
        return;
    }
    m_screen_id = VAPP_NCENTER_MAIN_SCREEN;

    m_darkScreen->setHidden(VFX_TRUE);
    m_optionsMenu->setHidden(VFX_TRUE);
    for (i = 0 ; i < VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM ; i++)
    {
        m_optionsMenuText[i]->setString(NULL);
    }
    m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
}


void VappNCenter::showPopup(const VfxWString &str, VfxResId icon_id, VfxResId lsk_id, VfxResId rsk_id, VfxS32 popup_type)
{
    S32 popup_icon_w, popup_icon_h;

    if (((popup_type == VAPP_NCENTER_CONFIRM_POPUP) && (isInConfirmPopup() == VFX_TRUE)) ||
        ((popup_type == VAPP_NCENTER_REMIND_POPUP) && (isInRemindPopup() == VFX_TRUE)))
    {
        return;
    }

    if (popup_type == VAPP_NCENTER_CONFIRM_POPUP)
    {
        m_screen_id = VAPP_NCENTER_CONFIRM_POPUP_SCREEN;
    }
    else if (popup_type == VAPP_NCENTER_REMIND_POPUP)
    {
        m_screen_id = VAPP_NCENTER_REMIND_POPUP_SCREEN;
    }
    
    gdi_image_get_dimension_id(icon_id, &popup_icon_w, &popup_icon_h);

    // enable options frame
    m_darkScreen->setHidden(VFX_FALSE);
    m_popup->setHidden(VFX_FALSE);

    // change softkey
    m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(lsk_id), VFX_IMAGE_SRC_NULL);
    m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(rsk_id), VFX_IMAGE_SRC_NULL);

    // resize options background
    m_popupBg->setPos(VfxPoint(0, UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y*3 - popup_icon_h));
    m_popupBg->setSize(UI_device_width, VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT + VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y*3 + popup_icon_h);

    // set icon
#if !defined(__MMI_BASIC_UI_STYLE__)
    m_popupIcon->setResId(icon_id);
    m_popupIcon->setPos(VfxPoint(((UI_device_width - popup_icon_w) >> 1), UI_device_height - VAPP_NCENTER_BOTTOM_HEIGHT - 
        VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT - VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y * 2 - popup_icon_h));
    m_popupIcon->setSize(popup_icon_w, popup_icon_h);
    m_popupIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_popupIcon->play();
#endif
    // set text
    m_popupText->setString(str);

    // play error tone
    if (popup_type == VAPP_NCENTER_REMIND_POPUP && icon_id == IMG_GLOBAL_FAIL)
    {
        srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE), NULL);
    }
}


void VappNCenter::closePopup(void)
{    
    if (isInRemindPopup() == VFX_FALSE && isInConfirmPopup() == VFX_FALSE)
    {
        return;
    }
    m_screen_id = VAPP_NCENTER_MAIN_SCREEN; 

    m_darkScreen->setHidden(VFX_TRUE);
    m_popup->setHidden(VFX_TRUE);
    if (isFocusOnQuickSetting() == VFX_FALSE)
    {
        m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_GLOBAL_OPTIONS), VFX_IMAGE_SRC_NULL);
        m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_GLOBAL_BACK), VFX_IMAGE_SRC_NULL);
    }
    else
    {
        m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(m_quickSettingCell->getLSKStringID()), VFX_IMAGE_SRC_NULL);
        m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_GLOBAL_BACK), VFX_IMAGE_SRC_NULL);
    }
}


void VappNCenter::setQuickSettingSoftkey(void)
{    
    if (isInMainScreen() && isFocusOnQuickSetting())
    {
        m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(m_quickSettingCell->getLSKStringID()), VFX_IMAGE_SRC_NULL);
        m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_GLOBAL_BACK), VFX_IMAGE_SRC_NULL);
    }
}


VfxBool VappNCenter::isFocusOnQuickSetting(void)
{
    return m_quickSettingCell->isDisplayFocus();        
}

void VappNCenter::clearQuickSettingFocus(void)
{
    m_quickSettingCell->setDisplayFocus(VFX_FALSE);
}


void VappNCenter::processRegisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->registerHandler(keyCode, target);
}


void VappNCenter::processUnregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->unregisterHandler(keyCode, target);
}


void VappNCenter::processUnregisterAllAccessKeyHandler(VfxControl *target)
{   
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->unregisterAllHandler(target);
}


VfxBool VappNCenter::processFocusKey(VfxKeyEvent &event)
{
    VfxBool ret = VFX_FALSE;

    // If there is focused child, let it handle first
    if (getFocusChildFrame())
    {
        ret = getFocusChildFrame()->processFocusKey(event);
    }

    // If there is access key registered, process it
    if (!ret)
    {
        VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
        ret = m_pAccessKeyMgr->processKeyInput(event);
    }

    // If there is no other one handle it, handle it by screen it self.
    if (!ret)
    {
        ret = onKeyInput(event);
    }
    return ret;
}


/***************************************************************************** 
 * Class VappNCenterScr 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNCenterScr", VappNCenterScr, VfxAppCatScr);
void VappNCenterScr::onInit()
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    m_dir = renderer->getPreScreenRotateType();
    renderer->setScreenRotateType(m_dir);
    
    VfxAppCatScr::onInit();

    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    NCenter->setNCenterScr(this);
}

static mmi_ret vapp_ncenter_close_scr(mmi_event_struct *evt)
{
    VFX_UNUSED(evt);
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_NCENTER);  
    return MMI_RET_OK;
}     
void VappNCenterScr::onEnter(VfxBool isBackward)
{
    VfxAppCatScr::onEnter(isBackward);

    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (isBackward)
    {
        // close scr only when disableLeave = false
        if (NCenter->getDisableLeaveOnScreeChange() == FALSE)
        {            
            // use MMI_FRM_POST_EVENT instead vfxPostInvoke0 to ensure post event after pluto entering flow
            mmi_event_struct postInvoke;
            MMI_FRM_INIT_EVENT(&postInvoke, 0);
            MMI_FRM_POST_EVENT(&postInvoke, vapp_ncenter_close_scr, NULL);           
        }
    }
    else
    {
        NCenter->disableLeaveOnScreenChange();
        NCenter->enter();
    }
}

void VappNCenterScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = m_dir;
}

    
#endif /* defined(__MMI_NCENTER_SUPPORT__) */

