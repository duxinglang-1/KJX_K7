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
 *  vapp_cal_edit.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Add/Edit event/task screen
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CAL_EDIT_H__
#define __VAPP_CAL_EDIT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C" 
{
 #include "todolistsrvgprot.h"
 #include "vcalsrvgprot.h"
}

#include "GlobalResDef.h"

#include "vfx_datatype.h"
#include "vfx_page.h"
#include "vfx_base_popup.h"

#include "vcp_list_menu.h"
#include "vcp_form.h"

#include "vapp_cal_list_mgr.h"
#include "vapp_cal_prot.h"

/***************************************************************************** 
 * Definition
 *****************************************************************************/

enum VAPP_CAL_EDITITEM_ID_ENUM
{
    VAPP_CAL_EDIT_SUBJECT = 1,
    VAPP_CAL_EDIT_START, //used only by event edit.
    VAPP_CAL_EDIT_TO, //used only by event edit.
    VAPP_CAL_EDIT_ALL_DAY,
    VAPP_CAL_EDIT_CATEGORY,
    VAPP_CAL_EDIT_REPEAT,
    VAPP_CAL_EDIT_REMINDER,
    VAPP_CAL_EDIT_LOCATION, //used only by event edit.
    VAPP_CAL_EDIT_NOTE,
    VAPP_CAL_EDIT_PRIORITY, //used only by task edit.
    VAPP_CAL_EDIT_DUETO, //used only by task edit.
    VAPP_CAL_EDIT_TOTAL_ITEMS
};

enum VAPP_CAL_EDIT_TB_ID_ENUM
{
    VAPP_CAL_TOOLBAR_EDIT_SAVE,
    VAPP_CAL_TOOLBAR_EDIT_CANCEL,
    VAPP_CAL_TOOLBAR_EDIT_TOTAL
};


//used by birthday and special day
enum VAPP_CAL_REMINDER_SPECIAL_ENUM
{
    VAPP_CAL_REMINDER_SPECIAL_NEVER,
    VAPP_CAL_REMINDER_SPECIAL_1DAY_EARLIER,
    VAPP_CAL_REMINDER_SPECIAL_3DAYS_EARLIER,
    VAPP_CAL_REMINDER_SPECIAL_1WEEK_EARLIER,
    VAPP_CAL_REMINDER_SPECIAL_TOTAL
};


enum VAPP_CAL_OPERATION_TYPE_ENUM
{
    VAPP_CAL_OPERATION_TYPE_ADD,
    VAPP_CAL_OPERATION_TYPE_EDIT,
    VAPP_CAL_OPERATION_TYPE_TOTAL
};


enum VappCalDatePickerPopupButtonEnum
{
     VAPP_CAL_DATE_PICKER_POPUP_BTN_LEFT, //OK as default
     VAPP_CAL_DATE_PICKER_POPUP_BTN_RIGHT, // Cancel as default
     VAPP_CAL_DATE_PICKER_POPUP_BTN_TOTAL
};


enum VappCalTimePickerPopupButtonEnum
{
     VAPP_CAL_TIME_PICKER_POPUP_BTN_LEFT,
     VAPP_CAL_TIME_PICKER_POPUP_BTN_RIGHT,
     VAPP_CAL_TIME_PICKER_POPUP_BTN_TOTAL
};


enum VappCalEditDateTimeItemButtonEnum
{
     VAPP_CAL_EDIT_DATETIME_BTN_DATE,
     VAPP_CAL_EDIT_DATETIME_BTN_TIME,
     VAPP_CAL_EDIT_DATETIME_BTN_TOTAL,
};

enum VappCalDateTimePickerTypeEnum
{
     VAPP_CAL_DATETIIME_START,
     VAPP_CAL_DATETIIME_END,
     VAPP_CAL_DATETIIME_TOTAL
};



