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
 *  vapp_widget_delegator.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  UI delegation of web widget
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

#include "MMI_features.h"

#ifdef __MMI_GADGET_SUPPORT__

#include "vfx_uc_include.h"
#include "vapp_widget_adp.h"
#include "vapp_widget.h"
#include "vapp_widget_def.h"
#include "vapp_widget_gadget_factory.h"
#include "vcp_pluto_control.h"
#include "vapp_widget_delegator.h"
#include "mmi_rp_vapp_widget_delegator_def.h"
#include "widget_adp_struct.h"

extern "C"
{
#include "med_utility.h" 
#include "wgtmgrsrvgprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#include "cache_sw.h"
#include "GlobalResDef.h"
}

#include "vadp_asm.h"
#include "vapp_widget_popup_controller.h"
#include "vapp_widget_editor.h"
#include "gadget_adp_audio_service.h"
#include "gadget_adp_avplugin.h"
#include "vapp_widget_defs.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif //__MTK_TARGET

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

#if defined(LIBRA35_DEMO_BB) || defined(AMBER38_DEMO_BB)
#define MAX_WIDGETS 8
#elif defined(UNICORN53V3_DEMO_EVB) || defined(UNICORN53V4_DEMO_EVB)
#define MAX_WIDGETS 3
#else
#define MAX_WIDGETS 10
#endif

//VfxObjList VappWidgetDelegator::m_list;

int VappWidgetDelegator::m_instance_count = 0;
VfxBool VappWidgetDelegator::m_hasInitialized = VFX_FALSE;

VFX_IMPLEMENT_CLASS("VappWidgetObjectList", VappWidgetObjectList, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWidgetObjectList);


VFX_IMPLEMENT_CLASS("VappWidgetDelegator", VappWidgetDelegator, VappWidget);

VappWidgetDelegator::VappWidgetDelegator() : 
    m_id(), 
    m_viewType(WIDGET_IDLE_VIEW), 
    m_viewHandle(NULL), 
    m_widgetStatus(UNLOADED), 
    m_isDragging(VFX_FALSE), 
    m_isResizing(VFX_FALSE),
    m_focused(VFX_FALSE), 
    m_clientWidth(0), 
    m_clientHeight(0), 
    m_imageFrame(NULL), 
    m_imageBuffer1(NULL), 
    m_imageBuffer2(NULL), 
    m_waitingIcon(NULL), 
    m_hasSetBut(MMI_FALSE), 
    m_buttonPressed(VFX_FALSE), 
    m_buttonSetting(NULL),
    m_timerSetBut(NULL), 
    m_tlSetBut(NULL), 
    m_timeline(NULL), 
    m_canvasLock(0), 
    m_isEnter(VFX_FALSE), 
    m_isTooLarge(VFX_FALSE), 
    m_textFrame(NULL), 
    m_drawedBuffer(1), 
    m_usedBuffer(NULL),
    m_gid(0)
{
    VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->append(this);
    m_canvasLock = createCanvasLock(0);
}


VappWidgetDelegator::~VappWidgetDelegator(void)
{
    VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->removeOne(this);

    kal_take_mutex(m_canvasLock);

    freeImgBuffer();

    kal_give_mutex(m_canvasLock);
}

VappWidgetId VappWidgetDelegator::getId() const
{
    return m_id;
}

VfxSize VappWidgetDelegator::getMaxSize() const
{
    VfxSize size;

    // Get the widget size defined in mainfest file from widget manager service.
    srv_wgtmgr_get_downloaded_widget_idle_view_size(m_id.getIntType(), &size.width, &size.height);

	size.width  = (VfxS32)(size.width * getResizeRatio(m_id.getIntType()));
    size.height = (VfxS32)(size.height * getResizeRatio(m_id.getIntType()));

    if (size.width == 0 || (size.width > (WIDGET_MAX_ROOM_WIDTH - WIDGET_MARGIN)))
    {
        size.width = WIDGET_MAX_ROOM_WIDTH - WIDGET_MARGIN;
    }

    if (size.height == 0 || (size.height > WIDGET_MAX_ROOM_HEIGHT - WIDGET_MARGIN))
    {
        size.height = WIDGET_MAX_ROOM_HEIGHT - WIDGET_MARGIN;
    }
    else if (srv_wgtmgr_is_wgt_setting_available(m_id.getIntType()))
    {
        size.height = size.height + WIDGET_SETTING_BUTTON_SIZE + SETBUT_MARGIN_GAP;
    }
 
    return size;
}


VfxS32 VappWidgetDelegator::getName(VfxWChar *string, VfxS32 size) const
{
    // Keep the last char for null terminated
    srv_wgtmgr_get_downloaded_wgt_name(m_id.getIntType(), string, sizeof(VfxWChar) * (size - 1));

    return kal_wstrlen(string);
}


VfxFrame *VappWidgetDelegator::createIcon(VfxObject *parentObj)
{
    VfxFrame *frame;
    VfxWString path;

    WCHAR icon_path[WIDGET_MAX_ICON_PATH_LENGTH];

    srv_wgtmgr_get_downloaded_wgt_icon_path(m_id.getIntType(), icon_path);
    path.loadFromMem(icon_path);

    VFX_OBJ_CREATE(frame, VfxFrame, parentObj);   
    frame->setImgContent(VfxImageSrc(VfxWString(path)));
    
    return frame;
}


