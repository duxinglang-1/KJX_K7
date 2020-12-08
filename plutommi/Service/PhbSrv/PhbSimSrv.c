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
 *  PhbSimSrv.c
 *
 * Project:
 * --------
 *  MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "GSM7BitDefaultAlphabet.h"
#include "App_usedetails.h"
//#include "SimDetectionDef.h"
//#include "SimDetectionGprot.h"
#include "mmi_rp_srv_phb_def.h"

//#undef __MMI_PHB_USIM_SUPPORT__

#ifdef __MMI_PHB_USIM_SUPPORT__

typedef struct
{
    void (*init_func)(U8 sim_id, phb_storage_enum storage);
} srv_phb_usim_init_struct;


typedef enum
{
    SRV_PHB_SIM_OP_EMAIL,
    SRV_PHB_SIM_OP_ANR,
    SRV_PHB_SIM_OP_SNE,
    SRV_PHB_SIM_OP_ADN,
    SRV_PHB_SIM_OP_GRP,
    SRV_PHB_SIM_OP_TOTAL,
} srv_phb_sim_op_enum;

typedef struct
{
    U16 cur_index;
    U8 cur_occur;
    U8 init_index;
    void (*continue_func)(U8 sim_id, phb_storage_enum storage, int mod_id);
    void (*return_func)(U8 sim_id, phb_storage_enum storage);
} srv_phb_usim_init_cntx_struct;


typedef struct
{
    srv_phb_sim_anr_struct* anr[MMI_PHB_MAX_ANR_COUNT];
    srv_phb_sim_email_struct* email[MMI_PHB_MAX_EMAIL_COUNT];
    srv_phb_sim_sne_struct* sne;
    srv_phb_sim_aas_struct* aas;
    srv_phb_sim_grp_struct* grp;
    srv_phb_sim_gas_struct* gas;
} srv_phb_usim_cache_struct;

typedef struct
{
    srv_phb_sim_op_enum status;
    U8 cur_occur;
    U8 op_occur;
    U8 sim_id;
    U8 cur_index;
    U8 finish_count;
    int mod;
    srv_phb_iterator iterator;
    S32 result;
    mmi_phb_contact_id dest_id;
    MMI_BOOL (* continue_func)(void);
} srv_phb_sim_op_cntx_struct;
#else


typedef struct
{
    U8 cur_index;
    U8 finish_count;
    mmi_phb_contact_id dest_id;
    S32 result;
    MMI_BOOL (* continue_func)(srv_phb_datamgr_op_status_struct* status);
} srv_phb_sim_op_cntx_struct;
#endif /* __MMI_PHB_USIM_SUPPORT__ */


#define SRV_PHB_SIM_CONVERT_ID(_id, _index) \
    do {                                    \
        _id -= MMI_PHB_PHONE_ENTRIES;       \
        while (_id >= MMI_PHB_SIM_ENTRIES)  \
        {                                   \
            _id -= MMI_PHB_SIM_ENTRIES;     \
            _index++;                       \
        }                                   \
    } while (0)

typedef struct
{
    U16 used_count;
    U16 total_count;
#ifdef __MMI_PHB_USIM_SUPPORT__
    U16 anr_used[MMI_PHB_MAX_ANR_COUNT];
    U16 anr_total[MMI_PHB_MAX_ANR_COUNT];
    U16 email_used[MMI_PHB_MAX_EMAIL_COUNT];
    U16 email_total[MMI_PHB_MAX_EMAIL_COUNT];
    U16 sne_used;
    U16 sne_total;
    U8 anr_occur;
    U8 email_occur;
    U8 sne_occur;
    U8 aas_total;
    U8 gas_used;
    U8 gas_total;
#endif
} srv_phb_sim_cntx_struct;

static srv_phb_sim_cntx_struct g_srv_phb_sim_cntx[MMI_PHB_SIM_COUNT];
static srv_phb_sim_cache_struct* g_srv_phb_sim_cache[MMI_PHB_SIM_COUNT];

#ifdef __MMI_PHB_USIM_SUPPORT__
static srv_phb_usim_cache_struct g_srv_phb_usim_cache[MMI_PHB_SIM_COUNT];
static srv_phb_usim_init_cntx_struct g_srv_phb_usim_init_cntx[MMI_PHB_SIM_COUNT];
#endif
static srv_phb_sim_op_cntx_struct g_srv_phb_sim_op_cntx;

#ifdef __MMI_PHB_USIM_SUPPORT__
static void srv_phb_init_sim_op_cntx(phb_storage_enum storage);
static void srv_phb_get_next_anr_info(U8 sim_id, phb_storage_enum storage, int mod_id);
static void srv_phb_init_anr_info(U8 sim_id, phb_storage_enum storage);
static void srv_phb_get_next_email_info(U8 sim_id, phb_storage_enum storage, int mod_id);
static void srv_phb_init_email_info(U8 sim_id, phb_storage_enum storage);
static void srv_phb_init_sne_info(U8 sim_id, phb_storage_enum storage);
static void srv_phb_init_usim(U8 sim_id, phb_storage_enum storage);
static void srv_phb_read_next_anr(U8 sim_id, phb_storage_enum storage, int mod_id);
static void srv_phb_init_anr(U8 sim_id, phb_storage_enum storage);
static void srv_phb_read_next_email(U8 sim_id, phb_storage_enum storage, int mod_id);
static void srv_phb_init_email(U8 sim_id, phb_storage_enum storage);
static void srv_phb_init_sne(U8 sim_id, phb_storage_enum storage);
static void srv_phb_read_next_aas(U8 sim_id, phb_storage_enum storage, int mod_id);
static void srv_phb_init_aas(U8 sim_id, phb_storage_enum storage);
static void srv_phb_init_gas(U8 sim_id, phb_storage_enum storage);
static void srv_phb_init_grp(U8 sim_id, phb_storage_enum storage);

static MMI_BOOL srv_phb_set_sim_number_req(phb_storage_enum storage, U16 index, U8 occur, WCHAR* name, WCHAR* number, U8 aas_id);
static void srv_phb_set_usim_field_req(phb_type_enum type, U16 index, U8 occur, WCHAR* data);
static void srv_phb_delete_usim_field_req(phb_type_enum type, U16 record_index, U8 occurrence);
static void srv_phb_delete_sim_number_req(phb_storage_enum storage, U16 record_index, U8 occurrence);

static void srv_phb_read_email_rsp(void *info, int mod_src);
static void srv_phb_read_sne_rsp(void *info, int mod_src);
static void srv_phb_read_aas_rsp(void *info, int mod_src);
static void srv_phb_read_gas_rsp(void *info, int mod_src);
static void srv_phb_read_grp_rsp(void *info, int mod_src);

const srv_phb_usim_init_struct phb_usim_init_info_table[] =
{
    /* init anr info */
    {
        srv_phb_init_anr_info
    },
    /* init email info */
    {
        srv_phb_init_email_info
    },
    /* init sne info */
    {
        srv_phb_init_sne_info
    },
    {
        NULL
    }
};


