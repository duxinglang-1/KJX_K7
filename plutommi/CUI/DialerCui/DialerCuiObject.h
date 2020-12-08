/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerCuiObject.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the dialer object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef DIALER_CUI_OBJECT_H
#define DIALER_CUI_OBJECT_H

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "DialerCuiGprot.h"
#include "custom_phb_config.h"
/* auto add by kw_check end */

/****************************************************************************
 * Typedef
 ****************************************************************************/

struct cui_dialer_obj_st;

typedef mmi_id (*cui_dialer_on_create_cb)(
    struct cui_dialer_obj_st *obj,
    mmi_id parent_gid);

typedef void (*cui_dialer_on_close_cb)(
    struct cui_dialer_obj_st *obj);

typedef void (*cui_dialer_on_run_cb)(
    struct cui_dialer_obj_st *obj);

typedef void (*cui_dialer_on_first_input)(
    struct cui_dialer_obj_st *obj);

typedef void (*cui_dialer_on_set_handler)(
    struct cui_dialer_obj_st *obj);

typedef void (*cui_dialer_set_dial_string_cb)(
    struct cui_dialer_obj_st *obj,
    const WCHAR *string);

typedef void (*cui_dialer_set_key_cb)(
    struct cui_dialer_obj_st *obj,
    U16 key_code);

typedef void (*cui_dialer_set_translate_key_cb)(
    struct cui_dialer_obj_st *obj,
    S16 key_code,
    S16 key_type,
    U16 ucs2_value,
    U32 key_flag);

typedef const WCHAR *(*cui_dialer_get_dial_string_cb)(
    struct cui_dialer_obj_st *obj);

typedef void (*cui_dialer_set_phb_data_cb)(
    struct cui_dialer_obj_st *obj,
    void *phb_data);

typedef void *(*cui_dialer_get_phb_data_cb)(
    struct cui_dialer_obj_st *obj);

typedef void (*cui_dialer_set_launch_cb)(
    struct cui_dialer_obj_st *obj,
    MMI_BOOL value);

typedef enum
{
    CUI_DIALER_FIRST_INPUT_DIGITAL_KEY,
    CUI_DIALER_FIRST_INPUT_QWERTY_KEY,
    CUI_DIALER_FIRST_INPUT_END_OF_ENUM,
    CUI_DIALER_FIRST_INPUT_INVALID
} cui_dialer_first_input_enum;

typedef struct
{
    MMI_BOOL enable_lsk;
    MMI_BOOL enable_csk;
    MMI_BOOL enable_send;
    MMI_BOOL enable_abbrev_dial;
    MMI_BOOL enable_ip_dial;
    MMI_BOOL enable_toggle_profile;
    MMI_BOOL enable_speed_dial;
    MMI_BOOL enable_baidu_search;
#ifdef __OP01_FWPBW__
    MMI_BOOL enable_direct_dial;
#endif
} cui_dialer_capability_struct;


/****************************************************************************
 * Object Definition
 ****************************************************************************/

#define CUI_DIALER_OBJ_FIELD_MEMBER_VARIABLE                                  \
    cui_dialer_type_enum            type;                                     \
    mmi_id                          parent_gid;                               \
    mmi_id                          this_gid;                                 \
    cui_dialer_first_input_enum     first_input_source;                       \
    U16                             key_code;                                 \
    U16                             key_type;                                 \
    U16                             ucs2_value;                               \
    U32                             key_flag;                                 \
    cui_dialer_capability_struct    capability;                               \
    void                           *phb_data;                                 \
    WCHAR                           dial_string[CUI_DIALER_MAX_DIAL_BUF_SIZE];\
    MMI_BOOL                        launch_by_calllog;                        \
    MMI_BOOL                        dial_string_change


#define CUI_DIALER_OBJ_FIELD_MEMBER_FUNCTION                                  \
    cui_dialer_on_create_cb         on_create;                                \
    cui_dialer_on_close_cb          on_close;                                 \
    cui_dialer_on_run_cb            on_run;                                   \
    cui_dialer_set_dial_string_cb   on_set_dial_string;                       \
    cui_dialer_set_key_cb           on_set_key;                               \
    cui_dialer_set_translate_key_cb on_set_translate_key;                     \
    cui_dialer_get_dial_string_cb   on_get_dial_string;                       \
    cui_dialer_set_phb_data_cb      on_set_phb_data;                          \
    cui_dialer_get_phb_data_cb      on_get_phb_data;                          \
    cui_dialer_set_launch_cb        on_set_launch

#define CUI_DIALER_OBJ_FIELD                                                  \
    CUI_DIALER_OBJ_FIELD_MEMBER_VARIABLE;                                     \
    CUI_DIALER_OBJ_FIELD_MEMBER_FUNCTION

typedef struct cui_dialer_obj_st
{
    CUI_DIALER_OBJ_FIELD;
} cui_dialer_obj_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

extern mmi_ret cui_dialer_obj_evt_hdlr(mmi_event_struct *event);


extern mmi_id cui_dialer_obj_on_create(
    cui_dialer_obj_struct *obj,
    mmi_id parent_gid);


extern void cui_dialer_obj_on_close(cui_dialer_obj_struct *obj);


extern void cui_dialer_obj_on_set_dial_string(
    cui_dialer_obj_struct *obj,
    const WCHAR *string);


extern void cui_dialer_obj_on_set_key(cui_dialer_obj_struct *obj, U16 key_code);


extern void cui_dialer_obj_on_set_translate_key(
    cui_dialer_obj_struct *obj,
    S16 key_code,
    S16 key_type,
    U16 ucs2_value,
    U32 key_flag);


extern const WCHAR *cui_dialer_obj_on_get_dial_string(
    cui_dialer_obj_struct *obj);


extern void cui_dialer_obj_on_set_phb_data(
    cui_dialer_obj_struct *obj,
    void *phb_data);


extern void *cui_dialer_obj_on_get_phb_data(cui_dialer_obj_struct *obj);


extern MMI_BOOL cui_dialer_obj_on_want_to_run(void);


extern void cui_dialer_obj_on_init(cui_dialer_obj_struct *obj);


extern void cui_dialer_obj_on_deinit(cui_dialer_obj_struct *obj);


#endif /* DIALER_CUI_OBJECT_H */

