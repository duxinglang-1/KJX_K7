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
 *  vapp_imgedt_util.h
 *
 * Project:
 * --------
 *  Venus
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
  * Typedef
  *****************************************************************************/

#ifndef __VAPP_PHOEDT__UTIL_H__
#define __VAPP_PHOEDT__UTIL_H__

#if (defined(__MMI_COSMOS_PHOTOEDITOR__) || defined(__MMI_COSMOS_IMAGECLIPPER__))

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VAPP_IMGEDT_INFO_TRACE(VAL)  \
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_COMMON_INFO, __LINE__, VAL)
#define VAPP_IMGEDT_WARN_TRACE(VAL)  \
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_COMMON_WARN, __LINE__, VAL)
#define VAPP_IMGEDT_ERROR_TRACE(VAL) \
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_COMMON_ERROR, __LINE__, VAL)

//Others but not skin
#define IMGEDT_CLIP_CUI_MAX_LENGTH      4095
#define IMGEDT_ADJUST_MIN_TICKS         40
#define IMGEDT_TEXT_COLOR_COUNT         23
#define IMGEDT_DOODLE_COLOR_COUNT       23
#define IMGEDT_ADD_FRAME_COUNT          5
#define IMGEDT_ADD_EFFECT_COUNT         7
#define IMGEDT_CLIPART_COUNT            10
#define IMGEDT_IMAGE_MOVE_MIN_RADIUS    10
#define IMGEDT_DOOLE_MOVE_MIN_RADIUS    3
#define IMGEDT_DOOLE_DIAL_MIN_RADIUS    10
#define IMGEDT_RESIVE_MIN_LENGTH        10
#define IMGEDT_BALLOON_FONT_COLOR       VfxColor(255,15,15,15)
#define IMGEDT_MATTS_CELL_BORDER_COLOR  VfxColor(255,222, 222, 222)
#define IMGEDT_HIGHLIGHT_CELL_COLOR     VFX_COLOR_GREEN
 //only for QVGA/WQVGA
#define IMGEDT_MATTS_AREA_HEIGHT_PEN    132
#define IMGEDT_MATTS_AREA_HEIGHT_ERASE  132
 
#if defined(__MMI_MAINLCD_480X800__)
 //BASE PAGE
#define IMGEDT_ZOOM_SLIDER_LENGTH_V     460  
#define IMGEDT_ZOOM_SLIDER_X_V          440
#define IMGEDT_ZOOM_SLIDER_LENGTH_H     300  
#define IMGEDT_ZOOM_SLIDER_X_H          760
#define IMGEDT_ZOOM_ADD_OFFSET_Y        25                     
#define IMGEDT_ZOOM_DEC_OFFSET_Y        15
#define IMGEDT_HIDE_BTN_SIZE            60
#define IMGEDT_HIDE_BTN_X_V             400
#define IMGEDT_HIDE_BTN_Y_V             720
#define IMGEDT_HIDE_BTN_X_H             720
#define IMGEDT_HIDE_BTN_Y_H             400
 //Popup
#define IMGEDT_SAVE_POPUP_WIDTH_VERT    446
#define IMGEDT_SAVE_POPUP_WIDTH_HORZ    546
#define IMGEDT_POPUP_POPUP_WIDTH_VERT   446
#define IMGEDT_POPUP_POPUP_WIDTH_HORZ   546
#define IMGEDT_MATTS_COL_COUNT          4
#define IMGEDT_MATTS_CELL_WIDTH         100
#define IMGEDT_MATTS_CELL_HEIGHT        100
#define IMGEDT_MATTS_CELL_GAPS          5
#define IMGEDT_MATTS_AREA_WIDTH         425 //(400 + 25)
#define IMGEDT_MATTS_AREA_HEIGHT_COLOR  330
#define IMGEDT_MATTS_AREA_HEIGHT_ICON   320
 //AdjustPage
