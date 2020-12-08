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
 *  vapp_JavaAgencyUIOptionMenu.cpp
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
#include "vapp_JavaAgencyUIOptionMenu.h"
#include "mmi_rp_vapp_java_def.h"
#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
#endif
#include "../xml/vfx_xml_loader.h"
#include "MMI_include.h"
#include "vapp_java_adp.h"
#include "vapp_java_srv.h"
#include "vapp_javaagencysrc.h"
#include "vapp_ncenter_gprot.h"

extern "C"
{
    #include "jam_internal.h"
    #include "jui_interface.h"

	#include "CommonScreens.h"
    #include "CommonScreensResDef.h"

	#include "JavaAgencyUICommon.h"
	#include "JavaAgencyUITextBox.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static mmi_java_ui_option_menu_data_struct *g_mmi_vjava_ui_option_menu = NULL;
static VappJavaUIOptionMenuScr *g_mmi_vjava_optionmenuscr_ptr = NULL;
/* why need ?*/
mmi_id g_mmi_vjava_ui_option_menu_gid = GRP_ID_INVALID;


/***************************************************************************** 
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappJavaUIOptionMenuContentProvider",VappJavaUIOptionMenuContentProvider,VfxObject);

void VappJavaUIOptionMenuContentProvider::onInit()
{
    VfxObject::onInit();
}


VfxU32 VappJavaUIOptionMenuContentProvider::getCount() const
{
    if (!g_mmi_vjava_ui_option_menu)
    {
        return 0;
    }
    return g_mmi_vjava_ui_option_menu->command_num;
}


VfxBool VappJavaUIOptionMenuContentProvider::getItemText(
    VfxU32 index,                 // [IN] the position of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
)
{
    VFX_TRACE(("\n ----VappJavaUIOptionMenuContentProvider::getItemText index = %d----",index));

    if (!g_mmi_vjava_ui_option_menu || index >= g_mmi_vjava_ui_option_menu->command_num)
    {        
        return VFX_FALSE;
    }
	
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text.loadFromMem((const VfxWChar *)(g_mmi_vjava_ui_option_menu->command_label[index]));
    }
	
    return VFX_TRUE;
}


void VappJavaUIOptionMenuScr::onInit()
{
	VfxAppCatScr::onInit();

	scr_width  = getSize().width; 
    scr_height = getSize().height;
	
	/* Create StatusBar */
	VFX_OBJ_CREATE(statusIconBar, VcpStatusIconBar, this);
	statusbar_height = statusIconBar->getSize().height;
	statusIconBar->setPos(0, 0);
    statusIconBar->setSize(scr_width, statusbar_height);

    /* Create Title */
	VFX_OBJ_CREATE(title,VcpTitleBar, this);
    title_height = title->getSize().height;
    title->setPos(0,statusbar_height);
    title->setSize(scr_width, title_height);
	title->setTitle(STR_GLOBAL_OPTIONS);

    /* Create OptionMenuContentProvider */
	VFX_OBJ_CREATE(optionMenuContentProvider,VappJavaUIOptionMenuContentProvider, this);

	/* Create ListMenu */
    VFX_OBJ_CREATE(listMenu, VcpListMenu, this);
	listMenu->setPos(0,statusbar_height + title_height);
	listMenu->setSize(scr_width, scr_height - title_height - statusbar_height);
    listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT); // Set a single text cell style
    listMenu->setContentProvider(optionMenuContentProvider); // Assign the content provider
    // The optinal setting of list menu
    listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    listMenu->m_signalItemTapped.connect(this, &VappJavaUIOptionMenuScr::VappJavaUIOptionMenuSelected); 
}

void VappJavaUIOptionMenuScr::VappJavaUIOptionMenuSelected(VcpListMenu* listMenu, VfxU32 pos)
{	

    jam_notify_vm();
    /* jui_widget_run_command(mmiapi_menu_ids[mmiapi_menu_index]); */

    jui_widget_mvm_fire_event_listener_void_int(
        g_mmi_vjava_ui_option_menu->vm_id,
        JUI_EVENT_RUN_COMMAND,
        g_mmi_vjava_ui_option_menu->command_id[pos]);
	g_mmi_vjava_ui_option_menu->submitted = KAL_TRUE;/*MAUI_03309642*/
}

VfxBool VappJavaUIOptionMenuScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_HOME && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        jvm_home_key_handler();
		return VFX_TRUE;
    }
	else if(event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        jam_notify_vm();
    	/* jui_widget_run_command(-2); */
    	jui_widget_mvm_fire_event_listener_void_int(
    		g_mmi_vjava_ui_option_menu->vm_id,
    		JUI_EVENT_RUN_COMMAND,
    		JUI_EVENT_OPTION_MENU_CANCEL);
    
    	jam_exit_fg_mmi_screen_callback(SCR_ID_JAVA_UI_OPTION_MENU, SCR_JAVA_APP, NULL);
		g_mmi_vjava_ui_option_menu->submitted = KAL_TRUE;/*MAUI_03309642*/
    
	}

    return VfxAppCatScr::onKeyInput(event);
}

extern "C" void vapp_java_ui_option_menu_launch(mmi_java_ui_option_menu_data_struct* option_menu)
{

	g_mmi_vjava_ui_option_menu = option_menu;

    // initalize app category
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    VfxAppCatScr::initalizeWithScrAsmSize(80*1024);
#else
		VfxAppCatScr::initalize();
#endif


    VFX_OBJ_CREATE(
        g_mmi_vjava_optionmenuscr_ptr,
        VappJavaUIOptionMenuScr, 
        VfxAppCatScr::getContext());
		
}

extern "C" kal_bool vapp_java_ui_is_option_menu_existed(void)
{
    if (g_mmi_vjava_optionmenuscr_ptr)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


extern "C" void vapp_java_ui_option_menu_exit(void)
{
    if(g_mmi_vjava_ui_option_menu && !g_mmi_vjava_ui_option_menu->submitted)
    {
		jam_exit_fg_mmi_screen_callback(SCR_ID_JAVA_UI_OPTION_MENU, SCR_JAVA_DUMMY, NULL);//interrupted, need to change to Long event state
    }/*MAUI_03309642*/
	g_mmi_vjava_ui_option_menu->screen_disppear_callback(g_mmi_vjava_ui_option_menu->vm_id);

    VFX_OBJ_CLOSE(g_mmi_vjava_optionmenuscr_ptr);
    
    VfxAppCatScr::deinitalize();

}
extern "C" void vapp_java_ui_option_menu_hide(kal_bool is_permission)
{	
	vapp_java_ui_option_menu_exit_screen();
    if (is_permission)
	{
	    jam_exit_fg_mmi_screen_callback(SCR_ID_JAVA_UI_OPTION_MENU, SCR_JAVA_GET_PERMISSION, NULL);
    }
}



#endif /*__J2ME__*/

