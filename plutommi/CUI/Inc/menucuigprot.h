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
 *   MenuCuiGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Menu Common UI header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef CUI_MENUCUI_GPROT_H
#define CUI_MENUCUI_GPROT_H

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "ScreenRotationGprot.h"

/*******************************************************************************
* Macro Define
*******************************************************************************/

/* Error return code for CUI MENU list invalid index */
#define CUI_MENU_INDEX_NOT_FOUND      (-1) 

/* Error return code for CUI MENU list invalid menuid */
#define CUI_MENU_MENUID_NOT_FOUND    (-1)  

/* Flags to set the menu type property of the current menu */

/* Menu CUI flag to set the current menu as normal list */
#define CUI_MENU_NORMAL_LIST                                                                                        0x00000001
/* Menu CUI flag to set the current menu as check box list */                                      
#define CUI_MENU_NORMAL_CHECK_BOX_LIST                                                                              0x00000002
/* Menu CUI flag to set the current menu as radio button list */
#define CUI_MENU_NORMAL_RADIO_BUTTON_LIST                                                                           0x00000004 
/* Menu CUI flag to set the current menu as radio button list with hints*/
#define CUI_MENU_RADIO_BUTTON_LIST_WITH_HINTS                                                                       0x00000008
/* Menu CUI flag to set the current menu as check box list without toggling */
#define CUI_MENU_CHECK_BOX_LIST_WITHOUT_TOGGLE                                                                      0x00000010
/* Menu CUI flag to set current menu as radio list with scrolling title */
#define CUI_MENU_RADIO_LIST_WITH_SCROLLING_TITLE                                                                    0x00000020   
/* Menu CUI flag to set the current menu as list with menu id driven highlighter */
#define CUI_MENU_LIST_WITH_MENUID_DRIVEN_HIGHLIGHTER                                                                0x00000040
/* Menu CUI flag to set current menu as list with no margin when no icon */
#define CUI_MENU_LIST_WITH_NO_MARGIN_WHEN_NO_ICON                                                                   0x00000080
/* Menu CUI flag to set current menu as list with no icons */
#define CUI_MENU_LIST_WITH_NO_ICON                                                                                  0x00000100
/* Menu CUI flag to set current menu as list with 2 text  rows and 1 icon */
#define CUI_MENU_LIST_WITH_DOUBLE_TEXT_SINGLE_ICON                                                                  0x00000200
/* Menu CUI flag to set current menu as list with 1 text  rows and 2 icon , icon text icon */
#define CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON                                                   0x00000400
/* Menu CUI flag to set current menu as list with 1 text  rows and 2 icon , icon icon text */
#define CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_ICON_TEXT                                                   0x00000800
/* Menu CUI flag to set current menu as list with 1 text  rows and 2 icon , text icon icon */
#define CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_TEXT_ICON_ICON                                                   0x00001000
/* Menu CUI flag to set current menu as list with 1 text  rows and 2 icon with hints, icon text icon */
#define CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_TEXT_ICON                                        0x00002000
/* Menu CUI flag to set current menu as list with 1 text  rows and 2 icon with hints, icon icon text */
#define CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_ICON_TEXT                                        0x00004000
/* Menu CUI flag to set current menu as list with 1 text  rows and 2 icon with hints, text icon icon */
#define CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON                                        0x00008000
/* Menu CUI flag to set current menu as list with Text Numbered Items */
#define CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS                                                                      0x00010000
/* Menu CUI flag to set current menu as list with Numbered Icons */
#define CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS                                                                   0x00020000

/* Flags for CUI Menu Events */

/* CUI Event Flag for event EVT_ID_CUI_MENU_LIST_ENTRY  or EVT_ID_CUI_MENU_LIST_EXIT when coming from history */

#define CUI_MENU_LIST_FROM_HISTORY     0x0001


/*******************************************************************************
* Enum Define
*******************************************************************************/


/* Menu Type */
typedef enum
{  /*Menu type as the resources for resource tree, basically APP will pass this type of menu type when it wants to set the actual menu type from resources */
    CUI_MENU_TYPE_FROM_RESOURCE,
    /* Application main menu: 1st level of application menu, if application passes this for resource tree then this menu type will over-ride the resource setting */
    CUI_MENU_TYPE_APPMAIN,
    /* Application sub menu: Rest application menu is sub menu, if application passes this for resource tree then this menu type will over-ride the resource setting */
    CUI_MENU_TYPE_APPSUB,
    /* Option menu, if application passes this for resource tree then this menu type will over-ride the resource setting */ 
    CUI_MENU_TYPE_OPTION
} cui_menu_type_enum;