#define IMGEDT_ADJUST_BAR_FONT_SIZE     24
#define IMGEDT_ADJUST_BAR_HEIGHT_V      90
#define IMGEDT_ADJUST_BAR_FONT_X_V      20
#define IMGEDT_ADJUST_BAR_FONT_Y_V      8
#define IMGEDT_ADJUST_BAR_SLIDER_X_V    20
#define IMGEDT_ADJUST_BAR_SLIDER_Y_V    40
#define IMGEDT_ADJUST_BAR_SLIDER_LEN_V  440
#define IMGEDT_ADJUST_BAR_HEIGHT_H      60
#define IMGEDT_ADJUST_BAR_FONT_X_H      20
#define IMGEDT_ADJUST_BAR_FONT_Y_H      12
#define IMGEDT_ADJUST_BAR_SLIDER_X_H    180
#define IMGEDT_ADJUST_BAR_SLIDER_Y_H    12
#define IMGEDT_ADJUST_BAR_SLIDER_LEN_H  600
 //info ballon
#define IMGEDT_BALLOON_FONT_SIZE        20
#define IMGEDT_BALLOON_ARROW_WIDTH      16
#define IMGEDT_BALLOON_ARROW_HEIGHT     51
#define IMGEDT_BALLOON_LR_HEIGHT        51
#define IMGEDT_BALLON_TEXT_HEIGHT       15
#define IMGEDT_BALLOON_LR_MARGIN        30
 //clip &rotate ...
#define IMGEDT_CLIP_MIN_LENGHTH         80
#define IMGEDT_DIAL_PANEL_RADIUS        120
#define IMGEDT_ROTATE_BTN_SIZE          40
#define IMGEDT_CLIP_BTN_SIZE            54
#define IMGEDT_FLIP_BTN_SIZE            40
#define IMGEDT_CLIP_FRAME_WIDTH         26
 //Top/ bottom Bars
#define IMGEDT_TOP_BAR_BTN_WIDTH        105 
#define IMGEDT_TOP_BAR_BTN_HEIGHT       70
#define IMGEDT_SCROLL_BTN_WIDTH         105
#define IMGEDT_SCROLL_BTN_HEIGHT        70
#define IMGEDT_TOOL_BAR_HEIGHT          78
#define IMGEDT_BOTTOM_BAR_HEIGHT        70
#define IMGEDT_BOTTOM_LRSK_SIZE         60      
#define IMGEDT_ADDFRAME_CELL_WIDTH      56
#define IMGEDT_ADDFRAME_CELL_HEIGHT     90
#define IMGEDT_ADDFRAME_OFFSET_X        5
#define IMGEDT_ADDFRAME_OFFSET_Y        5
#define IMGEDT_ADDFRAME_CELL_GAPS       12
#define IMGEDT_FRAME_PENAL_VERT_H       102
#define IMGEDT_FRAME_PENAL_HORZ_W       102
#define IMGEDT_ADDEFFECT_CELL_WIDTH     90
#define IMGEDT_ADDEFFECT_CELL_HEIGHT    90
#define IMGEDT_ADDEFFECT_BAR_HEIGHT     102
#define IMGEDT_ADDEFFECT_OFFSET_X       5 
#define IMGEDT_ADDEFFECT_OFFSET_Y       4
#define IMGEDT_ADDEFFECT_CELL_GAPS      12
#define IMGEDT_HILIGHT_BORDER_WIDTH     3
 //Add text font size
#define IMGEDT_ADD_TEXT_FONT_SIZE_L1    60
#define IMGEDT_ADD_TEXT_FONT_SIZE_L2    48
#define IMGEDT_ADD_TEXT_FONT_SIZE_L3    36
#define IMGEDT_ADD_TEXT_FONT_SIZE_L4    24
 
#define IMGEDT_EDGE_FRAME_BORDER        8
 
#elif defined(__MMI_MAINLCD_320X480__)
 //BASE PAGE
#define IMGEDT_ZOOM_SLIDER_LENGTH_V     260  
#define IMGEDT_ZOOM_SLIDER_X_V          299
#define IMGEDT_ZOOM_SLIDER_LENGTH_H     200  
#define IMGEDT_ZOOM_SLIDER_X_H          440
#define IMGEDT_ZOOM_ADD_OFFSET_Y        15                     
#define IMGEDT_ZOOM_DEC_OFFSET_Y        10
#define IMGEDT_HIDE_BTN_SIZE            40
#define IMGEDT_HIDE_BTN_X_V             260
#define IMGEDT_HIDE_BTN_Y_V             435
#define IMGEDT_HIDE_BTN_X_H             420
#define IMGEDT_HIDE_BTN_Y_H             275
 //popup
