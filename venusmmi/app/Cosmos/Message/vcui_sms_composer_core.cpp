/*  Copyright Statement:
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vcui_sms_composer_core.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_SMS_COMPOSER__

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_rp_app_cosmos_global_def.h"
//#include "mmi_rp_vapp_unifiedcomposer_def.h"

#ifdef __cplusplus
}
#endif

#include "vcui_sms_composer_gprot.h"

extern "C"
{
    #include "SmsSrvGprot.h"
    #include "UmSrvStruct.h"
    #include "PhbSrvGprot.h"
    #include "FileMgrSrvGProt.h"
    #include "BootupSrvGprot.h"
}

#include "vcui_sms_composer_core.h"
#include "vcui_sms_composer_util.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Macro Implementation
 *****************************************************************************/


/***************************************************************************** 
* Function
*****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiSmsComposerData", VcuiSmsComposerData, VfxObject);

VcuiSmsComposerData::VcuiSmsComposerData():
    //m_main(NULL),
    //m_sendInfo(NULL),
    m_addrNum(0),
    m_textNum(0),
    m_simId(MMI_SIM_NONE)

{
}    

void VcuiSmsComposerData::onInit()
{
    initData();
}

void VcuiSmsComposerData::onDeinit()
{
    resetRecipient();
}

void VcuiSmsComposerData::initData()
{
    resetRecipient();   
    
    m_textNum = 0;
    vfx_sys_mem_zero(&m_textBuffer, sizeof(VfxChar) * VCUI_SMS_COMPOSER_MAX_TEXT_CHAR_SIZE );

    vfx_sys_mem_zero(&m_textInfo, sizeof(VcuiSmsComposerTextInfoStruct) );
    getTextInfoFromBuffer((const VfxChar*)getContentDataBuffer(), &m_textInfo);
}

VcuiSmsComposerResultEnum VcuiSmsComposerData::copyEntryData(VcuiSmsComposerEntryStruct *entryData)
{
    VcuiSmsComposerResultEnum result = VCUI_SMS_COMPOSER_RESULT_OK;
    
    vfx_sys_mem_zero(m_addr, sizeof(VcuiSmsComposerAddrStruct) * VCUI_SMS_COMPOSER_MAX_ADDRESS_NUM);
    if(entryData->addr && entryData->addr_num > 0)
    vfx_sys_mem_copy(m_addr , entryData->addr, sizeof(VcuiSmsComposerAddrStruct) * entryData->addr_num); 

    m_addrNum = 0;
    
    for(VfxS32 i=0; i< entryData->addr_num; i++)
    {   
        result = checkValidForRecipient(&(entryData->addr[i])); 

        if(result == VCUI_SMS_COMPOSER_RESULT_OK)
        {               
            VfxWChar *addr;
            VfxU32 len = mmi_ucs2strlen((S8*) entryData->addr[i].addr);
            VFX_ALLOC_MEM(addr, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH) , this);
            MMI_ASSERT(addr);
            //MMI_ASSERT(len <= VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN);
            len = (len <= VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN) ? len : VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN ;
            vfx_sys_mem_zero(addr, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH));
            vfx_sys_mem_copy(addr, entryData->addr[i].addr, (len * ENCODING_LENGTH));

            m_addr[m_addrNum].addr = addr;
            m_addrNum++;
        }
        else
        {
            //self->m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_NEED_CLOSE_APP); 
            resetRecipient();
            return result;
            
        }
    }

    m_textNum = entryData->text_num;
    
    if(m_textNum)
    {
        VfxU16 len = mmi_ucs2strlen((VfxChar*) (entryData->text_buffer) );
        //MMI_ASSERT(len <= VCUI_SMS_COMPOSER_MAX_TEXT_BUFFER_SIZE);
        len = (len <= VCUI_SMS_COMPOSER_MAX_TEXT_BUFFER_SIZE) ? len : VCUI_SMS_COMPOSER_MAX_TEXT_BUFFER_SIZE ;
        vfx_sys_mem_zero(m_textBuffer, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH) );
        vfx_sys_mem_copy(m_textBuffer , entryData->text_buffer, sizeof(VfxChar) * (len * ENCODING_LENGTH));
    }

    return VCUI_SMS_COMPOSER_RESULT_OK;
}
           

VcuiSmsComposerResultEnum VcuiSmsComposerData::setEntryData(VcuiSmsComposerEntryStruct *entryData)
{
    VcuiSmsComposerResultEnum result = VCUI_SMS_COMPOSER_RESULT_OK;
    
    if( NULL == entryData )
    {
        // New Message from UM
    }
    else if(entryData->operation != VCUI_SMS_COMPOSER_OPERATION_NEW )
    {
        
        // Nothing to do, VcuiSmsComposerDataProvider will trigger "get content" opreration
    }
    else
    {
        // to set data in new message case
        initData();
        result = copyEntryData(entryData);           
    }
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_DATA_SET_ENTRY_DATA, result); 
    
    return result;
}

VcuiSmsComposerResultEnum VcuiSmsComposerData::addRecipient (VfxWChar *textAddr)
{
    VfxS32 index = 0;
    if( m_addrNum >= VcuiSmsComposerUtility::getMaxRecipientCount() )
        return VCUI_SMS_COMPOSER_RESULT_REACH_MAX_RECIPIENT;
    else
        m_addrNum ++; 

    index = m_addrNum-1 ;
    VfxU16 len = mmi_ucs2strlen((VfxChar*) (textAddr) );        
    VFX_ALLOC_MEM(m_addr[index].addr, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH) , this);
    MMI_ASSERT(m_addr[index].addr);
    //MMI_ASSERT(len <= VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN);
    len = (len <= VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN) ? len : VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN ;
    vfx_sys_mem_zero(m_addr[index].addr, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH));
    vfx_sys_mem_copy(m_addr[index].addr, textAddr, (len * ENCODING_LENGTH));

	return VCUI_SMS_COMPOSER_RESULT_OK;
}

VcuiSmsComposerResultEnum VcuiSmsComposerData::deleteRecipient (VfxWChar *textAddr)
{return VCUI_SMS_COMPOSER_RESULT_OK;}
VcuiSmsComposerResultEnum VcuiSmsComposerData::deleteRecipientByIndex (VfxWChar *textAddr, VfxS32 index)
{return VCUI_SMS_COMPOSER_RESULT_OK;}

VcuiSmsComposerResultEnum VcuiSmsComposerData::resetRecipient ()
{
    for(VfxS32 i=0;i<m_addrNum;i++)
    {
        VFX_FREE_MEM(m_addr[i].addr);
    }
    m_addrNum= 0;
    vfx_sys_mem_zero(&m_addr, sizeof(VcuiSmsComposerAddrStruct) * VCUI_SMS_COMPOSER_MAX_ADDRESS_NUM );
    return VCUI_SMS_COMPOSER_RESULT_OK;
}

VcuiSmsComposerResultEnum VcuiSmsComposerData::removeDuplicateRecipient()
{
    VcuiSmsComposerAddrStruct* addrBufferNew = NULL; 
    VfxS32 addrNumNew = 0;

    VFX_ALLOC_MEM(addrBufferNew, sizeof(VcuiSmsComposerAddrStruct) * m_addrNum, this);
    vfx_sys_mem_zero(addrBufferNew, sizeof(VcuiSmsComposerAddrStruct) * m_addrNum);
    
    for (VfxS32 i=0; i< m_addrNum; i++)
    {
        VfxBool isDuplicate = VFX_FALSE;
        VfxWChar *addr1 = m_addr[i].addr;
        MMI_ASSERT(addr1);
        
        for (VfxS32 j=0; j< addrNumNew; j++)
        {
            
            VfxWChar *addr2 = addrBufferNew[j].addr;            
            MMI_ASSERT(addr2);            
            if (srv_phb_compare_number(addr1, addr2) == MMI_FALSE)
            {
                
                isDuplicate = VFX_FALSE;
            }
            else
            {
                isDuplicate = VFX_TRUE;
                break;
            }
        }

        if(!isDuplicate)
        {        
            // new address
            VfxU16 len = mmi_ucs2strlen((VfxChar*) (addr1) );        
            VFX_ALLOC_MEM(addrBufferNew[addrNumNew].addr, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH) , this);
            MMI_ASSERT(addrBufferNew[addrNumNew].addr);
            len = (len <= VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN) ? len : VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN ;
            vfx_sys_mem_zero(addrBufferNew[addrNumNew].addr, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH));
            vfx_sys_mem_copy(addrBufferNew[addrNumNew].addr, addr1, (len * ENCODING_LENGTH));
            addrNumNew ++;
        }        
    }

    if(addrNumNew < m_addrNum)
    {
        resetRecipient();
        m_addrNum = addrNumNew;
        vfx_sys_mem_copy(m_addr, addrBufferNew, sizeof(VcuiSmsComposerAddrStruct) * m_addrNum);
    }
    else
    {
        for(VfxS32 i=0;i<addrNumNew;i++)
        {
            VFX_FREE_MEM(addrBufferNew[i].addr);
        }
    }
    VFX_FREE_MEM(addrBufferNew);
    
	return VCUI_SMS_COMPOSER_RESULT_OK ;
}


VfxS32 VcuiSmsComposerData::getRecipientNum()
{
    return m_addrNum;
}

VcuiSmsComposerResultEnum VcuiSmsComposerData::getRecipient(VfxS32 index, VfxWChar *textAddr, VfxS32 bufferSize)
{
    VFX_ASSERT(textAddr != NULL);

    if(index >= m_addrNum || index < 0 )
    {
        return VCUI_SMS_COMPOSER_RESULT_RECIPIENT_INDEX_OVERFLOW;
    }
    
    if(bufferSize < VCUI_SMS_COMPOSER_MAX_ADDR_CHAR_SIZE )
    {
        return VCUI_SMS_COMPOSER_RESULT_ADDR_BUF_NOT_ENOUGH;
    }
    
    vfx_sys_mem_zero(textAddr, (sizeof(VfxChar) * bufferSize));
    vfx_sys_mem_copy(textAddr , m_addr[index].addr, (sizeof(VfxChar) * VCUI_SMS_COMPOSER_MAX_ADDR_CHAR_SIZE));
    
    return VCUI_SMS_COMPOSER_RESULT_OK;
}

VcuiSmsComposerResultEnum VcuiSmsComposerData::getRecipientBuffer(VfxS32 index, VcuiSmsComposerAddrStruct* &addr)
{
    if(index >= m_addrNum || index < 0)
    {
        return VCUI_SMS_COMPOSER_RESULT_RECIPIENT_INDEX_OVERFLOW;
    }
	addr = &(m_addr[index]);

    return VCUI_SMS_COMPOSER_RESULT_OK;
}

VfxWChar* VcuiSmsComposerData::getContentDataBuffer()
{
    return (VfxWChar *)&m_textBuffer[0];
}

/* mmi_sim_enum VcuiSmsComposerData::getSimId()
{
    return m_simId;
}
void VcuiSmsComposerData::setSimId(mmi_sim_enum simId)
{
    m_simId = simId;
} */

