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
 *  vapp_helloworld.h
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
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_JAVAAGENCYSRC_H__
#define __VAPP_JAVAAGENCYSRC_H__

#ifdef __J2ME__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_list_menu.h"
#include "vapp_java_srv.h"
extern "C"
{
    #include "JavaAppFactorySrvProt.h"
    #include "JavaAgencyGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef    enum
    {
#if defined(__MMI_MAINLCD_320X240__) 
        OFFSET_X = 7,
        OFFSET_Y = 10,
        Y_GAP = 32,
        LABEL_HEIGHT = 28,
        LABAL_WIDTH = 100,
        ITEM_HEIGHT = 48    
#elif defined(__MMI_MAINLCD_240X320__) 
        OFFSET_X = 7,
        OFFSET_Y = 10,
        Y_GAP = 32,
        LABEL_HEIGHT = 32,
        LABAL_WIDTH = 100,
        ITEM_HEIGHT = 50
#elif defined(__MMI_MAINLCD_176X220__)
        OFFSET_X = 7,
        OFFSET_Y = 10,
        Y_GAP = 32,
        LABEL_HEIGHT = 26,
        LABAL_WIDTH = 100,
        ITEM_HEIGHT = 32
#else    
        OFFSET_X = 7,
        OFFSET_Y = 10,
        Y_GAP = 32,
        LABEL_HEIGHT = 26,
        LABAL_WIDTH = 100,
        ITEM_HEIGHT = 48
#endif
    };   

typedef enum 
    {
        AUDIO_VOLUME,
        VIBRATION,
        #ifdef __MMI_FOURWAYS_KEY_DISABLE__
        VIRTUAL_KEYPAD,
        #endif
        ITEM_TOTAL
    } VcpListMenuOptionIndexEnum;

 typedef  enum
{
    PUSH_OPT_YES,
    PUSH_OPT_NO,
    PUSH_OPT_ASK_ME_LATER,
    OPT_MIN,
    OPT_TER,
    OPT_TER_ALL,
    OPT_RESUME,
    OPT_CANCEL,
    OPT_OK,
    OPT_BACK,
    OPT_RESTORE
}vapp_java_option_item;
 

 typedef enum
{
    VJAVA_INDICATING,
    VJAVA_SCREEN_SWITCH,
    VJAVA_ALWAYS_ASK,
    VJAVA_PERMISSION_DIALOG,
    VJAVA_MID_SELECT,
    VJAVA_INSTALL,
    VJAVA_PUSH_INSTALL,
    VJAVA_DM_INSTALL,
    VJAVA_TASK_MANAGER,
    VJAVA_LAUNCH_AFTER_INSTALL,
    VJAVA_MID_STOP_RUNNING,
    VAPP_MAX_OP
}vapp_java_operation_item_enum;


typedef enum
{
#if defined(J2ME_SLIM_MEMORY_SUPPORT) && defined(J2ME_SUPPORT_BACKGROUND)
    VAPP_JAVA_SETTING_SUPPORT_BG,
#endif
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    VAPP_JAVA_SETTING_SUPPORT_VK,
#endif
    VAPP_JAVA_SETTING_DATA_ACCOUNT,
    VAPP_JAVA_SETTING_MAX
}vapp_java_setting_item_enum;

/*************************************************************************
 * Declaration
 *************************************************************************/
extern void vapp_java_catscr_close();
extern "C" void vapp_java_indicating_catscr_entry(void);
extern void vapp_java_catscr_entry(vapp_java_operation_item_enum type);



/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappJavaSettingListMenuCell: public VcpListMenuCellBaseControl
{
    VFX_DECLARE_CLASS(VappJavaSettingListMenuCell);
    public:
        virtual void onInit();
        VappJavaSettingListMenuCell():switchCell(NULL){};
        virtual ~VappJavaSettingListMenuCell(){};

// Override
        virtual void show(){};
        virtual void hide(){};

        VcpSwitch* switchCell;
};


class VappjavaSettingContentProvider : public VfxObject, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappjavaSettingContentProvider);
// Override
    public:
        VappjavaSettingContentProvider(){};
        virtual VfxU32 getCount(VfxU32 group) const;
        virtual VfxBool getItemText(
            VcpMenuPos pos,                  // [IN] the position of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxWString &text,                // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
        virtual VfxBool getItemImage(
            VcpMenuPos pos,                    
            VcpListMenuFieldEnum fieldType,  
            VfxImageSrc &image              
    ) ;
        VfxU32 getGroupCount() const;
    virtual void onInit();
    virtual VfxBool getItemIsDisabled(VcpMenuPos pos) const;
    virtual VfxBool getItemIsHighlightable(VcpMenuPos pos) const;
    virtual VcpListMenuCellBaseControl *getItemCustomControl(
        VcpMenuPos pos,                                  // [IN] position of the item
        VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
        VfxFrame *parentFrame  
    ); 
};


