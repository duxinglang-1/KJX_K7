#ifdef Q03C_IND_MOD_ARCH_SUPPORT
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
 * Copyright (C) Obigo AB, 2002-2006.
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
 * msf_tel.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 *   
 *
 */


/*******************************************************************************
 *
 * Filename:
 * ---------
 * msf_tel.h
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

#ifndef _msf_tel_h
#define _msf_tel_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif

/**********************************************************************
 * Telephone
 **********************************************************************/

/*
 * Result types
 */
#define MSF_TEL_OK                            HDI_TEL_OK
#define MSF_TEL_ERROR_UNSPECIFIED             HDI_TEL_ERROR_UNSPECIFIED
#define MSF_TEL_ERROR_CALLED_PARTY_IS_BUSY    HDI_TEL_ERROR_CALLED_PARTY_IS_BUSY
#define MSF_TEL_ERROR_NETWORK_NOT_AVAILABLE   HDI_TEL_ERROR_NETWORK_NOT_AVAILABLE
#define MSF_TEL_ERROR_CALLED_PARTY_NO_ANSWER  HDI_TEL_ERROR_CALLED_PARTY_NO_ANSWER
#define MSF_TEL_ERROR_NO_ACTIVE_CONNECTION    HDI_TEL_ERROR_NO_ACTIVE_CONNECTION
#define MSF_TEL_ERROR_INVALID                 HDI_TEL_ERROR_INVALID

/*
 * Functions
 */
#define MSF_TEL_MAKE_CALL                     HDIa_telMakeCall
#define MSF_TEL_SEND_DTMF                     HDIa_telSendDtmf


/**********************************************************************
 * Phonebook
 **********************************************************************/

/*
 * Result types
 */
#define MSF_PB_OK                             HDI_PB_OK
#define MSF_PB_ERROR_UNSPECIFIED              HDI_PB_ERROR_UNSPECIFIED
#define MSF_PB_ERROR_IN_NAME                  HDI_PB_ERROR_IN_NAME
#define MSF_PB_ERROR_NUMBER_TO_LONG           HDI_PB_ERROR_NUMBER_TO_LONG
#define MSF_PB_ERROR_PHONE_BOOK_ENTRY         HDI_PB_ERROR_PHONE_BOOK_ENTRY
#define MSF_PB_ERROR_PHONE_BOOK_IS_FULL       HDI_PB_ERROR_PHONE_BOOK_IS_FULL
#define MSF_PB_ERROR_INVALID                  HDI_PB_ERROR_INVALID

/*
 * Functions
 */
#define MSF_PB_ADD_ENTRY                      HDIa_pbAddEntry

#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
