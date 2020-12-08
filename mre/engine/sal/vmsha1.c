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
 * vmsha1.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * sha1
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

#include "vmswitch.h"

#ifdef __MRE_SAL_CHE_SHA1__

#include "che_api.h"
#include "string.h"
#include "vmsha1.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmlog.h"

static void vm_sha1_mod_init(void);
static void vm_sha1_mod_finalize(void);
static VMINT vm_sha1_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);
static void vm_sha1_release_callback(VM_P_HANDLE process_handle, VMINT sys_state);
static STCHE   *vm_get_cheinfo_from_processid(VM_P_HANDLE processid,VMINT * res_id);

VMINT _vm_reg_sha1_modual(void)
{
	int res_code = REG_MRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("sha1", (MOD_EVT_PROCESS)vm_sha1_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMSHA1_103 , res_code);
	}

	return res_code;
}

static VMINT vm_sha1_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_sha1_mod_init();
		break;
	case EVT_MOD_RELEASE:
		vm_sha1_mod_finalize();
		break;
	default:
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMSHA1_120 , event);
	}
	return REG_MRE_MODULE_SUCCESS;
}


void vm_sha1_release_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	//	MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMSHA1_128 ,process_handle,sys_state);

		switch (sys_state)
		{
			case VM_PMNG_UNLOAD:
				{
					VMINT i=0,sha1_ctx_size=0;
					STCHE   *sha1_ctx_p=NULL;

					while ( (i = vm_res_findfirst(process_handle, VM_RES_TYPE_SHA1)) != VM_RES_NOT_FIND)
					{
						vm_res_get_data(VM_RES_TYPE_SHA1,i,(void**)&sha1_ctx_p,&sha1_ctx_size);
						if (sha1_ctx_p)
						{
							vm_free(sha1_ctx_p);
							sha1_ctx_p=NULL;
						}
						//MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMSHA1_145 );	
						vm_res_release_data(VM_RES_TYPE_SHA1, i );
						vm_res_findclose(VM_RES_TYPE_SHA1);
					}
				}
				
				break;	
		}


}



static void vm_sha1_mod_init(void)
{	
	vm_res_type_set_notify_callback(VM_RES_TYPE_SHA1,vm_sha1_release_callback);
}

static void vm_sha1_mod_finalize(void)
{
}

static STCHE   *vm_get_cheinfo_from_processid(VM_P_HANDLE processid,VMINT * res_id)
{
	vm_res_node_t   vm_res_node;

	memset(&vm_res_node,0x00,sizeof(vm_res_node_t));
	if (vm_res_get_data_list_by_proecss(processid, VM_RES_TYPE_SHA1,&vm_res_node ,1)>0)
	{
		if (res_id)
		{
			*res_id=vm_res_node.res_id;
			MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMSHA1_178 ,*res_id);
		}
		return (STCHE  *)(vm_res_node.data_content);
	}
	return NULL;
	
}


void vm_sha1_reset( SHA1Context *context )
{
	VM_P_HANDLE processid=vm_pmng_get_current_handle();
	STCHE   *sha1_ctx_p=NULL;
	VMINT res_id;
	
	sha1_ctx_p=vm_get_cheinfo_from_processid(processid,&res_id);
	
	if (!sha1_ctx_p) 
	{
		//MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMSHA1_197 );
		if  ((sha1_ctx_p=(STCHE  *)vm_calloc(sizeof(STCHE)))==NULL)
		{
			MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMSHA1_200  );
			return;
		}
	} 
	che_init(sha1_ctx_p, CHE_SHA1);

	vm_res_save_data(VM_RES_TYPE_SHA1, (void*)(sha1_ctx_p),sizeof(STCHE), NULL,processid );
	
	memset(context->Message_Digest, 0x00, sizeof(context->Message_Digest));

}

VMINT vm_sha1_result( SHA1Context * context )
{ 
	STCHE   *sha1_ctx_p=NULL;
	VMINT res_id;
	
	sha1_ctx_p=vm_get_cheinfo_from_processid(vm_pmng_get_current_handle(),&res_id);

	if (sha1_ctx_p)
	{
		if (context)
		{
			che_process(sha1_ctx_p, CHE_SHA1, CHE_MODE_NULL, CHE_HASH, NULL, (VMUINT8*)context->Message_Digest,0, KAL_TRUE);
			che_deinit(sha1_ctx_p);
		} else
			MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMSHA1_226 );
		vm_free(sha1_ctx_p);
		sha1_ctx_p=NULL;

		vm_res_release_data(VM_RES_TYPE_SHA1,res_id);
		
	}	else
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMSHA1_234 );
		return 0;
	}
	
	return 1;
}
 

void vm_sha1_input( SHA1Context * context, VMUINT8 * message_array, VMUINT length )
{
	STCHE   *sha1_ctx_p=NULL;
	VMINT res_id;

	sha1_ctx_p=vm_get_cheinfo_from_processid(vm_pmng_get_current_handle(),&res_id);	
	
	if (sha1_ctx_p)
	{
		if (context && message_array )
		{
			che_process(sha1_ctx_p, CHE_SHA1, CHE_MODE_NULL, CHE_HASH, message_array, (VMUINT8*)context->Message_Digest, length, KAL_FALSE);
		} else
			MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMSHA1_255 );
	} else
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMSHA1_257 );

	
}

#endif

