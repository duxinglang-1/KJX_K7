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
 *  vapp_contact_backup_restore.cpp
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

#include "vapp_contact_storage.h"
#include "vapp_contact_backup_restore.h"
#include "mmi_rp_vapp_contact_def.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalResDef.h"
#include "PhbSrvGprot.h"
#include "FileMgrSrvGprot.h"
#ifdef __cplusplus
}
#endif


#ifdef __MMI_MULTI_VCARD__

#define CONTACT_BACKUP_MAX_YEAR                 2030
#define CONTACT_BACKUP_MIN_YEAR                 1900
#define CONTACT_BACKUP_MAX_MONTH                12
#define CONTACT_BACKUP_MIN_MONTH                1
#define CONTACT_BACKUP_MAX_DAY                  31
#define CONTACT_BACKUP_MIN_DAY                  1
#define CONTACT_BACKUP_MAX_HOUR                 24
#define CONTACT_BACKUP_MIN_HOUR                 0
#define CONTACT_BACKUP_MAX_MIN                  60
#define CONTACT_BACKUP_MIN_MIN                  0
#define CONTACT_BACKUP_MAX_SEC                  60
#define CONTACT_BACKUP_MIN_SEC                  0
#define CONTACT_BACKUP_TEMP_FILE_FILTER    "%c:\\%s\\~~Temp_????_??_??_??_??_??.xvc"
#define CONTACT_BACKUP_VCARD_FILE_FILTER   "%c:\\%s\\Contact_???_??_??_??_??_??___????_??_??_??_??_??__T????.vcf"

/*----------------------------------------------------------------*/
/* ContactConfigManager                                           */
/*----------------------------------------------------------------*/
void ContactConfigManager::onInit()
{
    m_error = VFX_FALSE;
    
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];
    kal_wsprintf(path,"%c:\\%s", SRV_FMGR_CARD_DRV, SRV_PHB_BACKUP_RESTORE_FILE_FOLDER_NAME);

    FS_HANDLE handle = FS_Open(path, FS_READ_ONLY | FS_OPEN_DIR);
    if (handle < FS_NO_ERROR)
    {
        handle = FS_CreateDir(path);
        if (handle < FS_NO_ERROR)
        {
            m_error = VFX_TRUE;
            return;
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
    }
    FS_Close(handle);

    m_oldFileName.setEmpty();
    m_newFileName.setEmpty();
    m_count = 0;
    m_totalNum = 0;
    m_curIndex = VAPP_CONTACT_BACKUP_RESTORE_MAX_FINE_NUM;

    clearTempvCardFile();
    refreshConfigFile();
}


VfxWString ContactConfigManager::getFilePath()
{
    if (m_oldFileName.isEmpty())
    {
        applib_time_struct time;
        DTGetRTCTime(&time);

        m_year   = time.nYear;
        m_month  = time.nMonth;
        m_day    = time.nDay;
        m_hour   = time.nHour;
        m_minute = time.nMin;
        m_second = time.nSec;

        VfxWChar temp_file[32];
        kal_wsprintf(temp_file,"%c:\\%s\\", SRV_FMGR_CARD_DRV, SRV_PHB_BACKUP_RESTORE_FILE_FOLDER_NAME);
        m_oldFileName += VFX_WSTR_MEM(temp_file);
        m_oldFileName += VFX_WSTR("~~Temp_");
        kal_wsprintf(temp_file, "%04d", m_year);
        m_oldFileName += VFX_WSTR_MEM(temp_file);
        m_oldFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_month);
        m_oldFileName += VFX_WSTR_MEM(temp_file);
        m_oldFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_day);
        m_oldFileName += VFX_WSTR_MEM(temp_file);
        m_oldFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_hour);
        m_oldFileName += VFX_WSTR_MEM(temp_file);
        m_oldFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_minute);
        m_oldFileName += VFX_WSTR_MEM(temp_file);
        kal_wsprintf(temp_file, "%02d", m_second);
        m_oldFileName += VFX_WSTR("_");
        m_oldFileName += VFX_WSTR_MEM(temp_file);
        m_oldFileName += VFX_WSTR(".xvc"); 
    }

    return m_oldFileName;
}


void ContactConfigManager::onRenameConfig(ContactConfigManager *self) /* backup success, post call this function */
{
    generateFileName(); /* generate new file name for backup */

    FS_Rename((const WCHAR*)m_oldFileName.getBuf(), (const WCHAR*)m_newFileName.getBuf());
 
    m_oldFileName.setEmpty();
    m_newFileName.setEmpty();

    VFX_OBJ_CLOSE(self);
}


