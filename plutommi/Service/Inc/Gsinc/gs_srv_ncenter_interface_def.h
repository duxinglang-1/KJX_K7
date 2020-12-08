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
 *   gs_srv_ncenter_interface_def.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   INcenter interface
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

#include "gs_idef.h"
#include "gs_srv_ncenter_type.h"

/***************************************************************************** 
* INcenter
*****************************************************************************/   
DEF_INTERFACE(INcenter, GS_IBase)
    DEF_METHODS_GS_IBase(INcenter)
    DEF_METHOD2(INcenter,gs_ngroup_handle,create_ngroup,gs_ngroup_type ,type, gs_ngroup_id ,gid)
    DEF_METHOD3(INcenter,gs_notification_handle,create_notification,gs_notification_type ,type, gs_ngroup_handle ,ghandle, gs_notification_id ,nid)
    DEF_METHOD1(INcenter,gs_ngroup_handle,query_ngroup,gs_ngroup_id ,gid)
    DEF_METHOD0(INcenter,gs_ngroup_entry,get_ngroup_entry)
    DEF_METHOD1(INcenter,gs_ngroup_entry,get_next_ngroup_entry,gs_ngroup_entry ,gentry)
    DEF_METHOD1(INcenter,gs_notification_entry,get_notification_entry,gs_ngroup_handle ,ghandle)
    DEF_METHOD1(INcenter,gs_notification_entry,get_next_notification_entry,gs_notification_entry ,nentry)
    DEF_METHOD1(INcenter,gs_ngroup_handle,get_ngroup,gs_ngroup_entry ,nentry)
    DEF_METHOD1(INcenter,gs_notification_handle,get_notification,gs_notification_entry ,nentry)
    DEF_METHOD2(INcenter,gs_notification_handle,query_notification,gs_ngroup_handle ,ghandle, gs_notification_id ,nid)
    DEF_METHOD1(INcenter,BOOL,close_ngroup,gs_ngroup_handle ,ghandle)
    DEF_METHOD1(INcenter,BOOL,close_notification,gs_notification_handle ,nhandle)
    DEF_METHOD1(INcenter,gs_ngroup_id,get_ngroup_id,gs_ngroup_handle ,ghandle)
    DEF_METHOD1(INcenter,gs_notification_id,get_notification_id,gs_notification_handle ,nhandle)
    DEF_METHOD2(INcenter,BOOL,set_ngroup_title,gs_ngroup_handle ,ghandle, WCHAR* ,title)
    DEF_METHOD2(INcenter,BOOL,set_notification_icon,gs_notification_handle ,nhandle, gs_image_src_struct ,icon)
    DEF_METHOD2(INcenter,BOOL,get_notification_icon,gs_notification_handle ,nhandle, gs_image_src_struct *,icon)
    DEF_METHOD2(INcenter,BOOL,set_notification_maintext,gs_notification_handle ,nhandle, WCHAR* ,text)
    DEF_METHOD3(INcenter,BOOL,get_notification_maintext,gs_notification_handle ,nhandle, WCHAR* ,text, U32 ,bufsize)
    DEF_METHOD2(INcenter,BOOL,set_notification_subtext,gs_notification_handle ,nhandle, WCHAR* ,text)
    DEF_METHOD3(INcenter,BOOL,get_notification_subtext,gs_notification_handle ,nhandle, WCHAR* ,text, U32 ,bufsize)
    DEF_METHOD2(INcenter,BOOL,set_notification_questiontext,gs_notification_handle ,nhandle, WCHAR* ,text)
    DEF_METHOD3(INcenter,BOOL,get_notification_questiontext,gs_notification_handle ,nhandle, WCHAR* ,text, U32 ,bufsize)
    DEF_METHOD2(INcenter,BOOL,set_notification_timestamp,gs_notification_handle ,nhandle, gs_time_struct *,timestamp)
    DEF_METHOD2(INcenter,BOOL,get_notification_timestamp,gs_notification_handle ,nhandle, gs_time_struct *,timestamp)
    DEF_METHOD4(INcenter,BOOL,set_notification_intent_callback,gs_notification_handle ,nhandle, gs_nitent_funcptr ,callback, void *,userdata, U32 ,userdata_size)
    DEF_METHOD1(INcenter,void*,get_notification_userdata,gs_notification_handle ,nhandle)
    DEF_METHOD1(INcenter,U32,get_notification_userdata_size,gs_notification_handle ,nhandle)
    DEF_METHOD1(INcenter,BOOL,notify_notification,gs_notification_handle ,nhandle)
    DEF_METHOD3(INcenter,BOOL,send_intent,gs_nviewer_type ,viewer, gs_nintent_type ,type, gs_notification_handle ,nhandle)
DEF_INTERFACE_END(INcenter)