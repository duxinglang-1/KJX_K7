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
 *  vapp_helloworld.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif
#include "MMIDataType.h" /* mmi_id */
#ifdef __cplusplus
}
#endif

//#include "vfx_mc_include.h"

#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_text_frame.h"
#include "vfx_app_launcher.h"
#include "vcp_navi_title_bar.h"
#include "mmi_rp_vapp_lemei_def.h"
#include "Vcp_tool_bar.h"
#include "Vcp_image_button.h"
#include "vcp_tabctrl_page.h"
#include "vcp_list_menu.h"
#include "mmi_rp_file_type_def.h"

class VappLemeiApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappLemeiApp);

    public:
        virtual void onRun(void * args, VfxU32 argSize);
        void launchNormalUnifiedComposer(void);
        mmi_ret onProc(mmi_event_struct *evt);
};

class VappLemeiScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappLemeiScreen);

    public:
        virtual void on1stReady();
        
    private:
        
};

class VappLemeiButtonFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VappLemeiButtonFrame);

    public:
        virtual void onInit();
        enum VcpLemeiButtonTypeEnum
        {
            BTN_ADO,
            BTN_CAM,
            BTN_VDO,
        };
        enum
        {
#if (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__))
        VFX_BUTTON_IMG_1_X = 0,
        VFX_BUTTON_IMG_2_X = 81,//102,
        VFX_BUTTON_IMG_3_X = 159,
        VFX_BUTTON_1_OFFSET = 3,
        VFX_BUTTON_2_OFFSET = 0,
        VFX_BUTTON_3_OFFSET = 0,
        VFX_BUTTON_WIDTH = 78,//102,
        VFX_BUTTON_HEIGHT = 62,
#elif defined(__MMI_MAINLCD_320X480__)
        VFX_BUTTON_IMG_1_X = 0,
        VFX_BUTTON_IMG_2_X = 109,//102,
        VFX_BUTTON_IMG_3_X = 212,
        VFX_BUTTON_1_OFFSET = 5,
        VFX_BUTTON_2_OFFSET = 0,
        VFX_BUTTON_3_OFFSET = 1,
        VFX_BUTTON_WIDTH = 103,//102,
        VFX_BUTTON_HEIGHT = 84,
#elif defined(__MMI_MAINLCD_480X800__)
        VFX_BUTTON_IMG_1_X = 0,
        VFX_BUTTON_IMG_2_X = 162,//102,
        VFX_BUTTON_IMG_3_X = 319,
        VFX_BUTTON_1_OFFSET = 8,
        VFX_BUTTON_2_OFFSET = 2,
        VFX_BUTTON_3_OFFSET = 1,
        VFX_BUTTON_WIDTH = 153,//102,
        VFX_BUTTON_HEIGHT = 124,
#endif /*defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X400__))*/
        };
    VfxSignal1 <VcpLemeiButtonTypeEnum> m_signalButtonClicked;
    private:
        VcpButton *m_btnCam;
        VcpButton *m_btnAdo;
        VcpButton *m_btnVdo;
        VfxImageFrame *m_camImg;
        VfxImageFrame *m_AdoImg;
        VfxImageFrame *m_VdoImg;
        void onButtonClicked(VfxObject *sender, VfxId id);
        void onButtonStateChange(VfxObject* obj, VfxId id, VcpButtonStateEnum state);
};

class VappLemeiPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappLemeiPage);

    public:

        enum
        {
#if (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__))
        VFX_BUTTON_FRAME_X = 0,//6,
        VFX_BUTTON_FRAME_Y = 127,
        VFX_BUTTON_FRAME_WIDTH = 240,//228,
        VFX_BUTTON_FRAME_HEIGHT = 113
#elif defined(__MMI_MAINLCD_320X480__)
        VFX_BUTTON_FRAME_X = 0,//7,
        VFX_BUTTON_FRAME_Y = 157,
        VFX_BUTTON_FRAME_WIDTH = 320,//306,
        VFX_BUTTON_FRAME_HEIGHT = 142
#elif defined(__MMI_MAINLCD_480X800__)
        VFX_BUTTON_FRAME_X = 0,
        VFX_BUTTON_FRAME_Y = 240,//285,
        VFX_BUTTON_FRAME_WIDTH = 480,
        VFX_BUTTON_FRAME_HEIGHT = 177
#endif /*defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X400__))*/
        };


        VappLemeiPage();
        virtual void onInit();
        virtual void onDeinit();
        void LemeiEnterMultimediaApp(VappLemeiButtonFrame::VcpLemeiButtonTypeEnum id);
    private:
        //VcpImageButton *m_btnCam;
        //VcpButton *m_btnAdo;
        //VcpButton *m_btnVdo;
        VfxImageFrame *m_background;
        VappLemeiButtonFrame *m_btnFrame;
        VfxWString m_filepath;
        void *     m_camcoLimit;
        mmi_ret onProc(mmi_event_struct *evt);
        void LemeilaunchUnifiedComposer();
        void onButtonClicked(VappLemeiButtonFrame::VcpLemeiButtonTypeEnum id);
        void onToolBarTapped(VfxObject* sender, VfxId id);
        void enterLocalAudioSelector();
        void setImageFilter(FMGR_FILTER * filter);
        void setVideoFilter(FMGR_FILTER * filter);
        
};


class VappLemeiLocalAudioTabPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappLemeiLocalAudioTabPage);

// Override
public:
    virtual void onInit();
    VfxPage * onCreateTabPage(VfxId tabId);
};


class VappLemeiLocalAudioPage : public VfxPage, IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappLemeiLocalAudioPage);

    public:
        VappLemeiLocalAudioPage(){};
        VappLemeiLocalAudioPage(VfxId tabId);
//Override
    public:
        virtual void onInit();
        virtual VfxBool getItemText(VfxU32 index,                    
						    VcpListMenuFieldEnum fieldType,  
						    VfxWString &text,                
						    VcpListMenuTextColorEnum &color);
        virtual VfxBool getItemImage(
                            VfxU32 index,                    // [IN] the index of item
                            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                            VfxImageSrc &image              // [OUT] the image resource
                            );
        virtual VfxU32 getCount()const;
        void onItemShortTapped(
                            VcpListMenu *list,          // [IN] ListMenu pointer
                            VfxU32 index                // [IN] The selected menu item
                            );
        void init_audio_folder(U16* file_path, S8 drv_type, U16* folder_name);
        void setAudioFilter(FMGR_FILTER * filter);

    private:
        VfxS32 m_Id;
        VfxTextFrame *m_messageFrame;
        
};

