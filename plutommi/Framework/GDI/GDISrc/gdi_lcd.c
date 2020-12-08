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
 *  gdi_lcd.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI LCD related.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "mmi_frm_gprot.h"
#include "GlobalConstants.h"

#ifdef GDI_USING_TV_OUTPUT
#include "med_api.h"    /* media task */
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* GDI_USING_TV_OUTPUT */ 

#include "kal_general_types.h"
#include "kal_release.h"
#include "drv_sw_features_display.h"
#include "string.h"
#include "lcd_if.h"
#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"
#include "display_io.h"
#include "MMIDataType.h"
#include "mmi_frm_timer_gprot.h"

#include "gdi_trc.h"
#include "gdi_include.h"
#include "gdi_lcd_config.h"
#include "gdi_mutex.h"
#include "gdi_datatype.h"
#include "gdi_primitive.h"
#include "gdi_const.h"
#include "gdi_lcd.h"
#include "gdi_features.h"
#include "gdi_layer.h"
#include "gdi_include.h"

#include "wfc.h"
#include "Owfimage.h"


/****************************************************************************
* Local Variable
*****************************************************************************/
/* gdi_layer context */
gdi_lcd_cntx_struct *GDI_LCD;
gdi_lcd_cntx_struct GDI_LCD_ARRAY[GDI_LCD_SUM];

static gdi_mutex_struct gdi_lcd_mutext;

kal_bool gdi_lcd_is_hw_updating = KAL_FALSE;

WFCDevice gdi_lcd_v2_dev = WFC_INVALID_HANDLE;
gdi_lcd_v2_context_struct gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_MAX]; /* mainlcd or sublcd or flatten */

/* For blt or flatten hw layer after hw update stop */
static WFCElement gdi_lcd_v2_hw_layer_element[GDI_LCD_HW_UPDATE_LAYER_MAX] = {WFC_INVALID_HANDLE};
static WFCSource gdi_lcd_v2_hw_layer_source[GDI_LCD_HW_UPDATE_LAYER_MAX] = {WFC_INVALID_HANDLE};


/*****************************************************************************
* FUNCTION
*  gdi_lcd_init_mutex
* DESCRIPTION
*  Init GDI LCD mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gdi_lcd_init_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_init(&gdi_lcd_mutext);
}

/*****************************************************************************
* FUNCTION
*  gdi_lcd_lock_mutex
* DESCRIPTION
*  Lock GDI LCD mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gdi_lcd_lock_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_lock(&gdi_lcd_mutext);
}

/*****************************************************************************
* FUNCTION
*  gdi_lcd_unlock_mutex
* DESCRIPTION
*  Unlock GDI LCD mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gdi_lcd_unlock_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_unlock(&gdi_lcd_mutext);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_te_ctrl
 * DESCRIPTION
 *  lcd API wrapper for application to set te ctrl.(tearing control)
 * PARAMETERS
 *  te_ctrl [IN] turn on or turn off lcd te ctrl.
 * RETURNS
 *  kal_bool, return the previous setting of te ctrl
 *****************************************************************************/
kal_bool gdi_lcd_set_te_ctrl(kal_bool te_ctrl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool old_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_value = (kal_bool)wfcGetContextAttribi(
                            gdi_lcd_v2_dev, 
                            gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle, 
                            WFC_CONTEXT_VSYNC_ENABLE_MTK);
    wfcSetContextAttribi(
        gdi_lcd_v2_dev, 
        gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle, 
        WFC_CONTEXT_VSYNC_ENABLE_MTK,
        (WFCint)te_ctrl);

    #if defined(__MMI_SUBLCD__)
    wfcSetContextAttribi(
        gdi_lcd_v2_dev, 
        gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_SUB_LCD].ctx_handle, 
        WFC_CONTEXT_VSYNC_ENABLE_MTK,
        (WFCint)te_ctrl);
    #endif
    return old_value;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_te_ctrl_with_commit
 * DESCRIPTION
 *  lcd API wrapper for application to set te ctrl.(tearing control) and commit for MATAV
 * PARAMETERS
 *  te_ctrl [IN] turn on or turn off lcd te ctrl.
 * RETURNS
 *  kal_bool, return the previous setting of te ctrl
 *****************************************************************************/
kal_bool gdi_lcd_set_te_ctrl_with_commit(kal_bool te_ctrl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool old_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_value = (kal_bool)wfcGetContextAttribi(
                            gdi_lcd_v2_dev, 
                            gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle, 
                            WFC_CONTEXT_VSYNC_ENABLE_MTK);
    wfcSetContextAttribi(
        gdi_lcd_v2_dev, 
        gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle, 
        WFC_CONTEXT_VSYNC_ENABLE_MTK,
        (WFCint)te_ctrl);


    #if defined(__MMI_SUBLCD__)
    wfcSetContextAttribi(
        gdi_lcd_v2_dev, 
        gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_SUB_LCD].ctx_handle, 
        WFC_CONTEXT_VSYNC_ENABLE_MTK,
        (WFCint)te_ctrl);
        
    #endif

wfcCommit(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle,WFC_TRUE);                      
    return old_value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_te_ctrl
 * DESCRIPTION
 *  lcd API wrapper for application to get te ctrl.(tearing control)
 * PARAMETERS
 *  
 * RETURNS
 *  kal_bool, return the current setting of te ctrl
 *****************************************************************************/
