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
 *   w32_memory_card.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Memory card functions for Win32 environment
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __FS_CARD_SUPPORT__

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "fs_errcode.h"

typedef struct 
{
	//LOCAL_PARA_HDR
	kal_uint8 media_size;
	kal_uint8 media_index;
    #if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
	kal_uint8 media_status;
	kal_uint16 media_array_size;
	#endif	
	void *media_array;
}msdc_card_detect_ind_struct; 

void w32_SendILM(module_type destModuleID);

// Memory card is plugged in by default
static int g_MemoryCardStatus = FS_NO_ERROR;

int w32_MediaChanged(void *driveData)
{
    return g_MemoryCardStatus;
}

int w32_IsMemoryCardSupported()
{
    return 1;
}

void w32_PlugInMemoryCard()
{
    if (g_MemoryCardStatus != FS_NO_ERROR)
    {
        g_MemoryCardStatus = FS_NO_ERROR;

#ifndef FMT_NOT_PRESENT
        w32_SendILM(MOD_FMT);
#endif // FMT_NOT_PRESENT
    }
}

void w32_PlugOutMemoryCard()
{
    if (g_MemoryCardStatus != FS_MSDC_NOT_PRESENT)
    {
        g_MemoryCardStatus = FS_MSDC_NOT_PRESENT;

#ifndef FMT_NOT_PRESENT
        w32_SendILM(MOD_FMT);
#endif // FMT_NOT_PRESENT
    }
}

static void w32_SendILM(module_type destModuleID)
{
#ifdef __FS_MODIS_FDM__
    #include "w32_file_disk.h"
    extern FILE_DISK_INFO_T file_disk_info[];
#endif
    ilm_struct *msdcIlm;
    msdc_card_detect_ind_struct *msdcCardDetectInd;

    msdcCardDetectInd =
        (msdc_card_detect_ind_struct *)
            construct_local_para(sizeof(msdc_card_detect_ind_struct), TD_CTRL);

    msdcCardDetectInd->media_size = 1;
	#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
	if (g_MemoryCardStatus == FS_NO_ERROR) {
        msdcCardDetectInd->media_status=1;
		msdcCardDetectInd->media_index=1;
	}	
	else {
        msdcCardDetectInd->media_status=0;
		msdcCardDetectInd->media_index=1;
	}
	#endif
#ifdef __FS_MODIS_FDM__
    msdcCardDetectInd->media_array = &file_disk_info[CARD_DISK];
#else
    msdcCardDetectInd->media_array = NULL;
#endif

    msdcIlm = allocate_ilm(MOD_DRV_HISR);
    msdcIlm->src_mod_id = MOD_DRV_HISR;
    msdcIlm->dest_mod_id = destModuleID;
    msdcIlm->sap_id = DRIVER_PS_SAP;
    msdcIlm->msg_id = MSG_ID_MSDC_CARD_DETECT_IND;
    msdcIlm->local_para_ptr = (local_para_struct *) msdcCardDetectInd;
    msdcIlm->peer_buff_ptr = NULL;

    msg_send_ext_queue(msdcIlm);
}

#else

#include "fs_errcode.h"
int w32_MediaChanged(void *driveData) { return FS_MSDC_NOT_PRESENT; }
int w32_IsMemoryCardSupported() { return 0; }
void w32_PlugInMemoryCard() { }
void w32_PlugOutMemoryCard() { }

#endif // __FS_CARD_SUPPORT__
