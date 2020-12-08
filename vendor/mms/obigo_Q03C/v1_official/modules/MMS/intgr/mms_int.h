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

/*! \file mms_int.h
 * \brief  Exported adapter function from MMS Service 
 *         Note - in the folder refsrc there is reference (example code) that 
 *                implements the protyped adapter functions in this file.
 *
 * Exported adapter functions, from MMS to e.g. Target Device Application
 * For every adapter function, the following data are listed:
 * - A brief one line description of the function
 * - A longer description of the function
 * - The parameters for the function
 */



/*******************************************************************************
 *
 * Filename:
 * ---------
 * mms_int.h
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
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMSINT_H
#define _MMSINT_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/
        
/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/


/*!
 * \brief Get cellular roaming status
 * 
 * This function is called by the MMS service when a new message notification
 * is received to decide if cellular is in roaming.
 *
 * \return The functions returns true if in roaming otherwise false.
 *
 * Type: Adapter
 *
 *****************************************************************************/
MSF_BOOL MMSa_getRoamingStatus(void); 


/*!
 * \brief Check phone number validity
 * 
 * This function is called by the MMS service to check whether the recipient
 * or sender phone number is valid or not.
 *
 * \return The functions returns true if phone number is valid otherwise false.
 *
 * Type: Adapter
 *
 *****************************************************************************/
MSF_BOOL MMSa_isValidNumber(char *addr);


/*!
 * \brief Check email address validity
 * 
 * This function is called by the MMS service to check whether the recipient
 * or sender email address is valid or not.
 *
 * \return The functions returns true if email address is valid otherwise false.
 *
 * Type: Adapter
 *
 *****************************************************************************/
MSF_BOOL MMSa_isValidEmailAddress(char *addr);


/*!
 * \brief Convert number of seconds (since 1/1 1970, GMT) to date string
 * 
 * This function is called by the MMS service to convert number of seconds 
 * (since 1/1 1970, GMT) to date string.
 *
 * \return 
 *
 * Type: Adapter
 *
 *****************************************************************************/
int MMSa_convertTimeToString(MSF_UINT32 date, char *s);


#endif  /* _MMSINT_H */

