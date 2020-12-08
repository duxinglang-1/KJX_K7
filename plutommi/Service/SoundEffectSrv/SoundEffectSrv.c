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
 * Filename:
 * ---------
 *  SoundEffectSrv.cpp
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_srv_soundeffect_def.h"
#include "MMIDataType.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "nvram_default_audio.h"
#include "..\inc\SoundEffectSrvGprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define SRV_EFFECT_EQ_MAX_NUM   8    /* double check if NVRAM_EF_AUDIO_EQUALIZER_COUNT == MAX_EQUALIZER_NUM */
#define SRV_EFFECT_EQ_BARS_NUM  NVRAM_EF_AUDIO_EQUALIZER_BAND_NUM
#define SRV_EFFECT_EQ_NAME_MAX_LEN  23

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    S16 count;
    S16 index;
    signed char magnitude[SRV_EFFECT_EQ_MAX_NUM][SRV_EFFECT_EQ_BARS_NUM];
    unsigned char setting_name[SRV_EFFECT_EQ_MAX_NUM][(SRV_EFFECT_EQ_NAME_MAX_LEN + 1) * 2];
} srv_sound_effect_equalizer_struct;


typedef struct
{
    MMI_BOOL is_init;
    MMI_BOOL is_playing;
    U8 effect_type;
    void (*callback)(S32 result, void* user_data);
    void *user_data;
#if defined(__MMI_AUDIO_EQUALIZER__)
    srv_sound_effect_equalizer_struct eq_data;
#endif
} srv_sound_effect_cntx_struct;


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static srv_sound_effect_cntx_struct snd_effect;
static srv_sound_effect_cntx_struct *g_snd_effect = &snd_effect;

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
void srv_sound_effect_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!g_snd_effect->is_init)
    {
    #if defined(__MMI_AUDIO_EQUALIZER__)
        ReadRecord(NVRAM_EF_AUDIO_EQUALIZER_LID, 1, (void*)&g_snd_effect->eq_data, sizeof(srv_sound_effect_equalizer_struct), &error);
    #endif
        g_snd_effect->is_init = MMI_TRUE;
        g_snd_effect->effect_type= SRV_SOUND_EFFECT_TYPE_NONE;
        g_snd_effect->callback = NULL;
        g_snd_effect->user_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sound_effect_get_count
 * DESCRIPTION
 *  This function is to get number of each effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_sound_effect_get_count(srv_sound_effect_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SRV_SOUND_EFFECT_TYPE_EQ:
            return SRV_SOUND_EFFECTS_EQ_NUM;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_SURROUND:
            return SRV_SOUND_EFFECTS_SURROUND_NUM;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_REVERB:
            return SRV_SOUND_EFFECTS_REVERB_NUM;
    #endif
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sound_effect_get_name
 * DESCRIPTION
 *  This function is to get effect name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const kal_wchar* srv_sound_effect_get_name(srv_sound_effect_type_enum type, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if initialize */
    if(!g_snd_effect->is_init)
    {
        srv_sound_effect_init();
    }

    /* Get name by type */
    switch(type)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SRV_SOUND_EFFECT_TYPE_EQ:
        {
            if(index == -1)
            {
                return (const kal_wchar*)get_string(STR_ID_SRV_SOUND_EFFECT_EQ);
            }
            else
            {
                return (const kal_wchar*)get_string(STR_ID_SRV_SOUND_EFFECT_EQ_SET1 + index);            
            }
        }
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_SURROUND:
        {
            if(index == -1)
            {
                return (const kal_wchar*)get_string(STR_ID_SRV_SOUND_EFFECT_SURROUND);
            }
            else
            {
                return (const kal_wchar*)GetString(STR_ID_SRV_SOUND_EFFECT_SURROUND_MODE1 + index);
            }
        }
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_REVERB:
        {
            if(index == -1)
            {
                return (const kal_wchar*)get_string(STR_ID_SRV_SOUND_EFFECT_REVERB);
            }
            else
            {
                return (const kal_wchar*)GetString(STR_ID_SRV_SOUND_EFFECT_REVERB_SET1 + index);
            }
        }
    #endif
        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sound_effect_turn_on
 * DESCRIPTION
 *  This function is to turn on sound effects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sound_effect_turn_on(srv_sound_effect_type_enum type, U8 index, void (*callback)(S32 result, void* user_data), void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result set_result = MDI_AUDIO_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if initialize */
    if(!g_snd_effect->is_init)
    {
        srv_sound_effect_init();
    }

    /* Stop playing effect and callback */
    if(g_snd_effect->is_playing)
    {
        srv_sound_effect_turn_off();
    }

    /* Keep current effect type and turn on it */
    g_snd_effect->effect_type = type;
    switch(type)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SRV_SOUND_EFFECT_TYPE_EQ:
            mdi_audio_eq_set_magnitude((S8*)g_snd_effect->eq_data.magnitude[index]);
            set_result = mdi_audio_eq_turn_on();
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_SURROUND:
            set_result = mdi_audio_surround_turn_on(index);
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_REVERB:
            mdi_audio_reverb_set_mode(index);
            set_result = mdi_audio_reverb_turn_on();
            break;
    #endif
        default:
            g_snd_effect->effect_type = SRV_SOUND_EFFECT_TYPE_NONE;
            break;
    }

    if(set_result == MDI_AUDIO_SUCCESS)
    {
    	g_snd_effect->is_playing = MMI_TRUE;
    	g_snd_effect->callback = callback;
    	g_snd_effect->user_data = user_data;
    	return MMI_TRUE;
    }

    return MMI_FALSE;
}


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
void srv_sound_effect_turn_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if initialize */
    if(!g_snd_effect->is_init)
    {
        srv_sound_effect_init();
    }

    /* Callback to user */
    if(g_snd_effect->callback != NULL)
    {
        g_snd_effect->callback(SRV_SOUND_EFFECTS_RESULT_TURN_OFF, g_snd_effect->user_data);
    	g_snd_effect->callback = NULL;        
    	g_snd_effect->user_data = NULL;	
    }

    switch(g_snd_effect->effect_type)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__    
        case SRV_SOUND_EFFECT_TYPE_EQ:
            mdi_audio_eq_turn_off();
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_SURROUND:
            mdi_audio_surround_turn_off();
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_REVERB:
            mdi_audio_reverb_turn_off();
            break;
    #endif
        default:
            break;
    }
    
    g_snd_effect->effect_type = SRV_SOUND_EFFECT_TYPE_NONE;
	g_snd_effect->is_playing = MMI_FALSE;
}
#endif /* __COSMOS_MMI_PACKAGE__ */

