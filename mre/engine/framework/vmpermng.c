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
 * vmpermng.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * permng
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
#include "vmsys.h"
#include "vmlog.h"

#include "vmnvram.h"

#include "vmperdef.h"
#include "vmpervar.h"
#include "vmcerter.h"
#include "vmcert.h"
#include "vmfilere.h"
#include "vmmem.h"
#include "vmgettag.h"
#include "vmpermng.h"
#include <string.h>


#define	PER_BUF_DEFAULT_LEN		(PER_TOTAL-PER_BASE+2)

extern const VMINT 	FuncList[TOTAL_COUNTER];
extern const VMINT 	HashList[TOTAL_COUNTER];
extern const VMINT	SecList[PER_TOTAL-PER_BASE+1];

extern const VMINT	SysFileFuncList[PERFILE_COUNTER];

extern VMINT	cur_file_sys_per;

static VMINT *	mrefun_list = NULL;

static VMINT mrefunlist_loaded = FALSE;

static VMINT	MatchInList( VMINT hash, const VMINT * hashlist, VMINT list_max );

static VMINT	merge_permission(vm_permission_t * app_permission_list, 
							   VMINT app_permission_list_len, 
							   VMINT app_permission_flags[PER_BUF_DEFAULT_LEN] );


VMINT	vm_per_hash( VMCHAR * src );

static VMINT	CheckValildAppPer( VMINT app_per_len );


VMINT * _vm_per_get_mre_fun_list(void)
{
	if (mrefunlist_loaded)
		return mrefun_list;
	else 
		return NULL;
}


void _vm_per_clear_mre_fun_list(void)
{
	if (mrefun_list != NULL)
		mrefun_list = NULL;
}

void _vm_per_free_mre_fun_list(VMINT * fun_list)
{
	if (fun_list != NULL)
	{
		_vm_kernel_free(fun_list);
	}
}


VMINT vm_per_init( void )
{

    mrefun_list = (VMINT *)_vm_kernel_malloc( sizeof(VMINT) * (TOTAL_COUNTER - FUNCSRC_COUNTER) );

	if( mrefun_list == NULL )
		return PER_OP_FAIL;

    memset( mrefun_list, 0x00, sizeof(VMINT) * (TOTAL_COUNTER - FUNCSRC_COUNTER) );
	mrefunlist_loaded = FALSE;

	return PER_OP_OK;
}

VMINT vm_per_finalize( void )
{

	if( mrefun_list == NULL )
		return PER_OP_FAIL;

    memset( mrefun_list, 0x00, sizeof(VMINT) * (TOTAL_COUNTER - FUNCSRC_COUNTER) );
	_vm_kernel_free( mrefun_list );
	
	mrefun_list = NULL;	
	mrefunlist_loaded = FALSE;
		
	return PER_OP_OK;
}

static VMINT MatchInList( VMINT hash, const VMINT * hashlist, VMINT list_max )
{
	VMINT	iMax = list_max - 1, iMin = 0;

	if( hash<hashlist[iMin] || hash>hashlist[iMax] )
		return -1;
	
	do{
		if( hash > hashlist[iMin+(iMax-iMin)/2] )
			iMin = iMin+(iMax-iMin)/2;
		else
			iMax = iMin+(iMax-iMin)/2;

	}while( (iMax-iMin)>1 );

	if( hash == hashlist[iMax] )
	{
		return iMax;
	}
	else if( hash == hashlist[iMin] )
	{
		return iMin;
	}
	else
	{
		return -1;
	}
}

VMINT	vm_per_hash( VMCHAR * src )
{	
	VMUINT 		h, v;
	VMCHAR *	p; 

	for(h=0, p = (VMCHAR *)src; *p ; p++)
	{
		h = 5527 * h + 7 *(*p);
		v = h & 0x0000ffff;
		h ^= v*v;
	}

	return h;
}

VMINT vm_per_get_fun_prt(VMINT* fun_list,  VMCHAR* func_name )
{
	VMINT		resid = -1;
	VMINT		iStart, iEnd, i;
	VMINT		hashvalue = 0;

	if( func_name == NULL )
	{
		return 0;
	}
	
	if( fun_list )
	{
		hashvalue = vm_per_hash( func_name );
        for (iStart = 0, i = 0; i < PER_TOTAL-PER_BASE+1; i++)
		{
			iEnd = SecList[i];
            resid = MatchInList( hashvalue, HashList+iStart, iEnd-iStart );
			if( resid >= 0 )
				break;

			iStart = iEnd;
		}
	}

    if (resid < 0) 
        return NULL;
	
    resid += iStart;
    ASSERT(resid < TOTAL_COUNTER);
    if (resid < FUNCSRC_COUNTER)
        return FuncList[resid];
    else
        return fun_list[resid - FUNCSRC_COUNTER];
}


VMINT vm_ce_merge_permission(VMWSTR filename)
{
	VMINT* app_per_list = NULL, app_per_list_len = 0;	
	
	if( vm_per_init( ) != 0 )
	{	
		MMI_TRACE(MMI_MRE_TRC_MOD_VMPERMNG, TRC_MRE_VMPERMNG_01);
		return VM_PER_INIT_ERROR;
	}

#ifdef 	__MRE_CORE_SANDBOX__

	vm_get_vm_tag(filename, VM_CE_INFO_PERMISSION, NULL, &app_per_list_len);

	app_per_list = (VMINT *)_vm_kernel_malloc( app_per_list_len + 4 );

	if( app_per_list == NULL )
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMPERMNG, TRC_MRE_VMPERMNG_02);
		return VM_PER_MEM_ERROR;
	}
			
	memset( (VMUCHAR *)app_per_list, 0x00, app_per_list_len + 4 );

	vm_get_vm_tag(filename, VM_CE_INFO_PERMISSION, app_per_list, &app_per_list_len);
		
	if( vm_per_catch_fun_list( app_per_list, app_per_list_len ) != 0 )
	{
		if( app_per_list != NULL )
			_vm_kernel_free( app_per_list );	
				
		MMI_TRACE(MMI_MRE_TRC_MOD_VMPERMNG, TRC_MRE_VMPERMNG_03);
		return VM_PER_CATCH_ERROR;
	}	

	if( app_per_list != NULL )
		_vm_kernel_free( app_per_list );
	