enum VAPP_CAL_DATE_VALID_ENUM
{
    VAPP_CAL_DATE_LESS_THAN_MIN_YEAR,
    VAPP_CAL_DATE_GREATER_THAN_MAX_YEAR,
    VAPP_CAL_DATE_NORMAL,
    VAPP_CAL_DATE_TOTAL
};


enum VAPP_CAL_FBAR_ENUM
{
    VAPP_CAL_FBAR_PREV,
    VAPP_CAL_FBAR_NEXT,
    VAPP_CAL_FBAR_SAVE,
    VAPP_CAL_FBAR_TOTAL
};


/***************************************************************************** 
 * Class VappCalCategoryListPage
 *****************************************************************************/
class VappCalCategoryListPage : public VfxPage, public IVcpListMenuContentProvider
{

    //construct
public:
	VappCalCategoryListPage(): m_selected(0)
	{
	}

    VappCalCategoryListPage(VfxU32 initSelect)
    {
        m_selected = initSelect;
    }


// Override
protected:
    // IVcpListMenuContentProvider
    virtual VfxBool getItemText(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxWString &text,                
            VcpListMenuTextColorEnum &color  
            );
    

    virtual VfxBool getItemImage(
        VfxU32 index,                   
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        );
   

    virtual VfxU32 getCount() const;
    

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

	virtual void onInit();

public:    
	void onSelectionChanged(VcpListMenu *menu, VfxU32 index);
    static VfxWString getCategoryString(VfxU8 index);
    static VfxImageSrc getCategoryIcon(VfxU8 index);
   

	VfxSignal2 <VappCalCategoryListPage*, VfxU32> m_signalSelectNewItem;

private:

    VfxU32 m_selected;
    
};


/***************************************************************************** 
 * Class VappCalRepeatListPage
 *****************************************************************************/
class VappCalRepeatListPage : public VfxPage, public IVcpListMenuContentProvider
{


    //construct
public:
    VappCalRepeatListPage(): m_selected(0)
	{
	}

    VappCalRepeatListPage(VfxU32 initSelect)
    {
        m_selected = initSelect;
    }

// Override
protected:
    // IVcpListMenuContentProvider
    virtual VfxBool getItemText(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxWString &text,                
            VcpListMenuTextColorEnum &color  
            );
  

    virtual VfxU32 getCount() const;
    

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;
	virtual void onInit();	

public:

	void onSelectionChanged(VcpListMenu *menu, VfxU32 index);
    static VfxWString getRepeatString(VfxU8 index);
	

public:
	VfxSignal2 <VappCalRepeatListPage*, VfxU32> m_signalSelectNewItem;
    VfxU32 m_selected;
};


/***************************************************************************** 
 * Class VappCalReminderListPage
 *****************************************************************************/
class VappCalReminderListPage : public VfxPage, public IVcpListMenuContentProvider
{

    
    //construct
public:
	VappCalReminderListPage(): 
        m_selected(0), 
        m_special(VFX_FALSE),
        m_data(NULL),
        m_vcalType(SRV_TDL_VCAL_EVENT)
	{
	}

    //m_data is a static buffer for reminder list page.
    VappCalReminderListPage(VfxU32 initSelect, VfxBool special, void *data, srv_tdl_vcal_enum vcalType)
    {
        m_selected = initSelect;
        m_data = data;
        m_vcalType = vcalType;
		m_special = special;
    }

        
// Override
protected:
    // IVcpListMenuContentProvider
    virtual VfxBool getItemText(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxWString &text,                
            VcpListMenuTextColorEnum &color  
            );
   

    virtual VfxU32 getCount() const;
    

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const;

	virtual void onInit();	

public:

