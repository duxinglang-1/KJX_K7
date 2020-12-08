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
 *  vtst_rt_picker.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for picker
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
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vcp_base_picker.h"
#include "vtst_rt_main.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_app_cat_scr.h"
#include "mmi_rp_srv_venus_component_base_picker_def.h"

static const VfxWChar *year[10] = 
{
    (const VfxWChar *)L"2000",
    (const VfxWChar *)L"2001",
    (const VfxWChar *)L"2002",
    (const VfxWChar *)L"2003",
    (const VfxWChar *)L"2004",
    (const VfxWChar *)L"2005",
    (const VfxWChar *)L"2006",
    (const VfxWChar *)L"2007",
    (const VfxWChar *)L"2008",
    (const VfxWChar *)L"2009"
};

static const VfxWChar *month[12] = 
{
    (const VfxWChar *)L"JAN",
    (const VfxWChar *)L"FEB",
    (const VfxWChar *)L"MAR",
    (const VfxWChar *)L"APR",
    (const VfxWChar *)L"MAY",
    (const VfxWChar *)L"JUN",
    (const VfxWChar *)L"JUL",
    (const VfxWChar *)L"AUG",
    (const VfxWChar *)L"SEP",
    (const VfxWChar *)L"OCT",
    (const VfxWChar *)L"NOV",
    (const VfxWChar *)L"DEC"
};

static const VfxWChar *day[7] = 
{
    (const VfxWChar *)L"SUN",
    (const VfxWChar *)L"MON",
    (const VfxWChar *)L"TUE",
    (const VfxWChar *)L"WED",
    (const VfxWChar *)L"THU",
    (const VfxWChar *)L"FRI",
    (const VfxWChar *)L"SAT"
};
        
 
/***************************************************************************** 
 * Class VcpMyWheelMenu
 *****************************************************************************/

