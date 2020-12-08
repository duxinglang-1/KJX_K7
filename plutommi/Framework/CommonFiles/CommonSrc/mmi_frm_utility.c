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
 *    mmi_frm_utility.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Common Utility
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "mmi_frm_gprot.h"
#include "mmi_frm_utility_gprot.h"

#include "gdi_include.h"

/****************************************************************************
 * Define
 ****************************************************************************/

//#define __MMI_FRM_UTILITY_UT__


/****************************************************************************
 * Global context
 ****************************************************************************/

/* Fill MMI SIM enum and L4C module id in g_mmi_sim_array[] and g_mmi_l4c_array[]. The array size should be the same with MMI_SIM_TOTAL */
static const mmi_sim_enum g_mmi_sim_array[] = { MMI_SIM1
                                            #if (MMI_MAX_SIM_NUM >= 2)
                                                ,MMI_SIM2
                                            #if (MMI_MAX_SIM_NUM >= 3)
                                                ,MMI_SIM3
                                            #if (MMI_MAX_SIM_NUM >= 4)
                                                ,MMI_SIM4
                                            #endif /* MMI_MAX_SIM_NUM >= 4 */
                                            #endif /* MMI_MAX_SIM_NUM >= 3 */
                                            #endif /* MMI_MAX_SIM_NUM >= 2 */
                                              };


static const module_type g_mmi_l4c_array[] = {MOD_L4C
                                            #if (MMI_MAX_SIM_NUM >= 2)
                                              ,MOD_L4C_2
                                            #if (MMI_MAX_SIM_NUM >= 3)
                                              ,MOD_L4C_3
                                            #if (MMI_MAX_SIM_NUM >= 4)
                                              ,MOD_L4C_4
                                            #endif /* MMI_MAX_SIM_NUM >= 4 */
                                            #endif /* MMI_MAX_SIM_NUM >= 3 */
                                            #endif /* MMI_MAX_SIM_NUM >= 2 */
                                             };

/****************************************************************************
 * Function
 ****************************************************************************/

U32 mmi_frm_sim_to_index(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(MMI_SIM_TOTAL == sizeof(g_mmi_sim_array)/sizeof(g_mmi_sim_array[0]));
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (g_mmi_sim_array[i] == sim)
        {
            return i;
        }
    }
    /* SIM enum is out of the max SIM number in this project */
    MMI_ASSERT(0);
    return MMI_SIM_END_OF_ENUM;
}


mmi_sim_enum mmi_frm_index_to_sim(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(MMI_SIM_TOTAL == sizeof(g_mmi_sim_array)/sizeof(g_mmi_sim_array[0]));
    /* The SIM index should be less than the max SIM number in this project */
    MMI_ASSERT(MMI_SIM_TOTAL >= index);
    return g_mmi_sim_array[index];
}


module_type mmi_frm_sim_to_l4c_mod(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = mmi_frm_sim_to_index(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_l4c_array[index];
}


mmi_sim_enum mmi_frm_l4c_mod_to_sim(module_type mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(MMI_SIM_TOTAL == sizeof(g_mmi_l4c_array)/sizeof(g_mmi_l4c_array[0]));
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (g_mmi_l4c_array[i] == mod_id)
        {
            return g_mmi_sim_array[i];
        }
    }
    /* Can't find the corresponding L4C module id */
    MMI_ASSERT(0);
    return MMI_SIM_END_OF_ENUM;
}




#ifdef __MMI_FRM_UTILITY_UT__

MMI_BOOL mmi_frm_utility_sim_enum_index_test_case(void)
{
    MMI_ASSERT(mmi_frm_sim_enum_to_index(MMI_SIM1) == 0);
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_ASSERT(mmi_frm_sim_enum_to_index(MMI_SIM2) == 1);
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_ASSERT(mmi_frm_sim_enum_to_index(MMI_SIM3) == 2);
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_ASSERT(mmi_frm_sim_enum_to_index(MMI_SIM4) == 3);
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* MMI_MAX_SIM_NUM >= 2 */

    MMI_ASSERT(mmi_frm_sim_index_to_enum(0) == MMI_SIM1);
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_ASSERT(mmi_frm_sim_index_to_enum(1) == MMI_SIM2);
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_ASSERT(mmi_frm_sim_index_to_enum(2) == MMI_SIM3);
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_ASSERT(mmi_frm_sim_index_to_enum(3) == MMI_SIM4);
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* MMI_MAX_SIM_NUM >= 2 */
}

