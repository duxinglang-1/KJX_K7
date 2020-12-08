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
 *  vapp_javaagencymidsinstall.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_JAVAAGENCYMIDINSTALL_H__
#define __VAPP_JAVAAGENCYMIDINSTALL_H__
#ifdef __J2ME__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_status_icon_bar.h"
#include "vapp_java_srv.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappJavaMidInstallProgress: public VcpIndicatorPopup
{
    VFX_DECLARE_CLASS(VappJavaMidInstallProgress);
    public:
        VappJavaMidInstallProgress(){};
        virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


class VappJavaMidInstallconfirm: public VcpConfirmPopup
{
    VFX_DECLARE_CLASS(VappJavaMidInstallconfirm);
    public:
        VappJavaMidInstallconfirm(){};
        virtual VfxBool onKeyInput(VfxKeyEvent &event);
};
class VappJavaMidInstallAuthInputPopup: public VcpInputPopup
{
    VFX_DECLARE_CLASS(VappJavaMidInstallAuthInputPopup);
    public:
        VappJavaMidInstallAuthInputPopup(){};
        virtual VfxBool onKeyInput(VfxKeyEvent &event);
};
#ifndef J2ME_SLIM_MEMORY_SUPPORT
class VappJavaMidStopScreen : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappJavaMidStopScreen);
private:
    //VfxBool is_need_abort;
    VfxScrRotateTypeEnum rotateType;
    VappJavaMidInstallconfirm* confirmPopup;
    VcpIndicatorPopup *terminatingPopup;
    VcpStatusIconBar *statusBar; // naozijinshuile,zheyangsheji

public:
    VappJavaMidStopScreen():
        statusBar(NULL), confirmPopup(NULL),terminatingPopup(NULL)//,is_need_abort(VFX_TRUE)
                {setIsSmallScreen();};
    void showStopConfirmDialog();
    void showTerminating();
    void stopConfirm(VfxObject *obj, VfxId id);
    void onEnter(VfxBool isBackward);
    void onInit(void); 
    //void onDeinit(void); 
    void onProcessClose(void);
    virtual void onBack();
    virtual void onSnapshotEnter();
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  
    ~VappJavaMidStopScreen(){};
};

#endif
class VappJavaMidInstallScreen : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappJavaMidInstallScreen);
private:
    VfxBool is_pushinstall_confirm;
    VfxBool is_need_abort;
    VfxScrRotateTypeEnum rotateType;
    VappJavaMidInstallProgress* progressBar;
    VappJavaMidInstallAuthInputPopup * authInputPopup;
    VcpTitleBar * authTitle;
    VappJavaMidInstallconfirm* confirmPopup;
    VappJavaMidInstallconfirm * option;
    VcpIndicatorPopup *terminatingPopup;
    VcpStatusIconBar *statusBar; // naozijinshuile,zheyangsheji
public:
    VcpCommandPopup* installConfirmPopup;
    VappJavaMidInstallScreen():
        statusBar(NULL),
        installConfirmPopup(NULL),
        progressBar(NULL), authInputPopup(NULL), authTitle(NULL),
        confirmPopup(NULL),option(NULL),terminatingPopup(NULL),is_need_abort(VFX_TRUE),
        is_pushinstall_confirm(VFX_FALSE)
        {setIsSmallScreen();};
    ~VappJavaMidInstallScreen(){};
    void showConfirmDialog(VfxU16*);
    void installConfirm(VfxObject *obj, VfxId id);
    virtual void onBack();
    void JavaInstallStart();
    void updateProgress(VfxFloat);
    void onCanceled(VfxObject * obj,VfxFloat id);
    void rmsConfirmDialog();
    void rmsConfirm(VfxObject *obj, VfxId id);
    void showAuthDialog();
    void onAuthInputBtnClicked(VfxObject* sender, VcpInputPopupButtonEnum id);
    void setDisplayStyle();
    void onInstallSelectDrvClick(VfxObject *obj, VfxId id);
    void selectInstallDrv();
    void showPushInstallDialog();
    void pushInstallConfirm(VfxObject *obj, VfxId id);
    void showDMInstallDialog();
    void dmInstallConfirm(VfxObject *obj, VfxId id);
    void setNeedAbortInstall(VfxBool abort);
    void onEnter(VfxBool isBackward);
    void onInit(void); 
    void onDeinit(void); 
    void onProcessClose(void);
    virtual void onSnapshotEnter();
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );  
};
#endif
#endif /*__VAPP_JAVAAGENCYSRC_H__*/

