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
 *   VdoRecCui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Recorder Common UI header file.
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
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"
#include "mmi_features_camcorder.h"

#include "mmi_include.h"

#include "CamcorderCui.h"
#include "CamcorderCuiGprot.h"
#include "CamcorderGprot.h"
#include "CamcorderResDef.h"
#include "MMIDataType.h"
#include "string.h"
#if defined(__MMI_CAMCORDER__)
#include "mmi_rp_app_camco_def.h"
#endif
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"

/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* Function Declaration
*******************************************************************************/

/*******************************************************************************
* External Function Declaration
*******************************************************************************/
extern mmi_ret mmi_camco_group_proc(mmi_event_struct *evt);

/*******************************************************************************
* Function Realization 
*******************************************************************************/
#if defined(__MMI_CAMCORDER__)

void cui_camco_struct_init(p_cui_camco_run_struct p_args)
{
    memset(p_args, 0, sizeof(cui_camco_run_struct));
    p_args->mode= 0;
}

mmi_id cui_camco_create(mmi_id parent_gid)
{
    mmi_frm_group_close(SCR_GROUP_ID_CAMCO_INT_APP);
    return mmi_frm_group_create(parent_gid, SCR_GROUP_ID_CAMCO_INT_APP, mmi_camco_group_proc, NULL);

}

MMI_BOOL cui_camco_check_and_display_popup(void)
{
    return mmi_camco_check_and_display_popup();
}

void cui_camco_run(mmi_id cui_gid, p_cui_camco_run_struct p_args)
{
    mmi_camco_enter_from_cui(cui_gid, p_args);
}

void cui_camco_close(mmi_id cui_gid)
{
    mmi_frm_group_close(cui_gid);
}


#endif