void VcuiSmsComposerData::getTextInfoFromBuffer(const VfxChar *text_buffer, 
                                                 VcuiSmsComposerTextInfoStruct *text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_7bit_counter_struct *count_info = NULL;
    VfxS32 counter = 0;
    VfxU16 tmp_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(text_info, 0, sizeof(VcuiSmsComposerTextInfoStruct));

    text_info->char_count = mmi_ucs2strlen((VfxChar*) text_buffer);
    mmi_7bit_counter_init((U8*) text_buffer);
    count_info = mmi_7bit_counter_get_info();
    text_info->UCS2_count = count_info->ucs2_count;
    text_info->extension_char_count = count_info->gsm_ext_count;

    for (counter = 0; counter < (text_info->char_count * ENCODING_LENGTH); counter += ENCODING_LENGTH)
    {
        tmp_char = ((VfxU16) text_buffer[counter + 1] << 8) | ((VfxU8) text_buffer[counter]);
        text_info->utf8_msg_len += app_unicode_to_utf8_len(tmp_char);
    }
    mmi_7bit_counter_init((VfxU8*) text_buffer);
}

VcuiSmsComposerTextInfoStruct* VcuiSmsComposerData::getTextInfo()
{
    getTextInfoFromBuffer((const VfxChar*)getContentDataBuffer(), &m_textInfo);
    return &m_textInfo;
}

VcuiSmsComposerResultEnum VcuiSmsComposerData::checkValidForRecipient(VcuiSmsComposerAddrStruct *addr)
{
    if (mmi_ucs2strlen((S8*) addr->addr) == 0)
    {
        return VCUI_SMS_COMPOSER_RESULT_NUM_CANNOT_BE_EMPTY;
    }
    else if(addr->type != VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER)
    {
        return VCUI_SMS_COMPOSER_RESULT_INVALID_RECIPIENT;
    }
    else if ((addr->type == VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER) &&
            ( VcuiSmsComposerUtility::checkIsAsciiString((VfxU8*) addr->addr) && 
              !VcuiSmsComposerUtility::checkIsPhoneNum((VfxU8*) addr->addr)))
    {
        return VCUI_SMS_COMPOSER_RESULT_INVALID_RECIPIENT;
    }
    else if ((addr->type == VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER) &&
            (mmi_ucs2strlen((S8*) addr->addr) > VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN))
    {
        return VCUI_SMS_COMPOSER_RESULT_NUMBER_LENGTH_EXCEED;
    }
    else
    {
        return VCUI_SMS_COMPOSER_RESULT_OK;
    }    
}



VcuiSmsComposerControl::VcuiSmsComposerControl()
{
}
VcuiSmsComposerResultEnum VcuiSmsComposerControl::getSmsContent(VfxU32 existedMsgId,
                                                srv_sms_msg_data_struct* msg_data,
                                                VfxWChar* contentBuffer,
                                                VfxU32 contentBufferSize,
                                                SrvSmsCallbackFunc callback,
                                                void *sender_data)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_CONTROL_GET_SMS_CONTENT);

    VFX_ASSERT(msg_data != NULL && contentBuffer!= NULL);
    memset(msg_data, 0, sizeof(srv_sms_msg_data_struct));
    memset(contentBuffer, 0, msg_data->content_buff_size);

    msg_data->para_flag = SRV_SMS_PARA_CONTENT_BUFF;
    msg_data->content_buff_size = contentBufferSize; //160 * (SRV_SMS_MAX_SEG) * ENCODING_LENGTH;
    msg_data->content_buff = (S8*) contentBuffer;
        
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    msg_data->para_flag |= SRV_SMS_PARA_PID;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    
    srv_sms_read_msg(
        existedMsgId,
        MMI_FALSE,
        msg_data,
        callback,
        sender_data);

    return VCUI_SMS_COMPOSER_RESULT_OK;
}
VcuiSmsComposerResultEnum VcuiSmsComposerControl::sendSms(VcuiSmsComposerAddrStruct* addrBuffer,
                                      VfxS32 addr_num,  
                                      VfxWChar* contentBuffer,
                                      VfxS32 content_char_count,
                                      mmi_sim_enum simId,
                                      VfxBool isMoreMsgToSend,
                                      VfxBool isSetReplyMsgId,
                                      VfxU32 replyMsgId,
                                      SrvSmsCallbackFunc callback,
                                      void *sender_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE send_handle = NULL;
    //U8 ucs2_addr[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    //U16 addr_len;
	//U16 dest_port = 0;
    //U16 i;
    
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_handle = srv_sms_get_send_handle();
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_CONTROL_SEND_SMS, send_handle);
    
    srv_sms_set_sim_id(send_handle, SRV_SMS_MMI_SIM_TO_SMS(simId));
    srv_sms_set_send_type(send_handle, SRV_SMS_BG_SAVE_SEND);
   
    // TODO: why need to asc to ucs2 ???
    //addr_len = mmi_asc_n_to_ucs2((S8*)ucs2_addr, (S8*)addrBuffer->addr, SRV_SMS_MAX_ADDR_LEN);
    //ucs2_addr[addr_len] = '\0';
    //ucs2_addr[addr_len + 1] = '\0';
    //srv_sms_set_address(send_handle, (S8*)ucs2_addr);
    srv_sms_set_address(send_handle, (S8*)addrBuffer->addr);

