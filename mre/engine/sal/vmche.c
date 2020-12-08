/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * vmche.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   mre che
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_SAL_CHE__
#include "kal_release.h"
#include "che_api.h"
#include "vmche.h"

typedef kal_bool (*vm_run_che_xxx_process_p)(STCHE *che_context,CHE_TYPE type, CHE_OPERATION_MODE mode,CHE_ACTION act,kal_uint8 *source,kal_uint8 *dest,kal_uint32 source_length,kal_bool last_block, STFSAL *pstFSAL);
typedef void (*vm_run_che_xxx_key_process_p)(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

vm_run_che_xxx_process_p vm_che_xxx_process[VM_CHE_TYPE_END] = {NULL,run_CHE_MD5_process,run_CHE_SHA1_process,run_CHE_DES_process,run_CHE_3DES_process,
	run_CHE_AES_process,run_CHE_MD4_process,run_CHE_MAC_MD5_process,run_CHE_MAC_SHA1_process,run_CHE_RC4_process,run_CHE_DES_process,
	run_CHE_DH_process,run_CHE_MAC_SHA224_process,run_CHE_MAC_SHA256_process,run_CHE_SHA224_process,run_CHE_SHA256_process};

vm_run_che_xxx_key_process_p vm_che_key_process[VM_CHE_ACTION_TYPE_END] = {run_CHE_GEN_KEY_process,run_CHE_SET_KEY_process,run_CHE_GET_KEY_process,
	            run_CHE_DEL_KEY_process,run_CHE_SET_RC4_KEY_process,run_CHE_SET_RSA_N_process,run_CHE_SET_RSA_E_process,run_CHE_SET_RSA_D_process,
	            run_CHE_SET_RSA_P_process,run_CHE_SET_RSA_Q_process,run_CHE_SET_RSA_dModPm1_process,run_CHE_SET_RSA_dModQm1_process,run_CHE_SET_RSA_qInvModP_process,
				run_CHE_SET_DH_P_process,run_CHE_SET_DH_G_process,run_CHE_SET_DH_SELF_PUBLIC_process,run_CHE_SET_DH_PEER_PUBLIC_process,run_CHE_SET_DH_PRIVATE_process,
				run_CHE_GET_DH_SELF_PUBLIC_LEN_process,run_CHE_GET_DH_PRIVATE_LEN_process,run_CHE_GET_DH_SECRET_LEN_process,run_CHE_GET_DH_SELF_PUBLIC_process,
				run_CHE_GET_DH_PRIVATE_process,run_CHE_GET_DH_SECRET_process,run_CHE_GET_RSA_N_process,run_CHE_GET_RSA_E_process,run_CHE_GET_RSA_D_process,
				run_CHE_GET_RSA_P_process,run_CHE_GET_RSA_Q_process,run_CHE_GET_RSA_dModPm1_process,run_CHE_GET_RSA_dModQm1_process,run_CHE_GET_RSA_qInvModP_process,
				run_CHE_GET_RSA_N_LEN_process,run_CHE_GET_RSA_E_LEN_process,run_CHE_GET_RSA_D_LEN_process,run_CHE_GET_RSA_P_LEN_process,run_CHE_GET_RSA_Q_LEN_process,
				run_CHE_GET_RSA_dModPm1_LEN_process,run_CHE_GET_RSA_dModQm1_LEN_process,run_CHE_GET_RSA_qInvModP_LEN_process};


static void vm_che_assign(STCHE* che_context, vm_stche *vm_che_context)
{
	che_context->cheLastLength = vm_che_context->cheLastLength;
    che_context->cheLastDstAddr = vm_che_context->cheLastDstAddr;
    che_context->cheWorkBuf = vm_che_context->cheWorkBuf;
    che_context->cheBufLen = vm_che_context->cheBufLen;
    che_context->cipher_type = vm_che_context->cipher_type;
    che_context->cheKey = vm_che_context->cheKey;
    che_context->cheIV = vm_che_context->cheIV;
    che_context->cheKeyLength = vm_che_context->cheKeyLength;
    che_context->cheIVLength = vm_che_context->cheIVLength;
    che_context->cheFirstFlag = (kal_bool)vm_che_context->cheFirstFlag;
}

void vm_che_init(vm_stche *che_context_p, VMUINT type)
{
	STCHE che_context;
	che_init(&che_context, type);
	
	che_context_p->cheLastLength = che_context.cheLastLength;
    che_context_p->cheLastDstAddr = che_context.cheLastDstAddr;
    che_context_p->cheWorkBuf = che_context.cheWorkBuf;
    che_context_p->cheBufLen = che_context.cheBufLen;
    che_context_p->cipher_type = che_context.cipher_type;
    che_context_p->cheKey = che_context.cheKey;
    che_context_p->cheIV = che_context.cheIV;
    che_context_p->cheKeyLength = che_context.cheKeyLength;
    che_context_p->cheIVLength = che_context.cheIVLength;
    che_context_p->cheFirstFlag = (kal_bool)che_context.cheFirstFlag;
	
}

void vm_che_deinit(vm_stche *che_context_p)
{
	STCHE che_context;
	
	vm_che_assign(&che_context, che_context_p);
	che_deinit(&che_context);
}

void vm_che_set_iv(vm_stche *che_context_p, VMUINT8 *iv, VMUINT iv_len)
{
	STCHE che_context;
	
	vm_che_assign(&che_context, che_context_p);
	che_set_iv(&che_context, iv, iv_len);
}


VMUINT8 vm_che_process(vm_stche *che_context_p,vm_che_type type,vm_che_operation_mode mode,
						vm_che_action act, VMUINT8 *source,VMUINT8 *dest,VMUINT source_length,VMUINT8 last_block)
{
	STCHE che_context;
	VMUINT8 ret = FALSE;
	vm_run_che_xxx_process_p xxx_process;

	if(type < 1 || type >= VM_CHE_TYPE_END)
		return ret;
	
	vm_che_assign(&che_context, che_context_p);
	
	xxx_process = vm_che_xxx_process[type];

	ret = xxx_process(&che_context,(CHE_TYPE)type,(CHE_OPERATION_MODE)mode,(CHE_ACTION)act,source,dest,source_length,(kal_bool)last_block,0);
	
	return ret;

}

void vm_che_key_action(vm_stche *che_context_p, vm_che_key_action_type type, VMUINT8 *key, VMINT key_len)
{
	STCHE che_context;
	vm_run_che_xxx_key_process_p xxx_key_process;
		
	if(type < 0 || type >= VM_CHE_ACTION_TYPE_END)
		return;
	
	vm_che_assign(&che_context, che_context_p);
	xxx_key_process = vm_che_key_process[type];
	xxx_key_process(&che_context,key,key_len);
}

VMINT vm_che_rsa_public_encrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding)
{
	STCHE che_context;
	
	vm_che_assign(&che_context, ctx);
	return che_rsa_public_encrypt(&che_context, src, src_len, dst, dst_len, (che_rsa_padding_mode_enum)padding);
}


VMINT vm_che_rsa_private_encrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding)
{
	STCHE che_context;
	
	vm_che_assign(&che_context, ctx);	
	return 	che_rsa_private_encrypt(&che_context, src, src_len, dst, dst_len, padding);
}
	
	
VMINT vm_che_rsa_public_decrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding)
{
	STCHE che_context;
	
	vm_che_assign(&che_context, ctx);	
	return che_rsa_public_decrypt(&che_context, src, src_len, dst, dst_len, (che_rsa_padding_mode_enum)padding);
}
	
	
VMINT vm_che_rsa_private_decrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding)
{
	STCHE che_context;
	
	vm_che_assign(&che_context, ctx);	
	return che_rsa_private_decrypt(&che_context, src, src_len, dst, dst_len, (che_rsa_padding_mode_enum)padding);
}

VMINT vm_get_che_sym(VMCHAR* func_name)
{
	return 0;
}

#endif

