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
 *  vapp_sms_notifier_core.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SMS_NOTIFIER_CORE_H__
#define __VAPP_SMS_NOTIFIER_CORE_H__
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vapp_sms_util.h"
#include "vsrv_notification.h"
#include "vsrv_ncenter.h"
#include "vapp_msg_features.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
	#include "NotificationGprot.h"
#ifdef __cplusplus
}
#endif


#ifdef LOW_COST_SUPPORT
#define VAPP_SMS_MAX_CLASS0_IND_NUM      (1)
#else
#define VAPP_SMS_MAX_CLASS0_IND_NUM      (5)
#endif

#define VAPP_SMS_MSG_WAITING_LINE_NUM    (2)
#define VAPP_SMS_MAX_REPORT_NUM          (1)
#define VAPP_SMS_MAX_CLASS0_CONTENT_LEN  ((1024*3)/ENCODING_LENGTH)

enum vapp_sms_msg_waiting_type_enum
{
    VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND  = 0x00,
    VAPP_SMS_NEW_FAX_WAITING_IND        = 0x01,
    VAPP_SMS_NEW_EMAIL_WAITING_IND      = 0x02,
    VAPP_SMS_NEW_NET_MSG_WAITING_IND    = 0x03,
    VAPP_SMS_NEW_VEDIO_WAITING_IND      = 0x04,
    VAPP_SMS_MAX_MSG_WAITING_TYPE       = 0x05
};

enum vapp_msg_waiting_line_id_enum
{
    VAPP_MSG_WAITING_NOT_SUPPORT, /* not support */
    VAPP_MSG_WAITING_LINE1, /* line 1 */
    VAPP_MSG_WAITING_LINE2, /* line 2 */
    VAPP_MSG_WAITING_LINE_END /* End of the enum */
};

struct SmsWaitingMsgUserData
{
	mmi_sim_enum sim;
	vapp_msg_waiting_line_id_enum line;
	vapp_sms_msg_waiting_type_enum type;
};
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class SmsClass0NotifyManager;
class SmsMsgWaitingManager;

/***************************************************************************** 
 * Class SmsListener
 *****************************************************************************/
#ifdef __MMI_MESSAGES_TEMPLATE__
class SmsListener: public VfxObject
{
    //VFX_DECLARE_CLASS(SmsListener);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(SmsListener);

    typedef SmsListener    Self;
    typedef VfxObject      Super;

public:
    SmsListener();

protected:
    virtual void onInit();
    virtual void onDeinit();

private:

public:
    VfxSignal2 <
        VfxU16,         // template ID
        VfxU16          // template list index
    > m_signalTextTemplateAdd;

    VfxSignal2 <
        VfxU16,         // template ID
        VfxU16          //template list index
    > m_signalTextTemplateDel;
};
#endif /* __MMI_MESSAGES_TEMPLATE__ */

/***************************************************************************** 
 * Class SmsClass0
 *****************************************************************************/
class SmsClass0: public VfxObject
{
    //VFX_DECLARE_CLASS(SmsClass0);

public:
    SmsClass0();
    //SmsClass0(srv_sms_event_new_sms_struct *event_data);
    SmsClass0(const SmsClass0 &class0){}

    VfxU8 getFo();
    const VfxU8* getAddress();
    const VfxU8* getScAddress();
    VfxU32 getTimestamp();
    VfxU8 getTotalSeg();
    VfxU8 getMti();
    VfxU8 getPid();
    srv_sms_sim_enum getSimId();
    const VfxWChar* getContent();
    VfxU16 getContentLength();
    VfxU8 getContentDcs();
    void replaceData(srv_sms_event_new_sms_struct *event_data);
	VfxBool isUsed(){ return m_isUsed; }
	void setUsed(VfxBool isUsed){ m_isUsed = isUsed; }

protected:
    //void onInit(){};
    //void onDeinit();

private:
    VfxU32 m_timestamp;
    VfxU16 m_contentLength;
    VfxU8 m_fo;
    VfxU8 m_dcs;
    VfxU8 m_addr[SRV_SMS_MAX_ADDR_LEN + 1];
    VfxU8 m_scAddr[SRV_SMS_MAX_ADDR_LEN + 1];
    VfxU8 m_totalSeg;
    VfxU8 m_pid;
    VfxU8 m_mti;
	VfxBool m_isUsed;
    srv_sms_sim_enum m_simId;
    VfxWChar m_content[VAPP_SMS_MAX_CLASS0_CONTENT_LEN];
};



/***************************************************************************** 
* Class MsgNotifyManager
*****************************************************************************/
class MsgNotifyManager: public VfxObject
{
public:
	MsgNotifyManager() : m_relatedApp(NULL){}
	virtual VfxBool addNewInd(mmi_event_struct *evt) = 0;
	virtual VfxBool deleteInd(VfxU8 index) = 0;
	virtual VfxU8 getNotifyIndex() = 0;
	virtual void getContent(VfxU8 index, VfxWString &content) = 0;
	virtual void getFormatAddr(VfxU8 index, VfxWString &addr) = 0;
	virtual void getFormatTimestamp(VfxU8 index, VfxWString &timesatmp) = 0;
	virtual void notify(VfxBool isNew) = 0;
	void setRelatedApp(VfxApp *app){ m_relatedApp = app;}
	VfxApp *getRelatedApp(){ return m_relatedApp; }
	
private:
	VfxApp *m_relatedApp;
};




