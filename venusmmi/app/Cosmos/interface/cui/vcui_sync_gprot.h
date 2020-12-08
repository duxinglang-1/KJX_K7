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
 *  vcui_sync_gprot.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h" 

#ifndef __VCUI_SYNC_GPROT_H__
#define __VCUI_SYNC_GPROT_H__

#include "MMIDataType.h"
#include "vfx_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************
 * FUNCTION
 *  vcui_sync_create
 * DESCRIPTION
 *  create sync cui, if there is background sync, GROUP_ID_INVALID will be return
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id vcui_sync_create(mmi_id parent_id, void *usr_data);


/*****************************************************************************
 * FUNCTION
 *  vcui_sync_run
 * DESCRIPTION
 *  run sync cui
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_sync_set_database(mmi_id cui_id, U32 db_mask);


/*****************************************************************************
 * FUNCTION
 *  vcui_sync_run
 * DESCRIPTION
 *  run sync cui
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_sync_run(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  vcui_sync_close
 * DESCRIPTION
 *  close sync cui
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_sync_close(mmi_id cui_id);

#ifdef __MMI_SYNCML_CCA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vcui_sync_otap_create
 * DESCRIPTION
 *  close sync cui
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id vcui_sync_otap_create(mmi_id parent_id, void *usr_data);

/*****************************************************************************
 * FUNCTION
 *  vcui_sync_otap_set_info
 * DESCRIPTION
 *  close sync cui
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_sync_otap_set_total(mmi_id cui_id, U16 total);

/*****************************************************************************
 * FUNCTION
 *  vcui_sync_otap_run
 * DESCRIPTION
 *  close sync cui
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/

void vcui_sync_otap_run(mmi_id cui_id);

/*****************************************************************************
 * FUNCTION
 *  vcui_sync_otap_close
 * DESCRIPTION
 *  close sync cui
 * PARAMETERS
 *  cui_id          :           [IN]        cui id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_sync_otap_close(mmi_id cui_id);
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */


#ifdef __cplusplus
}
#endif

#endif  /* __VCUI_SYNC_GPROT_H__ */