/* Menu cui resource type */
typedef enum
{
    /* CUI Menu src type : from resources */
    CUI_MENU_SRC_TYPE_RESOURCE,
    /* CUI Menu src type : Created by APP on run time(Dynamically) */
    CUI_MENU_SRC_TYPE_APPCREATE
 } cui_menu_src_type_enum;


/* Menu cui events */
typedef enum
{
    /* CUI Menu show event sent to APP before entering list menu screen */
    EVT_ID_CUI_MENU_LIST_ENTRY= CUI_MENU_BASE,
    /* CUI Menu exit event : sent to APP on exiting list menu screen */
    EVT_ID_CUI_MENU_LIST_EXIT,
    /* CUI Menu highlight event : send to APP by the menu cui highlight handler */
    EVT_ID_CUI_MENU_ITEM_HILITE,
    /* CUI Menu action event : send to APP when on menu item LSK selection (select/ok/done press) on menu screen, APP can close the menu cui in this event  */
    EVT_ID_CUI_MENU_ITEM_SELECT,
    /* CUI Menu tap event : send to APP when highlighted menu item is tapped, APP can close the menu cui in this event  */
    EVT_ID_CUI_MENU_ITEM_TAP,
    /* CUI Menu action event : send to APP when on menu item CSK selection (select/ok/done press) on menu screen, APP can close the menu cui in this event  */
    EVT_ID_CUI_MENU_ITEM_CSK_SELECT,
    /*CUI Menu close request event : send request to APP for closing the CUI menu instance */
    EVT_ID_CUI_MENU_CLOSE_REQUEST,
    /*CUI Menu check box change state event: send to the APP when the menuitem is selected or unselected in check box menu so that APP may change the state of other menu items */
    EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE,	
	/*CUI Menu Dinit: send to the app when menu cui group is deinit and recieve the deinit event from frame work, App can clear its context here */
	EVT_ID_CUI_MENU_LIST_DEINIT,
    /* Total events for Menu CUI */
    EVT_ID_CUI_MENU_EVENT_ALL
} cui_menu_event_enum;


/*******************************************************************************
* Structure Define
*******************************************************************************/
/* Menu cui event struct : It contains parent and highlighted menu id that will be passed to APP when the event is send to it.    
 1) On EVT_ID_CUI_MENU_ITEM_HILITE                             : Highlighted and parent menu id of menu list
 2) On EVT_ID_CUI_MENU_ITEM_SELECT                             : Highlighted and parent menu id of menu list
 3) On EVT_ID_CUI_MENU_LIST_ENTRY                              : Only parent menu id of menu list
 4) On EVT_ID_CUI_MENU_LIST_EXIT                               : Only parent menu id of the previous menu screen 
 */
typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_menu_id parent_menu_id;
    mmi_menu_id highlighted_menu_id; 	
    U16 cui_menu_event_flags;	
    void * app_data;	
} cui_menu_event_struct;


