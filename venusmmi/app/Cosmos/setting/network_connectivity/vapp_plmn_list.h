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
 *  vapp_plmn_list.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_PLMN_LIST_H__
#define __VAPP_PLMN_LIST_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
extern "C"
{
#include "netsetSrvGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SETTING_PLMN_NOT_FOUND (0xFFFFFFFF)
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
// Typedef 
/***************************************************************************** 
 * Class 
 *****************************************************************************/

class VappSettingPlmnNodeBase : public VfxObject
{
    VFX_DECLARE_CLASS(VappSettingPlmnNodeBase);
   
    // Overrides
    public:
    virtual VfxWString getOperatorName();
    virtual srv_netset_rat_mode_enum getRat() {return m_rat;};
    virtual VfxWString getRatString();
    virtual CHAR* getPlmn() {return m_plmn;};

    // Methods
    public:
    VappSettingPlmnNodeBase() : m_rat(SRV_NETSET_RAT_NONE){};
    VappSettingPlmnNodeBase(const CHAR* plmn, srv_netset_rat_mode_enum rat);
    VappSettingPlmnNodeBase(VappSettingPlmnNodeBase *node);
    // Varialbes
    protected:
    CHAR m_plmn[(MAX_PLMN_LEN + 1)];
    srv_netset_rat_mode_enum m_rat;
};

class VappSettingPlmnList : public VfxObject
{
    VFX_DECLARE_CLASS(VappSettingPlmnList);

    // Overrides    
    public:
//    virtual void onInit();
    VappSettingPlmnList() : m_currentNode(NULL), m_count(0) {};
    virtual void reset() { m_currentNode = m_plmnNodeList.getHead();};
    // Will move the pointer to the next one
    // return NULL if it is at the end of list
    virtual VappSettingPlmnNodeBase *getCurrentNode();
    virtual VappSettingPlmnNodeBase *getNode(VfxId index);
    virtual void appendNode(VappSettingPlmnNodeBase* node);
    virtual void deleteNode(VappSettingPlmnNodeBase* node);
    virtual void deleteNode(VfxId index);
    virtual VfxU32 getCount() {return m_count;};
    virtual void insertNodeBefore(VappSettingPlmnNodeBase* node, VfxId index);
    virtual void insertNodeAfter(VappSettingPlmnNodeBase* node, VfxId index);
    virtual void moveNode(VfxId oldId, VfxId newId);
    // Variables
    protected:
    VfxObjList       m_plmnNodeList;
    VfxObjListEntry *m_currentNode;
    VfxU32           m_count;
};
#endif /* __VAPP_PLMN_LIST_H__ */
 