	void onSelectionChanged(VcpListMenu *menu, VfxU32 index);
    static VfxWString getReminderString(VfxU8 index);
    static VfxWString getSpecialReminderString(VfxU8 index);
    static VfxWString getReminderAdditionalString();
    //used by Birthday and Special Day
    static VfxU32 convertToUIIndex(VfxU32 dataIndex);
    static VfxU32 convertToDataIndex(VfxU32 UIIndex);
	
public:
	VfxSignal2 <VappCalReminderListPage*, VfxU32> m_signalSelectNewItem;
    VcpListMenu *m_listMenu;
    VfxU32 m_selected;
    VfxBool m_special;
    void *m_data;
    srv_tdl_vcal_enum m_vcalType;
    
};

#ifdef __MMI_TASK_APP__
/***************************************************************************** 
 * Class VappCalPriorityListPage
 *****************************************************************************/
class VappCalPriorityListPage : public VfxPage, public IVcpListMenuContentProvider
{

    //construct
public:
	VappCalPriorityListPage(): m_selected(0)
	{
	}

    VappCalPriorityListPage(VfxU32 initSelect)
    {
        m_selected = initSelect;
    }


// Override
protected:
    // IVcpListMenuContentProvider
    virtual VfxBool getItemText(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxWString &text,                
            VcpListMenuTextColorEnum &color  
            );
    

    virtual VfxBool getItemImage(
        VfxU32 index,                   
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        );
   

    virtual VfxU32 getCount() const;
    

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;
            
	virtual void onInit();	

public:

	void onSelectionChanged(VcpListMenu *menu, VfxU32 index);
    static VfxWString getPriorityString(VfxU8 index);

public:
	VfxSignal2 <VappCalPriorityListPage*, VfxU32> m_signalSelectNewItem;
    VfxU32 m_selected;
};
#endif

/***************************************************************************** 
 * Class VappCalDatePickerPopup
 *****************************************************************************/
class VcpDatePicker;
class VappCalDatePickerPopup: public VfxBasePopup
{

public:
    VappCalDatePickerPopup() :
        m_datePicker(NULL),
        m_background(NULL),
        m_titleBg(NULL),
        m_titleFrame(NULL),
        m_rightButton(NULL),
        m_leftButton(NULL),
        m_data(NULL),
        m_usedByJumpToDate(VFX_FALSE),
        m_vcalType(SRV_TDL_VCAL_EVENT),
        m_pickerType(VAPP_CAL_DATETIIME_START),
        m_parentPage(NULL)
    {
    }

    //data is a static buffer for this class to use directly.
    VappCalDatePickerPopup(VfxBool usedByJumpToDate, 
                    void *data = NULL, 
                    srv_tdl_vcal_enum vcalType = SRV_TDL_VCAL_EVENT, 
                    VappCalDateTimePickerTypeEnum pickerType = VAPP_CAL_DATETIIME_START,
                    VfxPage *parentPage = NULL) :
        m_datePicker(NULL),
        m_background(NULL),
        m_titleBg(NULL),
        m_titleFrame(NULL),
        m_rightButton(NULL),
        m_leftButton(NULL)
    {
        m_data = data;
        m_vcalType = vcalType;
        m_usedByJumpToDate = usedByJumpToDate;
        m_pickerType = pickerType;
        m_parentPage = parentPage;
    }

// Override
protected:
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

// Interface
public:
    void setUsedByJumpToDate(void);
    
    void displayErrorPopup(void);
    
    
// Implenmention
private:
    virtual void onButtonClick(VfxObject* sender, VfxId id);

// Signal
public:
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

// Variable    
public:
    VcpDatePicker                   *m_datePicker;

// Implemention
protected:    
    VfxFrame                        *m_background;
    VfxFrame                        *m_titleBg;
    VfxTextFrame                    *m_titleFrame;
    VcpButton                       *m_rightButton;
    VcpButton                       *m_leftButton;  
    void *m_data;
    VfxBool m_usedByJumpToDate;
    srv_tdl_vcal_enum m_vcalType;
    VappCalDateTimePickerTypeEnum m_pickerType;
    VfxPage *m_parentPage;
    
};


/***************************************************************************** 
 * Class VappCalDatePickerPopup
 *****************************************************************************/