#ifdef __SRV_SMS_MULTI_ADDR__
    /* support sms send group address */    
    if(addr_num>=2)
	{
    	for (VfxS32 i=1; i<addr_num; i++)
        {
    		//WCHAR append_ucs2_addr[SRV_SMS_MAX_ADDR_LEN+1] = {0,};
    		//addr_len = mmi_asc_n_to_ucs2((S8*)append_ucs2_addr, (S8*)addrBuffer[i].addr, SRV_SMS_MAX_ADDR_LEN);
    		//append_ucs2_addr[addr_len] = '\0';
    		//append_ucs2_addr[addr_len + 1] = '\0';
    		srv_sms_append_address(send_handle, (VfxWChar*)addrBuffer[i].addr, SRV_SMS_STATUS_UNSENT);
        }
    }
#else
    // nothing to do
#endif /* __SRV_SMS_MULTI_ADDR__ */

    //if (m_service_cntxt->main->state == SRV_UC_STATE_REPLY &&
    //    m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
    //    !send_info->change_in_recipient_list)
    if(isSetReplyMsgId)
    {
        srv_sms_set_reply_msg_id(send_handle, replyMsgId);
    }

    //if (m_service_cntxt->send_info->curr_send_number + 1 < m_service_cntxt->msg->to_num)
    if(isMoreMsgToSend)
    {
        srv_sms_set_mms(send_handle, MMI_TRUE);
    }
    else
    {
        srv_sms_set_mms(send_handle, MMI_FALSE);
    }
		
	srv_sms_set_content(send_handle, 
                        (VfxChar*)contentBuffer, 
                        content_char_count*ENCODING_LENGTH);
                        //m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);   
    
    srv_sms_send_msg(send_handle, callback, sender_data);

    // TODO: UCM need handle this event, will send signal to UI in response function, UI will send event to UCM                    
	//app->vappUcSendEvtToCaller(EVT_ID_CUI_SMS_COMPOSER_SMS_SENT);

    return VCUI_SMS_COMPOSER_RESULT_OK;
}

VcuiSmsComposerResultEnum VcuiSmsComposerControl::saveSms(
                                      VcuiSmsComposerAddrStruct* addrBuffer,
                                      VfxS32 addr_num,  
                                      VfxWChar* contentBuffer,
                                      VfxS32 content_char_count,
                                      mmi_sim_enum simId,
                                      //VfxBool isMoreMsgToSend,
                                      //VfxBool isSetReplyMsgId,
                                      //VfxU32 replyMsgId,
                                      SrvSmsCallbackFunc callback,
                                      void *sender_data)
{

    SMS_HANDLE save_handle = NULL;
    save_handle = srv_sms_get_save_handle();
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_CONTROL_SAVE_SMS, save_handle);
    
    srv_sms_set_sim_id(save_handle, SRV_SMS_MMI_SIM_TO_SMS(simId));

    if(addrBuffer && addr_num > 0 )
    {
        srv_sms_set_address(save_handle, (S8*)addrBuffer->addr);

    #ifdef __SRV_SMS_MULTI_ADDR__
        /* support sms send group address */    
        if(addr_num>=2)
    	{
        	for (VfxS32 i=1; i<addr_num; i++)
            {
        		srv_sms_append_address(save_handle, (VfxWChar*)addrBuffer[i].addr, SRV_SMS_STATUS_UNSENT);
            }
        }
        
    #else
        // nothing to do
    #endif /* __SRV_SMS_MULTI_ADDR__ */
    }
    
    srv_sms_set_status(save_handle, SRV_SMS_STATUS_DRAFT);
	srv_sms_set_content(save_handle, 
                (VfxChar*)contentBuffer, 
                content_char_count*ENCODING_LENGTH);
                //m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);  
    srv_sms_save_msg(save_handle, callback, sender_data);   
    return VCUI_SMS_COMPOSER_RESULT_OK;
}   

VcuiSmsComposerResultEnum VcuiSmsComposerControl::deleteSms(
                                      VfxU32 msgId,
                                      SrvSmsCallbackFunc callback,
                                      void *sender_data)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_CONTROL_DELETE_SMS);

    srv_sms_delete_msg( msgId,callback,sender_data);
    return VCUI_SMS_COMPOSER_RESULT_OK;
}

VfxS32 VcuiSmsComposerControl::setPreferSim(srv_phb_set_preferred_sim_req *ucPhbData)
{
    S32 needWaitToCloseProgress = 0;
    //srv_phb_set_preferred_sim_req* ucPhbData = NULL ; /*kuldeep_async_phb*/
    //ucPhbData = (srv_phb_set_preferred_sim_req *)kal_adm_alloc(main->mem_pool_id, sizeof(srv_phb_set_preferred_sim_req));
    ASSERT(ucPhbData);

         
    needWaitToCloseProgress = srv_phb_set_preferred_sim_ex(ucPhbData);
    //WaitAsyncPhbRspToCloseUC = TRUE ;

    //if(needWaitToCloseProgress != SRV_PHB_NOT_FOUND)
    //        break ;
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_CONTROL_SET_PREFER_SIM, needWaitToCloseProgress);

    return needWaitToCloseProgress;
 

 }

VFX_IMPLEMENT_CLASS("VcuiSmsComposerDataProvider", VcuiSmsComposerDataProvider, VfxObject);
VcuiSmsComposerDataProvider::VcuiSmsComposerDataProvider():
   m_control(NULL),
   m_data(NULL)
{
}
   
void VcuiSmsComposerDataProvider::onInit()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_ONINIT);

    VFX_OBJ_CREATE(m_data,VcuiSmsComposerData, this);
    VFX_OBJ_CREATE(m_control,VcuiSmsComposerControl, this);
    vfx_sys_mem_zero(&m_context, sizeof(VcuiSmsComposerContextStruct));
    
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_DEL_MSG, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_UNAVAILABLE, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_AVAILABLE, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
}
void VcuiSmsComposerDataProvider::onDeinit()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_ONDEINIT);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_DEL_MSG, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_UNAVAILABLE, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_AVAILABLE, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VcuiSmsComposerDataProvider::onCommonEvtCb, getObjHandle());
    VFX_FREE_MEM(m_context.contentBuff);
    VFX_FREE_MEM(m_context.msg_data);
    
}