kal_bool gdi_lcd_get_te_ctrl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool old_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_value = (kal_bool)wfcGetContextAttribi(
                            gdi_lcd_v2_dev, 
                            gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle, 
                            WFC_CONTEXT_VSYNC_ENABLE_MTK);
    return old_value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_te_ctrl_handle
 * DESCRIPTION
 *  lcd API wrapper for application to set te ctrl.
 *  call this API before calling gdi_lcd_te_ctrl_push.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8 te_ctrl_handle
 *****************************************************************************/
kal_uint8 gdi_lcd_get_te_ctrl_handle(void)
{
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_te_ctrl_push
 * DESCRIPTION
 *  lcd API wrapper for application to set te ctrl.
 *  Set new setting and push previous setting to stack.
 * PARAMETERS
 *  on_Noff [IN] turn on or turn off lcd te ctrl.
 *  handle  [IN] handle get from gdi_lcd_get_te_ctrl_handle();
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool gdi_lcd_te_ctrl_push(kal_bool on_Noff, kal_uint8 handle)
{
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_te_ctrl_push
 * DESCRIPTION
 *  lcd API wrapper for application to set te ctrl.
 *  Pop and restore to previous lcd te ctrl setting.
 * PARAMETERS
 *  handle  [IN] handle get from gdi_lcd_get_te_ctrl_handle();
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool gdi_lcd_te_ctrl_pop(kal_uint8 handle)
{
    return KAL_FALSE;
}


static GDI_RESULT gdi_lcd_v2_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WFCint numDevs = 0;
    WFCint devIds[3] = {0};
    WFCint attribValue = 0;
    OWF_IMAGE image;

    U32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get list of devices */  
    numDevs = wfcEnumerateDevices(NULL, 0, NULL);
    GDI_ASSERT(numDevs > 0);
    numDevs = wfcEnumerateDevices(devIds, 3, NULL);

    /* select correct device */
    for (i = 0; i < numDevs; i++)
    {
        gdi_lcd_v2_dev = wfcCreateDevice(devIds[i], NULL);
        attribValue = wfcGetDeviceAttribi(gdi_lcd_v2_dev, WFC_DEVICE_CLASS);
        if (attribValue == WFC_DEVICE_CLASS_FULLY_CAPABLE)
        {
            break;
        }
        wfcDestroyDevice(gdi_lcd_v2_dev);
        gdi_lcd_v2_dev = WFC_INVALID_HANDLE;
    }

    GDI_ASSERT(gdi_lcd_v2_dev != WFC_INVALID_HANDLE);

    /* create on screen context */
    gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle = wfcCreateOnScreenContext(gdi_lcd_v2_dev, WFC_SCREEN_LCD_0, NULL);

#if defined(__MMI_SUBLCD__)
    gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_SUB_LCD].ctx_handle = wfcCreateOnScreenContext(gdi_lcd_v2_dev, WFC_SCREEN_LCD_1, NULL);
#endif

    /* create off screen context */
    /* currently we don't know the output layer, so it simply assign a OWF_IMAGE with all 0. */
    memset(&image, 0, sizeof(image));
    gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_FLATTEN].ctx_handle = wfcCreateOffScreenContextMTK(gdi_lcd_v2_dev, (WFCHandle)&image, NULL);

    /* create WFCElements for each WFCContext */
    for(j = 0 ; j < GDI_LCD_V2_CTX_MAX ; j++)
    {
        for(i = 0 ; i < GDI_LAYER_HW_LAYER_COUNT ; i++)
        {
            /* create wfcElement */
            gdi_lcd_v2_ctx_array[j].elm[i] = wfcCreateElement(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[j].ctx_handle, NULL);
            GDI_ASSERT(gdi_lcd_v2_ctx_array[j].elm[i] != WFC_INVALID_HANDLE);

            /* create wfcSource */
            gdi_lcd_v2_ctx_array[j].src1[i] = wfcCreateSourceFromImage(
                                                gdi_lcd_v2_dev,
                                                gdi_lcd_v2_ctx_array[j].ctx_handle,
                                                (WFCHandle)&image,
                                                NULL);
            gdi_lcd_v2_ctx_array[j].src2[i] = wfcCreateSourceFromImage(
                                                gdi_lcd_v2_dev,
                                                gdi_lcd_v2_ctx_array[j].ctx_handle,
                                                (WFCHandle)&image,
                                                NULL);
            /* set source to element */
            wfcSetElementAttribi(
                gdi_lcd_v2_dev,
                gdi_lcd_v2_ctx_array[j].elm[i],
                WFC_ELEMENT_SOURCE,
                gdi_lcd_v2_ctx_array[j].src1[i]);
        }
    }

    /* init WFCSource for each WFCContext */
    for(j = 0 ; j < GDI_LCD_V2_CTX_MAX ; j++)
    {
        gdi_lcd_v2_ctx_array[j].src_act = gdi_lcd_v2_ctx_array[j].src1;
        gdi_lcd_v2_ctx_array[j].src_pre = gdi_lcd_v2_ctx_array[j].src2;
        /*
        for(i = 0 ; i < GDI_LAYER_HW_LAYER_COUNT ; i++)
        {
            gdi_lcd_v2_ctx_array[j].src1[i] = WFC_INVALID_HANDLE;
            gdi_lcd_v2_ctx_array[j].src2[i] = WFC_INVALID_HANDLE;
        }
        */
    }

    /* init hw layer element */
    for(j = 0 ; j < GDI_LCD_HW_UPDATE_LAYER_MAX ; j++)
    {
        /* For blt or flatten hw layer after hw update stop */
        gdi_lcd_v2_hw_layer_element[j] = wfcCreateElement(
                                            gdi_lcd_v2_dev, 
                                            gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_FLATTEN].ctx_handle, /* ctx_handle doesn't matter, just chose one contex */
                                            NULL);
        /* create wfcSource */
        gdi_lcd_v2_hw_layer_source[j] = wfcCreateSourceFromImage(
                                            gdi_lcd_v2_dev, 
                                            gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_FLATTEN].ctx_handle, 
                                            (WFCHandle)&image, 
                                            NULL);
        /* set source to element */
        wfcSetElementAttribi(
            gdi_lcd_v2_dev, 
            gdi_lcd_v2_hw_layer_element[j],
            WFC_ELEMENT_SOURCE, 
            gdi_lcd_v2_hw_layer_source[j]);

    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_init
 * DESCRIPTION
 *  Init lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_lcd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DisplayCABC_T cabc_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_init)
    S32 i = 0;

    /* init GDI LCD mutex */
    gdi_lcd_init_mutex();

    memset(GDI_LCD_ARRAY, 0, sizeof(GDI_LCD_ARRAY));

    GDI_LCD_ARRAY[i].act_handle = GDI_LCD_MAIN_LCD_HANDLE;
    GDI_LCD_ARRAY[i].act_width = GDI_LCD_WIDTH;
    GDI_LCD_ARRAY[i].act_height = GDI_LCD_HEIGHT;
    GDI_LCD_ARRAY[i].act_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    GDI_LCD_ARRAY[i].cf = gdi_get_color_format(DRV_MAINLCD_BIT_PER_PIXEL); // not support PARGB & UYVY422
    GDI_LCD_ARRAY[i].is_freeze = FALSE;
    GDI_LCD_ARRAY[i].is_high_priority_freeze = FALSE;    
    GDI_LCD_ARRAY[i].lcd_type = GDI_LCD_TYPE_LCD;
    GDI_LCD_ARRAY[i].bind_handle = GDI_NULL_HANDLE;
    GDI_LCD_ARRAY[i].rotate_value = GDI_LCD_LAYER_ROTATE_0;
    GDI_LCD_ARRAY[i].rotate_by_layer = FALSE;
    GDI_LCD_ARRAY[i].cabc_current_mode = GDI_CABC_MODE_OFF;
    GDI_LCD_ARRAY[i].cabc_enable_setting = TRUE;
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    GDI_LCD_ARRAY[i].scanline_rotation = TRUE;
    GDI_LCD_ARRAY[i].scanline_blt_handle = GDI_NULL_HANDLE;
    GDI_LCD_ARRAY[i].rotate_by_layer = TRUE;
