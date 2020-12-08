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
 * vmcervar.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * cervar
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
 * removed!
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

#include "vmrsa.h"
#include "vmnvram.h"
#include "vmsys.h"
#include "vmcerter.h"

#include "vmlog.h"
#include "vmmem.h"

#include <string.h>


#define		FIRST_CERT_RECORD		(0)
#define		SECOND_CERT_RECORD	(1)
#define		MTK_CERT_RECORD	(2)
#define		MTK_CERT_RECORD_BAK	(3)


static  vm_nvram_root_pkey_list_t *		PubKeyStore;
static  vm_nvram_root_pkey_list_t *		PubKeyStore_bak;
static  vm_nvram_root_pkey_list_t*	PubKeyStore_mtk;
static  vm_nvram_root_pkey_list_t*	PubKeyStore_mtk_bak;

extern VMINT vm_nvram_get_ext_key(vm_pkey_ex_t* pkey);

VMINT	vm_ce_get_key( VMINT id, VMKey * key_buf )
{
    VMINT		i = 0;

    if( PubKeyStore == NULL || PubKeyStore_bak== NULL || PubKeyStore_mtk == NULL || PubKeyStore_mtk_bak == NULL || key_buf == NULL )
    {
        return VM_CE_GET_KEY_BAD_PARAM;
    }

    for( ; i<ROOT_PK_LIST_SIZE; i++ )
    {        
        if( PubKeyStore->pkey_item[i].pkey_index == id )
        {
			memcpy( key_buf, (VMKey *)(&PubKeyStore->pkey_item[i].pkey_content), sizeof(VMKey) );
			break;
        }
    }

    if( i == ROOT_PK_LIST_SIZE )
    {
        for( ; i<ROOT_PK_LIST_SIZE*2; i++ )
        {           
            if( PubKeyStore_bak->pkey_item[i-ROOT_PK_LIST_SIZE].pkey_index == id )
            {
                memcpy( key_buf, (VMKey *)(&PubKeyStore_bak->pkey_item[i-ROOT_PK_LIST_SIZE].pkey_content), sizeof(VMKey) );
                break;
            }
        }	
    }
    
    if( i == ROOT_PK_LIST_SIZE*2 )
	{
		for( ; i<ROOT_PK_LIST_SIZE*3; i++ )
		{		
			if( PubKeyStore_mtk->pkey_item[i-ROOT_PK_LIST_SIZE*2].pkey_index == id )
			{
				memcpy( key_buf, (VMKey *)(&PubKeyStore_mtk->pkey_item[i-ROOT_PK_LIST_SIZE*2].pkey_content), sizeof(VMKey) );
				break;
			}
		}	
	}


	if( i == ROOT_PK_LIST_SIZE*3 )
	{
		for( ; i<ROOT_PK_LIST_SIZE*4; i++ )
		{			
			if( PubKeyStore_mtk_bak->pkey_item[i-ROOT_PK_LIST_SIZE*3].pkey_index == id )
			{
				memcpy( key_buf, (VMKey *)(&PubKeyStore_mtk_bak->pkey_item[i-ROOT_PK_LIST_SIZE*3].pkey_content), sizeof(VMKey) );
				break;
			}
		}	
	}

	
    if( i == ROOT_PK_LIST_SIZE*4 )
        return VM_CE_GET_KEY_NOT_FOUND;

    return VM_CE_GET_KEY_OK;
}


VMINT	vm_ce_get_key_ex( VMINT id, VMKey_Ex* key_buf )
{
	vm_pkey_ex_t pkey;

	vm_nvram_get_ext_key(&pkey);

	if( pkey.pkey_index == id )
	{
		memcpy( key_buf, (VMKey_Ex *)(&pkey.pkey_content), sizeof(VMKey_Ex) );
	}

	return VM_CE_GET_KEY_OK;
	
}

void vm_ce_unload_var( void )
{
    if( PubKeyStore )
    {
        _vm_kernel_free( PubKeyStore );
        PubKeyStore = NULL;
    }

	PubKeyStore_bak= NULL;
    PubKeyStore_mtk = NULL;
    PubKeyStore_mtk_bak = NULL;
}

VMINT	vm_ce_load_var( void )
{
    if( PubKeyStore || PubKeyStore_bak || PubKeyStore_mtk || PubKeyStore_mtk_bak)
    {
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERVAR, TRC_MRE_VMCERVAR_01);
    	return VM_CE_LOAD_VAR_IN_USE;
    }

    PubKeyStore = (vm_nvram_root_pkey_list_t *)_vm_kernel_malloc( sizeof(vm_nvram_root_pkey_list_t) * 4 );

	if( PubKeyStore == NULL )
    {
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERVAR, TRC_MRE_VMCERVAR_02);
    	return VM_CE_LOAD_VAR_MEM_ERROR;
	}
	else
	{
		PubKeyStore_bak = &PubKeyStore[1];
		PubKeyStore_mtk = &PubKeyStore[2];
		PubKeyStore_mtk_bak = &PubKeyStore[3];
	}
	
    if( (vm_nvram_get_pkey_list( FIRST_CERT_RECORD, PubKeyStore ) == FALSE) || 
        (vm_nvram_get_pkey_list( SECOND_CERT_RECORD, PubKeyStore_bak) == FALSE)  ||
        (vm_nvram_get_pkey_list( MTK_CERT_RECORD, PubKeyStore_mtk) == FALSE) ||
        (vm_nvram_get_pkey_list( MTK_CERT_RECORD_BAK, PubKeyStore_mtk_bak) == FALSE) )
    {
		vm_ce_unload_var();
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERVAR, TRC_MRE_VMCERVAR_03);
        return VM_CE_LOAD_VAR_KEY_ERROR;
    }

	if(vm_nvram_adjust_pkey_list(PubKeyStore_mtk, PubKeyStore_mtk_bak) == FALSE)
	{
		vm_ce_unload_var();
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERVAR, TRC_MRE_VMCERVAR_04);
        return VM_CE_LOAD_VAR_KEY_ERROR;
	}

    return VM_CE_LOAD_VAR_OK;
}

#endif

