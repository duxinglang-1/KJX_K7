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
 *  
 *
 * Project:
 * --------
 *  Venus UI
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
#ifdef __MMI_GADGET_SUPPORT__
extern "C"
{
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "task_config.h"      	/* Task creation */

}

#include "vfx_uc_include.h"
#include "vcp_include.h"
	 
#include "widget_adp_struct.h"
#include "vapp_widget_delegator.h"
#include "vapp_widget_view.h"
#include "vapp_widget_editor.h"
#include "vapp_widget_popup_controller.h"
#include "mmi_rp_vapp_widget_delegator_def.h"

VfxWeakPtr <VappWidgetEditorManager> g_manager = NULL;
VfxWChar VappWidgetEditorManager::m_inputBuffer[TEXT_MAX_INPUT_LEN + 1] = {0}; 

/***************************************************************************** 
 * Implementation
 *****************************************************************************/
VfxU32 vapp_widget_editor_transform_method(int type, short pwd)
{
    VfxU32 mmi_method = IMM_INPUT_TYPE_SENTENCE;

    if (pwd)
    {
        if (type == 0)
        {
            mmi_method = IMM_INPUT_TYPE_NUMERIC_PASSWORD;
        }
        else
        {
            mmi_method = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
        }
    }
    else
    {
        switch(type)
        {
            case 0:
                mmi_method = IMM_INPUT_TYPE_KEYPAD_NUMERIC;
                break;
            case 1:
                mmi_method = IMM_INPUT_TYPE_SENTENCE;
                break;
            case 2:
                mmi_method = IMM_INPUT_TYPE_EMAIL;
                break;
            default:
                mmi_method = IMM_INPUT_TYPE_SENTENCE;
                break;
        }
    }
    return mmi_method;

}


void vapp_widget_editor_change_focus(VfxS32 id)
{
    // get parent object
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
    
    if (viewApp)
    {
        viewApp->onFocus();
    }
    else
    {
        VappWidgetDelegator *widget = VappWidgetDelegator::findByInstancId(id);
        
        VFX_ASSERT(widget != NULL);

        widget->onFocus();
        widget->onEditorClosed();
    }

}



// VappWidgetEditorManager implementation
VFX_IMPLEMENT_CLASS("VappWidgetEditorManager", VappWidgetEditorManager, VfxControl);

VappWidgetEditorManager::VappWidgetEditorManager() : 
    m_instanceId(0), 
    m_bufferLen(0), 
    m_viewHandle(NULL), 
    m_passwordField(0), 
    m_textEditor(NULL)
{
}


VfxBool VappWidgetEditorManager::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        textEditorHandler(NULL);
    }

    return VFX_TRUE;
}

void VappWidgetEditorManager::createTextEditor(void *param, VfxObject *parentObj, VfxBool isDetailsView)
{
    widget_enter_text_ind_struct *p = (widget_enter_text_ind_struct*)param;

    VfxU32 inputMethod;
    VfxS32 editorType = 0;

    m_bufferLen = ((p->length) > (TEXT_MAX_INPUT_LEN - 1)) ? (TEXT_MAX_INPUT_LEN - 1) : (p->length);

    memset(m_inputBuffer, 0, sizeof(m_inputBuffer));    

    if (p->length)
    {
        memcpy(m_inputBuffer, p->text, m_bufferLen * sizeof(VfxWChar));
    }

    m_instanceId = p->instance_id;
    m_passwordField = p->password_field;
    editorType = p->multiline;        //0: single line, 1: multi-line

    inputMethod = vapp_widget_editor_transform_method(p->type, p->password_field);

    // Set size of page grid
    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    setRect(VfxRect(0, 0, mainScreenSize.width, mainScreenSize.height));
    setBgColor(VFX_COLOR_BLACK);
    setOpacity((VfxFloat)0.5f);
    setFocused(VFX_TRUE);

    // create widget text editor component
    VFX_OBJ_CREATE_EX(
        m_textEditor, 
        VappWidgetEditor, 
        parentObj,
        (editorType, m_inputBuffer, m_bufferLen, inputMethod, IME_SETTING_FLAG_NONE, isDetailsView));  
}


