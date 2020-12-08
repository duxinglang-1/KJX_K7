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
 *  ui_buffer.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __UI_BUFFER_H__
#define __UI_BUFFER_H__

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define UI_BUFFER_MODE_FLAG_NONE 0

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* ui buffer id enum (MODIFIABLE) */
typedef enum
{
    UI_BUFFER_ID_GDI_MBL,       // GDI main base layer
    UI_BUFFER_ID_GDI_SBL,       // GDI 
#ifndef __MMI_REDUCED_UI_BUFFER__
    UI_BUFFER_ID_VRT_CACHE,     // VRT
    UI_BUFFER_ID_GUI_SSE_BUF_B, // SSE buf B
    UI_BUFFER_ID_GUI_SSE_BUF_A, // SSE buf A
#endif /* __MMI_REDUCED_UI_BUFFER__ */
    UI_BUFFER_ID_NUM,
    UI_BUFFER_ID_INVALID
} ui_buffer_id_enum;

/* ui buffer mode enum */
typedef enum
{
    UI_BUFFER_MODE_DEFAULT,
    UI_BUFFER_MODE_VENUS,
    UI_BUFFER_MODE_NUM,
    UI_BUFFER_MODE_INVALID
} ui_buffer_mode_enum;

typedef enum
{
    UI_BUFFER_RET_SUCCESS,
    UI_BUFFER_RET_FAILURE,
    UI_BUFFER_RET_END_OF_ENUM
} ui_buffer_ret_enum;

typedef ui_buffer_ret_enum (*ui_buffer_callback_func_ptr)(ui_buffer_mode_enum new_mode, ui_buffer_mode_enum old_mode, kal_uint32 flag);

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void *ui_buffer_get_start_addr(ui_buffer_id_enum id);
extern kal_uint32 ui_buffer_get_size(ui_buffer_id_enum id);
extern kal_uint32 ui_buffer_get_block_size(ui_buffer_id_enum id);

extern kal_uint32 ui_buffer_get_block_size_by_addr(void *mem_p);
extern ui_buffer_id_enum ui_buffer_get_id_by_addr(void *mem_p);

extern ui_buffer_mode_enum ui_buffer_get_mode(void);
extern ui_buffer_mode_enum ui_buffer_set_mode(ui_buffer_mode_enum mode);
extern void ui_buffer_register_mode_callback(ui_buffer_id_enum id, ui_buffer_callback_func_ptr func_ptr);

/* debug usage */
extern void ui_buffer_print_debug_info(void);

#ifdef __cplusplus
}
#endif

#endif /* __UI_BUFFER_H__ */

