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
 * BrowserSrvBookmarkConfig.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVBOOKMARKCONFIG_H
#define MMI_BROWSERSRVBOOKMARKCONFIG_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__

#define SRV_BRW_BKM_MAX_FILE_NAME_LEN               40 //SRV_FMGR_PATH_MAX_FILE_NAME_LEN - 1   /* subtracting 1 to sync it with file manager */
#define SRV_BRW_MAX_URL_LEN                                       255 /* check the loop case of headers inclusion*/
#define SRV_BRW_BKM_LINE_BREAK_SIZE                       2

/*
For Bookmark entry the following items need to be stored and their size in the file is
Bookmark type                                       2
Timestamp                                             10
Title                                                         SRV_BRW_BKM_MAX_FILE_NAME_LEN
URL                                                        SRV_BRW_MAX_URL_LEN
Parent                                                     3
Line break after all the above items     SRV_BRW_BKM_LINE_BREAK_SIZE
*/
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
#define SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE              (2 + 10  + SRV_BRW_BKM_MAX_FILE_NAME_LEN  + SRV_BRW_MAX_URL_LEN  + 3 + (5 * SRV_BRW_BKM_LINE_BREAK_SIZE))
#else
#define SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE              (2 + 10  + SRV_BRW_BKM_MAX_FILE_NAME_LEN  + SRV_BRW_MAX_URL_LEN  + (4 * SRV_BRW_BKM_LINE_BREAK_SIZE))
#endif

#endif /* __MMI_BROWSER_2__ */
#endif /* MMI_BROWSERSRVBOOKMARKCONFIG_H */
