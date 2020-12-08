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
 *  FileMgrSrvIProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager Service internal APIs (used by File manager Application).
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef SRV_FMGR_IPROT_H
#define SRV_FMGR_IPROT_H

#include "FileMgrSrvGProt.h"

#include "MMIDataType.h"
#include "kal_general_types.h"

/* DOM-NOT_FOR_SDK-BEGIN */

/* Type of drive list (Internal use) */
typedef enum
{
    SRV_FMGR_DRIVELIST_ITYPE_BEGIN = SRV_FMGR_DRIVELIST_TYPE_TOTAL,
        
    SRV_FMGR_DRIVELIST_ITYPE_FMGR,  /* for FMGR App use, include only accessible drives */

    SRV_FMGR_DRIVELIST_ITYPE_END,

    SRV_FMGR_DRIVELIST_ITYPE_FLAG_2ND_CARD = 0x80, /* with 2nd card */
    
    SRV_FMGR_DRIVELIST_ITYPE_FLAG_MASK = 0x7F

} srv_fmgr_drivelist_internal_type_enum;

typedef enum
{
    EVT_ID_SRV_FMGRI_BASE = EVT_ID_SRV_FMGR_NOTIFICATION_END,
    
    EVT_ID_SRV_FMGRI_CARD_PLUG_IN,
    EVT_ID_SRV_FMGRI_CARD_PLUG_OUT,
    EVT_ID_SRV_FMGRI_CARD_DISPLAY_MOUNTING,

    EVT_ID_SRV_FMGRI_END

} srv_fmgri_internel_event_enum;

S32         srv_fmgr_async_format(U8 drv, S32 flag, 
                                mmi_proc_func user_proc, void* user_data);
S32         srv_fmgr_async_checkdrive(U8 drv, S32 flag, 
                                mmi_proc_func user_proc, void* user_data);

S32         srv_fmgr_fs_soft_unmount(U8 drv_letter);
S32         srv_fmgr_fs_soft_mount(U8 drv_letter);

void        srv_fmgr_prepare_option_menu(mmi_menu_id option_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);

#if defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
U8          srv_fmgr_default_storage_need_confirm(void);
void        srv_fmgr_default_storage_do_confirm(void);
#endif

typedef void (*srv_fmgr_option_handler_funcptr)(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);

void        srv_fmgr_set_option_handler(srv_fmgr_option_handler_funcptr handler, srv_fmgr_option_handler_funcptr enabler);


/* DOM-NOT_FOR_SDK-END */

#endif /* SRV_FMGR_IPROT_H */
