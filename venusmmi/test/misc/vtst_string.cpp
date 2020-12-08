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
 *  vtst_string.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  A string example for Venus UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_string.h"

#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_app_cat_scr.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"

extern "C"
{
#include "GlobalResDef.h"
}


/***************************************************************************** 
 * Class VtstStringScr
 *****************************************************************************/

VtstStringScr::VtstStringScr() :
    m_strMember(VFX_WSTR("<MEMBER>"))
{
}


void VtstStringScr::onInit()
{
    VfxAppCatScr::onInit();

    setBgColor(VFX_COLOR_BLUE);

    // Temp text frame
    VfxTextFrame *text_frame = NULL;
    
    /*
     * Test #1 : member and constant string
     */
    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setPos(VfxPoint(10, 10));
    text_frame->setString(m_strMember);

    /*
     * Test #2 : local and resource string
     */
    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setPos(VfxPoint(10, 30));
    text_frame->setString(VFX_WSTR_RES(STR_GLOBAL_LOADING));

    /*
     * Test #3 : Compare and assign string
     */
    VfxWString str_temp_1(m_strMember);
    VfxWString str_temp_2(m_strMember);

    if (str_temp_1 == str_temp_2)
    {
        str_temp_1 = VFX_WSTR("TRUE");
    }
    else
    {
        str_temp_1 = VFX_WSTR("FALSE");
    }

    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setPos(VfxPoint(10, 50));
    text_frame->setString(str_temp_1);

    /*
     * Test #4 : Compare with other string
     */
    if (str_temp_2 == VFX_WSTR("<MEMBER>"))
    {
        str_temp_1 = VFX_WSTR("true");
    }
    else
    {
        str_temp_1 = VFX_WSTR("false");
    }

    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setPos(VfxPoint(10, 70));
    text_frame->setString(str_temp_1);

    /*
     * Test #5 : Append string
     */
    VfxWString str_temp_3;
    for (VfxS32 i = 0; i < 5; i++)
    {
        str_temp_3 += VFX_WSTR(">");
    }

    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setPos(VfxPoint(10, 90));
    text_frame->setString(str_temp_3);


    /*
     * Test #6 : Format string
     */
    VfxWString str_temp_4(VFX_WSTR("123456"));
    VfxWString str_temp_5;
    str_temp_5.format("length=%u", str_temp_4.getLength());
        
    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setPos(VfxPoint(10, 110));
    text_frame->setString(str_temp_5);
}

