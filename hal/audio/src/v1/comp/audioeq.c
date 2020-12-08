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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * audioEQ.c
 *
 * Project:
 * --------
 * Maui
 *
 * Description:
 * ------------
 * Audio EQ Manager
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#if defined(__BES_EQ_SUPPORT__)

#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "string.h"
#include "l1audio.h"
#include "common_def.h"
#include "audio_def.h"
#include "afe_def.h"
#include "l1sp_trc.h"
#include "am.h"
#include "afe.h"
#include "BesEQ_exp.h"

static kal_bool aeq_enable = false;
BEQ_RuntimeParam  BEQ_RTParam;
extern kal_uint32 BES_EQ_Band_Num;

void AudioPP_Equalizer_TurnOn( void )
{
   HOST_APM_Register(APM_TASKID_EQ);
   aeq_enable = true;
}

void AudioPP_Equalizer_TurnOff( void )
{
   aeq_enable = false;
   HOST_APM_UnRegister(APM_TASKID_EQ);
}

kal_bool AudioPP_Equalizer_IsEnable( void )
{
   return aeq_enable;
}

void AudioPP_EQ_Init(APM_TCM *tcm)
{
   aeq_enable = false;
}

void AudioPP_Equalizer_SetMag_Flexible(kal_int8 *band_mag)
{
    kal_int16 i;

    for (i = 0; i < BES_EQ_Band_Num; i++)
    {
        BEQ_RTParam.Gain_dB_level[i] = band_mag[i];
    }
    
    for (i = BES_EQ_Band_Num; i < BEQ_MAX_BAND_NUMBER; i++)
    {
        BEQ_RTParam.Gain_dB_level[i] = 0;
    }

    APM_SetPP_Param(APM_TASKID_EQ, sizeof(BEQ_RuntimeParam), &BEQ_RTParam, 0, 0);
}

void AudioPP_Equalizer_SetMag(kal_int8 pGain_dB_level[8])
{
    kal_uint32 i;
    
    for (i = 0; i < 8; i++)
    {
        BEQ_RTParam.Gain_dB_level[i] = pGain_dB_level[i];
    }

    APM_SetPP_Param(APM_TASKID_EQ, sizeof(BEQ_RuntimeParam), &BEQ_RTParam, 0, 0);
}

#endif  // defined(__BES_EQ_SUPPORT__)


