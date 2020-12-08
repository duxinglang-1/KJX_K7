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
 *  vapp_XXX.h
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WAP_PUSH_INTERFACE_H__
#define __VAPP_WAP_PUSH_INTERFACE_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#include "vfx_mc_include.h"
#include "vcp_include.h"
//#include "vfx_signal.h"
#ifdef __cplusplus
extern "C"
{
#endif

#include "WAPPushSrvProts.h"
#include "WAPPushSrvTypes.h"
#include "mmi_frm_events_gprot.h"
#include "NotificationGprot.h"

#ifdef __cplusplus
}
#endif



/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
#define VAPP_PUSH_IPV4_BYTE_NUM 4
#define VAPP_PUSH_IPV4_STR_MAX_LEN (VAPP_PUSH_IPV4_BYTE_NUM * 3 + 3)
#define VAPP_PUSH_IS_DIGIT(x) ((x >= '0') && (x <= '9'))
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
typedef struct{
    VfxU32	msg_id;
    VfxU32	msg_type;
}VappPushNotificationParam;


class VfxAppWapPushInterface : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxAppWapPushInterface);

public:
    VfxSignal2<pmg_detailed_msg_struct *, VfxS8 *> m_msgBodyDispatchCallback;
    VfxSignal2<VfxBool , VfxU32 > m_msgDeleteCallback;
    VfxSignal1<VfxBool> m_trustlistSettingScrActiveCallback;
    VfxSignal0 m_OTAlistEntry;
    VfxSignal0 m_lauchMsgURLNotify;
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    static void vappWapPushReturnThreeDigitString(VfxU8* StringVal, VfxU8 DigitVal);
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    template <class _func_type>
    static void vappWapPushLauchMsgURL(VfxU32 msgID, VfxObject *obj, _func_type func)
    {
        srv_wap_push_get_full_message (msgID, PUSH_LAUNCH_MSG_URL);
        ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_lauchMsgURLNotify.connect(obj, func);
    }
    static VfxU32 vappWapPushGetIcon(VfxU32 msg_status);
    static void displayPopup(VfxU16 stringId, VfxU32 event_id);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    static VfxBool addrString2Ipv4(VfxChar *src, VfxU8 *dst, VfxU16 dst_size);	 
    static VfxU32 vappWapPushGetErrorStrID (VfxU32 errCode);
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    static mmi_nmgr_balloon_type_enum vappWapPushGetBalloonType (VfxU32 event_id);

};

void onHighMsgConfirm(VfxId id, void *userData);

MMI_BOOL vapp_wap_push_handle_high_message(mmi_scenario_id scen_id, void *arg);
mmi_ret onServiceInitiationReq(mmi_event_struct *evt);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
mmi_ret onServiceUnknownAddrReq(mmi_event_struct *evt);
mmi_ret onDlgDataRsp(mmi_event_struct *evt);
#endif
#endif /* __VAPP_WAP_PUSH_INTERFACE_H__ */