#endif
    i++;
#ifdef __MMI_SUBLCD__
    GDI_LCD_ARRAY[i].act_handle = GDI_LCD_SUB_LCD_HANDLE;
    GDI_LCD_ARRAY[i].act_width = GDI_SUBLCD_WIDTH;
    GDI_LCD_ARRAY[i].act_height = GDI_SUBLCD_HEIGHT;
    GDI_LCD_ARRAY[i].act_layer_handle = GDI_LAYER_SUB_BASE_LAYER_HANDLE;
    GDI_LCD_ARRAY[i].cf = gdi_get_color_format(DRV_SUBLCD_BIT_PER_PIXEL);   // not support PARGB & UYVY422
    GDI_LCD_ARRAY[i].is_freeze = FALSE;
    GDI_LCD_ARRAY[i].is_high_priority_freeze = FALSE;
    GDI_LCD_ARRAY[i].lcd_type = GDI_LCD_TYPE_LCD;
    GDI_LCD_ARRAY[i].bind_handle = GDI_NULL_HANDLE;
    GDI_LCD_ARRAY[i].rotate_value = GDI_LCD_LAYER_ROTATE_0;
    GDI_LCD_ARRAY[i].rotate_by_layer = FALSE;
    GDI_LCD_ARRAY[i].cabc_current_mode = GDI_CABC_MODE_OFF;
    GDI_LCD_ARRAY[i].cabc_enable_setting = TRUE;
#if defined(GDI_SUBLCD_SCANLINE_ROTATION)
    GDI_LCD_ARRAY[i].scanline_rotation = TRUE;
    GDI_LCD_ARRAY[i].scanline_blt_handle = GDI_NULL_HANDLE;
    GDI_LCD_ARRAY[i].rotate_by_layer = TRUE;
#endif
#endif /* __MMI_SUBLCD__ */ 
    i++;
