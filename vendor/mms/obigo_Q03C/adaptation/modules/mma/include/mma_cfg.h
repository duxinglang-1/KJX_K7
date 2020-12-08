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
 * mma_cfg.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains MMA configration items.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_CFG_C
#define _MMA_CFG_C

#ifndef _MMS_DEF_H
#error "Please include mms_def.h first"
#endif 

/* doing MMS extra SLIM purpose */

#if !(defined(__MMI_UMMS_PST__) || defined(__MMI_UMMS_JSR205__))
#define MMA_JSR_PST_MMS_OPERATON_SUPPORT
#endif

//#define MMA_CFG_MMS_XML_FOLDER  MMA_FOLDER
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#define MMA_CFG_MMS_XML_FOLDER "/"
#else
#define MMA_CFG_MMS_XML_FOLDER "/mms/"
#endif
#define MMA_CFG_MMS_XML_PREFIX  'X'

#define MMA_CFG_SMIL_BG_COLOR (0x00FFFFFF)
#define MMA_CFG_SMIL_FG_COLOR (0x00000000)
#define MMA_CFG_SMIL_SLIDE_DURATION (5)

#define MMA_CFG_SMIL_CONTENT_ID  "MMMM" /* presentation part SHALL be identified by Content-ID */
#define MMA_CFG_SMIL_FILE_NAME   "s.smil"
#define MMA_CFG_SUBJECT_CHARSET MMS_UTF8

#define MMA_CFG_IMAGE_REGION_NAME "Image"       /* !< The image region name definition */
#define MMA_CFG_TEXT_REGION_NAME  "Text"        /* !< The text region name definition */

/*
 * Filter illegal PLMN number for UC 
 * 0: UC handles all PLMN case itself 
 */
#define MMA_CFG_PLMN_STRICT_CHECK 1  /* Previously it was 0 assuming that UC will hadle all PLMN case itself*/
#define MMA_USE_NAME_PARMS 1
//#define __MMS_XML_REMOVE_TEMP_SUPPORT__
/*logging information */
#ifndef MMS_CONTENT_DUMP_DATA
#define MMS_CONTENT_DUMP_DATA
#endif
#endif /* _MMA_CFG_C */ 