class VcpTimePicker;
class VfxTextFrame;
class VcpButton;
class VappCalTimePickerPopup: public VappCalDatePickerPopup
{

public:
    VappCalTimePickerPopup() :
        m_timePicker(NULL)
    {
    }


    //data is a static buffer for this class to use directly.
    VappCalTimePickerPopup(void *data, 
                    srv_tdl_vcal_enum vcalType, 
                    VappCalDateTimePickerTypeEnum pickerType, VfxPage *parentPage) :
        m_timePicker(NULL)
      
    {
        m_data = data;
        m_vcalType = vcalType;
        m_pickerType = pickerType;
        m_parentPage = parentPage;
    }

// Override
protected:
    virtual void onInit();
    
// Implenmention
private:
    virtual void onButtonClick(VfxObject* sender, VfxId id); 


// Variable    
public:
    VcpTimePicker                   *m_timePicker;

    
};


/***************************************************************************** 
 * Class VappCalEditDateTimeItem
 *****************************************************************************/
class VappCalEditDateTimeItem: public VcpFormItemLabeledControl
{
        
// Interface     
public:
    VappCalEditDateTimeItem();

    void setDate(const VfxWString &date);
    void setTime(const VfxWString &time);
    void changeDateLarge(VfxBool islarge);
    void onBtnClick(VfxObject* sender, VfxId id);


    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

// Override
protected:
    virtual void onInit();
    virtual void onUpdate();
    
// Implement
public:
    VcpButton *m_btnDate;
    VcpButton *m_btnTime;
    VfxWString m_date;
    VfxWString m_time;  
    VfxBool m_large;
};


/***************************************************************************** 
 * Class VappCalEditPage
 ******************************************************************************/
class VcpFunctionBar;
class VappCalEditPage: public VfxPage
{

    VFX_DECLARE_CLASS(VappCalEditPage);
    
// Interface
public:

	VappCalEditPage() : 
		m_form(NULL),
        m_vcalType(SRV_TDL_VCAL_EVENT), 
        m_index(0), 
        m_data(NULL), 
        m_operation(VAPP_CAL_OPERATION_TYPE_ADD),      
        #ifdef __MMI_PHB_BIRTHDAY_FIELD__    
        m_phbAddBirthday(VFX_FALSE),
        m_phbBirthName(NULL),
        #endif        
        #ifdef __MMI_CAL_FUNCBAR__
        m_subjectFBar(NULL),
        m_noteFBar(NULL),
        m_locationFBar(NULL),
        #endif
        m_datePickerPopup(NULL),
        m_timePickerPopup(NULL)
    {
    }
	    
	VappCalEditPage(srv_tdl_vcal_enum vcal_type, 
		VfxU32 index, 
		VAPP_CAL_OPERATION_TYPE_ENUM operation, 
        applib_time_struct *initDate = NULL
        
		): 
        m_form(NULL),
		m_vcalType(vcal_type),
		m_index(index),
        m_data(NULL), 
        m_operation(operation),		
        #ifdef __MMI_PHB_BIRTHDAY_FIELD__       
        m_phbAddBirthday(VFX_FALSE),
		m_phbBirthName(NULL),
		#endif  
        #ifdef __MMI_CAL_FUNCBAR__
		m_subjectFBar(NULL),
		m_noteFBar(NULL),
		m_locationFBar(NULL),
		#endif
        m_datePickerPopup(NULL),
		m_timePickerPopup(NULL)
			
	{
        if (initDate)
        {
            memcpy(&m_initDateForAdd, initDate, sizeof(applib_time_struct));
        }
	}

