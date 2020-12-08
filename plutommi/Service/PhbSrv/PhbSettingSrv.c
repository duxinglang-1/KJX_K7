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
 *  PhbAtSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for phb AT command handler.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "Nvram_common_defs.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "simCtrlSrvGprot.h"
#include "mmi_rp_srv_phb_def.h"
#include "fileMgrSrvGprot.h"
#include "FS_type.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef struct
{
    U16 storage;                                        /* phb storage mask */
    SRV_CONTACT_NAME_DISPLAY_TYPE_ENUM name_display;    /* phb name display sequence */
    SRV_CONTACT_SAVE_CONTACT_NOTIFY_ENUM save_notify;   /* save strange number notify */
    SRV_CONTACT_SPEAK_NAME_ENUM name_speak;             /* name speak out */
} srv_phb_setting_cntx_struct;

static srv_phb_setting_cntx_struct g_srv_phb_setting_cntx;


/***************************************************************************** 
 * Function
 *****************************************************************************/

#ifndef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
* FUNCTION
*  srv_phb_get_storage_by_mask
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static U16 srv_phb_get_storage_by_mask(U16 storage_mask)
{
    switch (storage_mask)
    {
        case SRV_PHB_STORAGE_MASK_PHONE:
            return PHB_STORAGE_NVRAM;
        case SRV_PHB_STORAGE_MASK_SIM:
            return PHB_STORAGE_SIM;
        case SRV_PHB_STORAGE_MASK_SIM2:
            return PHB_STORAGE_SIM2;
        case SRV_PHB_STORAGE_MASK_SIM3:
            return PHB_STORAGE_SIM3;
        case SRV_PHB_STORAGE_MASK_SIM4:
            return PHB_STORAGE_SIM4;
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        case SRV_PHB_STORAGE_MASK_TCARD:
            return PHB_STORAGE_TCARD;
        #endif
        case SRV_PHB_STORAGE_MASK_ALL:
        default:
            return PHB_STORAGE_MAX;
    }
}
#endif


/*****************************************************************************
* FUNCTION
*  srv_phb_setting_init
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
void srv_phb_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  temp_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_PHB_STORAGE_LOCATION, &g_srv_phb_setting_cntx.storage, DS_SHORT, &error);
    ReadValue(NVRAM_PHB_NAME_DISPLAY_TYPE, &temp_value, DS_BYTE, &error);
    if (temp_value != SRV_CONTACT_NAME_DISPLAY_TYPE_1 && temp_value != SRV_CONTACT_NAME_DISPLAY_TYPE_3)
    {
        temp_value = SRV_CONTACT_NAME_DISPLAY_TYPE_1;
        WriteValue(NVRAM_PHB_NAME_DISPLAY_TYPE, &temp_value, DS_BYTE, &error);
    }
    g_srv_phb_setting_cntx.name_display = (SRV_CONTACT_NAME_DISPLAY_TYPE_ENUM)temp_value;

#if defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)    
    ReadValue(NVRAM_PHB_SAVE_CONTACT_NOTIFY, &temp_value, DS_BYTE, &error);
    if (temp_value != SRV_PHB_SAVE_CONTACT_NOTIFY_ON && temp_value != SRV_PHB_SAVE_CONTACT_NOTIFY_OFF)
    {
        temp_value = SRV_PHB_SAVE_CONTACT_NOTIFY_ON;
    }    
    g_srv_phb_setting_cntx.save_notify = (SRV_CONTACT_SAVE_CONTACT_NOTIFY_ENUM)temp_value;
#endif /* defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__) */
}


