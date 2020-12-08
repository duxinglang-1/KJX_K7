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
 *  vapp_cal_utility.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  calendar utility
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
#ifndef __VAPP_CAL_UTILITY_H__
#define __VAPP_CAL_UTILITY_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

extern "C"
{
    #include "todolistsrvgprot.h"
    #include "remindersrvgprot.h"
}

#include "vfx_datatype.h"
#include "vcp_popup_data_type.h"
#include "vapp_cal_prot.h"
#include "vcp_global_popup.h"

/***************************************************************************** 
 * Definition
 *****************************************************************************/    
    
#define GetWeekDayMASK(_day) VappCalUtility::s_calWeek[_day]


enum VAPP_CAL_BUILD_FOLDER_TYPE
{
    VAPP_CAL_BUILD_FOLDER_RECEIVED,
    VAPP_CAL_BUILD_FOLDER_FOR_UC,
    VAPP_CAL_BUILD_FOLDER_TOTAL
};


/***************************************************************************** 
 * struct 
 *****************************************************************************/

struct VappCalLunarTableStruct
{
    U8 BaseDays;    /* different days from solar Jan 1 to lunar Jan 1. */
    U8 BaseWeekday; /* week day of Jan 1 this year. 0=Sunday */
    U8 BaseKanChi;  /* the Kan and Chin of Jan 1 this year. */
    S8 Intercalary;     /* an intercalary month in the lunar calendar.                    
                           0==no intercalary month in this year. */
    U16 MonthDays;  /* the number of days in lunar month, bit-level representation 0=29, 1=30. */
};

struct VappCalGlobalPopupStruct
{
    MMI_ID parentID;
    VcpPopupTypeEnum type;
    VfxResId textResId;
    VfxResId btnText1ResId;
    VcpPopupButtonTypeEnum type1;
    PopupCallBackPtr callback;
    void *userData;
};

/***************************************************************************** 
 * Class VappCalUtility
 *****************************************************************************/
class VappCalUtility : public VfxBase
{
    
// Static interface  
public:
    static VfxBool dateTimeIsOutOfBounder(VfxU16 year, VfxU16 category);  

    static void getListItemDateTimeStr(
                                VfxU16 fieldType, 
                                srv_tdl_vcal_enum type,
                                const void* dataPtr,
                                VfxWString &subBuf);

    static applib_time_struct getLunarDateBySolarDate(applib_time_struct& solarDate, VfxU16& lunar_days, VfxU8& leap_day);
    static void getLunarStringByDate(applib_time_struct solarDate, VfxWString &lunarStr);

#ifdef __MMI_VCALENDAR__ 
    static VfxS32 createFolderIfNotExist(VfxWChar* path);
    static VfxWChar* buildTempVcalFile(VfxWChar* path, void *data, srv_tdl_vcal_enum type, VAPP_CAL_BUILD_FOLDER_TYPE folderType);
#endif
    static VfxU16 getListIdx(srv_tdl_event_task_struct *list, VfxU16 listLength, VfxU16 storeIdx);

    static VfxBool isValidAlarm(void *data, srv_tdl_vcal_enum vcalType);


    static void getSnsDataError();
    static void ClosePopup(VfxId id, void *userData);

    //Static variable
public:
    static const VfxU8 s_calWeek[];
    static const VfxU16 s_calAccuDays[];
    static const VappCalLunarTableStruct s_calLunarInfo[];
    static const VfxU8 s_leapMonth[62][12];
    static const VfxU8 s_lunarTermTable[62][24];
    static const VfxU8 s_daysInMonth[]; 
    static VfxS32 tempId;

};


#endif //__VAPP_CAL_UTILITY_H__