mmi_ret VcuiSmsComposerDataProvider::onCommonEvtCb(mmi_event_struct * param)
{
    VcuiSmsComposerDataProvider *self = (VcuiSmsComposerDataProvider *)VfxObject::handleToObject((VfxObjHandle)param->user_data);

    if(self)
    {
        //MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "%s", self->getClassInfo()->getClassName());
        //MMI_TRACE(TRACE_GROUP_6, TRC_MMI_VAPP_MSG_UM_SRV_EVT, param->evt_id, self);
        VfxBool isNeedCloseApp = VFX_FALSE;
        VfxBool isNeedRefeshSim = VFX_FALSE;          

        switch (param->evt_id)
        {
            case EVT_ID_SRV_SMS_DEL_MSG:
            {
                srv_sms_event_struct *sms_event_data = (srv_sms_event_struct *) param;
                srv_sms_event_delete_struct *event_info = (srv_sms_event_delete_struct*)sms_event_data->event_info;
                if(event_info->msg_id == self->m_context.existed_msg_id)
                   isNeedCloseApp =  VFX_TRUE;
                break;
            }
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(srv_sms_get_msg_storage_type(m_context.existed_msg_id)== SRV_SMS_STORAGE_TCARD)
                    isNeedCloseApp =  VFX_TRUE;
            #endif
                break;
            }
            case EVT_ID_SRV_SIM_CTRL_UNAVAILABLE:
            case EVT_ID_SRV_SIM_CTRL_AVAILABLE:
            {
                if(srv_bootup_is_booting())
                    return MMI_RET_OK;
                isNeedCloseApp = VFX_TRUE;
                break;
            }
            case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
            {
                isNeedRefeshSim = VFX_TRUE;
            }
            default:
                break;
        }


        if(isNeedCloseApp)
        {   
            if(self->m_context.busyGettingData)
            {
               self->m_context.isCloseApp = VFX_TRUE;
            }
            else
            {
                self->m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_NEED_CLOSE_APP, VCUI_SMS_COMPOSER_RESULT_OK);    //VCUI_SMS_COMPOSER_RESULT_ERROR_FORCE_UPDATE
            }
        }
        else if(isNeedRefeshSim)
        {
            self->m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_SIM_REFRESH, VCUI_SMS_COMPOSER_RESULT_OK);    //VCUI_SMS_COMPOSER_RESULT_ERROR_FORCE_UPDATE
        }
        
        VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_EVT_HDLR, param->evt_id, 
            isNeedCloseApp, isNeedRefeshSim, self->m_context.busyGettingData);
    }

    return MMI_RET_OK;

}

VfxBool VcuiSmsComposerDataProvider::setEntryData(VcuiSmsComposerEntryStruct *entryData)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SET_DATA_BEGIN, 
        m_context.busyGettingData, NULL == entryData);

    // UI should wait until loading done if busyGettingData == VFX_TRUE;
    if(m_context.busyGettingData)
        return VFX_TRUE;       

    // set addr data and text data
    VfxS16 error;
    U8 get_sim_id = 0;
    ReadValue(NVRAM_VCUI_SMS_COMPOSER_PREFER_SIM, &get_sim_id, DS_BYTE, &error);
    mmi_sim_enum nvram_sim_id = (mmi_sim_enum)get_sim_id ;                   

    if(NULL == entryData)
    {
        // New Message from UM
    }
    else
    {            
        m_context.operation = entryData->operation;
        //m_context.sim_id = entryData->sim_id;        
        setSimId(entryData->sim_id);
        //m_context.existed_msg_id = entryData->msg_id;
        
        switch(entryData->operation)
        {
            case VCUI_SMS_COMPOSER_OPERATION_NEW:
            {                               
                VcuiSmsComposerResultEnum result = m_data->setEntryData(entryData);
                getPreferSim(VFX_FALSE);
                
                if(result == VCUI_SMS_COMPOSER_RESULT_OK)
                {
                    m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_LOADING_DATA_DONE, result);                
                }
                else
                {
                    m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_NEED_CLOSE_APP, result);
                }
                   
                break;
            }
            case VCUI_SMS_COMPOSER_OPERATION_REPLY:
            case VCUI_SMS_COMPOSER_OPERATION_FORWARD:
            case VCUI_SMS_COMPOSER_OPERATION_EDIT:
                
                //VFX_ASSERT(entryData->sim_id);
                m_context.existed_msg_id = entryData->msg_id;
                // get data from service
                getSmsContent();
                
                m_context.busyGettingData = VFX_TRUE;
                break;
            default:
                break;
        }
    }

    if( m_context.sim_id == MMI_SIM_NONE  && (nvram_sim_id & VcuiSmsComposerUtility::getValidSim()))
    {
        // m_context.sim_id = nvram_sim_id;
        setSimId(nvram_sim_id);
    }        

    if(m_context.sim_id == MMI_SIM_NONE)
    {
        // m_context.sim_id = VcuiSmsComposerUtility::getCurrSim();        
        setSimId(VcuiSmsComposerUtility::getCurrSim());
    }
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SET_DATA_END,
        m_context.busyGettingData, m_context.sim_id);
    
    return m_context.busyGettingData;
}

void VcuiSmsComposerDataProvider::getSmsTextInfoNum(VfxS32 &remain_character, 
                                                          VfxS32 &current_segment,
                                                          VfxS32 &maxSmsCharCount,
                                                          VfxS32 &maxSmsCharCountInOneSegment)
{
    remain_character = 0;
    current_segment = 0;
    VcuiSmsComposerTextInfoStruct *text_info = m_data->getTextInfo();

    remain_character = (U32)srv_sms_get_last_segment_remaining(
                    text_info->UCS2_count,
                    text_info->char_count,
                    text_info->extension_char_count);

    current_segment = (U32)srv_sms_get_sms_segment_number(
                    text_info->UCS2_count,
                    text_info->char_count,
                    text_info->extension_char_count);

    if (current_segment == 0 &&
        srv_sms_get_last_segment_remaining(
                    text_info->UCS2_count,
                    text_info->char_count,
                    text_info->extension_char_count) == 0)
    {
        // TODO: why limit to 4 segment
        current_segment = SRV_SMS_MAX_SEG;
    }

    if (text_info->UCS2_count > 0)
    {
        //VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_UCS2_TEXT_SIZE_EXCEED);
        maxSmsCharCount = srv_sms_get_usable_text_len(SMSAL_UCS2_DCS) / 2 ;
        
    }
    else
    {
    //VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_ASCII_TEXT_SIZE_EXCEED);
        maxSmsCharCount = srv_sms_get_usable_text_len(SMSAL_DEFAULT_DCS) / 2 - text_info->extension_char_count;
    }
    
    if(current_segment==1)
    {
        if (text_info->UCS2_count > 0)
        {
            maxSmsCharCountInOneSegment = 70;        
        }
        else
        {
            maxSmsCharCountInOneSegment = 160;
        }
    }
    else  
    {
        maxSmsCharCountInOneSegment = maxSmsCharCount / SRV_SMS_MAX_SEG; 
    }
        
	return;
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::addRecipient (VfxWChar *textAddr)
{
    VcuiSmsComposerResultEnum result = m_data->addRecipient(textAddr);
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_ADD_RECIPIENT, result);

    if(result == VCUI_SMS_COMPOSER_RESULT_OK)
    {
        getPreferSim(VFX_TRUE);

        m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_SIM_REFRESH, VCUI_SMS_COMPOSER_RESULT_OK);    //VCUI_SMS_COMPOSER_RESULT_ERROR_FORCE_UPDATE
    }
    
    return result;
}

//VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::deleteRecipient (VfxWChar *textAddr)
//{
//    return m_data->deleteRecipient(textAddr);
//}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::deleteRecipientByIndex (VfxWChar *textAddr, VfxS32 index)
{
    VcuiSmsComposerResultEnum result = m_data->deleteRecipientByIndex(textAddr, index);
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_DELETE_RECIPIENT, result, index);

    return result;
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::resetRecipient ()
{
    VcuiSmsComposerResultEnum result = m_data->resetRecipient();
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_RESET_RECIPIENT, result);

    return result;
}

VfxS32 VcuiSmsComposerDataProvider::getRecipientNum()
{
    return m_data->getRecipientNum();
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::getRecipient(VfxS32 index, 
                                                        VfxWChar *textAddr, 
                                                        VfxS32 bufferSize)
{
    return m_data->getRecipient(index,textAddr,bufferSize);
}

mmi_sim_enum VcuiSmsComposerDataProvider::getSimId()
{
    //return m_data->getSimId();
    return m_context.sim_id;
}

void VcuiSmsComposerDataProvider::setSimId(mmi_sim_enum simId)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SET_SIMID, m_context.sim_id, simId);  

    //m_data->setSimId(simId);
    m_context.sim_id = simId;
}

void VcuiSmsComposerDataProvider::getPreferSim(VfxBool forceUpdateSim)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_GET_RREFER_SIM, forceUpdateSim, 
        m_context.sim_id, m_context.isTakenPrefSimFromPhb);

    if(!forceUpdateSim && (m_context.sim_id != MMI_SIM_NONE))
    {
        return;
    }
        
    if(VFX_FALSE == m_context.isTakenPrefSimFromPhb)
    {
        // get prefer sim from phone book
        VfxS32  addr_num = m_data->getRecipientNum();
        VcuiSmsComposerAddrStruct* addr = NULL;
        m_data->getRecipientBuffer(0, addr);
            
        for(VfxS32 i=0; i<addr_num; i++)
        {
            if(addr->type == VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER)
            {
                mmi_sim_enum sim_id = MMI_SIM_NONE;
                srv_phb_get_preferred_sim( (U16 *) addr->addr,
                                            MMI_PHB_INVALID_CONTACT_ID,
                                            SRV_PHB_NUMBER_OP_TYPE_MESSAGE,
                                            &sim_id);
                                            
                VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_PHB_RREFER_SIM, sim_id, 
                    VcuiSmsComposerUtility::getValidSim());

                if(sim_id > MMI_SIM_NONE && sim_id < MMI_SIM_END_OF_ENUM)
                {    				
    				if(sim_id & VcuiSmsComposerUtility::getValidSim())
    				{  				
    					// m_context.sim_id = sim_id;    					
                        setSimId(sim_id);
                        m_context.isTakenPrefSimFromPhb = VFX_TRUE;
                        break;
    				}                    
                }
            }            
        }               
    }
}
 
 VfxBool VcuiSmsComposerDataProvider::setPreferSim()
 {
     // set prefer sim to phone book
     VfxS32  addr_num = m_data->getRecipientNum();              
     if(addr_num <= 0)
         return VFX_FALSE;
     
     VfxBool isWaitPhbCallback = VFX_FALSE;
     VfxS32 phbResult = 0;
     for(; m_context.currSetPreferSim< addr_num ; m_context.currSetPreferSim++ )
     {
        phbResult = 0;
        
        VcuiSmsComposerAddrStruct* addrBuffer = NULL;     
        m_data->getRecipientBuffer(0, addrBuffer);

        if(addrBuffer[m_context.currSetPreferSim].type == VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER)
        {
            srv_phb_set_preferred_sim_req *phbData;
            VFX_ALLOC_MEM(phbData, sizeof(srv_phb_set_preferred_sim_req), this);
            MMI_ASSERT(phbData);
            vfx_sys_mem_zero(phbData, sizeof(srv_phb_set_preferred_sim_req));
            phbData->number = addrBuffer[m_context.currSetPreferSim].addr;
            phbData->id = MMI_PHB_INVALID_CONTACT_ID ;
            phbData->sim_id = m_context.sim_id;
            phbData->op_type = SRV_PHB_NUMBER_OP_TYPE_MESSAGE ;
            phbData->cb = &VcuiSmsComposerDataProvider::setPreferSimRsp;
            phbData->user_data = (void *)getObjHandle();

            phbResult = m_control->setPreferSim(phbData);
            isWaitPhbCallback = VFX_TRUE;
            VFX_FREE_MEM(phbData);

            if(phbResult != SRV_PHB_NOT_FOUND)
			    break ;
        }
     }

     if(phbResult != SRV_PHB_NO_ERROR)
     {
         isWaitPhbCallback = VFX_FALSE;
     }

     VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SET_PREFER_SIMID, 
        isWaitPhbCallback, m_context.currSetPreferSim);  

     return isWaitPhbCallback;
     
}

void VcuiSmsComposerDataProvider::setPreferSimRsp(srv_phb_async_op_cb_struct *AsyncPhbInfo)
{
    VcuiSmsComposerDataProvider *data_provider = (VcuiSmsComposerDataProvider *)VfxObject::handleToObject((VfxObjHandle)AsyncPhbInfo->user_data);

    if(NULL == data_provider)
        return;
    
    data_provider->m_context.currSetPreferSim ++;
    VfxBool isWaitPhbCallback = data_provider->setPreferSim();

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SET_PREFER_SIMID_RSP, 
        isWaitPhbCallback, data_provider->m_context.currSetPreferSim);  

    if(!isWaitPhbCallback)
    {
        data_provider->handleDataAfterSend();
    }
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VfxWChar* VcuiSmsComposerDataProvider:: getContentDataBuffer()
{
    return m_data->getContentDataBuffer();
}


VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::sendSms()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SEND_SMS, m_data->getRecipientNum());  

    VfxS32  addr_num = m_data->getRecipientNum();
    if(addr_num<1)
        return VCUI_SMS_COMPOSER_RESULT_NO_RECIPIENT;

    VcuiSmsComposerResultEnum checkNumberLenthErr = checkNumberLength(0);
    if( checkNumberLenthErr != VCUI_SMS_COMPOSER_RESULT_OK )
        return checkNumberLenthErr; 

    m_data->removeDuplicateRecipient();
        
    VfxS16 error;
    VfxU8 set_sim_id = m_context.sim_id ;
    WriteValue(NVRAM_VCUI_SMS_COMPOSER_PREFER_SIM, &set_sim_id, DS_BYTE, &error);

#ifndef __SRV_SMS_MULTI_ADDR__ 
    m_context.curr_send_number = 0;
#endif

    return sendSmsReq();
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::sendSmsReq()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SEND_SMS_REQ, 
        m_data->getRecipientNum(), m_context.curr_send_number);  

    VfxS32  addr_num = m_data->getRecipientNum();
    
    if(addr_num <= 0)
        return VCUI_SMS_COMPOSER_RESULT_NO_RECIPIENT;
    
