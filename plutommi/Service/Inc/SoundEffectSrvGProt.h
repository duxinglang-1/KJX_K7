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
 *  SoundEffectSrvGProt.h
 *
 * Project:
 * --------
 *  Cosmos
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SOUND_EFFECT_SRV_G_PROT_H__
#define __SOUND_EFFECT_SRV_G_PROT_H__

#ifdef __COSMOS_MMI_PACKAGE__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define SRV_SOUND_EFFECTS_EQ_NUM        8
#define SRV_SOUND_EFFECTS_SURROUND_NUM  2
#define SRV_SOUND_EFFECTS_REVERB_NUM    6

#define SRV_SOUND_EFFECTS_RESULT_TURN_OFF -1

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    SRV_SOUND_EFFECT_TYPE_NONE,
    SRV_SOUND_EFFECT_TYPE_EQ,
    SRV_SOUND_EFFECT_TYPE_SURROUND,
    SRV_SOUND_EFFECT_TYPE_REVERB,
    SRV_SOUND_EFFECT_TYPE_TOTAL
}srv_sound_effect_type_enum;


/***************************************************************************** 
 * Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_sound_effect_init
 * DESCRIPTION
 *  This function is to init variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sound_effect_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sound_effect_get_count
 * DESCRIPTION
 *  This function is to get number of each effect
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  number of each effect
 *****************************************************************************/
U8 srv_sound_effect_get_count(srv_sound_effect_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_sound_effect_get_name
 * DESCRIPTION
 *  This function is to get effect name
 * PARAMETERS
 *  type    : [IN] effect type in srv_sound_effect_type_enum
 *  index   : [IN] effect index
 * RETURN VALUES
 *  name string of the effect
 *****************************************************************************/
const kal_wchar* srv_sound_effect_get_name(srv_sound_effect_type_enum type, S16 index);

/*****************************************************************************
 * FUNCTION
 *  srv_sound_effect_turn_on
 * DESCRIPTION
 *  This function is to turn on sound effects
 * PARAMETERS
 *  type    : [IN] effect type in srv_sound_effect_type_enum
 *  index   : [IN] effect index
 *  callback    : [IN] call back application if effect is turned off (SRV_SOUND_EFFECTS_RESULT_TURN_OFF)
 *  user data   : [IN] user data, will pass back in the callback function
 * RETURN VALUES
 *  MMI_TRUE  : turn on effect success
 *  MMI_FALSE : turn on effect fail
 *****************************************************************************/
MMI_BOOL srv_sound_effect_turn_on(srv_sound_effect_type_enum type, U8 index, void (*callback)(S32 result, void* user_data), void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sound_effect_turn_off
 * DESCRIPTION
 *  This function is to turn off sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sound_effect_turn_off(void);


#endif /*__COSMOS_MMI_PACKAGE__*/
#endif /* __SOUND_EFFECT_SRV_G_PROT_H__ */