#define IMGEDT_SAVE_POPUP_WIDTH_VERT    290
#define IMGEDT_SAVE_POPUP_WIDTH_HORZ    340
#define IMGEDT_POPUP_POPUP_WIDTH_VERT   287
#define IMGEDT_POPUP_POPUP_WIDTH_HORZ   340
#define IMGEDT_MATTS_COL_COUNT          4
#define IMGEDT_MATTS_CELL_WIDTH         60
#define IMGEDT_MATTS_CELL_HEIGHT        60
#define IMGEDT_MATTS_CELL_GAPS          5
#define IMGEDT_MATTS_AREA_WIDTH         265 //(240 + 25)
#define IMGEDT_MATTS_AREA_HEIGHT_COLOR  220
#define IMGEDT_MATTS_AREA_HEIGHT_ICON   200
 //AdjustPage
#define IMGEDT_ADJUST_BAR_FONT_SIZE     16
#define IMGEDT_ADJUST_BAR_HEIGHT_V      60
#define IMGEDT_ADJUST_BAR_FONT_X_V      15
#define IMGEDT_ADJUST_BAR_FONT_Y_V      8
#define IMGEDT_ADJUST_BAR_SLIDER_X_V    10
#define IMGEDT_ADJUST_BAR_SLIDER_Y_V    25
#define IMGEDT_ADJUST_BAR_SLIDER_LEN_V  300
#define IMGEDT_ADJUST_BAR_HEIGHT_H      47
#define IMGEDT_ADJUST_BAR_FONT_X_H      20
#define IMGEDT_ADJUST_BAR_FONT_Y_H      12
#define IMGEDT_ADJUST_BAR_SLIDER_X_H    104
#define IMGEDT_ADJUST_BAR_SLIDER_Y_H    12
#define IMGEDT_ADJUST_BAR_SLIDER_LEN_H  356
 //info ballon
#define IMGEDT_BALLOON_FONT_SIZE        14
#define IMGEDT_BALLOON_ARROW_WIDTH      16
#define IMGEDT_BALLOON_ARROW_HEIGHT     51
#define IMGEDT_BALLOON_LR_HEIGHT        51
#define IMGEDT_BALLON_TEXT_HEIGHT       15
#define IMGEDT_BALLOON_LR_MARGIN        10
 //clip &rotate ...
#define IMGEDT_CLIP_MIN_LENGHTH         60
#define IMGEDT_DIAL_PANEL_RADIUS        80
#define IMGEDT_ROTATE_BTN_SIZE          30
#define IMGEDT_CLIP_BTN_SIZE            28
#define IMGEDT_FLIP_BTN_SIZE            30
#define IMGEDT_CLIP_FRAME_WIDTH         18
 //Top/ bottom Bars
#define IMGEDT_TOP_BAR_BTN_WIDTH        70 
#define IMGEDT_TOP_BAR_BTN_HEIGHT       45
#define IMGEDT_SCROLL_BTN_WIDTH         70
#define IMGEDT_SCROLL_BTN_HEIGHT        45
#define IMGEDT_TOOL_BAR_HEIGHT          52
#define IMGEDT_BOTTOM_BAR_HEIGHT        45
#define IMGEDT_BOTTOM_LRSK_SIZE         40
#define IMGEDT_ADDFRAME_CELL_WIDTH      36
#define IMGEDT_ADDFRAME_CELL_HEIGHT     52
#define IMGEDT_ADDFRAME_OFFSET_X        5
#define IMGEDT_ADDFRAME_OFFSET_Y        5
#define IMGEDT_ADDFRAME_CELL_GAPS       12
#define IMGEDT_FRAME_PENAL_VERT_H       60
#define IMGEDT_FRAME_PENAL_HORZ_W       60
#define IMGEDT_ADDEFFECT_CELL_WIDTH     52
#define IMGEDT_ADDEFFECT_CELL_HEIGHT    52
#define IMGEDT_ADDEFFECT_BAR_HEIGHT     60
#define IMGEDT_ADDEFFECT_OFFSET_X       5 
#define IMGEDT_ADDEFFECT_OFFSET_Y       4
#define IMGEDT_ADDEFFECT_CELL_GAPS      5
#define IMGEDT_HILIGHT_BORDER_WIDTH     2
 //Add text font size
