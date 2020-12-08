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
 *  vtst_rt_fallback_image.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  fallback image example for Venus UI
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vtst_rt_fallback_image.h"
#include "Unicodexdcl.h"


/***************************************************************************** 
 * Class VtstFallbackImageScr
 *****************************************************************************/

VtstFallbackImageScr::VtstFallbackImageScr() :
    m_imageFrame(NULL), m_imageFrame2(NULL)
{
}


void VtstFallbackImageScr::onInit()
{
    VfxAppCatScr::onInit();
    
    // Initialize the BG color
    setBgColor(VFX_COLOR_BLUE);

    // Prepare a broken image for test
    VfxU8 drvCard = SRV_FMGR_PHONE_DRV;
    VfxWString str;
    str = VfxWString().format("%c:\\1.jpg", drvCard); //1.jpg is broken image
    VfxImageSrc source = VfxImageSrc(str);    

    // Prepare a good image for test
    VfxWString str2;
    str2 = VfxWString().format("%c:\\2.jpg", drvCard); //2,jpg is good image
    VfxImageSrc source2 = VfxImageSrc(str2);

    // Prepare a invalid image path for test
    VfxWString str3;
    str3 = VfxWString().format("%c:\\123.jpg", drvCard); //123.jpg is invalid image path
    VfxImageSrc source3 = VfxImageSrc(str3);

    // Create a frame with broken image source
    VFX_OBJ_CREATE(m_imageFrame, VfxFrame, this);
    m_imageFrame->setPos(40, 40);
    m_imageFrame->setBgColor(VFX_COLOR_RED);
    m_imageFrame->setBounds(VfxRect(0, 0, 100, 100));
    m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_imageFrame->setImgContent(source);
    m_imageFrame->setFallbackImage(IMG_GLOBAL_L1);

    // Create a frame with good image source
    VFX_OBJ_CREATE(m_imageFrame2, VfxFrame, this);
    m_imageFrame2->setPos(40, 150);
    m_imageFrame2->setBgColor(VFX_COLOR_GREEN);
    m_imageFrame2->setBounds(VfxRect(0, 0, 100, 100));
    m_imageFrame2->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_imageFrame2->setImgContent(source2);
    m_imageFrame2->setFallbackImage(IMG_GLOBAL_L1);

    // Create a frame with invalid image path
    VFX_OBJ_CREATE(m_imageFrame3, VfxFrame, this);
    m_imageFrame3->setPos(150, 40);
    m_imageFrame3->setBgColor(VFX_COLOR_YELLOW);
    m_imageFrame3->setBounds(VfxRect(0, 0, 100, 100));
    m_imageFrame3->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_imageFrame3->setImgContent(source3);
    m_imageFrame3->setFallbackImage(IMG_GLOBAL_L1);

    //VfxDrawContext onDraw() test case
    VFX_OBJ_CREATE(m_imageFrame4 , VtstFrame1, this);
    m_imageFrame4->setPos(40, 270);
    m_imageFrame4->setBgColor(VFX_COLOR_RED);
    m_imageFrame4->setBounds(VfxRect(0, 0, 80, 80));
    m_imageFrame4->setFallbackImage(IMG_GLOBAL_L1);

    //VfxDrawContext onDraw() test case
    VFX_OBJ_CREATE(m_imageFrame5 , VtstFrame2, this);
    m_imageFrame5->setPos(150, 270);
    m_imageFrame5->setBgColor(VFX_COLOR_RED);
    m_imageFrame5->setBounds(VfxRect(0, 0, 80, 80));
    m_imageFrame5->setFallbackImage(IMG_GLOBAL_L1);

    //VfxDrawContext onDraw() test case
    VFX_OBJ_CREATE(m_imageFrame6 , VtstFrame3, this);
    m_imageFrame6->setPos(40, 360);
    m_imageFrame6->setBgColor(VFX_COLOR_RED);
    m_imageFrame6->setBounds(VfxRect(0, 0, 80, 80));
    m_imageFrame6->setFallbackImage(IMG_GLOBAL_L1);

}

VtstTestResultEnum vtst_fallback_image_create(VfxU32 param)
{
    VTST_START_SCRN(VtstFallbackImageScr);
    return VTST_TR_OK;
}


