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
 *  vapp_hs_widget_mgr.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the classes for the widget manager.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_HS_WIDGET_MGR_H__
#define __VAPP_HS_WIDGET_MGR_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

#include "vapp_hs_cp.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_hs_widget_base.h"
#include "vapp_hs_def.h"
#include "vfx_timer.h"


/***************************************************************************** 
 * Venus home screen widget creator (base class)
 *****************************************************************************/

class VappHsWidgetCreator : public VfxObject
{
// Method
public:
    // This function returns the type of the widget creator.
    // RETURNS: type of the creator.
    virtual VfxS32 getType() = 0;

    // This function checks if the id is valid for this creator.
    // RETURNS: On valid, return VFX_TRUE; otherwise, return VFX_FALSE.
    virtual VfxBool isValid(
        VfxS32 id       // [IN] Id of the widget
    ) = 0;

    // This function creates a widget.
    // RETURNS: the created widget.
    virtual VfxBool create(
        VfxS32 id,                      // [IN]     Id of the widget
        VfxObject *parentObj,           // [IN]     Parent of the object
        VappHsWidget *&widget,          // [OUT]    The created widget
        VappHsDndImage *&widgetIcon     // [OUT]    The created widget icon
    ) = 0;

    // This function gets the total number of the widget associated with this
    // type.
    // RETURNS: total number of the widgets.
    virtual VfxS32 getTotalNum() = 0;

    // This function gets the id of all the widgets associated with this type.
    virtual VfxS32 getAllId(
        VfxS32 *id,     // [OUT]    Id of all the widget
        VfxS32 size     // [IN]     Size of the 'id' array
    ) = 0;

    // This function gets the total number of the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    virtual VfxS32 getPreInstalledNum() const
    {
        return 0;
    }

    // This function gets all the pre-installed widgets.
    // RETURNS: total number of the pre-installed widgets.
    virtual VfxS32 getPreInstalledWidget(
        VfxS32 *id,
        VfxS32 *pageIdx,
        VfxS32 *posX,
        VfxS32 *posY,
        VfxS32 size) const
    {
        return 0;
    }
};


/***************************************************************************** 
 * Venus home screen widget creator (device widget)
 *****************************************************************************/

class VappHsWidgetCreatorDevice : public VappHsWidgetCreator
{
// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetCreatorDevice();

// Override
public:
    virtual void onInit();
    
    virtual void onDeinit();

    virtual VfxS32 getType();
    
    virtual VfxBool isValid(
        VfxS32 id
    );
    
    virtual VfxBool create(
        VfxS32 id,
        VfxObject *parentObj,
        VappHsWidget *&widget,
        VappHsDndImage *&widgetIcon
    );
    
    virtual VfxS32 getTotalNum();
    
    virtual VfxS32 getAllId(
        VfxS32 *id, 
        VfxS32 size
    );

// Implementation
private:
    // This function loads the settings of the device widget.
    void loadSetting(void);

    // This function loads the settings by default.
    VfxBool loadDefaultSetting(void);

    // This function loads the settings of the widget manager.
    VfxBool loadManagerSetting(void);
    
    // This function unloads the settings of the widget manager.
    void unloadSetting(void);

private:
    // Id of the device widgets which is enabled in the widget manager.
    VfxS32         *m_id;

    // Number of device widgets which is enabled in the widget manager.
    VfxS32          m_count;
};


#if defined(__MMI_GADGET_SUPPORT__)
/***************************************************************************** 
 * Venus home screen widget creator (Google Gadget)
 *****************************************************************************/

class VappHsWidgetCreatorGadget : public VappHsWidgetCreator
{
// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetCreatorGadget();

// Override
public:
    virtual void onInit();

    virtual void onDeinit();
    
    virtual VfxS32 getType();
    
    virtual VfxBool isValid(
        VfxS32 id
    );
    
    virtual VfxBool create(
        VfxS32 id,
        VfxObject *parentObj,
        VappHsWidget *&widget,
        VappHsDndImage *&widgetIcon
    );
    
    virtual VfxS32 getTotalNum();
    
    virtual VfxS32 getAllId(
        VfxS32 *id,
        VfxS32 size
    );

	virtual VfxS32 getPreInstalledNum() const;