void VappWidgetEditorManager::closeTextEditor()
{
    if (m_textEditor != NULL && m_textEditor.isValid() == VFX_TRUE)
    {
        VFX_OBJ_CLOSE(m_textEditor);
    }

    vapp_widget_editor_change_focus(m_instanceId);

    VFX_OBJ_CLOSE(g_manager);
    g_manager = NULL;
}


void VappWidgetEditorManager::bindHandler()
{
    // connect the handler to handle button clicked signal
    m_textEditor->m_signalClosed.connect(this, &VappWidgetEditorManager::textEditorHandler);
}

void VappWidgetEditorManager::textEditorHandler(VcpButton* sender)
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if (topLevel->getActivePopup() != NULL)
    {
        return;
    }

    if (!sender)
    {
        closeTextEditor();
        return;
    }

    VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

    if (button->getId() != 0)
    {
        closeTextEditor();
        return;
    }
    
    VFX_OBJ_CLOSE(button);

    // send message
    vapp_widget_handle_enter_text_response(m_viewHandle, VFX_TRUE, m_textEditor->getInputText());

    closeTextEditor();
}



// widget text editor entry
void vapp_widget_handle_enter_text_ind(void *param)
{
    widget_enter_text_ind_struct *p = (widget_enter_text_ind_struct *)param;

#if !defined (__MMI_REDUCED_KEYPAD__)
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        viewApp->onInitEditorPage(p);
    }
    else
    {
        /* Launch widget delegator application */
        VfxAppLauncher::launch( 
            VAPP_WIDGET_DELEGATOR,                  /*app id = VAPP_WIDGET_DELEGATOR*/
            VFX_OBJ_CLASS_INFO(VappWidgetView),
            GRP_ID_ROOT, 
            param, 
            sizeof(widget_enter_text_ind_struct));
    }

#else
    VfxObject *parentObj = NULL;
    VfxBool isDetailsView = VFX_FALSE;

    VappWidgetDelegator *widget = VappWidgetDelegator::findByInstancId(p->instance_id);

    // get parent object
    VappWidgetView *viewApp = 
         (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
     
    if (viewApp)
    {
        viewApp->onDefocus();
        parentObj = viewApp->getActivePage();
        isDetailsView = VFX_TRUE;
    }
    else if (widget)
    {
        widget->onDefocus();
        parentObj = widget->getParent();
        isDetailsView = VFX_FALSE;
        widget->onEditorCreated();
    }
    else
    {
        return ;
    }


    VFX_ASSERT(parentObj != NULL);

    // delete g_manager if it has existed
    if (g_manager != NULL && g_manager.isValid() == VFX_TRUE)
    {
        g_manager->closeTextEditor();

        VFX_OBJ_CLOSE(g_manager);
        g_manager = NULL;
    }

    // new a WgtTextEditorMnanger object
    VFX_OBJ_CREATE(g_manager, VappWidgetEditorManager, parentObj);

    // create text editor 
    g_manager->createTextEditor(p, parentObj, isDetailsView);

    // bind the handler when text editor is closed
    g_manager->bindHandler();
    
#endif /* (__MMI_REDUCED_KEYPAD__)*/

}

int vapp_widget_close_editor_by_id(int instance_id)
{
#if !defined (__MMI_REDUCED_KEYPAD__)
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        viewApp->closeEditorPage();
    }

#else
    // delete g_manager if it has existed
    if (g_manager != NULL && g_manager.isValid() == VFX_TRUE)
    {
        g_manager->closeTextEditor();
        
        VFX_OBJ_CLOSE(g_manager);
        g_manager = NULL;
    }
#endif /* (__MMI_REDUCED_KEYPAD__)*/
    return 0;
}

#endif


