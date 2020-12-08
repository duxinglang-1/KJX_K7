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
 *  vapp_setting_dlui_menu.h
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SETTING_DLUI_MENU_H__
#define __VAPP_SETTING_DLUI_MENU_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vcp_base_menu.h"
#include "vfx_control.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VappVarUILayout: public VcpBaseMenuLayout
{
public:
	VappVarUILayout(VcpBaseMenu* menu)
		:VcpBaseMenuLayout(menu){}
	virtual ~VappVarUILayout(){}
protected:
	virtual void onInit();
	virtual ScrollDirEnum getScrollDir();
	virtual VfxS32 getGroupCount();
	virtual VfxS32 getCellCount(VfxS32 group);
	virtual VfxS32 getContentLength();
	virtual VfxBool hasGroupHeader(VfxS32 group);
	virtual void getPreferFocusMargin(VfxS32 margin[4]);
	virtual VfxBool navDir(NavDirEnum dir);

public:	
	virtual VcpMenuRegion queryRegion(const VfxRect & r);
	VcpMenuPos getCellByPos(VfxPoint pt);
	void setGroupCount(VfxS32 gNum);
	void setTotalItem(VfxS32 totalCount);
	VfxS32 menuPosToIndex(VcpMenuPos pos);
	virtual VfxRect queryCellRect(VcpMenuPos pos);

private:
	VfxS32 m_cellWidth;
	VfxS32 m_totalCount;
	VfxS32 m_groupCount;
};


class VappVarUICell: public VfxControl
{
protected:
	virtual void onInit();
	virtual void onDeinit();

public:
	VappVarUICell():m_curPos(VcpMenuPos(0, 0)), m_imageFrame(NULL),m_timeline1(NULL),m_highlight(VFX_FALSE), m_hiPic(NULL){};
	VappVarUICell(const VcpMenuPos& curPos):m_curPos(curPos), m_imageFrame(NULL),m_timeline1(NULL),m_highlight(VFX_FALSE),m_hiPic(NULL){};
	void enter(const VfxRect& r, VfxBool animation);
	void leave(const VfxRect& r);
	void updatePos(const VfxRect& r, VfxBool isAnim);
	void setHighlight(VfxBool isHighLight);
	VfxBool getHighlight() const;
	void setImage(VfxFrame* imgFrame);
	VfxFrame* getImage(void);

public:
	VfxSignal2 <const VcpMenuPos&, VfxFrame*> m_singalFreeImgMem;
private:
	VcpMenuPos m_curPos;
	VfxFrame* m_imageFrame;
	VfxFloatTimeline* m_timeline1;
	VfxBool m_highlight;
	VfxImageFrame* m_hiPic;
};

class IVappDLUISettingProvider;
class VappVarUIMenu: public VcpBaseMenu
{
public:
	VappVarUIMenu(IVappDLUISettingProvider* dluiProvider);
	virtual ~VappVarUIMenu();

	virtual VcpBaseMenuLayout* createLayout();
	virtual VfxFrame* createGroupHeader(VfxS32 group){ return NULL; }
	virtual void onCloseGroupHeader(VfxS32 group,VfxFrame * groupFrame){ VFX_OBJ_CLOSE(groupFrame); }
	virtual VfxFrame* createCell(VfxS32 group,VfxS32 pos);
	virtual void onCloseCell(VfxS32 group,VfxS32 pos,VfxFrame * cellFrame){ VFX_OBJ_CLOSE(cellFrame); }
	virtual void onUpdateGroupHeader(const VfxRect & rect,VfxS32 group,VfxFrame * groupObject,VfxU32 flag){}
	virtual void onUpdateCell(const VfxRect & rect,VfxS32 group,VfxS32 pos,VfxFrame * cell,VfxU32 flag);
	virtual void onTouchCell(VcpMenuPos cellPos,CellTouchTypeEnum touchType,VfxPoint pt,VfxFrame * cell);
	virtual void onViewScrollEnd();

	VfxS32 getGroupCount() const;
	VfxS32 getItemCount(VfxS32 group) const;
	VfxS32 menuPosToIndex(const VcpMenuPos& pos);
	VfxS32 getTotalItem() const;
	//void setDefault(const VcpMenuPos& pos){ m_default = pos; }

	void freeImgScreenMem(const VcpMenuPos& curPos, VfxFrame* imgFrame);
	void updateCachedImage(void);
	void releaseCachedImage(void);
	void forceCache(void);
	
protected:
	virtual void onFocusIndexChange(
		        VcpMenuPos focusItem,           // [IN] The focus item index now
		        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
    );
	void updateFocus();
private:
	VfxS32 _getTotalItem();

protected:
	IVappDLUISettingProvider* m_dluiProvider;
	VfxS32 m_itemCount;

public:	
    VfxSignal2 <VfxS32, VfxS32> m_signalFocusItemChange;
};
#endif //__VAPP_SETTING_DLUI_MENU_H__
