/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_cal_utility.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
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

#include "mmi_features.h"

extern "C"
{
	#include "mmi_frm_scenario_gprot.h"
	#include "filemgrsrvgprot.h"
	#include "usbsrvgprot.h"
	#include "notificationgprot.h"
}

#include "mmi_rp_srv_reminder_def.h"
#include "mmi_rp_vapp_calendar_def.h"

#include "vcp_global_popup.h"

#include "vapp_cal_gprot.h"
#include "vapp_nmgr_gprot.h"
#include "vapp_usb_gprot.h"


#include "vapp_cal_edit.h"
#include "vapp_cal_prot.h"
#include "vapp_cal_utility.h"
#include "vapp_cal_view_detail_ext.h"
#ifndef __MMI_VCALENDAR__
#pragma arm section code = "DYNAMIC_CODE_CLNDR_ROCODE", rodata = "DYNAMIC_CODE_CLNDR_RODATA"
#endif
const VfxU8 VappCalUtility::s_lunarTermTable[62][24] = 
{
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},       /* 1970 */
    {6, 21, 4, 19, 6, 21, 5, 21, 6, 22, 6, 22, 8, 23, 8, 24, 8, 24, 9, 24, 8, 23, 8, 22},
    {6, 21, 5, 19, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 21, 6, 22, 6, 22, 8, 23, 8, 24, 8, 24, 9, 24, 8, 23, 8, 22},       /* 1975 */
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 5, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 23, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 21, 6, 22, 6, 22, 8, 23, 8, 24, 8, 23, 9, 24, 8, 23, 8, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},       /* 1980 */
    {5, 20, 4, 19, 5, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 8, 23, 8, 24, 8, 23, 9, 24, 8, 23, 8, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 19, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},       /* 1985 */
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 8, 23, 8, 24, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},       /* 1990 */
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},       /* 1995 */
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},       /* 2000 */
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},       /* 2005 */
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},       /* 2010 */
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 20, 5, 21, 7, 22, 7, 23, 7, 22, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 5, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},       /* 2015 */
    {6, 20, 4, 19, 5, 20, 4, 19, 5, 20, 5, 21, 7, 22, 7, 23, 7, 22, 8, 23, 7, 22, 6, 21},
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 5, 20, 4, 19, 5, 20, 5, 21, 7, 22, 7, 23, 7, 22, 8, 23, 7, 22, 6, 21},       /* 2020 */
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 5, 20, 4, 19, 5, 20, 5, 21, 6, 22, 7, 23, 7, 22, 8, 23, 7, 22, 6, 21},
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},       /* 2025 */
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 5, 20, 4, 19, 5, 20, 5, 21, 6, 22, 7, 22, 7, 22, 8, 23, 7, 22, 6, 21},
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},       /* 2030 */
};

