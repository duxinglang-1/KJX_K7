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
 * VappWorldClockCui.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements world clock application.
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
 *****************************************************************************/
#ifndef __VAPP_WORLD_CLOCK_CUI_H__
#define __VAPP_WORLD_CLOCK_CUI_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "Vfx_string.h"
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcui_worldclock_select_city_gprot.h"

  
#ifdef __cplusplus
  extern "C"
  {
#endif
  
/****************************************************************************
 *class
 ***************************************************************************/

/***************************************************************************** 
 * World clock cui main screen Class 
 *****************************************************************************/

class VappWCCuiMainScr : public VfxMainScr
{
    //VFX_DECLARE_CLASS(VappWCCuiMainScr);

public:
    VappWCCuiMainScr();

    virtual void on1stReady();
private:
    void showSelectCityPage();
    void onCmdPopCallback(VfxObject *obj, VfxId id);
    void onCitySelected(VfxObject *sender, VfxU16 cityIndex);
private:

    VfxWString m_title;
    VfxU16 m_citySelect;
};

/***************************************************************************** 
 * World clock cui APP Class 
 *****************************************************************************/
class VappWCCui : public VfxCui
{

    VFX_DECLARE_CLASS(VappWCCui);
 
 public:  
    // Constructor 
    VappWCCui() {}
    // Override
    virtual void onRun(void *arg, VfxU32 argSize);
    virtual void onDeinit();
    void setTitle(const VfxWString title)
    {
        m_title = title;
    }
    VfxWString getTitle(void)
    {
        return m_title;
    }
    void setUsrData(void *user_data)
    {
        m_usrData = user_data;
    }
    void * getUsrData(void)
    {
        return m_usrData;
    }
    cui_wc_launch_struct getArg()
    {
        return m_arg;
    }
    void onCitySelect(VfxObject *sender, VfxU16 cityIndex);
private:
        
    VfxWString m_title;
    void * m_usrData;
    VappWCCuiMainScr *m_mainScr;
    cui_wc_launch_struct m_arg;
};
  
  
#ifdef __cplusplus
  }
#endif

#endif


