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
 *   gs_srv_ncenter_impl.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   NcenterService header file
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
#ifndef _NCENTER_INTERFACE_
#define _NCENTER_INTERFACE_
#ifdef __NCENTER20__
#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_ncenter_interface_def.h"


class NcenterService : public GS_CBase, public INcenter
{

public:
    NcenterService(U32 handle):GS_CBase(handle){}
         
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

    virtual gs_ngroup_handle CALLCC create_ngroup(gs_ngroup_type type, gs_ngroup_id gid);
    virtual gs_notification_handle CALLCC create_notification(gs_notification_type type, gs_ngroup_handle ghandle, gs_notification_id nid);
    virtual gs_ngroup_handle CALLCC query_ngroup(gs_ngroup_id gid);
    virtual gs_ngroup_entry CALLCC get_ngroup_entry();
    virtual gs_ngroup_entry CALLCC get_next_ngroup_entry(gs_ngroup_entry gentry);
    virtual gs_notification_entry CALLCC get_notification_entry(gs_ngroup_handle ghandle);
    virtual gs_notification_entry CALLCC get_next_notification_entry(gs_notification_entry nentry);
    virtual gs_ngroup_handle CALLCC get_ngroup(gs_ngroup_entry nentry);
    virtual gs_notification_handle CALLCC get_notification(gs_notification_entry nentry);
    virtual gs_notification_handle CALLCC query_notification(gs_ngroup_handle ghandle, gs_notification_id nid);
    virtual BOOL CALLCC close_ngroup(gs_ngroup_handle ghandle);
    virtual BOOL CALLCC close_notification(gs_notification_handle nhandle);
    virtual gs_ngroup_id CALLCC get_ngroup_id(gs_ngroup_handle ghandle);
    virtual gs_notification_id CALLCC get_notification_id(gs_notification_handle nhandle);
    virtual BOOL CALLCC set_ngroup_title(gs_ngroup_handle ghandle, WCHAR* title);
    virtual BOOL CALLCC set_notification_icon(gs_notification_handle nhandle, gs_image_src_struct icon);
    virtual BOOL CALLCC get_notification_icon(gs_notification_handle nhandle, gs_image_src_struct *icon);
    virtual BOOL CALLCC set_notification_maintext(gs_notification_handle nhandle, WCHAR* text);
    virtual BOOL CALLCC get_notification_maintext(gs_notification_handle nhandle, WCHAR* text, U32 bufsize);
    virtual BOOL CALLCC set_notification_subtext(gs_notification_handle nhandle, WCHAR* text);
    virtual BOOL CALLCC get_notification_subtext(gs_notification_handle nhandle, WCHAR* text, U32 bufsize);
    virtual BOOL CALLCC set_notification_questiontext(gs_notification_handle nhandle, WCHAR* text);
    virtual BOOL CALLCC get_notification_questiontext(gs_notification_handle nhandle, WCHAR* text, U32 bufsize);
    virtual BOOL CALLCC set_notification_timestamp(gs_notification_handle nhandle, gs_time_struct *timestamp);
    virtual BOOL CALLCC get_notification_timestamp(gs_notification_handle nhandle, gs_time_struct *timestamp);
    virtual BOOL CALLCC set_notification_intent_callback(gs_notification_handle nhandle, gs_nitent_funcptr callback, void *userdata, U32 userdata_size);
    virtual void* CALLCC get_notification_userdata(gs_notification_handle nhandle);
    virtual U32 CALLCC get_notification_userdata_size(gs_notification_handle nhandle);
    virtual BOOL CALLCC notify_notification(gs_notification_handle nhandle);
    virtual BOOL CALLCC send_intent(gs_nviewer_type viewer, gs_nintent_type type, gs_notification_handle nhandle);
	static void intent_callback(gs_notification_handle nhandle, gs_nintent intent, void* userData, U32 userdata_size);
};

#endif
#endif /* _NCENTER_INTERFACE_ */