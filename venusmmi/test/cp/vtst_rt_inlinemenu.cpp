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
 *  vtst_rt_inlinemenu.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Vcp Inline menu testing
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vcp_inline_menu.h"
#include "Vapp_hs_res.h"

 #include "vfx_datatype.h"
 #include "vfx_cpp_base.h"
 #include "wgui_touch_screen.h"
 #include "GlobalResDef.h"
 #include "mmi_rp_app_venus_homescreen_wg_date_def.h"
 #include "MMIDataType.h"
 #include "vfx_string.h"
 #include "vfx_sys_memory.h"
 #include "vfx_object.h"
 #include "vfx_basic_type.h"
 #include "lcd_sw_inc.h"
 #include "vrt_datatype.h"
 #include "vfx_signal.h"
 #include "vfx_app_cat_scr.h"

/***************************************************************************/
//    VcpInline Testbed
/***************************************************************************/

typedef enum 
{
	SETTING_MENU_CELLID_1,
	SETTING_MENU_CELLID_2,
	SETTING_MENU_CELLID_3,
	SETTING_MENU_CELLID_4,
	SETTING_MENU_CELLID_5,
	SETTING_MENU_CELLID_6,
	SETTING_MENU_CELLID_7,
	SETTING_MENU_CELLID_8,
	SETTING_MENU_CELLID_9,
	SETTING_MENU_CELLID_10,
	SETTING_MENU_CELLID_11,
	SETTING_MENU_CELLID_12,
	SETTING_MENU_CELLID_13,
	SETTING_MENU_CELLID_14,
	SETTING_MENU_CELLID_15,
	SETTING_MENU_CELLID_16,	
	SETTING_MENU_CELLID_TOTAL
}cell_id_enum;

class SettingsAppScreen : public VtstRtScr
{
public:
    typedef VtstRtScr Super;
	
public: 
	SettingsAppScreen():
		m_SettingsMenu(NULL),
		m_SettingsMenuContentProvider(NULL)	
        {}
	virtual ~SettingsAppScreen(){}
	
	virtual void onInit();
	void onDeinit();
    void somefunction();
    void AddCellFromDynamicContent();
    void onCellTap(VfxId cellid);
    virtual VfxS32 phase(VfxS32 idx);
    void onSwitchOperation(VfxId cellid, VfxBool newstate);

	VcpInlineMenuDefaultContentProvider   *m_SettingsMenuContentProvider;
	VcpInlineMenu 		            	  *m_SettingsMenu;		
	VcpInlineRadioListOptionStruct connection_setting_options[10];
	VcpInlineRadioListOptionStruct myoptions[15];
}; 


//Dummy resource definitions
#define STR_ID_SOME_SETTING STR_GLOBAL_DATE
#define STR_ID_ANOTHER_SETTING  STR_GLOBAL_DATE
#define STR_ID_CONNECTION_SETTING   STR_GLOBAL_DATE
#define IMG_ID_SOME_SETTING IMG_GLOBAL_L1
#define IMG_ID_ANOTHER_SETTING  IMG_GLOBAL_L2
#define IMG_ID_CONNECTION_SETTING   IMG_GLOBAL_L3

VcpInlineRadioListOptionStruct *g_connection_setting_options;

//Resource definitions
VCP_INLINE_CELL_BUTTON(SETTING_MENU_CELLID_1, STR_ID_SOME_SETTING, STR_ID_SOME_SETTING, IMG_ID_SOME_SETTING, 0);
VCP_INLINE_CELL_SWITCH(SETTING_MENU_CELLID_2, STR_ID_ANOTHER_SETTING, STR_ID_SOME_SETTING,IMG_ID_ANOTHER_SETTING, FALSE);
VCP_INLINE_CELL_RADIOLIST(SETTING_MENU_CELLID_3, STR_ID_CONNECTION_SETTING, IMG_ID_CONNECTION_SETTING, VCP_INL_ACC_NEXT_STEP_IND, 5, 2, g_connection_setting_options);
VCP_INLINE_CELL_BUTTON(SETTING_MENU_CELLID_4, STR_ID_SOME_SETTING, STR_ID_SOME_SETTING, IMG_ID_SOME_SETTING, 0);
VCP_INLINE_CELL_SWITCH(SETTING_MENU_CELLID_5, STR_ID_ANOTHER_SETTING, STR_ID_SOME_SETTING,IMG_ID_ANOTHER_SETTING, FALSE);
VCP_INLINE_CELL_RADIOLIST(SETTING_MENU_CELLID_6, STR_ID_CONNECTION_SETTING, IMG_ID_CONNECTION_SETTING, VCP_INL_ACC_NEXT_STEP_IND, 5, 2, g_connection_setting_options);
VCP_INLINE_CELL_BUTTON(SETTING_MENU_CELLID_7, STR_ID_SOME_SETTING, STR_ID_SOME_SETTING, IMG_ID_SOME_SETTING, 0);
VCP_INLINE_CELL_RADIOLIST(SETTING_MENU_CELLID_8, STR_ID_CONNECTION_SETTING, IMG_ID_CONNECTION_SETTING, VCP_INL_ACC_NEXT_STEP_IND, 5, 2, g_connection_setting_options);
VCP_INLINE_CELL_BUTTON(SETTING_MENU_CELLID_9, STR_ID_SOME_SETTING, STR_ID_SOME_SETTING, IMG_ID_SOME_SETTING, 0);
VCP_INLINE_CELL_SWITCH(SETTING_MENU_CELLID_10, STR_ID_ANOTHER_SETTING, STR_ID_SOME_SETTING,IMG_ID_ANOTHER_SETTING, FALSE);
VCP_INLINE_CELL_RADIOLIST(SETTING_MENU_CELLID_11, STR_ID_CONNECTION_SETTING, IMG_ID_CONNECTION_SETTING, VCP_INL_ACC_NEXT_STEP_IND, 5, 2, g_connection_setting_options);
VCP_INLINE_CELL_SWITCH(SETTING_MENU_CELLID_12, STR_ID_ANOTHER_SETTING, STR_ID_SOME_SETTING,IMG_ID_ANOTHER_SETTING, FALSE);
VCP_INLINE_CELL_SWITCH(SETTING_MENU_CELLID_13, STR_ID_ANOTHER_SETTING, STR_ID_SOME_SETTING,IMG_ID_ANOTHER_SETTING, FALSE);

