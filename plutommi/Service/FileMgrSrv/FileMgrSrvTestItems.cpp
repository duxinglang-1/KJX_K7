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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  FileMgrSrvTest.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Testbed of File manager service
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _FMGR_INTERNAL_SOURCE_C_
#define _FMGR_GPROT_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
extern "C"
{
#include "MMI_include.h"
#include "FileMgrSrvProt.h"
}

#if defined(SRV_FMGR_TESTBED_ENABLE)

#include "FileMgrSrvTest.h"

extern "C" mmi_ret srv_fmgr_cidb_notify_hdlr(mmi_event_struct *param);

/****************************************************************************
* Setting
*****************************************************************************/

#ifndef __MTK_TARGET__
#define FMGR_TESTBED_PATH   (WCHAR*)L" :\\FmgrSrv_modis\\"
#else
#define FMGR_TESTBED_PATH   (WCHAR*)L" :\\FmgrSrv_target\\"
#endif

/***************************************************************************** 
 * Test Implementation
 *****************************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define TEST_COMMON

static U8 rt_get_test_drive(void)
{
    return SRV_FMGR_CARD_DRV;
}

static void rt_init_testbed_path(WCHAR* buffer, S32 buffer_size)
{
    ASSERT((mmi_wcslen(FMGR_TESTBED_PATH)+1)*2 <= buffer_size);
    mmi_wcscpy(buffer, FMGR_TESTBED_PATH);
    buffer[0] = rt_get_test_drive();
}

#define TEST_PATH

class SrvFtstPath : public SrvFtstTestItem
{
// Variable
public:

// Constructor / Destructor
public:
    SrvFtstPath() {}

// Override
protected:
    virtual int start() 
    {
        srv_fmgri_set_trace_level(1);
        return 0;
    }
    virtual void end() 
    {
        srv_fmgri_set_trace_level(0);
    }

    virtual S32 phase(S32 idx)
    { 
        if(idx == 0)
        {
            /* srv_fmgr_path_get_filename_pos */
            SRV_FTST_CHECK(-1 == srv_fmgr_path_get_filename_pos(NULL));
            SRV_FTST_CHECK(-1 == srv_fmgr_path_get_filename_pos((WCHAR*)L""));
            SRV_FTST_CHECK(10 == srv_fmgr_path_get_filename_pos((WCHAR*)L"A:\\Photos\\test.jpg"));
            SRV_FTST_CHECK(10 == srv_fmgr_path_get_filename_pos((WCHAR*)L"B:\\Photos\\test.jpg\\"));
            SRV_FTST_CHECK(10 == srv_fmgr_path_get_filename_pos((WCHAR*)L"A:\\Photos\\  test.jpg"));
            SRV_FTST_CHECK(10 == srv_fmgr_path_get_filename_pos((WCHAR*)L"C:\\Photos\\ABC"));
            SRV_FTST_CHECK(10 == srv_fmgr_path_get_filename_pos((WCHAR*)L"D:\\Photos\\ABC\\"));
            SRV_FTST_CHECK(7  == srv_fmgr_path_get_filename_pos((WCHAR*)L"Photos\\test.jpg"));
            SRV_FTST_CHECK(0  == srv_fmgr_path_get_filename_pos((WCHAR*)L"test.jpg"));
            SRV_FTST_CHECK(0  == srv_fmgr_path_get_filename_pos((WCHAR*)L"test.jpg\\"));
            SRV_FTST_CHECK(2  == srv_fmgr_path_get_filename_pos((WCHAR*)L"  test.jpg"));

            /* srv_fmgr_path_get_extension_pos */
            SRV_FTST_CHECK(-1 == srv_fmgr_path_get_extension_pos(NULL));
            SRV_FTST_CHECK(-1 == srv_fmgr_path_get_extension_pos((WCHAR*)L""));
            SRV_FTST_CHECK(1  == srv_fmgr_path_get_extension_pos((WCHAR*)L".jpg"));
            SRV_FTST_CHECK(5  == srv_fmgr_path_get_extension_pos((WCHAR*)L"test.jpg"));
            SRV_FTST_CHECK(-1 == srv_fmgr_path_get_extension_pos((WCHAR*)L"test.jpg\\"));
            SRV_FTST_CHECK(15 == srv_fmgr_path_get_extension_pos((WCHAR*)L"A:\\Photos\\test.jpg"));
            SRV_FTST_CHECK(-1 == srv_fmgr_path_get_extension_pos((WCHAR*)L"B:\\Photos\\test"));
            SRV_FTST_CHECK(11 == srv_fmgr_path_get_extension_pos((WCHAR*)L"C:\\Photos\\.jpg"));
            SRV_FTST_CHECK(-1 == srv_fmgr_path_get_extension_pos((WCHAR*)L"D:\\Photos\\test.jpg\\"));

            /* srv_fmgr_path_is_filename_valid */
            SRV_FTST_CHECK(MMI_FALSE == srv_fmgr_path_is_filename_valid(NULL));
            SRV_FTST_CHECK(MMI_FALSE == srv_fmgr_path_is_filename_valid((WCHAR*)L""));
            SRV_FTST_CHECK(MMI_FALSE == srv_fmgr_path_is_filename_valid((WCHAR*)L"  "));
            SRV_FTST_CHECK(MMI_TRUE  == srv_fmgr_path_is_filename_valid((WCHAR*)L"test.jpg"));
            SRV_FTST_CHECK(MMI_TRUE  == srv_fmgr_path_is_filename_valid((WCHAR*)L"test.jpg.123.456"));
            SRV_FTST_CHECK(MMI_TRUE  == srv_fmgr_path_is_filename_valid((WCHAR*)L"   test.jpg.123.456"));
            SRV_FTST_CHECK(MMI_TRUE  == srv_fmgr_path_is_filename_valid((WCHAR*)L"te   st.jpg.123.456"));
            SRV_FTST_CHECK(MMI_FALSE == srv_fmgr_path_is_filename_valid((WCHAR*)L"A:\\Photos\\test.jpg"));
            SRV_FTST_CHECK(MMI_FALSE == srv_fmgr_path_is_filename_valid((WCHAR*)L"test.jpg.12\r3.456"));
            SRV_FTST_CHECK(MMI_FALSE == srv_fmgr_path_is_filename_valid((WCHAR*)L"te|st.jpg.123"));
            SRV_FTST_CHECK(MMI_FALSE == srv_fmgr_path_is_filename_valid((WCHAR*)L"test.jp:g"));
            
            return 0;
        }
        else if(idx == 1)
        {
            WCHAR path[SRV_FMGR_PATH_MAX_LEN+1];
            S32 fs_ret;

            /* srv_fmgr_path_append */
            SRV_FTST_CHECK(srv_fmgr_path_append(NULL, 0, NULL) == MMI_FALSE);
            mmi_wcscpy(path, (WCHAR*)L"D:\\123");
            SRV_FTST_CHECK(srv_fmgr_path_append(path, sizeof(path), (WCHAR*)L"ABC") == MMI_TRUE);
            SRV_FTST_CHECK(mmi_wcscmp(path, (WCHAR*)L"D:\\123\\ABC") == 0);
            mmi_wcscpy(path, (WCHAR*)L"D:\\123\\");
            SRV_FTST_CHECK(srv_fmgr_path_append(path, sizeof(path), (WCHAR*)L"ABC") == MMI_TRUE);
            SRV_FTST_CHECK(mmi_wcscmp(path, (WCHAR*)L"D:\\123\\ABC") == 0);
            mmi_wcscpy(path, (WCHAR*)L"D:\\123");
            SRV_FTST_CHECK(srv_fmgr_path_append_ex(path, sizeof(path), (WCHAR*)L"ABC", MMI_TRUE) == MMI_TRUE);
            SRV_FTST_CHECK(mmi_wcscmp(path, (WCHAR*)L"D:\\123\\ABC\\") == 0);
            mmi_wcscpy(path, (WCHAR*)L"D:\\123");
            SRV_FTST_CHECK(srv_fmgr_path_append_ex(path, sizeof(path), (WCHAR*)L"ABC\\", MMI_TRUE) == MMI_TRUE);
            SRV_FTST_CHECK(mmi_wcscmp(path, (WCHAR*)L"D:\\123\\ABC\\") == 0);

            mmi_wcscpy(path, (WCHAR*)L"D:\\123\\ABC\\");
            SRV_FTST_CHECK(mmi_wcscmp(srv_fmgr_path_remove_slash(path), (WCHAR*)L"D:\\123\\ABC") == 0);
            mmi_wcscpy(path, (WCHAR*)L"D:\\123\\ABC");
            SRV_FTST_CHECK(mmi_wcscmp(srv_fmgr_path_remove_slash(path), (WCHAR*)L"D:\\123\\ABC") == 0);

            /* srv_fmgr_path_skip_leading_space */
            SRV_FTST_CHECK(srv_fmgr_path_skip_leading_space(NULL) == NULL);
            mmi_wcscpy(path, (WCHAR*)L"");
            SRV_FTST_CHECK(srv_fmgr_path_skip_leading_space(path) == path);
            mmi_wcscpy(path, (WCHAR*)L"D:\\123\\456");
            SRV_FTST_CHECK(srv_fmgr_path_skip_leading_space(path) == path);
            mmi_wcscpy(path, (WCHAR*)L"  D:\\123\\456");
            SRV_FTST_CHECK(srv_fmgr_path_skip_leading_space(path) == path+2);

            /* srv_fmgr_path_remove_filename */
            TEST_srv_fmgr_path_remove_filename(path, (WCHAR*)L"D:\\Photos\\test.jpg\\", (WCHAR*)L"D:\\Photos\\");
            TEST_srv_fmgr_path_remove_filename(path, (WCHAR*)L"D:\\Photos\\test.jpg", (WCHAR*)L"D:\\Photos\\");
            TEST_srv_fmgr_path_remove_filename(path, (WCHAR*)L"D:\\Photos\\", (WCHAR*)L"D:\\");
            TEST_srv_fmgr_path_remove_filename(path, (WCHAR*)L"D:\\Photos", (WCHAR*)L"D:\\");
            /* ===================================== Operate File system ================*/

            /* srv_fmgr_fs_create_folder */
            SRV_FTST_CHECK(srv_fmgr_fs_create_folder(NULL) < 0);
            
            mmi_wcscpy(path, (WCHAR*)L"D:\\123\\12345678901234567890123456789");
            path[0] = SRV_FMGR_PUBLIC_DRV;
            fs_ret = srv_fmgr_fs_delete(path);
            SRV_FTST_CHECK(fs_ret == FS_PATH_NOT_FOUND || fs_ret == FS_FILE_NOT_FOUND || fs_ret >= 0);
            SRV_FTST_CHECK(srv_fmgr_fs_create_folder(path) == 0);
            SRV_FTST_CHECK(srv_fmgr_fs_path_exist(path) == 0);

            mmi_wcscpy(path, (WCHAR*)L"D:\\123\\456\\789\\12345678901234567890123456789012345678901234567890\\");
            path[0] = SRV_FMGR_PUBLIC_DRV;
            fs_ret = srv_fmgr_fs_delete(path);
            SRV_FTST_CHECK(fs_ret == FS_PATH_NOT_FOUND || fs_ret == FS_FILE_NOT_FOUND ||  fs_ret >= 0);
            SRV_FTST_CHECK(srv_fmgr_fs_create_folder(path) == 0);
            SRV_FTST_CHECK(srv_fmgr_fs_path_exist(path) == 0);

            /* srv_fmgr_fs_path_exist */
            SRV_FTST_CHECK(srv_fmgr_fs_path_exist(path) == 0);

            /* srv_fmgr_fs_path_is_not_empty */
            SRV_FTST_CHECK(srv_fmgr_fs_path_is_not_empty(path, NULL) == 0);
            SRV_FTST_CHECK(srv_fmgr_fs_path_is_not_empty((WCHAR*)L"root", NULL) > 0);        
            return 0;
        }
        
        return SRV_FTST_RT_END_TESTCASE;
    }

    void TEST_srv_fmgr_path_remove_filename(WCHAR* path, const WCHAR* src1, const WCHAR* src2)
    {
        mmi_wcscpy(path, src1);
        srv_fmgr_path_remove_filename(path);
        SRV_FTST_CHECK(mmi_wcscmp(path, src2) == 0);
    }

};

