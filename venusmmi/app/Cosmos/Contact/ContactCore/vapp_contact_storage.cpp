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
 *  vapp_contact_storage.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "vapp_contact_storage.h"
#include "mmi_rp_vapp_contact_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
#include "mmi_rp_vapp_fmgr_def.h"
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_frm_utility_gprot.h"
#include "GlobalResDef.h"
#include "PhbSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#ifdef __cplusplus
}
#endif


VfxU32 ContactStorage::getMask()
{
    return (VfxU32) srv_phb_get_storage_mask();
}


VfxU32 ContactStorage::getMask(phb_storage_enum storage)
{
    return (VfxU32) (1 << storage);
}


STORAGE_STATUS ContactStorage::getStatus(phb_storage_enum storage)
{
    STORAGE_STATUS status = STORAGE_VALID;

    if (!srv_phb_check_storage_accessible(storage))
    {
        status = STORAGE_NOT_ACCESSABLE;
    }
    else if (srv_phb_get_used_contact(storage) == srv_phb_get_total_contact(storage))
    {
        status = STORAGE_FULL;
    }
    else if (srv_phb_get_used_contact(storage) == 0)
    {
        status = STORAGE_EMPTY;
    }

    return status;
}


VfxImageSrc ContactStorage::getIcon(mmi_phb_contact_id id)
{
    return getIconEx(getStorage(id));
}


VfxImageSrc ContactStorage::getIconEx(phb_storage_enum storage)
{
    if (srv_sim_ctrl_get_num_of_inserted() == 1 // hot sim plug
        && (storage == PHB_STORAGE_SIM || storage == PHB_STORAGE_SIM2 || storage == PHB_STORAGE_SIM3 || storage == PHB_STORAGE_SIM4)
       )
    {
        return VfxImageSrc(IMG_COSMOS_SINGLE_SIM);
    }

    switch (storage)
    {
        case PHB_STORAGE_NVRAM:
            return VfxImageSrc(IMG_ID_VAPP_PHB_PHONE);

        case PHB_STORAGE_SIM:
        #if (MMI_MAX_SIM_NUM >= 2)
            return VfxImageSrc(IMG_COSMOS_SIM1);
        #else
            return VfxImageSrc(IMG_COSMOS_SINGLE_SIM);
        #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case PHB_STORAGE_SIM2:
            return VfxImageSrc(IMG_COSMOS_SIM2);
    #if (MMI_MAX_SIM_NUM >= 3)
        case PHB_STORAGE_SIM3:
            return VfxImageSrc(IMG_COSMOS_SIM3);
    #if (MMI_MAX_SIM_NUM >= 4)
        case PHB_STORAGE_SIM4:
            return VfxImageSrc(IMG_COSMOS_SIM4);
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case PHB_STORAGE_TCARD:
            return VfxImageSrc(IMG_ID_VAPP_FMGR_TAB_CARD_ICN); // icon from fmgr
    #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

        default:
            VFX_ASSERT(0);
            break;
    }

    return VfxImageSrc();
}


phb_storage_enum ContactStorage::getStorage(mmi_phb_contact_id id)
{
    return (phb_storage_enum) srv_phb_get_storage(id);
}


VfxWString ContactStorage::getName(phb_storage_enum storage)
{
    if (srv_sim_ctrl_get_num_of_inserted() == 1 // hot sim plug
        && (storage == PHB_STORAGE_SIM || storage == PHB_STORAGE_SIM2 || storage == PHB_STORAGE_SIM3 || storage == PHB_STORAGE_SIM4)
       )
    {
        return VFX_WSTR_RES(STR_GLOBAL_SIM);
    }

    switch (storage)
    {
        case PHB_STORAGE_NVRAM:
            return VFX_WSTR_RES(VAPP_PHB_STR_PHONE);

        case PHB_STORAGE_SIM:
        #if (MMI_MAX_SIM_NUM >= 2)
            return VFX_WSTR_RES(STR_GLOBAL_SIM_1);
        #else
            return VFX_WSTR_RES(STR_GLOBAL_SIM);
        #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case PHB_STORAGE_SIM2:
            return VFX_WSTR_RES(STR_GLOBAL_SIM_2);
    #if (MMI_MAX_SIM_NUM >= 3)
        case PHB_STORAGE_SIM3:
            return VFX_WSTR_RES(STR_GLOBAL_SIM_3);
    #if (MMI_MAX_SIM_NUM >= 4)
        case PHB_STORAGE_SIM4:
            return VFX_WSTR_RES(STR_GLOBAL_SIM_4);
    #endif /* MMI_MAX_SIM_NUM >= 4 */
    #endif /* MMI_MAX_SIM_NUM >= 3 */
    #endif /* MMI_MAX_SIM_NUM >= 2 */
    
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case PHB_STORAGE_TCARD:
           return VFX_WSTR_RES(STR_ID_VAPP_PHB_MEMORY_CARD);
    #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

        default:
            VFX_ASSERT(0);
            break;
    }

    return VFX_WSTR_EMPTY;
}


