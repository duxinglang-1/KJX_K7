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
 *  vapp_phb_backup_restore.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)

#ifndef __PB_BACKUP_RESTORE_H__
#define __PB_BACKUP_RESTORE_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"

#include "vapp_contact_backup_restore.h"
#include "vapp_contact_op.h"
#include "vapp_ncenter_base_cell.h"


/***************************************************************************** 
 * Class PBBackUp
 *****************************************************************************/ 
class PBBackUp: public VfxObject
{
public:
    PBBackUp(){}
    PBBackUp(VfxMainScr *scr):
        m_parent(scr),
        m_cloud(VFX_FALSE),
        m_backUp(NULL),
        m_progress(NULL){}
#ifdef __VCARD_CLOUD_SUPPORT__
    PBBackUp(VfxMainScr *scr, VfxU32 providerId, VfxU8 accountId):
        m_parent(scr),
        m_cloud(VFX_TRUE),
        m_providerId(providerId),
        m_accountId(accountId),
        m_backUp(NULL),
        m_progress(NULL){}
#endif /* __VCARD_CLOUD_SUPPORT__ */

    static VfxBool doCanRun();

public:
    VfxSignal0 m_signalBackUpDone;
    
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxMainScr              *m_parent;
    VfxBool                  m_cloud;
    ContactConfigManager    *m_configManage;
#ifdef __VCARD_CLOUD_SUPPORT__
    VfxU32 m_providerId;
    VfxU8 m_accountId;
#endif /* __VCARD_CLOUD_SUPPORT__ */
    ContactOP               *m_backUp;
    VcpIndicatorPopup       *m_progress;

private:
    static void onBackUpCB(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result);
    void onCancelClick(VfxObject*, VfxFloat);
    void terminate();
    void closeSelf(void *p);
    void onBackupDone();
};


/***************************************************************************** 
 * Class PBRestorePage
 *****************************************************************************/ 
class PBRestorePage : public VfxPage
{
public:
    PBRestorePage(){}
    PBRestorePage(VfxMainScr *scr, VfxU16 *path):
        m_selectFile(0),
        m_fileList(NULL),
        m_listProvider(NULL){}

    static VfxBool doCanRun();

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    VfxS32                  m_selectFile;
    VcpListMenu            *m_fileList;
    ContactRestoreProvider *m_listProvider;
    ContactConfigManager   *m_configManage;

private:
    void fileSelect(VcpListMenu* list, VfxU32 index);
    void onToolBarClicked(VfxObject* obj, VfxId id);
    void deleteTap();
    void onButtonClicked(VfxObject* obj, VfxId id);
    void removeSelectFile();
    static mmi_ret listener(mmi_event_struct* evt);
};


/***************************************************************************** 
 * Class PBRestore
 *****************************************************************************/ 
class PBRestore: public VfxObject
{
public:
    PBRestore(){}
    PBRestore(VfxMainScr *scr, const VfxWString path, VcpConfirmPopup *confirm):
        m_parent(scr),
        m_cloud(VFX_FALSE),
        m_path(path),
        m_confirmPopup(confirm),
        m_delete(NULL),
        m_restore(NULL),
        m_progress_delete(NULL),
        m_progress_restore(NULL){}
#ifdef __VCARD_CLOUD_SUPPORT__
    PBRestore(VfxMainScr *scr, VfxU32 providerId, VfxU8 accountId):
        m_parent(scr),
        m_cloud(VFX_TRUE),
        m_providerId(providerId),
        m_accountId(accountId),
        m_restore(NULL),
        m_delete(NULL),
        m_progress_delete(NULL),
        m_progress_restore(NULL){}
#endif /* __VCARD_CLOUD_SUPPORT__ */

public:
    VfxSignal0 m_signalRestoreDone;

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxMainScr             *m_parent;
    VfxBool                 m_cloud;
    VfxWString              m_path;
#ifdef __VCARD_CLOUD_SUPPORT__
    VfxU32 m_providerId;
    VfxU8 m_accountId;
#endif /* __VCARD_CLOUD_SUPPORT__ */
    VcpConfirmPopup        *m_confirmPopup;
    ContactOP              *m_delete;	
   	ContactOP              *m_restore;
    VcpIndicatorPopup      *m_progress_delete;
    VcpIndicatorPopup      *m_progress_restore;
private:
    void restoreBegin();
    void restoreContinue();
    static void onDeleteAllCB(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* cb);
    static void onRestoreCB(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* cb);
    void onCancelClick(VfxObject* obj, VfxFloat num);
    void onBtnClicked(VfxObject* obj, VfxId id);
    void terminate();
    void onRestoreDone();
};

#endif /* __PB_BACKUP_RESTORE_H__ */
#endif /* defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */


