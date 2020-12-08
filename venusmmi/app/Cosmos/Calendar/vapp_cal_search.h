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
 *  vapp_cal_search.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  search list screen of event/task
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CAL_SEARCH_H__
#define __VAPP_CAL_SEARCH_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifndef __LOW_COST_SUPPORT_COMMON__
#include "MMIDatatype.h"

extern "C" 
{
#include "todolistsrvgprot.h"
}

//#include "vcp_include.h"
//#include "vfx_mc_include.h"
#include "vfx_datatype.h"
#include "vfx_page.h"

#include "vcp_list_menu.h"
#include "vcp_menu_popup.h"


/***************************************************************************** 
 * Declaration 
 *****************************************************************************/

#define VAPP_CAL_SEARCH_SUBJECT_LEN    10

/***************************************************************************** 
 * Class  VappCalSearchPage
 *****************************************************************************/
class VcpTextEditor;
class VfxWString;
class VappCalListMgr;
class VfxObject;

//can be used by calendar event and task    
class VappCalSearchPage : public VfxPage, public IVcpListMenuContentProvider
{
	VFX_DECLARE_CLASS(VappCalSearchPage);

//construct
public:
    VappCalSearchPage(): 
        m_searchStringLen(0),
        m_vcalType(SRV_TDL_VCAL_EVENT)
        {
        }
    VappCalSearchPage(srv_tdl_vcal_enum type): 
        m_searchStringLen(0)
        {
            m_vcalType = type;
        }

// Override
public:
    // IVcpListMenuContentProvider
    virtual VfxBool getItemText(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxWString &text,                
            VcpListMenuTextColorEnum &color  
            );   

    virtual VfxU32 getCount() const;
    
    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VcpRichText &format        
        );
    
    virtual VfxBool getMenuEmptyText(
                        VfxWString &text,               
                        VcpListMenuTextColorEnum &color);


    // Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    
public:
    void onListMenuLongTap(VcpListMenu *sender, VfxId id);
    void onOpListClicked(VcpMenuPopup* sender, VcpMenuPopupEventEnum evtEnum, VcpMenuPopupItem* item);
    void onLongPressDelConfirm(VfxObject* sender, VfxId id);
    void onTextChanged(VcpTextEditor *sender);
    void onItemTapped(VcpListMenu *sender, VfxU32 id);
    void onDataUpdated(VfxObject *sender);
    void GetSnsData(const VfxWChar *subject = NULL);
    static mmi_ret updateSNSListData(mmi_event_struct *param);


public:
    void setDataChangeState(VfxBool isDataChanged);
    mmi_ret processOpEvent(mmi_event_struct *param);
    static mmi_ret updateSearchPage(mmi_event_struct *param);
    static mmi_ret updateEventSearchPage(mmi_event_struct *param);

    //variable
public:    
   VappCalListMgr *m_dataMgr;
   VcpListMenu *m_listMenu;
   VfxU32 m_searchStringLen;
   srv_tdl_vcal_enum m_vcalType;
   VfxU16 m_dataChangedType;
   VfxU16 m_selIdx;
   VfxWeakPtr<VcpMenuPopup> m_opListWeakPtr;
   VfxWeakPtr<VcpConfirmPopup> m_confirmPopupWeakPtr;
   VfxS32 m_jobId; 
   VfxU32 m_count;
   srv_tdl_event_id_struct *m_eventbuffer ;
   VfxU16 m_stringId;

   VfxBool m_dataChanged;

};

#endif/* __LOW_COST_SUPPORT_COMMON__*/
#endif /* __VAPP_CAL_SEARCH_H__ */
