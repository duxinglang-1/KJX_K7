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
 * vmdes.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * des
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

#ifdef __MRE_SAL_CHE_DES__

#include "che_api.h"
#include "string.h"
#include "vmsys.h"
#include "vmdes.h"
#include "vmmem.h"
#include "vmlog.h"

#define		DES_CTX_MAX		2


typedef struct _DES_CONTEXT_t{
		STCHE  		 che_str;
		VMUCHAR			key[8];
} DES_CONTEXT;

DES_CONTEXT *		g_des_ctx[DES_CTX_MAX];

static VMINT	SearchForSlot( DES_CONTEXT ** pPoints, VMINT max );

VMDESHANDLE vm_des_set_key( VMUINT8 key[8] )
{
	VMINT		iSlot;

	if( key == NULL )
	{
		return DES_INVALID_HANDLE;
	}
	iSlot = SearchForSlot( g_des_ctx, DES_CTX_MAX );

	
	if( iSlot < 0 )
		return DES_INVALID_HANDLE;

	g_des_ctx[iSlot] = (DES_CONTEXT *)_vm_kernel_calloc( sizeof(DES_CONTEXT) );
	
	if( g_des_ctx[iSlot] )
	{
		memcpy( &(g_des_ctx[iSlot]->key), key, 8 );

		che_init(&(g_des_ctx[iSlot]->che_str), CHE_DES);
		che_set_iv(&(g_des_ctx[iSlot]->che_str), g_des_ctx[iSlot]->key, 8);

		che_key_action(&(g_des_ctx[iSlot]->che_str), CHE_SET_KEY, g_des_ctx[iSlot]->key, 8);
		return iSlot;
	}
	else
	{
		return -1;
	}
}

VMUINT8 * vm_des_encrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len )
{
	VMUINT8 * output = NULL,*temp_input=NULL;

	if( input == NULL || output_len == NULL || input_len == 0 )
		return NULL;

	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return NULL;

	output = (VMUINT8 *)vm_calloc( (input_len/8 + 2) * 8 );

	if( output == NULL )
	{
		return NULL;
	}


	if (((VMUINT)input)&3)
	{
		temp_input = (VMUINT8 *)vm_calloc(input_len );
		
		if( temp_input == NULL )
		{
			MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDES_152 );
			return NULL;
		}
		memcpy(temp_input,input,input_len);
	}
	else
	{
		temp_input=input;	
	}
	
	che_process(&(g_des_ctx[handle]->che_str), CHE_DES,  CHE_CBC, CHE_ENC, temp_input, output, input_len, KAL_TRUE);
	
	*output_len = (input_len/8 + 1) * 8;

	if  ((((VMUINT)input)&3) && (temp_input))
	{
		vm_free(temp_input);
		temp_input=NULL;
	}
	
	return output;
}

VMUINT8 * vm_des_decrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len )
{
	VMUINT8 * output = NULL;

	if( input == NULL || output_len == NULL || input_len == 0 )
		return NULL;

	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return NULL;

	output = (VMUINT8 *)vm_calloc( (input_len/8 + 2) * 8 );
	if( output == NULL )
	{
		MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDES_183 );
		return NULL;
	}

	che_process(&(g_des_ctx[handle]->che_str), CHE_DES,  CHE_CBC/*CHE_ECB*/, CHE_DEC, input, output, input_len, KAL_TRUE);


	{
		VMUCHAR		pad[8], padch = *(output+input_len-1);

		memset( pad, padch, 8 );
		
		if( !memcmp( output+input_len-(VMINT)padch, pad, (VMINT)padch ) )
			{
				MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDES_198 );
				*output_len = input_len-(VMINT)padch;

			}	
		else
		{
			MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDES_204 );
			vm_free( output );

			return NULL;
		}
	}

	return output;
}

VMINT vm_des_reset_key( VMDESHANDLE handle )
{
	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return DES_INVALID_HANDLE;

	che_deinit(&(g_des_ctx[handle]->che_str));	
	

	_vm_kernel_free(g_des_ctx[handle]);
	g_des_ctx[handle] = NULL;


	return DES_OK;
}

static VMINT	SearchForSlot( DES_CONTEXT ** pPoints, VMINT max )
{
	VMINT		i = 0;

	for( ; i<max; i++ )
	{
		if( pPoints[i] == NULL )
			return i;
	}
	return -1;
}



#endif

