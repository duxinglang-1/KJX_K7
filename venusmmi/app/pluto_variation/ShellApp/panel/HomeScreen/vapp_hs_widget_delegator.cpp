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
 *  vapp_hs_widget_delegator.cpp
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
//#include "vfx_uc_include.h"

#include "MMI_features.h"

#ifdef __MMI_GADGET_SUPPORT__

//#include "vapp_hs_res.h"
//#include "vapp_hs_cp.h"
#include "vcp_pluto_control.h"
#include "vapp_hs_widget_delegator.h"
extern "C"
{
#include "string.h"
#include "stdio.h"

#include "widget_api.h"
#include "mmi_rp_app_widget_delegator_def.h"
#include "widget_adp_struct.h"
#include "gadget_adp_audio_service.h"
#include "gadget_adp_avplugin.h"
#include "kal_general_types.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"

#include "MMIDataType.h"
#include "kal_public_api.h"
#include "med_smalloc.h"
#include "kal_public_defs.h"

#include "mmi_frm_mem_gprot.h"

//#include "gdi_mutex.h"      // for gdi_fast_mutex_get_count(void);
#include "med_utility.h" // TODO: remove this after using VRT memory API
#include "wgtmgrsrvgprot.h"
#ifdef __MMI_USB_SUPPORT__
 #include "USBSrvGProt.h"
#endif

#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"    
#include "mmi_frm_mem_gprot.h"
}


#include "vfx_object_list.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_primitive_frame.h"
#include "vfx_signal.h"
#include "vfx_timer.h"
#include "vfx_auto_animate.h"
#include "vcp_button_internal.h"
#include "vfx_animation.h"
#include "vrt_datatype.h"
#include "vfx_input_event.h"
#include "vapp_hs_widget_base.h"

#if defined(LIBRA35_DEMO_BB) || defined(AMBER38_DEMO_BB)
#define MAX_WIDGETS 8
#elif defined(UNICORN53V3_DEMO_EVB) || defined(UNICORN53V4_DEMO_EVB)
#define MAX_WIDGETS 3
#else
#define MAX_WIDGETS 10
#endif

//VfxObjList VappHsWidgetDelegator::m_list;

int VappHsWidgetDelegator::m_instance_count = 0;
mmi_id VappHsWidgetDelegator::m_gid = 0;


VFX_IMPLEMENT_CLASS("VappWidgetObjectList", VappWidgetObjectList, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWidgetObjectList);

class VcpWidgetDelegator : public VcpPlutoControl
{
    VFX_DECLARE_CLASS(VcpWidgetDelegator);

private:
    unsigned char *updateLayerBuffer;

public:
    VcpWidgetDelegator():
        updateLayerBuffer(NULL)        
    {
    }

    ~VcpWidgetDelegator()
    {
    }

    void onPlutoCreate()
    {
    }

    void onPlutoClose()
    {
    }

    void onPlutoDraw()
    {
        unsigned char *layer_buffer = NULL;
        GDI_HANDLE layer = getLayerHandle();

        if (!layer)
        {
            ((VappHsWidgetDelegator *)getParent())->onTerminate();
            return;
        }

        if (updateLayerBuffer != NULL)
        {
            gdi_layer_push_and_set_active(layer);

            gdi_layer_get_buffer_ptr(&layer_buffer);

            memcpy(layer_buffer, updateLayerBuffer, getBounds().getWidth() * getBounds().getHeight() * 4);

            gdi_layer_pop_and_restore_active();

            setNeedRedrawPluto();

            updateLayerBuffer = NULL;
        }
    }

    void onWidgetContentUpdate(unsigned char *buffer)
    {
        unsigned char *layer_buffer = NULL;
        GDI_HANDLE layer = getLayerHandle();

        updateLayerBuffer = buffer;

        if (!layer)
        {
            return;
        }

        gdi_layer_push_and_set_active(layer);

        gdi_layer_get_buffer_ptr(&layer_buffer);


        memcpy(layer_buffer, buffer, getBounds().getWidth() * getBounds().getHeight() * 4);

        gdi_layer_pop_and_restore_active();

        setNeedRedrawPluto();
    }

    VfxBool onPlutoNeedAlphaChannel()
    {
        // Use PNG background image in theme
        return VFX_TRUE;
    }

    VfxSize onPlutoGetPreferredSize()
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        return getCurrentSize();
    }

};

VFX_IMPLEMENT_CLASS("WidgetDelegator", VcpWidgetDelegator, VcpPlutoControl);


VappHsWidgetDelegator::VappHsWidgetDelegator() : m_id(0), m_viewHandle(NULL), m_widgetStatus(UNLOADED),
                                                 m_dragImage(NULL), m_imageLoading(NULL), m_timerLoading(NULL),
                                                 m_impl(NULL), m_isDragging(false), m_buttonSetting(NULL), 
                                                 m_timerSetBut(NULL), m_tlSetBut(NULL), m_hasSetBut(VFX_FALSE),
                                                 m_isResizing(false), m_clientWidth(0), m_clientHeight(0), m_gdiBuffer(NULL),
                                                 m_focused(VFX_FALSE), m_buttonPressed(false)
{
    VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->append(this);
    m_canvasLock = createCanvasLock(m_id);
}


VappHsWidgetDelegator::~VappHsWidgetDelegator(void)
{
    VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->removeOne(this);
}

VfxBool VappHsWidgetDelegator::onCreateIconView()
{
    // background image
    WCHAR icon_path[260];

    srv_wgtmgr_get_downloaded_wgt_icon_path(m_id, icon_path);

    m_imageIcon.setPath(VFX_WSTR_MEM((const VfxWChar *)(icon_path)));

    m_controlIcon->setImgContent(m_imageIcon);
    m_controlIcon->setBounds(VfxRect(VFX_POINT_ZERO, m_imageIcon.getSize()));

    return VFX_TRUE;
}


void VappHsWidgetDelegator::onReleaseIconView()
{
    m_controlIcon->setImgContent(VFX_IMAGE_SRC_NULL);
}

void VappHsWidgetDelegator::onCreateView(void)
{
    WCHAR icon_path[260];

    widget_set_widget_active_flag(MMI_TRUE);

    VFX_OBJ_CREATE(m_dragImage, VfxImageFrame, this);

    srv_wgtmgr_get_downloaded_wgt_icon_path(m_id, icon_path);

    m_hasSetBut = srv_wgtmgr_is_wgt_setting_available(m_id);

    m_dragImage->setSrc(VFX_WSTR_MEM((const VfxWChar *)(icon_path)));

    setBounds(m_dragImage->getBounds());

	m_widgetStatus = UNLOADED;

    if (m_instance_count++ == 0)
    {
        widget_initialize();
    }
}