/***************************************************************************** 
* Class SmsClass0NotifyManager
*****************************************************************************/
class SmsClass0NotifyManager: public MsgNotifyManager
{
    //VFX_DECLARE_CLASS(SmsClass0NotifyManager);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(SmsClass0NotifyManager);

public:
    SmsClass0NotifyManager();
    virtual ~SmsClass0NotifyManager();

public:
    VfxU8 findoldest();
    void save(VfxU8 index);
    static void SaveCallback(srv_sms_callback_struct* callback_data);

    virtual VfxBool addNewInd(mmi_event_struct *evt);
    virtual VfxBool deleteInd(VfxU8 index);
    virtual VfxU8 getNotifyIndex();
    virtual void getContent(VfxU8 index, VfxWString &content);
    virtual void getFormatAddr(VfxU8 index, VfxWString &addr);
    virtual void getFormatTimestamp(VfxU8 index, VfxWString &timesatmp);
    virtual void notify(VfxBool isNew);

public:
    VfxSignal2<
        VfxBool, // result
        srv_sms_cause_enum // cause
    > m_signalClass0Saved;

protected:
	//void onInit();

private:
    SmsClass0 m_class0Provider[VAPP_SMS_MAX_CLASS0_IND_NUM];
    VfxU8 m_indNum;
};

/***************************************************************************** 
* Class SmsMsgWaitingManager
*****************************************************************************/
class SmsMsgWaitingManager: public VfxObject
{
    //VFX_DECLARE_CLASS(SmsMsgWaitingManager);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(SmsMsgWaitingManager);
public:
typedef struct{
    VfxU8 lineNo; /* Number of Line*/
    VfxU8 mspNo;
    VfxU8 waitingNum;
    VfxU8 indType;
    VfxBool isShowNum;
    VfxBool isClear;
    VfxBool isfromStorage;
}VappSmsMsgWaitingData;

typedef struct{
    VfxU8 waitingNum;
    VfxU8 indType;
    VfxBool isShowNum;
    VfxBool isValid;
}MsgWaitingData;

public:
    SmsMsgWaitingManager();

protected:
    virtual void onInit();

public:
    void addNewInd(VappSmsMsgWaitingData *info, srv_sms_sim_enum simId);
    void clearInd(VappSmsMsgWaitingData *info, srv_sms_sim_enum simId, VfxBool needCloseCell);

    VfxBool checkIsValid(mmi_sim_enum sim, vapp_msg_waiting_line_id_enum lineId, VfxU8 WaitingType);
    VfxBool checkIsShowNum(mmi_sim_enum sim, vapp_msg_waiting_line_id_enum lineId, VfxU8 WaitingType);
    VfxU8 getWaitingNum(mmi_sim_enum sim, vapp_msg_waiting_line_id_enum lineId, VfxU8 WaitingType);
	void callVoicemail();
	void setCurrentActionData(SmsWaitingMsgUserData *userData);
	void clearCells(SmsWaitingMsgUserData *data);
    void notify(mmi_sim_enum sim, //sim
        vapp_msg_waiting_line_id_enum line, // lineId
        vapp_sms_msg_waiting_type_enum type, //msg waiting type
        VfxBool isShow);
	
private:
	static void onPopupButtonClick(VfxId id, void *userData);
	void setVoicemailContent(VsrvNotificationEvent *noti, 
		mmi_sim_enum sim, //sim
        vapp_msg_waiting_line_id_enum line,
        vapp_sms_msg_waiting_type_enum type);
#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

	void setOtherWaitngMsgContent(VsrvNotificationEvent *noti, 
		mmi_sim_enum sim, //sim
        vapp_msg_waiting_line_id_enum line,
        vapp_sms_msg_waiting_type_enum type);
#endif
    VfxBool getHideFlag(mmi_sim_enum mmi_sim, VfxU8 lineNo, VfxU8 waitingType);
    void setHideFlag(mmi_sim_enum mmi_sim, VfxU8 lineNo, VfxU8 waitingType, VfxBool hideFlag);
	VsrvNotificationId getNotificationId(mmi_sim_enum sim, //sim
        vapp_msg_waiting_line_id_enum line, // lineId
        vapp_sms_msg_waiting_type_enum type);

public:
    VfxSignal4<mmi_sim_enum, //sim
        vapp_msg_waiting_line_id_enum, // lineId
        vapp_sms_msg_waiting_type_enum, //msg waiting type
        VfxBool // Show or hide in Ncenter
    > m_signalMsgWaitingStateChanged;

private:
    #define VAPP_SMS_MSG_WAITING_TYPE        (5)

    MsgWaitingData m_msgWaitingInfo[VAPP_SMS_TOTAL_SIM][VAPP_SMS_MSG_WAITING_LINE_NUM][VAPP_SMS_MAX_MSG_WAITING_TYPE];
	SmsWaitingMsgUserData m_currentActionData;
	NMGR_HANDLE m_notifyHandle[VAPP_SMS_MAX_MSG_WAITING_TYPE];
    
    VfxU8 m_indNum;
    VfxBool m_suportLine;
    VfxU64 m_hideFlag;
};

#endif /* __VAPP_SMS_NOTIFIER_CORE_H__ */
