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
 *  vmpayment.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_SAL_PAYMENT__

#include "vmpayment.h"
#include "alixpay.h"
#include "vmmacrostub.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "mmi_rp_app_mre_def.h"
#include "wgui_categories_util.h"
#include "custom_data_account.h"
#include "DtcntSrvGprot.h"
#include "vmlog.h"
#include "vmpromng.h"
#include "MRESrvDownloadGprot.h"

static ali_pay_back g_app_cb = NULL;
static VMINT g_handle = NULL;

extern VMUINT vm_get_account_id(VMUINT account_id, VMUINT8 app_id);

static alios_sim_enum svm_get_sim(srv_dtcnt_sim_type_enum e);
static void svm_adp_alipay_cb(void * user);


static void svm_adp_alipay_cb(void * user)
{

    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_90 );

    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_92 , g_handle);
    if ((0 < g_handle) && (VM_PMNG_OP_OK != vm_pmng_set_ctx(g_handle)))
    {        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_95 );
        return;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_98 , g_handle);
    g_app_cb((void*)user);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_100 , user);
    vm_pmng_reset_ctx();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_102 );
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_103 );
}


VM_H_BUYER vm_create_buyer(vm_payment_type_enum e)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_109 );
    
    if (VM_BUYER_ALIPAY == e)
    {
        g_handle = vm_pmng_get_app_handle();
        return 0x00;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_117 );
    return -1;
}

VMINT vm_purchase_item(VM_H_BUYER h, void * data, purchase_cb cb)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char * order = data;
    VMUINT account_id = 0;
    //VMINT apn = VM_TCP_APN_CMNET;
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_NONE;
    cbm_app_info_struct app_info = {0};
    VMUINT8 app_id = 0;
    MMI_BOOL ret_b = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_137 );
    if (NULL == order)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_140 );
        return VM_PURCHASE_RET_ERR_PARAM;
    }
    
    
#if defined(__COSMOS_MMI_PACKAGE__)  
    // SIM type
    
    srv_dtcnt_get_sim_preference(&sim_type);
    
    if (sim_type == SRV_DTCNT_SIM_TYPE_NONE)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_152 );
        return VM_PURCHASE_RET_ERR_SIM;
    }
    
#endif

    // account id
#ifdef __PLUTO_MMI_PACKAGE__
    app_info.app_icon_id = GetRootTitleIcon(IMAGE_MRE_ICON);
#else
    app_info.app_icon_id = GetRootTitleIcon(IMAGE_MRE_LARGE_ICON);
#endif
    app_info.app_str_id = STR_MRE_TITLE;
    app_info.app_type = DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_NO_PX;
    cbm_register_app_id_with_app_info(&app_info, &app_id);

#if __MMI_MRE_DTCNT_SETTING__ /* defined(__COSMOS_MMI_PACKAGE__) */
    {
    VMINT i = 0;
    switch(sim_type)
    {
        case SRV_DTCNT_SIM_TYPE_1:
            {
                i = srv_mre_da_get_account_id(SRV_MRE_DA_SIM1);
            }
            break;
        case SRV_DTCNT_SIM_TYPE_2:
            {
                i = srv_mre_da_get_account_id(SRV_MRE_DA_SIM2);
            }
            break;
        default:
            /* Other card use default */
            i = CBM_DEFAULT_ACCT_ID;
            break;
    }
    account_id = cbm_encode_data_account_id((kal_uint32)i, (cbm_sim_id_enum)(sim_type - 1), app_id, (kal_bool)0);
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_187 , app_id, account_id, sim_type);

#else

#ifdef __MRE_SAL_SIM__	
    /* encode account id, using default automatic account ID */
    account_id = vm_get_account_id(CBM_DEFAULT_ACCT_ID, app_id);
    ret_b = srv_dtcnt_get_sim_info(account_id, &sim_type);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_195 , ret_b, account_id, sim_type);
    //ASSERT(ret_b);
#else
    account_id = 0xFFFFFFFF;
#endif

#endif

    ASSERT(0xFFFFFFFF != account_id);
    
    cbm_deregister_app_id(app_id);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_207 , sim_type, account_id);
    
    g_app_cb = cb;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_210 , g_app_cb, cb);

    alixpay(order, svm_get_sim(sim_type), account_id, (ali_pay_back)svm_adp_alipay_cb);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_214 );

    return VM_PURCHASE_RET_ERR_SUCCESS;

}

void vm_release_buyer(VM_H_BUYER h)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_222 );
    if (0x00 == h)
    {
        g_handle = NULL;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_227 );

}

static alios_sim_enum svm_get_sim(srv_dtcnt_sim_type_enum e)
{
    alios_sim_enum ret_e = ALIOS_SIM_1;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_234 );
    switch (e)
    {
    case SRV_DTCNT_SIM_TYPE_1:
        {
            ret_e = ALIOS_SIM_1;
        }
        break;
    case SRV_DTCNT_SIM_TYPE_2:
        {
            ret_e = ALIOS_SIM_2;
        }
        break;
    case SRV_DTCNT_SIM_TYPE_3:
        {
            //ret_e = ALIOS_SIM_3;
        }
        break;
    case SRV_DTCNT_SIM_TYPE_4:
        {
            //ret_e = ALIOS_SIM_41;
        }
        break;
    case SRV_DTCNT_SIM_TYPE_NONE:
        {
            ret_e = ALIOS_SIM_ANY;
        }
    default:
        {}
        break;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_266 , e, ret_e);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMPAYMENT, TRC_MRE_VMPAYMENT_268 );
    return ret_e;
}



#include "mmi_rp_app_alipay_adp_def.h"

#define  PartnerID1    "2088301265823075"
#define  SellerID1     "2088301265823075"
#define  MD5_KEY1      "qi3ckotphdqr9vkc6az4fuqlh6nso4op"

#define  PartnerID    "2088601074681393"
#define  SellerID     "2088601074681393"
#define  MD5_KEY      "scabn19un0wsodbfjom8olag3c3qo21w"

extern void aliproc_MD5Make(unsigned char * buf, unsigned char* digest);
extern void alios_misc_get_rand_key(char *aKey,unsigned int key_len);

void demo_alipay_make_order_tst(VMSTR order, VMINT idx, void * partner, void * seller, void * md5_key)
{
    int i =0;
    char keybuf[20+2];
    char pre[128] = {0};
    unsigned short*pre1;
    char md5_out[34] = {0};
    memset((char*)order, 0, 1024);
    sprintf(order, "%s%s%s%s%s", "partner=\"",(char*)partner,"\"&seller=\"",(char*)seller,"\"&out_trade_no=\"");

    memset(keybuf, 0, 20+2);
    alios_misc_get_rand_key(keybuf,20);
    strncpy((char*)order+strlen((char*)order), keybuf, 20);
    pre1 = (unsigned short*)GetString(STR_ID_ALIPAY_DEMO_ORDER1+idx);
    //alios_str_conv_ucs2_utf8(pre1,mmi_ucs2strlen((char*)pre1),pre,127);
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)pre,127,(kal_uint8 *)pre1);
    strncpy((char*)order+strlen((char*)order), pre, strlen(pre));
    strncpy(order+strlen((char*)order), (char*)md5_key, strlen((char*)md5_key));	
    aliproc_MD5Make((char*)order,md5_out);
    
    sprintf((char*)order+strlen((char*)order)-strlen((char*)md5_key), "%s%s%s%s", "&sign_type=\"MD5\"","&sign=\"",md5_out,"\"");
}



#endif

