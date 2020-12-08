/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_dialer_core.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DIALER_CORE_H__
#define __VAPP_DIALER_CORE_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_dialer_cp.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "UCMGprot.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class IDialerOperation
 *****************************************************************************/
class IDialerOperation : public VfxBase
{
public:
    enum DialerCallTypeEnum
    {
        SIM1_CALL = MMI_SIM1,
        SIM2_CALL = MMI_SIM2,
        SIM3_CALL = MMI_SIM3,
        SIM4_CALL = MMI_SIM4,
        VIDEO_CALL,
        SIM_CALL_END,
    };

public:
    virtual void onSendKey(VfxWChar *str, mmi_sim_enum sim){};
    virtual void onCallBtn(DialerCallTypeEnum type, VfxWChar *str){};
    virtual void onPoundBtn(VfxWChar *str){};
    virtual void onSaveToContactBtn(VfxWChar *str){};
    void setParentScr(VfxMainScr *scr){m_scr = scr;}
    VfxMainScr* m_scr;

protected:
    srv_ucm_call_type_enum getDialType(DialerCallTypeEnum type);
    static void setDialerPreferSIM(DialerCallTypeEnum type);

private:
    mmi_id m_groupId;
};


/***************************************************************************** 
 * Class DialerOperationClassic
 *****************************************************************************/
class DialerOperationClassic : public IDialerOperation
{
public:
    virtual void onSendKey(VfxWChar *str, mmi_sim_enum sim);
    virtual void onCallBtn(DialerCallTypeEnum type, VfxWChar *str);
    virtual void onPoundBtn(VfxWChar *str);
    virtual void onSaveToContactBtn(VfxWChar *str);

private:
    void makeCall(VfxWChar *str, DialerCallTypeEnum type);
    static void dialCallback(mmi_ucm_after_make_call_cb_struct* make_call_cb_para);
    VfxBool languageSwitch(VfxWChar *str);
};


/***************************************************************************** 
 * Class DialerOperationCUI
 *****************************************************************************/
class DialerOperationCUI : public IDialerOperation
{
public:
    virtual void onSendKey(VfxWChar *str, mmi_sim_enum sim);
    virtual void onCallBtn(DialerCallTypeEnum type, VfxWChar *str);
};


extern "C"
{   
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
extern void vapp_dialer_language_switch(void *scr, U8* language_SSC);
#else
extern void vapp_dialer_language_switch(void *scr, U8 language_id);
#endif
extern MMI_BOOL mmi_dialer_ssc_process_chv(WCHAR *str, void *screen);
}

#endif /* __VAPP_DIALER_CORE_H__ */

