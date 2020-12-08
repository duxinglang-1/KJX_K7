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
 *   gs_srv_ncenter.cpp
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   NcenterService implement file
 *
 * Author:
 * -------
 *
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __NCENTER20__


#include "gs_srv_ncenter_impl.h"
#include "vsrv_ncenter.h"
extern "C"
{
#include "vmpromng.h"
}
//common interface

GS_IBase *CreateNcenterService(U32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NcenterService* service = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    GS_NEW_EX(service, NcenterService,(hd));
    return (GS_IBase*)(GS_CBase*)service;
}


S32 NcenterService::queryInterface(S32 iid, GS_IBase **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Please notes: pptr may be a proxy, your call should not use it directly. */
    if (pptr == NULL)
        return 0;
    if (iid == IID_INCENTER)
    {
        addRef();
        *pptr = BIND_PROXY(INcenter, this);
        return 1;
    }
    return GS_CBase::queryInterface(iid, pptr);
}

gs_ngroup_handle CALLCC NcenterService::create_ngroup(gs_ngroup_type type, gs_ngroup_id gid)
{
    return (gs_ngroup_handle)vsrv_ncenter_create_ngroup((vsrv_ngroup_type)type, (vsrv_ngroup_id)gid);
}

gs_notification_handle CALLCC NcenterService::create_notification(gs_notification_type type, gs_ngroup_handle ghandle, gs_notification_id nid)
{
    return (gs_notification_handle)vsrv_ncenter_create_notification((vsrv_notification_type)type, (vsrv_ngroup_handle)ghandle, (vsrv_notification_id)nid);
}

gs_ngroup_handle CALLCC NcenterService::query_ngroup(gs_ngroup_id gid)
{
    return (gs_ngroup_handle)vsrv_ncenter_query_ngroup((vsrv_ngroup_id) gid);
}

gs_ngroup_entry CALLCC NcenterService::get_ngroup_entry()
{
    return (gs_ngroup_entry)vsrv_ncenter_get_ngroup_entry();
}

gs_ngroup_entry CALLCC NcenterService::get_next_ngroup_entry(gs_ngroup_entry gentry)
{
    return (gs_ngroup_entry)vsrv_ncenter_get_next_ngroup_entry((vsrv_ngroup_entry) gentry);
}

gs_notification_entry CALLCC NcenterService::get_notification_entry(gs_ngroup_handle ghandle)
{
    return (gs_notification_entry)vsrv_ncenter_get_notification_entry((vsrv_ngroup_handle)ghandle);
}

gs_notification_entry CALLCC NcenterService::get_next_notification_entry(gs_notification_entry nentry)
{
    return (gs_notification_entry)vsrv_ncenter_get_next_notification_entry((vsrv_notification_entry)nentry);
}

gs_ngroup_handle CALLCC NcenterService::get_ngroup(gs_ngroup_entry nentry)
{
    return (gs_ngroup_handle)vsrv_ncenter_get_ngroup((vsrv_ngroup_entry)nentry);
}

gs_notification_handle CALLCC NcenterService::get_notification(gs_notification_entry nentry)
{
    return (gs_notification_handle)vsrv_ncenter_get_notification((vsrv_notification_entry)nentry);
}

gs_notification_handle CALLCC NcenterService::query_notification(gs_ngroup_handle ghandle, gs_notification_id nid)
{
    return (gs_notification_handle)vsrv_ncenter_query_notification((vsrv_ngroup_handle)ghandle, (vsrv_notification_id)nid);
}

BOOL CALLCC NcenterService::close_ngroup(gs_ngroup_handle ghandle)
{
    return vsrv_ncenter_close_ngroup((vsrv_ngroup_handle)ghandle);
}

BOOL CALLCC NcenterService::close_notification(gs_notification_handle nhandle)
{
    return vsrv_ncenter_close_notification((vsrv_notification_handle)nhandle);
}

gs_ngroup_id CALLCC NcenterService::get_ngroup_id(gs_ngroup_handle ghandle)
{
    return (vsrv_ngroup_id) vsrv_ncenter_get_ngroup_id((vsrv_ngroup_handle) ghandle);
}

gs_notification_id CALLCC NcenterService::get_notification_id(gs_notification_handle nhandle)
{
    return (vsrv_notification_id) vsrv_ncenter_get_notification_id((vsrv_notification_handle) nhandle);
}

BOOL CALLCC NcenterService::set_ngroup_title(gs_ngroup_handle ghandle, WCHAR* title)
{
    return vsrv_ncenter_set_ngroup_title((vsrv_ngroup_handle) ghandle,title);
}