#ifndef __SRV_SMS_MULTI_ADDR__            
    if(m_context.curr_send_number >= 0 && m_context.curr_send_number < addr_num)
    {
#endif
        VcuiSmsComposerAddrStruct* addrBuffer = NULL;
        VfxS32  sending_num = 0;

    #ifndef __SRV_SMS_MULTI_ADDR__
        sending_num = 1;
        m_data->getRecipientBuffer(m_context.curr_send_number, addrBuffer); 
    #else
        sending_num = addr_num;
        m_data->getRecipientBuffer(0, addrBuffer);
    #endif
    
        VfxWChar* contentBuffer = m_data->getContentDataBuffer();
        VfxS32 content_char_count = m_data->getTextInfo()->char_count;
        mmi_sim_enum simId = m_context.sim_id;
    #ifndef __SRV_SMS_MULTI_ADDR__     
        VfxBool isMoreMsgToSend = (m_context.curr_send_number + 1 < addr_num);
    #else
        VfxBool isMoreMsgToSend = VFX_FALSE;
    #endif
        VfxBool isSetReplyMsgId=  (m_context.operation == VCUI_SMS_COMPOSER_OPERATION_REPLY  
                               /* && !change_in_recipient_list */ ) ;
        // TODO:  change_in_recipient_list      select a contact from 
    
        VfxU32 replyMsgId = m_context.existed_msg_id;
        void *sender_data = (void *)getObjHandle();
            
        m_control->sendSms( addrBuffer,
                            sending_num,
                            contentBuffer,
                            content_char_count,
                            simId,
                            isMoreMsgToSend,
                            isSetReplyMsgId,
                            replyMsgId,
                            &VcuiSmsComposerDataProvider::sendSmsRsp,
                            sender_data);
        
#ifndef __SRV_SMS_MULTI_ADDR__                            
    }
#endif
    return VCUI_SMS_COMPOSER_RESULT_OK;
}

void VcuiSmsComposerDataProvider::sendSmsRsp(srv_sms_callback_struct* callback_data)
{    
    MMI_BOOL result = callback_data->result;
    VfxU32 cause = (VfxU32)callback_data->cause;
    VcuiSmsComposerDataProvider *data_provider = (VcuiSmsComposerDataProvider *)VfxObject::handleToObject((VfxObjHandle)callback_data->user_data);

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SEND_SMS_RSP, result, cause);  

    if(NULL == data_provider)
        return;    
    
    /* When background sending is enabled, rsp ok just means first step(save) ok */
    if (result == MMI_TRUE)
    {
        cause = SRV_SMS_CAUSE_NO_ERROR;
    }
#ifndef __SRV_SMS_MULTI_ADDR__    
    if (cause != SRV_SMS_CAUSE_SEND_ABORT)
    {
        data_provider->m_context.curr_send_number++;
        data_provider->sendSmsReq();

        if( data_provider-> m_context.curr_send_number < data_provider->m_data->getRecipientNum())
        {
            return;
        }
    }

    // TODO: why  curr_send_number-- ???
    if (result != MMI_TRUE && cause != SRV_SMS_CAUSE_SEND_ABORT)
    {
        data_provider->m_context.curr_send_number--;
    }
#else
    //need to do nothing.
#endif

#ifndef __SRV_SMS_MULTI_ADDR__ 
    if( data_provider->m_data->getRecipientNum() != 0 && 
        data_provider->m_context.curr_send_number == data_provider->m_data->getRecipientNum())
#endif
    {
        //data_provider->m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_SENDING_SMS_DONE, 
        //                                        VCUI_SMS_COMPOSER_RESULT_OK);
    }

    data_provider->m_context.currSetPreferSim = 0;
    data_provider->m_context.sendResult = cause;
    
    VfxBool isWaitPhbCallback = data_provider->setPreferSim();

    if(!isWaitPhbCallback)
    {
        data_provider->handleDataAfterSend();
    } 
}

void VcuiSmsComposerDataProvider::handleDataAfterSend()
{
    srv_um_msg_box_enum msg_box = getMsgBox(m_context.existed_msg_id);
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_HANDLE_DATA_SEND_FINISH, msg_box);  
    
    if (msg_box == SRV_UM_MSG_BOX_DRAFT)
    {
       m_control->deleteSms(m_context.existed_msg_id,&VcuiSmsComposerDataProvider::deleteSmsRsp,(void *)getObjHandle());
    }

    if(m_context.sendResult == SRV_SMS_CAUSE_NO_ERROR)
    {
        m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_SENDING_SMS_DONE, VCUI_SMS_COMPOSER_RESULT_OK);
    }
    else
    {
        smsErrHdlr(0, m_context.sendResult);  
    }
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::saveSms()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SAVE_SMS);  

    VcuiSmsComposerResultEnum checkNumberLenthErr = checkNumberLength(1);
    if( checkNumberLenthErr != VCUI_SMS_COMPOSER_RESULT_OK )
        return checkNumberLenthErr; 

    srv_um_msg_box_enum msg_box = getMsgBox(m_context.existed_msg_id);    
    if (msg_box == SRV_UM_MSG_BOX_DRAFT)
    {
       m_control->deleteSms(m_context.existed_msg_id,&VcuiSmsComposerDataProvider::deleteSmsRsp,(void *)getObjHandle());
    } 

#ifndef __SRV_SMS_MULTI_ADDR__ 
    m_context.curr_send_number = 0;
#endif

    return saveSmsReq();
}

extern "C" void vcui_sms_composer_send_um_msg_refresh_ind(U8 msg_box, U16 msg_type)
{
    srv_um_refresh_ind_struct *refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

    refresh_ind->msg_type = SRV_UM_MSG_SMS;
    refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;
    refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
    
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*)refresh_ind, NULL);
    
    return;
}


void VcuiSmsComposerDataProvider::deleteSmsRsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VcuiSmsComposerDataProvider *data_provider = (VcuiSmsComposerDataProvider *)VfxObject::handleToObject((VfxObjHandle)callback_data->user_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(data_provider)
    {		
		vcui_sms_composer_send_um_msg_refresh_ind(
			SRV_UM_MSG_BOX_DRAFT,
			SRV_UM_MSG_SMS);
		vcui_sms_composer_send_um_msg_refresh_ind(
			SRV_UM_MSG_BOX_UNSENT,
			SRV_UM_MSG_SMS);
    }
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::saveSmsReq()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SAVE_SMS_REQ, 
        m_data->getRecipientNum(), m_context.curr_send_number);  

    VfxS32  addr_num = m_data->getRecipientNum();
    
    if(addr_num == 0)
        addr_num = 1; /* save a draft sms with none recipient*/

#ifndef __SRV_SMS_MULTI_ADDR__            
    if(m_context.curr_send_number >= 0 && m_context.curr_send_number < addr_num)
    {
#endif
        VcuiSmsComposerAddrStruct* addrBuffer = NULL;
        VfxS32  sending_num = 0;

    #ifndef __SRV_SMS_MULTI_ADDR__
        sending_num = 1;
        m_data->getRecipientBuffer(m_context.curr_send_number, addrBuffer); 
    #else
        sending_num = addr_num;
        m_data->getRecipientBuffer(0, addrBuffer);
    #endif
    
        VfxWChar* contentBuffer = m_data->getContentDataBuffer();
        VfxS32 content_char_count = m_data->getTextInfo()->char_count;
        mmi_sim_enum simId = m_context.sim_id;
        void *sender_data = (void *)getObjHandle();
            
        m_control->saveSms( addrBuffer,
                            sending_num,
                            contentBuffer,
                            content_char_count,
                            simId,
                            //isMoreMsgToSend,
                            //isSetReplyMsgId,
                            //replyMsgId,
                            &VcuiSmsComposerDataProvider::saveSmsRsp,
                            sender_data);
        
#ifndef __SRV_SMS_MULTI_ADDR__                            
    }
#endif

    return VCUI_SMS_COMPOSER_RESULT_OK ;
}

void VcuiSmsComposerDataProvider::saveSmsRsp(srv_sms_callback_struct* callback_data)
{
    MMI_BOOL result = callback_data->result;
    VfxU32 cause = (VfxU32)callback_data->cause;
    VcuiSmsComposerDataProvider *data_provider = (VcuiSmsComposerDataProvider *)VfxObject::handleToObject((VfxObjHandle)callback_data->user_data);

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_SAVE_SMS_RSP, result, cause);  

    if(NULL == data_provider)
        return;    
    
    /* When background sending is enabled, rsp ok just means first step(save) ok */
    if (result == MMI_TRUE)
    {
        cause = SRV_SMS_CAUSE_NO_ERROR;
    }
