/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * gpiosrvsetting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  This file is intends for GPIO setting service part
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_include.h"

/* Device headers */
#include "lcd_if.h"
#ifdef __MMI_CABC__
#include "gdi_include.h"
#endif
/* nvram access */
#include "custom_mmi_default_value.h" 

/* Others */
#include "custom_equipment.h"
#include "BootupSrvGprot.h"

#include "GpioSrvGprot.h"
#include "GpioSrvprot.h"
#include "mmi_rp_srv_gpio_def.h"


/***************************************************************************** 
* Local Functions
*****************************************************************************/


/***************************************************************************** 
* Local Varibles
*****************************************************************************/
static mmi_phnset_gpio_cntx_struct g_phnset_gpio_cntx;


/***************************************************************************** 
* Global Varibles
*****************************************************************************/
mmi_phnset_gpio_cntx_struct *g_phnset_gpio_cntx_p = &g_phnset_gpio_cntx;

/*****************************************************************************
 * FUNCTION
 *  srv_gpio_setting_init
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_VUI_SCREEN_LOCK_KEY__)
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
    {
        ReadValue(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE, &error);
        if ((g_phnset_gpio_cntx_p->bl_setting_level < 1) ||(g_phnset_gpio_cntx_p->bl_setting_level > SRV_GPIO_BACKLIGHT_MAX_LEVEL))
        {
        #if !defined(__MTK_TARGET__)
            g_phnset_gpio_cntx_p->bl_setting_level = SRV_GPIO_BACKLIGHT_MAX_LEVEL;
        #else 
            g_phnset_gpio_cntx_p->bl_setting_level = ((SRV_GPIO_BACKLIGHT_MAX_LEVEL + 1) / 2);
        #endif 
            WriteValue(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE, &error);
        }

        ReadValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_SHORT, &error);
        if (g_phnset_gpio_cntx_p->bl_setting_hftime < 5 || g_phnset_gpio_cntx_p->bl_setting_hftime == 0xFFFF) // NVRAM default value
        {
            g_phnset_gpio_cntx_p->bl_setting_hftime = 55; // 55 sec to dimming, 5 sec to dark 
            WriteValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_SHORT, &error);
        }
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }
    else
    {
        g_phnset_gpio_cntx_p->bl_setting_level = ((SRV_GPIO_BACKLIGHT_MAX_LEVEL + 1) / 2);
        g_phnset_gpio_cntx_p->bl_setting_hftime = 55; // 55 sec to dimming, 5 sec to dark 
        #if 0
/* under construction !*/
        #endif
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if !defined(__MTK_TARGET__)
/* under construction !*/
        #else 
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_PHNSET_GPIO_COVER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_PHNSET_GPIO_COVER__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __COSMOS_MMI_PACKAGE__ */

    srv_backlight_set_hf_time(SRV_BACKLIGHT_SET_TIMER_DEFAULT, g_phnset_gpio_cntx_p->bl_setting_hftime);
	srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, g_phnset_gpio_cntx_p->bl_setting_level);

#ifdef __MMI_CABC__
/* Automatic brightness to savepower */
    ReadValue(NVRAM_BYTE_MMI_GPIO_CABC, &(g_phnset_gpio_cntx_p->cabc), DS_BYTE, &error);
    srv_gpio_setting_set_cabc(g_phnset_gpio_cntx_p->cabc);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_setting_set_bl_level
 * DESCRIPTION
 *  set backlite level, and display this backlight level right now
 * PARAMETERS
 *  level     : [IN]  want to display backlight level
 *  save_falg : [IN]  if save this level value to default backlight level
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_setting_set_bl_level(S32 level, MMI_BOOL save_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_gpio_cntx_p->bl_setting_level = level;

    if (save_flag == MMI_TRUE)
    {
        WriteValue(NVRAM_BYTE_BL_SETTING_LEVEL, 
                   &(g_phnset_gpio_cntx_p->bl_setting_level), 
                   DS_BYTE, 
                   &error);
    }

    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, g_phnset_gpio_cntx_p->bl_setting_level);
    srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_setting_set_hf_time
 * DESCRIPTION
 *  set backlight half time (not include dimming time), 
 *  but if execute right now, which due to save_falg
 * PARAMETERS
 *  hf_sec    : [IN]  want to set backlight half time in sec
 *  save_falg : [IN]  if save this level value to default backlight hf time
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_setting_set_hf_time(S32 hf_sec, MMI_BOOL save_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_gpio_cntx_p->bl_setting_hftime = hf_sec;

    if (save_flag == MMI_TRUE)
    {
        WriteValue(NVRAM_BYTE_BL_SETTING_HFTIME, 
                   &(g_phnset_gpio_cntx_p->bl_setting_hftime), 
                   DS_SHORT, 
                   &error);

        srv_backlight_set_hf_time(SRV_BACKLIGHT_SET_TIMER_DEFAULT, 
            g_phnset_gpio_cntx_p->bl_setting_hftime); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_setting_set_hf_time
 * DESCRIPTION
 *  set backlight time, which include half brightness time and dimming time,
 *  that to say, it is form turn on backlight to full drak (not dimming).
 * PARAMETERS
 *  bl_sec   :  [IN]  want to set backlight time in sec (from full bright to full dark)
 * RETURNS
 *  MMI_BOOL: will return MMI_TRUE when set success, else return MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_gpio_setting_set_bl_time(S32 bl_sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hf_sec;
    S32 dimming_sec = SRV_GPIO_BACKLIGHT_DIMMING_TIME / 1000;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(bl_sec <= dimming_sec)
        return MMI_FALSE;

    if (bl_sec == SRV_GPIO_BACKLIGHT_PERMANENT_ON_TIME)
        hf_sec = 0xFFFE; // different with NVRAM default value
    else
        hf_sec = bl_sec - dimming_sec;
    srv_gpio_setting_set_hf_time(hf_sec, MMI_TRUE);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_setting_bl_restore
 * DESCRIPTION
 *  restore gpio setting to Orignal value, include backlgiht level and half time
 *  such as, when user press end key or back softkey in gpio setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_setting_bl_restore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE, &error);
    ReadValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_SHORT, &error);
    
    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, g_phnset_gpio_cntx_p->bl_setting_level);
    srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
}


#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * FUNCTION
 *  srv_gpio_setting_get_hf_time
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_gpio_setting_get_hf_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_SHORT, &error);
    return (g_phnset_gpio_cntx_p->bl_setting_hftime * 1000);
}
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */


// Already phase out
MMI_BOOL srv_gpio_setting_contrast_restore(void)
{
    return MMI_TRUE;
}


// Already phase out
void srv_gpio_setting_set_mianlcd_contrast(U8 level)
{
}


// Already phase out
void srv_gpio_setting_set_sublcd_contrast(U8 level)
{
}


#ifdef __MMI_CABC__
/*****************************************************************************
 * FUNCTION
 *  srv_gpio_setting_set_cabc
 * DESCRIPTION
 *  This function is to set CABC feature Enable/Disable
 * PARAMETERS
 *  flag       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_setting_set_cabc(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_8, "srv_gpio_setting_set_cabc,flag=%d", flag);
    if (flag == 1)
    {
        gdi_cabc_enable();// call gdi to enable CABC
    }
    else
        gdi_cabc_disable();// call gdi to disable CABC
    g_phnset_gpio_cntx_p->cabc = flag;
    WriteValue(NVRAM_BYTE_MMI_GPIO_CABC, &flag, DS_BYTE, &error);
}
#endif

