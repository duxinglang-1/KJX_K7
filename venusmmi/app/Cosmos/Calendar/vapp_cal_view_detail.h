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
 *  vapp_cal_view_detail.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  view event/task detail
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CAL_VIEW_DETAIL_H__
#define __VAPP_CAL_VIEW_DETAIL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "MMIDatatype.h"

#include "vfx_datatype.h"
#include "vfx_page.h"
#include "vfx_signal.h"

#include "vapp_cal_edit.h"
#include "vapp_cal_prot.h"


/***************************************************************************** 
 * Definition
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
    #define VAPP_CAL_DETAIL_TOP_GAP                 8
    #define VAPP_CAL_DETAIL_DOWN_GAP                8
    #define VAPP_CAL_DETAIL_LEFT_GAP                8
    #define VAPP_CAL_DETAIL_RIGHT_GAP               8
       
#elif defined(__MMI_MAINLCD_480X800__)
    #define VAPP_CAL_DETAIL_TOP_GAP                 14      
    #define VAPP_CAL_DETAIL_DOWN_GAP                14
    #define VAPP_CAL_DETAIL_LEFT_GAP                14
    #define VAPP_CAL_DETAIL_RIGHT_GAP               14

#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )  
    #define VAPP_CAL_DETAIL_TOP_GAP                 5
    #define VAPP_CAL_DETAIL_DOWN_GAP                5
    #define VAPP_CAL_DETAIL_LEFT_GAP                5
    #define VAPP_CAL_DETAIL_RIGHT_GAP               5
    
#else
    #define VAPP_CAL_DETAIL_TOP_GAP                 14   
    #define VAPP_CAL_DETAIL_DOWN_GAP                14
    #define VAPP_CAL_DETAIL_LEFT_GAP                14
    #define VAPP_CAL_DETAIL_RIGHT_GAP               14
#endif


enum VAPP_CAL_VIEW_TB_ID_ENUM
{
    VAPP_CAL_TOOLBAR_VIEW_EDIT,
    VAPP_CAL_TOOLBAR_VIEW_SAVEAS,
    VAPP_CAL_TOOLBAR_VIEW_SHARE,
    VAPP_CAL_TOOLBAR_VIEW_DELETE,
    VAPP_CAL_TOOLBAR_VIEW_TOTAL
};


enum VAPP_CAL_CMD_SHARE_ID_ENUM
{
    VAPP_CAL_CMD_SHARE_BY_SMS,
    VAPP_CAL_CMD_SHARE_BY_MMS,
    VAPP_CAL_CMD_SHARE_BY_EMAIL,
    VAPP_CAL_CMD_SHARE_BY_BLUETOOTH,
    VAPP_CAL_CMD_SHARE_CANCEL,
    VAPP_CAL_CMD_SHARE_TOTAL
};


#define VAPP_CAL_VIEW_DETAIL_MAX_LEN   (VAPP_CAL_MAX_LOCATION_LEN + \
                                       VAPP_CAL_MAX_NOTE_LEN + \
                                       150)

/***************************************************************************** 
 * Class VappCalViewDetailPage
 *****************************************************************************/
class VcpTextView;
class VcpTitleBar;
class VappCalViewDetailPage: public VfxPage
{

    VFX_DECLARE_CLASS(VappCalViewDetailPage);
    
public:

    VappCalViewDetailPage() : 
        m_vcalType(SRV_TDL_VCAL_EVENT), 
        m_index(0),
        m_data(NULL)
        {}

    VappCalViewDetailPage(srv_tdl_vcal_enum vcal_type, VfxU16 index) : 
    m_vcalType(vcal_type), 
    m_index (index),
    m_data(NULL)
    {}

    VappCalViewDetailPage(srv_tdl_vcal_enum vcal_type, srv_tdl_event_id_struct eventIndex) : 
    m_vcalType(vcal_type), 
    m_index (0),
    m_eventbuffer(eventIndex),
    m_data(NULL)
    {
        m_index = (VfxU16)-1;

    }        
        

    VfxSignal1 <VfxObject*> m_signalDataUpdated;
// Override     
protected:
    virtual void onInit();
    virtual void onDeinit();
    
    virtual void onUpdate();

// Implement
private:
    void onTBClick(VfxObject* sender, VfxId id);
    void onDeleteConfirm(VfxObject* sender, VfxId id);
#if ((defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__) || \
         defined(__MMI_EMAIL__) || defined(__MMI_OPP_SUPPORT__))&&defined(__MMI_VCALENDAR__))

    void onShareCmdBtnClicked(VfxObject* sender, VfxId id);
    void send(VAPP_CAL_CMD_SHARE_ID_ENUM viaType);
#endif

    void initEventViewDetail();
    
#ifdef __MMI_TASK_APP__
    void initTaskViewDetail();
#endif

#ifndef __MMI_CAL_SLIM__
    void check(srv_tdl_op_evt_struct *op_evt);
    static mmi_ret onEventChange(mmi_event_struct *evt);
    void updatepage(srv_tdl_event_op_struct *op_evt);
    static mmi_ret onEvent(mmi_event_struct *evt);
    void onDataUpdated(VfxObject *sender);
#endif

private:
    VcpTextView *m_multilineView;
    srv_tdl_vcal_enum m_vcalType;
    VfxU16 m_index;  

    srv_tdl_event_id_struct m_eventbuffer;

    void *m_data;
    VfxWChar *m_multiViewString;
    VcpTitleBar *m_titleBar;
    
};

#endif /* __VAPP_CAL_VIEW_DETAIL_H__ */
