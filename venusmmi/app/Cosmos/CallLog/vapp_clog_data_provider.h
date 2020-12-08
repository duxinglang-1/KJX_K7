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
 *  vapp_clog_data_provider.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CALL_LOG_DATA_PROVIDER_H__
#define __VAPP_CALL_LOG_DATA_PROVIDER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vfx_datatype.h"
#include "vapp_phb_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMI_include.h"

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
class VappCLogDataProvider : public VfxObject
{
    friend class VppCLogAction;
public:
    //VappCLogDataProvider();
    VappCLogDataProvider(VfxU8 pageType);
    
    virtual void onInit();
    virtual void onDeinit();
    
    VfxU32 getClogCount(VfxId which_list);
    void getClogIDs(VfxId which_list);
#ifdef __MMI_CLOG_MARK_SEVERAL__
    SRV_CLOG_ID getClogIDByIdx(VfxU32 index);
#endif
	
#ifdef __MMI_PHB_VIEW_CALLOG__
    void getClogIDsWithSamePHB(VfxU16 storeIndex); // get all logs of the same contact
#endif
    VfxU32 getClogNum() {return m_index;}; // for Same PHB
    
    VfxS32 getClogByID(SRV_CLOG_ID log_id, srv_clog_log_struct &log);
    SRV_CLOG_ID getClogByIdx(VfxU32 idx, srv_clog_log_struct &log, VfxS32 &get_ret);

    void clearUnreadMissedCount() const;

    void regListener();
    void deregListener();
    static mmi_ret listener(mmi_event_struct* evt);
    
private:

    void processClogChanged() const;
    
    void processClogChanged(void *evt) const;
  
#ifdef __MMI_PHB_VIEW_CALLOG__  
    void createCLogInstance(VfxId which_list, SRV_CLOG_HANDLE &hdlr) const;

    static VfxS32  getClogIDsWithSamePHBCb(
                        SRV_CLOG_HANDLE handle,
                        VfxS32 pid, 
                        void *req_data,
                        void* cnf_data, 
                        MMI_BOOL more,
                        srv_clog_ret_enum ret);
#endif
    
public:
    VfxSignal0 m_signalGetClogCbDone; // for the same contact log info
    VfxSignal1 <void *> m_signalClogUpdated; // for the same contact log info
    VfxBool       m_isUpdating;   // for async get clog ids for same contact
    
private:    
    VfxU8         m_currPageType; // VappCLogList::CLogPageTypeEnum
    VfxU32        m_index;        // total count of logs for same contact
    SRV_CLOG_ID   m_logIDs[SRV_CLOG_LOG_MAX_NUM];
    VfxU32        m_deletingIndex; //  for Delete call logs with same PHB,contact
};


class VappCLogUtils : public VfxObject
{
public:
    struct myTimeStruct
    {
        U16 Hour;
        U8 Min;
        U8 Sec;
    };
    
    void convertUTC2DT(const VfxU32 &timestamp, VfxDateTime &logTime) const;
	
#ifdef __MMI_CLOG_CALL_TIME__
    void convertUTC2Duration(const VfxU32 &dur_sec, VfxWString &dur_str, VfxU8 log_type) const;
#endif
    //void timestamp2string(const VfxU32 &timestamp, VfxWString &str) const;
  //VfxBool VappCLogUtils::isToday(const VfxU32 &timestamp) const;
    
    // convert call time, e.g. 76->00:01:16
#ifdef __MMI_CLOG_CALL_TIME__
    void sec2mytime(const VfxU32 &dur_sec, VfxWString &myTime, VfxU8 log_type) const;
#endif /* __MMI_CLOG_CALL_TIME__ */

};




#endif /* __VAPP_CALL_LOG_DATA_PROVIDER_H__ */