/*******************************************************************************
* Export API 
*******************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************              
 * FUNCTION
 *  cui_menu_init
 * DESCRIPTION
 *  It initializes the menu CUI. It is called only once while booting up the target.
 * PARAMETERS
 *  void                   
 * RETURNS
 *  void
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_init(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_create
 * DESCRIPTION
 *  It creates the cui menu instance, cui menu group is created. 
 * PARAMETERS
 *  parent_gid              : [IN] Group ID of the parent 
 *  src_type                : [IN] Source type of the menu cui : CUI_MENU_SRC_TYPE_RESOURCE or CUI_MENU_SRC_TYPE_APPCREATE
 *  menu_type               : [IN] Menu type of cui menu instance, passed when src type is CUI_MENU_SRC_TYPE_APPCREATE, follow cui_menu_type_enum 
 *  root_menu_id            : [IN] Root id of the menu tree, passed in case the instance's source is CUI_MENU_SRC_TYPE_RESOURCE  
 *  is_item_flags_from_res  : [IN] Flag determines whether the menu item flags are set from res or cui menu instance  
 *  parent_data             : [IN] Parent's user data, only for the caller (application) usage
 * RETURNS
 *  mmi_id
 * RETURN VALUES
 *  group id of the cui menu group created
*****************************************************************************/
mmi_id cui_menu_create(mmi_id parent_gid,
                       cui_menu_src_type_enum src_type,
                       cui_menu_type_enum menu_type,
                       mmi_menu_id root_menu_id,
                       MMI_BOOL is_item_flags_from_res,
                       void* parent_data);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_run
 * DESCRIPTION
 *  It enters the cui menu group, does some initialization for that cui menu instance.
 * PARAMETERS
 *  owner_gid  : [IN] Menu cui group ID from cui_menu_create
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/
extern void  cui_menu_run(mmi_id owner_gid);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_create_and_run
 * DESCRIPTION
 *  It creates and then run the cui menu instance, cui menu group is created. 
 * PARAMETERS
 *  parent_gid              : [IN] Group ID of the parent 
 *  src_type                : [IN] Source type of the menu cui : CUI_MENU_SRC_TYPE_RESOURCE or CUI_MENU_SRC_TYPE_APPCREATE
 *  menu_type               : [IN] Menu type of cui menu instance, passed when src type is CUI_MENU_SRC_TYPE_APPCREATE, follow cui_menu_type_enum 
 *  root_menu_id            : [IN] Root id of the menu tree, passed in case the instance's source is CUI_MENU_SRC_TYPE_RESOURCE  
 *  is_item_flags_from_res  : [IN] Flag determines whether the menu item flags are set from res or cui menu instance  
 *  parent_data             : [IN] Parent's user data, only for the caller (application) usage
 * RETURNS
 *  mmi_id
 * RETURN VALUES
 *  group id of the cui menu group created
*****************************************************************************/
extern mmi_id cui_menu_create_and_run(mmi_id parent_gid,
                       cui_menu_src_type_enum src_type,
                       cui_menu_type_enum menu_type,
                       mmi_menu_id root_menu_id,
                       MMI_BOOL is_item_flags_from_res,
                       void* parent_data);
