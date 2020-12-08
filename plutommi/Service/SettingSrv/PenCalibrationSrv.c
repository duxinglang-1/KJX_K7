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
 *  PenCalibrationSrv.c
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "MMIDataType.h"
#if (defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__))
#include "mmi_frm_input_gprot.h"
#include "PenCalibrationSrvGprot.h"
#include "Mmi_rp_srv_pen_calibration_def.h" // Should be revised
#include "dcl.h"
/* RHR add */
#include "kal_general_types.h"
#include "lcd_sw_inc.h"
#include "string.h"
#include "kal_public_api.h"
#include "mmi_frm_nvram_gprot.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_nvram_gprot.h"
/* RHR add */
#include "nvram_data_items.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef enum 
{
    MMI_PHNSET_CALIBRATION_DATA,
    MMI_PHNSET_CALIBRATION_DEFAULT_DATA,

    MMI_PHNSET_CALIBRATION_TYPE_END
} mmi_phnset_calibration_type_enum;
static void srv_setting_pen_calibration_set_data(mmi_pen_calibration_struct *calibration_data);
static void srv_setting_pen_calibration_set_default_data(mmi_pen_calibration_struct *calibration_data);
#ifndef __TOUCH_PANEL_CAPACITY__
static MMI_BOOL srv_setting_pen_calibration_get_data_int(mmi_phnset_calibration_type_enum type, mmi_pen_calibration_struct *calibration_data);
static MMI_BOOL srv_setting_pen_calibration_check_data(mmi_pen_calibration_struct *calibration_data);
#endif
static MMI_BOOL srv_setting_pen_calibration_set_data_int(mmi_phnset_calibration_type_enum type, mmi_pen_calibration_struct *calibration_data);

static void srv_setting_pen_calibration_rsp(void *msg);
#ifndef __TOUCH_PANEL_CAPACITY__
static MMI_BOOL g_srv_pen_calibration_is_initialized;
#endif
static MMI_BOOL g_srv_pen_calibration_is_processing;
static mmi_proc_func g_srv_pen_calibration_proc;
static void *g_srv_pen_calibration_user_data;
static MMI_BOOL g_srv_pen_calibration_data_valid;
static MMI_BOOL g_srv_pen_calibration_update_default_data;
static mmi_pen_calibration_struct g_srv_pen_calibration_backup_data;
static U16 g_nvram_calibration_data_cache_id[] = {
        NVRAM_PEN_CALIBRATION_VALUE1,
        NVRAM_PEN_CALIBRATION_VALUE2,
        NVRAM_PEN_CALIBRATION_VALUE3,
        NVRAM_PEN_CALIBRATION_VALUE4,
        NVRAM_PEN_CALIBRATION_VALUE5,
        NVRAM_PEN_CALIBRATION_VALUE6,
        NVRAM_PEN_CALIBRATION_VALUE7,
        NVRAM_PEN_CALIBRATION_VALUE8};

static U16 g_nvram_calibration_default_data_cache_id[] = {
        NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE1,
        NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE2,
        NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE3,
        NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE4,
        NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE5,
        NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE6,
        NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE7,
        NVRAM_RESTORE_DEFAULT_PEN_CALIBRATION_VALUE8};

static mmi_pen_point_struct g_srv_pen_calibration_point[NUM_CALIBRATION_POINTS] = 
{
    {LCD_WIDTH / 10,      LCD_HEIGHT / 10},
    {LCD_WIDTH * 17 / 20, LCD_HEIGHT * 17 / 20},
    {LCD_WIDTH * 1 / 2,   LCD_HEIGHT * 1 / 2}
};
/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_set_data
 * DESCRIPTION
 *  Writes calibration setting in NVRAM
 * PARAMETERS
 *  calibration_data        [IN]        
 * RETURNS
 *  void
 * REMARKS
 *  This function assumes that NVRAM Values of Calibration data are stored in
 *  a fixed order in NVRAMEnum.h file . Order should not be changed.
 *  
 *  It is not atomic operation between ReadRecord and WriteRecord, but it's okay.
 *****************************************************************************/
