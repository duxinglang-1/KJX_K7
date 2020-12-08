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
 * 程序资源管理工具。MRE应用程序的资源根据执行文件格式不同而存放在不同的位置，对于
 * ELF格式的可执行文件，资源（如图像、声音）存放在一个特定的SECTION内（.vmres）。
 * 对于PE格式的WIN32执行文件，资源文件被打包在执行文件的尾部。打包器的实现细节由
 * 系统实现，应用侧只需要调用相应接口函数就可以完成资源打包和读出任务。
 *
 * WIN32 PE格式文件打包格式：
 *
 *   +-----------------------------+
 *   | PE Executable File(.exe)    |
 *   +-----------------------------+
 *   | MRE Resource Section.       |
 *   +-----------------------------+
 *   | Resource Head.              |
 *   +-----------------------------+
 *
 *   Resource Head是一个结构体，定长，每个成员变量都是4字节对齐。
 *     struct vm_pe_res_head_t {
 *         char sign[6];		// "VMRES\xF9"
 *         int  offset;			// 插入的资源块在文件中的偏移量——从头开始，字节单位。
 *         int  size;           // 插入的资源块大小，字节单位。
 *         char reserved[8];	// 保留字段，全部填0。
 *     };
 *
 * ARM ELF格式文件打包格式：
 *
 *   +-----------------------------+
 *   | ELF Executable File(.axf)   |
 *   +-----------------------------+
 *   | MRE Resource Section.       |
 *   | Inserted as .VM_RES         |
 *   +-----------------------------+
 *
 *   在ELF格式中资源以section的形式插入文件，因此不需要附加的资源头。
 *
 * 资源区不区分平台都是一个格式：
 *
 *   +-----------------------------+
 *   | Resource Descriptor Array   |
 *   +-----------------------------+
 *   | Resource Body.              |
 *   +-----------------------------+
 *
 *   Resource descriptor array是一个结构数组，成员变量都是4字节对齐。
 *     struct _vm_res_desc_t {
 *         char* name;			// 资源名称。
 *         int   offset;        // 资源从文件头开始的偏移量，字节单位。
 *         int   size;          // 资源大小，字节单位。
 *     };
 *     数组以一个size等于0的结构体结束，也就是说resource descriptor array
 *     的个数总比资源文件个数大一。
 *
 * $Author: guangyu.tang $
 * $Date: 2009/03/06 01:38:48 $
 *
 ****************************************************************************/

#ifndef VMRES_H
#define VMRES_H

#include "vmswitch.h"

#ifdef __MRE_LIB_APPRES__

#include "vmres_sdk.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 * 把资源写入可执行文件中，目前系统可以识别的文件后缀名有.axf(ELF)、.exe(WIN32 PE)。
 * 
 * @param filename		要写入资源的可执行文件名，必须是完整路径。
 * @param res_fns		要打包的资源文件名列表，必须是完整路径。
 * @param fn_count		资源文件的数量。
 *
 * @return				返回0表示打包成功，否则返回错误码。
 */
VMINT vm_pack_resource(VMWSTR filename, VMWSTR *res_fns, VMINT fn_count);

VMINT vm_get_res_header(void);	

#ifdef __cplusplus
}
#endif


#endif /* __MRE_LIB_APPRES__ */

#endif /* VMRES_H */