#else
	{
		VMINT i = 0;

        for( i=FUNCSRC_COUNTER; i<TOTAL_COUNTER; i++ )
		{
			if((i>=FILE_START_COUNTER) && (i<HTTP_START_COUNTER))
			{
                mrefun_list[i-FUNCSRC_COUNTER] = SysFileFuncList[i-FILE_START_COUNTER];
		    }
		    else
		    {	
			    mrefun_list[i-FUNCSRC_COUNTER] = FuncList[i];
			}
		}
	}
	mrefunlist_loaded = TRUE;
	cur_file_sys_per = VM_PERMISSION_SYS_DRV;
#endif
	return VM_CE_CHECK_PARAM_OK;

}



#ifdef __MRE_CORE_SANDBOX__
static VMINT vm_per_catch_fun_list( VMINT * app_per, VMINT app_per_len )
{
    VMINT		i, app_per_num = 0;
    VMINT		mixed_per[PER_BUF_DEFAULT_LEN];
	
	app_per_num = CheckValildAppPer( app_per_len );

    memset( mixed_per, 0x00, sizeof(mixed_per) );

	if( app_per_num )
	{
        if( merge_permission( (vm_permission_t *)app_per, app_per_num, mixed_per ) < 0 )
			return PER_MERGE_ERROR;
	}
	
	for( i=PER_BASE; i<PER_TOTAL; i++ )
	{
        VMINT from = SecList[i-PER_BASE];
        VMINT to   = SecList[i-PER_BASE+1];
        VMINT j;

        if (mixed_per[i-PER_BASE])
        {
            for (j = from; j < to; j++)
            {
                mrefun_list[j-FUNCSRC_COUNTER] = FuncList[j];
            }
        }
		
		if( i == PER_FILE )
		{

            if( mixed_per[i-PER_BASE] == 0)
			{
				cur_file_sys_per = VM_PERMISSION_USR_DRV;

                for (j = from; j < to; j++)
				{
                    mrefun_list[j-FUNCSRC_COUNTER] = FuncList[j];
				}				
			}
			else
			{	
				cur_file_sys_per = VM_PERMISSION_SYS_DRV;
				
                for (j = from; j < to; j++)
				{
                    mrefun_list[j-FUNCSRC_COUNTER] = SysFileFuncList[j-from];
				}
			}
		}
        else if( i == PER_SMS_SP && mixed_per[i-PER_BASE] )
		{
            for ( j=0; j<PERSMSPER_COUNTER; j++)
			{
                mrefun_list[(from-PERSMSPER_COUNTER)+j-FUNCSRC_COUNTER] = mrefun_list[from+j-FUNCSRC_COUNTER];
			}
		}
		
	}
	
	mrefunlist_loaded = TRUE;

	return PER_OP_OK;
}


static VMINT	CheckValildAppPer( VMINT app_per_len )
{
	if( app_per_len % sizeof(vm_permission_t) )
		return PER_OP_FAIL;

	return app_per_len / sizeof(vm_permission_t);
}

static VMINT merge_permission(
                vm_permission_t *app_permission_list,
                VMINT app_permission_list_len,
                VMINT app_permission_flags[PER_BUF_DEFAULT_LEN])
{
    VMINT i = 0; 
	vm_nvram_permission_list_t *	sym_permission_list; 

	sym_permission_list = (vm_nvram_permission_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_permission_list_t));

	if( sym_permission_list == NULL )
		return PER_OP_FAIL;

	memset(sym_permission_list, 0x00, sizeof(vm_nvram_permission_list_t));	
	
	vm_nvram_get_sym_permission(sym_permission_list);
	
	if( sym_permission_list->vm_sym_permission_list_len == 0 )
	{		
		_vm_kernel_free( sym_permission_list );
		return PER_OP_FAIL;
	}
	
	for( i=0; i<app_permission_list_len; i++ )
	{
		VMINT	id = app_permission_list[i].operate_index - PER_BASE;
		
		if( id<0 || id>=PER_BUF_DEFAULT_LEN )
		{
			_vm_kernel_free( sym_permission_list );
			return PER_OP_FAIL;
		}

		app_permission_flags[id] = app_permission_list[i].permission;
	}

	for( i=0; i<sym_permission_list->vm_sym_permission_list_len; i++ )
	{
		VMINT	id = sym_permission_list->vm_sym_permission_list[i].operate_index - PER_BASE;

		if( id<0 || id>=PER_BUF_DEFAULT_LEN )
		{
			_vm_kernel_free( sym_permission_list );
			
			if( id >= PER_BUF_DEFAULT_LEN )
				return PER_OP_OK;
							
			return PER_OP_FAIL;
		}
		
		if( id == (PER_SYSSTORAGE-PER_BASE) )
		{
			app_permission_flags[id] = app_permission_flags[id];
			
		}
		else
		{
			app_permission_flags[id] = app_permission_flags[id] & sym_permission_list->vm_sym_permission_list[i].permission;
		}

	}
	_vm_kernel_free( sym_permission_list );
	return PER_OP_OK;
}

#endif

