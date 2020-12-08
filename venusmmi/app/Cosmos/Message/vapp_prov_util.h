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
 * ProvBoxAppUtil.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox app utility procedure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_PROV_UTIL_H__
#define __VCP_PROV_UTIL_H__

#include "vcp_include.h"

#ifdef __MMI_PROV_IN_UM__ 

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C"
#endif
{
#include "MMIDataType.h"

#include "UMSrvDefs.h"

#include "UMSrvStruct.h"

#include "ProvBoxSrvIProt.h"
}

#include "vapp_prov_base.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define VAPP_PROV_FLAG_INSTALLING          (0x0001UL)

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define VAPP_PROV_SET_FLAG(_flag, _cur_flag) \
            do {                             \
                (_flag) |= (_cur_flag);      \
            } while(0)                       
            
#define VAPP_PROV_CLR_FLAG(_flag, _clr_flag) \
            do {                             \
                (_flag) &= (~(_clr_flag));   \
            } while(0)                       

#define VAPP_PROV_FLAG_CHECK(_flag, _cur_flag) ((_flag) &= (_cur_flag))

#define VAPP_PROV_GET_AVALIABLE_VALUE(_param, _idx) \
                (_param) & (1 << (_idx))

#define VAPP_PROV_RESET_VALUE(_param, _idx, _type)    \
            do {                               \
                U8 value = (U8)(_param);       \
                value &= ~(1 << (_idx));       \
                (_param) = (_type)value;              \
            } while(0)

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef MMI_BOOL (*VAPP_PROV_CB_FUNC_P)(void* user_data);

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
   VfxU32 msg_id;
   void * op_obj;
   VAPP_PROV_CB_FUNC_P op_cb_func;
} vapp_prov_msg_op_obj_struct;

typedef struct
{
   MMI_ID parent_id;
} vapp_prov_box_cntx_struct;


/*----------------------------------------------------------------------------*/
/* Extern Function Declaration                                                */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C"
#endif
{
extern srv_um_addr_enum vapp_prov_addr_type_pbox2um(srv_provbox_addr_type_enum provbox_type);

extern srv_um_sim_enum vapp_prov_sim_pbox2um(mmi_sim_enum prov_box_sim);

extern MMI_BOOL vapp_prov_read_status_pbox2um(srv_provbox_msg_read_status_enum read_status);

extern srv_um_msg_box_enum vapp_prov_box_type_pbox2um(srv_provbox_box_type_enum srv_box_type);
  
extern MMI_BOOL vapp_prov_ip_addr_is_validate(U16 *ip, S32 len);

extern void vapp_prov_get_msg_address(
                WCHAR *addr, mmi_sim_enum sim_id,
                srv_provbox_msg_type_enum msg_type,
                srv_provbox_addr_struct* msg_addr);

extern void vapp_prov_add_address(
                srv_um_msg_detail_struct* detail,
                WCHAR* addr,
                srv_um_addr_enum type,
                srv_um_addr_group_enum group);
         
//extern void vapp_prov_remove_address(srv_um_msg_detail_struct* detail);

extern void vapp_prov_compose_data_time(WCHAR* data_time, U32 timestamp);

extern void vapp_prov_get_available_msg_address(
                WCHAR *avail_addr, 
                vapp_prov_msg_addr_type_enum *addr_type, 
                srv_provbox_addr_struct *msg_addr);

extern VfxU32 vapp_prov_get_status_icon_id(VfxU32 status);

extern VfxU16 vapp_prov_get_sim_msg_title(VfxU32 sim_idx);

extern void vapp_prov_msg_sent_install_req(U32 msg_id, S32 tran_id);

extern U8 vapp_prov_msg_handle_install_cnf(void *msg);
}


class VcpProvCnfmPopup : public VcpConfirmPopup
{
    //VFX_DECLARE_CLASS(VcpProvCnfmPopup);

public:
    VcpProvCnfmPopup();

    VcpProvCnfmPopup(
        VfxWString &text, 
        VcpPopupTypeEnum type,
        VcpConfirmPopupButtonSetEnum buttonSet);
    
    virtual void onInit();
    
    //void show(VfxBool isAnim) { VcpConfirmPopup::show(isAnim); }
    
private:
    VfxWString m_text;
    VcpPopupTypeEnum m_type;
    VcpConfirmPopupButtonSetEnum m_buttonSet;
};

#endif /* __MMI_PROV_IN_UM__  */

#endif /* __VCP_PROV_UTIL_H__ */
