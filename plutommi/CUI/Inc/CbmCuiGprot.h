/*****************************************************************************
*
* Filename:
* ---------
* CbmSrvGprot.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file contains the CBM APIs
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _CBM_CUI_GPROT_H_
#define _CBM_CUI_GPROT_H_

#include "MMI_include.h"
#include "CbmSrvGprot.h"

#include "mmi_res_range_def.h"
#include "MMIDataType.h"

#ifndef __COSMOS_MMI_PACKAGE__

/*************************************************************************
* Constant values
*************************************************************************/


/*************************************************************************
* Enum values
*************************************************************************/


/* common CBM CUI event */
typedef enum
{
    EVT_ID_CUI_CBM_OK = APP_CBM_BASE + 1,  /* accept ok */
    EVT_ID_CUI_CBM_FAIL,   /* error occus and cannot display the screen */
    EVT_ID_CUI_CBM_CANCEL, /* cancel */
    EVT_ID_CUI_CBM_TOTAL 
} cui_cbm_event_enum;

typedef enum
{
    CUI_CBM_QUERY_FB_NONE,
    CUI_CBM_QUERY_FB_NORM,  /* normal bearer fallback cui */
    CUI_CBM_QUERY_FB_WIFI_TO_PS,   /* wifi to packet service fallback cui */
    CUI_CBM_QUERY_FB_TOTAL 
} cui_cbm_query_fb_type;


/* this strcture is used to get the event content in the callback 
 * when it register in group creation 
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    U32 ori_account_id; /* original account id*/
    U32 selected_account_id; /* selected account id */
    srv_cbm_bearer_type_enum bearer_type; /* bearer type for selected account */
    cui_cbm_query_fb_type fb_query_type;
} cui_evt_cbm_bearer_select_struct;

/*************************************************************************
* Structures
*************************************************************************/


/* This structure is used to define cui resource */
typedef struct
{
    U16 str_id; /* application's string id which would be displayed in CUI */
    U16 icon_id; /* application's icon id which would be displayed in CUI */
} cui_cbm_res_struct;
    
/* This structure is used to define necessary parameters */
typedef struct
{
    U32 account_id; /* original account id*/
    cui_cbm_res_struct res; /* screen resource */
    cui_cbm_query_fb_type fb_query_type;
} cui_cbm_parameter_struct;

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
mmi_id cui_cbm_always_ask_create(mmi_id parent_id);
    
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
void cui_cbm_always_ask_set_param(mmi_id cbm_id, cui_cbm_parameter_struct *param);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_always_ask_set_bearer_filter
 * DESCRIPTION
 *  set always ask cui bearer filters. For example, if you only want 
 *  gprs and wifi bearer type displayed in always cui, you can use it.
 * PARAMETERS
 *  cbm_id          : [IN]   cui group id
 *  bearer_type     : [IN]   bearer type (srv_cbm_bearer_type_enum)
 * RETURN VALUES
 *  void
 *****************************************************************************/
void cui_cbm_always_ask_set_bearer_filter(mmi_id cbm_id, U32 bearer_type);
    
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
void cui_cbm_always_ask_run(mmi_id cbm_id);
    
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
void cui_cbm_always_ask_close(mmi_id cbm_id);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_bearer_fallback_create
 * DESCRIPTION
 *  create bearer fallback common UI
 * PARAMETERS
 *  parent_id    : [IN]   application's group id
 * RETURN VALUES
 *  cbm cui group id
 *****************************************************************************/
mmi_id cui_cbm_bearer_fallback_create(mmi_id parent_id);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_bearer_fallback_set_param
 * DESCRIPTION
 *  set bearer fallback parameters
 * PARAMETERS
 *  cbm_id    : [IN]   cui group id
 *  param     : [IN]   cui necessary parameters
 * RETURN VALUES
 *  void
 *****************************************************************************/
void cui_cbm_bearer_fallback_set_param(mmi_id cbm_id, cui_cbm_parameter_struct *param);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_bearer_fallback_set_bearer_filter
 * DESCRIPTION
 *  Set bearer type filters which is allowed in bearer fallback screen
 * PARAMETERS
 *  cbm_id          : [IN]   cui group id
 *  bearer_type     : [IN]   bearer type (srv_cbm_bearer_type_enum)
 * RETURN VALUES
 *  void
 *****************************************************************************/
void cui_cbm_bearer_fallback_set_bearer_filter(mmi_id cbm_id, U32 bearer_type);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_bearer_fallback_run
 * DESCRIPTION
 *  display bearer fallback common ui
 * PARAMETERS
 *  cbm_id          : [IN]   cui group id
 * RETURN VALUES
 *  void
 *****************************************************************************/
void cui_cbm_bearer_fallback_run(mmi_id cbm_id);
    
/*****************************************************************************
 * FUNCTION
 *  cui_cbm_bearer_fallback_close
 * DESCRIPTION
 *  close bearer fallback common ui
 * PARAMETERS
 *  cbm_id          : [IN]   cui group id
 * RETURN VALUES
 *  void
 *****************************************************************************/
void cui_cbm_bearer_fallback_close(mmi_id cbm_id);

#endif /* __COSMOS_MMI_PACKAGE__ */

#endif /* _CBM_CUI_GPROT_H_ */
