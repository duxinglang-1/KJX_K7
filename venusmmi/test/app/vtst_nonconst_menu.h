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
 *  vtst_nonconst_menu.h
 *
 * Project:
 * --------
 *  Venus Regression Test
 *
 * Description:
 * ------------
 *  Menu with Nonconst Cell Size
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VTST_NONCONSTANT_MENU_H_
#define _VTST_NONCONSTANT_MENU_H_

#include "vcp_base_menu.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"

class VtstNonconstMenu;

/*****************************************************************************
 * class VtstNonconstMenuLayout
 *****************************************************************************/

class VtstNonconstMenuLayout : public VcpBaseMenuLayout
{
// Constructor / Destructor
public:
    VtstNonconstMenuLayout(VtstNonconstMenu* menu);

    ~VtstNonconstMenuLayout();

// Method
public:
    void setLayoutData();

    void setLayoutWidth(VfxU32 width);

// Override
public:
    virtual void onInit();

    virtual ScrollDirEnum getScrollDir();

    virtual VfxS32 getCellCount(VfxS32 group);

    virtual VfxS32 getContentLength();

    virtual VcpMenuRegion queryRegion(const VfxRect& r);

    virtual void onViewChanged();

    // Return a cell rect
    virtual VfxRect queryCellRect(VcpMenuPos pos);

private:
// Variable
    VfxU32 * m_accumulateSizeArray;
    VfxU32 m_count;
    VtstNonconstMenu * m_nonconstMenu;

//Implementation
    VcpMenuPos getCellByPos(VfxPoint pt);
};


/*****************************************************************************
 * class VtstNonconstMenuLayout
 *****************************************************************************/

class VtstNonconstMenu : public VcpBaseMenu
{
// Constructor / Destructor
public:
    VtstNonconstMenu();

// To Be Overridden
// must override: createCell(), getNonconstCellHeight(), getNonconstCellCount()
public:
    virtual void onInit();

    virtual VfxU32 getNonconstCellCount() = 0;

    virtual VfxU32 getNonconstCellHeight(VfxU32 index) = 0;

    virtual void onNonconstViewChanged(VfxS32 y);

// Override
public:
    virtual VcpBaseMenuLayout* createLayout();

    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);

    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag);
};

#endif //_VTST_NONCONSTANT_MENU_H_

