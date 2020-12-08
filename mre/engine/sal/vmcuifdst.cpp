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
 *     vmcuifdst.cpp
 *
 * Project:
 * --------
 *     MAUI
 *
 * Description:
 * ------------
 *     this file implements an vapp, in which we can create a file manger CUI 
 *     and run it to select a folder.
 *     "fdst" in file name means "folder selector". 
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
    const VMWCHAR   *start_folder_path;
    VMINT			folder_selector_style;
} vm_folder_selector_struct;

class VappFDSTApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappFDSTApp);

    // Override
public:
    virtual void    onRun(void *args, VfxU32 argSize);   
    static  mmi_id  m_mmiId;
protected:
    virtual void    onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
};

extern "C" MMI_ID vapp_cui_folder_selector_run(
    const VMWCHAR   *start_folder_path, 
    VMINT			folder_selector_style)
{
    vm_folder_selector_struct fdst;
    
    fdst.start_folder_path = start_folder_path;
    fdst.folder_selector_style = folder_selector_style;

    VappFDSTApp::m_mmiId = VfxAppLauncher::launch(
        VAPP_MRE_APP_FMGR, 
        VFX_OBJ_CLASS_INFO(VappFDSTApp),
        GRP_ID_ROOT,
        (void *) &fdst, 
        sizeof(fdst),
        VFX_FALSE);

    return VappFDSTApp::m_mmiId;
}

VFX_IMPLEMENT_CLASS("VappFDSTApp", VappFDSTApp, VfxApp);

mmi_id VappFDSTApp::m_mmiId = 0;

typedef struct _vm_folder_selector_ctx_t
{
    VMINT   m_phdl;
    VMINT   (*m_cb)(VMWCHAR *path, VMINT wlen);
    VMWCHAR *m_path;
    VMINT   res_handle;
    VMUINT  cui_id;
} vm_folder_selector_ctx_t;

/* APIs implemented in vmio.c */
extern "C" vm_folder_selector_ctx_t* vm_folder_selector_malloc_context(void);
extern "C" vm_folder_selector_ctx_t* vm_folder_selector_get_context(void);
extern "C" void vm_folder_selector_free_context(vm_folder_selector_ctx_t *ctx_p);

/* free resources when the folder manager CUI is going to be destroyed. */
void VappFDSTApp::onDeinit()
{
    /* free context memory and resource. */
    vm_folder_selector_free_context(vm_folder_selector_get_context());

    /* exit the folder selector app. */
    exit();
    VfxApp::onDeinit();
}

/* handle some events while the folder manager CUI is running. */
mmi_ret VappFDSTApp::onProc(mmi_event_struct *evt)
{
    vm_folder_selector_ctx_t *ctx_p 					 = NULL;
    mmi_ret					 success_to_handle_selection = MMI_RET_OK;

    switch (evt->evt_id)
    {
        /* this event indicates the result of selection. */
    case EVT_ID_VCUI_FOLDER_SELECTOR_RESULT:
        {
            vcui_folder_selector_result_event_struct *evt_fs = NULL;
            
            ctx_p = vm_folder_selector_get_context();
            if (!ctx_p)
            {
                vm_log_error("vm_selector_get_context == NULL");
                return !MMI_RET_OK;
            }

            evt_fs = (vcui_folder_selector_result_event_struct*) evt;
            if (evt_fs->result > 0) /* we got a selection now. */
            {
                VfxChar folder_path[SRV_FMGR_PATH_MAX_LEN + 1] = {0};
                if (vcui_folder_selector_get_selected_filepath(
                    	evt_fs->sender_id, 
                    	NULL,
                    	(WCHAR*) folder_path, 
                    	sizeof(folder_path)) == 0) /* got the folder path. */
                {
                    ctx_p->m_path = (VMWCHAR*) folder_path;
                    if (ctx_p->m_cb != NULL 
                        && ctx_p->m_phdl != NULL 
                        && vm_pmng_set_ctx(ctx_p->m_phdl) == VM_PMNG_OP_OK)
                    {
                        /* call user callback to handle the selected file path. */
                        ctx_p->m_cb(ctx_p->m_path, vm_wstrlen(ctx_p->m_path));
                        vm_pmng_reset_ctx();
                        success_to_handle_selection = MMI_RET_OK;
                    }
                    else
                    {
                        ctx_p->m_path = NULL;
                        vm_log_error(
                            "[SELECTOR FILE], ctx_p->m_cb[0x%x], ctx_p->m_phdl[0x%x]", 
                            ctx_p->m_cb,
                            ctx_p->m_phdl);
                        
                        success_to_handle_selection = !MMI_RET_OK;
                    }               
                }
                else /* can NOT get the selected folder's path. */
                {
                	success_to_handle_selection = !MMI_RET_OK;
                }
            }

            vcui_folder_selector_close(evt_fs->sender_id);
            vm_folder_selector_free_context(ctx_p);
            exit();

            return MMI_RET_OK;
        }
        //break;
    }

    return VfxApp::onProc(evt);
}

/* create a file manger CUI and run it. */
void VappFDSTApp::onRun(void *args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    MMI_ID 		              cui_gid = GRP_ID_INVALID;
    vm_folder_selector_ctx_t  *ctx_p  = NULL;
    vm_folder_selector_struct *fdst   = (vm_folder_selector_struct*) args;

    /*
    * if args is invalid, that means we can NOT get path_type and filter from 
    * the parameter, just return.
    */
    if (!fdst)
    {
        return;
    }

    /*
     * create folder selector CUI on COSMOS.
     */
    cui_gid = vcui_folder_selector_create(
        getGroupId(),
        (WCHAR*) fdst->start_folder_path, 
        (vcui_folder_selector_style_enum) fdst->folder_selector_style, 
        VCUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON
        | VCUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_SUB);

    if (cui_gid > GRP_ID_INVALID)
    {
        ctx_p = vm_folder_selector_get_context();
        if (ctx_p)
        {
            ctx_p->cui_id = (VMUINT) cui_gid;
        }

        /* hide CUI item in OOM screen. 
        * that means, when OOM occurs while the file manager CUI is running,
        * the item 'VAPP_MRE_APP_FMGR' won't be displayed on the screen. 
        */
        mmi_frm_asm_property_struct p;
        mmi_frm_asm_get_property(VAPP_MRE_APP_FMGR, &p);
        p.f_hide_in_oom = 1;
        mmi_frm_asm_set_property(VAPP_MRE_APP_FMGR, &p);

        vcui_folder_selector_run(cui_gid);
    }
}

#endif /* __MRE_CORE_BASE__ && __COSMOS_MMI_PACKAGE__  */
