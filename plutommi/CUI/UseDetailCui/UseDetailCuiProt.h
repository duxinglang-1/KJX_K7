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
 *  UseDetailCuiProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Use Detail CUI internal header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef USE_DETAIL_CUI_PRORT_H
#define USE_DETAIL_CUI_PRORT_H

#include "MMI_features.h"

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMIDataType.h"
#include "UseDetailCuiGprot.h"
#include "App_usedetails.h"   /* for APPLIB_MAX_PHONE_NUM_LEN, APPLIB_MAX_USSD_LEN */
#include "customer_ps_inc.h"  /* for MMI_EMAIL_MAX_ADDR_LEN */


/****************************************************************************
 * Define
 ****************************************************************************/

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef void (*HandlePtr) (void);

/* Use detail close type enum */
typedef enum
{
    CUI_USE_DETAIL_CLOSE_TYPE_BACK,          /* The action can not be done or back from menu */
    CUI_USE_DETAIL_CLOSE_TYPE_DONE,          /* The aciton was done */
    CUI_USE_DETAIL_CLOSE_TYPE_EDIT_ABORT,    /* Exist edit screen */
    CUI_USE_DETAIL_CLOSE_TYPE_VIEW_ABORT,    /* Exist view list screen */
    CUI_USE_DETAIL_CLOSE_TYPE_NO_OPERATE,    /* No supported operate */     
    CUI_USE_DETAIL_CLOSE_TYPE_TOTAL          /* end of the enum */
}cui_use_detail_close_type_enum;


/* Use detail confirm type enum */
typedef enum
{
    CUI_USE_DETAIL_CONFIRM_TYPE_GO_TO_WAP,   /* Go to wap confirm */
    CUI_USE_DETAIL_CONFIRM_TYPE_TOTAL        /* end of the enum */
}cui_use_detail_confirm_type_enum;


/* Use detail confirm type struct */
typedef struct
{
    cui_use_detail_confirm_type_enum confirm_type;
    mmi_id parent_gid;
    U16 *url_addr;
}cui_use_detail_confirm_struct;


typedef struct
{
    cui_use_detail_basic_obj_struct *obj_list;
    cui_use_detail_mode_struct *mode_list;
    U16 *edit_buffer;
    void* parent_data;
    cui_use_detail_operate_enum exe_operate;
    U8 obj_count;
    U8 obj_index;
    MMI_BOOL view_flag;
    MMI_BOOL close_flag;
}cui_use_detail_cntx_struct;


typedef struct
{    
    U16 max_len;
    mmi_menu_id root_menu_id;    
    cui_use_detail_operate_enum total_operate;    
    MMI_BOOL filter_edit_flag;
}cui_use_detail_type_cntx_struct;


#endif /* USE_DETAIL_CUI_PRORT_H */
