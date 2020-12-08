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
 * VappWorldclockSelectCity.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements world clock application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __VAPP_WORLD_CLOCK_SELECT_CITY_H__
#define __VAPP_WORLD_CLOCK_SELECT_CITY_H__

#include "Vfx_datatype.h"
#include "vfx_page.h"
#include "vcp_list_menu.h"

#include "vapp_worldclock_data_control.h"

/***************************************************************************** 
 * Class VappWCSelectCityPage
 *****************************************************************************/
class VcpTitleBar;
class VappWCSelectCityPage : public VfxPage,IVcpListMenuContentProvider
{     
    VFX_DECLARE_CLASS(VappWCSelectCityPage);
    
public:

    VappWCSelectCityPage(VfxBool isHighlightDisable);
    VappWCSelectCityPage(){};
    ~VappWCSelectCityPage();

// Interface
public:
    VfxU32 getCount() const;
    VfxBool getMenuEmptyText(VfxWString &text,VcpListMenuTextColorEnum &color);   
    VfxBool getItemText(
                VfxU32 index,
                VcpListMenuFieldEnum fieldType,
                VfxWString& text,
                VcpListMenuTextColorEnum & color
                );
    VfxBool getItemTextFormat(
                VfxU32 index,
                VcpListMenuFieldEnum fieldType,
                VcpRichText & format
                );

    VcpListMenuCellClientBaseFrame* getItemCustomContentFrame(
                                        VfxU32 index,
                                        VfxFrame * parentFrame);
    void closeItemCustomContentFrame(
								VfxU32 index,
								VcpListMenuCellClientBaseFrame *cell); 
    void setTitleText(const VfxWString &titleString);
    VfxWString getDateString(VfxU32 index);
    VfxWString getTimeString(VfxU32 index);

public:
    VfxSignal2 <
        VfxObject *, // Sender
        VfxU16       // cityIndex
        > m_signalCitySelected;

// Implement
private: 
    void onInit();
	void onEntered();
    void onTextChanged(VcpTextEditor *sender);    
    void onItemTapped(VcpListMenu *item, VfxU32 index);
    void onTimeUpdate(VfxU32 flag);
    void updateDateTimeList();
	
private:
    VfxU8 m_cityLen;   
    VfxU16 m_listLen;
	VfxBool m_firstEnter;
    VfxU16 *m_listIndex;    
    VfxU16 selectcityindex;
    VfxBool m_isHighlightDisable;
    VcpTitleBar *m_titleBar;
    VcpListMenu *m_citylist;
    VfxWChar **m_dateList;
    VfxWChar **m_timeList;
    VappWCDataControl m_dataControl;
};


/***************************************************************************** 
 * Class VappWCSelectCityCellItem
 *****************************************************************************/
class VappWCSelectCityCellItem : public VcpListMenuCellMultiTextFrame
{

public:
    VappWCSelectCityCellItem(){}
    VappWCSelectCityCellItem(VfxU32 index, VappWCSelectCityPage *page);

// Override
protected:
    virtual void onCreateElements(void);
    virtual void onCloseElements(void);
    virtual void onLayoutElements(void);
    virtual void onUpdateElements(void);

// Implement
private:
    VfxTextFrame *m_time;
    VfxTextFrame *m_date;
    VfxU32 m_index;
    VappWCSelectCityPage *m_parent;
};

#endif
