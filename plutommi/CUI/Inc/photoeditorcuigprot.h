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
 *  photoeditorcuigprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PhotoEditor CUI Gprot file
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PHOEDT_CUI_GPROT_H_
#define _PHOEDT_CUI_GPROT_H_

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PHOTOEDITOR__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "photoeditorgprot.h"

/*******************************************************************************
* Macro Define
*******************************************************************************/


/*******************************************************************************
* type Define
*******************************************************************************/

/*
 * event structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    WCHAR *file_path;               /* file path with filename of saved image */
} cui_phoedt_event_struct;

/*
 * collect some param for cui to run
 */
typedef struct
{
    WCHAR *origin_filepath;                 /* file path with filename of the image which you want to edit */
}cui_phoedt_run_struct, *p_cui_phoedt_run_struct;

/*
 * photoeditor cui events
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_PHOEDT_BEGIN = PHOEDT_BASE,
    /* DOM-NOT_FOR_SDK-END */

    /* edit the image and save new image successful,
    caller will receive EVT_ID_CUI_PHOEDT_RESULT_SUCCESS, and then EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME */
    EVT_ID_CUI_PHOEDT_RESULT_SUCCESS,

    /* edit the image or save new image faile, or the action is terminated by user
    caller will receive EVT_ID_CUI_PHOEDT_RESULT_FAILED, and then EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME */
    EVT_ID_CUI_PHOEDT_RESULT_FAILED,

    /* edit action is complete(success or fail),
    call should call cui_phoedt_close() to close CUI */
    EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME,

    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_PHOEDT_END
    /* DOM-NOT_FOR_SDK-END */
} cui_phoedt_event_enum;


/*******************************************************************************
* External APIs
*******************************************************************************/

/*****************************************************************************
* FUNCTION
*  cui_phoedt_create
* DESCRIPTION
*  create photo art cui
* PARAMETERS
*  parent_id    :   [IN] parent group id for photo art cui to add into
* RETURNS
*  phoart cui group id
* EXAMPLE
*  <code>
*  extern void mmi_phoedt_entry_from_other_app(
*                                       S8 *origin_filepath,
*                                       MMI_BOOL is_short,
*                                       MMI_BOOL is_vitual,
*                                       S32 sourcefile_handle,
*                                       phoedt_result_callback result_callback)
*  {
*      cui_phoedt_run_struct para;
*      MMI_ID   cui_gid;
*
*      mmi_frm_group_create(
*          GRP_ID_ROOT,
*          GRP_ID_PHOEDT_TEMP_PARENT_GROUP1,
*          mmi_phoedt_entry_from_other_app_proc,
*          NULL);
*
*      mmi_frm_group_enter(
*          GRP_ID_PHOEDT_TEMP_PARENT_GROUP1,
*          MMI_FRM_NODE_SMART_CLOSE_FLAG);
*
*      cui_gid = cui_phoedt_create(GRP_ID_PHOEDT_TEMP_PARENT_GROUP1);
*
*      cui_phoedt_struct_init(&para);
*
*      para.origin_filepath = origin_filepath;
*
*      cui_phoedt_run(cui_gid, &para);
*  }
*  </code>
*****************************************************************************/
extern MMI_ID cui_phoedt_create(MMI_ID parent_id);


/*****************************************************************************
* FUNCTION
*  cui_phoedt_run
* DESCRIPTION
*  start to run photo art cui
* PARAMETERS
*  cui_gid      :   [IN]
*  p_args       :   [IN] you can call cui_phoedt_struct_init first to init the args and then set your values.
*                    element "result_callback" is for internal use, so pls do not change its value
* RETURNS
*  void
*****************************************************************************/
extern void cui_phoedt_run(MMI_ID cui_gid, p_cui_phoedt_run_struct p_args);


/*****************************************************************************
* FUNCTION
*  cui_phoedt_close
* DESCRIPTION
*  close photo art cui
* PARAMETERS
*  cui_gid      :   [IN]
* RETURNS
*  void
*****************************************************************************/
extern void cui_phoedt_close(MMI_ID cui_gid);


/*****************************************************************************
* FUNCTION
*  cui_phoedt_struct_init
* DESCRIPTION
*  init photo art cui run struct
* PARAMETERS
*  p_args       :   [IN] you can call cui_phoedt_struct_init first to init the args and then set your values.
*                    element "result_callback" is for internal use, so pls do not change its value
* RETURNS
*  void
*****************************************************************************/
extern void cui_phoedt_struct_init(p_cui_phoedt_run_struct p_args);


/*****************************************************************************
* FUNCTION
*  cui_phoedt_is_phoedt_event
* DESCRIPTION
*  to adjust if the evt is come from photo editor cui
* PARAMETERS
*  evt       :  [IN] group event
* RETURNS
*  void
*****************************************************************************/
extern MMI_BOOL cui_phoedt_is_phoedt_event(mmi_event_struct *evt);


/*****************************************************************************
* FUNCTION
*  cui_phoedt_is_supported_format
* DESCRIPTION
*  check if support the image format, now it do not support virtual file
* PARAMETERS
*  filepath         [IN]
* RETURNS
*  support or not
*****************************************************************************/
extern MMI_BOOL cui_phoedt_is_supported_format(const WCHAR *filepath);


#endif /* __MMI_PHOTOEDITOR__ */
#endif /* _PHOEDT_CUI_GPROT_H_ */
