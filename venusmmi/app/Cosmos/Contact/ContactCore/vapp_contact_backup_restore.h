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
 *  vapp_contact_backup_restore.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __CONTACT_BACKUP_RESTORE_H__
#define __CONTACT_BACKUP_RESTORE_H__

#include "vfx_uc_include.h"
#include "vcp_include.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"
#include "GeneralSettingSrvGprot.h"

#ifdef __MMI_VCARD__
#include "vcard_lib.h"
#endif

#ifdef __cplusplus
}
#endif


#ifdef __MMI_MULTI_VCARD__
/*----------------------------------------------------------------*/
/* ContactConfigManager                                           */
/*----------------------------------------------------------------*/

#define VAPP_CONTACT_BACKUP_RESTORE_MAX_FINE_NUM 20
#define VAPP_CONTACT_BACKUP_FILE_NAME_MAX_LENGTH 64

class ContactConfigManager : public VfxObject
{
public:
    virtual void onInit();

public:
    VfxWString getFilePath();
    VfxU16 getContactCount(VfxU32 index);
    VfxU16 getTotalNum();
    VfxU16 getIndexTotalCount(VfxU16 index);
    VfxWChar *getIndexFileName(VfxWChar *fileName, VfxU16 index);
    VfxWChar *getIndexFilePath(VfxWChar *fileName, VfxU16 index);
    void setFileConfigure(VfxS32 count, VfxS16 opFlag = 0);
    void refreshConfigFile();
    VfxBool isFileError();
    void deleteFile(VfxWChar *fileName);
    void readIndexFileInfo(VfxU16 index);
    void readIndexFileInfo(VfxU16 index, mmi_phb_backup_restore_file_config_struct *fp);
    VfxS32 itemIndexToFileIndex(VfxU32 index);
    VfxBool isBackUpFull();
    void sortFileName();
    VfxBool isGreater(const WCHAR *dst, const WCHAR *src);
    void swapFileName(WCHAR *dst, WCHAR *src);

private:
    void    generateFileName();
    void    onRenameConfig(ContactConfigManager *self);
    VfxBool isValidFileName(VfxWChar *fileName, VfxU8 fileFlag = 0);
    VfxU16  clearTempvCardFile();

private:
    VfxU16 m_year;
    VfxU16 m_month;
    VfxU16 m_day;
    VfxU16 m_hour;
    VfxU16 m_minute;
    VfxU16 m_second;
    VfxU16 m_count;
    VfxU8  m_totalNum;
    VfxU16 m_curIndex;
    VfxWString m_oldFileName;
    VfxWString m_newFileName;
    WCHAR m_fileNameArray[VAPP_CONTACT_BACKUP_RESTORE_MAX_FINE_NUM][VAPP_CONTACT_BACKUP_FILE_NAME_MAX_LENGTH];
    VfxBool m_error;
};


/*----------------------------------------------------------------*/
/* ContactRestoreProvider                                         */
/*----------------------------------------------------------------*/
class ContactRestoreProvider : public VfxObject, public IVcpListMenuContentProvider 
{
public:
    ContactRestoreProvider(){}
    ContactRestoreProvider(ContactConfigManager *ptr):
        m_configManage(ptr){}

    virtual void onInit();

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    void removeFile(VfxS32 index);
    VfxWString getFileName(VfxS32 index);
    VfxU16 getContactCount(VfxU32 index);
    void setSelectItem(VfxU32 index);

private:
    VfxS32    m_fileCount;
    VfxU16    m_contactCount;
    VfxU16    m_activeCount;
    srv_setting_date_format_enum m_dateFormat;
    srv_setting_time_format_enum m_timeFormat;
    ContactConfigManager *m_configManage; 
};

#endif /* __MMI_MULTI_VCARD__ */

#endif /* __CONTACT_BACKUP_RESTORE_H__ */

