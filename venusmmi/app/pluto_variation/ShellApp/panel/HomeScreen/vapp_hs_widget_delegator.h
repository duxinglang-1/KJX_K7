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
 *  vapp_hs_widget_delegator.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Definition of widget delegator
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
#ifndef __VAPP_HS_WIDGET_DELEGATOR_H__
#define __VAPP_HS_WIDGET_DELEGATOR_H__

#include "MMI_features.h"

#ifdef __MMI_GADGET_SUPPORT__
//#include "vfx_uc_include.h"
//#include "vapp_hs_res.h"
#include "vapp_hs_widget_base.h"
#include "ui_core\pme\vfx_object_list.h"
//#include "vcp_include.h"

#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_datatype.h"
#include "vapp_hs_def.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_primitive_frame.h"
#include "vcp_button.h"
#include "vfx_animation.h"
extern "C"
{
#include "kal_public_defs.h"
}

class VcpWidgetDelegator;

class VappWidgetObjectList :
    public VfxObject
{
    VFX_DECLARE_CLASS(VappWidgetObjectList);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWidgetObjectList);

public:    
    VappWidgetObjectList() {};
    ~VappWidgetObjectList() {};

public:
    VfxObjList getList()
    {
        return m_list;
    };

    VfxObjListEntry *append(VfxObject *obj)
    { 
        return m_list.append(obj);
    };
    
    VfxBool removeOne(VfxObject *obj)
    {
        return m_list.removeOne(obj);
    };

    VfxObjListEntry *getHead() const
    {
        return m_list.getHead();
    }

private:
    VfxObjList m_list;
};

class VappHsWidgetDelegator :
    public VappHsWidget
{
public:
    static inline void *createWidget(int id, VfxObject *parentObj)
    {
        VappHsWidgetDelegator *widget;
        VFX_OBJ_CREATE(widget, VappHsWidgetDelegator, parentObj);
        widget->setId(id);

        return widget;
    }

    inline VfxS32 getType()
    {
        return VAPP_HS_WIDGET_TYPE_GADGET;
    }

    inline VfxS32 getId()
    {
        return m_id;
    }

    enum State{
        NONE,
        LOADING,
        LOADED,
        LOAD_FAILED,
        UNLOADED,
        MAX_REACHED
    };

public:
    VappHsWidgetDelegator();

    virtual ~VappHsWidgetDelegator(void);

    // get the image ID of widget bar icon
    virtual VfxU16 getIcon() { return 0; }

    // create widget bar icon frame, m_controlIcon
    virtual VfxBool onCreateIconView();

    // release widget bar icon frame
    virtual void onReleaseIconView();

    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onAddToDesktop();
    virtual void onRemoveFromDesktop();
    virtual void onDeselect();
    virtual void onEnterTop();
    virtual void onLeaveTop();

    void *lockCanvas(void **buffer, int width, int height);

    static void unlockCanvas(void *lock);

    virtual VfxPoint getSettingButtonPos(int, int) const;

    virtual VfxBool onPenInput(VfxPenEvent &event);
    static VappHsWidgetDelegator *findByInstancId(int instance_id)
    {
        VfxObjListEntry *iter = VFX_OBJ_GET_INSTANCE(VappWidgetObjectList)->getHead();

        while(iter)
        {
            VappHsWidgetDelegator *p = (VappHsWidgetDelegator *)iter->get();
            if(p->m_id == instance_id)
            {
                return p;
            }
            iter = iter->getNext();
        }
        return NULL;
    }

    void onTerminate();
    void onWidgetLoadResult(int result, void *view_handle, int width, int height);
    void onWidgetResize(int width, int height);
    void *getViewHandle(void);
    void onWidgetContentUpdate(void *buffer);
    void onLoadingTimerExpired(
        VfxTimer *timer             // [IN] timer
    );

private:
    static int m_instance_count;

    inline void setId(int id)
    {
        m_id = id;
    }

    // constant
    enum
    {
        SETBUT_MARGIN_GAP   = 5,    // margin gap of setting button
        SETBUT_APPEAR_TIME  = 2000, // appearance time of setting button
        SETBUT_FADEOUT_TIME = 250   // fadeout time of setting button
    };

    // widget bar icon image
    VfxImageSrc     m_imageIcon;
    VfxImageFrame   *m_dragImage;
    VcpWidgetDelegator *m_impl;
    //static VfxObjList m_list;
    int m_id;
    void *m_viewHandle;
    State m_widgetStatus;
    bool m_isDragging;
    bool m_isResizing;
    bool m_buttonPressed;
    VfxBool m_focused;
    int m_clientWidth;
    int m_clientHeight;

    VfxTimer        *m_timerLoading;
    VfxImageFrame   *m_imageLoading;

    // Whether there is a setting button
    VfxBool         m_hasSetBut;

    // Setting button to launch related application
    VcpButton       *m_buttonSetting;

    // Timer of setting button disappearance
    VfxTimer        *m_timerSetBut;

    // Timeline of fade-out animation for setting button
    VfxFloatTimeline    *m_tlSetBut;
    // After setting button is pressed, enter related application
    // RETURNS: void
    void launchSetting(VfxObject *obj, VfxId id);

    // After time-out, setting button starts disappearing
    // RETURNS: void
    void onTimerSetBut(VfxTimer *timer);

    // After fade-out, setting button will be hidden
    // RETURNS: void
    void onTlSetBut(VfxBaseTimeline *timeline, VfxBool isCompleted);

    VfxU8 *m_gdiBuffer;

    static kal_mutexid createCanvasLock(int id);

    kal_mutexid m_canvasLock;

    // Screen group id (use to allocate memory)
    static mmi_id m_gid;
};
#endif /* __MMI_GADGET_SUPPORT__ */
#endif /* __VAPP_HS_WIDGET_DELEGATOR_H__ */
