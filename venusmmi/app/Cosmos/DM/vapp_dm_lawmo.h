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
 *  vapp_dm_lawmo.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management LAWMO UI header file.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DM_LAWMO_H__
#define __VAPP_DM_LAWMO_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_list_menu.h"
extern "C"
{
#include "DmSrvIprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C"
{
extern MMI_ID vappDmLawmoLockEvtHdlr();
extern MMI_ID vappDmLawmoWipeEvtHdlr();
extern mmi_ret vappDmLawmoScreenLockPreLockHdlr(mmi_event_struct *evt);
extern mmi_ret vappDmLawmoLockIndHdlr(mmi_event_struct *evt);
extern mmi_ret vappDmLawmoWipeIndHdlr(mmi_event_struct *evt);
}
/***************************************************************************** 
 * Class VappDmLawmoLockMainScrn
 *****************************************************************************/

class VappDmLawmoLockMainScrn : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappDmLawmoLockMainScrn);

// Constructor / Destructor
public:
    VappDmLawmoLockMainScrn() {}
    ~VappDmLawmoLockMainScrn() {}

protected:
    virtual void on1stReady();
};


/***************************************************************************** 
 * Class VappDmLawmoLock
 *****************************************************************************/

class VappDmLawmoLock : public VfxApp
{
    VFX_DECLARE_CLASS(VappDmLawmoLock);

// Constructor / Destructor
public:
    VappDmLawmoLock() {}
    ~VappDmLawmoLock() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );

    virtual void onInit();

    virtual void onDeinit();

    virtual mmi_ret onProc(mmi_event_struct *evt);
    VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);


// Method
private:

// Variable

// Override

// Declaration

// Variable
private:
};


/***************************************************************************** 
 * Class VappDmLawmoLockPage
 *****************************************************************************/

class VappDmLawmoLockPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappDmLawmoLockPage);

// Constructor / Destructor
public:
    VappDmLawmoLockPage() {}
    ~VappDmLawmoLockPage() {}

public:
    static mmi_ret leaveHdlr(mmi_event_struct *evt);

private:
    void dialSos(VfxObject* obj, VfxId itemId);

// Override
protected:
    virtual void onInit();
    virtual void onEnter();
};


/***************************************************************************** 
 * Class VappDmLawmoWipeMainScrn
 *****************************************************************************/

class VappDmLawmoWipeMainScrn : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappDmLawmoWipeMainScrn);

// Constructor / Destructor
public:
    VappDmLawmoWipeMainScrn();
    ~VappDmLawmoWipeMainScrn() {}

protected:
    virtual void onInit();
};


/***************************************************************************** 
 * Class VappDmLawmoWipe
 *****************************************************************************/

class VappDmLawmoWipe : public VfxApp
{
    VFX_DECLARE_CLASS(VappDmLawmoWipe);

// Constructor / Destructor
public:
    VappDmLawmoWipe() {}
    ~VappDmLawmoWipe() {}

// Method
public:
    virtual void onRun(
        void* args,
        VfxU32 argSize
    );

    virtual mmi_ret onProc(mmi_event_struct *evt);
    VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);


// Method
private:

// Variable

// Override

// Declaration

// Variable
private:
};

#endif /* __VAPP_DM_LAWMO_H__ */