#ifndef __SRV_SMS_MULTI_ADDR__    
    if (cause != SRV_SMS_CAUSE_SEND_ABORT)
    {
        data_provider->m_context.curr_send_number++;
        data_provider->saveSmsReq();

        if( data_provider->m_context.curr_send_number >= 0 && 
            data_provider->m_context.curr_send_number < data_provider->m_data->getRecipientNum())
        {
            return;
        }
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#else
    //need to do nothing.
#endif

#ifndef __SRV_SMS_MULTI_ADDR__ 
    if( data_provider->m_data->getRecipientNum() == 0 || 
        data_provider->m_context.curr_send_number == data_provider->m_data->getRecipientNum())
#endif
    {
        data_provider->handleDataAfterSave(cause);
        
        
    }
    

}

void VcuiSmsComposerDataProvider::handleDataAfterSave(VfxU32 cause)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_HANDLE_DATA_SAVE, cause);  
    
    if(cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_SAVING_SMS_DONE, VCUI_SMS_COMPOSER_RESULT_OK);
    }
    else
    {
        smsErrHdlr(1, cause);    
    }
}

void VcuiSmsComposerDataProvider::smsErrHdlr(VfxU32 type, VfxU32 cause)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_ERROR_HDLR, type, cause);  

    VcuiSmsComposerRefreshTypeEnum signal;

    if(type == 0)
    {
        signal = VCUI_SMS_COMPOSER_SENDING_SMS_DONE;
    }
    else
    {
        signal = VCUI_SMS_COMPOSER_SAVING_SMS_DONE;
    }
    
    if (SRV_SMS_CAUSE_NO_ERROR != cause)
    {
        switch (cause)
        {
            case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
                m_signalRefresh.postEmit(signal, VCUI_SMS_COMPOSER_RESULT_INSUFFIENT_MEMORY);
                break;            
            case SRV_SMS_CAUSE_MEM_FULL:
                m_signalRefresh.postEmit(signal, VCUI_SMS_COMPOSER_RESULT_MEM_FULL);
                break;    
            case SRV_SMS_CAUSE_NUMBER_INVALID:
                m_signalRefresh.postEmit(signal, VCUI_SMS_COMPOSER_RESULT_INVALID_NUMBER);
                break;  
            case SRV_SMS_CAUSE_DATA_EXCEED:
                m_signalRefresh.postEmit(signal, VCUI_SMS_COMPOSER_RESULT_MSG_SIZE_EXCEED);
                break;
            default:
                m_signalRefresh.postEmit(signal, VCUI_SMS_COMPOSER_RESULT_ERROR_UNKNOWN_REASON);								
                break;
        }
    }
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::getSmsContent()
{
    getSmsContentReq();  
    return VCUI_SMS_COMPOSER_RESULT_OK ;
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::getSmsContentReq()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_GET_CONTENT_REQ);  
    
    srv_sms_msg_data_struct* msg_data = NULL;
    VfxWChar* contentBuff = NULL;
    VfxS32 contentBuffSize = 160 * (SRV_SMS_MAX_SEG) * ENCODING_LENGTH;
    VfxU32 existedMsgId = m_context.existed_msg_id;
    void *sender_data = (void*)getObjHandle();

    // Memory wii be freed in function getSmsContentRsp
    VFX_ALLOC_MEM(msg_data, sizeof(srv_sms_msg_data_struct) , this);            
    VFX_ALLOC_MEM(contentBuff, contentBuffSize , this);
    
    m_control->getSmsContent(existedMsgId,
                            msg_data,
                            contentBuff,
                            contentBuffSize,
                            &VcuiSmsComposerDataProvider::getSmsContentRsp,
                            sender_data);

    m_context.msg_data = msg_data;
    m_context.contentBuff = contentBuff;
    return VCUI_SMS_COMPOSER_RESULT_OK ;    
}

