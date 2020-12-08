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
 *  ProvBoxSrvConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements all configrable defines internally
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_PROVBOX_SRV_CONFIG_H
#define SRV_PROVBOX_SRV_CONFIG_H


/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/
/*
 * Any applications who use service provided by ProvBox can only include ProvBoxSrvGprot.h.
 * Mapping between UM and ProvBox
 * ProvBox: Get Sort Info <----> UM: Get List Info
 * ProvBox: Get List Info <----> UM: Get Msg Info
 * ProvBox: Get Msg Info  <----> UM: None
 */

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "Custom_ProvBox.h"
#include "MMI_features.h"

#include "MMI_inet_app_trc.h"
#include "MMIDataType.h"
#include "UmSrvDefs.h"
#include "UMSrvGProt.h"

/*----------------------------------------------------------------------------*/
/* Internal compile Options                                                   */
/*----------------------------------------------------------------------------*/

/* Internal Unit Test */
#if defined(__MTK_INTERNAL__) && !defined(__MTK_TARGET__)
/* under construction !*/
#endif 

#ifdef __MMI_PROVBOX_LOG__
#define  __MMI_PROVBOX_LOG_MEM__
#endif 

/*----------------------------------------------------------------------------*/
/* Internal compile Option dependencies                                       */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* TRACE group                                                                */
/*----------------------------------------------------------------------------*/

#define SRV_PROVBOX_TRC_INFO                    MMI_INET_TRC_G9_PROVINBOX
#define SRV_PROVBOX_TRC_WARNING                 MMI_INET_TRC_G9_PROVINBOX
#define SRV_PROVBOX_TRC_ERROR                   MMI_INET_TRC_G9_PROVINBOX

/*----------------------------------------------------------------------------*/
/* Version                                                                    */
/*----------------------------------------------------------------------------*/

/*
 * Version 
 * 
 *  task + application name + version number + feature bit mask,  
 *  for example: "MMI.ProvBox.V0.01.F0101"   -- four features support
 * 
 * 
 *  Objective
 * 
 *  The version is used for compatibility. ProvBox can detect different
 *  files with different format used internally and apply a proper action
 *  to read these files without formatting the whole target using version.
 *  ProvBox shall delete all files and reset the application if it finds 
 *  an unmatched version.
 * 
 * 
 *  Usage
 * 
 *  1.please increase the base version number if a new feature is added and
 *  can change the format of some files.
 *  2.please add a feature bit mask character postfix to the version if it
 *  can change the format of some files to turn on or turn off this feature.
 *  3.please never do change the feature bit mask postfix once exist except
 *  to increase the base version number. 
 *
 *  Version info
 *  1. V0.01:  Original version
 *  2. V0.02:  Split version
 *
 */

#define SRV_PROVBOX_BASE_VERSION                "SRV.ProvBox.V0.02"
#define SRV_PROVBOX_FEATURE_VERSION_CHAR        ".F"

/* please add new feature info if add new feature */

//#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
//#define SRV_PROVBOX_ARCHIVE_VERSION             "1"
//#else
#define SRV_PROVBOX_ARCHIVE_VERSION             "0"
//#endif

/*
 * for example :new feature
 * #ifdef __MMI_PROVBOX_XXX_SUPPORT___
 * #define MMI_PROVBOX_XXX_VERSION                 "1"
 * #else
 * #define MMI_PROVBOX_XXX_VERSION                 "0"
 * #endif
 */

/* please add a new feature version to this constant */
#define SRV_PROVBOX_VERSION                     SRV_PROVBOX_BASE_VERSION         \
                                                SRV_PROVBOX_FEATURE_VERSION_CHAR \
                                                SRV_PROVBOX_ARCHIVE_VERSION

/*----------------------------------------------------------------------------*/
/* file path                                                                  */
/*----------------------------------------------------------------------------*/

/* The char size of the follow folders or files should not be larger than SRV_PROVBOX_PATH_MAX_CHAR_LEN,
   if any of them are changed please do remember to check the char size limitation. */

#define SRV_PROVBOX_DIR_APP                     "Z:\\@ProvBox\\"        /* if change it, please remember to change the same name in fs_quota.c */

#define SRV_PROVBOX_DIR_INBOX                   SRV_PROVBOX_DIR_APP##"Inbox\\"

/*  Should not wrap this with archive compile option 
  * as it's still used in non-archiver supported sceanrio to apply the folder clear action
  * in srv_provbox_check_folder()
  */
//#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
#define SRV_PROVBOX_DIR_ARCHIVE                 SRV_PROVBOX_DIR_APP##"Archive\\"
//#endif

#define SRV_PROVBOX_DIR_EXTRA                   SRV_PROVBOX_DIR_APP##"Extra\\"  /* The folder to save extra message even the inbox is full */

