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
 *  vadp_v2p_cube_vip_contact.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Venus APP ---> v2p adaptor ---> Pluto APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_Features.h"

#ifdef __MMI_VUI_3D_CUBE_APP__

#include "MMI_include.h"

     
#include "CubeAppProt.h"
#include "CubeAppGprot.h"
     
     
#include "kal_release.h"
     

#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"
#include "PhonebookResDef.h" /* for phonebook icons for number */

#include "UCMGprot.h"
#include "SMSAppGprot.h"
#include "SmsSrvGprot.h"
     
#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#endif

#include "NwUsabSrvGprot.h"


/* Venus MMI headers: */
#include "ui_core\base\vfx_datatype.h"
#include "trc\vadp_app_trc.h"

#include "vadp_p2v_cube_vip_contact.h"
#include "vadp_v2p_cube_vip_contact.h"


typedef struct{
    struct _Setting
    {
        VfxU16 index[6]; // vip contact store index
        VfxU8  active;                 // the index of active contact
        VfxU8  state;                  // state
    } setting;
	
	VfxU16  cui_id;
}vadp_v2p_cube_vip_contact_cntx;

static vadp_v2p_cube_vip_contact_cntx g_vadp_v2p_cont_cntx;


static mmi_ret vadp_v2p_vip_contact_cui_evt_proc(mmi_event_struct *evt);

#ifndef __MTK_TARGET__
static S32 count = 0;
#endif
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vip_contact_deinit
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
VfxS8 vadp_v2p_contact_is_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxS8 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    if (count != 0)
    {
        count--;
        return 0;
    }
