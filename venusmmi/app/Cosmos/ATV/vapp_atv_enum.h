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
 *  vapp_atv_enum.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  vapp_atv_enum
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#ifndef __VAPP_ATV_ENUM_H__
#define __VAPP_ATV_ENUM_H__

#ifdef __MMI_ATV_SUPPORT__

/*******************************************
 * Enum
 *******************************************/

enum VAPP_ATV_KERNEL_STATE_ENUM
{
    ATV_KERNEL_CLOSED,      /* 0 */
    ATV_KERNEL_CLOSING,     /* 1 */
    ATV_KERNEL_OPENED,      /* 2 */
    ATV_KERNEL_SCANNING,    /* 3 */
    ATV_KERNEL_INIT,        /* 4 */
    ATV_KERNEL_READY        /* 5 */
};

enum VAPP_ATV_PLAYER_STATE_ENUM
{
    ATV_PLAYER_STOPPED,     /* 0 */
    ATV_PLAYER_BT_CONNECT,  /* 1 */
    ATV_PLAYER_PLAY         /* 2 */
};

enum VAPP_ATV_RECORDER_STATE_ENUM
{
    ATV_RECORDER_STOPPED,       /* 0 */
    ATV_RECORDER_RECORD,        /* 1 */
    ATV_RECORDER_PAUSED,        /* 2 */
    ATV_RECORDER_SAVE_CONFIRM,  /* 3 */
    ATV_RECORDER_SAVING,        /* 4 */
    ATV_RECORDER_DELETING       /* 5 */
};

enum VAPP_ATV_DISP_TYPE_ENUM
{
    ATV_DISP_CTRL_PANEL,    /* 0 */
    ATV_DISP_PLAYER_SETTING,/* 1 */
    ATV_DISP_SCAN_PROG,     /* 2 */
    ATV_DISP_AUD_MODE,      /* 3 */
    ATV_DISP_THUMBNAIL,     /* 4 */
    ATV_DISP_RECORDER,      /* 5 */
    ATV_DISP_RECORD_CONFIRM,/* 6 */
    ATV_DISP_POPUP_CONFIRM, /* 7 */
    ATV_DISP_PATH_CONFIRM,  /* 8 */
    ATV_DISP_QUICK_PREVIEW
};

#endif // __MMI_ATV_SUPPORT__
#endif /* __VAPP_ATV_ENUM_H__ */
