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
 * Vmsalmms.c
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
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "vmswitch.h"
#ifdef __MRE_SAL_MMS__

#include "vmlog.h"
//#include "vmopt.h"
//#include "vmsim.h"
//#include "vmstdlib.h"
//#include "vmsalmms.h"
#include "vmmacrostub.h"

#include "vmmms.h"
#include "vmsys.h"
#include "DevConfigGprot.h"
#include "devconfiggprot.h"

/* ------------------------------------------------------------------------ */
/* internal variable                                                                             */
/* ------------------------------------------------------------------------ */

vm_mms_callback_type  vm_sal_mms_user_callback = NULL;


VMINT s_vm_sal_mms_sendstate = FALSE;


VMUINT s_vm_sal_sim_id;

VMINT s_vm_sal_send_mms_cancel = FALSE;
VMINT s_vm_sal_create_mms_success = FALSE;
VMUINT s_vm_sal_cur_mms_msg_id;

/* ------------------------------------------------------------------------ */
/* internal functions                                                                              */
/* ------------------------------------------------------------------------ */
static VMINT vm_sal_mms_is_valid(void);


static VMINT vm_sal_mms_is_valid(void)
{
	return (VMINT)sysconf.newwork_protocol.mms_support;
}
void vm_sal_mms_modual_initialize(void)
{
	vm_sal_mms_user_callback = NULL;
	s_vm_sal_send_mms_cancel = FALSE;
	s_vm_sal_create_mms_success = FALSE;
}

void vm_sal_mms_modual_finialize(void)
{
    vm_sal_mms_user_callback = NULL;
    s_vm_sal_mms_sendstate = FALSE;
    s_vm_sal_send_mms_cancel = FALSE;
    s_vm_sal_create_mms_success = FALSE;
}


VMINT vm_sal_mms_send_mms(vm_send_mms_req_t * req_ptr,  vm_mms_callback_type callback)
{ 
	VMINT res = -1;

	vm_log_debug("vm_sal_mms_send_mms:start!");
	if(vm_sal_mms_is_valid())
	{
		vm_log_debug("vm_sal_mms_send_mms:valid = %d",vm_sal_mms_is_valid());
		if(req_ptr == NULL)
		{
			vm_log_error("vm_sal_mms_send_mms:req_ptr == NULL");
			return VM_MMS_FAIL;
		}

		if(s_vm_sal_mms_sendstate)
		{
			vm_log_error("vm_sal_mms_send_mms:mms_state == 1");
			return VM_MMS_FAIL;
		}
     
		vm_sal_mms_user_callback = callback;
		s_vm_sal_mms_sendstate = TRUE;
		s_vm_sal_send_mms_cancel = FALSE;
       	s_vm_sal_sim_id = req_ptr->sim_id;

		vm_log_debug("vm_sal_mms_send_mms:create req");
		res = vm_sal_mms_create_req( req_ptr);
	}
	vm_log_debug("vm_sal_mms_send_mms:end!");
    return res;
}

void vm_sal_mms_cancel_send_mms(void)
{
	vm_sal_stub_mms_cancel_send_mms();
}

#endif //__MRE_SAL_MMS__

