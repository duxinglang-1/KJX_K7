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
 *  vapp_sns_facebook.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_FACEBOOK_H__
#define __VAPP_SNS_FACEBOOK_H__

#include "mmi_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vcp_form.h"
#include "vfx_page.h"
#include "vapp_sns_factory.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvGprot.h"
#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
/*
 *  Toolbar Controller Base Class
 */
class VappSnsFbToolBarController : public VappSnsToolBarController
{
    VFX_DECLARE_CLASS(VappSnsFbToolBarController);

// Constructor / Destructor
public:
    // Default constructor.
    VappSnsFbToolBarController();

    // Default destructor.
    virtual ~VappSnsFbToolBarController();
    
// Method
public:
    // This function used to get a extended tool bar button counts.
    // RETURNS: extended toolbar button counts.
    virtual VfxU8 getCounts();
   
    // This function is used to create extended tool bar items
    // RETURNS: the id of tool bar item
    virtual VfxId getItem(
        VfxU8 index,                                            // [IN] index
        VfxWString &buttonString,                               // [OUT] the tool bar item string
        VfxImageSrc &buttonIcon,                                // [OUT] the tool bar item icon
        srv_sns_object_enum objType = SRV_SNS_OBJECT_OTHER,     // [IN] object type
        void *obj = NULL                                        // [IN] object param     
    );

    // This function is used to get extended tool bar item states
    // RETURNS: enable or not
    virtual VfxBool getIsItemEnabled(
        VfxId id
    );

    // This function is used to handle extended tool bar item clicked event
    // RETURNS:void
    virtual void onItemClicked(
        VfxId id,                              // [IN] tool bar item id 
        srv_sns_object_enum objType,           // [IN] object type
        void *obj,                             // [IN] object param 
        VfxS32 listId = 0,                         // [IN] list id which want to update
        VfxU32 index = 0                          // [IN] index of list        
    );    

    // This function is used to handle event
    mmi_ret onEvtHdlr( 
        mmi_event_struct *param
    );

    // This function is used to handle event
    mmi_ret isPhotoLikedCb( 
        mmi_event_struct *param
    );

// Enum
private:
    // Comments tool bar id
    enum ToolBarId {
        TOOL_BAR_ID_LIKE = 0,
        TOOL_BAR_TOTAL_NUM
    };

    // Tapped item index
    VfxId m_tappedItem;

    // Is allow like flag
    VfxBool m_allowLike;
    
    // Is unlike flag
    VfxBool m_isUnlike;

};


class VappFacebookFactory : public VappSnsFactory
{
    VAPP_SNS_DECLARE_CLASS(VappFacebookFactory);
    
// Override
public:
    // This function creates a widget.
    // RETURNS: the created widget.
#ifdef __MMI_SNS_ALBUM__
    virtual VcpFormItemLauncherCell* createAlbumAccLauncherCell(
        srv_sns_account_struct *account,         // [IN] Id of the widget
        VcpForm *parentCp,            // [IN] Parent of the widget
        VfxPage *parentPage
    );
#endif

    
    // This function create the extend frame which is appeneded to happenings cell.
    // RETURNS: the created extend frame
    virtual void createHappeningsExtendString(
        srv_sns_activity_struct *activity,       // [IN] activity
        VfxWString &str, 
        VfxObject *parentObj                    // [IN] parent of the extend frame
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

#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#endif /* __VAPP_SNS_FACEBOOK_H__ */

