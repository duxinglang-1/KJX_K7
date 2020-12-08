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
 *  SSCSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains external prototypes for phb service layer.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SSCGPROT_H
#define SSCGPROT_H

#include "MMIDataType.h"

/* auto add by kw_check begin */
#include "kal_general_types.h"
/* auto add by kw_check end */

#ifdef __cplusplus
extern "C"
{
#endif

#define MAX_SSC_STRING  30 * ENCODING_LENGTH    /* it means the maximun can not be more than 60/2(UCS2) word */

#define MEM_CTRL_BUF_DBG    "*035670766*001*"
#define MEM_CTRL_BUF_QRY    "*#035670766*001#"

#define TASK_CTRL_BUF_DBG    "*035670766*002*"
#define TASK_CTRL_BUF_QRY    "*#035670766*002#"

#define VFX_HEAP_PROFILE_DISABLE    "*#28987#0#"
#define VFX_HEAP_PROFILE_ENABLE     "*#28987#1#"
#define VFX_HEAP_PROFILE_ENABLE_CFG1 "*#28987#1#AppId#"  /**#26987#1#<5 code app_id>#<4 code threadhold size(KB)>*/
#define VFX_HEAP_PROFILE_ENABLE_CFG2 "*#28987#1#AppId#Size#" /**#26987#1#<5 code app_id>#<4 code threadhold size(KB)>#*/


typedef U8(*SSCFuncPtr) (void); 

typedef struct sscstringtblstruct
{
    const CHAR *ssc_string;
    const U8 ssc_disable_ctrl;
    FuncPtr func_ptr;
} SSCSTRINGTBL;

typedef struct simstringtblstruct
{
    const CHAR *sim_string;
    CHAR sim_length;
    SSCFuncPtr func_ptr;
} SIMSTRINGTBL;

/*
 * Strcutrue created to craete the common function for handling all
 * the SSc strings of languages.
 */ 
typedef struct sscstringtblstructEx
{
    const CHAR *ssc_string;
    const U8 ssc_disable_ctrl;
    S32 error_string;   /* Error String for SSC handling */
    S32 success_string; /* Success string for SSC handling */
} SSCStringTableEx;


extern MMI_BOOL mmi_ssc_phone_string_pass(WCHAR *str);
extern MMI_BOOL mmi_ssc_lauguage_string_pass(WCHAR *str);
extern MMI_BOOL mmi_ssc_sim_string_pass(WCHAR *str);

#ifdef __COSMOS_MMI_PACKAGE__
extern MMI_BOOL mmi_ssc_phone_string_pass_ex(WCHAR *str, void* scr);
extern MMI_BOOL mmi_ssc_lauguage_string_pass_ex(WCHAR *str, void* scr);
extern MMI_BOOL mmi_ssc_sim_string_pass_ex(WCHAR *str, void* scr);
#endif

#ifdef __cplusplus
}
#endif

#endif /* SSCGPROT_H */


