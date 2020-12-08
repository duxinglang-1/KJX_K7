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
 *  vapp_imgclip_cui.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_IMGCLIP_H__
#define __VAPP_IMGCLIP_H__

#ifdef __MMI_COSMOS_IMAGECLIPPER__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vcui_imgedt_gprot.h"
#include "vapp_imgedt_util.h"

/***************************************************************************** 
 * Class VappImgEdtClipCuiPage
 *****************************************************************************/
class VappImgEdtClipCuiPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappImgEdtClipCuiPage);
    
public:
    VappImgEdtClipCuiPage();

private:
    enum ImgClipCuiState
    {
        STATE_IDLE,
        STATE_INITED,
        STATE_DRAWING,
        STATE_READY,
        STATE_SAVING,
        STATE_DONE,
        STATE_ERROR,

        STATE_TOTAL
    };

public:
    void cancelAll();

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

private:
    void prepareMem();
    void unprepareMem();
    gdi_handle prepareLayer(const VfxRect& layerRect,
                            const VfxU8* mem_p, 
                            const VfxU8* path);
    void unprepareLayer(gdi_handle * hdlr_p);
    
    void showFrame(VfxFrame* preview,
                   const VfxRect& rect,
                   const VfxU8* mem_p);
    void setWaitIconShown(VfxBool is_active);
    
    VfxS32 updateImgRect();
    void updateImgClipRect();
    void updateClipRect();
    VfxS32 saveImage();
    void onCuiStateChange(VfxS32 state);
    void errorHandle(VfxS32 pre_state);

    VfxS32 translateGDIResult(gdi_result result);
    gdi_handle createGdiJob(gdi_handle layer, 
                            const VfxRect &rect, 
                            const VfxU8* path);
    void cancelGdiJob(gdi_handle *hdl_p);
    void onGdiJobCallback(gdi_result result, gdi_handle handle);
    static void gdiJobCallback(gdi_result result, gdi_handle handle);

    void onBottomBtnClicked(VfxObject *obj, VfxId id);
    void onErrorPopupCallback(VfxObject* sender,VfxId btn_id);
    void onErrorPopup(VfxResId strId, VfxBool needCallback = VFX_TRUE);

public:
    static VfxPage *m_pageInst;

private:
    VcpImgEdtClipWindow     *m_clipWd;
    VcpImgEdtBottomBar      *m_bottomBar;
    VcpActivityIndicator    *m_waitIcon;
    VfxFrame                *m_previewFrame;

    void            *m_pDecodeMem;
    void            *m_pPreviewLayerMem;
    gdi_handle      m_previewHdl;
    gdi_handle      m_renderHdl;
    gdi_handle      m_jobHdl;

    mmi_id  m_appId;
    VfxS32  m_state;
    VfxS32  m_lastError;
    VfxBool m_isRedrawBg;
    
    VfxRect m_previewRect;
    VfxRect m_previewClipRect;
    VfxRect m_imgRect;
    VfxRect m_imgClipRect;
    VfxRect m_saveRect;
    VfxRect m_saveClipRect;
};


/***************************************************************************** 
 * Class VappImgClipScr
 *****************************************************************************/
class VappImgClipScr : public VappImgEdtBaseScr
{
    VFX_DECLARE_CLASS(VappImgClipScr);

public:
    virtual void on1stReady();

private:
    VappImgEdtClipCuiPage *m_clipPage;        
};


/***************************************************************************** 
 * Class VappImgClipCui
 *****************************************************************************/
class VappImgClipCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappImgClipCui);

public:  
    VappImgClipCui();  

    mmi_ret sendEvent(cui_imgclip_evet_enum event,
                      cui_imgclip_result result = CUI_IMGEDT_OK);
    //VfxResId getErrorString(S32 error_id);
    void setParentData(S32 parent_data);
    VfxU32 getParentData();
    void setLayoutStyle(cui_imgclip_layout_enum layout);
    cui_imgclip_layout_enum getLayoutStyle();
    void setResolution(cui_imgclip_resolution_enum type);
    cui_imgclip_resolution_enum getResolution();
    void setIsRatioFixed(VfxBool is_fixed);
    VfxBool getIsRatioFixed();
    void setRatio(VfxS32 ratio_w, VfxS32 ratio_h);
    void getRatio(VfxS32 *ratio_w, VfxS32 *ratio_h);
    void setDestDimension(VfxS32 width, VfxS32 height);
    void setlimitDimension(VfxS32 width, VfxS32 height);
    void getDestDimension(VfxS32 *width, VfxS32 *height);
    void getSrcDimension(VfxS32 *width, VfxS32 *height);
    void setDestPath(VfxU8 *path);
    void getDestPath(VfxU8 *path);
    void getSavedSize(VfxSize &size);    
    VfxWString getDestFilePath();
    VfxWString getSrcFilePath();
    void getUserData(VfxU32 *user_data);
	void savePbmFile(VfxBool saveABpmfile);
	VfxBool isSavePbmFile();
	VfxWString getPbmFilePath();

protected:
    virtual void onDeinit();
    virtual void onRun(void *arg, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    VfxScrRotateTypeEnum getRotation();

private:  
    VappImgClipScr          *m_clipScr;
    
    VfxS32 m_state;
     
    VfxU32 m_parentData;
    VfxS32 m_ratioW;
    VfxS32 m_ratioH;
    VfxS32 m_destWidth;
    VfxS32 m_destHeight;
    VfxS32 m_limitWidth;
    VfxS32 m_limitHeight;
    VfxBool m_isFixed;
    VfxBool m_isLimited;
    cui_imgclip_layout_enum m_layout;

    VfxU32  m_userData;
    VcpImgEdtNamingHelper   *m_namingHelper;
    VfxWString              m_srcFilePath;
    VfxWString              m_destFilePath;
	VfxBool                 m_saveAPbmFlie;
};


#endif /* __MMI_COSMOS_IMAGECLIPPER__ */

#endif /* __VAPP_IMGCLIP_H__ */
