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
 *  vtst_rt_fallback_image.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Fallback image example for Venus UI
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VTST_FALLBACK_IMAGE_H__
#define __VTST_FALLBACK_IMAGE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
// For VfxAppCatScr
#include "vfx_app_cat_scr.h"
#include "vfx_cpp_base.h"
#include "vfx_frame.h"
#include "FileMgrSrvGProt.h"

/***************************************************************************** 
 * Class VtstDefaultErrorImage
 *****************************************************************************/
class VtstFallbackImageScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstFallbackImageScr();

// Override
protected:
    virtual void onInit();
    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        return 5000;
    }

// Vairable
protected:
    VfxFrame *m_imageFrame;
    VfxFrame *m_imageFrame2;
    VfxFrame *m_imageFrame3;
    VfxFrame *m_imageFrame4;
    VfxFrame *m_imageFrame5;
    VfxFrame *m_imageFrame6;
};


class VtstFrame1 : public VfxFrame
{ 
// Constructor / Destructor
public:
    VtstFrame1()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VfxFrame::onInit();
    }
    
    virtual void onDraw(VfxDrawContext &dc)
    {      
        VfxU8 drvCard = SRV_FMGR_PHONE_DRV;
        VfxWString str;
        str = VfxWString().format("%c:\\123.jpg", drvCard);
        VfxImageSrc source = VfxImageSrc(str);  

        dc.drawImage(0, 0, source);
    }    
};


class VtstFrame2 : public VfxFrame
{ 
// Constructor / Destructor
public:
    VtstFrame2()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VfxFrame::onInit();
    }
    
    virtual void onDraw(VfxDrawContext &dc)
    {      
        VfxU8 drvCard = SRV_FMGR_PHONE_DRV;
        VfxWString str;
        str = VfxWString().format("%c:\\1.jpg", drvCard);
        VfxImageSrc source = VfxImageSrc(str);  

        dc.drawImage(0, 0, source);
    }    
};


class VtstFrame3 : public VfxFrame
{ 
// Constructor / Destructor
public:
    VtstFrame3()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VfxFrame::onInit();
    }
    
    virtual void onDraw(VfxDrawContext &dc)
    {      
        VfxU8 drvCard = SRV_FMGR_PHONE_DRV;
        VfxWString str;
        str = VfxWString().format("%c:\\1.jpg", drvCard);
        VfxImageSrc source = VfxImageSrc(str);  

        dc.drawResizedImage(VfxRect(0, 0, 50, 50), source);
    }    
};


#endif /* __VTST_FALLBACK_IMAGE_H__ */