	VappCalEditPage(srv_tdl_vcal_enum vcal_type, 
		                srv_tdl_event_id_struct eventbuffer ,
						VAPP_CAL_OPERATION_TYPE_ENUM operation = VAPP_CAL_OPERATION_TYPE_EDIT, 
						applib_time_struct *initDate = NULL
						): 
			m_form(NULL),
			m_vcalType(vcal_type),
			m_data(NULL), 
			m_operation(operation),
            #ifdef __MMI_PHB_BIRTHDAY_FIELD__           
			m_phbAddBirthday(VFX_FALSE),
            m_phbBirthName(NULL),
		    #endif     
            #ifdef __MMI_CAL_FUNCBAR__
			m_subjectFBar(NULL),
			m_noteFBar(NULL),
			m_locationFBar(NULL),
			#endif
            m_datePickerPopup(NULL),
			m_timePickerPopup(NULL)
			
				
	{
		  m_eventbuffer = eventbuffer;
        if (initDate)
        {
            memcpy(&m_initDateForAdd, initDate, sizeof(applib_time_struct));
        }
	}
	

		

    //used for Adding Birthday reminder from phonebook
	VappCalEditPage(applib_time_struct *initDate, VfxWChar *phbBirthName) :
		m_form(NULL),
		m_vcalType(SRV_TDL_VCAL_EVENT),
		m_index(0),
		m_data(NULL),
		m_operation(VAPP_CAL_OPERATION_TYPE_ADD),
        #ifdef __MMI_PHB_BIRTHDAY_FIELD__     
		m_phbAddBirthday(VFX_TRUE),
        m_phbBirthName(phbBirthName),
		#endif
        #ifdef __MMI_CAL_FUNCBAR__
		m_subjectFBar(NULL),
		m_noteFBar(NULL),
		m_locationFBar(NULL),
		#endif
        m_datePickerPopup(NULL),
		m_timePickerPopup(NULL)
		
	{
        memcpy(&m_initDateForAdd, initDate, sizeof(applib_time_struct));
	}

	// Signal
	VfxSignal1 <VfxObject*> m_signalDataUpdated;

	// Static API
    static void setReminderFirstLaunchTime(
    				const MYTIME *baseTime, 
    				MYTIME *remimderTime, VAPP_CAL_REMINDER_ENUM reminderType, 
    				VfxBool allDay = VFX_FALSE, 
    				VAPP_CAL_CATEGORY_ENUM category = VAPP_CAL_CATEGORY_PERSONAL);
    static VfxBool reminderTimeIsInvalid(const MYTIME *reminderTime);
    static VfxBool checkreminderValidation(const void *data, 
    					srv_tdl_vcal_enum vcalType, 
    					VAPP_CAL_REMINDER_ENUM reminderType);

    static VAPP_CAL_CATEGORY_ENUM convertCategoryStoM(const srv_vcal_category_type_enum &category);

    
	static VAPP_CAL_REPEAT_ENUM convertRepeatStoM(const srv_tdl_repeat_rule_enum &repeat);
	static srv_tdl_repeat_rule_enum convertRepeatMtoS(const VAPP_CAL_REPEAT_ENUM &repeat);
	static srv_vcal_category_type_enum convertCategoryMtoS(const VAPP_CAL_CATEGORY_ENUM &category);
    
#ifdef __MMI_TASK_APP__
	static VAPP_CAL_PRIORITY_ENUM convertPriorityStoM(const srv_vcal_priority_enum &priority);
	static srv_vcal_priority_enum convertPriorityMtoS(const VAPP_CAL_PRIORITY_ENUM &priority);
#endif

	
	
	static VfxBool durationIsMoreThan1Day(const MYTIME *start, const MYTIME *to);
	
	static VfxBool endTimeIsLessThanStartTime(const MYTIME *start, const MYTIME *to);
	static VAPP_CAL_DATE_VALID_ENUM checkStartDateValidation(applib_time_struct *time); // if less than VAPP_CAL_MIN_YEAR
	
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
	static VfxWString getBirthdayAppendString();
#endif

