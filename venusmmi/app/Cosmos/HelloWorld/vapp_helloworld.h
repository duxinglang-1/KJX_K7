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
 *  vapp_helloworld.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_HELLOWORLD_H__
#define __VAPP_HELLOWORLD_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "mmi_rp_vcui_helloworld_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Helloworld App 
 *****************************************************************************/
class VappHelloWorldApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappHelloWorldApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);
};

class VappHelloWorldScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappHelloWorldScreen);

// Override
public:
    virtual void on1stReady();
};


class VappHelloWorldPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappHelloWorldPage);
public:
    VappHelloWorldPage();
// Override
public:
    virtual void onInit();
protected:
    virtual mmi_ret onProc(mmi_event_struct *evt);
private:
    void onBtnClicked(VfxObject *obj, VfxId id);

    mmi_id m_cuiId;
};

/***************************************************************************** 
 * Helloworld CUI
 *****************************************************************************/

extern "C"
{
    typedef enum
    {
        EVT_ID_CUI_HELLOWORLD_BEGIN = VCUI_HELLOWORLD,
        
        EVT_ID_CUI_HELLOWORLD_RESULT, 
        
        EVT_ID_CUI_HELLOWORLD_TOTAL
    } cui_helloworld_event_enum;

    typedef struct 
    {
        MMI_EVT_GROUP_PARAM_HEADER
        
        WCHAR buffer[20];

    } cui_helloworld_result_event_struct;

    mmi_id cui_helloworld_create(mmi_id parent_id);
    void cui_helloworld_run(mmi_id cui_id);
    void cui_helloworld_close(mmi_id cui_id);

    void cui_helloworld_set_content(mmi_id cui_id, const WCHAR *content);
}

class VcuiHelloWorldCui : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiHelloWorldCui);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
// Method
public:
    void setContent(const VfxWString &value);
    const VfxWString &getContent() { return m_content; }

private:
    VfxWString m_content;
};

class VcuiHelloWorldScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VcuiHelloWorldScreen);

// Override
public:
    virtual void on1stReady();
};

class VcuiHelloWorldPage : public VfxPage
{
    VFX_DECLARE_CLASS(VcuiHelloWorldPage);

// Method
public:
    void updateUI();

// Override
public:
    virtual void onInit();

private:
    void onBtnClicked(VfxObject *obj, VfxId id);

private:
    VfxTextFrame *m_textFrame;
};

#endif /* __VAPP_HELLOWORLD_H__ */

