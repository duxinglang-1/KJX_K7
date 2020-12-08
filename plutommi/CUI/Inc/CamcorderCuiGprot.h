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
 *   VdoRecCui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Camera Common UI header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef CUI_CAMCODERCUI_GPROT_H
#define CUI_CAMCODERCUI_GPROT_H

/*******************************************************************************
* Include Header File
*******************************************************************************/

/*******************************************************************************
* Structure Define
*******************************************************************************/
/* common UI struct */
#if defined(__MMI_CAMCORDER__)
typedef struct
{
    U8 mode;  
} cui_camco_run_struct, *p_cui_camco_run_struct;

typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER

} cui_camco_event_struct;

/*******************************************************************************
* Enum Define
*******************************************************************************/
/* camera event enum */
typedef enum
{
    CUI_CAMCO_EVENT_RESULT_SUCCESS = CAMCORDER_BASE,
    CUI_CAMCO_EVENT_RESULT_FAILED,

    CUI_CAMCO_EVENT_ALL
} cui_camco_event_enum;




/*******************************************************************************
* Macro Define
*******************************************************************************/


/*******************************************************************************
* Export API 
*******************************************************************************/
/*****************************************************************************              
 * FUNCTION
 *   cui_camco_struct_init
 * DESCRIPTION
 *   init camco struct
 * PARAMETERS
 *  p_args      : [OUT] camco cui struct
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_camco_struct_init(p_cui_camco_run_struct p_args);

/*****************************************************************************              
 * FUNCTION
 *   cui_camco_create
 * DESCRIPTION
 *   camco cui group create
 * PARAMETERS
 *  parent_gid  : [IN] parent group ID
 * RETURNS
 *  camco cui group ID
 * RETURN VALUES
 *  camco cui group ID
*****************************************************************************/
extern mmi_id cui_camco_create(mmi_id parent_gid);

/*****************************************************************************              
 * FUNCTION
 *   cui_camco_run
 * DESCRIPTION
 *   camco cui run
 * PARAMETERS
 *  cui_gid    : [IN] camco cui group ID
 *  p_args     : [IN] camco structure to receive parameter
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_camco_run(mmi_id cui_gid, p_cui_camco_run_struct p_args);

/*****************************************************************************              
 * FUNCTION
 *   cui_camco_close
 * DESCRIPTION
 *   close camco cui
 * PARAMETERS
 *  cui_gid     : [IN] camco cui group id
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_camco_close(mmi_id cui_gid);

/*****************************************************************************              
 * FUNCTION
 *   cui_camco_check_and_display_popup
 * DESCRIPTION
 *   check if the camco cui is avaiable. If no, show popup and back to previous screen
 * PARAMETERS
 *  None
 * RETURNS
 *  the status of camco cui is avaiable or not
 * RETURN VALUES
 *  the status of camco cui is avaiable or not
*****************************************************************************/
extern MMI_BOOL cui_camco_check_and_display_popup(void);

#endif
#endif /* CUI_CAMERACCUI_GPROT_H */ 

