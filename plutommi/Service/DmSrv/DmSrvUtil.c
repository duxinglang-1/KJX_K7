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
 *  DmSrvUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service utility functions.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef SYNCML_DM_SUPPORT
/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMIDataType.h"
#include "DmSrvUtil.h"
#include "ModeSwitchSrvGprot.h"
#include "DmSelfRegisterGprot.h"
#include "MMI_trc_int.h"
#include "mmi_conn_app_trc.h"
/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/

/****************************************************************************
 * Local Function
 ****************************************************************************/

MMI_BOOL srv_dm_check_sr_sim_match(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_state_enum mode_state = srv_mode_switch_get_current_mode();
    mmi_sim_enum reg_sim = srv_dm_get_reg_sim();
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode_state == SRV_MODE_DUAL_SIM)
    {
        ret = MMI_TRUE;
    }
    else if (mode_state == SRV_MODE_FLIGHT_MODE)
    {
        ret = MMI_FALSE;
    }
    else if ((reg_sim == MMI_SIM1 && mode_state == SRV_MODE_SIM2_ONLY) ||
             (reg_sim == MMI_SIM2 && mode_state == SRV_MODE_SIM1_ONLY) ||
             reg_sim == MMI_SIM_NONE)
    {
        ret = MMI_FALSE;
    }
    else
    {
        ret = MMI_TRUE;
    }
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_CHECK_SR_SIM_MATCH, ret, mode_state, reg_sim);
    return ret;
}


MMI_BOOL srv_dm_serverid_valid(CHAR *serverid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *p = serverid;
    U8 ansii_max_value = 127;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(serverid);

    while ((*p != 0) || (*(p + 1) != 0))
    {
        if (*p < ansii_max_value)
        {
            p++;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


MMI_BOOL srv_dm_check_asc_format(CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define MAX_ASC_VAL 127
    CHAR *p = str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return MMI_FALSE;
    }

    while (*p != '\0')
    {
        if (*p < MAX_ASC_VAL)
        {
            p++;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}
#endif /* SYNCML_DM_SUPPORT */
