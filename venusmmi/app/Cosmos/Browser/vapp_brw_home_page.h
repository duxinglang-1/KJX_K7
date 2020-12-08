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
 *  vapp_browser_home_page.h
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
#ifndef __VAPP_BRW_HOME_PAGE_H__
#define __VAPP_BRW_HOME_PAGE_H__

#ifndef __MMI_BRW_SLIM__
#include "MMI_features.h" 

#ifdef __MMI_BROWSER_2__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_photo_border_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappBrwHomePageIcon : public VcpPhotoBorderFrame
{
    VFX_DECLARE_CLASS(VappBrwHomePageIcon);


public:
	VappBrwHomePageIcon(){};
	VappBrwHomePageIcon(VfxU16 pos, VfxImageSrc &imgData,VfxWString textData, VfxBool lock):
    m_text(NULL),
    m_textImage(NULL),
    m_lockImage(NULL),
    m_image(NULL)
    {
		m_lock = lock;
		if (imgData.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
			m_imgData.setResId(imgData.getResId()); 
		else if (imgData.getType() == VFX_IMAGE_SRC_TYPE_PATH)
			m_imgData.setPath(imgData.getPath());
		m_textData = textData;
		m_pos = pos;
    }

    virtual ~VappBrwHomePageIcon() {};


public:
    // Text in this item.
    VfxTextFrame     *m_text;
    VfxImageFrame *m_textImage;
    VfxImageFrame *m_lockImage;
    // Image in thie item.
    VfxFrame    *m_image;
	VfxFrame    *m_iconDataFrame;
	VfxU32 m_uniqueIconID;
	VfxU16 m_pos;
	VfxBool m_lock;
	VfxImageSrc m_imgData; 
	VfxWString m_textData;

	VfxU16 m_iconWidth;
	VfxU16 m_iconHeight;
	VfxU16 m_lockIconWidth;
	VfxU16 m_lockIconHeight;
	VfxU16 m_iconTextHeight;
	VfxU16 m_iconTitleMargin;
	VfxU16 m_iconTextFontSize;
    VfxU16 m_LockTitleTextMargin;
	VfxSignal1<VfxU8> m_iconItemTap;
    VfxSignal1<VfxU8> m_iconItemLongPress;
	
	//VfxU16 m_pageMargin;
    
    void setHomePageIconElemntsSize(VfxU16 iconWidth,VfxU16 iconHeight,	VfxU16 lockIconWidth,VfxU16 lockIconHeight,VfxU16 iconTextHeight,VfxU16 iconTitleMargin,VfxU16 iconTextFontSize, VfxU16 locktitletextmargin);
    void updateString(void);
    void updateItem (VfxImageSrc &imgData,VfxWString textData, VfxBool lock);
    VfxImageSrc& getImgDataReference(){return m_imgData;};
    VfxWString& getTestDataReference(){return m_textData;};
    void setIconData();
    void setUniqueIconID(VfxU32 uniqueIconID){ m_uniqueIconID = uniqueIconID;};
    VfxU32 getUniqueIconID(void){ return m_pos ;};
    void onItemClicked(void);
    void onItemLongTapped(void);
// Override
protected:
    // Init function.
    virtual void onInit();
    // Deinit function.
    virtual void onDeinit();
	virtual void onUpdate(void);

// Method    
protected:
    void onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);


};
#if defined(__MMI_MAINLCD_240X320__)
	#define TOTAL_HOME_PAGE_ITEMS 6
#else
	#define TOTAL_HOME_PAGE_ITEMS 9
#endif /* __MMI_MAINLCD_240X320__ */

class VappBrwHomePage : public VfxControl
{
    VFX_DECLARE_CLASS(VappBrwHomePage);
public:
    VappBrwHomePage();
    virtual ~VappBrwHomePage() {};

    void enableTap(VfxBool enable);

    VappBrwHomePageIcon *m_iconItems[TOTAL_HOME_PAGE_ITEMS];
    void layoutItems();
    void setRowsColumns(VfxS32 numRows, VfxS32 numColumns);
	void onShortcutLongTap(VfxU8 index);
	void onShortcutItemTap(VfxU8 index);

    VfxCallback4<VfxU8 , VfxImageSrc &, VfxWString &, VfxBool &> m_callback;
    void updateItems(void);
    void updateItems(VfxU8 index);
    void setHomePageElementsSize(VfxU16 iconWidth,VfxU16 iconHeight,VfxU16 lockIconWidth,VfxU16 lockIconHeight,VfxU16 iconTextHeight,VfxU16 iconTitleMargin, VfxU16 HorizontalpageMargin,VfxU16 iconTextFontSize,VfxU16 VerticalPageMargin,VfxU16 HorzExtraMargin,VfxU16 VertExtraMargin,VfxU16 LockTitleTextMargin);
    void registerCallback(const VfxCallback4<VfxU8 , VfxImageSrc &, VfxWString &, VfxBool &> &callback)
     {
         m_callback = callback;
     }
	VfxSignal1<VfxU8> m_iconItemTap;
    VfxSignal1<VfxU8> m_iconItemLongPress;

protected:
    virtual void onInit(void);
    virtual void onDeinit(void);
    virtual void onUpdate();

private:
    void portraitPenDownEffect(VfxFrame *portraitBgFrame);
    void portraitPenUpEffect(void);
    void onClickPortrait(void);
    void onClickAddress(void);
private:
    VappBrwHomePageIcon *m_currentIconItem;
    // The number of rows in matrix.
    VfxS32                  m_numRows;
    // The number of columns in matrix.
    VfxS32                  m_numColumns;

	VfxU16 m_iconWidth;
	VfxU16 m_iconHeight;
	VfxU16 m_lockIconWidth;
	VfxU16 m_lockIconHeight;
	VfxU16 m_iconTextHeight;
	VfxU16 m_iconTitleMargin;
    VfxU16 m_LockTitleTextMargin;
	VfxU16 m_HorizontalpageMargin;
	VfxU16 m_VerticalpageMargin;
	VfxU16 m_iconTextFontSize;
	VfxU16 m_VerticalExtraMargin;
	VfxU16 m_HorizontalExtraMargin;
};

#endif
#endif

#endif /* __VAPP_BRW_HOME_PAGE_H__ */