SrvFtstTestResultEnum srv_ftst_rt_path(U32 param)
{
    SRV_FTST_START(SrvFtstPath);
    return SRV_FTST_TR_OK;
}

#define TEST_STORAGE

extern "C" MMI_BOOL srv_fmgri_test_drv_in_c(void);

class SrvFtstStorage : public SrvFtstTestItem
{
// Variable
public:

// Constructor / Destructor
public:
    SrvFtstStorage() {}

// Override
protected:
    virtual int start() 
    {
        srv_fmgri_set_trace_level(1);
        return 0;
    }
    virtual void end() 
    {
        srv_fmgri_set_trace_level(0);
    }

    virtual S32 phase(S32 idx)
    { 
        SRV_FMGR_DRVLIST_HANDLE list;
        S32 drv_count, i;
        U8  drv_letter;
        WCHAR drv_name[SRV_FMGR_DRV_MAX_NAME_LEN + 1];
        U64 size;
        S32 drv_type;

        list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
        drv_count = srv_fmgr_drivelist_count(list);

        for(i=0;i<drv_count;i++)
        {
            drv_letter = srv_fmgr_drivelist_get_drv_letter(list, i);

            SRV_FTST_CHECK(srv_fmgr_drv_get_name(drv_letter, NULL, 0) > 0);
            SRV_FTST_CHECK(srv_fmgr_drv_get_name(drv_letter, drv_name, sizeof(drv_name)) == 0);

            SRV_FTST_CHECK(srv_fmgr_drv_get_string(drv_letter) > 0);

            drv_type = srv_fmgr_drv_get_type(drv_letter);
            SRV_FTST_CHECK(drv_type >= 0);

            SRV_FTST_CHECK(srv_fmgr_drv_is_valid(drv_letter) == MMI_TRUE);

            if(srv_fmgr_drv_is_accessible(drv_letter))
            {
                SRV_FTST_CHECK(srv_fmgr_drv_get_size(drv_letter, &size, NULL) >= 0);
            }

            SRV_FTST_CHECK(i == srv_fmgr_drivelist_get_index_by_drv_letter(list, drv_letter));
            SRV_FTST_CHECK(i == srv_fmgr_drivelist_get_index_by_drv_type(list, (srv_fmgr_drv_type_enum)drv_type));
        }

        SRV_FTST_CHECK(srv_fmgr_drv_is_valid(0) == MMI_FALSE);
        SRV_FTST_CHECK(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_TOTAL) == 0);

