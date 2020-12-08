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
 *  Vapp_rmgr_cntx.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Header file for Vapp_rmgr_cntx
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_include.h"
#include "MMI_features.h"
#include "Vfx_datatype.h"

#ifdef __MMI_RMGR__

void set_licence_count(U16 count);
U16 get_licence_count(void);
void set_rmgr_list_index(U32 itemIndex);
int get_rmgr_list_index();
void set_fmgr_result(U32 result);
int get_fmgr_result();
void set_rmgr_drm_result(S32 result);
int get_rmgr_drm_result();
U16 get_rmgr_str_id();
void set_rmgr_str_id(U16 str);
void set_rmgr_detail_buffer(U8 * i);
U8* get_rmgr_detail_buffer();
S8 *mmi_vfx_rmgr_ucs2cat_secure(S8 *strDestination, const S8 *strSource, S32 destSize);
kal_wchar* get_detail_item_name();
void set_detail_item_name(kal_wchar* name);
U32 get_rmgr_list_index_longtap();
void set_rmgr_list_index_longtap(U32 itemIndex);
U8 vapp_get_rmgr_spc();
void vapp_set_rmgr_spc(U8 i);
void vapp_rmgr_set_del_item(U16 k);
U16 vapp_rmgr_get_del_item();
void vapp_rmgr_set_is_dl_popup(S32 index);
S32 vapp_rmgr_get_is_dl_popup();


#if defined(__MMI_MAINLCD_320X480__)
   #define VAPP_RMGR_POS_TITLE_X 10
   #define VAPP_RMGR_POS_TITLE_Y 10
   #define VAPP_RMGR_FORM_SIZE_X 320
   #define VAPP_RMGR_FORM_SIZE_Y 480
#elif defined(__MMI_MAINLCD_480X800__)
  #define VAPP_RMGR_POS_TITLE_X 15
  #define VAPP_RMGR_POS_TITLE_Y 17
  #define VAPP_RMGR_FORM_SIZE_X 480
  #define VAPP_RMGR_FORM_SIZE_Y 800
#else
   #define VAPP_RMGR_POS_TITLE_X 10
   #define VAPP_RMGR_POS_TITLE_Y 10
   #define VAPP_RMGR_FORM_SIZE_X 320
   #define VAPP_RMGR_FORM_SIZE_Y 480
#endif



#endif /*__MMI_RMGR__*/
