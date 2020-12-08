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
 * Vmsim.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *Jia Luo (mtk80935)
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "vmswitch.h"
#ifdef __MRE_SAL_SIM__
#include "MMIDataType.h"
#include "Cbm_api.h"
#include "SimCtrlSrvGprot.h"

#include "vmopt.h"
#include "vmsys.h"
#include "vmsim.h"
#include "vmlog.h"
#include "vmpromng.h"

#include "vmenv.h"
#include "ModeSwitchSrvGProt.h"
#include "ImeiSrvGprot.h"

#include "sim_public_enum.h"
#include "simaccesssrvgprot.h"
#include "DtcntSrvGprot.h"

typedef struct
{
    VM_P_HANDLE             pHandle;
    vm_sim_get_iccid_cb     callback;
    VMCHAR*                 iccid;
    VMINT                   buff_len;
    void*                   user_data;
}vm_sim_get_iccid_data;

#define VM_SIM_IS_SINGE_SIM_MODE(mod) !(mod&(mod-1))&&mod


#define	VM_MODE_ALL_OFF     0x00;                         /* All SIMs are turn off */
#define VM_MODE_SIM1        0x01;                         /* SIM1 only */
#define VM_MODE_SIM2        0x02;                         /* SIM2 only */
#define VM_MODE_SIM3        0x04;                         /* SIM3 only */
#define VM_MODE_SIM4        0x08;                         /* SIM4 only */

static VMCHAR vm_imsi_number[20] = {0};
static VMCHAR vm_imei_number[20] = {0};

static mmi_sim_enum g_vm_active_sim_card = MMI_SIM1;

static VMINT vm_sim_srv_sim_to_int(mmi_sim_enum sim_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT sim = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    while (sim_enum != 0)
    {
        sim_enum = sim_enum >> 1;
        sim++;
    }   
    return sim;
}


VMINT vm_sim_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    return (VMINT)srv_mode_switch_get_current_mode();
}

VMBOOL vm_is_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!srv_mode_switch_is_network_service_available())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

VMSTR vm_get_imei_ext(VMINT sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sim <= 0 || sim > MMI_SIM_TOTAL)
    {
        return NULL;
    }
    
	if (srv_imei_get_imei((mmi_sim_enum)(1<<(sim-1)),vm_imei_number,sizeof(vm_imei_number)))
	{
	    return vm_imei_number;
	}
	memset(vm_imei_number,0,sizeof(vm_imei_number));
	return vm_imei_number;
}


VMSTR vm_get_imei(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    return vm_get_imei_ext(vm_sim_srv_sim_to_int(g_vm_active_sim_card));
}

VMSTR vm_get_imsi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if (srv_sim_ctrl_get_imsi(g_vm_active_sim_card,vm_imsi_number,sizeof(vm_imsi_number)))
    {
        return vm_imsi_number;
    }
    memset(vm_imsi_number,0,sizeof(vm_imsi_number));
    return vm_imsi_number;
}


static VMUINT vm_get_encode_data_accound_id(VMUINT  account_id,VMUINT sim_src, VMUINT8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMUINT result = account_id;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__	
    if (sim_src <= (VMUINT)CBM_SIM_ID_SIM1 ||sim_src > (VMUINT)CBM_SIM_ID_TOTAL)
    {
        sim_src = 1;
    }
	result = cbm_encode_data_account_id(account_id, (cbm_sim_id_enum)(sim_src-1), app_id, (kal_bool)0);
#endif	
	return result;
}

VMUINT vm_get_account_id(VMUINT account_id, VMUINT8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT mode;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode = vm_sim_get_mode();
	if (VM_SIM_IS_SINGE_SIM_MODE(mode))
	{
	    sim = (mmi_sim_enum)mode;
	    MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][SIM]singe mode sim = %d",sim);
	    return vm_get_encode_data_accound_id(account_id, vm_sim_srv_sim_to_int(sim), app_id);
	}
	else
	{
	    srv_dtcnt_sim_type_enum dtcnt_sim;
	    srv_dtcnt_get_sim_preference(&dtcnt_sim);
        if (!(mode & (1<<(dtcnt_sim-1))))
        {
            VMINT i;
            for (i = 1; i <= MMI_SIM_TOTAL; i++)
            {
                if (mode & (1<<(i-1)))
                {
                    dtcnt_sim = (srv_dtcnt_sim_type_enum)i;;
                }
            }
        }
        MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G9,"[MRE][SIM]sim = %d",dtcnt_sim);
	    return vm_get_encode_data_accound_id(account_id, (VMUINT)dtcnt_sim, app_id);
	}

	
}

void _vm_init_sim_card_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT sim_idx = VM_SIM_SIM1;
	VMINT mode,i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if (vm_has_sim_card() == FALSE)
	{
		return;
	}

    mode = vm_sim_get_mode();
	if (VM_SIM_IS_SINGE_SIM_MODE(mode))
	{
	    g_vm_active_sim_card = (mmi_sim_enum)mode;
	    return;
	}

    for (i = 1; i <= MMI_SIM_TOTAL; i++)
    {
        if (vm_set_active_sim_card(i))
        {
            return;
        }
    }
}



VMINT vm_query_operator_code(VMCHAR* buffer, VMUINT buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMCHAR ghnum[SRV_MAX_PLMN_LEN + 1];
    VMINT mode;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (buffer == NULL || buffer_size == 0)
		return -1;

	if (vm_has_sim_card() == FALSE)
	{
		return -2;
	}

    mode = vm_sim_get_mode();
	if (VM_SIM_IS_SINGE_SIM_MODE(mode))
	{
	    sim = (mmi_sim_enum)mode;
	}
	else
	{
	    sim = g_vm_active_sim_card;
	}

	memset(ghnum, 0x00, SRV_MAX_PLMN_LEN + 1);
	if (!srv_sim_ctrl_get_home_plmn(sim, (S8 * )ghnum, SRV_MAX_PLMN_LEN + 1))
	{
	    return NO_SIM_CARD;
	}
    strncpy(buffer, ghnum, buffer_size);
	return 0;

}

