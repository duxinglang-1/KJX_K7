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
 *  DialerCuiFactory.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the dialer factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef DIALER_CUI_FACTORY_H
#define DIALER_CUI_FACTORY_H

/****************************************************************************
 * Define
 ****************************************************************************/
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "DialerCuiObject.h"
#include "DialerCuiGprot.h"
/* auto add by kw_check end */

/* Max number of the dialer object. */
#define CUI_DIALER_MAX_OBJ_NUM              (2)


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef MMI_BOOL (*cui_dialer_on_want_to_run_cb)(void);

typedef void (*cui_dialer_on_init_cb)(cui_dialer_obj_struct *obj);


typedef struct
{
    U16                             type;
    U16                             size;
    cui_dialer_on_want_to_run_cb    on_want_to_run;
    cui_dialer_on_init_cb           on_init;
} cui_dialer_cfg_struct;


#define CUI_DIALER_CFG_ADD(_type, _size, _on_want_to_run, _on_init) \
    {_type, _size, _on_want_to_run, _on_init}

#define CUI_DIALER_CFG_END()                                                    \
    CUI_DIALER_CFG_ADD(CUI_DIALER_TYPE_INVALID, 0, NULL, NULL)


/****************************************************************************
 * Function
 ****************************************************************************/

extern cui_dialer_type_enum cui_dialer_get_favorite_type(void);


extern cui_dialer_obj_struct *cui_dialer_new_obj(void);


extern cui_dialer_obj_struct *cui_dialer_new_obj_ex(cui_dialer_type_enum type);

extern void cui_dialer_dereg_obj(cui_dialer_obj_struct * obj);

extern cui_dialer_obj_struct *cui_dialer_get_obj_in_active_serial(void);


extern cui_dialer_obj_struct *cui_dialer_get_obj_in_history(void);


extern void cui_dialer_factory_init(void);


#endif /* DIALER_CUI_FACTORY_H */