	virtual VfxS32 getPreInstalledWidget(
		VfxS32 *id,
		VfxS32 *pageIdx,
		VfxS32 *posX,
		VfxS32 *posY,
		VfxS32 size) const;

// Variable
private:
    // Id of the gadgets which is enabled in the widget manager.
    VfxS32         *m_id;

    // Number of gadgets which is enabled in the widget manager.
    VfxS32          m_count;
};
#endif /* defined(__MMI_GADGET_SUPPORT__) */


/***************************************************************************** 
 * Venus home screen widget creator
 *****************************************************************************/

class VappHsWidgetMgr : public VfxObject
{
// Declaration
public:
    // This structure stores the setting of one widget.
    struct SettingElement
    {
        VfxS32          type;   // Type of the widget
        VfxS32          id;     // Id of the widget
        VfxS32          x;      // x position if the widget is on the desktop
        VfxS32          y;      // y position if the widget is on the desktop
    };

    // This structure defines the header of the widget setting.
    struct SettingHeader
    {
        // This guard pattern is used to check if the setting is valid. On 
        // valid, it should be 0xDCBADCBA.
        VfxU32          guardPattern;

        // The total size of the setting, including the header of the setting.
        VfxU16          settingSize;

        // The total number of the widgets in the 'elem'.
        VfxU8           numTotal;

        // The total number of the widgets in the desktop.
        VfxU8           numInDesktop;

        // This array stores the setting of each widget.
        SettingElement  elem[1];
    };

    // This class defines a object in the linked list.
    class ListObj : public VfxBase
    {
    public:
        // The next object in the linked list
        ListObj        *next;

        // The object
        SettingElement  elem;
    };

    // This class defines a linked list.
    class List : public VfxBase
    {
    public:
        // The total number of element in the list
        VfxS32          num;

        // The first element in the list
        ListObj        *first;

        // The last element in the list
        ListObj        *last;

        // The current element. This is used when we traverse the list.
        ListObj        *curr;
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetMgr();

// Method
public:
    // This function initializes the widget manager.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    void load();

    // This function binds the manager to the widget bar.
    void bindWidgetBar(
        VappHsInteractiveImageArray *widgetBar);// [IN] Widget bar

    // This function binds the manager to the desktop.
    void bindDesktop(
        VappHsDesktop *desktop                  // [IN] Desktop
    );

    // This function activates the widgets.
    void activateWidget(
        VfxBool isRedrawingBkScreens    // [IN] Draw for small screen goes back
    );

    // This function deactivates the widgets.
    void deactivateWidget();

    // This function checks whether the setting is relaible. For example, when 
    // the user is dragging a widget, the setting is not reliable. In this case,
    // we should not save the setting and should retain the old setting. 
    //
    // Consider the situation that the user is dragging a widget. At the mean 
    // time, a interrupt comes, e.g. MT calls or SMS or charger plug-in. In this
    // situation, the setting is not reliable and the mobile should retain the
    // old setting.
    // RETURNS: On reliable, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isStateReliable();

    // This function gets the required memory size of the widget setting.
    // RETURNs: the required memory size.
    VfxS32 getRequiredMemSize();

    // This function serializes the setting to the NVRAM.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool serializeToNvram();

    // This function modifies the NVRAM such that the widget will be put in the
    // widget bar, rather than the desktop when the handset displays the home
    // screen next time. Note that if the active screen is already home screen, 
    // after this function is called, we must deinit and init the home screen
    // such that it can load the new widget setting.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    static VfxBool dismissWidget(
        VfxS32 type,        // [IN] Type of the widget
        VfxBool compareId,  // [IN] Should compare ID or not
        VfxS32 id           // [IN] ID of the widget
    );
    
    // This function gets the total number of the widgets.
    // RETURNS: the total number of the widgets.
    VfxS32 getTotalNum();

    VappHsWidget *get(VfxS32 idx);

    VappHsDndImage *getIcon(VfxS32 idx);

    // This function gets the pointer to the first widget.
    // RETURNS: pointer to the widget.
    VappHsWidget *getFirst();

    // This function gets the next pointer to the widget.
    // RETURNS: pointer to the next widget.
    VappHsWidget *getNext();

    // This function gets the pointer to the first widget icon.
    // RETURNS: pointer to the widget.
    VappHsDndImage *getFirstIcon();

