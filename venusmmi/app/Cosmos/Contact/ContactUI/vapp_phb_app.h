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
 *  vapp_phb_app.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef _PB_APP_H
#define _PB_APP_H

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vapp_contact_entry.h"
#include "vapp_contact_several.h"
#include "vapp_contact_vcard.h"

#include "vapp_uc_gprot.h"

#ifdef __MMI_OPP_SUPPORT__
#include "vapp_bt_send_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "UcSrvGprot.h"

#include "UcmGprot.h"
#include "FileMgrSrvGprot.h"

#ifdef __MMI_CM_BLACK_LIST__
#include "CallSetSrvGprot.h"
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * enum
 *****************************************************************************/
// cui adpter type enum
typedef enum
{
    VAPP_PHB_CUI_ADPTER_URIAGENT,           // uri agent-> save name/number to contact
    VAPP_PHB_CUI_ADPTER_NOTIFIER,           // unsaved number to phonebook
    VAPP_PHB_CUI_ADPTER_RES,                // image to phonebook
    VAPP_PHB_CUI_ADPTER_VCARD,
    VAPP_PHB_CUI_ADPTER_ENUM_TOTAL          // enum end
} vapp_phb_cui_adpter_enum;


// action type enum
typedef enum
{
    VAPP_PHB_ACTION_CALL,                   // make call
    VAPP_PHB_ACTION_MSG,                    // send message
    VAPP_PHB_ACTION_EMAIL,                  // send email
    VAPP_PHB_ACTION_MSG_MARK,               // send multi message
    VAPP_PHB_ACTION_SHARE,                  // share contacts
    VAPP_PHB_ACTION_TYPE_TOTAL              // enum end
} vapp_phb_action_type_enum;


// cui adpter launch struct
typedef struct
{
    vapp_phb_cui_adpter_enum m_type;
    WCHAR m_name[MMI_PHB_NAME_LENGTH + 1];
    WCHAR m_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    U32 m_userData;
} vapp_phb_cui_adpter_struct;


// action data struct
typedef struct
{
    mmi_phb_contact_id m_id;
    VfxU32             m_type;
    VfxU32             m_subType;
} vapp_phb_action_data_struct;


/***************************************************************************** 
 * class VappPhbActionObj
 *****************************************************************************/ 
class VappPhbActionObj: public VfxObject
{
public:
    VappPhbActionObj();

    void setType(vapp_phb_action_type_enum type);

    void setData(vapp_phb_action_data_struct& data);

    static void makeCall(mmi_phb_contact_id id, VappContactNumber& number, mmi_sim_enum sim, MMI_BOOL m_isIpDial = MMI_FALSE);

    static void videoCall(mmi_phb_contact_id id, VappContactNumber& number);

    static void sendMessage(mmi_phb_contact_id id, VappContactNumber& number, mmi_sim_enum sim);

    static void sendEmail(mmi_phb_contact_id id, VappContactEmail& email);

    static void makeCallCb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para);

private:
    vapp_phb_action_type_enum   m_type;
    vapp_phb_action_data_struct *m_data;
    VfxU32                      m_count;
    static  MMI_BOOL            m_isIpDial;    

};


/***************************************************************************** 
 * Class VappPhbSharevCardBase
 *****************************************************************************/
	
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
class VappPhbSharevCardBase: public VfxBase
{
public:
    VappPhbSharevCardBase():
        m_idArray(NULL),
        m_count(0),
        m_path(NULL){}

