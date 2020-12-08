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
 * vmcermng.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * cermng
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
#include "lcd_sw_inc.h"
#include "vmsys.h"
#include "vmio.h"

#include "vmdl.h"

#include "vmopt.h"
#include "vmgraph.h"

#include "vmcert.h"
#include "vmcerenv.h"
#include "vmcermng.h"
#include "vmcervar.h"

#include "vmcerter.h"

#include "vmperdef.h"
#include "vmpermng.h"

#include "vmnvram.h"

#include "vmrsa.h"

#include "vmmd5.h"
#include "vmsha1.h"

#include "vmlog.h"
#include "vmmem.h"

#include "string.h"
#include "stdlib.h"
#include "vmgettag.h"

//#define __MMI_MRE_SWLA_DEBUG__

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_MRE_SWLA_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define MRE_SWLA_START(_symbol_)
#define MRE_SWLA_STOP(_symbol_)
#endif


#define		PROPERTY_BUF_SIZE		20
#define		VALUE_MAX_LEN			255
#define		TIME1_OLDER						(1)
#define		TIME1_SAME_AS_TIME2		(0)
#define		TIME2_OLDER						(-1)

#define		FILE_SUFFIX_LEN			(3)
#define		ROM_FILE_FLAG				"rom"

static	void ReleaseCert( MRECert * cert );

static	VMUCHAR							cedigest[DIG_MAX_LEN];

extern VMUINT vm_get_memory_size(void);
extern VMINT vm_rsa_verify_by_id_ex( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len );

static VMINT vm_ce_check_memory(VMWSTR filename)
{
    VMINT size = 4;
    VMUINT value = 0;
	
    if (vm_get_vm_tag(filename, VM_CE_INFO_MEM_REQ,(void*)&(value), &size) == GET_TAG_TRUE)
    {
    	if(  value> vm_get_memory_size())
        	return VM_CE_VERITY_INSUFFICIENT_SYS_MEM;
    }
	
    return VM_CE_CHECK_PARAM_OK;
}


static VMINT vm_ce_check_resolution(VMWSTR filename)
{
    VMINT size = 4;
    VMINT value = 0;
	
    if (vm_get_vm_tag(filename, VM_CE_INFO_RESOLUTION_REQ,(void*)&(value), &size) == GET_TAG_TRUE)
    {
		if((value & 0x0000ffff) > LCD_HEIGHT || (value >> 16) > LCD_WIDTH)
			return VM_CE_VERIFY_RESOLUTION_DISMATCH;
		else
			return VM_CE_CHECK_PARAM_OK;
    }
    
    return VM_CE_VERIFY_RESOLUTION_DISMATCH;
}

static VMINT vm_ce_check_appid(VMWSTR filename, VMINT id, VMINT cert_no)
{
#ifdef __MRE_CORE_SANDBOX__
    if( vm_app_in_ban_list( id ) )
        return VM_CE_VERIFY_APP_BANNED;
#endif
    
#ifndef MRE_ON_MODIS	
    if( id == ISD_APP_NUM ||cert_no == 1 )
    {
        VMSTR pStr = NULL;
		VMSTR pIMSI = NULL;
		VMINT size = 0;
		
        pStr = vm_get_imsi( );

		if (vm_get_vm_tag(filename, VM_CE_INFO_IMSI,NULL, &size) != GET_TAG_TRUE)
		{
			return VM_CE_CHECK_PARAM_FAIL;
		}
		
		pIMSI = (VMSTR)_vm_kernel_calloc( size+1 );

		if (vm_get_vm_tag(filename, VM_CE_INFO_IMSI, pIMSI, &size) != GET_TAG_TRUE)
		{
			return VM_CE_CHECK_PARAM_FAIL;
		}

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
#endif
        
        if( pStr == NULL || !strlen(pStr) || pIMSI == NULL || memcmp( pStr, pIMSI, strlen(pStr) ) )
            return VM_CE_VERIFY_IMSI_DISMATCH;
    }
    
#endif	
    return VM_CE_CHECK_PARAM_OK;
}