/*****************************************************************************
* FUNCTION
*  srv_phb_get_storage_mask
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
U16 srv_phb_get_storage_mask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U16 mask;
    U16 storage_mask = g_srv_phb_setting_cntx.storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    storage_mask &= SRV_PHB_STORAGE_MASK_ALL;
    for (i = 0; i < MMI_PHB_SIM_COUNT; i ++)
    {
        mask = 1 << (i + PHB_STORAGE_SIM);
        if ((storage_mask & mask) && !srv_sim_ctrl_is_available(mmi_frm_index_to_sim(i)))
        {
            storage_mask &= ~mask;
        }
    }
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    if (storage_mask & SRV_PHB_STORAGE_MASK_TCARD)
    {
        if (!srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
        {
            storage_mask &= ~SRV_PHB_STORAGE_MASK_TCARD;
        }
    }
#endif
    if (storage_mask == 0)
    {
        storage_mask = SRV_PHB_STORAGE_MASK_PHONE;
    }
#ifdef __COSMOS_MMI_PACKAGE__
    return storage_mask;
#else
    return srv_phb_get_storage_by_mask(storage_mask);
#endif

}


/*****************************************************************************
* FUNCTION
*  srv_phb_set_storage_mask
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
void srv_phb_set_storage_mask(U16 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    U32 i;
#endif
    S16 error;
    srv_phb_storage_change_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    if (storage == PHB_STORAGE_MAX)
    {
        storage |= SRV_PHB_STORAGE_MASK_PHONE;
        for (i = 0; i < MMI_PHB_SIM_COUNT; i ++)
        {
            if (srv_sim_ctrl_is_available(mmi_frm_index_to_sim(i)))
            {
                storage |= 1 << (i + PHB_STORAGE_SIM);
            }
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
        {
            storage |= SRV_PHB_STORAGE_MASK_TCARD;     
        }
        #endif
    }
    else
    {
        storage = 1 << storage;
    }
#endif
    if (g_srv_phb_setting_cntx.storage != storage)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_STORAGE_CHANGE);
        evt.old_storage_mask = g_srv_phb_setting_cntx.storage;
        evt.new_storage_mask = storage;
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);

        g_srv_phb_setting_cntx.storage = storage;
        WriteValue(NVRAM_PHB_STORAGE_LOCATION, &storage, DS_SHORT, &error);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_check_storage_is_hide
* DESCRIPTION
*
* PARAMETERS
*  storage: 
* RETURNS
*
*****************************************************************************/
MMI_BOOL srv_phb_check_storage_is_hide(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((1 << storage) & g_srv_phb_setting_cntx.storage)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }    
}


/*****************************************************************************
* FUNCTION
*	srv_phb_set_storage_mask
* DESCRIPTION
*	
* PARAMETERS
*	
* RETURNS
*	
*****************************************************************************/
SRV_CONTACT_NAME_DISPLAY_TYPE_ENUM srv_phb_get_name_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_phb_setting_cntx.name_display;
}



/*****************************************************************************
* FUNCTION
*	srv_phb_set_name_display
* DESCRIPTION
*	
* PARAMETERS
*	
* RETURNS
*	
*****************************************************************************/
MMI_BOOL srv_phb_set_name_display(SRV_CONTACT_NAME_DISPLAY_TYPE_ENUM type, srv_phb_async_func_type cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    srv_phb_name_sequence_change_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_srv_phb_setting_cntx.name_display != type)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_NAME_SEQUENCE_CHANGE);
        evt.old_name_sequence = g_srv_phb_setting_cntx.name_display;
        evt.new_name_sequence = type;
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);

        g_srv_phb_setting_cntx.name_display = type;
        WriteValue(NVRAM_PHB_NAME_DISPLAY_TYPE, &g_srv_phb_setting_cntx.name_display, DS_BYTE, &error);
        return srv_phb_set_name_display_type((srv_phb_name_display_type_enum)type, cb, NULL);
    }
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*	srv_phb_get_save_notify
* DESCRIPTION
*	
* PARAMETERS
*	
* RETURNS
*	
*****************************************************************************/
SRV_CONTACT_SAVE_CONTACT_NOTIFY_ENUM srv_phb_get_save_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_phb_setting_cntx.save_notify;
}


/*****************************************************************************
* FUNCTION
*	srv_phb_set_save_notify
* DESCRIPTION
*	
* PARAMETERS
*	
* RETURNS
*	
*****************************************************************************/
void srv_phb_set_save_notify(SRV_CONTACT_SAVE_CONTACT_NOTIFY_ENUM type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_srv_phb_setting_cntx.save_notify != type)
    {
        g_srv_phb_setting_cntx.save_notify = type;
        WriteValue(NVRAM_PHB_SAVE_CONTACT_NOTIFY, &g_srv_phb_setting_cntx.save_notify, DS_BYTE, &error);
    }
}


/*****************************************************************************
* FUNCTION
*	srv_phb_get_name_speak
* DESCRIPTION
*	
* PARAMETERS
*	
* RETURNS
*	
*****************************************************************************/
SRV_CONTACT_SPEAK_NAME_ENUM srv_phb_get_name_speak(void)
{
    return g_srv_phb_setting_cntx.name_speak;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_set_name_speak
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
void srv_phb_set_name_speak(SRV_CONTACT_SPEAK_NAME_ENUM type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_srv_phb_setting_cntx.name_speak != type)
    {
        g_srv_phb_setting_cntx.name_speak = type;
        WriteValue(NVRAM_PHB_SPEAK_NAME_ON_OFF, &g_srv_phb_setting_cntx.name_speak, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_read_my_number(mmi_phb_my_number_struct *my_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, my_number, NVRAM_EF_PHB_MY_NUMBER_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_write_my_number(mmi_phb_my_number_struct *my_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, my_number, NVRAM_EF_PHB_MY_NUMBER_SIZE, &error);
}
