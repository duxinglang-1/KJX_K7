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
 * vmua.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * ua
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "vmswitch.h"
#include "lcd_sw_inc.h"


#include "MMIDataType.h"
#include "string.h"
#include "vmsys.h"
#include "vmua.h"
#include "verno.h"
#include "med_mem.h"
#include "vmopt.h"
#include "DevConfigDef.h"
#include "DevConfigGprot.h"
#include "AMGprot.h"

extern VMCHAR* release_verno(void);
extern VMCHAR* build_date_time(void); 
extern VMCHAR* release_branch(void);
extern VMCHAR* customer_name(void);
extern VMCHAR* origin_release_verno(void);

#ifdef __MRE_CORE_SAFETY__

VMUINT vm_get_useragent(VMCHAR* value, VMUINT len)
{
	VMUINT length = 0;
	length = strlen(MRE_SYS_USER_AGENT);
	if (length >= len)
		length = len - 1;
	strncpy(value, MRE_SYS_USER_AGENT, length);
	value[length] = '\0';

	return length;
}

#endif

VMUINT vm_get_host_version(VMCHAR* value, VMUINT len)
{
	_snprintf(value,len,"MRE_VER_%d;%dX%d;%s;%s",MRE_VERSION,LCD_WIDTH,LCD_HEIGHT,PLATFORM,release_verno());
	return strlen(value);
}

VMUINT vm_get_build_date_time(VMCHAR* value, VMUINT len) 
{
	_snprintf(value,len,"%s",build_date_time());
   return strlen(value);
} 

VMUINT vm_get_release_branch(VMCHAR* value, VMUINT len) 
{
	_snprintf(value,len,"%s",release_branch());
   return strlen(value);
} 

VMUINT vm_get_customer_name(VMCHAR *value, VMUINT len)
{
	_snprintf(value, len, "%s", customer_name());
	return strlen(value);
}

VMUINT vm_get_origin_release_verno(VMCHAR *value, VMUINT len)
{
	_snprintf(value, len, "%s", origin_release_verno());
	return strlen(value);
}