        SRV_FTST_CHECK(srv_fmgri_test_drv_in_c() == MMI_TRUE);
        
        return SRV_FTST_RT_END_TESTCASE;
    }

};

SrvFtstTestResultEnum srv_ftst_rt_storage(U32 param)
{
    SRV_FTST_START(SrvFtstStorage);
    return SRV_FTST_TR_OK;
}

#define TEST_TYPES

class SrvFtstTypes : public SrvFtstTestItem
{
// Variable
public:

// Constructor / Destructor
public:
    SrvFtstTypes() {}

// Override
protected:
    virtual int start() 
    {
        srv_fmgri_set_trace_level(1);
        return 0;
    }
    virtual void end() 
    {
        srv_fmgri_set_trace_level(0);
    }

    virtual S32 phase(S32 idx)
    { 
        if(idx == 0)
        {
            SRV_FTST_CHECK(srv_fmgr_types_find_type_by_filename_str((WCHAR*)L"123.bmp") == FMGR_TYPE_BMP);
            SRV_FTST_CHECK(srv_fmgr_types_find_type_by_extension_str((WCHAR*)L"bmp") == FMGR_TYPE_BMP);
            SRV_FTST_CHECK(srv_fmgr_types_find_type_by_filepath((WCHAR*)L"123.bmp") == FMGR_TYPE_BMP);
            SRV_FTST_CHECK(srv_fmgr_types_find_group_by_type(FMGR_TYPE_BMP) == FMGR_GROUP_IMAGE);
            SRV_FTST_CHECK(srv_fmgr_types_find_group_by_filename_str((WCHAR*)L"123.bmp") == FMGR_GROUP_IMAGE);

            FMGR_FILTER filter;
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
            SRV_FTST_CHECK(srv_fmgr_types_get_main_type(&filter) == FMGR_TYPE_BMP);

            SRV_FTST_CHECK(strcmp(srv_fmgr_types_get_extension(FMGR_TYPE_BMP), "BMP") == 0);
            SRV_FTST_CHECK(mmi_wcscmp(srv_fmgr_types_get_extension_ucs2(FMGR_TYPE_BMP), (WCHAR*)L"BMP") == 0);

            SRV_FTST_CHECK(srv_fmgr_types_get_icon(FMGR_TYPE_BMP, NULL, SRV_FMGR_TYPES_ICON_SMALL) != 0);
            SRV_FTST_CHECK(srv_fmgr_types_get_icon(FMGR_TYPE_BMP, NULL, SRV_FMGR_TYPES_ICON_LARGE) != 0);

            SRV_FTST_CHECK(srv_fmgr_types_get_option_menu(FMGR_TYPE_BMP, NULL, 0) != 0);
            SRV_FTST_CHECK(srv_fmgr_types_get_send_option_menu(FMGR_TYPE_BMP, NULL) != 0);
            SRV_FTST_CHECK(srv_fmgr_types_get_use_option_menu(FMGR_TYPE_BMP, NULL) != 0);

            return 0;
        }
        else if(idx == 1)
        {
            /* filter test */
            U16 t;
            FMGR_FILTER filter;

            FMGR_FILTER_INIT(&filter);
            for(t=0;t<FMGR_TYPE_COUNT;t++)
                SRV_FTST_CHECK(FMGR_FILTER_IS_SET(&filter, t) == 0);
            
            FMGR_FILTER_SET_ALL(&filter);
            for(t=0;t<FMGR_TYPE_COUNT;t++)
                SRV_FTST_CHECK(FMGR_FILTER_IS_SET(&filter, t) != 0);

            FMGR_FILTER_INIT(&filter);
            for(t=0;t<FMGR_TYPE_COUNT;t++)
            {
                FMGR_FILTER_SET(&filter, t);
                SRV_FTST_CHECK(FMGR_FILTER_IS_SET(&filter, t) != 0);
                FMGR_FILTER_CLEAR(&filter, t);
                SRV_FTST_CHECK(FMGR_FILTER_IS_SET(&filter, t) == 0);
            }

        }
        
        return SRV_FTST_RT_END_TESTCASE;
    }

};

SrvFtstTestResultEnum srv_ftst_rt_types(U32 param)
{
    SRV_FTST_START(SrvFtstTypes);
    return SRV_FTST_TR_OK;
}
#define TEST_FOLDERFL

