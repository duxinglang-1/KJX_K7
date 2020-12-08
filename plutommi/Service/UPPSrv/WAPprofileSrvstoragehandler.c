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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * WAPProfileSrvstoragehandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for MTK to config/customize NVRAM settings.
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"


#ifdef WAP_SUPPORT
#include "WAPProfileSrvType.h"
#include "WAPProfileSrvProt.h"
#include "custom_mmi_default_value.h"


#include "mmi_rp_srv_wap_prof_def.h"

//------------------------------ suggest Add ------------------------------

#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "kal_public_api.h"
#include "cbm_api.h"

#include "cbm_consts.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_general_types.h"
//------------------------------ usage ------------------------------






/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_set_active_profile_index
 * DESCRIPTION
 *  Sets index value to active profile index global. commits to NVRAM if commit_flag = MMI_TRUE
 * PARAMETERS
 *  sim_id          [IN]        
 *  app_id          [IN]        
 *  index_value     [IN]        
 *  commit_flag     [IN]        
 * RETURNS
 *  U8    activated profile index(?)
 *****************************************************************************/
void srv_wap_prof_set_active_profile_index(
        srv_wap_prof_sim_id_enum sim_id,
        srv_wap_prof_app_id_enum app_id,
        U32 index_value,
        MMI_BOOL commit_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_SET_ACTIVE_INDEX, sim_id, app_id, index_value, commit_flag);

    if ((sim_id >= SRV_WAP_PROF_SIMID_END) ||
        (app_id >= SRV_WAP_PROF_APPID_END))     
    {
        ASSERT(app_id < SRV_WAP_PROF_APPID_END);
        ASSERT(sim_id < SRV_WAP_PROF_SIMID_END);
        return;
    }

#if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)
    if (g_srv_wap_prof_cntx.sim_id != SRV_WAP_PROF_SIMID_WLAN)
    {
    g_srv_wap_prof_cntx.active_dtcnt_index[sim_id][app_id] = index_value;
     }
#else /*(__MMI_WAP_DUAL_SIM__ ) && defined(__MMI_WLAN_FEATURES__)*/   
    g_srv_wap_prof_cntx.active_dtcnt_index[sim_id][app_id] = index_value;