const VfxU8 VappCalUtility::s_leapMonth[62][12] = 
{
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1970 */
    {0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0},       /* 1971 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1972 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1973 */
    {0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1974 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1975 */
    {0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0},       /* 1976 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1977 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1978 */
    {0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0},       /* 1979 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1980 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1981 */
    {0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1982 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1983 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0},       /* 1984 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1985 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1986 */
    {0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0},       /* 1987 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1988 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1989 */
    {0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0},       /* 1990 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1991 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1992 */
    {0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1993 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1994 */
    {0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0},       /* 1995 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1996 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1997 */
    {0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0},       /* 1998 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 1999 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2000 */
    {0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2001 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2002 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2003 */
    {0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2004 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2005 */
    {0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0},       /* 2006 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2007 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2008 */
    {0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0},       /* 2009 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2010 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2011 */
    {0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2012 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2013 */
    {0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0},       /* 2014 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2015 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2016 */
    {0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0},       /* 2017 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2018 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2019 */
    {0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2020 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2021 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2022 */
    {0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2023 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2024 */
    {0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0},       /* 2025 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2026 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2027 */
    {0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0},       /* 2028 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2029 */
    {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},       /* 2030 */
};

/* array of lunar calendar */
const VappCalLunarTableStruct VappCalUtility::s_calLunarInfo[] = 
{
    {47, 2, 11, 0, 5482},
    {36, 3, 16, 0, 2921},   /* 1970 */
    {26, 4, 21, 5, 5970},
    {45, 5, 26, 0, 6994},
    {33, 0, 32, 0, 6949},
    {22, 1, 37, 4, 5707},
    {41, 2, 42, 0, 6731},   /* 1975 */
    {30, 3, 47, 8, 5291},
    {48, 5, 53, 0, 4781},
    {37, 6, 58, 0, 5485},
    {27, 0, 3, 	6, 2921},
    {46, 1, 8, 	0, 3497},    /* 1980 */
    {35, 3, 14, 0, 7570},
    {24, 4, 19, 4, 7461},
    {43, 5, 24, 0, 7461},
    {32, 6, 29, 10, 6733},
    {50, 1, 35, 0, 2646},   /* 1985 */
    {39, 2, 40, 0, 4790},
    {28, 3, 45, 6, 1461},
    {47, 4, 50, 0, 5845},
    {36, 6, 56, 0, 3753},
    {26, 0, 1, 	5, 7826},    /* 1990 */
    {45, 1, 6, 	0, 3730},
    {34, 2, 11, 0, 3366},
    {22, 4, 17, 3, 2646},
    {40, 5, 22, 0, 2647},
    {30, 6, 27, 8, 5334},   /* 1995 */
    {49, 0, 32, 0, 4954},
    {37, 2, 38, 0, 5845},
    {27, 3, 43, 5, 5833},
    {46, 4, 48, 0, 5961},
    {35, 5, 53, 0, 5779},   /* 2000 */
    {23, 0, 59, 4, 5419},
    {42, 1, 4, 	0, 5419},
    {31, 2, 9, 	0, 2651},
    {21, 3, 14, 2, 5466},
    {39, 5, 20, 0, 5482},   /* 2005 */
    {28, 6, 25, 7, 6997},
    {48, 0, 30, 0, 7076},
    {37, 1, 35, 0, 6985},
    {25, 3, 41, 5, 6803},
    {44, 4, 46, 0, 6805},   /* 2010 */
    {33, 5, 51, 0, 5421},
    {22, 6, 56, 4, 2733},
    {40, 1, 2, 	0, 2741},
    {30, 2, 7, 	9, 5546},
    {49, 3, 12, 0, 5586},   /* 2015 */
    {38, 4, 17, 0, 3493},
    {27, 6, 23, 6, 7498},
    {46, 0, 28, 0, 3402},
    {35, 1, 33, 0, 3221},
    {24, 2, 38, 4, 5422},   /* 2020 */
    {42, 4, 44, 0, 5462},
    {31, 5, 49, 0, 2741},
    {21, 6, 54, 2, 5554},
    {40, 0, 59, 0, 5842},
    {28, 2, 5, 	6, 3749},    /* 2025 */
    {47, 3, 10, 0, 5925},
    {36, 4, 15, 0, 5707},
    {25, 5, 20, 5, 3223},
    {43, 0, 26, 0, 3243},
    {33, 1, 31, 0, 1370},   /* 2030 */
    {22, 2, 36, 3, 2774},
};

/* number of accumulated days per solar month, non-leap year and leap year. */
const VfxU16 VappCalUtility::s_calAccuDays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, 396};

const VfxU8 VappCalUtility::s_daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const VfxU8 VappCalUtility::s_calWeek[] = 
{
    0x01,   /* DAY_SUN */
    0x02,   /* DAY_MON */
    0x04,   /* DAY_TUE */
    0x08,   /* DAY_WED */
    0x10,   /* DAY_THU */
    0x20,   /* DAY_FRI */
    0x40    /* DAY_SAT */
};


VfxS32 VappCalUtility::tempId = 0;


VfxBool VappCalUtility::dateTimeIsOutOfBounder(VfxU16 year, VfxU16 category)
{
    VfxU16 minYear;
    if (category == VAPP_CAL_CATEGORY_SPECIALDAY || 
    category == VAPP_CAL_CATEGORY_BIRTHDAY)
    {
        minYear = VAPP_CAL_MIN_BIR_YEAR;
    }
    else
    {
        minYear = VAPP_CAL_MIN_YEAR;
    }

    if (year <= VAPP_CAL_MAX_YEAR && year >= minYear) 
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

void VappCalUtility::getListItemDateTimeStr(
                                    VfxU16 fieldType, 
                                    srv_tdl_vcal_enum type,
                                    const void* dataPtr,
                                    VfxWString &subBuf)
{
    VfxDateTime dateTime;
    VfxWString tempBuf;
    if (type == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_short_struct* pEvent = (srv_tdl_event_short_struct*)dataPtr;
        applib_time_struct *sTime = (applib_time_struct*)&(pEvent->start_time);
        applib_time_struct *eTime = (applib_time_struct*)&(pEvent->end_time);

        if (sTime->nYear == eTime->nYear &&
            sTime->nMonth == eTime->nMonth &&
            sTime->nDay == eTime->nDay)
        {
            // year.mon.day
            if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
            {
                dateTime.setDate(sTime->nYear, sTime->nMonth, sTime->nDay);
                subBuf = dateTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
            }
            // 0xFFFF is for reminder popup time data string
            // hour:min - hour:min
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1 || fieldType == 0xFFFF)
            {
                VfxU32 flags;
                flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;

                dateTime.setTime(sTime->nHour, sTime->nMin, sTime->nSec);
                dateTime.getDateTimeString(flags);
                tempBuf += dateTime.getDateTimeString(flags);
                tempBuf += VfxWString(VFX_WSTR(" - "));
                dateTime.setTime(eTime->nHour, eTime->nMin, eTime->nSec);
                dateTime.getDateTimeString(flags);
                tempBuf += dateTime.getDateTimeString(flags);

                subBuf = tempBuf;
            }
        }
        else
        {
            VfxU32 flags;
            flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
            // year.mon.day hour:min - year.mon.day hour:min
            if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                dateTime.setDate(sTime->nYear, sTime->nMonth, sTime->nDay);
                tempBuf = dateTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
                tempBuf += VfxWString(VFX_WSTR(" "));
            }
            if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1 || fieldType == 0xFFFF)
            {
                // hour:min - year.mon.day hour:min
                // for reminder popup time data string
                dateTime.setTime(sTime->nHour, sTime->nMin, sTime->nSec);
                tempBuf += dateTime.getDateTimeString(flags);

                tempBuf += VfxWString(VFX_WSTR(" - "));

                dateTime.setDate(eTime->nYear, eTime->nMonth, eTime->nDay);
                tempBuf += dateTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
                tempBuf += VfxWString(VFX_WSTR(" "));
                dateTime.setTime(eTime->nHour, eTime->nMin, eTime->nSec);
                tempBuf += dateTime.getDateTimeString(flags);
                subBuf = tempBuf;
            }
            
        }
    }
    
#ifdef __MMI_TASK_APP__
    else if (type == SRV_TDL_VCAL_TASK)
    {
        srv_tdl_task_struct* pTask = (srv_tdl_task_struct*)dataPtr;
        applib_time_struct *dTime = (applib_time_struct*)&(pTask->due_time);

        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            // year.mon.day hour:min
            VfxU32 flags;
            flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;

            dateTime.setDate(dTime->nYear, dTime->nMonth, dTime->nDay);
            tempBuf = dateTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
            tempBuf += VfxWString(VFX_WSTR(" "));
            dateTime.setTime(dTime->nHour, dTime->nMin, dTime->nSec);
            tempBuf += dateTime.getDateTimeString(flags);
            subBuf = tempBuf;
        }
        else if (fieldType == 0xFFFF)
        {
            // for reminder popup time data string
            // hour:min
            VfxU32 flags;
            flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;

            dateTime.setTime(dTime->nHour, dTime->nMin, dTime->nSec);
            tempBuf += dateTime.getDateTimeString(flags);
            subBuf = tempBuf;
        }

    }
#endif
    else
    {
        return;
    }
}




applib_time_struct VappCalUtility::getLunarDateBySolarDate(applib_time_struct& solarDate, VfxU16& lunar_days, VfxU8& leap_day)
{
   
    VfxU16 start_month;
    VfxU16 year_index;
    VfxU16 accumulate_day;
   
    VfxU16 date_diff;
    VfxU16 intercalary_month;
   
    VfxU16 month_index;
    applib_time_struct lunarDate;

    /* to check if the month out of boundary */
    start_month = solarDate.nMonth - 1;

    /* to calculate the number of days in Feb. this year */
    if (start_month > 1)
    {
        leap_day = (U8) IsLeapYear(solarDate.nYear);
    }
    else
    {
        leap_day = 0;
    }

    year_index = solarDate.nYear - VAPP_CAL_TABLE_START_YEAR;
    MMI_ASSERT(year_index < 63);
    
    /* to calculate weekday */
    accumulate_day = (s_calAccuDays[start_month] + leap_day + solarDate.nDay);

   

    /* to check if today is earlier than the Chinese New Year day of this year */
    if (solarDate.nMonth == 1 || 
        (solarDate.nMonth == 2 && solarDate.nDay < 29))
    {
        leap_day = 0;
    }

    if (accumulate_day <= s_calLunarInfo[year_index].BaseDays)
    {
        year_index--;
        lunarDate.nYear = solarDate.nYear - 1;
        
        start_month += 12;
        leap_day = (U8) IsLeapYear(lunarDate.nYear);
        accumulate_day = (s_calAccuDays[start_month] + leap_day + solarDate.nDay);
    }
    else
    {
        lunarDate.nYear = solarDate.nYear;
    }

    /* to calculate the lunar month and day */
    intercalary_month = s_calLunarInfo[year_index].Intercalary;
    date_diff = s_calLunarInfo[year_index].BaseDays;
    for (month_index = 0; month_index < 13; month_index++)
    {
        lunar_days = date_diff + 29;
        if (s_calLunarInfo[year_index].MonthDays & (0x01 << month_index))
        {
            lunar_days++;
        }

        if (accumulate_day <= lunar_days)
        {
            break;
        }

        date_diff = lunar_days;
    }

    lunarDate.nMonth = (month_index + 1);
    lunarDate.nDay = accumulate_day - date_diff;

    /* to adjust Lunar month if there is a intercalary month in this year */
    if (intercalary_month != 0 && lunarDate.nMonth > intercalary_month)
    {
        lunarDate.nMonth--;
    }

    if (lunarDate.nMonth > 12)
    {
        lunarDate.nMonth -= 12;
    }
     return lunarDate;

}





void VappCalUtility::getLunarStringByDate(applib_time_struct solarDate, VfxWString &lunarStr)
{
    VfxU16 lunar_days;
    VfxU8 leap_day;
    applib_time_struct lunarDate = getLunarDateBySolarDate(solarDate,lunar_days,leap_day);

    #ifndef __MMI_CAL_SLIM__
    /* to calculate the Kan and Chin of this year */
    VfxU8 kanYear, chiYear;
    if (lunarDate.nYear == solarDate.nYear)
    {
        kanYear = (solarDate.nYear - 1864) % 10;
        chiYear = (solarDate.nYear -1864) % 12;    
    }
    else
    {
        kanYear = (solarDate.nYear -1865) % 10;
        chiYear = (solarDate.nYear - 1865) % 12;
     
    }
    #endif  
    /* to calculate the lunar day of solar term in this month */
    VfxU8 solar_date1 
            = s_lunarTermTable[solarDate.nYear - 1970][(solarDate.nMonth - 1) * 2];

    VfxU8 solar_date2 
            = s_lunarTermTable[solarDate.nYear - 1970][(solarDate.nMonth - 1) * 2 + 1];

    VfxU8 solar_date3;
    if (solarDate.nMonth < 12)
    {
        solar_date3 = s_lunarTermTable[solarDate.nYear - 1970][(solarDate.nMonth - 1) * 2 + 2];
    }
    else
    {
        solar_date3 = s_lunarTermTable[solarDate.nYear + 1 - 1970][0];
    }

    VfxU8 lunarTerm, lunarTermDate;
    if (solarDate.nDay < solar_date1)
    {
        lunarTerm = 0;
        lunarTermDate = solar_date1 - solarDate.nDay + lunarDate.nDay;
    }
    else if (solarDate.nDay == solar_date1)
    {
        lunarTerm = 0;
        lunarTermDate = 0;
    }
    else if (solarDate.nDay < solar_date2)
    {
        lunarTerm = 1;
        lunarTermDate = solar_date2 - solarDate.nDay + lunarDate.nDay;
    }
    else if (solarDate.nDay == solar_date2)
    {
        lunarTerm = 1;
        lunarTermDate = 0;
    }
    else
    {
        lunarTerm = 2;
        if (solarDate.nMonth == 2)
        {
            if (solarDate.nMonth + 1 == 1 || 
                (solarDate.nMonth + 1 == 2 && solar_date3 < 29))
            {
                leap_day = 0;
            }
            else
            {
                leap_day = (U8) IsLeapYear(solarDate.nYear);
            }
            lunarTermDate = 
                s_daysInMonth[solarDate.nMonth - 1] - solarDate.nDay + solar_date3 + lunarDate.nDay + leap_day;
        }
        else
        {
            lunarTermDate = 
                s_daysInMonth[solarDate.nMonth - 1] - solarDate.nDay + solar_date3 + lunarDate.nDay;
        }
    }

    //get year_index
    VfxU16 year_index = solarDate.nYear - VAPP_CAL_TABLE_START_YEAR;
    MMI_ASSERT(year_index < 63);
    if(lunarDate.nYear == solarDate.nYear - 1)
    {
        year_index--;

    }

        //get month year
    VfxU16 month_index = lunarDate.nMonth - 1;
    if (s_calLunarInfo[year_index].MonthDays & (0x01 << month_index))
    {
        lunar_days = 30;
    }
    else
    {
        lunar_days = 29;
    }

    if (lunarTermDate > lunar_days)
    {
        lunarTermDate -= lunar_days;
    }

   

    VfxWString tempStr;

    /* Lunar Term */
    if (lunarTermDate == 0)
    {
        lunarStr.loadFromRes(STR_ID_VAPP_CAL_SOLARTERM1 + (solarDate.nMonth - 1) * 2 + lunarTerm);
        lunarStr += VfxWString(VFX_WSTR("."));
    }
    #ifndef __MMI_CAL_SLIM__
    tempStr.loadFromRes(STR_ID_VAPP_CAL_KAN1 + kanYear);
    lunarStr += tempStr;
    tempStr.loadFromRes(STR_ID_VAPP_CAL_CHI1 + chiYear);
    lunarStr += tempStr;
    lunarStr += VfxWString(VFX_WSTR("."));
    #endif  /*__MMI_CAL_SLIM__*/

    if (s_leapMonth[solarDate.nYear - 1970][lunarDate.nMonth - 1])
    {
        applib_time_struct decrement,Result,lastLunarDate;
        memset(&decrement,0,sizeof(applib_time_struct));
        decrement.nDay = lunarDate.nDay ;	
        DecrementTime(solarDate,decrement,&Result);
        VfxU16 lastLunar_days;
        VfxU8  lastLeap_day;
        lastLunarDate = getLunarDateBySolarDate(Result,lastLunar_days,lastLeap_day);
        if(s_leapMonth[solarDate.nYear - 1970][lastLunarDate.nMonth - 1])
        {
            tempStr.loadFromRes(STR_ID_VAPP_CAL_LEAP);
            lunarStr += tempStr;
        }
    }
         
    if (lunarDate.nMonth < 10)
    {
        tempStr.loadFromRes(STR_ID_VAPP_CAL_CHINESE_NO1 + lunarDate.nMonth - 1);
        lunarStr += tempStr;
    }
    else
    {
        tempStr.loadFromRes(STR_ID_VAPP_CAL_CHINESE_NO10);
        lunarStr += tempStr;

        if (lunarDate.nMonth > 10)
        {
            tempStr.loadFromRes((STR_ID_VAPP_CAL_CHINESE_NO1 + (lunarDate.nMonth % 10 - 1)));
            lunarStr += tempStr;
        }
    }

    tempStr.loadFromRes(STR_ID_VAPP_CAL_MONTH);
    lunarStr += tempStr;
    lunarStr += VfxWString(VFX_WSTR("."));

    if (lunarDate.nDay < 10)
    {
        tempStr.loadFromRes(STR_ID_VAPP_CAL_CHINESE_CHU);
        lunarStr += tempStr;
        tempStr.loadFromRes((STR_ID_VAPP_CAL_CHINESE_NO1 + lunarDate.nDay - 1));
        lunarStr += tempStr;
    }
    else if (lunarDate.nDay < 20)
    {
        tempStr.loadFromRes(STR_ID_VAPP_CAL_CHINESE_NO10);
        lunarStr += tempStr;

        if (lunarDate.nDay > 10)
        {
            tempStr.loadFromRes((STR_ID_VAPP_CAL_CHINESE_NO1 + lunarDate.nDay % 10 - 1));
            lunarStr += tempStr;
        }
    }
    else if (lunarDate.nDay < 30)
    {
        tempStr.loadFromRes(STR_ID_VAPP_CAL_CHINESE_NO20);
        lunarStr += tempStr;

        if (lunarDate.nDay > 20)
        {
            tempStr.loadFromRes(STR_ID_VAPP_CAL_CHINESE_NO1 + lunarDate.nDay % 10 - 1);
            lunarStr += tempStr;
        }
    }
    else
    {
        tempStr.loadFromRes(STR_ID_VAPP_CAL_CHINESE_NO30);
        lunarStr += tempStr;

        if (lunarDate.nDay > 30)
        {
            tempStr.loadFromRes(STR_ID_VAPP_CAL_CHINESE_NO1 + lunarDate.nDay % 10 - 1);
            lunarStr += tempStr;
        }
    }
}
#ifdef __MMI_VCALENDAR__ 

VfxS32 VappCalUtility::createFolderIfNotExist(VfxWChar* path)
{
    FS_HANDLE fh;
    S32 result = FS_NO_ERROR;

    fh = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);

    // Folder Exists 
    if (fh > 0)
    {
        FS_Close(fh);
        return result;
    }

    /* Folder Does Not Exist */
    result = FS_CreateDir(path);

    // result may be error, should check by caller 
    MMI_TRACE(CALENDAR_TRC_GROUP, VAPP_CAL_CREATE_FOLDER_RESULT, result);
    return result;
}



VfxWChar* VappCalUtility::buildTempVcalFile(VfxWChar* path, void *data, srv_tdl_vcal_enum type, VAPP_CAL_BUILD_FOLDER_TYPE folderType)
{
#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* Todo: Usd defined value SRV_USB_ERROR_UNAVAILABLE to get error string id then popup */
        vapp_usb_unavailable_popup(0);	
        return NULL;
    }
#endif

    if (folderType == VAPP_CAL_BUILD_FOLDER_RECEIVED)
    {
        kal_wsprintf(path, "%c:\\%s\\", VAPP_CAL_TEMP_DRV, VAPP_CAL_TEMP_FOLDER_PATH);
    }
    else 
    {
        kal_wsprintf(path, "%c:\\%s\\", VAPP_CAL_TEMP_DRV, VAPP_CAL_TEMP_FOLDER_FOR_UC);
    }

    VfxS32 result = createFolderIfNotExist(path);

    if (result != FS_NO_ERROR)
    {
        mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (const WCHAR *)GetString(srv_fmgr_fs_error_get_string(result)));

        return NULL;
    }

    if (folderType == VAPP_CAL_BUILD_FOLDER_FOR_UC)
    {
        FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }

    // subject length + the length of .vcs
    VfxWChar *tempName;
    VFX_SYS_ALLOC_MEM(tempName, (VAPP_CAL_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH + 10);

    if (type == SRV_TDL_VCAL_EVENT)
    {
        vfx_sys_wcscpy(tempName, (VfxWChar*)(((srv_tdl_event_struct*)data)->subject));
    }
    else
    {
        vfx_sys_wcscpy(tempName, (VfxWChar*)(((srv_tdl_task_struct*)data)->subject));
    }

    VfxWChar *newTemp = srv_fmgr_path_skip_leading_space(tempName);

    if (vfx_sys_wcslen(newTemp) == 0)
    {
        mmi_ucs2cat((VfxChar*)newTemp, (VfxChar*)((VFX_WSTR_RES(STR_ID_VAPP_CAL_NO_CONTENT)).getBuf()));
    }

    mmi_ucs2cat((VfxChar*)newTemp, (VfxChar*)VAPP_CAL_TEMP_FILE_EXT);

    VfxU32 oriLen = vfx_sys_wcslen(path);

    mmi_ucs2cat((VfxChar*)path, (VfxChar*)newTemp);    

    if (!srv_fmgr_path_is_filename_valid(path))
    {
        path[oriLen] = 0;
        path[oriLen + 1] = 0;
        mmi_ucs2cat((VfxChar*)path, (VfxChar*)L"~vcalendar");
        mmi_ucs2cat((VfxChar*)path, (VfxChar*)VAPP_CAL_TEMP_FILE_EXT);
    }

    VFX_FREE_MEM(tempName);

    srv_vcal_build_struct *handle;

    handle = (srv_vcal_build_struct*)srv_vcal_build_begin(path, SRV_VCAL_VER_VCAL_1_0);
    result = srv_vcal_build_add(handle, data, (srv_vcal_type_enum)type);            
    result = srv_vcal_build_end(handle);
    
    if (result != SRV_VCAL_RESULT_SUCCESS)
    {
        FS_Delete(path);

        mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (const WCHAR *)GetString(srv_fmgr_fs_error_get_string(result)));

        return NULL;        
    }

    return path;
}
#endif  /*__MMI_VCALENDAR__*/