class SrvFtstFFLTravel : public SrvFtstTestItem
{
// Variable
public:
   
    WCHAR   m_path[SRV_FMGR_PATH_MAX_LEN + 1];
    WCHAR   m_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];

    SRV_FMGR_FILELIST_HANDLE m_handle;

    S32     m_base_folder_len;
    S32     m_count;
    S32     m_index;
    S32     m_sort_option;
    FMGR_FILTER m_filter;

// Constructor / Destructor
public:
    SrvFtstFFLTravel() : m_handle(0)
    {
        reinit();
    }

    virtual ~SrvFtstFFLTravel()
    {
        if(m_handle)
            srv_fmgr_filelist_destroy(m_handle);
    }

    void reinit(void)
    {
        if(m_handle)
        {
            srv_fmgr_filelist_destroy(m_handle);
            m_handle = 0;
        }

        rt_init_testbed_path(m_path, sizeof(m_path));
        m_base_folder_len = mmi_wcslen(m_path);

        m_index = -1;
        m_sort_option = FS_SORT_NAME;
        FMGR_FILTER_SET_ALL(&m_filter);
    }


// Override
protected:
    virtual int start() 
    {
        srv_fmgri_set_trace_level(1);
        return 0;
    }
    virtual void end() 
    {
        srv_fmgri_set_trace_level(0);
    }

    virtual S32 phase(S32 idx)
    { 
        S32 fs_ret;
        if(idx == 0)        /* test empty file list */
        {
            if(!check(srv_fmgr_drv_is_accessible(rt_get_test_drive()) == MMI_TRUE, (WCHAR*)L"No memory card", NULL, 0))
                return SRV_FTST_RT_END_TESTCASE;
        
            reinit();
            
            /* test empty list */
            fs_ret = srv_fmgr_empty_filelist_create(&m_handle);
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            SRV_FTST_CHECK(srv_fmgr_filelist_get_state(m_handle) == SRV_FMGR_FILELIST_STATE_READY);
            SRV_FTST_CHECK(srv_fmgr_filelist_get_capability(m_handle) == SRV_FMGR_FILELIST_CAP_RANDOM_ACCESS);
            SRV_FTST_CHECK(srv_fmgr_filelist_count(m_handle) == 0);
            SRV_FTST_CHECK(srv_fmgr_filelist_is_empty(m_handle) == MMI_TRUE);
            SRV_FTST_CHECK(srv_fmgr_filelist_is_dirty(m_handle) == MMI_FALSE);
            SRV_FTST_CHECK(srv_fmgr_filelist_get_filepath(m_handle, 0, NULL, 0) == FS_PARAM_ERROR);
            SRV_FTST_CHECK(srv_fmgr_filelist_get_filename(m_handle, 0, NULL, 0) == FS_PARAM_ERROR);
            SRV_FTST_CHECK(srv_fmgr_filelist_get_fileinfo(m_handle, 0, NULL) == FS_PARAM_ERROR);
            SRV_FTST_CHECK(srv_fmgr_filelist_load_file(m_handle, 0, _Proc, NULL) == FS_PARAM_ERROR);
            SRV_FTST_CHECK(srv_fmgr_filelist_refresh(m_handle, NULL, 0, 0, _Proc, NULL) == FS_PARAM_ERROR);
            srv_fmgr_filelist_get_setting(m_handle, NULL, NULL);
            srv_fmgr_filelist_set_setting(m_handle, NULL, 0);
            srv_fmgr_filelist_destroy(m_handle);
            m_handle = NULL;

            return 0;
        }
        else if(idx == 1)   /* test folder traverse */
        {
            reinit();
            
            fs_ret = createFilelist();
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;
            fs_ret = srv_fmgr_filelist_refresh(m_handle, NULL, 0, 0, SrvFtstFFLTravel::_Proc, this);
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            return -1;
        }
        else if(idx == 2)   /* test folder traverse, with filter */
        {
            reinit();
            
            FMGR_FILTER_INIT(&m_filter);
            FMGR_FILTER_SET(&m_filter, FMGR_TYPE_FOLDER);
            srv_fmgr_types_filter_set_group(&m_filter, FMGR_GROUP_AUDIO);
            
            fs_ret = createFilelist();
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;
            fs_ret = srv_fmgr_filelist_refresh(m_handle, NULL, 0, 0, SrvFtstFFLTravel::_Proc, this);
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            return -1;
        }

        return SRV_FTST_RT_END_TESTCASE;
    }

protected:
    virtual const WCHAR* getOutputFilename(void)
    {
        return (WCHAR*)L"SrvFtstFFLTravel.result";
    }

    virtual void onFile(const WCHAR* path, const srv_fmgr_fileinfo_struct* info)
    {
        writeString(path);
    }

    virtual S32 createFilelist(void)
    {
        return srv_fmgr_folder_filelist_create(m_path, &m_filter, m_sort_option, NULL, 0, &m_handle);
    }

protected:
    virtual const WCHAR* getWritePath(WCHAR* path, S32 size)
    {
        if(!getOutputFilename())
            return NULL;
        kal_wsprintf(path, "%c:\\%w", rt_get_test_drive(), getOutputFilename());
        return path;
    }

    virtual const WCHAR* getCheckPath(WCHAR* path, S32 size)
    {
        if(!getOutputFilename())
            return NULL;
        rt_init_testbed_path(path, size);
        srv_fmgr_path_append(path, size, getOutputFilename());
        return path;
    }

    virtual mmi_ret onProc(mmi_event_struct *param)
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        srv_fmgr_filelist_refresh_result_event_struct *evt;
        srv_fmgr_filelist_load_result_event_struct *load_evt;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/

        switch(param->evt_id)
        {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
            evt = (srv_fmgr_filelist_refresh_result_event_struct*)param;

            if(!SRV_FTST_CHECK(evt->result >= 0))
            {
                endPhase(MMI_TRUE);
                return MMI_RET_OK;
            }

            m_count = srv_fmgr_filelist_count(evt->handle);
            if(evt->search_index >= 0)
                m_index = evt->search_index;
            
            if(!SRV_FTST_CHECK(m_index < m_count))
            {
                endPhase(MMI_TRUE);
                return MMI_RET_OK;
            }

            onLoop();
            break;
            
        case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:
            load_evt = (srv_fmgr_filelist_load_result_event_struct*)param;

            if(!SRV_FTST_CHECK(load_evt->result >= 0))
            {
                endPhase(MMI_TRUE);
                return MMI_RET_OK;
            }

            if(!SRV_FTST_CHECK(m_index >= load_evt->ready_index_start && m_index < load_evt->ready_index_end))
            {
                endPhase(MMI_TRUE);
                return MMI_RET_OK;
            }

            m_index--;
            onLoop();
            break;
        }
        return MMI_RET_OK;
    }

