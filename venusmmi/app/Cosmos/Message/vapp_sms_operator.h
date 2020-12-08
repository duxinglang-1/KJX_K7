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
 *  vapp_sms_operater.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SMS_OPERATOR_H__
#define __VAPP_SMS_OPERATOR_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_sms_base.h"
#include "vapp_sms_provider.h"
#include "vapp_msg_use_detail.h"
#ifdef __cplusplus
extern "C"
#endif
{
    #include "SmsSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class 
 *****************************************************************************/
enum VappSmsOpType
{
    VAPP_SMS_OP_NONE,
    VAPP_SMS_OP_REPLY,
    VAPP_SMS_OP_RESEND,
    VAPP_SMS_OP_FORWARD,
    VAPP_SMS_OP_EDIT,
    VAPP_SMS_OP_DELETE,
    VAPP_SMS_OP_COPY_FROM_PHONE,
    VAPP_SMS_OP_COPY_TO_PHONE,
    
    VAPP_SMS_OP_COPY_TO_TCARD,
    
    VAPP_SMS_OP_COPY_FROM_ARCHIVE,
    VAPP_SMS_OP_COPY_FROM_TCARD,
    VAPP_SMS_OP_USE_DETAIL,
    VAPP_SMS_OP_VIEW_DELIVERY_STATUS,
    VAPP_SMS_OP_DIAL_NUMBER,

    VAPP_SMS_OP_RESERVED
};

class VappSmsOperator : public VfxObject
{
    //VFX_DECLARE_CLASS(VappSmsOperator);

public:
    VappSmsOperator();
    virtual ~VappSmsOperator(){};

    void setParentPage(VfxPage* parentPage);
    void setProvider(VappSmsProvider* provider);
	void setLiteMode(VfxBool mode);

    void Reply(void);
    void forward(void);
    void edit(void);
    void resend(void);
    void deleteMsg(void);
    void copyFromPhone(void);
    void copyToPhone(void);
    void copyFromArchive(void);
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	void copyFromTcard();
	void copyToInbox();
#endif
#ifdef __MMI_SMS_DETAILS_INFO__	

    void useDetail(VappMsgUseDetailProvider* useDetailProvider);
#endif
#ifdef __SRV_SMS_DELIVERY_STATUS__
    void viewDeliveryStatus(void);
#endif
    void dialNumber(void);

    static VfxBool showInfoBalloonIfNeed(void);
    static VfxBool showInfoBalloonIfNeed(mmi_sim_enum simId);

private:
    void onPopupButtonClicked(VfxObject* obj, VfxId id);

    void dialNumberInt(mmi_sim_enum simId);
    VfxBool showBalloonIfCmdInvalid(void);
    void startOperation(void);

    static void onOperateDone(srv_sms_callback_struct* callbackData);
    void popupOperateResult(VfxBool result, srv_sms_cause_enum errorCause);
    VfxResId getResultStringRes(VfxBool result, srv_sms_cause_enum errorCause);
    void onCancelClicked(VfxObject* obj, VfxFloat progress);
    void showIndicatorPopup(void);
    void stopIndicatorPopup(void);
    void entryUcEditor(VappSmsOpType opType);
    static mmi_ret onCuiProc(mmi_event_struct *evt);
	void copyToSim();

private:
    enum SmsOpcmdEnum
    {
        CMD_COPY_TO_SIM1,
        CMD_COPY_TO_SIM2,
        CMD_COPY_TO_SIM3,
        CMD_COPY_TO_SIM4,
        CMD_DELETE,
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        CMD_COPY_TO_ARCHIVE,
    #endif
	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		CMD_COPY_TO_TCARD,
	#endif
		CMD_COPY_TO_SIM,
        CMD_COPY_TO_PHONE,
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        CMD_COPY_FROM_ARCHIVE,
    #endif
        CMD_DIAL_NUMBER,

        CMD_CANCEL
    };

    VappSmsProvider *m_smsProvider;
    VfxPage *m_parentPage;
    VappSmsOpType m_currOp;
    VfxId m_currCmdId;
    SMS_HANDLE m_smsHandle;

    VcpIndicatorPopup *m_indicatorPopup;
    mmi_sim_enum m_dialSimId;
	VfxBool m_isLiteMode;
};
#endif /* __VAPP_SMS_OPERATOR_H__ */

