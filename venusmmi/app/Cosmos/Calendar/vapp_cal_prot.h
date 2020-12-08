/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_cal_prot.h
 *
 * Project:
 * --------
 *  Cosmos
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CAL_PROT_H__
#define __VAPP_CAL_PROT_H__
 
/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#ifdef __cplusplus
extern "C"
{
#endif

    #include "custom_mmi_default_value.h"
    #include "vcalsrvgprot.h"
    #include "filemgrsrvgprot.h"

#ifdef __cplusplus
}
#endif


#ifndef __MMI_CAL_SLIM__
#define __MMI_TASK_APP__
#define __MMI_CAL_EXPIRY__
#define __MMI_CAL_FUNCBAR__
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
 
#define VAPP_CAL_MAX_DAYS_PER_MONTH 31
#define VAPP_CAL_MAX_DAYS_PER_WEEK 7
#define VAPP_CAL_START_WEEKDAY 0
#define VAPP_CAL_HOURS_ONE_DAY 24
#define VAPP_CAL_MIN_YEAR       1970
#define VAPP_CAL_MIN_BIR_YEAR   1900
#define VAPP_CAL_MAX_YEAR       2030

#define VAPP_CAL_TABLE_START_YEAR   1969          /* the frist year in the database table */
#define VAPP_CAL_TABLE_END_YEAR     2031          /* the last year in the database table */
#define VAPP_CAL_SEC_PER_YEAR       31556926


#define VAPP_CAL_MAX_COUNT NUM_OF_CAL
#define VAPP_TASK_MAX_COUNT NUM_OF_TASK
#define VAPP_TDL_MAX_COUNT (NUM_OF_CAL + NUM_OF_TASK)

#define VAPP_CAL_TEMP_STRING_LEN       32
#define VAPP_CAL_MAX_SUBJECT_LEN       ((MAX_TODO_LIST_NOTE / ENCODING_LENGTH) - 1)
#define VAPP_CAL_MAX_LOCATION_LEN      MAX_TDL_LOCATION_LEN
#define VAPP_CAL_MAX_NOTE_LEN          MAX_TDL_DETAILS_LEN

#define VAPP_CAL_MAX_FILE_PATH_SIZE ((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH)
#define VAPP_CAL_TEMP_DRV SRV_FMGR_SYSTEM_DRV
#define VAPP_CAL_TEMP_FILE_NAME  L"~vobj_tmp.vcs"
#define VAPP_CAL_TEMP_FOLDER_PATH  "@caltodo"
#define VAPP_CAL_TEMP_FOLDER_FOR_UC "@caltodo"
#define VAPP_CAL_TEMP_FILE_EXT  L".vcs"


#define MMI_BOOL_2_VFX(value) (value) ? VFX_TRUE : VFX_FALSE

#define CALENDAR_TRC_GROUP TRACE_GROUP_2

#undef __VAPP_CAL_TEST_MODE__

enum VAPP_CAL_CATEGORY_ENUM
{
    VAPP_CAL_CATEGORY_PERSONAL,
    VAPP_CAL_CATEGORY_MEETING,
    VAPP_CAL_CATEGORY_SPECIALDAY,
    VAPP_CAL_CATEGORY_BIRTHDAY,
    VAPP_CAL_CATEGORY_OTHER,
    VAPP_CAL_CATEGORY_TOTAL
};


enum VAPP_CAL_REMINDER_ENUM
{
    VAPP_CAL_REMINDER_NEVER,
    VAPP_CAL_REMINDER_5MINS_EARLIER,
    VAPP_CAL_REMINDER_15MINS_EARLIER,
    VAPP_CAL_REMINDER_30MINS_EARLIER,
    VAPP_CAL_REMINDER_1HOUR_EARLIER,
    VAPP_CAL_REMINDER_1DAY_EARLIER,
    VAPP_CAL_REMINDER_3DAYS_EARLIER,
    VAPP_CAL_REMINDER_1WEEK_EARLIER,
    VAPP_CAL_REMINDER_TOTAL
};

enum VAPP_CAL_REPEAT_ENUM
{
    VAPP_CAL_REPEAT_NEVER,
    VAPP_CAL_REPEAT_DAILY,
    VAPP_CAL_REPEAT_WEEKDAY,
    VAPP_CAL_REPEAT_WEEKLY,
    VAPP_CAL_REPEAT_MONTHLY,
    VAPP_CAL_REPEAT_YEARLY,
    VAPP_CAL_REPEAT_TOTAL
};

enum VAPP_CAL_PRIORITY_ENUM
{
    VAPP_CAL_PRIORITY_HIGH,
    VAPP_CAL_PRIORITY_MEDIUM,
    VAPP_CAL_PRIORITY_LOW,
    VAPP_CAL_PRIORITY_TOTAL
};





#endif /* __VAPP_CAL_PROT_H__ */



