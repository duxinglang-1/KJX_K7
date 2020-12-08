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
 * vmrsa.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * vmrsa
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

#ifdef __MRE_CORE_SAFETY__

#include "che_api.h"

#include "vmsys.h"
#include "vmrsa.h"
#include "vmcerter.h"
#include "vmcervar.h"


static STCHE   che_str;

static VMINT	rsa_encode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len );
static VMINT	rsa_decode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len );


VMINT vm_rsa_verify( VMUCHAR * signature, VMINT sign_len, VMPUBKey * pubkey, VMUCHAR * text, VMINT * text_len )
{
	VMINT		 res_code = 0;

	res_code = rsa_decode( signature, sign_len, (VMKey *)pubkey, text, text_len );

	return res_code;
}


VMINT vm_rsa_verify_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len )
{
	VMPUBKey	pub;
	switch( vm_ce_get_key( id, (VMKey *)&pub ) )
	{
		case VM_CE_GET_KEY_EXPIRED:
			return VM_CE_RSA_KEY_EXPIRED;
		case VM_CE_GET_KEY_OK:
			break;
		default:
			return VM_CE_RSA_GET_KEY_ERROR;
	}

	return vm_rsa_verify( signature, sign_len, (VMKey *)&pub, text, text_len );
}

VMINT vm_rsa_sign( VMUCHAR * signature, VMINT sign_len, VMPRIKey * prikey, VMUCHAR * text, VMINT * text_len, VMINT type )
{
	
	VMINT		res_code = 0;
	
	res_code=rsa_encode( signature, sign_len, (VMKey *)prikey, text, text_len );

	return res_code;

}


VMINT vm_rsa_sign_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len, VMINT type )
{
	VMPRIKey	pri;
	
	if( vm_ce_get_key( id, (VMKey *)&pri ) < 0 )
		return -1;

	return vm_rsa_sign( signature, sign_len, (VMKey *)&pri, text, text_len, type );	
}


static VMINT	rsa_encode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len )
{
	
	
	if( signature == NULL || sign_len == 0 || key == NULL )
		return -1;
		
	if( key->modlen == 0 || key->keylen == 0 )
		return -1;
		
	if( text == NULL || text_len == NULL )
		return -1;

	che_init(&che_str,CHE_RSA);
	che_key_action(&che_str, CHE_SET_RSA_N, key->mod, key->modlen);
   	che_key_action(&che_str, CHE_SET_RSA_E, key->key,key->keylen );//3
   	che_rsa_public_encrypt(&che_str, signature, sign_len, text, (VMUINT*)text_len, CHE_RSA_PKCS1_V15);
	
    	che_deinit(&che_str);	
	return 0;
	
}


static VMINT	rsa_decode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len )
{		

	if( signature == NULL || sign_len == 0 || key == NULL )
		return -1;
		
	if( key->modlen == 0 || key->keylen == 0 )
		return -1;
		
	if( text == NULL || text_len == NULL )
		return -1;

	che_init(&che_str,CHE_RSA);
	che_key_action(&che_str, CHE_SET_RSA_N, key->mod, key->modlen);
	
	che_key_action(&che_str, CHE_SET_RSA_E, key->key,key->keylen);
	che_rsa_public_decrypt(&che_str, signature, sign_len, text, (VMUINT*)text_len,CHE_RSA_PKCS1_V15 );

	che_deinit(&che_str);
		return 0;
}

VMINT vm_rsa_verify_by_id_ex( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len )
{
	
	VMINT		 res_code = 0;
	VMKey_Ex key;
	
	if( signature == NULL || sign_len == 0 )
		return -1;
		
		
	if( text == NULL || text_len == NULL )
		return -1;

	switch( vm_ce_get_key_ex( id, (VMKey_Ex*)&key ) )
	{
		case VM_CE_GET_KEY_EXPIRED:
			return VM_CE_RSA_KEY_EXPIRED;
		case VM_CE_GET_KEY_OK:
			break;
		default:
			return VM_CE_RSA_GET_KEY_ERROR;
	}

	if( key.modlen == 0 || key.keylen == 0 )
		return VM_CE_RSA_GET_KEY_ERROR;

	che_init(&che_str,CHE_RSA);
	che_key_action(&che_str, CHE_SET_RSA_N, key.mod, key.modlen);
	
	che_key_action(&che_str, CHE_SET_RSA_E, key.key,key.keylen);
	che_rsa_public_decrypt(&che_str, signature, sign_len, text, (VMUINT*)text_len,CHE_RSA_PKCS1_V15 );

	che_deinit(&che_str);

	return 0;
}

#endif

