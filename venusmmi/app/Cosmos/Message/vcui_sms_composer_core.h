/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vcui_sms_composer_core.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author: Keyu Xiang
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SMS_COMPOSER_CORE_H__
#define __VCUI_SMS_COMPOSER_CORE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_SMS_COMPOSER__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_uc_include.h"

#include "custom_phb_config.h"

#include "vcui_sms_composer_gprot.h"

extern "C"
{
    #include "SmsSrvGProt.h"
    #include "UmSrvDefs.h"
    #include "PhbSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
 // TODO: check how many text num sms support 

#define VCUI_SMS_COMPOSER_MAX_ADDRESS_NUM 20 
//#define VCUI_SMS_COMPOSER_MAX_TEXT_BUFFER_SIZE  670  //#define UC_MAX_SMS_CONTENT 670
#define VCUI_SMS_COMPOSER_MAX_TEXT_BUFFER_SIZE (160 * (SRV_SMS_MAX_SEG) )  //max 1280

#define VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN MMI_PHB_NUMBER_LENGTH  //#define SRV_UC_MAX_PHONE_NUMBER_LEN

#define VCUI_SMS_COMPOSER_MAX_TEXT_CHAR_SIZE (VCUI_SMS_COMPOSER_MAX_TEXT_BUFFER_SIZE * ENCODING_LENGTH + ENCODING_LENGTH)
#define VCUI_SMS_COMPOSER_MAX_ADDR_CHAR_SIZE (VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN * ENCODING_LENGTH + ENCODING_LENGTH)


/* Max Email length UC supports. */
//#define VCUI_SMS_COMPOSER_MAX_EMAIL_LEN (MMI_EMAIL_MAX_ADDR_LEN)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef enum
{
    VCUI_SMS_COMPOSER_LOADING_DATA_DONE,
    VCUI_SMS_COMPOSER_SENDING_SMS_DONE,
    VCUI_SMS_COMPOSER_SAVING_SMS_DONE,
    VCUI_SMS_COMPOSER_SIM_REFRESH,
    //VCUI_SMS_COMPOSER_FORCE_UPDATE,
    VCUI_SMS_COMPOSER_NEED_CLOSE_APP
} VcuiSmsComposerRefreshTypeEnum;

typedef enum
{
    VCUI_SMS_COMPOSER_RESULT_OK = 0,
        
    //VCUI_SMS_COMPOSER_RESULT_ERROR_FORCE_UPDATE,
    //VCUI_SMS_COMPOSER_RESULT_SIM_CHANGE,
    
    // Parameter check errors
    VCUI_SMS_COMPOSER_RESULT_RECIPIENT_INDEX_OVERFLOW,
    VCUI_SMS_COMPOSER_RESULT_ADDR_BUF_NOT_ENOUGH,
    VCUI_SMS_COMPOSER_RESULT_NO_RECIPIENT,
    
    //entry error
    VCUI_SMS_COMPOSER_RESULT_NUM_CANNOT_BE_EMPTY, //STR_ID_VAPP_UC_NUM_CANNOT_BE_EMPTY_ID 
    VCUI_SMS_COMPOSER_RESULT_INVALID_RECIPIENT,   //STR_ID_VAPP_UC_INVALID_RECIPIENT
    VCUI_SMS_COMPOSER_RESULT_NUMBER_LENGTH_EXCEED, //STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID
    VCUI_SMS_COMPOSER_RESULT_REACH_MAX_RECIPIENT,    //STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID
    
    // Sending errors
    VCUI_SMS_COMPOSER_RESULT_SEND_FAIL_NOT_SUPPORT_FORGROUND_SEND,

    // Sending and Saving errors
    VCUI_SMS_COMPOSER_RESULT_MEM_FULL,            //STR_GLOBAL_MEMORY_FULL
    VCUI_SMS_COMPOSER_RESULT_INSUFFIENT_MEMORY,   //STR_GLOBAL_NOT_ENOUGH_MEMORY
    VCUI_SMS_COMPOSER_RESULT_INVALID_NUMBER,      //STR_GLOBAL_INVALID_NUMBER
    VCUI_SMS_COMPOSER_RESULT_MSG_SIZE_EXCEED,     //STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID
    VCUI_SMS_COMPOSER_RESULT_ERROR_UNKNOWN_REASON //STR_GLOBAL_ERROR
    
} VcuiSmsComposerResultEnum;

typedef enum
{
    VCUI_SMS_COMPOSER_STATE_NONE,
    VCUI_SMS_COMPOSER_STATE_INSERT_ADDRESS,
    VCUI_SMS_COMPOSER_STATE_INSERT_VCARD,
    VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NUM,
    VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NAME,
    VCUI_SMS_COMPOSER_STATE_INSERT_TASK,
    VCUI_SMS_COMPOSER_STATE_INSERT_EVENT,
    VCUI_SMS_COMPOSER_STATE_TOTAL
}VcuiSmsComposerPbCuiState;

/* UCE text info structure */
typedef struct
{
    VfxU16 char_count;             /* Total Character Count */
    VfxU16 utf8_msg_len;           /* Msg Len in UTF8 */
    VfxU16 extension_char_count;   /* EXT CHAR Count */
    VfxU16 UCS2_count;             /* UCS2 characters count that are not also extension characters */
} VcuiSmsComposerTextInfoStruct;

/* UCE text info structure */
typedef struct
{
    VcuiSmsComposerOperationEnum operation;             /* Total Character Count */
    //VfxU32 msg_id;  
    mmi_sim_enum sim_id;
    
#ifndef __SRV_SMS_MULTI_ADDR__
    VfxS16 curr_send_number;
#endif
    SMS_HANDLE send_handle; /* only usefull in foreground send */

    VfxU32 existed_msg_id;   /* for get sms content only */
    VfxBool busyGettingData; /* for get sms content only */
    srv_sms_msg_data_struct* msg_data; /* for get sms content only */
    VfxWChar* contentBuff;   /* for get sms content only */
    VfxS32 contentBuffSize;  /* for get sms content only */
    VfxBool isCloseApp; /* for get sms content only */

    VfxBool isTakenPrefSimFromPhb; /* prefer sim */
    VfxS16 currSetPreferSim;
    VfxU32 sendResult;
    
} VcuiSmsComposerContextStruct;



/******************************************************************************/
/*                          Class VcuiSmsComposerData                             */
/******************************************************************************/
class VcuiSmsComposerData : public VfxObject
{
    VFX_DECLARE_CLASS(VcuiSmsComposerData);

public:
// Constructor
    VcuiSmsComposerData();

// Method

    // set entry data, return true means data is ready, other wise UI need to wait for event then can update the UI
    VcuiSmsComposerResultEnum setEntryData(VcuiSmsComposerEntryStruct *entryData);

    // UI level try to store a single addres in data level, return true means recipient is added to data level successfully,
    // other wise  it means the address is invalid. But, no matter what it returns UI need to update
    VcuiSmsComposerResultEnum addRecipient (VfxWChar *textAddr);
    VcuiSmsComposerResultEnum deleteRecipient (VfxWChar *textAddr);
    VcuiSmsComposerResultEnum deleteRecipientByIndex (VfxWChar *textAddr, VfxS32 index);
    VcuiSmsComposerResultEnum resetRecipient ();
    VcuiSmsComposerResultEnum removeDuplicateRecipient();
    VfxS32 getRecipientNum();
    VcuiSmsComposerResultEnum getRecipient(VfxS32 index, VfxWChar *textAddr, VfxS32 bufferSize);
    VcuiSmsComposerResultEnum getRecipientBuffer(VfxS32 index, VcuiSmsComposerAddrStruct* &addr);

    /* mmi_sim_enum getSimId();
    void setSimId(mmi_sim_enum simId); */

        
    //data levle will return the buffer pointer directly, UI levlel can set this buffer into VcpTextEditor
    VfxWChar * getContentDataBuffer();

    VcuiSmsComposerTextInfoStruct* getTextInfo();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    void getTextInfoFromBuffer(const VfxChar *text_buffer, 
                                       VcuiSmsComposerTextInfoStruct *text_info);
    VcuiSmsComposerResultEnum copyEntryData(VcuiSmsComposerEntryStruct *entryData);
    void initData();

    VcuiSmsComposerResultEnum checkValidForRecipient(VcuiSmsComposerAddrStruct *addr);  
    
private:
    VcuiSmsComposerEntryStruct m_entryData;
    VfxS32 m_addrNum;                 /* Max addresses */  
    VcuiSmsComposerAddrStruct m_addr[VCUI_SMS_COMPOSER_MAX_ADDRESS_NUM];           /* Addresses linklist */
    VfxS32 m_textNum;                /* content text number */
    VfxChar m_textBuffer[VCUI_SMS_COMPOSER_MAX_TEXT_CHAR_SIZE];             /* content text buffer */
    mmi_sim_enum m_simId;
    VcuiSmsComposerTextInfoStruct m_textInfo;
};



/******************************************************************************/
/*                          Class VcuiSmsComposerDataControl                             */
/******************************************************************************/
// TODO: static ???
class VcuiSmsComposerControl : public VfxObject
{   
    public:
    // Constructor
        VcuiSmsComposerControl();

    /** SMS operations  **/
    VcuiSmsComposerResultEnum getSmsContent(VfxU32 existedMsgId,
                                                srv_sms_msg_data_struct* msg_data,
                                                VfxWChar* contentBuffer,
                                                VfxU32 contentBufferSize,
                                                SrvSmsCallbackFunc callback,
                                                void *sender_data);

    VcuiSmsComposerResultEnum sendSms(VcuiSmsComposerAddrStruct* addrBuffer,
                                          VfxS32 addr_num,  
                                          VfxWChar* contentBuffer,
                                          VfxS32 content_char_count,
                                          mmi_sim_enum simId,
                                          VfxBool isMoreMsgToSend,
                                          VfxBool isSetReplyMsgId,
                                          VfxU32 replyMsgId,
                                          SrvSmsCallbackFunc callback,
                                          void *sender_data);

    VcuiSmsComposerResultEnum saveSms(
                                      VcuiSmsComposerAddrStruct* addrBuffer,
                                      VfxS32 addr_num,  
                                      VfxWChar* contentBuffer,
                                      VfxS32 content_char_count,
                                      mmi_sim_enum simId,
                                      //VfxBool isMoreMsgToSend,
                                      //VfxBool isSetReplyMsgId,
                                      //VfxU32 replyMsgId,
                                      SrvSmsCallbackFunc callback,
                                      void *sender_data);
    
    VcuiSmsComposerResultEnum deleteSms(
                                      VfxU32 msgId,
                                      SrvSmsCallbackFunc callback,
                                      void *sender_data);
    
    VfxS32 setPreferSim(srv_phb_set_preferred_sim_req *ucPhbData);
};



/******************************************************************************/
/*                          Class VcuiSmsComposerDataProvider                             */
/******************************************************************************/
class VcuiSmsComposerDataProvider : public VfxObject
{
    VFX_DECLARE_CLASS(VcuiSmsComposerDataProvider);

public:
// Constructor
    VcuiSmsComposerDataProvider();

//interface    
    // set entry data, return true means data is ready, other wise UI need to wait for event then can update the UI
    VfxBool setEntryData(VcuiSmsComposerEntryStruct *entryData);
    void getSmsTextInfoNum(VfxS32 &remain_character, 
                                  VfxS32 &current_segment,
                                  VfxS32 &maxSmsCharCount,
                                  VfxS32 &maxSmsCharCountInOneSegment);

    // data
    VcuiSmsComposerResultEnum addRecipient (VfxWChar *textAddr);
    //VcuiSmsComposerResultEnum deleteRecipient (VfxWChar *textAddr);
    VcuiSmsComposerResultEnum deleteRecipientByIndex (VfxWChar *textAddr, VfxS32 index);
    VcuiSmsComposerResultEnum resetRecipient ();
    VfxS32 getRecipientNum();
    VcuiSmsComposerResultEnum getRecipient(VfxS32 index, VfxWChar *textAddr, VfxS32 bufferSize);
    VcuiSmsComposerResultEnum removeDuplicateEntries();
        
    mmi_sim_enum getSimId();
    void setSimId(mmi_sim_enum simId);

    VfxWChar * getContentDataBuffer();
    

    //control
    VcuiSmsComposerResultEnum sendSms();
    VcuiSmsComposerResultEnum saveSms(); 

    VcuiSmsComposerOperationEnum getOperationType();

private:
    virtual void onInit();
    virtual void onDeinit();
    static mmi_ret onCommonEvtCb(mmi_event_struct * param);
        
    static void deleteSmsRsp(srv_sms_callback_struct* callback_data);
    
    VcuiSmsComposerResultEnum sendSmsReq();
    static void sendSmsRsp(srv_sms_callback_struct* callback_data);
    void handleDataAfterSend();
    
    VcuiSmsComposerResultEnum saveSmsReq();
    static void saveSmsRsp(srv_sms_callback_struct* callback_data);    
    void handleDataAfterSave(VfxU32 cause);

    void smsErrHdlr(VfxU32 type, VfxU32 cause);


    VcuiSmsComposerResultEnum getSmsContent();

    VcuiSmsComposerResultEnum getSmsContentReq();
    static void getSmsContentRsp(srv_sms_callback_struct* callback_data);
    VcuiSmsComposerResultEnum handleDataAfterGetContent();
    
    void getPreferSim(VfxBool forceUpdateSim);
    VfxBool setPreferSim();
    static void setPreferSimRsp(srv_phb_async_op_cb_struct *AsyncPhbInfo);
        
    VcuiSmsComposerResultEnum checkNumberLength(VfxU32 type); //type = 0 send, type = 1 save
    srv_um_msg_box_enum getMsgBox(U32 msg_id);
    


public:  
    // variables
    VfxSignal2 <VcuiSmsComposerRefreshTypeEnum, VcuiSmsComposerResultEnum> m_signalRefresh;

private:
    VcuiSmsComposerContextStruct m_context;        
    VcuiSmsComposerControl *m_control;
    VcuiSmsComposerData *m_data;
};

#endif /* __MMI_SMS_COMPOSER__ */
#endif /* __VCUI_SMS_COMPOSER_H__ */