    void setCount(VfxU16 count)
    {
        m_count = count;
        m_idArray = (mmi_phb_contact_id*)srv_phb_mem_malloc(sizeof(mmi_phb_contact_id) * count, SRV_PHB_MEMORY_TYPE_ADM);
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BT]malloc--count: %d\n, array: 0x%0x\n", count, m_idArray);
    }

    void setId(VfxU16 index, mmi_phb_contact_id id)
    {
        VFX_ASSERT(index < m_count);
        m_idArray[index] = id;
    }

    static MMI_BOOL getNextvCard(WCHAR* path, void* para)
    {
        VappPhbSharevCardBase *base = (VappPhbSharevCardBase*) para;

        if (NULL == path)
        {
            base->closeSelf();
            return MMI_FALSE;
        }

        VfxS32 result;
        VfxWChar *file = base->getFile(path, base->m_idArray[(base->m_index)++], &result);

        if (file == NULL)
        {
            path[0] = 0;
        }

        if (base->m_index >= base->m_count)
        {
            base->closeSelf();
            return MMI_FALSE;
        }

        return MMI_TRUE;
    }

    void start(mmi_id groupId, ContactMark *mark)
    {
        setCount(mark->getCount());
        for (m_index = 0; m_index < m_count; m_index++)
        {
            m_idArray[m_index] = mark->getMarkKey(m_index).m_id;
        }

        m_index = 0;

#ifdef __MMI_OPP_SUPPORT__
        vapp_bt_send_app_info info;
        info.group_id = groupId;
        info.callback = VappPhbSharevCardBase::getNextvCard;
        info.user_data = this;

        vapp_bt_send_obj(
            &info,
            VAPP_BT_SEND_DELETE_FILE,
            m_count,
            NULL);
#endif /* __MMI_OPP_SUPPORT__ */
    }

    VfxS32 buildFileName(VfxWChar* path, mmi_phb_contact_id id)
    {
        m_path = path;

        kal_wsprintf(
            m_path,
            "%c:\\~vcard",
            VCARD_DRV);

        FS_HANDLE fh = FS_CreateDir(m_path);
        if (fh != FS_NO_ERROR && fh != FS_FILE_EXISTS)
        {
            return (VfxS32)fh;
        }

        VfxWChar temp_name[MMI_PHB_NAME_LENGTH+ 1];
        VfxWChar *name;
        ContactEntry entry(id);

        srv_phb_convert_to_name(
            temp_name,
            (U16*)(entry.getName().getGivenBuf()),
            (U16*)(entry.getName().getFamilyBuf()),
            MMI_PHB_NAME_LENGTH);

        name = (VfxWChar*)srv_fmgr_path_skip_leading_space(temp_name);

        //unnamed
        if (mmi_wcslen(name) == 0)
        {
            mmi_wcscpy(temp_name, VFX_WSTR_RES(VAPP_PHB_STR_UNNAMED).getBuf());
        }

        kal_wsprintf(
            m_path,
            "%c:\\~vcard\\%w%s",
            VCARD_DRV,
            name,
            VCARD_FILE_EXT);

        fh = FS_Open(m_path, FS_READ_ONLY);
        FS_Close(fh);

        if (fh == FS_INVALID_FILENAME)
        {
            kal_wsprintf(
                m_path,
                "%c:\\~vcard\\~vcard%s",
                VCARD_DRV,
                VCARD_FILE_EXT);
        }

        return FS_NO_ERROR;
    }

    VfxWChar* getFile(VfxWChar *path, mmi_phb_contact_id id, VfxS32 *result)
    {
        // build file name
        *result = buildFileName(path, id);

        if (*result != FS_NO_ERROR && *result != FS_FILE_EXISTS)
        {
            return NULL;
        }

        // build vcard
        VB_HANDLE vb;
        vcard_object_struct *vcard;

        vcard = (vcard_object_struct*)srv_phb_mem_malloc(sizeof(vcard_object_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(vcard, 0, sizeof(vcard_object_struct));

        vb = vcard_open_builder(m_path, VCARD_OPEN_MODE_DEFAULT, result);
        if (!vb)
        {
            srv_phb_mem_free(vcard);
            FS_Delete(path);
            return NULL;
        }

        srv_phb_contact handle = srv_phb_read_contact(id, NULL, NULL);
        srv_phb_contact_to_vcard_object(handle, vcard);

        *result = vcard_build(vb, vcard);
        if (*result == VCARD_RESULT_FAIL)
        {
            *result = vcard_get_build_error(vb);
            vcard_close_builder(vb);
            srv_phb_free_contact(handle);
            srv_phb_mem_free(vcard);
            FS_Delete(path);
            return NULL;
        }

        srv_phb_free_contact(handle);
        vcard_close_builder(vb);
        srv_phb_mem_free(vcard);

        return m_path;
    }

private:
    void closeSelf()
    {
        if (m_idArray != NULL)
        {
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BT]free--count: %d, array: 0x%0x\n", m_count, m_idArray);
            srv_phb_mem_free(m_idArray);
            m_idArray = NULL;
        }

        VfxBase *base = this;
        delete base;
    }

public:
    mmi_phb_contact_id *m_idArray;
    VfxU16             m_count;
    VfxWChar*          m_path;
    VfxU16             m_index;
};

#endif /*__MMI_OPP_SUPPORT__ && __MMI_VCARD__ */
/***************************************************************************** 
 * Class VappPhbCuiAdpter
 *****************************************************************************/ 
class VappPhbCuiAdpter : public VfxApp
{
    VFX_DECLARE_CLASS(VappPhbCuiAdpter);

public:
    virtual void onRun(void* args, VfxU32 argSize);

protected:
    virtual mmi_ret onProc(mmi_event_struct *evt);

public:
    vapp_phb_cui_adpter_enum m_type;
};


extern "C"
{

extern VfxBool vapp_phb_usb_app_is_available(void);

extern VfxBool vapp_phb_ready_balloon(void);

extern void vapp_phb_init_uri_agent_registration(void);

extern void vapp_phb_op_error_balloon(S32 result);

extern srv_callset_result_enum vapp_phb_add_to_blacklist(mmi_phb_contact_id id, VappContactNumber& number);

extern VfxBool vapp_phb_is_blocked_number(mmi_phb_contact_id id, VappContactNumber& number);

extern srv_callset_result_enum vapp_phb_delete_from_blacklist(mmi_phb_contact_id id, VappContactNumber& number);

#ifdef __DM_LAWMO_SUPPORT__
extern VfxS32 vapp_phb_dm_wipe_do_format();

extern mmi_ret vapp_phb_multi_op_done(mmi_event_struct* evt);
#endif /* __DM_LAWMO_SUPPORT__ */
}

#endif /* _PB_APP_H */