class VappJavaMidsBGSettingControllor: public VfxControl
{
    VFX_DECLARE_CLASS(VappJavaMidsBGSettingControllor);
    public:
        virtual void onInit();
        void setBGHandler(VcpSwitch *thiz, VfxBool status);
};


class VappJavaMidsVKSettingControllor: public VfxControl
{
    VFX_DECLARE_CLASS(VappJavaMidsVKSettingControllor);
    public:
        virtual void onInit();
        void setVKHandler(VcpSwitch *thiz, VfxBool status);
};

class VjavaPerListMenuContentProvider : public VfxObject, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VjavaPerListMenuContentProvider);
// Override
    public:
        VjavaPerListMenuContentProvider(){};
        virtual VfxU32 getCount() const;
        virtual VfxBool getItemText(
                VfxU32 index,                    // [IN] the index of item
                VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                VfxWString &text,                // [OUT] the text resource
                VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual void onInit();
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
   /* Implement the required virtual functions of IVcpListMenuContentProvider */
};


class VappJavaPermissionListPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappJavaPermissionListPage);
    private:
        VcpListMenu *listMenu; // Member pointer to the child list menu of this screen     
        VjavaPerListMenuContentProvider* contentProvider;
        VcpTitleBar * title;
        VfxU32 count;
        
    public:
        virtual void onInit();
        VappJavaPermissionListPage():listMenu(NULL),contentProvider(NULL),title(NULL),count(0){ };
        void tapItem(VcpListMenu *menu, VfxU32 index);
        VfxSignal0 eventUpdatePer;
        void emitEvent();
        void setCount(VfxU32 c){ count = c; };
        VfxU32 getCount() const { return count; };
};

#ifdef _J2ME_SUPPORT_SETTING_

class VappjavaGlobalSettingContentProvider : public VfxObject, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappjavaGlobalSettingContentProvider);
// Override
    public:
        VappjavaGlobalSettingContentProvider(){};
        virtual VfxU32 getCount(VfxU32 group) const;
        virtual VfxBool getItemText(
            VcpMenuPos pos,                  // [IN] the position of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxWString &text,                // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
        virtual VfxBool getItemImage(
            VcpMenuPos pos,                    
            VcpListMenuFieldEnum fieldType,  
            VfxImageSrc &image              
    ) ;
        VfxU32 getGroupCount() const;
    virtual void onInit();
    VfxResId getStrResIDFromVolume(VfxU8 val);
};
#endif
#ifdef _J2ME_SUPPORT_SETTING_

class VappjavaOptionContentProvider:public VfxObject, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappjavaOptionContentProvider);
    public:
        VappjavaOptionContentProvider(){};
        virtual VfxU32 getCount() const;
        virtual VfxBool getItemText(
            VfxU32 index,              // [IN] the position of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxWString &text,                // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
        virtual VfxBool getItemImage(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxImageSrc &image              
    ) ;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const; 
    virtual void onInit();
};
#endif
#ifdef _J2ME_SUPPORT_SETTING_

class VappjavaGlobalSettingOptionPage: public VfxPage
{

