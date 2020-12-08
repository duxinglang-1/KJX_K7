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
 * phs_cfg.h
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

#ifndef _phs_cfg_h
#define _phs_cfg_h

#include "MMI_features.h"

/* PHS_CONFIG_WAP_PUSH_MESSAGES Requires the UIS module
 * If not supported PHS will ignore the following message types
 * - SIA
 * - SL
 * - SI
 * - CO
 */
#ifdef BROWSER_SUPPORT
#define PHS_CONFIG_WAP_PUSH_MESSAGES  
#endif /* BROWSER_SUPPORT */
#define PHS_CONFIG_WSP_PUSH
#ifdef WAP_SEC_SUPPORT
//#define PHS_CONFIG_HTTP_PUSH
#endif

#ifndef SLIM_WAP_MMS
#define PHS_CONFIG_MULTIPART
#endif /*SLIM_WAP_MMS*/

/**************************************************
 * Parser configuration settings
 **************************************************/

#define PHS_CFG_MAX_CONCURRENT_PARSINGS 10

/* The initial buffer size used for the parser. */
#define PHS_PRSR_BUF_SIZE 500

/* The default character set used when parsing a text document
 * with no encoding information. Must be ASCII based.
 * PHS_CFG_DEFAULT_CHARSET can only take the value MSF_CHARSET_UTF_8
 * or MSF_CHARSET_LATIN_1. */
#define PHS_CFG_DEFAULT_CHARSET   MSF_CHARSET_UTF_8

/**************************************************
 * Connections configuration settings
 **************************************************/

/* Max number of open connections per active Object */
#define PHS_CFG_MAX_CONNECTIONS_PER_USER          5

#define PHS_CFG_MAX_CONNECTIONS                   20

#define PHS_CFG_UDP_DEFAULT_PUSH_PORT             2948
#define PHS_CFG_WTLS_DEFAULT_PUSH_PORT            2949
#define PHS_CFG_HTTP_DEFAULT_PUSH_PORT            4035

/**************************************************
 * Other settings
 **************************************************/
/* 
 * PHS_CFG_SIR_LOCKOUT_TIMER is used for handling a lockout timer for SIR. 
 * The lockut timer is used to protect against denial of service 
 * attacks. The timer is turned om when a SIR arrives and can be handled
 * sucessfully. All other SIR that arrives when the timer is set will 
 * be discarded. The timer is turned of and SIR can be handled again
 * after one of the following cases:
 * - When the connection has been established 
 * - If the user answers the dialog followed after an SIR with cancel 
 *   (then the connection will never be established)
 * - If the timer expires.
 *
 * PHS_CFG_SIR_LOCKOUT_TIMER defines how long the 
 * lockout timer should be on. The value should be given
 * in 1/10ths of a second
 *
 * If this behavior is not requried set the value to 0,
 * and no lockout tmer will be used
 */
#define PHS_CFG_SIR_LOCKOUT_TIMER                 100

/* DELETE OLDEST Always ON */
#define __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__

#ifdef __GEMINI__
#define __WAP_DUAL_SIM__
#endif

/* White list Support */
#ifdef __MMI_WAP_PUSH_WHITE_LIST__

#define PHS_CFG_PUSH_WHITELIST_SUPPORT


#endif /*__MMI_WAP_PUSH_WHITE_LIST__*/

#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__)
#define PHS_CFG_PUSH_SIA_SUPPORT
#define PHS_CFG_PUSH_SLIM_SUPPORT

#endif /*__MMI_WAP_PUSH_SIA_SLIM__*/


/* BLACK list Support */
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
#define PHS_CFG_PUSH_BLACKLIST_SUPPORT
#endif

#ifdef OBIGO_Q05A
#define __OBIGO_FRMW2__
#endif

#endif /* _phs_cfg_h */


