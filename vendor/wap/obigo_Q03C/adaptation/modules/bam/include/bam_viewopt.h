#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_viewopt.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains code to handle the viewport options.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_viewopt.h
 *
 * Description:
 *              This file contains code to handle the viewport options.
 *
 */

#ifndef _bam_viewopt_h

#define _bam_viewopt_h

#include "msf_core.h"
#include "msf_int.h"
#include "bam_cfg.h"

/************************************************************
 * Constatns
 ************************************************************/
/* bam_viewopt_nav_t */
#define BAM_VIEWOPT_NAV_STOP     0x01
#define BAM_VIEWOPT_NAV_BACK     0x02
#define BAM_VIEWOPT_NAV_FORWARD  0x04
#define BAM_VIEWOPT_NAV_ALL      0xff

/************************************************************
 * Type definitions
 ************************************************************/

typedef unsigned bam_viewopt_nav_t;

/************************************************************
 * Functions
 ************************************************************/
extern void bam_viewopt_init(void);

extern void bam_viewopt_start(MsfWindowHandle window);

extern void bam_viewopt_remove_commands(MsfWindowHandle window);

extern void bam_viewopt_set_resp_funcs(void);

extern void bam_viewopt_nav_enable(bam_viewopt_nav_t navigation);

extern void bam_viewopt_nav_disable(bam_viewopt_nav_t navigation);

extern void bam_viewopt_nav_commit(void);

extern MSF_BOOL bam_viewopt_handle_widget_notify(msf_widget_notify_t *notification);

extern void bam_viewopt_win_in_focus(void);

#ifdef BAM_CFG_STREAMING_TV
extern void bam_viewopt_stv_show(void);

extern void bam_viewopt_stv_hide(void);

#endif /* BAM_CFG_STREAMING_TV */ 

#endif /* _bam_viewopt_h */ 


#endif /*OBIGO_Q03C_BROWSER*/
