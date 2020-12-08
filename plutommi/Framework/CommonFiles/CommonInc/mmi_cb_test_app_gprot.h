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
 * mmi_cb_test_app_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Application (caller) should define events and events struct here.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_CB_TEST_APP_GPROT_H
#define MMI_CB_TEST_APP_GPROT_H
#include "MMIDataType.h"

#ifdef MMI_CB_MGR_UT

typedef enum
{
	EVT_ID_PHONEBOOK_XXX = PHONE_BOOK_BASE + 1,
	EVT_ID_PHONEBOOK_YYY,
	EVT_ID_UT_PHONEBOOK_MAX
} mmi_cb_ut_phb_evt_enum;

typedef enum
{
	EVT_ID_IDLE_XXX = IDLE_APP_BASE + 1,
	EVT_ID_IDLE_YYY,
	EVT_ID_IDLE_MAX
} mmi_cb_ut_idle_evt_enum;

typedef enum
{
	EVT_ID_MM_XXX = MMEDIA_BASE + 1,
	EVT_ID_MM_MAX
} mmi_cb_ut_multimedia_evt_enum;

typedef enum
{
	EVT_ID_FMGR_COPY = FILE_MANAGER_BASE + 1,
	EVT_ID_FMGR_PASTE,
	EVT_ID_FMGR_REMOVE,
	EVT_ID_FMGR_NO_REG,
	EVT_ID_FMGR_STEP_1,
	EVT_ID_FMGR_STEP_2,
	EVT_ID_FMGR_STEP_3,
	EVT_ID_FMGR_MAX
} mmi_cb_ut_fmgr_evt_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U8 fmgr_type;
} mmi_fmgr_evt_stuct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U8 idle_type;
    S8 *buffer;
} mmi_idle_evt_stuct;

#endif /* MMI_CB_MGR_UT */

#endif /* MMI_CB_TEST_APP_GPROT_H */