MMI_BOOL mmi_frm_utility_sim_enum_l4c_test_case(void)
{
    MMI_ASSERT(mmi_frm_sim_enum_to_l4c_module_id(MMI_SIM1) == MOD_L4C);
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_ASSERT(mmi_frm_sim_enum_to_l4c_module_id(MMI_SIM2) == MOD_L4C_2);
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_ASSERT(mmi_frm_sim_enum_to_l4c_module_id(MMI_SIM3) == MOD_L4C_3);
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_ASSERT(mmi_frm_sim_enum_to_l4c_module_id(MMI_SIM4) == MOD_L4C_4);
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* MMI_MAX_SIM_NUM >= 2 */

    MMI_ASSERT(mmi_frm_l4c_module_id_to_sim_enum(MOD_L4C) == MMI_SIM1);
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_ASSERT(mmi_frm_l4c_module_id_to_sim_enum(MOD_L4C_2) == MMI_SIM2);
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_ASSERT(mmi_frm_l4c_module_id_to_sim_enum(MOD_L4C_3) == MMI_SIM3);
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_ASSERT(mmi_frm_l4c_module_id_to_sim_enum(MOD_L4C_4) == MMI_SIM4);
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* MMI_MAX_SIM_NUM >= 2 */
}



typedef MMI_BOOL (*mmi_frm_utility_test_case_fp)(void);
typedef struct
{
    S8 index;
    mmi_frm_utility_test_case_fp test_case_func;
} mmi_frm_utility_test_case_struct;

static const mmi_frm_utility_test_case_struct mmi_frm_utility_test_case_db[] =
{
    /* Test all cases */
    {0,     NULL},
    {1,     mmi_frm_utility_sim_enum_index_test_case},
    {2,     mmi_frm_utility_sim_enum_l4c_test_case},
    {-1,    NULL}
};

void mmi_frm_utility_test_case_expiry(void* arg)
{
    static U8 __i;

    if (arg == (void*)1)
    {
        __i = 1;
    }
    if (mmi_frm_utility_test_case_db[__i].index > 0 && mmi_frm_utility_test_case_db[__i].test_case_func)
    {
        mmi_frm_utility_test_case_db[__i].test_case_func();
        gui_start_timer_ex(100, mmi_frm_utility_test_case_expiry, (void*)2);
        __i++;
    }
    else
    {
        __i = 0;
    }
}

void mmi_frm_utility_test_case_entry(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == index)
    {
        /* Test all cases */
        gui_start_timer_ex(100, mmi_frm_utility_test_case_expiry, (void*)1);
    }
    else
    {
        mmi_frm_utility_test_case_db[index].test_case_func();
    }
}


#endif /* __MMI_FRM_UTILITY_UT__ */

void mmi_frm_set_cabc_mode(mmi_frm_cabc_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_cabc_mode_enum gdi_mode = GDI_CABC_MODE_OFF; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CABC__
    mode = MMI_FRM_CABC_MODE_OFF;
#endif

    switch (mode)
    {
        case MMI_FRM_CABC_MODE_OFF:
            gdi_mode = GDI_CABC_MODE_OFF;
            break;
        case MMI_FRM_CABC_MODE_UI:
            gdi_mode = GDI_CABC_MODE_UI;
            break;            
        case MMI_FRM_CABC_MODE_STILL:
            gdi_mode = GDI_CABC_MODE_STILL;
            break;            
        case MMI_FRM_CABC_MODE_MOVING:
            gdi_mode = GDI_CABC_MODE_MOVING;
            break;            
        default:
            MMI_ASSERT(0);
            break;            
    }
    
    gdi_cabc_set_mode(gdi_mode);    
}


mmi_frm_cabc_mode_enum mmi_frm_get_cabc_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_cabc_mode_enum mode = MMI_FRM_CABC_MODE_OFF; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gdi_cabc_get_mode())
    {
        case GDI_CABC_MODE_OFF:
            mode = MMI_FRM_CABC_MODE_OFF;
            break;
        case GDI_CABC_MODE_UI:
            mode = MMI_FRM_CABC_MODE_UI;
            break;            
        case GDI_CABC_MODE_STILL:
            mode = MMI_FRM_CABC_MODE_STILL;
            break;            
        case GDI_CABC_MODE_MOVING:
            mode = MMI_FRM_CABC_MODE_MOVING;
            break;            
        default:
            MMI_ASSERT(0);
            break;            
    }
        
    return mode;
}


void mmi_frm_reset_cabc_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CABC__
    mmi_frm_set_cabc_mode(MMI_FRM_CABC_MODE_OFF);
#else
    gdi_cabc_reset();
#endif      
}


