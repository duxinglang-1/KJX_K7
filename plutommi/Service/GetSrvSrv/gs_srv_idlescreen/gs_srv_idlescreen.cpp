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
*   gs_srv_idlescreen.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IProfile implement file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
	//#include "custom_mmi_default_value.h"
#include "MMI_Include.h"
#include "NwNameSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "EonsSrvGprot.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_idlescreen_impl.h"
#include "vmlog.h"

GS_IBase *CreateIdleScreenService(U32 hd)
{
	IdleScreenService* service = NULL;
	GS_NEW_EX(service, IdleScreenService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
} 

IdleScreenService::IdleScreenService(U32 handle):GS_CBase(handle)
{

}
S32 CALLCC IdleScreenService::queryInterface(S32 iid, GS_IBase **pptr)
{
	/* Please notes: pptr may be a proxy, your call should not use it directly. */
	if (pptr == NULL)
		return 0;
	if (iid == IID_IIDLESCREEN)
	{
		//vm_log_debug("ProfileService::iid == IID_IPROFILE ");
		addRef();
		*pptr = BIND_PROXY(IIdleScreen,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}




S32  CALLCC IdleScreenService::networkGetName(gs_sim_enum sim, WCHAR * name, S32 size)
{
	return srv_nw_name_get_name((mmi_sim_enum)sim,name,size);
}

S32 CALLCC IdleScreenService::networkGetNameEx(gs_sim_enum sim, nw_name_type_enum type, WCHAR * name, S32 size)
{
	return  srv_nw_name_get_name_ex((mmi_sim_enum)sim, (srv_nw_name_type_enum)type, name, size);
}

S32 CALLCC IdleScreenService::networkGetNameIfAny(gs_sim_enum sim, WCHAR * name, S32 size)
{
	return  srv_nw_name_get_name_if_any((mmi_sim_enum)sim, name, size);
}

S32 CALLCC IdleScreenService::networkGetSPN(gs_sim_enum sim, WCHAR * name, S32 size)
{
	return  srv_nw_name_get_spn((mmi_sim_enum)sim, name, size);
}

MMI_BOOL CALLCC IdleScreenService::networkNameServiceIsReady(gs_sim_enum sim)
{
	return  srv_nw_name_is_ready((mmi_sim_enum)sim);
}

MMI_BOOL CALLCC IdleScreenService::networkGetLocationInfo(gs_sim_enum sim, nw_info_location_info_struct * out_info)
{
	return srv_nw_info_get_location_info((mmi_sim_enum)sim, (srv_nw_info_location_info_struct*)out_info);
}

MMI_BOOL CALLCC IdleScreenService::eonsGetName(gs_sim_enum sim, const S8 * plmn, U16 lac, eons_get_name_cb callback, void * user_data)
{
#ifdef __MMI_EONS_SRV__
	return  srv_eons_get_name((mmi_sim_enum)sim,plmn,lac,(srv_eons_get_name_cb)callback, user_data);
#else
	return MMI_FALSE;
#endif
}

MMI_BOOL CALLCC IdleScreenService::eonsServiceIsReady(gs_sim_enum sim)
{
	#ifdef __MMI_EONS_SRV__
	return  srv_eons_is_ready((mmi_sim_enum)sim);
	#else
	return MMI_FALSE;
#endif
}