static MRECert * vm_ce_load_app( VMWSTR filename, VMINT cert_size)
{
    VMUCHAR	* tempbuf = NULL;
    VMINT digtype = 0;
    VMFILE file = -1;
    MRECert * cert = NULL;
	
    file=vm_ce_open_file(filename);

    if( file < 0 )
        return NULL;
		
    tempbuf = (VMUCHAR *)_vm_kernel_malloc( cert_size );
    if( tempbuf == NULL )
        return NULL;

    if( vm_ce_read_cert( file, tempbuf, cert_size, &digtype )<0 )
    {
        vm_ce_close_file( file );
        _vm_kernel_free( tempbuf );
        return NULL;
    }
	
    vm_ce_close_file( file );	

	cert = (MRECert *)_vm_kernel_malloc( sizeof(MRECert) );
	if( cert == NULL )
	{		
		_vm_kernel_free( tempbuf );
		return NULL;
	}

	memset( cert, 0x00, sizeof(MRECert) );
	cert->digest = tempbuf;
	cert->digesttype = digtype;
	cert->diglen = cert_size;
	
    memset( cedigest, 0x00, DIG_MAX_LEN );
    vm_ce_get_cert_digest( filename, cedigest);

    return cert;
}

void vm_ce_unload_app( MRECert * cert )
{
    if( cert == NULL )
        return;

    ReleaseCert( cert );

    memset( cedigest, 0x00, DIG_MAX_LEN );
}


static	void ReleaseCert( MRECert * cert )
{
    VMINT		i = 0;

    if( cert == NULL )
        return;

    if( cert->digest )
        _vm_kernel_free( cert->digest );
    
	_vm_kernel_free( cert );
}