void ContactConfigManager::refreshConfigFile()
{
    WCHAR file_filter[SRV_FMGR_PATH_MAX_LEN + 1], file_name[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_DOSDirEntry file_info;

    m_totalNum = 0;
    kal_wsprintf(file_filter, CONTACT_BACKUP_VCARD_FILE_FILTER, SRV_FMGR_CARD_DRV, SRV_PHB_BACKUP_RESTORE_FILE_FOLDER_NAME);

    FS_HANDLE handle = FS_FindFirst(file_filter, 0, 0, &file_info, file_name, SRV_FMGR_PATH_MAX_LEN);

    if (handle < 0) /*no filter file match*/
    {
        return;
    }
    else
    {
        do
        {
            if (isValidFileName(file_name))
            {
                if (m_totalNum < VAPP_CONTACT_BACKUP_RESTORE_MAX_FINE_NUM)
                {
                   mmi_wcscpy(m_fileNameArray[m_totalNum++], file_name);
                }
                else
                {
                    FS_FindClose(handle);
                    return;
                }
            }
        }while (FS_FindNext(handle, &file_info, file_name, SRV_FMGR_PATH_MAX_LEN) == FS_NO_ERROR);
    }
    FS_FindClose(handle);
}


VfxBool ContactConfigManager::isFileError()
{
    return m_error;
}


void ContactConfigManager::deleteFile(VfxWChar *fileName)
{
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];

    kal_wsprintf(path,"%c:\\%s\\", SRV_FMGR_CARD_DRV, SRV_PHB_BACKUP_RESTORE_FILE_FOLDER_NAME);
    mmi_wcscat(path, (WCHAR *)fileName);

    FS_Delete(path);
}


VfxU16 ContactConfigManager::getTotalNum()
{
    return m_totalNum;
}


VfxU16  ContactConfigManager::getIndexTotalCount(VfxU16 index)
{
    if (index != m_curIndex)
    {
        readIndexFileInfo(index);
    }

    return m_count;
}


void ContactConfigManager::readIndexFileInfo(VfxU16 id)
{
    if (id >= VAPP_CONTACT_BACKUP_RESTORE_MAX_FINE_NUM || id == m_curIndex)
    {
        return;
    }

    VfxWChar file_name[SRV_FMGR_PATH_MAX_LEN + 1];

    if (getIndexFileName(file_name, id))
    {
        WCHAR temp[8];
        VfxU16 index;
        /*year*/
        index = 8;
        mmi_wcsncpy(temp, file_name + index, 3);
        temp[3] = L'\0';
        m_year = CONTACT_BACKUP_MAX_YEAR - mmi_wcs_wtoi(temp);
        /*month*/
        index = 12;
        mmi_wcsncpy(temp, file_name + index, 2);
        temp[2] = L'\0';
        m_month = CONTACT_BACKUP_MAX_MONTH - mmi_wcs_wtoi(temp);
        /*day*/
        index = 15;
        mmi_wcsncpy(temp, file_name + index, 2);
        temp[2] = L'\0';
        m_day = CONTACT_BACKUP_MAX_DAY - mmi_wcs_wtoi(temp);
        /*hour*/
        index = 18;
        mmi_wcsncpy(temp, file_name + index, 2);
        temp[2] = L'\0';
        m_hour = CONTACT_BACKUP_MAX_HOUR - mmi_wcs_wtoi(temp);
        /*minute*/
        index = 21;
        mmi_wcsncpy(temp, file_name + index, 2);
        temp[2] = L'\0';
        m_minute = CONTACT_BACKUP_MAX_MIN - mmi_wcs_wtoi(temp);
        /*second*/
        index = 24;
        mmi_wcsncpy(temp, file_name + index, 2);
        temp[2] = L'\0';
        m_second = CONTACT_BACKUP_MAX_SEC - mmi_wcs_wtoi(temp);
        /*total*/
        index = 51;
        mmi_wcsncpy(temp, file_name + index, 4);
        temp[4] = L'\0';
        m_count = mmi_wcs_wtoi(temp);

        m_curIndex = id;
    }
}


void ContactConfigManager::readIndexFileInfo(VfxU16 index, mmi_phb_backup_restore_file_config_struct *fp) /*just for RestoreProvider getItemText*/
{
    VFX_ASSERT(fp);

    readIndexFileInfo(index);

    kal_wsprintf(fp->date.year, "%04d", m_year);
    kal_wsprintf(fp->date.month, "%02d", m_month);
    kal_wsprintf(fp->date.day, "%02d", m_day);
    kal_wsprintf(fp->date.hour, "%02d", m_hour);
    kal_wsprintf(fp->date.minute, "%02d", m_minute);
    fp->contact_num = m_count;
}