#ifdef GDI_USING_TV_OUTPUT
    GDI_LCD_ARRAY[i].act_handle = GDI_LCD_TVOUT_HANDLE;
    GDI_LCD_ARRAY[i].act_width = 0;
    GDI_LCD_ARRAY[i].act_height = 0;
    GDI_LCD_ARRAY[i].act_layer_handle = 0;
    GDI_LCD_ARRAY[i].cf = GDI_COLOR_FORMAT_16;
    GDI_LCD_ARRAY[i].is_freeze = FALSE;
    GDI_LCD_ARRAY[i].is_high_priority_freeze = FALSE;
    GDI_LCD_ARRAY[i].lcd_type = GDI_LCD_TYPE_TVOUT;
    GDI_LCD_ARRAY[i].bind_handle = GDI_NULL_HANDLE;
    GDI_LCD_ARRAY[i].rotate_value = GDI_LCD_LAYER_ROTATE_0;
    GDI_LCD_ARRAY[i].rotate_by_layer = FALSE;
#endif /* GDI_USING_TV_OUTPUT */ 
    /* init LCD */

    gdi_lcd_v2_init();

    GDI_LCD = &GDI_LCD_ARRAY[0];

    /* Set LCD cabc OFF Mode in Init */
    DisplayIOControl(DISPLAY_LCM0, DISPLAY_IOCTL_CABC_QUERY_SUPPORT, (void *)(&cabc_data));
    if (KAL_TRUE == cabc_data.bSupport)
    {
        cabc_data.mode = DISPLAY_CABC_MODE_OFF;
        DisplayIOControl(DISPLAY_LCM0, DISPLAY_IOCTL_CABC_SET_MODE, (void *)(&cabc_data));
    }
#ifdef __MMI_SUBLCD__
    DisplayIOControl(DISPLAY_LCM1, DISPLAY_IOCTL_CABC_QUERY_SUPPORT, (void *)(&cabc_data));
    if (KAL_TRUE == cabc_data.bSupport)
    {
        cabc_data.mode = DISPLAY_CABC_MODE_OFF;
        DisplayIOControl(DISPLAY_LCM1, DISPLAY_IOCTL_CABC_SET_MODE, (void *)(&cabc_data));
    }
