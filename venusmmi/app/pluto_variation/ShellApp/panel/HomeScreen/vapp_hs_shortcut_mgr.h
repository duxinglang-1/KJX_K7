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
 *  vapp_hs_shortcut_mgr.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the classes for the shortcut manager.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_HS_SHORTCUT_MGR_H__
#define __VAPP_HS_SHORTCUT_MGR_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vapp_hs_def.h"
#include "vapp_hs_cp.h"


/***************************************************************************** 
 * Venus home screen shortcut (base class)
 *****************************************************************************/

class VappHsShortcut : public VappHsDndImage
{
// Constructor / Destructor
public:
    // Default constructor
    VappHsShortcut();

// Method
public:
    // This function returns the type of the shortcut.
    // RETURNS: type of the shortcut.
    VfxS32 getType();

    // This function returns of id of the shortcut. A shortcut can be determined
    // by a (type, id) couple.
    // RETURNS: id of the shortcut.
    VfxS32 getId();

    // This function launches the shortcut.
    void launch();

// Override
protected:
    // This function returns the type of the shortcut.
    // RETURNS: type of the shortcut.
    virtual VfxS32 onGetType() = 0;

    // This function returns the id of the shortcut.
    // RETURNS: id of the shortcut.
    virtual VfxS32 onGetId() = 0;

    // This function launches the shortcut.
    virtual void onLaunch() = 0;
};


/***************************************************************************** 
 * Venus home screen shortcut (device shortcut)
 *****************************************************************************/

class VappHsShortcutDevice : public VappHsShortcut
{
// Constructor / Destructor
public: 
    // This function constructs a device shortcut associated with the id.
    VappHsShortcutDevice(
        VfxS32 id       // [IN] Id of the shortcut
    );

// Override
protected:
    virtual VfxS32 onGetType();
    virtual VfxS32 onGetId();
    virtual void onLaunch();

// Variable
private:
    // Id of this shortcut.
    VfxS32 m_id;
};


#ifdef __MRE_AM__
/***************************************************************************** 
 * Venus home screen shortcut (VRE shortcut)
 *****************************************************************************/

class VappHsShortcutVam : public VappHsShortcut
{
// Constructor / Destructor
public: 
    // This function constructs a VRE shortcut associated with the id.
    VappHsShortcutVam(
        VfxS32 id       // [IN] Id of the shortcut
    );

// Override
protected:
    virtual VfxS32 onGetType();
    virtual VfxS32 onGetId();
    virtual void onLaunch();

// Variable
private:
    // Id of this shortcut.
    VfxS32 m_id;
};
#endif /* __MRE_AM__ */


/***************************************************************************** 
 * Venus home screen shortcut creator (base class)
 *****************************************************************************/

class VappHsShortcutCreator : public VfxObject
{
// Constructor / Destructor
public:
    // Default constructor
    VappHsShortcutCreator();

// Method
public:
    // This function returns the type of the shortcut creator.
    // RETURNS: type of the creator.
    VfxS32 getType();

    // This function checks if the id is valid for this creator.
    // RETURNS: On valid, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isValid(
        VfxS32 id       // [IN] Id of the shortcut
    );

    // This function creates a device shortcut.
    // RETURNS: the created shortcut.
    VappHsShortcut *create(
        VfxS32 id,              // [IN] Id of the shortcut
        VfxObject *owner        // [IN] The owner of the created shortcut
    );

    // This function gets the total number of the shortcut associated with this
    // type.
    // RETURNS: total number of the shortcuts.
    VfxS32 getTotalNum();

    // This function gets the id of all the shortcuts associated with this type.
    VfxS32 getAllId(
        VfxS32 *id,     // [OUT]    Id of all the shortcut
        VfxS32 size     // [IN]     Size of the 'id' array
    );