/*********************/
/* Cell lookup table */
/* The Cell positions (group, pos) should be automatically set 
 * with populateMenu() as per the cell sequence specified here */
VCP_INLINE_MENU_STRUCTURE(lookup_table) /* 'g_' would be prefixed to table name*/
{
	VCP_INLINE_ADD_CELL_BUTTON(SETTING_MENU_CELLID_1),
	VCP_INLINE_ADD_CELL_SWITCH(SETTING_MENU_CELLID_2),
	VCP_INLINE_ADD_CELL_RADIOLIST(SETTING_MENU_CELLID_3),	
	VCP_INLINE_ADD_GROUP_SEPARATOR(),
	
	VCP_INLINE_ADD_CELL_BUTTON(SETTING_MENU_CELLID_4),
	VCP_INLINE_ADD_CELL_SWITCH(SETTING_MENU_CELLID_5),
	VCP_INLINE_ADD_CELL_RADIOLIST(SETTING_MENU_CELLID_6),
	VCP_INLINE_ADD_CELL_BUTTON(SETTING_MENU_CELLID_7),
	VCP_INLINE_ADD_CELL_RADIOLIST(SETTING_MENU_CELLID_8),
	VCP_INLINE_ADD_CELL_BUTTON(SETTING_MENU_CELLID_9),
	VCP_INLINE_ADD_GROUP_SEPARATOR(),

	VCP_INLINE_ADD_CELL_SWITCH(SETTING_MENU_CELLID_10),
	VCP_INLINE_ADD_CELL_RADIOLIST(SETTING_MENU_CELLID_11),
	VCP_INLINE_ADD_CELL_SWITCH(SETTING_MENU_CELLID_12),
	VCP_INLINE_ADD_CELL_SWITCH(SETTING_MENU_CELLID_13),
};

VfxS32 LookupTableSize()
{
	return (sizeof(g_lookup_table)/sizeof(VcpInlineCellLookup));
}

void SettingsAppScreen ::onInit()
{
	Super::onInit(); 
	g_connection_setting_options = connection_setting_options;

	connection_setting_options[0].text = VFX_WSTR("STR_GLOBAL_ABORT");
	connection_setting_options[1].text = VFX_WSTR("STR_GLOBAL_ABORTING");
	connection_setting_options[2].text = VFX_WSTR("STR_GLOBAL_ACCEPT");
	connection_setting_options[3].text = VFX_WSTR("STR_GLOBAL_ACCOUNTS");
	connection_setting_options[4].text = VFX_WSTR("STR_GLOBAL_ACTIVATE");

	myoptions[0].text = VFX_WSTR("STR_GLOBAL_ABORT");
	myoptions[1].text = VFX_WSTR("STR_GLOBAL_ABORTING");
	myoptions[2].text = VFX_WSTR("STR_GLOBAL_ACCEPT");
	myoptions[3].text = VFX_WSTR("STR_GLOBAL_ACCOUNTS");
	myoptions[4].text = VFX_WSTR("STR_GLOBAL_ABORTING");
	myoptions[5].text = VFX_WSTR("STR_GLOBAL_ACCEPT");
	myoptions[6].text = VFX_WSTR("STR_GLOBAL_ACCOUNTS");
	myoptions[7].text = VFX_WSTR("STR_GLOBAL_ABORTING");
		

    setTitle(VFX_WSTR("Inline Test"));
    
    VFX_OBJ_CREATE(m_SettingsMenuContentProvider, VcpInlineMenuDefaultContentProvider, this);

	VFX_OBJ_CREATE(m_SettingsMenu, VcpInlineMenu, this);	
	m_SettingsMenuContentProvider->setClientMenu(m_SettingsMenu);		
	m_SettingsMenuContentProvider->setLookupTable((VcpInlineCellLookup*)g_lookup_table, LookupTableSize());    

	m_SettingsMenu->setPos(VfxPoint(0,10));
	m_SettingsMenu->setBounds(VfxRect(0,0,LCD_WIDTH, LCD_HEIGHT- 50));
    m_SettingsMenu->setViewRect(VfxRect(0,0,LCD_WIDTH, LCD_HEIGHT- 50));
    m_SettingsMenu->setBgColor(VFX_COLOR_WHITE);
    m_SettingsMenu->enableVerticalScrollIndicator(VFX_TRUE);
	m_SettingsMenu->setBorderColor(VFX_COLOR_AQUA);
    m_SettingsMenu->setBorderWidth(VfxS32(2)); 

	m_SettingsMenuContentProvider->PopulateMenu();
    AddCellFromDynamicContent();

	m_SettingsMenu->updateCellVisibility(SETTING_MENU_CELLID_5, VFX_FALSE); // initialy hiding this cell
	
	m_SettingsMenu->Cell_Tapped.connect(this, &SettingsAppScreen::onCellTap);
    m_SettingsMenu->SwitchChangedTo.connect(this, &SettingsAppScreen::onSwitchOperation);
}

