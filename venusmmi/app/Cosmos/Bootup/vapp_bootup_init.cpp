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
 *  vapp_bootup_inin_app.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Initialize applications.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDatatype.h"

extern "C"
{
#include "mmi_frm_events_gprot.h"
#include "gdi_include.h"
}
#include "vfx_datatype.h"

#include "vapp_bootup.h"

#define VAPP_BOOTUP_ANI_MIN_FRAME_INTERVAL 60 /* ms */

/*
 * Profile the exection speed of initialization functions
 * Turn on MOD_MMI_COMMON_APP \ TRACE_FUNC
 */
#define __VAPP_BOOTUP_TIME_PROFILING__


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_proc_func hdlr;
} vapp_bootup_init_table_entry_struct;


/****************************************************************************
 * Handler table
 ****************************************************************************/

/* Declare function prototypes */
#define VAPP_BOOTUP_INIT_REG_BEGIN(evt_id)
#define VAPP_BOOTUP_INIT_REG(hdlr) extern "C" mmi_ret hdlr(mmi_event_struct *evt);
/* Export the adaptor so that we can look it up in the symbol table */
#define VAPP_BOOTUP_INIT_ADP(hdlr) \
    extern "C" void hdlr(void); \
    mmi_ret hdlr##_adp(mmi_event_struct *evt) { hdlr(); return MMI_RET_OK; }
#define VAPP_BOOTUP_INIT_REG_END(evt_id)
#include "vapp_bootup_init_cfg.h"
#undef VAPP_BOOTUP_INIT_REG_BEGIN
#undef VAPP_BOOTUP_INIT_REG
#undef VAPP_BOOTUP_INIT_ADP
#undef VAPP_BOOTUP_INIT_REG_END

/* Generate the handler table */
#define VAPP_BOOTUP_INIT_REG_BEGIN(evt_id) \
    static const vapp_bootup_init_table_entry_struct evt_id##_table[] = {
#define VAPP_BOOTUP_INIT_REG(hdlr) { hdlr },
#define VAPP_BOOTUP_INIT_ADP(hdlr) { hdlr##_adp },
#define VAPP_BOOTUP_INIT_REG_END(evt_id) { NULL }  };
#include "vapp_bootup_init_cfg.h"
#undef VAPP_BOOTUP_INIT_REG_BEGIN
#undef VAPP_BOOTUP_INIT_REG
#undef VAPP_BOOTUP_INIT_ADP
#undef VAPP_BOOTUP_INIT_REG_END

#define VAPP_BOOTUP_INIT_GET_TABLE(evt_id) (evt_id##_table)

#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_bootup_init_apps
 * DESCRIPTION
 *  Invoke the callbacks in the table.
 * PARAMETERS
 *  evt     [IN] Event to be sent to the callbacks
 *  table   [IN] The callback table
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_bootup_init_apps(
    mmi_event_struct *evt,
    const vapp_bootup_init_table_entry_struct *table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const vapp_bootup_init_table_entry_struct *entry;
	VfxU32 i;
#ifdef __VAPP_BOOTUP_TIME_PROFILING__
    U32 curr_tick;
    U32 prev_tick;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&curr_tick);
#endif

    for (i = 0, entry = table; entry->hdlr != NULL; i++, entry++)
    {

#ifdef __VAPP_BOOTUP_TIME_PROFILING__
	MMI_TRACE(MMI_COMMON_TRC_FUNC, TRC_VAPP_BOOTUP_INIT_ENTRY, i, (VfxU32)entry);
#endif
        entry->hdlr(evt);

#ifdef __VAPP_BOOTUP_TIME_PROFILING__
        prev_tick = curr_tick;
        kal_get_time(&curr_tick);
        MMI_TRACE(MMI_COMMON_TRC_FUNC, 
			TRC_VAPP_BOOTUP_INIT_TIME,
			i,
			(VfxU32)entry,
            (VfxU32)entry->hdlr, 
            (curr_tick - prev_tick));
#endif //__VAPP_BOOTUP_TIME_PROFILING__
    }
}


/*****************************************************************************
 * FUNCTION
 *  vapp_bootup_early_init
 * DESCRIPTION
 *  Emit EARLY_INIT to applications.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_bootup_early_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_early_init_evt_struct evt;
    const vapp_bootup_init_table_entry_struct *table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BOOTUP_EARLY_INIT);
    evt.is_exception_mode = srv_bootup_is_exception_mode();

    table = VAPP_BOOTUP_INIT_GET_TABLE(EVT_ID_SRV_BOOTUP_EARLY_INIT);
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_EARLY_INIT, '{');
    vapp_bootup_init_apps((mmi_event_struct*)&evt, table);
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_EARLY_INIT, '}');
}


/*****************************************************************************
 * FUNCTION
 *  vapp_bootup_normal_init
 * DESCRIPTION
 *  Emit NORMAL_INIT to applications.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed()
 * RETURNS
 *  void
 *****************************************************************************/
mmi_frm_proc_result_enum vapp_bootup_normal_init(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_normal_init_evt_struct evt;
    const vapp_bootup_init_table_entry_struct *table;
    BOOL gdi_enable_min_delay_time;
    U32 gdi_min_delay_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BOOTUP_NORMAL_INIT);
    evt.is_exception_mode = srv_bootup_is_exception_mode();

    gdi_anim_get_min_delay_time(&gdi_enable_min_delay_time, &gdi_min_delay_time);
    gdi_anim_set_min_delay_time(MMI_TRUE, VAPP_BOOTUP_ANI_MIN_FRAME_INTERVAL);

    table = VAPP_BOOTUP_INIT_GET_TABLE(EVT_ID_SRV_BOOTUP_NORMAL_INIT);
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_NORMAL_INIT, '{');
    vapp_bootup_init_apps((mmi_event_struct*)&evt, table);
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_NORMAL_INIT, '}');

    gdi_anim_set_min_delay_time(gdi_enable_min_delay_time, gdi_min_delay_time);
    
    return MMI_FRM_PROC_RESULT_COMPLETED;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_bootup_notify_before_idle
 * DESCRIPTION
 *  Emit BEFORE_IDLE to applications.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_bootup_notify_before_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_before_idle_evt_struct evt;
    const vapp_bootup_init_table_entry_struct *table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BOOTUP_BEFORE_IDLE);
    evt.is_exception_mode = srv_bootup_is_exception_mode();

    table = VAPP_BOOTUP_INIT_GET_TABLE(EVT_ID_SRV_BOOTUP_BEFORE_IDLE);
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_BEFORE_IDLE, '{');
    vapp_bootup_init_apps((mmi_event_struct*)&evt, table);
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_BEFORE_IDLE, '}');
}


/*****************************************************************************
 * FUNCTION
 *  vapp_bootup_notify_completed
 * DESCRIPTION
 *  Emit COMPLETED to applications.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_bootup_notify_completed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_completed_evt_struct evt;
    const vapp_bootup_init_table_entry_struct *table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BOOTUP_COMPLETED);
    evt.is_exception_mode = srv_bootup_is_exception_mode();
    
    table = VAPP_BOOTUP_INIT_GET_TABLE(EVT_ID_SRV_BOOTUP_COMPLETED);
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_COMPLETED, '{');
    vapp_bootup_init_apps((mmi_event_struct*)&evt, table);
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_COMPLETED, '}');
}
#pragma arm section code, rodata