private:
    virtual void onLoop(void)
    {
        srv_fmgr_fileinfo_struct fileinfo;
        S32 fs_ret, len;
        
        while(1)
        {
            m_index++;
            if(m_index == m_count)
            {
                /* already at root, end test */
                if(mmi_wcslen(m_path) <= m_base_folder_len)
                {
                    srv_fmgr_filelist_destroy(m_handle);
                    m_handle = 0;
                    endPhase();
                    break;
                }
                
                /* go back to upper folder */
                mmi_wcscpy(m_name, srv_fmgr_path_get_filename_ptr(m_path));
                len = mmi_wcslen(m_name);
                if(m_name[len-1] == '\\')
                    m_name[len-1] = 0;
                srv_fmgr_path_remove_filename(m_path);
                
                srv_fmgr_filelist_destroy(m_handle);
                m_handle = 0;
                fs_ret = createFilelist();
                if(!SRV_FTST_CHECK(fs_ret >= 0))
                {
                    endPhase(MMI_TRUE);
                    return;
                }
                fs_ret = srv_fmgr_filelist_refresh(m_handle, m_name, 0, 0, _Proc, this);
                if(!SRV_FTST_CHECK(fs_ret >= 0))
                {
                    endPhase(MMI_TRUE);
                    return;
                }
                m_index = 0xFFFFF;
                break;
            }
            
            fs_ret = srv_fmgr_filelist_get_fileinfo(m_handle, m_index, &fileinfo);
            if(fs_ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
            {
                fs_ret = srv_fmgr_filelist_load_file(m_handle, m_index, _Proc, this);
                if(!SRV_FTST_CHECK(fs_ret >= 0))
                {
                    endPhase(MMI_TRUE);
                }
                return;
            }
            
            if(!SRV_FTST_CHECK(fs_ret >= 0))
            {
                endPhase(MMI_TRUE);
                return;
            }

            fs_ret = srv_fmgr_filelist_get_filepath(m_handle, m_index, m_path, sizeof(m_path));
            if(!SRV_FTST_CHECK(fs_ret >= 0))
            {
                endPhase(MMI_TRUE);
                return;
            }

            onFile(m_path, &fileinfo);

            if(fileinfo.attribute & FS_ATTR_DIR)
            {
                srv_fmgr_filelist_destroy(m_handle);
                m_handle = 0;
                fs_ret = createFilelist();
                if(!SRV_FTST_CHECK(fs_ret >= 0))
                {
                    endPhase(MMI_TRUE);
                    return;
                }
                fs_ret = srv_fmgr_filelist_refresh(m_handle, NULL, 0, 0, _Proc, this);
                if(!SRV_FTST_CHECK(fs_ret >= 0))
                {
                    endPhase(MMI_TRUE);
                    return;
                }
                m_index = -1;
                break;
            }
        }
    }

    
};

SrvFtstTestResultEnum srv_ftst_rt_ffl_travel(U32 param)
{
    SRV_FTST_START(SrvFtstFFLTravel);
    return SRV_FTST_TR_OK;
}

class SrvFtstFFLTravel2 : public SrvFtstFFLTravel
{
// Variable
public:
    S32         m_job_id;
    WCHAR       m_output_dir[20];

// Constructor / Destructor
public:
    SrvFtstFFLTravel2() :m_job_id(0)
    {
        kal_wsprintf(m_output_dir, "%c:\\%s\\", rt_get_test_drive(), "out");
    }

    virtual ~SrvFtstFFLTravel2()
    {
        if(m_job_id)
            srv_fmgr_async_abort(m_job_id, MMI_TRUE);
    }

// Override
protected:
    virtual void end() 
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, _Proc, this);
        SrvFtstFFLTravel::end();
    }

    virtual S32 phase(S32 idx)
    { 
        S32 fs_ret;
        if(idx == 0)
        {
            if(!check(srv_fmgr_drv_is_accessible(rt_get_test_drive()) == MMI_TRUE, (WCHAR*)L"No memory card", NULL, 0))
                return SRV_FTST_RT_END_TESTCASE;

            if(srv_fmgr_fs_path_exist(m_output_dir) < 0)
                return 0;

            fs_ret = srv_fmgr_async_delete(m_output_dir, 0, _Proc, this);
            SRV_FTST_CHECK(fs_ret > 0);
            if(fs_ret <= 0)
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 1)
        {
            mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, _Proc, this);

            if(!SRV_FTST_CHECK(srv_fmgr_fs_create_folder(m_output_dir) == 0))
                return SRV_FTST_RT_END_TESTCASE;
            SRV_FTST_CHECK(srv_fmgr_fs_path_exist(m_output_dir) == 0);
            
            reinit();
            
            fs_ret = createFilelist();
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;
            fs_ret = srv_fmgr_filelist_refresh(m_handle, NULL, 0, 0, SrvFtstFFLTravel::_Proc, this);
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            return -1;
        }
        
        return SRV_FTST_RT_END_TESTCASE;
    }

    virtual const WCHAR* getOutputFilename(void)
    {
        return (WCHAR*)L"SrvFtstFFLTravel2.result";
    }
    
    virtual void onFile(const WCHAR* path, const srv_fmgr_fileinfo_struct* info)
    {
        S32 fs_ret;

        if(info->attribute & FS_ATTR_DIR)
            return;
        if(info->size > 1024 * 100)
            return;
        if(info->type == FMGR_TYPE_JPG)
            return;
            
        fs_ret = srv_fmgr_fs_delete(path);
        SRV_FTST_CHECK(fs_ret == FS_ACCESS_DENIED);
        fs_ret = srv_fmgr_fs_copy(path, m_output_dir);
        SRV_FTST_CHECK(fs_ret == 0);
    }

    virtual mmi_ret onProc(mmi_event_struct *param)
    {
        srv_fmgr_notification_adv_action_event_struct   *adv_action;
        srv_fmgr_async_done_event_struct                *async_evt;

        switch(param->evt_id)
        {
        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
            adv_action = (srv_fmgr_notification_adv_action_event_struct*)param;

            if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
            {
                if(adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE)
                    return MMI_RET_ERR;
            }
            else if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE)
            {
                writeString((WCHAR*)L"[Before]", MMI_FALSE);
                writeString(adv_action->src_filepath);
            }
            else if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                writeString((WCHAR*)L"[After] ", MMI_FALSE);
                writeString(adv_action->src_filepath);
            }
            break;
            
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
            async_evt = (srv_fmgr_async_done_event_struct*)param;
            SRV_FTST_CHECK(async_evt->job_id == m_job_id);
            SRV_FTST_CHECK(async_evt->result == 0);

            m_job_id = 0;
            endPhase();
            break;

        default:
            return SrvFtstFFLTravel::onProc(param);
        }

        return MMI_RET_OK;
    }
};

