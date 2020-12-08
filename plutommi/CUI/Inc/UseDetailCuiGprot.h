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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  UseDetailCuiGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Use Detail CUI external interfaces
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef USE_DETAIL_CUI_GPRORT_H
#define USE_DETAIL_CUI_GPRORT_H

#include "MMI_features.h"

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMIDataType.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/
/* Use detail type enum */
typedef enum
{
    CUI_USE_DETAIL_TYPE_PHONENUMBER,
    CUI_USE_DETAIL_TYPE_USSD,
    CUI_USE_DETAIL_TYPE_EMAIL,
    CUI_USE_DETAIL_TYPE_URL,
    CUI_USE_DETAIL_TYPE_END_OF_ENUM
} cui_use_detail_type_enum;


/* Use detail favor operate enum */
typedef enum
{
    CUI_USE_DETIAL_OPERATE_NO_OPERATE,
    CUI_USE_DETAIL_OPERATE_CALL = 0x01,                 /* Used for phonenumber and USSD to call directily */
    CUI_USE_DETAIL_OPERATE_SAVE_NUM_TO_PHB = 0x02,      /* Used for phonenumber and USSD to save to phonebook */
    CUI_USE_DETAIL_OPERATE_SEND_SMS = 0x04,             /* Used for phonenumber to send SMS */
    CUI_USE_DETAIL_OPERATE_SEND_MMS = 0x08,             /* Used for phonenumber to send MMS */
    CUI_USE_DETAIL_OPERATE_SAVE_EMAIL_TO_PHB = 0x10,    /* Used for Email to save to phonebook */
    CUI_USE_DETAIL_OPERATE_SEND_EMAIL = 0x20,           /* Used for Email to send email */
    CUI_USE_DETAIL_OPERATE_TO_WAP = 0x40,               /* Used for URL to go to wap */
    CUI_USE_DETAIL_OPERATE_ADD_TO_BOOKMARK = 0x80,      /* Used for URL to add to bookmark */
    CUI_USE_DETAIL_OPERATE_END_OF_ENUM
}cui_use_detail_operate_enum;


/* Use detail result enum */
typedef enum
{
    CUI_USE_DETAIL_RESULT_OK,       /* User has completed one operate */
    CUI_USE_DETAIL_RESULT_ABORT,    /* User hasn't completed any operate, and go back */
    CUI_USE_DETAIL_RESULT_ERROR,    /* The action cannot be done, Error */
    CUI_USE_DETAIL_RESULT_TOTAL     /* end of the enum */
}cui_use_detail_result_enum;


/* <GROUP use detail Event>
 *  Here are events that "Use detail CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_USE_DETAIL_BEGIN,
    /* DOM-NOT_FOR_SDK-END */
    EVT_ID_CUI_USE_DETAIL_RESULT, /* cui_use_detail_result_event_struct */
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_USE_DETAIL_TOTAL
    /* DOM-NOT_FOR_SDK-END */
}cui_use_detail_event_enum;

/* <GROUP Use Detail Event>
 * event structure of EVT_ID_CUI_USE_DETAIL_RESULT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    cui_use_detail_result_enum result; /* cui_sim_sel_result_enum */
    cui_use_detail_operate_enum operate;
    void* parent_data;
}cui_use_detail_result_event_struct;

typedef struct
{
    U16* detail_txt;
    U16 txtlen;
    cui_use_detail_type_enum type;
}cui_use_detail_basic_obj_struct;


typedef struct
{
    cui_use_detail_operate_enum operate;
    cui_use_detail_type_enum type;
    MMI_BOOL edit_flag;
}cui_use_detail_mode_struct;


/****************************************************************************
 * Define
 ****************************************************************************/
#define CUI_USE_DETAIL_OPERATE_TOTAL (cui_use_detail_operate_enum) \\
(CUI_USE_DETAIL_OPERATE_CALL | CUI_USE_DETAIL_OPERATE_SAVE_NUM_TO_PHB | CUI_USE_DETAIL_OPERATE_SEND_SMS | \\
CUI_USE_DETAIL_OPERATE_SEND_MMS | CUI_USE_DETAIL_OPERATE_SAVE_EMAIL_TO_PHB | CUI_USE_DETAIL_OPERATE_SEND_EMAIL | \\
CUI_USE_DETAIL_OPERATE_TO_WAP | CUI_USE_DETAIL_OPERATE_ADD_TO_BOOKMARK)