#define IMGEDT_ADD_TEXT_FONT_SIZE_L1    48
#define IMGEDT_ADD_TEXT_FONT_SIZE_L2    36
#define IMGEDT_ADD_TEXT_FONT_SIZE_L3    24
#define IMGEDT_ADD_TEXT_FONT_SIZE_L4    12
 
#define IMGEDT_EDGE_FRAME_BORDER        8
 
#elif defined(__MMI_MAINLCD_240X400__)
 //BASE PAGE
#define IMGEDT_ZOOM_SLIDER_LENGTH_V     160  
#define IMGEDT_ZOOM_SLIDER_X_V          220
#define IMGEDT_ZOOM_SLIDER_LENGTH_H     318  
#define IMGEDT_ZOOM_SLIDER_X_H          380
#define IMGEDT_ZOOM_SLIDER_Y_H          145
#define IMGEDT_ZOOM_ADD_OFFSET_X        18                     
#define IMGEDT_ZOOM_DEC_OFFSET_X        18
#define IMGEDT_ZOOM_ADD_OFFSET_Y        15                     
#define IMGEDT_ZOOM_DEC_OFFSET_Y        10
#define IMGEDT_ZOOM_TOOLBAR_OFFSET_Y    15
#define IMGEDT_HIDE_BTN_SIZE            30
#define IMGEDT_HIDE_BTN_X_V             200
#define IMGEDT_HIDE_BTN_Y_V             360
#define IMGEDT_HIDE_BTN_X_H             360
#define IMGEDT_HIDE_BTN_Y_H             200
 //popup
#define IMGEDT_SAVE_POPUP_WIDTH_VERT    222
#define IMGEDT_SAVE_POPUP_WIDTH_HORZ    242
#define IMGEDT_POPUP_POPUP_WIDTH_VERT   223
#define IMGEDT_POPUP_POPUP_WIDTH_HORZ   242
#define IMGEDT_MATTS_COL_COUNT          4
#define IMGEDT_MATTS_CELL_WIDTH         47
#define IMGEDT_MATTS_CELL_HEIGHT        47
#define IMGEDT_MATTS_CELL_GAPS          3
#define IMGEDT_MATTS_AREA_WIDTH         203 //(47*4 + 5*3)
#define IMGEDT_MATTS_AREA_HEIGHT_COLOR  160
#define IMGEDT_MATTS_AREA_HEIGHT_ICON   150
 //AdjustPage
#define IMGEDT_ADJUST_BAR_FONT_SIZE     13
#define IMGEDT_ADJUST_BAR_HEIGHT_V      44
#define IMGEDT_ADJUST_BAR_FONT_X_V      11
#define IMGEDT_ADJUST_BAR_FONT_Y_V      4
#define IMGEDT_ADJUST_BAR_SLIDER_X_V    11
#define IMGEDT_ADJUST_BAR_SLIDER_Y_V    18
#define IMGEDT_ADJUST_BAR_SLIDER_LEN_V  218
#define IMGEDT_ADJUST_BAR_HEIGHT_H      34
#define IMGEDT_ADJUST_BAR_FONT_X_H      10
#define IMGEDT_ADJUST_BAR_FONT_Y_H      10
#define IMGEDT_ADJUST_BAR_SLIDER_X_H    75
#define IMGEDT_ADJUST_BAR_SLIDER_Y_H    5
#define IMGEDT_ADJUST_BAR_SLIDER_LEN_H  235
 //info ballon
#define IMGEDT_BALLOON_FONT_SIZE        13
#define IMGEDT_BALLOON_ARROW_WIDTH      16
#define IMGEDT_BALLOON_ARROW_HEIGHT     40
#define IMGEDT_BALLOON_LR_HEIGHT        40
#define IMGEDT_BALLON_TEXT_HEIGHT       13
#define IMGEDT_BALLOON_LR_MARGIN        10
 //clip &rotate ...
