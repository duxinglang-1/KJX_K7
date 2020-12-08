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
 * Filename:
 * ---------
 * vCalSrvProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines function prototypes used in vcalendar application.
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
#ifndef VCAL_SERVICE_PROT_H
#define VCAL_SERVICE_PROT_H

#include "MMI_features.h"
#include "MMIDataType.h"
    
//#ifdef __MMI_SRV_TODOLIST__
#if ((defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)
#define SRV_VCAL_TIME_FMT_UTC      (0)
#define SRV_VCAL_TIME_FMT_RTC      (1)
#define SRV_VCAL_TIME_FMT_RTC_TZ   (2)

#define SRV_VCAL_REMOVE_PRE_WS        (0)
#define SRV_VCAL_REMOVE_POST_WS       (1)
#define SRV_VCAL_REMOVE_BOTH_WS       (2)

#define SRV_VCAL_SEP_STR             ":"
#define SRV_VCAL_CRLF_STR            "\r\n"
#define SRV_VCAL_PARSE_BUFF_LEN      (1024)
#define SRV_VCAL_PARSE_TYPE_LEN      (50)
#define SRV_VCAL_BUILD_BUFF_LEN      (1024)
#define SRV_VCAL_BUILD_HEADER_LEN    (50)
#define SRV_VCAL_BUILD_TAIL_LEN      (50)
#define SRV_VCAL_MIN_START_YEAR      (1900)
#define SRV_VCAL_MIN_START_YEAR_EXT  (1970)
#define SRV_VCAL_MAX_END_YEAR        (2030)

#define SRV_VCAL_CATEGORY_REMINDER    "Reminder"    
#define SRV_VCAL_CATEGORY_MEETING     "Meeting"    
#define SRV_VCAL_CATEGORY_COURSE      "Course"    
#define SRV_VCAL_CATEGORY_DATE        "Date"    
#define SRV_VCAL_CATEGORY_CALL        "Call"    
#define SRV_VCAL_CATEGORY_ANNIVERSARY "Anniversary"    
#define SRV_VCAL_CATEGORY_BIRTHDAY    "Birthday"

#define VCLNDR_STATUS_COMPLETED     "COMPLETED"
#define VCLNDR_STATUS_DEFAULT       "NEEDS ACTION"

typedef enum
{
    SRV_VCAL_BEGIN,
    SRV_VCAL_VERSION,
    SRV_VCAL_VEVENT_BEGIN,
    SRV_VCAL_VTODO_BEGIN,
    SRV_VCAL_DTSTART,
    SRV_VCAL_DTEND,
    SRV_VCAL_DUE,
    SRV_VCAL_TZID,
    SRV_VCAL_SUMMARY,
    SRV_VCAL_DESCRIPTION,
    SRV_VCAL_RRULE,
    SRV_VCAL_DALARM,
    SRV_VCAL_AALARM,
    SRV_VCAL_VTODO_END,
    SRV_VCAL_VEVENT_END,
    SRV_VCAL_END,
    SRV_VCAL_CLASS,
    SRV_VCAL_LOCATION,
    SRV_VCAL_PRIORITY,
    SRV_VCAL_COMPLETED,
    SRV_VCAL_LAST_MODIFIED,
    SRV_VCAL_CATEGORY,
    SRV_VCAL_STATUS,
    SRV_VCAL_UID,
    SRV_VCAL_X_EXTENSION,
    SRV_VCAL_PRODID,
    SRV_VCAL_SEQUENCE,
    SRV_VCAL_TOTAL_FILEDS
} srv_vcal_filed_type;

typedef enum
{
    SRV_VCAL_DAILY,
    SRV_VCAL_WEEKLY,
    SRV_VCAL_MONTHLY,
    SRV_VCAL_YEARLY,
    SRV_VCAL_RECURR_TOTAL
}srv_vcal_recurr_enum;

typedef struct
{
    U8 days;
    U8 repeat;
}srv_vcal_recurr_struct;

typedef enum
{
    SRV_VCAL_PARA_LANGUAGE,               /* Not used */
    SRV_VCAL_PARA_CHARSET,                /* Charset for parsing */
    SRV_VCAL_PARA_ENCODING,               /* Encoding for parsing */
    SRV_VCAL_PARA_TOTAL
}srv_vcal_para_type_enum;

#endif /*__MMI_SRV_TODOLIST__*/
#endif /* VCAL_SERVICE_PROT_H */