void VappWidgetDelegator::onCreateView()
{
#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("CR0", SA_start);
#endif

    // call VappWidget's onCreateView
    VappWidget::onCreateView();

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("CR1", SA_start);
#endif

    if (m_instance_count++ == 0 && m_hasInitialized == VFX_FALSE)
    {
        vapp_widget_initialize();
        
        m_hasInitialized = VFX_TRUE;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if(srv_usb_is_in_mass_storage_mode_ext() == MMI_TRUE)
    {    
        setImageToDefaultRes();

        return ;
    }
#endif

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("CR1", SA_stop);
#endif

    if (m_instance_count > MAX_WIDGETS)
    {
        cancelLoadWidgetPopup(STR_ID_VAPP_WIDGET_MAXIMUM_REACHED);         
        return;
    }

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("CR2", SA_start);
#endif

    if (m_widgetStatus == LOADED)
    {
        m_isDragging = false;

        gadget_adp_audio_service_resume();
        gadget_adp_avplugin_notify_resume();
        return;
    }
    else if (m_widgetStatus == LOADING)
    {
        return;
    }

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("CR2", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("CR3", SA_start);
#endif
    // check if there is settings button
    //m_hasSetBut = srv_wgtmgr_is_wgt_setting_available(m_id.getIntType());

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("CR3", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("CR4", SA_start);
#endif

    loadingImage();

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("CR4", SA_stop);
#endif

    // send load widget request to gadget task
    vapp_widget_load_widget(m_id.getIntType(), 0);

    // set widget status to loading
    m_widgetStatus = LOADING;

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("CR0", SA_stop);
#endif
}


void VappWidgetDelegator::onReleaseView(void)
{
#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RL0", SA_start);
#endif

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RL1", SA_start);
#endif
    releaseResource();

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RL1", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RL2", SA_start);
#endif    
    if ((m_isEnter == VFX_FALSE || m_widgetStatus == LOADED) && m_instance_count == 0)
    {
        gadget_adp_audio_service_suspend();
        gadget_adp_avplugin_notify_suspend();

        //
        // We check if the interrupt here is due to confirm dialog raised from Gadget engine
        // to avoid plugin reset in this scenario.
        //
        if (VappWidgetPopupController::m_isPopup == VFX_FALSE)
        {
            gadget_adp_avplugin_notify_reset();
        }

#ifdef __MAUI_SOFTWARE_LA__     
        SLA_CustomLogging("RL3", SA_start);
#endif

        vapp_widget_disable_view_cache(VFX_FALSE, VFX_FALSE);

#ifdef __MAUI_SOFTWARE_LA__     
        SLA_CustomLogging("RL3", SA_stop);
#endif

    }

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RL2", SA_stop);
#endif

    if (m_widgetStatus == LOADED)
    {
        widget_unload_widget(m_id.getIntType());
        m_widgetStatus = UNLOADED;
    }

    VappWidget::onReleaseView();

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RL0", SA_stop);
#endif
}


void VappWidgetDelegator::onSerializeView(VfxArchive *ar)
{
#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("SR0", SA_start);
#endif

    // If there is a small screen drawing, do nothing
    VfxMainScr *scr = VfxMainScr::findMainScr(this);

    if ((scr && scr->getIsSnapshotDrawing()) || m_widgetStatus == LOAD_FAILED)
    {
        return ;
    }

    m_isEnter = VFX_FALSE;
    m_viewType = WIDGET_DETAIL_VIEW;
	m_widgetStatus = UNLOADED;

    onReleaseView();

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("SR0", SA_stop);
#endif
}

void VappWidgetDelegator::onRestoreView(VfxArchive *ar)
{
#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RS0", SA_start);
#endif

    // If there is a small screen drawing, do nothing
    VfxMainScr *scr = VfxMainScr::findMainScr(this);

    if ((scr && scr->getIsSnapshotDrawing()) || m_widgetStatus == LOAD_FAILED)
    {
        return ;
    }


    m_viewType = WIDGET_IDLE_VIEW;
    m_isEnter = VFX_TRUE;

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RS1", SA_start);
#endif

#ifdef __USB_IN_NORMAL_MODE__
    if(srv_usb_is_in_mass_storage_mode() == MMI_TRUE)
    {    
        setImageToDefaultRes();

        return ;
    }
#endif

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RS1", SA_stop);
#endif

    if (m_widgetStatus != UNLOADED)
    {
        return ;
    }

    VFX_ASSERT(m_widgetStatus == UNLOADED);

    // create widget when back to home screen
    m_imageFrame = NULL;
    m_imageBuffer1 = NULL;
    m_imageBuffer2 = NULL;
    //m_waitingIcon = NULL,
    m_hasSetBut = MMI_FALSE;
    m_buttonPressed = VFX_FALSE;
    m_buttonSetting = NULL;
    m_timerSetBut = NULL;
    m_tlSetBut = NULL;
    m_timeline = NULL;

    onCreateView();

#ifdef __MAUI_SOFTWARE_LA__     
    SLA_CustomLogging("RS0", SA_stop);
#endif
}


void VappWidgetDelegator::onDrag(VfxPenEvent & event)
{
    m_isDragging = VFX_TRUE;
    VappWidget::onDrag(event);
}


void VappWidgetDelegator::onMove(VfxPenEvent & event)
{
    VappWidget::onMove(event);    
}


void VappWidgetDelegator::onDrop(VfxPenEvent & event)
{
    m_isDragging = VFX_FALSE;
    VappWidget::onDrop(event);    
}


void VappWidgetDelegator::onFocus()
{
    m_buttonPressed = VFX_FALSE;

    VappWidget::onFocus();

    if (m_widgetStatus != LOADED && m_isEnter == VFX_TRUE)
    {
        return;
    }

    if (m_focused == VFX_FALSE)
    {
        m_focused = VFX_TRUE;
        vapp_widget_focus_in(m_id.getIntType(), m_viewHandle);
    }

    // set widget update indicator to gadget task    
    vapp_widget_update_content(m_id.getIntType(), m_viewHandle);

}


void VappWidgetDelegator::onDefocus()
{
    if (m_widgetStatus != LOADED)
    {
        return;
    }

    if (m_focused == VFX_TRUE)
    {
        m_focused = VFX_FALSE;
        if (m_buttonSetting)
        {
            m_buttonSetting->setHidden(VFX_TRUE);
            m_buttonSetting->setOpacity(0.0f);
        }
        vapp_widget_focus_out(m_id.getIntType(), m_viewHandle);
    }

    VappWidget::onDefocus();
}


void VappWidgetDelegator::onVisibleChanged(VfxBool isVisible)
{
    VappWidget::onVisibleChanged(isVisible);
    
    if (isVisible == VFX_TRUE)
    {
        widget_set_widget_active_flag(VFX_TRUE);
    }
    else
    {
        widget_set_widget_active_flag(VFX_FALSE);

        VfxObjListEntry *iter = VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->getHead();

        while(iter)
        {
            VappWidgetDelegator *p = (VappWidgetDelegator *)iter->get();

            if (p->isVisible() == VFX_TRUE)
            {
                widget_set_widget_active_flag(VFX_TRUE);
            }
        
            iter = iter->getNext();
        }
    }

}


VfxPoint VappWidgetDelegator::onGetEditButtonOffset()
{
    return VfxPoint((getMaxSize().width - WIDGET_DEL_BTN_MARGIN_X), WIDGET_DEL_BTN_MARGIN_Y);
}


VfxBool VappWidgetDelegator::onPenInput(VfxPenEvent &event)
{
    VfxS32 x = event.getRelPos(this).x;
    VfxS32 y = event.getRelPos(this).y;

    if (!m_imageFrame)
    {
        return VFX_FALSE;
    }

    VFX_ASSERT(m_imageFrame);

    VfxS32 m_widget_x1 = m_imageFrame->getPos().x;
    VfxS32 m_widget_y1 = m_imageFrame->getPos().y;
    VfxS32 m_widget_x2 = m_widget_x1 + m_imageFrame->getSize().width;
    VfxS32 m_widget_y2 = m_widget_y1 + m_imageFrame->getSize().height;

    if (m_hasSetBut && m_buttonSetting)
    {
        m_widget_y2 += m_buttonSetting->getSize().height;
    }

    // drop the pen input event if the position is outside of the actual widget
    if (!m_isDragging && 
        (x < m_widget_x1 || x > m_widget_x2 || y < m_widget_y1 || y > m_widget_y2))
    {
        return VFX_FALSE;
    }

    // dragging mode
    if (m_isDragging)
    {
        VappWidget::onPenInput(event);

        if (event.type != VFX_PEN_EVENT_TYPE_UP && event.type != VFX_PEN_EVENT_TYPE_ABORT)
        {
            return VFX_TRUE;
        }
        else
        {
            event.type = VFX_PEN_EVENT_TYPE_ABORT;
        }
    }
    else
    {
        VappWidget::onPenInput(event);
    }

    VfxPoint pos(event.getRelPos(this));

    // adjust coordinate because of the actual widget has been moved to center
	pos.x = (VfxS32)((pos.x - m_widget_x1) / getResizeRatio(m_id.getIntType()));
	pos.y = (VfxS32)((pos.y - m_widget_y1) / getResizeRatio(m_id.getIntType()));

    if (m_widgetStatus != LOADED)
    {
        return VFX_TRUE;
    }

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        // display setting button
        if (m_hasSetBut && m_buttonSetting)
        {
            m_buttonSetting->setHidden(VFX_FALSE);
            m_buttonSetting->setOpacity(0.8f);
            m_timerSetBut->stop();
        }
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        // start appearance duration
        if (m_hasSetBut && m_buttonSetting)
        {
            m_timerSetBut->start();
        }
    }

    // dispatch event directly
    int type = -1;
    
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        type = PEN_DOWN;
        break;
    case VFX_PEN_EVENT_TYPE_MOVE:
        type = PEN_MOVE;
        break;
    case VFX_PEN_EVENT_TYPE_UP:
        type = PEN_UP;
        break;
    case VFX_PEN_EVENT_TYPE_ABORT:
        type = PEN_ABORT;
        break;
    default:
        return VFX_TRUE;
    }

    widget_enter_widget_active_mode();

    vapp_widget_handle_pen_event(m_id.getIntType(), m_viewHandle, pos.x, pos.y, type);
    return VFX_TRUE;
}