VfxU16 VappCalUtility::getListIdx(srv_tdl_event_task_struct *list, VfxU16 listLength, VfxU16 storeIdx)
{
    for (VfxU32 i = 0; i < listLength; i++)
    {
        if (list[i].index == storeIdx)
        {
            return i;
        }
    }
    return listLength;
}


VfxBool VappCalUtility::isValidAlarm(void *data, srv_tdl_vcal_enum vcalType)
{
    if (vcalType == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_struct *evt = (srv_tdl_event_struct *)data;

        VAPP_CAL_CATEGORY_ENUM cat = VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)evt->category);
        if ((cat == VAPP_CAL_CATEGORY_SPECIALDAY) ||(cat == VAPP_CAL_CATEGORY_BIRTHDAY))
        {
            if (evt->alarm.type != VAPP_CAL_REMINDER_NEVER &&
                evt->alarm.type != VAPP_CAL_REMINDER_1DAY_EARLIER &&
                evt->alarm.type != VAPP_CAL_REMINDER_3DAYS_EARLIER &&
                evt->alarm.type != VAPP_CAL_REMINDER_1WEEK_EARLIER)
            {
                return VFX_FALSE;
            }
        }
    }

    return VFX_TRUE;
}

void VappCalUtility::getSnsDataError()
{
    if(tempId != 0)
    {
        tempId =  vapp_nmgr_global_popup_show_confirm_one_button_id(
                                        MMI_SCENARIO_ID_DEFAULT,
                                        VCP_POPUP_TYPE_FAILURE,
                                        STR_ID_VAPP_CAL_MEM_FULL,
                                        STR_GLOBAL_OK,
                                        VCP_POPUP_BUTTON_TYPE_NORMAL,
                                        VappCalUtility::ClosePopup,
                                        NULL);
    }
}


