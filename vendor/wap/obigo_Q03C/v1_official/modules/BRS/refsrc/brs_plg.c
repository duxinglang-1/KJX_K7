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

/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * brs_plg.c
 *
 * Created by Anders Edenbrandt, Wed Oct 23 16:48:54 2002.
 *
 * Revision history:
 *
 */
 
/*******************************************************************************
 *
 * Filename:
 * ---------
 * brs_plg.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Definition of plugin APIs.
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/  
 
#include "msf_cfg.h"
#include "brs_cfg.h"
#ifdef BRS_CONFIG_PLUGIN
/************************************************************
 * Registering of all plug-ins in the refsrc directory
 ************************************************************/

/************************************************************
 * Functions
 ************************************************************/

extern void brs_plab_register (void);
extern void brs_pltx_register (void);
extern void brs_pldata_register (void);


#ifdef MSF_CFG_URI_AGENT

extern void brs_plschmhdlr_register (void);

#ifndef MSF_CFG_UCM_SUPPORT
	extern void brs_plti_register (void);
#endif

#else



extern void brs_plti_register (void);
extern void brs_plsms_register (void);

#ifdef OBIGO_Q03C_MMS_V01
extern void brs_plmms_register (void);
#endif

#ifdef __SUPPORT_INFUSIO__
extern void brs_plege_register (void);
extern char support_ege_runtime;
#endif

#ifdef STREAM_SUPPORT
extern void brs_plrtsp_register (void);
#endif

#endif /*MSF_CFG_URI_AGENT*/


void
brs_plg_init (void)
{
  /* Register the "about" scheme handler */
  brs_plab_register ();

  /* Register the handler of text/plain documents */
  brs_pltx_register ();

  /* Register the "data" scheme handler */ 
  brs_pldata_register ();

#ifdef MSF_CFG_URI_AGENT
	/*Register the default scheme handler which hanles
		all the scheme except "about" and it is dispatched
		to UTI agent through BRA. It also handles the WMLs 
		WTAPublic.makeCall, WTAPublic.sendDTMF and WTAPublic.addPBEntry*/	
  brs_plschmhdlr_register();

#ifndef MSF_CFG_UCM_SUPPORT
  brs_plti_register ();
#endif
#else

  brs_plti_register ();

  /* Register the "sms" and "smsto" scheme handler */
  brs_plsms_register();

#ifdef OBIGO_Q03C_MMS_V01
  /* Register the "mms" and "mmsto" scheme handler */
  brs_plmms_register();
#endif

#ifdef __SUPPORT_INFUSIO__
  if(support_ege_runtime)
  {
    /* Register the "ege" scheme handler */
    brs_plege_register();
  }
#endif
#ifdef STREAM_SUPPORT
  /* Register the "rtsp" scheme handler */
  brs_plrtsp_register();
#endif
#endif /*MSF_CFG_URI_AGENT*/

}
#endif /* BRS_CONFIG_PLUGIN */
