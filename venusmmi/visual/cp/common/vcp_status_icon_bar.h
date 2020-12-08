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
 *  vcp_status_icon_bar.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Status icon bar component (Adaptor to Pluto UI component )
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
#ifndef __VCP_STATUS_ICON_BAR_H__
#define __VCP_STATUS_ICON_BAR_H__

#ifndef __cplusplus
// If you don't allow C to include this file, remove following //
// #error "This header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "gui_status_icon_bar.h"
}
#include "vcp_pluto_control.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
 
/***************************************************************************** 
 * Class VcpStatusIconBar
 *****************************************************************************/

/*
 * The description of this class
 *
 * EXAMPLE
 * <code>
 *   VcpStatusIconBar *icon_bar;
 *   VFX_OBJ_CREATE(icon_bar, VcpStatusIconBar, this);
 * </code>
 */
class VcpStatusIconBar : public VcpPlutoControl
{
    VFX_DECLARE_CLASS(VcpStatusIconBar);

// Constructor / Destructor
public:
    // <group DOM_StatusIconBar_VcpStatusIconBar_Constructor/Destructor>
    // Default constructor.
    VcpStatusIconBar();

//variable
public:
    VfxBool         m_translucent;
    
    VfxFloat        m_curOpacity;

    VfxBool         m_init;

    VfxBool         m_freeze;

    VfxS32          m_barid;

    VfxTimer        *m_timer;

    VfxRect         m_curRect;

    VfxBool         m_enableBackground;

    status_icon_bar_chain_node_struct   m_chain_node;

// Method
public:
    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    // Show an icon with icon ID.
    void showIcon(
        VfxS32 iconId // [IN] Is the icon ID
    );

    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    // Blink an icon with icon ID.
    void blinkIcon(
        VfxS32 iconId // [IN] Is the icon ID
    );

    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    // Animate an icon with icon ID.
    void animateIcon(
        VfxS32 iconId // [IN] Is the icon ID
    );

    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    //  Change an icon level with icon ID and level percentage (0 ~ 100).
    void changeIconLevel(
        VfxS32 iconId,  // [IN] Is the icon ID
        VfxU8 level_percentage // [IN] Is the level percetage (0 ~ 100)
    );

    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    // Change an icon's image with icon ID and image ID.
    void changeIconImage(
        VfxS32 iconId, // [IN] Is the icon ID
        VfxU16 image_id // [IN] Is the image ID
    );

    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    // Enable background filler or not.
    void enableBackground(
        VfxBool enable  // [IN] Enabel background or not.
    );

    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    //Close clock.
    void closeClock();

    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    // Only show system infomation in current screen.
    void hideEvents();

    // <group DOM_StatusIconBar_VcpStatusIconBar_Method>
    // Show events  in current screen.
    void showEvents();

    void registerTapProc(FuncPtr handler);

    void setTranslucent(VfxBool translucent);

    void setEnable(VfxBool enable);

    void setStatusbarBG(VfxS32 id);

    void setFreeze(VfxBool freeze);


// Override
protected:
    static void enterNCenter(
        void *object    // the status icon bar pointer 
    );

    static void leaveNCenter(
        void *object    // the status icon bar pointer 
    );

    void    onTimer(
        VfxTimer* pTime
        );

    // <group DOM_StatusIconBar_VcpStatusIconBar_Override>
    virtual void onPlutoCreate();

    // <group DOM_StatusIconBar_VcpStatusIconBar_Override>
    virtual void onPlutoClose();

    // <group DOM_StatusIconBar_VcpStatusIconBar_Override>
    virtual void onPlutoDraw();

    // <group DOM_StatusIconBar_VcpStatusIconBar_Override>
    virtual VfxBool onPlutoNeedDoubleBuffer() {return VFX_TRUE;}

    // <group DOM_StatusIconBar_VcpStatusIconBar_Override>
    virtual VfxSize onPlutoGetPreferredSize();

    // <group DOM_StatusIconBar_VcpStatusIconBar_Override>
    virtual VfxBool onPenInput(
        VfxPenEvent &event  //[IN] Pen event
        );


};


#endif /* __VCP_STATUS_ICON_BAR_H__ */
