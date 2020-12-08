/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   hdi_file.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating Obigo file APIs.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "msf_def.h"
#include "msf_int.h"
#include "msf_env.h"
#include "msf_cmmn.h"
#include "msf_mem.h"
#include "msf_chrs.h"
#include "msf_log.h"
#include "msf_errc.h"

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "msf_cfg.h"
#include "msf_file.h"
#include "msm_int.h"
#include "msf_env.h"
#include "msf_lib.h"
#include "wap_cmn.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
#include "msf_dcvt.h"
#include "msf_core.h"
#include "msf_file.h"
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */

#include "mmi_platform.h"

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
#include "fat_fs.h"         /* file system */
#include "L4Dr.h"
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */

#include "FileManagerGProt.h"
#include "FileMgrSrvGProt.h"

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
#include "fmt_struct.h"
#include "stack_ltlcom.h"
#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"    /* Stack timer */
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */

#include "app_str.h"        /* For app_ucs2_strlen */

#include "int_exec.h"
#include "int_cmmn.h"
#include "kal_internal_api.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#define MAX_NUM_FILES 25
#define HDI_FILE_DELAY_TIME (KAL_TICKS_100_MSEC * 2)
#define HDI_INVALID_FILE (-1)
#define FILE_NAME_FREE(fn)    MSF_MEM_FREE(MSF_MODID_MSM, (fn))

#define WAP_FS_ROOT_FOLDER             "/@wap/"
#define MAX_HDI_FILE_NAME_SIZE     (MSF_CFG_VIRTUAL_FILE_NAME_LENGTH)

typedef struct
{
    kal_uint8 flag;
    kal_uint8 mod_id;   /* module id of opened file */
    kal_uint8 is_read_delay;
    kal_uint8 is_write_delay;
    kal_uint8 is_remove_delay;
    FS_HANDLE handle;   /* file handle */
	int mode;
    eventid event_id;   /* for timer */
    char *file_name;
	msf_mms_storage_enum mms_drive; 
    kal_uint32 fs_flag;
} file_info_struct;

static file_info_struct files[MAX_NUM_FILES];

static file_info_struct empty_file_info = {0, 0xff, 0, 0, 0, 0, 0, NULL, NULL, MSF_MMS_STORAGE_NONE, 0};

typedef struct
{
    char *int_name;
    kal_uint8 ext_drive;
    char *ext_name;
    int hidden;
} fs_map_table_struct;

typedef union
{
	FS_DOSDateTime DateTime;
	MSF_UINT32 LastModified;
}LastModifiedDate_u;

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#define NUM_FS_MAP_TABLE_ENTRY 8

static fs_map_table_struct fs_map_table[NUM_FS_MAP_TABLE_ENTRY] = 
{
    {"/external", MMS_STORAGE_EXTERNAL, "", 0},
    {"/mmt", MMS_STORAGE_DEFAULT, "\\@mms", 1},
    {"/mms_sys", MMS_STORAGE_DEFAULT, "\\@mms\\mms_sys", 1},
    {"/mms_pdu", MMS_STORAGE_DEFAULT, "\\@mms\\mms_pdu", 1},
    {"/mms_info", MMS_STORAGE_DEFAULT, "\\@mms\\mms_info", 1},
    {"/mma", MMS_STORAGE_SYSTEM, "\\@mma", 0},
    {"/\\.\\FMapF", MMS_STORAGE_VIRTUAL, "\\\\.\\FMapF", 0},
    {"/", MMS_STORAGE_DEFAULT, "\\@mms\\", 1}
};
#else
#define NUM_FS_MAP_TABLE_ENTRY 25

static fs_map_table_struct fs_map_table[NUM_FS_MAP_TABLE_ENTRY] = 
{
    {"/external", MMS_STORAGE_EXTERNAL, "", 0},
    {"/msm", MMS_STORAGE_SYSTEM, "\\@wap\\msm", 0},
    {"/mmt", MMS_STORAGE_DEFAULT, "\\@mms", 1},
    {"/mms_sys", MMS_STORAGE_DEFAULT, "\\@mms\\mms_sys", 1},
    {"/mms_pdu", MMS_STORAGE_DEFAULT, "\\@mms\\mms_pdu", 1},
    {"/mms_info", MMS_STORAGE_DEFAULT, "\\@mms\\mms_info", 1},
    {"/mma", MMS_STORAGE_SYSTEM, "\\@mma", 0},
    {"/mms", WAP_STORAGE_MMS, "\\@mms" ,1},
    {"\\mms", WAP_STORAGE_MMS, "\\@mms", 1},
    {"/public", WAP_STORAGE_PUBLIC, "", 0},
    {"\\public", WAP_STORAGE_PUBLIC, "", 0},
    {"/stk", MMS_STORAGE_SYSTEM, "\\@wap\\stk", 0},
    {"/sec", MMS_STORAGE_SYSTEM, "\\@wap\\sec", 0},
    {"/wps", MMS_STORAGE_SYSTEM, "\\@wap\\wps", 0},
    {"/bam", MMS_STORAGE_SYSTEM, "\\@wap\\bam", 0},
#if defined(SLIM_WAP_MMS) && !defined(__OP01__) && !defined(__OP02__)
    {WIDGET_RAWFILE_DIRECTORY, WAP_STORAGE_REMOVABLE, "\\@wcache\\", 0},
    {WIDGET_RAWFILE_MMS_DIRECTORY, WAP_STORAGE_REMOVABLE, "\\@wcache\\", 0},
#else
    {WIDGET_RAWFILE_DIRECTORY, WAP_STORAGE_SYSTEM, "\\@wcache\\", 0},
    {WIDGET_RAWFILE_MMS_DIRECTORY, WAP_STORAGE_SYSTEM, "\\@wcache\\", 0},
#endif /* */
    {"/brs", WAP_STORAGE_PUBLIC, "\\brs", 1},
    {"\\brs", WAP_STORAGE_PUBLIC, "\\brs", 1},
    {WAP_DOWNLOAD_FOLDER, WAP_STORAGE_PUBLIC, "\\download\\", 0},
    {"/push", WAP_STORAGE_SYSTEM, "\\@push", 1},
    {"/pmg", MMS_STORAGE_SYSTEM, "\\@wap\\pmg", 0},
    {"/temp", WAP_STORAGE_SYSTEM, "\\@wap\\temp", 0},
    {"/\\.\\FMapF", MMS_STORAGE_VIRTUAL, "\\\\.\\FMapF", 0},
    {"/", MMS_STORAGE_DEFAULT, "\\@mms\\", 1}
};
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
typedef struct msf_file_move_node_st{
	msf_file_move_t *node;
	struct msf_file_move_node_st *next;
}msf_file_move_node_t;

typedef struct{
	msf_file_move_enum state;
	msf_file_move_node_t *head;
	msf_file_move_node_t *tail;    
}msf_file_move_list_t;

static msf_file_move_list_t *msf_file_move_list = NULL;
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */

static kal_mutexid hdi_file_mutex;
/*
 * following files either important or only close when terminate, 
 * thus we need to flush file for every write operation 
 */
static const char *const hdi_critical_files[] = 
{
    NULL
};


static event_scheduler *evt_scheduler;

static int fileRemove(const char *fileName, int forceRemove, msf_mms_storage_enum storage_id);

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
static void 
gmms_file_move_add_node(msf_file_move_t *resp);

static void 
gmms_HDI_file_move(void);
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  getDiskLabel
 * DESCRIPTION
 *  Returns disk label with the storage enum given.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  disk label character
 *****************************************************************************/
static int getDiskLabel(int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int system_disk = -1;
    static int public_disk = -1;
    static int mms_disk = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMS_STORAGE_SYSTEM:
            if (system_disk < 0)
            {
                system_disk = SRV_FMGR_SYSTEM_DRV;
            }
            ASSERT(system_disk > 0);
            return system_disk;
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
        case WAP_STORAGE_MMS:
#endif
        case MMS_STORAGE_MMS:
            if (mms_disk < 0)
            {
            #ifdef MMS_IN_LARGE_STORAGE
                /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
                mms_disk = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
            #else /* MMS_IN_LARGE_STORAGE */ 
                mms_disk = SRV_FMGR_SYSTEM_DRV;
            #endif /* MMS_IN_LARGE_STORAGE */ 
            }
            ASSERT(mms_disk > 0);
            return mms_disk;
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
        case MMS_STORAGE_PUBLIC:
            /* Order: 1. Visible NAND 2. Invisible NOR (system drive) */
            if (public_disk < 0)
            {
                /*public_disk = SRV_FMGR_PUBLIC_DRV;*/
                public_disk = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
            }
#else
         case MMS_STORAGE_PUBLIC:
        case WAP_STORAGE_PUBLIC:
            /* Order: 1. Visible NAND 2. Invisible NOR (system drive) */
            if (public_disk < 0)
            {
            #ifndef APP_STORAGE_IN_SYS_DRV
                /*public_disk = SRV_FMGR_PUBLIC_DRV;*/
                public_disk = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
            #else /* APP_STORAGE_IN_SYS_DRV */ 
                public_disk = SRV_FMGR_SYSTEM_DRV;
            #endif /* APP_STORAGE_IN_SYS_DRV */ 
            }
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
            ASSERT(public_disk > 0);
            return public_disk;

        default:
            ASSERT(0);
            return 0;   /* Unreached */
    }
}   /* end of getDiskLabel */


