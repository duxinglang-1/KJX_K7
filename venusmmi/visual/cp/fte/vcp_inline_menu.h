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
 *  vcp_inline_menu.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus Inline menu component 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VCP_INLINE_MENU_H_
#define _VCP_INLINE_MENU_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_switch.h"
#include "vcp_option_menu.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_object.h"
#include "vfx_weak_ptr.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vfx_text_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vcp_scrollable.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Enum for types of accessories available with VcpInlineCellBase
// <group DOM_InlineMenu_Macro&Enum_Enum>
typedef enum VcpInlineAccessoryEnum 
{
	VCP_INL_ACC_NONE,           // No Accessory
	VCP_INL_ACC_NEXT_STEP_IND,  // An arrow icon
	VCP_INL_ACC_CHECK_MARK,
	VCP_INL_ACC_POPUP_RADIO_LIST,
	VCP_INL_ACC_TOTAL_ACCESSORIES
}VcpInlineAccessoryEnum;

// Enum for cell types supported by Inline Menu
// <group DOM_InlineMenu_Macro&Enum_Enum>
typedef enum VcpInlineCellTypeEnum 
{
	VCP_INL_CELLTYPE_INVALID,
	VCP_INL_CELLTYPE_GROUP,    // Cell Group
	VCP_INL_CELLTYPE_BUTTON,   // Button type cell
	VCP_INL_CELLTYPE_SWITCH,   // Cell with switch control. Helpful for ON/OFF settings
	VCP_INL_CELLTYPE_RADIOLIST,// Radiolist launcher cell. Helps in selection of items
	VCP_INL_CELLTYPE_TOTAL
}VcpInlineCellTypeEnum;

class VcpInlineCellPos
{
public:
	VfxS32 group;
	VfxS32 pos; 
    
    VcpInlineCellPos(VfxS32 g, VfxS32 p)
    {
        group = g;
        pos = p;
    }
};

// Structure to store content data for cell type: VCP_INL_CELLTYPE_BUTTON
struct VcpInlineCellButtonData
{
	VfxResId text;
    VfxResId hinttext;
	VfxResId icon;
	VcpInlineAccessoryEnum accessory;
};

// Structure to store content data for cell type: VCP_INL_CELLTYPE_SWITCH
struct VcpInlineCellSwitchData
{
	VfxResId text;
    VfxResId hinttext;	
	VfxResId icon;
	VfxBool switchState;
};

// Structure to store data for the options in radio list (launched by VCP_INL_CELLTYPE_RADIOLIST)
struct VcpInlineRadioListOptionStruct
{
    VfxWString text;
    VfxImageSrc icon;
};

// Structure to store content data for cell type: VCP_INL_CELLTYPE_RADIOLIST
struct VcpInlineCellRadioListData 
{
	VfxResId text;
	VfxResId icon;
	VcpInlineAccessoryEnum accessory;
    VfxS32 total_options;
    VfxS32 selectedoption;
	VcpInlineRadioListOptionStruct *optionList;
};

struct VcpInlineCellLookup
{
	void *cellData; 
	VfxId cellid;
	VcpInlineCellTypeEnum celltype;
}; 

class VcpInlineCellBase;
class VcpInlineMenu;
class VcpInlineMenuLayout;
/***************************************************************************** 
 * Define
 *****************************************************************************/

// <group DOM_InlineMenu_Macro&Enum_Macro>
// Maximum number of cells allowed
#define MAX_CELLS 100

// <group DOM_InlineMenu_Macro&Enum_Macro>
// Base value for IDs reserved for cell-groups
// The cell id values from MAX_CELLS to MAX_CELLS*2 
// are reserved for groups. They should not be 
// used by apps as cell ids
#define VCP_INL_GROUP_ID_BASE	MAX_CELLS
// <group DOM_InlineMenu_Macro&Enum_Macro>
// End value for IDs reserved for cell-groups
// The cell id values from MAX_CELLS to MAX_CELLS*2 
// are reserved for groups. They should not be 
// used by apps as cell ids
#define VCP_INL_GROUP_ID_END	MAX_CELLS * 2

#define VCP_INL_CELL_HEIGHT			52
#define VCP_INL_WIDE_CELL_HEIGHT	65
#define VCP_INL_ACC_TOP_GAP			26
#define VCP_INL_GROUP_SEP_GAP		 6
#define VCP_INL_TEXT_LEFT_GAP		15
#define VCP_INL_TEXT_HINT_VERT_GAP   4