static void srv_setting_pen_calibration_set_data(mmi_pen_calibration_struct *calibration_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_setting_pen_calibration_set_data_int(MMI_PHNSET_CALIBRATION_DATA, calibration_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_set_default_data
 * DESCRIPTION
 *  Writes factory default calibration setting in NVRAM
 * PARAMETERS
 *  calibration_data        [IN]        
 * RETURNS
 *  void
 * REMARKS
 *  This function assumes that NVRAM Values of Calibration data are stored in
 *  a fixed order in NVRAMEnum.h file . Order should not be changed.
 *  
 *  It is not atomic operation between ReadRecord and WriteRecord, but it's okay.
 *****************************************************************************/
static void srv_setting_pen_calibration_set_default_data(mmi_pen_calibration_struct *calibration_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note: It is not atomic operation between ReadRecord and WriteRecord. */
    srv_setting_pen_calibration_set_data_int(MMI_PHNSET_CALIBRATION_DEFAULT_DATA, calibration_data);
}

#ifndef __TOUCH_PANEL_CAPACITY__
/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_check_data
 * DESCRIPTION
 *  Function to validate calibration data read from NVRAM
 * PARAMETERS
 *  buffer          [?]         
 *  start_index     [IN]        
 *  end_index       [IN]        
 *  a(?)            [IN]        U8* , S16, S16
 *  b(?)            [OUT]       BOOL
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_setting_pen_calibration_check_data(mmi_pen_calibration_struct *calibration_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    unsigned char default_value[] = "\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";
	CHAR *data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < PEN_CALIBRATION_DATA_SIZE; i++)
    {
		data = (CHAR*)(&(calibration_data->data[i]));
		MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_CALIBRATION_DATA_INFO,(U32)(calibration_data->data[i]));    
        /*if (memcmp(&(calibration_data->data[i]), default_value, sizeof(double)))*/
		if(strncmp(data, (char *)default_value, sizeof(double)))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_get_data_int
 * DESCRIPTION
 *  Read the calibration data to the buffer 
 * PARAMETERS
 *  type    :   [IN]    data type
 *  buffer  :   [IN]    buffer, should => (PEN_CALIBRATION_DATA_SIZE * 2) bytes
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_setting_pen_calibration_get_data_int(mmi_phnset_calibration_type_enum type, mmi_pen_calibration_struct *calibration_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *nvram_cache_id = NULL;
    U8 i;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
	{
	case MMI_PHNSET_CALIBRATION_DATA:
		nvram_cache_id = g_nvram_calibration_data_cache_id;
		break;
    case MMI_PHNSET_CALIBRATION_DEFAULT_DATA:
        nvram_cache_id = g_nvram_calibration_default_data_cache_id;
        break;
	default:
		ASSERT(0);
	}
    for (i = 0; i < PEN_CALIBRATION_DATA_SIZE; i++)
	{
		ReadValue(nvram_cache_id[i], &(calibration_data->data[i]), DS_DOUBLE, &error);
        if (error < 0)
    	{
            return MMI_FALSE;    	
    	}
	}
    return MMI_TRUE;
    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_set_data_int
 * DESCRIPTION
 *  Set the buffer to NVRAM 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_setting_pen_calibration_set_data_int(mmi_phnset_calibration_type_enum type, mmi_pen_calibration_struct *calibration_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *nvram_cache_id = NULL;
    U8 i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
	{
	case MMI_PHNSET_CALIBRATION_DATA:
		nvram_cache_id = g_nvram_calibration_data_cache_id;
		break;
    case MMI_PHNSET_CALIBRATION_DEFAULT_DATA:
        nvram_cache_id = g_nvram_calibration_default_data_cache_id;
        break;
	default:
		ASSERT(0);
	}
	
	SetFlashNVRAMCatchData(DS_DOUBLE, MMI_FALSE); 
    for (i = 0; i < PEN_CALIBRATION_DATA_SIZE; i++)
	{
		WriteValue(nvram_cache_id[i], &(calibration_data->data[i]), DS_DOUBLE, &error);
        if (error < 0)
    	{
            return MMI_FALSE;
        }
	}
	SetFlashNVRAMCatchData(DS_DOUBLE, MMI_TRUE);
	
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_set_data_int");            
    g_srv_pen_calibration_data_valid = MMI_TRUE;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_setting_pen_calibration_pre_start
 * DESCRIPTION
 *  Check if pen calibration can be launched currently, should call this before
 *  start calibration, it will block other pre start calibration request
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE can start calibration
 *  MMI_FALSE cannot start calibration
 *****************************************************************************/
MMI_BOOL srv_setting_pen_calibration_pre_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_pen_calibration_is_processing)
	{
        /* Cannot start more than one calibration process */
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_pre_start cannot enter");        
	    return MMI_FALSE;
	}    
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_pre_start entered");        
    g_srv_pen_calibration_is_processing = MMI_TRUE;
    return MMI_TRUE;
}
 

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
void srv_setting_pen_calibration_start(mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_start proc(%d), userdata(%d)", proc, user_data);
#ifdef __MTK_TARGET__
    SetProtocolEventHandler(srv_setting_pen_calibration_rsp, MSG_ID_TP_CALI_DONE);
#endif
    g_srv_pen_calibration_proc = proc;
    g_srv_pen_calibration_user_data = user_data;
    mmi_pen_start_calibration(NUM_CALIBRATION_POINTS, g_srv_pen_calibration_point);    
    mmi_pen_read_calibration_data(&g_srv_pen_calibration_backup_data);  
}

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
void srv_setting_pen_calibration_restart(mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_restart proc(%d), userdata(%d)", proc, user_data);
    if (!srv_setting_pen_calibration_pre_start())
    {
	    srv_setting_pen_calibration_cancel_calibration();
    }    
#ifdef __MTK_TARGET__
    SetProtocolEventHandler(srv_setting_pen_calibration_rsp, MSG_ID_TP_CALI_DONE);
#endif
    g_srv_pen_calibration_proc = proc;
    g_srv_pen_calibration_user_data = user_data;
    mmi_pen_start_calibration(NUM_CALIBRATION_POINTS, g_srv_pen_calibration_point);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_setting_pen_calibration_rsp
 * DESCRIPTION
 *  Handle the response for calibration 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_setting_pen_calibration_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tp_cali_done_struct *rsp = (tp_cali_done_struct*) msg;
    mmi_pen_calibration_struct calibration_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_rsp");
#ifdef __MTK_TARGET__
    ClearProtocolEventHandler(MSG_ID_TP_CALI_DONE);
#endif
    if (rsp->result)
	{
        mmi_pen_read_calibration_data(&calibration_data);
        if (g_srv_pen_calibration_update_default_data)
        {
            srv_setting_pen_calibration_set_default_data(&calibration_data);
        }
        else
        {
            srv_setting_pen_calibration_set_data(&calibration_data);
        }	
	}
    else
    {
        /*
         * Flush pen event queue because Pen Down event of the 3rd point might come after 
         * * MSG_ID_TP_CALI_DONE, but it is changed to CALIBRATION_TOP_LEFT_POINT_STATE.
         */
        mmi_pen_reset();
    }
    g_srv_pen_calibration_is_processing = MMI_FALSE;
    g_srv_pen_calibration_update_default_data = MMI_FALSE;        
    if (g_srv_pen_calibration_proc)
	{
        srv_setting_pen_calibration_event_struct msg;
        msg.evt_id = EVT_ID_SRV_PEN_CALIBRATION_DONE;
        msg.result = rsp->result;
        msg.user_data = g_srv_pen_calibration_user_data;
	   (*g_srv_pen_calibration_proc)((mmi_event_struct*)&msg);
	}
}

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
void srv_setting_pen_calibration_update_data_in_modis(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_calibration_struct calibration_data; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_read_calibration_data(&calibration_data);
    if (g_srv_pen_calibration_update_default_data)
    {
        srv_setting_pen_calibration_set_default_data(&calibration_data);
    }
    else
    {
        srv_setting_pen_calibration_set_data(&calibration_data);
    }    
    g_srv_pen_calibration_update_default_data = MMI_FALSE;    
    g_srv_pen_calibration_proc = NULL;
    g_srv_pen_calibration_user_data = NULL;          
    g_srv_pen_calibration_is_processing = MMI_FALSE;
}
#endif 

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
void srv_setting_pen_calibration_cancel_calibration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_cancel_calibration");   
#ifdef __MTK_TARGET__
    ClearProtocolEventHandler(MSG_ID_TP_CALI_DONE);
#endif
    if (g_srv_pen_calibration_proc)
    {
        // Only set the data when the calibration is started.
        mmi_pen_set_calibration_data(&g_srv_pen_calibration_backup_data);    
    }
    g_srv_pen_calibration_update_default_data = MMI_FALSE;    
    g_srv_pen_calibration_proc = NULL;
    g_srv_pen_calibration_user_data = NULL;          
    g_srv_pen_calibration_is_processing = MMI_FALSE;    
}

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
void srv_setting_pen_calibration_update_default_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_pen_calibration_update_default_data = MMI_TRUE;
}

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
mmi_pen_point_struct* srv_setting_pen_calibration_get_point(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= NUM_CALIBRATION_POINTS)    
	{
	    ASSERT(0);
	}
    return &g_srv_pen_calibration_point[index];
}


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
MMI_BOOL srv_setting_pen_calibration_is_calibration_needed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __TOUCH_PANEL_CAPACITY__
    U8 buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_AUTO_TEST, (void*)buffer, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
    
    if (buffer[0])
    {
        return MMI_FALSE;
    }
    
