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
 * WAPProvisioningSrvmsghandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for UI handling for the profile handler
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
#include "MMI_include.h"
#include "MMI_features.h"
#include "custom_nvram_editor_data_item.h"

#include "Nvram_enums.h"

#ifdef WAP_SUPPORT
#include "WAPProfSrvConfig.h"
#include "WAPProfileSrvProt.h"
#ifdef PROV_SUPPORT
#include "WAPprovisioningSrvProt.h"
#include "CcaSrvGprot.h"



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_add_bookmark_rsp_hdlr
 * DESCRIPTION
 *  Handler for add bookmark rsp.
 *  
 *  PARAMETERS:
 *  msg     [?]     
 *****************************************************************************/
void srv_wap_prof_add_bookmark_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_add_bookmark_rsp_struct *l_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg);
    l_data = (srv_wap_prof_add_bookmark_rsp_struct*) msg;

    /* Mark setting as installed even if 1 BKM is installed. */
     if (SRV_WAP_PROF_SUCCESS == l_data->result)
        {
            /* SUCCESS result cannot be put in main file as that API is called 1st time also. */
		srv_wap_prov_update_provisioning_response_to_cca(SRV_WAP_PROF_PROV_RESULT_SUCCESS);
    }
	
    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_PROV_INSTALL_BOOKMARK_RESULT, l_data->result);
    srv_wap_prov_install_bookmark(l_data->result);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prov_add_bookmark_rsp_callback
 * DESCRIPTION
 *  Callback function called by WAP2 to give result.
 *  
 *  PARAMETERS:
 *  result      [IN]        
 *****************************************************************************/
void srv_wap_prov_add_bookmark_rsp_callback(srv_wap_prof_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_add_bookmark_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_wap_prof_add_bookmark_rsp_struct*) OslConstructDataPtr(sizeof(srv_wap_prof_add_bookmark_rsp_struct));
    data->result = result;

    srv_wap_prof_send_msg(MOD_MMI, MSG_ID_MMI_WAP_PROF_ADD_BOOKMARK_RSP, (void*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prov_send_response
 * DESCRIPTION
 *  This API sends the status of provisioning to CCA.
 * PARAMETERS
 *  status      [IN]        
 *  cca_doc     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_prov_send_response(srv_cca_status_enum status, srv_cca_app_configure_ind_struct **cca_doc)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_configure_rsp_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cca_doc != NULL)
    {
        local_data = (srv_cca_app_configure_rsp_struct*) OslConstructDataPtr(sizeof(srv_cca_app_configure_rsp_struct));
        local_data->config_id = (*cca_doc)->config_id;
        local_data->hConfig = (*cca_doc)->hConfig;
        local_data->status = status;

        srv_wap_prof_send_msg(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (void*)local_data, NULL);
        srv_wap_prof_mem_free(*cca_doc);
        *cca_doc = NULL;
		g_srv_wap_prof_cntx.profile_content_src = SRV_WAP_PROF_PROFILE_SRC_USER;

    }
}


#endif /* WAP_SUPPORT */ 
#endif/* PROV_SUPPORT */