VfxS32 ContactConfigManager::itemIndexToFileIndex(VfxU32 index)
{
    return index;
}


VfxBool ContactConfigManager::isBackUpFull()
{
    return m_totalNum < VAPP_CONTACT_BACKUP_RESTORE_MAX_FINE_NUM ? VFX_FALSE : VFX_TRUE;
}


void ContactConfigManager::sortFileName()
{
    VfxS32 i, j;
    VfxBool fg;

    fg = VFX_TRUE;

    for (i = 0; i < m_totalNum && fg; ++i)
    {
        fg = VFX_FALSE;
        for (j = 0; j < m_totalNum - i - 1; ++j)
        {
            if (isGreater(m_fileNameArray[j], m_fileNameArray[j + 1]))
            {
                swapFileName(m_fileNameArray[j], m_fileNameArray[j + 1]);
                fg = VFX_TRUE;
            }
        }
    }
}


VfxBool ContactConfigManager::isGreater(const WCHAR *dst, const WCHAR *src)
{
    VfxS32 ret;

    ret = mmi_wcscmp(dst, src);

    return ret > 0 ? VFX_TRUE: VFX_FALSE;
}


void ContactConfigManager::swapFileName(WCHAR *dst, WCHAR *src)
{
    WCHAR str_temp[VAPP_CONTACT_BACKUP_FILE_NAME_MAX_LENGTH];

    mmi_wcscpy(str_temp, dst);
    mmi_wcscpy(dst, src);
    mmi_wcscpy(src, str_temp);
}


VfxWChar *ContactConfigManager::getIndexFileName(VfxWChar *fileName, VfxU16 index)
{
    if (index > VAPP_CONTACT_BACKUP_RESTORE_MAX_FINE_NUM)
    {
        return NULL;
    }

    if (index < m_totalNum)
    {
        mmi_wcscpy(fileName, m_fileNameArray[index]);
        return fileName;
    }

    return NULL;
}

VfxWChar *ContactConfigManager::getIndexFilePath(VfxWChar *fileName, VfxU16 index)
{
    VfxS32 len;

    kal_wsprintf(fileName, "%c:\\%s\\", SRV_FMGR_CARD_DRV, SRV_PHB_BACKUP_RESTORE_FILE_FOLDER_NAME);
    len = mmi_wcslen((WCHAR *)fileName);

    return getIndexFileName(fileName + len, index);
}


