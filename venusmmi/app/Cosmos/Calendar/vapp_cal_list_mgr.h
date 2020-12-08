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
 *  vapp_cal_list_mgr.h
 *
 * Project:
 * --------
 *  Cosmos
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __VAPP_CAL_LIST_MGR_H__
#define __VAPP_CAL_LIST_MGR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

extern "C"
{
	#include "todolistsrvgprot.h"
}

#include "vfx_datatype.h"
#include "vfx_object.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappCalListMgr
 *****************************************************************************/
class VappCalListMgr : public VfxObject
{
    VFX_DECLARE_CLASS(VappCalListMgr);

public:
    VappCalListMgr() {}
    VappCalListMgr(srv_tdl_vcal_enum type, VfxU16 maxCount) 
                        : m_capacity(maxCount), m_listType(type) {}

public:
    //VfxU16 getListCapacity();
    VfxU16 getAllList(const srv_tdl_vcal_enum &vcalType);
    VfxU16 getList(const srv_tdl_search_filter_struct &filter);
    //srv_tdl_event_task_struct getListItem(const VfxU16 &index);
    VfxU16 getListCount();
    VfxU16 getListItemStoreIndex(const VfxU16 &index);
    //srv_tdl_vcal_enum getListItemType(const VfxU16 &index);
    void sortList(const srv_tdl_sort_type_enum &sortType);
    //srv_tdl_vcal_enum getListType();
    void setSelListItemState(const VfxU16 &index, const VfxU16 &state);
    void setSelListState(const VfxU16 &state);
    VfxU16 getSelListState(const VfxU16 &index);
    VfxU16 getSelListMarkedCount();
    VfxU16 getListIdx(const VfxU16 &storeIdx);
    VfxU16 getListBySubject(const VfxWChar *subject);

    static CHAR * vappCalUcs2istr(CHAR *Dstr, CHAR *Sstr);
    static MMI_BOOL searchBySubCallback(const void *data, 
                                const srv_tdl_vcal_enum vcal_type, 
                                const srv_tdl_search_filter_struct search_filter);
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxU16 m_count;
    VfxU16 m_capacity;
    srv_tdl_vcal_enum m_listType;   
    srv_tdl_event_task_struct *m_list;
    VfxU16 *m_selList;
    VfxU16 m_markedCount;
};

#endif /* __VAPP_CAL_LIST_MGR_H__ */