#endif
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_init)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_active
 * DESCRIPTION
 *  set a lcd active
 * PARAMETERS
 *  lcd_handle      [IN]        
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_lcd_set_active(gdi_handle lcd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_active)
    /* check if is already active */
    if (GDI_LCD->act_handle == lcd_handle)
    {
        GDI_RETURN_VOID;
    }

    /* backup the active layer for current LCD */
    gdi_layer_get_active(&GDI_LCD->act_layer_handle);

    /* switch to the new LCD */
    GDI_ASSERT(0 < lcd_handle && lcd_handle <= GDI_LCD_SUM);
    GDI_LCD = &GDI_LCD_ARRAY[lcd_handle - 1];
    GDI_ASSERT(GDI_LCD->lcd_type);

    /* set the active layer for new LCD */
    if(GDI_LCD->act_layer_handle != GDI_NULL_HANDLE)
        gdi_layer_set_active(GDI_LCD->act_layer_handle);

    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_active)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_active
 * DESCRIPTION
 *  get current active lcd's handle
 * PARAMETERS
 *  lcd_handle_ptr      [OUT]       
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_lcd_get_active(gdi_handle *lcd_handle_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_active)
    *lcd_handle_ptr = GDI_LCD->act_handle;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_active)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_dimension
 * DESCRIPTION
 *  get dimesion of current active lcd
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_lcd_get_dimension(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    if ((GDI_LCD->rotate_value) & (0x01))
    {
        *width = GDI_LCD->act_height;
        *height = GDI_LCD->act_width;
    }
    else
    {
        *width = GDI_LCD->act_width;
        *height = GDI_LCD->act_height;
    }
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_bits_per_pixel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int gdi_lcd_get_bits_per_pixel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_bits_per_pixel)
    ret = gdi_bits_per_pixel(GDI_LCD->cf);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_bits_per_pixel)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_freeze
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_freeze       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_freeze(BOOL is_freeze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    GDI_TRACE(GDI_TRC_LAYER, GDI_TRC_LCD_FREEZE, is_freeze, lr);
    
    GDI_LCD_LOCK_MUTEX;
    GDI_LCD->is_freeze = is_freeze;
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_freeze
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  The acrive LCD is freezed or not
 *****************************************************************************/
BOOL gdi_lcd_get_freeze(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    ret = GDI_LCD->is_freeze;
    GDI_LCD_UNLOCK_MUTEX;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_high_priority_freeze
 * DESCRIPTION
 *  Sets the high priority freeze flag. This high priority flag can override normal lcd freeze.
 *  This API is reserved for framework usage. Do not use it.
 * PARAMETERS
 *  is_freeze       [IN]    freeze flag
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_high_priority_freeze(BOOL is_freeze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    GDI_TRACE(GDI_TRC_LAYER, GDI_TRC_LCD_HIGH_PRIORITY_FREEZE, is_freeze, lr);
    
    GDI_LCD_LOCK_MUTEX;
    GDI_LCD->is_high_priority_freeze = is_freeze;
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_high_priority_freeze
 * DESCRIPTION
 *  Gets the high priorty freeze flag.
 *  This API is reserved for framework usage. Do not use it.
 * PARAMETERS
 *  void        
 * RETURNS
 *  The active LCD is freezed or not.
 *****************************************************************************/
BOOL gdi_lcd_get_high_priority_freeze(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    ret = GDI_LCD->is_high_priority_freeze;
    GDI_LCD_UNLOCK_MUTEX;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_esd_recovery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_esd_recovery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_esd_recovery)
#ifdef __LCD_ESD_RECOVERY__
    gdi_handle current_lcd_handle;
    S32 lcd_width, lcd_height;
    LcdEsdCheck_T esdCheck;

    gdi_lcd_get_active(&current_lcd_handle);
    esdCheck.bEsdHappened = KAL_FALSE;
    DisplayIOControl(DISPLAY_LCM0, DISPLAY_IOCTL_ESD_CHECK, &esdCheck);
    if (esdCheck.bEsdHappened)
    {
        DisplayIOControl(DISPLAY_LCM0, DISPLAY_IOCTL_ESD_RESET, NULL);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
    }

    #ifdef __MMI_SUBLCD__
    /* sub lcd supported */
    esdCheck.bEsdHappened = KAL_FALSE;
    DisplayIOControl(DISPLAY_LCM1, DISPLAY_IOCTL_ESD_CHECK, &esdCheck);
    if (esdCheck.bEsdHappened)
    {
        DisplayIOControl(DISPLAY_LCM1, DISPLAY_IOCTL_ESD_RESET, NULL);
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
    }
#endif 
    gdi_lcd_set_active(current_lcd_handle);
    
#endif /* __LCD_ESD_RECOVERY__ */ 
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_esd_recovery)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_start_esd_recovery_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_start_esd_recovery_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_start_esd_recovery_timer)
    gdi_lcd_esd_recovery();
    StartTimer(
        (U16) GDI_TIMER_ESD_RECOVERY,
        GDI_LCD_ESD_RECOVERY_TIME,
        (FuncPtr) gdi_lcd_start_esd_recovery_timer);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_start_esd_recovery_timer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_stop_esd_recovery_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_stop_esd_recovery_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_stop_esd_recovery_timer)
    StopTimer((U16) GDI_TIMER_ESD_RECOVERY);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_stop_esd_recovery_timer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_rotate(U8 rotate_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_rotate)
    GDI_LCD->rotate_value = rotate_value;

    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_rotate)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 gdi_lcd_get_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_rotate)
    ret = GDI_LCD->rotate_value;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_rotate)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_bind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_bind(gdi_handle lcd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_bind)
    GDI_ASSERT(GDI_LCD->lcd_type != GDI_LCD_TYPE_TVOUT);
    GDI_ASSERT(GDI_LCD_ARRAY[lcd_handle - 1].lcd_type == GDI_LCD_TYPE_TVOUT || lcd_handle == GDI_NULL_HANDLE);
    GDI_LCD->bind_handle = lcd_handle;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_bind)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_blt_counter
 * DESCRIPTION
 *  return the blt counter.
 *  blt counter is the number that lcd update.
 *  UI engine use this to know their previous setting ever blt out or not.
 * PARAMETERS
 *  
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_lcd_get_blt_counter(U32 *blt_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently not to get gdi mutex for performance */
    
    if (blt_counter ==  NULL)
    {
        return GDI_FAILED;
    }
    
    *blt_counter = GDI_LCD->blt_counter;

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_lcd_to_absolute_hw_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 *  x1                  [?]         
 *  y1                  [?]         
 *  x2                  [?]         
 *  y2                  [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_lcd_to_absolute_hw_region(U8 rotate_value, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tx1, ty1, tx2, ty2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;

    switch (rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx1 = *y1;
            ty1 = GDI_LCD->act_height - *x2 - 1;
            tx2 = *y2;
            ty2 = GDI_LCD->act_height - *x1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx1 = GDI_LCD->act_width - *x2 - 1;
            ty1 = GDI_LCD->act_height - *y2 - 1;
            tx2 = GDI_LCD->act_width - *x1 - 1;
            ty2 = GDI_LCD->act_height - *y1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx1 = GDI_LCD->act_width - *y2 - 1;
            ty1 = *x1;
            tx2 = GDI_LCD->act_width - *y1 - 1;
            ty2 = *x2;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx1 = GDI_LCD->act_width - *x2 - 1;
            tx2 = GDI_LCD->act_width - *x1 - 1;
            *x1 = tx1;
            *x2 = tx2;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx1 = *y1;
            ty1 = *x1;
            tx2 = *y2;
            ty2 = *x2;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty1 = GDI_LCD->act_height - *y2 - 1;
            ty2 = GDI_LCD->act_height - *y1 - 1;
            *y1 = ty1;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx1 = GDI_LCD->act_width - *y2 - 1;
            ty1 = GDI_LCD->act_height - *x2 - 1;
            tx2 = GDI_LCD->act_width - *y1 - 1;
            ty2 = GDI_LCD->act_height - *x1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
    }
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_absolute_hw_to_lcd_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 *  x1                  [?]         
 *  y1                  [?]         
 *  x2                  [?]         
 *  y2                  [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_absolute_hw_to_lcd_region(U8 rotate_value, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tx1, ty1, tx2, ty2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;

    switch (rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx1 = GDI_LCD->act_height - *y2 - 1;
            ty1 = *x1;
            tx2 = GDI_LCD->act_height - *y1 - 1;
            ty2 = *x2;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx1 = GDI_LCD->act_width - *x2 - 1;
            ty1 = GDI_LCD->act_height - *y2 - 1;
            tx2 = GDI_LCD->act_width - *x1 - 1;
            ty2 = GDI_LCD->act_height - *y1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx1 = *y1;
            ty1 = GDI_LCD->act_width - *x2 - 1;
            tx2 = *y2;
            ty2 = GDI_LCD->act_width - *x1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx1 = GDI_LCD->act_width - *x2 - 1;
            tx2 = GDI_LCD->act_width - *x1 - 1;
            *x1 = tx1;
            *x2 = tx2;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty1 = GDI_LCD->act_height - *y2 - 1;
            ty2 = GDI_LCD->act_height - *y1 - 1;
            *y1 = ty1;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx1 = GDI_LCD->act_height - *x2 - 1;
            ty1 = GDI_LCD->act_width - *y2 - 1;
            tx2 = GDI_LCD->act_height - *x1 - 1;
            ty2 = GDI_LCD->act_width - *y1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
    }
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_absolute_hw_to_lcd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [?]     
 *  y       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_absolute_hw_to_lcd(S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_rotate_map_absolute_hw_to_lcd)
    S32 tx, ty;

    switch (GDI_LCD->rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx = GDI_LCD->act_height - *y - 1;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx = GDI_LCD->act_width - *x - 1;
            ty = GDI_LCD->act_height - *y - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx = *y;
            ty = GDI_LCD->act_width - *x - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx = GDI_LCD->act_width - *x - 1;
            *x = tx;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx = *y;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty = GDI_LCD->act_height - *y - 1;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx = GDI_LCD->act_height - *y - 1;
            ty = GDI_LCD->act_width - *x - 1;
            *x = tx;
            *y = ty;
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_rotate_map_absolute_hw_to_lcd)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_lcd_to_absolute_hw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [?]     
 *  y       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_lcd_to_absolute_hw(S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_rotate_map_lcd_to_absolute_hw)
    S32 tx, ty;

    switch (GDI_LCD->rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx = *y;
            ty = GDI_LCD->act_height - *x - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx = GDI_LCD->act_width - *x - 1;
            ty = GDI_LCD->act_height - *y - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx = GDI_LCD->act_width - *y - 1;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx = GDI_LCD->act_width - *x - 1;
            *x = tx;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx = *y;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty = GDI_LCD->act_height - *y - 1;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx = GDI_LCD->act_height - *y - 1;
            ty = GDI_LCD->act_width - *x - 1;
            *x = tx;
            *y = ty;
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_rotate_map_lcd_to_absolute_hw)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_blt(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    S32 lcd_width, lcd_height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_blt)

    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    ret = gdi_layer_blt(handle0, handle1, handle2, handle3, 0, 0, lcd_width - 1, lcd_height - 1);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_blt)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_rotate_by_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_by_layer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_set_rotate_by_layer(BOOL rotate_by_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If is in scanline, not permit it to change rotate_by_layer value.
     * It should always be TRUE.
     */
#if defined(GDI_LCD_SCANLINE_ROTATION)
    if (GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
    #if defined(GDI_MAINLCD_SCANLINE_ROTATION)
        return;
    #endif
    }

    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
    #if defined(GDI_SUBLCD_SCANLINE_ROTATION)
        return;
    #endif
    }
#endif /* GDI_LCD_SCANLINE_ROTATION */
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_rotate_by_layer)
    GDI_LCD->rotate_by_layer = rotate_by_layer;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_rotate_by_layer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_rotate_by_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_lcd_get_rotate_by_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_USING_LCD_ROTATE)
    BOOL ret;
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_get_rotate_by_layer)
    ret = GDI_LCD->rotate_by_layer;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_get_rotate_by_layer)
    return ret;
