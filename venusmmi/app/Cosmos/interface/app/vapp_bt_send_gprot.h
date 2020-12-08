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
 *  vapp_bt_send_gprot.h
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  BT sending header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BT_SEND_GPROT_H__
#define __VAPP_BT_SEND_GPROT_H__
#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_features.h"
#ifdef __cplusplus
}
#endif
#ifdef __MMI_OPP_SUPPORT__
/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * the biggest number of objects one time to be sent
*/
#define VAPP_BTSENDING_MAX_OBJ              (50)

typedef enum
{
    VAPP_BT_SEND_DELETE_FILE = 1,           /* when finish sending, BT will help to delete the file */
    VAPP_BT_SEND_NONE
} vapp_bt_send_option_enum;

/***************************************************************************** 
 * Struct 
 *****************************************************************************/
typedef MMI_BOOL (*vapp_bt_send_get_next_obj) (WCHAR*, void*);

typedef struct 
{
    U32 group_id;                           /* app group id */
    vapp_bt_send_get_next_obj callback;     /* callback for getting next object to be sent */
    void *user_data;                        /* user data */
} vapp_bt_send_app_info;

/*****************************************************************************
 * FUNCTION
 *  bt_start_sending_obj
 * DESCRIPTION
 *  Venus BT sending function. APP can call this function to send object(s) via BT.
 * PARAMETERS
 *  app_info:           [IN] app info, including group id, callback and user_data
 *  option:             [IN] see vapp_bt_send_option_enum
 *  total:              [IN] the total objects to be sent
 *  obj_path_array:     [IN] objects array to be sent, if NULL, BT will use callback to get object
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
extern void vapp_bt_send_obj(vapp_bt_send_app_info *app_info, U32 option, U32 total, WCHAR** obj_path_array);
#ifdef __cplusplus
}
#endif
#endif // __MMI_OPP_SUPPORT__
#endif /* __VAPP_BT_SEND_GPROT_H__ */