VfxU32 ContactSim::getTotal()
{
    return MMI_SIM_TOTAL;
}


VfxImageSrc ContactSim::getIcon(mmi_sim_enum sim)
{
    switch (sim)
    {
        case MMI_SIM1:
        #if (MMI_MAX_SIM_NUM >= 2)
            return VfxImageSrc(IMG_COSMOS_SIM1);
        #else
            return VfxImageSrc(IMG_COSMOS_SINGLE_SIM);
        #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return VfxImageSrc(IMG_COSMOS_SIM2);
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return VfxImageSrc(IMG_COSMOS_SIM3);
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            return VfxImageSrc(IMG_COSMOS_SIM4);
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        default:
            VFX_ASSERT(0);
            break;
    }

    return VfxImageSrc();
}


VfxResId ContactSim::getCallIconId(mmi_sim_enum sim)
{
    if (srv_sim_ctrl_get_num_of_inserted() == 1) // hot sim plug
    {
        return IMG_COSMOS_GEMINI_SIM_CALL;
    }

    switch (sim)
    {
        case MMI_SIM1:
        #if (MMI_MAX_SIM_NUM >= 2)
            return IMG_COSMOS_GEMINI_SIM1_CALL;
        #else
            return IMG_COSMOS_GEMINI_SIM_CALL;
        #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return IMG_COSMOS_GEMINI_SIM2_CALL;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return IMG_COSMOS_GEMINI_SIM3_CALL;
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            return IMG_COSMOS_GEMINI_SIM4_CALL;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        default:
            VFX_ASSERT(0);
            break;
    }

    return IMG_NONE;
}


VfxImageSrc ContactSim::getCallIcon(mmi_sim_enum sim)
{
    return VfxImageSrc(getCallIconId(sim));
}


VfxResId ContactSim::getMsgIconId(mmi_sim_enum sim)
{
    if (srv_sim_ctrl_get_num_of_inserted() == 1) // hot sim plug
    {
        return IMG_COSMOS_GEMINI_SIM_MSG;
    }

    switch (sim)
    {
        case MMI_SIM1:
        #if (MMI_MAX_SIM_NUM >= 2)
            return IMG_COSMOS_GEMINI_SIM1_MSG;
        #else
            return IMG_COSMOS_GEMINI_SIM_MSG;
        #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return IMG_COSMOS_GEMINI_SIM2_MSG;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return IMG_COSMOS_GEMINI_SIM3_MSG;
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            return IMG_COSMOS_GEMINI_SIM4_MSG;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        default:
            VFX_ASSERT(0);
            break;
    }

    return IMG_NONE;
}


VfxImageSrc ContactSim::getMsgIcon(mmi_sim_enum sim)
{
    return VfxImageSrc(getMsgIconId(sim));
}


phb_storage_enum ContactSim::getStorage(mmi_sim_enum sim)
{
    switch (sim)
    {
        case MMI_SIM1:
            return PHB_STORAGE_SIM;

    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return PHB_STORAGE_SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return PHB_STORAGE_SIM3;
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            return PHB_STORAGE_SIM4;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        default:
            VFX_ASSERT(0);
            break;
    }

    return PHB_STORAGE_NONE;
}


VfxWString ContactSim::getName(mmi_sim_enum sim)
{
    if (srv_sim_ctrl_get_num_of_inserted() == 1) // hot sim plug
    {
        return VFX_WSTR_RES(STR_GLOBAL_SIM);
    }
    
    switch (sim)
    {
        case MMI_SIM1:
        #if (MMI_MAX_SIM_NUM >= 2)
            return VFX_WSTR_RES(STR_GLOBAL_SIM_1);
        #else
            return VFX_WSTR_RES(STR_GLOBAL_SIM);
        #endif

    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return VFX_WSTR_RES(STR_GLOBAL_SIM_2);
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return VFX_WSTR_RES(STR_GLOBAL_SIM_3);
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            return VFX_WSTR_RES(STR_GLOBAL_SIM_4);
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        default:
            VFX_ASSERT(0);
            break;
    }

    return VFX_WSTR_EMPTY;
}