VfxFloat VappWidgetDelegator::getResizeRatio(VfxS32 instance_id)
{
	VfxFloat resizeRatio = 1;

    //
    // This API is only applied in WVGA project. In other cases, will return 1 directly.
    //
#if defined(__MMI_MAINLCD_480X800__) 
	VfxU8 maxResolusion = srv_wgt_get_downloaded_widget_max_resolution(instance_id);
	
	switch (maxResolusion)
	{
		case WIDGET_LCD_UNKNOWN:
			resizeRatio = 1;
			break;

		case WIDGET_LCD_240x320:
			resizeRatio = ((LCD_WIDTH / 240.0f) < (LCD_HEIGHT / 320.0f)) ? (LCD_WIDTH / 240.0f) : (LCD_HEIGHT / 320.0f);
			break;

		case WIDGET_LCD_240x400:
			resizeRatio = ((LCD_WIDTH / 240.0f) < (LCD_HEIGHT / 400.0f)) ? (LCD_WIDTH / 240.0f) : (LCD_HEIGHT / 400.0f);
			break;

		case WIDGET_LCD_320x480:
			resizeRatio = ((LCD_WIDTH / 320.0f) < (LCD_HEIGHT / 480.0f)) ? (LCD_WIDTH / 320.0f) : (LCD_HEIGHT / 480.0f);
			break;

		case WIDGET_LCD_480x800:
			resizeRatio = ((LCD_WIDTH / 480.0f) < (LCD_HEIGHT / 800.0f)) ? (LCD_WIDTH / 480.0f) : (LCD_HEIGHT / 800.0f);
			break;
		default:
			VFX_ASSERT(0);
			break;
	}
#endif
	
	VFX_ASSERT(resizeRatio > 0);
	
	return resizeRatio;
}

