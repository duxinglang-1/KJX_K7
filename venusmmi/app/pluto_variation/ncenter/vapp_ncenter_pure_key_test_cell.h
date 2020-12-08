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
 *  vapp_ncenter_test_cell.h
 *
 * Project:
 * --------
 *  COSMOS Notification Center
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_NCENTER_SUPPORT__)


#ifndef __VAPP_NCENTER_TEST_CELL_H__
#define __VAPP_NCENTER_TEST_CELL_H__


//#define __VAPP_NCENTER_UNIT_TEST__


#ifdef __VAPP_NCENTER_UNIT_TEST__

#include "vfx_primitive_frame.h"
#include "vsrv_ncenter.h"



/***************************************************************************** 
 * Class VsrvNCellTest    
 *****************************************************************************/

class VsrvNCellTest : public VsrvNCell
{
    VFX_DECLARE_CLASS(VsrvNCellTest);        

// Override
protected:
    virtual void onCreateView(void* viewData, VfxU32 viewDataSize);
    virtual void onProcessIntent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize);


// Variable
private:    
    VfxFrame *m_frame1;
    VfxFrame *m_frame2;
    VfxFrame *m_frame3;    
    VfxFrame *m_frame4;    

};

/***************************************************************************** 
 * Class VappNCenterGridCell    
 *****************************************************************************/
#define NCENTER_GRID_ITEMS_AMOUNT 10



class VappNCenterGridCell : public VfxControl
{
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterGridCell();   
    VfxU16 layoutItems(VfxU16 width);

// Override
protected:
    virtual void onInit();
    VfxBool onPenInput(VfxPenEvent &event);

    
private:
    
    VfxS16 findHitItem(const VfxPenEvent &event) const;
    VfxFrame *m_items[NCENTER_GRID_ITEMS_AMOUNT];   

        
// Variable
public:

};

#endif /* __VAPP_NCENTER_UNIT_TEST__ */

#endif /* __VAPP_NCENTER_TEST_CELL_H__ */

#endif /* defined(__MMI_NCENTER_SUPPORT__) */

