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
 *  vapp_sms_provider.h
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
#ifndef __VAPP_SMS_PROVIDER_H__
#define __VAPP_SMS_PROVIDER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_sms_base.h"

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
class VappSmsProvider;
typedef void (*VappSmsPortRegCallback)(VfxChar* data, VfxU32 dataSize, void* userData);


/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappSmsProvider : public VfxObject
{
    //VFX_DECLARE_CLASS(VappSmsProvider);

public:
    VappSmsProvider();
    void read(VfxU16 msgID, VfxBool changeReadFlag = VFX_FALSE);
    void update(void);
	//void setParentObj(VfxObject *parent);
	//VfxBool checkParent();
    VfxBool isDataValid(void);
	void setMsgID(VfxU16 msgID);
    VfxU16 getMsgID(void);
    VfxWChar* getContent(void);
    VfxU32 getContentSize(void);
    void getTimeStatmp(VfxDateTime* timestatmp);
    srv_sms_sim_enum getSimID(void);
    srv_sms_status_enum getStatus(void);
    srv_sms_storage_enum getStorageType(void);
    srv_sms_box_enum getBoxType(void);
    VfxU16 getPID(void);
#ifdef __MMI_SMS_PORT_MSG__
    VfxU16 getDestPort(void);
#endif
    srv_sms_send_status_enum getSendStatus(void);
    srv_sms_folder_enum getFolderID(void);
#ifdef __MMI_SMS_PORT_MSG__
    VfxBool isPortRegMsg(void);
#endif
    VfxBool isNotSupportMsg(void);
    VappSmsProvider& operator = (const VappSmsProvider& rightProvider);

protected:
    virtual void onInit(void);
    virtual void onDeinit(void);

private:
    void abortRead();
    static void onReadMsgDone(srv_sms_callback_struct *callbackData);
    static mmi_ret onMsgChanged(mmi_event_struct *evt);

public:
    VfxSignal1<VfxBool> m_signalReadDone;
    VfxSignal0 m_signalMsgDeleted;
	VfxSignal0 m_signalReadAgain;
    VfxSignal0 m_signalMsgChanged;

private:
    enum
    {
        MAX_CONTENT_LEN = 3062
    };

    VfxU16 m_msgID;
    VfxBool m_changeReadFlag;

    VfxWChar *m_content;
    VfxU32 m_contentSize;

    VfxBool m_isMsgValid;
    VfxBool m_isDataValid;
    VfxBool m_isUpdate;
	VfxBool m_isReading;
	VfxBool m_needReadAgain;

    SMS_HANDLE m_currHandle;
    srv_sms_msg_data_struct *m_msgData;
	VfxObjWeakPtr m_parentPtr;
};
#ifdef __MMI_SMS_PORT_MSG__

class VappSmsPortRegEntry
{
public:
    VfxU16 m_port;
    VfxWString m_appName;
    VfxImageSrc m_appImage;
    VappSmsPortRegCallback m_callback;
    void *m_userData;
};

class VappSmsPortReg : public VfxObject
{
VFX_OBJ_DECLARE_SINGLETON_CLASS(VappSmsPortReg);

public:
    VappSmsPortReg(){};
    virtual ~VappSmsPortReg(){};
    VfxBool registerPort(
                VfxU16 port,
                VfxWString& appName,
                VfxImageSrc& appImage,
                VappSmsPortRegCallback callback,
                void* userData);
    void unregPort(VfxU16 port);
    VfxBool dispatch(VfxU16 port, VfxChar* data, VfxU32 dataSize);
    VfxBool getAppInfo(VfxU16 port, VfxWString& appName, VfxImageSrc& appImage);
    VfxBool findPort(VfxU16 port);
    VfxU16 getAppImageResId(VfxU16 port);
    const VfxWChar* getAppName(VfxU16 port);

private:
    enum
    {
        MAX_PORT_REG_NUM = 3
    };

private:
    VappSmsPortRegEntry* getEntry(VfxU16 port);

private:
    VappSmsPortRegEntry m_portTable[MAX_PORT_REG_NUM];
    VfxU16 m_total;
};

#endif /* __MMI_SMS_PORT_MSG__ */
#endif /* __VAPP_SMS_PROVIDER_H__ */

