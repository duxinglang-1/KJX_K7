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
 *  vapp_clog_action.h
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
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CALL_LOG_ACTION_H__
#define __VAPP_CALL_LOG_ACTION_H__
 
 
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vfx_datatype.h"
#include "vapp_clog_data_provider.h"
#include "vapp_phb_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMI_include.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "UCMGprot.h"
#include "UcmSrvGprot.h"
#include "UcSrvGprot.h"
#include "CalllogSrvGprot.h"

}
#endif

 
/***************************************************************************** 
 * Define
 *****************************************************************************/
 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VppCLogAction : public VfxControl
{
public:
    VppCLogAction() :
        m_groupId(GRP_ID_ROOT),
        m_dataSrv(NULL)
    {
    };
    VppCLogAction(srv_clog_log_struct & log);

public:
    typedef enum
    {
        DELETE_ITEM,    // delete one log item
        DELETE_MISSED,  // delete all missed call logs
        DELETE_ALL,     // delete all call logs
#ifdef __MMI_PHB_VIEW_CALLOG__
        DELETE_LOGS_FOR_ONE_CONTACT,     // delete call logs of the same one contact
#endif
        DELETE_TYPE_END_OF_ENUM
    } deleteTypeEnum;

public:
    void setLog(const srv_clog_log_struct & log);
    void setGroupId(mmi_id gid);
    void setAppScr(VfxAppScr *scr);
    void onButtonClicked(VfxObject* sender, VfxId btnID);
    void makeCall(srv_ucm_call_type_enum type);
    static void makeCallCb(mmi_ucm_after_make_call_cb_struct* cb_para);
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))	
	void sendMSG(srv_uc_sim_id specify_sim);
#endif
#ifdef __MMI_SMS_COMPOSER__

	void sendMSG(mmi_sim_enum specify_sim);

#endif


    //void sendMSG(srv_uc_sim_id specify_sim);
    void viewContact();
    void saveContact(); //refer cui_phb_save_contact_style_enum
    void editBeforeCall();
    mmi_ret onProc(mmi_event_struct *evt);
    static mmi_ret listener(mmi_event_struct * evt);
    
    void deleteConfrim(deleteTypeEnum type);
    void onDelelteConfrimButtonClicked(VfxObject* sender, VfxId buttonId);
    static VfxS32 onDeleteCbk(SRV_CLOG_HANDLE handle, S32 pid,
                                void *req_data, void *cnf_data, MMI_BOOL more, srv_clog_ret_enum ret);
    void deleteClog(SRV_CLOG_BASE_CB cbk);
    //void deleting();
    void closeMyself();

    void setDataSrv(VappCLogDataProvider * srv) {m_dataSrv = srv;};
	
#ifdef __MMI_PHB_VIEW_CALLOG__
    void deleteClogsForSamePHB(VfxObject* obj, VfxId id);
    static VfxS32 deleteClogsForSamePHBCb(
                        SRV_CLOG_HANDLE handle, 
                        VfxS32 pid,
                        void *req_data, 
                        void *cnf_data, 
                        MMI_BOOL more, 
                        srv_clog_ret_enum ret);
#endif
    
#if defined(__MMI_CM_BLACK_LIST__) && defined(__OP01__)
    void viewBlackList();
#endif

private:
    srv_clog_log_struct m_clogItem;
    deleteTypeEnum      m_deleteType;
    mmi_id              m_groupId;
    VfxAppScr           * m_scr;
    static VcpIndicatorPopup* m_indicator;
    VappCLogDataProvider *m_dataSrv;

};
 
 
 
#endif /* __VAPP_CALL_LOG_ACTION_H__ */



