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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    inputs.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is used to implement general input event handle
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

/*****************************************************************************
* Include                                                                     
*****************************************************************************/
//#include "mmi_frm_gprot.h"

//RHR Add
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "kal_general_types.h"

/*****************************************************************************
* Defines                                                                     
*****************************************************************************/
//#define __MMI_GENERAL_INPUT_UT__
#define INPUT_SUPPORT_TOUCH              (0x04)
#define INPUT_SUPPORT_FINGER_TOUCH       (0x08)
#define INPUT_SUPPORT_MULTI_TOUCH        (0x10)
#define INPUT_TYPE_MAP_TAL_ENTRY_NUM     sizeof(g_input_type_map) / sizeof(g_input_type_map[0])

/*****************************************************************************
* Enum & Structure                                                                     
*****************************************************************************/

typedef enum
{
    MMI_FRM_NORMAL_KEYPAD,
    MMI_FRM_REDUCED_KEYPAD,
    MMI_FRM_QWERTY_KEYPAD,
    MMI_FRM_KEYPAD_NONE
} keypad_type_enum;

typedef struct
{
    U8 pattern;  /*
                  * bit0-1 keypad type, 
                  * bit 2 support touch or not, 
                  * bit 3 support finger or not,
                  * bit 4 support multi touch or not
                  */
    U8 input_type;
} input_type_map_struct;

#ifdef __MMI_GENERAL_INPUT_UT__
typedef struct
{
    MMI_BOOL is_touch;
    MMI_BOOL is_ft;
    MMI_BOOL is_multi;
    MMI_BOOL is_slide;
    MMI_BOOL is_slide_closed;    
    U8 keypad_type;
} query_input_style_test;
#endif

/*****************************************************************************
* Local function declaration                                                                     
*****************************************************************************/
static keypad_type_enum get_keypad_type(void);
static MMI_BOOL is_support_ft(void);
static MMI_BOOL is_support_touch(void);
static MMI_BOOL is_support_multi_touch(void);
static U16 get_input_type(void);
static U16 get_prefer_device(void);
static MMI_BOOL is_side_slide_support(void);
static MMI_BOOL is_slide_close(void);

/*****************************************************************************
* Global Variables                                                                     
*****************************************************************************/
const static input_type_map_struct g_input_type_map[] =
{
    {   
        MMI_FRM_QWERTY_KEYPAD, 
        KEYPAD_QWERTY_NON_TOUCH
    },
    {
        MMI_FRM_QWERTY_KEYPAD | INPUT_SUPPORT_TOUCH, 
        KEYPAD_QWERTY_SINGLE_TOUCH_PEN
    },
    {
        MMI_FRM_QWERTY_KEYPAD | INPUT_SUPPORT_TOUCH| INPUT_SUPPORT_FINGER_TOUCH, 
        KEYPAD_QWERTY_SINGLE_TOUCH_FINGER
    },
    {   
        MMI_FRM_QWERTY_KEYPAD | INPUT_SUPPORT_TOUCH| INPUT_SUPPORT_FINGER_TOUCH | INPUT_SUPPORT_MULTI_TOUCH,
        KEYPAD_QWERTY_MULTI_TOUCH_FINGER
    },
    {
        MMI_FRM_NORMAL_KEYPAD,
        KEYPAD_NUMERICAL_NON_TOUCH
    },
    { 
        MMI_FRM_NORMAL_KEYPAD | INPUT_SUPPORT_TOUCH, 
        KEYPAD_NUMERICAL_SINGLE_TOUCH_PEN
    },
    {
        MMI_FRM_NORMAL_KEYPAD | INPUT_SUPPORT_TOUCH| INPUT_SUPPORT_FINGER_TOUCH,
        KEYPAD_NUMERICAL_SINGLE_TOUCH_FINGER
    },
    {
        MMI_FRM_NORMAL_KEYPAD | INPUT_SUPPORT_TOUCH | INPUT_SUPPORT_FINGER_TOUCH | INPUT_SUPPORT_MULTI_TOUCH, 
        KEYPAD_NUMEIRCAL_MULTI_TOUCH_FINGER
    },
    {
        MMI_FRM_REDUCED_KEYPAD | INPUT_SUPPORT_TOUCH, 
        KEYPAD_NAVIGATION_SINGLE_TOUCH_PEN
    },
    {
        MMI_FRM_REDUCED_KEYPAD | INPUT_SUPPORT_TOUCH | INPUT_SUPPORT_FINGER_TOUCH, 
        KEYPAD_NAVIGATION_SINGLE_TOUCH_FINGER
    },
    {
        MMI_FRM_REDUCED_KEYPAD | INPUT_SUPPORT_TOUCH | INPUT_SUPPORT_FINGER_TOUCH | INPUT_SUPPORT_MULTI_TOUCH, 
        KEYPAD_NAVIGATION_MULTI_TOUCH_FINGER
    }
};