    VFX_DECLARE_CLASS(VappjavaGlobalSettingOptionPage);
private:
    VcpTitleBar * title;
    VcpListMenu *listMenu; // Member pointer to the child list menu of this screen     
    VappjavaOptionContentProvider* optionContentProvider;
     static VcpListMenuOptionIndexEnum optionIndex;
public :
    virtual void onInit();
    VappjavaGlobalSettingOptionPage():title(NULL),listMenu(NULL),optionContentProvider(NULL){};
    void tapItem(VcpListMenu *menu, VfxU32 index);
    VfxSignal0 eventUpdateOption;
    void emitEvent();  
    static VcpListMenuOptionIndexEnum getIndex() {return optionIndex;};
    static void setIndex(VcpListMenuOptionIndexEnum index){optionIndex = index;};
};

#endif
#ifdef _J2ME_SUPPORT_SETTING_

class VappJavaGlobalSettingVolumePage: public VfxPage
{
VFX_DECLARE_CLASS(VappJavaGlobalSettingVolumePage);
private:
    VcpSlider * volume_slider;
    VcpToolBar* optionToolBar;
    VcpTitleBar* title;
    VfxFloat volume;
public:
    VappJavaGlobalSettingVolumePage():volume_slider(NULL),optionToolBar(NULL),title(NULL),volume(0){};
    virtual void onInit();
    VfxSignal0 volumeUpdateOption;
    void emitEvent(); 
    void onVolumeValueChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval);
    void onVolumeValueChangeDrag(VcpSlider  *sender, VfxFloat newval);
    void onOptionTBClick(VfxObject  * sender, VfxId id);
    void saveVolume();
    void cancelVolume();
};
#endif
#ifdef _J2ME_SUPPORT_SETTING_

class VappJavaGolbalSettingPage: public VfxPage
{
        VFX_DECLARE_CLASS(VappJavaGolbalSettingPage);
private:
    VcpTitleBar * title;
    VcpGroupListMenu *listMenu; // Member pointer to the child list menu of this screen     
    VappjavaGlobalSettingContentProvider* settingContentProvider;
public :
    virtual void onInit();
    VappJavaGolbalSettingPage():title(NULL),listMenu(NULL),settingContentProvider(NULL){};
    void VappJavaGlobalSettingEntry(VcpGroupListMenu*, VcpMenuPos);    
    void VappJavaGlobalSettingRefresh();
};

#endif
class VappJavaMidsSettingPage: public VfxPage
{
    VFX_DECLARE_CLASS(VappJavaMidsSettingPage);
private:
    VcpTitleBar * title;
    VcpGroupListMenu *listMenu; // Member pointer to the child list menu of this screen     
    VappjavaSettingContentProvider* settingContentProvider;
public :
    virtual void onInit();
    virtual void onDeinit();
    VappJavaMidsSettingPage():title(NULL),listMenu(NULL),settingContentProvider(NULL){};
    void VappJavaMidsSettingEntry(VcpGroupListMenu*, VcpMenuPos);
    void VappJavaMidsPermissionEntry(VfxU8 index);
    void VappUpdateJavaMidsPer();
    void VappJavaRefreshPer();
    mmi_ret onProc(mmi_event_struct *evt);
    static mmi_ret static_callerProc(mmi_event_struct *evt);
    VcpGroupListMenu* getListMenu(){return listMenu;};
};


class VappJavaMIDDetailControllor: public VfxControl
{
        VFX_DECLARE_CLASS(VappJavaMIDDetailControllor);
public:
    static VcpIndicatorPopup*  m_indacatorppPopup;
public:
    virtual void onInit();
    VappJavaMIDDetailControllor(){ };
    static void deleteMidsHandler(CHAR* app_name,void * user_data, mids_delete_callback callback);
    static void updateMidsHandler(CHAR* app_name,VfxMainScr* screen);
    static void midsSettingHandler(CHAR* app_name,VfxMainScr* screen);
    static void midsRestoreHandler(CHAR* app_name,VfxMainScr* screen);
};

class VappJavaMIDDetailScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappJavaMIDDetailScreen);

// Override
public:
    virtual void on1stReady();
    void entrySettingPage();
};


class VappJavaPushScr: public VfxMainScr
{

VFX_DECLARE_CLASS(VappJavaPushScr);
public:
    virtual void on1stReady();
    virtual void pushOption(VfxObject *obj, VfxId id);
};