VfxBool ContactConfigManager::isValidFileName(VfxWChar *fileName, VfxU8 fileFlag)
{
    WCHAR temp[8];
    VfxU8 index;

    if (0 == fileFlag) /*file name in renameconfig*/
    {
        /*year*/
        index = 8;
        mmi_wcsncpy(temp, fileName + index, 3);
        temp[3] = L'\0';
        if (mmi_wcscmp(temp, (WCHAR *)L"000") < 0 || mmi_wcscmp(temp, (WCHAR *)L"130") > 0)
        {
            return VFX_FALSE;
        }
        /*month*/
        index = 12;
        mmi_wcsncpy(temp, fileName + index, 2);
        temp[2] = L'\0';
        if (mmi_wcscmp(temp, (WCHAR *)L"00") < 0 || mmi_wcscmp(temp, (WCHAR *)L"11") > 0)
        {
            return VFX_FALSE;
        }
        /*day*/
        index = 15;
        mmi_wcsncpy(temp, fileName + index, 2);
        temp[2] = L'\0';
        if (mmi_wcscmp(temp, (WCHAR *)L"00") < 0 || mmi_wcscmp(temp, (WCHAR *)L"30") > 0)
        {
            return VFX_FALSE;
        }
        /*total*/
        index = 51;
        mmi_wcsncpy(temp, fileName + index, 4);
        temp[4] = L'\0';
        if (mmi_wcscmp(temp, (WCHAR *)L"000") < 0 || mmi_wcscmp(temp, (WCHAR *)L"2000") > 0)
        {
            return VFX_FALSE;
        }
    }
    else if (1 == fileFlag) /*temp file*/
    {
        /*year*/
        index = 7;
        mmi_wcsncpy(temp, fileName + index, 4);
        temp[3] = L'\0';
        if (mmi_wcscmp(temp, (WCHAR *)L"1900") < 0 || mmi_wcscmp(temp, (WCHAR *)L"2030") > 0)
        {
            return VFX_FALSE;
        }
        /*month*/
        index = 12;
        mmi_wcsncpy(temp, fileName + index, 2);
        temp[2] = L'\0';
        if (mmi_wcscmp(temp, (WCHAR *)L"01") < 0 || mmi_wcscmp(temp, (WCHAR *)L"12") > 0)
        {
            return VFX_FALSE;
        }
        /*day*/
        index = 15;
        mmi_wcsncpy(temp, fileName + index, 2);
        temp[2] = L'\0';
        if (mmi_wcscmp(temp, (WCHAR *)L"01") < 0 || mmi_wcscmp(temp, (WCHAR *)L"31") > 0)
        {
            return VFX_FALSE;
        }
    }
    /*hour*/
    index = 18;
    mmi_wcsncpy(temp, fileName + index, 2);
    temp[2] = L'\0';
    if (mmi_wcscmp(temp, (WCHAR *)L"00") < 0 || mmi_wcscmp(temp, (WCHAR *)L"24") > 0)
    {
        return VFX_FALSE;
    }
    /*minute*/
    index = 21;
    mmi_wcsncpy(temp, fileName + index, 2);
    temp[2] = L'\0';
    if (mmi_wcscmp(temp, (WCHAR *)L"00") < 0 || mmi_wcscmp(temp, (WCHAR *)L"60") > 0)
    {
        return VFX_FALSE;
    }
    /*second*/
    index = 24;
    mmi_wcsncpy(temp, fileName + index, 2);
    temp[2] = L'\0';
    if (mmi_wcscmp(temp, (WCHAR *)L"00") < 0 || mmi_wcscmp(temp, (WCHAR *)L"60") > 0)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxU16 ContactConfigManager::clearTempvCardFile()
{
    VfxU16 delCount;
    WCHAR file_filter[SRV_FMGR_PATH_MAX_LEN + 1], file_name[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_DOSDirEntry file_info;

    kal_wsprintf(file_filter, CONTACT_BACKUP_TEMP_FILE_FILTER, SRV_FMGR_CARD_DRV, SRV_PHB_BACKUP_RESTORE_FILE_FOLDER_NAME);

    FS_HANDLE handle = FS_FindFirst(file_filter, 0, 0, &file_info, file_name, SRV_FMGR_PATH_MAX_LEN);
    delCount = 0;

    if (handle < 0)
    {
        return 0;
    }
    else
    {
        do
        {
            if (isValidFileName(file_name, 1))
            {
                deleteFile(file_name);
                ++delCount;
            }
        }while (FS_FindNext(handle, &file_info, file_name, SRV_FMGR_PATH_MAX_LEN) == FS_NO_ERROR);
    }
    FS_FindClose(handle);

    return delCount;
}


void ContactConfigManager::setFileConfigure(VfxS32 count, VfxS16 opFlag)
{
    m_count = count;
    vfxPostInvoke1(this, &ContactConfigManager::onRenameConfig, this);
}


void ContactConfigManager::generateFileName()
{
    if (m_newFileName.isEmpty())
    {
        VfxWChar temp_file[32];

        kal_wsprintf(temp_file,"%c:\\%s\\", SRV_FMGR_CARD_DRV, SRV_PHB_BACKUP_RESTORE_FILE_FOLDER_NAME); 
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("Contact_");

        kal_wsprintf(temp_file, "%03d", CONTACT_BACKUP_MAX_YEAR - m_year);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", CONTACT_BACKUP_MAX_MONTH - m_month);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", CONTACT_BACKUP_MAX_DAY - m_day);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", CONTACT_BACKUP_MAX_HOUR - m_hour);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", CONTACT_BACKUP_MAX_MIN - m_minute);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        kal_wsprintf(temp_file, "%02d", CONTACT_BACKUP_MAX_SEC - m_second);
        m_newFileName += VFX_WSTR("_");
        m_newFileName += VFX_WSTR_MEM(temp_file);

        m_newFileName += VFX_WSTR("___");
        kal_wsprintf(temp_file, "%04d", m_year);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_month);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_day);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_hour);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_minute);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR("_");
        kal_wsprintf(temp_file, "%02d", m_second);
        m_newFileName += VFX_WSTR_MEM(temp_file);

        m_newFileName += VFX_WSTR("__T");
        kal_wsprintf(temp_file, "%04d", m_count);
        m_newFileName += VFX_WSTR_MEM(temp_file);
        m_newFileName += VFX_WSTR(".vcf");
    }
}


/*----------------------------------------------------------------*/
/* ContactRestoreProvider                                         */
/*----------------------------------------------------------------*/
void ContactRestoreProvider::onInit()
{
    VfxObject::onInit();

    m_activeCount = 0; 
    m_dateFormat = srv_setting_get_date_format();
    m_timeFormat = srv_setting_get_time_format();
    m_configManage->onInit();
    m_configManage->sortFileName();
    m_fileCount = m_configManage->getTotalNum();
}


