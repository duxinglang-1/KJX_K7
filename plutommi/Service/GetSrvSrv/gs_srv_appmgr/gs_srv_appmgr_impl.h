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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   gs_srv_appmgr_impl.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Class header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMS_INTERFACE_
#define _MMS_INTERFACE_

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_appmgr_interface_def.h"


class AppmgrService : public GS_CBase, public IAppmgr
{

public:
    AppmgrService(U32 handle):GS_CBase(handle){}

    /* Common API */
    virtual S32 CALLCC addRef()
    {
        return GS_CBase::addRef();
    }
    virtual S32 CALLCC release()
    {
        return GS_CBase::release();
    }
    virtual S32 CALLCC queryInterface(S32 iid, GS_IBase **pptr);

    /* Functional API */   
    virtual U32 CALLCC get_app_package_num(gs_appmgr_query_type_enum flag);
    virtual S32 CALLCC get_app_package_list(gs_appmgr_query_type_enum flag, gs_app_package_name_struct *name_array, U32 num);
    virtual S32 CALLCC get_app_package_name(const CHAR* app_name, WCHAR *string);
    virtual S32 CALLCC get_app_package_image(const CHAR* app_name, gs_image_src_struct *image);
    virtual S32 CALLCC get_app_package_badge(const CHAR* app_name, WCHAR *badge);
    virtual gs_appmgr_app_package_type_enum CALLCC get_app_package_type(const CHAR* app_name);
    virtual U16 CALLCC launch_app(const CHAR* app_name);
    virtual S32 CALLCC install_app(const CHAR* file_path); /* Not support now */
    virtual S32 CALLCC uninstall_app(const CHAR* app_name, gs_appmgr_uninstall_cb_fct cb_fct, void* user_data);
    virtual S32 CALLCC reg_event_hdlr(gs_appmgr_event_cb_fct cb_fct, void* user_data);
    virtual void CALLCC unreg_event_hdlr();

    static void init(void);
    
private:
    static void AppmgrService::uninstall_cb(srv_appmgr_cb_event_enum result, void* user_data);
    static gs_appmgr_cb_event_enum transEvent(U16 event_id);
    static mmi_ret appmgr_event_hdlr(mmi_event_struct *param);
    static void unreg(VM_P_HANDLE handle);
    static void release(VM_P_HANDLE process_handle, VMINT sys_state);
    
};


#endif /* _MMS_INTERFACE_ */ 


