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
 *  vapp_JavaAgencyUITextField.cpp
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
#ifdef __J2ME__
#include "MMI_features.h" 
#include "vapp_JavaAgencyUITextField.h"
#include "mmi_rp_vapp_java_def.h"
#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
#endif
#include "../xml/vfx_xml_loader.h"
#include "MMI_include.h"
#include "vapp_java_adp.h"
#include "vapp_java_srv.h"
#include "vcui_phb_gprot.h"
#include "vapp_ncenter_gprot.h"

extern "C"
{
    #include "jam_internal.h"
    #include "jui_interface.h"

    #include "CommonScreens.h"
    #include "CommonScreensResDef.h"

    #include "JavaAgencyUICommon.h"
    #include "JavaAgencyUITextField.h"

    #include "PhbSrvGprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
#define JAVA_UI_TEXTBOX_EDITOR_LINE_GAP                  36
#endif
	
#if defined(__MMI_MAINLCD_480X800__)
#define JAVA_UI_TEXTBOX_EDITOR_LINE_GAP                  60
#endif
	
#if defined(__MMI_MAINLCD_240X400__)
#define JAVA_UI_TEXTBOX_EDITOR_LINE_GAP                  32
#endif
	
#if defined(__MMI_MAINLCD_240X320__)
#define JAVA_UI_TEXTBOX_EDITOR_LINE_GAP                  32
#endif
	
#define JAVA_UI_TEXTBOX_TICKER_HEIGHT                     (JAVA_UI_TEXTBOX_EDITOR_LINE_GAP)
	//#define JAVA_UI_TEXTBOX_TICKER_HEIGHT 					20
	
#define COMAND_SCREEN  1
#define COMAND_BACK      2
#define COMAND_CANCEL 3
#define COMAND_OK	     4
#define COMAND_HELP       5
#define COMAND_STOP      6
#define COMAND_EXIT        7
#define COMAND_ITEM       8

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static mmi_java_ui_textfield_data_struct *g_mmi_vjava_ui_textfield = NULL;
static VappJavaUITextfieldScr *g_mmi_vjava_ui_textfield_scr = NULL;
extern "C"
{
extern MMI_ID mmi_java_ui_textfield_phone_number_group_id;
}


/***************************************************************************** 
 * Function
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef J2ME_SLIM_MEMORY_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef J2ME_SLIM_MEMORY_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef J2ME_SLIM_MEMORY_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef J2ME_SLIM_MEMORY_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif




#ifndef J2ME_SLIM_MEMORY_SUPPORT
void VappJavaUITextfieldScr::updateSearchItem()
{
    /* Add or Remove Search Item */
    if ((g_mmi_vjava_ui_textfield->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
    {
        if (vfx_sys_wcslen((VfxWChar*)g_mmi_vjava_ui_textfield->text))
        {
            toolBar->removeItem(JAVA_UI_TEXTFIELD_TAB_SEARCH);
        }
        else
        {
            toolBar->addItem(JAVA_UI_TEXTFIELD_TAB_SEARCH, STR_GLOBAL_SEARCH, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
        }
    }
}
#endif
VfxResId VappJavaUITextfieldScr::gettoolBarItemIcon(kal_int32 command_type)
{
    switch(command_type)
    {
        case COMAND_SCREEN:
		 return VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND;
        case COMAND_BACK:
		return VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL;
	case COMAND_CANCEL:
		return VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL;
	case COMAND_OK:
		return VCP_IMG_TOOL_BAR_COMMON_ITEM_OK;
	case COMAND_HELP:
		return VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH;
	case COMAND_STOP:
		return VCP_IMG_TOOL_BAR_COMMON_ITEM_REMOVE;
	case COMAND_EXIT:
		return VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT;
	case COMAND_ITEM:
		return VCP_IMG_TOOL_BAR_COMMON_ITEM_LIST;
    default:
	    return VCP_IMG_TOOL_BAR_COMMON_ITEM_OK;
		
		
    }
}
void VappJavaUITextfieldScr::onInit()
{
    VfxU32 i = 0;
    VfxAppCatScr::onInit();

    scr_width = getSize().width; 
    scr_height = getSize().height;
    vk_mode = VFX_FALSE;
    vk_height = 0;

    setBgColor(VFX_COLOR_WHITE);

	
    /* Create StatusBar */
    VFX_OBJ_CREATE(statusBar, VcpStatusIconBar, this);
    statusbar_height = statusBar->getSize().height;
    statusBar->setPos(0, 0);
    statusBar->setSize(scr_width, statusbar_height);


    /* Create Title */	
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title_height = title->getSize().height;
    title->setPos(0,statusbar_height);
    title->setSize(scr_width, title_height);
    title->setTitle(STR_GLOBAL_TEXT);

    /* Create TextEditor */
	VFX_OBJ_CREATE(textEditor, VcpTextEditor , this);
   
	
    /* Create ToolBar */
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->setPos(0,scr_height -getToolbarHeight());
    toolBar->setSize(scr_width,getToolbarHeight());
    toolBar->m_signalButtonTap.connect(this, &VappJavaUITextfieldScr::onTBClick);
    toolBar->m_signalBarFolded.connect(this, &VappJavaUITextfieldScr::onFolding);
	toolBar->addItem(JAVA_UI_TEXTFIELD_TAB_OK, STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
#ifndef J2ME_SLIM_MEMORY_SUPPORT
    /* cosmos slim do not support search */
    if ((g_mmi_vjava_ui_textfield->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER && 
        !mmi_ucs2strlen((PS8)g_mmi_vjava_ui_textfield->text))
    {
        toolBar->addItem(JAVA_UI_TEXTFIELD_TAB_SEARCH, STR_GLOBAL_SEARCH, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
    }
#endif

    /* Set TextEditor */
    resizeTextEidtor();

    if ((g_mmi_vjava_ui_textfield->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SENTENCE ||
        (g_mmi_vjava_ui_textfield->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_EMAIL ||
        (g_mmi_vjava_ui_textfield->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_URL)
    {
        textEditor->setIME((VfxU64)g_mmi_vjava_ui_textfield->constraints, (VfxU32)IME_JAVA_SPECIAL_SYMBOL);
    }
    else
    {
		if((g_mmi_vjava_ui_textfield->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SIGNED_NUMERIC ||
			(g_mmi_vjava_ui_textfield->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER ||
			(g_mmi_vjava_ui_textfield->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)
		{
			textEditor->setIME((VfxU64)g_mmi_vjava_ui_textfield->constraints,IME_DISABLE_NEW_LINE_SYMBOL);
		}
		else
		{
            textEditor->setIME((VfxU64)g_mmi_vjava_ui_textfield->constraints);
		}
    }
	
    textEditor->setText((VfxWChar*)g_mmi_vjava_ui_textfield->text, g_mmi_vjava_ui_textfield->max_size - 1);               
    textEditor->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    textEditor->disableBackground(VFX_TRUE);
    textEditor->setBgColor(VFX_COLOR_WHITE);
    textEditor->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
	textEditor->setCounterDisplayMode(VCP_TEXT_COUNTER_DISP_AUTO);
    textEditor->m_signalActivated.connect(this, &VappJavaUITextfieldScr::onTextBoxActivated); 
    textEditor->m_signalTextChanged.connect(this, &VappJavaUITextfieldScr::onTextChanged);       


	textEditor->setIsDisabled(VFX_FALSE);
	textEditor->setAutoActivated(VFX_FALSE);


#ifndef J2ME_SLIM_MEMORY_SUPPORT
    updateSearchItem();
#endif

}

void VappJavaUITextfieldScr::onDeinit()
{

	VfxAppCatScr::onDeinit();

}


VfxS32 VappJavaUITextfieldScr::getToolbarHeight()
{
	return toolBar ? toolBar->getSize().height : 0;
}

VfxS32 VappJavaUITextfieldScr::getTextEditorHeight()
{
    if(textEditor)
    {
        /* vk appear */
        if(vk_mode)
        {
            return scr_height -statusbar_height -title_height -vk_height ;
        }
	/* vk disapear */
        else
        {
            return scr_height -statusbar_height -title_height -getToolbarHeight() ;
        }
    }
    else
    {
        return 0;
    }

}

void VappJavaUITextfieldScr::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_ADJUST_IME_RESIZE:
        {
            VfxFrameAdjustImeResizeData *data = (VfxFrameAdjustImeResizeData *)userData;
			adjustImeResize(data->size,data->focusFrame);
            return;
        }
		case VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE:
		{
			VfxFrameImeModeEnum *data = (VfxFrameImeModeEnum*)userData;
			*data = VFX_FRAME_IME_MODE_RESIZE;
			return;
		}
        default:
        {
            VfxAppCatScr::onObjectNotify(id, userData);
            return;
        }
    }
}

void VappJavaUITextfieldScr::adjustImeResize(const VfxSize & size, VfxFrame * focusFrame)
{
    VfxSize  m_size = size;
	
    /* reset vk property */
    if((m_size.height < scr_height))	
    {
        vk_mode = VFX_TRUE;
	vk_height = scr_height - m_size.height;
    }
    else
    {
        vk_mode = VFX_FALSE;
	vk_height = 0;
    }

    /* resize texteditor */	
    if(textEditor)
    {
        resizeTextEidtor();
    }

    /* resize screen */
    //setSize(size);
}

void VappJavaUITextfieldScr::resizeTextEidtor()
{
    if(textEditor)
    {
        textEditor->setPos(0, statusbar_height + title_height);
        textEditor->setSize(scr_width, getTextEditorHeight());
    }
}

void VappJavaUITextfieldScr::onTextBoxActivated(VcpTextEditor *editor, VfxBool active)
{
/*
    if (active)
    {
        g_mmi_vjava_ui_textfield_active = VFX_TRUE;
    }
    else
    {

       */
}

void VappJavaUITextfieldScr::onTextChanged(VcpTextEditor *editor)
{
    /* Sync text of editor to mmi textbox text */
    if(vfx_sys_wcslen((VfxWChar*)editor->getText()))
    {
        mmi_ucs2ncpy((PS8)g_mmi_vjava_ui_textfield->text, (PS8)editor->getText(),vfx_sys_wcslen((VfxWChar*)editor->getText()));
        g_mmi_vjava_ui_textfield->text[vfx_sys_wcslen((VfxWChar*)editor->getText())] = 0;
         
    }
    else
    {
        g_mmi_vjava_ui_textfield->text[0] = 0;
    }

#ifndef J2ME_SLIM_MEMORY_SUPPORT
	updateSearchItem();
#endif	

}

void VappJavaUITextfieldScr::onTBClick(VfxObject* sender, VfxId id)
{

    switch(id)
    {
    #ifndef J2ME_SLIM_MEMORY_SUPPORT
        case JAVA_UI_TEXTFIELD_TAB_SEARCH:
        {
	    mmi_java_ui_textfield_phone_number_group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, VAPP_JAVA_TEXTBOX, mmi_java_ui_textfield_set_number, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
					
	    mmi_frm_asm_prepare(VAPP_JAVA_TEXTBOX, 0, (mmi_proc_func)mmi_java_ui_textfield_set_number_prepare_proc, NULL, MMI_FRM_ASM_F_NONE);

            break;
            
        }
    #endif
		case JAVA_UI_TEXTFIELD_TAB_OK:
		{
			VfxWChar* editorText = textEditor->getText();
            //memset(g_mmi_vjava_ui_textfield->text, 0x00, (g_mmi_vjava_ui_textfield->max_size+ 1) * sizeof(kal_uint16));
            //memcpy(g_mmi_vjava_ui_textfield->text, editorText, mmi_ucs2strlen((PS8)editorText) * 2);
            mmi_ucs2cpy((char *)g_mmi_vjava_ui_textfield->text, (char *)editorText);
            if (g_mmi_vjava_ui_textfield->callback != NULL)
            {
                g_mmi_vjava_ui_textfield->callback(KAL_TRUE, g_mmi_vjava_ui_textfield->vm_id);
            }
			g_mmi_vjava_ui_textfield->callback = NULL;
			vapp_java_ui_textfield_hide();
            //VfxAppLauncher::terminate(g_mmi_vjava_ui_textfield_gid);
			break;
		}
    }

}

void VappJavaUITextfieldScr::onFolding(VfxObject* sender, VfxBool is_fold)
{
        /* resize text editor */
        resizeTextEidtor();
}

extern "C" void vapp_java_ui_textfield_hide(void)
{
    if (g_mmi_vjava_ui_textfield_scr == NULL || g_mmi_vjava_ui_textfield == NULL)
		return;
	
    if (g_mmi_vjava_ui_textfield->callback != NULL)
	{
	    g_mmi_vjava_ui_textfield->callback(
			KAL_FALSE,
			g_mmi_vjava_ui_textfield->vm_id);
	}
	mmi_java_ui_textfield_exit_screen(SCR_ID_JAVA_UI_TEXTFIELD_EDITOR);
}


extern "C" void vapp_java_ui_textfield_launch(mmi_java_ui_textfield_data_struct* textfield)
{

    g_mmi_vjava_ui_textfield = textfield;

    // initalize app category
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    VfxAppCatScr::initalizeWithScrAsmSize(80*1024);
#else
		VfxAppCatScr::initalize();
#endif


    VFX_OBJ_CREATE(
        g_mmi_vjava_ui_textfield_scr,
        VappJavaUITextfieldScr, 
        VfxAppCatScr::getContext());
}


extern "C" void vapp_java_ui_textfield_exit()
{

    VFX_OBJ_CLOSE(g_mmi_vjava_ui_textfield_scr);
    
    VfxAppCatScr::deinitalize();

	g_mmi_vjava_ui_textfield = NULL;

}




#endif /*__J2ME__*/

