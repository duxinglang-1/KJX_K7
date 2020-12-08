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
 *  WorldClockCuiGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  WorldClock export APIs header files
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WORLDCLOCK_CUI_GPROT_H__
#define __WORLDCLOCK_CUI_GPROT_H__

/* select city struct */
#include "MMI_features.h"

#if defined(__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)

typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
        
    U16 city_index;
} cui_worldclock_event_struct;

#ifndef __COSMOS_MMI__
typedef enum
{
    CUI_WC_SELECT_EVENT_OK = WORLD_CLOCK_BASE,
    CUI_WC_SELECT_EVENT_CANCEL,
    CUI_WC_SELECT_EVENT_CLOSE_REQ,
    CUI_WC_SELECT_EVENT_TOTAL  
} cui_worldclock_event_enum;
#else
typedef enum
{
    CUI_WC_SELECT_EVENT_OK = 0,
    CUI_WC_SELECT_EVENT_CANCEL,
    CUI_WC_SELECT_EVENT_CLOSE_REQ,
    CUI_WC_SELECT_EVENT_TOTAL  
} cui_worldclock_event_enum;
#endif

/*****************************************************************************
 * FUNCTION
 *   cui_worldclock_create
 * DESCRIPTION
 *   camera cui group create
 * PARAMETERS
 *  parent_gid  : [IN] parent group ID
 * RETURNS
 *  camera cui group ID
 * RETURN VALUES
 *  camera cui group ID
*****************************************************************************/
extern void cui_worldclock_launch(void);



/*****************************************************************************
 * FUNCTION
 *   cui_wc_select_city_create
 * DESCRIPTION
 *   camera cui group create
 * PARAMETERS
 *  parent_gid  : [IN] parent group ID
 * RETURNS
 *  camera cui group ID
 * RETURN VALUES
 *  camera cui group ID
*****************************************************************************/
extern mmi_id cui_worldclock_create(mmi_id parent_gid);


/*****************************************************************************
 * FUNCTION
 *   cui_worldclock_set_current_city
 * DESCRIPTION
 *   camera cui group create
 * PARAMETERS
 *  city_index  : [IN] parent group ID
 * RETURNS
 *  camera cui group ID
 * RETURN VALUES
 *  camera cui group ID
*****************************************************************************/
extern void cui_worldclock_set_current_city(U16 city_index);


/*****************************************************************************
 * FUNCTION
 *   cui_worldclock_set_timezone
 * DESCRIPTION
 *   camera cui group create
 * PARAMETERS
 *  city_index  : [IN] parent group ID
 * RETURNS
 *  camera cui group ID
 * RETURN VALUES
 *  camera cui group ID
*****************************************************************************/
extern void cui_worldclock_set_timezone(U16 city_index);


/*****************************************************************************              
 * FUNCTION
 *   cui_worldclock_run
 * DESCRIPTION
 *   camera cui run
 * PARAMETERS
 *  parent_gid : [IN] camera cui group ID
 *  p_args     : [IN] camera structure to receive parameter
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_worldclock_run(mmi_id cui_gid);


/*****************************************************************************              
 * FUNCTION
 *   cui_worldclock_close
 * DESCRIPTION
 *   world clock cui close
 * PARAMETERS
 *  cui_gid : [IN] world clock cui group ID
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_worldclock_close(mmi_id cui_gid);

#endif /* __MMI_WORLD_CLOCK__ */
#endif /* __WORLDCLOCK_CUI_GPROT_H__ */

