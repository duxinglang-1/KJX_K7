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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#include "vapp_sms_voicemail_core.h"
#include "mmi_rp_app_vapp_sms_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
    #include "PhbsrvGprot.h"
	#include "wgui_categories_list.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VoicemailServerList
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VoicemailServerList", VoicemailServerList, VfxObject);

void VoicemailServerList::onInit()
{
    const srv_sms_mailbox_struct *mailbox = srv_sms_get_mailbox_setting(m_simId);

    if (mailbox->mailbox_number > SRV_SMS_MAX_MAILBOX_NUM)
    {
        m_vmCount = SRV_SMS_MAX_MAILBOX_NUM;
    }
    else
    {
        m_vmCount = mailbox->mailbox_number;
    }

    for (VfxU8 index = 0; index < m_vmCount; index++)
    {
        memcpy(m_name[index], mailbox->p_mailbox_name[index], (SRV_SMS_MAX_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH);
        memcpy(m_number[index], mailbox->p_mailbox_number[index], (MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH);
    }
}

const VfxWChar* VoicemailServerList::getName(VfxU32 index)
{
    return m_name[index];
}


const VfxWChar* VoicemailServerList::getNumber(VfxU32 index)
{
    return m_number[index];
}


VfxBool VoicemailServerList::setName(const VfxWChar *name, VfxU32 index)
{
    mmi_ucs2cpy((char *)(m_name[index]), (char *)name);
    return VFX_TRUE;
}


VfxBool VoicemailServerList::setNumber(const VfxWChar *number, VfxU32 index)
{
	mmi_ucs2cpy((char *)(m_number[index]), (char *)number);
    return VFX_TRUE;
}

VfxU8 VoicemailServerList::getCount()
{
    return m_vmCount;
}

/***************************************************************************** 
 * Class VoicemailServer
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VoicemailServer", VoicemailServer, VfxObject);

void VoicemailServer::onInit()
{
    const srv_sms_mailbox_struct *mailbox = srv_sms_get_mailbox_setting(m_simId);

    memcpy(m_name, mailbox->p_mailbox_name[m_index], (SRV_SMS_MAX_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH);
    memcpy(m_number, mailbox->p_mailbox_number[m_index], (MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH);
    m_nameDcs = mailbox->mailbox_name_dcs[m_index];
    m_nameLen = mailbox->mailbox_name_len;
    m_numberLen = mailbox->mailbox_number_len;
#ifdef __MMI_MSG_REL4_SUPPORT__
    m_support_r4 = mailbox->is_support_r4;
#endif /* __MMI_MSG_REL4_SUPPORT__ */
}

const VfxWChar* VoicemailServer::getName()
{
    return m_name;
}


const VfxWChar* VoicemailServer::getNumber()
{
    return m_number;
}


VfxU8 VoicemailServer::getMaxNameLen()
{
    return m_nameLen;
}


VfxU8 VoicemailServer::getMaxNumberLen()
{
    return m_numberLen;
}

VfxBool VoicemailServer::saveVmServer(const VfxWChar *name, const VfxWChar *number)
{
    srv_sms_mailbox_edit_struct setData;
	mmi_ucs2cpy((char *)(setData.mailbox_name), (char *)name);
    if (srv_phb_check_ucs2_character((U16*)setData.mailbox_name))
    {
        setData.mailbox_name_dcs= PHB_UCS2;
    }
    else
    {
        setData.mailbox_name_dcs = PHB_ASCII;
    }

    setData.malbox_name_len = m_nameLen;
    setData.mailbox_number_len = m_numberLen;
    setData.mailbox_index = m_index;
	mmi_ucs2cpy((char *)(setData.mailbox_address), (char *)number);
#ifdef __MMI_MSG_REL4_SUPPORT__
    setData.is_support_r4 = m_support_r4;
    setData.default_index = 0;
#endif

    srv_sms_set_setting_para(
        SRV_SMS_VOICEMAIL_NUM,
        &setData,
        m_simId,
        NULL,
        NULL);

    return VFX_TRUE;
}

