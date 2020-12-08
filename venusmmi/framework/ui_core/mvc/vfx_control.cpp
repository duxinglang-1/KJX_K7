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
 *  vfx_control.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Core Class VfxControl
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_control.h"

#include "vfx_input_event.h"
#include "vfx_frame.h"
#include "vfx_renderer.h"
#include "vfx_screen.h"
#include "vfx_pen.h"
#include "vfx_keypad.h"
#include "vfx_archive.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"


/***************************************************************************** 
 * Class VfxControl
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_CONTROL_CLASS_NAME, VfxControl, VfxFrame);

VfxControl *VfxControl::getRootControl()
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    VfxFrame *rootFrame = renderer->getRootFrame();
    if (rootFrame == NULL)
    {
        return NULL;
    }

    return VFX_OBJ_DYNAMIC_CAST(rootFrame, VfxControl);
}


VfxControl::VfxControl() :
    m_checkUpdate(VFX_FALSE),
    m_isDisabled(VFX_FALSE),
    m_noAnimUpdate(VFX_FALSE)
{
}


VfxBool VfxControl::getIsDisabled() const
{
    return m_isDisabled;
}


void VfxControl::setIsDisabled(VfxBool isDisabled)
{
    m_isDisabled = isDisabled;
}


VfxControl *VfxControl::getParentControl() const
{
    VfxControl *control = NULL;
    VfxFrame *i;
    for (i = getParentFrame(); i != NULL; i = i->getParentFrame())
    {
        control = VFX_OBJ_DYNAMIC_CAST(i, VfxControl);
        if (control != NULL)
        {
            break;
        }
    }
    return control;
}


VfxScreen *VfxControl::findScreen() const
{
    VfxScreen *screen = NULL;
    VfxFrame *i;
    for (i = getParentFrame(); i != NULL; i = i->getParentFrame())
    {
        screen = VFX_OBJ_DYNAMIC_CAST(i, VfxScreen);
        if (screen != NULL)
        {
            break;
        }
    }
    return screen;
}


VfxBool VfxControl::serialize(VfxArchive &ar)
{
    return onSerialize(ar);
}


void VfxControl::restore(VfxArchive &ar)
{
    onRestore(ar);
}


VfxBool VfxControl::capture(VfxPenAbortReasonEnum reason)
{
    VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
    return penSrv->setCapture(this, reason);
}


VfxBool VfxControl::onKeyInput(VfxKeyEvent &event)
{
    VFX_UNUSED(event);
    
    // do nothing
    return VFX_FALSE;
}


VfxBool VfxControl::onSerialize(VfxArchive &ar)
{
    VFX_UNUSED(ar);
    
    // do nothing
    return VFX_FALSE;
}


void VfxControl::onRestore(VfxArchive &ar)
{
    VFX_UNUSED(ar);
    
    // do nothing
}


VfxBool VfxControl::onPreviewPenInput(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    
    // do nothing
    return VFX_FALSE;
}


VfxBool VfxControl::penInput(VfxPenEvent &event)
{
    if (getIsDisabled())
    {
        return VFX_TRUE;
    }
    
    return onPenInput(event);
}


VfxBool VfxControl::penAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason)
{
    return onPenAbortAccepted(aborter, reason);
}


void VfxControl::checkUpdate()
{
    if (!m_checkUpdate)
    {
        m_checkUpdate = VFX_TRUE;
        vfxPostInvoke0(this, &VfxControl::processUpdate);
    }

    if (VfxAutoAnimate::getDisable())
    {
        m_noAnimUpdate = VFX_TRUE;
    }
}


void VfxControl::processUpdate()
{
    VfxBool noAnimation = m_noAnimUpdate;

    if (m_checkUpdate)
    {
        m_checkUpdate = VFX_FALSE;

        if (noAnimation)
        {
            m_noAnimUpdate = VFX_FALSE;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
        }

        onUpdate();

        if (noAnimation)
        {
            VfxAutoAnimate::commit();
        }
    }
}


VfxBool VfxControl::onPenInput(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    
    // do nothing
    return VFX_FALSE;
}


VfxBool VfxControl::onPenAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason)
{
    VFX_UNUSED(aborter);
    VFX_UNUSED(reason);

    return VFX_TRUE;
}


void VfxControl::processRegisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    VfxControl *parentControl = getParentControl();
    if (parentControl != NULL)
    {
        parentControl->processRegisterAccessKeyHandler(keyCode, target);
    }
}


void VfxControl::processUnregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    VfxControl *parentControl = getParentControl();
    if (parentControl != NULL)
    {
        parentControl->processUnregisterAccessKeyHandler(keyCode, target);
    }
}


void VfxControl::processUnregisterAllAccessKeyHandler(VfxControl *target)
{
    VfxControl *parentControl = getParentControl();
    if (parentControl != NULL)
    {
        parentControl->processUnregisterAllAccessKeyHandler(target);
    }
}


VfxBool VfxControl::processFocusKey(VfxKeyEvent &event)
{
    // If this control is disable, we return the key is not handled.
    if (getIsDisabled())
    {
        return VFX_FALSE;
    }

    return VfxFrame::processFocusKey(event);
}


VfxBool VfxControl::processAccessKey(VfxKeyEvent &event)
{
    VfxBool ret = VFX_FALSE;

    // If this control is disable, we return the key is not handled.
    if (getIsDisabled())
    {
        return VFX_FALSE;
    }

    // handle the key by control itself
    ret = onKeyInput(event);

    return ret;
}

