/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerCuiFactory.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the dialer CUI factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "DialerCuiFactory.h"
#include "DialerCuiObject.h"
#include "DialerCuiGprot.h"
#include "DialerCuiSearch.h"
#include "DialerCuiClassic.h"
#include "DialerCuiSos.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "DialerCuiObject.h"
#include "DialerCuiVoip.h"

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    S8                      num;
    cui_dialer_obj_struct  *obj[CUI_DIALER_MAX_OBJ_NUM];
} cui_dialer_factory_cntx_struct;


/****************************************************************************
 * Global Context
 ****************************************************************************/

static cui_dialer_factory_cntx_struct g_cui_dialer_factory_cntx;


const static cui_dialer_cfg_struct g_cui_dialer_cfg_tbl[] =
{
#ifdef __OP01_FWPBW__
    CUI_DIALER_CFG_ADD(
        CUI_DIALER_TYPE_BWT,
        sizeof(cui_dialer_bwt_struct),
        cui_dialer_bwt_on_want_to_run,
        cui_dialer_bwt_on_init),
#endif

#if defined(__MMI_VOIP__)
    CUI_DIALER_CFG_ADD(
        CUI_DIALER_TYPE_VOIP,
        sizeof(cui_dialer_voip_struct),
        cui_dialer_voip_on_want_to_run,
        cui_dialer_voip_on_init),
#endif /* defined(__MMI_VOIP__) */

#if defined(__MMI_DIALER_SEARCH__)
    CUI_DIALER_CFG_ADD(
        CUI_DIALER_TYPE_SEARCH,
        sizeof(cui_dialer_search_struct),
        cui_dialer_search_on_want_to_run,
        cui_dialer_search_on_init),
#endif /* defined(__MMI_DIALER_SEARCH__) */

    CUI_DIALER_CFG_ADD(
        CUI_DIALER_TYPE_CLASSIC,
        sizeof(cui_dialer_classic_struct),
        cui_dialer_obj_on_want_to_run,
        cui_dialer_classic_on_init),

    CUI_DIALER_CFG_ADD(
        CUI_DIALER_TYPE_SOS,
        sizeof(cui_dialer_sos_struct),
        cui_dialer_obj_on_want_to_run,
        cui_dialer_sos_on_init),

    CUI_DIALER_CFG_END()
};


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_first_cfg
 * DESCRIPTION
 *  This function gets the first configuration.
 * PARAMETERS
 *  void
 * RETURNS
 *  Configuration.
 *****************************************************************************/
static const cui_dialer_cfg_struct *cui_dialer_get_first_cfg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cui_dialer_cfg_tbl[0].type == CUI_DIALER_TYPE_INVALID)
    {
        return NULL;
    }

    return &(g_cui_dialer_cfg_tbl[0]);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_next_cfg
 * DESCRIPTION
 *  This function gets the next configuration.
 * PARAMETERS
 *  cfg             : [IN]          Configuration
 * RETURNS
 *  Configuration.
 *****************************************************************************/
static const cui_dialer_cfg_struct *
cui_dialer_get_next_cfg(const cui_dialer_cfg_struct *cfg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cfg || cfg[1].type == CUI_DIALER_TYPE_INVALID)
    {
        return NULL;
    }

    return &(cfg[1]);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_cfg
 * DESCRIPTION
 *  This function gets the configuration of the specified type.
 * PARAMETERS
 *  type            : [IN]          Type
 * RETURNS
 *  Configuration.
 *****************************************************************************/
