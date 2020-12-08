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
 *  vapp_screen_lock_zipper_time.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SCREEN_LOCK_ZIPPER_TIME_H__
#define __VAPP_SCREEN_LOCK_ZIPPER_TIME_H__


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
// Date time area
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_AREA_Y          50
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     70
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_AMPM_GAP              4
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_STR_SIZE             42
#define VAPP_ZIPPER_SCREEN_LOCK_AMPM_STR_SIZE             22
#elif defined(__MMI_MAINLCD_320X480__) 
// Date time area
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_AREA_Y          30
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     50
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_AMPM_GAP              2
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_STR_SIZE             30
#define VAPP_ZIPPER_SCREEN_LOCK_AMPM_STR_SIZE             16
#elif defined(__MMI_MAINLCD_240X400__)
// Date time area
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_AREA_Y          25
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     40
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_AMPM_GAP              2
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_STR_SIZE             20
#define VAPP_ZIPPER_SCREEN_LOCK_AMPM_STR_SIZE             14

#elif defined(__MMI_MAINLCD_240X320__)
// Date time area
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_AREA_Y          25
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     40
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_AMPM_GAP              2
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_STR_SIZE             20
#define VAPP_ZIPPER_SCREEN_LOCK_AMPM_STR_SIZE             12

#else
    // Date time area
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_AREA_Y          30
#define VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT     50
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_AMPM_GAP              2
#define VAPP_ZIPPER_SCREEN_LOCK_TIME_STR_SIZE             30
#define VAPP_ZIPPER_SCREEN_LOCK_AMPM_STR_SIZE             16

#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class VappSteamScreenLockDateTimeArea
 *****************************************************************************/
class VappZipperScreenLockDateTimeArea : public VfxFrame
{

// Constructor
public:
    VappZipperScreenLockDateTimeArea();

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
};

 
/***************************************************************************** 
 * Class VappSteamScreenLockTime
 *****************************************************************************/
class VappZipperScreenLockTime : public VfxFrame
{
    VFX_DECLARE_CLASS(VappZipperScreenLockTime);

// Constructor
public:
    VappZipperScreenLockTime();

private:
    void getTime();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Variable
private:
    VfxImageFrame *m_imgBg;
    VappZipperScreenLockDateTimeArea *m_DateTimeArea;
};
#endif /* __VAPP_STEAM_SCREEN_LOCK_CARD_H__ */