class VtstRtPicker : public VcpBasePicker, public IVcpBasePickerContentProvider
{
    
// Constructor / Destructor
public:
    VtstRtPicker()
        {}
    virtual ~VtstRtPicker(){}

// Override
protected:
    virtual void onInit()
    {       
        VcpBasePicker::onInit();

        setBounds(0, 0, 320, 166);
        setFieldCount(3);
        setFieldCellHeight(33);
        setUnitTextRect(0, VfxRect(12, 11, 78, 14));
        setUnitTextRect(1, VfxRect(102, 11, 78, 14));
        setUnitTextRect(2, VfxRect(192, 11, 118, 14));
        
        setFieldCellRect(0, VfxRect(12, 36, 78, 125));
        setFieldCellRect(1, VfxRect(102, 36, 78, 125));
        setFieldCellRect(2, VfxRect(192, 36, 118, 125));
        setContentProvider(this);

        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(14);

        VfxFontDesc fontDesc2;
        fontDesc2.size = VFX_FONT_DESC_VF_SIZE(22);

        VfxFontDesc fontDesc3;
        fontDesc3.size = VFX_FONT_DESC_VF_SIZE(30);

        VcpBasePickerFieldInfo tempFieldInfo;
        tempFieldInfo.index = 0;
        tempFieldInfo.isDataLoop = VFX_FALSE;
        tempFieldInfo.focusIndex = 1;
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
        tempFieldInfo.textColor = VfxColor(255, 123, 123, 123);
		tempFieldInfo.focusTextColor = VfxColor(255, 15, 15, 15);
		tempFieldInfo.unitTextColor = VFX_COLOR_WHITE;
#endif
		tempFieldInfo.textFont = fontDesc2;       
        tempFieldInfo.focusTextFont = fontDesc3;
        tempFieldInfo.unitTextVisible = VFX_TRUE;
        tempFieldInfo.unitTextString = VFX_WSTR("Year");

        tempFieldInfo.unitTextFont = fontDesc;
        setFieldInfo(tempFieldInfo);

        tempFieldInfo.index = 1;
        tempFieldInfo.isDataLoop = VFX_TRUE;
        tempFieldInfo.focusIndex = 2;
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
        tempFieldInfo.textColor = VfxColor(255, 123, 123, 123);
		tempFieldInfo.focusTextColor = VfxColor(255, 15, 15, 15);
		tempFieldInfo.unitTextColor = VFX_COLOR_WHITE;
#endif
        tempFieldInfo.textFont = fontDesc2;
        
        tempFieldInfo.focusTextFont = fontDesc3;
        tempFieldInfo.unitTextVisible = VFX_TRUE;
        tempFieldInfo.unitTextString = VFX_WSTR("Month");

        tempFieldInfo.unitTextFont = fontDesc;
        setFieldInfo(tempFieldInfo);

        tempFieldInfo.index = 2;
        tempFieldInfo.isDataLoop = VFX_FALSE;
        tempFieldInfo.focusIndex = 3;
#ifndef __MMI_VUI_COSMOS_CP_SLIM__
        tempFieldInfo.textColor = VfxColor(255, 123, 123, 123);
		tempFieldInfo.focusTextColor = VfxColor(255, 15, 15, 15);
		tempFieldInfo.unitTextColor = VFX_COLOR_WHITE;
#endif
        tempFieldInfo.textFont = fontDesc2;
        
        tempFieldInfo.focusTextFont = fontDesc3;
        tempFieldInfo.unitTextVisible = VFX_TRUE;
        tempFieldInfo.unitTextString = VFX_WSTR("Day");
        
        tempFieldInfo.unitTextFont = fontDesc;
        setFieldInfo(tempFieldInfo);

        /*
        setFieldIsDataLoop(0, VFX_FALSE);
        setFieldIsDataLoop(1, VFX_TRUE);
        setFieldIsDataLoop(2, VFX_FALSE);

        setFieldDataType(0, VCP_PICKER_DATA_TYPE_STRING);
        setFieldDataType(1, VCP_PICKER_DATA_TYPE_STRING);
        setFieldDataType(2, VCP_PICKER_DATA_TYPE_STRING);

        setFieldFocus(0, 1);
        setFieldFocus(1, 2);
        setFieldFocus(2, 3);

        setUnitTextString(0, VFX_WSTR("Year"));
        setUnitTextString(1, VFX_WSTR("Month"));
        setUnitTextString(2, VFX_WSTR("Day"));
        */
    }

    virtual VfxS32 getFieldCellCount(VfxS32 field)
    {
        if (field == 0)
        {
            return 10;
        }
        else if (field == 1)
        {
            return 12;
        }
        else
        {
            if (getFieldFocus(1) == 1)
            {
                // only six day a week in Feb
                return 6;
            }
            else
            {
                return 7;
            }
        }
    }

    virtual VfxWString onGetFieldString(VfxS32 field, VfxS32 cell)
    {
        if (field == 0)
        {
            return VFX_WSTR_STATIC(year[cell]);
        }
        else if (field == 1)
        {
            return VFX_WSTR_STATIC(month[cell]);
        }
        else
        {
            return VFX_WSTR_STATIC(day[cell]);
        }
    }

    virtual void onFieldFocusIndexChange(VfxS32 field, VfxS32 focusItem, VfxS32 previousFocusItem)
    {
        if (field == 1 && focusItem == 1)
        {
            setFieldFocus(2, 0);
        }
    }
    
};

class VtstRtPickerScr : public VtstRtScr
{
public:
    typedef VtstRtPickerScr Self;
    typedef VtstRtScr   Super;

// Variable
public:
    VtstRtPicker      *m_picker;

// Constructor / Destructor
public:
    VtstRtPickerScr() : m_picker(NULL){}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Picker Test"));

        VFX_OBJ_CREATE(m_picker, VtstRtPicker, this);
        m_picker->setPos(VfxPoint(0, 50));
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (event.keyCode == VFX_KEY_CODE_1)
            {
            }
            
        }
        return Super::onKeyInput(event);
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};

VtstTestResultEnum vtst_rt_picker(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtPickerScr);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