void VappHsWidgetDelegator::onAddToDesktop(void)
{
    if (m_instance_count > MAX_WIDGETS)
    {
        m_signalReset.emit(this, STR_ID_WIDGET_MAXIMUM_REACHED);
        return;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if(srv_usb_is_in_mass_storage_mode_ext() == MMI_TRUE)
    {
        m_dragImage->setResId(IMG_ID_WIDGET_LOAD_FAILED);
        return;
    }
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

    VFX_OBJ_CLOSE(m_dragImage);
    m_dragImage = NULL;

    // create loading image
    VFX_OBJ_CREATE(m_imageLoading, VfxImageFrame, this);

    m_imageLoading->setResId(IMG_ID_WIDGET_LOADING_0);

    // create idle timer
    VFX_OBJ_CREATE(m_timerLoading, VfxTimer, this);
    m_timerLoading->setDuration(250);
    m_timerLoading->m_signalTick.connect(this, &VappHsWidgetDelegator::onLoadingTimerExpired);
    m_timerLoading->start();


    setBounds(m_imageLoading->getBounds());

    widget_load_widget(m_id);

    m_widgetStatus = LOADING;
}

void VappHsWidgetDelegator::onWidgetLoadResult(int result, void *view_handle, int width, int height)
{
    if (!isCreated() || m_widgetStatus != LOADING)
    {
        return;
    }

	if (result != 0)
    {
    	switch(result)
    	{
        case WIDGET_WAIT_FOR_UNLOADING:
            widget_load_widget(m_id);
            return;
    	case WIDGET_PERMISSION_NOT_GRANTED:
	        m_signalReset.emit(this, STR_ID_WIDGET_PERMISSION_NOT_GRANTED);
	        return;
        case WIDGET_PATH_NOT_FOUND:
	        m_signalReset.emit(this, STR_ID_WIDGET_PATH_NOT_FOUND);
	        return;
    	case WIDGET_FAILED_LOAD_GADGET:
    	case WIDGET_HOST_NOT_INITIALIZED:
	        m_signalReset.emit(this, STR_ID_WIDGET_FAILED_LOAD_WIDGET);
	        return;
    	case WIDGET_MEMORY_FULL:
	        m_signalReset.emit(this, STR_ID_WIDGET_MEMORY_FULL);
	        return;
	    default:
	    	ASSERT(0);
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

    if (m_gdiBuffer)
    {
        ASSERT(m_gid);

        med_free_asm_mem(m_gid, (void **) &m_gdiBuffer);
    }

    // Allocate layer buffer
    int size = m_clientWidth * m_clientHeight * 4;

    // 4 bytes alignment
    size = ((size + 31) >> 5) << 5;
    if (m_gid == 0)
    {
        m_gid = mmi_frm_group_create(GRP_ID_ROOT, APP_WIDGET_DELEGATOR_IDLE, NULL, NULL);
    }

    m_gdiBuffer = (VfxU8 *) med_alloc_asm_mem(m_gid, size);

    if (!m_gdiBuffer)
    {
        widget_unload_widget(m_id);
        m_widgetStatus = UNLOADED;
        m_signalReset.emit(this, STR_ID_WIDGET_MEMORY_FULL);
        return;
    }

    memset(m_gdiBuffer, 0, size);
    widget_update_content(m_id, m_viewHandle);

}


void VappHsWidgetDelegator::onTerminate()
{
    m_signalReset.emit(this, STR_ID_WIDGET_MEMORY_FULL);
}


void VappHsWidgetDelegator::onWidgetResize(int width, int height)
{
	if (!isCreated())
	{
		return;
	}

    if (m_clientWidth == width && m_clientHeight == height)
    {
        /* This usually happens when the widget is still loading, skip the update for little gain of performance */
        return;
    }

    m_isResizing = true;
    m_clientWidth = width;
    m_clientHeight = height;

    kal_take_mutex(m_canvasLock);

    if (m_gdiBuffer)
    {
        ASSERT(m_gid);

        med_free_asm_mem(m_gid, (void **) &m_gdiBuffer);
    }

    // Allocate layer buffer
    int size = m_clientWidth * m_clientHeight * 4;

    // 4 bytes alignment
    size = ((size + 31) >> 5) << 5;
    if (m_gid == 0)
    {
        m_gid = mmi_frm_group_create(GRP_ID_ROOT, APP_WIDGET_DELEGATOR_IDLE, NULL, NULL);
    }

    m_gdiBuffer = (VfxU8 *) med_alloc_asm_mem(m_gid, size);

    if (!m_gdiBuffer)
    {
        kal_give_mutex(m_canvasLock);
        widget_unload_widget(m_id);
        m_widgetStatus = UNLOADED;
        m_signalReset.emit(this, STR_ID_WIDGET_MEMORY_FULL);
        return;
    }

    memset(m_gdiBuffer, 0, size);

    kal_give_mutex(m_canvasLock);

    widget_update_content(m_id, m_viewHandle);
}

kal_mutexid VappHsWidgetDelegator::createCanvasLock(int id)
{
    static kal_mutexid mutex_pool[MAX_WIDGETS] = {0};

    ASSERT(id < MAX_WIDGETS);

    if (mutex_pool[id])
    {
        return mutex_pool[id];
    }

    {
        char name[20];
        sprintf(name, "WIDGET%02d", id);
        mutex_pool[id] = kal_create_mutex(name);
        return mutex_pool[id];
    }
}

void *VappHsWidgetDelegator::lockCanvas(void **buffer, int width, int height)
{
    canvas_lock_struct *lock = NULL;

    int buffer_size = width * height * 4; 

    kal_take_mutex(m_canvasLock);

    if (m_gdiBuffer && m_clientWidth == width && m_clientHeight == height)
    {
        lock = (canvas_lock_struct *)OslMalloc(sizeof(canvas_lock_struct));

        memset(lock, 0, sizeof(canvas_lock_struct));

        lock->mutex = m_canvasLock;
        lock->unlock_canvas = VappHsWidgetDelegator::unlockCanvas;
        lock->context = this;

        memset(m_gdiBuffer, 0, buffer_size);
        *buffer = m_gdiBuffer;
    }
    else
    {
        kal_give_mutex(m_canvasLock);
        return NULL;
    }

    return lock;
}

void VappHsWidgetDelegator::unlockCanvas(void *p)
{
    canvas_lock_struct *lock = (canvas_lock_struct *)p;
    VappHsWidgetDelegator *delegator;

    ASSERT(lock);

    delegator = (VappHsWidgetDelegator *)lock->context;

    ASSERT(delegator);

    ASSERT(lock->mutex == delegator->m_canvasLock);

    kal_give_mutex(delegator->m_canvasLock);

    OslMfree(lock);
}

void VappHsWidgetDelegator::onRemoveFromDesktop(void)
{
    m_isDragging = true;
}

void VappHsWidgetDelegator::onDeselect(void)
{
    if (m_widgetStatus == LOADED)
    {
        widget_unload_widget(m_id);
        m_widgetStatus = UNLOADED;
    }
}

void VappHsWidgetDelegator::onReleaseView(void)
{
    m_instance_count--;
    if (m_widgetStatus == LOADED && m_instance_count == 0)
    {
        gadget_adp_audio_service_suspend();
        gadget_adp_avplugin_notify_suspend();

        /* We check if the interrupt here is due to confirm dialog raised from Gadget engine
           to avoid plugin reset in this scenario. */
        if (g_confirm_dialog_gid == 0)
        {
            gadget_adp_avplugin_notify_reset();
        }
        
        widget_disable_view_cache();
    }

    kal_take_mutex(m_canvasLock);
    if (m_gdiBuffer)
    {
        ASSERT(m_gid);

        med_free_asm_mem(m_gid, (void **) &m_gdiBuffer);
        m_gdiBuffer = NULL;
    }
    kal_give_mutex(m_canvasLock);

    if (m_hasSetBut)
    {
        VFX_OBJ_CLOSE(m_buttonSetting);
        VFX_OBJ_CLOSE(m_timerSetBut);
        VFX_OBJ_CLOSE(m_tlSetBut);
    }

    VFX_OBJ_CLOSE(m_dragImage);
    m_dragImage = NULL;

    VFX_OBJ_CLOSE(m_impl);
    VFX_OBJ_CLOSE(m_imageLoading);

    if (m_timerLoading)
    {
        m_timerLoading->stop();
        VFX_OBJ_CLOSE(m_timerLoading);
    }

    // TODO: instance count == 0???
    if (m_instance_count == 0)
    {
        mmi_frm_group_close(m_gid);
    }
    
    widget_set_widget_active_flag(MMI_FALSE);
}

void *VappHsWidgetDelegator::getViewHandle(void)
{
    return m_viewHandle;
}

void VappHsWidgetDelegator::onWidgetContentUpdate(void *buffer)
{
    if (!isCreated() || m_widgetStatus != LOADED || m_gdiBuffer == NULL)
    {
        return;
    }

    if (!m_impl)
    {
        int width = m_clientWidth, height = m_clientHeight;

        VFX_OBJ_CREATE(m_impl, VcpWidgetDelegator, this);

        m_impl->setBounds(VfxRect(0, 0, width, height));

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        if (m_hasSetBut)
        {
            // create button
            VfxImageSrc imageUp = VfxImageSrc(IMG_ID_WIDGET_SETTING_BUTTON_UP);
            VfxImageSrc imageDown = VfxImageSrc(IMG_ID_WIDGET_SETTING_BUTTON_DOWN);

            height += imageUp.getSize().height;
            
            VFX_OBJ_CREATE(m_buttonSetting, VcpButton, this);
            m_buttonSetting->setAnchor(VfxFPoint(0.5, 0.5));
            m_buttonSetting->setSize(imageUp.getSize());
            m_buttonSetting->setPos(getSettingButtonPos(width, height));
            m_buttonSetting->setHidden(VFX_TRUE);
            m_buttonSetting->setOpacity(0.8f);
            m_buttonSetting->setBgImageList(
                VcpStateImage(IMG_ID_WIDGET_SETTING_BUTTON_UP, 
                              IMG_ID_WIDGET_SETTING_BUTTON_DOWN,
                              IMG_ID_WIDGET_SETTING_BUTTON_UP,
                              IMG_ID_WIDGET_SETTING_BUTTON_UP));
            m_buttonSetting->m_signalClicked.connect(this, &VappHsWidgetDelegator::launchSetting);

            // create timer
            VFX_OBJ_CREATE(m_timerSetBut, VfxTimer, this);
            m_timerSetBut->setStartDelay(SETBUT_APPEAR_TIME);
            m_timerSetBut->m_signalTick.connect(this, &VappHsWidgetDelegator::onTimerSetBut);

            // create timeline to fadeout setting button
            VFX_OBJ_CREATE(m_tlSetBut, VfxFloatTimeline, this);
            m_tlSetBut->setTarget(m_buttonSetting);
            m_tlSetBut->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
            m_tlSetBut->setToValue(0.0f);
            m_tlSetBut->setDurationTime(SETBUT_FADEOUT_TIME);
            m_tlSetBut->m_signalStopped.connect(this, &VappHsWidgetDelegator::onTlSetBut);
        }

      	setBounds(VfxRect(0, 0, width, height));

        setOpacity(0.0f);
        VfxAutoAnimate::commit();

        m_imageLoading->setOpacity(0.0f);
        setOpacity(1.0f);

        /* Cannot delete the image here otherwise fade out animation will fail */
        //VFX_OBJ_CLOSE(m_imageLoading);

        m_timerLoading->stop();
        VFX_OBJ_CLOSE(m_timerLoading);

        m_isResizing = false;
    }
    else if (m_isResizing)
    {
        int x, y, width = m_clientWidth, height = m_clientHeight;
        VfxPoint currentPos = getPos();
        x = currentPos.x - getBounds().getWidth() / 2;
        y = currentPos.y - getBounds().getHeight() / 2;
        m_impl->setBounds(VfxRect(0, 0, width, height));

        if (m_hasSetBut && m_buttonSetting)
        {
            height += m_buttonSetting->getSize().height;
            m_buttonSetting->setPos(getSettingButtonPos(width, height));
        }
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        setBounds(VfxRect(0, 0, width, height));
        currentPos.x = x + width / 2;
        currentPos.y = y + height / 2;
        setPos(currentPos);

        VfxAutoAnimate::commit();

        m_isResizing = false;
    }

    kal_take_mutex(m_canvasLock);
    m_impl->onWidgetContentUpdate((unsigned char *)m_gdiBuffer);
    kal_give_mutex(m_canvasLock);

}

VfxBool VappHsWidgetDelegator::onPenInput(VfxPenEvent &event)
{
    int type = -1;

    if (m_isDragging)
    {
        VappHsWidget::onPenInput(event);

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
        VappHsWidget::onPenInput(event);
    }

    VfxPoint pos(event.getRelPos(this));


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

    widget_handle_pen_event(m_id, m_viewHandle, pos.x, pos.y, type);
    return VFX_TRUE;
}


void VappHsWidgetDelegator::onLoadingTimerExpired(VfxTimer *timer)
{
    static int index;

    if (!m_imageLoading)
        return;

    m_imageLoading->setResId(IMG_ID_WIDGET_LOADING_0 + (++index % 8));

}

void VappHsWidgetDelegator::onTlSetBut(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);

    if (isCompleted)
    {
        m_buttonSetting->setHidden(VFX_TRUE);
        m_buttonSetting->setOpacity(0.0f);
    }
}


void VappHsWidgetDelegator::onTimerSetBut(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    m_tlSetBut->start();
}


void VappHsWidgetDelegator::launchSetting(VfxObject *obj, VfxId id)
{
    m_timerSetBut->stop();
    if (!m_buttonPressed)
    {
        m_buttonPressed = true;
        widget_show_setting_dialog(m_id);
    }
}


VfxPoint VappHsWidgetDelegator::getSettingButtonPos(int widget_width, int widget_height) const
{
    VfxSize image_size = m_buttonSetting->getSize();
    VfxPoint pos;

    pos.x = widget_width - 1 - (image_size.width >> 1) - SETBUT_MARGIN_GAP;
    pos.y = widget_height - 1 - (image_size.height >> 1); // - SETBUT_MARGIN_GAP;

    return pos;
}

void VappHsWidgetDelegator::onEnterTop()
{
    if (m_widgetStatus != LOADED)
    {
        return;
    }

    if (m_focused == VFX_FALSE)
    {
        m_focused = VFX_TRUE;
        widget_focus_in(m_id, m_viewHandle);
    }
}

void VappHsWidgetDelegator::onLeaveTop()
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
        widget_focus_out(m_id, m_viewHandle);
    }
}

#endif /* __MMI_GADGET_SUPPORT__ */
