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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_baidu_search.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the baidu search widget.
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

#ifndef VAPP_WIDGET_BAIDU_SEARCH_H
#define VAPP_WIDGET_BAIDU_SEARCH_H

#include "MMI_features.h"

#ifdef __MMI_VUI_WIDGET_BAIDU_SEARCH__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_search_widget_base_class.h"


/*****************************************************************************
 * Baidu Widget
 *****************************************************************************/

class VappWidgetBaiduSearch : public VappWidgetSearchEditor

{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetBaiduSearch);

public:
    enum
    {
    
        BAIDU_WIDGET_ICON_SIZE = 50,
    #if defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 120,
        BAIDU_SEARCH_WIDET_ICON_POS_X = 19,
		BAIDU_SEARCH_WIDET_ICON_POS_Y = 21,
    #elif defined(__MMI_MAINLCD_320X480__)
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 84,
        BAIDU_SEARCH_WIDET_ICON_POS_X = 16,
		BAIDU_SEARCH_WIDET_ICON_POS_Y = 14,
    #elif defined(__MMI_MAINLCD_240X400__)
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 71,
        BAIDU_SEARCH_WIDET_ICON_POS_X = 10,
		BAIDU_SEARCH_WIDET_ICON_POS_Y = 10, 
    #else /* defined(__MMI_MAINLCD_240X320__) */
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 70,
        BAIDU_SEARCH_WIDET_ICON_POS_X = 10,
		BAIDU_SEARCH_WIDET_ICON_POS_Y = 10, 
    #endif

        WIDTH = 250,
        HEIGHT = 150
    };

	VfxFrame *m_iconFrame;

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetBaiduSearch();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

    virtual void onCreateView();

    virtual void onReleaseView();
	
	virtual void setOnWidgetClick();
	
};

#endif /*__MMI_VUI_WIDGET_BAIDU_SEARCH__*/

#endif /* VAPP_WIDGET_BAIDU_SEARCH_H */