	static mmi_ret onEventDataChangeCallBack(mmi_event_struct *param);
#if defined(__MMI_TASK_APP__)
        static mmi_ret onDataChangeCallBack(mmi_event_struct *param);
    #endif
        void onUpdateData();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Implement
private:
    void creatpage();
    void onTBClick(VfxObject* sender, VfxId id);
	void onItemClicked(VcpFormItemCell* sender, VfxId id);
    
#ifdef __MMI_CAL_FUNCBAR__
    void onSubjectFBarTap(VfxObject* sender, VfxId id);
    void onLocationFBarTap(VfxObject* sender, VfxId id);
    void onNoteFBarTap(VfxObject* sender, VfxId id);
#endif
    void onStartDateTimeItemClick(VfxObject *obj, VfxId id);
    void onEndDateTimeItemClick(VfxObject *obj, VfxId id);
    
    void onBtnStartDatePopupBtnClick(VfxObject *obj, VfxId id);
    void onBtnEndDatePopupBtnClick(VfxObject *obj, VfxId id);
    void onBtnStartTimePopupBtnClick(VfxObject *obj, VfxId id);
    void onBtnEndTimePopupBtnClick(VfxObject *obj, VfxId id);
    

    

    void onCategoryChanged(VappCalCategoryListPage* sender, VfxU32 index);
    void onRepeatChanged(VappCalRepeatListPage* sender, VfxU32 index);
    void onReminderChanged(VappCalReminderListPage* sender, VfxU32 index);
    
	void allDaySwitchChangeState(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
    void allDaySwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
    void initData();
    void setInitDateTime();
    VfxBool saveData();
    void adjustData();
    VfxU8 setWeekDays();
    void initEventFormContent();
    
#ifdef __MMI_TASK_APP__ 
    void onPriorityChanged(VappCalPriorityListPage* sender, VfxU32 index);

    void initTaskFormContent();
#endif
    static VfxWString getDefaultSubjectString();
   // void displayConfictPopup(const VfxWString &str);
	void closeVK();
	void closeRelativePage(srv_tdl_operator_enum op_type);

private:

    VcpForm *m_form;
	VfxTextFrame * m_textLoad;
    srv_tdl_vcal_enum m_vcalType;
	
	VfxU32 m_index;
	srv_tdl_event_id_struct m_eventbuffer;
	

    void *m_data;
	
    VAPP_CAL_OPERATION_TYPE_ENUM m_operation;

    applib_time_struct m_initDateForAdd;

    
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    VfxBool m_phbAddBirthday;
    VfxWChar *m_phbBirthName;
#endif
#ifdef __MMI_CAL_FUNCBAR__
    VcpFunctionBar *m_subjectFBar;
    VcpFunctionBar *m_noteFBar;
    VcpFunctionBar *m_locationFBar;
#endif
    VappCalDatePickerPopup *m_datePickerPopup;
    VappCalTimePickerPopup *m_timePickerPopup;

	static const VAPP_CAL_REPEAT_ENUM s_srv2AppRepeat[SRV_TDL_RULE_TOTAL];
    static const srv_tdl_repeat_rule_enum s_app2SrvRepeat[VAPP_CAL_REPEAT_TOTAL];
	
	static const VAPP_CAL_CATEGORY_ENUM s_srv2AppCategory[SRV_VCAL_CATEGORY_TYPE_TOTAL];
	static const srv_vcal_category_type_enum s_app2SrvCategory[VAPP_CAL_CATEGORY_TOTAL];
#ifdef __MMI_TASK_APP__
	static const VAPP_CAL_PRIORITY_ENUM s_srv2AppPriority[SRV_VCAL_PRIORITY_TOTAL];
	static const srv_vcal_priority_enum s_app2SrvPriority[VAPP_CAL_PRIORITY_TOTAL];
#endif
	
	enum VAPP_ON_EDIT_PAGE_ID
	{
	  VAPP_REMINDER_PAGE = 100,
	  VAPP_REPETITION_PAGE,
	  VAPP_EDIT_PRIORITY_PAGE
	};
	
};

#endif /* __VAPP_CAL_EDIT_H__ */
