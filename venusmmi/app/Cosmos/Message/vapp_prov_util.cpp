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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vcp_include.h"

#ifdef __MMI_PROV_IN_UM__ 

#ifdef __cplusplus
extern "C" 
#endif
{
#include "MMIDataType.h"

//#include "APPSDKFrameworkGProt.h"

#include "wgui_categories_util.h"

#include "UMSrvDefs.h"

#include "UMSrvStruct.h"

#include "mmi_frm_mem_gprot.h"

#include "mmi_rp_app_cosmos_global_def.h"

#include "vcp_popup_data_type.h"

#include "mmi_rp_vapp_prov_msg_def.h"

#include "ProvBoxSrvIProt.h"
}

#include "vapp_prov_util.h"
#include "vapp_prov_base.h"

#ifdef __cplusplus
extern "C" 
#endif
{

static const VfxU16 g_vapp_sim_msg_title[] = 
{
#if (MMI_MAX_SIM_NUM == 1)
    STR_ID_VAPP_PROV_MSG_SIM_NAME,
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    STR_ID_VAPP_PROV_MSG_SIM1_NAME,
    STR_ID_VAPP_PROV_MSG_SIM2_NAME,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    STR_ID_VAPP_PROV_MSG_SIM3_NAME,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    STR_ID_VAPP_PROV_MSG_SIM4_NAME
#endif
};


VfxU16 vapp_prov_get_sim_msg_title(VfxU32 sim_idx)
{
    return g_vapp_sim_msg_title[sim_idx];
}


/*****************************************************************************
 * FUNCTION
 *  vapp_prov_addr_type_pbox2um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  provbox_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_um_addr_enum vapp_prov_addr_type_pbox2um(srv_provbox_addr_type_enum provbox_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_addr_enum um_addr_type = SRV_UM_ADDR_EMPTY;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (provbox_type)
    {
        case SRV_PROVBOX_ADDR_TYPE_PHONENUM:
        {
            um_addr_type = SRV_UM_ADDR_PHONE_NUMBER;
        }
        break;

        case SRV_PROVBOX_ADDR_TYPE_IPV4:
        {
            um_addr_type = SRV_UM_ADDR_IP_ADDRESS;
        }
        break;

        case SRV_PROVBOX_ADDR_TYPE_TEXT:
        {
            um_addr_type = SRV_UM_ADDR_PLAIN_TEXT;
        }
        break;
            
        default:
        break;
    }
    
    return um_addr_type;
}



srv_um_sim_enum vapp_prov_sim_pbox2um(mmi_sim_enum prov_box_sim)
{
    srv_um_sim_enum um_sim = SRV_UM_SIM_UNCLASSIFIED;

     switch (prov_box_sim)
    {
        case MMI_SIM1:
        {
            um_sim = SRV_UM_SIM_GSM_SIM1;
        }
        break;
            
    #if (MMI_MAX_SIM_NUM > 1) 
        case MMI_SIM2:
        {
            um_sim = SRV_UM_SIM_GSM_SIM2;
        }
        break;
            
        case MMI_SIM3:
        {
            um_sim = SRV_UM_SIM_GSM_SIM3;
        }
        break;
            
        case MMI_SIM4:
        {
            um_sim = SRV_UM_SIM_GSM_SIM4;
        }
        break;
            
        case MMI_SIM_ALL:
        {
            um_sim = SRV_UM_SIM_ALL;
        }
        break;
     #endif
            
        default:
        break;
    }
    
    return um_sim;
}


MMI_BOOL vapp_prov_read_status_pbox2um(srv_provbox_msg_read_status_enum read_status)
{
    MMI_BOOL result = MMI_FALSE;


    if (read_status == SRV_PROVBOX_MSG_READ_STATUS_UNREAD)
    {
        result = MMI_FALSE;
    }
    else if (read_status == SRV_PROVBOX_MSG_READ_STATUS_READ)
    {
        result = MMI_TRUE;
    }

    return result;
}

srv_um_msg_box_enum vapp_prov_box_type_pbox2um(srv_provbox_box_type_enum srv_box_type)
{
    srv_um_msg_box_enum um_box_type = SRV_UM_MSG_BOX_NONE;


    switch (srv_box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
        {
            um_box_type = SRV_UM_MSG_BOX_INBOX;
        }
        break;
            
        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
        {
            um_box_type = SRV_UM_MSG_BOX_ARCHIVE;
        }
        break;
            
        case SRV_PROVBOX_BOX_TYPE_ALL:
        {
            um_box_type = SRV_UM_MSG_BOX_ALL;
        }
        break;
        
        default:
        break;
    }
    
    return um_box_type;
}

void vapp_prov_get_msg_address(
         WCHAR *addr, mmi_sim_enum sim_id,
         srv_provbox_msg_type_enum msg_type, 
         srv_provbox_addr_struct* msg_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *name = NULL;
    S32 len;
    U16 str_id = vapp_prov_get_sim_msg_title(mmi_frm_sim_to_index(sim_id));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_type)
    {
        case SRV_PROVBOX_MSG_TYPE_SIM_MMSICP:
        {
            name = (WCHAR*) get_string(str_id);
        }
        break;

        default:
        {
            if (mmi_wcslen((const WCHAR*)msg_addr->addr) > 0)
            {
                name = (WCHAR*) msg_addr->addr;
            }
            else
            {
                name = (WCHAR*) get_string(STR_ID_VAPP_PROV_MSG_NO_NUMBER);
            }
        }
        break;
    }
    
    len = mmi_wcslen((WCHAR*) name);

    if (len < VAPP_PROV_IP_MAX_LEN)
    {
        mmi_wcscat((WCHAR*) addr, (const WCHAR*) name);
    }
    else
    {
        mmi_wcsncat((WCHAR*) addr, (const WCHAR*) name, VAPP_PROV_ADDR_MAX_LEN);
    }
}

MMI_BOOL vapp_prov_ip_addr_is_validate(U16 *ip, S32 len)
{
    U16 *p;
    U16 tmp = 0;
    S32 seg_len = 0;
    S32 seg_val = 0;
    U16 *seg_p;
    S32 read_len;
    S32 seg_num = 0;

    if (len > VAPP_PROV_IP_MAX_LEN)
    {
        return MMI_FALSE;
    }

    p = ip;
    seg_p = ip;
    seg_num = 1;
    while(p)
    {
        if (*p == VAPP_PROV_IP_DOT ||
            *p == 0)
        {
            if (*p != 0)
            {
                tmp = *p;
                *p = 0;
            }
            mmi_ucs2toi((S8*) seg_p, &seg_val, &read_len);
            if (seg_val > VAPP_PROV_IP_MAX_SEG_VAL)
            {
                *p = tmp;
                return MMI_FALSE;

            }

            if (tmp != 0)
            {
                *p = tmp;
                tmp = 0;
            }

            if (*p == 0)
            {
                return MMI_TRUE;
            }
            p++;
            seg_p = p;
            seg_len = 0;
            seg_num++;
            if (seg_num > VAPP_PROV_IP_MAX_SEG_NUM)
            {
                return MMI_FALSE;    
            }
            continue;
        }
        else
        {
            p++;
            seg_len++;
            if (seg_len > VAPP_PROV_IP_MAX_SEG_LEN)
            {
                return MMI_FALSE;
            }
        }
    }
    return MMI_FALSE;
}


void vapp_prov_add_address(
         srv_um_msg_detail_struct* detail,
         WCHAR* addr,
         srv_um_addr_enum type,
         srv_um_addr_group_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //before slim......
    /*if (&(detail->address.addr) == NULL)
    {
        detail->address.addr = addr;
        detail->address.next = detail->address.previous = NULL;
        detail->address.type = type;
        detail->address.group = group;
    }
    else
    {
        detail->address.addr = addr;
        detail->address.group = group;
        detail->address.next  = NULL;
        detail->address.previous = NULL;
        detail->address.type = type;
    }*/
    detail->address.addr = addr;
    detail->address.group = group;
    detail->address.next  = NULL;
    detail->address.previous = NULL;
    detail->address.type = type;
}