VfxBool ContactRestoreProvider::getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    VfxS32 file_index;

    file_index = m_configManage->itemIndexToFileIndex(index);

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        mmi_phb_backup_restore_file_config_struct temp;

        m_configManage->readIndexFileInfo(file_index, &temp);

        switch (m_dateFormat)
        {
        case SETTING_DATE_FORMAT_DD_MM_YYYY:
            text += VFX_WSTR_MEM(temp.date.day);
            text += VFX_WSTR("/");
            text += VFX_WSTR_MEM(temp.date.month);
            text += VFX_WSTR("/");
            text += VFX_WSTR_MEM(temp.date.year);
            break;
        case SETTING_DATE_FORMAT_MM_DD_YYYY:
            text += VFX_WSTR_MEM(temp.date.month);
            text += VFX_WSTR("/");
            text += VFX_WSTR_MEM(temp.date.day);
            text += VFX_WSTR("/");
            text += VFX_WSTR_MEM(temp.date.year);
            break;
        case SETTING_DATE_FORMAT_YYYY_MM_DD:
            text += VFX_WSTR_MEM(temp.date.year);
            text += VFX_WSTR("/");
            text += VFX_WSTR_MEM(temp.date.month);
            text += VFX_WSTR("/");
            text += VFX_WSTR_MEM(temp.date.day);
            break;
        default:
            break;
        }

        text += VFX_WSTR("  ");

        switch (m_timeFormat)
        {
        case SETTING_TIME_FORMAT_12_HOURS:
            {
                VfxBool fg;
                VfxS16 ret = mmi_wcscmp(temp.date.hour, (VfxWChar *)L"12");
                if (ret > 0)
                {
                    fg = VFX_TRUE;
                    VfxS32 val = mmi_wcs_wtoi(temp.date.hour);
                    WCHAR wstr[2 + 1];
                    kal_wsprintf(wstr, "%02d", (val - 12));
                    text += VFX_WSTR_MEM(wstr);
                }
                else
                {
                    fg = VFX_FALSE;
                    text += VFX_WSTR_MEM(temp.date.hour);
                }

                text += VFX_WSTR(":");
                text += VFX_WSTR_MEM(temp.date.minute);

                if (fg)
                {
                    text += VFX_WSTR(" PM");
                }
                else
                {
                    text += VFX_WSTR(" AM");
                }
            }
            break;
        case SETTING_TIME_FORMAT_24_HOURS:
            text += VFX_WSTR_MEM(temp.date.hour);
            text += VFX_WSTR(":");
            text += VFX_WSTR_MEM(temp.date.minute);
            break;
        default:
            break;
        }

        return VFX_TRUE;
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        VfxU16 total;
        total = m_configManage->getIndexTotalCount(file_index);
        text.format("%d ", total);
        if (total != 1)
        {
            text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);
        }
        else
        {
            text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACT_APPEND);
        }

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxU32 ContactRestoreProvider::getCount() const
{
    return m_fileCount;
}


VfxU16 ContactRestoreProvider::getContactCount(VfxU32 index)
{
    VfxS32 file_index;

    file_index = m_configManage->itemIndexToFileIndex(index);

    m_contactCount = m_configManage->getIndexTotalCount(file_index);

    return m_contactCount;
}


VcpListMenuItemStateEnum ContactRestoreProvider::getItemState(
        VfxU32 index   // [IN] index of the item
        ) const 
{
    if (index == m_activeCount)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


VfxBool ContactRestoreProvider::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    text.loadFromRes(STR_ID_VAPP_PHB_NO_FILE_TO_RESTORE);

    return VFX_TRUE;
}


void ContactRestoreProvider::removeFile(VfxS32 index)
{
    VfxS32 file_index = m_configManage->itemIndexToFileIndex(index);
    VfxWChar file_name[SRV_FMGR_PATH_MAX_LEN + 1];

    if (m_configManage->getIndexFileName(file_name, file_index))
    {
        m_configManage->deleteFile(file_name);
    }
}


VfxWString ContactRestoreProvider::getFileName(VfxS32 index)
{
    VfxS32 file_index = m_configManage->itemIndexToFileIndex(index);
    VfxWChar file_name[SRV_FMGR_PATH_MAX_LEN + 1];

    if (m_configManage->getIndexFilePath(file_name, file_index))
    {
        return VfxWString().loadFromMem(file_name);
    }

    return VfxWString();
}


void ContactRestoreProvider::setSelectItem(VfxU32 index)
{
    m_activeCount = (VfxU16)index;
}

#endif /* __MMI_MULTI_VCARD__ */