#if defined(__MMI_MAINLCD_240X400) || defined(__MMI_MAINLCD_240X320)
#define VCP_INL_ACC_RIGHT_GAP		9
#define VCP_INL_SWITCH_RIGHT_GAP  	9
#define VCP_INL_NORMAL_FONT_SIZE	14
#define VCP_INL_HINT_FONT_SIZE		12
#else
#define VCP_INL_ACC_RIGHT_GAP		13
#define VCP_INL_SWITCH_RIGHT_GAP  	13
#define VCP_INL_NORMAL_FONT_SIZE	18
#define VCP_INL_HINT_FONT_SIZE		14
#endif


//Defining menu resources:

// <group DOM_InlineMenu_Macro&Enum_Macro>
// Macro to define static data for a VCP_INL_CELLTYPE_BUTTON type cell
#define VCP_INLINE_CELL_BUTTON(_id, _str, _hintstr, _icon, _accessory)	\
	const VcpInlineCellButtonData g_inline_celldata_##_id	=	\
	{														\
		(VfxResId)_str,										\
        (VfxResId)_hintstr,                                 \
		(VfxResId)_icon,									\
		(VcpInlineAccessoryEnum)_accessory					\
	}

// <group DOM_InlineMenu_Macro&Enum_Macro>
// Macro to define static data for a VCP_INL_CELLTYPE_SWITCH type cell
#define VCP_INLINE_CELL_SWITCH(_id, _str,_hintstr, _icon, _state)	\
	const VcpInlineCellSwitchData g_inline_celldata_##_id	=	\
	{														\
		(VfxResId)_str,										\
        (VfxResId)_hintstr,									\
		(VfxResId)_icon,									\
		(VfxBool)_state										\
	}

// <group DOM_InlineMenu_Macro&Enum_Macro>
// Macro to define static data for a VCP_INL_CELLTYPE_RADIOLIST type cell
#define VCP_INLINE_CELL_RADIOLIST(_id, _str, _icon, _accessory, _numOfOptions, _selectedOption, _optionList)	\
	const VcpInlineCellRadioListData g_inline_celldata_##_id	=	\
	{														\
		(VfxResId)_str,										\
		(VfxResId)_icon,									\
		(VcpInlineAccessoryEnum)_accessory,					\
		(VfxS32)_numOfOptions,								\
		(VfxS32)_selectedOption,							\
		(VcpInlineRadioListOptionStruct *)_optionList						    \
	}