const srv_phb_usim_init_struct phb_usim_init_table[] =
{
    /* init anr */
    {
        srv_phb_init_anr
    },
    /* init email */
    {
        srv_phb_init_email
    },
    /* init sne info */
    {
        srv_phb_init_sne
    },
    /* init aas */
    {
        srv_phb_init_aas
    },
    /*init gas*/
    {
        srv_phb_init_gas
    },    
    /*init grp*/
    {
        srv_phb_init_grp
    },
    {
        NULL
    }
};
#endif /* __MMI_PHB_USIM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
U8 srv_phb_get_sim_id(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (storage)
    {
        case PHB_STORAGE_SIM:
            return 0;
            
    #if (MMI_MAX_SIM_NUM >= 2)
        case PHB_STORAGE_SIM2:
            return 1;
    #endif
    
    #if (MMI_MAX_SIM_NUM >= 3)
        case PHB_STORAGE_SIM3:
            return 2;
    #endif
                
    #if (MMI_MAX_SIM_NUM >= 4)
        case PHB_STORAGE_SIM4:
            return 3;
    #endif

        case PHB_STORAGE_MAX:
            return MMI_PHB_SIM_COUNT;
            
        default:
            ASSERT (0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_storage_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
phb_storage_enum srv_phb_get_storage_by_sim_id(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case 0:
            return PHB_STORAGE_SIM;
            
    #if (MMI_MAX_SIM_NUM >= 2)
        case 1:
            return PHB_STORAGE_SIM2;
    #endif
            
    #if (MMI_MAX_SIM_NUM >= 3)
        case 2:
            return PHB_STORAGE_SIM3;
    #endif
                
    #if (MMI_MAX_SIM_NUM >= 4)
        case 3:
            return PHB_STORAGE_SIM4;
    #endif
        default:
            ASSERT (0);
    }
    return PHB_STORAGE_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_id_by_mod_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
U8 srv_phb_get_sim_id_by_mod_id(int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mod_id)
    {
        case MOD_L4C:
            return 0;
            
    #if (MMI_MAX_SIM_NUM >= 2)
        case MOD_L4C_2:
            return 1;
    #endif
    
    #if (MMI_MAX_SIM_NUM >= 3)
        case MOD_L4C_3:
            return 2;
    #endif
                
    #if (MMI_MAX_SIM_NUM >= 4)
        case MOD_L4C_4:
            return 3;
    #endif
        default:
            ASSERT (0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_l4c_mod_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
int srv_phb_get_l4c_mod_by_sim_id(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case 0:
            return MOD_L4C;
            
    #if (MMI_MAX_SIM_NUM >= 2)
        case 1:
            return MOD_L4C_2;
    #endif
    
    #if (MMI_MAX_SIM_NUM >= 3)
        case 2:
            return MOD_L4C_3;
    #endif
                
    #if (MMI_MAX_SIM_NUM >= 4)
        case 3:
            return MOD_L4C_4;
    #endif

        default:
            ASSERT (0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_l4c_mod_by_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
static int srv_phb_get_l4c_mod_by_storage(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (storage)
    {
        case PHB_STORAGE_SIM:
            return MOD_L4C;
            
    #if (MMI_MAX_SIM_NUM >= 2)
        case PHB_STORAGE_SIM2:
            return MOD_L4C_2;
    #endif
    
    #if (MMI_MAX_SIM_NUM >= 3)
        case PHB_STORAGE_SIM3:
            return MOD_L4C_3;
    #endif
                
    #if (MMI_MAX_SIM_NUM >= 4)
        case PHB_STORAGE_SIM4:
            return MOD_L4C_4;
    #endif

        default:
            ASSERT (0);
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_update_field_mask
 * DESCRIPTION
 *  update name and number fileter flag of a entry.
 * PARAMETERS
 *  store_index              [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_update_field_mask(U8 sim_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sim_adn_struct* adn_cache = &(g_srv_phb_sim_cache[sim_id][index].adn);
    U32* field_mask = &(g_srv_phb_sim_cache[sim_id][index].field_mask);
#ifdef __MMI_PHB_USIM_SUPPORT__
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *field_mask = MMI_PHB_CONTACT_FIELD_EXIST;  /* to mark the contact is exist, special use */
    if (adn_cache->name[0])
    {
        *field_mask |= MMI_PHB_CONTACT_FIELD_NAME;
    }
    else
    {
        *field_mask &= ~MMI_PHB_CONTACT_FIELD_NAME;
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (g_srv_phb_sim_cntx[sim_id].sne_occur)
    {
        if (g_srv_phb_usim_cache[sim_id].sne[index].name[0])
        {
            *field_mask |= MMI_PHB_CONTACT_FIELD_NICK;
        }
        else
        {
            *field_mask &= ~MMI_PHB_CONTACT_FIELD_NICK;
        }
    }

    g_srv_phb_sim_cache[sim_id][index].email_count = 0;
    for (i = 0; i < g_srv_phb_sim_cntx[sim_id].email_occur; i++)
    {
        if (g_srv_phb_usim_cache[sim_id].email[i][index].email[0])
        {
            g_srv_phb_sim_cache[sim_id][index].email_count++;
        }
    }
    if (g_srv_phb_sim_cache[sim_id][index].email_count)
    {
        *field_mask |= MMI_PHB_CONTACT_FIELD_EMAIL;
    }
    else
    {
        *field_mask &= ~MMI_PHB_CONTACT_FIELD_EMAIL;
    }

    g_srv_phb_sim_cache[sim_id][index].number_count = 0;
    if (adn_cache->number[0])
    {
        g_srv_phb_sim_cache[sim_id][index].number_count++;
    }
    for (i = 0; i < g_srv_phb_sim_cntx[sim_id].anr_occur; i++)
    {
        if (g_srv_phb_usim_cache[sim_id].anr[i][index].number[0])
        {
            g_srv_phb_sim_cache[sim_id][index].number_count++;
        }
    }
    if (g_srv_phb_sim_cache[sim_id][index].number_count)
    {
        *field_mask |= MMI_PHB_CONTACT_FIELD_NUMBER;
    }
    else
    {
        *field_mask &= ~MMI_PHB_CONTACT_FIELD_NUMBER;
    }
    if (g_srv_phb_usim_cache[sim_id].grp[index].grp)
    {
        *field_mask |= MMI_PHB_CONTACT_FIELD_GROUP;
    }
#else
    if (adn_cache->number[0])
    {
        *field_mask |= MMI_PHB_CONTACT_FIELD_NUMBER;
    }
    else
    {
        *field_mask &= ~MMI_PHB_CONTACT_FIELD_NUMBER;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_sim_set_field_mask(U8 sim_id, U16 index, U32 filed_flag, MMI_BOOL exist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (exist)
    {
        g_srv_phb_sim_cache[sim_id][index].field_mask |= filed_flag;
    }
    else
    {
        g_srv_phb_sim_cache[sim_id][index].field_mask &= ~filed_flag;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_sim_get_field_mask(U8 sim_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < g_srv_phb_sim_cntx[sim_id].total_count)
    {
        return g_srv_phb_sim_cache[sim_id][index].field_mask;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_clear_all_fields
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_sim_clear_all_fields(U8 sim_id, U16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_SUPPORT__
    U32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_cache[sim_id][record_index].adn.name[0] = 0;
    g_srv_phb_sim_cache[sim_id][record_index].adn.number[0] = 0;
    g_srv_phb_sim_cache[sim_id][record_index].field_mask = 0;
    
#ifdef __MMI_PHB_USIM_SUPPORT__
    for (i = 0; i < g_srv_phb_sim_cntx[sim_id].anr_occur; i++)
    {
        g_srv_phb_usim_cache[sim_id].anr[i][record_index].number[0] = 0;
    }
    for (i = 0; i < g_srv_phb_sim_cntx[sim_id].email_occur; i++)
    {
        g_srv_phb_usim_cache[sim_id].email[i][record_index].email[0] = 0;
    }
    g_srv_phb_sim_cache[sim_id][record_index].number_count = 0;
    g_srv_phb_sim_cache[sim_id][record_index].email_count = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static WCHAR* srv_phb_sim_get_name(U8 sim_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < g_srv_phb_sim_cntx[sim_id].total_count)
    {
        return (WCHAR*)(g_srv_phb_sim_cache[sim_id][index].adn.name);
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static CHAR* srv_phb_sim_get_number(U8 sim_id, U16 index, U8 save_index, U8* type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= g_srv_phb_sim_cntx[sim_id].total_count)
    {
        return NULL;
    }
    if (save_index)
    {
    #ifdef __MMI_PHB_USIM_SUPPORT__
        if (save_index <= g_srv_phb_sim_cntx[sim_id].anr_occur)
        {
            if (type)
            {
                *type = g_srv_phb_usim_cache[sim_id].anr[save_index - 1][index].type;
            }
            return (CHAR*)(g_srv_phb_usim_cache[sim_id].anr[save_index - 1][index].number);
        }
    #endif
        return NULL;
    }
    if (type)
    {
        *type = MMI_PHB_NUM_TYPE_MOBILE;
    }
    return (CHAR*)(g_srv_phb_sim_cache[sim_id][index].adn.number);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_parse_sim_bcd_entry
 * DESCRIPTION
 *  This function set the read indication data from L4 Phb at bootup time.
 *  Stores each indication to the global phonebook list.
 * PARAMETERS
 *  phb_entry       [IN]        
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_parse_sim_bcd_entry(l4c_phb_bcd_entry_struct* phb_entry, srv_phb_sim_adn_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 encode_num[MMI_PHB_NUMBER_PLUS_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_entry->alpha_id.name_length == 0 || (phb_entry->alpha_id.name[0] == 0xff && phb_entry->alpha_id.name[1] == 0xff))
    {
        entry->name[0] = 0;
    }
    else
    {
        InputboxConvertGSMToDeviceEncoding(
                    phb_entry->alpha_id.name,
                    (U8*)entry->name,
                    phb_entry->alpha_id.name_length,
                    (MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH,
                    phb_entry->alpha_id.name_dcs,
                    0,
                    1);
        if (phb_entry->alpha_id.name_length > MMI_PHB_NAME_FIELD_LENGTH)
        {
            if (phb_entry->alpha_id.name_dcs == SRV_PHB_CHARSET_UCS2)
            {
                entry->name[MMI_PHB_NAME_FIELD_LENGTH / 2] = 0;
            }
        #if defined(__PHB_0x81_SUPPORT__)
            else if (phb_entry->alpha_id.name_dcs == SRV_PHB_CHARSET_UCS2_81)
            {
                entry->name[MMI_PHB_NAME_FIELD_LENGTH - 3] = 0;
            }
        #endif /* __PHB_0x81_SUPPORT__ */
        }
    }

    /* Number Field */
    srv_phb_convert_to_digit(
        encode_num,
        (phb_entry->tel.addr_bcd + 1), 
        MMI_PHB_NUMBER_LENGTH + 1);
    applib_decode_number(encode_num, entry->number, phb_entry->tel.addr_bcd[0]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_startup_read_next
 * DESCRIPTION
 *  This function receives the read indication from L4 Phb at bootup time.
 *  and send confirm to L4 to read next entry.
 * PARAMETERS
 *  access_id       [IN]        
 *  mod_dest        [IN]        Indication from L4 PHB
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_startup_read_next(U8 access_id, int mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_startup_read_next_req_struct* local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_phb_startup_read_next_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_startup_read_next_req_struct));
    local_ptr->access_id = access_id;
    mmi_frm_send_ilm((oslModuleType)mod_dest, MSG_ID_MMI_PHB_STARTUP_READ_NEXT_REQ, (oslParaType*)local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_startup_read_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 *  mod_src     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_startup_read_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_startup_read_ind_struct *local_ptr;
    l4c_phb_bcd_entry_struct* phb_entry;
    srv_phb_sim_adn_struct* adn;
    mmi_phb_contact_id id;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_startup_read_ind_struct*) info;
    phb_entry = &local_ptr->phb_entries[0].phb_entry[0];

    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SIM_STARTUP_READ_IND,
                         phb_entry->record_index,
                         phb_entry->storage);

    /* Send read confirm messaeg back to L4 */
    srv_phb_sim_startup_read_next(local_ptr->access_id, mod_src);

    /* Parse and save data from indication */
    i = srv_phb_get_sim_id((phb_storage_enum)(phb_entry->storage));
    id = phb_entry->record_index + MMI_PHB_PHONE_ENTRIES + i * MMI_PHB_SIM_ENTRIES - 1;    /* Storage Location in array. */
    MMI_ASSERT(g_srv_phb_sim_cntx[i].used_count <= g_srv_phb_sim_cntx[i].total_count);
    adn = &(g_srv_phb_sim_cache[i][phb_entry->record_index - 1].adn);
    srv_phb_parse_sim_bcd_entry(phb_entry, adn);
    if (adn->name[0] || adn->number[0])
    {
    srv_phb_sim_update_field_mask(i, (U16)(phb_entry->record_index - 1));

#if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
    srv_phb_sse_make_pinyin_cache(id, adn->name);
#endif
    srv_phb_sse_populate_name_index(id);
        g_srv_phb_sim_cntx[i].used_count++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_build_l4_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_build_l4_name(l4_name_struct* l4_name, WCHAR* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name != NULL)
    {
        WCHAR data[MMI_PHB_NAME_LENGTH + 1];
        mmi_wcsncpy(data, name, MMI_PHB_NAME_LENGTH);
        srv_phb_remove_invalid_name(data);
        /* Prepare Name Data */
        if (srv_phb_check_ucs2_character(data))
        {
        #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
            U8 length;
            if ((length = srv_phb_convert_to_0x81(data, MMI_TRUE)) > 0)
            {
                l4_name->name_dcs = SRV_PHB_CHARSET_UCS2_81;
                l4_name->name_length = (length > MAX_PS_NAME_SIZE ? MAX_PS_NAME_SIZE : length);
                memcpy(l4_name->name, data, l4_name->name_length);
                l4_name->name[1] = l4_name->name_length - 3;
            }
            else
        #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            {
                l4_name->name_dcs = SRV_PHB_CHARSET_UCS2;
                l4_name->name_length = InputboxConvertDeviceEncodingToGSM(
                                                (PU8)data,
                                                l4_name->name,
                                                MAX_PS_NAME_SIZE,
                                                SRV_PHB_CHARSET_UCS2,
                                                0,
                                                1) - 2;
                l4_name->name[l4_name->name_length] = 0;
                l4_name->name[l4_name->name_length + 1] = 0;
            }
        }
        else
        {
            l4_name->name_dcs = SRV_PHB_CHARSET_ASCII;
            l4_name->name_length = InputboxConvertDeviceEncodingToGSM(
                                                (PU8)data,
                                                l4_name->name,
                                                MAX_PS_NAME_SIZE - 1,
                                                SRV_PHB_CHARSET_ASCII,
                                                0,
                                                1) - 1;
            l4_name->name[l4_name->name_length] = 0;
        }
    }
    else
    {
        l4_name->name_dcs = SRV_PHB_CHARSET_ASCII;
        l4_name->name_length = 0;
        l4_name->name[0] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_parse_l4_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_parse_l4_name(l4_name_struct* l4_name, WCHAR* name, U16 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (l4_name->name_length == 0 || (l4_name->name[0] == 0xff && l4_name->name[1] == 0xff))
    {
        name[0] = 0;
    }
    else
    {
        InputboxConvertGSMToDeviceEncoding(
                    l4_name->name,
                    (U8*)name,
                    l4_name->name_length,
                    (MMI_PHB_NAME_FIELD_LENGTH + 1) * ENCODING_LENGTH,
                    l4_name->name_dcs,
                    0,
                    1);
        if (l4_name->name_length > max_len)
        {
            if (l4_name->name_dcs == SRV_PHB_CHARSET_UCS2)
            {
                name[MMI_PHB_NAME_FIELD_LENGTH / 2] = 0;
            }
        #if defined(__PHB_0x81_SUPPORT__)
            else if (l4_name->name_dcs == SRV_PHB_CHARSET_UCS2_81)
            {
                name[MMI_PHB_NAME_FIELD_LENGTH - 3] = 0;
            }
        #endif /* __PHB_0x81_SUPPORT__ */
        }
    }
}

#ifdef __MMI_PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_sne
 * DESCRIPTION
 *  
 * PARAMETERS
 *             
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_set_sne(U8 sim_id, U16 index, WCHAR* sne)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* temp = g_srv_phb_usim_cache[sim_id].sne[index].name;
    U16* used = &(g_srv_phb_sim_cntx[sim_id].sne_used);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp[0])
    {
        (*used)--;
    }
    if (sne && sne[0])
    {
        mmi_wcscpy(temp, sne);
    }
    else
    {
        temp[0] = 0;
    }
    if (temp[0])
    {
        (*used)++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_nick_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_sim_get_nick_name(U8 sim_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index < g_srv_phb_sim_cntx[sim_id].total_count) && g_srv_phb_sim_cntx[sim_id].sne_occur)
    {
        return (WCHAR*)(g_srv_phb_usim_cache[sim_id].sne[index].name);
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_l4_sne
 * DESCRIPTION
 *  
 * PARAMETERS
 *             
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_set_l4_sne(U8 sim_id, U16 index, l4_name_struct* sne)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* temp = g_srv_phb_usim_cache[sim_id].sne[index].name;
    U16* used = &(g_srv_phb_sim_cntx[sim_id].sne_used);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_phb_usim_cache[sim_id].sne)
    {
        return;
    }
    if (temp[0])
    {
        (*used)--;
    }
    if (sne)
    {
        srv_phb_sim_parse_l4_name(sne, temp, MMI_PHB_NAME_FIELD_LENGTH);
    }
    else
    {
        temp[0] = 0;
    }
    if (temp[0])
    {
        (*used)++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *             
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_set_number(U8 sim_id, U8 occur, U16 index, WCHAR* src_num, U8 aas_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id = (mmi_phb_contact_id)(index + MMI_PHB_PHONE_ENTRIES + sim_id * MMI_PHB_SIM_ENTRIES);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (occur)
    {
        srv_phb_sim_anr_struct* anr = &(g_srv_phb_usim_cache[sim_id].anr[occur - 1][index]);
        U16* used = &(g_srv_phb_sim_cntx[sim_id].anr_used[occur - 1]);
        if (anr->number[0])
        {
            srv_phb_sse_lookup_table_remove_contact(id, (CHAR*)anr->number);
            (*used)--;
        }
        if (src_num)
        {
            mmi_wcs_n_to_asc(anr->number, src_num, MMI_PHB_NUMBER_PLUS_LENGTH * sizeof(U16));
            if (aas_id && aas_id <= g_srv_phb_sim_cntx[sim_id].aas_total)
            {
                anr->type = (U8)(aas_id + MMI_PHB_NUM_TYPE_USER_BASE - 1);
            }
            else
            {
                anr->type = MMI_PHB_NUM_TYPE_MOBILE;
            }
        }
        else
        {
            anr->number[0] = 0;
        }
        if (anr->number[0])
        {
            srv_phb_sse_lookup_table_add_contact(id, (CHAR*)anr->number);
            (*used)++;
        }
    }
    else
    {
        srv_phb_sim_adn_struct* adn = &(g_srv_phb_sim_cache[sim_id][index].adn);
        if (adn->number[0])
        {
            srv_phb_sse_lookup_table_remove_contact(id, (CHAR*)adn->number);
        }
        if (src_num)
        {
            mmi_wcs_n_to_asc(adn->number, src_num, MMI_PHB_NUMBER_PLUS_LENGTH * sizeof(U16));
        }
        else
        {
            adn->number[0] = 0;
        }
        if (adn->number[0])
        {
            srv_phb_sse_lookup_table_add_contact(id, (CHAR*)adn->number);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_l4_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *             
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_set_l4_number(U8 sim_id, U8 occur, U16 index, CHAR* src_num, U8 ton, U8 aas_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id = (mmi_phb_contact_id)(index + MMI_PHB_PHONE_ENTRIES + sim_id * MMI_PHB_SIM_ENTRIES);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (occur)
    {
        srv_phb_sim_anr_struct* anr = &(g_srv_phb_usim_cache[sim_id].anr[occur - 1][index]);
        U16* used = &(g_srv_phb_sim_cntx[sim_id].anr_used[occur - 1]);
        if (anr->number[0])
        {
            srv_phb_sse_lookup_table_remove_contact(id, (CHAR*)anr->number);
            (*used)--;
        }
        if (src_num)
        {
            applib_decode_number(
                src_num,
                anr->number,
                ton);
            if (aas_id && aas_id <= g_srv_phb_sim_cntx[sim_id].aas_total)
            {
                anr->type = (U8)(aas_id + MMI_PHB_NUM_TYPE_USER_BASE - 1);
            }
            else
            {
                anr->type = MMI_PHB_NUM_TYPE_MOBILE;
            }
        }
        else
        {
            anr->number[0] = 0;
        }
        if (anr->number[0])
        {
            srv_phb_sse_lookup_table_add_contact(id, (CHAR*)anr->number);
            (*used)++;
        }
    }
    else
    {
        srv_phb_sim_adn_struct* adn = &(g_srv_phb_sim_cache[sim_id][index].adn);
        if (adn->number[0])
        {
            srv_phb_sse_lookup_table_remove_contact(id, (CHAR*)adn->number);
        }
        if (src_num)
        {
            applib_decode_number(
                src_num,
                adn->number,
                ton);
        }
        else
        {
            adn->number[0] = 0;
        }
        if (adn->number[0])
        {
            srv_phb_sse_lookup_table_add_contact(id, (CHAR*)adn->number);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *             
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_set_email(U8 sim_id, U8 occur, U16 index, WCHAR* email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* temp = g_srv_phb_usim_cache[sim_id].email[occur - 1][index].email;
    U16* used = &(g_srv_phb_sim_cntx[sim_id].email_used[occur - 1]);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp[0])
    {
        (*used)--;
    }
    if (email && email[0])
    {
        mmi_wcs_to_asc(temp, email);
    }
    else
    {
        temp[0] = 0;
    }
    if (temp[0])
    {
        (*used)++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_sim_get_email(U8 sim_id, U16 index, U8 save_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index < g_srv_phb_sim_cntx[sim_id].total_count) && save_index < g_srv_phb_sim_cntx[sim_id].email_occur)
    {
        return (CHAR*)(g_srv_phb_usim_cache[sim_id].email[save_index][index].email);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_update_email_field_mask
 * DESCRIPTION
 *  update name and number fileter flag of a entry.
 * PARAMETERS
 *  store_index              [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sim_update_email_field_mask(U8 sim_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32* field_mask = &(g_srv_phb_sim_cache[sim_id][index].field_mask);
    U8* count = &(g_srv_phb_sim_cache[sim_id][index].email_count);
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *count = 0;
    for (i = 0; i < g_srv_phb_sim_cntx[sim_id].email_occur; i++)
    {
        if (g_srv_phb_usim_cache[sim_id].email[i][index].email[0])
        {
            (*count)++;
        }
    }
    if (*count)
    {
        *field_mask |= MMI_PHB_CONTACT_FIELD_EMAIL;
    }
    else
    {
        *field_mask &= ~MMI_PHB_CONTACT_FIELD_EMAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_next_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_phb_get_next_sim_contact(U8 sim_id, U16 start, U8 field_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 end = g_srv_phb_sim_cntx[sim_id].total_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (start < end)
    {
        if (g_srv_phb_sim_cache[sim_id][start].field_mask & field_mask)
        {
            return start;
        }
        start++;
    }
    return SRV_PHB_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_usim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_usim_info(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (phb_usim_init_info_table[g_srv_phb_usim_init_cntx[sim_id].init_index].init_func)
    {
        phb_usim_init_info_table[g_srv_phb_usim_init_cntx[sim_id].init_index++].init_func(sim_id, storage);
        return;
    }
    g_srv_phb_usim_init_cntx[sim_id].init_index = 0;
    g_srv_phb_usim_init_cntx[sim_id].return_func = srv_phb_init_usim;
    srv_phb_init_usim(sim_id, storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_info_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_get_sim_info_req(U8 type, U8 occurrence, int mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_type_info_req_struct *my_msg_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_get_type_info_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_get_type_info_req_struct));

    my_msg_ptr->type = type;
    my_msg_ptr->occurrence = occurrence;
    mmi_frm_send_ilm((oslModuleType)mod_dest, MSG_ID_MMI_PHB_GET_TYPE_INFO_REQ, (oslParaType*)my_msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_contact_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_get_sim_info_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_type_info_rsp_struct *local_ptr = (mmi_phb_get_type_info_rsp_struct*)info;
    U8 sim_id = srv_phb_get_sim_id_by_mod_id(mod_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (local_ptr->result)
    {
        switch (local_ptr->type)
        {
            case PHB_ANR:              
                g_srv_phb_sim_cntx[sim_id].anr_total[g_srv_phb_usim_init_cntx[sim_id].cur_occur - 1] =
                    local_ptr->num_of_tot_rec;
                g_srv_phb_sim_cntx[sim_id].anr_used[g_srv_phb_usim_init_cntx[sim_id].cur_occur - 1] = 0;
                break;
                
            case PHB_EMAIL:
                g_srv_phb_sim_cntx[sim_id].email_total[g_srv_phb_usim_init_cntx[sim_id].cur_occur - 1] =
                    local_ptr->num_of_tot_rec;
                g_srv_phb_sim_cntx[sim_id].email_used[g_srv_phb_usim_init_cntx[sim_id].cur_occur - 1] = 0;
                break;
                
            case PHB_SNE:
                g_srv_phb_sim_cntx[sim_id].sne_total = local_ptr->num_of_tot_rec;
                g_srv_phb_sim_cntx[sim_id].sne_used = 0;
                break;

            default:
                MMI_ASSERT(0);
        }
    }
    g_srv_phb_usim_init_cntx[sim_id].continue_func(sim_id, srv_phb_get_storage_by_sim_id(sim_id), mod_src);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_anr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_get_next_anr_info(U8 sim_id, phb_storage_enum storage, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_srv_phb_usim_init_cntx[sim_id].cur_occur < g_srv_phb_sim_cntx[sim_id].anr_occur)
    {
        srv_phb_get_sim_info_req(
            PHB_ANR,
            (U8)(g_srv_phb_usim_init_cntx[sim_id].cur_occur + 1),
            mod_id);
        g_srv_phb_usim_init_cntx[sim_id].cur_occur++;
        return;
    }
    g_srv_phb_usim_init_cntx[sim_id].return_func(sim_id, storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_anr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_anr_info(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].cur_occur = 0;
    g_srv_phb_usim_init_cntx[sim_id].continue_func = srv_phb_get_next_anr_info;
    SetProtocolEventHandler(srv_phb_get_sim_info_rsp, MSG_ID_MMI_PHB_GET_TYPE_INFO_RSP);
    srv_phb_get_next_anr_info(sim_id, storage, srv_phb_get_l4c_mod_by_sim_id(sim_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_anr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_get_next_email_info(U8 sim_id, phb_storage_enum storage, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_srv_phb_usim_init_cntx[sim_id].cur_occur < g_srv_phb_sim_cntx[sim_id].email_occur)
    {
        srv_phb_get_sim_info_req(
            PHB_EMAIL,
            (U8)(g_srv_phb_usim_init_cntx[sim_id].cur_occur + 1),
            mod_id);
        g_srv_phb_usim_init_cntx[sim_id].cur_occur++;
        return;
    }
    g_srv_phb_usim_init_cntx[sim_id].return_func(sim_id, storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_anr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_email_info(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].cur_occur = 0;
    g_srv_phb_usim_init_cntx[sim_id].continue_func = srv_phb_get_next_email_info;
    SetProtocolEventHandler(srv_phb_get_sim_info_rsp, MSG_ID_MMI_PHB_GET_TYPE_INFO_RSP);
    srv_phb_get_next_email_info(sim_id, storage, srv_phb_get_l4c_mod_by_sim_id(sim_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_anr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_sne_info(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_phb_get_sim_info_rsp, MSG_ID_MMI_PHB_GET_TYPE_INFO_RSP);
    g_srv_phb_usim_init_cntx[sim_id].continue_func = g_srv_phb_usim_init_cntx[sim_id].return_func;
    srv_phb_get_sim_info_req(
        PHB_SNE,
        1,
        srv_phb_get_l4c_mod_by_sim_id(sim_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_usim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_usim(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (phb_usim_init_table[g_srv_phb_usim_init_cntx[sim_id].init_index].init_func)
    {
        phb_usim_init_table[g_srv_phb_usim_init_cntx[sim_id].init_index++].init_func(sim_id, storage);
        return;
    }
    srv_phb_datamgr_set_startup_ready(storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_anr_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_anr_req(U16 record_index, U8 num_index, phb_storage_enum storage, int mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_entry_by_index_req_struct *my_msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_get_entry_by_index_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_get_entry_by_index_req_struct));

    my_msg_ptr->no_data = 1;
    // TODO : use l4 enum
    my_msg_ptr->type = PHB_ANR;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    my_msg_ptr->storage = storage;
    my_msg_ptr->index = SRV_PHB_INVALID_INDEX;
    my_msg_ptr->record_index = record_index;
    my_msg_ptr->num_index = num_index;
    mmi_frm_send_ilm((oslModuleType) mod_dest, MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_REQ, (oslParaType*)my_msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_anr_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_read_anr_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_get_entry_by_index_rsp_struct *local_ptr = (mmi_phb_get_entry_by_index_rsp_struct*) info;
    U8 sim_id = srv_phb_get_sim_id_by_mod_id(mod_src);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].continue_func(sim_id, srv_phb_get_storage_by_sim_id(sim_id), mod_src);
    if (local_ptr && local_ptr->result.flag == L4C_OK)
    {
        l4c_phb_entry_struct*phb_entry = &local_ptr->list[0];
        if (phb_entry->tel.number[0])
        {
            srv_phb_sim_set_l4_number(
                sim_id,
                phb_entry->num_index,
                (U16)(phb_entry->record_index - 1),
                phb_entry->tel.number,
                phb_entry->tel.type,
                phb_entry->aas_id);
            srv_phb_sim_set_field_mask(
                sim_id,
                (U16)(phb_entry->record_index - 1),
                MMI_PHB_CONTACT_FIELD_NUMBER,
                MMI_TRUE);
            g_srv_phb_sim_cache[sim_id][phb_entry->record_index - 1].number_count++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_next_anr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_next_anr(U8 sim_id, phb_storage_enum storage, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_srv_phb_usim_init_cntx[sim_id].cur_occur < g_srv_phb_sim_cntx[sim_id].anr_occur)
    {
        g_srv_phb_usim_init_cntx[sim_id].cur_index =
            srv_phb_get_next_sim_contact(
                    sim_id,
                    g_srv_phb_usim_init_cntx[sim_id].cur_index,
                    MMI_PHB_CONTACT_FIELD_EXIST);
        
        if (g_srv_phb_usim_init_cntx[sim_id].cur_index++ < g_srv_phb_sim_cntx[sim_id].total_count)
        {
            srv_phb_read_anr_req(
                g_srv_phb_usim_init_cntx[sim_id].cur_index,
                (U8)(g_srv_phb_usim_init_cntx[sim_id].cur_occur + 1),
                storage,
                mod_id);
            return;
        }
        g_srv_phb_usim_init_cntx[sim_id].cur_occur++;
        g_srv_phb_usim_init_cntx[sim_id].cur_index = 0;
    }
    g_srv_phb_usim_init_cntx[sim_id].return_func(sim_id, storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_anr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_anr(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].cur_occur = 0;
    g_srv_phb_usim_init_cntx[sim_id].cur_index = 0;
    g_srv_phb_usim_init_cntx[sim_id].continue_func = srv_phb_read_next_anr;
    srv_phb_startup_set_initing_entry_type(sim_id, PHB_ANR);
    SetProtocolEventHandler(srv_phb_startup_read_entry_by_index_rsp, MSG_ID_MMI_PHB_GET_ENTRY_BY_INDEX_RSP);
    srv_phb_read_next_anr(sim_id, storage, srv_phb_get_l4c_mod_by_sim_id(sim_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_email_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_usim_field_req(phb_type_enum type, U16 record_index, U8 occurrence, phb_storage_enum storage, int mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_read_usim_req_struct *my_msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_read_usim_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_read_usim_req_struct));

    my_msg_ptr->occurrence = occurrence;
    // TODO : use l4 enum
    my_msg_ptr->type = type;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    my_msg_ptr->record_index = record_index;
    mmi_frm_send_ilm((oslModuleType) mod_dest, MSG_ID_MMI_PHB_READ_USIM_REQ, (oslParaType*) my_msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_email_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_usim_field_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_read_usim_rsp_struct *local_ptr = (mmi_phb_read_usim_rsp_struct*) info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (local_ptr->type)
    {
        case PHB_EMAIL:
            srv_phb_read_email_rsp(info, mod_src);
            break;
            
        case PHB_SNE:
            srv_phb_read_sne_rsp(info, mod_src);
            break;

        case PHB_AAS:
            srv_phb_read_aas_rsp(info, mod_src);
            break;

        case PHB_GAS:
            srv_phb_read_gas_rsp(info, mod_src);
            break;

        case PHB_GRP:
            srv_phb_read_grp_rsp(info, mod_src);
            break;

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_email_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_email_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_read_usim_rsp_struct *local_ptr = (mmi_phb_read_usim_rsp_struct*) info;
    U8 sim_id = srv_phb_get_sim_id_by_mod_id(mod_src);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].continue_func(sim_id, srv_phb_get_storage_by_sim_id(sim_id), mod_src);
    if (local_ptr->result.flag == L4C_OK)
    {
        if (local_ptr->entry.field.email.email_address[0])
        {
            WCHAR dest_email[MMI_PHB_EMAIL_LENGTH + 1];
            InputboxConvertGSMToDeviceEncoding(
                local_ptr->entry.field.email.email_address,
                (U8*)dest_email,
                local_ptr->entry.field.email.email_length,
                (MMI_PHB_EMAIL_LENGTH + 1) * ENCODING_LENGTH,
                SRV_PHB_CHARSET_ASCII,
                0,
                1);
            srv_phb_sim_set_email(
                sim_id,
                local_ptr->occurrence,
                (U16)(local_ptr->record_index - 1),
                dest_email);
            srv_phb_sim_set_field_mask(
                sim_id,
                (U16)(local_ptr->record_index - 1),
                MMI_PHB_CONTACT_FIELD_EMAIL,
                MMI_TRUE);
            g_srv_phb_sim_cache[sim_id][local_ptr->record_index - 1].email_count++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_next_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_next_email(U8 sim_id, phb_storage_enum storage, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_srv_phb_usim_init_cntx[sim_id].cur_occur < g_srv_phb_sim_cntx[sim_id].email_occur)
    {
        g_srv_phb_usim_init_cntx[sim_id].cur_index =
            srv_phb_get_next_sim_contact(
                    sim_id,
                    g_srv_phb_usim_init_cntx[sim_id].cur_index,
                    MMI_PHB_CONTACT_FIELD_EXIST);
        
        if (g_srv_phb_usim_init_cntx[sim_id].cur_index++ < g_srv_phb_sim_cntx[sim_id].total_count)
        {
            srv_phb_read_usim_field_req(
                PHB_EMAIL,
                g_srv_phb_usim_init_cntx[sim_id].cur_index,
                (U8)(g_srv_phb_usim_init_cntx[sim_id].cur_occur + 1),
                storage,
                mod_id);
            return;
        }
        g_srv_phb_usim_init_cntx[sim_id].cur_occur++;
        g_srv_phb_usim_init_cntx[sim_id].cur_index = 0;
    }
    g_srv_phb_usim_init_cntx[sim_id].return_func(sim_id, storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_email(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].cur_occur = 0;
    g_srv_phb_usim_init_cntx[sim_id].cur_index = 0;
    g_srv_phb_usim_init_cntx[sim_id].continue_func = srv_phb_read_next_email;
    SetProtocolEventHandler(srv_phb_read_usim_field_rsp, MSG_ID_MMI_PHB_READ_USIM_RSP);
    srv_phb_read_next_email(sim_id, storage, srv_phb_get_l4c_mod_by_sim_id(sim_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_sne_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_sne_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_read_usim_rsp_struct *local_ptr = (mmi_phb_read_usim_rsp_struct*) info;
    U8 sim_id = srv_phb_get_sim_id_by_mod_id(mod_src);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].continue_func(sim_id, srv_phb_get_storage_by_sim_id(sim_id), mod_src);
    if (local_ptr->result.flag == L4C_OK)
    {
        srv_phb_sim_set_l4_sne(sim_id, (U16)(local_ptr->record_index - 1), &(local_ptr->entry.field.sne));
        srv_phb_sim_set_field_mask(
            sim_id,
            (U16)(local_ptr->record_index - 1),
            MMI_PHB_CONTACT_FIELD_NICK,
            MMI_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_next_sne
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_next_sne(U8 sim_id, phb_storage_enum storage, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_usim_init_cntx[sim_id].cur_occur < g_srv_phb_sim_cntx[sim_id].sne_occur)
    {
        g_srv_phb_usim_init_cntx[sim_id].cur_index =
            srv_phb_get_next_sim_contact(
                    sim_id,
                    g_srv_phb_usim_init_cntx[sim_id].cur_index,
                    MMI_PHB_CONTACT_FIELD_EXIST);
        
        if (g_srv_phb_usim_init_cntx[sim_id].cur_index++ < g_srv_phb_sim_cntx[sim_id].total_count)
        {
            srv_phb_read_usim_field_req(
                PHB_SNE,
                g_srv_phb_usim_init_cntx[sim_id].cur_index,
                (U8)(g_srv_phb_usim_init_cntx[sim_id].cur_occur + 1),
                storage,
                mod_id);
            return;
        }
    }
    g_srv_phb_usim_init_cntx[sim_id].return_func(sim_id, storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_sne
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_sne(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].cur_occur = 0;
    g_srv_phb_usim_init_cntx[sim_id].cur_index = 0;
    g_srv_phb_usim_init_cntx[sim_id].continue_func = srv_phb_read_next_sne;
    SetProtocolEventHandler(srv_phb_read_usim_field_rsp, MSG_ID_MMI_PHB_READ_USIM_RSP);
    srv_phb_read_next_sne(sim_id, storage, srv_phb_get_l4c_mod_by_sim_id(sim_id));
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_aas_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_aas_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_read_usim_rsp_struct *local_ptr = (mmi_phb_read_usim_rsp_struct*) info;
    U8 sim_id = srv_phb_get_sim_id_by_mod_id(mod_src);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].continue_func(sim_id, srv_phb_get_storage_by_sim_id(sim_id), mod_src);
    if (local_ptr->result.flag == L4C_OK && g_srv_phb_usim_cache[sim_id].aas)
    {
        srv_phb_sim_parse_l4_name(
            &(local_ptr->entry.field.aas),
            g_srv_phb_usim_cache[sim_id].aas[local_ptr->record_index - 1].label,
            MMI_PHB_FIELD_LABEL_LENGTH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_next_aas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_next_aas(U8 sim_id, phb_storage_enum storage, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_srv_phb_usim_init_cntx[sim_id].cur_index++ < g_srv_phb_sim_cntx[sim_id].aas_total)
    {
        srv_phb_read_usim_field_req(
            PHB_AAS,
            g_srv_phb_usim_init_cntx[sim_id].cur_index,
            (U8)(1),
            storage,
            mod_id);
        return;
    }
    g_srv_phb_usim_init_cntx[sim_id].return_func(sim_id, storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_init_aas(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].cur_index = 0;
    g_srv_phb_usim_init_cntx[sim_id].continue_func = srv_phb_read_next_aas;
    SetProtocolEventHandler(srv_phb_read_usim_field_rsp, MSG_ID_MMI_PHB_READ_USIM_RSP);
    srv_phb_read_next_aas(sim_id, storage, srv_phb_get_l4c_mod_by_sim_id(sim_id));
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_gas_rsp
 * DESCRIPTION
 *  request message to L4 for read gas
 * PARAMETERS
 *  info         :      [IN]        message info 
 *  mod_src   :      [IN]        module id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_read_gas_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_read_usim_rsp_struct *local_ptr = (mmi_phb_read_usim_rsp_struct*) info;
    U8 sim_id = srv_phb_get_sim_id_by_mod_id(mod_src);
    #ifdef __MMI_PHB_CALLER_GROUP__
    U8 group_id = local_ptr->record_index - 1 + MMI_PHB_GROUP_COUNT + sim_id * PHB_MAX_ASSOCIATE_GRP;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].continue_func(sim_id, srv_phb_get_storage_by_sim_id(sim_id), mod_src);
    if (local_ptr->result.flag == L4C_OK && g_srv_phb_usim_cache[sim_id].gas && local_ptr->entry.field.gas.name_length)
    {
        srv_phb_sim_parse_l4_name(
            &(local_ptr->entry.field.gas),
            g_srv_phb_usim_cache[sim_id].gas[local_ptr->record_index - 1].group_name,
            MMI_PHB_FIELD_LABEL_LENGTH);
        #ifdef __MMI_PHB_CALLER_GROUP__
        srv_phb_group_delete_group_index(group_id);
        srv_phb_group_insert_group_index(
            group_id,
            g_srv_phb_usim_cache[sim_id].gas[local_ptr->record_index - 1].group_name);
        #endif
        g_srv_phb_sim_cntx[sim_id].gas_used ++;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_next_aas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_read_next_gas(U8 sim_id, phb_storage_enum storage, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_srv_phb_usim_init_cntx[sim_id].cur_index++ < g_srv_phb_sim_cntx[sim_id].gas_total)
    {
        srv_phb_read_usim_field_req(
            PHB_GAS,
            g_srv_phb_usim_init_cntx[sim_id].cur_index,
            (U8)(1),
            storage,
            mod_id);
        return;
    }
    g_srv_phb_usim_init_cntx[sim_id].return_func(sim_id, storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_gas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_init_gas(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].cur_index = 0;
    g_srv_phb_usim_init_cntx[sim_id].continue_func = srv_phb_read_next_gas;
    SetProtocolEventHandler(srv_phb_read_usim_field_rsp, MSG_ID_MMI_PHB_READ_USIM_RSP);
    srv_phb_read_next_gas(sim_id, storage, srv_phb_get_l4c_mod_by_sim_id(sim_id));
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_gas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sim_set_gas(phb_storage_enum storage, U16 record_id, WCHAR* gas_alpha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_init_sim_op_cntx(storage);    
    if (gas_alpha != NULL)
    {
        srv_phb_set_usim_field_req(PHB_GAS, record_id, 0, gas_alpha);
    }
    else
    {
        srv_phb_delete_usim_field_req(PHB_GAS, record_id, 0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_l4_gas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sim_set_l4_gas(U8 sim_id, U16 index, l4_name_struct* gas)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* group_name = g_srv_phb_usim_cache[sim_id].gas[index].group_name;
    U8* used = &(g_srv_phb_sim_cntx[sim_id].gas_used);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!group_name)
    {
        return;
    }
    if (group_name && group_name[0])
    {
        (*used)--;
    }
    if (gas)
    {
        srv_phb_sim_parse_l4_name(gas, group_name, MMI_PHB_NAME_FIELD_LENGTH);
    }
    else
    {
        group_name[0] = 0;
    }
    if (group_name[0])
    {
        (*used)++;
    } 
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_gas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16* srv_phb_sim_get_gas(U8 sim_id, U16 store_index, U16 *group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_wcsncpy(
               group_name,
               g_srv_phb_usim_cache[sim_id].gas[store_index].group_name,
               MMI_PHB_GROUP_NAME_LENGTH);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_next_aas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_read_next_grp(U8 sim_id, phb_storage_enum storage, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_srv_phb_usim_init_cntx[sim_id].cur_index++ < g_srv_phb_sim_cntx[sim_id].total_count)
    {
        srv_phb_read_usim_field_req(
            PHB_GRP,
            g_srv_phb_usim_init_cntx[sim_id].cur_index,
            (U8)(1),
            storage,
            mod_id);
        return;
    }
    g_srv_phb_usim_init_cntx[sim_id].return_func(sim_id, storage);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_next_aas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_init_grp(U8 sim_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].cur_index = 0;
    g_srv_phb_usim_init_cntx[sim_id].continue_func = srv_phb_read_next_grp;
    SetProtocolEventHandler(srv_phb_read_usim_field_rsp, MSG_ID_MMI_PHB_READ_USIM_RSP);
    srv_phb_read_next_grp(sim_id, storage, srv_phb_get_l4c_mod_by_sim_id(sim_id));
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_grp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_sim_set_grp(U8 sim_id, U16 index, phb_grp_struct *group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* grp = &g_srv_phb_usim_cache[sim_id].grp[index].grp;
    U32 i;
    U8 gas_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!grp)
    {
        return;
    }
    *grp = 0;
    if (group)
    {
        for (i = 0; i < PHB_MAX_ASSOCIATE_GRP; i ++)
        {
            gas_id = group->gas_id[i];
            if (gas_id != 0 && gas_id != 0xFF)
            {
                *grp |= 1 << (gas_id - 1);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_grp_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_read_grp_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_read_usim_rsp_struct *local_ptr = (mmi_phb_read_usim_rsp_struct*) info;
    U16 store_index = local_ptr->record_index - 1;
    U8 sim_id = srv_phb_get_sim_id_by_mod_id(mod_src);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_usim_init_cntx[sim_id].continue_func(sim_id, srv_phb_get_storage_by_sim_id(sim_id), mod_src);
    if (local_ptr->result.flag == L4C_OK)
    {
        srv_phb_sim_set_grp(sim_id, store_index, &(local_ptr->entry.field.grp));
        srv_phb_sim_set_field_mask(
            sim_id,
            store_index,
            MMI_PHB_CONTACT_FIELD_GROUP,
            MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_grp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_sim_get_grp(U8 sim_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < g_srv_phb_sim_cntx[sim_id].total_count)
    {
        return g_srv_phb_usim_cache[sim_id].grp[index].grp;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_grp_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sim_get_grp_cache(U8 sim_id, U16* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer && g_srv_phb_usim_cache[sim_id].grp)
    {
        memcpy(buffer, g_srv_phb_usim_cache[sim_id].grp, g_srv_phb_sim_cntx[sim_id].total_count* sizeof(srv_phb_sim_grp_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_sim_op_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_init_sim_op_cntx(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_op_cntx.status = 0;
    g_srv_phb_sim_op_cntx.cur_occur = 0;
    g_srv_phb_sim_op_cntx.sim_id = srv_phb_get_sim_id(storage);
    g_srv_phb_sim_op_cntx.cur_index = 0;
    g_srv_phb_sim_op_cntx.finish_count = 0;
    g_srv_phb_sim_op_cntx.mod = srv_phb_get_l4c_mod_by_storage(storage);
    g_srv_phb_sim_op_cntx.iterator = 0;
    g_srv_phb_sim_op_cntx.result = SRV_PHB_NO_ERROR;
    g_srv_phb_sim_op_cntx.dest_id = MMI_PHB_INVALID_CONTACT_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_build_sim_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_build_sim_entry(void *req_msg, WCHAR* name, WCHAR* num, U8 aas_id, phb_storage_enum storage, U16 index, U8 occur)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4c_phb_entry_struct *phb_entry = (l4c_phb_entry_struct*)req_msg;
    U8 ton;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num != NULL)
    {
        U16 encode_num[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
        srv_phb_remove_invalid_number(num);
        /* now number is **21*+8123456# */
        /* call the second API to transfer + to the first place */
        ton = applib_encode_number_unicode(num, encode_num);
        /* now number is +**21*8123456#, so we know it is an international number */
        /* Prepate Number Data */
        if (ton == 0x91)
        {
            phb_entry->tel.type = SRV_PHB_NUMBER_TYPE_INTERNATIONAL; /* INTERNATIONAL */
        }
        else
        {
            phb_entry->tel.type = SRV_PHB_NUMBER_TYPE_DEFAULT;  /* DEFAULT */
        }
        phb_entry->tel.length = (U8)mmi_wcslen(encode_num);
        mmi_wcs_to_asc((CHAR*)phb_entry->tel.number, encode_num);
    }
    else if (index != MMI_PHB_INVALID_CONTACT_ID)
    {
        CHAR* number = srv_phb_sim_get_number(
                            srv_phb_get_sim_id(storage),
                            (U16)(index - 1),
                            occur,
                            NULL);
        
        if (number[0])
        {
            ton = applib_encode_number(
                    (kal_uint8*)number, 
                    phb_entry->tel.number, 
                    (U8)(number[0]=='+' ? 0x91 : 0x81));
            phb_entry->tel.length = (U8)strlen((CHAR*)phb_entry->tel.number);
            if (ton == 0x91)
            {
                phb_entry->tel.type = SRV_PHB_NUMBER_TYPE_INTERNATIONAL; /* INTERNATIONAL */
            }
            else
            {
                phb_entry->tel.type = SRV_PHB_NUMBER_TYPE_DEFAULT;  /* DEFAULT */
            }
        }
    }
    if (!occur && name)
    {
        srv_phb_sim_build_l4_name(&phb_entry->alpha_id, name);
    }
    else
    {
        phb_entry->aas_id = aas_id;
    }
    if (phb_entry->tel.length || phb_entry->alpha_id.name_length)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_sim_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_write_sim_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id;
    srv_phb_datamgr_op_status_struct status;
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    U8 sim_id = g_srv_phb_sim_op_cntx.sim_id;
    U16 index = (U16)(cntx->pos.index - 1);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = (mmi_phb_contact_id)(cntx->pos.index - 1 + MMI_PHB_PHONE_ENTRIES + sim_id * MMI_PHB_SIM_ENTRIES);
    if ((g_srv_phb_sim_op_cntx.result == SRV_PHB_NO_ERROR) ||
        (g_srv_phb_sim_op_cntx.result == SRV_PHB_NAME_MODIFIED) ||
        (g_srv_phb_sim_op_cntx.result == SRV_PHB_SIM_PARTIAL_ERROR))
    {
        if (cntx->pos.index != SRV_PHB_INVALID_INDEX)
        {
        srv_phb_sim_update_field_mask(sim_id, index);
        }
    }

    status.result = g_srv_phb_sim_op_cntx.result;
    status.id = id;
    srv_phb_datamgr_op_done(&status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_sim_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_write_sim_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        switch (g_srv_phb_sim_op_cntx.status)
        {
            case SRV_PHB_SIM_OP_EMAIL:
                if (cntx->update_field & MMI_PHB_CONTACT_FIELD_EMAIL)
                {
                    srv_phb_email_struct* email = NULL;
                    if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].email_occur)
                    {
                        g_srv_phb_sim_op_cntx.cur_occur++;
                        if (g_srv_phb_sim_op_cntx.iterator)
                        {
                            email = srv_phb_contact_get_email_next(&(g_srv_phb_sim_op_cntx.iterator));
                            if (cntx->mode == SRV_PHB_UPDATE_MODE_IMPORT)
                            {
                                if (email->index <= g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].email_occur)
                                {
                                    g_srv_phb_sim_op_cntx.op_occur = (U8)(email->index + 1);
                                }
                                else
                                {
                                    /* print error trace */
                                    g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
                                    break;
                                }
                            }
                        }
                        else if (cntx->mode == SRV_PHB_UPDATE_MODE_IMPORT)
                        {
                            g_srv_phb_sim_op_cntx.cur_occur = 0;
                            g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_SNE;
                            break;
                        }
                        if (cntx->mode == SRV_PHB_UPDATE_MODE_REPLACE)
                        {
                            g_srv_phb_sim_op_cntx.op_occur = g_srv_phb_sim_op_cntx.cur_occur;
                        }

                        if (email && email->email[0])
                        {
                            srv_phb_set_usim_field_req(
                                        PHB_EMAIL,
                                        cntx->pos.index,
                                        g_srv_phb_sim_op_cntx.op_occur,
                                        email->email);
                        }
                        else
                        {
                            srv_phb_delete_usim_field_req(
                                        PHB_EMAIL,
                                        cntx->pos.index,
                                        g_srv_phb_sim_op_cntx.op_occur);
                        }
                        return MMI_TRUE;
                    }
                    while (g_srv_phb_sim_op_cntx.iterator)
                    {
                        email = srv_phb_contact_get_email_next(&(g_srv_phb_sim_op_cntx.iterator));
                        if (email)
                        {
                            srv_phb_contact_remove_email(cntx->contact, email);
                        }
                    }
                }
                g_srv_phb_sim_op_cntx.cur_occur = 0;
                g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_SNE;
                break;
                
            case SRV_PHB_SIM_OP_SNE:
                if (cntx->update_field & MMI_PHB_CONTACT_FIELD_NICK)
                {
                    if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].sne_occur)
                    {
                        WCHAR* name = srv_phb_contact_get_nick(cntx->contact);
                        g_srv_phb_sim_op_cntx.cur_occur++;
                        if (name && name[0])
                        {
                            srv_phb_set_usim_field_req(
                                        PHB_SNE,
                                        cntx->pos.index,
                                        g_srv_phb_sim_op_cntx.cur_occur,
                                        name);
                        }
                        else
                        {
                            srv_phb_delete_usim_field_req(
                                        PHB_SNE,
                                        cntx->pos.index,
                                        g_srv_phb_sim_op_cntx.cur_occur);
                        }
                        return MMI_TRUE;
                    }
                }
                g_srv_phb_sim_op_cntx.cur_occur = 0;
                g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_GRP;
                break;
                
            case SRV_PHB_SIM_OP_ANR:
                if (cntx->update_field & MMI_PHB_CONTACT_FIELD_NUMBER)
                {
                    srv_phb_number_struct* number = NULL;
                    if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].anr_occur)
                    {
                        U8 aas_id = 0xff;
                        g_srv_phb_sim_op_cntx.cur_occur++;
                        if (g_srv_phb_sim_op_cntx.iterator)
                        {
                            number = srv_phb_contact_get_number_next(&(g_srv_phb_sim_op_cntx.iterator));
                            if (number)
                            {
                                if (number->type >= MMI_PHB_NUM_TYPE_USER_BASE &&
                                    number->type < (g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].aas_total + MMI_PHB_NUM_TYPE_USER_BASE))
                                {
                                    aas_id = (U8)(number->type - MMI_PHB_NUM_TYPE_USER_BASE + 1);
                                }
                                if (mmi_wcschr(number->number, L'w') ||
                                    mmi_wcschr(number->number, L'W') ||
                                    mmi_wcschr(number->number, L'?'))
                                {
                                    g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
                                    break;
                                }
                                if (cntx->mode == SRV_PHB_UPDATE_MODE_IMPORT)
                                {
                                    if (number->index <= g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].anr_occur)
                                    {
                                        g_srv_phb_sim_op_cntx.op_occur = number->index;
                                    }
                                    else
                                    {
                                        /* print error trace */
                                        g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
                                        break;
                                    }
                                }
                            }
                        }
                        else if (cntx->mode == SRV_PHB_UPDATE_MODE_IMPORT)
                        {
                            g_srv_phb_sim_op_cntx.cur_occur = 0;
                            g_srv_phb_sim_op_cntx.iterator = srv_phb_contact_get_email_iterator(cntx->contact);
                            g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_EMAIL;
                            break;
                        }
                        if (cntx->mode == SRV_PHB_UPDATE_MODE_REPLACE)
                        {
                            g_srv_phb_sim_op_cntx.op_occur = g_srv_phb_sim_op_cntx.cur_occur;
                            if (number)
                            {
                                number->index = g_srv_phb_sim_op_cntx.cur_occur;
                                number->sub_id = g_srv_phb_sim_op_cntx.cur_occur;
                            }
                        }
                        if (number && number->number[0])
                        {
                            srv_phb_set_sim_number_req(
                                            cntx->pos.storage,
                                            cntx->pos.index,
                                            g_srv_phb_sim_op_cntx.op_occur,
                                            NULL,
                                            number->number,
                                            aas_id);
                        }
                        else
                        {
                            srv_phb_delete_sim_number_req(
                                            cntx->pos.storage,
                                            cntx->pos.index,
                                            g_srv_phb_sim_op_cntx.op_occur);

                        }
                        return MMI_TRUE;
                    }
                    else
                    {
                        while (g_srv_phb_sim_op_cntx.iterator)
                        {
                            number = srv_phb_contact_get_number_next(&(g_srv_phb_sim_op_cntx.iterator));
                            if (number)
                            {
                                srv_phb_contact_remove_number(cntx->contact, number);
                            }
                        }
                    }
                }
                g_srv_phb_sim_op_cntx.iterator = srv_phb_contact_get_email_iterator(cntx->contact);
                g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_EMAIL;
                g_srv_phb_sim_op_cntx.cur_occur = 0;
                break;
                
            case SRV_PHB_SIM_OP_ADN:
            {
                srv_phb_number_struct* temp;
                WCHAR* number = NULL;
                WCHAR* name = NULL;
                if (cntx->update_field & MMI_PHB_CONTACT_FIELD_NAME)
                {
                    name = srv_phb_contact_get_name(cntx->contact);
                }
                else if (cntx->pos.index != SRV_PHB_INVALID_INDEX)
                {
                    name = srv_phb_sim_get_name(srv_phb_get_sim_id((phb_storage_enum)cntx->pos.storage), (U16)(cntx->pos.index - 1));
                }
                
                g_srv_phb_sim_op_cntx.iterator = srv_phb_contact_get_number_iterator(cntx->contact);
                if (g_srv_phb_sim_op_cntx.iterator)
                {
                    temp = srv_phb_contact_get_number_next(&(g_srv_phb_sim_op_cntx.iterator));
                    if (temp)
                    {
                        if (cntx->mode == SRV_PHB_UPDATE_MODE_IMPORT && temp->index)
                        {
                            g_srv_phb_sim_op_cntx.iterator = srv_phb_contact_get_number_iterator(cntx->contact);
                            g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_ANR;
                            break;
                        }
                        else
                        {
                            number = temp->number;
                            if (mmi_wcschr(number, L'w') || mmi_wcschr(number, L'W') || mmi_wcschr(number, L'?'))
                            {
                                return MMI_FALSE;
                            }
                        }
                    }
                }
                g_srv_phb_sim_op_cntx.op_occur = 0;

                if (cntx->update_field & MMI_PHB_CONTACT_FIELD_NAME ||
                    cntx->update_field & MMI_PHB_CONTACT_FIELD_NUMBER)
                {
                    return srv_phb_set_sim_number_req(
                                cntx->pos.storage,
                                cntx->pos.index,
                                0,
                                name,
                                number,
                                0);
                }
                else
                {
                    g_srv_phb_sim_op_cntx.iterator = srv_phb_contact_get_number_iterator(cntx->contact);
                    g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_ANR;
                    break;
                }
            }
            case SRV_PHB_SIM_OP_GRP:
                if ((cntx->update_field & MMI_PHB_CONTACT_FIELD_GROUP) &&
                    g_srv_phb_sim_op_cntx.cur_occur == 0)
                {
                    srv_phb_group_struct* group;
                    group = srv_phb_contact_get_group(cntx->contact);
                    g_srv_phb_sim_op_cntx.cur_occur ++;
                    if (group && group->group_count)
                    {
                        U16 count = 0;
                        U8 sim_id = srv_phb_get_sim_id(cntx->pos.storage);
                        while (count < group->group_count)
                        {
                            group->group_id[count] -= (MMI_PHB_GROUP_COUNT + PHB_MAX_ASSOCIATE_GRP * sim_id);
                            group->group_id[count ++] += 1;
                        }
                        srv_phb_set_usim_field_req(
                            PHB_GRP,
                            cntx->pos.index,
                            g_srv_phb_sim_op_cntx.cur_occur,
                            (WCHAR* )group);
                    }
                    else
                    {
                        srv_phb_delete_usim_field_req(
                            PHB_GRP,
                            cntx->pos.index,
                            g_srv_phb_sim_op_cntx.cur_occur);
                    }
                    return MMI_TRUE;
                }
                g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_TOTAL;
                break;

            default:
                srv_phb_write_sim_done();
                return MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_sim_number_rsp
 * DESCRIPTION
 *  response message from L4 after delete one entry
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_set_sim_number_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    mmi_phb_set_entry_rsp_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_phb_set_entry_rsp_struct*) info;
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SIM_SET_SIM_NUMBER_RSP, g_srv_phb_sim_op_cntx.status);
    if (local_ptr->result.flag == 0 /* OK */ )
    {
        S32 sim_id = g_srv_phb_sim_op_cntx.sim_id;

        if (!(local_ptr->list[0].num_index))
        {
            mmi_phb_contact_id id;
            srv_phb_sim_adn_struct* adn;
            WCHAR* name = srv_phb_contact_get_name(cntx->contact);

            cntx->pos.index = local_ptr->list[0].record_index;
            id = (mmi_phb_contact_id)(cntx->pos.index - 1 + MMI_PHB_PHONE_ENTRIES + sim_id * MMI_PHB_SIM_ENTRIES);
            adn = &(g_srv_phb_sim_cache[sim_id][cntx->pos.index - 1].adn);
            g_srv_phb_sim_op_cntx.finish_count++;
            if (g_srv_phb_sim_op_cntx.finish_count == 1)
            {
                g_srv_phb_sim_op_cntx.dest_id = id;
            }
            srv_phb_sim_parse_l4_name(&(local_ptr->list[0].alpha_id), adn->name, MMI_PHB_NAME_FIELD_LENGTH);
            
            if (name && mmi_wcscmp(name, adn->name) != 0)
            {
                srv_phb_contact_set_fname(cntx->contact, adn->name);
                srv_phb_contact_set_lname(cntx->contact, NULL);
                g_srv_phb_sim_op_cntx.result = SRV_PHB_NAME_MODIFIED;
            }
            
            if ((cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_ADD || cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_COPY) &&
                !(g_srv_phb_sim_cache[sim_id][cntx->pos.index - 1].field_mask & MMI_PHB_CONTACT_FIELD_SIM))
            {
                g_srv_phb_sim_cntx[sim_id].used_count++;
                MMI_ASSERT(g_srv_phb_sim_cntx[sim_id].used_count <= g_srv_phb_sim_cntx[sim_id].total_count);
            }
            else
            {
                cntx->op_type = SRV_PHB_DATAMGR_OP_TYPE_UPD;
                srv_phb_sse_delete_name_index(id);
            }
            srv_phb_sse_insert_name_index(id, adn->name);
            
        #if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
            srv_phb_sse_make_pinyin_cache(id, adn->name);
        #endif
        }
        srv_phb_sim_set_l4_number(
            g_srv_phb_sim_op_cntx.sim_id,
            local_ptr->list[0].num_index,
            (U16)(local_ptr->list[0].record_index - 1),
            (CHAR*)&(local_ptr->list[0].tel.number),
            local_ptr->list[0].tel.type,
            local_ptr->list[0].aas_id);
        
    }
    else if (g_srv_phb_sim_op_cntx.status == SRV_PHB_SIM_OP_ADN)
    {
        U16 cause = local_ptr->result.cause;
        if (cause == PHB_CAUSE_CAPACITY_EXCEEDED)
        {
            g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
        }
        else if (cause == SIM_EF_RECORD_FULL)
        {
            g_srv_phb_sim_op_cntx.result = SRV_PHB_NUMBER_TOO_LONG;
        }
        else if (cause == SIM_CMD_FAIL)
        {
            g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_ERROR;
        }
        else
        {
            g_srv_phb_sim_op_cntx.result = SRV_PHB_ERROR;
        }
        g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_TOTAL;
        g_srv_phb_sim_op_cntx.continue_func();
        return;
    }
    else
    {
        if (cntx->contact)
        {
            srv_phb_number_struct* number =
                srv_phb_contact_get_number_by_save_index(cntx->contact, (U8)(g_srv_phb_sim_op_cntx.op_occur - 1));
            srv_phb_contact_remove_number(cntx->contact, number);
        }
        g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
    }
    g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_ANR;
    g_srv_phb_sim_op_cntx.continue_func();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_contact_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_phb_set_sim_number_req(phb_storage_enum storage, U16 index, U8 occur, WCHAR* name, WCHAR* number, U8 aas_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_set_entry_req_struct *my_msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_set_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_set_entry_req_struct));

    my_msg_ptr->no_data = 1;
    if (occur)
    {
        my_msg_ptr->type = PHB_ANR;
    }
    else
    {
        my_msg_ptr->type = PHB_PHONEBOOK;
    }
    my_msg_ptr->list.storage = storage;
    my_msg_ptr->list.index = SRV_PHB_INVALID_INDEX;
    my_msg_ptr->list.record_index = index;
    my_msg_ptr->list.num_index = occur;
    
    if (!srv_phb_build_sim_entry(&my_msg_ptr->list, name, number, aas_id, storage, index, occur) && !occur)
    {
        OslFreeDataPtr(my_msg_ptr);
        return MMI_FALSE;
    }
    SetProtocolEventHandler(srv_phb_set_sim_number_rsp, MSG_ID_MMI_PHB_SET_ENTRY_RSP);
    mmi_frm_send_ilm((oslModuleType) g_srv_phb_sim_op_cntx.mod, MSG_ID_MMI_PHB_SET_ENTRY_REQ, (oslParaType*) my_msg_ptr, NULL);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_usim_field_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_set_usim_field_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_write_usim_rsp_struct *local_ptr = (mmi_phb_write_usim_rsp_struct*) info;
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (local_ptr->type)
    {
        case PHB_EMAIL:
        {
            srv_phb_email_struct* src = NULL;
            if (cntx->contact)
            {
                src = srv_phb_contact_get_email_by_save_index(cntx->contact, (U8)(local_ptr->occurrence - 1));
                MMI_ASSERT(src);
            }
            if (local_ptr->result.flag == L4C_OK)
            {
                WCHAR dest_email[MMI_PHB_EMAIL_LENGTH + 1];
                InputboxConvertGSMToDeviceEncoding(
                    local_ptr->entry.field.email.email_address,
                    (U8*)dest_email,
                    local_ptr->entry.field.email.email_length,
                    (MMI_PHB_EMAIL_LENGTH + 1) * ENCODING_LENGTH,
                    SRV_PHB_CHARSET_ASCII,
                    0,
                    1);
                if (src && mmi_wcscmp(src->email, dest_email) != 0)
                {
                    mmi_wcscpy(src->email, dest_email);
                    g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
                }
                srv_phb_sim_set_email(
                    g_srv_phb_sim_op_cntx.sim_id,
                    local_ptr->occurrence,
                    (U16)(local_ptr->record_index - 1),
                    dest_email);
            }
            else
            {
                if (src)
                {
                    srv_phb_contact_remove_email(cntx->contact, src);
                }
                g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
            }
            break;
        }

        case PHB_SNE:
        {
            if (local_ptr->result.flag == L4C_OK)
            {
                WCHAR dest_name[MMI_PHB_NAME_FIELD_LENGTH + 1];
                
                srv_phb_sim_parse_l4_name(&(local_ptr->entry.field.sne), dest_name, MMI_PHB_NAME_FIELD_LENGTH);
                if (cntx->contact && mmi_wcscmp(srv_phb_contact_get_nick(cntx->contact), dest_name) != 0)
                {
                    srv_phb_contact_set_nick(cntx->contact, dest_name);
                    g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
                }
                srv_phb_sim_set_l4_sne(
                    g_srv_phb_sim_op_cntx.sim_id,
                    (U16)(local_ptr->record_index - 1),
                    &(local_ptr->entry.field.sne));
            }
            else
            {
                if (cntx->contact)
                {
                    srv_phb_contact_set_nick(cntx->contact, NULL);
                }
                g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
            }
            break;
        }
        case PHB_GAS:
        {
            if (local_ptr->result.flag == L4C_OK)
            {
                WCHAR dest_name[MMI_PHB_NAME_FIELD_LENGTH + 1];
                U16 store_index = (U16)(local_ptr->record_index - 1);
                srv_phb_sim_parse_l4_name(&(local_ptr->entry.field.gas), dest_name, MMI_PHB_NAME_FIELD_LENGTH);
                srv_phb_sim_set_l4_gas(
                    g_srv_phb_sim_op_cntx.sim_id,
                    store_index,
                    &(local_ptr->entry.field.gas));
                #ifdef __MMI_PHB_CALLER_GROUP__
                srv_phb_group_set_group_done(
                    SRV_PHB_NO_ERROR,
                    (U8)(store_index + MMI_PHB_GROUP_COUNT + g_srv_phb_sim_op_cntx.sim_id * PHB_MAX_ASSOCIATE_GRP),
                    dest_name);
                #endif
            }
            return;
        }
        case PHB_GRP:
        {
            if (local_ptr->result.flag == L4C_OK)
            {
                srv_phb_group_struct group;
                U32 i;
                U8 gas_id;
                group.group_count = 0;
                if (cntx->contact)
                {
                    for (i = 0; i < PHB_MAX_ASSOCIATE_GRP; i ++)
                    {
                        gas_id = local_ptr->entry.field.grp.gas_id[i];
                        if (gas_id != 0)
                        {
                            group.group_id[group.group_count] = gas_id + g_srv_phb_sim_op_cntx.sim_id * PHB_MAX_ASSOCIATE_GRP + MMI_PHB_GROUP_COUNT - 1;
                            group.group_count ++;
                        }
                    }
                    if (group.group_count > 0)
                    {
                        srv_phb_contact_set_group(cntx->contact, &group);
                    }
                    else
                    {
                        srv_phb_contact_set_group(cntx->contact, NULL);
                    }
                }
                srv_phb_sim_set_field_mask(
                    g_srv_phb_sim_op_cntx.sim_id,
                    (U16)(local_ptr->record_index - 1),
                    MMI_PHB_CONTACT_FIELD_GROUP,
                    MMI_TRUE);
                srv_phb_sim_set_grp(
                    g_srv_phb_sim_op_cntx.sim_id,
                    (U16)(local_ptr->record_index - 1),
                    &local_ptr->entry.field.grp);
            }
            else
            {
                g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
            }
            break;
        }
        default:
            break;
    }
    g_srv_phb_sim_op_cntx.continue_func();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_usim_field_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_set_usim_field_req(phb_type_enum type, U16 index, U8 occur, WCHAR* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_write_usim_req_struct *my_msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_write_usim_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_write_usim_req_struct));
    my_msg_ptr->occurrence = occur;

    my_msg_ptr->type = type;
    my_msg_ptr->record_index = index;
    switch (type)
    {
        case PHB_EMAIL:
        {
            phb_email_struct* email_field = &(my_msg_ptr->entry.field.email);
            if (data && data[0])
            {
                mmi_wcs_n_to_asc(email_field->email_address, data, MMI_PHB_EMAIL_LENGTH * sizeof(U16));
                email_field->email_length = InputboxConvertDeviceEncodingToGSM(
                                                (PU8)data,
                                                email_field->email_address,
                                                MMI_PHB_EMAIL_LENGTH,
                                                SRV_PHB_CHARSET_ASCII,
                                                0,
                                                1) - 1;
            }
            else
            {
                email_field->email_address[0] = 0;
                email_field->email_length = 0;
            }
            email_field->adn_record_index = index;
            break;
        }

        case PHB_SNE:
        {
            phb_sne_struct* sne_field = &(my_msg_ptr->entry.field.sne);
            srv_phb_sim_build_l4_name(sne_field, data);
            break;
        }

        case PHB_GAS:
        {
            phb_gas_struct * gas_field = &(my_msg_ptr->entry.field.gas);
            srv_phb_sim_build_l4_name(gas_field, data);
            break;
        }
        case PHB_GRP:
        {
            U32 count;
            phb_grp_struct* grp = &(my_msg_ptr->entry.field.grp);
            srv_phb_group_struct *group = (srv_phb_group_struct*)data;            
            for (count = 0; count < group->group_count; count ++)
            {
                grp->gas_id[count] = group->group_id[count];
            }
            break;
        }

        default:
            MMI_ASSERT(0);
    }
    SetProtocolEventHandler(srv_phb_set_usim_field_rsp, MSG_ID_MMI_PHB_WRITE_USIM_RSP);
    mmi_frm_send_ilm((oslModuleType) g_srv_phb_sim_op_cntx.mod, MSG_ID_MMI_PHB_WRITE_USIM_REQ, (oslParaType*) my_msg_ptr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_delete_sim_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id;
    srv_phb_datamgr_op_status_struct status;
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = (mmi_phb_contact_id)(cntx->pos.index - 1 + MMI_PHB_PHONE_ENTRIES + g_srv_phb_sim_op_cntx.sim_id * MMI_PHB_SIM_ENTRIES);
    
    MMI_ASSERT(g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].used_count > 0);
    g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].used_count--;
    srv_phb_sim_clear_all_fields(g_srv_phb_sim_op_cntx.sim_id, (U16)(cntx->pos.index - 1));
    
    /* clear phonebook entry and remove from index */
    srv_phb_sse_delete_name_index(id);
    status.result = SRV_PHB_NO_ERROR;
    status.id = id;
    srv_phb_datamgr_op_done(&status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_fail
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_delete_sim_fail(U16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_PHB_ERROR;
    srv_phb_datamgr_op_status_struct status;
    mmi_phb_contact_id id;
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = (mmi_phb_contact_id)(cntx->pos.index - 1 + MMI_PHB_PHONE_ENTRIES + g_srv_phb_sim_op_cntx.sim_id * MMI_PHB_SIM_ENTRIES);
    if (error_code == SIM_CMD_FAIL)
    {
        status.result = SRV_PHB_SIM_ERROR;
    }
    else
    {
        status.result = SRV_PHB_ERROR;
    }
    status.id = id;
    srv_phb_datamgr_op_done(&status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_delete_sim_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        switch (g_srv_phb_sim_op_cntx.status)
        {
            case SRV_PHB_SIM_OP_EMAIL:
                if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].email_occur)
                {
                    g_srv_phb_sim_op_cntx.cur_occur++;
                    g_srv_phb_sim_op_cntx.op_occur = g_srv_phb_sim_op_cntx.cur_occur;
                    srv_phb_delete_usim_field_req(
                        PHB_EMAIL,
                        cntx->pos.index,
                        g_srv_phb_sim_op_cntx.op_occur);
                    return MMI_TRUE;
                }
                break;
                
            case SRV_PHB_SIM_OP_ANR:
                if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].anr_occur)
                {
                    g_srv_phb_sim_op_cntx.cur_occur++;
                    g_srv_phb_sim_op_cntx.op_occur = g_srv_phb_sim_op_cntx.cur_occur;
                    srv_phb_delete_sim_number_req(
                        (phb_storage_enum)(cntx->pos.storage),
                        cntx->pos.index,
                        g_srv_phb_sim_op_cntx.op_occur);
                    return MMI_TRUE;
                }
                break;
                
            case SRV_PHB_SIM_OP_SNE:
                if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].sne_occur)
                {
                    srv_phb_delete_usim_field_req(
                        PHB_SNE,
                        cntx->pos.index,
                        (U8)(g_srv_phb_sim_op_cntx.cur_occur + 1));
                    g_srv_phb_sim_op_cntx.status++;
                    return MMI_TRUE;
                }
                break;
                
            case SRV_PHB_SIM_OP_ADN:
                g_srv_phb_sim_op_cntx.op_occur = 0;
                srv_phb_delete_sim_number_req(
                    (phb_storage_enum)(cntx->pos.storage),
                    cntx->pos.index,
                    0);
                g_srv_phb_sim_op_cntx.status++;
                return MMI_TRUE;
                
            case SRV_PHB_SIM_OP_GRP:
                srv_phb_delete_usim_field_req(
                    PHB_GRP,
                    cntx->pos.index,
                    (U8)(g_srv_phb_sim_op_cntx.cur_occur + 1));
                g_srv_phb_sim_op_cntx.status++;
                return MMI_TRUE;
                    
            default:
                srv_phb_delete_sim_done();
                return MMI_TRUE;
        }
        g_srv_phb_sim_op_cntx.cur_occur = 0;
        g_srv_phb_sim_op_cntx.status++;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_usim_field_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_delete_usim_field_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_delete_usim_rsp_struct *local_ptr = (mmi_phb_delete_usim_rsp_struct*) info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (local_ptr->result.flag != L4C_OK)
    {
        if (local_ptr->type == PHB_GAS)
        {
            srv_phb_group_set_group_done(
                SRV_PHB_SIM_ERROR,
                (U8)(local_ptr->record_index - 1 + MMI_PHB_GROUP_COUNT + g_srv_phb_sim_op_cntx.sim_id * PHB_MAX_ASSOCIATE_GRP),
                NULL);
            return;
        }
        g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
    }
    else
    {
        switch (local_ptr->type)
        {
            case PHB_EMAIL:
            {
                srv_phb_sim_set_email(
                    g_srv_phb_sim_op_cntx.sim_id,
                    local_ptr->occurrence,
                    (U16)(local_ptr->record_index - 1),
                    NULL);
                break;
            }

            case PHB_SNE:
            {
                srv_phb_sim_set_sne(
                    g_srv_phb_sim_op_cntx.sim_id,
                    (U16)(local_ptr->record_index - 1),
                    NULL);
                break;
            }
            
            case PHB_GRP:
            {
                srv_phb_sim_set_grp(
                    g_srv_phb_sim_op_cntx.sim_id,
                    (U16)(local_ptr->record_index - 1),
                    NULL);
                break;
            }
            case PHB_GAS:
                srv_phb_sim_set_l4_gas(
                    g_srv_phb_sim_op_cntx.sim_id,
                    (U16)(local_ptr->record_index - 1),
                    NULL);
                #ifdef __MMI_PHB_CALLER_GROUP__
                srv_phb_group_set_group_done(
                    SRV_PHB_NO_ERROR,
                    (U8)(local_ptr->record_index - 1 + MMI_PHB_GROUP_COUNT + g_srv_phb_sim_op_cntx.sim_id * PHB_MAX_ASSOCIATE_GRP),
                    NULL);
                #endif
                return;
            default:
                break;
        }
    }

    g_srv_phb_sim_op_cntx.continue_func();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_usim_field_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_delete_usim_field_req(phb_type_enum type, U16 record_index, U8 occurrence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_delete_usim_req_struct *my_msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_delete_usim_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_delete_usim_req_struct));

    my_msg_ptr->occurrence = occurrence;
    // TODO : use l4 enum
    my_msg_ptr->type = type;

    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    my_msg_ptr->record_index = record_index;
    SetProtocolEventHandler(srv_phb_delete_usim_field_rsp, MSG_ID_MMI_PHB_DELETE_USIM_RSP);
    mmi_frm_send_ilm((oslModuleType)g_srv_phb_sim_op_cntx.mod, MSG_ID_MMI_PHB_DELETE_USIM_REQ, (oslParaType*) my_msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_number_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_delete_sim_number_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_del_entry_rsp_struct *local_ptr = (mmi_phb_del_entry_rsp_struct*)info;
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (local_ptr->result.flag != L4C_OK)
    {
        if (local_ptr->type == PHB_PHONEBOOK)
        {
            srv_phb_delete_sim_fail(local_ptr->result.cause);
        }
        else
        {
            g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
            g_srv_phb_sim_op_cntx.continue_func();
        }
    }
    else
    {
        srv_phb_sim_set_number(
            g_srv_phb_sim_op_cntx.sim_id,
            g_srv_phb_sim_op_cntx.op_occur,
            (U16)(cntx->pos.index - 1),
            NULL,
            0);
        g_srv_phb_sim_op_cntx.continue_func();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_number_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_delete_sim_number_req(phb_storage_enum storage, U16 record_index, U8 occurrence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_del_entry_req_struct *my_msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_del_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_del_entry_req_struct));

    // TODO : use l4 enum
    my_msg_ptr->num_index = occurrence;
    if (occurrence)
    {
        my_msg_ptr->type = PHB_ANR;
    }
    else
    {
        my_msg_ptr->type = PHB_PHONEBOOK;
    }
    my_msg_ptr->storage = storage;
    my_msg_ptr->record_index = record_index;
    my_msg_ptr->index = SRV_PHB_INVALID_INDEX;
    my_msg_ptr->no_data = 1;
    SetProtocolEventHandler(srv_phb_delete_sim_number_rsp, MSG_ID_MMI_PHB_DEL_ENTRY_RSP);
    mmi_frm_send_ilm((oslModuleType)g_srv_phb_sim_op_cntx.mod, MSG_ID_MMI_PHB_DEL_ENTRY_REQ, (oslParaType*) my_msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_copy_sim_contact_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        switch (g_srv_phb_sim_op_cntx.status)
        {
            case SRV_PHB_SIM_OP_EMAIL:
                if (g_srv_phb_sim_op_cntx.finish_count == 1)
                {
                    if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].email_occur)
                    {
                        CHAR* asc_email = NULL;
                        asc_email = srv_phb_datamgr_get_email(cntx->src_id, g_srv_phb_sim_op_cntx.cur_occur++);

                        if (asc_email && asc_email[0])
                        {
                            WCHAR email[MMI_PHB_EMAIL_LENGTH + 1];
                            mmi_asc_to_wcs(email, asc_email);
                            srv_phb_set_usim_field_req(
                                        PHB_EMAIL,
                                        cntx->pos.index,
                                        g_srv_phb_sim_op_cntx.cur_occur,
                                        email);
                            return MMI_TRUE;
                        }
                    }
                }
                g_srv_phb_sim_op_cntx.cur_occur = 0;
                g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_SNE;
                break;
                
            case SRV_PHB_SIM_OP_SNE:
                if (g_srv_phb_sim_op_cntx.finish_count == 1 && srv_phb_get_storage(cntx->src_id) != PHB_STORAGE_NVRAM)
                {
                    if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].sne_occur)
                    {
                        WCHAR* name = srv_phb_get_sim_nick_name(cntx->src_id);
                        g_srv_phb_sim_op_cntx.cur_occur++;
                        if (name && name[0])
                        {
                            srv_phb_set_usim_field_req(
                                        PHB_SNE,
                                        cntx->pos.index,
                                        g_srv_phb_sim_op_cntx.cur_occur,
                                        name);
                            return MMI_TRUE;
                        }
                    }
                }
                g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_TOTAL;
                break;
                
            case SRV_PHB_SIM_OP_ANR:
                if (g_srv_phb_sim_op_cntx.cur_occur < g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].anr_occur)
                {
                    CHAR* asc_num = NULL;
                    U8 type;
                    g_srv_phb_sim_op_cntx.cur_occur++;
                    while (g_srv_phb_sim_op_cntx.cur_index < MMI_PHB_NUMBER_FIELD_COUNT)
                    {
                        asc_num = srv_phb_datamgr_get_number(cntx->src_id, g_srv_phb_sim_op_cntx.cur_index++, &type);
                        if (asc_num && asc_num[0])
                        {
                            if (strchr(asc_num, 'w') || strchr(asc_num, 'W') || strchr(asc_num, '?'))
                            {
                                g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
                                asc_num = NULL;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    if (asc_num && asc_num[0])
                    {
                        WCHAR number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
                        U8 aas_id = 0xff;
                        mmi_asc_to_wcs(number, asc_num);
                        if (srv_phb_get_storage(cntx->src_id) == cntx->pos.storage &&
                            type >= MMI_PHB_NUM_TYPE_USER_BASE &&
                            type < (g_srv_phb_sim_cntx[g_srv_phb_sim_op_cntx.sim_id].aas_total + MMI_PHB_NUM_TYPE_USER_BASE))
                        {
                            aas_id = (U8)(type - MMI_PHB_NUM_TYPE_USER_BASE + 1);
                        }
                        return srv_phb_set_sim_number_req(
                                        cntx->pos.storage,
                                        cntx->pos.index,
                                        g_srv_phb_sim_op_cntx.cur_occur,
                                        NULL,
                                        number,
                                        aas_id);
                    }
                }
                g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_EMAIL;
                g_srv_phb_sim_op_cntx.cur_occur = 0;
                break;
                
            case SRV_PHB_SIM_OP_ADN:
            {
                CHAR* asc_num = NULL;
                g_srv_phb_sim_op_cntx.op_occur = 0;
                while (g_srv_phb_sim_op_cntx.cur_index < MMI_PHB_NUMBER_FIELD_COUNT)
                {
                    asc_num = srv_phb_datamgr_get_number(cntx->src_id, g_srv_phb_sim_op_cntx.cur_index++, NULL);
                    if (asc_num && asc_num[0])
                    {
                        if (strchr(asc_num, 'w') || strchr(asc_num, 'W') || strchr(asc_num, '?'))
                        {
                            g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
                            asc_num = NULL;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if ((asc_num && asc_num[0]) || (g_srv_phb_sim_op_cntx.finish_count == 0))
                {
                    WCHAR name[MMI_PHB_NAME_LENGTH + 1];
                    WCHAR number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
                    srv_phb_datamgr_get_name(cntx->src_id, name, MMI_PHB_NAME_LENGTH);
                    if (asc_num)
                    {
                        mmi_asc_to_wcs(number, asc_num);
                    }
                    else
                    {
                        number[0] = 0;
                    }
                    return srv_phb_set_sim_number_req(
                                cntx->pos.storage,
                                cntx->pos.index,
                                0,
                                name,
                                number,
                                0);
                }
                else
                {
                    srv_phb_datamgr_op_status_struct status;
                    status.result = g_srv_phb_sim_op_cntx.result;
                    status.id = g_srv_phb_sim_op_cntx.dest_id;
                    srv_phb_datamgr_op_done(&status);
                }
                return MMI_TRUE;
            }

            default:
                if (g_srv_phb_sim_op_cntx.result >= 0)
                {
                    g_srv_phb_sim_op_cntx.finish_count++;
                    if (cntx->pos.index != SRV_PHB_INVALID_INDEX)
                    {
                    srv_phb_sim_update_field_mask(g_srv_phb_sim_op_cntx.sim_id, (U16)(cntx->pos.index - 1));
                    }
                    cntx->pos.index = SRV_PHB_INVALID_INDEX;
                    g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_ADN;
                }
                else
                {
                    srv_phb_datamgr_op_status_struct status;
                    status.result = g_srv_phb_sim_op_cntx.result;
                    status.id = g_srv_phb_sim_op_cntx.dest_id;
                    srv_phb_datamgr_op_done(&status);
                    return MMI_TRUE;
                }
                break;
        }
    }
    return MMI_TRUE;
}

#else
/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_parse_sim_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_parse_sim_entry(l4c_phb_entry_struct* phb_entry, srv_phb_sim_adn_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_sim_parse_l4_name(
        &(phb_entry->alpha_id),
        entry->name,
        MMI_PHB_NAME_FIELD_LENGTH);

    applib_decode_number(phb_entry->tel.number, entry->number, phb_entry->tel.type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_name_num_field_flag
 * DESCRIPTION
 *  update name and number fileter flag of a entry.
 * PARAMETERS
 *  store_index              [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_phb_sim_check_name_modify(srv_phb_sim_adn_struct* entry, WCHAR* name, WCHAR* l_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!name && entry->name[0]) || (name && mmi_wcslen(entry->name) != mmi_wcslen(name)))
    {
        return MMI_TRUE;
    }
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (l_name && l_name[0])
    {
        return MMI_TRUE;
    }
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_build_sim_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_build_sim_entry(void *req_msg, WCHAR* name, WCHAR* l_name, WCHAR* num, srv_phb_contact_pos_struct* pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4c_phb_entry_struct *phb_entry = (l4c_phb_entry_struct*)req_msg;
    U8 ton;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num != NULL)
    {
        U16 encode_num[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
        srv_phb_remove_invalid_number(num);
        /* now number is **21*+8123456# */
        /* call the second API to transfer + to the first place */
        ton = applib_encode_number_unicode(num, encode_num);
        /* now number is +**21*8123456#, so we know it is an international number */
        /* Prepate Number Data */
        if (ton == 0x91)
        {
            phb_entry->tel.type = SRV_PHB_NUMBER_TYPE_INTERNATIONAL; /* INTERNATIONAL */
        }
        else
        {
            phb_entry->tel.type = SRV_PHB_NUMBER_TYPE_DEFAULT;  /* DEFAULT */
        }
        phb_entry->tel.length = (U8)mmi_wcslen(encode_num);
        mmi_wcs_to_asc((CHAR*)phb_entry->tel.number, encode_num);
    }
    else if (pos->index != MMI_PHB_INVALID_CONTACT_ID)
    {
        CHAR* number = srv_phb_sim_get_number(
                            srv_phb_get_sim_id((phb_storage_enum)pos->storage),
                            (U16)(pos->index - 1),
                            0,
                            NULL);
        
        if (number[0])
        {
            ton = applib_encode_number(
                    (kal_uint8*)number, 
                    phb_entry->tel.number, 
                    (U8)(number[0]=='+' ? 0x91 : 0x81));
            phb_entry->tel.length = (U8)strlen((CHAR*)phb_entry->tel.number);
            if (ton == 0x91)
            {
                phb_entry->tel.type = SRV_PHB_NUMBER_TYPE_INTERNATIONAL; /* INTERNATIONAL */
            }
            else
            {
                phb_entry->tel.type = SRV_PHB_NUMBER_TYPE_DEFAULT;  /* DEFAULT */
            }
        }
    }

    if ((name != NULL) || (l_name != NULL))
    {
        U16 full_name[MMI_PHB_NAME_FIELD_LENGTH + 1];
        srv_phb_convert_to_name(full_name, name, l_name, MMI_PHB_NAME_FIELD_LENGTH);
        srv_phb_sim_build_l4_name(&phb_entry->alpha_id, full_name);
    }

    if (phb_entry->tel.length || phb_entry->alpha_id.name_length)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_sim_contact_rsp
 * DESCRIPTION
 *  response message from L4 after delete one entry
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_set_sim_contact_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_status_struct status;
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    mmi_phb_contact_id id = SRV_PHB_INVALID_INDEX;
    S32 result = SRV_PHB_NO_ERROR;
    mmi_phb_set_entry_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_phb_set_entry_rsp_struct*) info;
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SIM_SET_SIM_NUMBER_RSP, 3);
    if (localPtr->result.flag == 0 /* OK */ )
    {
        srv_phb_sim_adn_struct* adn;
        S32 sim_id = srv_phb_get_sim_id((phb_storage_enum)(cntx->pos.storage));
        cntx->pos.index = localPtr->list[0].record_index;
        
        adn = &(g_srv_phb_sim_cache[sim_id][cntx->pos.index - 1].adn);
            
        srv_phb_record_index_to_store_index(
            cntx->pos.storage,
            cntx->pos.index,
            &id);
        g_srv_phb_sim_op_cntx.finish_count++;
        if (g_srv_phb_sim_op_cntx.finish_count == 1)
        {
            g_srv_phb_sim_op_cntx.dest_id = id;
        }
        if ((cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_ADD || cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_COPY) &&
            !g_srv_phb_sim_cache[sim_id][cntx->pos.index - 1].field_mask)
        {
            g_srv_phb_sim_cntx[sim_id].used_count++;
            MMI_ASSERT(g_srv_phb_sim_cntx[sim_id].used_count <= g_srv_phb_sim_cntx[sim_id].total_count);
        }
        else
        {
            cntx->op_type = SRV_PHB_DATAMGR_OP_TYPE_UPD;
            srv_phb_sse_lookup_table_remove_contact(id, NULL); 
            srv_phb_sse_delete_name_index(id);
        }

        srv_phb_parse_sim_entry(&localPtr->list[0], adn);
        
        srv_phb_sse_insert_name_index(id, adn->name);
    
    #if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
        srv_phb_sse_make_pinyin_cache(id, adn->name);
    #endif
        srv_phb_sse_lookup_table_add_contact(id, (CHAR*)adn->number);
            
        /* Update name and number field flag */
        if (cntx->pos.index != SRV_PHB_INVALID_INDEX)
        {
        srv_phb_sim_update_field_mask(sim_id, (U16)(cntx->pos.index - 1));
        }
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        if (cntx->contact &&
            srv_phb_sim_check_name_modify(
                adn,
                srv_phb_contact_get_fname(cntx->contact),
                srv_phb_contact_get_lname(cntx->contact))
            )
    #else
        if (cntx->contact &&
            srv_phb_sim_check_name_modify(
                adn,
                srv_phb_contact_get_fname(cntx->contact),
                NULL)
            )
    #endif /* __MMI_PHB_LAST_NAME_FIELD__ */
        {
            srv_phb_contact_set_fname(cntx->contact, (WCHAR*)(adn->name));
        #if defined(__MMI_PHB_LAST_NAME_FIELD__)
            srv_phb_contact_set_lname(cntx->contact, NULL);
        #endif
            result = SRV_PHB_NAME_MODIFIED;
        }
    }
    else
    {
        if (localPtr->result.cause == SIM_EF_RECORD_FULL)
        {
            result = SRV_PHB_NUMBER_TOO_LONG;
        }
        else if (localPtr->result.cause == SIM_CMD_FAIL)
        {
            result = SRV_PHB_SIM_ERROR;
        }
        else
        {
            result = SRV_PHB_ERROR;
        }
    }
    status.result = result;
    status.id = id;
    g_srv_phb_sim_op_cntx.continue_func(&status);
}

    
/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_sim_contact_req
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_phb_set_sim_contact_req(srv_phb_contact_pos_struct* pos, WCHAR* name, WCHAR* l_name, WCHAR* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_set_entry_req_struct *my_msg_ptr;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_set_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_set_entry_req_struct));

    my_msg_ptr->no_data = 1;
    // TODO : use l4 enum
    my_msg_ptr->type = PHB_PHONEBOOK;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */

    my_msg_ptr->list.storage = pos->storage;
    my_msg_ptr->list.index = SRV_PHB_INVALID_INDEX;
    my_msg_ptr->list.record_index = pos->index;
    if (!srv_phb_build_sim_entry(&my_msg_ptr->list, name, l_name, number, pos))
    {
        OslFreeDataPtr(my_msg_ptr);
        return MMI_FALSE;
    }
    SetProtocolEventHandler(srv_phb_set_sim_contact_rsp, MSG_ID_MMI_PHB_SET_ENTRY_RSP);
    mmi_frm_send_ilm(
        (oslModuleType)srv_phb_get_l4c_mod_by_storage((phb_storage_enum)pos->storage),
        MSG_ID_MMI_PHB_SET_ENTRY_REQ,
        (oslParaType*) my_msg_ptr,
        NULL);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_contact_rsp
 * DESCRIPTION
 *  response message from L4 after delete one entry
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_delete_sim_contact_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_del_entry_rsp_struct *localPtr;
    mmi_phb_contact_id id;
    S32 result = SRV_PHB_ERROR;
    srv_phb_datamgr_op_status_struct status;
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_phb_del_entry_rsp_struct*) info;
    srv_phb_record_index_to_store_index(
        cntx->pos.storage,
        cntx->pos.index,
        &id);

    if (localPtr->result.flag == 0 /* OK */ )
    {
        S32 sim_id = srv_phb_get_sim_id((phb_storage_enum)(cntx->pos.storage));
        MMI_ASSERT(g_srv_phb_sim_cntx[sim_id].used_count > 0);
        g_srv_phb_sim_cntx[sim_id].used_count--;
        srv_phb_sim_clear_all_fields(sim_id, (U16)(cntx->pos.index - 1));
        /* Remove lookup table entry */
        srv_phb_sse_lookup_table_remove_contact(id, NULL); 
        
        /* clear phonebook entry and remove from index */
        srv_phb_sse_delete_name_index(id);

        result = SRV_PHB_NO_ERROR;
    }
    else if (localPtr->result.cause == SIM_CMD_FAIL)
    {
        result = SRV_PHB_SIM_ERROR;
    }
    status.result = result;
    status.id = id;
    srv_phb_datamgr_op_done(&status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_copy_sim_contact_continue(srv_phb_datamgr_op_status_struct* status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    mmi_phb_contact_id id = cntx->src_id;
    U8 storage = srv_phb_get_storage(id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status->result >= 0)
    {
        CHAR* asc_num = NULL;
        WCHAR* fname, *lname;
        while (g_srv_phb_sim_op_cntx.cur_index < MMI_PHB_NUMBER_FIELD_COUNT)
        {
            asc_num = srv_phb_datamgr_get_number(id, g_srv_phb_sim_op_cntx.cur_index++, NULL);
            if (asc_num && asc_num[0])
            {
                if (strchr(asc_num, 'w') || strchr(asc_num, 'W') || strchr(asc_num, '?'))
                {
                    g_srv_phb_sim_op_cntx.result = SRV_PHB_SIM_PARTIAL_ERROR;
                    asc_num = NULL;
                }
                else
                {
                    break;
                }
            }
        }
        if ((asc_num && asc_num[0]) || (g_srv_phb_sim_op_cntx.finish_count == 0))
        {
            WCHAR number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
            if (asc_num)
            {
                mmi_asc_to_wcs(number, asc_num);
            }
            else
            {
                 number[0] = 0;
            }
            if (storage == PHB_STORAGE_NVRAM)
            {
                fname = srv_phb_get_phone_fname(id);
                lname = srv_phb_get_phone_lname(id);
            }
            #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            else if (storage == PHB_STORAGE_TCARD)
            {
                fname = srv_phb_get_tcard_fname(id);
                lname = srv_phb_get_tcard_lname(id);
            }
            #endif

            else
            {
                fname = srv_phb_get_sim_name(id);
                lname = NULL;
            }
            cntx->pos.index = SRV_PHB_INVALID_INDEX;
            return srv_phb_set_sim_contact_req(
                        &(cntx->pos),
                        fname,
                        lname,
                        number);
        }
        status->result = g_srv_phb_sim_op_cntx.result;
    }
    else if (g_srv_phb_sim_op_cntx.finish_count)
    {
        status->result = SRV_PHB_SIM_PARTIAL_ERROR;
    }
    status->id = g_srv_phb_sim_op_cntx.dest_id;
    srv_phb_datamgr_op_done(status);
    return MMI_TRUE;
}
#endif /* __MMI_PHB_USIM_SUPPORT__ */


#define EXTERNAL_FUNCTION
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_support_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_sim_support_field(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U32 field = MMI_PHB_CONTACT_FIELD_SIM;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_SUPPORT__
    U8 sim_id = srv_phb_get_sim_id(storage);
    if (g_srv_phb_sim_cntx[sim_id].email_occur)
    {
        field |= MMI_PHB_CONTACT_FIELD_EMAIL;
    }
    if (g_srv_phb_sim_cntx[sim_id].sne_occur)
    {
        field |= MMI_PHB_CONTACT_FIELD_NICK;
    }
    if (g_srv_phb_sim_cntx[sim_id].gas_total)
    {
        field |= MMI_PHB_CONTACT_FIELD_GROUP;
    }
#endif
    return field;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_support_field_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_sim_support_field_count(phb_storage_enum storage, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field)
    {
        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
        #ifdef __MMI_PHB_USIM_SUPPORT__
            return g_srv_phb_sim_cntx[srv_phb_get_sim_id(storage)].anr_occur + 1;
            
        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
            return g_srv_phb_sim_cntx[srv_phb_get_sim_id(storage)].email_occur;
            
        case MMI_PHB_CONTACT_FIELD_ID_NICK:
            return g_srv_phb_sim_cntx[srv_phb_get_sim_id(storage)].sne_occur;
        #endif
        
        case MMI_PHB_CONTACT_FIELD_ID_NAME:
            return 1;

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_alpha_field_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_sim_alpha_field_len(phb_storage_enum storage, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field)
    {
        case MMI_PHB_CONTACT_FIELD_ID_NAME:
            type = PHB_PHONEBOOK;
            break;                
        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
            return MMI_PHB_NUMBER_PLUS_LENGTH;
            
    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_CONTACT_FIELD_ID_NICK:
            type = PHB_SNE;
            break;
        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
            type = PHB_EMAIL;
            break;
        case MMI_PHB_CONTACT_FIELD_ID_GROUP:
            type = PHB_GAS;
            break;
    #endif
    
        default:
            return 0;
    }
    return srv_phb_startup_get_alpha_length(srv_phb_get_sim_id(storage), type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_sim_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_set_sim_field_mask(mmi_phb_contact_id id, U32 filed_flag, MMI_BOOL exist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PHB_SIM_CONVERT_ID(id, sim_id);
    srv_phb_sim_set_field_mask(sim_id, id, filed_flag, exist);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_sim_field_mask(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PHB_SIM_CONVERT_ID(id, sim_id);
    return srv_phb_sim_get_field_mask(sim_id, id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_used
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_sim_used(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = srv_phb_get_sim_id(storage);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i == MMI_PHB_SIM_COUNT)
    {
        U16 used = 0;
        while (i--)
        {
            used += g_srv_phb_sim_cntx[i].used_count;
        }
        return used;
    }
    else
    {
        return g_srv_phb_sim_cntx[i].used_count;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_sim_total(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = srv_phb_get_sim_id(storage);;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i == MMI_PHB_SIM_COUNT)
    {
        U16 total = 0;
        while (i--)
        {
            total += g_srv_phb_sim_cntx[i].total_count;
        }
        return total;
    }
    else
    {
        return g_srv_phb_sim_cntx[i].total_count;
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_reset_sim_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sim_reset(srv_phb_startup_sim_init_cntx *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = info->sim_interface;
    U16 total_count = info->total_count;
    #ifdef __MMI_PHB_USIM_SUPPORT__
    U8 aas_total = info->aas_count;
    U8 anr_occur = info->anr_count;
    U8 email_occur = info->email_count;
    U8 sne_occur = info->sne_count;
    U8 gas_total = info->gas_count;
    S32 j;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_sim_cache[i])
    {
        srv_phb_mem_free(g_srv_phb_sim_cache[i]);
        g_srv_phb_sim_cache[i] = NULL;
    #ifdef __MMI_PHB_USIM_SUPPORT__
        if (g_srv_phb_usim_cache[i].sne)
        {
            srv_phb_mem_free(g_srv_phb_usim_cache[i].sne);
            g_srv_phb_usim_cache[i].sne = NULL;
        }
        for (j = 0; j < MMI_PHB_MAX_ANR_COUNT; j++)
        {
            if (g_srv_phb_usim_cache[i].anr[j])
            {
                srv_phb_mem_free(g_srv_phb_usim_cache[i].anr[j]);
                g_srv_phb_usim_cache[i].anr[j] = NULL;
            }
        }
        for (j = 0; j < MMI_PHB_MAX_EMAIL_COUNT; j++)
        {
            if (g_srv_phb_usim_cache[i].email[j])
            {
                srv_phb_mem_free(g_srv_phb_usim_cache[i].email[j]);
                g_srv_phb_usim_cache[i].email[j] = NULL;
            }
        }
        if (g_srv_phb_usim_cache[i].aas)
        {
            srv_phb_mem_free(g_srv_phb_usim_cache[i].aas);
            g_srv_phb_usim_cache[i].aas = NULL;
        }
    #endif /* __MMI_PHB_USIM_SUPPORT__ */
    }

    if (total_count)
    {
        g_srv_phb_sim_cache[i] = srv_phb_mem_malloc(total_count * sizeof(srv_phb_sim_cache_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(g_srv_phb_sim_cache[i], 0, total_count * sizeof(srv_phb_sim_cache_struct));
        g_srv_phb_sim_cntx[i].total_count = total_count;
        g_srv_phb_sim_cntx[i].used_count = 0;
        
    #ifdef __MMI_PHB_USIM_SUPPORT__
        for (j = 0; j < anr_occur; j++)
        {
            g_srv_phb_usim_cache[i].anr[j] =
                srv_phb_mem_malloc(total_count * sizeof(srv_phb_sim_anr_struct), SRV_PHB_MEMORY_TYPE_ADM);
            memset(g_srv_phb_usim_cache[i].anr[j], 0, total_count * sizeof(srv_phb_sim_anr_struct));
        }
        for (j = 0; j < email_occur; j++)
        {
            g_srv_phb_usim_cache[i].email[j] =
                srv_phb_mem_malloc(total_count * sizeof(srv_phb_sim_email_struct), SRV_PHB_MEMORY_TYPE_ADM);
            memset(g_srv_phb_usim_cache[i].email[j], 0, total_count * sizeof(srv_phb_sim_email_struct));
        }
        if (sne_occur)
        {
            g_srv_phb_usim_cache[i].sne =
                srv_phb_mem_malloc(total_count * sizeof(srv_phb_sim_sne_struct), SRV_PHB_MEMORY_TYPE_ADM);
            
            g_srv_phb_sim_cntx[i].sne_occur = 1;
        }
        g_srv_phb_usim_cache[i].grp = srv_phb_mem_malloc(total_count * sizeof(srv_phb_sim_grp_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(g_srv_phb_usim_cache[i].grp, 0, total_count * sizeof(srv_phb_sim_grp_struct));
        g_srv_phb_usim_cache[i].aas = srv_phb_mem_malloc(aas_total * sizeof(srv_phb_sim_aas_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(g_srv_phb_usim_cache[i].aas, 0, aas_total * sizeof(srv_phb_sim_aas_struct));
        g_srv_phb_usim_cache[i].gas = srv_phb_mem_malloc(gas_total * sizeof(srv_phb_sim_gas_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(g_srv_phb_usim_cache[i].gas, 0, gas_total * sizeof(srv_phb_sim_gas_struct));
        g_srv_phb_sim_cntx[i].anr_occur = anr_occur > MMI_PHB_MAX_ANR_COUNT ? MMI_PHB_MAX_ANR_COUNT : anr_occur;
        g_srv_phb_sim_cntx[i].email_occur = email_occur > MMI_PHB_MAX_EMAIL_COUNT ? MMI_PHB_MAX_EMAIL_COUNT : email_occur;;
        g_srv_phb_sim_cntx[i].aas_total = aas_total > MMI_PHB_FIELD_LABEL_COUNT ? MMI_PHB_FIELD_LABEL_COUNT : aas_total;
        g_srv_phb_sim_cntx[i].gas_total = gas_total > MMI_PHB_MAX_GAS_COUNT ? MMI_PHB_MAX_GAS_COUNT : gas_total;
    #endif /* __MMI_PHB_USIM_SUPPORT__ */
    }
    else
    {
        memset(&(g_srv_phb_sim_cntx[i]), 0, sizeof(srv_phb_sim_cntx_struct));
    }
    srv_phb_sse_delete_name_index_by_storage(srv_phb_get_storage_by_sim_id(info->sim_interface));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_startup_read_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sim_startup_read_finish(U8 sim_interface, U16 sim_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = sim_interface;
    phb_storage_enum storage = srv_phb_get_storage_by_sim_id(sim_interface);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_cntx[i].total_count = (sim_total > MMI_PHB_SIM_ENTRIES) ? MMI_PHB_SIM_ENTRIES : sim_total;
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SIM_STARTUP_READ_FINISH,
            storage, g_srv_phb_sim_cntx[i].used_count, g_srv_phb_sim_cntx[i].total_count);
#ifdef __MMI_PHB_USIM_SUPPORT__
    g_srv_phb_usim_init_cntx[i].init_index = 0;
    g_srv_phb_usim_init_cntx[i].return_func = srv_phb_init_usim_info;
    srv_phb_init_usim_info(i, storage);
#else
    srv_phb_datamgr_set_startup_ready(storage);
#endif /* __MMI_PHB_USIM_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sim_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_phb_sim_startup_read_ind, MSG_ID_MMI_PHB_STARTUP_READ_IND);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_get_sim_name(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PHB_SIM_CONVERT_ID(id, sim_id);
    return srv_phb_sim_get_name(sim_id, id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_get_sim_nick_name(mmi_phb_contact_id id)
{
#ifdef __MMI_PHB_USIM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PHB_SIM_CONVERT_ID(id, sim_id);
    return srv_phb_sim_get_nick_name(sim_id, id);
#else
    return NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_num_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_sim_num_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PHB_SIM_CONVERT_ID(id, sim_id);
    if (id >= g_srv_phb_sim_cntx[sim_id].total_count)
    {
        return 0;
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    return g_srv_phb_sim_cache[sim_id][id].number_count;
#else
    if (srv_phb_sim_get_field_mask(sim_id, id) & MMI_PHB_CONTACT_FIELD_NUMBER)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#endif
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_get_sim_number(mmi_phb_contact_id id, U8 save_index, U8* type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PHB_SIM_CONVERT_ID(id, sim_id);
    return srv_phb_sim_get_number(sim_id, id, save_index, type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_email_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_sim_email_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_SUPPORT__
    S32 i = 0;
    SRV_PHB_SIM_CONVERT_ID(id, i);
    if (id < g_srv_phb_sim_cntx[i].total_count)
    {
        return g_srv_phb_sim_cache[i][id].email_count;
    }
#endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_get_sim_email(mmi_phb_contact_id id, U8 save_index)
{
#ifdef __MMI_PHB_USIM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PHB_SIM_CONVERT_ID(id, sim_id);
    return srv_phb_sim_get_email(sim_id, id, save_index);
#else
    return NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_read_sim_contact(mmi_phb_contact_id id, srv_phb_contact contact, srv_phb_field_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    U32 contact_mask = srv_phb_get_sim_field_mask(id);
    U8 save_index = 0;
    CHAR* temp;
    U8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PHB_SIM_CONVERT_ID(id, sim_id);
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NAME) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_NAME))
    {
        WCHAR* name = srv_phb_sim_get_name(sim_id, id);
        if (name && name[0])
        {
            srv_phb_contact_set_fname(contact, name);
        }
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NICK) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_NICK))
    {
        WCHAR* name = srv_phb_sim_get_nick_name(sim_id, id);
        if (name && name[0])
        {
            srv_phb_contact_set_nick(contact, name);
        }
    }
#endif
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NUMBER) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_NUMBER))
    {
    #ifdef __MMI_PHB_USIM_SUPPORT__
        for (save_index = 0; save_index <= g_srv_phb_sim_cntx[sim_id].anr_occur; save_index++)
    #endif
        {
            temp = srv_phb_sim_get_number(sim_id, id, save_index, &type);
            if (temp && temp[0])
            {
                srv_phb_contact_add_asc_number(
                    contact,
                    (mmi_phb_contact_id)save_index,
                    save_index,
                    type,
                    temp,
                    srv_phb_sim_get_type_label(type, srv_phb_get_storage_by_sim_id(sim_id)),
                    save_index ? MMI_FALSE :MMI_TRUE);
            }
        }
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_EMAIL) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_EMAIL))
    {
        for (save_index = 0; save_index < g_srv_phb_sim_cntx[sim_id].email_occur; save_index++)
        {
            temp = srv_phb_sim_get_email(sim_id, id, save_index);
            if (temp && temp[0])
            {
                srv_phb_contact_add_asc_email(
                    contact,
                    (mmi_phb_contact_id)save_index,
                    save_index,
                    MMI_PHB_EMAIL_TYPE_NONE,
                    temp,
                    srv_phb_phone_get_type_label(MMI_PHB_EMAIL_TYPE_HOME, MMI_PHB_CONTACT_FIELD_ID_EMAIL));
            }
        }
    }
    
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_GROUP) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_GROUP))
    {
        U8 group_id;
        U16 mask;
        U32 i;
        srv_phb_group_struct group;
        U16 sim_group = srv_phb_sim_get_grp(sim_id, id);
        group.group_count = 0;
        for (i = 0; i < PHB_MAX_ASSOCIATE_GRP; i ++)
        {
            mask = 1 << i;
            if (sim_group & mask)
            {
                group_id = i + sim_id * PHB_MAX_ASSOCIATE_GRP + MMI_PHB_GROUP_COUNT;
                group.group_id[group.group_count] = group_id;
                group.group_count ++;
            }
        }
        if (group.group_count > 0)
        {
            srv_phb_contact_set_group(contact, &group);
        }
    }
#endif
}


#ifdef __MMI_PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_usim_field_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_usim_field_total(phb_storage_enum storage, U8 occr, phb_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = srv_phb_get_sim_id(storage);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case PHB_ANR:
            if (occr < g_srv_phb_sim_cntx[sim_id].anr_occur)
            {
                return g_srv_phb_sim_cntx[sim_id].anr_total[occr];
            }
            break;
            
        case PHB_EMAIL:
            if (occr < g_srv_phb_sim_cntx[sim_id].email_occur)
            {
                return g_srv_phb_sim_cntx[sim_id].email_total[occr];
            }
            break;

        case PHB_SNE:
            if (occr < g_srv_phb_sim_cntx[sim_id].sne_occur)
            {
                return g_srv_phb_sim_cntx[sim_id].sne_total;
            }
            break;

        case PHB_GAS:
            return g_srv_phb_sim_cntx[sim_id].gas_total;

        default:
            break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_usim_field_used
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_usim_field_used(phb_storage_enum storage, U8 occr, phb_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = srv_phb_get_sim_id(storage);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case PHB_ANR:
            if (occr < g_srv_phb_sim_cntx[sim_id].anr_occur)
            {
                return g_srv_phb_sim_cntx[sim_id].anr_used[occr];
            }
            break;
            
        case PHB_EMAIL:
            if (occr < g_srv_phb_sim_cntx[sim_id].email_occur)
            {
                return g_srv_phb_sim_cntx[sim_id].email_used[occr];
            }
            break;

        case PHB_SNE:
            if (occr < g_srv_phb_sim_cntx[sim_id].sne_occur)
            {
                return g_srv_phb_sim_cntx[sim_id].sne_used;
            }
            break;
        case PHB_GAS:
            return g_srv_phb_sim_cntx[sim_id].gas_used;

        default:
            break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_write_sim_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_init_sim_op_cntx(cntx->pos.storage);
    g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_ADN;
    g_srv_phb_sim_op_cntx.continue_func = srv_phb_write_sim_continue;
    return srv_phb_write_sim_continue();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_delete_sim_contact(srv_phb_contact_pos_struct* pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_init_sim_op_cntx(pos->storage);
    g_srv_phb_sim_op_cntx.continue_func = srv_phb_delete_sim_continue;
    srv_phb_delete_sim_continue();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_copy_sim_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_init_sim_op_cntx(cntx->pos.storage);
    g_srv_phb_sim_op_cntx.status = SRV_PHB_SIM_OP_ADN;
    g_srv_phb_sim_op_cntx.continue_func = srv_phb_copy_sim_contact_continue;
    return srv_phb_copy_sim_contact_continue();
}

#else /* __MMI_PHB_USIM_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_write_sim_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    srv_phb_iterator iterator = srv_phb_contact_get_number_iterator(cntx->contact);
    srv_phb_number_struct* temp;
    WCHAR* number = NULL;
    WCHAR* fname, *lname;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_reset_contact(cntx->contact, ~MMI_PHB_CONTACT_FIELD_SIM);
    while (iterator)
    {
        temp = srv_phb_contact_get_number_next(&iterator);
        if (temp)
        {
            if (number)
            {
                srv_phb_contact_remove_number(cntx->contact, temp);
            }
            else
            {
                number = temp->number;
                if (mmi_wcschr(number, L'w') || mmi_wcschr(number, L'W') || mmi_wcschr(number, L'?'))
                {
                    return MMI_FALSE;
                }
            }
        }
    }
    if (cntx->update_field & MMI_PHB_CONTACT_FIELD_NAME)
    {
        fname = srv_phb_contact_get_fname(cntx->contact);
        lname = srv_phb_contact_get_lname(cntx->contact);
    }
    else
    {
        if (cntx->pos.index != SRV_PHB_INVALID_INDEX)
        {
            fname = srv_phb_sim_get_name(srv_phb_get_sim_id((phb_storage_enum)cntx->pos.storage), (U16)(cntx->pos.index - 1));
        }
        else
        {
            fname = NULL;
        }
        lname = NULL;
    }
    g_srv_phb_sim_op_cntx.continue_func = srv_phb_datamgr_op_done;
    return srv_phb_set_sim_contact_req(
                    &(cntx->pos),
                    fname,
                    lname,
                    number);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_delete_sim_contact(srv_phb_contact_pos_struct* pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_del_entry_req_struct *my_msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_phb_del_entry_req_struct*) OslConstructDataPtr(sizeof(mmi_phb_del_entry_req_struct));

    my_msg_ptr->del_all = MMI_FALSE;
    my_msg_ptr->no_data = 1;
    my_msg_ptr->type = PHB_PHONEBOOK;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    my_msg_ptr->index = pos->index;
    my_msg_ptr->storage = pos->storage;
    SetProtocolEventHandler(srv_phb_delete_sim_contact_rsp, MSG_ID_MMI_PHB_DEL_ENTRY_RSP);
    mmi_frm_send_ilm((oslModuleType)srv_phb_get_l4c_mod_by_storage((phb_storage_enum)pos->storage), MSG_ID_MMI_PHB_DEL_ENTRY_REQ, (oslParaType*) my_msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_copy_sim_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_status_struct status;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_op_cntx.cur_index = 0;
    g_srv_phb_sim_op_cntx.finish_count = 0;
    g_srv_phb_sim_op_cntx.continue_func = srv_phb_copy_sim_contact_continue;
    g_srv_phb_sim_op_cntx.result = SRV_PHB_NO_ERROR;

    status.result = SRV_PHB_NO_ERROR;
    return srv_phb_copy_sim_contact_continue(&status);
}
#endif /* __MMI_PHB_USIM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_type_list
 * DESCRIPTION
 *  get type id list ordered by type name
 * PARAMETERS
 *  type_array         :   [OUT]   type id array
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           type count
 ****************************************************************************/
U8 srv_phb_sim_get_type_list(U8* type_array, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_SUPPORT__
    {
        U8 sim_id = srv_phb_get_sim_id(storage);
        U32 count = 0;
        S32 i;
        for (i = 0; i < g_srv_phb_sim_cntx[sim_id].aas_total; i++)
        {
            if (g_srv_phb_usim_cache[sim_id].aas[i].label[0])
            {
                type_array[count++] = (U8)(MMI_PHB_NUM_TYPE_USER_BASE + i);
            }
        }
        return count;
    }
#else
    return 0;
#endif /* __MMI_PHB_USIM_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_type_label
 * DESCRIPTION
 *  get a type label by id
 * PARAMETERS
 *  type_id            :   [IN]    type id
 *  field              :   [IN]    field
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
WCHAR* srv_phb_sim_get_type_label(U8 type_id, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type_id)
    {
        case MMI_PHB_NUM_TYPE_NONE:
            return NULL;
            
        case MMI_PHB_NUM_TYPE_MOBILE:
            return (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);

        default:
            break;
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    {
        U8 sim_id = srv_phb_get_sim_id(storage);
        type_id -= MMI_PHB_NUM_TYPE_USER_BASE;
        if (type_id > g_srv_phb_sim_cntx[sim_id].aas_total)
        {
            return NULL;
        }
        return g_srv_phb_usim_cache[sim_id].aas[type_id].label;
    }
#else
    return NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_type_max
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 ****************************************************************************/
U8 srv_phb_sim_get_type_max(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_SUPPORT__
    return g_srv_phb_sim_cntx[srv_phb_get_sim_id(storage)].aas_total;
#else
    return 0;
#endif
}

