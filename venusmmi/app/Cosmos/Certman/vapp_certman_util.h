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
*  vapp_certman_util.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef __VAPP_CERTMAN_UTIL_H__
#define __VAPP_CERTMAN_UTIL_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vapp_certman_cfg.h"
#include "vapp_certman_msg_hndlr.h"
#include "vcp_text_view.h"

class VappCertmanUtilities
{
public:

    typedef enum
    {
        FILL_LABEL = 0x01
    };
    static VfxBool vapp_certman_fill_certificate_contents_only(VfxU8 *cert_info, certman_cert_display_struct *display_cert, VfxBool addlabel);
    static void vapp_certman_cert_strncpy(VfxU8 *Destination, VfxU8 *Source, certman_dcs_enum dcs_type, VfxU32 dest_size);
    static void vapp_certman_send_msg_on_queue(module_type src_mod, module_type dest_mod, void *data, msg_type msg_id);
    static void vapp_certman_set_protocol_events(void);
    static void vapp_certman_bootup_notify(mmi_event_struct *evt);
    static VfxU8 *vapp_certman_left_trim_label(VfxU8 *label);
    static VfxU8* vapp_certman_suggest_label(VfxU8* subject, certman_dcs_enum &dcs);
    static void vapp_certman_convert_time_to_string(applib_time_struct time, VfxU8* buff);
    static VfxU16 vapp_certman_convert_error_to_string(certman_error_enum error);
    static VfxWChar* vapp_certman_get_alg_string(certman_signature_alg algorithm_enum);
    static VfxBool vapp_certman_fill_certificate_contents_only_rich(VcpTextView *cert_view, certman_cert_display_struct *display_cert, VfxBool addlabel);
};


typedef void (*cleanup_fn_p)(void*);

//don't have dyanmic memory
/////////////////////////////////////////////////////////////////////////////////
class VappCertmanIfMapItem
{
public:

    VfxU32 transid;
    mmi_id app_handler;
    VfxBool isvalid;

    VappCertmanIfMapItem();
};


class VappCertmanIfMapList : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappCertmanIfMapList);

    VappCertmanIfMapItem list[VAPP_CERTMAN_MAX_IF_MAP_SIZE];
    VfxU32 list_count;
    VappCertmanIfMapList();
public:
    const VappCertmanIfMapItem dummy_item;
    VfxBool add (VfxU32 transid, mmi_id app_handler);
    VfxU32 remove_by_transid (VfxU32 transid);
    VfxU32 remove_by_apphandler (mmi_id app_handler);
    const VappCertmanIfMapItem& get_by_trans_id(VfxU32 transid);
    const VappCertmanIfMapItem& get_by_app_handler(VfxU32 app_handler);
};

///////////////////////////////////////////////////////////////////////////////

class VappCertmanServiceMapItem
{
public:

    VfxU32 transid;
    void *msghndlr_obj;
    cleanup_fn_p fp;
    VfxBool isvalid;

    VappCertmanServiceMapItem();
};


class VappCertmanServiceMapList : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappCertmanServiceMapList);
    VappCertmanServiceMapItem list[VAPP_CERTMAN_MAX_SERIVICE_MAP_SIZE];
    VfxU32 list_count;
    VappCertmanServiceMapList();
public:
    const VappCertmanServiceMapItem dummy_item;
    void add (VfxU32 transid, void *msghndlr_obj, cleanup_fn_p fp);
    VfxU32 remove_by_transid (VfxU32 transid);
    const VappCertmanServiceMapItem& get_by_trans_id(VfxU32 transid);
};


class VappCertmanUtil
{
    static VfxU32 curr_trans_id;
public:
    static VfxU32 generate_new_trans_id(void);
};

#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_UTIL_H__ */