// <group DOM_InlineMenu_Macro&Enum_Macro>
// Macro to create a cell from already defined cell data
#define CREATE_CELL_FROM_RESOURCE(_inlineMenu, CELL_ID, g_id, c_id, celltype)	\
	_inlineMenu->createCell(g_id, c_id, CELL_ID, celltype);						\
	_inlineMenu->fillcelldata( 													\
				CELL_ID,													  	\
				&g_inline_celldata_##CELL_ID)
				

// <group DOM_InlineMenu_Macro&Enum_Macro>
// Macro to create a cell from cell data by sending a cell data structure
#define CREATE_CELL_FROM_DATA(_inlineMenu, cellDataPtr, g_id, c_id, CELL_ID, celltype)	\
	_inlineMenu->createCell(g_id, c_id, CELL_ID, celltype);								\
	_inlineMenu->fillCellData(															\
				CELL_ID,																\
				cellDataPtr)


#define VCP_INLINE_MENU_STRUCTURE(_tableName)		\
	const VcpInlineCellLookup g_##_tableName[] =							

#define VCP_INLINE_ADD_CELL_BUTTON(_id)							\
	{(void*)& g_inline_celldata_##_id, _id, VCP_INL_CELLTYPE_BUTTON}
		
#define VCP_INLINE_ADD_CELL_SWITCH(_id)							\
	{(void*)& g_inline_celldata_##_id, _id, VCP_INL_CELLTYPE_SWITCH}
		
#define VCP_INLINE_ADD_CELL_RADIOLIST(_id)						\
	{(void*)& g_inline_celldata_##_id, _id, VCP_INL_CELLTYPE_RADIOLIST}

#define VCP_INLINE_ADD_GROUP_SEPARATOR()						\
	{NULL, VCP_INL_CELLTYPE_GROUP}
		

		

/*****************************************************************************
 * Class VcpInlineMenuDefaultContentProvider
 *
 * This is the default content provider that can be used by apps. This would help 
 * app. separate out the data transfer part. Its use is optional, but recommended.
 * <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider>
 *****************************************************************************/ 
class VcpInlineMenuDefaultContentProvider: public VfxObject
{
/**********************/
// Constructor / Destructor
public:
	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Constructor/Destructor>
	VcpInlineMenuDefaultContentProvider();
	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Constructor/Destructor>
	VcpInlineMenuDefaultContentProvider(VcpInlineMenu *parent_menu);
	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Constructor/Destructor>
	~VcpInlineMenuDefaultContentProvider(){}

public:
// Variable	

	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Variable>
	VcpInlineCellLookup *m_cellLookupTable;

	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Variable>
        //Including group headers
	VfxS32 m_cellcount; 

	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Variable>
	VcpInlineMenu *m_parentMenu;

// Method

	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Method>
	void setClientMenu(VcpInlineMenu * menu);
	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Method>
	void PopulateMenu();

	// <group DOM_InlineMenu_VcpInlineMenuDefaultContentProvider_Method>
	void setLookupTable(VcpInlineCellLookup *table, VfxU32 total_cells)
	{	
		m_cellLookupTable = table;
		m_cellcount = total_cells;
    }	
};

/*****************************************************************************
 * Class VcpInlineGroup 
 *
 * 	This is the group class, the parent frame for cells. A group can have several 
 *  cells as its children. It can have a background image/color and a header caption.
*****************************************************************************/
class VcpInlineGroup: public VfxControl
{
	/**********************/
	// Constructor / Destructor
	public:
    	// <group DOM_InlineMenu_VcpInlineGroup_Constructor/Destructor>
    	VcpInlineGroup();
		// <group DOM_InlineMenu_VcpInlineGroup_Constructor/Destructor>
		VcpInlineGroup(VfxS32 idx, VfxWString *text = NULL);
	    // <group DOM_InlineMenu_VcpInlineGroup_Constructor/Destructor>
	    virtual ~VcpInlineGroup();
// Override

	// <group DOM_InlineMenu_VcpInlineGroup_Override>
	virtual void onInit()
	{
		VfxControl::onInit();
		setAutoAnimate(VFX_TRUE);
	}

	// <group DOM_InlineMenu_VcpInlineGroup_Override>
	virtual void onDeinit()
	{
		VfxControl::onDeinit();
	}

        // <group DOM_InlineMenu_VcpInlineGroup_Override>
        VfxBool onPenInput(VfxPenEvent &event);
	/****************************/
	// Implementation
	private:

		// <group DOM_InlineMenu_VcpInlineGroup_Implementation>
		VfxTextFrame 	*m_caption;
		// <group DOM_InlineMenu_VcpInlineGroup_Implementation>
		VfxImageFrame	*m_celldivider;
        // <group DOM_InlineMenu_VcpInlineGroup_Implementation>
        VfxBool         m_visibility; //Active or hidden

    public:
        // <group DOM_InlineMenu_VcpInlineGroup_Implementation>
        VfxSize         m_currentFrameSize;
        // <group DOM_InlineMenu_VcpInlineGroup_Implementation>
        VfxS32 			m_cellCount;		
		// <group DOM_InlineMenu_VcpInlineGroup_Implementation>
		VfxFrame 		*m_sep_frameimg;
	/****************************/
	// Property

	public:
		// <group DOM_InlineMenu_VcpInlineGroup_Property>
		void setCaption(const VfxWString& text);
		// <group DOM_InlineMenu_VcpInlineGroup_Property>
		void setBkgImage(VfxResId img);
    
        // <group DOM_InlineMenu_VcpInlineGroup_Property>
        void SetVisibleState(VfxBool state);
        // <group DOM_InlineMenu_VcpInlineGroup_Property>
        VfxBool isVisible();		

		// <group DOM_InlineMenu_VcpInlineGroup_Property>
		VfxWString getCaption(); 
};

/*****************************************************************************
 * Class VcpInlineCellBase
 *
 * 	This is the base cell class for inline menu. All different kinds of cells for 
 * 	inline menu would inherit from this class.
*****************************************************************************/
class  VcpInlineCellBase: public VfxControl
{
/**********************/
// Constructor / Destructor
public:
    // <group DOM_InlineMenu_VcpInlineCellBase_Constructor/Destructor>
    VcpInlineCellBase();
	// <group DOM_InlineMenu_VcpInlineCellBase_Constructor/Destructor>
	VcpInlineCellBase(VcpInlineCellPos p);
    // <group DOM_InlineMenu_VcpInlineCellBase_Constructor/Destructor>
    virtual ~VcpInlineCellBase();

/**********************/
public:
// Override

    // <group DOM_InlineMenu_VcpInlineCellBase_Override>
    virtual void onInit();
    // <group DOM_InlineMenu_VcpInlineCellBase_Override>
    virtual void onDeinit();
    // <group DOM_InlineMenu_VcpInlineCellBase_Override>
    void setPos(const VfxPoint &value);
    // <group DOM_InlineMenu_VcpInlineCellBase_Override>
    void setBounds(const VfxRect &value);
    // <group DOM_InlineMenu_VcpInlineCellBase_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);
	
/****************************/
// Implementation

public:
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxImageSrc				m_bkg;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxTextFrame			*m_textframe;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxImageFrame 			*m_iconframe;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxFrame 				*m_accframe;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VcpInlineAccessoryEnum 	m_accessory;
	
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxBool					m_isFocussed;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxS32 					Cellheight;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VcpInlineCellPos		pos;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxId 					id;
		
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VcpInlineCellTypeEnum	m_Celltype;
    
    // <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
    VfxBool                 m_visibility; //Active or hidden
    // <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
    VfxSize                 m_currentFrameSize;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxPoint 				m_downPos;	
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxBool 				m_isActive;
	// <group DOM_InlineMenu_VcpInlineCellBase_Implementation>
	VfxFrame				*m_cover;
/****************************/
// Property

public:
	// <group DOM_InlineMenu_VcpInlineCellBase_Property>
	void setCellText(VfxWString text);
	// <group DOM_InlineMenu_VcpInlineCellBase_Property>
	void setCellIcon(VfxResId icon_id);
	// <group DOM_InlineMenu_VcpInlineCellBase_Property>
	void setAccessory(VcpInlineAccessoryEnum accessory);
    // <group DOM_InlineMenu_VcpInlineCellBase_Property>
    void setCellBounds(VfxS32 x, VfxS32 y, VfxS32 width, VfxS32 height); // Takes care of cell bkg too    
    // <group DOM_InlineMenu_VcpInlineCellBase_Property>
    void SetVisibility(VfxBool state);
    // <group DOM_InlineMenu_VcpInlineCellBase_Property>
    VfxBool isVisible();		

    // <group DOM_InlineMenu_VcpInlineCellBase_Property>
    VfxWString getCellText();
	// <group DOM_InlineMenu_VcpInlineCellBase_Property>
	VfxResId getCellIcon();	
	// <group DOM_InlineMenu_VcpInlineCellBase_Property>
	VcpInlineAccessoryEnum getAccessory();
// Method

	// <group DOM_InlineMenu_VcpInlineCellBase_Method>
	void update();
};


/*****************************************************************************
 * Class VcpInlineCellButton 
 *
 * 	VcpInlineCellButton is the simplest inline cell currently supporting only the 
 *  items provided with base cell. This cell works as a simple button.
 *
*****************************************************************************/ 
class  VcpInlineCellButton: public VcpInlineCellBase
{
/**********************/
// Constructor / Destructor
public:
    // <group DOM_InlineMenu_VcpInlineCellButton_Constructor/Destructor>
    VcpInlineCellButton();
    // <group DOM_InlineMenu_VcpInlineCellButton_Constructor/Destructor>
    virtual ~VcpInlineCellButton(){}

/**********************/
public:
// Override

    // <group DOM_InlineMenu_VcpInlineCellButton_Override>
    virtual void onInit();
    // <group DOM_InlineMenu_VcpInlineCellButton_Override>
    virtual void onDeinit();
    // <group DOM_InlineMenu_VcpInlineCellButton_Override>
    void update(VcpInlineCellButtonData *data);
	// <group DOM_InlineMenu_VcpInlineCellButton_Override>
	VfxBool onPenInput(VfxPenEvent &event);

/****************************/
// Implementation

private:
	// <group DOM_InlineMenu_VcpInlineCellButton_Implementation>
	VfxTextFrame *m_hinttext;
/****************************/
// Property

public:
    // <group DOM_InlineMenu_VcpInlineCellButton_Property>
    void setCellHintText(VfxWString hinttext);
/****************************/
// Event
public:
   	// <group DOM_InlineMenu_VcpInlineCellButton_Event>
   	VfxSignal1 <VfxId>	tapped;
};


/*****************************************************************************
 * Class VcpInlineCellSwitch 
 *
 * 	VcpInlineCellSwitch cell includes a VcpSwitch button which makes it useful 
 *  for creating checkbox type menu. Other items are inherited from base cell.
 *
*****************************************************************************/ 
class VcpInlineCellSwitch : public VcpInlineCellBase
{
/**********************/
// Constructor / Destructor
public:
    // <group DOM_InlineMenu_VcpInlineCellSwitch_Constructor/Destructor>
    VcpInlineCellSwitch();
    // <group DOM_InlineMenu_VcpInlineCellSwitch_Constructor/Destructor>
    virtual ~VcpInlineCellSwitch();

/**********************/
public:
// Override

    // <group DOM_InlineMenu_VcpInlineCellSwitch_Override>
    void onInit();
    // <group DOM_InlineMenu_VcpInlineCellSwitch_Override>
    void onDeinit();
/****************************/
// Implementation

private:
	// <group DOM_InlineMenu_VcpInlineCellSwitch_Implementation>
	VfxBool		m_switchStatus; //ON = TRUE and OFF = FALSE
	// <group DOM_InlineMenu_VcpInlineCellSwitch_Implementation>
	VcpSwitch	*m_switch;

/****************************/
public:
// Property

	// <group DOM_InlineMenu_VcpInlineCellSwitch_Property>
	void setSwitchStatus(VfxBool status, VfxBool isAnim = VFX_TRUE); //Sets the status as specified
	// <group DOM_InlineMenu_VcpInlineCellSwitch_Property>
	VfxBool getSwitchStatus();

// Method

	// <group DOM_InlineMenu_VcpInlineCellSwitch_Method>
	void update(VcpInlineCellSwitchData *data);

// Slot

    // <group DOM_InlineMenu_VcpInlineCellSwitch_Slot>
    void onSwitchToggled(VcpSwitch *theSwitch, VfxBool newState);
/****************************/
// Event
public:
	// <group DOM_InlineMenu_VcpInlineCellSwitch_Event>
	VfxSignal2 <VfxId, VfxBool> SwitchToggled;	//App should connect to this signal. Passes the new switch state as the VfxBool argument.

};

/*****************************************************************************
 * Class VcpInlineCellRadioList 
 *
 * 	VcpInlineCellRadioList cell is a button type cell that launches a VcpOptionMenu. 
 * 	The cyurretly selected option in the option menu, shows up as hint text in this 
 * 	cell.
 *
*****************************************************************************/ 
class VcpInlineCellRadioList: public VcpInlineCellBase
{
/**********************/
// Constructor / Destructor
public:
    // <group DOM_InlineMenu_VcpInlineCellRadioList_Constructor/Destructor>
    VcpInlineCellRadioList();
    // <group DOM_InlineMenu_VcpInlineCellRadioList_Constructor/Destructor>
    virtual ~VcpInlineCellRadioList();

/**********************/
public:
// Override

    // <group DOM_InlineMenu_VcpInlineCellRadioList_Override>
    virtual void onInit();
    // <group DOM_InlineMenu_VcpInlineCellRadioList_Override>
    virtual void onDeinit();
    // <group DOM_InlineMenu_VcpInlineCellRadioList_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);

/****************************/
// Implementation

private:
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Implementation>
	VfxS32 m_totalOptions;
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Implementation>
	VfxS32 m_selectedOption;	
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Implementation>
	VcpInlineRadioListOptionStruct *m_optionList;	
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Implementation>
	VfxTextFrame *m_hinttext;
public:
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Implementation>
	VcpOptionMenu   *m_RadioListMenu;

/****************************/

public:
// Method

	// <group DOM_InlineMenu_VcpInlineCellRadioList_Method>
	void fillOptionList();
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Method>
	void addOptionToList(VfxWString text);
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Method>
	void removeOptionFromList(VfxS32 idx);
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Method>
	void update(VcpInlineCellRadioListData *data);
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Method>
	void onCloseRadiolist(VcpOptionMenu* opMenu, VcpOptionMenu::VcpOptionMenuEventEnum list_event, VcpOptionMenuItem* item);
// Property

	// <group DOM_InlineMenu_VcpInlineCellRadioList_Property>
	void setOptionList(VcpInlineRadioListOptionStruct *optionlist);
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Property>
	void setSelectedOption(VfxS32 idx); //Sets the given index as selected option
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Property>
	void setTotalOptions(VfxS32 options);
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Property>
	VfxS32 getTotalOptions()
	{
		return m_totalOptions;
	}				
	
/****************************/
// Event
public:
	// <group DOM_InlineMenu_VcpInlineCellRadioList_Event>
	VfxSignal2 <VfxId, VfxS32> SelectionChanged;
   	// <group DOM_InlineMenu_VcpInlineCellRadioList_Event>
   	VfxSignal1 <VfxId>	tapped;
};

// DOM-NOT_FOR_SDK-BEGIN

/*****************************************************************************
 * Class VcpInlineMenuLayout
 *
 *  VcpInlineMenuLayout decribes the layout of VcpInlineMenu. 
 *  The methods of VcpInlineMenuLayout are designed for VcpInlineMenu to use. APP 
 *  should not call its methods.
 *
*****************************************************************************/
class VcpInlineMenuLayout: public VfxObject
{

// Constructor / Destructor
public:
    
    // <group DOM_InlineMenu_VcpInlineMenuLayout_Constructor/Destructor>
    VcpInlineMenuLayout(VcpInlineMenu* menu = NULL);    
    // <group DOM_InlineMenu_VcpInlineMenuLayout_Constructor/Destructor>
    virtual ~VcpInlineMenuLayout() {}   
	
/***************************/
public:
// Override

	// <group DOM_InlineMenu_VcpInlineMenuLayout_Override>
	virtual void onInit()
	{
        VfxObject::onInit();
	}
public:
// Variable

    // <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
    VcpInlineMenu *m_pMenu;
	
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 GroupCellTopGap;
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 CellGroupBottomGap;		
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 GroupCellLeftGap;
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 CellGroupRightGap;

	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 MenuGroupLeftGap;
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 MenuGroupTopGap;
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 GroupMenuRightGap;
    // <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
    VfxS32 GroupMenuBottomGap;

	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 GroupGroupVertGap;
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 CellCellVertGap;
	
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 CellWidth;
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Variable>
	VfxS32 FocusedCellExpansion;	

/***************************/
// Get dimensions
public:
// Method

	// <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
	void updateContentSize();		
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
	VfxRect getDefaultCellBounds();
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
	VfxPoint getCellPos(VfxS32 g, VfxS32 p);
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
	VfxRect getDefaultGroupBounds();
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
	VfxPoint getGroupPos(VfxS32 g);
	
/***************************/
// Method

public:

    // Return the number of groups of this layout.    
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
	VfxS32 getGroupCount();
    
    
    // <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
    // Return the number of cells of a group.
    VfxS32 getCellCount(
        VfxS32 group    // [IN] The group index
    ); 					// Should be maintained internally by VcpInlineMenu 

    // <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
    // Return the whole size of the menu.
    VfxS32 getContentLength(); // Should be maintained internally by VcpInlineMenu    
    
	// <group DOM_InlineMenu_VcpInlineMenuLayout_Method>
	void adjustCell(VcpInlineCellBase *aCell, VcpInlineGroup *grp);

};

/*****************************************************************************
 * Class VcpInlineCellIndexer
 *
 *	Internal helper class for Inline Menu. Helps to index the cells.
 *
*****************************************************************************/ 
class VcpInlineCellIndexer : public VfxObject
{
/**********************/
// Type Declarations 
public:
// Enum
    enum {data_chunk = 16};
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Enum>
	typedef VfxU64 Key;
	class Celldata: public VfxBase
	{
	public:
		Key key;
		VfxFrame *cellframe;		
	};
// Sub structure and class
	class CellIdIndexedData: public VfxBase
	{
	public:
		VfxId cellid;
		VfxFrame *cellframe;
	};


/**********************/
// Constructor / Destructor
public:
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Constructor/Destructor>
	VcpInlineCellIndexer();
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Constructor/Destructor>
	~VcpInlineCellIndexer();
// Override

	// <group DOM_InlineMenu_VcpInlineCellIndexer_Override>
	void onInit()
	{
		VfxObject::onInit();
	}
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Override>
	void onDeinit()
	{
		VfxObject::onDeinit();
	}

/**********************/
// Implementation

public:	
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Implementation>
	Celldata **cellTable;
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Implementation>
	CellIdIndexedData **cellIdTable;
	
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Implementation>
	VfxS32 m_itemCount;
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Implementation>
	VfxS32 m_availableCount;
	
/**********************/
// Interface
public: 
// Method

	// <group DOM_InlineMenu_VcpInlineCellIndexer_Method>
	void addNewCell(VfxS32 group, VfxS32 pos, VfxId cellid, VfxFrame *cellframe);
	// void removeCell(VfxS32 group, VfxS32 pos); // Unsused currently. TODO: make it compatible with cell id based indexing
	
// Position based indexing
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Method>
	VfxFrame *getCell(VfxS32 group, VfxS32 pos);	
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Method>
	VfxS32 getIndex(VfxS32 group, VfxS32 pos);	
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Method>
	VfxFrame *getFrame(VfxS32 idx, VfxS32 &g, VfxS32 &p);

// ID based indexing	
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Method>
	VfxFrame *getCell(VfxId cellid);	
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Method>
	VfxS32 getIndex(VfxId cellid);	
	// <group DOM_InlineMenu_VcpInlineCellIndexer_Method>
	VfxFrame *getFrame(VfxS32 idx, VfxId &cellid);


/**********************/
// Helper functions	
// Implementation

private:
    // <group DOM_InlineMenu_VcpInlineCellIndexer_Implementation>
    Key makeKey(VfxS32 group, VfxS32 pos)
    {
        // we offset pos 1, because -1 is a special key for header
        return (VfxU64(group) << 32) + VfxU32(pos + 1);
    }
    // <group DOM_InlineMenu_VcpInlineCellIndexer_Implementation>
    Key makeKey(VcpInlineCellPos p)
    {
        makeKey(p.group, p.pos);
    }
    // <group DOM_InlineMenu_VcpInlineCellIndexer_Implementation>
    VcpInlineCellPos decodeKey(Key key)
    {
        return VcpInlineCellPos(VfxS32(key >> 32), VfxS32(key & 0xFFFFFFFF) - 1);
    }
    // <group DOM_InlineMenu_VcpInlineCellIndexer_Implementation>
    VfxS32 bisect_left(Key key);

};

// DOM-NOT_FOR_SDK-END


/*****************************************************************************
 *  Class VcpInlineMenu (Main Interface Class)
 *  VcpInlineMenu provide a scrollable UI to view active inline elements in a menu.
 *  The APP who uses VcpInlineMenu needs to provide the data for each cell. 
 *  The types of cells supported are mentioned in VcpInlineCellTypeEnum. Each cell 
 *  requires different set of data, which can be packed in thier corresponding data 
 *	structures. VcpInlineMenu will notify APP about various cell specific events through 
 *  member signals.
 *
 *****************************************************************************/
class VcpInlineMenu: public VcpScrollable
{

friend class VcpInlineMenuLayout;

/**********************/
// Constructor / Destructor
public:
    // <group DOM_InlineMenu_VcpInlineMenu_Constructor/Destructor>
    VcpInlineMenu();
    // <group DOM_InlineMenu_VcpInlineMenu_Constructor/Destructor>
    virtual ~VcpInlineMenu();
	
/**********************/
public:
// Override

    // <group DOM_InlineMenu_VcpInlineMenu_Override>
    virtual void onInit();
    // <group DOM_InlineMenu_VcpInlineMenu_Override>
    virtual void onDeinit();
    // <group DOM_InlineMenu_VcpInlineMenu_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);

protected:
// Implementation

	// Create a layout object for menu.
    // RETURNS: a layout object 
    // <group DOM_InlineMenu_VcpInlineMenu_Implementation>
    virtual VcpInlineMenuLayout* createLayout();

/************************/
// Internal functions
public:
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
    // Create a group.
	VfxFrame* createGroupHeader(
        VfxS32 group // [IN] The group index
    );

	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	VfxBool groupHasHeader(VfxS32 idx);		
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	void relayoutCellsBelow(VcpInlineCellBase *aCell);
	
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	void launch_RadioList(VfxId cellid); //Launch the Option menu screen
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	void onNewOptionSelection(VfxId cellid, VfxS32 newSelection);
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	void onSwitchToggle(VfxId cellid, VfxBool newState);
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	void onCellTapped(VfxId cellid);

/*************/
// Internal data

private:
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	VcpInlineCellIndexer 			*m_indexer;
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	VfxS32 							m_groupcount;
	VfxS32 							m_cellCountInGroup[MAX_CELLS];	
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	VcpInlineMenuLayout				*m_layout;	
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	VfxId							m_focusedCell;	
	// <group DOM_InlineMenu_VcpInlineMenu_Implementation>
	VfxFrame 						*m_cover;
	VfxWeakPtr <VcpOptionMenu> 	    m_activeRadioList;

/*************/
// Method

public:

    // <group DOM_InlineMenu_VcpInlineMenu_Method>
    // Create a cell object.
    // RETURNS: a cell object     
    VfxFrame* createCell(
        VfxS32 group,           		// [IN] The group index
        VfxS32 pos,              		// [IN] The cell index
        VfxId id,				        // [IN} The cell id
        VcpInlineCellTypeEnum celltype	// [IN] The cell type
    );

    // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Create a cell object. Inserts the new cell to the end of 'group'
    // RETURNS: a cell object     
    VfxFrame* createCell(
        VcpInlineCellTypeEnum celltype,
		VfxId id,				        // [IN} The cell id
        VfxS32 group           			// [IN] The group index    
    );

	// Fill the cell using cell data structure (for that cell type)
	// Identify cell using cell frame pointer
        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	void fillCellData(VfxId cellid, VcpInlineCellButtonData *data);
        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	void fillCellData(VfxId cellid, VcpInlineCellSwitchData *data);
        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	void fillCellData(VfxId cellid, VcpInlineCellRadioListData *data);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update cell's main text
	VfxFlag updateCellText(VfxId cellid, VfxWString text);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update cell icon image
	VfxFlag updateCellIcon(VfxId cellid, VfxResId icon);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update cell hint text
	VfxFlag updateCellHinttext(VfxId cellid, VfxWString text);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update cell accessory (the marker shown at the end)
	VfxFlag updateCellaccessory(VfxId cellid, VcpInlineAccessoryEnum Acc);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update cell visibility
	// visibility = VFX_TRUE: Cell would be visible
	// visibility = VFX_FALSE: Cell would be hidden
	VfxFlag updateCellVisibility(VfxId cellid, VfxBool visibility);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Make cell active or inactive
	// state = VFX_TRUE: Cell would be active (hittable)
	// state = VFX_FALSE: Cell would be disabled (grayed and unhittable)
	VfxFlag updateCellActiveState(VfxId cellid, VfxBool state);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update switch status of cell (Applicable only on VCP_INL_CELLTYPE_SWITCH cells)
	VfxFlag updateCellSwitchStatus(VfxId cellid, VfxBool switchState);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update Option list pointer (Applicable only on VCP_INL_CELLTYPE_RADIOLIST)
	// App. needs to maintain an array of string ids which could be read to create the popup option menu
	VfxFlag updateCellOptionList(VfxId cellid, VcpInlineRadioListOptionStruct *optionlist);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update the selected item index (Applicable only on VCP_INL_CELLTYPE_RADIOLIST)
	// The index value should be between 0 and total option count
	VfxFlag updateCellSelectedOption(VfxId cellid, VfxS32 selected);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Increase the total number of options by optionsIncreased
	// (Applicable only on VCP_INL_CELLTYPE_RADIOLIST)
	VfxFlag updateCellIncrementTotalOptions(VfxId cellid, VfxS32 optionsIncreased);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Update the total number of options
	// (Applicable only on VCP_INL_CELLTYPE_RADIOLIST)
	VfxFlag updateCellSetTotalOptions(VfxId cellid, VfxS32 optionsCount);	

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Get the total number of options
	// (Applicable only on VCP_INL_CELLTYPE_RADIOLIST)	
	// RETURNS: current total option count
	VfxS32 queryCellGetTotalOptions(VfxId cellid);

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Send to suspended state. Darkens the menu screen and disables all operations
	void suspendMenu(); 

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Resume the menu from suspended state to normal state.
	void resumeMenu();	

        // <group DOM_InlineMenu_VcpInlineMenu_Method>
	// Notify Inline menu that a pending external process is completed. 
	// (Applicable only on VCP_INL_CELLTYPE_SWITCH cells)
	void onPendingActivityCompletion(VfxId cellid, VfxBool success);	
	
/************/
// Event
public:	
	// <group DOM_InlineMenu_VcpInlineMenu_Event>
	// Signal to notify that switch status of a cell is changed.
	// (Applicable only on VCP_INL_CELLTYPE_SWITCH cells)
	VfxSignal2 <
			VfxId, 		// [IN] Id of the cell 
			VfxBool		// [IN} New swicth status, VFX_TRUE means checked
			> SwitchChangedTo;

	// <group DOM_InlineMenu_VcpInlineMenu_Event>
	// Signal to notify that a cell has been tapped
	VfxSignal1 <
			VfxId		// [IN] Id of tapped cell
			> Cell_Tapped;

	// <group DOM_InlineMenu_VcpInlineMenu_Event>
	// Signal to notify that option selection is changed by the user for a cell
	// (Applicable only on VCP_INL_CELLTYPE_RADIOLIST)
	VfxSignal2 <
			VfxId, 		// [IN] Id of the cell
			VfxS32		// [IN] index of new selected option (from a radioList).
			> NewOptionSelected; 
	
};

#endif /* _VCP_INLINE_MENU_H_ */