protected:
    // This function returns the type of the shortcut creator.
    // RETURNS: type of the creator.
    virtual VfxS32 onGetType() = 0;

    // This function checks if the id is valid for this creator.
    // RETURNS: On valid, return VFX_TRUE; otherwise, return VFX_FALSE.
    virtual VfxBool onIsValid(
        VfxS32 id       // [IN] Id of the shortcut
    ) = 0;

    // This function creates a device shortcut.
    // RETURNS: the created shortcut.
    virtual VappHsShortcut *onCreate(
        VfxS32 id,              // [IN] Id of the shortcut
        VfxObject *owner        // [IN] The owner of the created shortcut
    ) = 0;

    // This function gets the total number of the shortcut associated with this
    // type.
    // RETURNS: total number of the shortcuts.
    virtual VfxS32 onGetTotalNum() = 0;

    // This function gets the id of all the shortcuts associated with this type.
    virtual VfxS32 onGetAllId(
        VfxS32 *id,     // [OUT]    Id of all the shortcut
        VfxS32 size     // [IN]     Size of the 'id' array
    ) = 0;
};


/***************************************************************************** 
 * Venus home screen shortcut creator (device shortcut)
 *****************************************************************************/

class VappHsShortcutCreatorDevice : public VappHsShortcutCreator
{
// Constructor / Destructor
public:
    // Default constructor
    VappHsShortcutCreatorDevice();

// Override
protected:
    virtual VfxS32 onGetType();
    virtual VfxBool onIsValid(VfxS32 id);
    virtual VappHsShortcut *onCreate(VfxS32 id, VfxObject *owner);
    virtual VfxS32 onGetTotalNum();
    virtual VfxS32 onGetAllId(VfxS32 *id, VfxS32 size);
};


#ifdef __MRE_AM__
/***************************************************************************** 
 * Venus home screen shortcut creator (VRE shortcut)
 *****************************************************************************/

class VappHsShortcutCreatorVam : public VappHsShortcutCreator
{
// Constructor / Destructor
public:
    // Default constructor
    VappHsShortcutCreatorVam();

    // Default destructor
protected:
    virtual void onInit();
    virtual void onDeinit();

// Override
protected:
    virtual VfxS32 onGetType();
    virtual VfxBool onIsValid(VfxS32 id);
    virtual VappHsShortcut *onCreate(VfxS32 id, VfxObject *owner);
    virtual VfxS32 onGetTotalNum();
    virtual VfxS32 onGetAllId(VfxS32 *id, VfxS32 size);

// Variable
private:
    // Total number of the VRE shortcuts.
    VfxS32 m_num;

    // The ID of all the VRE shortcuts.
    VfxS32 *m_id;
};
#endif /* __MRE_AM__ */


/***************************************************************************** 
 * Venus home screen shortcut manager
 *****************************************************************************/

class VappHsShortcutMgr : public VfxObject
{
// Declaration
public:
    // This structure stores the setting of one shortcut.
    struct SettingElement
    {
        VfxS32          type;   // Type of the shortcut
        VfxS32          id;     // Id of the shortcut
    };

    // This structure defines the header of the shortcut setting.
    struct SettingHeader
    {
        // This guard pattern is used to check if the setting is valid. On 
        // valid, it should be 0xABCDABCD.
        VfxU32          guardPattern;

        // The total size of the setting, including the header of the setting.
        VfxU16          settingSize;

        // The total number of the shortcuts in the 'elem'.
        VfxU8           numTotal;

        // The total number of the shortcuts in the shortcut bar.
        VfxU8           numInBar;

        // This array stores the setting of each shortcut.
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
    VappHsShortcutMgr();

// Method
public:
    // This function loads the shortcut manager.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool load();

    // This function binds the manager to the shortcut bar and shortcut pool.
    void bind(
        VappHsInteractiveImageArray *bar,   // [IN] Shortcut bar
        VappHsInteractiveImageArray *pool   // [IN] Shortcut pool
    );

    // This function checks if the shortcuts are reliable. 'Reliable' means all
    // the shortcuts are in the shortcut bar or in the shortcut pool. No one is
    // during the drag-and-drop period.
    // RETURNS: On reliable, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isStateReliable();

