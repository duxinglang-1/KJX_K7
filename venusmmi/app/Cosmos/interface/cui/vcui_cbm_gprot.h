/*****************************************************************************
*
* Filename:
* ---------
* vcui_cbm_gprot.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file contains the CBM CUI APIs
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef __VCUI_CBM_GPROT_H__
#define __VCUI_CBM_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "MMI_features.h"
    #include "MMI_include.h"
    #include "CbmSrvGprot.h"
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
/***************************************************************************** 
  * Class 
 *****************************************************************************/
 
/* External interface */
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __COSMOS_MMI_PACKAGE__ 

/* common CBM CUI event */
typedef enum
{
    EVT_ID_CUI_VAPP_CBM_OK = VCUI_CBM + 1,  /* accept ok */
    EVT_ID_CUI_VAPP_CBM_FAIL,   /* error occus and cannot display the screen */
    EVT_ID_CUI_VAPP_CBM_CANCEL, /* cancel */
    EVT_ID_CUI_VAPP_CBM_TOTAL 
} vcui_cbm_event_enum;


/* this strcture is used to get the event content in the callback 
 * when it register in group creation 
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    U32 ori_account_id; /* original account id*/
    U32 selected_account_id; /* selected account id */
    srv_cbm_bearer_type_enum bearer_type; /* bearer type for selected account */
} vcui_evt_cbm_bearer_select_struct;

#define cui_cbm_parameter_struct vcui_cbm_parameter_struct

/*************************************************************************
* Structures
*************************************************************************/

/* This structure is used to define cui resource */
typedef struct
{
    U16 str_id; /* application's string id which would be displayed in CUI */
    U16 icon_id; /* application's icon id which would be displayed in CUI */
} vcui_cbm_res_struct;
    
/* This structure is used to define necessary parameters */
typedef struct
{
    U32 account_id; /* original account id*/
    vcui_cbm_res_struct res; /* screen resource */
} vcui_cbm_parameter_struct;

/*************************************************************************
* External APIs
*************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  cui_cbm_always_ask_create
 * DESCRIPTION
 *  create always ask common UI
 * PARAMETERS
 *  parent_id    : [IN]   application's group id
 * RETURN VALUES
 *  cbm cui group id
 *****************************************************************************/
mmi_id vcui_cbm_always_ask_create(mmi_id parent_id);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_always_ask_set_param
 * DESCRIPTION
 *  set always ask parameters
 * PARAMETERS
 *  cbm_id    : [IN]   cui group id
 *  param     : [IN]   cui necessary parameters
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vcui_cbm_always_ask_set_param(mmi_id cbm_id, cui_cbm_parameter_struct *param);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_always_ask_set_bearer_filter
 * DESCRIPTION
 *  set always ask cui bearer filters. For example, if you only want 
 *  gprs bearer type displayed in always cui, you can use it.
 *  we don't support wifi bearer in always ask (FTO design).
 *  please do not use WIFI.
 * PARAMETERS
 *  cbm_id          : [IN]   cui group id
 *  bearer_type     : [IN]   bearer type (srv_cbm_bearer_type_enum)
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vcui_cbm_always_ask_set_bearer_filter(mmi_id cbm_id, U32 bearer_type);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_always_ask_run
 * DESCRIPTION
 *  display always ask common ui
 * PARAMETERS
 *  cbm_id          : [IN]   cui group id
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vcui_cbm_always_ask_run(mmi_id cbm_id);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_always_ask_close
 * DESCRIPTION
 *  close always ask common ui
 * PARAMETERS
 *  cbm_id          : [IN]   cui group id
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vcui_cbm_always_ask_close(mmi_id cbm_id);
      
#endif /* __COSMOS_MMI_PACKAGE__  */

#ifdef __cplusplus
}
#endif

#endif /* __VCUI_CBM_GPROT_H__ */
