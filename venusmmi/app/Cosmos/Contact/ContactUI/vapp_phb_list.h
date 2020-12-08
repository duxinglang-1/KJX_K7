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
 *  vapp_phb_list.h
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
 * removed!
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
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __PB_LIST_H__
#define __PB_LIST_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"

#include "vapp_contact_list.h"
#include "vapp_contact_several.h"
#include "vapp_contact_op.h"
#include "vapp_phb_gprot.h"
#include "vapp_phb_menu_list_cp.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"

#ifdef __cplusplus
}
#endif


enum
{
#if defined(__MMI_MAINLCD_320X480__)
    LIST_COUNT_FONT_SIZE = 20,
    LIST_COUNT_FRM_SIZE_H = 40,
#elif defined(__MMI_MAINLCD_480X800__)
    LIST_COUNT_FONT_SIZE = 30,
    LIST_COUNT_FRM_SIZE_H = 50,
#else
    LIST_COUNT_FONT_SIZE = 20,
    LIST_COUNT_FRM_SIZE_H = 40,
#endif

    VAPP_PHB_LIST_UI_ENUM_END
};


enum vapp_phb_list_type_enum
{
    VAPP_PHB_LIST_NORMAL,
    VAPP_PHB_LIST_SINGLE,
    VAPP_PHB_LIST_MARK,
    VAPP_PHB_LIST_TYPE_TOTAL
};


enum vapp_phb_list_storage_type_enum
{
    VAPP_PHB_LIST_STORAGE_TYPE_NORAML,
    VAPP_PHB_LIST_STORAGE_TYPE_IMPORT,
    VAPP_PHB_LIST_STORAGE_TYPE_ENTRY,
    VAPP_PHB_LIST_STORAGE_TYPE_TOTAL
};


/***************************************************************************** 
 * Class VappPhbListCountFrame
 *****************************************************************************/ 
class VappPhbListCountFrame: public VfxFrame
{
public:
    VappPhbListCountFrame(){}

    void setCount(VfxU32 count);

protected:
    virtual void onInit();

private:
    VfxTextFrame *m_text;
};


/***************************************************************************** 
 * Class VappPhbListCp
 *****************************************************************************/ 
class VappPhbListCp: public VcpGroupListMenu, public IVcpGroupListMenuContentProvider
{
public:
    VappPhbListCp(VfxBool b2ndReady = VFX_FALSE):
        m_b2ndReady(b2ndReady),
        m_list(NULL),
        m_mark(NULL),
        m_listType(VAPP_PHB_LIST_NORMAL),
        m_searchText(VFX_WSTR_EMPTY),
        m_countText(NULL),
        m_countTextExist(VFX_FALSE),
        m_storageType(VAPP_PHB_LIST_STORAGE_TYPE_NORAML),
        m_activity(NULL){}

public:
    void setProvider();

    void setListType(vapp_phb_list_type_enum type);

    void setSearchString(const VfxWString& search);

    void setAlignField(VfxU32 alignField);

    void setStorage(phb_storage_enum storage);

#ifdef __MMI_PHB_CALLER_GROUP__ 
    void setGroup(VfxU8 groupId, VfxBool isEqual = VFX_TRUE);
#endif  /* __MMI_PHB_CALLER_GROUP__ */   

    void setEmptyStr(VfxResId str);
    
    void setRefreshFlag(VfxBool flag);

    void setListStorageType(vapp_phb_list_storage_type_enum storageType);

    void getList();

public:
    // build list done
    void onListReady();

    // list changed
    void onListRefresh(ContactList* list, mmi_event_struct* evt);

    void onListGetting();

    void onListBoundsChanged(VfxFrame* frame, const VfxRect& rect);

    void onContactUpdated(ContactTask* task, mmi_event_struct* evt);

    // get list object
    ContactList* getListObject();

    void markAll();

    void unMarkAll();

    VfxWString getAlignValue(VfxU32 index, VfxU32 groupIndex);

    ContactMark *getMarked() const;

    VfxWString& getSearchString();

    void configSeekBar();

    void onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos);

    void onItemLongTaped(VcpGroupListMenu *list, VcpMenuPos pos);

public:
    virtual VfxU32 getCount(VfxU32 group) const;

    virtual VfxU32 getGroupCount() const;

    virtual VfxBool hasGroupHeader(VfxS32 group) const;

    virtual VfxWString getGroupString(VfxU32 group);

    virtual VfxU32 getId(VfxU32 index, VfxU32 groupIndex = 0);

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemText(
                VcpMenuPos pos,                    // [IN] the position of item
                VcpListMenuFieldEnum fieldType,    // [IN] the type of the field in the cell
                VfxWString &text,                  // [OUT] the text resource
                VcpListMenuTextColorEnum &color    // [OUT] the text color
                );

    virtual VfxBool getItemTextFormat(
                VcpMenuPos pos,                  // [IN] the position of item
                VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                VcpRichText &format              // [OUT] the text resource
                );

    virtual VfxBool getItemImage(
                VcpMenuPos pos,                  // [IN] the position of item
                VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                VfxImageSrc &image               // [OUT] the image resource
                );

    virtual VfxU32 getSeekBarEntryCount();

    virtual VfxBool getSeekBarEntryText(
        VfxU32 index,       // [IN] index of the seek bar entry
        VfxWString &text    // [OUT] the text of the seek bar entry
        );

    virtual VfxBool getItemPosNeedJumpTo(
        VfxU32 touchedSeekBarEntryIndex,  // [IN] the index of the touched seek bar entry
        VcpMenuPos &posJumpTo             // [OUT] the list menu position need jump to
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos pos                   // [IN] position of the item
        ) const;

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VcpMenuPos pos,         // [IN] position of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        );

public:
    void onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state);

    void onTextChanged(VcpTextEditor *editor);

    // list count signal
    VfxSignal2<VappPhbListCp*, VfxU32> m_signalCount;

protected:
    virtual void onInit();

private:
    // list object
    VfxBool m_b2ndReady;
    ContactList *m_list;
    ContactMark *m_mark;
    vapp_phb_list_type_enum m_listType;
    VfxWString              m_searchText;
    VappPhbListCountFrame  *m_countText;
    VfxBool                 m_countTextExist;
    VfxResId                m_str;
    VfxBool                 m_stopRefresh;
    VappPhbListMenuItemBase::ListModeEnum m_listMode;
    VfxBool                 m_tcardMask;
    VfxBool                 m_singleMask;
    vapp_phb_list_storage_type_enum m_storageType;
	VcpActivityIndicator   *m_activity;
};

#endif /* __PB_LIST_H__ */

