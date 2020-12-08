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
 *  vapp_JavaAgencyUITextBox.cpp
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
#include "vapp_JavaAgencyUITextBox.h"
#include "mmi_rp_vapp_java_def.h"
#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
#endif
#include "../xml/vfx_xml_loader.h"
#include "MMI_include.h"
#include "vapp_java_adp.h"
#include "vapp_java_srv.h"
#include "vcui_phb_gprot.h"

extern "C"
{
    #include "jam_internal.h"
    #include "jui_interface.h"

    #include "CommonScreens.h"
    #include "CommonScreensResDef.h"

    #include "JavaAgencyUICommon.h"
    #include "JavaAgencyUITextBox.h"

    #include "PhbSrvGprot.h"

    extern MMI_ID mmi_java_ui_textbox_phone_number_group_id;
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define JAVA_UI_TEXTBOX_SEARCH (8)
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
//#define JAVA_UI_TEXTBOX_TICKER_HEIGHT                     20

#define COMAND_SCREEN  1
#define COMAND_BACK      2
#define COMAND_CANCEL 3
#define COMAND_OK	     4
#define COMAND_HELP       5
#define COMAND_STOP      6
#define COMAND_EXIT        7
#define COMAND_ITEM       8

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static mmi_java_ui_textbox_data_struct *g_mmi_vjava_ui_textbox = NULL;
static VappJavaUITextboxScr *g_mmi_vjava_textboxscr_ptr = NULL;

/*****************************************************************************
 * Class VappJavaUITextboxScr
 *****************************************************************************/
VappJavaUITextboxScr::VappJavaUITextboxScr()
{

}

void VappJavaUITextboxScr::createTicker(const VfxWString &ticker_string)
{
        VFX_OBJ_CREATE(ticker, VcpMarquee, this);
        ticker->setRect(VfxRect(0,statusbar_height + title_height,scr_width,getTickerHeight()));  
	ticker->setTextColor(VRT_COLOR_WHITE, VFX_COLOR_BLACK);
	ticker->setBgColor(VFX_COLOR_BLACK);
        //ticker->setMovableFrame(ticker_string,VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_EFFECT_BORDER));
	    ticker->setMovableFrame(ticker_string,textEditor->getFont());
        
        ticker->setLoop(0);
        ticker->setIsScrollAlways(VFX_TRUE);
        ticker->startScroll();
}

/* search item can not del by this function */
void VappJavaUITextboxScr::delItems()
{
    /* remove allitems of funcbar and tool bar */
    for (VfxU8 i = 0; i < JAVA_UI_TEXTBOX_SEARCH; i++)
    {
        if(i < 4)
        {
            funcBar->removeItem(i);
	}
        toolBar->removeItem(i);
    }
}

/* search item can not add by this function */
void VappJavaUITextboxScr::addItems()
{
    for (VfxS32 i = 0; i < g_mmi_vjava_ui_textbox->command_num; i++)
    {
    	  if(vfx_sys_wcslen((VfxWChar*)g_mmi_vjava_ui_textbox->command_label[i]))
    	  {
    	  	funcBar->addItem(i,g_mmi_vjava_ui_textbox->command_label[i]);
    	  }
    	  else
    	  {
    	  	funcBar->addItem(i,VFX_WSTR(" "));
    	  }
        
	toolBar->addItem(i,g_mmi_vjava_ui_textbox->command_label[i],gettoolBarItemIcon(g_mmi_vjava_ui_textbox->command_type[i]));
    }
	
    if(g_mmi_vjava_ui_textbox->command_num > 0)
    {
        /* only command from midlet can be set to special item */
        funcBar->setItemSpecial(0);
    }
}

#ifndef J2ME_SLIM_MEMORY_SUPPORT
void VappJavaUITextboxScr::updateSearchItem()
{
    /* Add or Remove Search Item */
    if (g_mmi_vjava_ui_textbox->is_editable && (g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
    {
        if (vfx_sys_wcslen((VfxWChar*)g_mmi_vjava_ui_textbox->text))
        {
            toolBar->removeItem(JAVA_UI_TEXTBOX_SEARCH);
	    funcBar->removeItem(JAVA_UI_TEXTBOX_SEARCH);
        }
        else
        {
            toolBar->addItem(JAVA_UI_TEXTBOX_SEARCH, STR_GLOBAL_SEARCH, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
	    funcBar->addItem((VfxResId)STR_GLOBAL_SEARCH, (VfxId)JAVA_UI_TEXTBOX_SEARCH);
        }
    }
}
#endif
VfxResId VappJavaUITextboxScr::gettoolBarItemIcon(kal_int32 command_type)
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
void VappJavaUITextboxScr::onInit()
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
    title->setTitle((VfxWChar*)g_mmi_vjava_ui_textbox->title);

    /* Create TextEditor */
	VFX_OBJ_CREATE(textEditor, VcpTextEditor , this);

    /* Create Ticker */
    if (g_mmi_vjava_ui_textbox->ticker_length > 0)
    {
        createTicker((VfxWChar*)g_mmi_vjava_ui_textbox->ticker);
    }
	else if(g_mmi_vjava_ui_textbox->ticker_length == 0)
	{
		createTicker(VFX_WSTR(" "));
	}
    else
    {
        ticker = NULL;
    }
	
    /* Create ToolBar */
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->setPos(0,scr_height -getToolbarHeight());
    toolBar->setSize(scr_width,getToolbarHeight());
    toolBar->m_signalButtonTap.connect(this, &VappJavaUITextboxScr::onTBClick);
    toolBar->m_signalBarFolded.connect(this, &VappJavaUITextboxScr::onFolding);

    /* Set TextEditor */
    resizeTextEidtor();

    if ((g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SENTENCE ||
        (g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_EMAIL ||
        (g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_URL)
    {
        textEditor->setIME((VfxU64)g_mmi_vjava_ui_textbox->constraints, (VfxU32)IME_JAVA_SPECIAL_SYMBOL);
    }
    else
    {
		if((g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SIGNED_NUMERIC ||
			(g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER ||
			(g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)
		{
			textEditor->setIME((VfxU64)g_mmi_vjava_ui_textbox->constraints,IME_DISABLE_NEW_LINE_SYMBOL);
		}
		else
		{
            textEditor->setIME((VfxU64)g_mmi_vjava_ui_textbox->constraints);
		}
    }
	
    textEditor->setText((VfxWChar*)g_mmi_vjava_ui_textbox->text, g_mmi_vjava_ui_textbox->text_max_size - 1);               
    textEditor->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    textEditor->disableBackground(VFX_TRUE);
    textEditor->setBgColor(VFX_COLOR_WHITE);
    textEditor->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
    textEditor->setUnderline(VFX_TRUE);
    textEditor->setMargins(10,0,10,0);
    textEditor->setMinLineHeight(JAVA_UI_TEXTBOX_EDITOR_LINE_GAP);
	textEditor->setCounterDisplayMode(VCP_TEXT_COUNTER_DISP_SHOW);
    textEditor->m_signalActivated.connect(this, &VappJavaUITextboxScr::onTextBoxActivated); 
    textEditor->m_signalTextChanged.connect(this, &VappJavaUITextboxScr::onTextChanged);       

    if(!g_mmi_vjava_ui_textbox->is_editable)
    {
        textEditor->setIsDisabled(VFX_TRUE);
	textEditor->setAutoActivated(VFX_FALSE);
    }
    else
    {
        textEditor->setIsDisabled(VFX_FALSE);
        textEditor->setAutoActivated(VFX_TRUE);
    }

    /* Create FunctionBar */
    VFX_OBJ_CREATE(funcBar, VcpFunctionBar, this);

    textEditor->setFunctionBar(funcBar);	
    funcBar->m_signalButtonTap.connect(this,&VappJavaUITextboxScr::onTBClick);

    addItems();
#ifndef J2ME_SLIM_MEMORY_SUPPORT
    updateSearchItem();
#endif

}

void VappJavaUITextboxScr::onDeinit()
{

	VfxAppCatScr::onDeinit();

}

VfxS32 VappJavaUITextboxScr::getTickerHeight()
{
    return ticker ? JAVA_UI_TEXTBOX_TICKER_HEIGHT : 0;
}

VfxS32 VappJavaUITextboxScr::getToolbarHeight()
{
	return toolBar ? toolBar->getSize().height : 0;
}

VfxS32 VappJavaUITextboxScr::getTextEditorHeight()
{
    if(textEditor)
    {
        /* vk appear */
        if(vk_mode)
        {
            return scr_height -statusbar_height -title_height -getTickerHeight() -vk_height ;
        }
	/* vk disapear */
        else
        {
            return scr_height -statusbar_height -title_height -getTickerHeight() -getToolbarHeight() ;
        }
    }
    else
    {
        return 0;
    }

}

void VappJavaUITextboxScr::onObjectNotify(VfxId id, void *userData)
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

void VappJavaUITextboxScr::adjustImeResize(const VfxSize & size, VfxFrame * focusFrame)
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

void VappJavaUITextboxScr::resizeTextEidtor()
{
    if(textEditor)
    {
        textEditor->setPos(0, statusbar_height + title_height + getTickerHeight());
        textEditor->setSize(scr_width, getTextEditorHeight());
    }
}

void VappJavaUITextboxScr::onTextBoxActivated(VcpTextEditor *editor, VfxBool active)
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

void VappJavaUITextboxScr::onTextChanged(VcpTextEditor *editor)
{
    /* Sync text of editor to mmi textbox text */
    if(vfx_sys_wcslen((VfxWChar*)editor->getText()))
    {
        mmi_ucs2ncpy((PS8)g_mmi_vjava_ui_textbox->text, (PS8)editor->getText(),vfx_sys_wcslen((VfxWChar*)editor->getText()));
        g_mmi_vjava_ui_textbox->text[vfx_sys_wcslen((VfxWChar*)editor->getText())] = 0;
         
    }
    else
    {
        g_mmi_vjava_ui_textbox->text[0] = 0;
    }

#ifndef J2ME_SLIM_MEMORY_SUPPORT
	updateSearchItem();
#endif	

}

void VappJavaUITextboxScr::onTBClick(VfxObject* sender, VfxId id)
{

    switch(id)
    {
        case JAVA_UI_TEXTBOX_SEARCH:
        {
	    mmi_java_ui_textbox_phone_number_group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, VAPP_JAVA_TEXTBOX, mmi_java_ui_textbox_set_number, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
					
	    mmi_frm_asm_prepare(VAPP_JAVA_TEXTBOX, 0, (mmi_proc_func)mmi_java_ui_textbox_set_number_prepare_proc, NULL, MMI_FRM_ASM_F_NONE);

            break;
            
        }
	default:
        {
            jam_notify_vm();
            jui_widget_mvm_fire_event_listener_void_int(
                g_mmi_vjava_ui_textbox->vm_id,
                JUI_EVENT_RUN_COMMAND,
                g_mmi_vjava_ui_textbox->command_id[id]);
			g_mmi_vjava_ui_textbox->is_back2java = KAL_TRUE;
	    break;
	}
    }

}

void VappJavaUITextboxScr::onFolding(VfxObject* sender, VfxBool is_fold)
{
        /* resize text editor */
        resizeTextEidtor();
}

void VappJavaUITextboxScr::updateTitle()
{
    if(title)
    {  /* Do we need to remove title when length = -1 ??? */
        title->setTitle((VfxWChar*)g_mmi_vjava_ui_textbox->title);
    }
}

void VappJavaUITextboxScr::updateTicker()
{
    if(ticker)
    {
        if(g_mmi_vjava_ui_textbox->ticker_length > 0)
        {
            /* change ticker */
            ticker->setMovableFrame((VfxWChar*)g_mmi_vjava_ui_textbox->ticker,textEditor->getFont());
	        ticker->startScroll();
        }
		else if(g_mmi_vjava_ui_textbox->ticker_length == 0)
		{
			/* change ticker */
            ticker->setMovableFrame(VFX_WSTR(" "),textEditor->getFont());
	        ticker->startScroll();
		}
	    else
	    {
	        /* remove ticker */
	        VFX_OBJ_CLOSE(ticker);
	        ticker = NULL;
            resizeTextEidtor();
	    }
        
    }
    else 
	{
		if(g_mmi_vjava_ui_textbox->ticker_length > 0)
        {
            /* add ticker */
            createTicker((VfxWChar*)g_mmi_vjava_ui_textbox->ticker);
            resizeTextEidtor();
        }
	    else if(g_mmi_vjava_ui_textbox->ticker_length == 0)
	    {
		    /* ticke_lenght == 0 */
		    createTicker(VFX_WSTR(" "));
            resizeTextEidtor();
	    }
	}
}

void VappJavaUITextboxScr::updateCommands()
{
    delItems();
    addItems();
}

void VappJavaUITextboxScr::updateText()
{
    textEditor->setText((VfxWChar*)g_mmi_vjava_ui_textbox->text, g_mmi_vjava_ui_textbox->text_max_size - 1);    
    textEditor->setCursorIndex(vfx_sys_wcslen((VfxWChar*)g_mmi_vjava_ui_textbox->text));
	
     if ((g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SENTENCE ||
        (g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_EMAIL ||
        (g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_URL)
    {
        textEditor->setIME((VfxU64)g_mmi_vjava_ui_textbox->constraints, (VfxU32)IME_JAVA_SPECIAL_SYMBOL);
    }
    else
    {
		if((g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SIGNED_NUMERIC ||
			(g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER ||
			(g_mmi_vjava_ui_textbox->constraints & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC)
		{
			textEditor->setIME((VfxU64)g_mmi_vjava_ui_textbox->constraints,IME_DISABLE_NEW_LINE_SYMBOL);
		}
		else
		{
            textEditor->setIME((VfxU64)g_mmi_vjava_ui_textbox->constraints);
		}
    }

    if(!g_mmi_vjava_ui_textbox->is_editable)
    {
        textEditor->setIsDisabled(VFX_TRUE);
	textEditor->setAutoActivated(VFX_FALSE);
    }
    else
    {
        textEditor->setIsDisabled(VFX_FALSE);
        textEditor->setAutoActivated(VFX_TRUE);
    }
}


extern "C" void vapp_java_ui_textbox_launch(mmi_java_ui_textbox_data_struct* textbox)
{

    g_mmi_vjava_ui_textbox = textbox;

    // initalize app category
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    VfxAppCatScr::initalizeWithScrAsmSize(90*1024);//textbox could use 82K+ memory when using hand writing IME and choose IME option
#else
    VfxAppCatScr::initalize();
#endif

    VFX_OBJ_CREATE(
        g_mmi_vjava_textboxscr_ptr,
        VappJavaUITextboxScr, 
        VfxAppCatScr::getContext());
}

extern "C" void vapp_java_ui_textbox_resume()
{

	g_mmi_vjava_textboxscr_ptr->updateTitle();
	g_mmi_vjava_textboxscr_ptr->updateTicker();
	g_mmi_vjava_textboxscr_ptr->updateText();
	g_mmi_vjava_textboxscr_ptr->updateCommands();

}

extern "C" void vapp_java_ui_textbox_exit()
{

    VFX_OBJ_CLOSE(g_mmi_vjava_textboxscr_ptr);
    
    VfxAppCatScr::deinitalize();

	if(!g_mmi_vjava_ui_textbox->is_back2java)
		jam_exit_fg_mmi_screen_callback((kal_uint16) SCR_ID_JAVA_UI_TEXTBOX_EDITOR, 
		(kal_uint16)SCR_JAVA_DUMMY, NULL);/*MAUI_03309642*/

}

extern "C" void vapp_java_ui_textbox_update_component(kal_uint32 component_type)
{
    switch(component_type)
    {
        case JAVA_UI_TEXTBOX_TITLE:
		g_mmi_vjava_textboxscr_ptr->updateTitle();
		break;
	case JAVA_UI_TEXTBOX_TICKER:
		g_mmi_vjava_textboxscr_ptr->updateTicker();
		break;
	case JAVA_UI_TEXTBOX_COMMAND:
		g_mmi_vjava_textboxscr_ptr->updateCommands();
		break;
	case JAVA_UI_TEXTBOX_TEXT:
		g_mmi_vjava_textboxscr_ptr->updateText();
		break;
	default:
		break;
    }
}

#endif /*__J2ME__*/