#if defined(MMI_ON_WIN32) || defined(IC_MODULE_TEST) 
    /* PC Simulator does not support NVRAM */
    return MMI_FALSE;
#else /* #if defined(MMI_ON_WIN32) || defined(IC_MODULE_TEST) */ 
#if (defined (MT6268_EVB) && defined (__FLAVOR_HQA__))
    return MMI_FALSE;
#endif
    if (!g_srv_pen_calibration_is_initialized)
	{
	    srv_setting_pen_calibration_init_data();
	}

    if (!g_srv_pen_calibration_data_valid)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_is_calibration_needed");        
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif /* #if defined(MMI_ON_WIN32) || defined(IC_MODULE_TEST) */ 

#else /* __TOUCH_PANEL_CAPACITY__ */
    return MMI_FALSE;
#endif /* __TOUCH_PANEL_CAPACITY__ */
}

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
void srv_setting_pen_calibration_init_data(void)
{
#ifndef __TOUCH_PANEL_CAPACITY__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_calibration_struct calibration_data;
    MMI_BOOL no_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[PenCalibrationSrv.c] srv_setting_pen_calibration_init_data");            
    if (g_srv_pen_calibration_is_initialized)
    {
        return;
    }
    g_srv_pen_calibration_data_valid = MMI_FALSE;

    no_error = srv_setting_pen_calibration_get_data_int(MMI_PHNSET_CALIBRATION_DATA, &calibration_data);
    if (!no_error)
    {
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_READ_CALIBRATION_FAIL, (int)no_error);
        /* Do nothing, driver will take care */
        return;
    }
    else
    {
        if (srv_setting_pen_calibration_check_data(&calibration_data))
        {
            /* Use user-calibrated data */
            mmi_pen_set_calibration_data(&calibration_data);
            g_srv_pen_calibration_data_valid = MMI_TRUE;
            return;
        }
        else
        {
            no_error = srv_setting_pen_calibration_get_data_int(MMI_PHNSET_CALIBRATION_DEFAULT_DATA, &calibration_data);            
            /* Use factory default data */
            if (no_error && srv_setting_pen_calibration_check_data(&calibration_data))
            {
                mmi_pen_set_calibration_data(&calibration_data);
                g_srv_pen_calibration_data_valid = MMI_TRUE;
                return;
            }
        }
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_NOT_CALIBRATION_DATA);
        /* Do nothing, driver will take care */
    }
    g_srv_pen_calibration_is_initialized = MMI_TRUE;
#endif /* __TOUCH_PANEL_CAPACITY__ */
}
#endif /* (defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)) */