#endif

    if (commit_flag)
    {
        srv_wap_prof_nvram_write_active_profile_index(sim_id, app_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_nvram_write_active_profile_index
 * DESCRIPTION
 *  THis API writes active index to NVRAM.
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  U8    activated profile index(?)
 *****************************************************************************/
void srv_wap_prof_nvram_write_active_profile_index(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    S16 error;
    U16 lid = 0;
    U32 encoded_dtcnt_id = 0;
    U8 primary_dtcnt_id = (U8) -1;
    U8 secondary_dtcnt_id = (U8) -1;

    cbm_account_info_struct acct_info;
    S8 decode_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

  if (app_id >= SRV_WAP_PROF_APPID_END || sim_id >= SRV_WAP_PROF_SIMID_END)
    {
        ASSERT(app_id < SRV_WAP_PROF_APPID_END);
        ASSERT(sim_id < SRV_WAP_PROF_SIMID_END);
        return;
    }

    if (SRV_WAP_PROF_APPID_BRW == app_id)
    {

        if(SRV_WAP_PROF_SIMID_SIM1 == sim_id)
    {
            lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM1_DTCNT_INDEX;
    }
#if (MMI_MAX_SIM_NUM>=2)
        else if(SRV_WAP_PROF_SIMID_SIM2 == sim_id)
    {
            lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM2_DTCNT_INDEX;
   }
#if (MMI_MAX_SIM_NUM>=3) 
		else if(SRV_WAP_PROF_SIMID_SIM3 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM3_DTCNT_INDEX;
		}
#if(MMI_MAX_SIM_NUM>=4) 
		else if(SRV_WAP_PROF_SIMID_SIM4 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM4_DTCNT_INDEX;
		}
#endif
#endif
#endif

        else
		{ 
			ASSERT(0);
		}
    }
#ifdef MMS_SUPPORT
    else if (SRV_WAP_PROF_APPID_MMS == app_id)
    {

        if (SRV_WAP_PROF_SIMID_SIM1 == sim_id)
        {
            lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM1_DTCNT_INDEX;
        }

#if (MMI_MAX_SIM_NUM>=2)
        else if (SRV_WAP_PROF_SIMID_SIM2 == sim_id)
        {
            lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM2_DTCNT_INDEX;
        }
#if (MMI_MAX_SIM_NUM>=3)
		else if(SRV_WAP_PROF_SIMID_SIM3 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM3_DTCNT_INDEX;
    }
#if (MMI_MAX_SIM_NUM>=4)
		else if(SRV_WAP_PROF_SIMID_SIM4 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM4_DTCNT_INDEX;
		}
#endif 
#endif
#endif
    else
    {
        ASSERT(0);
        return;
    }
	}
#endif


    encoded_dtcnt_id = srv_wap_prof_get_active_dtcnt_index(sim_id, app_id);


    decode_result = cbm_decode_data_account_id_ext(encoded_dtcnt_id, &acct_info);

    if (CBM_OK == decode_result)
{

            primary_dtcnt_id = acct_info.account[0].account_id;
            secondary_dtcnt_id = (U8) - 1;

            if (acct_info.acct_num > 1)
    {
				secondary_dtcnt_id = acct_info.account[1].account_id;
}

        }
        else
    {  //10ADA  check this case
            /* Do not change account id as result is error. */
/*            MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, "[WAP_PROF] CBM decode API error."); */
            MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ERR_CBM_DECODE);
        }



    index = (U16)secondary_dtcnt_id;

    index = index << 8;
    index = index | (U16) (primary_dtcnt_id & 0x00FF);
		
		

    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_WRITE_ACTIVE_INDEX, app_id, index);

    WriteValue(lid, &index, DS_SHORT, &error);
    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_WRITE_ERROR, error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_nvram_read_active_profile_index
 * DESCRIPTION
 *  It will read the active data account id from NVRAM, based on app_id.
 * PARAMETERS
 *  app_id      [IN]        Application ID BRW / MMS.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_prof_nvram_read_active_profile_index(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    S16 error;
    U16 lid = 0;
    MMI_BOOL upd_flag = MMI_FALSE;
    U32 encoded_dtcnt_id = 0;
    U8 secondary_index =0;
    U8 primary_index = 0;
   
  

#if (defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) || defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__))

    U32 cbm_encoded_dtcnt_id = 0;    /* MAUI_01730725 */
    cbm_account_info_struct data_account_info;

#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_READ_ACTIVE_INDEX, app_id);
    if (app_id >= SRV_WAP_PROF_APPID_END || sim_id >= SRV_WAP_PROF_SIMID_END)
    {
        ASSERT(app_id < SRV_WAP_PROF_APPID_END);
        ASSERT(sim_id < SRV_WAP_PROF_SIMID_END);
        return;
    }

    if (SRV_WAP_PROF_APPID_BRW == app_id)
    {
        
        if (SRV_WAP_PROF_SIMID_SIM1 == sim_id)
        {
            lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM1_DTCNT_INDEX;
        }

#if (MMI_MAX_SIM_NUM>=2)
        else if (SRV_WAP_PROF_SIMID_SIM2 == sim_id)
        {
            lid =NVRAM_WAP_PROF_ACTIVE_WAP_SIM2_DTCNT_INDEX;
}
#if (MMI_MAX_SIM_NUM>=3)
		else if(SRV_WAP_PROF_SIMID_SIM3 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM3_DTCNT_INDEX;
		}
#if (MMI_MAX_SIM_NUM>=4)
		else if(SRV_WAP_PROF_SIMID_SIM4 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_WAP_SIM4_DTCNT_INDEX;
		}
    
      
#endif
#endif
#endif

        else
        { ASSERT(0); }

   
    }
#ifdef MMS_SUPPORT
    else if (SRV_WAP_PROF_APPID_MMS == app_id)
    {

     if(SRV_WAP_PROF_SIMID_SIM1 == sim_id)
    {
            lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM1_DTCNT_INDEX;
    }

#if (MMI_MAX_SIM_NUM>=2)
        else if(SRV_WAP_PROF_SIMID_SIM2 == sim_id)
    {
            lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM2_DTCNT_INDEX;
    }
#if (MMI_MAX_SIM_NUM>=3)
		else if(SRV_WAP_PROF_SIMID_SIM3 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM3_DTCNT_INDEX;
		}
#if (MMI_MAX_SIM_NUM>=4) 
		else if(SRV_WAP_PROF_SIMID_SIM4 == sim_id)
		{
			lid = NVRAM_WAP_PROF_ACTIVE_MMS_SIM4_DTCNT_INDEX;
		}
#endif
#endif
#endif
    
    else
    {
        ASSERT(0);
        return;
    }
	}
#endif

    ReadValue(lid, &index, DS_SHORT, &error);

    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_READ_ERROR, error);
    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_NVRAM_READ_RETURN_INDEX, index);

    /* Bits 0-7 contains primary data account id. */
    primary_index = (U8) ((index) & 0x00FF);  




    /* Bits 8-15 contains secondary data account id. */
    secondary_index = (U8) ((index) >> 8);