void SettingsAppScreen::onSwitchOperation(VfxId cellid, VfxBool newstate)
{
    m_SettingsMenu->suspendMenu();
    // Do the req. work
    m_SettingsMenu->onPendingActivityCompletion(cellid, VFX_TRUE); // Notify menu about success
}

void SettingsAppScreen::onCellTap(VfxId cellid)
{
	m_SettingsMenu->updateCellHinttext(cellid, VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE));
	switch(cellid)
	{
		case SETTING_MENU_CELLID_4:
			m_SettingsMenu->updateCellVisibility(SETTING_MENU_CELLID_5, VFX_TRUE); // Showing this cell
			break;
		case SETTING_MENU_CELLID_7:
			m_SettingsMenu->updateCellVisibility(SETTING_MENU_CELLID_5, VFX_FALSE); // hiding this cell			
			break;
		default:
			break;
	}
}

void SettingsAppScreen ::onDeinit()
{
    // un-register content provider first.
    VFX_OBJ_CLOSE(m_SettingsMenuContentProvider);
    VFX_OBJ_CLOSE(m_SettingsMenu);

    Super::onDeinit();
}


void SettingsAppScreen::AddCellFromDynamicContent()
{
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_1, VFX_WSTR("CELLID_1"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_2, VFX_WSTR("CELLID_2"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_3, VFX_WSTR("CELLID_3"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_4, VFX_WSTR("CELLID_4"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_5, VFX_WSTR("CELLID_5"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_6, VFX_WSTR("CELLID_6"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_7, VFX_WSTR("CELLID_7"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_8, VFX_WSTR("CELLID_8"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_9, VFX_WSTR("CELLID_9"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_10, VFX_WSTR("CELLID_10"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_11, VFX_WSTR("CELLID_11"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_12, VFX_WSTR("CELLID_12"));
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_13, VFX_WSTR("CELLID_13"));   

    
    /* Dynamic cell creation method: 1 */
    VcpInlineCellSwitchData newcell = {STR_GLOBAL_MEMORY_STATUS, 0, IMG_NONE, VFX_TRUE};
    CREATE_CELL_FROM_DATA(m_SettingsMenu, &newcell, 0, 3, SETTING_MENU_CELLID_14, VCP_INL_CELLTYPE_SWITCH);
    
    /* Dynamic cell creation method: 2 */
    m_SettingsMenu->createCell(VCP_INL_CELLTYPE_RADIOLIST, SETTING_MENU_CELLID_15, 1);
    m_SettingsMenu->updateCellText(SETTING_MENU_CELLID_15, VFX_WSTR("New option list"));
    
    /* The optionList is to be maintained by app only. 
     * It is read at the time of launch the pop-up, 
     * and so its contents should be accessible at that time. 
     */
    m_SettingsMenu->updateCellOptionList(SETTING_MENU_CELLID_15, myoptions); 
	m_SettingsMenu->updateCellIncrementTotalOptions(SETTING_MENU_CELLID_15, 8);	    
	m_SettingsMenu->updateCellSelectedOption(SETTING_MENU_CELLID_15, 1);

}

void SettingsAppScreen::somefunction()
{	

}

VfxS32 SettingsAppScreen::phase(VfxS32 idx)
{
    if (idx == 0)
    {
        confirm(VFX_WSTR("Is it OK?"));
        return -1;
    }
    return VTST_RT_END_TESTCASE;
}

	
VtstTestResultEnum vtst_rt_vcp_inline(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(SettingsAppScreen);
    return VTST_TR_OK;
}


#endif


