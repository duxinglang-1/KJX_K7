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

/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * brs_dlg.h
 *
 * Created by Anders Edenbrant, Mon Sep 30 09:03:55 2002.
 *
 * Revision  history:
 *   020903, AED: Updated
 *
 */
 
/*******************************************************************************
 *
 * Filename:
 * ---------
 * brs_dlg.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/  
 
#ifndef _brs_dlg_h
#define _brs_dlg_h

#ifndef  _msf_def_h
#include "msf_def.h"
#endif


/**********************************************************************
 * Constants
 **********************************************************************/

/* Types of dialogues */
#define BRS_DLG_WMLS_ALERT                        1
#define BRS_DLG_WMLS_CONFIRM                      2
#define BRS_DLG_WMLS_PROMPT                       3
#define BRS_DLG_DISPLAY_SCRIPT_ALERT              4
#define BRS_DLG_DISPLAY_I_MODE_UTN_CONFIRM        5
#define BRS_DLG_DISPLAY_OBJECT_LOAD_CONFIRM       6
#define BRS_DLG_LE_INPUT_FORMAT_ERROR_CONFIRM     7
#define BRS_DLG_LE_INPUT_FORMAT_ERROR_ALERT       8
#define BRS_DLG_UA_RESEND_POST                    9
#define BRS_DLG_UA_REDIRECT_POST                  10

/* Response types */
#define BRS_DLG_RESPONSE_POSITIVE                 1
#define BRS_DLG_RESPONSE_NEGATIVE                 2
#define BRS_DLG_RESPONSE_CANCEL                   3


/**********************************************************************
 * Parameters for different dialog types
 **********************************************************************/

/*
 * The call to brs_dlgCreate must have exactly this many elements
 * in the 'strings' array, for each of the Dialog types below:
 *
 * BRS_DLG_WMLS_ALERT: 
 * BRS_DLG_DISPLAY_SCRIPT_ALERT: 1 string parameter
 *   0: the message to display to the user
 *
 * BRS_DLG_WMLS_CONFIRM: 
 * BRS_DLG_DISPLAY_I_MODE_UTN_CONFIRM: 3 string parameters
 *   0: the message to display to the user
 *   1: string to display on the OK button (or empty string/NULL for default)
 *   2: string to display on the Cancel button (or empty string/NULL for default)
 *
 * BRS_DLG_WMLS_PROMPT: 2 string parameters
 *   0: the message to display to the user
 *   1: default input in the input field (or empty string/NULL)
 *
 * BRS_DLG_DISPLAY_OBJECT_LOAD_CONFIRM: 2 string parameters
 *   0: the mime type of the object
 *   1: the URL to be used if loading the object
 *
 * BRS_DLG_LE_INPUT_FORMAT_ERROR_CONFIRM: 1 string parameter
 *   0: the message to display to the user.
 *
 * BRS_DLG_LE_INPUT_FORMAT_ERROR_ALERT: 1 string parameter
 *   0: the message to display to the user.
 */

/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef struct brs_dlg_st brs_dlg_t;


/**********************************************************************
 * Exported functions
 **********************************************************************/

/*
 * Create a dialog.
 * Returns a pointer to a struct brs_dlg_st, or NULL on error.
 */
brs_dlg_t *
brs_dlgCreate (MSF_UINT32 screenHandle, int dialogType,
               int numStrings, const char *strings[]);

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 */
void
brs_dlgDelete (brs_dlg_t *dlg);

/*
 * Inform the dialog of the Action notification that was received.
 * 'action' is the MsfActionHandle.
 */
void
brs_dlgAction (brs_dlg_t *dlg, MSF_UINT32 action);

/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
brs_dlgGetType (brs_dlg_t *dlg);

/*
 * Return the Dialog Handle associated with the specified dialog.
 * Returns 0 on error. 
 */
MSF_UINT32
brs_dlgGetDialogHandle (brs_dlg_t *dlg);

/*
 * Return the input string from one of the input fields of
 * this dialog. The index of the requested input field is given
 * as 'idx', with indices starting at 0.
 * Returns NULL on error.
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string.
 */
char *
brs_dlgGetInput (brs_dlg_t *dlg, int idx);

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered (by calling brs_dlgAction).
 */
int
brs_dlgGetResponse (brs_dlg_t *dlg);

#endif
