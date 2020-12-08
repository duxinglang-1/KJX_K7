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
 *  vapp_sms_setting_content.cpp
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
#include "MMI_features.h"

#ifdef __MMI_MESSAGES_TEMPLATE__

#include "vapp_text_template_core.h"
#include "vapp_sms_notifier_core.h"
#include "mmi_rp_app_vapp_sms_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
#ifdef __cplusplus
}
#endif

//static VfxWeakPtr <SmsTemplateList> templateListPtr = NULL;

/***************************************************************************** 
 * Class SmsTemplateList
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("SmsTemplateList", SmsTemplateList, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(SmsTemplateList);

SmsTemplateList::SmsTemplateList():
	m_initDone(VFX_FALSE),
    m_listSize(0)    
{
/*
    VfxU16 index;

    for (index = 0; index < SRV_SMS_TEMPLATE_TOTAL_NUM; index++)
    {
        m_contentList[index] = NULL;
    }*/
}

void SmsTemplateList::onInit()
{
    m_listSize = srv_sms_template_get_list_size();

    //templateListPtr = this;

    VfxU16 index;
    for (index = 0; index < m_listSize; index++)
    {
        //VFX_ALLOC_MEM(m_contentList[index], VAPP_SMS_TEMPLATE_SHORTCUT_CONTENT_BUFF_LEN, this);
        VfxU16 template_id = srv_sms_template_get_id(index);
        srv_sms_template_read(template_id, (WCHAR *)m_contentList[index], VAPP_SMS_TEMPLATE_SHORTCUT_CONTENT_BUFF_LEN);
    }

    SmsListener *listener = VFX_OBJ_GET_INSTANCE(SmsListener);
    listener->m_signalTextTemplateAdd.connect(this, &SmsTemplateList::onHandleAddTemplate);
    listener->m_signalTextTemplateDel.connect(this, &SmsTemplateList::onHandleDelTemplate);

    onInitDone();
}

void SmsTemplateList::onDeinit()
{
    VfxU16 index;

   /* for (index = 0; index < SRV_SMS_TEMPLATE_TOTAL_NUM; index++)
    {
        if (m_contentList[index] != NULL)
        {
            VFX_FREE_MEM(m_contentList[index]);
            m_contentList[index] = NULL;
        }
    }*/

    SmsListener *listener = VFX_OBJ_GET_INSTANCE(SmsListener);
    listener->m_signalTextTemplateAdd.disconnect(this, &SmsTemplateList::onHandleAddTemplate);
    listener->m_signalTextTemplateDel.disconnect(this, &SmsTemplateList::onHandleDelTemplate);
}


void SmsTemplateList::onInitDone()
{
    //if (templateListPtr->isValid())
    //{
        m_initDone = VFX_TRUE;
        m_signalInitDone.emit(this, VFX_TRUE);
    //}

    //templateListPtr = NULL;
}

void SmsTemplateList::onHandleAddTemplate(VfxU16 templateId, VfxU16 listIndex)
{
    m_listSize = srv_sms_template_get_list_size();

    VFX_ASSERT(m_listSize >= 1);

    //templateListPtr = this;

    //if (m_contentList[m_listSize-1] == NULL)
    //{
        //VFX_ALLOC_MEM(m_contentList[m_listSize-1], VAPP_SMS_TEMPLATE_SHORTCUT_CONTENT_BUFF_LEN, this);
    //}

    VfxU16 index;

    for (index = m_listSize-1; index > listIndex; index--)
    {
        memcpy(m_contentList[index], m_contentList[index-1], VAPP_SMS_TEMPLATE_SHORTCUT_CONTENT_BUFF_LEN);
    }

    VfxU16 template_id = srv_sms_template_get_id(listIndex);
    srv_sms_template_read(template_id, (WCHAR *)m_contentList[listIndex], VAPP_SMS_TEMPLATE_SHORTCUT_CONTENT_BUFF_LEN);

    m_signalAddTemplate.emit(this, templateId, listIndex);
}

void SmsTemplateList::onHandleDelTemplate(VfxU16 templateId, VfxU16 listIndex)
{
    m_listSize = srv_sms_template_get_list_size();

    //templateListPtr = this;

    VfxU16 index;
    for (index = listIndex; index < m_listSize; index++)
    {
        memcpy(m_contentList[index], m_contentList[index+1], VAPP_SMS_TEMPLATE_SHORTCUT_CONTENT_BUFF_LEN);
    }
	/*
    if (m_contentList[index] != NULL)
    {
        VFX_FREE_MEM(m_contentList[index]);
        m_contentList[index] = NULL;
    }*/

    m_signalDelTemplate.emit(this, templateId, listIndex);
}

const VfxWChar* SmsTemplateList::getContent(VfxU16 listIndex)
{
    VfxU16 template_id = srv_sms_template_get_id(listIndex);

    srv_sms_template_read(template_id, m_curContent, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1)*ENCODING_LENGTH);

    return m_curContent;
}

const VfxWChar* SmsTemplateList::getContentShortcut(VfxU16 listIndex)
{
    return (const VfxWChar*)m_contentList[listIndex];
}

VfxU16 SmsTemplateList::getListSize()
{
    return m_listSize;
}

VfxU16 SmsTemplateList::getTemplateId(VfxU16 listIndex)
{
    return srv_sms_template_get_id(listIndex);
}

VfxU16 SmsTemplateList::getListIndex(VfxU16 templateId)
{
    return srv_sms_template_get_list_index(templateId);
}

VfxBool SmsTemplateList::onDelete(VfxU16 templateId)
{
    return srv_sms_template_delete(templateId)? VFX_TRUE: VFX_FALSE;
}

VfxBool SmsTemplateList::isTemplateFull()
{
    if (srv_sms_template_is_full())
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


/***************************************************************************** 
 * Class SmsTemplate
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("SmsTemplate", SmsTemplate, VfxObject);

SmsTemplate::SmsTemplate(VfxU16 templateId): // for get/save template
    m_templateId(templateId)
{
    memset(m_content, 0, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM +1)*ENCODING_LENGTH);
}

SmsTemplate::SmsTemplate(): // only for save template
    m_templateId(0xFFFF)
{
    memset(m_content, 0, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM +1)*ENCODING_LENGTH);
}

void SmsTemplate::onInit()
{
    VfxObject::onInit();
    srv_sms_template_read(m_templateId, m_content, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM +1)*ENCODING_LENGTH);
}

void SmsTemplate::onDeinit()
{
    VfxObject::onDeinit();
}

const VfxWChar* SmsTemplate::getContent()
{
    return m_content;
}

VfxBool SmsTemplate::setContent(VfxWChar *content)
{
    //wcsncpy((wchar_t*)m_content, content, SRV_SMS_TEMPLATE_MAX_CHAR_NUM);

    return VFX_TRUE;
}

VfxBool SmsTemplate::save()
{
    if (m_templateId != 0xFFFFF)
    {
        srv_sms_template_delete(m_templateId);
    }

    srv_sms_template_save(m_content,(SRV_SMS_TEMPLATE_MAX_CHAR_NUM +1)*ENCODING_LENGTH);

    return VFX_TRUE;
}

#endif //__SRV_SMS_TEMPLATE__

