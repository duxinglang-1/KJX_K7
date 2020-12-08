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
*  ToneSelectorCui.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Tone selector common UI.
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef TONE_SELECTOR_CUI_H
#define TONE_SELECTOR_CUI_H
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "Mmi_rp_srv_prof_def.h"


typedef struct
{
    mmi_id      str_id;
    mmi_id      img_id;
    U16         tone_filter;
    U16         selected_tone;
    U8          is_used; 
}cui_tonesel_mem_struct;

typedef struct
{
    mmi_id      cur_gid;        /* the last active group id of CUI*/
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    mmi_id      fmgr_id;        /*file manager cui group id*/
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */
#if defined(__MMI_BASIC_UI_STYLE__) || defined(__OP01_FWPBW__)
    mmi_id      str_id;
    mmi_id      img_id;
    U16         tone_filter;
#endif
    U16         highlight_audioid;
    MMI_BOOL    is_playing;
    U8          volume;         /* 7 Level, Level 0 is mute (2nd bit on)*/
}cui_tonesel_cntx_struct;

typedef enum
{
    SCR_CUI_TONE_SELECTOR_LIST = TONE_SELECTOR_BASE + 1,
    SCR_CUI_ID_MAX
} cui_tone_selector_scr_enum;

typedef enum
{
    CUI_TONESEL_GET_MEMORY_FAIL, 
    CUI_TONESEL_GRP_NOT_ACTIVE,
    CUI_TONESEL_ERROR_MAX
} CUI_TONE_SELECTOR_ERROR;

typedef enum
{
    CUI_TONESEL_TONE_ID_BEGIN = AUD_ID_PROF_TONE_BEGIN + 1, 
    CUI_TONESEL_TONE_ID_END = AUD_ID_PROF_TONE_END,
    CUI_TONESEL_TONE_ID_NUM = CUI_TONESEL_TONE_ID_END - CUI_TONESEL_TONE_ID_BEGIN,
    CUI_TONESEL_RING_ID_BEGIN = AUD_ID_PROF_RING_BEGIN + 1, 
    CUI_TONESEL_RING_ID_END = AUD_ID_PROF_RING_END,
    CUI_TONESEL_RING_ID_NUM = CUI_TONESEL_RING_ID_END - CUI_TONESEL_RING_ID_BEGIN
} CUI_TONE_SELECTOR_DFT_AUDIO;


#endif /*TONE_SELECTOR_CUI_H*/
