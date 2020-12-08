/*  Copyright Statement:
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
 *  vapp_sns_factory.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_FACTORY_H__
#define __VAPP_SNS_FACTORY_H__

#include "mmi_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vfx_object.h"
#include "vcp_form.h"
#include "vfx_page.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvGprot.h"
#ifdef __cplusplus
}
#endif

/*
 * Macro to declare a widget factory.
 */
#define VAPP_SNS_DECLARE_CLASS(_className)                       \
    VFX_DECLARE_CLASS(_className);                                          \
    public:                                                                 \
        static inline VappSnsFactory *createFactory(VfxObject* parentObj) \
        {                                                                   \
            VappSnsFactory *factory;                                     \
            VFX_OBJ_CREATE(factory, _className, parentObj);                     \
            return factory;                                                 \
        }

/*
 * Macro to implement a widget factory.
 */
#define VAPP_SNS_IMPLEMENT_CLASS(_className)                     \
    VFX_IMPLEMENT_CLASS(#_className, _className, VappSnsFactory);        \

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
/*
 *  Toolbar Controller Base Class
 */
class VappSnsToolBarController : public VfxObject
{
    VFX_DECLARE_CLASS(VappSnsToolBarController);

// Constructor / Destructor
public:
    // Default constructor.
    VappSnsToolBarController();

    // Default destructor.
    virtual ~VappSnsToolBarController();
    
// Method
public:
    // This function used to get a extended tool bar button counts.
    // RETURNS: extended toolbar button counts.
    virtual VfxU8 getCounts() = 0;
   
    // This function is used to create extended tool bar items
    // RETURNS: the id of tool bar item
    virtual VfxId getItem(
        VfxU8 index,                                            // [IN] index
        VfxWString &buttonString,                               // [OUT] the tool bar item string
        VfxImageSrc &buttonIcon,                                // [OUT] the tool bar item icon
        srv_sns_object_enum objType = SRV_SNS_OBJECT_OTHER,     // [IN] object type
        void *obj = NULL                                        // [IN] object param     
    ) = 0;

    // This function is used to get extended tool bar item states
    // RETURNS: enable or not
    virtual VfxBool getIsItemEnabled(
        VfxId id
    ) = 0;

    // This function is used to handle extended tool bar item clicked event
    // RETURNS:void
    virtual void onItemClicked(
        VfxId id,                              // [IN] tool bar item id 
        srv_sns_object_enum objType,           // [IN] object type
        void *obj,                             // [IN] object param 
        VfxS32 listId = 0,                         // [IN] list id which want to update
        VfxU32 index = 0                          // [IN] index of list
    ) = 0;    

// Signal
public:
    // This signal is used to notify the toolbar item text or image changed
    VfxSignal1 <VfxId> m_signalItemContentChanged;

    // This signal is used to notify the toolbar status changed
    VfxSignal1 <VfxId> m_signalItemStatusChanged;
};


/*
 * Sns Factory Base Class
 */
class VappSnsFactory : public VfxObject
{
    VFX_DECLARE_CLASS(VappSnsFactory);
// Constructor / Destructor
public:
    // Default constructor.
    VappSnsFactory();

    // Default destructor.
    virtual ~VappSnsFactory();

public:
    static VfxPage* getParentPage(VfxObject* obj);
    
// Method
public:
    // This function creates a album launcher cell.
    // RETURNS: the created album launcher cell.
#ifdef __MMI_SNS_ALBUM__
    virtual VcpFormItemLauncherCell* createAlbumAccLauncherCell(srv_sns_account_struct *account, VcpForm *parentCp, VfxPage *parentPage);
#endif

    // This function create the extend frame which is appeneded to happenings cell.
    // RETURNS: void
    virtual void createHappeningsExtendString(
        srv_sns_activity_struct *activity,
        VfxWString &str, 
        VfxObject *parentObj
    );

    // This function creates a toolbar controller
    // RETURNS: the created toolbar controller object
    virtual VappSnsToolBarController *createToolBarController(
        VfxObject *parentObj                    // [IN] parent object
    );

    // This function get comment editor default string
    // RETURNS: default string want to show in comment editor
    virtual void getCommentEditorDefaultString(
        VfxWString &str, 
        VfxObject *parentObj
    );
};

class VappCommonFactory : public VappSnsFactory
{
    VAPP_SNS_DECLARE_CLASS(VappCommonFactory);
    
// Override
public:
    // This function creates a widget.
    // RETURNS: the created widget.
#ifdef __MMI_SNS_ALBUM__
    virtual VcpFormItemLauncherCell* createAlbumAccLauncherCell(
        srv_sns_account_struct *account,         // [IN] Id of the widget
        VcpForm *parentCp,            // [IN] Parent of the widget
        VfxPage *parentPage
    ) {return NULL;}
#endif

    
    // This function create the extend frame which is appeneded to happenings cell.
    // RETURNS: the created extend frame
    virtual void createHappeningsExtendString(
        srv_sns_activity_struct *activity,       // [IN] activity
        VfxWString &str, 
        VfxObject *parentObj                    // [IN] parent of the extend frame
    ) {return;}

    // This function creates a toolbar controller
    // RETURNS: the created toolbar controller object
    virtual VappSnsToolBarController *createToolBarController(
        VfxObject *parentObj                    // [IN] parent object
    ) {return NULL;}

    // This function get comment editor default string
    // RETURNS: default string want to show in comment editor
    virtual void getCommentEditorDefaultString(
        VfxWString &str, 
        VfxObject *parentObj
    ){return;}
};



class VappSnsKit : public VfxObject
{
    VFX_DECLARE_CLASS(VappSnsKit);

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappSnsKit);

public:
    typedef VappSnsFactory *(*sns_fac_createFunc)(VfxObject* parentObj);

    typedef struct _sns_fac_struct
    {
        VfxU32 id;
        sns_fac_createFunc createfunc;
    } sns_fac_struct;
    
public:
    VappSnsKit();

public:
    // This function creates the widgets.
    // RETURNS: the created widget.
#ifdef __MMI_SNS_ALBUM__
    VcpFormItemLauncherCell* createAlbumAccLauncherCell(
        srv_sns_account_struct *account,         // [IN] Id of the widget
        VcpForm *parentCp,            // [IN] Parent of the widget
        VfxPage *parentPage
    );
#endif

    // This function creates the extend frame which is appeneded to happenings cell.
    // RETURNS: void
    void createHappeningsExtendString(
        srv_sns_activity_struct *activity,       // [IN] activity
        VfxWString &str,                           // [OUT] extend string content
        VfxObject *parentObj                     // [IN] parent object
    );

    // This function creates a toolbar controller
    // RETURNS: the created toolbar controller object
    VappSnsToolBarController *createToolBarController(
        VfxU32 provider, 
        VfxObject *parentObj
    );

    // This function get comment editor default string
    // RETURNS: default string want to show in comment editor
    void getCommentEditorDefaultString(
        VfxU32 provider, 
        VfxWString &str, 
        VfxObject *parentObj
    );

// Override
protected:
    virtual void onInit();

// Implementation
private:
    VappSnsFactory *findFactory(VfxU32 provider, VfxObject *parentObj);

// Variable
private:
    // The number of widget kits.
    VfxS32 m_numOfFactory;
    // The number of widget kits.
    VfxS32 m_numOfExportFactory;
};
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#endif /* __VAPP_SNS_FACTORY_H__ */