/*****************************************************************************
 * FUNCTION
 *  mms_get_disk_label
 * DESCRIPTION
 *  Returns disk label with the storage enum given.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  disk label character
 *****************************************************************************/
int mms_get_disk_label(int type)
{
    return getDiskLabel(type);
}


/*****************************************************************************
 * FUNCTION
 *  translateFileError
 * DESCRIPTION
 *  To translate FS native error code to HDI error code.
 * PARAMETERS
 *  err     [IN]        
 * RETURNS
 *  error code in Obigo framework
 *****************************************************************************/
static int translateFileError(int err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (err >= 0)
    {
        return err;
    }

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_4A4B4420DEAA65C10F9B23D101E7B538, "translateFileError: error=%d\n",err));

    switch (err)
    {
        case FS_PATH_NOT_FOUND:
        case FS_FILE_NOT_FOUND:
        case FS_INVALID_FILENAME:
            return HDI_FILE_ERROR_PATH; /* Note that applications might check this error code */

        case FS_READ_ONLY_ERROR:
            return HDI_FILE_ERROR_ACCESS;

        case FS_ACCESS_DENIED:
        case FS_DEVICE_EXPORTED_ERROR:
            return HDI_FILE_ERROR_ACCESS;

        case FS_MEDIA_CHANGED:
            return HDI_FILE_ERROR_ACCESS;

        case FS_TOO_MANY_FILES:
            ASSERT(0); /* this is not allowed */
            return HDI_FILE_ERROR_ACCESS;

        case FS_DISK_FULL:
        case FS_APP_QUOTA_FULL:
            return HDI_FILE_ERROR_FULL; /* Note that applications might check this error code */

        case FS_ROOT_DIR_FULL:
            return HDI_FILE_ERROR_ROOT_DIR_FULL;
        case FS_FILE_EXISTS:
            return HDI_FILE_ERROR_EXIST;    /* Note that applications might check this error code */

            /* File System is busy now, return immediately with cause "DELAY" */
        case FS_FLASH_ERASE_BUSY:
        case FS_LOCK_MUTEX_FAIL:
            return HDI_FILE_ERROR_DELAYED;

        case FS_MSDC_MOUNT_ERROR:
        case FS_MSDC_READ_SECTOR_ERROR:
        case FS_MSDC_WRITE_SECTOR_ERROR:
        case FS_MSDC_DISCARD_SECTOR_ERROR:
        case FS_MSDC_PRESNET_NOT_READY:
        case FS_MSDC_NOT_PRESENT:
            return HDI_FILE_ERROR_CARD_ACCESS;
        default:
            return HDI_FILE_ERROR_INVALID;

    }

}   /* end of HDI_FileErrorNoTranslate */


/*****************************************************************************
 * FUNCTION
 *  translateFileMode
 * DESCRIPTION
 *  To translate Obigo file mode to native FS mode.
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  file mode of native FS driver
 *****************************************************************************/
static kal_uint32 translateFileMode(int mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 m = 0;   /* reset */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mode & HDI_FILE_SET_RDONLY))   /* read only */
    {
        m |= FS_READ_ONLY;
    }

    /* write only, but FS does not have this mode
       set READ/WRITE */
    if ((mode & HDI_FILE_SET_WRONLY) || (mode & HDI_FILE_SET_RDWR))
    {
        m |= FS_READ_WRITE;
    }

    if ((mode & HDI_FILE_SET_BUFFERED)) /* access data in RAM */
    {
        m |= FS_LAZY_DATA;
    }

    /* HDI_FILE_SET_APPEND */

    if ((mode & HDI_FILE_SET_CREATE))
    {
        m |= FS_CREATE;
    }
    if ((mode & HDI_FILE_SET_CREATE_ALWAYS))
    {
        m |= FS_CREATE_ALWAYS;
    }

    if (!(mode & HDI_FILE_SET_CUSTOM_BLOCKING))
    {
        m |= FS_NONBLOCK_MODE;
    }
    
    /* HDI_FILE_SET_EXCL */

    return m;
}


/*****************************************************************************
 * FUNCTION
 *  translateFileName
 * DESCRIPTION
 *  This function translates file name from Obigo format to File System
 *  format. Specifically, the translations are listed below:
 *  a. utf8 --> ucs2
 *  b. / --> \
 *  c. remove "/external/"
 *  For internal use.
 * PARAMETERS
 *  src        [IN]        filename to be converted to native one.
 * RETURNS
 *  filename in native filesystem format
 *****************************************************************************/
static kal_uint8 *translateFileName(const char *src, msf_mms_storage_enum storage_id)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    char drive_name[32], *text = NULL, *destBuffer = NULL, *filename = NULL;
    long destLen, len;
    char mms_disk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(src);
	if((int)storage_id < MSF_MMS_STORAGE_PHONE || (int)storage_id > MSF_MMS_STORAGE_NONE)
	{
		ASSERT(0);
	}

    if(src[0] == '\\')
    {
        filename = msf_cmmn_strdup(MSF_MODID_MSM, src);
        filename[0] = '/';
    }
    else if(src[0] == '/')
    {
        filename = msf_cmmn_strdup(MSF_MODID_MSM, src);
    }
    else
    {
        /* For external filename direct translation */
        filename = msf_cmmn_strcat(MSF_MODID_MSM, "/external/", src);
    }

    if (!filename)
    {
        return NULL;
    }
    
	if(storage_id > MSF_MMS_STORAGE_PHONE && storage_id < MSF_MMS_STORAGE_NONE)
	{				
		mms_disk = (char)FS_GetDrive(FS_DRIVE_V_REMOVABLE, storage_id, FS_NO_ALT_DRIVE);			
		sprintf(drive_name, "%c:", mms_disk);
	}
    
    for (i = 0; i < NUM_FS_MAP_TABLE_ENTRY; i++)
    {
        if (msf_cmmn_strncmp_nc(
                filename,
                fs_map_table[i].int_name,
                msf_cmmn_utf8_strlen(fs_map_table[i].int_name)) == 0)
        {
            if(fs_map_table[i].ext_drive == MMS_STORAGE_VIRTUAL)
            {
                text = msf_cmmn_strcat(
                    MSF_MODID_MSM,
                    fs_map_table[i].ext_name,
                    (char*)(filename + msf_cmmn_utf8_strlen(fs_map_table[i].int_name)));
            }
            else if(fs_map_table[i].ext_drive == MMS_STORAGE_EXTERNAL)
            {
                text = msf_cmmn_strdup(MSF_MODID_MSM, (char*)(filename + 10)); /* Strip off "/external/" */
            }
			else if(fs_map_table[i].ext_drive == MMS_STORAGE_SYSTEM)
			{
				sprintf(drive_name, "%c:", getDiskLabel(MMS_STORAGE_SYSTEM));
				text = msf_cmmn_str3cat(
                    MSF_MODID_MSM,
                    drive_name,
                    fs_map_table[i].ext_name,
                    (char*)(filename + msf_cmmn_utf8_strlen(fs_map_table[i].int_name)));
			}
/* SLIM_R starts */
#ifdef SLIM_WAP_MMS
            else if(fs_map_table[i].ext_drive == WAP_STORAGE_REMOVABLE)
            {
                mms_disk = (char)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);		
		        sprintf(drive_name, "%c:", mms_disk);
                text = msf_cmmn_str3cat(
                    MSF_MODID_MSM,
                    drive_name,
                    fs_map_table[i].ext_name,
                    (char*)(filename + msf_cmmn_utf8_strlen(fs_map_table[i].int_name)));
            }
#endif /*SLIM_WAP_MMS*/
/* SLIM_R ends */
            else
            {
                if(storage_id == MSF_MMS_STORAGE_PHONE)
				{
#ifdef MMS_IN_LARGE_STORAGE
					sprintf(drive_name, "%c:", getDiskLabel(MMS_STORAGE_PUBLIC));
					fs_map_table[i].hidden = 1;
#else					
				
					sprintf(drive_name, "%c:", getDiskLabel(MMS_STORAGE_SYSTEM));
				
				
				
#endif /*MMS_IN_LARGE_STORAGE*/
				}
                text = msf_cmmn_str3cat(
                    MSF_MODID_MSM,
                    drive_name,
                    fs_map_table[i].ext_name,
                    (char*)(filename + msf_cmmn_utf8_strlen(fs_map_table[i].int_name)));
            }
            break;
        }

    }

    if (!text)
    {
        MSF_MEM_FREE(MSF_MODID_MSM, filename);
        return NULL;
    }

    len = strlen(text);

    for (i = 0; i < len; i++)
    {
        if (text[i] == '/')
        {
            text[i] = '\\';
        }
    }

    len++;

    destLen = len * 2;

    destBuffer = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, destLen);

    if (destBuffer)
    {
        msf_charset_utf8_to_ucs2le(text, &len, destBuffer, &destLen);
    }

    MSF_MEM_FREE(MSF_MODID_MSM, filename);
    MSF_MEM_FREE(MSF_MODID_MSM, text);
    
    return (kal_uint8 *)destBuffer;
}   /* end of HDI_FileNameTranslate */