SrvFtstTestResultEnum srv_ftst_rt_ffl_travel2(U32 param)
{
    SRV_FTST_START(SrvFtstFFLTravel2);
    return SRV_FTST_TR_OK;
}

class SrvFtstFFLTravel3 : public SrvFtstFFLTravel
{
// Variable
public:
    U8 m_sort_buffer[2048];

// Constructor / Destructor
public:
    SrvFtstFFLTravel3()
    {
    }

    virtual ~SrvFtstFFLTravel3()
    {
    }

// Override
protected:
    virtual S32 phase(S32 idx)
    { 
        S32 fs_ret;
        if(idx == 0)
        {
            if(!check(srv_fmgr_drv_is_accessible(rt_get_test_drive()) == MMI_TRUE, (WCHAR*)L"No memory card", NULL, 0))
                return SRV_FTST_RT_END_TESTCASE;

            reinit();
            m_sort_option = FS_SORT_USER;
            
            fs_ret = createFilelist();
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;
            fs_ret = srv_fmgr_filelist_refresh(m_handle, NULL, 0, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            return -1;
        }
        
        return SRV_FTST_RT_END_TESTCASE;
    }

    virtual const WCHAR* getOutputFilename(void)
    {
        return (WCHAR*)L"SrvFtstFFLTravel3.result";
    }

    virtual S32 createFilelist(void)
    {
        return srv_fmgr_folder_filelist_create(m_path, &m_filter, m_sort_option, m_sort_buffer, 2048, &m_handle);
    }
    
    virtual void onFile(const WCHAR* path, const srv_fmgr_fileinfo_struct* info)
    {
        writeString(path);
    }
};

SrvFtstTestResultEnum srv_ftst_rt_ffl_travel3(U32 param)
{
    SRV_FTST_START(SrvFtstFFLTravel3);
    return SRV_FTST_TR_OK;
}

#define TEST_ASYNCFS

class SrvFtstAsyncFS : public SrvFtstTestItem
{
// Variable
public:
    S32         m_job_id;
    MMI_BOOL    m_aborting;
    
    WCHAR       m_dest_path[SRV_FMGR_PATH_MAX_LEN+1];
    srv_fmgr_fileinfo_struct m_src_info, m_dest_info;
    FMGR_FILTER m_del_filter;

// Constructor / Destructor
public:
    SrvFtstAsyncFS() :m_job_id(0), m_aborting(MMI_FALSE) 
    {
        kal_wsprintf(m_dest_path, "%c:\\%s\\", rt_get_test_drive(), "out2");
    }