#define IMGEDT_CLIP_MIN_LENGHTH         60
#define IMGEDT_DIAL_PANEL_RADIUS        78
#define IMGEDT_ROTATE_BTN_SIZE          30
#define IMGEDT_CLIP_BTN_SIZE            28
#define IMGEDT_FLIP_BTN_SIZE            30
#define IMGEDT_CLIP_FRAME_WIDTH         18
 //Top/ bottom Bars
#define IMGEDT_TOP_BAR_BTN_WIDTH        53 
#define IMGEDT_TOP_BAR_BTN_HEIGHT       40
#define IMGEDT_SCROLL_BTN_WIDTH         53
#define IMGEDT_SCROLL_BTN_HEIGHT        40
#define IMGEDT_TOOL_BAR_HEIGHT          40
#define IMGEDT_BOTTOM_BAR_HEIGHT        40
#define IMGEDT_BOTTOM_LRSK_SIZE         40
#define IMGEDT_ADDFRAME_CELL_WIDTH      27
#define IMGEDT_ADDFRAME_CELL_HEIGHT     39
#define IMGEDT_ADDFRAME_OFFSET_X        3
#define IMGEDT_ADDFRAME_OFFSET_Y        0
#define IMGEDT_ADDFRAME_CELL_GAPS       9
#define IMGEDT_FRAME_PENAL_VERT_H       42
#define IMGEDT_FRAME_PENAL_HORZ_W       42
#define IMGEDT_ADDEFFECT_CELL_WIDTH     37
#define IMGEDT_ADDEFFECT_CELL_HEIGHT    37
#define IMGEDT_ADDEFFECT_BAR_HEIGHT     42
#define IMGEDT_ADDEFFECT_OFFSET_X       4 
#define IMGEDT_ADDEFFECT_OFFSET_Y       2
#define IMGEDT_ADDEFFECT_CELL_GAPS      4
#define IMGEDT_HILIGHT_BORDER_WIDTH     2
 //Add text font size
#define IMGEDT_ADD_TEXT_FONT_SIZE_L1    48
#define IMGEDT_ADD_TEXT_FONT_SIZE_L2    36
#define IMGEDT_ADD_TEXT_FONT_SIZE_L3    24
#define IMGEDT_ADD_TEXT_FONT_SIZE_L4    12
 
#define IMGEDT_EDGE_FRAME_BORDER        4
 
#elif defined(__MMI_MAINLCD_240X320__) 
 //BASE PAGE
#define IMGEDT_ZOOM_SLIDER_LENGTH_V     160  
#define IMGEDT_ZOOM_SLIDER_X_V          220
#define IMGEDT_ZOOM_SLIDER_LENGTH_H     238 
#define IMGEDT_ZOOM_SLIDER_X_H          300
#define IMGEDT_ZOOM_SLIDER_Y_H          145
#define IMGEDT_ZOOM_ADD_OFFSET_X        18                     
#define IMGEDT_ZOOM_DEC_OFFSET_X        18
#define IMGEDT_ZOOM_ADD_OFFSET_Y        15                     
#define IMGEDT_ZOOM_DEC_OFFSET_Y        10
#define IMGEDT_ZOOM_TOOLBAR_OFFSET_Y    15
#define IMGEDT_HIDE_BTN_SIZE            30
#define IMGEDT_HIDE_BTN_X_V             200
#define IMGEDT_HIDE_BTN_Y_V             280
#define IMGEDT_HIDE_BTN_X_H             280
#define IMGEDT_HIDE_BTN_Y_H             200
 //popup
#define IMGEDT_SAVE_POPUP_WIDTH_VERT    222
#define IMGEDT_SAVE_POPUP_WIDTH_HORZ    242
#define IMGEDT_POPUP_POPUP_WIDTH_VERT   223
#define IMGEDT_POPUP_POPUP_WIDTH_HORZ   242
#define IMGEDT_MATTS_COL_COUNT          4
#define IMGEDT_MATTS_CELL_WIDTH         47
#define IMGEDT_MATTS_CELL_HEIGHT        47
#define IMGEDT_MATTS_CELL_GAPS          3
#define IMGEDT_MATTS_AREA_WIDTH         203 //(47*4 + 5*3)
#define IMGEDT_MATTS_AREA_HEIGHT_COLOR  160
#define IMGEDT_MATTS_AREA_HEIGHT_ICON   150
 //AdjustPage