class VappJavaTerminatePage: public VfxPage
{

VFX_DECLARE_CLASS(VappJavaTerminatePage);
public:
    virtual void onInit();
    VappJavaTerminatePage(){};
    void onTerminatePageClick(VfxObject *obj, VfxId id);
};

#if !(defined(J2ME_SLIM_MEMORY_SUPPORT) && defined(__COSMOS_MMI_PACKAGE__))

class VappJavaScreenSwitchScr: public VfxAppScr
{

VFX_DECLARE_CLASS(VappJavaScreenSwitchScr);
public:
    virtual void onInit();
    virtual void onDeinit();
    VappJavaScreenSwitchScr(){setIsSmallScreen();};
    void onOptionClick(VfxObject *obj, VfxId id);
};

#endif
class VappJavaAlwaysAskScr: public VfxMainScr
{

VFX_DECLARE_CLASS(VappJavaAlwaysAskScr);
public:
    virtual void on1stReady();
};

class VappJavaStopPopup: public VcpConfirmPopup
{
    VFX_DECLARE_CLASS(VappJavaStopPopup);
    public:
        VappJavaStopPopup(){};
        virtual void onExit();
        virtual void onInit(); 
};

class VappJavaPopup: public VfxAppScr
{
    VFX_DECLARE_CLASS(VappJavaPopup);
    private:
        static VfxResId resID;
        VcpIndicatorPopup* m_indacatorppPopup;
        static vapp_java_popup_type_enum m_type;
        VcpCommandPopup * commandPopup;
        VcpConfirmPopup * confirmPopup;
        VappJavaStopPopup * stopPopup;
    public:
        VappJavaPopup(){setIsSmallScreen();};
        virtual void onInit();
        static void setResID(VfxResId id){resID = id;};
        static void setType(vapp_java_popup_type_enum type){m_type = type;};
        static VfxResId getResID(){return resID;};
        static vapp_java_popup_type_enum getType(){return m_type;};
        void displayJavaPopup(vapp_java_popup_type_enum type);
};


class VappJavaMidletSelectProvider : public VfxObject, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappJavaMidletSelectProvider);
// Override
    public:
        VappJavaMidletSelectProvider(){};
        virtual VfxU32 getCount() const;
        virtual VfxBool getItemText(
                VfxU32 index,                    // [IN] the index of item
                VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                VfxWString &text,                // [OUT] the text resource
                VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
        virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );
    virtual void onInit();
};


class VappJavaMidletSelectPage: public VfxPage
{
    VFX_DECLARE_CLASS(VappJavaMidletSelectPage);
    private:
        VcpListMenu *midList; // Member pointer to the child list menu of this screen     
        VappJavaMidletSelectProvider* contentProvider;
        VcpTitleBar* title;
        VcpToolBar* toolBar;
    public:
        virtual void onInit();
        void tapItem(VcpListMenu *menu, VfxU32 index);
        virtual void onBack();
        virtual void onDeinit();
        void onCancelTBClick(VfxObject  * sender, VfxId id);
};


class VappJavaMidletSelectScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappJavaMidletSelectScr);
    public:
        VappJavaMidletSelectScr(){};
        virtual void on1stReady();
};

#if !(defined(J2ME_SLIM_MEMORY_SUPPORT) && defined(__COSMOS_MMI_PACKAGE__))

class VappJavaPermissionDialogPage: public VfxPage
{
    VFX_DECLARE_CLASS(VappJavaPermissionDialogPage);
    private:
        VcpTextView *text;
        VcpToolBar *toolBar;
        VcpTitleBar* title;
        VfxBool selected;
    public:
        VappJavaPermissionDialogPage():text(NULL),toolBar(NULL),title(NULL),selected(VFX_FALSE){};
        void onInit();
        void onDeinit();
        void onOptionTBClick(VfxObject  * sender, VfxId id);
        mmi_ret onProc(mmi_event_struct *evt);    
        void setSelected(VfxBool sel){selected = sel;};
        VfxBool getSelected(void){return selected;};
};
#endif
#if !(defined(J2ME_SLIM_MEMORY_SUPPORT) && defined(__COSMOS_MMI_PACKAGE__))

class VappJavaPermissionDialogScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappJavaPermissionDialogScr);
    public:
        VappJavaPermissionDialogScr(){};
        virtual void on1stReady();
        virtual void onDeinit();
};
#endif
#if !((defined(J2ME_SLIM_MEMORY_SUPPORT))&&(MAX_VM_INSTANCE_NUM == 1))

class VappJavaTaskMgrProvider : public VfxObject, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappJavaTaskMgrProvider);
// Override
    public:
        VappJavaTaskMgrProvider(){};
        virtual VfxU32 getCount() const;
        virtual VfxBool getItemText(
                VfxU32 index,                    // [IN] the index of item
                VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                VfxWString &text,                // [OUT] the text resource
                VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
        virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );
    virtual void onInit();
};
#endif
#if !((defined(J2ME_SLIM_MEMORY_SUPPORT))&&(MAX_VM_INSTANCE_NUM == 1))

class VappJavaTaskManagerPage: public VfxPage
{
    VFX_DECLARE_CLASS(VappJavaTaskManagerPage);
    private:
        VcpListMenu *midList; // Member pointer to the child list menu of this screen     
        VappJavaTaskMgrProvider* contentProvider;
        VcpTitleBar* title;
        VcpConfirmPopup* confirmPopup;
        VfxTextFrame* text;
        VcpToolBar* toolBar;
        static VfxBool Choosed;
    public:
        virtual void onInit();
        virtual void onDeinit();
        virtual void onBack();
        virtual void onEnter(VfxBool isBackward);
        virtual VfxBool onKeyInput(VfxKeyEvent &event);
        void tapItem(VcpListMenu *menu, VfxU32 index);
        void emptyConfirm(VfxObject *obj, VfxId id);
        void taskMgrOption(VfxObject *obj, VfxId id);
        VcpListMenu * getListMenu(){return midList;};
        void onTBClick(VfxObject  * sender, VfxId id);
        static void setChoosed(VfxBool p){Choosed = p;};
        static VfxBool getChoosed(){return Choosed;};
        VappJavaTaskManagerPage():confirmPopup(NULL){};
};
#endif     // modify by MTK71383 2013-1-03;
#if !((defined(J2ME_SLIM_MEMORY_SUPPORT))&&(MAX_VM_INSTANCE_NUM == 1))

class VappJavaTaskManagerScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappJavaTaskManagerScr);
    public:
        VappJavaTaskManagerPage * javaTaskMgrPage;
        VappJavaTaskManagerScr():javaTaskMgrPage(NULL){};
        virtual void on1stReady();
        virtual mmi_ret onProc(mmi_event_struct *evt);
};
#endif


class VappLaunchAfterConfirmScr: public VfxAppScr
{
VFX_DECLARE_CLASS(VappLaunchAfterConfirmScr);
private:
    VcpStatusIconBar *statusBar; // naozijinshuile,zheyangsheji
    VcpConfirmPopup * confirmPopup;
    VfxScrRotateTypeEnum rotateType;
public:
    virtual void onInit();
    virtual void onDeinit();
    void onEnter(VfxBool isBackward);
    VappLaunchAfterConfirmScr():statusBar(NULL),confirmPopup(NULL){setIsSmallScreen();};
    void launchAfterInstall(VfxObject *obj, VfxId id);
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  
};
class VappJavaMidInstallScreen;
class VappJavaAgency : public VfxApp
{
    VFX_DECLARE_CLASS(VappJavaAgency);
private:
    VappJavaMidInstallScreen * g_vapp_java_install;
    static VappJavaAgency *g_vappJavaAgency;
    static vapp_java_operation_item_enum g_vappJavaOpType;
protected:
    virtual void onInit();
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
public:
    virtual void onDeinit();
    VappJavaAgency():g_vapp_java_install(NULL){};
    virtual void onRun(void* args, VfxU32 argSize); 
    virtual mmi_ret onProc(mmi_event_struct *evt); 
    void selectOpEntry(vapp_java_operation_item_enum type);
    void set_install_screen(VappJavaMidInstallScreen * scr) { g_vapp_java_install = scr;};
    VappJavaMidInstallScreen * get_install_screen() { return g_vapp_java_install;};
    VfxBool install_is_active (){return (g_vapp_java_install != NULL);};
    static void setOpType(vapp_java_operation_item_enum type){g_vappJavaOpType = type;};
    static vapp_java_operation_item_enum getOpType(){ return g_vappJavaOpType;};
    static void terminate();
    static VappJavaAgency* getInstance(){ return g_vappJavaAgency; };
};

