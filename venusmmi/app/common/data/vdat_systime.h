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
 *  vdat_systime.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  System time utility
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VDAT_SYSTIME_H__
#define __VDAT_SYSTIME_H__

#ifdef __cplusplus

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"
// For VfxSignal1
#include "vfx_signal.h"

#include "vfx_datatype.h"
#include "vfx_date_time.h"


/***************************************************************************** 
 * Class VdatSystemTime
 *****************************************************************************/

#define VDAT_SYSTIME_CHANGED_YEAR       (1 << 5)
#define VDAT_SYSTIME_CHANGED_MONTH      (1 << 4)
#define VDAT_SYSTIME_CHANGED_DAY        (1 << 3)
#define VDAT_SYSTIME_CHANGED_HOUR       (1 << 2)
#define VDAT_SYSTIME_CHANGED_MIN        (1 << 1)

/*
 * This class can receive pluto time event to venus.
 * You can connect signal for time change event.
 */
class VdatTimeNotification : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VdatTimeNotification);

// Declaration
public:

// Constructor / Destructor
public:
    // Default constructor
    VdatTimeNotification();

// Method
public:
    // Reset internal cache time.
    // This function will not invoke signal.
    void reset();

// Singal
public:
    // This signal will invoke time change event with modified flag
    // Please refer VDAT_SYSTIME_CHANGED_XXXX bits.
    VfxSignal1<VfxU32> m_signalTimeChanged;

// Variable
private:
    // This store for current time.
    VfxDateTime m_curTime;

// Implementation
public:
    // Check whether we need to invoke event at this moments
    void checkTimeEvent();
};

#endif

/***************************************************************************** 
 * Global function
 *****************************************************************************/

// This function is invoked by system datatime module.
#ifdef __cplusplus
extern "C" 
{
#endif // __cplusplus

void vdat_system_time_changed_handler(void);

#ifdef __cplusplus
} // extern "C" 
#endif // __cplusplus

#endif // __VDAT_SYSTIME_H__

