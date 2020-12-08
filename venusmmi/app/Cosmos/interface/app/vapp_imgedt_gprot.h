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
 *  vapp_imgedt_gprot.h
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

#ifndef __VAPP_IMGEDT_GPROT_H__
#define __VAPP_IMGEDT_GPROT_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "MMI_features.h"
#ifdef __MMI_COSMOS_PHOTOEDITOR__
#include "MMIDataType.h"
#include "FileMgrSrvGprot.h"

/*****************************************************************************  
*   enum
*****************************************************************************/
/* Image editor callback event enum */
typedef enum
{
    EVT_ID_IMGEDT_BEGIN_SAVE,
    EVT_ID_IMGEDT_SAVED    /* Edit and save as an other file */
}vapp_imgedt_evt_enum;

/* Image editor rotation */
typedef enum
{
    VAPP_IMGEDT_SCR_ROTATE_0,  
    VAPP_IMGEDT_SCR_ROTATE_90,
    VAPP_IMGEDT_SCR_ROTATE_270,
    
    VAPP_IMGEDT_ROTATE_TOTAL
}vapp_imgedt_scr_rotate_enum;

/*****************************************************************************  
*   structure
*****************************************************************************/
typedef struct
{
    mmi_id    parent_id;
    vapp_imgedt_scr_rotate_enum rotate;
    WCHAR     filePath[SRV_FMGR_PATH_MAX_LEN + 1];
}vapp_imgedt_launch_struct;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    WCHAR *filePath;
}vapp_imgedt_event_struct;

/*****************************************************************************  
*   function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_vapp_imgedt_util_check_file_support
 * DESCRIPTION
 *  Query if file is support
 * PARAMETERS 
 *  path            : [IN] Image path
 * RETURNS
 *  onwer id
 *****************************************************************************/
extern MMI_BOOL vapp_imgedt_is_file_support(const WCHAR *filePath);

/*****************************************************************************
 * FUNCTION
 *  vapp_image_editor_launch
 * DESCRIPTION
 *  launch image editor
 * PARAMETERS 
 *  param            : [IN] vapp_imgedt_launch_struct
 *  param						 : [IN] size of vapp_imgedt_launch_struct
 * RETURNS
 *  onwer id
 *****************************************************************************/
extern mmi_id vapp_imgedt_launch(void *param, U32 param_size);


#endif /* __MMI_COSMOS_PHOTOEDITOR__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __VAPP_IMGEDT_GPROT_H__ */
