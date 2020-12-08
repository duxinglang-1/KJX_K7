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
 *  vapp_contact_setting.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __CONTACT_SETTING_H__
#define __CONTACT_SETTING_H__

#include "vfx_uc_include.h"
#include "vcp_include.h"


/***************************************************************************** 
 * Class VappContactStorageProvider
 *****************************************************************************/
class VappContactStorageProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    virtual void onInit();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
            VfxU32 index,                    // [IN] the index of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxWString &text,                // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
            );
    virtual VcpListMenuItemStateEnum getItemState(
            VfxU32 index   // [IN] index of the item
            ) const;
    virtual VfxBool getItemIsDisabled(
            VfxU32 index   // [IN] the index of item
            ) const;

    void setStorageDone();
    void setStorageState(VcpListMenu *list, VfxU32 index, VcpListMenuItemStateEnum state);
    VfxBool isUserSelect();

    static VfxWString getStorageString();

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    void updateProvider();
#endif

private:
    phb_storage_enum m_storageList[PHB_STORAGE_NUM];
    VfxBool    m_chooseList[PHB_STORAGE_NUM];
    VfxU32     m_count;

private:
    void storageSelectInit();
};


#ifdef __MMI_PHB_LAST_NAME_FIELD__
/***************************************************************************** 
 * Class VappContactNameDisplayProvider
 *****************************************************************************/
class VappContactNameDisplayProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    virtual void onInit();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
            VfxU32 index,                    // [IN] the index of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxWString &text,                // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
            );
    virtual VcpListMenuItemStateEnum getItemState(
            VfxU32 index   // [IN] index of the item
            ) const;

    static VfxWString getNameDisplayString();

private:
    VfxBool    m_chooseList[2];
};
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */

#endif /* __CONTACT_SETTING_H__ */

