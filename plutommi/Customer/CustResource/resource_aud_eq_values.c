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
#include "MMI_features.h"
#include "MMIDataType.h"
#include "Gui_data_types.h"

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__

#include "Wgui_Categories_multimedia.h"

extern wgui_cat334_info_struct g_audio_equalizer_current_setting_info;

void mmi_aud_eq_init_image_specific_vals(void)
{
#if defined __MMI_MAINLCD_128X128__

    g_audio_equalizer_current_setting_info.bar_start_x = 22;
    g_audio_equalizer_current_setting_info.bar_start_y = 31;
    g_audio_equalizer_current_setting_info.bar_hor_gap = 6;
    g_audio_equalizer_current_setting_info.available_height = 64;
    g_audio_equalizer_current_setting_info.total_steps = 16;

#elif defined __MMI_MAINLCD_128X160__

    g_audio_equalizer_current_setting_info.bar_start_x = 25;
    g_audio_equalizer_current_setting_info.bar_start_y = 30;
    g_audio_equalizer_current_setting_info.bar_hor_gap = 6;
    g_audio_equalizer_current_setting_info.available_height = 64;
    g_audio_equalizer_current_setting_info.total_steps = 16;

#elif defined __MMI_MAINLCD_176X220__

    g_audio_equalizer_current_setting_info.bar_start_x = 29;
    g_audio_equalizer_current_setting_info.bar_start_y = 81;
    g_audio_equalizer_current_setting_info.bar_hor_gap = 7;
    g_audio_equalizer_current_setting_info.available_height = 80;
    g_audio_equalizer_current_setting_info.total_steps = 16;

#elif defined __MMI_MAINLCD_240X320__

    g_audio_equalizer_current_setting_info.bar_start_x = 41;
    g_audio_equalizer_current_setting_info.bar_start_y = 125;
    g_audio_equalizer_current_setting_info.bar_hor_gap = 12;
    g_audio_equalizer_current_setting_info.available_height = 112;
    g_audio_equalizer_current_setting_info.total_steps = 32;


#elif defined __MMI_MAINLCD_320X240__

    g_audio_equalizer_current_setting_info.bar_start_x = 75;
    g_audio_equalizer_current_setting_info.bar_start_y = 56;
    g_audio_equalizer_current_setting_info.bar_hor_gap = 13;
    g_audio_equalizer_current_setting_info.available_height = 112;
    g_audio_equalizer_current_setting_info.total_steps = 32;

#elif defined __MMI_MAINLCD_240X400__

    g_audio_equalizer_current_setting_info.bar_start_x = 60;
    g_audio_equalizer_current_setting_info.bar_start_y = 152;
    g_audio_equalizer_current_setting_info.bar_hor_gap = 10;
    g_audio_equalizer_current_setting_info.available_height = 112;
    g_audio_equalizer_current_setting_info.total_steps = 32;

#elif defined __MMI_MAINLCD_320X480__

    g_audio_equalizer_current_setting_info.bar_start_x = 77;
    g_audio_equalizer_current_setting_info.bar_start_y = 153;
    g_audio_equalizer_current_setting_info.bar_hor_gap = 16;
    g_audio_equalizer_current_setting_info.available_height = 182;
    g_audio_equalizer_current_setting_info.total_steps = 32;
    
#endif
}

#endif
