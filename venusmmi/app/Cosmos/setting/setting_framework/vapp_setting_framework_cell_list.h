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
 *  vapp_setting_framework_cell_list.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SETTING_FRAMEWORK_CELL_LIST_H__
#define __VAPP_SETTING_FRAMEWORK_CELL_LIST_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_framework_gprot.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappSettingFWBaseCell
 *****************************************************************************/
class VappSettingFWBaseCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappSettingFWBaseCell);

    // Override
    public:
    virtual void updateCell();
    
    // Method
    public:
    virtual void onTap(VcpFormItemCell* sender, VfxId senderId) {};
    
    // Variables
    public:
    VfxId m_titleStringId;
    VfxId m_hintStringId;
};

/***************************************************************************** 
 * VappSettingFWPublicCell
 *****************************************************************************/
class VappSettingFWPublicCell : public VappSettingFWBaseCell
{
    VFX_DECLARE_CLASS(VappSettingFWPublicCell);

    // Override
    public:
    virtual void onTap(VcpFormItemCell* sender, VfxId senderId);    

    // Methods
    public:
    VappSettingFWPublicCell() : m_menuId(0), m_launchHdlr(NULL) {};
    // Variables
    public:
    VfxId m_menuId;    
    VappSettingLaunchHdlr m_launchHdlr;    
    VfxSignal1 <VfxId> m_signalEntryMenu;
};

/***************************************************************************** 
 * VappSettingFWIconCell
 *****************************************************************************/
class VappSettingFWIconCell : public VappSettingFWPublicCell
{
    VFX_DECLARE_CLASS(VappSettingFWIconCell);
    protected:
    // The size parameter should be the same as the VcpListMenuCellIconSingleTextFrame
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 10,
        IMG_LEFT_GAPS    = 8,
        IMG_RIGHT_GAPS   = 8,
        IMG_MAX_WIDTH    = 30,
        // Add for setting framework cell
        IMG_MAX_HEIGHT    = 30,        
        ACCESSORY_WIDTH  = 30,
        ACCESSORY_RIGHT_GAPS = 8
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 18,
        IMG_LEFT_GAPS    = 14,
        IMG_RIGHT_GAPS   = 18,
        IMG_MAX_WIDTH    = 35,
        // Add for setting framework cell
        IMG_MAX_HEIGHT    = 35,        
        ACCESSORY_WIDTH  = 30,
        ACCESSORY_RIGHT_GAPS = 8        
    };
#else
    enum
    {
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 8,
        IMG_LEFT_GAPS    = 5,
        IMG_RIGHT_GAPS   = 5,
        IMG_MAX_WIDTH    = 23,
        // Add for setting framework cell        
        IMG_MAX_HEIGHT    = 23,
        ACCESSORY_WIDTH  = 30,
        ACCESSORY_RIGHT_GAPS = 8        
    };
#endif       

    // Overrides
    public:
    virtual void onInit();
    void setIconResId(VfxU32 id) {if (id) m_imageFrame->setResId(id);};
    virtual void onUpdate();
    
    // Variables
    private:
    VfxImageFrame *m_imageFrame;
};

/***************************************************************************** 
 * VappSettingFWCellList a list for VcpFormItemBase
 *****************************************************************************/
class VappSettingFWCellList : public VfxObject
{
    VFX_DECLARE_CLASS(VappSettingFWCellList);
    //typedef
    typedef struct _VappSettingFWItemContainer
    {
        VcpFormItemBase *cell;
        _VappSettingFWItemContainer *nextContainer;        
    } VappSettingFWItemContainer;

    // Method
    public:
    VappSettingFWCellList() : m_cellContainterHead(NULL), m_currentCellContainer(NULL) {};
    virtual ~VappSettingFWCellList();
    VcpFormItemBase* getCell() {return m_currentCellContainer->cell;};
    VcpFormItemBase* getNext();
    void addCell(VcpFormItemBase* cell);
    void reset() {m_currentCellContainer = m_cellContainterHead;};
    void setParentMenuId(VfxId parentMenuId) {m_parentMenuId = parentMenuId;};
    // Variables
    private:
    VappSettingFWItemContainer *m_cellContainterHead;
    VappSettingFWItemContainer *m_currentCellContainer;
    VfxId                       m_parentMenuId;
};

/***************************************************************************** 
 * VappSettingFWCelllistCreator
 *****************************************************************************/
class VappSettingFWCelllistCreator : public VfxObject
{
    VFX_DECLARE_CLASS(VappSettingFWCelllistCreator);

    // Method
    public:
    VappSettingFWCellList* getMenuCellList(VfxId menuId, VfxPage *page);
    VfxWString getPublicMenuTitle(VfxId menuId);
    VfxBool checkIsSubItem(VfxId menuId);
    
    protected:
    VappSettingConfigStruct* getConfigStruct(VfxId menuId);
    VappSettingConfigStruct* getItemStruct(VfxId parentMenuId);
    VcpFormItemBase* createCell(VappSettingConfigStruct* configStruct, VfxPage *page);
    //Variable
    VfxId  m_searchId;
    VappSettingConfigStruct *m_searchPointer;
};
#endif /* __VAPP_SETTING_FRAMEWORK_CELL_H__ */

