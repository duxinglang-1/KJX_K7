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
 *   wap_cmn.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Common definition of wap framework adaptation for internal use
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *==============================================================================
 *******************************************************************************/
#ifndef WAP_CMN_H
#define WAP_CMN_H

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "int_exec.h"
#endif
/***************************************************************************** 
* Define
*****************************************************************************/
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
typedef enum
{
    WAP_STORAGE_SYSTEM = 0,
    WAP_STORAGE_MMS,    /* Hold MMS data */
    WAP_STORAGE_PUBLIC,  /* Default place for public data (Users can choose another partition) */
    WAP_STORAGE_EXTERNAL,
    WAP_STORAGE_VIRTUAL
} wap_storage_enum;
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

// #define DEBUG_FILE_WITH_INJECTION       /* Justin */


#define WAP_BAM_FILE_DIR "/bam"
#define WAP_MSM_FILE_DIR "/msm"
#define WAP_SEC_STORAGE_DIR "/sec/storage"

#define WAP_SEC_FILE_DIR "/sec"
#define WAP_COMMON_SETTING_FILE "/msm/registry.txt"
#define WAP_COMMON_SETTING_INITIAL_SIZE 1024
#define WAP_CRITICAL_CHKSUM_FILE "/msm/chksum1.dat"
#define WAP_SEC_CHKSUM_FILE "/msm/secchksum.dat"
#define WAP_MAX_WRITE_SIZE 512

/***************************************************************************** 
 * Extern Global Variable
 *****************************************************************************/
extern kal_uint8 wap_status;
extern kal_int32 wap_external_get_id;

/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
/* Task */
extern void wap_restart_task(void);
extern void wap_task_sleep(int milliseconds);
extern int MSF_wapIsReady(void);
extern int MSF_wapIsInit(void);

/* File API */
extern kal_uint8 *HDI_FileNameTranslate(const char *src);
extern void HDI_FileNameFree(kal_uint8 *fname);
extern int HDIa_fileGenVirtualFileName(int fileHandle, char *vfs_name, int name_len, int offset, int len);
extern int HDIa_fileCheckDirExist(const char *dirName);
extern int HDI_FileGetDiskLabel(wap_storage_enum type);
#ifdef __USB_IN_NORMAL_MODE__
extern void HDIa_fileHideDir(const char *dirName);
#endif /* __USB_IN_NORMAL_MODE__ */ 

/* Pipe */
extern int HDIa_pipeDeleteByHandle(int handle);

extern kal_uint32 msm_get_disk_free_space(kal_uint8 disk_index);
extern void msm_remove_files_under_dir(const char *folder);

extern void HDIa_socketDiscBearerById(MSF_INT32 networkAccountID);

extern kal_uint8 wap_get_sim_status(void);
extern kal_uint8 wap_get_sim_setting_mode(void);
#if 0
/* under construction !*/
/* under construction !*/
#endif

extern kal_uint8 wap_get_wap_status(void);
extern kal_uint8 wap_get_wap_action(void);
#if 0
/* under construction !*/
#endif

extern void utf8_modify_name(unsigned char *dst, unsigned char *src, int len);
extern void utf8_modify_name_backward(unsigned char *dst, unsigned char *src, int dst_len);
#if 0
/* under construction !*/
#else
extern void wap_reserve_file(const char *filename, kal_uint16 filesize);
#endif
extern void wap_delete_all_files(void);
extern kal_uint16 wap_utf8_to_ucs2(kal_uint16 srcLen, kal_uint8 *srcStr, char **dstStr);
extern kal_uint16 wap_ucs2_to_utf8(kal_uint16 srcLen, kal_uint8 *srcStr, char **dstStr);
extern BOOL wap_is_ascii_string(const kal_uint8 *str);


#endif /* WAP_CMN_H */





