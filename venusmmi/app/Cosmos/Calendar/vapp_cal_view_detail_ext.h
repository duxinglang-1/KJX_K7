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
 *  vapp_cal_view_detail_ext.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  implementation view detail event/task fomr external APP 
 *  such as SMS/MMS/FMGR/EMAIL/BT
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CAL_VIEW_DETAIL_EXT_H__
#define __VAPP_CAL_VIEW_DETAIL_EXT_H__
#include "mmi_features.h"
#ifdef __MMI_VCALENDAR__ 

extern "C" 
{
#include "custom_mmi_default_value.h"
#include "todolistsrvgprot.h"
#include "vcalsrvgprot.h"
#include "filemgrsrvgprot.h"
}

#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"

#include "vapp_cal_prot.h"

/**************************DECLARATION*******************************************/
/********************************************************************************/

enum VAPP_CAL_VIEW_DETAIL_EXT_FROM_APP_ENUM
{
    VAPP_CAL_VIEW_DETAIL_EXT_FROM_MESSAGE,
    VAPP_CAL_VIEW_DETAIL_EXT_FROM_FMGR,
    VAPP_CAL_VIEW_DETAIL_EXT_FROM_TOTAL
};


enum VAPP_CAL_VIEW_DETAIL_EXT_TB_ID_ENUM
{
    VAPP_CAL_VIEW_DETAIL_EXT_TB_SAVE, //save to cal or task directly
    VAPP_CAL_VIEW_DETAIL_EXT_TB_CANCEL,
    VAPP_CAL_VIEW_DETAIL_EXT_TB_SAVEASFILE,
    VAPP_CAL_VIEW_DETAIL_EXT_TB_TOTAL
};


struct vapp_cal_view_detail_struct
{
    VfxWChar filePath[SRV_FMGR_PATH_MAX_LEN + 1];
    VAPP_CAL_VIEW_DETAIL_EXT_FROM_APP_ENUM appType;
};


#define VAPP_VCAL_PORT 0x23f5


extern "C" void vapp_vcal_view_detail_register_message(void);

/***************************************************************************** 
 * Class VappCalViewDetailApp
 *****************************************************************************/
class VappCalViewDetailApp : public VfxApp, public IVfxMainScrHandler
{
    VFX_DECLARE_CLASS(VappCalViewDetailApp);

    //override 
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    virtual void onScr1stReady(VfxMainScrEx *scr);

public:
    VfxWChar *m_filePath;
    VAPP_CAL_VIEW_DETAIL_EXT_FROM_APP_ENUM m_appType;

};


/***************************************************************************** 
 * Class VappCalViewDetailFromExtPage
 *  View an Event/Task from external APP.
 *  This page will provide "Save" function.
 *****************************************************************************/
class VcpTextView;
class VappCalViewDetailFromExtPage: public VfxPage
{
    
public:
    
    VappCalViewDetailFromExtPage():
        m_data(NULL), 
        m_appType(VAPP_CAL_VIEW_DETAIL_EXT_FROM_MESSAGE),
        m_vcalType(SRV_TDL_VCAL_EVENT),
        m_filePath(NULL)
    {};


    VappCalViewDetailFromExtPage(VAPP_CAL_VIEW_DETAIL_EXT_FROM_APP_ENUM appType, 
            VfxWChar *filePath ):m_data(NULL),m_multiViewString(NULL)
    {
        m_appType = appType;  
        m_filePath = filePath;
    };


public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    void onTBClick(VfxObject* sender, VfxId id);
    void onPopupClicked(VfxObject* sender, VfxId id);
    
    static void adjustDataValidation(void *data, srv_tdl_vcal_enum vcalType);
    static VAPP_CAL_REMINDER_ENUM computeReminderType(void *data, srv_tdl_vcal_enum vcalType);
    static void adjustCategory(srv_tdl_event_struct *event);
    
    // get event time
    static void getEventAlarmTime(
            const srv_tdl_event_struct *event, // [IN]	: event pointer
            MYTIME *almTime                 // [OUT]	: the result alarm time
            );

private:
    void initEventView();
    
#ifdef __MMI_TASK_APP__
    void initTaskView();
#endif
    void displayErrorPopup(void);

public:
    VcpTextView *m_multilineView;
    srv_tdl_vcal_enum m_vcalType;
    void *m_data;
    VfxWChar *m_multiViewString;
    VAPP_CAL_VIEW_DETAIL_EXT_FROM_APP_ENUM m_appType;
    VfxWChar *m_filePath;
    
};

#endif
#endif /* __VAPP_CAL_VIEW_DETAIL_EXT_H__ */

