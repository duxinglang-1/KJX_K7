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
 *  vapp_screen_lock_time.h
 *
 * Project:
 * --------
 *  Venus
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

#ifndef __VAPP_SCREEN_LOCK_COSMOS_TIME_H__
#define __VAPP_SCREEN_LOCK_COSMOS_TIME_H__

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "MMIDataType.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT  (185+13)
#define VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH    36
#define VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_SHADOW    14

    
// Operator name area
#define VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT 30
    
// Date time area
#define VAPP_SCREEN_LOCK_DATE_TIME_AREA_Y          (40 + VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH)//49
#define VAPP_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     (VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT - VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT)
#define VAPP_SCREEN_LOCK_WEEK_DATE_AREA_POS_Y      120
#define VAPP_SCREEN_LOCK_TIME_AMPM_GAP              8
#define VAPP_SCREEN_LOCK_TIME_STR_SIZE             98
#define VAPP_SCREEN_LOCK_DAY_STR_SIZE              23
#define VAPP_SCREEN_LOCK_AMPM_STR_SIZE             30
    
#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT  (108+7)
#define VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH    24
#define VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_SHADOW    7
    
// Operator name area
#define VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT 30
    
// Date time area
#define VAPP_SCREEN_LOCK_DATE_TIME_AREA_Y          (25 + VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH)
#define VAPP_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     (VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT - VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT)
#define VAPP_SCREEN_LOCK_WEEK_DATE_AREA_POS_Y      80
#define VAPP_SCREEN_LOCK_TIME_AMPM_GAP              2
#define VAPP_SCREEN_LOCK_TIME_STR_SIZE             58
#define VAPP_SCREEN_LOCK_DAY_STR_SIZE              14
#define VAPP_SCREEN_LOCK_AMPM_STR_SIZE             18

#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#define VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT  90 
#define VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH   24
#define VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_SHADOW    7
    
// Operator name area
#define VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT 15
    
// Date time area
#define VAPP_SCREEN_LOCK_DATE_TIME_AREA_Y          (20 + VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH)
#define VAPP_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     (VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT - VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT)
#define VAPP_SCREEN_LOCK_WEEK_DATE_AREA_POS_Y      55
#define VAPP_SCREEN_LOCK_TIME_AMPM_GAP              1
#define VAPP_SCREEN_LOCK_TIME_STR_SIZE             42
#define VAPP_SCREEN_LOCK_DAY_STR_SIZE              13
#define VAPP_SCREEN_LOCK_AMPM_STR_SIZE             16

#else
#define VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT  131 
#define VAPP_SCREEN_LOCK_COSMOS_STATUS_BAR_WIDTH    24
#define VAPP_SCREEN_LOCK_COSMOS_TIME_AREA_SHADOW    7

    
// Operator name area
#define VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT 50
    
// Date time area
#define VAPP_SCREEN_LOCK_DATE_TIME_AREA_Y          (VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT - VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT)
#define VAPP_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     (VAPP_SCREEN_LOCK_OPERATOR_AND_TIME_HIEGHT - VAPP_SCREEN_LOCK_OPERATOR_NAME_AREA_HEIGHT)
#define VAPP_SCREEN_LOCK_WEEK_DATE_AREA_POS_Y      69
#define VAPP_SCREEN_LOCK_TIME_AMPM_GAP              2
#define VAPP_SCREEN_LOCK_TIME_STR_SIZE             58
#define VAPP_SCREEN_LOCK_DAY_STR_SIZE              14
#define VAPP_SCREEN_LOCK_AMPM_STR_SIZE             18
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class VappScreenLockDateTimeArea
 *****************************************************************************/
class VappScreenLockDateTimeArea : public VfxFrame
{

// Constructor
public:
    VappScreenLockDateTimeArea();

// Method
public:
    void timeUpdate(VfxU32 flag);

// Override
protected:
    // On init
    virtual void onInit();
    // On Deinit
    virtual void onDeinit();

// Variable
private:
    VfxFrame            *m_DateTimeBg;
    VfxTextFrame        *m_Time;
    VfxTextFrame        *m_AmPm;
    VfxTextFrame        *m_WeekDay;
    VfxTextFrame        *m_Date;
};


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/***************************************************************************** 
 * Class VappScreenLockTime
 *****************************************************************************/
class VappScreenLockTime : public VfxFrame
{
    VFX_DECLARE_CLASS(VappScreenLockTime);

// Constructor
public:
    VappScreenLockTime();

private:
    void getTime();
    void getOperatorName();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Implementation
public:

    //
    // For the purpose of change background dynamically while notification panel has been created,
    // the background image will be replaced with no shadow in the bottom.
    //
    void setTimeAreaBG(VfxResId img, VfxBool isShadow);

// Variable
private:
    VfxImageFrame *m_imgBg;
    VappScreenLockDateTimeArea *m_DateTimeArea;
};
#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
#endif /* __VAPP_SCREEN_LOCK_COSMOS_CARD_H__ */