void vapp_prov_compose_data_time(WCHAR* data_time, U32 timestamp)
{
    U32 local_sec = 0;
    applib_time_struct time = {0};
    U8 dttemp[VAPP_PROV_DATA_TIME_BUF_SIZE];


    /* date */
    local_sec = applib_dt_sec_utc_to_local(timestamp);
    applib_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);

    memset(dttemp, 0x00, VAPP_PROV_DATA_TIME_BUF_SIZE);
    date_string((MYTIME*) & time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) data_time, (S8*) dttemp);
    mmi_ucs2cat((S8*) data_time, (S8*) VAPP_PROV_UCS2_SPACE);

    /* time */
    memset(dttemp, 0x00, VAPP_PROV_DATA_TIME_BUF_SIZE);
    time_string((MYTIME*) & time, (UI_string_type) dttemp, DT_IDLE_SCREEN);
    mmi_ucs2cat((S8*) data_time, (S8*) dttemp);
}


void vapp_prov_get_available_msg_address(WCHAR *avail_addr, vapp_prov_msg_addr_type_enum *addr_type, srv_provbox_addr_struct *msg_addr)
{
    if (msg_addr->addr[0] != 0)
    {
         *addr_type = VAPP_PROV_MSG_ADDR_TYPE_NUM;
    }
    else
    {
         *addr_type = VAPP_PROV_MSG_ADDR_TYPE_STR;
    }

    if (msg_addr->addr_len >= VAPP_PROV_MSG_SEND_ADDR_MAX_LEN)
    {
       memcpy((void*)avail_addr, (const void*)msg_addr->addr, sizeof(U16) * VAPP_PROV_MSG_SEND_ADDR_MAX_LEN);       
    }
    else
    {
        mmi_wcscpy((WCHAR *)avail_addr, (const WCHAR*)msg_addr->addr);
    }
}


VfxU32 vapp_prov_get_status_icon_id(VfxU32 status)
{
    return IMG_ID_VAPP_PROV_MSG_INDICTOR_ICON;
}
}

/*****************************************************************************
 * Class VcpProvCnfmPopup
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VcpProvCnfmPopup", VcpProvCnfmPopup, VcpConfirmPopup);


VcpProvCnfmPopup::VcpProvCnfmPopup() : m_type(VCP_POPUP_TYPE_FAILURE), m_buttonSet(VCP_CONFIRM_BUTTON_SET_NONE)
{
}

VcpProvCnfmPopup::VcpProvCnfmPopup(
                           VfxWString &text, 
                           VcpPopupTypeEnum type,
                           VcpConfirmPopupButtonSetEnum buttonSet) : 
                           m_text(text), m_type(type), m_buttonSet(buttonSet)
{
}

void VcpProvCnfmPopup::onInit()
{
    VcpConfirmPopup::onInit();
    setText(m_text);
    setInfoType(m_type);
    setButtonSet(m_buttonSet);
}


#endif /* __MMI_PROV_IN_UM__ */

