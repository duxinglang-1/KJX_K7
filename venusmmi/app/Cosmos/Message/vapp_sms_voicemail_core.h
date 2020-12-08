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
 *  vapp_sms_voicemail_core.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SMS_VOICEMAIL_CORE_H__
#define __VAPP_SMS_VOICEMAIL_CORE_H__

#include "MMI_features.h"
#include "vfx_mc_include.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * Class VoicemailServerList
 *****************************************************************************/
class VoicemailServerList: public VfxObject
{
    //VFX_DECLARE_CLASS(VoicemailServerList);

public:
    VoicemailServerList(){}
    VoicemailServerList(srv_sms_sim_enum simId): m_simId(simId), m_vmCount(0){}
    const VfxWChar *getName(VfxU32 index);
    const VfxWChar *getNumber(VfxU32 index);
    VfxBool setName(const VfxWChar *name, VfxU32 index);
    VfxBool setNumber(const VfxWChar *number, VfxU32 index);
    VfxU8 getCount();

protected:
    virtual void onInit();

private:
    VfxWChar m_name[SRV_SMS_MAX_MAILBOX_NUM][SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
    VfxWChar m_number[SRV_SMS_MAX_MAILBOX_NUM][MAX_CC_ADDR_LEN + 1];
    srv_sms_sim_enum m_simId;
    VfxU8 m_vmCount;
};


/***************************************************************************** 
 * Class VoicemailServer
 *****************************************************************************/
class VoicemailServer: public VfxObject
{
    //VFX_DECLARE_CLASS(VoicemailServer);

public:
    typedef struct
    {
        srv_sms_sim_enum simId;
        VfxU8 vmIndex;
    }VoicemailServerInitData;

public:
    VoicemailServer(){}
    VoicemailServer(VoicemailServerInitData data): m_simId(data.simId), m_index(data.vmIndex){}
    const VfxWChar *getName();
    const VfxWChar *getNumber();
    VfxU8 getMaxNameLen();
    VfxU8 getMaxNumberLen();
    VfxBool saveVmServer(const VfxWChar *name, const VfxWChar *number);

protected:
    virtual void onInit();

private:
    VfxWChar m_name[SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
    VfxWChar m_number[MAX_CC_ADDR_LEN + 1];
    VfxU8 m_nameDcs;
    VfxU8 m_nameLen;
    VfxU8 m_numberLen;
#ifdef __MMI_MSG_REL4_SUPPORT__
    VfxU8 m_support_r4;
#endif /* __MMI_MSG_REL4_SUPPORT__ */
    srv_sms_sim_enum m_simId;
    VfxU8 m_index;
};

#endif /* __VAPP_SMS_VOICEMAIL_CORE_H__ */
