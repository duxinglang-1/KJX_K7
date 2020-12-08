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
 *   pns_trc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Push notification service and engine traces definition
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _TRC_PNS_H
#define _TRC_PNS_H


#ifndef GEN_FOR_PC
#include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"


#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "pns_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_NMS)

    TRC_MSG(TRC_SRV_PNS_166be444de2146db8c5fa64f942a5de4, "[SRV_PNS] Find req (%d, %d)")
    TRC_MSG(TRC_SRV_PNS_b389d98874e94a3397f7a803beb9c26a, "[SRV_PNS] Register (%d)")
    TRC_MSG(TRC_SRV_PNS_c284149e950c436f95a993fe69b2c20a, "[SRV_PNS] Deregister (%d)")
    TRC_MSG(TRC_SRV_PNS_113f6e4db9bb4bf1976b664e527c1cb1, "[SRV_PNS] Set msg callback (%d)")
    TRC_MSG(TRC_SRV_PNS_5fb17f944d1344d689c7687b93c17ae3, "[SRV_PNS] Handle request rsp (%d, %d)")
    TRC_MSG(TRC_SRV_PNS_QC_5fb17f944d1344d689c7687b93c17ae3, "[SRV_PNS] regId (%s)")
    TRC_MSG(TRC_SRV_PNS_57fa5f4bbbe34a4ab6b21a8a7ce0fb96, "[SRV_PNS] Handle unsolicited msg (%d)")
    TRC_MSG(TRC_SRV_PNS_QC_57fa5f4bbbe34a4ab6b21a8a7ce0fb96, "[SRV_PNS] msg (%s)")
    TRC_MSG(TRC_SRV_PNS_14da7cb659d84555ac66f20dca38267c, "[SRV_PNS] query (%d)")
    TRC_MSG(TRC_SRV_PNS_QC_14da7cb659d84555ac66f20dca38267c, "[SRV_PNS] query regId (%s)")
    TRC_MSG(TRC_SRV_PNS_360d0e29bf1542ceae1719af363518f0, "[SRV_PNS] Flight mode (%d)")
    TRC_MSG(TRC_SRV_PNS_4008c72958bc477680ec923fe8487bf7, "[SRV_PNS] Search object (%d)")
    TRC_MSG(TRC_SRV_PNS_b899b98bfa5947f99aa06c9b64e2fe27, "[SRV_PNS] Get object (%d)")
    TRC_MSG(TRC_SRV_PNS_d3753130f54443a1b2b550d4e0bf3bae, "[SRV_PNS] Parse mps (%d)")
    TRC_MSG(TRC_SRV_PNS_fd44c8688a0740e8995ab4127f02a2d2, "[SRV_PNS] Register cbm event callback (%d)")
    TRC_MSG(TRC_SRV_PNS_cc5b0ae0b7314ded9b178ec16ce64a64, "[SRV_PNS] Cbm event disconnect")
    TRC_MSG(TRC_SRV_PNS_cbe721a3d3484328bbe7598d22725712, "[SRV_PNS] Cbm event switch (%d, %d)")
    TRC_MSG(TRC_SRV_PNS_bf22764593d5431ba4103f0e46b74b74, "[SRV_PNS] Encrypt (%d)")
    TRC_MSG(TRC_SRV_PNS_0c0234b554e94e33bb3310f0c9db5e12, "[SRV_PNS] Decrypt (%d)")
    TRC_MSG(TRC_SRV_PNS_37cc3d31c15e46ef8dee105cee153ab2, "[SRV_PNS] Has custom object (%d, %d)")
    TRC_MSG(TRC_SRV_PNS_f259e52cedb140c886b281182df3e682, "[SRV_PNS] SIM ctrl event detected (%d, %d, %d)")
    TRC_MSG(TRC_SRV_PNS_0ef09041462b4623b66cf5a387a71c2b, "[SRV_PNS] CBM_BEARER_INFO broadcast (%d, %d)")
    TRC_MSG(TRC_SRV_PNS_e3cbf98f0e3746a5b356604fe7dc7cfd, "[SRV_PNS] Confirm with user to upload device info")
    TRC_MSG(TRC_SRV_PNS_65a49cdf234b4fa9b0c573f80b0c651a, "[SRV_PNS] Show warning")
    TRC_MSG(TRC_SRV_PNS_8ce568f74b8a44b49c089d7f797172be, "[SRV_PNS] Agree to upload device info")
    TRC_MSG(TRC_SRV_PNS_68bda4ef7ba545f9abd0adb383dc811c, "[SRV_PNS] Disagree to upload device info")
    TRC_MSG(TRC_SRV_PNS_2bbd7f0e594f440f9f4a1d627064837b, "[SRV_PNS] Get click rate (%d)")
    TRC_MSG(TRC_SRV_PNS_1cdc3f7cdfaa4adabc4d8bdab55293fa, "[SRV_PNS] CBM info callback (%d, %d, %d)")
    TRC_MSG(TRC_SRV_PNS_c6d8090c29b14b95bc6ec239225f6837, "[SRV_PNS] Force close (%d, %d, %d)")
    TRC_MSG(TRC_SRV_PNS_c7aff01de57d4be8ae684d51b48c29f8, "[SRV_PNS] Force close start (%d, %d, %d, %d)")
    TRC_MSG(TRC_SRV_PNS_fa7a628ab560498cba42ed306a874269, "[SRV_PNS] Response dtcnt, closed done (%d, %d, %d, %d)")
    TRC_MSG(TRC_SRV_PNS_02a81689ac0947e59608e59555ea6e0a, "[SRV_PNS] Resume connection")
    TRC_MSG(TRC_SRV_PNS_7d845edb498a4b7e91cf58bfd6462b04, "[SRV_PNS] Get object, query mps! %d")
    TRC_MSG(TRC_SRV_PNS_81c5f76d8d2340d2a79762311edf068a, "[SRV_PNS] Revise mps payload (%d, %d)")

    TRC_MSG(TRC_HPNS_166be444de2146db8c5fa64f942a5de4, "[HPNS] hpnsSaveHpnsInfo (%d)")
    TRC_MSG(TRC_HPNS_c284149e950c436f95a993fe69b2c20a, "[HPNS] hpnsReadHpnsInfo (%d)")
    TRC_MSG(TRC_HPNS_0b00c6f01c5a4404bd84d08e21c156be, "[HPNS] To Engine (%d)")
    TRC_MSG(TRC_HPNS_0e908191eef14f2a95487e3dd32afb10, "[HPNS] To UI (%d)")
    TRC_MSG(TRC_HPNS_d1aca1acdae240618d6d43fc58be5d03, "[HPNS] hpnsInitTask (%d)")
    TRC_MSG(TRC_HPNS_7be32a6f57cc4e869f7b1987694368b2, "[HPNS] hpnsInitTask (%d %d %d %d)")
	TRC_MSG(TRC_HPNS_b74207c1e6bc4e49ab23a8b1491990ce, "[HPNS] hpnsProcessRegistrationReq (%d)")
	TRC_MSG(TRC_HPNS_135c6fc638ce4cec99341d3c86983f2e, "[HPNS] hpnsProcessUnRegistrationReq (%d)")
	TRC_MSG(TRC_HPNS_66a1d971b4c74253854ad9092badd884, "[HPNS] hpnsProcessPushNotificationSwitch (%d, %d)")	
	TRC_MSG(TRC_HPNS_63c0838aa64d45de9f13393ce9328b26, "[HPNS] hpnsProcessChangeConnMode (%d, %d)")
	TRC_MSG(TRC_HPNS_7ff3b223b2a94c7b923079d9b2a98a4e, "[HPNS] hpnsProcessNetworkStatechanged (%d, %d, %d, %d)")
	TRC_MSG(TRC_HPNS_7e8b39bdf26645d091afd580a5fe78cd, "[HPNS] hpnsHandleMsg, %d")
	TRC_MSG(TRC_HPNS_857dd200b4dd4d44bcb9bc7ec898fb21, "[HPNS] HPNS task is cleaned up")	
    TRC_MSG(TRC_HPNS_1c1eae39c8a141b89eb2a3f2fd5212f2, "[HPNS] soc_result (%d, %d)")
    TRC_MSG(TRC_HPNS_a97f67bbbb914eae984b534e93e4ed51, "[HPNS] Open UDP socket (%u, %d)")
    TRC_MSG(TRC_HPNS_c9c82ebfe28a411facc6cc0a04f9761a, "[HPNS] Open UDP socket fail")
    TRC_MSG(TRC_HPNS_7b8b99d5b19d424caaad79af871e68d4, "[HPNS] Close UDP socket %d")
    TRC_MSG(TRC_HPNS_709ea4a50bac4edaa24851be1c0aa863, "[HPNS] Pre process incoming msg, reset type")
    TRC_MSG(TRC_HPNS_5c0e84c82f1140a89311c735856e14ad, "[HPNS] Get server ip via DNS %d")
    TRC_MSG(TRC_HPNS_20efbd7b67bd4aceb6a617901ea868b7, "[HPNS] Get ip from DNS - 1 > (%d, %d)")
    TRC_MSG(TRC_HPNS_6c0722106c4643ea957adf0c29b2a226, "[HPNS] Get ip from DNS - 2 > (%d, %u)")
	TRC_MSG(TRC_HPNS_6f59731d5bcb46548bea6cefaa5743a1, "[HPNS] To push server (%d, %d)")
	TRC_MSG(TRC_HPNS_eda46fe0a47840abb3ed93211049f6f7, "[HPNS] hpnsPreProcessIncomingMsg (%d)")
	TRC_MSG(TRC_HPNS_7d2c0f7b853a418fadaa0c3ec7bfe545, "[HPNS] Pre process incoming msg (%d, %d)")
	TRC_MSG(TRC_HPNS_99b15e2e823b4ad6976ffd098846001f, "[HPNS] %d bytes data is received from push server")
	TRC_MSG(TRC_HPNS_7ec8173c83e84543b0ee88111a923314, "[HPNS] Last message is sending")
    TRC_MSG(TRC_HPNS_c479b293ad814c22ae4fdd306f5954b6, "[HPNS] set Timer (%d, %d)")
    TRC_MSG(TRC_HPNS_9f209ffdfa2e4638b8d07665a6fe99ee, "[HPNS] kill Timer %d")
	TRC_MSG(TRC_HPNS_87b331ec8851496d8e7739daa081f4bb, "[HPNS] Timer Callback (%d, %d)")
    TRC_MSG(TRC_HPNS_b0a60f1d29d1471bafaa16eb04f697d8, "[HPNS] Soc Notify result=%d type=%d error=%d")
	TRC_MSG(TRC_HPNS_eb06db410c8e43efb5977ce5c779bdaa, "[HPNS] hpnsUpdateMru (%x%x%x%x%x)")
	TRC_MSG(TRC_HPNS_041b26450bcb41c68eee7bd141885915, "[HPNS] Set connection to push server (%x)")
	TRC_MSG(TRC_HPNS_0f74e67930f9471fa52f5e75c96f5f51, "[HPNS] hpnsHandleConnectionError (%d, %d, %d)")
	TRC_MSG(TRC_HPNS_2d532504164f40a6aa3d96e1ea4e0ae7, "[HPNS] Process Connection Timer (%d)")	
	TRC_MSG(TRC_HPNS_0420270bbda24afc8ddf788708b6550a, "[HPNS] Close connection to push server")
	TRC_MSG(TRC_HPNS_320103a2bd6d48e3bb0259b5f1ce4b28, "[HPNS] Start registration (%d, %d)")
    TRC_MSG(TRC_HPNS_fae225b77dff4dce973d33fd97c79e90, "[HPNS] Open connection to push server start (%d)")
	TRC_MSG(TRC_HPNS_051274eb92784374b10b0a7127b11c21, "[HPNS] Open connection to push server at step (%d)")
    TRC_MSG(TRC_HPNS_8aa6d6f63f4541a2b49b1b5574fae03a, "[HPNS] Open connection to push server end (%d)")
	TRC_MSG(TRC_HPNS_f6c739dd408a40ba8c4c4c37dc97648e, "[HPNS] Check List (%d, %d, %d)")
	TRC_MSG(TRC_HPNS_02552340f13b4603abc27bdf738659cf, "[HPNS] Process Response (%d, %d)")
	TRC_MSG(TRC_HPNS_20d7815f2a6543039b53e2dc70d947a5, "[HPNS] Process Response (%d)")
	TRC_MSG(TRC_HPNS_96426e290a6f4885a318d69b8062ec8f, "[HPNS] Process Response (%d, %d, %d, %d, %d, %d)")
	TRC_MSG(TRC_HPNS_acce7f174f9448fa894579fb6228db9a, "[HPNS] Process deliver msg from push server")
	TRC_MSG(TRC_HPNS_a0edf79c8a514ae695fa621c67e248d0, "[HPNS] Notification message is duplicated, drop it, msgId:%d")
	TRC_MSG(TRC_HPNS_c8be2741947241e6bfc0fb0b5b299680, "[HPNS] Receive msg from push server (%d)")
	TRC_MSG(TRC_HPNS_1e8a3f917039460f9cc9afba974f9548, "[HPNS] Receive msg from push server (%d, %d)")
	TRC_MSG(TRC_HPNS_7120bd2cb24443b9bf48356dc8d2ed83, "[HPNS] Process heartbeat response (%d)")
    TRC_MSG(TRC_HPNS_540bff66a3ea48cdb1af66d616a874f6, "[HPNS] Process heartbeat timer (%d, %d)")
	TRC_MSG(TRC_HPNS_07a540586b15493d9878cdefca122b4a, "[HPNS] Process Transaction Timer (%d, %d, %x, %d)")
	TRC_MSG(TRC_HPNS_07c099c5ff5746d9902eb40dfbbcc3b4, "[HPNS] Clean App (%d)")
	TRC_MSG(TRC_HPNS_c9d6c318e29f46468667a1fcf0d8f127, "[HPNS] Parse ie from push server (%d)")
    TRC_MSG(TRC_HPNS_8cb4cf44effd4da8a3005b71d236dd4d, "[HPNS] Query account id (%u)")
	TRC_MSG(TRC_HPNS_d1f534a8f72542e2af02bb6c94f86942, "[HPNS] Account id (%u, %d)")

    TRC_MSG(TRC_HPNS_QC_17109e7e17c7408ab32834b1f11ca223, "[HPNS] hpnsCompareAndMergeAppList (%d, %d)")
    TRC_MSG(TRC_HPNS_QC_8f0d1f78b81241bfb2400a3019a4769d, "[HPNS] hpnsProcessNotificaitonResp (%d, %d)")

END_TRACE_MAP(MOD_NMS)

#endif /* _TRC_PNS_H */