#define SRV_PROVBOX_DIR_TEMP                    SRV_PROVBOX_DIR_APP##"Temp\\"

#define SRV_PROVBOX_FILE_APPFILE                SRV_PROVBOX_DIR_APP##"ProvBoxApp.dat"

#define SRV_PROVBOX_FILE_MSG_CHECK              SRV_PROVBOX_DIR_TEMP##"Check.dat"

#define SRV_PROVBOX_FILE_MSG_INFO_DATA          "MsgInfo.dat"

#define SRV_PROVBOX_FILE_MSG_APP_DATA           "MsgAppData.dat"

#define SRV_PROVBOX_FILE_MSG_PROV_DATA_POSTFIX  ".prov"

/* Inbox message info data file */
#define SRV_PROVBOX_FILE_IMSG_INFO_DATA         SRV_PROVBOX_DIR_INBOX \
                                                SRV_PROVBOX_FILE_MSG_INFO_DATA

/* Inbox message app data file */
#define SRV_PROVBOX_FILE_IMSG_APP_DATA          SRV_PROVBOX_DIR_INBOX \
                                                SRV_PROVBOX_FILE_MSG_APP_DATA

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
/* Archive box message info data file */
#define SRV_PROVBOX_FILE_AMSG_INFO_DATA         SRV_PROVBOX_DIR_ARCHIVE \
                                                SRV_PROVBOX_FILE_MSG_INFO_DATA

#define SRV_PROVBOX_FILE_AMSG_APP_DATA          SRV_PROVBOX_DIR_ARCHIVE \
                                                SRV_PROVBOX_FILE_MSG_APP_DATA
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

/* Extra box message info data file */
#define SRV_PROVBOX_FILE_EMSG_INFO_DATA         SRV_PROVBOX_DIR_EXTRA \
                                                SRV_PROVBOX_FILE_MSG_INFO_DATA

#define SRV_PROVBOX_FILE_EMSG_APP_DATA          SRV_PROVBOX_DIR_EXTRA \
                                                SRV_PROVBOX_FILE_MSG_APP_DATA

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------Max message number------------------------------------*/

/* It means the message num supported is unlimited unless no enough resource. */
#define SRV_PROVBOX_UNLIMITED_NUM               CUSTOM_PROVBOX_UNLIMITED_NUM

/* Common messages such as WAP & DM message saved extra if inbox is full, design to support several ones. */
#define SRV_PROVBOX_MAX_CMN_EXT_MSG_NUM         CUSTOM_PROVBOX_MAX_CMN_EXT_MSG_NUM

/* MMI_SPAMax SIM message read from SIM card, 1 currently, please refer to 
   SIM Provisioning Agent(SPA) application */
#define SRV_PROVBOX_MAX_SIM_MSG_NUM             CUSTOM_PROVBOX_MAX_SIM_MSG_NUM

#define SRV_PROVBOX_MAX_EXT_MSG_NUM             CUSTOM_PROVBOX_MAX_EXT_MSG_NUM

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
#define SRV_PROVBOX_MAX_ARCHIVE_MSG_NUM         CUSTOM_PROVBOX_MAX_ARCHIVE_MSG_NUM    
#endif

#define SRV_PROVBOX_MAX_MSG_NUM                 CUSTOM_PROVBOX_MAX_MSG_NUM

#define SRV_PROVBOX_TOTAL_MSG_NUM               CUSTOM_PROVBOX_TOTAL_MSG_NUM

#define SRV_PROVBOX_MAX_UNDELETABLE_MSG_NUM     (1)     /* only one currently. The max undeletable message when deleting */


/*----------------------Message data size-------------------------------------*/

#define SRV_PROVBOX_MAX_APP_DATA_SIZE           (512)   /* Max app data size support, enougth now, use for length check. */
#define SRV_PROVBOX_MAX_PROV_DATA_SIZE          (3 * 1024)      /* Max provisioning message raw data size support, enougth now. use for length check. */

/*----------------------Message node------------------------------------------*/

/* 
 * The node type of the message node loaded to memory when initializing, can only be 0, 1 or 2;
 * more larger more memory needed; more smaller more time to read info from files.
 * the value decide how to use time to replace the memory.
 *
 * 0: Load message base info to memory; 
 * 1: load message standand info to memory;
 * 2: load mesage full info to memory; 
 */
 
#define SRV_PROVBOX_MSG_NODE_INIT_LOAD_TYPE          (0) 

/*----------------------ADM memory pool size----------------------------------*/
/*
 * It's the proper memory size needed to run this application, 
 * it is a little urgent, and is not preferred to decrease it, however, welcome to increase it if want to support more messages.  
 */
