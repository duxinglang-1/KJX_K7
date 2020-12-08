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
 * 
 *
 * Project:
 * --------
 * MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MRE_OPTIONS_H_
#define MRE_OPTIONS_H_

#ifdef __cplusplus 
extern "C" {
#endif
#include "vmsys.h"
#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#ifndef MRE_DUAL_SIM
	#define MRE_DUAL_SIM
#endif
#endif

#define MRE_BUILDIN_APP_COUNT 					(25)//(10)
#define MRE_BUILDIN_VSM_COUNT 					(5)
#define MRE_BUILDIN_VSO_COUNT 					(1)


#ifdef WIN32
#define MRE_ON_MODIS
#endif


#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
#ifndef MRE_SUPPORT_CAMERA_FEATURE
#define MRE_SUPPORT_CAMERA_FEATURE
#endif
#endif


#define MRE_SUPPORT_INTEGRATE_EXTERNAL_SENSOR

#if defined (__MRE_CUST_MEM_SIZE__) 
#define MRE_SYS_MEMPOOL_SIZE (__MRE_CUST_MEM_SIZE__ << 10)
#else
#define MRE_SYS_MEMPOOL_SIZE (MRE_SYS_MEMORY_SIZE << 10)
#endif

/*
* maxium number of application of MRE support
*/
#define MRE_SUPPORT_MAX_APP_NUM         (10)

/*
* maxium number of vsm/vso of MRE support
*/
#define MRE_SUPPORT_MAX_VSM_NUM         (10)


#ifndef __MRE_AM__
#define MMI_AM_MAX_DYN_MEM_SIZE 			(0)
#endif

#if defined(__MMI_MRE_DISABLE_FMGR__)
#define MRE_30_KERNEL_MEM_SIZE					(32)
#else
#define MRE_30_KERNEL_MEM_SIZE					(55 << 10)
#endif

#ifdef __MRE_MEDIA_BUF__
#error please remove __MRE_MEDIA_BUF__ compile option
#endif

//#ifdef __MRE_MEDIA_BUF__
//#define MRE_SYS_ASM_CORE_MEMPOOL_SIZE			(MRE_30_KERNEL_MEM_SIZE + MMI_AM_MAX_DYN_MEM_SIZE)
//#define MRE_SYS_ASM_APP_MEMPOOL_SIZE			(0)
//#define MRE_SYS_MED_MEMPOOL_SIZE			(MRE_SYS_MEMPOOL_SIZE )
//#else
#define MRE_SYS_ASM_CORE_MEMPOOL_SIZE			(MRE_30_KERNEL_MEM_SIZE)
#define MRE_SYS_ASM_APP_MEMPOOL_SIZE			(MRE_SYS_MEMPOOL_SIZE )
//#define MRE_SYS_MED_MEMPOOL_SIZE			(0)
//#endif

#if defined (__MRE_BGMEM_SIZE__) 
#define MRE_SYS_BGMEM_SIZE (__MRE_BGMEM_SIZE__ << 10)
#else
#define MRE_SYS_BGMEM_SIZE (-1)
#endif

//#if MRE_SYS_BGMEM_SIZE >= (MRE_SYS_ASM_APP_MEMPOOL_SIZE)
//#error MRE background memory is bigger than total memory size, please re-configure it
//#endif

/*
  * engine version number.
  */
#define MRE_SYS_MRESION_NUMBER							"3.0.75"

/*
 * max file handle supported
 */
#define MRE_SUPPORT_FILE_HANDLE_MAX_NUM					(12)

/*
 * max socket context supported
 */
#define MRE_SUPPORT_TCP_CONTEXT_MAX_NUM					(3)



/*
 * character width padding.  
 */
#define MRE_CHAR_H_PADDING								(0)

/*
 * character heigth padding
 */
#define MRE_CHAR_V_PADDING								(0)

/*
  * print system memory status on screen
  */
//#define VM_OUTPUT_MEM_STATE	

/**
 * support screen group
 */
#define MRE_SUPPORT_SCREEN_GROUP_FRAMEWOK

void vm_open_mre_exec_file_callback(const VMWSTR path, VMINT is_short);

/**
 * memory card plug out handler
 */
void mmi_mre_card_plug_out_hdlr(void);

/**
 * permit to format disk or not before format disk
 */
VMINT  mmi_mre_pre_format_hdlr(VMINT8 drv);

#define MRE_UNUSED_PARAMETER(x)  (void)(x)

#ifdef __cplusplus
}
#endif

#endif
