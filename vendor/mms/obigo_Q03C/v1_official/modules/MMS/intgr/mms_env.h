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
 * Copyright (C) Obigo AB, 2002-2005.
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

/*! \file mms_env.h
 * \brief  Exported functions to be used by the MSF
 *
 * Exported connector functions, i.e. from Target Device Application to the MMS 
 * client. For every connector function, the following data are listed:
 * - A brief one line description of the function
 * - A longer description of the function
 * - The parameters for the function
 */



/*******************************************************************************
 *
 * Filename:
 * ---------
 * mms_env.h
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

#ifndef _MMSENV_H
#define _MMSENV_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/
        
/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/

/*!
 * \brief This function is called by the system in emergency situations.
 *
 *****************************************************************************/
void MMSc_kill (void);

/*!
 * \brief Performs an execution 'tick' for the MMS client.
 *
 * When this function is called, the MMS client executes one 'tick' (or 
 * actually one state change in the internal state machines). This function 
 * is only called if MMSc_wantsToRun() has returned TRUE.
 *
 * Type: Request Connector
 *
 * Adapter Name: None.
 *
 *****************************************************************************/
void MMSc_run(void);

/*!
 * \brief Prepares the MMS client for running.
 *
 * The MMS client initializes internal memory structures, timers and data. It
 * is also reading configuration data and setting default values
 *
 * Type: Request Connector
 *
 * Adapter Name: None.
 *
 *****************************************************************************/
void MMSc_start(void);

/*!
 * \brief Cleans up all resources and ends the MMS client.
 *
 * All allocated memory and other resources are deallocated. Tasks 
 * currently running will be aborted.
 *
 * Type: Request Connector
 *
 * Adapter Name: None.
 *
 *****************************************************************************/
void MMSc_terminate(void);

/*!
 * \brief  Check if MMS wants to run. 
 *
 * This connector checks if the MMS client has any signals in its signal queue.
 * If so, the MMSc_run() function shall be called.
 *
 * Type: Request Connector
 *
 * Adapter Name: None.
 *
 * \return 1 if MMS Client has work to do, 0 otherwise
 *****************************************************************************/
int MMSc_wantsToRun(void);

/*!
 * \brief Returns the sender module identification 
 *
 * \returns the module identification 
 *
 * ONLY FOR MMS SERVICE INTERNAL USAGE.
 *****************************************************************************/
MSF_UINT8 getSenderModule(void);

#endif  /* _MMSENV_H */