static const cui_dialer_cfg_struct *
cui_dialer_get_cfg(cui_dialer_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const cui_dialer_cfg_struct *cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (cfg = cui_dialer_get_first_cfg();
         cfg != NULL;
         cfg = cui_dialer_get_next_cfg(cfg))
    {
        if (cfg->type == type)
        {
            return cfg;
        }
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_reg_obj
 * DESCRIPTION
 *  This function registers the dialer object.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_reg_obj(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_factory_cntx_struct *cntx = &g_cui_dialer_factory_cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ++cntx->num;
    MMI_ASSERT(cntx->num <= CUI_DIALER_MAX_OBJ_NUM);

    for (i = 0; i < CUI_DIALER_MAX_OBJ_NUM; i++)
    {
        if (cntx->obj[i] == NULL)
        {
            cntx->obj[i] = obj;
            return;
        }
    }

    MMI_ASSERT(0); /* not found */
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_dereg_obj
 * DESCRIPTION
 *  This function deregisters the dialer object.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_dereg_obj(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_factory_cntx_struct *cntx = &g_cui_dialer_factory_cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx->num > 0);
    --cntx->num;

    for (i = 0; i < CUI_DIALER_MAX_OBJ_NUM; i++)
    {
        if (cntx->obj[i] == obj)
        {
            cntx->obj[i] = NULL;
            return;
        }
    }

    MMI_ASSERT(0); /* not found */
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_favorite_type
 * DESCRIPTION
 *  This function gets the favorite dialer type.
 * PARAMETERS
 *  void
 * RETURNS
 *  Type.
 *****************************************************************************/
cui_dialer_type_enum cui_dialer_get_favorite_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const cui_dialer_cfg_struct *cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (cfg = cui_dialer_get_first_cfg();
         cfg != NULL;
         cfg = cui_dialer_get_next_cfg(cfg))
    {
        if (cfg->on_want_to_run && cfg->on_want_to_run())
        {
            return (cui_dialer_type_enum)cfg->type;
        }
    }

    return CUI_DIALER_TYPE_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_new_obj
 * DESCRIPTION
 *  This function news a dialer object of the favorite type.
 * PARAMETERS
 *  void
 * RETURNS
 *  Dialer object.
 *****************************************************************************/
cui_dialer_obj_struct *cui_dialer_new_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = cui_dialer_get_favorite_type();

    return cui_dialer_new_obj_ex(type);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_new_obj_ex
 * DESCRIPTION
 *  This function news a dialer object of the specified type.
 * PARAMETERS
 *  type            : [IN]              Type
 * RETURNS
 *  Dialer object.
 *****************************************************************************/
cui_dialer_obj_struct *cui_dialer_new_obj_ex(cui_dialer_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const cui_dialer_cfg_struct *cfg;
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == CUI_DIALER_TYPE_UNSPECIFIED)
    {
        type = cui_dialer_get_favorite_type();
    }

    cfg = cui_dialer_get_cfg(type);

    obj = (cui_dialer_obj_struct *)mmi_malloc(cfg->size);

    memset(obj, 0, cfg->size);

    obj->type = type;

    if (cfg->on_init)
    {
        cfg->on_init(obj);
    }

    cui_dialer_reg_obj(obj);

    return obj;
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_obj_in_active_serial
 * DESCRIPTION
 *  This function gets the dialer object in the active serial of the group.
 * PARAMETERS
 *  void
 * RETURNS
 *  Dialer object.
 *****************************************************************************/
cui_dialer_obj_struct *cui_dialer_get_obj_in_active_serial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_factory_cntx_struct *cntx = &g_cui_dialer_factory_cntx;
    cui_dialer_obj_struct *obj;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_DIALER_MAX_OBJ_NUM; i++)
    {
        obj = cntx->obj[i];

        if (obj && obj->this_gid != GRP_ID_INVALID &&
            mmi_frm_group_is_in_active_serial(obj->this_gid))
        {
            return obj;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_obj_in_history
 * DESCRIPTION
 *  This function gets the dialer object in the history.
 * PARAMETERS
 *  void
 * RETURNS
 *  Dialer object.
 *****************************************************************************/
cui_dialer_obj_struct *cui_dialer_get_obj_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_factory_cntx_struct *cntx = &g_cui_dialer_factory_cntx;
    cui_dialer_obj_struct *obj;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_DIALER_MAX_OBJ_NUM; i++)
    {
        obj = cntx->obj[i];

        if (obj && obj->this_gid != GRP_ID_INVALID &&
            mmi_frm_group_is_present(obj->this_gid))
        {
            return obj;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_factory_init
 * DESCRIPTION
 *  This function initializes the dialer factory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_factory_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_factory_cntx_struct *cntx = &g_cui_dialer_factory_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(cntx, 0, sizeof(cui_dialer_factory_cntx_struct));
}