#define IMGEDT_ADJUST_BAR_FONT_SIZE     13
#define IMGEDT_ADJUST_BAR_HEIGHT_V      44
#define IMGEDT_ADJUST_BAR_FONT_X_V      11
#define IMGEDT_ADJUST_BAR_FONT_Y_V      4
#define IMGEDT_ADJUST_BAR_SLIDER_X_V    11
#define IMGEDT_ADJUST_BAR_SLIDER_Y_V    18
#define IMGEDT_ADJUST_BAR_SLIDER_LEN_V  218
#define IMGEDT_ADJUST_BAR_HEIGHT_H      34
#define IMGEDT_ADJUST_BAR_FONT_X_H      10
#define IMGEDT_ADJUST_BAR_FONT_Y_H      10
#define IMGEDT_ADJUST_BAR_SLIDER_X_H    75
#define IMGEDT_ADJUST_BAR_SLIDER_Y_H    5
#define IMGEDT_ADJUST_BAR_SLIDER_LEN_H  235
 //info ballon
#define IMGEDT_BALLOON_FONT_SIZE        13
#define IMGEDT_BALLOON_ARROW_WIDTH      16
#define IMGEDT_BALLOON_ARROW_HEIGHT     40
#define IMGEDT_BALLOON_LR_HEIGHT        40
#define IMGEDT_BALLON_TEXT_HEIGHT       13
#define IMGEDT_BALLOON_LR_MARGIN        10
 //clip &rotate ...
#define IMGEDT_CLIP_MIN_LENGHTH         60
#define IMGEDT_DIAL_PANEL_RADIUS        78
#define IMGEDT_ROTATE_BTN_SIZE          30
#define IMGEDT_CLIP_BTN_SIZE            28
#define IMGEDT_FLIP_BTN_SIZE            30
#define IMGEDT_CLIP_FRAME_WIDTH         18
 //Top/ bottom Bars
#define IMGEDT_TOP_BAR_BTN_WIDTH        53 
#define IMGEDT_TOP_BAR_BTN_HEIGHT       40
#define IMGEDT_SCROLL_BTN_WIDTH         53
#define IMGEDT_SCROLL_BTN_HEIGHT        40
#define IMGEDT_TOOL_BAR_HEIGHT          40
#define IMGEDT_BOTTOM_BAR_HEIGHT        40
#define IMGEDT_BOTTOM_LRSK_SIZE         40
#define IMGEDT_ADDFRAME_CELL_WIDTH      27
#define IMGEDT_ADDFRAME_CELL_HEIGHT     39
#define IMGEDT_ADDFRAME_OFFSET_X        3
#define IMGEDT_ADDFRAME_OFFSET_Y        0
#define IMGEDT_ADDFRAME_CELL_GAPS       9
#define IMGEDT_FRAME_PENAL_VERT_H       42
#define IMGEDT_FRAME_PENAL_HORZ_W       42
#define IMGEDT_ADDEFFECT_CELL_WIDTH     37
#define IMGEDT_ADDEFFECT_CELL_HEIGHT    37
#define IMGEDT_ADDEFFECT_BAR_HEIGHT     42
#define IMGEDT_ADDEFFECT_OFFSET_X       4 
#define IMGEDT_ADDEFFECT_OFFSET_Y       2
#define IMGEDT_ADDEFFECT_CELL_GAPS      4
#define IMGEDT_HILIGHT_BORDER_WIDTH     2
 //Add text font size
#define IMGEDT_ADD_TEXT_FONT_SIZE_L1    48
#define IMGEDT_ADD_TEXT_FONT_SIZE_L2    36
#define IMGEDT_ADD_TEXT_FONT_SIZE_L3    24
#define IMGEDT_ADD_TEXT_FONT_SIZE_L4    12
 
#define IMGEDT_EDGE_FRAME_BORDER        4
 
#endif


/***************************************************************************** 
 * Class VcpImgEdtNamingHelper
 *****************************************************************************/
class VcpImgEdtNamingHelper : public VfxObject
{
public:

    VfxWString getOrgFileName(const VfxWString &strFullPath);
    VfxWString getNewPathByName(const VfxWString &strOrgPath, const VfxWString &strNewName);
    VfxWString autoGenNewPath(const VfxWString &strFullPath);

private:
    VfxWChar* getFileNamePos(const VfxWChar *fullpath);
    VfxWChar* getFileExtPos(const VfxWChar * filename);
};

