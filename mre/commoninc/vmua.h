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
 * vmua.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * ua
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VMUA_H_

#define VMUA_H_

#include "vmswitch.h"
#include "vmsys.h"



#ifdef __cplusplus
extern "C" {
#endif

#if defined(__MMI_MAINLCD_480X320__)
#if defined(__MMI_TOUCH_SCREEN__)
#define MRE_SYS_USER_AGENT	"WW_00_480x320_TS_EN"
#else
#define MRE_SYS_USER_AGENT	"WW_00_480x320_KEY_EN"
#endif
#elif defined(__MMI_MAINLCD_400X240__)
#if defined(__MMI_TOUCH_SCREEN__)
#define MRE_SYS_USER_AGENT	"WW_00_400X240_TS_EN"
#else
#define MRE_SYS_USER_AGENT	"WW_00_400X240_KEY_EN"
#endif
#elif defined(__MMI_MAINLCD_320X480__)
#if defined(__MMI_TOUCH_SCREEN__)
#define MRE_SYS_USER_AGENT	"WW_00_320X480_TS_EN"
#else
#define MRE_SYS_USER_AGENT	"WW_00_320X480_KEY_EN"
#endif
#elif defined(__MMI_MAINLCD_240X400__)
#if defined(__MMI_TOUCH_SCREEN__)
#define MRE_SYS_USER_AGENT	"WW_00_240X400_TS_EN"
#else
#define MRE_SYS_USER_AGENT	"WW_00_240X400_KEY_EN"
#endif
#elif defined(__MMI_MAINLCD_240X320__)
#if defined(__MMI_TOUCH_SCREEN__)
#define MRE_SYS_USER_AGENT	"WW_00_240X320_TS_EN"
#else
#define MRE_SYS_USER_AGENT	"WW_00_240X320_KEY_EN"
#endif
#elif defined(__MMI_MAINLCD_176X220__)
#if defined(__MMI_TOUCH_SCREEN__)
#define MRE_SYS_USER_AGENT	"WW_00_176X220_TS_EN"
#else
#define MRE_SYS_USER_AGENT	"WW_00_176X220_KEY_EN"
#endif
#else
#if defined(__MMI_TOUCH_SCREEN__)
#define MRE_SYS_USER_AGENT	"WW_00_176X220_TS_EN"
#else
#define MRE_SYS_USER_AGENT	"WW_00_176X220_KEY_EN"
#endif
#endif 

#ifdef __MRE_CORE_SAFETY__

/*
 * MREÏµÍ³µÄUSER AGENT¡£
 */

VMUINT vm_get_useragent(VMCHAR* value, VMUINT len);

#endif

VMUINT vm_get_host_version(VMCHAR* value, VMUINT len);

VMUINT vm_get_build_date_time(VMCHAR* value, VMUINT len);

VMUINT vm_get_release_branch(VMCHAR* value, VMUINT len);

#ifdef __cplusplus
}
#endif 

#endif