    virtual ~SrvFtstAsyncFS()
    {
        if(m_job_id)
            srv_fmgr_async_abort(m_job_id, MMI_TRUE);
    }

// Override
protected:
    virtual int start() 
    {
        srv_fmgri_set_trace_level(1);
        return 0;
    }
    virtual void end() 
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, _Proc, this);
        srv_fmgri_set_trace_level(0);
    }

    virtual S32 phase(S32 idx)
    { 
        S32 fs_ret;
        WCHAR src_path[SRV_FMGR_PATH_MAX_LEN+1];

        if(idx == 0)    /* create folder */
        {
            if(!check(srv_fmgr_drv_is_accessible(rt_get_test_drive()) == MMI_TRUE, (WCHAR*)L"No memory card", NULL, 0))
                return SRV_FTST_RT_END_TESTCASE;

            if(srv_fmgr_fs_path_exist(m_dest_path) < 0)
                return 0;

            fs_ret = srv_fmgr_async_delete(m_dest_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 1)
        {
            /* First step of removing folder may not always happen, 
             * move reg() here, to make sure the output is the same every time */
            mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, _Proc, this);
            
            SRV_FTST_CHECK(srv_fmgr_fs_create_folder(m_dest_path) == 0);
            SRV_FTST_CHECK(srv_fmgr_fs_path_exist(m_dest_path) == 0);
            return 0;
        }
        else if(idx == 2)   /* copy file 1 */
        {
            mmi_wcscpy(src_path, FMGR_TESTBED_PATH);
            src_path[0] = rt_get_test_drive();
            srv_fmgr_path_append(src_path, sizeof(src_path), (WCHAR*)L"Photos\\WALL01.jpg");

            fs_ret = srv_fmgr_async_copy(src_path, m_dest_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 3)   /* copy file & cancel*/
        {
            mmi_wcscpy(src_path, FMGR_TESTBED_PATH);
            src_path[0] = rt_get_test_drive();
            srv_fmgr_path_append(src_path, sizeof(src_path), (WCHAR*)L"Videos\\PWRONOFF.mpg");

            fs_ret = srv_fmgr_async_copy(src_path, m_dest_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            
            SRV_FTST_CHECK(srv_fmgr_async_abort(fs_ret, MMI_FALSE) == MMI_TRUE);
            m_aborting = MMI_TRUE;
            return -1;
        }
        else if(idx == 4)   /* copy file 2 */
        {
            mmi_wcscpy(src_path, FMGR_TESTBED_PATH);
            src_path[0] = rt_get_test_drive();
            srv_fmgr_path_append(src_path, sizeof(src_path), (WCHAR*)L"Audio\\02.au");

            fs_ret = srv_fmgr_async_copy(src_path, m_dest_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 5)   /* copy file 3 */
        {
            mmi_wcscpy(src_path, FMGR_TESTBED_PATH);
            src_path[0] = rt_get_test_drive();
            srv_fmgr_path_append(src_path, sizeof(src_path), (WCHAR*)L"Audio\\canon_64.mid");

            srv_fmgr_path_append(m_dest_path, sizeof(m_dest_path), (WCHAR*)L"canon_32.mid");

            fs_ret = srv_fmgr_async_copy(src_path, m_dest_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            srv_fmgr_path_remove_filename(m_dest_path);

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 6)   /* delete file */
        {
            mmi_wcscpy(src_path, m_dest_path);
            srv_fmgr_path_append(src_path, sizeof(src_path), (WCHAR*)L"02.au");

            fs_ret = srv_fmgr_async_delete(src_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 7)   /* delete all jpeg */
        {
            FMGR_FILTER filter;
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
        
            fs_ret = srv_fmgr_async_delete_all(m_dest_path, &filter, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 8)   /* delete all */
        {
            /* at this time, canon_32.mid should still exist */
            srv_fmgr_path_append(m_dest_path, sizeof(m_dest_path), (WCHAR*)L"canon_32.mid");
            SRV_FTST_CHECK(srv_fmgr_fs_path_exist(m_dest_path) == 0);
            srv_fmgr_path_remove_filename(m_dest_path);
        
            FMGR_FILTER filter;
            FMGR_FILTER_SET_ALL(&filter);
        
            fs_ret = srv_fmgr_async_delete_all(m_dest_path, &filter, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 9)   /* delete folder */
        {
            /* at this time, canon_32.mid should NOT exist */
            srv_fmgr_path_append(m_dest_path, sizeof(m_dest_path), (WCHAR*)L"canon_32.mid");
            SRV_FTST_CHECK(srv_fmgr_fs_path_exist(m_dest_path) != 0);
            srv_fmgr_path_remove_filename(m_dest_path);
        
            fs_ret = srv_fmgr_async_delete(m_dest_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }
        else if(idx == 10)  /* create & delete 128 level folder */
        {
            SRV_FTST_CHECK(srv_fmgr_fs_path_exist(m_dest_path) < 0);

#ifdef __MTK_TARGET__
            S32 i;
            kal_wsprintf(m_dest_path, "%c:\\", rt_get_test_drive());
            for (i=0;i<128;i++)
            {
                m_dest_path[3+i*2] = '0'+(i%10);
                m_dest_path[4+i*2] = '\\';
            }
            m_dest_path[3+i*2] = 0;

            mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, _Proc, this);
            if(!SRV_FTST_CHECK(srv_fmgr_fs_create_folder(m_dest_path) == 0))
                return SRV_FTST_RT_END_TESTCASE;
            mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, _Proc, this);

            fs_ret = srv_fmgr_async_delete(m_dest_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
#else            
            return 0;
#endif
        }

        return SRV_FTST_RT_END_TESTCASE;
    }

    virtual const WCHAR* getWritePath(WCHAR* path, S32 size)
    {
        kal_wsprintf(path, "%c:\\%w", rt_get_test_drive(), (WCHAR*)L"SrvFtstAsyncFS.result");
        return path;
    }
    virtual const WCHAR* getCheckPath(WCHAR* path, S32 size)
    {
        rt_init_testbed_path(path, size);
        srv_fmgr_path_append(path, size, (WCHAR*)L"SrvFtstAsyncFS.result");
        return path;
    }

    virtual mmi_ret onProc(mmi_event_struct *param)
    {
        srv_fmgr_notification_adv_action_event_struct   *adv_action;
        srv_fmgr_async_done_event_struct                *async_evt;

        switch(param->evt_id)
        {
        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
            adv_action = (srv_fmgr_notification_adv_action_event_struct*)param;

            if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE)
            {
                writeString((WCHAR*)L"[Before][Src] ", MMI_FALSE);
                writeInfo(adv_action->action, &adv_action->src_fileinfo, MMI_FALSE);
                writeString(adv_action->src_filepath);
                m_src_info = adv_action->src_fileinfo;
                if(adv_action->dest_filepath)
                {
                    writeString((WCHAR*)L"[Before][Dest]", MMI_FALSE);
                    writeInfo(adv_action->action, &adv_action->dest_fileinfo, MMI_FALSE);
                    writeString(adv_action->dest_filepath);
                    m_dest_info = adv_action->dest_fileinfo;
                }
                if(adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL)
                    m_del_filter = *adv_action->filter;
            }
            else if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                writeString((WCHAR*)L"[After] [Src] ", MMI_FALSE);
                writeInfo(adv_action->action, &adv_action->src_fileinfo, MMI_FALSE);
                writeString(adv_action->src_filepath);
                SRV_FTST_CHECK(kal_mem_cmp(&m_src_info, &adv_action->src_fileinfo, sizeof(m_src_info)) == 0);
                if(adv_action->dest_filepath)
                {
                    writeString((WCHAR*)L"[After] [Dest]", MMI_FALSE);
                    writeInfo(adv_action->action, &adv_action->dest_fileinfo, MMI_FALSE);
                    writeString(adv_action->dest_filepath);
                    SRV_FTST_CHECK(kal_mem_cmp(&m_dest_info, &adv_action->dest_fileinfo, sizeof(m_dest_info)) == 0);
                }
                if(adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL)
                    SRV_FTST_CHECK(kal_mem_cmp(&m_del_filter, adv_action->filter, sizeof(m_del_filter)) == 0);
            }
            break;
            
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
            async_evt = (srv_fmgr_async_done_event_struct*)param;
            SRV_FTST_CHECK(async_evt->job_id == m_job_id);
            if(m_aborting)
            {
                SRV_FTST_CHECK(async_evt->result == FS_ABORTED_ERROR);
                m_aborting = MMI_FALSE;
            }
            else
                SRV_FTST_CHECK(async_evt->result == 0);

            m_job_id = 0;
            endPhase();
            break;

        }
        
        return MMI_RET_OK;
    }

    void writeInfo(S32 action, const srv_fmgr_fileinfo_struct* info, MMI_BOOL newline = MMI_TRUE)
    {
        /* Note: type is different between projects, so not output it */
        WCHAR info_str[128];
        kal_wsprintf(info_str, "(%d, %d,%d)", action, info->attribute, info->size);
        writeString(info_str, newline);
    }

};

SrvFtstTestResultEnum srv_ftst_rt_asyncfs(U32 param)
{
    SRV_FTST_START(SrvFtstAsyncFS);
    return SRV_FTST_TR_OK;
}

#define TEST_CUSTICON

class SrvFtstCustIcon : public SrvFtstTestItem
{
// Variable
public:
    WCHAR m_objpath[SRV_FMGR_PATH_MAX_LEN+1];

// Constructor / Destructor
public:
    SrvFtstCustIcon() {}

// Override
protected:
    virtual int start() 
    {
        srv_fmgri_set_trace_level(1);
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, srv_fmgr_cidb_notify_hdlr, 0);
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, srv_fmgr_cidb_notify_hdlr, 0);
        return 0;
    }
    virtual void end() 
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, srv_fmgr_cidb_notify_hdlr, 0);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, srv_fmgr_cidb_notify_hdlr, 0);
        srv_fmgri_set_trace_level(0);
    }

    virtual S32 phase(S32 idx)
    { 
        WCHAR path[SRV_FMGR_PATH_MAX_LEN+1];
        FS_HANDLE fh;
        S32 fs_ret;
        
        if(idx == 0)
        {
            mmi_wcscpy(m_objpath, (WCHAR*)L"D:\\a.txt");
            m_objpath[0] = SRV_FMGR_PUBLIC_DRV;
            fh = FS_Open(m_objpath, FS_READ_WRITE | FS_CREATE_ALWAYS);
            FS_Write(fh, m_objpath, sizeof(m_objpath), NULL);
            FS_Close(fh);

            mmi_wcscpy(path, (WCHAR*)L"D:\\b.jpg");
            path[0] = SRV_FMGR_PUBLIC_DRV;
            fh = FS_Open(path, FS_READ_WRITE | FS_CREATE_ALWAYS);
            FS_Write(fh, path, sizeof(path), NULL);
            FS_Close(fh);

            fs_ret = srv_fmgr_custicon_do(SRV_FMGR_CUSTICON_OP_REGISTER, m_objpath, path);
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            fs_ret = srv_fmgr_custicon_query(m_objpath, path, sizeof(path));
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            if(!SRV_FTST_CHECK(srv_fmgr_fs_path_exist(path) == 0))
                return SRV_FTST_RT_END_TESTCASE;

            return 0;
        }
        else if(idx == 1)
        {
            /* try rename */
            mmi_wcscpy(path, (WCHAR*)L"D:\\b.txt");
            path[0] = SRV_FMGR_PUBLIC_DRV;

            fs_ret = srv_fmgr_fs_rename(m_objpath, path);
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            mmi_wcscpy(m_objpath, path);

            fs_ret = srv_fmgr_custicon_query(m_objpath, path, sizeof(path));
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            if(!SRV_FTST_CHECK(srv_fmgr_fs_path_exist(path) == 0))
                return SRV_FTST_RT_END_TESTCASE;

            return 0;
        }
        else if(idx == 2)
        {
            /* try delete */
            fs_ret = srv_fmgr_fs_delete(m_objpath);
            if(!SRV_FTST_CHECK(fs_ret == 0))
                return SRV_FTST_RT_END_TESTCASE;

            fs_ret = srv_fmgr_custicon_query(m_objpath, path, sizeof(path));
            if(!SRV_FTST_CHECK(fs_ret != 0))
                return SRV_FTST_RT_END_TESTCASE;

            return 0;
        }

        return SRV_FTST_RT_END_TESTCASE;
    }

};

