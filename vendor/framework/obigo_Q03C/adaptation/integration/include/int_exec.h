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
 *
 * Filename:
 * ---------
 *   int_exec.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Common types for frame executions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef INT_EXEC_H
#define INT_EXEC_H

typedef void (*pfTaskStart) (void);
typedef int (*pfTaskWantsToRun) (void);
typedef void (*pfTaskRun) (void);
typedef void (*pfTaskKill) (void);
typedef int (*pfMsgHdlr) (void *);
typedef void (*pfAction) (void);        /* The callback after Obigo is initialized. */

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
typedef struct _ExModuleDescr
{
    int moduleId;
    const char *short_name;
    char startup_policy;
    int traceClass;
    pfTaskStart pTaskStart;
    pfTaskWantsToRun pTaskWantsToRun;
    pfTaskRun pTaskRun;
    pfTaskKill pTaskKill;
    pfMsgHdlr pMsgHdlr;
    int isActive;
    int status;
} ExModuleDescr;
#else
typedef struct _ExModuleDescr
{
    int moduleId;
    int taskId;
    const char *short_name;
    char startup_policy;
    int memPoolId;
    int traceClass;
    pfTaskStart pTaskStart;
    pfTaskWantsToRun pTaskWantsToRun;
    pfTaskRun pTaskRun;
    pfTaskKill pTaskKill;
    pfMsgHdlr pMsgHdlr;
    int isActive;
    int status;
} ExModuleDescr;
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

typedef enum
{
    MMS_STATUS_NULL,
    MMS_STATUS_CREATED,
    MMS_STATUS_ACTIVE,
    MMS_STATUS_SHUTTING_DOWN,
    MMS_STATUS_TERMINATED
} mms_status_enum;

typedef enum
{
   MMS_ACTION_NONE,
   MMS_ACTION_RESET
} mms_action_enum;

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
typedef enum
{
    MMS_STORAGE_SYSTEM = 0,
    MMS_STORAGE_MMS,    /* Hold MMS data */
    MMS_STORAGE_PUBLIC,  /* Default place for public data (Users can choose another partition) */
    MMS_STORAGE_EXTERNAL,
    MMS_STORAGE_VIRTUAL,
    MMS_STORAGE_DEFAULT
} wap_storage_enum;

#else
typedef enum
{
    MMS_STORAGE_SYSTEM = 0,
    WAP_STORAGE_SYSTEM = 0,
    MMS_STORAGE_MMS,    /* Hold MMS data */
    WAP_STORAGE_MMS,    /* Hold MMS data */
    MMS_STORAGE_PUBLIC,  /* Default place for public data (Users can choose another partition) */
    WAP_STORAGE_PUBLIC,  /* Default place for public data (Users can choose another partition) */
    MMS_STORAGE_EXTERNAL,
    WAP_STORAGE_EXTERNAL,
    MMS_STORAGE_VIRTUAL,
    WAP_STORAGE_VIRTUAL,
    WAP_STORAGE_REMOVABLE,  /* SLIM_R */
    MMS_STORAGE_DEFAULT
} wap_storage_enum;
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/



#define HDI_STARTUP_STATIC       0
#define HDI_STARTUP_DYNAMIC      1

extern ExModuleDescr msf_modules[];

#ifdef OBIGO_Q03C_MMS_V02
extern void mms_init_framework(void);

extern int mms_start_framework(void);

extern void mms_execute_framework(void);

extern void mms_stop_framework(void);
#endif

extern void gmms_adp_mms_jmpbuf_hdlr(void);

extern kal_uint8 mms_status;

extern int mms_action;

extern pfAction mms_ready_cb;

#endif /* INT_EXEC_H */ 

