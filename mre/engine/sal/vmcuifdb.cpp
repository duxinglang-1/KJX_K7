/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 * vmcuifdb.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   implement vm cui folder browser.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "vmswitch.h"

#if defined(__MRE_CORE_BASE__) && defined(__COSMOS_MMI_PACKAGE__)

#include "vmsys.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "vapp_vol_dialog_gprot.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vfx_datatype.h"
#include "vmpromng.h"
#include "vmstdlib.h"
#include "vmlog.h"
#include "vfx_app.h"
#include "vfx_app_launcher.h"

typedef struct
{
    const VMWCHAR       *path_type;
    const FMGR_FILTER   *filter;
} vm_fdb_struct;

class VappFDBApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappFDBApp);

    // Override
public:
    virtual void    onRun(void *args, VfxU32 argSize); 
    static  mmi_id  m_mmiId;

protected:
    virtual void    onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
};

extern "C" MMI_ID vapp_cui_folder_browser_run(
    const VMWCHAR       *path_type, 
    const FMGR_FILTER   *filter)
{
    vm_fdb_struct fdb;
    fdb.filter = filter;
    fdb.path_type = path_type;

    VappFDBApp::m_mmiId = VfxAppLauncher::launch( 
        VAPP_MRE_APP_FMGR,
        VFX_OBJ_CLASS_INFO(VappFDBApp),
        GRP_ID_ROOT, 
        (void *) &fdb,
        sizeof(fdb),
        VFX_FALSE);

    return VappFDBApp::m_mmiId;
}

VFX_IMPLEMENT_CLASS("VappFDBApp", VappFDBApp, VfxApp);

mmi_id VappFDBApp::m_mmiId = 0;

typedef struct _vm_folder_browser_ctx_t
{
    VMINT m_phdl;
    VMINT res_handle;
    VMUINT cui_id;
} vm_folder_browser_ctx_t;

extern "C" vm_folder_browser_ctx_t* vm_folder_browser_malloc_context(void);
extern "C" vm_folder_browser_ctx_t* vm_folder_browser_get_context(void);
extern "C" void vm_folder_browser_free_context(vm_folder_browser_ctx_t *ctx_p);

/* free resources when file manager CUI is going to be destroyed. */
void VappFDBApp::onDeinit()
{
    /* free context memory and resource. */
    vm_folder_browser_free_context(vm_folder_browser_get_context());

    /* exit folder browser app. */
    exit();
    VfxApp::onDeinit();
}

/* handle some events while file manager CUI is running. */
mmi_ret VappFDBApp::onProc(mmi_event_struct *evt)
{
    vm_folder_browser_ctx_t *ctx_p = NULL;

    switch (evt->evt_id)
    {   
        /*
        * while folder browser is going to quit, we should close the CUI and 
        * free all resources. 
        */
    case EVT_ID_VCUI_FOLDER_BROWSER_LAUNCH_QUIT:
        {
            ctx_p = vm_folder_browser_get_context();
            if (ctx_p != NULL)
            {
                vcui_folder_browser_close(ctx_p->cui_id);
                vm_folder_browser_free_context(ctx_p);
            }
            exit();
            
            return MMI_RET_OK;
        }
        //break;

    default:
        break;
    }

    return VfxApp::onProc(evt);
}

/* create a file manager CUI and run it. */
void VappFDBApp::onRun(void *args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    MMI_ID cui_gid = GRP_ID_INVALID;
    vm_folder_browser_ctx_t *ctx_p = NULL;
    vm_fdb_struct *fdb = (vm_fdb_struct *) args;

    /* 
    * if args is invalid, that means we can NOT get the path_type and filter 
    * from the parameter, just return.
    */
    if (!fdb)
    {
        return;
    }

    /* the 'launch' operation includes 2 steps:
    *   1. create a file manager CUI.
    *   2. run it.
    */
    cui_gid = vcui_folder_browser_launch(
        getGroupId(), 
        (WCHAR *) fdb->path_type, 
        fdb->filter);

    if (cui_gid != GRP_ID_INVALID)
    {
        ctx_p = vm_folder_browser_get_context();
        if (ctx_p)
        {
            ctx_p->cui_id = (VMUINT) cui_gid;
        }

        /* 
        * hide file manager CUI item in OOM screen.
        * that means, when OOM occurs while file manager CUI is running, 
        * the item 'VAPP_MRE_APP_FMGR' won't be displayed on the screen.
        */
        mmi_frm_asm_property_struct p;
        mmi_frm_asm_get_property(VAPP_MRE_APP_FMGR, &p);
        p.f_hide_in_oom = 1;
        mmi_frm_asm_set_property(VAPP_MRE_APP_FMGR, &p);
    }
}

#endif /* __COSMOS_MMI_PACKAGE__ && __MRE_CORE_BASE_ */