class VappJavaIndicatingCatScr : public VfxAppCatScr
{
VFX_DECLARE_CLASS(VappJavaIndicatingCatScr);  
    public:
	
    protected:
	    virtual void onInit();
	    virtual void onDeinit();
         virtual VfxBool onKeyInput(VfxKeyEvent &event){ return VfxAppCatScr::onKeyInput(event);};
    private:
			VcpIndicatorPopup *indacatorppPopup;

};


class VappJavaScreenSwitchCatScr : public VfxAppCatScr
{
VFX_DECLARE_CLASS(VappJavaScreenSwitchCatScr);  
    public:
		VappJavaScreenSwitchCatScr(){setIsSmallScreen();};
        virtual void onInit();
        virtual void onDeinit();
        void onOptionClick(VfxObject *obj, VfxId id);
         virtual VfxBool onKeyInput(VfxKeyEvent &event){ return VfxAppCatScr::onKeyInput(event);};
	private:
		VcpCommandPopup * option;
        VcpStatusIconBar * statusIconBar;

};

class VappJavaPermissionDialogCatScr : public VfxAppCatScr
{
VFX_DECLARE_CLASS(VappJavaPermissionDialogCatScr);  
    public:
		VappJavaPermissionDialogCatScr():text(NULL),toolBar(NULL),title(NULL),selected(VFX_FALSE){};
        virtual void onInit();
        virtual void onDeinit();
        void onOptionTBClick(VfxObject  * sender, VfxId id);
       // mmi_ret onProc(mmi_event_struct *evt);    
        void setSelected(VfxBool sel){selected = sel;};
        VfxBool getSelected(void){return selected;};
         virtual VfxBool onKeyInput(VfxKeyEvent &event);//{ return VfxAppCatScr::onKeyInput(event);};     // modify by MTK71383 2012-12-11;
	private:
        VcpStatusIconBar *  m_statusBar;
		VcpTextView *text;
        VcpToolBar *toolBar;
        VcpTitleBar* title;
        VfxBool selected;
        VfxS32 scr_width; /* lcd width */
        VfxS32 scr_height; /* lcd height */

};

class VappJavaHelper: public VfxObject
{
    private:
        VfxBool is_home_key_pressed;
        vapp_java_entry_after_popup_enum _entry;
        VfxBool skipFlag;
    public:
        void reEntryInstall();
        void closeJavaApp();
        void launchAfterInstall();
        void launchJavaApp();
        void entryRightManager();
        void setSkip(VfxBool skip){skipFlag = skip;};
        VfxBool getSkip(void){return skipFlag;};
        void setEntry(vapp_java_entry_after_popup_enum entry){_entry = entry;};
        vapp_java_entry_after_popup_enum getEntry(void){return _entry;};        
        void switchEntry();
        void closeMIDletScreen(void);
        void closeJavaUIscreen();
        void closeMidSettingPage();
        void setHomekeyPressed(VfxBool is_set){is_home_key_pressed = is_set;};
        static void onResumeConfirm(VfxId id, void *userData);
        static void terminateRunningCB(VfxId id, void *userData);
        static void showTerminating(void);
        static void restoreSettings(VfxId id, void *userData);
};

extern VappJavaHelper vappjavaHelper;

#ifdef __cplusplus
extern "C"
{
#endif
extern void vapp_java_entry(vapp_java_operation_item_enum type);
extern void vapp_java_launch_after_install_entry(void);
#ifdef __cplusplus
}
#endif
#endif
#endif /*__VAPP_JAVAAGENCYSRC_H__*/