#else 
    return TRUE;
#endif 
    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_paint_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_paint_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3,
            gdi_handle handle4, 
            gdi_handle handle5,
            S32 x1, 
            S32 y1, 
            S32 x2, 
            S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_paint_ext)
    result = gdi_layer_blt_ext(handle0, handle1, handle2, handle3, handle4, handle5, x1, y1, x2, y2);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_paint_ext)
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_repaint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_repaint(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_repaint_ext)
    ret = gdi_layer_blt_previous(x1, y1, x2, y2);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_repaint_ext)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_paint_all_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_paint_all_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3, 
            gdi_handle handle4, 
            gdi_handle handle5)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lcd_width, lcd_height;
    GDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_paint_all_ext)

    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    result = gdi_layer_blt_ext(handle0, handle1, handle2, handle3, handle4, handle5, 0, 0, lcd_width - 1, lcd_height - 1);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_paint_all_ext)
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_repaint_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_lcd_repaint_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lcd_width, lcd_height;
    gdi_result ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_repaint_all_ext)
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    ret = gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_repaint_all_ext)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_set_hw_update_ext
 * DESCRIPTION
 *  start hw update or stop hw update.
 *  remeber to set correct hw update layers before starting hw update.
 * PARAMETERS
 *  hw_update  [IN]  true means starting hw update. false means stop hw update.
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_lcd_set_hw_update(kal_bool hw_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_lcd_v2_context_enum ctx_index = GDI_LCD_V2_CTX_BLT_MAIN_LCD;
    WFCContext ctx = gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_MAIN_LCD].ctx_handle;
    U8 i = 0, hw_layer_count = 0;
    kal_uint32 lr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    GDI_TRACE(GDI_TRC_LAYER, GDI_TRC_LCD_SET_HW_UPDATE, hw_update, lr, gdi_lcd_is_hw_updating);

    GDI_ENTER_CRITICAL_SECTION(gdi_lcd_set_hw_update_ext)
    GDI_LCD_LOCK_MUTEX;
    if (hw_update && (hw_update != gdi_lcd_is_hw_updating))
    {
        for (i = 0; i < GDI_LAYER_HW_LAYER_COUNT ; i++)
        {
            if ((GDI_LCD->blt_handle[i] != GDI_NULL_HANDLE) &&
                (GDI_LAYER_GET_FLAG(GDI_LCD->blt_handle[i], GDI_LAYER_FLAG_HW_UPDATE)))
            {
            #ifdef GDI_6_LAYERS
                gdi_layer_set_blt_layer_ext(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    GDI_LCD->blt_handle[4],
                    GDI_LCD->blt_handle[5]);
            #else
                gdi_layer_set_blt_layer_ext(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    0,
                    0);
            #endif
                break;
            }
        }
    }
    GDI_LCD_UNLOCK_MUTEX;
    GDI_EXIT_CRITICAL_SECTION(gdi_lcd_set_hw_update_ext)

    GDI_LCD_LOCK_MUTEX;