#ifdef __MMI_GENERAL_INPUT_UT__
static query_input_style_test g_query_input;
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_query_input_style
 * DESCRIPTION
 *  This API is used to query the preferred input style and the input type
 *  of the project.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  16H - prefer device, 16L - input type
 *****************************************************************************/
U32 mmi_query_input_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (get_prefer_device() << 16) | get_input_type();
}


/*****************************************************************************
 * FUNCTION
 *  get_prefer_device
 * DESCRIPTION
 *  This API is used to get the preferred input device
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  prefer device see enum mmi_ue_style_enum
 *****************************************************************************/
static U16 get_prefer_device(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prefer_dev;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if ((is_support_touch() == MMI_TRUE))
    {
        if (get_keypad_type() == MMI_FRM_REDUCED_KEYPAD)
        {
            prefer_dev = MMI_UE_STYLE_PREFER_TOUCH;
        }
        else
        {
            if ((is_side_slide_support() == MMI_TRUE) && (is_slide_close() == MMI_TRUE))
            {
                prefer_dev = MMI_UE_STYLE_PREFER_TOUCH;
            }
            else
            {
                prefer_dev = MMI_UE_STYLE_PREFER_KEYPAD;
            }
        }        
    }
    else
    {
        prefer_dev = MMI_UE_STYLE_PREFER_KEYPAD;
    }
    return prefer_dev;
}


/*****************************************************************************
 * FUNCTION
 *  get_input_type
 * DESCRIPTION
 *  This API is used to query the input device type
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  input device type see enum mmi_input_type_enum
 *****************************************************************************/
static U16 get_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pattern = 0;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pattern = get_keypad_type() | 
        (is_support_touch() << 2) | 
        (is_support_ft() << 3) |
        (is_support_multi_touch() << 4);
    for (i = 0; i < INPUT_TYPE_MAP_TAL_ENTRY_NUM; i++)
    {
        if (pattern == g_input_type_map[i].pattern)
        {
            return g_input_type_map[i].input_type;
        }
    }
    return INPUT_TYPE_MAX;
}    


/*****************************************************************************
 * FUNCTION
 *  Is_side_slide_support
 * DESCRIPTION
 *  This API is used to query if the hardware suport side slide or not
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  always return false now
 *****************************************************************************/
static MMI_BOOL is_side_slide_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GENERAL_INPUT_UT__
    return g_query_input.is_slide;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  Is_slide_close
 * DESCRIPTION
 *  This API is used to query if the hardware suport side slide or not
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  always return false now
 *****************************************************************************/
static MMI_BOOL is_slide_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GENERAL_INPUT_UT__
    return g_query_input.is_slide_closed;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  is_support_ft
 * DESCRIPTION
 *  This function is used to query if FT(Finger touch) support
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  keypad type
 *****************************************************************************/
static MMI_BOOL is_support_ft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_GENERAL_INPUT_UT__)
    return g_query_input.is_ft;
#elif (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  is_support_touch
 * DESCRIPTION
 *  This function is used to query if touch pannel support
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if support
 *****************************************************************************/
static MMI_BOOL is_support_touch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if  defined(__MMI_GENERAL_INPUT_UT__)
    return g_query_input.is_touch;
#elif defined(__MMI_TOUCH_SCREEN__)
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  is_support_multi_touch
 * DESCRIPTION
 *  This function is used to query if touch pannel support multi touch
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if support
 *****************************************************************************/
static MMI_BOOL is_support_multi_touch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GENERAL_INPUT_UT__
    return g_query_input.is_multi;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  get_keypad_type
 * DESCRIPTION
 *  This function is used to get keypad type of the project
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  keypad type
 *****************************************************************************/