/***************************************************************************** 
 * class VcpImgEdtPopup
 *****************************************************************************/
class VcpImgEdtPopup : public VfxObject
{
public:
    static void popup(VcpConfirmPopup *popup,
                      VfxResId strId,
                      VcpPopupTypeEnum type);
    static void popupDone(VcpConfirmPopup *popup);
    static void popupError(VcpConfirmPopup *popup,
                           VfxResId strId);
};

/***************************************************************************** 
 * Class VcpImgEdtClipWindow
 *****************************************************************************/
class VcpImgEdtClipWindow : public VfxControl
{
private:
    enum ClipWindowDirect
    {
        DIRECT_UP,
        DIRECT_DOWN,
        DIRECT_LEFT,
        DIRECT_RIGHT,
            
        DIRECT_TOTAL
    };
    
    enum ClipWindowCorner
    {
        CORNER_LEFT_UP,
        CORNER_LEFT_DOWN,
        CORNER_RIGHT_UP,
        CORNER_RIGHT_DOWN,

        CORNER_TOTAL 
    };
    
    enum ClipWindowState
    {
        STATE_IDLE,
        STATE_MOVE,
        STATE_RESIZE_FIXED,
        STATE_RESIZE_FREE,
        //STATE_MOVE_IMG,

        STATE_TOTAL
    };

public:
    VcpImgEdtClipWindow();

public:
    void setImgRect(VfxRect rect);    
    void setRatioFixed(VfxBool bFixed);
    void setRatio(VfxS32 ratioW, VfxS32 ratioH);
    void changeRatio(VfxS32 ratioW, VfxS32 ratioH, VfxBool bFixed);
    void setDetectRect(VfxRect &rect);
    void getClipRect(VfxRect *rect);
    void setFreeze(VfxBool is_freeze);
    void show();
    
    //VfxSignal1  <VfxSize &> m_signalDragImg;
    VfxSignal0  m_signalDetectAreaTouched;
        
protected:
    virtual void onInit();    
    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    void createTransFrame();
    void createLineFrame();
    void createConerBtn();
    void createMiddleBtn();

	void redrawClipwindow();
    void redrawTransFrame();
    void redrawLineFrame();
    void redrawConerBtn();
    void redrawMiddleBtn();
    
    void updateLayout();
    void setMiddleBtnHidden(VfxBool is_hidden);

    void setLineFrameFocus(VfxBool bFocus);
    void setBtnFocus(VfxBool bFocus);
    VfxBool onPenDownCheck(VfxPenEvent &event);
    
    void  onClipWindowMove(VfxPenEvent &event);
    void  onClipWindowFreeResize(VfxPenEvent &event);
    void  onClipWindowFixedResize(VfxPenEvent &event);

    VfxBool checkInputValid(VfxPoint pos);
    void resetValidRect();
    void ajustInputPos(VfxPoint &pos);

private:

    VfxBool         m_isFreeze;
    VfxBool         m_resetResizeInfo;
   
    VfxFrame        *m_transFrame[DIRECT_TOTAL];
    VfxFrame        *m_lineFrame[DIRECT_TOTAL];
    VfxFrame        *m_borderFrame;
    VfxFrame        *m_cornerBtn[CORNER_TOTAL];
    VfxFrame        *m_middleBtn[DIRECT_TOTAL];
    VfxFrame        *m_btnHL;
    VfxRect         m_clipRect;

    VfxS32      m_focusBtnInx;
    VfxS32      m_state;
    VfxPoint    m_movePole;

    //ratio related
    VfxBool m_isFixed;
    VfxS32  m_curRatioW;
    VfxS32  m_curRatioH;
    VfxRect m_imgRect;
    VfxRect m_detectRect;
    VfxRect m_validResizeRect;
    VfxSize m_initSize;
};

/***************************************************************************** 
 * class VcpImgEdtBottomBar
 *****************************************************************************/
#define IMGEDT_BOTTOM_L1_MAX_BTNS_COUNT              (5)
#define IMGEDT_BOTTOM_L2_MAX_BTNS_COUNT              (5)


