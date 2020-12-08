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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*******************************************************************************
 *
 * Filename:
 * ---------
 * phs_dlg.h
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _phs_dlg_h
#define _phs_dlg_h


#ifndef  _msf_def_h
#include "msf_def.h"
#endif


/**********************************************************************
 * Constants
 **********************************************************************/


/**********************************************************************
 * Parameters for different dialog types
 **********************************************************************/

/*
 * The call to phs_dlgCreate must have exactly this many elements
 * in the 'strings' array, for each of the Dialog types below:
 *
 * PHS_DLG_SIA_CONFIRM: 3 string parameters
 *   0: the message to display to the user
 *   1: string to display on the Ok button (or empty string/NULL for default)
 *   2: string to display on the Cancel button (or empty string/NULL for default)
 *
 */

/**********************************************************************
 * Type definitions
 **********************************************************************/

/* 
	Types of dialogues 
*/

typedef enum{
  PHS_DLG_RESPONSE_NONE,
  PHS_DLG_RESPONSE_POSITIVE,
  PHS_DLG_RESPONSE_NEGATIVE,               
  PHS_DLG_RESPONSE_CANCEL                 
}phs_dlg_sia_response;

typedef enum{
  PHS_DLG_RESPONSE_UAF_NONE,
  PHS_DLG_RESPONSE_UAF_ACCEPT,
  PHS_DLG_RESPONSE_UAF_DECLINE,               
  PHS_DLG_RESPONSE_UAF_ACCEPT_AND_ADD,
  PHS_DLG_RESPONSE_UAF_DECLINE_AND_ADD
}phs_dlg_uaf_response;


typedef enum {
  PHS_DLG_SIA_CONFIRM,
  PHS_DLG_WHITELIST_NO_MATCH
} phs_dlg_type_t;

typedef struct phs_dlg_st {
  struct phs_dlg_st  *next;
  void               *dlg_handle;
  phs_dlg_type_t     type;
  int                response;
  int                msg_id;
} phs_dlg_t;



typedef struct phs_queued_push_msg_st {
  int                     msg_id;
  int                     mod_id;
  char                    *info;
  phs_dlg_type_t          dlg_type;
  struct phs_queued_push_msg_st *next_msg;
} phs_queued_push_msg_t;

typedef struct phs_queued_response_st {
  int                     msg_id;
  int                     mod_id;
  int                     response;
  phs_dlg_type_t          dlg_type;
  struct phs_queued_response_st *next;
} phs_queued_response_t;

/**********************************************************************
 * Exported functions
 **********************************************************************/
void phs_dlg_init (void);

void phs_dlg_terminate (void);

void phs_dlg_display_dialog (int mod_id, int msg_id, char* info, phs_dlg_type_t dlg_type);

void phs_dlg_ready_to_launch (void);

void phs_register_dialog (int phs_module, phs_dlg_t *dlg);

int phs_deregister_dialog (phs_dlg_t *dlg);

void *phs_disp_start_sia_dialog (int msg_id, char* info);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
void phs_dlg_response (void* dlg_handle, int res_type);

void phs_dlg_close_dialog (int msg_id);

void phs_dlg_postResponse(int msg_id, int response);
/*
 * Create a dialog.
 * Returns a pointer to a struct phs_dlg_st, or NULL on error.
 */
phs_dlg_t * phs_dlgCreate (phs_dlg_type_t dialogType, int numStrings, 
                               MSF_UINT32 strings[], char* info, int msg_id);

/*
 * Delete a dialog. Should be called when the user
 * has responded and all information has been extracted.
 * If moreDialogs = TRUE, teh screen should be removed and released
 */
void
phs_dlgDelete (phs_dlg_t *dlg, int moreDialogs);



/*
 * Return the type of dialog that we have (one of the Dialog types
 * above).
 * Returns 0 on error.
 */
int
phs_dlgGetType (int msg_id);



/*
 * Return the input string from one of the input fields of
 * this dialog. The index of the requested input field is given
 * as 'idx', with indices starting at 0.
 * Returns NULL on error.
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string.
 */
char *
phs_dlgGetInput (phs_dlg_t *dlg, int idx);

/*
 * Return the response that this dialog has received
 * (one of the Response types above).
 * Returns 0 if no response has been registered 
 */
int
phs_dlgGetResponse (int msg_id);

#endif


