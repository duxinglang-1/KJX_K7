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
 *  vtst_rt_cp_mem_test_all.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  CP memory test for all CPs
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VTST_RT_CP_MEM_TEST_LIST_MENU_H__
#define __VTST_RT_CP_MEM_TEST_LIST_MENU_H__

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_cp_mem_test_main.h"

#include "vcp_button.h"
#include "vcp_image_button.h"
#include "vcp_navi_title_bar.h"
#include "vcp_photo_border_frame.h"
#include "vcp_switch.h"
#include "mmi_rp_srv_venus_component_button_def.h"
#include "vcp_list_menu.h"
#include "GlobalResDef.h"
#include "vcp_popup.h"
#include "vcp_info_balloon.h"


/***************************************************************************** 
 * Class VtstRtMemTestButton
 *****************************************************************************/

class VtstRtMemTestButton : public VtstRtMemTestObj
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestButton);

// Constructor / Destructor
public:
    VtstRtMemTestButton() {}

// Overridable
protected:
    virtual void testFunc()
    {
        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, this);
        button->setText(VFX_WSTR("test"));
        button->setRect(10, 10, 150, 50);
    }
};


/***************************************************************************** 
 * Class VtstRtMemTestImageButton
 *****************************************************************************/

class VtstRtMemTestImageButton : public VtstRtMemTestObj
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestImageButton);

// Constructor / Destructor
public:
    VtstRtMemTestImageButton() {}

// Overridable
protected:
    virtual void testFunc()
    {
        VcpImageButton *button;
        VFX_OBJ_CREATE(button, VcpImageButton, this);

        VcpStateImage imgList;
        imgList.setImage(
                VfxImageSrc(VCP_IMG_BUTTON_N),
                VfxImageSrc(VCP_IMG_BUTTON_P),
                VfxImageSrc(VCP_IMG_BUTTON_D),
                VfxImageSrc(VCP_IMG_BUTTON_H) );

        VfxS32 buttonWidth = 53;
        VfxS32 buttonHeight = 54;
        VfxS32 xStart = 10;
        VfxS32 yStart = 30;
        VfxS32 xOffset = buttonWidth + 15;
        VfxS32 yOffset = buttonHeight + 15;

        button->setImage(imgList);
        button->setRect(VfxRect(xStart, yStart, buttonWidth, buttonHeight));
        button->setIsStretchMode(VFX_TRUE);
    }
};


/***************************************************************************** 
 * Class VtstRtMemTestPhotoBorderFrame
 *****************************************************************************/

#ifdef __COSMOS_MMI_PACKAGE__
class VtstRtMemTestPhotoBorderFrame : public VtstRtMemTestObj
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestPhotoBorderFrame);

// Constructor / Destructor
public:
    VtstRtMemTestPhotoBorderFrame() {}

// Overridable
protected:
    virtual void testFunc()
    {
        // photo border frame
        VcpPhotoBorderFrame * photoBorder;
        VFX_OBJ_CREATE(photoBorder, VcpPhotoBorderFrame, this);
        photoBorder->setPos(100, 100);
        photoBorder->setMaxSize(VfxSize(150, 150) );
        photoBorder->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
        photoBorder->setImgContent(VfxImageSrc(IMG_GLOBAL_L1));
    }
};
#endif // __COSMOS_MMI_PACKAGE__

/***************************************************************************** 
 * Class VtstRtMemTestSwitch
 *****************************************************************************/

class VtstRtMemTestSwitch : public VtstRtMemTestObj
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestSwitch);

// Constructor / Destructor
public:
    VtstRtMemTestSwitch() {}

// Overridable
protected:
    virtual void testFunc()
    {
        // switch
        VcpSwitch *sw;
        VFX_OBJ_CREATE(sw, VcpSwitch, this);
        sw->setPos(VfxPoint(50, 50));
        sw->setChecked(VFX_TRUE);
    }
};


/***************************************************************************** 
 * Class VtstRtMemTestTitleBar
 *****************************************************************************/

class VtstRtMemTestTitleBar : public VtstRtMemTestObj
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestTitleBar);

// Constructor / Destructor
public:
    VtstRtMemTestTitleBar() {}

// Overridable
protected:
    virtual void testFunc()
    {
        // title bar
        VcpTitleBar * titleBar;
        VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
        titleBar->setPos(VfxPoint(0, 100));
    }
};


/***************************************************************************** 
 * Class VtstRtMemTestListMenu
 *****************************************************************************/

class VtstRtMemTestListMenu : public VtstRtMemTestObj, public IVcpListMenuContentProvider
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestListMenu);

// Constructor / Destructor
public:
    VtstRtMemTestListMenu() {}

// Overridable
protected:
    virtual void testFunc()
    {
        VcpListMenu *list;
        VFX_OBJ_CREATE(list, VcpListMenu, this);
        list->setSize(getSize());
        list->setContentProvider(this);
        list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
    }

// List menu
public:
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
    {
        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            text = VFX_WSTR("Today");
        }
        else
        {
            text = VFX_WSTR("Hello world");
        }
        return VFX_TRUE;
    }

    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType,VfxImageSrc &image) 
    {
        image.setResId(IMG_GLOBAL_L1);
        return VFX_TRUE;
    }

    virtual VfxU32 getCount() const {return 20; }
};


/***************************************************************************** 
 * Class VtstRtMemTestInfoBalloon
 *****************************************************************************/

class VtstRtMemTestInfoBalloon : public VtstRtMemTestObj
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestInfoBalloon);

// Constructor / Destructor
public:
    VtstRtMemTestInfoBalloon() {}

// Overridable
protected:
    virtual void testFunc()
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, VFX_WSTR("Failed balloon!"));
    }
};


/***************************************************************************** 
 * Class VtstRtMemTestMoreCommandPopup
 *****************************************************************************/

class VtstRtMemTestMoreCommandPopup : public VtstRtMemTestObj
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestMoreCommandPopup);

// Constructor / Destructor
public:
    VtstRtMemTestMoreCommandPopup() {}

// Overridable
protected:
    virtual void testFunc()
    {
        VcpMoreCommandPopup *m_moreCommandPopup;
        VFX_OBJ_CREATE(m_moreCommandPopup, VcpMoreCommandPopup, this);

        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->setAutoDestory(VFX_FALSE);
        m_moreCommandPopup->show(VFX_FALSE);
    }
};


/***************************************************************************** 
 * Class VtstRtMemTestInfoBalloon
 *****************************************************************************/

class VtstRtMemTestSelectPopup : public VtstRtMemTestObj
{
    VTEST_RT_MEM_TEST_CREATE(VtstRtMemTestSelectPopup);

// Constructor / Destructor
public:
    VtstRtMemTestSelectPopup() {}

// Overridable
protected:
    virtual void testFunc()
    {
        VcpSelectPopup *m_moreCommandPopup;
        VFX_OBJ_CREATE(m_moreCommandPopup, VcpSelectPopup, this);

        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->setAutoDestory(VFX_FALSE);
        m_moreCommandPopup->show(VFX_FALSE);
    }
};


#endif /* __AFX_RT_TEST__ */

#endif /*  __VTST_RT_CP_MEM_TEST_LIST_MENU_H__ */
