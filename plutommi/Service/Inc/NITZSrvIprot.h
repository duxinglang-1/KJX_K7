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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  NITZSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Nitz service internal prototypes
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef __SRV_NITZ_PROT_H__
#define __SRV_NITZ_PROT_H__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "CallSetSrvGprot.h"
#include "UcmSrvGprot.h" /* SRV_UCM_MAX_NUM_URI_LEN */
#ifdef __MMI_VIDEO_TELEPHONY__
#include "FileMgrGProt.h" /* SRV_FMGR_PATH_MAX_LEN */
#endif /* __MMI_VIDEO_TELEPHONY__ */


#include "MMIDataType.h"
#include "MMI_features.h"
#include "kal_non_specific_general_types.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef  enum
 *****************************************************************************/
typedef enum
{
    SRV_NITZ_OFF,
    SRV_NITZ_CONFIRM_FIRST,
    SRV_NITZ_ON
}srv_nitz_type_enum;

typedef enum
{
  	SRV_NITZ_STATE_OFF,
	SRV_NITZ_IDLE,
	SRV_NITZ_BUSY,
	SRV_NITZ_WAIT_UPDATE
} srv_nitz_state_enum;
/* data structure for event EVT_ID_SRV_NITZ_UPDATE */

/***************************************************************************** 
 * Internal Function
 *****************************************************************************/
extern void srv_set_nitz_state_ext(srv_nitz_state_enum state, U32 line);
 
extern srv_nitz_state_enum srv_get_nitz_state_ext(U32 line);

extern void srv_set_apply_nitz_type(srv_nitz_type_enum apply_type);

/* Get NITZ apply type */
extern srv_nitz_type_enum srv_get_apply_nitz_type(void);

extern void srv_nitz_msg_ind(void *msg, int mod_src);

#endif
