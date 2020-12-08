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
 *   bam_do_elem.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains code for presenting WML do-elements.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_do_elem.c
 *
 * Description:
 *              This file contains code for presenting WML do-elements.
 */

#include "bam_do_elem.h"

#include "bam_cmn.h"
#include "bam_msg.h"
#include "bam_sif.h"
#include "bam_win.h"

#include "brs_if.h"

#include "msf_core.h"
#include "msf_lib.h"

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
/************************************************************
 * Global Variables
 ************************************************************/

static brs_do_elements_t *bam_do_elem_elements;

/************************************************************
 * Functions declarations
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  bam_do_elem_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_do_elem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_do_elem_elements = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  bam_do_elem_terminate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_do_elem_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_do_elem_remove();
}

/**********************************
 * Handle do elements
 **********************************/


/*****************************************************************************
 * FUNCTION
 *  bam_do_elem_add
 * DESCRIPTION
 *
 * PARAMETERS
 *  p       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_do_elem_add(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_do_elem_elements != NULL)
    {
        //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_DO_ELEMENTS, bam_do_elem_elements);
		if(bam_do_elem_elements->elements)
		{
		    BAM_FREE(bam_do_elem_elements->elements->label);
                    BAM_FREE(bam_do_elem_elements->elements->eventType);
	            BAM_FREE(bam_do_elem_elements->elements);
		}
	    BAM_FREE(bam_do_elem_elements);
    }

    bam_do_elem_elements = (brs_do_elements_t*) p;
    if((bam_do_elem_elements != NULL) && (bam_do_elem_elements->numElements != 0))
        bam_msg_do_elements_ind(bam_sif_get_brs_id(), bam_do_elem_elements);
}


/*****************************************************************************
 * FUNCTION
 *  bam_do_elem_remove
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_do_elem_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_do_elem_elements == NULL)
    {
        return;
    }

    //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BRS_SIG_DO_ELEMENTS, bam_do_elem_elements);
	if(bam_do_elem_elements->elements)
	{
	BAM_FREE(bam_do_elem_elements->elements->label);
    BAM_FREE(bam_do_elem_elements->elements->eventType);
	BAM_FREE(bam_do_elem_elements->elements);
	}
	BAM_FREE(bam_do_elem_elements);

    bam_do_elem_elements = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  bam_do_elem_exists
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
MSF_BOOL bam_do_elem_exists(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_do_elem_elements ? TRUE : FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_do_elem_activate
 * DESCRIPTION
 *
 * PARAMETERS
 *  elemt_id        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_do_elem_activate(MSF_INT32 elemt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif
    BRSif_activateDoElement(MSF_MODID_BAM, bam_sif_get_brs_id(), elemt_id);
}
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */

#endif /*OBIGO_Q03C_BROWSER*/