void VappCalUtility::ClosePopup(VfxId id, void *userData)
{
    tempId = 0;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_sync_vevent
 * DESCRIPTION
 *  Synchronize the calendar data
 * PARAMETERS
 *  action        [IN]            sync type
 *  path          [IN/OUT]     file path of sync data
 *  index         [IN/OUT]     index of todolist
 * RETURNS
 *  U16  error code
 *****************************************************************************/
#ifdef __MMI_VCALENDAR__
VappCalSyncErrorEnum VappCalSync(srv_vcal_type_enum type, VappCalSyncOpEnum action, VfxU8 *path, VfxU16 *index, mmi_chset_enum sync_chset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 result = VAPP_CAL_SYNCML_ERR_NO_ERROR;
    VfxU16 bufSize;
    void *pData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == SRV_VCAL_VEVENT)
    {
        bufSize = sizeof(srv_tdl_event_struct);
    }
    else if (type == SRV_VCAL_VTODO)
    {
        bufSize = sizeof(srv_tdl_task_struct);
    }
    else
    {
        return VAPP_CAL_SYNCML_ERR_INVALID_INDEX;
    }

    VFX_SYS_ALLOC_MEM(pData, bufSize);


    /* transfer error code */
    switch(action)
    {           
        case VAPP_CAL_SYNCML_ADD:
        {
            srv_vcal_parse_struct *handle;
            srv_vcal_type_enum vcal_type;
            void *pobject;
            VfxU8 flag_finish;
            VfxU16 t;

            handle = (srv_vcal_parse_struct*) srv_vcal_parse_begin((U16*)path, sync_chset);
            result = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (VfxU8*)&flag_finish);
            if (vcal_type != type)
            {
                result = VAPP_CAL_SYNCML_ERR_UNSUPPORT_FORMAT;
            }
            else
            {
                memcpy(pData, pobject, bufSize);
            }
            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);
            if (result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = VAPP_CAL_SYNCML_ERR_UNKNOWN;
                break;
            }

            // need adjust the data;
            VappCalViewDetailFromExtPage::adjustDataValidation(pData, (srv_tdl_vcal_enum)vcal_type);

            result = srv_tdl_add(pData, (srv_tdl_vcal_enum)type, &t);
                            
            if (result == SRV_TDL_RESULT_OK)
            {
                *index = t;
                result = VAPP_CAL_SYNCML_ERR_NO_ERROR;
            }
            else if (result == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
            {
                result = VAPP_CAL_SYNCML_ERR_MEMORY_FULL;
            }
            else
            {
                result = VAPP_CAL_SYNCML_ERR_UNKNOWN;
            }
            break;
        }
        case VAPP_CAL_SYNCML_MODIFY:
        {
            srv_vcal_parse_struct *handle;
            void *pobject;
            srv_vcal_type_enum vcal_type;
            U8 flag_finish;
            
            handle = (srv_vcal_parse_struct*)srv_vcal_parse_begin((U16*)path, (mmi_chset_enum)sync_chset);
            result = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (U8*)&flag_finish);
            if (vcal_type != type)
            {
                result = VAPP_CAL_SYNCML_ERR_UNSUPPORT_FORMAT;
            }
            else
            {
                memcpy(pData, pobject, bufSize);
            }

            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);

            if (result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = VAPP_CAL_SYNCML_ERR_UNSUPPORT_FORMAT;
                break;
            }
            if (*index > VAPP_CAL_MAX_COUNT)
            {
                result = VAPP_CAL_SYNCML_ERR_INVALID_INDEX;
                break;
            }

            VappCalViewDetailFromExtPage::adjustDataValidation(pData, (srv_tdl_vcal_enum)vcal_type);

            result = srv_tdl_update(pData, (srv_tdl_vcal_enum)type, *index);

            if (result == SRV_TDL_RESULT_OK)
            {
                result = VAPP_CAL_SYNCML_ERR_NO_ERROR;
            }
            else
            {
                result = VAPP_CAL_SYNCML_ERR_UNKNOWN;
            }
            break;
        }
        case VAPP_CAL_SYNCML_DELETE:
        {
            if (*index >= VAPP_CAL_MAX_COUNT)
            {
                result = VAPP_CAL_SYNCML_ERR_INVALID_INDEX;
                break;
            }

            result = srv_tdl_delete(*index, (srv_tdl_vcal_enum)type);

            if (result == SRV_TDL_RESULT_OK)
            {
                result = VAPP_CAL_SYNCML_ERR_NO_ERROR;
            }
            else
            {
                result = VAPP_CAL_SYNCML_ERR_UNKNOWN;
            }
            break;
        } 
        case VAPP_CAL_SYNCML_GET:
        {
            srv_vcal_build_struct *handle;
            
            if (*index >= VAPP_CAL_MAX_COUNT)
            {
                result = VAPP_CAL_SYNCML_ERR_INVALID_INDEX;
                break;
            }

            result = srv_tdl_get(pData, bufSize, (srv_tdl_vcal_enum)type, *index);

            if (result != SRV_TDL_RESULT_OK)
            {
                result = VAPP_CAL_SYNCML_ERR_UNKNOWN;
                break;
            }

            handle = (srv_vcal_build_struct*)srv_vcal_build_begin((U16*)path, SRV_VCAL_VER_VCAL_1_0);
            result = (S32)srv_vcal_build_add(handle, pData, type);
            srv_vcal_build_end(handle);

            if (result != SRV_VCAL_RESULT_SUCCESS)
            {
                result = VAPP_CAL_SYNCML_ERR_UNKNOWN;
            }

            break;
        }
        default:
            result =  VAPP_CAL_SYNCML_ERR_INVALID_OPERATION;
            break;

    }

    VFX_SYS_FREE_MEM(pData);

    MMI_TRACE(CALENDAR_TRC_GROUP, VAPP_CAL_SYNC_RESULT, type, action, *index, result);

    return (VappCalSyncErrorEnum)result;
}
#endif
#ifndef __MMI_VCALENDAR__
#pragma arm section code, rodata
#endif
