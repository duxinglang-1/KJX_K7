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
 *  ImeiSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Service to get IMEI.
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "SimCtrlSrvGprot.h"
#include "ImeiSrvGprot.h"
#include "app_str.h"
#include "nvram_interface.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "nvram_data_items.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_utility_gprot.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    MMI_BOOL is_inited;
    CHAR imei[SRV_IMEI_MAX_LEN + 1];
} srv_imei_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static srv_imei_cntx_struct g_srv_imei_cntx[MMI_SIM_TOTAL] =
{
    { MMI_FALSE } /* Zero-init */
};


/****************************************************************************
 * Functions
 ****************************************************************************/

#define srv_imei_bcd_to_char(bcd) ((bcd) < 10 ? ((CHAR)(bcd) + '0') : '\0')


/*****************************************************************************
 * FUNCTION
 *  srv_imei_get_cntx
 * DESCRIPTION
 *  Get the context of the protocol layer of SIM
 * PARAMETERS
 *  sim     [IN] Which protocol layer of SIM
 * RETURNS
 *  Context
 *****************************************************************************/
static srv_imei_cntx_struct* srv_imei_get_cntx(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_srv_imei_cntx[mmi_frm_sim_to_index(sim)]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_imei_init_cntx
 * DESCRIPTION
 *  Initiailze context
 * PARAMETERS
 *  sim     [IN] Which protocol layer of SIM
 *  cntx    [IN] Context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_imei_init_cntx(mmi_sim_enum sim, srv_imei_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 raw_imei[NVRAM_EF_IMEI_IMEI_SIZE];
    S32 i;
    U8 bcd;
    S32 nvram_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx->is_inited)
    {
        raw_imei[0] = 0xff;

        nvram_index = mmi_frm_sim_to_index(sim) + 1;
        nvram_get_imei_value(NVRAM_EF_IMEI_IMEI_SIZE, raw_imei, nvram_index);

        /* Convert BCD string raw_imei to char string cntx->imei */
        for (i = 0; i < SRV_IMEI_MAX_LEN; i++)
        {
            if ((i & 0x1) == 0)
            {
                bcd = raw_imei[i >> 1] & 0xf;
            }
            else
            {
                bcd = (raw_imei[i >> 1] >> 4) & 0xf;
            }

            cntx->imei[i] = srv_imei_bcd_to_char(bcd);
        }

        cntx->imei[SRV_IMEI_MAX_LEN] = '\0';

        /* Check validity of IMEI, invalid value was converted to '\0' */
        if (strlen(cntx->imei) != SRV_IMEI_MAX_LEN)
        {
            /* Invalid IMEI */
            cntx->imei[0] = '\0';
        }

        cntx->is_inited = MMI_TRUE;
    }
}


/*****************************************************************************
 * Refer to ImeiSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_imei_get_imei(mmi_sim_enum sim, CHAR *out_buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_imei_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EXT_ASSERT(buffer_size >= SRV_IMEI_MAX_LEN + 1,
        buffer_size, 0, 0);

    cntx = srv_imei_get_cntx(sim);
    srv_imei_init_cntx(sim, cntx);

    app_strlcpy(out_buffer, cntx->imei, buffer_size);

    return (out_buffer[0] == '\0' ? MMI_FALSE : MMI_TRUE);
}


/*****************************************************************************
 * Refer to ImeiSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_imei_is_valid(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_imei_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = srv_imei_get_cntx(sim);
    srv_imei_init_cntx(sim, cntx);

    return (cntx->imei[0] == '\0' ? MMI_FALSE : MMI_TRUE);
}


/*****************************************************************************
 * Refer to ImeiSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_imei_same_config_on_any_pair(mmi_sim_enum sim)
{
#if (MMI_MAX_SIM_NUM >= 2)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_sim_enum simx;
    srv_imei_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        simx = mmi_frm_index_to_sim(i);
        cntx = &(g_srv_imei_cntx[i]);
        srv_imei_init_cntx(simx, cntx);
    }

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
    	if (i == mmi_frm_sim_to_index(sim))
        {
    		continue;
        }

        if (strncmp(g_srv_imei_cntx[i].imei, g_srv_imei_cntx[mmi_frm_sim_to_index(sim)].imei, SRV_IMEI_MAX_LEN) == 0)
        {
            return MMI_TRUE;
        }
    }
#endif

    return MMI_FALSE;
}