#define CUI_USE_DETAIL_OPERATE_PHONENUMBER_TOTAL (cui_use_detail_operate_enum)(CUI_USE_DETAIL_OPERATE_CALL | CUI_USE_DETAIL_OPERATE_SAVE_NUM_TO_PHB | CUI_USE_DETAIL_OPERATE_SEND_SMS | CUI_USE_DETAIL_OPERATE_SEND_MMS)

#define CUI_USE_DETAIL_OPERATE_USSD_TOTAL (cui_use_detail_operate_enum)(CUI_USE_DETAIL_OPERATE_CALL | CUI_USE_DETAIL_OPERATE_SAVE_NUM_TO_PHB)

#define CUI_USE_DETAIL_OPERATE_EMAIL_TOTAL (cui_use_detail_operate_enum)(CUI_USE_DETAIL_OPERATE_SAVE_EMAIL_TO_PHB | CUI_USE_DETAIL_OPERATE_SEND_EMAIL)

#define CUI_USE_DETAIL_OPERATE_URL_TOTAL (cui_use_detail_operate_enum)(CUI_USE_DETAIL_OPERATE_TO_WAP | CUI_USE_DETAIL_OPERATE_ADD_TO_BOOKMARK)

#define CUI_USE_DETAIL_MAX_BUFFER_SIZE     2048
#define CUI_USE_DETAIL_MAX_OBJ_NUM         40
#define CUI_USE_DETAIL_OPERATE_NUM         8


#define CUI_USE_DETAIL_MAX_PHONE_NUM_LEN APPLIB_MAX_PHONE_NUM_LEN
#define CUI_USE_DETAIL_MAX_USSD_LEN APPLIB_MAX_USSD_LEN
#define CUI_USE_DETAIL_MAX_EMAIL_LEN MMI_EMAIL_MAX_ADDR_LEN
#define CUI_USE_DETAIL_MAX_URL_LEN 255
#define CUI_USE_DETAIL_MAX_LEN CUI_USE_DETAIL_MAX_URL_LEN
/****************************************************************************
 * Global function
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_create
 * DESCRIPTION
 *  Create an instance of "Use Detail CUI".
 *  In text, may exist some useful contents, EX: phonenumber, USSD, Email, URL.
 *  For each type of the contents, have some common actions.
 *  This CUI can use the contents which the user provided to do the common actions.
 *  EX: use phonenumber to make call, to send SMS etc.
 * PARAMETERS
 *  caller           : [IN]    Parent group ID
 *  obj_list         : [IN]    the detail contents list which the user want to use
 *  obj_count        : [IN]    number of the detail contents in the list
 *  parent_data      : [IN]    Parent data
 * RETURNS
 *  Return new CUI id if create sucessfully; otherwise, GRP_ID_INVALID
 *****************************************************************************/
extern mmi_id cui_use_detail_create(mmi_id caller, cui_use_detail_basic_obj_struct *obj_list, U8 obj_count, void* parent_data);


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_set_mode
 * DESCRIPTION
 *  Set mode for every use detial type. If not invoke this API, every type have default mode.
 *  Default mode: edit_flag for USSD is MMI_TRUE, others is MMI_FALSE;
 *                CUI_USE_DETAIL_OPERATE_XXX_TOTAL is XXX_OPERATE's default operate
 *                Not support edit function for email and URL, so if user set MMI_TRUE, the value
 *                will be modified to MMI_FALSE.
 * PARAMETERS
 *  cui_id             : [IN]    ID of CUI
 *  mode_list          : [IN]    mode for use detail type
 *  list_count         : [IN]    number of mode list
 * RETURNS
 *  Return MMI_TRUE if set mode sucessfully; otherwise, return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL cui_use_detail_set_mode(mmi_id cui_id, cui_use_detail_mode_struct *mode_list, U8 list_count);


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_set_view_flag
 * DESCRIPTION
 *  Set view flag for use detail cui. If not invoke this API, view flag have default value.
 *  Default value: If obj_count > 1, view_flag is MMI_TRUE, obj_count == 1, view_falg is MMI_FALSE.
 * PARAMETERS
 *  cui_id             : [IN]    ID of CUI
 *  view_flag          : [IN]    support diaplay all contents in a list or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_use_detail_set_view_flag(mmi_id cui_id, MMI_BOOL view_flag);


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_run
 * DESCRIPTION
 *  Run "Use Detail CUI"
 * PARAMETERS
 *  cui_id             : [IN]    ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_use_detail_run(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  cui_use_detail_close
 * DESCRIPTION
 *  Close "Use Detail CUI"
 * PARAMETERS
 *  cui_id             : [IN]    ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_use_detail_close(mmi_id cui_id);


#endif /* USE_DETAIL_CUI_GPRORT_H */