#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileReadDirLong
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [?]         
 *  nameBufLength       [IN]        
 *  type                [?]         
 *  size                [?]         
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileReadDirLong(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, long *size)
{
    return gmms_HDIa_fileReadDirLong_ext(dirName, pos, nameBuf, nameBufLength, type, size, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileReadDirLong
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [?]         
 *  nameBufLength       [IN]        
 *  type                [?]         
 *  size                [?]         
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileReadDirLong_ext(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, long *size, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gmms_HDIa_fileReadDir_ext(dirName, pos, nameBuf, nameBufLength, type, (int*)size, storage_id);
}

/*****************************************************************************
 * FUNCTION
 *  HDI_FileNameTranslate
 * DESCRIPTION
 *  This function translates file name from Obigo format to File System
 *  format. Specifically, the translations are listed below:
 *  a. utf8 --> ucs2
 *  b. / --> \
 *  c. remove "/external/"
 * PARAMETERS
 *  filename        [IN]        
 *  a(?)            [IN]        Src, pointer of file name
 * RETURNS
 *  a pointer of translated file name, integration shall free this pointer.
 *****************************************************************************/
kal_uint8 *HDI_FileNameTranslate(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return translateFileName(filename, MSF_MMS_STORAGE_PHONE);
  }



/*****************************************************************************
 * FUNCTION
 *  HDI_FileNameTranslate_ext
 * DESCRIPTION
 *  This function translates file name from Obigo format to File System
 *  format. In this we are providing the api to give prefrence to the memory card over
 *  the phone.
 *  Specifically, the translations are listed below:
 *  a. utf8 --> ucs2
 *  b. / --> \
 *  c. remove "/external/"
 * PARAMETERS
 *  filename        [IN]        
 *  a(?)            [IN]        Src, pointer of file name
 * RETURNS
 *  a pointer of translated file name, integration shall free this pointer.
 *****************************************************************************/

kal_uint8 *HDI_FileNameTranslate_ext(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_int32 result;
    FS_DiskInfo diskinfo;
    kal_uint8 *path;

	path = translateFileName(filename, MSF_MMS_STORAGE_MEM_CARD_1);
    result = FS_GetDiskInfo((WCHAR*) path, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

	if(result < 0)
	{
		 path = translateFileName(filename, MSF_MMS_STORAGE_MEM_CARD_2);
		 result = FS_GetDiskInfo((WCHAR*) path, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
		 if(result < 0)
		 {
			
		 	return translateFileName(filename, MSF_MMS_STORAGE_PHONE);
		 }
	}
	
	return path;
   
  }

MSF_INT32
msf_file_exist (const char *path)
{
  int       type;
  int size;
  char      name[MSF_CFG_VIRTUAL_FILE_NAME_LENGTH + 1];

  if (MSF_FILE_GETSIZE (path ) == HDI_FILE_ERROR_PATH) {
    if (MSF_FILE_READ_DIR (path, 0, name, MSF_CFG_VIRTUAL_FILE_NAME_LENGTH + 1, &type, &size ) ==
      HDI_FILE_ERROR_PATH) {
      return HDI_FILE_ERROR_PATH;
    }
  }
  return 1;
}
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGetExternalFileName
 * DESCRIPTION
 *  This function is to wrap translateFileName for other modules to use.
 *  Note that it is the output string is copied to the memory block allocated using
 *  the caller's module id.
 * PARAMETERS
 *  modId            [IN]        source module ID 
 *  src              [IN]        source filename
 * RETURNS
 *  a pointer of translated file name, integration shall free this pointer.
 *****************************************************************************/
MSF_UINT8 *gmms_HDIa_fileGetExternalFileName(MSF_UINT8 modId, const char *src)
{
    return gmms_HDIa_fileGetExternalFileName_ext(modId, src, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGetExternalFileName
 * DESCRIPTION
 *  This function is to wrap translateFileName for other modules to use.
 *  Note that it is the output string is copied to the memory block allocated using
 *  the caller's module id.
 * PARAMETERS
 *  modId            [IN]        source module ID 
 *  src              [IN]        source filename
 * RETURNS
 *  a pointer of translated file name, integration shall free this pointer.
 *****************************************************************************/
MSF_UINT8 *gmms_HDIa_fileGetExternalFileName_ext(MSF_UINT8 modId, const char *src, msf_mms_storage_enum storage_id)
{
    MSF_UINT8 *dest, *temp = translateFileName(src, storage_id);

    dest = MSF_MEM_ALLOC(modId, (app_ucs2_strlen((const kal_int8 *)temp) + 1) * ENCODING_LENGTH);

    app_ucs2_strcpy((kal_int8 *)dest, (const kal_int8 *)temp);

    FILE_NAME_FREE(temp);
    
    return dest;
}

/*****************************************************************************
 * FUNCTION
 *  HDI_needFlush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int isCriticalFile(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (!hdi_critical_files[i])
        {
            break;
        }
        if (msf_cmmn_strncmp_nc(
                filename,
                hdi_critical_files[i],
                msf_cmmn_utf8_strlen(hdi_critical_files[i])) == 0)
        {
            return 1;
        }
        i++;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  onFileTimeout
 * DESCRIPTION
 *  To handle timeout event for asyncronous file operation.
 * PARAMETERS
 *  msg_ptr     [in]        message pointer.
 * RETURNS
 *  void
 *****************************************************************************/
static void onFileTimeout(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    file_info_struct *file_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg_ptr != NULL);

    for (i = 0; i < MAX_NUM_FILES; i++)
    {
        if (&files[i] == msg_ptr)
        {
            break;
        }
    }

    if (i == MAX_NUM_FILES)
    {
        return;
    }

    file_ptr = (file_info_struct*) msg_ptr;

    file_ptr->event_id = NULL;

    if (file_ptr->mod_id != 0xff)
    {
        if (file_ptr->is_read_delay)
        {
            file_ptr->is_read_delay = KAL_FALSE;
            HDIc_fileNotify(file_ptr->mod_id, i, HDI_FILE_READ_READY);
        }

        if (file_ptr->is_write_delay)
        {
            file_ptr->is_write_delay = KAL_FALSE;
            HDIc_fileNotify(file_ptr->mod_id, i, HDI_FILE_WRITE_READY);
        }
    }

}   /* end of HDI_file_notify */


/*****************************************************************************
 * FUNCTION
 *  startTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pFile       [?]     
 *  file_ptr        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static eventid startTimer(file_info_struct *pFile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return evshed_set_event(evt_scheduler, onFileTimeout, (void*)pFile, HDI_FILE_DELAY_TIME);

}   /* end of HDI_file_start_timer */


/*****************************************************************************
 * FUNCTION
 *  stopTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_id        [IN]        
 *  file_ptr        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void stopTimer(eventid event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evshed_cancel_event(evt_scheduler, &event_id);

}   /* end of HDI_file_stop_timer */


/*****************************************************************************
 * FUNCTION
 *  file_handle_timer_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void hdi_file_timer_expiry_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evshed_timer_handler(evt_scheduler);

}

/*****************************************************************************
 * FUNCTION
 *  initFile
 * DESCRIPTION
 *  initialize context for file integration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void init_hdi_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(hdi_file_mutex == NULL)
    {
        hdi_file_mutex = kal_create_mutex("hdi_file_mutex");
    }    

    for (i = 0; i < MAX_NUM_FILES; i++)
    {
        files[i] = empty_file_info;
    }

    if (evt_scheduler == NULL)
    {

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
        evt_scheduler = evshed_create("HDI_FILE_BASE_TIMER", MOD_MMS, 0, 0);
#else
        evt_scheduler = evshed_create("HDI_FILE_BASE_TIMER", MOD_WAP, 0, 0);
#endif
        evshed_set_index(evt_scheduler, MSF_FILE_TIMER_ID);
    }
}

/**********************************************************************
 * HDI File functions 
 **********************************************************************/
/*****************************************************************************
 * FUNCTION
 *  HDIa_fileOpen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  fileName        [IN]        
 *  mode            [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileOpen(MSF_UINT8 modId, const char *fileName, int mode, long size)
{
    return gmms_HDIa_fileOpen_ext(modId, fileName, mode, size, MSF_MMS_STORAGE_PHONE);
}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileOpen_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  fileName        [IN]        
 *  mode            [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileOpen_ext(MSF_UINT8 modId, const char *fileName, int mode, long size, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, fd, ret = HDI_FILE_OK;
    kal_uint8 *fname;
    kal_uint32 flag = translateFileMode(mode) | FS_OPEN_SHARED | FS_OPEN_NO_DIR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_OPEN_01, "MSF_FILE_OPEN: fname=%s, storage=%d, mode=%d, size=%d\n",fileName, storage_id, mode, size));
    
    kal_take_mutex(hdi_file_mutex);
    if (fileName == NULL || msf_cmmn_utf8_strlen(fileName) == 0)
    {
        ret = HDI_FILE_ERROR_PATH;
        goto end;
    }

    for (i = 0; i < MAX_NUM_FILES; i++)
    {
        if (files[i].is_remove_delay != 0 && !msf_cmmn_strcmp_nc(fileName, files[i].file_name))
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_751C83E4172AEC19F1584BBCCED1AE38, "MSF_FILE_OPEN: File has been removed.\n"));            
            ret = HDI_FILE_ERROR_ACCESS;
            goto end;
        }
    }

    fname = translateFileName(fileName, storage_id);

    /* If both SET_CREATE and SET_EXCL are set and the file already exist,
       return ERROR_EXIST */
    if ((mode & HDI_FILE_SET_CREATE) && (mode & HDI_FILE_SET_EXCL))
    {
        if (FS_GetAttributes((WCHAR *)fname) >= 0)
        {
            FILE_NAME_FREE(fname);
            ret = HDI_FILE_ERROR_EXIST;
            goto end;
        }
    }

    for (i = 0; i < MAX_NUM_FILES; i++)
    {
        if (files[i].mod_id == 0xff)
        {
            break;
        }
    }

    if (i == MAX_NUM_FILES)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_01B703735B6BFC3FEFCCBF921F927750, "MSF_FILE_OPEN: No more empty file slot available.\n"));            
        for (i = 0; i < MAX_NUM_FILES; i++)
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_OPEN_02, "fname=%s, storage=%d, mod_id=%d\n", files[i].file_name, files[i].mms_drive, files[i].mod_id));            
        }
        FILE_NAME_FREE(fname);
        ret = HDI_FILE_ERROR_ACCESS;
        goto end;
    }

    fd = FS_Open((WCHAR*) fname, flag);
    FILE_NAME_FREE(fname);

    if (fd < 0)
    {
        ret = translateFileError(fd);
        goto end;
    }

    /* open successfully */

    /* because FS doesn't support APPEND mode, thus we shall seek the 
       file pointer to the end of file */
    if (mode & HDI_FILE_SET_APPEND)
    {
        ret = FS_Seek(fd, 0, FS_FILE_END);

        if (ret < 0)
        {
            FS_Close(fd);
            ret = translateFileError(ret);
            goto end;
        }
    }

    if ((mode & HDI_FILE_SET_CREATE) && size > 0)
    {
        ret = FS_Seek(fd, size, FS_FILE_BEGIN);
        if (ret == FS_DISK_FULL)
        {
            FS_Close(fd);
            /* 
             * We need to remove the file as we have to free the DISK SPACE. 
             * FS_Seek() API fails due to insufficient DISK SPACE.
             * So, we need to cleanup the created file.
             */
            fileRemove(fileName,1, storage_id); 
            ret = HDI_FILE_ERROR_FULL;
            goto end;
        }
        FS_Seek(fd, 0, FS_FILE_BEGIN);
    }

    files[i].handle = fd;
    files[i].mod_id = modId;
    files[i].mode = mode;
    files[i].is_read_delay = KAL_FALSE;
    files[i].is_write_delay = KAL_FALSE;
    files[i].flag = 0;
    files[i].fs_flag = isCriticalFile(fileName);
    files[i].file_name = msf_cmmn_strdup(MSF_MODID_MSM, fileName);
	files[i].mms_drive = storage_id;
    ret = i;

  end:
    kal_give_mutex(hdi_file_mutex);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileClose(int fileHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = HDI_FILE_OK;
    file_info_struct *file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_904608A303CCA8516AEC7AD181370F73, "MSF_FILE_CLOSE: fileHandle=%d\n",fileHandle));

    if (fileHandle < 0 || fileHandle >= MAX_NUM_FILES)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    kal_take_mutex(hdi_file_mutex);

    file = &files[fileHandle];

    ret = FS_Close(file->handle);

    if(file->is_remove_delay)
    {
        fileRemove(file->file_name, 1, file->mms_drive);
    }

    /* if already started a timer for notify, stop it now */
    if (file->event_id != NULL)
    {
        stopTimer(file->event_id);
    }

    MSF_MEM_FREE(MSF_MODID_MSM, file->file_name);
    files[fileHandle] = empty_file_info;

    kal_give_mutex(hdi_file_mutex);

    return translateFileError(ret);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileWrite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  data            [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_fileWrite(int fileHandle, void *data, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    long bytes_written = 0;
    file_info_struct *file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_6C020031813BA0DB00C8288925B73B5C, "MSF_FILE_WRITE: fileHandle=%d, size=%d\n",fileHandle, size));

    if (fileHandle < 0 || fileHandle >= MAX_NUM_FILES || data == NULL)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    if (size == 0)
    {
        return 0;
    }

    kal_take_mutex(hdi_file_mutex);

    file = &files[fileHandle];

    ret = FS_Write(file->handle, data, size, (kal_uint32*)&bytes_written);

    if (ret < 0 && ((file->mode & HDI_FILE_SET_CUSTOM_BLOCKING) || bytes_written == 0))
    {
        kal_give_mutex(hdi_file_mutex);
        return translateFileError(ret);
    }

    if (file->fs_flag)
    {
        FS_Commit(file->handle);
    }

    kal_give_mutex(hdi_file_mutex);
    return bytes_written;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRead
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  data            [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_fileRead(int fileHandle, void *data, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    kal_uint32 bytes_read = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_5A94EB217FC4D26EC83E2EA36990FEE5, "MSF_FILE_READ: fileHandle=%d, size=%d\n",fileHandle, size));

    if (fileHandle < 0 || fileHandle >= MAX_NUM_FILES || data == NULL)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    if (size == 0)
    {
        return 0;
    }

    kal_take_mutex(hdi_file_mutex);

    if(files[fileHandle].mode & HDI_FILE_SET_WRONLY)
    {
        kal_give_mutex(hdi_file_mutex);
        return HDI_FILE_ERROR_ACCESS;
    }

    ret = FS_Read(files[fileHandle].handle, data, size, &bytes_read);

    if (ret < 0 && bytes_read == 0)
    {
        kal_give_mutex(hdi_file_mutex);
        return translateFileError(ret);
    }

    if (bytes_read == 0)
    {
        kal_give_mutex(hdi_file_mutex);
        return HDI_FILE_ERROR_EOF;
    }

    kal_give_mutex(hdi_file_mutex);
    
    return bytes_read;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileFlush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_fileFlush(int fileHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_8D57BE6374C85BFBEA10E8CFCE95E451, "MSF_FILE_FLUSH: fileHandle=%d\n",fileHandle));

    if (fileHandle < 0 || fileHandle >= MAX_NUM_FILES)
    {
        return;
    }

    kal_take_mutex(hdi_file_mutex);

    FS_Commit(files[fileHandle].handle);

    kal_give_mutex(hdi_file_mutex);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileSeek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  offset          [IN]        
 *  seekMode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_fileSeek(int fileHandle, long offset, int seekMode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    file_info_struct *file;
    long cur_pos;
    int seekType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_F80F98C86B56AB610567C1DBFDE0EDA7, "MSF_FILE_SEEK: fileHandle=%d, offset=%d, seekMod=%d\n",fileHandle, offset, seekMode));
    if (fileHandle < 0 || fileHandle >= MAX_NUM_FILES)
    {
        return HDI_FILE_ERROR_INVALID;
    }

    kal_take_mutex(hdi_file_mutex);

    file = &files[fileHandle];

    if(file->mode & HDI_FILE_SET_APPEND)
    {
        kal_give_mutex(hdi_file_mutex);
        return HDI_FILE_ERROR_ACCESS;
    }

    if (seekMode == HDI_FILE_SEEK_SET)
    {
        seekType = FS_FILE_BEGIN;
    }
    else if (seekMode == HDI_FILE_SEEK_CUR)
    {
        seekType = FS_FILE_CURRENT;
    }
    else
    {
        seekType = FS_FILE_END;
    }

    cur_pos = FS_Seek(file->handle, offset, seekType);

    /* not error actually, file is too long */
    if ((cur_pos < 0) && (cur_pos == FS_LONG_FILE_POS))
    {
        FS_FileInfo info;

        if (FS_GetFileInfo(file->handle, &info) < 0)
        {
            kal_give_mutex(hdi_file_mutex);
            return -1;
        }
        cur_pos = info.FilePos;
    }
    kal_give_mutex(hdi_file_mutex);

    return cur_pos;
}

