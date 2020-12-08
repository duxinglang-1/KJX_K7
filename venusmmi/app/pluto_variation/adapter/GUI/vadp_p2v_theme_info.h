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
 *  vf_test_image_flow.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus test application.
 *  A temp porting Venus UI Core to PlutoMMI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VDAT_THEME_INFO_H__
#define __VDAT_THEME_INFO_H__

#include "CustThemesRes.h"

#include "vfx_object.h"
#include "vfx_basic_type.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

class VadpTheme : public VfxObject
{
public:
    enum vadp_theme_filler_enum
    {
        UNKNOWN_FILLER = 0,
            IDLE_BKG_FILLER,
            MAIN_MENU_BKG_FILLER,
            SUB_MENU_BKG_FILLER,
            SOFTKEY_BAR_BKG_FILLER,
            STATUS_BAR_BKG_FILLER,
            END_OF_FILLER_ENUM
    };
    enum vadp_theme_color_enum
    {
        UNKNOWN_COLOR = 0,
            LSK_UP_TEXT_COLOR,
            LSK_DOWN_TEXT_COLOR,
            RSK_UP_TEXT_COLOR,
            RSK_DOWN_TEXT_COLOR,
            SOFTKEY_TEXT_BORDER_COLOR,
            END_OF_COLOR_ENUM
    };
    enum vadp_theme_filler_type_enum
    {
        UNKNOWN_FILLER_TYPE = 0,
            FILLER_COLOR,
            FILLER_IMAGE,
            END_OF_FILLER_TYPE_ENUM
    };
public:
    /*
     * Constructor / Destructor
     */ 
    VadpTheme();

protected:
    virtual void onInit();
    virtual void onDeinit();

public:
    /*
    * Methods
     */
    void GetColor(vadp_theme_color_enum theme_content, VfxColor* color);
    UI_filled_area* GetFiller(vadp_theme_filler_enum theme_content);
    //vfrm_u8 * vf_theme_get_image(vf_theme_content_enum theme_content);
    //vfrm_s32  vf_theme_get_value(vf_theme_content_enum theme_content);
};


#endif /* __VDAT_THEME_INFO_H__ */