VMINT	vm_ce_verify_app( VMWSTR filename, MRECert * cert, VMUCHAR * digest, VMINT len, VMINT mode )
{
    VMINT buflen = 0,res, cert_no = 0;
    VMUCHAR* certdig = NULL, totaldigest[DIG_MAX_LEN];
	VMINT app_id = 0;
    VMINT size = 4;

    memset( totaldigest, 0x00, DIG_MAX_LEN );
    
#ifndef MRE_ON_MODIS

    if (vm_get_vm_tag(filename, VM_CE_INFO_APP_ID,(void*)&(app_id), &size) != GET_TAG_TRUE)
    {
        return VM_CE_CHECK_PARAM_FAIL;
    }
	
	size = 4;

    if (vm_get_vm_tag(filename, VM_CE_INFO_CERT_ID,(void*)&(cert_no), &size) != GET_TAG_TRUE)
    {
        return VM_CE_CHECK_PARAM_FAIL;
    }
	
	if( app_id != ISD_APP_NUM  && cert_no != 1 )
	{
	
#ifdef __MRE_SAL_CHE_MD5__
		if( cert->digesttype == CERT_DIGEST_TYPE_MD5 )
		{
			md5_state_t 	totalmd5;
		
			md5_init( &totalmd5 );
			md5_append( &totalmd5, digest, DIG_MD5_LEN );
			md5_append( &totalmd5, cedigest, DIG_MD5_LEN );
			md5_finish( &totalmd5, totaldigest );
		}
#endif
	
#ifdef __MRE_SAL_CHE_SHA1__
		if( cert->digesttype == CERT_DIGEST_TYPE_SHA )
		{
			SHA1Context 	totalsha;
		
			vm_sha1_reset( &totalsha );
	
			vm_sha1_input( &totalsha, digest, DIG_SHA_LEN );
			vm_sha1_input( &totalsha, cedigest, DIG_SHA_LEN );
	
			vm_sha1_result( &totalsha );
	
			memcpy( totaldigest, (VMUCHAR *)&(totalsha.Message_Digest[0]), DIG_SHA_LEN );
		}
#endif
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERMNG, TRC_MRE_VMCERMNG_01, cert_no, app_id);

	    if(cert_no < 1000)
	    {
	    	buflen = KEY_LEN;
			
			certdig = (VMUCHAR *)_vm_kernel_malloc( buflen );
			
			if( certdig == NULL )
				return VM_CE_VERIFY_BAD_DIGEST;
				
			res = vm_rsa_verify_by_id( cert->digest, buflen, cert_no, certdig, &buflen );
	    }
		else
		{
			buflen = KEY_LEN*2;
			
			certdig = (VMUCHAR *)_vm_kernel_malloc( buflen );
			
			if( certdig == NULL )
				return VM_CE_VERIFY_BAD_DIGEST;
				
			res = vm_rsa_verify_by_id_ex( cert->digest, buflen, cert_no, certdig, &buflen );
		}

	    if( res < VM_CE_VERIFY_OK )
	    {
	        _vm_kernel_free( certdig );
			
			MMI_TRACE(MMI_MRE_TRC_MOD_VMCERMNG, TRC_MRE_VMCERMNG_02, res);

	        if( res == VM_CE_RSA_KEY_EXPIRED )
	            return VM_CE_VERIFY_KEY_EXPIRED;
	        else	
	            return VM_CE_VERIFY_VERIFY_FAILED;
	    }

#ifdef __MRE_SAL_CHE_MD5__
	    if( cert->digesttype == CERT_DIGEST_TYPE_MD5 )
	    {
	        if( memcmp( certdig, totaldigest, DIG_MD5_LEN) )
	        {
	            _vm_kernel_free( certdig );
	            return VM_CE_VERIFY_DIGEST_DISMATCH;
	        }
	    }
#endif

#ifdef __MRE_SAL_CHE_SHA1__
    if( cert->digesttype == CERT_DIGEST_TYPE_SHA )
    {
        if( memcmp( certdig, totaldigest, DIG_SHA_LEN) )
        {
	            _vm_kernel_free( certdig );
	            return VM_CE_VERIFY_DIGEST_DISMATCH;
	        }	
	    }
#endif

	}
	
#if defined(__MRE_CORE_SMAUTH__) && defined (__MRE_SAL_CHE_DES__)
	{
	    extern VMINT _vm_sm_set_key(VMUCHAR*);
	    _vm_sm_set_key(certdig);
	}
#endif

    _vm_kernel_free( certdig );
	
	res = vm_ce_check_appid(filename, app_id,cert_no);

	if(res != VM_CE_CHECK_PARAM_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERMNG, TRC_MRE_VMCERMNG_03, res);
		return res;
	}
	
	res = vm_ce_check_resolution(filename);

	if(res != VM_CE_CHECK_PARAM_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERMNG, TRC_MRE_VMCERMNG_04, res);
		return res;
	}

    if( mode != VERIFY_SIG )
	{
		res = vm_ce_check_memory(filename);

		if(res != VM_CE_CHECK_PARAM_OK)
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_VMCERMNG, TRC_MRE_VMCERMNG_05, res);
			return res;
		}
	}
#endif
	
	return VM_CE_VERIFY_OK;	
}


VMINT vm_ce_init( void )
{	
    return vm_ce_load_var( );
}


void vm_ce_finialize( void )
{
    vm_ce_unload_var( );
}


