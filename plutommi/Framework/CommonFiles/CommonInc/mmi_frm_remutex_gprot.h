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
 *    mmi_frm_remutex_prot.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Recursive mutex mechanism
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_FRM_REMUTEX_PROT_H
#define MMI_FRM_REMUTEX_PROT_H


#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#ifdef __cplusplus
extern "C"
{
#endif


/*
 * recursive mutex data struct
 */
typedef struct
{
    /* Mutex id */
    kal_mutexid mutexID;
    kal_taskid taskid;
    /* Reference count */
    kal_uint32 ref_count;
} mmi_frm_recursive_mutex_struct;


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_recursive_mutex_init
 * DESCRIPTION
 *  Recursive mutex intialize.
 * PARAMETERS
 *  mutex         : [OUT]       the mutex that needs to create.
 *  mutex_name    : [IN]       mutex name.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_recursive_mutex_init(mmi_frm_recursive_mutex_struct *mutex, S8 *mutex_name);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_recursive_mutex_lock
 * DESCRIPTION
 *  get the recursive mutex.
 * PARAMETERS
 *  mutex : [IN] The mutex
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_recursive_mutex_lock(mmi_frm_recursive_mutex_struct *mutex);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_recursive_mutex_unlock
 * DESCRIPTION
 *  release the recursive mutex.
 * PARAMETERS
 *  mutex  : [IN] The mutex
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_recursive_mutex_unlock(mmi_frm_recursive_mutex_struct *mutex);



#ifdef __cplusplus
}   /* extern "C" */
#endif







#endif /* MMI_FRM_REMUTEX_PROT_H */


