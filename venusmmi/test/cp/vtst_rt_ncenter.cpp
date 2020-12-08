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
 *  vtst_sample_setting.cpp
 *
 * Project:
 * --------
 *  Venus Sample code of setting
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"
#ifdef __AFX_RT_TEST__
#include "MMI_features.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vfx_uc_include.h"
#include "vtst_rt_main.h"
#include "vcp_navi_title_bar.h"
#include "vcp_form.h"
//#include "Cosmos/NCenter/vapp_ncenter.h"

extern "C" 
{
    #include "GlobalResDef.h"
}
/***************************************************************************** 
 * Class VtstSampleSettingMainPage implementation
 *****************************************************************************/

class VtstSampleNCenterMainPage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstSampleNCenterMainPage);
protected:
    virtual void onInit()
    {
        VfxPage::onInit();
		
        VcpTitleBar *bar;
        VFX_OBJ_CREATE(bar, VcpTitleBar, this);
        bar->setTitle(VFX_WSTR("Contacts setting"));
        setTopBar(bar);

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
#endif
    }


private:
    //VcpForm *m_form;
//    VappNCenter  *m_NCenter;

//    VappNCTestPanel *m_testPanel;

};

VFX_IMPLEMENT_CLASS("VtstSampleSettingMainPage", VtstSampleNCenterMainPage, VfxPage);


/***************************************************************************** 
 * Class VtstSampleSettingAppScr declaration
 *****************************************************************************/

class VtstSampleNCenterAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstSampleNCenterAppScr);


// Override
protected:
    virtual void on1stReady();

};

/***************************************************************************** 
 * Class VtstSampleSettingAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstSampleNCenterAppScr", VtstSampleNCenterAppScr, VfxMainScr);

void VtstSampleNCenterAppScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VfxPage *page;
    VFX_OBJ_CREATE(page, VtstSampleNCenterMainPage, this);
    pushPage(0, page);
}

/***************************************************************************** 
 * Class VtstSampleSettingApp declaration
 *****************************************************************************/

class VtstSampleNCenterApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstSampleNCenterApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

/***************************************************************************** 
 * Class VtstSampleSettingApp implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstSampleNCenterApp", VtstSampleNCenterApp, VfxApp);

void VtstSampleNCenterApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstSampleNCenterAppScr *scr;
    VFX_OBJ_CREATE(scr, VtstSampleNCenterAppScr, this);
    scr->show();
}

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

VtstTestResultEnum vtst_sample_ncenter_entry(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstSampleNCenterApp),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}

#endif // __COSMOS_MMI_PACKAGE__
#endif // __AFX_RT_TEST__