VfxObjListEntry* VappWidgetDelegator::getHead()
{
    return VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->getHead();
}

void VappWidgetDelegator::deleteWidget(VappWidgetDelegator *widget)
{
    if (!widget || !widget->isCreated())
    {
        return ;
    }

    widget->m_widgetStatus = DELETING;

    widget->m_signalDeselect.emit(widget);
}

void VappWidgetDelegator::cancelLoadWidget(VfxId id, void *widget)
{
    //No matter the response is what, delete widget
    VappWidgetDelegator *self = (VappWidgetDelegator *)VfxObject::handleToObject((VfxObjHandle)widget);

    if (self)
    {
        deleteWidget(self);
    }
}

void VappWidgetDelegator::deleteAllWidget(VfxBool checkStatus)
{
    VfxObjListEntry *iter = VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->getHead();

    while(iter)
    {
        VappWidgetDelegator *p = (VappWidgetDelegator *)iter->get();

        iter = iter->getNext();

        if (checkStatus == VFX_FALSE || (checkStatus == VFX_TRUE && p->m_widgetStatus != UNLOADED))
        {
            deleteWidget(p);
        }
    }
}

void VappWidgetDelegator::setViewType(WidgetViewType type)
{
    m_viewType = type;
};

VfxBool VappWidgetDelegator::isDetailView() const
{
    if (m_viewType == WIDGET_DETAIL_VIEW)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
};

VappWidgetDelegator* VappWidgetDelegator::findByInstancId(int instance_id)
{
    VfxObjListEntry *iter = VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->getHead();

    while(iter)
    {
        VappWidgetDelegator *p = (VappWidgetDelegator *)iter->get();
        if(p->m_id.getIntType() == instance_id)
        {
            return p;
        }
        iter = iter->getNext();
    }
    return NULL;
}

void VappWidgetDelegator::setImageToDefaultRes()
{
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_IND, NULL, KAL_FALSE);

    if (!m_imageFrame)
    {
        // create widget idle view frame to prepare showing in home screen
        VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
    }
    
    m_imageFrame->setResId(IMG_ID_VAPP_WIDGET_LOAD_BACKGROUND);
    m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imageFrame->setSize(getMaxSize());
    
    if (!m_textFrame)
    {
        VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    }
    
    m_textFrame->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_MID,
        VFX_FRAME_ALIGNER_MODE_MID,
        VFX_FRAME_ALIGNER_MODE_MID,
        VFX_FRAME_ALIGNER_MODE_MID);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER_WITHIN_MARGIN);
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_textFrame->setVerticalToCenter(VFX_TRUE);
    m_textFrame->setMargins(WIDGET_MARGIN, 0, WIDGET_MARGIN, 0);
    m_textFrame->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_NOT_AVAILABLE_IN_USB_MODE));            
    m_textFrame->setBgColor(VFX_COLOR_TRANSPARENT);
    m_textFrame->setColor(VFX_COLOR_WHITE);
    m_textFrame->setAutoFontSize(VFX_TRUE);
    m_textFrame->setPos(0, m_imageFrame->getSize().height/2 - WIDGET_MARGIN_TOP);
    m_textFrame->setSize(m_imageFrame->getSize().width, m_imageFrame->getSize().height/2);

}