#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    if (gdi_lcd_is_hw_updating != hw_update)
    {
        if (hw_update)
        {
            /* update global variable before gdi_bltdb_hw_update_state_change */
            gdi_lcd_is_hw_updating = hw_update;
            gdi_bltdb_hw_update_state_change(hw_update);
        }
        else
        {
            /* update global variable after gdi_bltdb_hw_update_state_change, 
               because it should use old setting */
            gdi_bltdb_hw_update_state_change(hw_update);
            
            /* update is hw updating */
            gdi_lcd_is_hw_updating = hw_update;
        }
    }
#else
    /* update is hw updating */
    gdi_lcd_is_hw_updating = hw_update;
#endif

#if defined(__MMI_SUBLCD__)
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        ctx_index = GDI_LCD_V2_CTX_BLT_SUB_LCD;
        ctx = gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_BLT_SUB_LCD].ctx_handle;
    }
#endif

    if (gdi_lcd_is_hw_updating)
    {
        wfcActivate(gdi_lcd_v2_dev, ctx);   /* start lcd auto mode */
        gdi_layer_toggle_lcd_source(ctx_index);
    }
    else
    {
        wfcDeactivate(gdi_lcd_v2_dev, ctx); /* stop lcd auto mode */

        /* copy the hw layer element to hw layer struct. For blt or flatten hw layer after hw update stop. */
        hw_layer_count = 0;
        for (i = 0; i < GDI_LAYER_HW_LAYER_COUNT ; i++)
        {
            if ((GDI_LCD->blt_handle[i] != GDI_NULL_HANDLE) &&
                (GDI_LAYER_GET_FLAG(GDI_LCD->blt_handle[i], GDI_LAYER_FLAG_HW_UPDATE)))   /* previous blt hw layer */
            {
                gdi_layer_struct* temp_layer = (gdi_layer_struct*)(GDI_LCD->blt_handle[i]);

                ASSERT(hw_layer_count < GDI_LCD_HW_UPDATE_LAYER_MAX);   /* APP use too much hw update layer */

                /* copy the hw update element to hw layer struct */
                wfcCloneElementAttribute(
                    gdi_lcd_v2_dev,
                    gdi_lcd_v2_ctx_array[ctx_index].elm[i],         // source
                    gdi_lcd_v2_hw_layer_element[hw_layer_count]);   // destination

                temp_layer->hw_update_element = (U32)(gdi_lcd_v2_hw_layer_element[hw_layer_count]);

                hw_layer_count++;
            }
        }
    }
    
    GDI_LCD_UNLOCK_MUTEX;
    return GDI_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_hw_update
 * DESCRIPTION
 *  get hw update is on going or not.
 * PARAMETERS
 *  hw_update  [OUT]  true means hw update is on going.
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_lcd_get_hw_update(kal_bool *hw_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    if (hw_update)
    {
        *hw_update = gdi_lcd_is_hw_updating;
    }
    GDI_LCD_UNLOCK_MUTEX;
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_get_refresh_rate
 * DESCRIPTION
 *  Get refresh rate of LCD
 * PARAMETERS
 *  lcd_handle  [IN] LCD handle
 * RETURNS
 *  Refresh rate of LCD; <= 0 means not available
 *****************************************************************************/
kal_int32 gdi_lcd_get_refresh_rate(gdi_handle lcd_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ctx_index;
    kal_int32 refresh_rate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctx_index = GDI_LCD_V2_CTX_BLT_MAIN_LCD;
#if defined(__MMI_SUBLCD__)
    if (lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        ctx_index = GDI_LCD_V2_CTX_BLT_SUB_LCD;
    }
#endif
    
    GDI_LCD_LOCK_MUTEX;

    refresh_rate = wfcGetContextAttribi(
        gdi_lcd_v2_dev,
        gdi_lcd_v2_ctx_array[ctx_index].ctx_handle,
        WFC_CONTEXT_BLT_MAX_REFRESH_RATE_MTK);

    GDI_LCD_UNLOCK_MUTEX;

    return refresh_rate;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_cabc_enable
 * DESCRIPTION
 *  Enable to set the cabc mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_cabc_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd_handle;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);
#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        i = 1;
    }
