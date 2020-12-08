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
 *  PenCalibrationSrvGprot.h
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PEN_CALIBRATION_SRV_GPROT_H__
#define __PEN_CALIBRATION_SRV_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "MMIDataType.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define NUM_CALIBRATION_POINTS 3

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    EVT_ID_SRV_PEN_CALIBRATION_DONE,

    EVT_ID_SRV_PEN_CALIBRATION_ENUM_END
} srv_setting_pen_calibration_event_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_BOOL result;
} srv_setting_pen_calibration_event_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_is_calibration_needed
 * DESCRIPTION
 *  Whether pen is calibrated.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL srv_setting_pen_calibration_is_calibration_needed(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_setting_pen_calibration_start
 * DESCRIPTION
 *  Register the callback for pen calibration, please call this API before calibration on target. 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_setting_pen_calibration_start(mmi_proc_func proc, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mmi_setting_pen_calibration_restart
 * DESCRIPTION
 *  Register the callback for pen calibration, please call this API before calibration on target. 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_setting_pen_calibration_restart(mmi_proc_func proc, void *user_data);

#ifndef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  void
 * DESCRIPTION
 *  Update the data in modis 
 * PARAMETERS
 *  
 * RETURNS
 *  void srv_setting_pen_calibration_update_data_in_modis
 *****************************************************************************/
extern void srv_setting_pen_calibration_update_data_in_modis(void);
#endif /* __MTK_TARGET__ */

/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_cancel_calibration
 * DESCRIPTION
 *  Cancel calibration, it will restore the data with the backup one 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_setting_pen_calibration_cancel_calibration(void);

/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_update_default_data
 * DESCRIPTION
 *  Call this API if the calibration data need to be saved to default data, 
 *  it should be called at the first calibration 
 *  The flag will be cleared after saving.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_setting_pen_calibration_update_default_data(void);

/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_pre_start
 * DESCRIPTION
 *  Check if pen calibration can be launched currently 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_setting_pen_calibration_pre_start(void);

/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_get_point
 * DESCRIPTION
 *  Get calibration point with index 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_pen_point_struct
 *****************************************************************************/
extern mmi_pen_point_struct* srv_setting_pen_calibration_get_point(U8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_init_data
 * DESCRIPTION
 *  Function to read calibration data from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_setting_pen_calibration_init_data(void);
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __PEN_CALIBRATION_SRV_GPROT_H__ */
 
