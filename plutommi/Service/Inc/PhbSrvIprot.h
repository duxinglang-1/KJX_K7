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
 *  PhbSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains prototypes for Phonebook internal service layer.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PHBSRVIPROT_H
#define PHBSRVIPROT_H

#include "custom_phb_config.h"
#include "MMIDataType.h"

#include "ps_public_struct.h"
#include "PhbSrvGprot.h"
#include "kal_general_types.h"
//#include "wgui_categories_list.h"
//#include "ImeGprot.h"

typedef enum
{
    SRV_PHB_SPEED_DIAL_SYNC_STATUS_FAIL,
    SRV_PHB_SPEED_DIAL_SYNC_STATUS_OK,
    SRV_PHB_SPEED_DIAL_SYNC_STATUS_ADDING,
    SRV_PHB_SPEED_DIAL_SYNC_STATUS_DELING,
    SRV_PHB_SPEED_DIAL_SYNC_STATUS_TOTAL
} srv_phb_speed_dial_sync_status;

typedef enum
{
   SRV_PHB_DN_TYPE_NONE=0,
   SRV_PHB_DN_TYPE_ADN=0x2,
   SRV_PHB_DN_TYPE_FDN=0x4,
   SRV_PHB_DN_TYPE_BDN=0x8,
   SRV_PHB_DN_TYPE_ADN_BDN=0x0A,
   SRV_PHB_DN_TYPE_FDN_BDN=0x0C
}srv_phb_sim_dn_enum;


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_set_phb_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status:             [IN]        SQL command want to run
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_set_phb_status(MMI_BOOL status);

#ifdef __MMI_PHB_STARTUP_COPY_SIM__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_adn_used_first
 * DESCRIPTION
 *  This function is used to get ADN 1st-used records. It won't change when ADN is added or deleted.
 * PARAMETERS
 *  sim_interface:      [IN]        SIM1/SIM2
 * RETURNS
 *  ADN used No. (first time)
 *****************************************************************************/
U16 srv_phb_startup_get_adn_used_first(U8 sim_interface);
#endif /* __MMI_PHB_STARTUP_COPY_SIM__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_async_event_interface
 * DESCRIPTION
 *  This function is used to provide a sync.-to-async. interface.
 * PARAMETERS
 *  func:               [IN]        Execute function
 *  user_data:          [IN]        User data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_async_event_interface(srv_phb_async_func_type func, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_field_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_mask      [IN]        
 * RETURNS
 *  contact_p
 *****************************************************************************/
srv_phb_contact_info_struct *srv_phb_field_malloc(U32 field_mask);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_field_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_mask      [IN]        
 *  contact_p       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_field_free(U32 field_mask, srv_phb_contact_info_struct *contact_p);


#if defined(__MMI_PHB_SPEED_DIAL__)

/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_speed_dial_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_reload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_speed_dial_reload(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pre_set_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  store_index     [IN]        
 *  num_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_pre_set_speed_dial(U16 index, U16 store_index, U32 num_type);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pre_del_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_pre_del_speed_dial(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_revert_syncing_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_revert_syncing_speed_dial(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  store_index     [IN]        
 *  number          [IN]        
 *  num_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_update_speed_dial(U16 index, U16 store_index, U16 *number, U32 num_type);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_delete_speed_dial(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_is_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  MMI_TRUE if set
 *****************************************************************************/
MMI_BOOL srv_phb_speed_dial_is_sync(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_sync_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_phb_speed_dial_get_sync_status(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_speed_dial_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  num_type        [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_phb_query_speed_dial_key(U16 store_index, U32 num_type);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_store_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial store index
 *****************************************************************************/
U16 srv_phb_speed_dial_get_store_index(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial name
 *****************************************************************************/
U16 *srv_phb_speed_dial_get_name(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial number
 *****************************************************************************/
U16 *srv_phb_speed_dial_get_number(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_number_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial number type
 *****************************************************************************/
U32 srv_phb_speed_dial_get_number_type(U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_speed_dial_get_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 * RETURNS
 *  Speed dial entry
 *****************************************************************************/
mmi_phb_speed_dial_struct *srv_phb_speed_dial_get_entry(U16 index);

#endif /* defined(__MMI_PHB_SPEED_DIAL__) */


#ifdef __OP01_FWPBW__
void srv_phb_direct_dial_init(mmi_phb_speed_dial_struct *buf);
void srv_phb_direct_dial_save(U16 index, U16 *buf);
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_WIDGET_KEY_VIP_CONTACT__)

/*****************************************************************************
 * FUNCTION
 *  srv_phb_vip_contact_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_vip_contact_init(void);
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_name_display_type
 * DESCRIPTION
 *  get name display type
 * PARAMETERS
 *  void
 * RETURNS
 *  name display type
 *****************************************************************************/
extern srv_phb_name_display_type_enum srv_phb_get_name_display_type(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_name_display_type
 * DESCRIPTION
 *  set name display type
 * PARAMETERS
 *  type:         [IN]        name display type
 *  cb :          [IN]        call back function
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_phb_set_name_display_type(srv_phb_name_display_type_enum type, srv_phb_async_func_type cb, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_storage_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
phb_storage_enum srv_phb_get_storage_by_sim_id(U8 sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
U8 srv_phb_get_sim_id(phb_storage_enum storage);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_id_by_mod_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
U8 srv_phb_get_sim_id_by_mod_id(int mod_id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_l4c_mod_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
int srv_phb_get_l4c_mod_by_sim_id(U8 sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_fdn_name
 * DESCRIPTION
 *  This function is used to get fdn name by contact id.
 * PARAMETERS
 *  id:             [IN]        contact id
 * RETURNS
 *  extra# list count
 *****************************************************************************/
WCHAR* srv_phb_xmgnt_get_fdn_name(mmi_phb_contact_id id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_res_check_data_space
 * DESCRIPTION
 *  Check free space in data record before save to phonebook.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_phb_datamgr_res_check_data_space(U32 field_mask);

#endif /* PHBSRVIPROT_H */