#if (SRV_PROVBOX_MAX_MSG_NUM >= 100)
#define SRV_PROVBOX_MEM_POOL_BASE_SIZE          (10 * 1024)
#else
#define SRV_PROVBOX_MEM_POOL_BASE_SIZE          (5 * 1024)
#endif
/*
 * Average number, the common memory size needed for one message, use to save memory.
 * 28: if load (SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO) to memory; 
 * 100: if load (SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO) to memory;
 * 160: if load (SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO) to memory;
 */

#if (SRV_PROVBOX_MSG_NODE_INIT_LOAD_TYPE == 0)
#define SRV_PROVBOX_MSG_CMN_MEM_SIZE            (50)    /* info: 4; app: 4; msg_node: 4;  */
#elif (SRV_PROVBOX_MSG_NODE_INIT_LOAD_TYPE == 1)
#define SRV_PROVBOX_MSG_CMN_MEM_SIZE            (80)    /* info: 4; app: 4; msg_node: 4 + 3 + 4; */
#else 
#define SRV_PROVBOX_MSG_CMN_MEM_SIZE            (160)   /* info: 4; app: 4; msg_node: 4 + 3 + 4 + 11 + 6; */
#endif 

#if (SRV_PROVBOX_TOTAL_MSG_NUM == SRV_PROVBOX_UNLIMITED_NUM)

/* please try to alloc a proper memory and a proper quota value in fs_quota.c for your reqirement. */
#define SRV_PROVBOX_MEM_POOL_DYNC_SIZE          (SRV_PROVBOX_MSG_CMN_MEM_SIZE * 1024)  /* for example support 1000 message. */

#else /* (SRV_PROVBOX_TOTAL_MSG_NUM == SRV_PROVBOX_UNLIMITED_NUM) */ 
/* It's the minimum memory size to store information of every message in memory commonly. */
#define SRV_PROVBOX_MEM_POOL_DYNC_SIZE          (SRV_PROVBOX_MSG_CMN_MEM_SIZE * SRV_PROVBOX_TOTAL_MSG_NUM)

#endif /* (SRV_PROVBOX_TOTAL_MSG_NUM == SRV_PROVBOX_UNLIMITED_NUM) */ 

/* Dependency : No change, the minimum memory size needed for this application. */
#define SRV_PROVBOX_MIM_MEM_POOL_SIZE           (SRV_PROVBOX_MEM_POOL_BASE_SIZE + SRV_PROVBOX_MEM_POOL_DYNC_SIZE)

/* Extra memory size allocate, to improve the application */
#define SRV_PROVBOX_EXT_MEM_POOL_SIZE           (0)

#define SRV_PROVBOX_MEM_POOL_SIZE               (SRV_PROVBOX_MIM_MEM_POOL_SIZE + SRV_PROVBOX_EXT_MEM_POOL_SIZE)

#define SRV_PROVBOX_MEM_LOW_THRESHOLD           (SRV_PROVBOX_MEM_POOL_SIZE / 5)

/*----------------------Common field size-------------------------------------*/

/* Max file record value size saved in message info file and message app data file,
   it's may use to alloc memory, so not so larger is preferred */
#define SRV_PROVBOX_FILE_MAX_RECORD_VALUE_SIZE  (500)

/*
 * File size, no large than 2k is preferred 
 * initialize file size of record file, include message info file and app data file
 * One message need sizeof(mmi_provbox_msg_store_info_sturct) of file size to save its info data, 
 * and need MMI_PROVBOX_FILE_COMMON_APP_DATA_SIZE to save its app data.0
 */
#define SRV_PROVBOX_FILE_INIT_MSG_NODE_NUM      (10)
#define SRV_PROVBOX_FILE_DEFRAG_MSG_NODE_NUM    (15)
#define SRV_PROVBOX_FILE_INC_MSG_NODE_NUM       (10)
#define SRV_PROVBOX_FILE_COMMON_APP_DATA_SIZE   (120)

/* Multiple read file operation in one asynchronous event handler, 
   please decrease it if the target is too slow to read file for long time which can block other task 
   and make MMI task queue full, or increase it if not. */
#define SRV_PROVBOX_FILE_MAX_OP_RECORD_HEAD_NUM (10)    /* 100 ~ 200 is preferred, more larger if more power CPU. */
#define SRV_PROVBOX_FILE_MAX_OP_RECORD_NUM      (10)

#define SRV_PROVBOX_FILE_MAX_DEL_FILE_NUM       (10)    /* 300 ~ 500 is preferred, more larger if more powerer CPU. */

#define SRV_PROVBOX_MAX_HANDLE_NUM              (5)     /* 5 is the max app number which provbox support */.

#endif /* MMI_PROVBOX_SRV_CONFIG_H */ 