#endif /* __MMI_SUBLCD__ */
    GDI_LCD_LOCK_MUTEX;
    GDI_LCD_ARRAY[i].cabc_enable_setting = TRUE;
    gdi_cabc_set_mode(GDI_LCD_ARRAY[i].cabc_current_mode);

    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_cabc_disable
 * DESCRIPTION
 *  Enable to set the cabc mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_cabc_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd_handle;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_cabc_set_mode(GDI_CABC_MODE_OFF);

    gdi_lcd_get_active(&act_lcd_handle);
#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        i = 1;
    }
#endif /* __MMI_SUBLCD__ */

    GDI_LCD_LOCK_MUTEX;
    GDI_LCD_ARRAY[i].cabc_enable_setting = FALSE;
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_cabc_set_mode
 * DESCRIPTION
 *  Set the cabc mode.
 * PARAMETERS
 *  mode        [IN]: Is the mode to set to LCM.
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_cabc_set_mode(gdi_cabc_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DisplayCABC_T cabc_data;
    gdi_handle act_lcd_handle;
    DisplayResultEnum result;
    DisplayDeviceEnum lcm_id = DISPLAY_LCM0;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);
    if (act_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        lcm_id = DISPLAY_LCM0;
    }
#ifdef __MMI_SUBLCD__
    else if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        lcm_id = DISPLAY_LCM1;
        i = 1;
    }
#endif /* __MMI_SUBLCD__ */

    /* Query CABC support */
    GDI_LCD_LOCK_MUTEX;
    DisplayIOControl(lcm_id, DISPLAY_IOCTL_CABC_QUERY_SUPPORT, (void *)(&cabc_data));
    if ((KAL_TRUE == cabc_data.bSupport) &&
        (TRUE == GDI_LCD_ARRAY[i].cabc_enable_setting))
    {
        GDI_LCD_ARRAY[i].cabc_current_mode = mode;
        switch (mode)
        {
            case GDI_CABC_MODE_OFF:
                cabc_data.mode = DISPLAY_CABC_MODE_OFF;
                break;
            case GDI_CABC_MODE_UI:
                cabc_data.mode = DISPLAY_CABC_MODE_UI;
                break;
            case GDI_CABC_MODE_STILL:
                cabc_data.mode = DISPLAY_CABC_MODE_STILL;
                break;
            case GDI_CABC_MODE_MOVING:
                cabc_data.mode = DISPLAY_CABC_MODE_MOVING;
                break;
            default:
                cabc_data.mode = DISPLAY_CABC_MODE_INVALID;
                break;
        }
        result = DisplayIOControl(lcm_id, DISPLAY_IOCTL_CABC_SET_MODE, (void *)(&cabc_data));
        GDI_TRACE(GDI_TRC, GDI_TRC_57,//"CABC set: mode:%d, result: %d"
            mode, result);
    }
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_cabc_get_mode
 * DESCRIPTION
 *  Get the cabc mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
gdi_cabc_mode_enum gdi_cabc_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd_handle;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);
#ifdef __MMI_SUBLCD__
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        i = 1;
    }
#endif /* __MMI_SUBLCD__ */

    return GDI_LCD_ARRAY[i].cabc_current_mode;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_cabc_reset
 * DESCRIPTION
 *  Reset the cabc mode to default value.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_cabc_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_cabc_set_mode(GDI_CABC_MODE_DEFAULT);
}


#if defined(GDI_LCD_SCANLINE_ROTATION)
/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_scanline_rotation_enable
 * DESCRIPTION
 *  Enable the current LCD scanline rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_scanline_rotation_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    if (GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
    #if !defined(GDI_MAINLCD_SCANLINE_ROTATION)
        GDI_LCD_UNLOCK_MUTEX;
        return;
    #endif
    }

    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
    #if !defined(GDI_SUBLCD_SCANLINE_ROTATION)
        GDI_LCD_UNLOCK_MUTEX;
        return;
    #endif
    }

    GDI_LCD->scanline_rotation = TRUE;
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_lcd_scanline_rotation_disable
 * DESCRIPTION
 *  Disable the current LCD scanline rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_lcd_scanline_rotation_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    if (GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
    #if !defined(GDI_MAINLCD_SCANLINE_ROTATION)
        GDI_LCD_UNLOCK_MUTEX;
        return;
    #endif
    }

    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
    #if !defined(GDI_SUBLCD_SCANLINE_ROTATION)
        GDI_LCD_UNLOCK_MUTEX;
        return;
    #endif
    }

    GDI_LCD->scanline_rotation = FALSE;
    GDI_LCD_UNLOCK_MUTEX;
}
#endif /* GDI_LCD_SCANLINE_ROTATION */