    // This function gets the pointer to the next widget icon.
    // RETURNS: pointer to the widget.
    VappHsDndImage *getNextIcon();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Declaration
private:
    enum
    {
        // Guard pattern of the widget setting.
        GUARD_PATTERN = 0xDCBADCBA
    };

// Variable
private:
    // The array of the widget creator.
    VappHsWidgetCreator            *m_creator[VAPP_HS_WIDGET_TYPE_TOTAL];

    VappHsWidgetCreatorDevice      *m_creatorDevice;

#if defined(__MMI_GADGET_SUPPORT__)
    VappHsWidgetCreatorGadget      *m_creatorGadget;
#endif

    // The array of the widget.
    VappHsWidget                  **m_widget;

    // The array of the widget icon.
    VappHsDndImage                **m_widgetIcon;

    // Desktop
    VappHsDesktop                  *m_desktop;

    // Widget bar
    VappHsInteractiveImageArray    *m_bar;

    // The total number of the widgets.
    VfxS32                          m_numTotal;

    // The total number of the widgets in the desktop. Note this value is only
    // value when the widgets are just created from the settings. Later on,
    // when the user moves the widgets between widget bar and desktop, this 
    // value becomes invalid.
    VfxS32                          m_numInDesktopOnInit;

    // The current index of the widget. This variable is used when we traverse
    // the widget.
    VfxS32                          m_curr;

    // The list of the widget parsed from the memory.
    List                            m_list;

    // Timer to create the widget one-by-one
    VfxTimer                       *m_timerCreateWidget;

    // Delay time to create the next widget
    static const VfxS32             s_createDelayedDuration;

    // If NVRAM is locked, it will not be able to serialize setting to NVRAM
    // until we load the widget next time.
    static VfxBool                  s_isNvramLocked;

// Method
private:
    // This function gets the widget creator of the specified type.
    // RETURNS: the widget creator.
    VappHsWidgetCreator *getCreator(
        VfxS32 type     // [IN] The type of the widget creator.
    );

    // This function checks if the specified creator can create a widget of
    // the specified 'id'.
    // RETURNS: On ok, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool canBeHandled(
        VfxS32 type,    // [IN] The type of the creator
        VfxS32 id);     // [IN] The id of the widget

    // This function adds the extra widgets to the widget bar.
    void addExtra();

    // This function initializes the widget manager from the memory.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool initFromMem();

    // This function initializes the pre-installed widgets.
    void initPreInstalledWidget();

    // This function sets the NVRAM is dirty such that we need to serialize the
    // new setting to the NVRAM.
    void setDirty();

    // This function creates all delayed widgets.
    void createAllDelayedWidget();

    // This function is the timeout handler for hte "Create Widget" timer.
    void onTimerCreateWidget(
        VfxTimer *timer         // [IN] "Create Widget" timer
    );

    // This function reads the NVRAM.
    static VfxU8 *readNvram(
        VfxU8 *buf,             // [OUT]    Buffer
        VfxS16 size             // [IN]     Buffer size   
    );

    // This function writes the NVRAM.
    static void writeNvram(
        VfxU8 *buf,             // [IN] Buffer
        VfxS16 size             // [IN] Buffer size
    );
    
    // This function appends a widget setting to the tail of the list.
    void listAppend(
        const SettingElement &elem  // [IN] A widget setting
    );

    // This function removes a widget setting from the head of the list.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool listRemove(
        SettingElement &elem    // [OUT] The removed widget setting
    );

    // This function clears all the widget settings from the list.
    void listClear();

    // This function checks if the widget setting is present in the list.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool listIsPresent(
        const SettingElement &elem  // [IN] A widget setting
    );

    // This function gets the totol number of widget settings in the list.
    // RETURNS: the total number.
    VfxS32 listGetNum();

    // This function returns the first element in the list.
    // RETURNS: pointer to the first element in the list.
    const SettingElement *listGetFirst();

    // This function returns the next element in the list.
    // RETURNS: pointer to the next element in the list.
    const SettingElement *listGetNext();

    // This function serializes the setting to the setting structure.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool serializeToMem(
        SettingHeader *&header,     // [OUT] The setting
        VfxS32 &size                // [OUT] The size of the setting
    );
};


#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VAPP_HS_WIDGET_MGR_H__ */