class VcpImgEdtBottomBtn : public VfxControl
{
    //VFX_DECLARE_CLASS(VcpImgEdtBottomBtn);
public:
    VcpImgEdtBottomBtn();
    void setId(VfxId id);
    void setImageId(VcpStateImage imgList);
    void setBtnSize(VfxSize size);
    void setStateDown(VfxBool isDown);
    void setTabBtn(VfxBool isTab);
    void setBgSize(VfxSize size);
    void setDisabled(VfxBool isDisabled);
    VfxId getId();
    void updatePos();

public:
    VfxSignal2 <VfxObject*, VfxId> m_signalPressed;
  
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        //Not allow pen event pass down
        if (m_bTabBtn)
        {
            m_button->penInput(event);
        }
        return VFX_TRUE;
    };

private:
    void onBtnClicked(VfxObject* obj, VfxId id);

private:
    VcpImageButton   *m_button;
    VfxBool           m_bTabBtn;
    VfxBool           m_bDownState;
    VfxSize           m_bgSize;
};


class VcpImgEdtBottomBar : public VfxPageBar
{
    //VFX_DECLARE_CLASS(VcpImgEdtBottomBar);
public:
    enum BottomBtnLevel
    {
        BOTTOM_BTN_L1,
        BOTTOM_BTN_L2
    };

    enum BottomBtnType
    {
        BOTTOM_BTN_TYPE_OK,     //always the 1st in L1
        BOTTOM_BTN_TYPE_CANCEL, //always the last one in L1

        BOTTOM_BTN_TYPE_EX        
    };

    VfxSignal2 <VfxObject*, VfxId> m_signalBtnTap;

public:

    VcpImgEdtBottomBar();

    void setBgSize(VfxSize size);
    void setBtnHeight(VfxS32 height);
    void setVisibleMode(VfxBool is_full);    
    void show();
    void setDisabled(VfxBool isDisabled);
    void setDisabled(VfxS32 btnId, VfxBool isDisabled);
    void setDownState(VfxBool isLevel1, VfxS32 btnId);
    void setBtnHilit(VfxS32 btn_id, VfxBool isHilit);
    void clearDownState(VfxBool isLevel1, VfxS32 exceptId);
    void addItem(VfxId btn_id, 
                 VfxResId button_icon, 
                 BottomBtnLevel level = BOTTOM_BTN_L1,
                 VfxBool is_tab = VFX_FALSE
                 );
    void resetItemImage(VfxS32 index, 
                        VfxResId button_icon, 
                        BottomBtnLevel level = BOTTOM_BTN_L1);
	VfxS32 getbtnNum(VfxS32 level);

protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent & event);

private:
    void onBtnTaped(VfxObject *obj, VfxId id);
    //void onStateChange(VfxObject* obj, VfxId id, VcpButtonStateEnum state);

private:
    VcpImgEdtBottomBtn  *m_btnArrayL1[IMGEDT_BOTTOM_L1_MAX_BTNS_COUNT];
    VcpImgEdtBottomBtn  *m_btnArrayL2[IMGEDT_BOTTOM_L1_MAX_BTNS_COUNT];
    VcpImageButton      *m_btnOK;
    VcpImageButton      *m_btnBack;
    //VfxImageFrame   *m_btnHL;
    VfxS32          m_btnNumL1;
    VfxS32          m_btnNumL2;
    
    VfxSize         m_bgSize;
    VfxSize         m_btnL1Size;
    VfxSize         m_btnL2Size;
};


/***************************************************************************** 
 * Class VappImgEdtBaseScr
 *****************************************************************************/
class VappImgEdtBaseScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappImgEdtBaseScr);

public:
    VappImgEdtBaseScr();

    static void getHaloSize(const VfxSize &btnSize, VfxSize &haloSize);
    VfxBool checkVertMode();
    void setScrRotate(VfxScrRotateTypeEnum type);
    VfxScrRotateTypeEnum getScrRotate();

protected:
    VfxScrRotateTypeEnum    m_scrRotate;
};


#endif /* defined(__MMI_COSMOS_PHOTOEDITOR__) || defined(__MMI_COSMOS_IMAGECLIPPER__) */
#endif /* __VAPP_PHOEDT__UTIL_H__ */
