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
 *   bam_cmn.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains code for common functionlity
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_cmn.h
 *
 * Description:
 *              This file contains code for common functionlity
 *
 */

#ifndef _bam_cmn_h

#define _bam_cmn_h

#include "bam_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_mem.h"

/******************************************************************************
 * Definitions
 *****************************************************************************/

/* Memory macros used in the BAM module */
#define BAM_ALLOC(s)      MSF_MEM_ALLOC(MSF_MODID_BAM, s)
#define BAM_ALLOCTYPE(t)  MSF_MEM_ALLOCTYPE(MSF_MODID_BAM, t)
#define BAM_CALLOC(n, s)  MSF_MEM_CALLOC(MSF_MODID_BAM, n, s)
#define BAM_REALLOC(p, s) MSF_MEM_REALLOC(MSF_MODID_BAM, p, s)
#define BAM_FREE(p)       if(p!=NULL) MSF_MEM_FREE(MSF_MODID_BAM, p)
#define	BAM_STRCONV(a)    MSF_WIDGET_STRING_CREATE(MSF_MODID_BAM, a, MsfUtf8, strlen(a)+1, 0)

#define BAM_CFG_MENU_POS {0,0}

#define BAM_REG_KEY_RESUME_URL  "resume_url"
#define BAM_REG_KEY_SIM_ID  "sim_id"

/******************************************************************************
 * Helper Macros
 *****************************************************************************/

/* This macro converts a null pointer to const string "". HNV = Handle Null Value */
#define BAM_CMN_HNV(p) ((p != NULL) ? p : "")

/* macro to remove warnings */
#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)    \
        /* lint -e527 -e530 */       \
        {                            \
            (P) = (P);               \
        }                            \
        /* lint +e527 +e530 */
#endif /* UNREFERENCED_PARAMETER */ 

/******************************************************************************
 * Functions
 *****************************************************************************/

/*
 * Initialize current address and homepage.
 *
 * PARAMETERS
 *
 *
 * RETURN    : void
 */

extern void bam_cmn_init(void);

/*
 * This function create and initializes a MSF Screen, which the BAM uses to
 * display menus and content.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
extern void bam_widget_create_screen(void);

extern long int bam_cmn_new_handle(void);

extern char *bam_cmn_remove_trailing_space(const char *str);

/*
 * Treat the input parameter "data" as an array of bits, most significant
 * bit first, and set the indicated bit range to the given value. "numbits"
 * must not be larger than 32.  The value must fit in that number of bits.
 */
extern void bam_cmn_set_bits(MSF_INT8 *data, MSF_UINT32 numbits, MSF_UINT32 value);

/*
 * Treat the input parameter "data" as an array of bits, most significant
 * bit first, and return the indicated bit range as an integer. "numbits"
 * must not be larger than 32.
 */
extern MSF_UINT32 bam_cmn_get_bits(MSF_INT8 *data, MSF_INT32 numbits);

extern MSF_UINT8 bam_cmn_get_address(const char *s, unsigned char *addr);

extern void bam_cmn_hold_bearer(MSF_INT32 net_acc_id);

extern void bam_cmn_release_bearer(MSF_INT32 net_acc_id);

#endif /* _bam_cmn_h */ 


#endif /*OBIGO_Q03C_BROWSER*/