#endif

	if (srv_phb_startup_is_phb_ready())
	{
		// If sync is on backgournd, contact is not available
#ifdef __SYNCML_SUPPORT__
	    if (!mmi_syncml_is_phb_sync_now())
#endif /*__SYNCML_SUPPORT__*/
        {
            ret = 1;
        }		
	}

    VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_PHB_AVAILABLE, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vip_contact_deinit
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
void vadp_v2p_vip_contact_select_contact(VfxU16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id grp_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	grp_id = mmi_frm_group_create(GRP_ID_ROOT, 
								 GRP_ID_AUTO_GEN, 
								 vadp_v2p_vip_contact_cui_evt_proc,
								 (void*)index);
	
	mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	 
    g_vadp_v2p_cont_cntx.cui_id = cui_phb_list_select_contact_create(grp_id);

    if (g_vadp_v2p_cont_cntx.cui_id != GRP_ID_INVALID)
    {
    	g_vadp_v2p_cont_cntx.setting.active = (VfxU8)index;
    	cui_phb_list_select_contact_set_field_filter(g_vadp_v2p_cont_cntx.cui_id, 
													 SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER);
        cui_phb_list_select_contact_set_storage(g_vadp_v2p_cont_cntx.cui_id, PHB_STORAGE_NVRAM);
        cui_phb_list_select_contact_run(g_vadp_v2p_cont_cntx.cui_id);
    }
    else
    {
        g_vadp_v2p_cont_cntx.cui_id = GRP_ID_INVALID;
    }  
	
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_get_number_res
 * DESCRIPTION
 *  get phone book image
 * PARAMETERS
 *  flag		[IN]	flag
 * RETURNS
 *  resource id
 *****************************************************************************/
VfxS32 vadp_v2p_vip_contact_get_number_res(const VfxU32 flag)
{
	if (flag == CONTACT_NUMBER_MASK_HOME)
	{
		return IMG_HOME_NUMBER;
	}
	else if (flag == CONTACT_NUMBER_MASK_OFFICE)
	{
		return IMG_OFFICE_NUMBER;
	}
	else if (flag == CONTACT_NUMBER_MASK_MOBILE)
	{
		return IMG_MOBILE_NUMBER;
	}
	else if (flag == CONTACT_NUMBER_MASK_FAX)
	{
		return IMG_FAX_NUMBER;
	}
	
	return 0; 
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_load_setting
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_vip_contact_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxS16 sError;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // read before screen init
    ReadRecord(NVRAM_EF_CUBE_VIP_CONTS_LID, 
           1, 
           &g_vadp_v2p_cont_cntx.setting, 
           NVRAM_EF_CUBE_VIP_CONTS_SIZE, 
           &sError);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_save_setting
 * DESCRIPTION
 *  save setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_vip_contact_save_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxS16 sError;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	WriteRecord(NVRAM_EF_CUBE_VIP_CONTS_LID, 
				1, 
				&g_vadp_v2p_cont_cntx.setting, 
				NVRAM_EF_CUBE_VIP_CONTS_SIZE, 
				&sError);	
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_get_index
 * DESCRIPTION
 *  save setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxU16 vadp_v2p_vip_contact_get_index(VfxU16 index)
{
    return g_vadp_v2p_cont_cntx.setting.index[index];
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_clear_index
 * DESCRIPTION
 *  save setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_vip_contact_clear_index(VfxU16 index)
{
    g_vadp_v2p_cont_cntx.setting.index[index] = 0xFFFF;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_get_setting
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  S8
 *****************************************************************************/
void* vadp_v2p_vip_contact_get_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return &g_vadp_v2p_cont_cntx.setting;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_get_image_id
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
VfxS8 vadp_v2p_vip_contact_get_image_id(VfxU16 store_index, VfxS32 *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxU16 resId;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!srv_phb_get_image_id(store_index, &resId))
	{
		return 0;
	}

	// default image.
	if (resId & 0x8000)
	{
		return 0;
	}
	*image = resId;
	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_get_image_path
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
VfxS8 vadp_v2p_vip_contact_get_image_path(VfxU16 store_index,
                                          VfxWChar *buffer,
                                          VfxU16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxS8 ret;
	U16 *imgPath;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	imgPath = (U16*)OslMalloc((FMGR_MAX_PATH_LEN + 1) * sizeof(VfxU16));
    
	if (srv_phb_get_image_path(store_index, imgPath) &&
		mmi_ucs2strlen((S8*)imgPath) != 0)
	{
        mmi_ucs2ncpy((S8*)buffer, (S8*)imgPath, len);
		ret = 1;
	}
	else
	{
		ret = 0;	
	}
	OslMfree(imgPath);

	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_get_name
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
void vadp_v2p_vip_contact_get_name(VfxU16 store_index, 
                                             VfxWChar *buffer,
                                             VfxU16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	srv_phb_get_name(store_index, buffer, len);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_get_number
 * DESCRIPTION
 *  Get contact number.
 * PARAMETERS
 *  buffer      :[OUT] buffer for out data
 *  length      :[IN] number length.
 *  store_index :[IN]
 *  flag        :[IN]
 * RETURNS
 *  S8 : 1 -> OK, 0 -> FAIL
 *****************************************************************************/
VfxS8 vadp_v2p_vip_contact_get_number(VfxWChar *buffer, 
                                                 VfxU16 length, 
                                                 VfxU16 store_index, 
                                                 VfxU32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_phb_contact_info_struct contact;
	U16 *number;
    VfxU16 str_len;
    VfxS8 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    number = (U16*)OslMalloc((MMI_PHB_NUMBER_PLUS_LENGTH + 1) * sizeof(U16));

    // memset the other pointer to NULL, or srv_phb_oplib_get_contact_info will assert.
    memset(&contact, 0, sizeof(srv_phb_contact_info_struct));
    
    if (flag == CONTACT_NUMBER_MASK_MOBILE)
    {        
        contact.field_data.number = number;
        contact.field_mask = SRV_PHB_ENTRY_FIELD_NUMBER;
    }
    else if (flag == CONTACT_NUMBER_MASK_HOME)
    {
        contact.field_data.home_number = number;   
        contact.field_mask = SRV_PHB_ENTRY_FIELD_HOME;

    }
    else if (flag == CONTACT_NUMBER_MASK_OFFICE)
    {
        contact.field_data.office_number = number;
        contact.field_mask = SRV_PHB_ENTRY_FIELD_OFFICE;
    }
	else if (flag == CONTACT_NUMBER_MASK_FAX)
    {
        contact.field_data.fax_number = number;
        contact.field_mask = SRV_PHB_ENTRY_FIELD_FAX;
    }
    else
    {
        // Error
    }
    
    srv_phb_oplib_get_contact_info(store_index, &contact);
    str_len = mmi_ucs2strlen((S8*)number);
    
	if (str_len != 0)
	{
	    if (str_len > length)
        {
            mmi_ucs2ncpy((S8*)buffer, (S8*)number, length - 2);
        }
        else
        {
            mmi_ucs2cpy((S8*)buffer, (S8*)number);
        }
	    
	    ret = 1;
	}
    else
    {
        ret = 0;
    }
	
	OslMfree(number);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_send_sms
 * DESCRIPTION
 *  This function is used to send sms/mms
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
void vadp_v2p_vip_contact_send_sms(const VfxWChar *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sms_write_msg_para_struct sms_write_struct;
	U8 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sms_write_struct.srcport = 0;
    sms_write_struct.desport = 0;
    sms_write_struct.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    sms_write_struct.stringlength = 0;
    sms_write_struct.string =  NULL;
    sms_write_struct.filename = NULL;
    sms_write_struct.dcs = SMSAL_UCS2_DCS;
    sms_write_struct.dcs_class = 0;

    len = mmi_ucs2strlen((const CHAR *)number);
    sms_write_struct.ascii_addr = (U8 *)OslMalloc(len + 1);
	mmi_ucs2_to_asc((S8 *)sms_write_struct.ascii_addr, (S8 *)number);
	
	mmi_sms_write_msg_lanch(0, &sms_write_struct);

    OslMfree(sms_write_struct.ascii_addr);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_make_call_callback
 * DESCRIPTION
 *  Make call callback function.
 * PARAMETERS
 *  make_call_cb_para   : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_vip_contact_make_call_callback(mmi_ucm_after_make_call_cb_struct* make_call_cb_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_destory_cm_user_data(make_call_cb_para->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_make_call
 * DESCRIPTION
 *  This function is used to make call
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
void vadp_v2p_vip_contact_make_call(const VfxWChar *number,
                                              VfxU32 flag,
                                              VfxU16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_ucm_make_call_para_struct make_call_para;
	void *cm_user_data;
    U32 number_type;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    mmi_ucm_init_call_para(&make_call_para);  

    if (flag == CONTACT_NUMBER_MASK_MOBILE)
    {        
        number_type = SRV_PHB_ENTRY_FIELD_NUMBER;
    }
    else if (flag == CONTACT_NUMBER_MASK_HOME)
    {
        number_type = SRV_PHB_ENTRY_FIELD_HOME;
    }
    else if (flag == CONTACT_NUMBER_MASK_OFFICE)
    {
        number_type = SRV_PHB_ENTRY_FIELD_OFFICE;
    }
    else if (flag == CONTACT_NUMBER_MASK_FAX)
    {
        number_type = SRV_PHB_ENTRY_FIELD_FAX;
    }
    else
    {
        VFX_ASSERT(!"Wrong number type");
    }

    cm_user_data = srv_phb_create_cm_user_data(NULL, number_type, store_index);
    
    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.after_make_call_callback = vadp_v2p_vip_contact_make_call_callback;
    make_call_para.ucs2_num_uri = (U16*)number;
    mmi_ucm_call_launch(0, &make_call_para);

#else/* __MMI_UCM__ */

    MakeCall((PS8)number);
#endif/* __MMI_UCM__ */
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_select_contact_proc
 * DESCRIPTION
 *  Handler phone book CUI event
 *  buffer.
 * PARAMETERS
 *  evt         : [IN]	event pointer
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret vadp_v2p_vip_contact_cui_evt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_select_contact_result_struct* result;
	VfxU16 index;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_INACTIVE:
            break;
        
        case EVT_ID_GROUP_ACTIVE:
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;
            
        case EVT_ID_GROUP_DEINIT:
			g_vadp_v2p_cont_cntx.cui_id = GRP_ID_INVALID;
            break;
			
        case EVT_ID_PHB_SELECT_CONTACT:
            result = (cui_phb_select_contact_result_struct*)evt;

			index = g_vadp_v2p_cont_cntx.setting.active;
    		g_vadp_v2p_cont_cntx.setting.index[index] = result->store_index;
			
			vadp_v2p_vip_contact_save_setting();
           /*
            * Caller should call CUI close function to release CUI resource
            */
            cui_phb_list_select_contact_close(g_vadp_v2p_cont_cntx.cui_id);
           
			VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_PHB_SELECT, index, result->store_index);
            
            break;
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
    
           /*
            * Caller should call CUI close function to release CUI resource
            */
            cui_phb_list_select_contact_close(g_vadp_v2p_cont_cntx.cui_id);
            break;
        default:
            break;
    }
    
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_is_sms_available
 * DESCRIPTION
 *  Check whether SMS is available
 * PARAMETERS
 *  void
 * RETURNS
 *  1 -> available
 *  0 -> not available 
 *****************************************************************************/
VfxS8 vadp_v2p_vip_contact_is_sms_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_valid())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_vip_contact_is_nwk_available
 * DESCRIPTION
 *  Check whether network is available
 * PARAMETERS
 *  void
 * RETURNS
 *  1 -> available
 *  0 -> not available 
 *****************************************************************************/
VfxS8 vadp_v2p_vip_contact_is_nwk_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS8 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_nw_usab_is_any_network_available())
    {
        ret = 1;
    }
    else
    {
        ret =  0;
    }

    VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_NWK_AVAILABLE, ret);
    
    return ret;
}

#endif /* __MMI_VUI_3D_CUBE_APP__ */

