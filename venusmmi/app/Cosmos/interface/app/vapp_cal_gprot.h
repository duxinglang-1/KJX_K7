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
 *  vapp_cal_gprot.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Declaration: 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __VAPP_CAL_GPROT_H__
#define __VAPP_CAL_GPROT_H__
 

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#include "vfx_datatype.h"
#ifdef __cplusplus
extern "C"
{
#endif

    #include "todolistsrvgprot.h"
    #include "vcalsrvgprot.h"
    #include "conversions.h"
    #include "app_datetime.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum 
{
	VAPP_CAL_SYNCML_GET,
	VAPP_CAL_SYNCML_ADD,
	VAPP_CAL_SYNCML_MODIFY,
	VAPP_CAL_SYNCML_DELETE,
	VAPP_CAL_SYNCML_TOTAL_OPERATIONS
}VappCalSyncOpEnum;

typedef enum 
{
	VAPP_CAL_SYNCML_ERR_NO_ERROR,
	VAPP_CAL_SYNCML_ERR_NOT_FOUND,
	VAPP_CAL_SYNCML_ERR_EMPTY_NAME,
	VAPP_CAL_SYNCML_ERR_DUPLICATE_NAME,
	VAPP_CAL_SYNCML_ERR_MEMORY_FULL,
	VAPP_CAL_SYNCML_ERR_INVALID_FILENAME,
	VAPP_CAL_SYNCML_ERR_SELECT_PATH_TOO_LONG,
	VAPP_CAL_SYNCML_ERR_UNSUPPORT_FORMAT,
	VAPP_CAL_SYNCML_ERR_UNKNOWN,
	VAPP_CAL_SYNCML_ERR_INVALID_INDEX,	  
	VAPP_CAL_SYNCML_ERR_DELETE_FAIL,	
	VAPP_CAL_SYNCML_ERR_INVALID_OPERATION,
	VAPP_CAL_SYNCML_ERR_TOTAL
}VappCalSyncErrorEnum;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
 
/***************************************************************************** 
 * Function
 *****************************************************************************/
VappCalSyncErrorEnum VappCalSync(srv_vcal_type_enum type, VappCalSyncOpEnum action, VfxU8 *path, VfxU16 *index, mmi_chset_enum sync_chset);
void vapp_calendar_launch_by_widget(applib_time_struct *currDt);

#ifdef __cplusplus
	}
#endif


#endif /* __VAPP_CAL_GPROT_H__ */

