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
 *  vapp_nitz_gprot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_NITZ_GPROT_H__
#define __VAPP_NITZ_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#ifdef __MMI_NITZ__
#include "vapp_ncenter_base_cell.h"

extern "C"
{
#include "NITZSrvGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    VAPP_NITZ_OFF,
    VAPP_NITZ_ON,
    VAPP_NITZ_ALWAYS_ASK,

    VAPP_NITZ_SETTING_ENUM_END
} VappNitzSettingEnum;
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappNitzLaunchCell : public VcpFormItemLauncherCell
{

    VFX_DECLARE_CLASS(VappNitzLaunchCell);
    public:
    virtual void onInit();
    virtual void onTap(VcpFormItemCell* sender, VfxId senderId);
    virtual VfxWString getHint();
    virtual void updateCell() {setHintText(getHint());};

    // Methods
    void updateNitzSetting(VfxU8 setting);

    // Variables
    protected:
    VappNitzSettingEnum m_nitzSetting;
};
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
class VappNitzController : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappNitzController);
    // Methods
    public:
    VappNitzController();
    ~VappNitzController();

    VappNitzSettingEnum getNITZSetting();
    void setNITZSetting(VappNitzSettingEnum setting);

    // Used for ask dialog
    void confirmUpdate();
    void ignoreUpdate();


    // Internal use
    // Save data from indication to temp variable
    void updateReqHandler(const srv_nitz_context_struct *data);

    VfxBool checkTimeZone(void);
    void saveTempData(const srv_nitz_context_struct *data);
    void updateSystemData();

    // Variables
    public:
    //VfxSignal0 m_signalUpdateAvailable;
    VfxSignal0 m_signalSettingUpdate;
    
    protected:
    // Temp value for confirm
    nitz_nw_name_struct m_tempOperatorName[MMI_SIM_TOTAL]; 
    VfxBool m_updateTime;
    VfxBool m_updateLocalTimeZone;
    VfxFloat m_tempTimeZone;
    MYTIME m_tempTime;
    VfxU32 m_tempRecvTick;
    VfxBool m_updateDayLightSaving;
    VfxU8  m_tempdayLightSaving;
};
#endif /* __MMI_NITZ__ */
#endif /* __VAPP_NITZ_GPROT_H__ */
 
