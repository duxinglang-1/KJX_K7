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
 *  ReminderConfigTable.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  reminder table, AP should add reminder type and change the total number
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __REMINDER_TYPE_TABLE_H__
#define __REMINDER_TYPE_TABLE_H__

/****************************************************************************
 * Include
 ****************************************************************************/

/****************************************************************************
 * Constants
 ****************************************************************************/

/****************************************************************************
 * Typedef
 ****************************************************************************/
 
 /*
   *  1. The former one has high priority. 
   *  2. don't need to add compile option. 
   */
typedef enum
{
	SRV_REMINDER_TYPE_SPON,             /* 0 */
	SRV_REMINDER_TYPE_THEME,            /* 1 */
	SRV_REMINDER_TYPE_TASK,             /* 2 */
	SRV_REMINDER_TYPE_CAL,              /* 3 */
	SRV_REMINDER_TYPE_ALM,              /* 4 */
    SRV_REMINDER_TYPE_AZAAN,            /* 5 */
    SRV_REMINDER_TYPE_FMSR,             /* 6 */
    SRV_REMINDER_TYPE_FMRDO,            /* 7 FM alarm */
    SRV_REMINDER_TYPE_SPOF,             /* 8 schedule power off alarm */
    SRV_REMINDER_TYPE_FACTORY,          /* 9 factory alarm */
    SRV_REMINDER_TYPE_PWR_RESET,        /* 10 resets alarm */
    SRV_REMINDER_TYPE_SYNCML,           /* 11 1 alarm for syncml */
    SRV_REMINDER_TYPE_LANGLN,           /* 12 language alarm */
    SRV_REMINDER_TYPE_DTV,              /* 13 */
    SRV_REMINDER_TYPE_SNS,              /* 14 */
	/* Add reminder type before this line */
	SRV_REMINDER_TYPE_CUSTOM,           /* 15 */
	SRV_REMINDER_TYPE_POWER_ON_CONFIRM, /* 16 For power on confirm after alarm power on */
	SRV_REMINDER_TYPE_MRE_ALARM,
	SRV_REMINDER_TYPE_TOTAL             /* 17 */
}srv_reminder_type;

#endif /* __REMINDER_TYPE_TABLE_H__ */