BOOL CALLCC NcenterService::set_notification_icon(gs_notification_handle nhandle, gs_image_src_struct icon)
{
    mmi_image_src_struct image;
    memcpy(&image,&icon,sizeof(mmi_image_src_struct));
    return vsrv_ncenter_set_notification_icon((vsrv_notification_handle)nhandle, image);
}

BOOL CALLCC NcenterService::get_notification_icon(gs_notification_handle nhandle, gs_image_src_struct *icon)
{
    return vsrv_ncenter_get_notification_icon((vsrv_notification_handle)nhandle, (mmi_image_src_struct*)icon);
}

BOOL CALLCC NcenterService::set_notification_maintext(gs_notification_handle nhandle, WCHAR* text)
{
    return vsrv_ncenter_set_notification_maintext((vsrv_notification_handle) nhandle, text);
}

BOOL CALLCC NcenterService::get_notification_maintext(gs_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
    return vsrv_ncenter_get_notification_maintext((vsrv_notification_handle)nhandle, text, bufsize);
}

BOOL CALLCC NcenterService::set_notification_subtext(gs_notification_handle nhandle, WCHAR* text)
{
    return vsrv_ncenter_set_notification_subtext((vsrv_notification_handle)nhandle, text);
}

BOOL CALLCC NcenterService::get_notification_subtext(gs_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
    return vsrv_ncenter_get_notification_subtext((vsrv_notification_handle)nhandle, text, bufsize);
}

BOOL CALLCC NcenterService::set_notification_questiontext(gs_notification_handle nhandle, WCHAR* text)
{
    return vsrv_ncenter_set_notification_questiontext((vsrv_notification_handle) nhandle, text);
}

BOOL CALLCC NcenterService::get_notification_questiontext(gs_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
    return vsrv_ncenter_get_notification_questiontext((vsrv_notification_handle) nhandle, text, bufsize);
}

BOOL CALLCC NcenterService::set_notification_timestamp(gs_notification_handle nhandle, gs_time_struct *timestamp)
{
    return vsrv_ncenter_set_notification_timestamp((vsrv_notification_handle)nhandle, (applib_time_struct*) timestamp);
}

BOOL CALLCC NcenterService::get_notification_timestamp(gs_notification_handle nhandle, gs_time_struct *timestamp)
{
    return vsrv_ncenter_get_notification_timestamp((vsrv_notification_handle )nhandle, (applib_time_struct *)timestamp);
}

typedef struct
{
    VM_P_HANDLE                 pHandle;
    void*                       callback;
    void*                       user_data;
    U32                         size;
}gs_cb_data;

void NcenterService::intent_callback(gs_notification_handle nhandle, gs_nintent intent, void* userData, U32 userdata_size)
{
    gs_cb_data* data = (gs_cb_data*)userData;
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->pHandle && data->callback))
    {
        ((gs_nitent_funcptr)data->callback)(nhandle,intent,data->user_data,data->size);
        vm_free(data->user_data);
        vm_free(data);
        vm_pmng_reset_ctx();
    }
    return;
}

BOOL CALLCC NcenterService::set_notification_intent_callback(gs_notification_handle nhandle, gs_nitent_funcptr callback, void *userdata, U32 userdata_size)
{
	gs_cb_data* data;
	data = (gs_cb_data*)vm_malloc(sizeof(gs_cb_data));
    if (!data)
    {
        return -2;
    }
    data->pHandle = vm_pmng_get_current_handle();
    data->callback = (void*)callback;    
    data->user_data = vm_malloc(userdata_size);
    if (!data->user_data)
    {
        return -3;
    }
    memcpy(data->user_data,userdata,userdata_size);
    data->size = userdata_size;
    
    return vsrv_ncenter_set_notification_intent_callback((vsrv_notification_handle) nhandle, (vsrv_nitent_funcptr) intent_callback, data, sizeof(gs_cb_data));
}

void* NcenterService::get_notification_userdata(gs_notification_handle nhandle)
{
    return vsrv_ncenter_get_notification_userdata((vsrv_notification_handle) nhandle);
}

U32 CALLCC NcenterService::get_notification_userdata_size(gs_notification_handle nhandle)
{
    return vsrv_ncenter_get_notification_userdata_size((vsrv_notification_handle)nhandle);
}

BOOL CALLCC NcenterService::notify_notification(gs_notification_handle nhandle)
{
    return vsrv_ncenter_notify_notification((vsrv_notification_handle) nhandle);
}

BOOL CALLCC NcenterService::send_intent(gs_nviewer_type viewer, gs_nintent_type type, gs_notification_handle nhandle)
{
    return vsrv_ncenter_send_intent((vsrv_nviewer_type) viewer, (vsrv_nintent_type)type, (vsrv_notification_handle) nhandle);
}

#endif