operator_t vm_get_operator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT mode;
    mmi_sim_enum sim;
    srv_sim_ctrl_op_enum op;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if (vm_has_sim_card() == FALSE)
	{
		return NO_SIM_CARD;
	}

    mode = vm_sim_get_mode();
	if (VM_SIM_IS_SINGE_SIM_MODE(mode))
	{
	    sim = (mmi_sim_enum)mode;
	}
	else
	{
	    sim = g_vm_active_sim_card;
	}
	
	op = srv_sim_ctrl_get_op(sim);
	if (SRV_SIM_CTRL_OP_CMCC == op)
	{
	    return CMCC;
	}
	else if (SRV_SIM_CTRL_OP_CU == op)
	{
	    return UNICOM;
	}
	return UNKOWN_OPERATOR;
}

VMINT vm_sim_card_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT i,ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vm_is_flight_mode())
	{
		vm_log_error("vm_sim_card_count: flight mode");
		return 99;  
	}

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sim_ctrl_is_available((mmi_sim_enum)(1<<i)))
        {
            ret++;
        }
    }
    
	return ret;
}

VMBOOL vm_set_active_sim_card(VMINT sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT mode;
    mmi_sim_enum sim_enum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if (sim <= 0 || sim > MMI_SIM_TOTAL)
	{
	    return FALSE;
	}
	
    sim_enum = (mmi_sim_enum)(1<<(sim-1));
	if(srv_sim_ctrl_is_available(sim_enum))
	{
		g_vm_active_sim_card = sim_enum;
		return TRUE;
	}
	return FALSE;
}

vm_sim_state_t vm_get_sim_card_status(VMINT sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim <= 0 || sim > MMI_SIM_TOTAL)
	{
	    return VM_SIM_STATE_VACANT;
	}
	
	if (srv_sim_ctrl_is_available((mmi_sim_enum)(1<<(sim-1))))
	{
	    return VM_SIM_STATE_WORKING;
	}
	return VM_SIM_STATE_VACANT;
}


VMINT vm_sim_get_iccid_callback(srv_sim_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;   
    srv_sim_cb_struct* sim_cb_struct = callback_data;
    srv_sim_data_struct* sim_data = (srv_sim_data_struct*)sim_cb_struct->data;
    vm_sim_get_iccid_data* get_iccid_data = (vm_sim_get_iccid_data*)sim_cb_struct->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_iccid_data->callback && VM_PMNG_UNLOAD != vm_pmng_state(get_iccid_data->pHandle))
    {
        memset(get_iccid_data->iccid,0,21);

        if (sim_cb_struct->result)
        {
            VMCHAR* tmp = sim_data->data;
            for (i = 0; i < 10; i++)
            {            
                get_iccid_data->iccid[2*i] = (tmp[i]&0x0f) + 0x30;
                get_iccid_data->iccid[2*i+1] = ((tmp[i]>>4 )&0x0f) + 0x30;
            }
        }
        
        vm_pmng_set_ctx(get_iccid_data->pHandle);
        get_iccid_data->callback(get_iccid_data->iccid,get_iccid_data->user_data);
        vm_free(get_iccid_data);
        vm_pmng_reset_ctx();        
    }        
    return 0;
}


VMINT vm_sim_get_iccid(VMINT sim, vm_sim_get_iccid_cb callback, VMCHAR* iccid, VMINT buff_len, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_sim_get_iccid_data* data ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!callback || !iccid || sim <= 0 || sim > MMI_SIM_TOTAL)
    {
        return -2;
    }
    
    if (buff_len < 21)
    {
        return -3;
    }
    
    data = (vm_sim_get_iccid_data*)vm_malloc(sizeof(vm_sim_get_iccid_data));
    if (!data)
    {
        return -4;
    }
    
    data->pHandle = vm_pmng_get_current_handle();
    data->callback = callback;
    data->iccid = iccid;
    data->buff_len = buff_len;
    data->user_data = user_data;
    
    if (!srv_sim_read_record(FILE_ICCID_IDX,NULL,0,10,(mmi_sim_enum)(1<<(sim-1)),vm_sim_get_iccid_callback,(void*)data))
    {
        return -5;
    }
    return 0;
}



VMBOOL vm_has_sim_card(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return srv_sim_ctrl_get_one_available_sim()?VM_TRUE:VM_FALSE;
}

VMINT vm_sim_get_active_sim_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_sim_srv_sim_to_int(g_vm_active_sim_card);
}


VMINT vm_sim_max_card_count(void)
{
    return MMI_SIM_TOTAL;
}

/*for compatible*/
VMINT vm_is_card2Absent(void)
{
#if (MMI_SIM_TOTAL >= 2)
    return srv_sim_ctrl_is_available(MMI_SIM2)?0:1;
#else
    return 1;
#endif    
}

VMINT vm_is_card1Absent(void)
{
    return srv_sim_ctrl_is_available(MMI_SIM1)?0:1;
}
/*for compatible*/

VMINT vm_sim_get_prefer_sim_card(void)
{
    srv_dtcnt_sim_type_enum type=SRV_DTCNT_SIM_TYPE_NONE;
    srv_dtcnt_get_sim_preference(&type);
    return (VMINT)type;
}

VMINT vm_get_sim_sym(VMCHAR* func_name)
{
	return 0;
}

#endif //__MRE_SAL_SMS__
