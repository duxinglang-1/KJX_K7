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
 *  vapp_ncenter_system_cell.h
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
#ifndef __VAPP_NCENTER_SYSTEM_CELL_H__
#define __VAPP_NCENTER_SYSTEM_CELL_H__


/***************************************************************************** 
 * include
 *****************************************************************************/
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "MMIDataType.h"
#include "NwNameSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

#ifdef __cplusplus
}
#endif

#include "vapp_ncenter_pure_key_base_cell.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/


#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/***************************************************************************** 
 * Class VappNCenterSIMNameElement
 *****************************************************************************/
class VappNCenterSIMNameElement : public VfxFrame
{
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterSIMNameElement(VfxS32 simId);   

// Override
protected:
    virtual void onInit();

// Method
public:
    void layout();

// Variable
private:
    VfxS32 m_simId;
    VfxTextFrame    *m_leftParenthesis;
    VfxTextFrame    *m_textSIMName;
    VfxTextFrame    *m_rightParenthesis;
    VfxSize         m_size;
};
#endif


/***************************************************************************** 
 * Class VappNCenterOperatorElement
 *****************************************************************************/

class VappNCenterOperatorElement : public VfxFrame
{
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterOperatorElement(VfxS32 simId);   

// Override
protected:
    virtual void onInit();

// Method
public:
    void updateOperatorName(VfxS32 maxWidth);

private:
    void insertSeparator(VfxFrame *target, VfxS32 posY);

// Variable
private:
    VfxS32 m_simId;
    VfxImageFrame   *m_imgSim;
    VfxTextFrame    *m_textOPN;    
    VfxTextFrame    *m_textSPN;   
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    VappNCenterSIMNameElement *m_textSIMName;
#endif
    VfxImageFrame *m_separatorL;
};


/***************************************************************************** 
 * Class VappNCenterOperatorCell 
 *****************************************************************************/

class VappNCenterOperatorCell : public VfxFrame
{
    // Constructor / Destructor
public:
    // Default constructor
    VappNCenterOperatorCell();   

    VfxBool getIsFold(){ return m_isFold;}
    void setIsFold(VfxBool isFold);
    VcpImageButton* getFoldButton(){ return m_foldButton; }

    void requestNCenterUpdate(VfxId id, VfxS32 height){
            setSize(getSize().width, height);
            m_signalRequestUpdate.emit(id,height);
    }

    void createFoldButton(VfxBool isCreate);       

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onFoldButtonClick(VfxObject* sender, VfxId id);


private:
    void insertSeparator(VfxFrame *target, VfxS32 posY);
    void initOperatorNameCell();
    void update(VfxS32 maxWidth);
    static mmi_ret eventHandler(mmi_event_struct *event);

// Variable
public:
    VfxSignal1 <
           VfxObject *            // sender
           > m_signalRequestLeave;
       VfxSignal2 <VfxId, VfxS32>  m_signalRequestUpdate;
       

private:
    VappNCenterOperatorElement *m_operElement[MMI_SIM_TOTAL]; 

    VfxTextFrame *m_noServiceText;
    VfxImageFrame *m_separatorL;

    VcpImageButton *m_foldButton;
    VfxBool m_isFold;
};
#endif /* __VAPP_NCENTER_TEST_CELL_H__ */