    // This function gets the required memory size of the shortcut setting.
    // RETURNs: the required memory size.
    VfxS32 getRequiredMemSize();

    // This function serializes the setting to the NVRAM.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool serializeToNvram();

    // This function gets the total number of the shortcuts.
    // RETURNS: the total number of the shortcuts.
    VfxS32 getTotalNum();

    // This function gets the pointer to the first shortcut.
    // RETURNS: pointer to the shortcut.
    VappHsShortcut *getFirst();

    // This function gets the next pointer to the shortcut.
    // RETURNS: pointer to the next shortcut.
    VappHsShortcut *getNext();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Declaration
private:
    enum
    {
        // Guard pattern of the shortcut setting.
        GUARD_PATTERN = 0xABCDABCD
    };

// Variable
private:
    // The array of the shortcut creator.
    VappHsShortcutCreator          *m_creator[VAPP_HS_SHORTCUT_TYPE_TOTAL];

    // The array of the shortcuts.
    VappHsShortcut                **m_shortcut;

    // The pointer to the shortcut bar.
    VappHsInteractiveImageArray    *m_bar;

    // The pointer to the shortcut pool.
    VappHsInteractiveImageArray    *m_pool;

    // The total number of the shortcuts.
    VfxS32                          m_numTotal;

    // The total number of the shortcuts in the shortcut bar. Note this value
    // is only value when the shortcuts are just created from the settings. 
    // Later on, when the user moves the shortcuts between shortcut bar and
    // shortcut pool, this value becomes invalid.
    VfxS32                          m_numInBarOnInit;

    // The current index of the shortcut. This variable is used when we traverse
    // the shortcuts.
    VfxS32                          m_curr;

    // The list of the shortcuts parsed from the memory.
    List                            m_list;

// Method
private:
    // This function gets the shortcut creator of the specified type.
    // RETURNS: the shortcut creator.
    VappHsShortcutCreator *getCreator(
        VfxS32 type     // [IN] The type of the shortcut creator.
    );

    // This function checks if the specified creator can create a shortcut of
    // the specified 'id'.
    // RETURNS: On ok, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool canBeHandled(
        VfxS32 type,    // [IN] The type of the creator
        VfxS32 id);     // [IN] The id of the shortcut

    // This function adds the extra shortcuts to the shortcut pool.
    // RETURNS: If there are missed device shortcuts, return VFX_TRUE.
    VfxBool addExtra();

    // This function initializes the shortcut manager from the default device
    // shortcut configuration.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool initFromDefault();

    // This function initializes the shortcut manager from the memory.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool initFromMem();

    // This function reads the shortcut settings from NVRAM.
    // RETURNS: On success, return NVRAM setting; otherwise, return NULL.
    VfxU8 *readNvram(VfxS16 &size);

    // This function writes the shortcut settings to NVRAM.
    void writeNvram(VfxU8 *mem, VfxS16 size);

    // This function appends a shortcut setting to the tail of the list.
    void listAppend(
        const SettingElement &elem  // [IN] A shortcut setting
    );

    // This function removes a shortcut setting from the head of the list.
    // RETURNS: On success, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool listRemove(
        SettingElement &elem    // [OUT] The removed shortcut setting
    );

    // This function clears all the shortcut settings from the list.
    void listClear();

    // This function checks if the shortcut setting is present in the list.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool listIsPresent(
        const SettingElement &elem  // [IN] A shortcut setting
    );

    // This function gets the totol number of shortcut settings in the list.
    // RETURNS: the total number.
    VfxS32 listGetNum();

    // This function returns the first element in the list.
    // RETURNS: pointer to the first element in the list.
    const SettingElement *listGetFirst();

    // This function returns the next element in the list.
    // RETURNS: pointer to the next element in the list.
    const SettingElement *listGetNext();
};

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VAPP_HS_SHORTCUT_MGR_H__ */

