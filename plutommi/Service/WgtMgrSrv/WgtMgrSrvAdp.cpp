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
 * WgtMgrSrvAdp.cpp
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
#ifdef __GADGET_SUPPORT__
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "WgtMgrSrv.h"

#ifdef __PLUTO_MMI_PACKAGE__
extern "C"
{
#include "DataAccountGProt.h"
}
#endif

#ifdef __COSMOS_MMI_PACKAGE__
#include "vfx_cpp_base.h"
#include "vapp_dtcnt_gprot.h"
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_dtcnt_ready_check
 * DESCRIPTION
 *  This function is to check if data account is ready
 * PARAMETERS
 *  ready_callback:  [IN] callback function
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_dtcnt_ready_check(FuncPtr ready_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PLUTO_MMI_PACKAGE__
    return mmi_dtcnt_ready_check(ready_callback, MMI_FALSE);
#endif

#ifdef __COSMOS_MMI_PACKAGE__
    return vapp_dtcnt_ready_check(ready_callback, MMI_FALSE);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_dtcnt_acct_is_valid
 * DESCRIPTION
 *  This function is to check if a id is valid
 * PARAMETERS
 *  id:  [IN] data account id 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_dtcnt_acct_is_valid(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PLUTO_MMI_PACKAGE__
    if (mmi_dtcnt_acct_is_valid(id) == MMI_DTCNT_ACCT_VALID_NONE)
    {
        return MMI_FALSE;
    }
#endif

#ifdef __COSMOS_MMI_PACKAGE__
    if (vapp_dtcnt_acct_is_valid(id, MMI_FALSE) == DTCNT_ACCT_VALID_NONE)
    {
        return MMI_FALSE;
    }
#endif
    return MMI_TRUE; 
}


#endif /* __GADGET_SUPPORT__ */

