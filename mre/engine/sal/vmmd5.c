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
 * vmmd5.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * md5
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "vmswitch.h"

#ifdef __MRE_SAL_CHE_MD5__

#include "che_api.h"
#include "vmmd5.h"
#include "vmsys.h"
#include "string.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmlog.h"


static void vm_md5_mod_init(void);
static void vm_md5_mod_finalize(void);
static VMINT vm_md5_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);
static void vm_md5_release_callback(VM_P_HANDLE process_handle, VMINT sys_state);
static STCHE   *vm_get_cheinfo_from_processid(VM_P_HANDLE processid,VMINT * res_id);

VMINT _vm_reg_md5_modual(void)
{
	int res_code = REG_MRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("MD5", (MOD_EVT_PROCESS)vm_md5_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMMD5_105 , res_code);
	}

	return res_code;
}

static VMINT vm_md5_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_md5_mod_init();
		break;
	case EVT_MOD_RELEASE:
		vm_md5_mod_finalize();
		break;
	default:
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMMD5_122 , event);
	}
	return REG_MRE_MODULE_SUCCESS;
}


static void vm_md5_release_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	switch (sys_state)
	{
		case VM_PMNG_UNLOAD:
		{
			VMINT i=0,md5_ctx_size=0;
			STCHE   *md5_ctx_p=NULL;

			while ( (i = vm_res_findfirst(process_handle, VM_RES_TYPE_MD5)) != VM_RES_NOT_FIND)
			{
				vm_res_get_data(VM_RES_TYPE_MD5,i,(void**)&md5_ctx_p,&md5_ctx_size);
				if (md5_ctx_p)
				{
					vm_free(md5_ctx_p);
					md5_ctx_p=NULL;
				}
				vm_res_release_data(VM_RES_TYPE_MD5, i );
				vm_res_findclose(VM_RES_TYPE_MD5);
			}

		}
		
		break;	
	}
}
 
static void vm_md5_mod_init(void)
{	
	vm_res_type_set_notify_callback(VM_RES_TYPE_MD5,vm_md5_release_callback);
}

static void vm_md5_mod_finalize(void)
{

}

static STCHE   *vm_get_cheinfo_from_processid(VM_P_HANDLE processid,VMINT * res_id)
{
	vm_res_node_t   vm_res_node;

	memset(&vm_res_node,0x00,sizeof(vm_res_node_t));
	if (vm_res_get_data_list_by_proecss(processid, VM_RES_TYPE_MD5,&vm_res_node ,1)>0)
	{
		if (res_id)
		{
			*res_id=vm_res_node.res_id;
		}
		return (STCHE  *)(vm_res_node.data_content);
	}
	return NULL;
}



void md5_init(md5_state_t *pms)
{
	VM_P_HANDLE processid=vm_pmng_get_current_handle();
	STCHE   *md5_ctx_p=NULL;
	VMINT res_id;

	md5_ctx_p=vm_get_cheinfo_from_processid(processid,&res_id);
	
	if (!md5_ctx_p )
	{
		if  ((md5_ctx_p=(STCHE  *)vm_calloc(sizeof(STCHE)))==NULL)
		{
			MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMMD5_218  );
			return;
		}
	}

	che_init(md5_ctx_p, CHE_MD5);

	vm_res_save_data(VM_RES_TYPE_MD5, (void*)(md5_ctx_p),sizeof(STCHE), NULL,processid );
}
 


void md5_append(md5_state_t *pms, const md5_byte_t *data, int nbytes)
{
	VMUINT8 data_out[16];
	STCHE   *md5_ctx_p=NULL;
	VMINT res_id;
	
	md5_ctx_p=vm_get_cheinfo_from_processid(vm_pmng_get_current_handle(),&res_id);	

	if (md5_ctx_p)
	{
		if (pms && data && (nbytes>=0))
		{
			che_process(md5_ctx_p, CHE_MD5, CHE_MODE_NULL, CHE_HASH, (VMUINT8*)data, data_out, nbytes,KAL_FALSE);
		} 
		else
		{	
			MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMMD5_247 );
		}
	} 
	else
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMMD5_250 );
	}
	
}



void md5_finish(md5_state_t *pms, md5_byte_t digest[16])
{
	STCHE   *md5_ctx_p=NULL;
	VMINT res_id;
	
	md5_ctx_p=vm_get_cheinfo_from_processid(vm_pmng_get_current_handle(),&res_id);
	
	if (md5_ctx_p)
	{
		if (pms && digest )
		{
			che_process(md5_ctx_p, CHE_MD5, CHE_MODE_NULL, CHE_HASH, NULL, digest, 0, KAL_TRUE);
			che_deinit(md5_ctx_p);
		} 
		else
		{
			MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMMD5_274 );
		}
		
		vm_free(md5_ctx_p);
		md5_ctx_p=NULL;

		vm_res_release_data(VM_RES_TYPE_MD5,res_id);
	}
	else
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMMD5_282 );	
	}
}
#endif