static int fileRemove(const char *fileName, int forceRemove, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, ret;
    WCHAR *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((fname = (WCHAR*) translateFileName(fileName, storage_id)) == NULL)
    {
        return HDI_FILE_ERROR_PATH;
    }

    if(!forceRemove)
    {
        for (i = 0; i < MAX_NUM_FILES; i++)
        {
            if (files[i].mod_id != 0xff && (storage_id == files[i].mms_drive) && !msf_cmmn_strcmp_nc(fileName, files[i].file_name))
            {
                files[i].is_remove_delay = 1;
                FILE_NAME_FREE(fname);
                return 0;
            }
        }
    }

    ret = FS_Delete(fname);

    FILE_NAME_FREE(fname);

    return translateFileError(ret);
}
/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRemove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileRemove(const char *fileName)
{
    return gmms_HDIa_fileRemove_ext(fileName, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileRemove_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileRemove_ext(const char *fileName, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    kal_uint8 *fname = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_REMOVE_01, "MSF_FILE_REMOVE: fileName=%s, storage=%d\n",fileName, storage_id));

    fname = translateFileName(fileName, storage_id);
    if (fname == NULL)
    {
        return HDI_FILE_ERROR_PATH;
    }

    FILE_NAME_FREE(fname);

    kal_take_mutex(hdi_file_mutex);
    ret = fileRemove(fileName, 0, storage_id);
    kal_give_mutex(hdi_file_mutex);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcName     [IN]        
 *  dstName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileRename(const char *srcName, const char *dstName)
{
    return gmms_HDIa_fileRename_ext(srcName, dstName, MSF_MMS_STORAGE_PHONE);
}
/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcName     [IN]        
 *  dstName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileRename_ext(const char *srcName, const char *dstName, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    WCHAR *fname1, *fname2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_RENAME_01, "MSF_FILE_RENAME: srcName=%s, dstName=%s, storage=%d\n",srcName, dstName, storage_id));

    if ((fname1 = (WCHAR*) translateFileName(srcName, storage_id)) == NULL)
    {
        return HDI_FILE_ERROR_PATH;
    }

    if ((fname2 = (WCHAR*) translateFileName(dstName, storage_id)) == NULL)
    {
        return HDI_FILE_ERROR_PATH;
    }

    ret = FS_Rename(fname1, fname2);

    FILE_NAME_FREE(fname1);
    FILE_NAME_FREE(fname2);

    if (ret == FS_ACCESS_DENIED)
    {
        return HDI_FILE_ERROR_EXIST;
    }

    return translateFileError(ret);
}


