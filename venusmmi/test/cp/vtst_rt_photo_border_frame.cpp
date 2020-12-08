#include "vfx_config.h"

#if defined(__AFX_RT_TEST__)  && defined(__MMI_VUI_COSMOS_CP__)

#include "vfx_uc_include.h"
#include "vcp_photo_border_frame.h"
#include "vtst_rt_main.h"
#include "vcp_res.h"
#include "Gui_virtual_keyboard_res.h"
#include "mmi_rp_srv_venus_component_button_def.h"
#include "mmi_rp_vapp_cosmos_mainmenu_def.h"
#include "vcp_async_image_frame.h"
#include "vfx_mc_include.h"

/***************************************************************************** 
 * Class VtstPhotoBorderFrameScr
 *****************************************************************************/
class VtstPhotoBorderFrameScr : public VfxAppScr
{
//    VFX_DECLARE_CLASS(VtstPhotoBorderFrameScr);


// Override
protected:
    virtual void onInit();

// Member Variables
private:
    VcpPhotoBorderFrame * m_photoBorder;
    VcpPhotoBorderFrame * m_photoBorder2;
    VfxTextFrame *m_clickCount;
    VfxS32 m_count;
    void onClicked();
};


class VtstMyPhotoBorderFrame : public VcpPhotoBorderFrame
{
public:
    VtstMyPhotoBorderFrame(const VfxWString & filename);

protected:
    virtual void onInit();
private:
    VfxWString m_filename;
    VcpAsyncImageFrame * m_asyncImage;
};

VtstMyPhotoBorderFrame::VtstMyPhotoBorderFrame(const VfxWString & filename):
    m_filename(filename)
{
}

void VtstMyPhotoBorderFrame::onInit()
{
    VcpPhotoBorderFrame::onInit();

    VFX_OBJ_CREATE_EX(m_asyncImage, VcpAsyncImageFrame, this, (m_filename, IMG_ID_VAPP_COSMOS_MAINMENU_ICON_HOME, VfxSize(80, 80) ) );
    setImageFrame(m_asyncImage);
}


void VtstPhotoBorderFrameScr::onInit()
{
    VfxAppScr::onInit();
    m_count = 0;
    setBgColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_photoBorder, VcpPhotoBorderFrame, this);
    m_photoBorder->setPos(100, 100);
    m_photoBorder->setMaxSize(VfxSize(150, 150) );
    m_photoBorder->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
//    m_photoBorder->setImgContent(VfxImageSrc(VCP_IMG_BUTTON_TEST_1) );
    //m_photoBorder->setImgContent(VfxImageSrc(IMG_ID_VKBD_CUSTOM_UIELEMENT_VIRTUALKEYBOARD_QWERTY_BACKGROUND_V_KBD_BG_QWERTY_320X205) );
    m_photoBorder->setImgContent(VfxImageSrc(IMG_ID_VAPP_COSMOS_MAINMENU_ICON_HOME) );
    m_photoBorder->m_signalClicked.connect(this, &VtstPhotoBorderFrameScr::onClicked);

    VFX_OBJ_CREATE(m_clickCount, VfxTextFrame, this);
    m_clickCount->setPos(VfxPoint(50, 50));
    m_clickCount->setBgColor(VFX_COLOR_WHITE);
    m_clickCount->setColor(VFX_COLOR_BLACK); 

    // custom photo border frame
    VFX_OBJ_CREATE_EX(m_photoBorder2, VtstMyPhotoBorderFrame, this, (VFX_WSTR("E:\\1B.BMP") ) );
    m_photoBorder2->setPos(100, 300);
    m_photoBorder2->setMaxSize(VfxSize(150, 150) );
    m_photoBorder2->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
}

void VtstPhotoBorderFrameScr::onClicked()
{
    ++m_count;
    VfxWString str;
    str.format("%d", m_count);
    m_clickCount->setString(str);
}


class VtstPhotoBorderFrameApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstPhotoBorderFrameApp );

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

VFX_IMPLEMENT_CLASS("VtstPhotoBorderFrameApp", VtstPhotoBorderFrameApp, VfxApp);

void VtstPhotoBorderFrameApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstPhotoBorderFrameScr *scr;
    VFX_OBJ_CREATE(scr, VtstPhotoBorderFrameScr, this);
    scr->show();
}


VtstTestResultEnum vtst_rt_photo_border_frame(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize(
        APP1_BASE,
        VFX_OBJ_CLASS_INFO(VtstPhotoBorderFrameApp),
        GRP_ID_ROOT, 204800 * 3,
        NULL, 0);
    return VTST_TR_OK;
}
#endif // __AFX_RT_TEST__

