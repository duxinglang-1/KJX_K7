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
 *  CharBatGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for charger battery service
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
#ifndef _CHARGER_BATTERY_PROT_H
#define _CHARGER_BATTERY_PROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "CharBatSrvGprot.h"

/*----------------------------------------------------------------------------*/
/* TRACE                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_CHARBAT_TRC                               MMI_COMMON_TRC_G8_DEV


/*----------------------------------------------------------------------------*/
/* Enum, Struct                                                                     */
/*----------------------------------------------------------------------------*/
typedef enum
{
    SRV_CHARBAT_FLAG_ALLOW_MO         = (0x0001), /* MMI_TRUE: allow MO call; MMI_FALSE: not allow */
    SRV_CHARBAT_FLAG_CHARGING         = (0x0002), /* MMI_TRUE: phone is charging */
    SRV_CHARBAT_FLAG_CHARGE_COMPLETE  = (0x0004), /* MMI_TRUE: when charger in, battery is full and charging is completed */
    SRV_CHARBAT_FLAG_LOW_BATTERY      = (0x0008), /* MMI_TRUE: current battery status is low battery */
    SRV_CHARBAT_FLAG_CHARGE_CONNECT   = (0x0010), /* MMI_TRUE: charger is connected */
    SRV_CHARBAT_FLAG_END_OF_ENUM      = (0x1111)
} srv_charbat_flag_enum;


typedef struct
{
    U16   flag;              /* support bitwise operation */
    U8    battery_level;     /* refer: battery_level_enum */
    U8    notify_mod_id;     /* need notify this mod, when receive battery_level */
} srv_charbat_cntx_struct;


/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define  SRV_CHARBAT_CHECK_BIT(flag, bit)               ((flag) & (bit))
#define  SRV_CHARBAT_SET_BIT(flag, bit)                 ((flag) |= (bit))
#define  SRV_CHARBAT_CLEAR_BIT(flag, bit)               ((flag) &= ~(bit))


/*----------------------------------------------------------------------------*/
/* Extern Variable                                                            */
/*----------------------------------------------------------------------------*/
extern U8 batteryLowCount;
extern U8 lowBatteryAlarmThreshold;


/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/
extern void srv_charbat_set_mo_allow_flag(MMI_BOOL allow_flag);
extern void srv_charbat_set_bat_level(U8 bat_level);
extern void srv_charbat_set_low_bat_flag(MMI_BOOL low_flag);
extern void srv_charbat_notify_bat_level(void);
extern void srv_charbat_bat_status_hdlr(U8 bat_level);
extern void srv_charbat_reset_low_bat_cnt(void);


extern MMI_BOOL srv_charbat_get_charger_status(srv_charbat_status_enum status_id);


#endif /* _CHARGER_BATTERY_PROT_H */ 