void VcuiSmsComposerDataProvider::getSmsContentRsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_msg_data_struct * msg_data = NULL;
    VfxWChar* contentBuff = NULL;
    VcuiSmsComposerDataProvider *data_provider = (VcuiSmsComposerDataProvider *)VfxObject::handleToObject((VfxObjHandle)callback_data->user_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_GET_CONTENT_RSP, 
        callback_data->result, data_provider->m_context.isCloseApp, data_provider->m_context.operation);  

    if(NULL == data_provider)
        return; 
    
    data_provider->m_context.busyGettingData = VFX_FALSE;
    if(data_provider->m_context.isCloseApp)
    {
        goto error_hdlr;
    }
	msg_data = (srv_sms_msg_data_struct *)(((srv_sms_read_msg_cb_struct*)callback_data->action_data)->msg_data);
    contentBuff = (VfxWChar *) msg_data->content_buff;

    VFX_ASSERT(data_provider->m_context.msg_data == msg_data);
    VFX_ASSERT(data_provider->m_context.contentBuff == contentBuff);
        
    if (callback_data->result)
    {
        if(msg_data->is_with_obj &&
            (data_provider->m_context.operation == VCUI_SMS_COMPOSER_OPERATION_FORWARD ||
            data_provider->m_context.operation == VCUI_SMS_COMPOSER_OPERATION_EDIT))
        {
            // TODO: add trace
            goto error_hdlr;
        }
	    VFX_FREE_MEM(msg_data);
        
        switch (data_provider->m_context.operation)
        {
            case VCUI_SMS_COMPOSER_OPERATION_REPLY:
            case VCUI_SMS_COMPOSER_OPERATION_FORWARD:
            case VCUI_SMS_COMPOSER_OPERATION_EDIT:
            {
                data_provider->handleDataAfterGetContent();
                break;
            }

            default:
                // TODO: add trace
                goto error_hdlr;
        }
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if(callback_data->cause == SRV_SMS_CAUSE_ARCH_FILE_NOT_EXIST)
    {
        // TODO: add trace    
        goto error_hdlr;
    }
#endif
    else
    {
        // TODO: add trace
        goto error_hdlr;
    }

    data_provider->m_context.contentBuff = NULL;
    data_provider->m_context.msg_data = NULL;
    
    return;
    
error_hdlr:
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_GET_CONTENT_ERROR);  
    VFX_FREE_MEM(contentBuff);
    data_provider->m_context.contentBuff = NULL;
    VFX_FREE_MEM(msg_data);
    data_provider->m_context.msg_data = NULL;
    data_provider->m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_NEED_CLOSE_APP, VCUI_SMS_COMPOSER_RESULT_OK);
    
    return;
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::handleDataAfterGetContent()
{   
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_CORE_PROVIDER_HANDLE_GET_CONTENT); 

    VcuiSmsComposerEntryStruct *entryData = NULL;
    VcuiSmsComposerAddrStruct *addr=NULL;  
    VfxBool needAddress = VFX_FALSE;
    VfxBool needContent = VFX_FALSE;
    VfxBool needSimid = VFX_FALSE;
    
    
    VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
    vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct));

    switch (m_context.operation)
    {
        case VCUI_SMS_COMPOSER_OPERATION_REPLY:
            needAddress = VFX_TRUE;
            needSimid = VFX_TRUE;
            break;
        case VCUI_SMS_COMPOSER_OPERATION_FORWARD:
            needContent = VFX_TRUE;
            break;
        case VCUI_SMS_COMPOSER_OPERATION_EDIT:
            needAddress = VFX_TRUE;
            needContent = VFX_TRUE;
            break;
        default:            
            break;
    }

    if(needAddress)
    {
        VfxS32 temp_addr_num = 0;
        entryData->addr_num = 0;
    #ifdef __SRV_SMS_MULTI_ADDR__        
        temp_addr_num = srv_sms_get_msg_addr_num(m_context.existed_msg_id);
        if(temp_addr_num > 1)
        {
            VFX_ALLOC_MEM(addr, sizeof(VcuiSmsComposerAddrStruct) * temp_addr_num, this);
            vfx_sys_mem_zero(addr, sizeof(VcuiSmsComposerAddrStruct) * temp_addr_num);
            
            for(VfxS32 i=0; i< temp_addr_num; i++)
            {
                VfxWChar* ucs2_addr;
                srv_sms_status_enum status;
                VFX_ALLOC_MEM(ucs2_addr, VCUI_SMS_COMPOSER_MAX_ADDR_CHAR_SIZE , this);
                vfx_sys_mem_zero(ucs2_addr, VCUI_SMS_COMPOSER_MAX_ADDR_CHAR_SIZE);
                VFX_ASSERT(VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN >= SRV_SMS_MAX_ADDR_LEN); 
    			srv_sms_get_msg_multi_addr( ucs2_addr,
                    &status,
                    m_context.existed_msg_id,
                    i);

                if (mmi_ucs2strlen((VfxChar*)ucs2_addr) > 0)
                {
                    addr[entryData->addr_num].addr = ucs2_addr;
                    entryData->addr_num++;
                }
                else
                {
                    VFX_FREE_MEM(ucs2_addr);
                }
            }

            if(entryData->addr_num > 0)
            {
                entryData->addr = addr;
            }
            else
            {
                VFX_FREE_MEM(addr);
            }
        }
        else
	#endif
        {
            temp_addr_num = 1;
            VFX_ALLOC_MEM(addr, sizeof(VcuiSmsComposerAddrStruct) * temp_addr_num, this);
            vfx_sys_mem_zero(addr, sizeof(VcuiSmsComposerAddrStruct) * temp_addr_num);
            
            VfxWChar* ucs2_addr;
            VFX_ALLOC_MEM(ucs2_addr, VCUI_SMS_COMPOSER_MAX_ADDR_CHAR_SIZE , this);
            vfx_sys_mem_zero(ucs2_addr, VCUI_SMS_COMPOSER_MAX_ADDR_CHAR_SIZE);
            VFX_ASSERT(VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN >= SRV_SMS_MAX_ADDR_LEN); 
			srv_sms_get_msg_address( m_context.existed_msg_id, (VfxChar*)ucs2_addr);
            if (mmi_ucs2strlen((VfxChar*)ucs2_addr) > 0)
            {
                addr[entryData->addr_num].addr = ucs2_addr;
                entryData->addr_num++;
            }
            else
            {
                VFX_FREE_MEM(ucs2_addr);
            }

            if(entryData->addr_num > 0)
            {
                entryData->addr = addr;
            }
            else
            {
                VFX_FREE_MEM(addr);
            }            
        }   
    }

    if(needContent)
    {
        entryData->text_buffer = (VfxWChar*)m_context.contentBuff;
        entryData->text_num = mmi_ucs2strlen((VfxChar*)m_context.contentBuff);
    }
    else
    {
        entryData->text_num = 0;
    }

    if(needSimid)
    {
        // m_context.sim_id = SRV_SMS_SMS_SIM_TO_MMI(srv_sms_get_msg_sim_id(m_context.existed_msg_id));
        setSimId(SRV_SMS_SMS_SIM_TO_MMI(srv_sms_get_msg_sim_id(m_context.existed_msg_id)));
    }
            
    VcuiSmsComposerResultEnum result = m_data->setEntryData(entryData);

    getPreferSim(VFX_FALSE);

    for(VfxS32 i=0; i< entryData->addr_num; i++)
    {
        VFX_FREE_MEM(addr[i].addr); 
    }
    VFX_FREE_MEM(addr);    
    VFX_FREE_MEM(m_context.contentBuff);
    VFX_FREE_MEM(entryData);

    if(result == VCUI_SMS_COMPOSER_RESULT_OK)
    {
        m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_LOADING_DATA_DONE, VCUI_SMS_COMPOSER_RESULT_OK);                
    }
    else
    {
        m_signalRefresh.postEmit(VCUI_SMS_COMPOSER_NEED_CLOSE_APP, result);
    }

    return VCUI_SMS_COMPOSER_RESULT_OK;
}

VcuiSmsComposerResultEnum VcuiSmsComposerDataProvider::checkNumberLength(VfxU32 type)
{
    VcuiSmsComposerResultEnum retValue = VCUI_SMS_COMPOSER_RESULT_OK;
    
    if(type == 0 || type == 1)  //send
    {
        S32 number_len;
        S32 i;

        VcuiSmsComposerAddrStruct* addrBuffer = NULL; 

        VfxS32  addr_num = m_data->getRecipientNum();
        m_data->getRecipientBuffer(0, addrBuffer);


        for ( i=0; i< addr_num && addrBuffer != NULL; i++)
        {
            number_len = mmi_ucs2strlen((VfxChar*)addrBuffer->addr);
        
            if ((number_len < SRV_SMS_MAX_ADDR_LEN) ||
                ((number_len == SRV_SMS_MAX_ADDR_LEN) && (mmi_ucs2ncmp((VfxChar*)addrBuffer->addr, (const CHAR *)(VFX_WSTR("+").getBuf()), 1) == 0)))
            {
                retValue = VCUI_SMS_COMPOSER_RESULT_OK;
            }
            else
            {
                //STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID
                retValue = VCUI_SMS_COMPOSER_RESULT_NUMBER_LENGTH_EXCEED;
                break;
            }
        }
    }

    return retValue;        
}
extern "C" srv_um_msg_box_enum vcuiSmsComposerConvertSmsBoxToUm(srv_sms_box_enum msg_box)
{
	switch(msg_box)
	{
		case SRV_SMS_BOX_NONE:
			return SRV_UM_MSG_BOX_NONE;
		case SRV_SMS_BOX_INBOX:
			return SRV_UM_MSG_BOX_INBOX;
		case SRV_SMS_BOX_OUTBOX:
            return SRV_UM_MSG_BOX_SENT;
		case SRV_SMS_BOX_DRAFTS:
			return SRV_UM_MSG_BOX_DRAFT;
        case SRV_SMS_BOX_UNSENT:
			return SRV_UM_MSG_BOX_UNSENT;
        case SRV_SMS_BOX_SIM:
            return SRV_UM_MSG_BOX_SIM;
		case SRV_SMS_BOX_ARCHIVE:
			return SRV_UM_MSG_BOX_ARCHIVE;
		default:
			return SRV_UM_MSG_BOX_DRAFT;
	}
}

srv_um_msg_box_enum VcuiSmsComposerDataProvider::getMsgBox(U32 msg_id)
{
    if (m_context.operation == VCUI_SMS_COMPOSER_OPERATION_NEW)
    {
        return SRV_UM_MSG_BOX_NONE;
    }
    else
    {
        srv_sms_box_enum msg_box_type;
        srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);
        return vcuiSmsComposerConvertSmsBoxToUm(msg_box_type);
    }
}

VcuiSmsComposerOperationEnum VcuiSmsComposerDataProvider::getOperationType()
{
    return m_context.operation;
}

#endif /* __MMI_SMS_COMPOSER__ */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UNIFIED_COMPOSER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#ifdef __MMI_SMS_COMPOSER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SMS_COMPOSER__ */
/* under construction !*/
#endif
/* under construction !*/
#endif
/* EOF */