if( primary_index == (U8)-1 || primary_index == CBM_DEFAULT_ACCT_ID)
    {
   primary_index = CBM_DEFAULT_ACCT_ID;
    if(secondary_index == CBM_DEFAULT_ACCT_ID)
	{
          secondary_index = (U8) - 1;
	}
   //10ADA : Check how to handle the case of updating the nvram here
    }


    encoded_dtcnt_id = srv_wap_prof_encode_dtcnt(primary_index, secondary_index, sim_id,  app_id );

    srv_wap_prof_set_active_profile_index(sim_id, app_id, encoded_dtcnt_id, upd_flag); //10ADA : upd_flag always FALSE

 

}



/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_encode_dtcnt
 * DESCRIPTION
 *  It will return an encoded data account id 
 * PARAMETERS
 *  app_id      [IN]        Application ID BRW / MMS.
 * RETURNS
 *  U32
 *****************************************************************************/

U32 srv_wap_prof_encode_dtcnt(U8 primary_index, U8 secondary_index, srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id )
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
	


#if (defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) || defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__))

    U32 cbm_encoded_dtcnt_id = 0;    /* MAUI_01730725 */
    cbm_account_info_struct data_account_info;
   
#endif

    U32 encoded_dtcnt_id = 0;
    U8 cbm_app_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	cbm_app_id = srv_wap_prof_get_cbm_app_id(app_id,sim_id);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MMS_SUPPORT
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif

	 cbm_sim_id = (cbm_sim_id_enum)sim_id;

 #if (defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) || defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__))

    data_account_info.account[0].account_id =  primary_index;

    data_account_info.account[0].is_always_ask = FALSE;
    data_account_info.account[0].sim_id =  cbm_sim_id ;   //10ADA check the mapping

    if ((U8) - 1 != secondary_index)
{
        data_account_info.account[1].account_id = secondary_index;

        data_account_info.account[1].is_always_ask = FALSE;
        data_account_info.account[1].sim_id = cbm_sim_id ;   //10ADA check the mapping
        data_account_info.acct_num = 2;
    }
    else
    {
        data_account_info.acct_num = 1;
    }





    data_account_info.app_id = cbm_app_id;
     


    cbm_encode_data_account_id_ext(primary_index, 
                                   &cbm_encoded_dtcnt_id,
                                   &data_account_info);

#endif /* (defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) || defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__)) */ 



    if (app_id == SRV_WAP_PROF_APPID_BRW)
        {

    #if defined (__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__)
    encoded_dtcnt_id = cbm_encoded_dtcnt_id ;
    #else
    encoded_dtcnt_id = cbm_encode_data_account_id(primary_index, cbm_sim_id, cbm_app_id, KAL_FALSE);
#endif
}


    if (app_id == SRV_WAP_PROF_APPID_MMS)
    {

    #if defined (__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__)
    encoded_dtcnt_id = cbm_encoded_dtcnt_id ;
    #else
    encoded_dtcnt_id = cbm_encode_data_account_id(primary_index, cbm_sim_id, cbm_app_id, KAL_FALSE);
#endif
                }

    return encoded_dtcnt_id;

    }
    


#endif /* WAP_SUPPORT */ 
