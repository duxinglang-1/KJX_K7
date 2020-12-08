/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vtst_rt_xml_loader.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for XML Loader
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_xml_loader.h"
#include "vfx_datatype.h"
#include "vfx_xml_enum.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_app_cat_scr.h"
#include "vfx_primitive_frame.h"

extern "C"
{
#include "GlobalResDef.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define DATA_U32(_d0)                   ((VfxU32)(_d0))
#define DATA_U16(_d0, _d1)              ((VfxU32)(_d0) + ((VfxU32)(_d1) << 16))
#define DATA_U8(_d0, _d1, _d2, _d3)     (((VfxU32)(_d0)) + ((VfxU32)(_d1) << 8) + ((VfxU32)(_d2) << 16) + ((VfxU32)(_d3) << 24))



/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

#include "..\xml\vfx_xml_enum.h"

static VfxU32 g_vtstRtXmlLoaderTestData0[] =
{
    DATA_U8('V', 'X', VFX_XML_VER_MAJOR, VFX_XML_VER_MINOR),
    DATA_U16(VFX_XML_PROP_ID_VfxObject_items, VFX_XML_CLASS_ID_VfxImageFrame),
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_pos),
    DATA_U32(10), DATA_U32(20), // VfxPoint
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_bounds),
    DATA_U32(30), DATA_U32(40), DATA_U32(50), DATA_U32(60), // VfxRect
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_bgColor),
    DATA_U32(0xaabbccdd), // VfxColor
    
    DATA_U16(VFX_XML_PROP_ID_VfxObject_items, VFX_XML_CLASS_ID_VfxTimer),
    DATA_U32(VFX_XML_PROP_ID_VfxObject_name),
    DATA_U16(2, 2),    // String type, Count
    DATA_U16(L't', L'0'),
    DATA_U16(0, 0),
    DATA_U32(VFX_XML_PROP_ID_VfxTimer_startDelay),
    DATA_U32(12345), // VfxTimer
    DATA_U32(VFX_XML_PROP_ID_Unknown),
    
    DATA_U32(VFX_XML_PROP_ID_Unknown)
};


static VfxU32 g_vtstRtXmlLoaderTestData1[] =
{
    DATA_U8('V', 'X', VFX_XML_VER_MAJOR, VFX_XML_VER_MINOR),
    DATA_U16(VFX_XML_PROP_ID_VfxObject_items, VFX_XML_CLASS_ID_VfxFrame),
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_pos),
    DATA_U32(50), DATA_U32(100),    
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_bounds),
    DATA_U32(0), DATA_U32(0), DATA_U32(50), DATA_U32(70), // VfxRect    
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_bgColor),
    DATA_U32(VFX_COLOR_RED),    // VfxColor
    
    DATA_U16(VFX_XML_PROP_ID_VfxObject_items, VFX_XML_CLASS_ID_VfxFrame),
    DATA_U32(VFX_XML_PROP_ID_VfxObject_name),
    DATA_U16(2, 2),    // String type, Count
    DATA_U16(L'f', L'1'),
    DATA_U16(0, 0),
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_pos),
    DATA_U32(10), DATA_U32(10), // VfxPoint
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_bounds),
    DATA_U32(0), DATA_U32(0), DATA_U32(20), DATA_U32(30), // VfxRect
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_bgColor),
    DATA_U32(VFX_COLOR_YELLOW), // VfxColor
    DATA_U32(VFX_XML_PROP_ID_Unknown),
    
    DATA_U16(VFX_XML_PROP_ID_VfxObject_items, VFX_XML_CLASS_ID_VfxFrame),
    DATA_U32(VFX_XML_PROP_ID_VfxObject_name),
    DATA_U16(2, 2),    // String type, Count
    DATA_U16(L'f', L'2'),
    DATA_U16(0, 0),
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_pos),
    DATA_U32(30), DATA_U32(30), // VfxPoint
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_bounds),
    DATA_U32(0), DATA_U32(0), DATA_U32(20), DATA_U32(30), // VfxRect
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_bgColor),
    DATA_U32(VFX_COLOR_YELLOW), // VfxColor
    DATA_U32(VFX_XML_PROP_ID_Unknown),
    
    DATA_U32(VFX_XML_PROP_ID_Unknown)
};