static VMINT vm_ce_get_app_digest( VMWSTR filename, VMINT* cert_size, VMUCHAR * cache_buf, VMINT cache_len, unsigned char digest[DIG_MAX_LEN] )
{
    VMFILE file = -1;
    VMINT res, org_size = 0;
    VMUINT nRead = 0;
    VMCHAR Head_tag[CERT_HEAD_LEN+1];
	VMINT digestype;
	VMUINT8 cert_type;
	
#ifdef __MRE_SAL_CHE_MD5__
    md5_state_t	*	appmd5 = NULL;
#endif

#ifdef __MRE_SAL_CHE_SHA1__
    SHA1Context	*	appsha = NULL;
#endif

    memset( Head_tag, 0x00, CERT_HEAD_LEN+1 );

    file = vm_file_open( filename, MODE_READ, TRUE );
    if( file<0 )
    {
        return VM_CE_OP_FAIL;
    }
	
	if( vm_file_seek(file,-8,BASE_END) != 0 )
	{
		vm_file_close(file);
		return VM_CE_OP_FAIL;				
	}
	
	if( vm_file_read(file, &cert_type, 1, &nRead ) == 0 )
	{
		vm_file_close(file);
		return VM_CE_OP_FAIL;				
	}
	
	if(cert_type == 1)
    {
    	*cert_size = CERT_DIGEST_LEN * 2;;
    	res = vm_file_seek( file, (sizeof(MRECertHead_Ex)+CERT_HEAD_LEN)*(-1), BASE_END );
	}
	else
	{
		*cert_size = CERT_DIGEST_LEN;
		res = vm_file_seek( file, (sizeof(MRECertHead)+CERT_HEAD_LEN)*(-1), BASE_END );
	}
	
    if( res < 0 )
    {
        vm_file_close( file );
        return VM_CE_OP_FAIL;
    }		

    if( vm_file_read( file, Head_tag, CERT_HEAD_LEN, &nRead ) == 0 )
    {			
        vm_file_close( file );
        return VM_CE_OP_FAIL;
    }
	
    if( nRead != CERT_HEAD_LEN || Head_tag[0] != 0xb4 || strcmp(Head_tag+1, "VDE10" ) != 0 )
    {
        vm_file_close( file );
        return VM_CE_OP_FAIL;
    }

	if(cert_type == 1)
	{
		MRECertHead_Ex head;

		if( vm_file_read( file, (VMCHAR *)&head, sizeof(MRECertHead_Ex), &nRead ) == 0 )
		{
			vm_file_close( file );
			return VM_CE_OP_FAIL;
		}
		else
		{
			digestype = head.digestype;
			org_size = head.offset;
		}
	}
	else
	{
		MRECertHead head;

		if( vm_file_read( file, (VMCHAR *)&head, sizeof(MRECertHead), &nRead ) == 0 )
		{
			vm_file_close( file );
			return VM_CE_OP_FAIL;
		}
		else
		{
			digestype = head.digestype;
			org_size = head.offset;
		}
	}

#ifdef __MRE_SAL_CHE_MD5__
    if( digestype == CERT_DIGEST_TYPE_MD5 )
    {
        appmd5 = (md5_state_t	*)_vm_kernel_malloc( sizeof(md5_state_t) );
        if( appmd5 != NULL )
            md5_init( appmd5 );
        else
        {
            vm_file_close( file );
            return VM_CE_OP_FAIL;
        }
    }
#endif

#ifdef __MRE_SAL_CHE_SHA1__
    if( digestype == CERT_DIGEST_TYPE_SHA )
    {
        appsha = (SHA1Context *)_vm_kernel_malloc( sizeof(SHA1Context) );
        if( appsha != NULL )
            vm_sha1_reset( appsha );
        else
        {
            vm_file_close( file );
            return VM_CE_OP_FAIL;
        }			
    }
#endif

    res = vm_file_seek( file, 0, BASE_BEGIN );
    if( res < 0 )
    {
#ifdef __MRE_SAL_CHE_MD5__
        if( appmd5 )
        {
            _vm_kernel_free( appmd5 );
            appmd5 = NULL ;
        }
#endif
#ifdef __MRE_SAL_CHE_SHA1__
        if( appsha )
        {
            _vm_kernel_free( appsha );
            appsha = NULL;
        }
#endif
        vm_file_close( file );
        return VM_CE_OP_FAIL;		
    }

    while( org_size )
    {
        VMINT		BytesToRead;
        
        memset( cache_buf, 0x00, cache_len );

        if( org_size > cache_len )
            BytesToRead = cache_len;
        else
            BytesToRead = org_size;


        if( vm_file_read( file, cache_buf, BytesToRead, &nRead ) == 0 )
        {
#ifdef __MRE_SAL_CHE_MD5__
            if( appmd5 )
            {
                _vm_kernel_free( appmd5 );
                appmd5 = NULL ;
            }
#endif
#ifdef __MRE_SAL_CHE_SHA1__
            if( appsha )
            {
                _vm_kernel_free( appsha );
                appsha = NULL;
            }
#endif
            vm_file_close( file );
            return VM_CE_OP_FAIL;				
        }	
        else
        {
            if( nRead != BytesToRead )
                break;
#ifdef __MRE_SAL_CHE_MD5__
            if( digestype == CERT_DIGEST_TYPE_MD5 )
                md5_append( appmd5, (unsigned char *)cache_buf, BytesToRead );
#endif
#ifdef __MRE_SAL_CHE_SHA1__
            if( digestype == CERT_DIGEST_TYPE_SHA )
                vm_sha1_input( appsha, (unsigned char *)cache_buf, BytesToRead );
#endif
            org_size -= BytesToRead;		
        }
    }	

#ifdef __MRE_SAL_CHE_MD5__
    if( digestype == CERT_DIGEST_TYPE_MD5 )
    {
        md5_finish( appmd5, digest );		
        _vm_kernel_free( appmd5 );

    }
#endif

#ifdef __MRE_SAL_CHE_SHA1__
    if( digestype == CERT_DIGEST_TYPE_SHA )
    {
        vm_sha1_result( appsha );		
        memcpy( digest, (VMUCHAR *)&(appsha->Message_Digest[0]), DIG_SHA_LEN );
        
        _vm_kernel_free( appsha );
    }
#endif

    vm_file_close( file );
    
    if( org_size )
        return VM_CE_OP_FAIL;
    else
        return VM_CE_OP_OK;
        
}