#ifndef __NON_BLOCKING_FILE_MOVE_SUPPORT__
int gmms_HDIa_filemove_ext1(const char *srcName, msf_mms_storage_enum src_storage_id, const char *dstName, msf_mms_storage_enum dest_storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    WCHAR *fname1, *fname2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_MOVE_EXT_01, "MSF_FILE_MOVE_EXT: srcName=%s, src_storage=%d, dstName=%s, dst_storage=%d\n",srcName, src_storage_id, dstName, dest_storage_id));

    if ((fname1 = (WCHAR*) translateFileName(srcName, src_storage_id)) == NULL)
    {
        return HDI_FILE_ERROR_PATH;
    }

    if ((fname2 = (WCHAR*) translateFileName(dstName, dest_storage_id)) == NULL)
    {
        return HDI_FILE_ERROR_PATH;
    }

    ret = FS_Move(fname1, fname2, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);

    FILE_NAME_FREE(fname1);
    FILE_NAME_FREE(fname2);

    if (ret == FS_ACCESS_DENIED)
    {
        return HDI_FILE_ERROR_EXIST;
    }

    return translateFileError(ret);
}
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileMkDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileMkDir(const char *dirName)
{
    return gmms_HDIa_fileMkDir_ext(dirName, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileMkDir_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileMkDir_ext(const char *dirName, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret, i, len;
    WCHAR *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_MKDIR_01, "MSF_FILE_MKDIR: dirName=%s, storage=%d\n",dirName, storage_id));

    fname = (WCHAR*) translateFileName(dirName, storage_id);

    if (!fname)
    {
        return HDI_FILE_ERROR_PATH;
    }

    len = strlen(dirName);
    if (dirName[len - 1] == '/')
    {
        len--;  /* Trim off the last '/' */
    }

    ret = FS_CreateDir(fname);

    if (ret == FS_NO_ERROR)
    {
        for (i = 0; i < NUM_FS_MAP_TABLE_ENTRY; i++)
        {
            if (msf_cmmn_strncmp_nc(dirName, fs_map_table[i].int_name, len) == 0 && fs_map_table[i].hidden)
            {
                FS_SetAttributes((unsigned short*)fname, FS_ATTR_DIR | FS_ATTR_HIDDEN);
                break;
            }
        }
    }

    FILE_NAME_FREE(fname);

    return translateFileError(ret);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRmDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileRmDir(const char *dirName)
{
    return gmms_HDIa_fileRmDir_ext(dirName, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileRmDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileRmDir_ext(const char *dirName, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_RMDIR_01, "MSF_FILE_RMDIR: dirName=%s, storage=%d\n",dirName, storage_id));

    if (dirName == NULL || msf_cmmn_utf8_strlen(dirName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    /* convert slash '/' to backslash '\' */
    fname = translateFileName(dirName, storage_id);

    ret = FS_RemoveDir((WCHAR*) fname);

    FILE_NAME_FREE(fname);

    return translateFileError(ret);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileDelDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId     [IN]
 *  path      [IN]
 *  removeDirectory [IN]
 * RETURNS
 *  
 *****************************************************************************/
int
gmms_HDIa_fileDelDir (MSF_UINT8 modId, const char *path, MSF_BOOL removeDirectory)
{
    return gmms_HDIa_fileDelDir_ext(modId, path, removeDirectory, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileDelDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId     [IN]
 *  path      [IN]
 *  removeDirectory [IN]
 * RETURNS
 *  
 *****************************************************************************/
int
gmms_HDIa_fileDelDir_ext (MSF_UINT8 modId, const char *path, MSF_BOOL removeDirectory, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    size_t     pathLength;
    int        index;
    int        returnCode;
    int        type;
    int        size;
    MSF_BOOL   removedEntry;
    char      *entryPath = 0;
    char       name[MSF_CFG_VIRTUAL_FILE_NAME_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pathLength = strlen (path);
    entryPath = MSF_MEM_ALLOC (modId, pathLength + MSF_CFG_VIRTUAL_FILE_NAME_LENGTH + 2);

    (void)strcpy (entryPath, path);
    if (path[pathLength - 1] != '/')
    {
    	(void)strcat (entryPath, "/");
    	pathLength++;
    }

    index = 0;
    do
    {
      	returnCode = gmms_HDIa_fileReadDir_ext (path, index, name, MSF_CFG_VIRTUAL_FILE_NAME_LENGTH + 1, &type, &size, storage_id);
      	removedEntry = FALSE;
      	if (returnCode == HDI_FILE_OK)
        {
        		entryPath[pathLength] = '\0';
        		(void)strcat (entryPath, name);

        		if (type == HDI_FILE_FILETYPE)
            {
        		  	if (gmms_HDIa_fileRemove_ext (entryPath, storage_id) == HDI_FILE_OK)
                {
        			    	removedEntry = TRUE;
        			  }
        		}
        		else
            {
          			if (gmms_HDIa_fileDelDir_ext (modId, entryPath, TRUE, storage_id) == HDI_FILE_OK)
                {
          			  	removedEntry = TRUE;
          			}
        		}
        		if (!removedEntry)
            {
        			index++;
        		}
        }
      	else if (returnCode == HDI_FILE_ERROR_PATH)
        {

        }
    } while (returnCode == HDI_FILE_OK);

    MSF_MEM_FREE (modId, entryPath);

    if (removeDirectory)
    {
      	returnCode = gmms_HDIa_fileRmDir_ext (path, storage_id);
    }
    return returnCode;
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGetSizeDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileGetSizeDir(const char *dirName)
{
    return gmms_HDIa_fileGetSizeDir_ext(dirName, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileGetSizeDir_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileGetSizeDir_ext(const char *dirName, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    FS_DOSDirEntry info;
    kal_uint8 *path;
    WCHAR *filename;
    char *buf;
    int no_entry = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_GET_SIZE_DIR_01, "MSF_FILE_GETSIZE_DIR: dirName=%s, storage=%d\n",dirName, storage_id));

    if (dirName == NULL || msf_cmmn_utf8_strlen(dirName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    path = translateFileName(dirName, storage_id);

    if(FS_GetAttributes((WCHAR*) path) < 0)
    {
        FILE_NAME_FREE(path);
        return HDI_FILE_ERROR_PATH;
    }

    FILE_NAME_FREE(path);

    buf = msf_cmmn_strcat(MSF_MODID_MSM, dirName, "/*");

    if (!buf)
    {
        return HDI_FILE_ERROR_PATH;
    }
    
    path = translateFileName(buf, storage_id);

    FILE_NAME_FREE(buf);

    if (!path)
    {
        return HDI_FILE_ERROR_PATH;
    }

    filename = MSF_MEM_ALLOC(MSF_MODID_MSM, MAX_HDI_FILE_NAME_SIZE * 2);

    if (!filename)
    {
        FILE_NAME_FREE(path);
        return HDI_FILE_ERROR_PATH;
    }

    handle = FS_FindFirst((WCHAR*) path, 0, 0, &info, (WCHAR*) filename, MAX_HDI_FILE_NAME_SIZE * 2);

    FILE_NAME_FREE(path);

    if (handle < 0)
    {
        FILE_NAME_FREE(filename);
        if(handle == FS_NO_MORE_FILES)
        {
            return 0;
        }
        return HDI_FILE_ERROR_PATH;
    }

    do
    {
        if (kal_wstrcmp((WCHAR*) filename, L".") != 0 && kal_wstrcmp((WCHAR*) filename, L"..") != 0)
        {
            no_entry++;
        }
    } while (FS_FindNext(handle, &info, (WCHAR*) filename, MAX_HDI_FILE_NAME_SIZE * 2) == FS_NO_ERROR);

    FILE_NAME_FREE(filename);

    if (FS_FindClose(handle) < 0)
    {
        return -1;
    }

    return no_entry;

}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [OUT]         
 *  nameBufLength       [IN]        
 *  type                [OUT]         
 *  size                [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileReadDir(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size)
{
    return gmms_HDIa_fileReadDir_ext(dirName, pos, nameBuf, nameBufLength, type, size, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [OUT]         
 *  nameBufLength       [IN]        
 *  type                [OUT]         
 *  size                [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileReadDir_ext(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle = -1;  /* save temp. file handle for find */
    FS_DOSDirEntry info;
    kal_uint8 *path;
    WCHAR *filename;
    char *buf;
    int index = 0;
    long length1, length2;
    int ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_READ_DIR_01, "MSF_FILE_READ_DIR: dirName=%s, storage=%d, pos=%d\n",dirName, storage_id, pos));

    if (dirName == NULL || msf_cmmn_utf8_strlen(dirName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    buf = msf_cmmn_strcat(MSF_MODID_MSM, dirName, "/*");

    if (!buf)
    {
        return HDI_FILE_ERROR_PATH;
    }

    path = translateFileName(buf, storage_id);

    FILE_NAME_FREE(buf);

    if (!path)
    {
        return HDI_FILE_ERROR_PATH;
    }

    filename = (WCHAR*) MSF_MEM_ALLOC(MSF_MODID_MSM, nameBufLength * 2);

    if (!filename)
    {
        goto error;
    }

    handle = FS_FindFirst((WCHAR*) path, 0, 0, &info, (WCHAR*) filename, nameBufLength * 2);

    FILE_NAME_FREE(path);

    if (handle < 0)
    {
        goto error;
    }

    do
    {
        if (kal_wstrcmp((WCHAR*) filename, L".") != 0 && kal_wstrcmp((WCHAR*) filename, L"..") != 0)
        {
            if (index == pos)
            {
                break;
            }
            index++;
        }
        ret = FS_FindNext(handle, &info, (WCHAR*) filename, nameBufLength * 2);
    } while (ret == FS_NO_ERROR);

    if (ret != FS_NO_ERROR)
    {
        FS_FindClose(handle);
        FILE_NAME_FREE(filename);
        return HDI_FILE_ERROR_INVALID;  /* the value of 'pos' did not present a valid entry */
    }

    if (info.Attributes & FS_ATTR_DIR)
    {
        *type = HDI_FILE_DIRTYPE;
    }
    else
    {
        *type = HDI_FILE_FILETYPE;
        if (size)
        {
            *size = info.FileSize;
        }
    }

    length1 = (kal_wstrlen(filename) + 1) * 2 ;
    length2 = nameBufLength - 1; /* Last byte is for NULL termination */
    
    msf_charset_ucs2le_to_utf8((const char*)filename, &length1, nameBuf, &length2);

    FILE_NAME_FREE(filename);

    FS_FindClose(handle);

    return HDI_FILE_OK;

error:
    FILE_NAME_FREE(filename);
    return HDI_FILE_ERROR_PATH;
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDirSeq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [?]         
 *  nameBufLength       [IN]        
 *  type                [?]         
 *  size                [?]         
 *  dirHandle           [?]         
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileReadDirSeq(
        const char *dirName,
        int pos,
        char *nameBuf,
        int nameBufLength,
        int *type,
        int *size,
        int *dirHandle)
{
    return gmms_HDIa_fileReadDirSeq_ext(dirName, pos, nameBuf, nameBufLength, type, size, dirHandle, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDirSeq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirName             [IN]        
 *  pos                 [IN]        
 *  nameBuf             [?]         
 *  nameBufLength       [IN]        
 *  type                [?]         
 *  size                [?]         
 *  dirHandle           [?]         
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileReadDirSeq_ext(
        const char *dirName,
        int pos,
        char *nameBuf,
        int nameBufLength,
        int *type,
        int *size,
        int *dirHandle, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DOSDirEntry info;
    kal_uint8 *path;
    WCHAR *filename;
    char *buf;
    long length1, length2;
    int ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_READ_DIR_01, "MSF_FILE_READ_DIR: dirName=%s, storage=%d, pos=%d\n",dirName, storage_id, pos));

    if (dirHandle == NULL)
    {
        return HDI_FILE_ERROR_INVALID;
    }
    
    if (dirName == NULL || msf_cmmn_utf8_strlen(dirName) == 0)
    {
        return HDI_FILE_ERROR_PATH;
    }

    filename = (WCHAR*) MSF_MEM_ALLOC(MSF_MODID_MSM, nameBufLength * 2);

    if (!filename)
    {
        return HDI_FILE_ERROR_PATH;
    }

    if (*dirHandle < 0)
    {
        buf = msf_cmmn_strcat(MSF_MODID_MSM, dirName, "/*");

        if (!buf)
        {
            goto error;
        }

        path = translateFileName(buf, storage_id);

        FILE_NAME_FREE(buf);

        if (!path)
        {
            goto error;
        }

        *dirHandle = FS_FindFirst((WCHAR*) path, 0, 0, &info, (WCHAR*) filename, nameBufLength * 2);

        FILE_NAME_FREE(path);

        if (*dirHandle < 0)
        {
            goto error;
        }

        if (kal_wstrcmp((WCHAR*) filename, L".") != 0 && kal_wstrcmp((WCHAR*) filename, L"..") != 0)
        {
            goto exit;
        }
    }

    while ((ret = FS_FindNext(*dirHandle, &info, (WCHAR*) filename, nameBufLength * 2)) == FS_NO_ERROR)
    {
        if (kal_wstrcmp((WCHAR*) filename, L".") != 0 && kal_wstrcmp((WCHAR*) filename, L"..") != 0)
        {
            break;
        }
    }

    if (ret != FS_NO_ERROR)
    {
        FILE_NAME_FREE(filename);
        return HDI_FILE_ERROR_INVALID;  /* the value of 'pos' did not present a valid entry */
    }

exit:
    if (info.Attributes & FS_ATTR_DIR)
    {
        *type = HDI_FILE_DIRTYPE;
    }
    else
    {
        *type = HDI_FILE_FILETYPE;
        if (size)
        {
            *size = info.FileSize;
        }
    }

    length1 = (kal_wstrlen(filename) + 1) * 2 ;
    length2 = nameBufLength - 1;
    
    msf_charset_ucs2le_to_utf8((const char*)filename, &length1, nameBuf, &length2);

    FILE_NAME_FREE(filename);

    return HDI_FILE_OK;

error:
    FILE_NAME_FREE(filename);
    return HDI_FILE_ERROR_PATH;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileReadDirSeqClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dirHandle       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_fileReadDirSeqClose(int *dirHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*dirHandle > 0)
    {
        FS_FindClose(*dirHandle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileSelect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  eventType       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_fileSelect(int fileHandle, int eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    file_info_struct *file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_1251685E473153699DB93021728F8CF2, "MSF_FILE_SELECT: fileHandle=%d, eventType=%d\n",fileHandle, eventType));

    if (fileHandle < 0 || fileHandle >= MAX_NUM_FILES)
    {
        return;
    }

    kal_take_mutex(hdi_file_mutex);

    file = &files[fileHandle];

    /* for one file, only start timer once */
    if ((file->is_read_delay == KAL_FALSE) && (file->is_write_delay == KAL_FALSE))
    {
        file->event_id = startTimer(file);
    }

    if (eventType == HDI_FILE_EVENT_READ)
    {
        file->is_read_delay = KAL_TRUE;
    }
    else
    {
        file->is_write_delay = KAL_TRUE;
    }

    kal_give_mutex(hdi_file_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileSetSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileHandle      [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_fileSetSize(int fileHandle, long size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_FileInfo info;
    kal_int32 cur_pos;
    file_info_struct *file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_0AC6E18667C5C1009BCBE9703A7EF2CA, "MSF_FILE_SETSIZE: fileHandle=%d, size=%d\n",fileHandle, size));

    if (fileHandle < 0 || fileHandle >= MAX_NUM_FILES || (size < 0))
    {
        return HDI_FILE_ERROR_INVALID;
    }

    kal_take_mutex(hdi_file_mutex);

    file = &files[fileHandle];

    /* get current allocated size & file pointer */
    if (FS_GetFileInfo(file->handle, &info) < 0)
    {
        goto error;
    }

    if ((cur_pos = FS_Seek(file->handle, 0, FS_FILE_CURRENT)) < 0)
    {
        goto error;
    }

    if (size > (long)info.AllocatedSize)
    {
#if 1        
        if (FS_Seek(file->handle, size, FS_FILE_BEGIN) < 0)
        {
            goto error;
        }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }
    else if (size < (long)info.AllocatedSize)
    {
        /* need to truncate the file */

        /* use FS_Truncate to shorter the file size, 
           FS_truncate set the current file size to "current file pointer"
           thus we need to seek the file pointer to the position we desired 
           and then truncate it !! */
        if (FS_Seek(file->handle, size, FS_FILE_BEGIN) < 0)
        {
            goto error;
        }

        if (FS_Truncate(file->handle) < 0)
        {
            goto error;
        }
    }

    /* set file pointer to original one */
    if (cur_pos < size)
    {
        FS_Seek(file->handle, cur_pos, FS_FILE_BEGIN);
    }

    kal_give_mutex(hdi_file_mutex);
    return size;

  error:
    kal_give_mutex(hdi_file_mutex);
    return -1;

}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGetSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_fileGetSize(const char *fileName)
{
    return gmms_HDIa_fileGetSize_ext(fileName, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGetSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long gmms_HDIa_fileGetSize_ext(const char *fileName, msf_mms_storage_enum storage_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    kal_uint32 size;
    int ret;
    kal_uint8 *fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_GET_SIZE_01, "MSF_FILE_GETSIZE: fileName=%s, storage=%d\n",fileName, storage_id));

    fname = translateFileName(fileName, storage_id);

    if (!fname)
    {
        return HDI_FILE_ERROR_PATH;
    }

    /* because FS_GetFileSize doesn't take file name as argument, thus
       we shall oepn this file first */
    handle = FS_Open((WCHAR*) fname, FS_READ_ONLY | FS_OPEN_SHARED);

    FILE_NAME_FREE(fname);

    if (handle < 0)
    {
        return translateFileError(handle);
    }

    ret = FS_GetFileSize(handle, &size);

    FS_Close(handle);

    return (ret == FS_NO_ERROR) ? size : translateFileError(ret);

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileCloseAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_fileCloseAll(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_D2E20A6822333F4B6A0B747C3B24EC22, "MSF_FILE_CLOSE_ALL: modId=%d\n",modId));

    for (i = 0; i < MAX_NUM_FILES; i++)
    {
        if (files[i].handle != HDI_INVALID_FILE && files[i].mod_id == modId)
        {
            ret = gmms_HDIa_fileClose(i);

            /* HDI_FILE_ERROR_ACCESS on closing files of removed memory card */
            if (ret != 0 && ret != HDI_FILE_ERROR_ACCESS && ret != HDI_FILE_ERROR_PATH)
            {
                /*EXT_ASSERT(0, (kal_uint32)ret, 0, 0);*/  /* error occurred */
                ASSERT(0); /*can be removed in slim*/
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_fileGenVirtualFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]
 *  fileHandle      [IN]        
 *  vfs_name        [?]         
 *  name_len        [IN]        
 *  offset          [IN]        
 *  len             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int gmms_HDIa_fileGenVirtualFileName(MSF_UINT8 modId, int fileHandle, char *vfs_name, int name_len, int offset, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fs_result;
    char *fname;
    file_info_struct *file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(hdi_file_mutex);
    file = &files[fileHandle];
    memset(vfs_name, 0, name_len);
    fname = MSF_MEM_CALLOC(modId, 1, FS_GenVFN_SIZE);
    fs_result = FS_GenVirtualFileName(
                    file->handle,
                    (kal_uint16 *) fname,
                    (unsigned int)FS_GenVFN_SIZE,
                    (unsigned int)offset,
                    (unsigned int)len);

    kal_give_mutex(hdi_file_mutex);
    if (fs_result != 0)
    {
        MSF_MEM_FREE(modId, fname);
        return HDI_FILE_ERROR_ACCESS;
    }
    else
    {
        kal_int32 src_len = 0, dst_len = 0;

        /* convert the virtual file name */
        src_len = app_ucs2_strlen((const kal_int8 *)fname) * ENCODING_LENGTH;
        dst_len = name_len;
        msf_charset_ucs2le_to_utf8(fname, (long *)&src_len, NULL, (long *)&dst_len);
        ASSERT(dst_len < name_len);
        msf_charset_ucs2le_to_utf8(fname, (long *)&src_len, vfs_name, (long *)&dst_len);
        MSF_MEM_FREE(modId, fname);
        /* Append the default file type */
        strcat(vfs_name, ".vir");

        return HDI_FILE_OK;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileLastModifiedDate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src           [IN]
 *  storage_id      [IN]      
      
 * RETURNS
 *  
 *****************************************************************************/


MSF_UINT32
gmms_HDIa_fileLastModifiedDate(const char *src)
{
    return gmms_HDIa_fileLastModifiedDate_ext(src, MSF_MMS_STORAGE_PHONE);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileLastModifiedDate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src           [IN]
 *  storage_id      [IN]      
      
 * RETURNS
 *  
 *****************************************************************************/


MSF_UINT32
gmms_HDIa_fileLastModifiedDate_ext(const char *src, msf_mms_storage_enum storage_id)
{
	kal_uint8 *fname;
	int fileHandle;
	FS_FileInfo fileInfo;
	int ret; 
	LastModifiedDate_u lastmodifieddate; 

	if ((fname = translateFileName(src, storage_id)) == NULL)
    {
        return (MSF_UINT32)HDI_FILE_ERROR_PATH;
    }

	fileHandle = FS_Open((WCHAR*)fname, FS_READ_ONLY);

	if (fileHandle < 0)
    {
        ret = translateFileError(fileHandle);
		FS_Close(fileHandle);
		if(NULL != fname)
		{
			FILE_NAME_FREE(fname);
		}
        return ret;
    }
    
	if (FS_GetFileInfo(fileHandle, &fileInfo) == FS_NO_ERROR)
    {
        lastmodifieddate.DateTime =  fileInfo.DirEntry->DateTime;
		FS_Close(fileHandle);
		if(NULL != fname)
		{
			FILE_NAME_FREE(fname);
		}
		return lastmodifieddate.LastModified;
    }

	FS_Close(fileHandle);
		if(NULL != fname)
		{
			FILE_NAME_FREE(fname);
		}
	return (MSF_UINT32)HDI_FILE_ERROR_ACCESS;
}


/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_IsMemCardPresent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage_id           [IN]
       
 * RETURNS
 *  
 *****************************************************************************/

MSF_BOOL
gmms_HDIa_IsMemCardPresent(msf_mms_storage_enum storage_id)
{
	int mms_disk;
	int ret; 
	
	if(storage_id < MSF_MMS_STORAGE_MEM_CARD_1 || storage_id > MSF_MMS_STORAGE_MEM_CARD_2)
	{				
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_IS_MCARD_PRESENT_01, "MSF_FILE_IS_MCARD_PRESENT: Inavlid storage=%d\n",storage_id));
		return FALSE; 			
	}
	mms_disk = FS_GetDrive(FS_DRIVE_V_REMOVABLE, storage_id, FS_NO_ALT_DRIVE);	
	ret = FS_GetDevStatus(mms_disk, FS_MOUNT_STATE_ENUM);

	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, HDI_FILE_IS_MCARD_PRESENT_02, "MSF_FILE_IS_MCARD_PRESENT: storage=%d, status=%d\n",storage_id, ret));

	if(ret >=0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_send_filemove_response_signal_to_msm
 * DESCRIPTION : this API is called by mms task to write a signal to MSM 
 * telling it the result of File Move operation.
 *  
 * PARAMETERS
 *  result           [IN]       
 * RETURNS
 *  
 *****************************************************************************/

void 
gmms_HDIa_send_filemove_response_signal_to_msm(MSF_INT32 result)
{
	msf_file_move_response_t *p;

	p = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(msf_file_move_response_t));

    if (result == FS_MOVE_PGS_DONE)
    {
        p->status = MSF_MMS_FILE_MOVE_DONE; 
    }
    else
    {
        p->status = MSF_MMS_FILE_MOVE_FAIL; 
    }
	
    MSF_SIGNAL_SEND (MSF_MODID_MSM, MSF_MODID_MSM, MSF_MMS_SIG_FILE_MOVE, p);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileMove
 * DESCRIPTION : this API is to be called by application for moving a file .
 *  It will write a signal to MSM, for intiating the operation.
 * PARAMETERS
 *  modId					[IN]
 *  src						[IN]        
 *  src_storage_id			[IN]         
 *  dst						[IN]        
 *  dst_storage_id          [IN]        
 *  flag					[IN]        
 * RETURNS
 *  
 *****************************************************************************/

void
gmms_HDIa_fileMove(MSF_UINT8 ModId, const char *src, const char *dst, int flag)
{
    gmms_HDIa_fileMove_ext2(ModId, src, MSF_MMS_STORAGE_PHONE, dst, MSF_MMS_STORAGE_PHONE, flag);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_fileMove
 * DESCRIPTION : this API is to be called by application for moving a file .
 *  It will write a signal to MSM, for intiating the operation.
 * PARAMETERS
 *  modId					[IN]
 *  src						[IN]        
 *  src_storage_id			[IN]         
 *  dst						[IN]        
 *  dst_storage_id          [IN]        
 *  flag					[IN]        
 * RETURNS
 *  
 *****************************************************************************/

void
gmms_HDIa_fileMove_ext2(MSF_UINT8 ModId, const char *src, msf_mms_storage_enum src_storage_id,
				   const char *dst, msf_mms_storage_enum dst_storage_id, int flag)
{
	msf_file_move_t *p;
	
	p = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(msf_file_move_t));
	
	p->flag = flag;
	p->modid = ModId;
	p->src_filename = msf_cmmn_strdup(MSF_MODID_MSM, src);
	p->src_store = src_storage_id;
	p->dst_filename = msf_cmmn_strdup(MSF_MODID_MSM, dst);
	p->dst_store = dst_storage_id;
	
	MSF_SIGNAL_SEND (MSF_MODID_MSM, MSF_MODID_MSM, MSF_SIG_FILE_MOVE, p);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDI_handle_file_move
 * DESCRIPTION This APi is called by MSM , for in response to the signal
 * MSF_SIG_FILE_MOVE, it will create a linked list for corrsponding requests.
 *  
 * PARAMETERS
 *  p           [IN]      
 * RETURNS
 *  
 *****************************************************************************/


void
gmms_HDI_handle_file_move(void *p)
{
	msf_file_move_t *resp = (msf_file_move_t*)p;
	msf_file_move_list_t *temp = msf_file_move_list;
	

	if(NULL == temp)
	{
		temp = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(msf_file_move_list_t));
		temp->head = NULL;
		temp->tail = NULL;
		msf_file_move_list = temp;
		msf_file_move_list->state = MSF_FILE_MOVE_AVAILABLE;
	}

	gmms_file_move_add_node(resp);   /* Add node to msf_file_move_node_t list.*/
	
	if(msf_file_move_list->state == MSF_FILE_MOVE_AVAILABLE)
	{
		temp->state = MSF_FILE_MOVE_BUSY;
		gmms_HDI_file_move();
	}
	else
	{
		return; /* Need to see */	
	}		
}

/*****************************************************************************
 * FUNCTION
 *  gmms_file_move_add_node
 * DESCRIPTION : Creates a linked list of nodes of type "msf_file_move_t".
 *  
 * PARAMETERS
 *  resp           [IN]        
 * RETURNS
 *  
 *****************************************************************************/


static void 
gmms_file_move_add_node(msf_file_move_t *resp)
{
	msf_file_move_node_t *temp = msf_file_move_list->head;
	msf_file_move_t *p;
	
	p = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(msf_file_move_t));
	p->flag = resp->flag;
	p->modid = resp->modid;
	p->src_filename = msf_cmmn_strdup(MSF_MODID_MSM, resp->src_filename);
	p->src_store = resp->src_store;	
	p->dst_filename = msf_cmmn_strdup(MSF_MODID_MSM, resp->dst_filename);
	p->dst_store = resp->dst_store;
	
	
	if(NULL == temp)
	{
		temp = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(msf_file_move_node_t));
		temp->node = p;
		temp->next = NULL;
		msf_file_move_list->head = temp;
		msf_file_move_list->tail = temp;
		msf_file_move_list->state = MSF_FILE_MOVE_AVAILABLE;
	}
	else
	{
		temp = MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(msf_file_move_node_t));
		temp->node = p;
		temp->next = NULL;

		msf_file_move_list->tail->next = temp;
		msf_file_move_list->tail = temp;		
	}
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDI_file_move_callback
 * DESCRIPTION : this is the call back used in Fs_Move API, this is called by 
 * FMT task to intimate the progress of file move task.
 *  
 * PARAMETERS
 *  action				[IN]
 *  total				[IN]        
 *  completed			[IN]         
 *  handle				[IN]          
 * RETURNS
 *  
 *****************************************************************************/

int
gmms_HDI_file_move_callback(int action, UINT total, UINT completed, UINT handle)
{
	ilm_struct *ilm_ptr = NULL;
	mmi_fmt_op_abort_processing_ind_struct *param_ptr = NULL;
	
    if (action == FS_MOVE_PGS_FAIL || (action == FS_MOVE_PGS_DONE))
    {
		ilm_ptr = allocate_ilm(MOD_FMT);
		
		param_ptr = (mmi_fmt_op_abort_processing_ind_struct*) construct_local_para(sizeof(mmi_fmt_op_abort_processing_ind_struct), TD_CTRL);
		
        param_ptr->op_type = FMT_MOVE;
        param_ptr->result = action;
		
        ilm_ptr->msg_id = MSG_ID_MMS_FMT_FILE_MOVE_PROCESSING_IND; 
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;
		
        SEND_ILM(MOD_FMT, MOD_MMS, MMI_L4C_SAP, ilm_ptr);        
    }
    else
    {
        /* send message to MMS to show progress */
    }
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDI_file_move
 * DESCRIPTION Takes care of calling Fs_move.
 *  
 * PARAMETERS       
 * RETURNS
 *  
 *****************************************************************************/

static void 
gmms_HDI_file_move(void)
{
	msf_file_move_node_t *temp = msf_file_move_list->head;
	kal_uint8 *fname_src, *fname_dst;
	MSF_UINT32 flag;
	
	fname_src = translateFileName(temp->node->src_filename, temp->node->src_store);
	if(NULL == fname_src)
	{
		gmms_HDI_send_file_move_response(FS_MOVE_PGS_FAIL);/*Write a signal to corresponding module*/
		return;
	}
	fname_dst = translateFileName(temp->node->dst_filename, temp->node->dst_store);
	if( NULL == fname_dst )
	{
		FILE_NAME_FREE(fname_src);
		gmms_HDI_send_file_move_response(FS_MOVE_PGS_FAIL);/*Write a signal to corresponding module*/
		return;
	}
	
	flag = FS_MOVE_KILL | FS_MOVE_OVERWRITE;
	
	if(temp->node->flag & HDI_FILE_MOVE_RETAIN_SOURCE)
	{
		flag &= ~FS_MOVE_KILL;
		flag |= FS_MOVE_COPY;
	}
	if(temp->node->flag & HDI_FILE_MOVE_DO_NOT_OVERWRITE_DEST)
	{
		flag &= ~FS_MOVE_OVERWRITE;
	}
	
	
	FS_Move((const WCHAR *)fname_src, (const WCHAR *)fname_dst,flag, gmms_HDI_file_move_callback, NULL, 0);
	
	
	if(NULL != fname_src)
	{
		FILE_NAME_FREE(fname_src);
	}
	if(NULL != fname_dst)
	{
		FILE_NAME_FREE(fname_dst);
	}
	
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDI_send_file_move_response
 * DESCRIPTION : This API tells the application which called for File Move about the 
 * result of this operation by writing a signal "MSF_SIG_FILE_MOVE_RESPONSE
 *  
 * PARAMETERS
 *  modId           [IN]
 *  fileHandle      [IN]        
 *  vfs_name        [?]         
 *  name_len        [IN]        
 *  offset          [IN]        
 *  len             [IN]        
 * RETURNS
 *  
 *****************************************************************************/


void 
gmms_HDI_send_file_move_response(MSF_INT32 status)
{
	msf_file_move_response_t *p;
	MSF_UINT8 dest_modid;

	ASSERT(msf_file_move_list);
	ASSERT(msf_file_move_list->head);
	ASSERT(msf_file_move_list->head->node);

	dest_modid = msf_file_move_list->head->node->modid;
	
	p = MSF_MEM_ALLOC(dest_modid, sizeof(msf_file_move_response_t))

	p->status = status;

    MSF_SIGNAL_SEND (MSF_MODID_MSM, dest_modid, MSF_SIG_FILE_MOVE_RESPONSE, p);
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDI_file_move_list_update
 * DESCRIPTION : Updates the linked list for handling file move requests after a 
 * request has been attended to.
 *  
 * PARAMETERS        
 * RETURNS
 *  
 *****************************************************************************/

void
gmms_HDI_file_move_list_update(void)
{
	msf_file_move_node_t *temp = msf_file_move_list->head;
	
	if(NULL == temp->next)
	{
		MSF_MEM_FREE(MSF_MODID_MSM, temp->node->src_filename);
		MSF_MEM_FREE(MSF_MODID_MSM, temp->node->dst_filename);
		MSF_MEM_FREE(MSF_MODID_MSM, temp->node);
		MSF_MEM_FREE(MSF_MODID_MSM, temp);
		msf_file_move_list->head = NULL;
		msf_file_move_list->tail = NULL;		
	}
	else
	{
		msf_file_move_node_t *next = temp->next;
		MSF_MEM_FREE(MSF_MODID_MSM, temp->node->src_filename);
		MSF_MEM_FREE(MSF_MODID_MSM, temp->node->dst_filename);
		MSF_MEM_FREE(MSF_MODID_MSM, temp->node);
		MSF_MEM_FREE(MSF_MODID_MSM, temp);
		msf_file_move_list->head = next;
	}
	msf_file_move_list->state = MSF_FILE_MOVE_AVAILABLE;
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDI_check_next_file_move_operation
 * DESCRIPTION : checks if anymore file move opearations are pending?
 *  
 * PARAMETERS
     
 * RETURNS
 *  
 *****************************************************************************/

void
gmms_HDI_check_next_file_move_operation(void)
{
	msf_file_move_node_t *temp = msf_file_move_list->head;

	if(NULL != temp)
	{
		gmms_HDI_file_move();
	}
}

#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */


#ifdef __USB_IN_NORMAL_MODE__
/*****************************************************************************
 * FUNCTION
 *  gmms_is_mms_storage_exported_to_pc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int gmms_is_mms_storage_exported_to_pc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //extern int mmi_usb_check_path_exported(char *path);
    
    kal_wchar mms_folder_path[10] = {0};
    int drv_letter = getDiskLabel(MMS_STORAGE_MMS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(mms_folder_path, "%c", drv_letter);
    kal_wstrcat(mms_folder_path, L"\\");

    return srv_usb_check_path_exported((WCHAR*)mms_folder_path);
}
#endif /* __USB_IN_NORMAL_MODE__ */

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  HDI_FileNameFree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fname       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_FileNameFree(kal_uint8 *fname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FILE_NAME_FREE(fname);
}

/*****************************************************************************
 * FUNCTION
 *  HDI_list_number_opened_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_list_number_opened_files()
{
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
#ifndef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
#else /* __MTK_TARGET__ */ 
/* under construction !*/
#endif /* __MTK_TARGET__ */ 
#endif
}

/*****************************************************************************
 * FUNCTION
 *  HDI_reset_number_opened_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_reset_number_opened_files()
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

#ifndef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  HDI_list_opened_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_list_opened_files(void)
{
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
#endif
}
#else /* __MTK_TARGET__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDI_list_opened_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_list_opened_files(void)
{
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
#endif        
}
#endif /* __MTK_TARGET__ */ 
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
