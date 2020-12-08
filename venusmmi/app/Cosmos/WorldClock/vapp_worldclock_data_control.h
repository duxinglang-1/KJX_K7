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
 * VappWCDataControl.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements world clock application.
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
 *****************************************************************************/
#ifndef __VAPP_WORLD_CLOCK_DATA_CONTROL_H__
#define __VAPP_WORLD_CLOCK_DATA_CONTROL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_string.h"
#include "vfx_datatype.h"

/****************************************************************************
 *class
 ***************************************************************************/

/***************************************************************************** 
 * World clock data control Class
 * supply API for getting data from srv
 *****************************************************************************/
class VappWCDataControl : public VfxBase
{
public:
    
    VappWCDataControl(){};

    VfxU8  getTimeFormat();
    VfxU8  getHomeCityDst();
    VfxU8  getFrnCityDst(const VfxU8 cityOrder);
    VfxU16 getHomeCityIndex();
    VfxU16 getFrnCityIndex(const VfxU8 cityOrder);
    VfxU16 getCityListByName(VfxWChar *city, VfxU16 *result);
    VfxU16 getCityListByTZ(VfxFloat tz, VfxU16 *result);
    VfxU16 getCityByPos(VfxPoint cityPos);
    VfxU16 getCityByX(VfxS32 posX);
    VfxWString getTimeZoneStr(VfxFloat tz);
    VfxWString getCityString(VfxU16 cityIndex);
    VfxWString getAmPmString(VfxDateTime dt);
    VfxFloat getTimeZone(VfxU16 cityIndex);
    VfxFloat getPrevTimeZone(VfxFloat currTZ);
    VfxFloat getNextTimeZone(VfxFloat currTZ);
    VfxPoint getCityPos(VfxU16 cityIndex);        
    void saveHomeCityIdx(VfxU16 cityIndex);
    void saveFrnCityIdx(VfxU16 cityIndex, VfxU8 cityOrder);
    void saveHomeCityDst(VfxU8 homeDst);
    void saveFrnCityDst(VfxU8 frnDst, VfxU8 cityOrder);
    void getTime(VfxFloat src, VfxFloat des, VfxDateTime &dt);
    void updateSysTime(VfxU16 newCityIndex, VfxS16 dstFlag);
};

#endif
