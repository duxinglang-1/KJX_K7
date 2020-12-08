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
 *  Vapp_dm_otap.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management otap header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DM_HS_H__
#define __VAPP_DM_HS_H__
#include "MMI_features.h"
#if defined(SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_list_menu.h"
#include "vapp_cca_gprot.h"

extern "C"
{
#include "DmSrvIprot.h"
}

/***************************************************************************** 
 * Functions
 *****************************************************************************/
extern "C" void vcui_dm_otap_create(void);

/***************************************************************************** 
 * Class VcuiDmOtapCui
 *****************************************************************************/
 
class VcuiDmOtapCui : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiDmOtapCui);

// Constructor / Destructor
public:
    VcuiDmOtapCui() {}
    ~VcuiDmOtapCui() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
        );

// Method
private:

// Variable

// Override

// Declaration

// Variable
private:

};


/***************************************************************************** 
* Class VappDmOtapMainScrn
*****************************************************************************/

class VappDmOtapMainScrn : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappDmOtapMainScrn);

// Constructor / Destructor
public:
    VappDmOtapMainScrn();
    ~VappDmOtapMainScrn();

public:
    void rspSrv(srv_cca_status_enum result);

private:

// Override
protected:
    virtual void on1stReady();

// Method
public:

// Variable
private:
    VfxBool m_rspSrv;
};


/***************************************************************************** 
* Class VappDmOtapProfInfoPage
*****************************************************************************/

class VappDmOtapProfInfoPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappDmOtapProfInfoPage);
private:
    enum {
#if defined(__MMI_MAINLCD_320X480__)
         LEFT_GAPS = 8,
         RIGHT_GAPS = 8,
         TOP_GAPS = 8,
         BOTTOM_GAPS = 8
#elif defined(__MMI_MAINLCD_480X800__)
         LEFT_GAPS = 14,
         RIGHT_GAPS = 14,
         TOP_GAPS = 14,
         BOTTOM_GAPS = 14
#else
         LEFT_GAPS = 5,
         RIGHT_GAPS = 5,
         TOP_GAPS = 5,
         BOTTOM_GAPS = 5
#endif
         } ;

// Constructor / Destructor
public:
    VappDmOtapProfInfoPage() {}
    ~VappDmOtapProfInfoPage() {}

private:
    void composeProfInfo(VcpTextView *text);
    void onToolBarClick(VfxObject *obj, VfxId id);

// Override
protected:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param){}
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


#endif
#endif