static VfxU32 g_vtstRtXmlLoaderTestData2[] =
{
    DATA_U8('V', 'X', VFX_XML_VER_MAJOR, VFX_XML_VER_MINOR),
    DATA_U16(VFX_XML_PROP_ID_VfxObject_items, VFX_XML_CLASS_ID_VfxImageFrame),
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_pos),
    DATA_U32(50), DATA_U32(200), // VfxPoint
    DATA_U32(VFX_XML_PROP_ID_VfxImageFrame_resId),
    DATA_U32(IMG_GLOBAL_L5),    // VfxS32
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_size),
    DATA_U32(30), DATA_U32(40), // VfxSize
    DATA_U32(VFX_XML_PROP_ID_VfxFrame_contentPlacement),
    DATA_U32(VFX_XML_ENUM_ID_VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE), // Enum
    DATA_U32(VFX_XML_PROP_ID_Unknown)
};


/***************************************************************************** 
 * class VtstRtXmlLoader
 *****************************************************************************/

class VtstRtXmlLoader : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtXmlLoader()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("XML Loader Test"));
    }

    virtual int start()
    {
        VfxFrame *frame0 = (VfxFrame *)VfxXmlLoader::createObjectBegin(
            (VfxU8 *)g_vtstRtXmlLoaderTestData0, 
            NULL,
            this);

        VfxTimer *timer0 = (VfxTimer *)VfxXmlLoader::findObjByName(VFX_WSTR("t0"));
        
        VfxXmlLoader::createObjectEnd();
        
        check(frame0 != NULL, VFX_WSTR("Create object #1"));
        check(frame0->isKindOf(VFX_OBJ_CLASS_INFO(VfxFrame)), VFX_WSTR("Create object #2"));
        check(timer0 != NULL, VFX_WSTR("Find object #1"));
        check(timer0->isKindOf(VFX_OBJ_CLASS_INFO(VfxTimer)), VFX_WSTR("Find object #2"));
        
        if (frame0 != NULL)
        {
            check(frame0->getPos() == VfxPoint(10, 20), VFX_WSTR("VfxPoint type"));
            check(frame0->getBounds() == VfxRect(30, 40, 50, 60), VFX_WSTR("VfxRect type"));
            check(frame0->getBgColor() == VfxColor(0xaabbccdd), VFX_WSTR("VfxColor type"));
        }

        if (timer0 != 0)
        {
            check(timer0->getStartDelay() == 12345, VFX_WSTR("VfxMsec type"));
        }
            
        return 0;
    }
};


VtstTestResultEnum vtst_rt_xml_loader(VfxU32 param)
{
    VTST_START_SCRN(VtstRtXmlLoader);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * class VtstRtXmlLoader2
 *****************************************************************************/

class VtstRtXmlLoader2 : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtXmlLoader2()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("XML Loader Test"));
    }

    virtual int start()
    {
#if 1
        VfxFrame *frame0 = (VfxFrame *)VfxXmlLoader::createObjectBegin(
            (VfxU8 *)g_vtstRtXmlLoaderTestData1, 
            NULL,
            this);

        VfxFrame *frame0a = (VfxFrame *)VfxXmlLoader::findObjByName(VFX_WSTR("f1"));
        VfxFrame *frame0b = (VfxFrame *)VfxXmlLoader::findObjByName(VFX_WSTR("f2"));

        VfxXmlLoader::createObjectEnd();

        frame0a->setBorder(VFX_COLOR_PURPLE, 2);
        frame0b->setBorder(VFX_COLOR_PURPLE, 1);
        
        VfxFrame *frame1;
        VFX_OBJ_CREATE(frame1, VfxImageFrame, this);
        VfxXmlLoader::load(frame1, (VfxU8 *)g_vtstRtXmlLoaderTestData2);
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Correct?"));
        return -1;
    }


    virtual void end()
    {
    }
};


VtstTestResultEnum vtst_rt_xml_loader2(VfxU32 param)
{
    VTST_START_SCRN(VtstRtXmlLoader2);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

