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
 *  vapp_dtcnt_wlan_settings.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_WLAN_SETTINGS_H__
#define __VAPP_DTCNT_WLAN_SETTINGS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "vapp_dtcnt_wlan_ui.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappWiFiSwitchCell
 *****************************************************************************/
class VappWiFiSwitchCell : public VcpFormItemSwitchCell
{
// Declaration
    VFX_DECLARE_CLASS(VappWiFiSwitchCell);

// Constructor / Destructor
public:
    VappWiFiSwitchCell();
    virtual ~VappWiFiSwitchCell();

// Method

// Overridable

// Override
public:
    virtual void onInit();
    virtual void onDeinit();

// Variable
private:
    VappWlanRepository          *m_repository;
    VcpConfirmPopup             *m_turnOffConfirm;
// Implementation 

public:

    void onSwitch(VcpFormItemSwitchCell*, VfxId, VfxBool);
    void onStopWiFiTethering(VfxBool result);
    void onConfirmBtnClicked(VfxObject* sender, VfxId id);
    static void stopWiFiTetheringCallback(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data);

#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__		
    void showConfirmPopupInFlightMode();
    void onButtonClick(VfxObject* sender, VfxU32 id);
#endif   
};

/***************************************************************************** 
 * Class VappWiFiSettingCell
 *****************************************************************************/
class VappWiFiSettingCell : public VcpFormItemLauncherCell
{
// Declaration
    VFX_DECLARE_CLASS(VappWiFiSettingCell);

// Constructor / Destructor
public:
    VappWiFiSettingCell();
    virtual ~VappWiFiSettingCell();

// Method

// Overridable

// Override
public:
    virtual void onInit ();
    virtual void onDeinit();

// Variable
private:
    VappWlanRepository          *m_repository;
    
// Implementation
public:
    void onTap(VcpFormItemCell*, VfxId);
};

#endif
