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
 *  Vapp_rmgr_cntx.c
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  File for parameter passing in  Rights Manager
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *					
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_include.h"
#include "Vapp_rmgr_cntx.h"
#include "String.h"
#include "Vfx_datatype.h"
#ifdef __MMI_RMGR__
U32 indx;
U32 indx_long;
U32 err;
S32 res;
U16 str;
U8 *inf;
U32 detail[60] = {0,};
U16 licence_count = 0;
U16 flag_del=0;
U8 rmgr_spc_ck;
S32 pop_indx=0;


void set_detail_item_name(kal_wchar* name)
{
	memset(detail,0,60);
	mmi_ucs2ncpy((kal_int8*)detail, (kal_int8*)name, mmi_ucs2strlen((S8*)name));
}

kal_wchar* get_detail_item_name()
{
	return (kal_wchar*)detail;
}


void set_rmgr_detail_buffer(U8 *i)
{
	inf= i;
}

U8 * get_rmgr_detail_buffer()
{
	return inf;
}

void set_rmgr_list_index(U32 itemIndex)
{ 
	indx=itemIndex;
}

int get_rmgr_list_index()
{
	return indx;
}

void set_rmgr_list_index_longtap(U32 itemIndex)
{ 
	indx_long=itemIndex;
}

U32 get_rmgr_list_index_longtap()
{
	return indx_long;
}

void set_fmgr_result(U32 result)
{
   err=result;
}

int get_fmgr_result()
{
	return err;
}

void set_rmgr_drm_result(S32 result)
{
    res=result;
}

int get_rmgr_drm_result()
{
	return res;
}

void set_rmgr_str_id(U16 i)
{
	str=i;
}

U16 get_rmgr_str_id()
{
	return str;
}

void set_licence_count(U16 count)
{
	licence_count = count;
}

U16 get_licence_count(void)
{
	return licence_count;
}


S8 *mmi_vfx_rmgr_ucs2cat_secure(S8 *strDestination, const S8 *strSource, S32 destSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = mmi_ucs2strlen(strDestination);

    destSize = destSize / 2;

    if (destSize - n - 1 <= 0)
    {
        return NULL;
    }

    return mmi_ucs2ncat(strDestination, strSource, destSize - n - 1 );
}

void vapp_set_rmgr_spc(U8 i)
{
  rmgr_spc_ck=i;
}


U8 vapp_get_rmgr_spc()
{ 
	return rmgr_spc_ck;

}

void vapp_rmgr_set_del_item(U16 flag)
{
	flag_del=flag;
}

U16 vapp_rmgr_get_del_item()
{
	if(flag_del)
		return 1;
	else 
		return 0;
}


void vapp_rmgr_set_is_dl_popup(S32 p_indx)
{
  pop_indx =p_indx;
}

S32 vapp_rmgr_get_is_dl_popup()
{
   return pop_indx;
}

#endif /* __MMI_RMGR__ */
