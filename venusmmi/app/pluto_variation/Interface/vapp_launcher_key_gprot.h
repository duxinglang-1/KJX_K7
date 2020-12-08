/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_launcher_key_gprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the keylauncher launcher.
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

#ifndef VAPP_KEYLAUNCHER_GPROT_H
#define VAPP_KEYLAUNCHER_GPROT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"


/*****************************************************************************
 * Include
 *****************************************************************************/


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * Config
 *****************************************************************************/


/*****************************************************************************
 * Macro
 *****************************************************************************/


/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_key_create
 * DESCRIPTION
 *  This function creates the keylauncher, mean to create homescreen.
 * PARAMETERS
 *  group_id  : [IN] parent group ID of app category
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_launcher_key_create(MMI_ID group_id);


/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_key_release
 * DESCRIPTION
 *  This function releases the keylauncher, mean to release homescreen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_launcher_key_release(void);


/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_key_launch
 * DESCRIPTION
 *  This function is a dummy function used in the resource XML. It always
 *  return GRP_ID_INVALID because only the Bootup App can launch the keylauncher.
 * PARAMETERS
 *  param           : [IN]      Paramter
 *  param_size      : [IN]      Parameter size
 * RETURNS
 *  Group ID.
 *****************************************************************************/
extern MMI_ID vapp_launcher_key_launch(void *param, U32 param_size);


/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_key_on_before_idle_display
 * DESCRIPTION
 *  This function is to store some flag, before enter keylauncher
 *  If this function is called, mean to enter Idle page or Widget page, not enter Mainmenu page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_launcher_key_on_before_idle_display(void);


/* the application package name (include the terminal character) */
#define MMI_VAPP_WIDGET_NAME_MAX_LEN   (30)

/* the struct of application package name */
typedef WCHAR mmi_vapp_widget_name_struct[MMI_VAPP_WIDGET_NAME_MAX_LEN];


/*****************************************************************************
 * Adapter for Plut setting to call Venus Widget Kit function
 *****************************************************************************/
extern S32 vapp_keylauncher_get_widget_total_num(void);


/*****************************************************************************
 * Adapter for Plut setting to call Venus Widget Kit function
 *****************************************************************************/
extern void vapp_keylauncher_get_widget_name_list(mmi_vapp_widget_name_struct * name_array);

extern void vapp_keylauncher_get_widget_ids(S32 *ids);  // [OUT]

extern void vapp_keylauncher_get_widget_name_list_by_ids(
					mmi_vapp_widget_name_struct * name_array,  // [OUT]
					S32 *ids,    // [IN]
					S32 count);  // [IN]





#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */
#endif /* VAPP_KEYLAUNCHER_GPROT_H */