/*****************************************************************************              
 * FUNCTION
 *  cui_menu_close
 * DESCRIPTION
 *  It closes the cui menu group.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_close(mmi_id owner_gid);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title
 * DESCRIPTION
 *  It sets Default title of menu cui, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  str           : [IN] title string 
 *  img           : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_default_title(mmi_id owner_gid, WCHAR* str, UI_image_type img);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title_by_id
 * DESCRIPTION
 *  It sets Default title of menu cui using string and image ids, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  str_id        : [IN] title string id
 *  img_id        : [IN] title image id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_default_title_by_id(mmi_id owner_gid, U16 str_id, U16 img_id);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title_string
 * DESCRIPTION
 *  It sets default title string of menu cui, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  str                : [IN] title string 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_string(mmi_id owner_gid, WCHAR* str);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title_string_by_id
 * DESCRIPTION
 *  It sets default title string of menu cui using string id, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  str_id             : [IN] title string id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_string_by_id(mmi_id owner_gid, U16 str_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title_image
 * DESCRIPTION
 *  It sets default title image of menu cui, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  str                : [IN] title string 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_image(mmi_id owner_gid, UI_image_type img);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title_image_by_id
 * DESCRIPTION
 *  It sets default title image of menu cui using image id, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  img_id             : [IN] title image id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_image_by_id(mmi_id owner_gid, U16 img_id);


/****************************************************************************            
 * FUNCTION
 *  cui_menu_get_default_title_image
 * DESCRIPTION
 *  get default title image of menu cui
 * PARAMETERS
 *  owner_gid             : [IN] menu cui owner group id
 *  img                       : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_get_default_title_image(mmi_id owner_gid, UI_image_type  *img);



/****************************************************************************          
 * FUNCTION
 *  cui_menu_set_default_left_softkey
 * DESCRIPTION
 *  It sets Default left softkey label of menu cui, the left softkey label will be default unless current left softkey label
 *  is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  lsk_str       : [IN] lsk string
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_default_left_softkey(mmi_id owner_gid, WCHAR* lsk_str);

/****************************************************************************          
 * FUNCTION
 *  cui_menu_set_default_left_softkey_by_id
 * DESCRIPTION
 *  It sets Default left softkey label of menu cui by string id, the left softkey label will be default unless current left softkey label
 *  is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  lsk_str_id       : [IN] lsk string id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_default_left_softkey_by_id(mmi_id owner_gid, U16 lsk_str_id);


/****************************************************************************          
 * FUNCTION
 *  cui_menu_set_default_right_softkey
 * DESCRIPTION
 *  It sets Default right softkey label of menu cui, the right softkey label will be default unless current right softkey label
 *  is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  rsk_str       : [IN] rsk string 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_default_right_softkey(mmi_id owner_gid, WCHAR* rsk_str);


/****************************************************************************          
 * FUNCTION
 *  cui_menu_set_default_right_softkey_by_id
 * DESCRIPTION
 *  It sets Default right softkey label of menu cui by id, the right softkey label will be default unless current right softkey label
 *  is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  rsk_str_id    : [IN] rsk string id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_default_right_softkey_by_id(mmi_id owner_gid, U16 rsk_str_id);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_title
 * DESCRIPTION
 *  It sets current title of current menu list, if current list title is set then it will override the default title setting
 *  for the cui menu. Current title needs to be set for each menu list in the cui menu if default title is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  str                : [IN] title string 
 *  img                : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_currlist_title(mmi_id owner_gid, WCHAR* str, UI_image_type img);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_title
 * DESCRIPTION
 *  It sets current title of current menu list using string and image Ids, if current list title is set then it will override the default title setting
 *  for the cui menu. Current title needs to be set for each menu list in the cui menu if default title is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  str_id             : [IN] title string id
 *  img_id             : [IN] title image id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_currlist_title_by_id(mmi_id owner_gid, U16 str_id, U16 img_id);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_left_softkey
 * DESCRIPTION
 *  It sets current left softkey label of current menu list, if current list left softkey label is set then it will override the default left softkey label setting
 *  for the cui menu. Current left softkey label needs to be set for each menu list in the cui menu if default left softkey label is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid    : [IN] Menu cui group ID from cui_menu_create
 *  lsk_str      : [IN] lsk string
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_currlist_left_softkey(mmi_id owner_gid, WCHAR* lsk_str);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_left_softkey_by_id
 * DESCRIPTION
 *  It sets current left softkey label of current menu list, if current list left softkey label is set then it will override the default left softkey label setting
 *  for the cui menu. Current left softkey label needs to be set for each menu list in the cui menu if default left softkey label is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid    : [IN] Menu cui group ID from cui_menu_create
 *  lsk_str_id   : [IN] lsk string id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_currlist_left_softkey_by_id(mmi_id owner_gid, U16 lsk_str_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_right_softkey
 * DESCRIPTION
 *  It sets current right softkey label of current menu list, if current list right softkey label is set then it will override the default right softkey label setting
 *  for the cui menu. Current right softkey label needs to be set for each menu list in the cui menu if default right softkey label is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid       : [IN] Menu cui group ID from cui_menu_create
 *  rsk_str         : [IN] rsk string
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_currlist_right_softkey(mmi_id owner_gid, WCHAR* rsk_str);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_right_softkey_by_id
 * DESCRIPTION
 *  It sets current right softkey label of current menu list, if current list right softkey label is set then it will override the default right softkey label setting
 *  for the cui menu. Current right softkey label needs to be set for each menu list in the cui menu if default right softkey label is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid       : [IN] Menu cui group ID from cui_menu_create
 *  rsk_str_id         : [IN] rsk string
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_currlist_right_softkey_by_id(mmi_id owner_gid, U16 rsk_str_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_flags
 * DESCRIPTION
 *  It sets current menu list flags of current menu screen.
 *  The flag value can be CUI_MENU_NORMAL_LIST, CUI_MENU_NORMAL_CHECK_BOX_LIST or CUI_MENU_NORMAL_RADIO_BUTTON_LIST 
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  flags         : [IN] Flags of current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_currlist_flags(mmi_id owner_gid, U32 flags);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist
 * DESCRIPTION
 *  It sets the sub menu ids of curent menu list screen. This api is used in case where APP wants to set the 
 *  the menu items of the list menu dynamically at run time.
 *  List of id cannot be more than MAX_SUB_MENUS
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid            : [IN] Menu cui group ID from cui_menu_create
 *  number_of_items      : [IN] Number of items in current menu list screen
 *  list_of_ids          : [IN] list of menu ids in current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
 *
 * EXAMPLE		                            
 *  <code>
 *  case EVT_ID_CUI_MENU_LIST_ENTRY:
 *  {
 *      if(((cui_menu_event_struct*)evt)->parent_menu_id == MENU_ID_PHNSET_PREFERED_WRITING_LANG)
 *      {
 *          U16 menuid_array[4] = {0, 1, 2, 3};
 *          U8 sub_menu[30];
 *          U8 hint_menu[30];
 *          S32 i = 0;
 *          if(((cui_menu_event_struct*)evt)->sender_id == child_menu_gid)
 *          {
 *              cui_menu_set_currlist_flags(child_menu_gid, CUI_MENU_NORMAL_CHECK_BOX_LIST);
 *               cui_menu_set_currlist(child_menu_gid, 4, menuid_array);
 *              for(i = 0; i < 4; i++)
 *              {
 *                  gui_sprintf(sub_menu, "mti0010%d", i);
 *                  cui_menu_set_item_string(child_menu_gid, i, (WCHAR*)sub_menu);
 *              }
 *              cui_menu_set_checkbox_state(child_menu_gid, check_box_states);
 *          }
 *      }
 *      break;
 *  }
 *  </code>
*****************************************************************************/
extern void cui_menu_set_currlist(mmi_id owner_gid, S32 number_of_items, mmi_menu_id* list_of_ids);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_insert_currlist
 * DESCRIPTION
 *  Insert  the data in curent menu list screen after a certain menu id
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  number_of_items               : [IN] Number of items in current menu list screen
 *  list_of_ids                          : [IN] list of menu ids to be inserted in current menu list screen
 *  after_menu_id                    : [IN] menu ids after which inserted in current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_insert_currlist(mmi_id owner_gid, S32 number_of_items, mmi_menu_id* list_of_ids, mmi_menu_id after_menu_id );


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_delete_currlist_menuid
 * DESCRIPTION
 *  Delete a menu id from the currlist
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  delete_menu_id                  : [IN] menu ids which needs to be deleted in current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_delete_currlist_menuid(mmi_id owner_gid, mmi_menu_id delete_menu_id );


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_delete_currlist
 * DESCRIPTION
 *  Delete  list of menuid  from  current menu list screen
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  number_of_items               : [IN] Number of items to be deleted
 *  list_of_ids                          : [IN] list of menu ids to be deleted in current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_delete_currlist(mmi_id owner_gid, S32 number_of_items, mmi_menu_id* list_of_ids); 


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_string
 * DESCRIPTION
 *  It sets the sub-menu string corresponding to the menuid of the menu item of curent menu list screen.
 *  This api should be called in show event handling of cui menu for a particular screen
 *  or for refreshing the current list menu with new menuitem info without the change in the no. of menu items in the list 
 * PARAMETERS
 *  owner_gid             : [IN] Menu cui group ID from cui_menu_create
 *  menu_id               : [IN] Menu ID of the menu-item
 *  str                   : [IN] String of the menu-item
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_item_string(mmi_id owner_gid, mmi_menu_id menu_id, WCHAR* str);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_string_by_id
 * DESCRIPTION
 *  It sets the sub-menu string corresponding to the menuid of the menu item of curent menu list screen.
 *  This api should be called in show event handling of cui menu for a particular screen
 *  or for refreshing the current list menu with new menuitem info without the change in the no. of menu items in the list 
 * PARAMETERS
 *  owner_gid             : [IN] Menu cui group ID from cui_menu_create
 *  menu_id               : [IN] Menu ID of the menu-item
 *  str_id                   : [IN] String id of the menu-item
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_item_string_by_id(mmi_id owner_gid, mmi_menu_id menu_id, U16 str_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_hint
 * DESCRIPTION
 *  It sets the hint string corresponding to the menuid of the menu item of curent menu list screen.
 *  This api should be called in show event handling of cui menu for a particular screen.
 *  or for refreshing the current list menu with new menuitem info without the change in the no. of menu items in the list 
 * PARAMETERS
 *  owner_gid            : [IN] Menu cui group ID from cui_menu_create
 *  menu_id              : [IN] Menu ID of the menu-item
 *  str                  : [IN] Hint String of the menu-item
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_item_hint(mmi_id owner_gid, mmi_menu_id menu_id, WCHAR* str);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_image
 * DESCRIPTION
 *  It sets the menu item image corresponding to the menuid of the menu item of curent menu list screen.
 *  This api should be called in show event handling of cui menu for a particular screen.
 *  or for refreshing the current list menu with new menuitem info without the change in the no. of menu items in the list 
 * PARAMETERS
 *  owner_gid            : [IN] Menu cui group ID from cui_menu_create
 *  menu_id              : [IN] Menu ID of the menu-item
 *  img                  : [IN] Image  for the menu-item
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_item_image(mmi_id owner_gid, mmi_menu_id menu_id, U16 img_icon);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_second_image
 * DESCRIPTION
 *  It sets the menu items second image corresponding to the menuid of the menu item of curent menu list screen with double icons.
 *  This api should be called in show event handling of cui menu for a particular screen.
 *  or for refreshing the current list menu with new menuitem info without the change in the no. of menu items in the list 
 * PARAMETERS
 *  owner_gid                           :  [IN] Menu GID from cui_menu_create
 *  menu_id                             : [IN] Menu ID of the menu-item
 *  img                                 : [IN] Image  for the menu-item
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_item_second_image(mmi_id owner_gid, mmi_menu_id menu_id, U16 img_icon);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_hidden
 * DESCRIPTION
 *  It hides or unhides a menu id. 
 *  This api can be called anytime after the cui menu group has been created.
 * PARAMETERS
 *  owner_gid                          : [IN] Menu GID from cui_menu_create
 *  menu_id                            : [IN] Menu ID of the menu-item
 *  is_hidden_flag                     : [IN] Is the menu id need to be hidden
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_item_hidden(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL is_hidden_flag);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_group_hidden
 * DESCRIPTION
 *  It hides or unhides a menu id group. 
 *  This api can be called anytime after the cui menu group has been created.
 * PARAMETERS
 *  owner_gid                          : [IN] Menu GID from cui_menu_create
 *  menu_id_group                   : [IN] Menu ID group
 *  is_hidden_flag                     : [IN] Is the menu group need to be hidden
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_group_hidden(mmi_id owner_gid, U16 menu_id_group, MMI_BOOL is_hidden_flag);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_disabled
 * DESCRIPTION
 *  It disables or enables a menu id. 
 *  This api can be called anytime after the cui menu group has been created.
 * PARAMETERS
 *  owner_gid                          : [IN] Menu GID from cui_menu_create
 *  menu_id                            : [IN] Menu ID of the menu-item
 *  is_disabled_flag                   : [IN] Is the menu id need to be disabled
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_item_disabled(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL is_disabled_flag);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_group_disabled
 * DESCRIPTION
 *  It disables or enables a menu id group. 
 *  This api can be called anytime after the cui menu group has been created.
 * PARAMETERS
 *  owner_gid                          : [IN] Menu GID from cui_menu_create
 *  menu_id_group                   : [IN] Menu ID group 
 *  is_disabled_flag                  : [IN] Is the menu group need to be disabled
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_group_disabled(mmi_id owner_gid, U16 menu_id_group, MMI_BOOL is_disabled_flag);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_checkbox_state
 * DESCRIPTION
 *  It sets the check box states of the menu items of the menu list screen. The APP needs to
 *  send the state of all the menu ids in the menu list whether they are hidden, unhidden,
 *  enabled or disabled. CUI Menu will take care to see which all menu ids are hidden or disabled.
 *  The max list of states size could be MAX_SUB_MENUS.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  list_of_states     : [IN] pointer to the list of states
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_checkbox_state(mmi_id owner_gid, U8* list_of_states);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_checkbox_state
 * DESCRIPTION
 *  It gets the check box states of the menu items of the menu list screen. The list of states
 *  will include only the states of the menu items which are enabled and unhidden. Rest all will
 *  be removed by menu cui. The max list of states size could be MAX_SUB_MENUS.
 *  This api should be called in exit event handling of cui menu for a the previous screen.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  list_of_states     : [OUT] pointer to the list of states
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_get_checkbox_state(mmi_id owner_gid, U8* list_of_states);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_highlighted_id
 * DESCRIPTION
 *  It sets the current menu list's highlighted menu id of the menu item.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid              : [IN] Menu cui group ID from cui_menu_create
 *  menu_id                : [IN] menu id of the menu item to be set as highlighted
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_currlist_highlighted_id(mmi_id owner_gid, mmi_menu_id menu_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_radio_list_item
 * DESCRIPTION
 *  It sets current selected menu id for the radio list  
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  menu_id                           : [IN] pointer to the list of states
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_radio_list_item(mmi_id owner_gid, mmi_menu_id menu_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_enable_cascading_option_menu
 * DESCRIPTION
 *  Enable the cascading type option menu called before run.
 *  If you want to override the default setting of lsk, rsk string
 *  for cascaded option menu then do that after calling this api
 *  because this api will also do the default setting for lsk and rsk. 
 * PARAMETERS
 *  owner_gid             : [IN] Menu cui group ID from cui_menu_create
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_enable_cascading_option_menu(mmi_id owner_gid);



/*****************************************************************************              
 * FUNCTION
 *  cui_menu_disable_cascading_option_menu
 * DESCRIPTION
 *  Disable the cascading type option menu, called before run.
 *  If you want to override the default cascading option menu layout then call this api. 
 *  If you want to override the default setting of  lsk/rsk 
 *  for option menu then do that after calling this api
 *  because this api will also do the default setting for lsk and rsk. 
 * PARAMETERS
 *  owner_gid             : [IN] Menu cui group ID from cui_menu_create
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_disable_cascading_option_menu(mmi_id owner_gid);



/*****************************************************************************              
 * FUNCTION
 *   cui_menu_set_non_leaf_item
 * DESCRIPTION
 *   set the item as non leaf in the menu list , needs to be called in the show event
 *   Menu items in Radio and check box lists are always leaf nodes so no need to call this API
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 *  menu_id                            :  [IN] Menu ID of the menu-item
 *  flag                                   :  [IN] Flag to set the menu item as no leaf or leaf node
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_non_leaf_item(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL flag);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_new_list_parent_id
 * DESCRIPTION
 *  Set the new parent id of curent CUI menu
 *  This api has to be called by APP only when it receives the action event from CUI menu
 *  This api helps the APP to connect to some other tree with the same cui menu. 
 * PARAMETERS
 *  owner_gid                     : [IN] Menu GID from cui_menu_create
 *  parent_menu_id                : [IN] New parent menu id for the next list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_new_list_parent_id(mmi_id owner_gid, mmi_menu_id parent_menu_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_currlist_item_count
 * DESCRIPTION
 *  It gets the current menu lists total items.
 *  This api can  be called by APP when it receives the entry, highlight or select event from CUI menu
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  No. of items in the list menu
 * RETURN VALUES
 *  ReturnValue : count of items
*****************************************************************************/
extern S32 cui_menu_get_currlist_item_count(mmi_id owner_gid);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_currlist_menu_id_from_index
 * DESCRIPTION
 *  It gets the menu id from current menu lists for the index passed to it.
 *  This api can  be called by APP when it receives the entry, highlight or select event from CUI menu
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  index                             : [IN] Index of the menu item in the list
 * RETURNS 
 *  menu id of the menu item in the list menu 
 * RETURN VALUES
 *  ReturnValue : menu id 
*****************************************************************************/
extern mmi_menu_id cui_menu_get_currlist_menu_id_from_index(mmi_id owner_gid, S32 index );


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_index_in_currlist_from_menu_id
 * DESCRIPTION
 *  It gets the index in current menu lists for the menu_id passed to it.
 *  This api can  be called by APP when it receives the entry, highlight or select event from CUI menu
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  menu_id                           : [IN] Menu id of the item in the list
 * RETURNS 
 *  index of the menu id in the enu list 
 * RETURN VALUES
 *  ReturnValue : Valid index of the menu item or CUI_MENU_INDEX_NOT_FOUND
*****************************************************************************/
extern S32 cui_menu_get_index_in_currlist_from_menu_id(mmi_id owner_gid, mmi_menu_id menu_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_change_left_softkey_string
 * DESCRIPTION
 *  This api has to be called by APP only when it receives the highlight event from CUI menu
 *  This api helps the APP to change the left softkey label of the list menu of the cui menu . 
 * PARAMETERS
 *  owner_gid                            : [IN] Menu GID from cui_menu_create
 *  lsk_str                              : [IN] new lsk string label
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_change_left_softkey_string(mmi_id owner_gid, WCHAR* lsk_str);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_change_left_softkey_string_by_id
 * DESCRIPTION
 *  This api has to be called by APP only when it receives the highlight event from CUI menu
 *  This api helps the APP to change the left softkey label of the list menu of the cui menu . 
 * PARAMETERS
 *  owner_gid                            : [IN] Menu GID from cui_menu_create
 *  lsk_str_id                              : [IN] new lsk string label
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_change_left_softkey_string_by_id(mmi_id owner_gid, U16 lsk_str_id);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_change_center_softkey_content
 * DESCRIPTION
 *  This api has to be called by APP only when it receives the highlight event from CUI menu
 *  This api helps the APP to change the center softkey label of the list menu of the cui menu . 
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  lsk_str                               : [IN] New lsk string label
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_change_center_softkey_content(mmi_id owner_gid, WCHAR* lsk_str, UI_image_type img );



/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_src_type
 * DESCRIPTION
 *  This api has to be called by APP to know the source type of cui menu
 *   It can be called any time after the creation of cui menu
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  enum value of  cui_menu_src_type_enum which tells whether the cui menu tree is from resource or APP created
 * RETURN VALUES
 *  CUI_MENU_SRC_TYPE_RESOURCE or CUI_MENU_SRC_TYPE_APPCREATE
*****************************************************************************/
extern cui_menu_src_type_enum cui_menu_get_src_type(mmi_id group_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_is_menu_event
 * DESCRIPTION
 *  This api has to be called by APP to know whether the current event received is from cui menu
 *   It can be called any time when it receives any event
 * PARAMETERS
 *  evt_id                         : [IN] Event id 
 * RETURNS 
 *  Bool value whether the event is cui menu defined or not 
 * RETURN VALUES
 *  ReturnValues: 0 or 1
*****************************************************************************/
extern MMI_BOOL cui_menu_is_menu_event (U16 evt_id);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_enable_fte_sublevel_option_menu
 * DESCRIPTION
 *  Enable the small list type option menu called before run.
 * PARAMETERS
 *  owner_gid             : [IN] Menu cui group ID from cui_menu_create
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_enable_fte_sublevel_option_menu(mmi_id owner_gid);

/*****************************************************************************              
 * FUNCTION
 *   cui_menu_enable_tap_to_highlight
 * DESCRIPTION
 *   It enables tap to highlight for FTE, needs to be called in the show event.
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_enable_tap_to_highlight(mmi_id owner_gid);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_refresh_currlist
 * DESCRIPTION
 *  Refresh list for cui menu, this api will send the entry event to the APP, again for the same list menu screen
 *  so that it can again modify(refresh) the current list menu.
 *  This api needs cannot be called in the EVT_ID_CUI_MENU_LIST_ENTRY or  EVT_ID_CUI_MENU_LIST_EXIT event
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/
extern void cui_menu_refresh_currlist(mmi_id owner_gid);


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_pause
 * DESCRIPTION
 *   It pauses the cui menu to the current list menu screen (to the current level of the tree ),
 *   needs to be called in the select, csk select  or tap event .
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_pause(mmi_id owner_gid);


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_play
 * DESCRIPTION
 *   It plays the cui menu to the next list menu screen (to the next level of the tree ),
 *   needs to be called when the APP is ready after it has earlier paused the cui menu during the select, csk select  or tap event .
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_play(mmi_id owner_gid);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_override_center_softkey
 * DESCRIPTION
 *  It  overides the default csk setting and sets current APP defined csk string and icon and CUI will send csk event to APP
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  csk_str                : [IN] title string 
 *  csk_img                : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_override_center_softkey(mmi_id owner_gid, WCHAR* csk_str, UI_image_type csk_img);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_enable_center_softkey
 * DESCRIPTION
 *  It  overides the default csk setting and sets current APP defined csk label and  icon id and CUI will send csk event to APP
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  csk_str                : [IN] title string 
 *  csk_img                : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_enable_center_softkey(mmi_id owner_gid, U16 str_id, U16 img_id);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_rotate_screen
 * DESCRIPTION
 *  It  set 
 *  This api should be called before calling cui_menu_run to rotate the screen
 * PARAMETERS
 *  owner_gid                  : [IN] Menu cui group ID from cui_menu_create
 *  rotate_type                : [IN] Rotate type
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/

extern void cui_menu_set_rotate_screen(mmi_id owner_gid, mmi_frm_screen_rotate_enum rotation);


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_access_by_shortcut
 * DESCRIPTION
 *  This api should be called in the entry event to enable or disable access by shortcut
 * PARAMETERS
 *  owner_gid                            : [IN] Menu cui group ID from cui_menu_create
 *  access_by_sc_flag                : [IN] Send True to enable and False to disable
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_menu_set_access_by_shortcut(mmi_id owner_gid,MMI_BOOL access_by_sc_flag);

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_app_parent_data
 * DESCRIPTION
 *  This api returns the app parent data associated by APP while creating menu cui
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 * RETURNS 
 *  void* 
 * RETURN VALUES
 *  Pointer to APP parent data
*****************************************************************************/
extern void * cui_menu_get_app_parent_data(mmi_id owner_gid);


#endif /* CUI_MENUCUI_GPROT_H */ 

