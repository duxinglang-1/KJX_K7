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
 *  vtst_drag.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Drag example for Venus UI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VTST_DRAG_H__
#define __VTST_DRAG_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxControl
#include "vfx_control.h"
// For VfxAppCatScr
#include "vfx_app_cat_scr.h"

#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_timer.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Predefined class
class VfxTimer;


/***************************************************************************** 
 * Class VtstDragTarget
 *****************************************************************************/

class VtstDragTarget : public VfxControl
{
// Constructor / Destructor
public:
    // Default constructor
    VtstDragTarget();

public:
    void delayClose(VfxMsec delayTime);

// Signal
public:
    VfxSignal2 <VtstDragTarget *, VfxPenEvent &> m_signalDrag;
    VfxSignal2 <VtstDragTarget *, VfxPenEvent &> m_signalMove;
    VfxSignal2 <VtstDragTarget *, VfxPenEvent &> m_signalDrop;

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
};


/***************************************************************************** 
 * Class VtstDragBarItem
 *****************************************************************************/

class VtstDragBarItem : public VfxControl
{
// Constructor / Destructor
public:
    // Default constructor
    VtstDragBarItem();

    VfxSignal1 <VtstDragBarItem *> m_signalDragStart;

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
};


/***************************************************************************** 
 * Class VtstDragBar
 *****************************************************************************/

class VtstDragBar : public VfxControl
{
// Constructor / Destructor
public:
    // Default constructor
    VtstDragBar();

    void addItem(const VfxPoint &pos);

    VfxSignal1 <VtstDragBarItem *> m_signalDragStart;

// Override
protected:
    virtual void onInit();

    void onItemDragStart(VtstDragBarItem *);
};


/***************************************************************************** 
 * Class VtstDragScr
 *****************************************************************************/

class VtstDragScr : public VfxAppCatScr
{
// Constructor / Destructor
public:
    // Default constructor
    VtstDragScr();

// Override
protected:
    virtual void onInit();

private:
    VtstDragBar *m_controlBar;
    VtstDragTarget *m_controlTarget;
    VfxTimer *m_timerDropTargetToBar;
    
    void onItemDragStart(VtstDragBarItem *obj);
    void onTargetDrag(VtstDragTarget *obj, VfxPenEvent &event);
    void onTargetMove(VtstDragTarget *obj, VfxPenEvent &event);
    void onTargetDrop(VtstDragTarget *obj, VfxPenEvent &event);

    void onTimerDropTargetToBarTick(VfxTimer *obj);
};

#endif /* __VTST_DRAG_H__ */