SrvFtstTestResultEnum srv_ftst_rt_custicon(U32 param)
{
    SRV_FTST_START(SrvFtstCustIcon);
    return SRV_FTST_TR_OK;
}

#define TEST_MISC

class SrvFtstMisc : public SrvFtstTestItem
{
// Variable
public:
    S32         m_job_id;
    MMI_BOOL    m_aborting;
    
    WCHAR       m_dest_path[SRV_FMGR_PATH_MAX_LEN+1];

// Constructor / Destructor
public:
    SrvFtstMisc() :m_job_id(0), m_aborting(MMI_FALSE) 
    {
    }

    virtual ~SrvFtstMisc()
    {
        if(m_job_id)
            srv_fmgr_async_abort(m_job_id, MMI_TRUE);
    }

// Override
protected:
    virtual int start() 
    {
        srv_fmgri_set_trace_level(1);
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, _Proc, this);

        kal_wsprintf(m_dest_path, "%c:\\1\\2\\3\\4\\5\\6\\7\\", rt_get_test_drive());
        return 0;
    }
    virtual void end() 
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, _Proc, this);
        srv_fmgri_set_trace_level(0);
    }

    virtual S32 phase(S32 idx)
    {
        S32 fs_ret;
        WCHAR src_path[SRV_FMGR_PATH_MAX_LEN+1];

        if(idx == 0)
        {
            kal_wsprintf(m_dest_path, "%c:\\", rt_get_test_drive());

            fs_ret = srv_fmgr_async_get_folder_size(m_dest_path, 0, _Proc, this);
            if(!SRV_FTST_CHECK(fs_ret > 0))
                return SRV_FTST_RT_END_TESTCASE;

            m_job_id = fs_ret;
            return -1;
        }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        return SRV_FTST_RT_END_TESTCASE;
    }

    virtual mmi_ret onProc(mmi_event_struct *param)
    {
        srv_fmgr_notification_adv_action_event_struct   *adv_action;
        srv_fmgr_async_done_event_struct                *async_evt;
        srv_fmgr_async_folder_size_result_event_struct  *result_evt;
        srv_fmgr_async_folder_size_progress_event_struct *prog_evt;

        switch(param->evt_id)
        {
        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
            break;
            
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
            async_evt = (srv_fmgr_async_done_event_struct*)param;
            SRV_FTST_CHECK(async_evt->job_id == m_job_id);
            if(m_aborting)
            {
                SRV_FTST_CHECK(async_evt->result == FS_ABORTED_ERROR);
                m_aborting = MMI_FALSE;
            }
            else
                SRV_FTST_CHECK(async_evt->result == 0);

            m_job_id = 0;
            endPhase();
            break;

        case EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_PROGRESSING:
            break;

        case EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_RESULT:
            result_evt = (srv_fmgr_async_folder_size_result_event_struct*)param;
            SRV_FTST_CHECK(result_evt->job_id == m_job_id);
            if(m_aborting)
            {
                SRV_FTST_CHECK(result_evt->result == FS_ABORTED_ERROR);
                m_aborting = MMI_FALSE;
            }
            else
                SRV_FTST_CHECK(result_evt->result == 0);

            m_job_id = 0;
            endPhase();
            break;
        }
        
        return MMI_RET_OK;
    }

};

SrvFtstTestResultEnum srv_ftst_rt_misc(U32 param)
{
    SRV_FTST_START(SrvFtstMisc);
    return SRV_FTST_TR_OK;
}


#endif