void VappWidgetDelegator::recoverImageFromDefaultRes()
{
    VfxObjListEntry *iter = VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->getHead();
    
    while(iter)
    {
        VappWidgetDelegator *p = (VappWidgetDelegator *)iter->get();

        p->releaseImageResource();
        p->onCreateView();
        // set widget update indicator to gadget task    
        //vapp_widget_update_content(p->m_id.getIntType(), p->m_viewHandle);

        iter = iter->getNext();
    }
}


void VappWidgetDelegator::loadingImage()
{
#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("LD1", SA_start);
#endif

    // create widget idle view frame to prepare showing in home screen
    if (m_imageFrame)
    {
        VFX_OBJ_CLOSE(m_imageFrame);
    }

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("LD1", SA_stop);
#endif

    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("LD2", SA_start);
#endif
    m_imageFrame->setResId(IMG_ID_VAPP_WIDGET_LOAD_BACKGROUND);
    m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imageFrame->setSize(getMaxSize());
    setBounds(m_imageFrame->getBounds()); 
#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("LD2", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("LD3", SA_start);
#endif
    // show loading icon
    if (!m_waitingIcon)
    {
        VFX_OBJ_CREATE(m_waitingIcon, VcpActivityIndicator, this);
        VfxU32 x, y;
        m_waitingIcon->setSize(WIDGET_LOADING_ICON_SIZE_WIDTH, WIDGET_LOADING_ICON_SIZE_HEIGHT);
        x = m_imageFrame->getPos().x + 
            m_imageFrame->getSize().width/2 - 
            m_waitingIcon->getSize().width/2;
        y = m_imageFrame->getPos().y + 
            m_imageFrame->getSize().height/2 - 
            m_waitingIcon->getSize().height/2;
        m_waitingIcon->setPos(x, y);
    }
#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("LD3", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("LD4", SA_start);
#endif
    insertChildFrameAfter(m_imageFrame, m_waitingIcon);
    m_waitingIcon->setHidden(VFX_FALSE);
    m_waitingIcon->start();
#ifdef __MAUI_SOFTWARE_LA__ 
    SLA_CustomLogging("LD4", SA_stop);
#endif

}


void VappWidgetDelegator::releaseImageResource()
{
    freeImgBuffer();

    if (m_imageFrame)
    {
        VFX_OBJ_CLOSE(m_imageFrame);
    }

    if (m_waitingIcon)
    {
        m_waitingIcon->stop();
        m_waitingIcon->setHidden(VFX_TRUE);

        VFX_OBJ_CLOSE(m_waitingIcon);
    }

    if (m_textFrame)
    {
        VFX_OBJ_CLOSE(m_textFrame);
    }

}


void VappWidgetDelegator::releaseResource()
{
    m_instance_count--;

    kal_take_mutex(m_canvasLock);

    releaseImageResource();

    if (m_hasSetBut && m_buttonSetting)
    {
        VFX_OBJ_CLOSE(m_buttonSetting);
        VFX_OBJ_CLOSE(m_timerSetBut);
        VFX_OBJ_CLOSE(m_tlSetBut);
    }

    if (m_timeline)
    {
        m_timeline->stop();
        VFX_OBJ_CLOSE(m_timeline);
    }
    
    kal_give_mutex(m_canvasLock);

}


void *VappWidgetDelegator::lockCanvas(void **buffer, int width, int height)
{
    canvas_lock_struct *lock = NULL;
    int size = width * height * 4;

    kal_take_mutex(m_canvasLock);

    if (!isCreated())
    {
        return NULL;
    }

    if (m_imageFrame && m_imageBuffer1 && m_imageBuffer2 && m_clientWidth == width && m_clientHeight == height)
    {
        lock = (canvas_lock_struct *)OslMalloc(sizeof(canvas_lock_struct));

        memset(lock, 0, sizeof(canvas_lock_struct));

        lock->mutex = m_canvasLock;
        lock->unlock_canvas = VappWidgetDelegator::unlockCanvas;
        lock->context = this;

        // give gadget task the unused buffer 
        if (m_imageFrame->getImgContent().getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER && m_usedBuffer == m_imageBuffer1)
        {
            memset(m_imageBuffer2, 0, size);
            
            *buffer = m_imageBuffer2;

            m_drawedBuffer = 2;
        }
        else
        {
            memset(m_imageBuffer1, 0, size);

            *buffer = m_imageBuffer1;

            m_drawedBuffer = 1;
        }

    }
    else
    {
        m_drawedBuffer = 0;
        kal_give_mutex(m_canvasLock);
        return NULL;
    }

    return lock;
}


void VappWidgetDelegator::unlockCanvas(void *p)
{
    canvas_lock_struct *lock = (canvas_lock_struct *)p;
    VappWidgetDelegator *delegator;

    VFX_ASSERT(lock);

    delegator = (VappWidgetDelegator *)lock->context;

    VFX_ASSERT(delegator);

    VFX_ASSERT(lock->mutex == delegator->m_canvasLock);

    kal_give_mutex(delegator->m_canvasLock);

    OslMfree(lock);
}


void *VappWidgetDelegator::getViewHandle(void)
{
    return m_viewHandle;
}