static keypad_type_enum get_keypad_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_GENERAL_INPUT_UT__)
    return g_query_input.keypad_type;
#elif (defined(__MMI_NORMAL_KEYPAD__))
    return MMI_FRM_NORMAL_KEYPAD;
#elif (defined(__MMI_REDUCED_KEYPAD__))
    return MMI_FRM_REDUCED_KEYPAD;
#elif (defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
    return MMI_FRM_QWERTY_KEYPAD;
#else
    return MMI_FRM_KEYPAD_NONE;
#endif
}


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Test Case for General Input event Handle
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#ifdef __MMI_GENERAL_INPUT_UT__

/*****************************************************************************
* Defines                                                                     
*****************************************************************************/
#define GES_UT (sizeof(g_ts_ut)/sizeof(g_ts_ut[0]))


/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

typedef mmi_ret (*unit_test_func)(void *para);

typedef struct
{
    U8 index;
    unit_test_func test;
} mmi_unit_test_struct;

typedef struct
{
    query_input_style_test combine;
    U32  expect_input_style;
} test_query_input_style_data;

/*****************************************************************************
* Global Variables                                                                     
*****************************************************************************/
static const test_query_input_style_data _query_input[] = 
{
    {
        {   //touch     finger    multi      slide      slide close
            MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FRM_NORMAL_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_NUMERICAL_NON_TOUCH
    },
    {
        {
            MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FRM_NORMAL_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_NUMERICAL_SINGLE_TOUCH_PEN
    }, 
    {
        {
            MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FRM_NORMAL_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_NUMEIRCAL_MULTI_TOUCH_FINGER,
    }, 
    {
        {
            MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FRM_NORMAL_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_NUMERICAL_SINGLE_TOUCH_FINGER
    },     
    {
        {
            MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FRM_QWERTY_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_QWERTY_NON_TOUCH
    },
    
    {
        {
            MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FRM_QWERTY_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_QWERTY_SINGLE_TOUCH_PEN
    },
    {
        {
            MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FRM_QWERTY_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_QWERTY_SINGLE_TOUCH_FINGER
    }, 
    {
        {
            MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FRM_QWERTY_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_QWERTY_MULTI_TOUCH_FINGER
    },
    {
        {
            MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FRM_QWERTY_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_KEYPAD << 16) | KEYPAD_QWERTY_MULTI_TOUCH_FINGER
    }, 
    {
        {
            MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FRM_QWERTY_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_TOUCH << 16) | KEYPAD_QWERTY_MULTI_TOUCH_FINGER
    },      
    {
        {
            MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FRM_REDUCED_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_TOUCH << 16) | KEYPAD_NAVIGATION_SINGLE_TOUCH_PEN
    }, 
    {
        {
            MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FALSE, MMI_FRM_REDUCED_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_TOUCH << 16) | KEYPAD_NAVIGATION_SINGLE_TOUCH_FINGER
    },
    {
        {
            MMI_TRUE, MMI_TRUE, MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_FRM_REDUCED_KEYPAD
        },
        (MMI_UE_STYLE_PREFER_TOUCH << 16) | KEYPAD_NAVIGATION_MULTI_TOUCH_FINGER
    },     
};

mmi_ret ut_mmi_query_input_style(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 style;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    for (i = 0; i < sizeof(_query_input)/ sizeof(_query_input[0]); i++)
    {
        g_query_input = _query_input[i].combine;
        style = mmi_query_input_style();
        MMI_ASSERT(style == _query_input[i].expect_input_style);
    }
    kal_prompt_trace(MOD_MMI, "[UT_GENERAL_INPUT] test query input style PASS!!!");
    return MMI_RET_OK;
}


/*****************************************************************************
* Test Engine                                                                     
*****************************************************************************/
const static mmi_unit_test_struct g_ts_ut[] =
{
    {1, ut_mmi_query_input_style}     
};

void mmi_frm_general_input_ut(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (index == 0)
    {
        for (i = 0; i < GES_UT; i++)
        {
            g_ts_ut[i].test(NULL);
        }
    }
    else
    {
        for (i = 0; i < GES_UT; i++)
        {
            if (g_ts_ut[i].index == index)
            {
                g_ts_ut[i].test(NULL);
            }
        }
    }
}

#endif  /* __MMI_GENERAL_INPUT_UT__ */