VMINT vm_ce_auth_app_ex( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, VMINT mode )
{
    VMINT rescode = -1;
    VMUCHAR	appdigest[DIG_MAX_LEN];
    MRECert* apce = NULL;	
	VMINT cert_size = 0;

    MRE_SWLA_START("M50");
	
	if(filename == NULL || cache_buf == NULL || cache_len == 0)
		return VM_CE_READ_CERT_BAD_PARAM;
	
	if( vm_parse_exec_format( filename ) == VM_EXEC_ROM )
    {
        MRE_SWLA_STOP("M50");
        return VM_CE_VERIFY_OK;
    }
	
    memset( appdigest, 0x00, DIG_MAX_LEN );
        
    rescode = vm_ce_init( );
    if( rescode < 0 )
    {            
        vm_ce_finialize( );
        MRE_SWLA_STOP("M50");
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERMNG, TRC_MRE_VMCERMNG_06, rescode);
        return rescode;
    }
        
    rescode = vm_ce_get_app_digest( filename, &cert_size, cache_buf, cache_len, appdigest );
    if( rescode<0 )
    {
        vm_ce_finialize( );
        MRE_SWLA_STOP("M50");
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCERMNG, TRC_MRE_VMCERMNG_07, rescode);
        return rescode;
    }
    
    apce = vm_ce_load_app( filename, cert_size );

    if( apce )
        rescode = vm_ce_verify_app( filename, apce, (VMUCHAR *)appdigest, DIG_MAX_LEN, mode );
    else
        rescode = -1;	

    vm_ce_unload_app( apce );
    vm_ce_finialize( );		
        
    MRE_SWLA_STOP("M50");
    return rescode;
}

VMINT vm_ce_auth_app( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len )
{
    return vm_ce_auth_app_ex(filename, cache_buf, cache_len, VERIFY_SIG);
}

#endif