void VappWidgetDelegator::cancelLoadWidgetPopup(VfxResId str_id)
{
    m_widgetStatus = LOAD_FAILED;

    VfxObject *parentObj = VappWidgetPopupController::getParentObj();

    if (!parentObj)
    {
        cancelLoadWidget(VCP_POPUP_BUTTON_NO_PRESSED, (void *)getObjHandle());    
        return ;
    }    
    
    VappWidgetPopupController *controller;
    VFX_OBJ_CREATE(controller, VappWidgetPopupController, parentObj);
    controller->setCallback(VappWidgetDelegator::cancelLoadWidget, (void *)getObjHandle());
    
    controller->showPopupWithOk(
        parentObj, 
        VFX_WSTR_RES(str_id));  
}


void VappWidgetDelegator::onWidgetLoadResult(int result, void *view_handle, int width, int height)
{
    if (!isCreated() || m_widgetStatus != LOADING)
    {
        return;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    m_hasSetBut = srv_wgtmgr_is_wgt_setting_available(m_id.getIntType());	

    if (result != 0)
    {
    	switch(result)
    	{
        case WIDGET_WAIT_FOR_UNLOADING:
            vapp_widget_load_widget(m_id.getIntType(), 0);
            return;
    	case WIDGET_PERMISSION_NOT_GRANTED:
            cancelLoadWidgetPopup(STR_ID_VAPP_WIDGET_PERMISSION_NOT_GRANTED);
	        return;
        case WIDGET_PATH_NOT_FOUND:
            cancelLoadWidgetPopup(STR_ID_VAPP_WIDGET_PATH_NOT_FOUND);  
            return;
    	case WIDGET_FAILED_LOAD_GADGET:
    	case WIDGET_HOST_NOT_INITIALIZED:
            cancelLoadWidgetPopup(STR_ID_VAPP_WIDGET_FAILED_LOAD_WIDGET);  
 	        return;
    	case WIDGET_MEMORY_FULL:
            cancelLoadWidgetPopup(STR_ID_VAPP_WIDGET_MEMORY_FULL);  	        
	        return;
	    default:
	    	VFX_ASSERT(0);
        	return;
        }
    }

    m_widgetStatus = LOADED;
    m_isDragging = false;
    m_viewHandle = view_handle;

    gadget_adp_audio_service_resume();
    gadget_adp_avplugin_notify_resume();

    m_clientWidth = width;
    m_clientHeight = height;

    // Allocate image buffer
    int size = m_clientWidth * m_clientHeight * 4;

    if (!allocImgBuffer(size))
    {
        widget_unload_widget(m_id.getIntType());
        //m_widgetStatus = UNLOADED;
        
        return ;
    }

    // set widget update indicator to gadget task    
    vapp_widget_update_content(m_id.getIntType(), m_viewHandle);

}

//Add resize handler function
void VappWidgetDelegator::onWidgetResize(VfxS32 width, VfxS32 height)
{
    if (!isCreated() 
        || (m_clientWidth == width && m_clientHeight == height) 
        ||  m_viewHandle == NULL ||  m_widgetStatus != LOADED )
    {
        return ;
    }

    m_isResizing = VFX_TRUE;
    m_clientWidth = width;
    m_clientHeight = height;

    kal_take_mutex(m_canvasLock);

    freeImgBuffer();
    
    // Allocate image buffer
    int size = m_clientWidth * m_clientHeight * 4;

    if (!allocImgBuffer(size))
    {
        widget_unload_widget(m_id.getIntType());
        
        return ;
    }

    kal_give_mutex(m_canvasLock);

    vapp_widget_update_content(m_id.getIntType(), m_viewHandle);
}


void VappWidgetDelegator::onWidgetContentUpdate(void *buffer)
{
    if (!isCreated() || m_widgetStatus != LOADED || 
        m_imageBuffer1 == NULL || m_imageBuffer2 == NULL)
    {
        return;
    }

    int width = m_clientWidth, height = m_clientHeight;    

    if (m_imageFrame->getImgContent().getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        if (m_hasSetBut && !m_buttonSetting)
        {
            // create button
            VfxImageSrc imageUp = VfxImageSrc(IMG_ID_VAPP_WIDGET_SETTING_BUTTON_UP);
            VfxImageSrc imageDown = VfxImageSrc(IMG_ID_VAPP_WIDGET_SETTING_BUTTON_DOWN);

            height = (VfxS32)((height * getResizeRatio(m_id.getIntType())) + imageUp.getSize().height);
            
            VFX_OBJ_CREATE(m_buttonSetting, VcpButton, this);
            m_buttonSetting->setAnchor(VfxFPoint(0.5, 0.5));
            m_buttonSetting->setSize(imageUp.getSize());
            m_buttonSetting->setPos(getSettingButtonPos((VfxS32)(width * getResizeRatio(m_id.getIntType())), height));
            m_buttonSetting->setHidden(VFX_TRUE);
            m_buttonSetting->setOpacity(0.8f);
            m_buttonSetting->setBgImageList(
                VcpStateImage(IMG_ID_VAPP_WIDGET_SETTING_BUTTON_UP, 
                              IMG_ID_VAPP_WIDGET_SETTING_BUTTON_DOWN,
                              IMG_ID_VAPP_WIDGET_SETTING_BUTTON_UP,
                              IMG_ID_VAPP_WIDGET_SETTING_BUTTON_UP));
            m_buttonSetting->m_signalClicked.connect(this, &VappWidgetDelegator::launchSetting);

            // create timer
            VFX_OBJ_CREATE(m_timerSetBut, VfxTimer, this);
            m_timerSetBut->setStartDelay(SETBUT_APPEAR_TIME);
            m_timerSetBut->m_signalTick.connect(this, &VappWidgetDelegator::onTimerSetBut);
        
            // create timeline to fadeout setting button
            VFX_OBJ_CREATE(m_tlSetBut, VfxFloatTimeline, this);
            m_tlSetBut->setTarget(m_buttonSetting);
            m_tlSetBut->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
            m_tlSetBut->setToValue(0.0f);
            m_tlSetBut->setDurationTime(SETBUT_FADEOUT_TIME);
            m_tlSetBut->m_signalStopped.connect(this, &VappWidgetDelegator::onTlSetBut);
        }
    
        m_waitingIcon->stop();
        m_waitingIcon->setHidden(VFX_TRUE);
        //VFX_OBJ_CLOSE(m_waitingIcon);
        //m_waitingIcon = NULL;
    
        VFX_OBJ_CREATE(m_timeline, VfxFloatTimeline, this);
        m_timeline->setTarget(m_imageFrame);
        m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_timeline->setFromValue((VfxFloat)0.0);
        m_timeline->setToValue((VfxFloat)1.0f);
        m_timeline->setDuration(500);
        m_timeline->setIsFromCurrent(VFX_FALSE);
        m_timeline->m_signalStopped.connect(this, &VappWidgetDelegator::onAnimationStopped);
        m_timeline->start();

        m_isResizing = VFX_FALSE;

    }


    setImageContent(m_clientWidth, m_clientHeight);

}


void VappWidgetDelegator::onEditorCreated()
{
    m_signalForbidDesktopSwipe.emit(this);
}

void VappWidgetDelegator::onEditorClosed()
{
    m_signalPermitDesktopSwipe.emit(this);
}


kal_mutexid VappWidgetDelegator::createCanvasLock(int id)
{
    static kal_mutexid mutex_id = 0;

    VFX_ASSERT(id < MAX_WIDGETS);

    if (!mutex_id)
    {
        // create mutex
        mutex_id = kal_create_mutex("WIDGET_MUTEX");
    }

    return mutex_id;
}

VfxBool VappWidgetDelegator::checkMemAvaliable(VfxS32 instance_id, VfxU32 size)
{
    VfxU32 allocatedSize = 0;
    
    VfxObjListEntry *iter = VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->getHead();

    while(iter)
    {
        VappWidgetDelegator *p = (VappWidgetDelegator *)iter->get();

        if (p->m_id.getIntType() != instance_id)
        {
            allocatedSize += p->m_clientHeight * p->m_clientWidth * 4 * 2;
        }
        iter = iter->getNext();
    }

    if ((allocatedSize + (size * 2) ) >= VAPP_WIDGET_IDLE_FG_SIZE)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}


VfxBool VappWidgetDelegator::allocImgBuffer(VfxU32 size)
{
    // 4 bytes alignment
    size = ((size + 31) >> 5) << 5;
    m_gid = mmi_frm_group_create(GRP_ID_ROOT, VAPP_WIDGET_DELEGATOR_IDLE, NULL, NULL);

    if (!checkMemAvaliable(m_id.getIntType(), size))
    {
        cancelLoadWidgetPopup(STR_ID_VAPP_WIDGET_REMOVE_SOME_WIDGETS_FIRST);

        return VFX_FALSE;       
    }

    if(!m_imageBuffer1 && m_gid > 0)
    {
        m_imageBuffer1 = (VfxU8 *)med_alloc_asm_mem(m_gid, size);
    }
    
    if(!m_imageBuffer2 && m_gid > 0)
    {
        m_imageBuffer2 = (VfxU8 *)med_alloc_asm_mem(m_gid, size);
    }


    if (!m_imageBuffer1 || !m_imageBuffer2)
    {
        cancelLoadWidgetPopup(STR_ID_VAPP_WIDGET_MEMORY_FULL);

        return VFX_FALSE;
    }
        
    VFX_ASSERT(m_imageBuffer1 || m_imageBuffer2);
    
    memset(m_imageBuffer1, 0, size);
    memset(m_imageBuffer2, 0, size);
    
    return VFX_TRUE;
}


void VappWidgetDelegator::freeImgBuffer()
{
    if (m_imageBuffer1)
    {
        med_free_asm_mem(m_gid, (void **) &m_imageBuffer1);
        m_imageBuffer1 = NULL;
    }
    
    if (m_imageBuffer2)
    {
        med_free_asm_mem(m_gid, (void **) &m_imageBuffer2);
        m_imageBuffer2 = NULL;
    }

    if (m_instance_count == 0 && m_gid > 0)
    {
        mmi_frm_group_close(m_gid);
    }

}


void VappWidgetDelegator::setImageContent(VfxU32 width, VfxU32 height)
{

    VfxImageBuffer imageBuf;

    kal_take_mutex(m_canvasLock);

    if (!isCreated() || m_drawedBuffer == 0)
    {
        kal_give_mutex(m_canvasLock);
        return ;
    }

    // get the unused image buffer
    if (m_drawedBuffer == 2)
    {
        imageBuf.ptr = (VfxU8 *)m_imageBuffer2;
    }
    else
    {
        imageBuf.ptr = (VfxU8 *)m_imageBuffer1;
    }

    // set image buffer source
    imageBuf.pitchBytes = width * 4;
    imageBuf.width = width;
    imageBuf.height = height;
    imageBuf.colorFormat = VRT_COLOR_TYPE_ARGB8888;

    // adjust widget idle view's position (only at first time)
    if (m_imageFrame->getSize() == getMaxSize())
    {
        if (m_hasSetBut)
        {
            m_imageFrame->setSize(
                (VfxS32)(width * getResizeRatio(m_id.getIntType())), 
                (VfxS32)((height * getResizeRatio(m_id.getIntType())) + m_buttonSetting->getSize().height));
         }
        else
        {
            m_imageFrame->setSize(
                (VfxS32)(width * getResizeRatio(m_id.getIntType())), 
                (VfxS32)(height * getResizeRatio(m_id.getIntType())));
        }
        VfxU32 x, y;
        x = m_imageFrame->getPos().x + 
            getMaxSize().width/2 - 
            m_imageFrame->getSize().width/2;
        y = m_imageFrame->getPos().y + 
            getMaxSize().height/2 - 
            m_imageFrame->getSize().height/2;
        m_imageFrame->setPos(x, y);   
        
        m_isResizing = VFX_FALSE;
    }
    else if(m_isResizing)
    {
        VfxU32 x, y;
        x = (VfxS32)(m_imageFrame->getPos().x + 
            m_imageFrame->getSize().width/2 - width * getResizeRatio(m_id.getIntType())/2);
        y = (VfxS32)(m_imageFrame->getPos().y + 
            m_imageFrame->getSize().height/2 - height * getResizeRatio(m_id.getIntType())/2);
        m_imageFrame->setPos(x, y);   

        if (m_hasSetBut)
        {
			m_imageFrame->setSize(
                (VfxS32)(width * getResizeRatio(m_id.getIntType())), 
                (VfxS32)((height * getResizeRatio(m_id.getIntType())) + m_buttonSetting->getSize().height));
            x = (VfxS32)(x + width * getResizeRatio(m_id.getIntType()) - m_buttonSetting->getSize().width / 2);
            y = (VfxS32)(y + height * getResizeRatio(m_id.getIntType()) + m_buttonSetting->getSize().height / 2 + SETBUT_MARGIN_GAP);
            m_buttonSetting->setPos(x, y);
        }
        else
        {
            m_imageFrame->setSize(
                (VfxS32)(width * getResizeRatio(m_id.getIntType())), 
                (VfxS32)(height * getResizeRatio(m_id.getIntType())));
        }


        m_isResizing = VFX_FALSE;
    }
    
    m_usedBuffer = imageBuf.ptr;
    m_imageFrame->forceImgContent(VfxImageSrc(imageBuf));
    m_imageFrame->setSize(
        (VfxS32)(width * getResizeRatio(m_id.getIntType())), 
        (VfxS32)(height * getResizeRatio(m_id.getIntType())));
    m_imageFrame->setBorder(VFX_COLOR_TRANSPARENT, 0);
    m_imageFrame->setOpacity(1.0f);
    m_imageFrame->setBgColor(VFX_COLOR_TRANSPARENT);

    kal_give_mutex(m_canvasLock);
}


VfxPoint VappWidgetDelegator::getSettingButtonPos(int widget_width, int widget_height) const
{
    VfxSize image_size = m_buttonSetting->getSize();
    VfxPoint pos;
    
    VfxU32 x, y;
    x = m_imageFrame->getPos().x + getMaxSize().width/2 + widget_width/2;
    y = m_imageFrame->getPos().y + getMaxSize().height/2 + widget_height/2;


    pos.x = x - (image_size.width >> 1);  // - SETBUT_MARGIN_GAP;
    pos.y = y - (image_size.height >> 1) + SETBUT_MARGIN_GAP;

    return pos;
}


void VappWidgetDelegator::onTlSetBut(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);

    if (isCompleted)
    {
        m_buttonSetting->setHidden(VFX_TRUE);
        m_buttonSetting->setOpacity(0.0f);
    }
}


void VappWidgetDelegator::onTimerSetBut(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    m_tlSetBut->start();
}

void VappWidgetDelegator::onAnimationStopped(VfxBaseTimeline *timeline, VfxBool stop)
{
    if (stop && m_timeline)
    {
        m_timeline->stop();
        VFX_OBJ_CLOSE(m_timeline);
        m_timeline = NULL;
    }
}

void VappWidgetDelegator::launchSetting(VfxObject *obj, VfxId id)
{
    m_timerSetBut->stop();
    if (!m_buttonPressed)
    {
        m_buttonPressed = VFX_TRUE;
        vapp_widget_show_setting_dialog(m_id.getIntType());
    }
}


#endif /* __MMI_GADGET_SUPPORT__ */
