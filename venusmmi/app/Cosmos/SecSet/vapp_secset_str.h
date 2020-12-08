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
 *  vapp_secset_str.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Security setting
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

#ifndef __VAPP_SECSET_STR_H__
#define __VAPP_SECSET_STR_H__


#include "MMI_features.h"
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
extern "C"
{
#include "SimCtrlSrvGprot.h"
}


namespace VappSecSetStr
{
    enum SimStrEnum
    {
        STR_SIM_BLOCKED = 0,

        SIM_STR_TOTAL
    };

    enum ChvStrEnum
    {
        STR_INPUT_CHV = 0,
        STR_WRONG_CHV,
        STR_OLD_CHV,
        STR_NEW_CHV,
        STR_CONFIRM_CHV,
        STR_DIFF_CHV,
        STR_CHV_DISABLED,
        STR_CHV_CHANGED,

        STR_CHV_BLOCKED,
        STR_CHV_BLOCKED_REQ_UBCHV,
        STR_INPUT_UBCHV,
        STR_WRONG_UBCHV,
        STR_UBCHV_BLOCKED,
        STR_CHV_UNBLOCKED,

        CHV_STR_TOTAL
    };

    VfxResId getSimIDNameByIndex(VfxS32 simIndex);

    VfxWString composeSimStr(
        VfxResId str_template_id,
        mmi_sim_enum sim);

    VfxWString getSimStr(mmi_sim_enum sim, SimStrEnum type);

    VfxWString getChvStr(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum chv_type,
        ChvStrEnum str_type);

    VfxWString getSimFailureMessage(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum chv_type,
        srv_sim_ctrl_fail_cause_enum cause);

    VfxWString getRemainingPromptStr(
        S32 nRemainingAttempts,
        VfxObject *tempBufferSrc);

    VfxWString getFailureMsgWithRemaining(
        const VfxWString &prompt,
        S32 nRemainingAttempts,
        VfxObject *tempBufferSrc);

}

#endif /* __VAPP_SECSET_STR_H__ */
