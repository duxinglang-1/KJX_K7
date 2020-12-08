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
 *  vapp_sms_template_core.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SMS_TEMPLATE_CORE_H__
#define __VAPP_SMS_TEMPLATE_CORE_H__
#include "MMI_features.h"

#ifdef __MMI_MESSAGES_TEMPLATE__

#include "vfx_mc_include.h"
#include "vapp_sms_util.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
#ifdef __cplusplus
}
#endif

#define VAPP_SMS_MAX_TEMPLATE           (20)
#define VAPP_SMS_MAX_PD_TEMPLATE        (10) // predefined template use resource STR, if enlarge must add String resource, minimum is 1.
#define VAPP_SMS_MAX_UD_TEMPLATE        (VAPP_SMS_MAX_TEMPLATE)
#define VAPP_SMS_MAX_TEMPLATE_LENGTH    (160)

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * Class SmsTemplate
 *****************************************************************************/
class SmsTemplate: public VfxObject
{
    //VFX_DECLARE_CLASS(SmsTemplate);

public:
    SmsTemplate(); // only for save template
    SmsTemplate(VfxU16 templateId); // for get/save template

    typedef enum
    {
        SMS_TEMPLATE_RESULT_OK,
        SMS_TEMPLATE_REACH_MAX_NUM,
        SMS_TEMPLATE_CONTENT_EXCEED,
        SMS_TEMPLATE_FAIL_CAUSE_UNKNOW,
        SMS_TEMPLATE_TOTAL
    }SmsTemplateSaveResultEnum;

public:
    const VfxWChar* getContent();
    VfxBool setContent(VfxWChar *content);
    VfxBool save(); //save new template

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxWChar m_content[SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1];
    VfxU16 m_templateId;
};


class SmsTemplateList: public VfxObject
{
    //VFX_DECLARE_CLASS(SmsTemplateList);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(SmsTemplateList);

public:
    SmsTemplateList();

    typedef enum
    {
        SMS_TEMPLATE_PRE_DEFINED = 0x01,
        SMS_TEMPLATE_USER_DEFINED = 0x02,
        SMS_TEMPLATE_TOTAL
    } SmsTemplateTypeEnum;

public:
    const VfxWChar* getContent(VfxU16 listIndex);
    const VfxWChar* getContentShortcut(VfxU16 listIndex);
    VfxU16 getListSize();
    VfxU16 getTemplateId(VfxU16 listIndex);
    VfxU16 getListIndex(VfxU16 templateId);
    VfxBool onDelete(VfxU16 templateId);
    VfxBool isTemplateFull();

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void onInitDone();
    void onHandleAddTemplate(VfxU16 templateId, VfxU16 listIndex);
    void onHandleDelTemplate(VfxU16 templateId, VfxU16 listIndex);

public:
    VfxSignal2<VfxObject*, //sender
        VfxBool // result
        > m_signalInitDone;

    VfxSignal3<VfxObject*, //sender
        VfxU16, // template ID
        VfxU16  // template list index
        > m_signalAddTemplate;

    VfxSignal3<VfxObject*, //sender
        VfxU16, // template ID
        VfxU16  // template list index
        > m_signalDelTemplate;

private:
    #define VAPP_SMS_TEMPLATE_SHORTCUT_CONTENT_BUFF_LEN  ((SRV_SMS_TEMPLATE_MAX_CHAR_NUM+1)*ENCODING_LENGTH)

    VfxBool m_initDone;
    VfxWChar m_contentList[SRV_SMS_TEMPLATE_TOTAL_NUM][SRV_SMS_TEMPLATE_MAX_CHAR_NUM+1];
    VfxU16 m_listSize;
    VfxWChar m_curContent[SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1];
};

#endif //__SRV_SMS_TEMPLATE__

#endif /* __VAPP_SMS_TEMPLATE_CORE_H__ */

