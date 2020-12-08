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
 * mobile_suite_app.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * WAP/MMI interaction
 * 1. Key queue
 * 2. WAP/MMS screen enter/exit
 * 3. Full-screen editor and menu
 * 4. Misc. screens like popup
 * 5. WAP download & file manager integration
 * 6. New Push/Provision/MMS  notification
 * 7. RPC (widget_execute_MMI(), etc)
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*******************************************************************************
 * Common scenarios of MMI screen interaction:
 *
 * 1. WAP overlapped with MMI
 * 
 * 2. WAP overlapped with MMI, then press END key (wap_entry_idle_screen_notify)
 *
 * 3. widget_prepare_to_leave_screen() invoked, but MMI popup, wap_exit_widget_screen(), and then 
 *  widget_leave_screen_hdlr() found that WGUI_CTX->is_widget_screen is false, it doesn't GoBackHistory(). 
 *  MMI screen go back => wap_entry_widget_screen() found there is no window to display, and call
 *  widget_prepare_to_leave_screen() again.
 *
 * 4. WAP overlapped with MMI (including CTK), and out-of-memory
 *
 * To be continued ...
 *
 *******************************************************************************/

/*******************************************************************************
 * Rules on Inter-Task Synchronization:
 *
 * MMI resources are shared among three processes (MMI, WAP, Java), and there are more tasks to come in the future.
 * We need to define protocol to meet the following criteria:
 *
 * o Deadlock avoidance
 * o Screen-based shared memory must be released in wap_exit_widget_screen() synchronously.
 * o Prevent partial update the the LCD (e.g. clipping and double buffer might not be unlocked correctly)
 * 
 * -------------------------------
 * Problems of Race Condition if we invoke MMI functions from WAP task:
 *
 * We should prevent invoking MMI function from WAP task
 * o MMI funtions might enter NVRAM message loop, which can NOT be invoked in WAP context.
 *  (For example, entry function of idle screen might write NVRAM)
 *
 * WAP and MMI have the same priority, this prevents the following race condition when WAP and MMI 
 * 1. access global data structures
 * 2. invoke system service that do not put task itself into waiting queue. 
 *  (e.g. WAP might execute MMI functions that use StartTimer() to start event scheduler of MMI)
 * 3. No preemption between allocate_ilm and SEND_ILM 
 * (Assume we do not do blocking operations between two operations)
 * 4. MSF_MEM_ALLOC and MSF_SIGNAL_SEND!!
 *
 * However, it is still dangerous when 
 * o WAP/MMI use other blocking functions that use event groups or mutex (including filesystem API)
 *  For example, WAP decode an image from file.
 * o WAP/MMI display screen at the same time.
 *
 * If another task executes entry/exit function owned by a blocked task, its state might be incorrect.
 * For example: Partial update of screen:
 * a. widget_paint_hdlr is blocked, and MMI display new popup before it returns.
 * b. RedrawCategoryScreen is blocked, and enter WAP screen.
 * For the worst case, it might ASSERT.
 *
 * -------------------------------
 * o MMI wait for WAP:
 *  1. (Unfinished) Power off
 * 2. Wait WAP to shutdown UI from idle screen
 * 3. Wait WAP to display message notification screen from idle screen
 * 4. Wait WAP to get data of dynamic list (handled specially)
 *
 *  NOTE: BE CAREFUL NOT TO USE MMI FUNCTION WHEN MMI IS WAITING FOR WAP
 * If MMI wait for WAP , and WAP task use some MMI function that need to receive external queue,
 * then there will be deadlock!(For example, MMI API of JPEG, Audio receive extq from media task)
 * => When WAP is going to display message notification in idle screen, we wake up MMI before
 *    wap_entry_widget_screen()
 * => Idle screen must be executed in MMI task. (Already ASSERT() to check it)
 * => when WGUI_CTX->is_shutdown_UI is TRUE, we can not enter widget screen or show other window (e.g. HDIa_widgetExtShowPopup)
 *     Otherwise, it will widget_execute_MMI(show popup, KAL_TRUE) and cause deadlock.
 *
 * o Execute in WAP task asynchronously
 * 1. Keypad queue
 *
 * o When WAP wait MMI:
 *    1. HDIa_widgetSetInFocus -> wap_entry_widget_screen
 *   => If it is invoked from idle screen to show message, wap_entry_widget_screen() is invoked in widget_MMI_check_and_display_new_msg() instead
 *    2. Create Popup (e.g.  HDIa_widgetExtShowPopup) or enter MMI screens voluntarily (e.g. file manager, full-screen editor)
 *    3. widget_paint_hdlr, widget_paint_GIF_animation_hdlr, widget_paint_command_hdlr
 *    4. GoBackToHistory(WAP_SCREEN_WIDGET)  (not GoBackHistory())
 *    5. Enter and leave CTK screen 
 *    6. (?) sound playing
 *
 *  NOTE1: BE CAREFUL NOT TO GO BACK IDLE SCREEN WHEN WAP IS WAITING MMI
 * NOTE2: ALL SUCH RPC IN MMI TASK MUST BE GRACEFULLY CANCELED IN IDLE SCREEN
 * If WAP is suspended for MMI, and MMI go back to idle screen before the request is processed, there is deadlock
 *    => WAP should "not" invoke GoBackHistory(), DisplayIdleScreen(), .... in blocking mode
 *    => If protocol events happen before entering new screen, and other application go back history
 *       (i) There will still be deadlock in EntryIdleScreen before widget_execute_MMI(func, KAL_TRUE) is executing.
 *       (ii) For example, an End key event is queued in MMI ext queue, and WAP takes a lot of time to process 
 *        before widget_paint_hdlr() timer is fired. Then End key event is processed before widget_MMI_paint_hdlr
 *        where WIPC_CTX->WAP_is_waiting
 *       (iii) We cancel these RPC in idle screen
 *
 * o Execute in MMI task asynchronously
 * 1. widget_leave_screen_hdlr -> GoBackHistory
 *
 * -------------------------------
 * Other protocol to handle deadlock prevention
 *
 * o Mutex locked and unlocked inside of low-level functions
 *  => Mutex allocated in system functions like file API must be released inside the function too.
 *    They are transparent to use. 
 *     (e.g. lcd_fb_update, file API, blocking JPEG decoding, ...)
 * => NOT applicable to mutex/event groups held in a long period.
 *
 * o If widget_execute_MMI(funcA, KAL_TRUE) and then widget_execute_WAP(funcB, KAL_TRUE) 
 *  We do not wait event group for the second function.
 *
 * o Idle screen should always be executed in MMI task
 *  1. Idle screen call widget_MMI_on_enter_idle_screen and widget_MMI_check_and_display_new_msg
 * 2. Idle screen might invoke Java function
 * 3. Idle screen should not be re-entered
 *
 * -------------------------------
 * How to guarentee that WAP do not use MMI API/change MMI data/or draw on non-widget screen?
 * => All entry/exit/redraw functions should be executed in MMI task. Entry/redraw functions draw on the screen such that
 *   exit functions can only be executed if no other entry/redraw functions are running.
 *
 * Screen drawing of widget: 
 * o HDIa_widgetDrawXXX always check WGUI_CTX->is_widget_screen
 * o widget_paint_GIF_animation_hdlr are fired in WAP task, but widget_execute_MMI(widget_MMI_paint_GIF_animation_hdlr, KAL_TRUE)
 * o widget_paint_hdlr are fired in WAP task, but widget_execute_MMI(widget_MMI_paint_hdlr, KAL_TRUE)
 * o widget_paint_command_hdlr are  fired in WAP task, but widget_execute_MMI(widget_MMI_paint_command_hdlr, KAL_TRUE)
 *
 * Note: For widget_paint_hdlr and widget_paint_command_hdlr , we should not simply invoke the timer in MMI task because 
 * it can not guarentee integrity of widget data .
 * 
 * 
 *******************************************************************************/

#if defined(OBIGO_Q03C_BROWSER)
#include "mmi_rp_app_q03c_timer_def.h"  //MAUI_03167355
#endif
#include "widget_linklist.h"
#include "widget.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stack_msgs.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "BrowserResDef.h"
#endif
#include "wgui_categories_popup.h"

#include "CommonScreens.h"

#include "wap_adp_struct.h"
#include "wapresdef.h"
#include "msf_mem.h"


#include "mmiapi_struct.h"
#include "wap_ps_struct.h"

#include "WapDef.h"
#include "msf_file.h"
#include "msf_cmmn.h"
#include "widget_extension.h"

// TODO: set settingprof into include path, otherwise we cannot include it
#include "phonebook\phonebookinc\PhoneBookGprot.h"
/* Phbook revise */
#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"

#include "SettingDefs.h"
#include "SettingsGdcl.h"

#include "mmi_include.h"
#include "FileMgr.h"
#include "fs_func.h"

#include "mmiapi_struct.h"
#include "mmiapi_func.h"

#include "ucmsrvgprot.h"

#include "conversions.h"
#include "app_str.h"
#include "app_usedetails.h"

#include "wgui_softkeys.h"

#include "IdleAppDef.h"
//#include "SimDetectionGprot.h"
#include "ShutdownSrvGprot.h"
/* popup */
#include "Custom_events_notify.h"
#include "kal_public_defs.h"

#include "gpiosrvgprot.h"
#include "gui_themes.h"
#include "Wgui_categories_util.h"
#include "msf_cmmn.h"
/*Dinesh memory reduction*/
#include "widget_struct.h"
#include "Gui_fixed_menuitems.h"
#ifdef __MMI_BROWSER_2__
#include "brs_main.h"
#endif/*#ifdef __MMI_BROWSER_2__*/
/*Dinesh ends*/
#ifdef __MMI_BROWSER_2__
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_brw_struct.h"
#include "vapp_launcher_gprot.h"
#include "vapp_screen_lock_gprot.h"
#else/*__COSMOS_MMI_PACKAGE__*/
#include "IdleGprot.h"
#include "ScrSaverGprot.h"
#include "ScrLockerGprot.h"
#endif/*__COSMOS_MMI_PACKAGE__*/
#endif/*__MMI_BROWSER_2__*/

#include "msf_int.h"


#ifdef __DRM_SUPPORT__
#include "../../drm/include/drm_def.h"
#include "../../drm/include/drm_main.h"
#include "../../drm/include/drm_gprot.h"
#endif /* __DRM_SUPPORT__ */ 

#include "mdi_datatype.h"
#include "mdi_audio.h"  /* Message tone pause/resume */

#include "lcd_sw_rnd.h"
#include "notificationgprot.h"

/*
#include "CallmanagementGprot.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"
*/
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "mmi_rp_app_uiframework_def.h"
 
#ifdef __DM_LAWMO_SUPPORT__
#include "..\plutommi\mtkapp\dmuiapp\dmuiappinc\dmuigprot.h"
#endif /* __DM_LAWMO_SUPPORT__ */

#include "IdleAppDef.h" /* Idle screen */
#include "IdleAppProt.h"
#include "IdleNotificationManagerGprot.h"
#include "AudioInc.h"
#include "ProfilesSrvGprot.h"      /* Alert type */
#include "AlarmFrameworkProt.h" /* Alarm */
#include "messages/messagesInc/MessagesResourceData.h"  /* message image */

#include "WAPProfileSrvGProt.h"
#if defined(__MMI_FTE_SUPPORT__)
#include "wgui_categories_util.h"
#endif
#include "Fseditorcuigprot.h" 
#include "menucuigprot.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"

#ifdef __USB_IN_NORMAL_MODE__
extern int is_mms_storage_exported_to_pc(void);
//extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
//extern pBOOL mmi_usb_is_leaving_ms_mode(void);
#endif /* __USB_IN_NORMAL_MODE__ */ 
#endif /* __MMI_USB_SUPPORT__ */

#define INDICATION_KEY_CODE      (255)
#define NONE_REPEATED_KEY_CODE   (255)


extern U8 PhnsetGetDefEncodingType(void);
/* ind push */

extern void mmi_msg_start_msg_sub_anm(void);

#ifdef __MMI_WAP_DUAL_SIM__
extern kal_uint8 wap_get_sim_status(void);
extern kal_uint8 wap_get_sim_setting_mode(void);
#endif /* __MMI_WAP_DUAL_SIM__ */

#ifdef WAP_CFG_UNIFIED_PUSH
extern mmi_brw_push_delete_previous_instance_of_push (void);  
#endif /* WAP_CFG_UNIFIED_PUSH */

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

void wap_entry_wap_transition_animation(void);
void widget_dialog_get_popup_event(MsfDialogType type, mmi_event_notify_enum *event);

#define WIDGET_MAX_PENDING_KEY_NUM    (4)

/* For WCSS editor replace mode state */
#define WIDGET_FULLSCREEN_EDITOR_IN_INSERT_MODE         (0)
#define WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE   (1)
#define WIDGET_FULLSCREEN_EDITOR_IN_REPLACE_MODE        (2)


#ifdef OBIGO_Q03C_BROWSER
extern MMI_BOOL mmi_brw_is_rendered_page_present(void);
#endif /*OBIGO_Q03C_BROWSER*/
/*DInesh memory reduction*/
widget_pre_string_struct *widget_predefined_string_table = NULL;
#if 0
/* under construction !*/
#endif
widget_pre_image_struct *widget_predefined_image_table = NULL;
#ifndef WIDGET_USE_MMI_ICONTEXT_MENU
fixed_icontext_list_menuitem_type *widget_icontext_menu_items = NULL;
#endif
fixed_twostate_menuitem_type *widget_twostate_menu_items = NULL;
/*DInesh Ends*/
/******************************************************************************
 * Local variables/functions
 ******************************************************************************/




/******************************************************************************
 * Fullscreen editor
 ******************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_TOUCH_SCREEN__
static int g_v_bar_pen_state;
static int g_h_bar_pen_state;
#endif
static void wap_entry_fullscreen_editor_option(void);
static void wap_entry_fullscreen_editor(void);
static void widget_fullscreen_editor_highlight_done(void);
static void widget_fullscreen_editor_highlight_cancel(void);
static void widget_fullscreen_editor_highlight_input_method(void);
static int widget_check_fullscreen_editor_input_value(kal_bool go_back_history_if_fail);
static void widget_exit_fullscreen_editor(void);
static void widget_exit_fullscreen_editor_with_done(void);
//static void widget_exit_fullscreen_editor_number_with_ok(void);
static void widget_exit_fullscreen_editor_with_cancel(int level);
static void widget_exit_fullscreen_editor_with_cancel_level0(void);
void widget_exit_fullscreen_editor_with_cancel_level1(void);
static void widget_fullscreen_editor_insert_character_dot(void);
static void widget_fullscreen_editor_customize_key(void);

static mmi_ret widget_fseditor_event_handler_proc(mmi_event_struct *evt);
static mmi_ret widget_event_handler_proc(mmi_event_struct *evt);
static mmi_ret widget_wcss_event_handler_proc(mmi_event_struct *evt);
#ifdef __MMI_BROWSER_2__
#ifdef __COSMOS_MMI_PACKAGE__
extern void vappBrwCloseWapEditor(void);
void widget_accept_fullscreen_input_from_browser(kal_uint8 *object);
extern void vappBrwDisplayWapEditor(vappBrwFullScreenEditorStruct *obj);
extern void vappBrwDisplayWapListMenu(vappBrwListMenuChoiceEnum listMenuType);
U32 widget_return_no_of_menu_items(void);
void widget_set_item_radio_menu(int index);
extern vappBrwFullScreenEditorStruct *screendata; 
extern void mmi_frm_nmgr_balloon(
    mmi_scenario_id scenario_id,
    mmi_event_notify_enum type,
    mmi_nmgr_balloon_type_enum balloon_type,
    const WCHAR *string);
#endif
#endif

//MAUI_03240037 starts

#ifdef __COSMOS_MMI_PACKAGE__
gdi_handle fixed_list_menu_prev_layer_handle;
extern fixed_list_menu MMI_fixed_list_menu;
#endif

//MAUI_03240037 ends

/******************************************************************************
 * Task Management
 ******************************************************************************/


/******************************************************************************
 * Circular Keypad Queue
 ******************************************************************************/

/*
 * We execute widget_general_keyboard_handler in WAP task. Otherwise, MsfAction and MsfUserEvent 
 * * might be inserted in WAP internal queue when WAP is blocked inside MSF_fsm and the execution order might be wrong.
 * *
 * * NOTE: The current implementation does not handle KEY_REPEAT in order to reduce queue size.
 */

/* 
 * If the processing time of certain keypad events exceeds WIDGET_KEY_TIMEOUT_TICKS,
 * we shall flush the key queue and stop processing it after WIDGET_KEY_TIMEOUT2_TICKS.
 */
#define WIDGET_KEY_TIMEOUT_TICKS (KAL_TICKS_1_SEC/2)
#define WIDGET_KEY_TIMEOUT2_TICKS (KAL_TICKS_100_MSEC)

#define WIDGET_KEY_REPEAT_DURATION_TIME      10


/*****************************************************************************
 * FUNCTION
 *  widget_init_structure
 * DESCRIPTION

 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_structure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                        */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                               */
    /*----------------------------------------------------------------*/
	/*Dinesh*/
#ifdef __MMI_BROWSER_2__
/*
	  widget_predefined_string_table     = BRS_MEM_ALLOC(sizeof(widget_pre_string_struct)*WAP_STR_ID_SUM);
	  memset(
          widget_predefined_string_table,
          0,
          sizeof(widget_pre_string_struct) * WAP_STR_ID_SUM);
*/
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     
	  widget_predefined_image_table    = BRS_MEM_ALLOC(sizeof(widget_pre_image_struct)*(WAP_IMAGE_ID_END - WAP_IMAGE_ID_BEGIN));
	  memset(
          widget_predefined_image_table,
          0,
          sizeof(widget_pre_image_struct) * (WAP_IMAGE_ID_END - WAP_IMAGE_ID_BEGIN));

#ifndef WIDGET_USE_MMI_ICONTEXT_MENU     
	  widget_icontext_menu_items       = BRS_MEM_ALLOC(sizeof(fixed_icontext_list_menuitem_type)*MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS);
	  memset(
          widget_icontext_menu_items,
          0,
          sizeof(fixed_icontext_list_menuitem_type) * MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS);
#endif
      
	  widget_twostate_menu_items      = BRS_MEM_ALLOC(sizeof(fixed_twostate_menuitem_type)*MAX_FIXED_TWOSTATE_MENU_ITEMS);
	  memset(
          widget_twostate_menu_items,
          0,
          sizeof(fixed_twostate_menuitem_type) * MAX_FIXED_TWOSTATE_MENU_ITEMS);
 return;
  /*End Dinesh*/
#endif/*#ifdef __MMI_BROWSER_2__*/

}
/*****************************************************************************
 * FUNCTION
 *  widget_deinit_structure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_structure(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                        */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                               */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_BROWSER_2__
/*
	BRS_MEM_FREE(widget_predefined_string_table);
    widget_predefined_string_table = NULL;
*/
#if 0
/* under construction !*/
/* under construction !*/
#endif
	BRS_MEM_FREE(widget_predefined_image_table);
    widget_predefined_image_table = NULL;
    #ifndef WIDGET_USE_MMI_ICONTEXT_MENU
	BRS_MEM_FREE(widget_icontext_menu_items);
    widget_icontext_menu_items = NULL;
#endif
	BRS_MEM_FREE(widget_twostate_menu_items);
    widget_twostate_menu_items =NULL;
return;
#endif/*#ifdef __MMI_BROWSER_2__*/
}
/*****************************************************************************
 * FUNCTION
 *  widget_init_key_queue
 * DESCRIPTION
 *  Initialize widget keypad queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_key_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_widget_context )
	{
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INIT_KEY_QUEUE); 
    WKEY_CTX->head = WKEY_CTX->tail = 0;
    WKEY_CTX->last_enqueue_time = 0;
    WKEY_CTX->last_process_time = 0;
    WKEY_CTX->is_processing_key = 0;
}
}

/* Insert keypad event into keypad queue */


/*****************************************************************************
 * FUNCTION
 *  widget_insert_key_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keycode     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_insert_key_queue(kal_uint16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int new_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(keycode < 256);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INSERT_KEY_QUEUE, keycode); 
	if(g_widget_context )					//MAUI_03325866
	{
    new_tail = WKEY_CTX->tail + 1;
    if (new_tail == WIDGET_KEY_QUEUE_SIZE)
    {
        new_tail = 0;
    }

    if (WKEY_CTX->head == new_tail) /* Full */
    {
        /* We can safely drop the key because only KeyUp is enqueued. */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_KEY_DROPPED_QUEUE_FULL); 
        return KAL_FALSE;
    }

    WKEY_CTX->keycode[WKEY_CTX->tail] = (kal_uint8) keycode;
    WKEY_CTX->tail = new_tail;
    return KAL_TRUE;
}
	return KAL_FALSE;													//MAUI_03325866
}

/* Retrieve keypad event from keypad queue */


/*****************************************************************************
 * FUNCTION
 *  widget_get_key_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keycode     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_get_key_queue(kal_uint16 *keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WKEY_CTX->head == WKEY_CTX->tail)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_KEY_DROPPED_QUEUE_FULL); 
        return KAL_FALSE;
    }
    *keycode = WKEY_CTX->keycode[WKEY_CTX->head];
    if (++WKEY_CTX->head == WIDGET_KEY_QUEUE_SIZE)
    {
        WKEY_CTX->head = 0;
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GET_KEY_QUEUE, *keycode);  
    return KAL_TRUE;
}

/* Check whether keypad queue is empty */


/*****************************************************************************
 * FUNCTION
 *  widget_key_queue_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_key_queue_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_widget_context )
	{
    return (WKEY_CTX->head == WKEY_CTX->tail) ? KAL_TRUE : KAL_FALSE;
}
	else 
	{
		return KAL_FALSE;
	}
}

/* 
 * Put keypad indication to WAP external queue. 
 * We typically keep atmost one keypad indication in WAP external queue. 
 */


/*****************************************************************************
 * FUNCTION
 *  widget_put_key_indication_in_ext_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_put_key_indication_in_ext_q(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;
    wap_mmi_key_indication_struct *mmi_key_ind =
        ((wap_mmi_key_indication_struct*) construct_local_para(sizeof(wap_mmi_key_indication_struct), TD_CTRL));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set keycode as 255 for an indication. Keycode  will be retrieved from key queue later in widget_wap_mmi_key_ind() */
    mmi_key_ind->keycode = INDICATION_KEY_CODE;
    mmi_key_ind->keytype = 0;
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PUT_KEY_IND_IN_EXT_QUEUE);  
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_MMI_KEY_INDICATION;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) mmi_key_ind;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}

/* Key released event */


/*****************************************************************************
 * FUNCTION
 *  widget_put_key_up_event_in_ext_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keycode     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_put_key_up_event_in_ext_q(kal_uint16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;
    wap_mmi_key_indication_struct *mmi_key_ind =
        ((wap_mmi_key_indication_struct*) construct_local_para(sizeof(wap_mmi_key_indication_struct), TD_CTRL));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_key_ind->keycode = keycode;
    mmi_key_ind->keytype = KEY_EVENT_UP;
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PUT_KEY_UP_EVENT_IN_EXT_QUEUE, keycode);  
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_WAP_MMI_KEY_INDICATION;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) mmi_key_ind;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_key_handler
 * DESCRIPTION
 *  WAP general key handler for keypads used by MsfUserEvent and MsfAction
 *  (invoked in MMI task, set from widget_clear_all_handler())
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_KEY_HANDLER);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    /* Out-of-memory. WAP is resetting. */
    if (wap_status != WAP_RUNNING)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_KEY_HANDLER_END_WAP_NOT_RUNNING);

        widget_init_key_queue();
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WIDGET_CALLS_GOBACKHISTORY);  
        mmi_frm_scrn_close_active_id();
        return;
    }

    GetkeyInfo(&Keycode, &Keytype);

#ifdef __SENDKEY2_SUPPORT__
    /* Handle KEY_SEND2 events, convert it to KEY_SEND */
    if (Keycode == KEY_SEND2)
    {
        Keycode = KEY_SEND;
    }
#endif

    widget_enqueue_keypad_event(Keycode, Keytype);
}


/*****************************************************************************
 * FUNCTION
 *  widget_enqueue_keypad_event
 * DESCRIPTION
 *  Put an key event in key queue
 *  
 *  Note: We only enqueue KEY_EVENT_UP, but we will emulate KEY_EVENT_DOWN in widget_wap_mmi_key_ind()
 * PARAMETERS
 *  Keycode     [IN]        
 *  Keytype     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enqueue_keypad_event(U16 Keycode, U16 Keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Disable enqueuing of keypad event if the last keypad event took too much time to process */
    static kal_uint32 last_repeated_time = 0;
    kal_uint32 now;
    kal_bool was_empty;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     ***********************************************************************
     * 1. Check and convert the keytype: KEY_EVENT_UP, KEY_REPEAT
     ***********************************************************************
     * Although WAP/Widget may set the keyhandler with KEY_EVENT_DOWN, 
     * KEY_REPEAT and KEY_EVENT_UP, we will only insert the 
     * keycode with KEY_EVENT_UP into WAP internal key queue. 
     * We will convert the KEY_REPEAT to KEY_EVENT_UP and then insert 
     * it into WAP's internal key queue.
     */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENQUEUE_KEYPAD_EVENT, Keycode, Keytype);  
    if (Keytype == KEY_EVENT_DOWN)
    {
        /* Don't process KEY_EVENT_DOWN, KEY_LONG_PRESS */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_KEY_EVENT_DOWN_NOT_PROCESSED);  
        return;
    }
if(g_widget_context )             //MAUI_03325866
{
    if (WGUI_CTX->is_painted_after_first_focus_changed == 0)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);  
        return;
    }
}

    /* Check the key number */
    if (!widget_key_queue_is_empty())
    {
		if(g_widget_context )                  //MAUI_03325866
		{
        if (WKEY_CTX->tail > WKEY_CTX->head)
        {
            if (WKEY_CTX->tail - WKEY_CTX->head > WIDGET_MAX_PENDING_KEY_NUM)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENQUEUE_KEYPAD_EVENT_END_DROP_KEYEVENT);

                /* the key number exceed more than WIDGET_MAX_PENDING_KEY_NUM */
                return;
            }
        }
        else
        {
            if ((WIDGET_KEY_QUEUE_SIZE - WKEY_CTX->head) + WKEY_CTX->tail > WIDGET_MAX_PENDING_KEY_NUM)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENQUEUE_KEYPAD_EVENT_END_DROP_KEYEVENT);

                /* the key number exceed more than WIDGET_MAX_PENDING_KEY_NUM */
                return;
            }
        }
    }
    }

    /* We only process KEY_LONG_PRESS & KEY_REPEAT in navigation keys */
    if ((Keytype == KEY_REPEAT || Keytype == KEY_LONG_PRESS) &&
        !(Keycode >= KEY_UP_ARROW && Keycode <= KEY_RIGHT_ARROW))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_KEY_OTHER_THAN_REPEAT_LONG_PRESS_NAVIGATION);  
        return;
    }

    kal_get_time(&now);
    if (Keytype == KEY_REPEAT || Keytype == KEY_LONG_PRESS)
    {
        if (last_repeated_time && (now - last_repeated_time) <= WIDGET_KEY_REPEAT_DURATION_TIME)
        {
            /* 
             * If key repeated frequecy is faster than widget paint frequency,
             * we will drop the repeated key
             */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_KEY_FREQUENCY_MORE);  
            return;
        }
        else
        {
            /* 
             * last_repeated_time == 0 ||
             * now - last_repeated_time > WIDGET_PAINT_DELAY_TIME
             */
            last_repeated_time = now;
            Keytype = KEY_EVENT_UP;
        }
    }
    else if (Keytype == KEY_EVENT_UP)
    {
        if (last_repeated_time)
        {
            if (now - last_repeated_time <= WIDGET_KEY_REPEAT_DURATION_TIME)
            {   /* drop the key */
                /* The key has detected the repeat event, reset last_repeated_time  */
                last_repeated_time = 0;
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_KEY_DROPPED_REPEAT_EVENT); 
                return;
            }
            /* The key has detected the repeat event, reset last_repeated_time  */
            last_repeated_time = 0;
        }
    }

    /*
     ***********************************************************************
     * 2. Check the key process time
     ***********************************************************************
     * Disable enqueuing of keypad event if the last keypad event 
     * took too much time to process
     */
	if(g_widget_context )                    //MAUI_03325866
	{
    if (WKEY_CTX->last_process_time && WKEY_CTX->last_enqueue_time &&
        (now - WKEY_CTX->last_process_time < WIDGET_KEY_TIMEOUT2_TICKS) &&
        (WKEY_CTX->last_process_time - WKEY_CTX->last_enqueue_time >= WIDGET_KEY_TIMEOUT_TICKS))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENQUEUE_KEYPAD_EVENT_END_TIME_TOO_LONG);

        WKEY_CTX->head = WKEY_CTX->tail = 0;
        return;
    }
    else if (WKEY_CTX->last_process_time && WKEY_CTX->last_enqueue_time &&
             (WKEY_CTX->last_process_time - WKEY_CTX->last_enqueue_time < WIDGET_KEY_TIMEOUT_TICKS))
    {
        WKEY_CTX->last_process_time = WKEY_CTX->last_enqueue_time = 0;
    }
    else if (WKEY_CTX->last_process_time && (now - WKEY_CTX->last_process_time >= WIDGET_KEY_TIMEOUT2_TICKS))
    {
        WKEY_CTX->last_process_time = WKEY_CTX->last_enqueue_time = 0;
    }

    if (WKEY_CTX->last_enqueue_time == 0)
    {
        WKEY_CTX->last_enqueue_time = now;
        WKEY_CTX->last_process_time = 0;
    }
	}

    /*
     ***********************************************************************
     * 3. insert the key in WAP/widget internal queue
     ***********************************************************************
     * 
     */
    was_empty = widget_key_queue_is_empty();

    if (widget_insert_key_queue(Keycode) && was_empty)
    {
        widget_put_key_indication_in_ext_q();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_wap_mmi_key_ind
 * DESCRIPTION
 *  Event handler of key indication, invoked from messsage loop of WAP external queue.
 *  Process one key one time.
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_wap_mmi_key_ind(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 keycode;
    wap_mmi_key_indication_struct *mmi_key_ind = (wap_mmi_key_indication_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND);

    if (WGUI_CTX->is_in_goto_idle_screen)
    {
        /* widget is in goto idle screen procedure */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND_END_DISCARD_KEY);
        return;
    }

    if (mmi_key_ind->keycode != INDICATION_KEY_CODE)    /* Key released */
    {
        /* set WKEY_CTX->last_process_time after KEY_EVENT_DOWN and KEY_EVENT_UP are both processed */
        WKEY_CTX->is_processing_key = 1;

        /* It guarentees that KEY_EVENT_DOWN and KEY_EVENT_UP are paired together. */
        if (WIDGET_IS_WAP_RUNNING)
        {
            widget_general_keyboard_handler(mmi_key_ind->keycode, KEY_EVENT_UP);
        }

        if (!widget_key_queue_is_empty())
        {
            widget_put_key_indication_in_ext_q();
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND_PUT_IN_Q);
        }
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);  
        return;
    }

    /* Key pressed */
    if (WKEY_CTX->last_process_time && WKEY_CTX->last_enqueue_time &&
        (WKEY_CTX->last_process_time - WKEY_CTX->last_enqueue_time > WIDGET_KEY_TIMEOUT_TICKS))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND_END_TIME_TOO_LONG);

        WKEY_CTX->head = WKEY_CTX->tail = 0;
        return;
    }

    if (!widget_get_key_queue(&keycode))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_MMI_KEY_IND_END_Q_EMPTY);

        return;
    }

    if (WIDGET_IS_WAP_RUNNING)
    {
        /*
         * Note that we should not simply call widget_general_keyboard_handler twice sequencially
         * * by passing KEY_EVENT_DOWN and KEY_EVENT_UP repectively.
         * *
         * * Take SMIL scrolling as example, for a SMIL with text on top and image on bottom,
         * * smaDeleteUserEvent delete user events after it receive MsfKey_Up + MsfPress (KEY_UP_ARROW + KEY_EVENT_DOWN) 
         * * at top of the text, and widget_form_scroll_up_sliding_SMIL() is executed for KEY_UP_ARROW + KEY_EVENT_UP.
         * * Then the text gadget will get focus and register user events again.
         * *
         * * If we invoke two widget_general_keyboard_handler() sequencially here. widget_form_scroll_up_sliding_SMIL()
         * * will be invoked here because it is function call, and smaDeleteUserEvent() is invoked later because it is 
         * * triggered by internal queue.
         * *
         */
        widget_general_keyboard_handler(keycode, KEY_EVENT_DOWN);
        widget_put_key_up_event_in_ext_q(keycode);
    }
}


/*****************************************************************************
 *
 * WAP/MMI interaction & window management
 *
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_ready_to_leave_screen
 * DESCRIPTION
 *  If there is no active window left, we should invoke a timer to go back from widget screen.
 *  The timer is used to guard a race condition that a window is created immediately.
 *  
 *  We don't go back to MMI by explicitly invoking GoBackHistory from WAP.
 *  (There are too many scenario to handle, e.g., leaving a push dialog in WAP or in idle screen are different)
 *  Instead, we check certain condition to determine whether to go back to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_ready_to_leave_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *screen;
    widget_header_struct *window;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * If no MsfWindow is left, we should leave widget screen.
     * Note that MsfScreen might not be released after WAP UI is shutdown, and we don't check it.
     */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_READY_TO_LEAVE_SCREEN);  
    foreach_childs((&WGUI_CTX->widget_root), screen,
                   {
                   foreach_childs(screen, window,
                                  {
                                  if (IS_WINDOW_TYPE(window))
                                  {
                                  return KAL_FALSE;}
                                  }
                   );}
    );

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_READY_TO_LEAVE_SCREEN_TRUE);  
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_leave_screen_goback
 * DESCRIPTION
 *  After timer expired,  leave widget screen.
 *  (Invoked as a tmer handler in WAP)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
// TODO: handle the case of CTK (when release all widgets)

static void widget_MMI_leave_screen_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Race condition. Do we need to check widget_ready_to_leave_screen() again? */
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_LEAVE_SCREEN_GOBACK);  
    if (!widget_ready_to_leave_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_LEAVE_SCREEN_GOBACK_WINDOW_LEFT);
        return;
    }
/* This is not Required as screen handling is now controlled by Application */     

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_LEAVE_SCREEN_GOBACK);  
}


/*****************************************************************************
 * FUNCTION
 *  widget_leave_screen_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_leave_screen_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Scenario: We need to GoBackHistory in MMI task. Otherwise, successive push/provision/MMS will 
     * enter idle screen in WAP task and create deadlock in widget_MMI_check_and_display_new_msg()
     */

    widget_stop_timer(WIDGET_EXIT_DELAY_TIMER);

    /* 
     * WAP modules might remove a window and create another window immediately.
     * We do not leave widget screen for this case.
     */
    if (!widget_ready_to_leave_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_LEAVE_SCREEN_HDLR_WITH_WINDOW);
        return;
    }
    if (!WGUI_CTX->is_widget_screen)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_LEAVE_SCREEN_HDLR_NOT_IN_WIDGET_SCREEN);
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WIDGET_CALLS_DELETE_SCREEN_IF_PRESENT, ret); 
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_LEAVE_SCREEN_HDLR);

    /* WAP might be paused in history (by CTK screen or MMI), and we cannot GoBackToHistory() for this case */
    /* If the last screen is idle screen, widget_execute_MMI with blocking mode causes deadlock */
    widget_execute_MMI(widget_MMI_leave_screen_goback, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_prepare_to_leave_screen
 * DESCRIPTION
 *  Wait for a perod to check whether new window is created. If not, leave widget screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_prepare_to_leave_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: If we restart WAP task, the timer will be destroyed and it will never call widget_leave_screen_hdlr!!

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PREPARE_TO_LEAVE_SCREEN);

    widget_start_timer(
        WIDGET_EXIT_DELAY_TIMER,
        (widget_timer_func) widget_leave_screen_hdlr,
        (void*)WGUI_CTX->current_screen_level /* Deprecated */ ,
        WIDGET_EXIT_DELAY_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  widget_notify_shutdown_UI_finished
 * DESCRIPTION
 *  After WAP finished shutdown of UI, wake up MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_notify_shutdown_UI_finished(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_NOTIFY_SHUTDOWN_UI_FINISHED); 
    WGUI_CTX->is_shutdown_UI = 0;
#ifdef WIDGET_DRAW_STATUS_BAR
    WGUI_CTX->status_bar_flags = 0;
#endif
    WGUI_CTX->is_painted_after_first_focus_changed = 0;

    /* We may send MSG_ID_WAP_BROWSER_SHUTDOWN_REQ without WIDGET_WAIT_MMI_LOCK() */
    if (!WIDGET_TRY_MMI_LOCK())
    {
        ASSERT(!WIPC_CTX->WAP_is_waiting && WIPC_CTX->MMI_is_waiting);
        WIPC_CTX->MMI_is_waiting = 0;
        WIDGET_SIGNAL_MMI_LOCK();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_goback_history1
 * DESCRIPTION
 *  Go back two level of MMI screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_goback_history1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  GoBacknHistory(1);
}


/*  
 * There is a race condition (race to happen)
 * 
 * 1. L4 send incoming call primitive to MMI task
 * 2. WAP/MMS is starting, WAP task sends RPC request to MMI task to enter widget screen 
 * 3. MMI task enters incoming call screen first. If we do not check in-call here, widget screen
 *  will hide incoming call screen.
 *
 */




/*****************************************************************************
 * FUNCTION
 *  widget_allow_create_new_MMI_screen
 * DESCRIPTION
 *  Check whether we can display new window (e.g., poup, file manager, phonebook...)
 *  
 *  Note:
 *  1. We have three kinds of screen in WAP - widget, CTK, and other MMI screens used by WAP/MMS
 *  2. The rules is subset to the rules defined in widget_set_current_focus
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_allow_create_new_MMI_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We cannot display new window when shutdown UI in idle screen or out-of-memory */
    if (WGUI_CTX->is_shutdown_UI)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ALLOW_CREATE_NEW_MMI_SCREEN_FAILED_BY_SHUTDOWN);
        return KAL_FALSE;
    }

    /* 
     * We have unlocked RPC lock and cancel pending RPC requests to 
     * MMI task widget_MMI_on_enter_idle_screen.
     *
     * However, if WAP send RPC request to MMI task before widget_MMI_check_and_display_new_msg(). 
     * It creates deadlock. 
     *
     * Reference: EntryIdleScreen(). 
     * Note: We check GetExitScrnID() because g_idle_context.IsOnIdleScreen is not always set inside EntryIdleScreen().
     */
#ifndef __COSMOS_MMI_PACKAGE__
	if (WGUI_CTX->is_in_goto_idle_screen == 1 || mmi_idle_is_active())
#else
	if (WGUI_CTX->is_in_goto_idle_screen == 1 || vapp_launcher_is_active())
#endif
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ALLOW_CREATE_NEW_MMI_SCREEN_FAILED_BY_GOTO_IDLE_SCREEN);
        return KAL_FALSE;
    }

    if (widget_check_is_incoming_call())
    {
        /* The phone shows incoming call screen, but the users don't answer/reject the call, yet. */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURNS_IN_WAP_CALL);  
        return KAL_FALSE;
    }

    if (!WIDGET_IS_WAP_RUNNING)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURNS_WAP_NOT_RUNNING);  
        return KAL_FALSE;
    }

    if (srv_shutdown_is_running())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURNS_POWER_OFF_PERIOD);  
        return KAL_FALSE;
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ALLOW_CREATE_NEW_MMI_SCREEN_TRUE);  
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_goback_to_widget_screen
 * DESCRIPTION
 *  Go back to widget screen in MMI task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
// TODO: Use widget_goback_to_WAP_screens() to replace it

static void widget_MMI_goback_to_widget_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
#ifdef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_BROWSER_2__
    vappBrwCloseWapListMenu();
    WGUI_CTX->resume_rendering = KAL_TRUE;
#endif
#else
#ifdef __MMI_BROWSER_2__
    if (mmi_frm_scrn_is_present(BRW_RENDERED_PAGE_GRP_ID,widget_get_screen_id(),MMI_FRM_NODE_ALL_FLAG))
    {
#endif
        if((mmi_frm_scrn_get_active_id() >= WAP_SCREEN_WIDGET) && (mmi_frm_scrn_get_active_id() < SCR_ID_WAP_END))
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_GOBACK_TO_WIDGET_SCREEN);
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            widget_MMI_delete_symbol_picker_screen_if_present();

        }
#ifdef __MMI_BROWSER_2__
	}
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  widget_goback_to_widget_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_goback_to_widget_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GOBACK_TO_WIDGET_SCREEN);
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_BROWSER_2__
    if (mmi_frm_scrn_is_present(BRW_RENDERED_PAGE_GRP_ID,widget_get_screen_id(),MMI_FRM_NODE_ALL_FLAG)) /* To prevent callback in idle screen */
#endif
#endif
    {
		widget_execute_MMI(widget_MMI_goback_to_widget_screen, KAL_TRUE);
    }
 }


#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING

/*****************************************************************************
 * FUNCTION
 *  widget_MMI_not_ready_goback_hdlr
 * DESCRIPTION
 *  Timer handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_precache_not_ready_goback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_image_precache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_entry_image_precache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WAP_ENTRY_IMAGE_PRECACHE);
/*This api is called from widget.ctk  it is wrapped under MMS_V01 macro so for removing history 
related API commenting EntryNewScreen */
    //EntryNewScreen(WAP_SCREEN_NOT_READY, wap_exit_widget_not_ready, wap_entry_image_precache, NULL);
    
#if defined(OBIGO_Q03C_BROWSER)

    StartTimer((U16) WAP_NOT_READY_TIMER, 20000, widget_MMI_precache_not_ready_goback_hdlr);
#endif

    ShowCategory66Screen(
        MEA_STR_ID_MMS,
        MEA_IMG_TITLE_NORMAL,
        0,
        0,
        0,
        0,
        (U8*) GetString(WIDGET_STR_ID_PLEASE_WAIT),
        0,
        NULL);

}

#endif /*WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING*/




/******************************************************************************
 * Widget internal message box used by fullscreen editor
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wap_entry_widget_editor_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message_icon        [IN]        
 *  message             [IN]         
 *  callback            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_entry_widget_editor_message(mmi_event_notify_enum eventid, void *message, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_popup_display_simple((WCHAR*)message, eventid, GRP_ID_ROOT, NULL);
    WGUI_CTX->is_popup_displayed = KAL_TRUE;
}

/******************************************************************************
 * Widget Popup
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  force_to_display    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_display_popup(int force_to_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool display_on_idle_screen = KAL_TRUE;
	mmi_event_notify_enum mmi_popup_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DISPLAY_POPUP);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    if (force_to_display & WIDGET_EXT_FORCE_POPUP_IN_IDLE_CHECKING == WIDGET_EXT_FORCE_POPUP_IN_IDLE_CHECKING)
    {
        /*
         * If calling widget_MMI_display_popup() from widget_MMI_check_and_display_new_msg(),
         * we don't need re-entry idle screen again 
         */
        display_on_idle_screen = KAL_FALSE;
        force_to_display &= ~(WIDGET_EXT_FORCE_POPUP_IN_IDLE_CHECKING);
        
    }
    else
    {
        /* Display it in idle screen or display popup otherwise */
    #ifndef __COSMOS_MMI_PACKAGE__
		#ifdef __MMI_SCREEN_SAVER__
			display_on_idle_screen = (mmi_idle_is_active() || mmi_scr_saver_is_active()) && !widget_check_is_in_non_wap_call();
		#else
			display_on_idle_screen = (mmi_idle_is_active()) && !widget_check_is_in_non_wap_call();
		#endif
	#else
		display_on_idle_screen = (vapp_launcher_is_active()) && !widget_check_is_in_non_wap_call();
	#endif
    }

    if (display_on_idle_screen)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DISPLAY_POPUP_GOTO_IDLE_SCREEN);
        WGUI_CTX->has_popup_in_idle_screen = 1;
        mmi_idle_display();  /* DisplayIdleScreen() do nothing in idle screen */    
    }
    else
    {
        if (!AlmIsTonePlaying())
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_DISPLAY_POPUP_DIRECTLY, force_to_display);
            if ((force_to_display == WIDGET_EXT_FORCE_POPUP_FLAG &&
                 WGUI_CTX->is_in_goto_idle_screen == 0) ||
                (force_to_display == WIDGET_EXT_DISPLAY_POPUP_FLAG && 
                 widget_allow_create_new_MMI_screen()))
            {
                /*
                 * Only show popup when widget screen is active.
                 * Can't show popup in the idle screen.
                 */
                /*
                DisplayPopup(
                    WGUI_CTX->popup_text,
                    WGUI_CTX->popup_imageid,
                    WGUI_CTX->popup_imageOnBottom,
                    WGUI_CTX->popup_timeout,
                    WGUI_CTX->popup_toneid);
					*/
				widget_dialog_get_popup_event(WGUI_CTX->dialog_type, &mmi_popup_event);
#ifdef __COSMOS_MMI_PACKAGE__
	mmi_frm_nmgr_balloon(
	MMI_SCENARIO_ID_GENERAL,
    MMI_EVENT_INFO_BALLOON,
	MMI_NMGR_BALLOON_TYPE_FAILURE,
    (WCHAR*)WGUI_CTX->popup_text
	);
                
#else
				mmi_popup_display_simple((WCHAR*)WGUI_CTX->popup_text, mmi_popup_event, GRP_ID_ROOT, NULL);
#endif           
            }
            WGUI_CTX->popup_text = NULL;
            WGUI_CTX->popup_imageid = 0;
            WGUI_CTX->popup_imageOnBottom = 0;
            WGUI_CTX->popup_timeout = 0;
            WGUI_CTX->popup_toneid = 0;
			WGUI_CTX->dialog_type = 0;
        }
	}
}


/* cf. HDIa_widgetExtShowPopup */

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtShowPopupWithType
 * DESCRIPTION
 *  This function is workable only when widget need to be active
 *  This function doesn't work in the idle screen
 * PARAMETERS
 *  modId           [IN]        
 *  dialogText      [IN]        
 *  type            [IN]        
 *  timeout         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtShowPopupWithType(MSF_UINT8 modId, MsfStringHandle dialogText, MsfDialogType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_tone_id toneid;
    ctk_image_id imageid;
    kal_bool image_bottom;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_dialog_get_attributes(type, &imageid, &toneid, &image_bottom);
	WGUI_CTX->dialog_type = type;

    HDIa_widgetExtShowPopupExt(modId, dialogText, imageid, toneid, image_bottom);
    return 0;
}

/*
 * Because HDIa_widgetExtShowPopup is used among different module, be sure not to 
 * * use HDIa_widgetRelease(), which has problems on HDIa_widgetReleaseAll().
 * *
 * * Note: Use HDIa_widgetExtRegisterPopupMsg() instead if you want to display on any
 * * MMI screens including idle screen.
 */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtShowPopupExt
 * DESCRIPTION
 *  This function is workable only when widget need to be active
 *  This function doesn't work in the idle screen
 * PARAMETERS
 *  modId               [IN]        
 *  dialogText          [IN]        
 *  imageid             [IN]        
 *  toneid              [IN]        
 *  imageOnBottom       [IN]        
 *  timeout             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtShowPopupExt(
        MSF_UINT8 modId,
        MsfStringHandle dialogText,
        ctk_image_id imageid,
        ctk_tone_id toneid,
        kal_bool imageOnBottom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *text = HDIa_widgetExtStringGetUCS2buffer(dialogText);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(modId);

    if (!widget_allow_create_new_MMI_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SHOW_POPUP_EXT_NOT_ALLOW);
        return 0;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SHOW_POPUP_EXT);


    WGUI_CTX->popup_text = (U8*) text;
    WGUI_CTX->popup_imageid = imageid;
    WGUI_CTX->popup_imageOnBottom = (U8) imageOnBottom;
    //WGUI_CTX->popup_timeout = (U32) (timeout == 0 ? UI_POPUP_NOTIFYDURATION_TIME : timeout);
    WGUI_CTX->popup_toneid = toneid;

    /*
     * Only show popup when widget screen is active.
     * Can't show popup in the idle screen.
     */
    widget_execute_MMI_i(widget_MMI_display_popup, (int)WIDGET_EXT_DISPLAY_POPUP_FLAG, KAL_TRUE);

    return 0;
}





/******************************************************************************
 * Fullscreen editor
 ******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wap_entry_fullscreen_editor_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_fullscreen_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_FULLSCREEN_EDITOR_OPTION);

    WEDITOR_CTX->menu_cui_group_id = cui_menu_create(WEDITOR_CTX->group_id,
                                                CUI_MENU_SRC_TYPE_RESOURCE,
                                                CUI_MENU_TYPE_OPTION,
                                                WAP_MENU_FULLSCREEN_EDITOR_OPTION,
                                                MMI_TRUE, NULL);
    //cui_menu_set_default_title(WEDITOR_CTX->menu_cui_group_id, (WCHAR*)get_string(WIDGET_STR_ID_OPTION), (UI_image_type)get_image(widget_get_title_icon(0)));
    cui_menu_set_default_title_by_id(WEDITOR_CTX->menu_cui_group_id, WIDGET_STR_ID_OPTION, widget_get_title_icon(0));
    /* In WCSS Editor Input Method Optionis not required */
        mmi_frm_hide_menu_item(WAP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD);        

    cui_menu_run(WEDITOR_CTX->menu_cui_group_id);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
}

/* /////////////////////////////////////////////////////////////////////// */

/* initialize some global variables local to this file */


/*****************************************************************************
 * FUNCTION
 *  widget_setup_fullscreen_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object              [IN]         
 *  src                 [IN]         
 *  maxlen              [IN]        The UCS2 character count including terminating character ('\0')
 *  type                [IN]        
 *  input_required      [IN]        
 *  title               [IN]        
 *  CSS_format          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_setup_fullscreen_editor(
        widget_header_struct *object,
        kal_uint8 *src,
        int maxlen,
        MsfTextType type,
        kal_int8 input_required,
        MsfStringHandle title,
        const char *CSS_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_IN_INSERT_MODE;
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
    if (CSS_format && (type == MsfPasswordText || type == MsfPasswordNumber))
    {
        if (!app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*m") ||
            !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"m*m") ||
            !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*M") ||
            !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"M*M"))
        {
            /* If CSS format is *m, m*m, *M, M*M, we use the general fullscreen editor */
            WEDITOR_CTX->CSS_format = NULL;
        }
        else
        {
            /* If CSS format isn't *m, m*m, *M, M*M, we use WCSS editor */
            WEDITOR_CTX->CSS_format = CSS_format;
            WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE;
        }
    }
    else if (!CSS_format || !CSS_format[0] || 
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*m") ||
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"m*m") ||
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*M") ||
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"M*M"))
    {
        /* Keep input type unchanged */
        WEDITOR_CTX->CSS_format = NULL;
    }
    else if (!CSS_format || !CSS_format[0] || 
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*N"))
    {
        type = MsfNumber;
        WEDITOR_CTX->CSS_format = NULL;
        WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE;
    }
    else if (!CSS_format || !CSS_format[0] || 
             !app_ucs2_strcmp((const kal_int8*)CSS_format, (const kal_int8*)L"*n"))
    {
        type = MsfInteger;
        WEDITOR_CTX->CSS_format = NULL;
        WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE;
    }
    else
    {
        type = MsfText;
        WEDITOR_CTX->CSS_format = CSS_format;
        WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE;
    }
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 

    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    WEDITOR_CTX->active_object = object;
    WEDITOR_CTX->input_buffer = src;
    WEDITOR_CTX->input_buffer_max_len = maxlen;
    WEDITOR_CTX->texttype = type;
    WEDITOR_CTX->input_required = input_required;
    WEDITOR_CTX->disable_switch_IM = KAL_FALSE;
    WEDITOR_CTX->disable_symbol_picker = KAL_FALSE;
    WEDITOR_CTX->title = title;

    if (WEDITOR_CTX->CSS_format)
    {
        WEDITOR_CTX->disable_switch_IM = KAL_TRUE;
    }

    switch (type)
    {
            /* Reference: widget_input_gadget_use_fullscreen_editor() */
//        case MsfNumeric:  //Not in use.
        case MsfNumber:
            /* allow the entry of any numeric character */
            // TODO: It seems that IMM_INPUT_TYPE_NUMERIC will disable symbol picker, but we need it
            //WEDITOR_CTX->input_type = IMM_INPUT_TYPE_NUMERIC | INPUT_TYPE_OVERRIDE_DEFAULT;
            WEDITOR_CTX->input_type = IMM_INPUT_TYPE_NUMERIC;
            WEDITOR_CTX->disable_switch_IM = KAL_TRUE;
            break;
//        case MsfIpAddress:    //Not in use.
        case MsfInteger:
            /* allow the entry of any numeric, symbol, or punctuation character */
            WEDITOR_CTX->input_type = IMM_INPUT_TYPE_NUMERIC_SYMBOL;
            WEDITOR_CTX->disable_switch_IM = KAL_TRUE;
            break;
        case MsfPasswordText:
            //WEDITOR_CTX->input_type =
            //    IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_OVERRIDE_DEFAULT;
            WEDITOR_CTX->input_type =
                IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD /*| INPUT_TYPE_OVERRIDE_DEFAULT*/;
            break;
        case MsfPasswordNumber:
            WEDITOR_CTX->input_type = IMM_INPUT_TYPE_NUMERIC_PASSWORD/* | INPUT_TYPE_OVERRIDE_DEFAULT*/;
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
        case MsfMMIDefaultInputMethod:
            WEDITOR_CTX->input_type = IMM_INPUT_TYPE_SENTENCE;
            break;
        case MsfUpperCase:
            WEDITOR_CTX->input_type = IMM_INPUT_TYPE_SENTENCE;
            break;
        case MsfText:
            /* FALLTHROUGH no break */
        default:
            WEDITOR_CTX->input_type = IMM_INPUT_TYPE_SENTENCE;
    }
}

/* Return non-zero value for error message ID, and 0 for valid filename */


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

/* 1: ok 0: fail */


/*****************************************************************************
 * FUNCTION
 *  widget_check_fullscreen_editor_input_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  go_back_history_if_fail     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int widget_check_fullscreen_editor_input_value(kal_bool go_back_history_if_fail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*fail_callback) (void);

    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (go_back_history_if_fail)
    {
        fail_callback = widget_goback_history1; /* leave the option menu */
    }
    else
    {
        fail_callback = mmi_frm_scrn_close_active_id;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 Not in use */

    if (WEDITOR_CTX->input_required == 1 /* 1 true, 0 false, -1 none */  &&
        CHR_AT(WEDITOR_CTX->input_buffer, 0) == CHR(0))
    {
        /*wap_entry_widget_editor_message(
            IMG_GLOBAL_ERROR,
            GetString(WIDGET_STR_ID_CANT_INPUT_EMPTY_VALUE),
            fail_callback);*/
		wap_entry_widget_editor_message(
            MMI_EVENT_ERROR,
            GetString(WIDGET_STR_ID_CANT_INPUT_EMPTY_VALUE),
            fail_callback);
        return 0;
    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
	/* Because WCSS editor doesn't support password mark, we need to check the WCSS format all the time */
	if(!widget_is_match_CSS_pattern(WEDITOR_CTX->input_buffer))
	{
	    char * format = (char*)widget_get_input_CSS_format_pattern();

        if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*A") ||
            !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"A*A"))
        {
            /* allow the entry of any uppercase letter, symbol, or punctuation character, Numeric characters are excluded. */
		    /*wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_A),fail_callback);*/
			wap_entry_widget_editor_message(MMI_EVENT_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_A),fail_callback);
        }
        else if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*a") ||
                 !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"a*a"))
        {
            /* allow the entry of any lowercase letter, symbol, or punctuation character, Numeric characters are excluded. */
		    /*wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_A),fail_callback);*/
			wap_entry_widget_editor_message(MMI_EVENT_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_A),fail_callback);
        }
        else if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*X") ||
                 !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"X*X"))
        {
            /* allow the entry of any uppercase letter, numeric, symbol, or punctuation character */
		    /*wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_X),fail_callback);*/
			wap_entry_widget_editor_message(MMI_EVENT_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_X),fail_callback);
        }
        else if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*x") ||
                 !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"x*x"))
        {
            /* allow the entry of any lowercase letter, numeric, symbol, or punctuation character */
		    /*wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_X),fail_callback);*/
			wap_entry_widget_editor_message(MMI_EVENT_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_X),fail_callback);
        }
        else if (!app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"*n") ||
                 !app_ucs2_strcmp((const kal_int8*)format, (const kal_int8*)L"n*n"))
        {
            /* allow the entry of any numeric, symbol, or punctuation character */
		    /*wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_N),fail_callback);*/
			wap_entry_widget_editor_message(MMI_EVENT_ERROR, 
			    GetString(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_N),fail_callback);
        }
        else
        {
		    /*wap_entry_widget_editor_message(IMG_GLOBAL_ERROR, 
			    GetString(WIDGET_STR_ID_INPUT_FORMAT_ERROR),fail_callback);*/
			wap_entry_widget_editor_message(MMI_EVENT_ERROR, 
			    GetString(WIDGET_STR_ID_INPUT_FORMAT_ERROR),fail_callback);
        }
		return 0;	
	}
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 

    return 1;
}

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__

#if (CAT115_MAXSIZE - 1 < WIDGET_MAX_INPUT_LEN)
#error "Values of CAT115_MAXSIZE  and WIDGET_MAX_INPUT_LEN are not sync"
#endif 


//#ifndef __MMI_TOUCH_SCREEN__    //MAUI_02442437


static void wap_entry_WCSS_editor(void);
static widget_wcss_event_handler_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        switch(menu_evt->highlighted_menu_id)
        {
        case WAP_MENU_FULLSCREEN_EDITOR_OPTION_DONE:
#ifdef __COSMOS_MMI_PACKAGE__
		#ifdef __MMI_BROWSER_2__
		vappBrwCloseWapEditor();
        #endif
#else
            widget_exit_fullscreen_editor_with_done();
#endif
            if (WEDITOR_CTX->group_id)
            {
                mmi_frm_group_close(WEDITOR_CTX->group_id);
            }
            WEDITOR_CTX->group_id = 0;
            WEDITOR_CTX->menu_cui_group_id = 0;
            break;
            
        case WAP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL:
#ifdef __COSMOS_MMI_PACKAGE__
			#ifdef __MMI_BROWSER_2__
			vappBrwCloseWapEditor();
            #endif
#else
            widget_exit_fullscreen_editor_with_cancel_level1();
#endif
            if (WEDITOR_CTX->group_id)
            {
                mmi_frm_group_close(WEDITOR_CTX->group_id);
            }
            WEDITOR_CTX->group_id = 0;
            WEDITOR_CTX->menu_cui_group_id = 0;
            break;
        }
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (WEDITOR_CTX->menu_cui_group_id)
            {
                cui_menu_close(menu_evt->sender_id);
            }
            WEDITOR_CTX->menu_cui_group_id = 0;
            break;
    case EVT_ID_GROUP_EXIT:
            if (WEDITOR_CTX->group_id)
            {
                mmi_frm_group_close(WEDITOR_CTX->group_id);
                WEDITOR_CTX->group_id = 0;
                WEDITOR_CTX->menu_cui_group_id = 0;
            }
    }
	return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  wap_entry_WCSS_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_WCSS_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    kal_uint8 *input_format;
    int input_format_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WCSS_EDITOR);
    if (!WEDITOR_CTX->group_id)
    {
        /*WEDITOR_CTX->group_id = mmi_frm_group_create(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN, 
            widget_wcss_event_handler_proc,
            NULL); 

        mmi_frm_group_enter(WEDITOR_CTX->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);*/
		
		WEDITOR_CTX->group_id = mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN, 
            widget_wcss_event_handler_proc,
            NULL,
			MMI_FRM_NODE_SMART_CLOSE_FLAG); 
    }
    /* Category115 use UCS2 string for input format */
    if (WEDITOR_CTX->CSS_format)
    {
        input_format_len = app_ucs2_strlen((const kal_int8 *)WEDITOR_CTX->CSS_format);
        input_format_len = (input_format_len + 1) * ENCODING_LENGTH;
#ifdef WAP_USE_ASM
        input_format = widget_internal_mem_alloc(MSF_MODID_WIDGET, input_format_len);
#else
        input_format = MSF_MEM_ALLOC(MSF_MODID_WIDGET, input_format_len);
#endif
        app_ucs2_strcpy((kal_int8*)input_format, (const kal_int8*)WEDITOR_CTX->CSS_format);
    }
    else
    {
        input_format = (kal_uint8*) L"*m";
        input_format_len = 6;
    }
 if(mmi_frm_scrn_enter(WEDITOR_CTX->group_id, WAP_SCREEN_WCSS_EDITOR, NULL, wap_entry_WCSS_editor, MMI_FRM_FULL_SCRN))
 {
   // EntryNewScreen(WAP_SCREEN_WCSS_EDITOR, wap_exit_WCSS_editor, NULL, NULL);
   guiBuffer = mmi_frm_scrn_get_gui_buf(WEDITOR_CTX->group_id, WAP_SCREEN_WCSS_EDITOR);

    ShowCategory115Screen_ext(
        WIDGET_STR_ID_INPUT_TITLE,
        widget_get_title_icon(0),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) WEDITOR_CTX->input_buffer,
        WEDITOR_CTX->input_buffer_max_len,
        (U8*) input_format,
        1,
        WEDITOR_CTX->input_type,
        guiBuffer);

    SetLeftSoftkeyFunction(wap_entry_fullscreen_editor_option, KEY_EVENT_UP);
    SetCategory115RightSoftkeyFunction(widget_exit_fullscreen_editor_with_cancel_level0, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(widget_exit_fullscreen_editor_with_done,KEY_EVENT_UP);
    if (WEDITOR_CTX->CSS_format)
    {
#ifdef WAP_USE_ASM
        widget_internal_mem_free(MSF_MODID_WIDGET, input_format);
#else
        MSF_MEM_FREE(MSF_MODID_WIDGET, input_format);
#endif
    }
}
}

//#endif /* __MMI_TOUCH_SCREEN__ */   //MAUI_02442437

#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */ 

#ifdef WIDGET_LEAVE_EDITOR_IF_RELEASED
/* We need to leave full screen editor if the WAP page is reloaded (e.g. a script to reload the page periodically) */


/*****************************************************************************
 * FUNCTION
 *  widget_dummy_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_dummy_screen (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

  //  GoBackHistory();
}
/*****************************************************************************
 * FUNCTION
 *  widget_MMI_leave_fullscreen_editor_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_leave_fullscreen_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_BROWSER_2__
    vappBrwCloseWapEditor();
    WGUI_CTX->resume_rendering = KAL_TRUE;
#endif
#else
    if (WEDITOR_CTX->editor_id)
		{
        cui_fseditor_close(WEDITOR_CTX->editor_id);
        mmi_frm_group_close (WEDITOR_CTX->group_id);
        WEDITOR_CTX->group_id = 0;
        WEDITOR_CTX->editor_id = 0;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  widget_leave_fullscreen_editor_screen_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_leave_fullscreen_editor_screen_if_present(widget_header_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object && WEDITOR_CTX->active_object == object)
    {
        /* Actually this should not happen */
        WEDITOR_CTX->active_object = NULL;
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;

        if (WIPC_CTX->MMI_is_waiting)
        {
            widget_MMI_leave_fullscreen_editor_screen();
        }
        else
        {
            widget_execute_MMI(widget_MMI_leave_fullscreen_editor_screen, KAL_TRUE);
        }
    }
}
#else /* WIDGET_LEAVE_EDITOR_IF_RELEASED */ 


/*****************************************************************************
 * FUNCTION
 *  widget_leave_fullscreen_editor_screen_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_leave_fullscreen_editor_screen_if_present(widget_header_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object && WEDITOR_CTX->active_object == object)
    {
        /* Actually this should not happen */
        WEDITOR_CTX->active_object = NULL;
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    }
}

#endif /* WIDGET_LEAVE_EDITOR_IF_RELEASED */ 


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_delete_symbol_picker_screen_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_delete_symbol_picker_screen_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret = 0;
    U16 scrid = CTK_BASE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_widget_context )	      //MAUI_03325866															//MAUI_03325866
	{
    if (WEDITOR_CTX->editor_id)
	{
        cui_fseditor_close(WEDITOR_CTX->editor_id);
        mmi_frm_group_close (WEDITOR_CTX->group_id);
        WEDITOR_CTX->group_id = 0;
        WEDITOR_CTX->editor_id = 0;
	}
     if(WEDITOR_CTX->group_id)
     {
          mmi_frm_group_close (WEDITOR_CTX->group_id);
          WEDITOR_CTX->group_id = 0;
     }
	}

  
}

#ifdef __COSMOS_MMI_PACKAGE__
void widget_accept_fullscreen_input_from_browser(kal_uint8 *inputbuffer)
{
    widget_ucs2_strcpy(WEDITOR_CTX->input_buffer, (U8*)inputbuffer);
    widget_exit_fullscreen_editor_with_done();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor_with_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_fullscreen_editor_with_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check the validity of input value
     * * For some cases, we also check input values in widget_set_current_focus()
     */
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
#ifndef __COSMOS_MMI_PACKAGE__
    if (!widget_check_fullscreen_editor_input_value(KAL_TRUE))
    {
        return;
    }
#endif

    widget_init_paint_input_gadget();   // Discarding buffer.
    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_DONE;
    WEDITOR_CTX->active_object = NULL;
     /* WEDITOR_CTX->leave_from_fullscreen will be TRUE when leaving from widget fullscreen option menu. */
    WEDITOR_CTX->leave_from_fullscreen = KAL_TRUE;
#ifndef __COSMOS_MMI_PACKAGE__
    if (WEDITOR_CTX->group_id)
    {    
         mmi_frm_group_close(WEDITOR_CTX->group_id);
         WEDITOR_CTX->group_id = 0;
         WEDITOR_CTX->menu_cui_group_id = 0;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor_with_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_fullscreen_editor_with_cancel(int level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_uint8 backup_editor_buffer[STR_SIZE(WIDGET_MAX_INPUT_LEN + 1)];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    widget_copy_editor_buffer(WEDITOR_CTX->input_buffer, backup_editor_buffer);
    widget_init_paint_input_gadget();

    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_CANCEL;
    WEDITOR_CTX->active_object = NULL;
     /* WEDITOR_CTX->leave_from_fullscreen will be TRUE when leaving from widget fullscreen option menu. */
    WEDITOR_CTX->leave_from_fullscreen = KAL_TRUE;
    if (WEDITOR_CTX->group_id)
    {
	mmi_frm_group_close(WEDITOR_CTX->group_id);
    }
     WEDITOR_CTX->group_id = 0;

}


/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor_with_cancel_level0
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_exit_fullscreen_editor_with_cancel_level0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_exit_fullscreen_editor_with_cancel(0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_exit_fullscreen_editor_with_cancel_level1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_exit_fullscreen_editor_with_cancel_level1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_exit_fullscreen_editor_with_cancel(1);
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_insert_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_insert_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_direct_input((UI_character_type) c);
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_insert_character_dot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_insert_character_dot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_fullscreen_editor_insert_character(CHR('.'));
}



#ifdef WIDGET_TEST_CHINESE_TEXT_INPUT


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_insert_chinese_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_insert_chinese_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_fullscreen_editor_insert_character(0x4E2D);
    widget_fullscreen_editor_insert_character(0x6587);
    widget_fullscreen_editor_insert_character(0x6E2C);
    widget_fullscreen_editor_insert_character(0x8A66);
    widget_fullscreen_editor_insert_character(0x5B57);
    widget_fullscreen_editor_insert_character(0x4E32);
    widget_fullscreen_editor_insert_character(0x7532);
    widget_fullscreen_editor_insert_character(0x4E59);
    widget_fullscreen_editor_insert_character(0x4E19);
    widget_fullscreen_editor_insert_character(0x4E01);
    widget_fullscreen_editor_insert_character(0x0065);
    widget_fullscreen_editor_insert_character(0x0066);
    widget_fullscreen_editor_insert_character(0x0067);

}
#endif /* WIDGET_TEST_CHINESE_TEXT_INPUT */ 


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_editor_customize_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fullscreen_editor_customize_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI WCSS editor will disable/enable '#' key by itself */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 unsed code */
#ifdef WIDGET_TEST_CHINESE_TEXT_INPUT
    SetKeyHandler((FuncPtr) widget_fullscreen_editor_insert_chinese_string, KEY_STAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_STAR, KEY_EVENT_UP);
#endif /* WIDGET_TEST_CHINESE_TEXT_INPUT */ 
}




/*****************************************************************************
 * FUNCTION
 *  wap_entry_fullscreen_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 left_softkey = STR_GLOBAL_OPTIONS;
    S16 input_ext_type = 0;
     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_FULLSCREEN_EDITOR);

    WEDITOR_CTX->entered = KAL_TRUE;
#ifndef __COSMOS_MMI_PACKAGE__
    WGUI_CTX->is_widget_screen = 0;
    WGUI_CTX->resume_rendering = 0;
#endif
    if (!WEDITOR_CTX->disable_gui_buffer)
    {
          guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    }
    else
    {
        /* Disable history such that the cursor will move to the last position */
        guiBuffer = NULL;
        WEDITOR_CTX->disable_gui_buffer = KAL_FALSE;
    }


/*
    if (WEDITOR_CTX->texttype == MsfEmailAddress)
    {
        
        input_ext_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    }
*/

#ifdef __COSMOS_MMI_PACKAGE__
    {
        S32 lock_count = 0;
        gdi_layer_get_frame_buffer_lock_count(&lock_count);
        if(lock_count > 0)
        {
            gui_unlock_double_buffer();
            widget_reset_active_layer();
            WGUI_CTX->lock_buffer_level--;
			#ifdef __MMI_BROWSER_2__
    	    vappBrwDisplayWapEditor(screendata);
            widget_internal_mem_free(MSF_MODID_WIDGET,screendata);
			#endif
            gui_lock_double_buffer();
            WGUI_CTX->lock_buffer_level++;
        }
        else
        {
			#ifdef __MMI_BROWSER_2__
    	    vappBrwDisplayWapEditor(screendata);
            #endif
        }

    }


#else
    /* Prevent title blinking */
    gui_lock_double_buffer();

/* If WEDITOR_CTX->group_id is zero then only we should create a group */
    if (!WEDITOR_CTX->group_id)
    {
    /*    WEDITOR_CTX->group_id = mmi_frm_group_create(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN, 
            widget_fseditor_event_handler_proc,
        NULL); 

        mmi_frm_group_enter(WEDITOR_CTX->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);*/
      
		WEDITOR_CTX->group_id = mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_AUTO_GEN, 
            widget_fseditor_event_handler_proc,
			NULL,
			MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    WEDITOR_CTX->editor_id = cui_fseditor_create(WEDITOR_CTX->group_id);

    ASSERT( WEDITOR_CTX->editor_id);

    cui_fseditor_set_title( WEDITOR_CTX->editor_id, WIDGET_STR_ID_INPUT_TITLE, widget_get_title_icon(0));
    cui_fseditor_set_text( WEDITOR_CTX->editor_id, (WCHAR*)WEDITOR_CTX->input_buffer, WEDITOR_CTX->input_buffer_max_len * ENCODING_LENGTH, WEDITOR_CTX->input_buffer_max_len - 1);
    cui_fseditor_set_input_method( WEDITOR_CTX->editor_id, WEDITOR_CTX->input_type, 0, input_ext_type);
    cui_fseditor_run( WEDITOR_CTX->editor_id); 


    if (WEDITOR_CTX->in_replace_mode == WIDGET_FULLSCREEN_EDITOR_WANT_IN_REPLACE_MODE)
    {
        /*
         * If WCSS format is "*n" or "*N", 
         * we use Category5Screen but need change to replace mode. 
         */
        multiline_inputbox_toggle_insert_mode();
        WEDITOR_CTX->in_replace_mode = WIDGET_FULLSCREEN_EDITOR_IN_REPLACE_MODE;
    }
#ifndef __MMI_MAINLCD_320X240__
/* In Landscape 320x240, we don't have title/status bar in fullscreen editor */
    if (WEDITOR_CTX->title != 0)
    {
        widget_set_title(WEDITOR_CTX->title);
        /* ShowCategory5Screen already use show_title_status_icon() */
        draw_title();
    }
#endif /* #ifndef __MMI_MAINLCD_320X240__ */
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);



    /* customize key */
    widget_fullscreen_editor_customize_key();
#endif

}

/*****************************************************************************
 * FUNCTION
 *  widget_fseditor_event_handler_proc
 * DESCRIPTION  : This is the proc function which will handle the events which are sent by Editor CUI.
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret widget_fseditor_event_handler_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        
    case EVT_ID_CUI_FSEDITOR_SUBMMIT:
   
           cui_fseditor_get_text(WEDITOR_CTX->editor_id, (WCHAR*)WEDITOR_CTX->input_buffer, WEDITOR_CTX->input_buffer_max_len * ENCODING_LENGTH);

#ifdef __COSMOS_MMI_PACKAGE__
		#ifdef __MMI_BROWSER_2__
		vappBrwCloseWapEditor();
        #endif
#else
                widget_exit_fullscreen_editor_with_done();
#endif

		if (!WGUI_CTX->is_popup_displayed)
		{
                    cui_fseditor_close(WEDITOR_CTX->editor_id);
                    WEDITOR_CTX->editor_id = 0;
	            if (WEDITOR_CTX->group_id)
	            {
                        mmi_frm_group_close (WEDITOR_CTX->group_id);
                        WEDITOR_CTX->group_id = 0;
	            }
	        }
	        else
		{
		    WGUI_CTX->is_popup_displayed = KAL_FALSE;
		}

            break;

       /* when user cancel edit (Select Cancel in Options or Press RSK (Back)) */
    case  EVT_ID_CUI_FSEDITOR_ABORT:
#ifdef __COSMOS_MMI_PACKAGE__
		#ifdef __MMI_BROWSER_2__
		vappBrwCloseWapEditor();
        #endif
#else
        widget_exit_fullscreen_editor_with_cancel_level0();
#endif
        cui_fseditor_close(WEDITOR_CTX->editor_id);
        WEDITOR_CTX->editor_id = 0;
        mmi_frm_group_close (WEDITOR_CTX->group_id);
        WEDITOR_CTX->group_id = 0;
        break;

        /* when edit content change to empty */
    case EVT_ID_CUI_FSEDITOR_EMPTY:

        break;


        /* when edit content change to not empty */
    case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:

     break;

    default:
        break;
    }
     return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  widget_enter_fullscreen_editor
 * DESCRIPTION
 *  enter full screen editor and put widget screen into history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enter_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_uint8 backup_editor_buffer[STR_SIZE(WIDGET_MAX_INPUT_LEN + 1)];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* we only backup the buffer for the first time */
    widget_copy_editor_buffer(backup_editor_buffer, WEDITOR_CTX->input_buffer);

    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());   /* It should be invoked from widget_paint_hdlr */

/*#ifndef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
    wap_entry_fullscreen_editor();

#elif defined (__MMI_WCSS_INPUT_FORMAT_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
    /* WCSS editor (Category115Screen) only supported in non touch screen project */
   // wap_entry_fullscreen_editor();

/*#else /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ 
    if (WEDITOR_CTX->CSS_format)
    {
        wap_entry_WCSS_editor();
    }
    else
    {
        wap_entry_fullscreen_editor();
    }
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */   // MAUI_02442437 starts
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
 if (WEDITOR_CTX->CSS_format)
    {
        wap_entry_WCSS_editor();
    }
 else
   wap_entry_fullscreen_editor();
#else
wap_entry_fullscreen_editor();
#endif

// MAUI_02442437 ends
}

/******************************************************************************
 * Internal dialog category screen 
 ******************************************************************************/

/*
 * Since we do not enter a new category screen for dialog, 
 * * There is no explicit exit point of this category 123 since we might close the window by MsfAction
 * * As a result, we just call gui_hide_animations() in widget_paint
 */


/*
 * Be very careful that we do not put widget screen into history on invoking widget_ShowCategory123Screen
 * However, we will temporarily override RedrawCategoryFunction as widget_RedrawCategory123Screen()
 */


/*****************************************************************************
 * FUNCTION
 *  widget_RedrawCategory123Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_RedrawCategory123Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

#ifdef __MMI_CHANGABLE_FONT__
    //U8 old_font_size;
    UI_font_type old_text_font;
#endif 
#if defined(__MMI_FTE_SUPPORT__)
    GDI_HANDLE hint_layer;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    gui_hide_animations();
    x1 = MMI_pop_up_dialog_x;
    y1 = MMI_pop_up_dialog_y;
    x2 = x1 + MMI_pop_up_dialog_width - 1;
    y2 = y1 + MMI_pop_up_dialog_height - 1;
    gui_reset_clip();
    wgui_draw_pop_up_screen_background(x1, y1, x2, y2, &wgui_pop_up_dialog_background, MMI_FALSE);

#ifdef __GDI_MEMORY_PROFILE_2__
	if (wgui_layer_1 == (gdi_handle) NULL)
	{
		/* Create layer fail */
		if (gdi_layer_create(0, 0, UI_device_width, UI_device_height, &wgui_layer_1) < 0)
		{
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
			return;
		}
	}

	gdi_layer_push_and_set_active(wgui_layer_1);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(TRUE, (U8)(current_MMI_theme->bg_opacity_full));
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#endif /* __GDI_MEMORY_PROFILE_2__ */

#ifdef __MMI_CHANGABLE_FONT__
    //old_font_size = MMI_multiline_inputbox.text_font->size;
    //MMI_multiline_inputbox.text_font->size = MEDIUM_FONT;
    old_text_font = MMI_multiline_inputbox.text_font;
    MMI_multiline_inputbox.text_font = &MMI_medium_font;

    show_multiline_inputbox();

    //MMI_multiline_inputbox.text_font->size = old_font_size;
    MMI_multiline_inputbox.text_font = old_text_font;
#else /* __MMI_CHANGABLE_FONT__ */ 
    show_multiline_inputbox();
#endif /* __MMI_CHANGABLE_FONT__ */ 

    gui_set_clip(x1 + 2, y1 + 2, x2 - 2, y2 - 2);
    wgui_show_transparent_animation();

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
	gdi_layer_flatten(wgui_base_layer, wgui_layer_1, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
    gdi_set_alpha_blending_source_layer(wgui_base_layer);
#if defined(__MMI_FTE_SUPPORT__)
    hint_layer = wgui_icon_bar_get_hint_layer_handle();
    gdi_layer_set_blt_layer(wgui_base_layer, wgui_layer_1, hint_layer, 0);
#else
    gdi_layer_set_blt_layer(wgui_base_layer, wgui_layer_1, 0, 0);
#endif /* __MMI_FTE_SUPPORT__*/
#endif /* __GDI_MEMORY_PROFILE_2__ */

#if !defined(__MMI_MAINLCD_320X480__)
    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
#endif
    gui_unlock_double_buffer();
/*
    if ((widget_browserv2_check_version() == WIDGET_BROWSER_V1) || (widget_browserv2_check_version() == WIDGET_BROWSER_V2_WITH_MMSV01_CALLER_MMS))
    {
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
    else
*/
    {
        gui_BLT_double_buffer(WGUI_CTX->display_pos.x, WGUI_CTX->display_pos.y, (WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width) , (WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height));
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_ShowCategory123Screen_Common
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_bottom            [IN]        
 *  title                   [IN]        
 *  title_icon              [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  message                 [IN]        
 *  message_icon            [IN]        
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_ShowCategory123Screen_Common
    (int image_bottom,
     U16 title, U16 title_icon, U16 left_softkey, U16 left_softkey_icon,
     U16 right_softkey, U16 right_softkey_icon, UI_string_type message, U16 message_icon, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l, fh;
    PU8 image;
    S32 width = 0, height = 0;
    S32 inputbox_h;
    S32 dialog_width = MMI_pop_up_dialog_width - 2*UI_POPUP_BORDER_SIZE;
    S32 x = MMI_pop_up_dialog_x + UI_POPUP_BORDER_SIZE;
    S32 y = MMI_pop_up_dialog_y + UI_POPUP_BORDER_SIZE;
    S32 dialog_y = MMI_pop_up_dialog_y + UI_POPUP_BORDER_SIZE;
#if defined(__MMI_MAINLCD_320X480__)
	S32 dialog_height = MMI_POP_UP_SOFTKEY_Y - MMI_POP_UP_DIALOG_Y - 2*UI_POPUP_BORDER_SIZE;
#else
    S32 dialog_height = MMI_pop_up_dialog_height - 2*UI_POPUP_BORDER_SIZE;
#endif
	
#ifdef __MMI_CHANGABLE_FONT__
    // U8 old_font_size;
    UI_font_type old_text_font;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_register_integrated_redraw(NULL);
#endif
#if defined (WIDGET_RESIDENT_STATUS_ICON)

    if (WGUI_CTX->current_window && WGUI_CTX->current_dialog &&
        _W(WGUI_CTX->current_window) == _W(WGUI_CTX->current_dialog) &&
        (WGUI_CTX->current_dialog->property_mask & MSF_WINDOW_PROPERTY_EXT_STATUS_ICON))
    {
        /*
         * widget will clear the screen in widget_paint_object (WIDGET_DIALOG_TYPE) and 
         * we need to show the status bar in MsfDialog
         */
    }
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 

    gui_lock_double_buffer();


    image = get_image(message_icon);
    gui_measure_image(image, &width, &height);
    MMI_message_string = (UI_string_type) message;  /* get_string(message); */
    l = gui_strlen(MMI_message_string);
    create_multiline_inputbox_set_buffer(MMI_message_string, l, l, 0);
    MMI_multiline_inputbox.normal_text_color = *current_MMI_theme->popup_text_color;
    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
         UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR);
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;
    resize_multiline_inputbox(dialog_width, dialog_height);
    show_multiline_inputbox_no_draw();

#ifdef __MMI_CHANGABLE_FONT__
    //old_font_size = MMI_multiline_inputbox.text_font->size;
    //MMI_multiline_inputbox.text_font->size = MEDIUM_FONT;
    old_text_font = MMI_multiline_inputbox.text_font;
    MMI_multiline_inputbox.text_font = &MMI_medium_font;
    
#endif /* __MMI_CHANGABLE_FONT__ */ 

    gui_set_font(MMI_multiline_inputbox.text_font);
    fh = get_multiline_inputbox_line_height();
    if (image == NULL)
    {
        inputbox_h = (MMI_multiline_inputbox.n_lines * fh) + MMI_multiline_inputbox.text_y + MULTILINE_INPUTBOX_HEIGHT_PAD;

        /* Line height of multi-line inputbox is font height + 1 */
        inputbox_h = (inputbox_h < (dialog_height)) 
                        ? inputbox_h 
                        : (dialog_height);
        resize_multiline_inputbox(
            MMI_multiline_inputbox.width,
            inputbox_h);
        y = dialog_y + ((dialog_height - MMI_multiline_inputbox.height) >> 1);
    }
    else
    {
        inputbox_h = (MMI_multiline_inputbox.n_lines * fh) + MMI_multiline_inputbox.text_y + MULTILINE_INPUTBOX_HEIGHT_PAD;

        inputbox_h = (inputbox_h < (dialog_height - height)) 
                        ? inputbox_h 
                        : (dialog_height - height);
        resize_multiline_inputbox(MMI_multiline_inputbox.width, inputbox_h);

        y = dialog_y + (dialog_height >> 1) - ((MMI_multiline_inputbox.height + height) >> 1);
    }
    
    if (y < dialog_y)
    {
        y = dialog_y;
    }
    if (!image_bottom)
    {
        wgui_set_animation_image_y((UI_device_width >> 1), y, image);
        if (image == NULL)
        {
            move_multiline_inputbox(x, y);
        }
        else
        {
            move_multiline_inputbox(x, y + height);
        }
    }
    else
    {
        /* should have the image */
        move_multiline_inputbox(x, y);
        wgui_set_animation_image_y((UI_device_width >> 1), y + MMI_multiline_inputbox.height, image);
    }
#ifdef __MMI_CHANGABLE_FONT__
    //MMI_multiline_inputbox.text_font->size = old_font_size;
     MMI_multiline_inputbox.text_font = old_text_font;
#endif 

    gui_unlock_double_buffer();
    /* We do not create a new screen in addition to widget */

    widget_RedrawCategory123Screen();
}


/*****************************************************************************
 * FUNCTION
 *  widget_ShowCategory123Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                   [IN]        
 *  title_icon              [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  message                 [IN]        
 *  message_icon            [IN]        
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ShowCategory123Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        UI_string_type message,
        U16 message_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ShowCategory123Screen_Common
        (0,
         title, title_icon, left_softkey, left_softkey_icon,
         right_softkey, right_softkey_icon, message, message_icon, history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ShowCategory123Screen_ImageBottom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                   [IN]        
 *  title_icon              [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  message                 [IN]        
 *  message_icon            [IN]        
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void widget_ShowCategory123Screen_ImageBottom
    (U16 title, U16 title_icon, U16 left_softkey, U16 left_softkey_icon,
     U16 right_softkey, U16 right_softkey_icon, UI_string_type message, U16 message_icon, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_ShowCategory123Screen_Common
        (1,
         title, title_icon, left_softkey, left_softkey_icon,
         right_softkey, right_softkey_icon, message, message_icon, history_buffer);
}

/******************************************************************************
 * Fullscreen menu
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_radio_menu_okay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fullscreen_radio_menu_okay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (menu != NULL)
    {
        widget_notify(_H(menu), MsfNotifyStateChange);

        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                    if (cnt == WENTER_MENU_CTX->highlighted)
                        enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED); 
                    cnt++;
                }
            }
        );

        menu->highlight_index = -1;
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_OK;
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close (WEDITOR_CTX->group_id);
#endif
    }
    else
    {
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close (WEDITOR_CTX->group_id);
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_radio_menu_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fullscreen_radio_menu_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
#ifdef __COSMOS_MMI_PACKAGE__
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_CANCEL;
#else

    if (WENTER_MENU_CTX->target_menu != NULL)
    {
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_CANCEL;
        mmi_frm_group_close (WEDITOR_CTX->group_id);
    }
    else
    {
        mmi_frm_group_close (WEDITOR_CTX->group_id);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  highlight_widget_fullscreen_radio_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void highlight_widget_fullscreen_radio_menu(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WENTER_MENU_CTX->highlighted = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_radio_menu_get_item_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL widget_fullscreen_radio_menu_get_item_hdlr(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;
    MsfStringHandle string1 = 0;
    int cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu == NULL || item_index < 0 || item_index >= menu->menu_items_sum)
    {
        SET_CHR_AT(str_buff, 0, 0);
        *img_buff_p = NULL;
        return TRUE;
    }
    else
    {
        /* widget_get_childs_by_index(node, menu, item_index); */
        cnt = 0;
        foreach(_H(menu), CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (cnt == item_index)
                    {
                        string1 = node->string1;
                    }
                    cnt++;
                }
            }
        );

        if (string1 == 0)
        {
            SET_CHR_AT(str_buff, 0, 0);
        }
        else
        {
            widget_ucs2_strncpy((kal_uint8*) str_buff, widget_string_content(string1), MAX_SUB_MENU_SIZE);
        }
#ifndef __COSMOS_MMI_PACKAGE__
        *img_buff_p = get_image((MMI_ID_TYPE)
                                ((item_index ==
                                  WENTER_MENU_CTX->last_highlighted) ? RADIO_ON_IMAGE_ID : RADIO_OFF_IMAGE_ID));
#endif
    }
    return TRUE;
}

static S32 widget_fullscreen_radio_menu_get_Asyncitem_hdlr(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    S32 i;

	for (i = 0; i < data_size; i++)
	{
	    widget_fullscreen_radio_menu_get_item_hdlr((start_index+i), menu_data[i].item_list[0], &menu_data[i].image_list[0], 0);
	}
	return data_size;
}

/*****************************************************************************
 * FUNCTION
 *  widget_event_handler_proc
 * DESCRIPTION  : This API is event handler for the screen group created by widget for Checkbox and radio menu screens.
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret widget_event_handler_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(evt->evt_id)
    {
         case EVT_ID_GROUP_EXIT:
           {
               WEDITOR_CTX->group_id  = 0;
           }
    }
    return MMI_RET_OK;

}

#ifdef __COSMOS_MMI_PACKAGE__

/*****************************************************************************
 * FUNCTION
 *   widget_set_item_radio_menu
 * DESCRIPTION
 *  It recieves an update on the current selected item in the radio menu
    from browser 
 * PARAMETERS
 *  int (The index of the radio item selected)
 * RETURNS
 *  void
 *****************************************************************************/

void widget_set_item_radio_menu(int index)
{

WENTER_MENU_CTX->highlighted = index;

}

#endif


/*****************************************************************************
 * FUNCTION
 *  wap_entry_fullscreen_radio_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_fullscreen_radio_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	S32 category_error_flag;
	U16 left_softkey;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_FULLSCREEN_RADIO_MENU);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

#ifdef __COSMOS_MMI_PACKAGE__
    {
        S32 lock_count = 0;
        gdi_layer_get_frame_buffer_lock_count(&lock_count);
        if(lock_count > 0)
        {
            gui_unlock_double_buffer();
            widget_reset_active_layer();
            WGUI_CTX->lock_buffer_level--;
			#ifdef __MMI_BROWSER_2__
            vappBrwDisplayWapListMenu(VAPP_BRW_CHOICE_EXCLUSIVE);
            #endif
            gui_lock_double_buffer();
            WGUI_CTX->lock_buffer_level++;
        }
        else
        {
			#ifdef __MMI_BROWSER_2__
    	    vappBrwDisplayWapEditor(screendata);
            #endif
        }

    }
#endif
    /* Create a new group only when WEDITOR_CTX->group_id is zero.*/
#ifndef __COSMOS_MMI_PACKAGE__

    if (!WEDITOR_CTX->group_id)
    {
      /* WEDITOR_CTX->group_id = mmi_frm_group_create(GRP_ID_ROOT,GRP_ID_AUTO_GEN, widget_event_handler_proc,NULL);
       mmi_frm_group_enter(WEDITOR_CTX->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);*/
	   WEDITOR_CTX->group_id = mmi_frm_group_create_ex(GRP_ID_ROOT,GRP_ID_AUTO_GEN, widget_event_handler_proc,NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    if(mmi_frm_scrn_enter(WEDITOR_CTX->group_id, WAP_SCREEN_OPTION_GROUP, NULL, wap_entry_fullscreen_radio_menu, MMI_FRM_FULL_SCRN))
    {
        
    WGUI_CTX->is_widget_screen = 0;
    WGUI_CTX->resume_rendering = 0;
        guiBuffer = mmi_frm_scrn_get_gui_buf(WEDITOR_CTX->group_id, WAP_SCREEN_OPTION_GROUP);

    if (!WENTER_MENU_CTX->target_menu)
    {
        /* Abnormal case. Be paranoid. */
            SetGroupKeyHandler(mmi_frm_scrn_close_active_id, widget_all_keys, MAX_KEYS, KEY_EVENT_UP);
        return;
    }

    RegisterHighlightHandler(highlight_widget_fullscreen_radio_menu);
    if (WENTER_MENU_CTX->target_menu->menu_items_sum)
    {
        left_softkey = STR_GLOBAL_OK;
    }
    else
    {
        left_softkey = 0;
    }
	
/*	wgui_cat1032_show(
		(WCHAR*)get_string(STR_GLOBAL_OPTIONS),
		(PU8)get_image(widget_get_title_icon(0)),
		(WCHAR*)get_string(left_softkey),
		0,
		(WCHAR*)get_string(STR_GLOBAL_BACK),
                0,
                WENTER_MENU_CTX->target_menu->menu_items_sum,
		widget_fullscreen_radio_menu_get_Asyncitem_hdlr,
                NULL,
                WENTER_MENU_CTX->last_highlighted,
		0,
		RADIO_ON_IMAGE_ID,
		0,
		guiBuffer,
		&category_error_flag);*/
	
	wgui_cat1043_show(
		STR_GLOBAL_OPTIONS,
		widget_get_title_icon(0),
		left_softkey,
		STR_GLOBAL_BACK,
		WENTER_MENU_CTX->target_menu->menu_items_sum,
		widget_fullscreen_radio_menu_get_Asyncitem_hdlr,
                NULL,
		WENTER_MENU_CTX->last_highlighted,
		0,
		RADIO_ON_IMAGE_ID,
		0,
		guiBuffer,
		&category_error_flag);

    SetLeftSoftkeyFunction(widget_fullscreen_radio_menu_okay, KEY_EVENT_UP);
    SetRightSoftkeyFunction(widget_fullscreen_radio_menu_back, KEY_EVENT_UP);
    if (WENTER_MENU_CTX->target_menu->menu_items_sum)
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(widget_fullscreen_radio_menu_okay, KEY_EVENT_UP);
    }
    /* In MMI screen, we trigger the key handler in KEY_EVENT_DOWN */
   // SetKeyHandler(widget_fullscreen_radio_menu_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
#endif
}

#ifdef __COSMOS_MMI_PACKAGE__
U16 widget_get_selected_radio_id(void)
{
    return WENTER_MENU_CTX->last_highlighted;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_checkbox_menu_okay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fullscreen_checkbox_menu_okay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (menu != NULL)
    {
        WAP_DBG_ASSERT(menu->checkbox_menu_list_state != NULL);
        widget_notify(_H(menu), MsfNotifyStateChange);
        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (menu->checkbox_menu_list_state[cnt])
                    {
                        disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                        enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    else
                    {
                    disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    if (cnt == WENTER_MENU_CTX->highlighted)
                    {
                    enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                    }
                    cnt++;
                }
            }
        );

#ifdef WAP_USE_ASM
        widget_internal_mem_free(MSF_MODID_WIDGET, menu->checkbox_menu_list_state);
#else
        MSF_MEM_FREE(MSF_MODID_WIDGET, menu->checkbox_menu_list_state);
#endif
        menu->checkbox_menu_list_state = NULL;
        menu->highlight_index = -1;

        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_OK;
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close (WEDITOR_CTX->group_id);
#endif
    }
    else
    {
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close (WEDITOR_CTX->group_id);
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_checkbox_menu_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_fullscreen_checkbox_menu_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (WENTER_MENU_CTX->target_menu != NULL)
    {
        if (WENTER_MENU_CTX->target_menu->checkbox_menu_list_state != NULL)
        {
#ifdef WAP_USE_ASM
            widget_internal_mem_free(MSF_MODID_WIDGET, WENTER_MENU_CTX->target_menu->checkbox_menu_list_state);
#else
            MSF_MEM_FREE(MSF_MODID_WIDGET, WENTER_MENU_CTX->target_menu->checkbox_menu_list_state);
#endif
            WENTER_MENU_CTX->target_menu->checkbox_menu_list_state = NULL;
        }
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_RETURN_CANCEL;
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close (WEDITOR_CTX->group_id);
#endif
    }
    else
    {
		#ifndef __COSMOS_MMI_PACKAGE__
        mmi_frm_group_close (WEDITOR_CTX->group_id);
        #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_widget_fullscreen_checkbox_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void highlight_widget_fullscreen_checkbox_menu(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WENTER_MENU_CTX->highlighted = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  widget_fullscreen_checkbox_menu_get_item_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  str_buff        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL widget_fullscreen_checkbox_menu_get_item_hdlr(S32 item_index, UI_string_type str_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;
    MsfStringHandle string1 = 0;
    int cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu == NULL || item_index < 0 || item_index >= menu->menu_items_sum)
    {
        SET_CHR_AT(str_buff, 0, 0);
        return TRUE;
    }
    else
    {
        /* widget_get_childs_by_index(node, menu, item_index); */
        cnt = 0;
        foreach(_H(menu), CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (cnt == item_index)
                    {
                        string1 = node->string1;
                    }
                    cnt++;
                }
            }
        );

        if (string1 == 0)
        {
            SET_CHR_AT(str_buff, 0, 0);
        }
        else
        {
            widget_ucs2_strncpy((kal_uint8*) str_buff, widget_string_content(string1), MAX_SUB_MENU_SIZE);
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_exit_fullscreen_checkbox_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_exit_fullscreen_checkbox_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu != NULL &&
        WENTER_MENU_CTX->state != WIDGET_ENTER_MENU_RETURN_OK &&
        WENTER_MENU_CTX->state != WIDGET_ENTER_MENU_RETURN_CANCEL)
    {
        WAP_DBG_ASSERT(menu->checkbox_menu_list_state != NULL);
        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (menu->checkbox_menu_list_state[cnt])
                    {
                        disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                        enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    else
                    {
                    disable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED | MSF_CHOICE_ELEMENT_SELECTED);
                    }
                    if (cnt == WENTER_MENU_CTX->highlighted)
                    {
                    enable_bit_flag(node->state, MSF_CHOICE_ELEMENT_FOCUSED);
                    }
                    cnt++;
                }
            }
        );

    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_fullscreen_checkbox_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_entry_fullscreen_checkbox_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_FULLSCREEN_CHECKBOX_MENU);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

#ifndef __COSMOS_MMI_PACKAGE__
    if (!WEDITOR_CTX->group_id)
    {
       /*
       WEDITOR_CTX->group_id = mmi_frm_group_create(GRP_ID_ROOT,GRP_ID_AUTO_GEN, widget_event_handler_proc,NULL);
       mmi_frm_group_enter(WEDITOR_CTX->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
       */
       WEDITOR_CTX->group_id = mmi_frm_group_create_ex(GRP_ID_ROOT,GRP_ID_AUTO_GEN, widget_event_handler_proc,NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    if(!mmi_frm_scrn_enter(WEDITOR_CTX->group_id, WAP_SCREEN_MULTIPLE_OPTION_GROUP, wap_exit_fullscreen_checkbox_menu, wap_entry_fullscreen_checkbox_menu, MMI_FRM_FULL_SCRN))
		return;

    WGUI_CTX->is_widget_screen = 0;
    WGUI_CTX->resume_rendering = 0;
    
        guiBuffer = mmi_frm_scrn_get_gui_buf(WEDITOR_CTX->group_id, WAP_SCREEN_MULTIPLE_OPTION_GROUP);

    if (!WENTER_MENU_CTX->target_menu)
    {
        /* Abnormal case. Be paranoid. */
            SetGroupKeyHandler(mmi_frm_scrn_close_active_id, widget_all_keys, MAX_KEYS, KEY_EVENT_UP);
        return;
    }

#endif

    if (WENTER_MENU_CTX->target_menu->checkbox_menu_list_state == NULL)
    {
#ifdef WAP_USE_ASM
        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state = widget_internal_mem_alloc(MSF_MODID_WIDGET, WENTER_MENU_CTX->target_menu->menu_items_sum * sizeof(U8));
#else
        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state = MSF_MEM_ALLOC(MSF_MODID_WIDGET, WENTER_MENU_CTX->target_menu->menu_items_sum * sizeof(U8));
#endif
        memset(
            WENTER_MENU_CTX->target_menu->checkbox_menu_list_state,
            0,
            WENTER_MENU_CTX->target_menu->menu_items_sum * sizeof(U8));
    }

    {
        int cnt = 0;
        widget_menu_struct *menu = WENTER_MENU_CTX->target_menu;
        widget_choice_element_struct *node;

        foreach(menu, CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if (node->state & MSF_CHOICE_ELEMENT_SELECTED == MSF_CHOICE_ELEMENT_SELECTED)
                    {
                        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state[cnt] = 1;
                    }
                    else
                    {
                        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state[cnt] = 0;
                    }
                    cnt++;
                }
            }
        );
    

    }
#ifndef __COSMOS_MMI_PACKAGE__
    RegisterHighlightHandler(highlight_widget_fullscreen_checkbox_menu);
    SetCheckboxToggleRightSoftkeyFunctions(widget_fullscreen_checkbox_menu_okay, widget_fullscreen_checkbox_menu_back);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   wgui_cat1047_show(
        STR_GLOBAL_OPTIONS,
        widget_get_title_icon(0),
        WENTER_MENU_CTX->target_menu->menu_items_sum,
        widget_fullscreen_checkbox_menu_get_item_hdlr,
        WENTER_MENU_CTX->target_menu->checkbox_menu_list_state,
        WENTER_MENU_CTX->last_highlighted,
        guiBuffer);   
#endif 
#else

    {
        S32 lock_count = 0;
        gdi_layer_get_frame_buffer_lock_count(&lock_count);
        if(lock_count > 0)
        {
            gui_unlock_double_buffer();
            widget_reset_active_layer();
            WGUI_CTX->lock_buffer_level--;
			#ifdef __MMI_BROWSER_2__
            vappBrwDisplayWapListMenu(VAPP_BRW_CHOICE_MULTIPLE);
            #endif
            gui_lock_double_buffer();
            WGUI_CTX->lock_buffer_level++;
        }
        else
        {
			#ifdef __MMI_BROWSER_2__
    	    vappBrwDisplayWapEditor(screendata);
            #endif
        }

    }
#endif
}

#ifdef __COSMOS_MMI_PACKAGE__

/*****************************************************************************
 * FUNCTION
 *  wwidget_return_no_of_menu_items
 * DESCRIPTION
 *  returns the no. of items present in the menu
 * PARAMETERS
 *  void    
 * RETURNS
 *  U32 (The no. of items present in the menu)
 *****************************************************************************/

U32 widget_return_no_of_menu_items(void)
{
     return WENTER_MENU_CTX->target_menu->menu_items_sum;
}


/*****************************************************************************
 * FUNCTION
 *  widget_checkbox_set_selection_state
 * DESCRIPTION
 *  updates info about the items in checkbox menu
 * PARAMETERS
 *  index of the item and its state   
 * RETURNS
 *  void
 *****************************************************************************/


void widget_checkbox_set_selection_state(int index, MMI_BOOL state)
{

 WENTER_MENU_CTX->target_menu->checkbox_menu_list_state[index] = state;
    
}
/*****************************************************************************
 * FUNCTION
 *  widget_checkbox_set_highlighted_item
 * DESCRIPTION
 *  updates highlighted item in checkbox menu
 * PARAMETERS
 *  index of the item 
 * RETURNS
 *  void
 *****************************************************************************/
/**/
void widget_checkbox_set_highlighted_item(int index)
{
	if(index < WENTER_MENU_CTX->target_menu->menu_items_sum)
        WENTER_MENU_CTX->highlighted = index;
}
/**/
/*****************************************************************************
 * FUNCTION
 *  widget_checkbox_reset_selection_state
 * DESCRIPTION
 *  reset all the items state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_checkbox_reset_selection_state(void)
{

 memset(WENTER_MENU_CTX->target_menu->checkbox_menu_list_state, 0, WENTER_MENU_CTX->target_menu->menu_items_sum);
    
}

/*****************************************************************************
 * FUNCTION
 *  widget_checkbox_get_selection_state
 * DESCRIPTION
 * 
 * PARAMETERS
 *  int index  
 * RETURNS
 *  
 *****************************************************************************/

MMI_BOOL widget_checkbox_get_selection_state(int index)
{

 if(WENTER_MENU_CTX->target_menu->checkbox_menu_list_state[index] > 0)
 {
     return MMI_TRUE;
 }
 else
 {
     return MMI_FALSE;
}

}

#endif

/*****************************************************************************
 * FUNCTION
 *  widget_enter_fullscreen_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enter_fullscreen_menu(widget_menu_struct *menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WENTER_MENU_CTX->target_menu == menu);
    WENTER_MENU_CTX->target_menu = menu;

    if (WENTER_MENU_CTX->target_menu->choice_type == MsfExclusiveChoice)
    {
        WENTER_MENU_CTX->highlighted = -1;

        foreach(_H(menu), CHOICE_ELEMENT, node,
            {
                /* If state is MSF_CHOICE_ELEMENT_DISABLED, don't display in the option menu */
                if ((node->state & MSF_CHOICE_ELEMENT_DISABLED) != MSF_CHOICE_ELEMENT_DISABLED)
                {
                if (node->state & MSF_CHOICE_ELEMENT_SELECTED)
                {
                    WENTER_MENU_CTX->highlighted = cnt;
                }
                cnt++;}
            }
        );

        if (WENTER_MENU_CTX->highlighted < 0)
        {
            WENTER_MENU_CTX->highlighted = 0;
        }
        WENTER_MENU_CTX->last_highlighted = WENTER_MENU_CTX->highlighted;

        WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());   /* It should be invoked from widget_paint_hdlr */
        wap_entry_fullscreen_radio_menu();
    }
    else if (WENTER_MENU_CTX->target_menu->choice_type == MsfMultipleChoice)
    {
        WENTER_MENU_CTX->highlighted = 0;
        WENTER_MENU_CTX->last_highlighted = WENTER_MENU_CTX->highlighted;

        WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());   /* It should be invoked from widget_paint_hdlr */
        wap_entry_fullscreen_checkbox_menu();
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_init_fullscreen_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_fullscreen_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(WENTER_MENU_CTX, 0, sizeof(widget_enter_menu_struct));
}

/******************************************************************************
 *
 * IPC
 *
 ******************************************************************************/

/*
 * NOTICE! THE ASSUMPTION OF THE FOLLOWING CODE IS WAP AND MMI HAVE THE SAME PRIORITY 
 */


/*****************************************************************************
 * FUNCTION
 *  widget_init_IPC
 * DESCRIPTION
 *  Initialze inter-process communication mechanism
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_IPC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WIPC_CTX->initialized)
    {
        WIPC_CTX->initialized = 1;

        WIPC_CTX->event_group = kal_create_event_group("widgetev");

        WIPC_CTX->wait_message_notification_in_idle_screen = 0;

        WIPC_CTX->pending_to_enter_widget_screen = 0;

    #ifdef WIDGET_TMPFIX_DYNAMIC_LIST
        WIPC_CTX->WAP_extq_mutex = kal_create_mutex("widgetext");

        WIPC_CTX->extq_mutex_locked_by_WAP = 0;
        WIPC_CTX->extq_mutex_locked_by_MMI = 0;
        WIPC_CTX->MMI_try_to_lock_extq_mutex = 0;
    #endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
        WIPC_CTX->idlescreen_seq_no = 0;
    }

    WIPC_CTX->update_event_is_sent = 0;

    WAP_DBG_ASSERT(!WIPC_CTX->wait_MMI_lock);

    WAP_DBG_ASSERT(!WIPC_CTX->is_executing_RPC);

    /*
     * We do not reset WIPC_CTX->is_executing_RPC because we always need to execute the callback 
     * * even if out-of-memory happened.
     */
}


/*****************************************************************************
 * FUNCTION
 *  widget_mmiapi_remote_proc_call_req
 * DESCRIPTION
 *  Message handler of remote procedure call request
 * PARAMETERS
 *  ilm_ptr     [IN]        Request data
 * RETURNS
 *  void
 *****************************************************************************/
void widget_mmiapi_remote_proc_call_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_remote_proc_call_struct *rpc = (mmiapi_remote_proc_call_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMIAPI_REMOTE_PROC_CALL_REQ);

    WIPC_CTX->RPC_finish_callback = rpc->finish_callback;
    WIPC_CTX->is_executing_RPC = 1;

    /*
     * Pending this callback until internal queue are processed in MSF_fsm(). 
     * * Otherwise, WAP task might not have chance to process its internal queues before 
     * * widget_execute_WAP() returns.
     */
    rpc->finish_callback = NULL;
    mmiapi_remote_proc_call_req(rpc, ilm_ptr->src_mod_id);
}

/* Callback handler to unlock widget/MMI event group */


/*****************************************************************************
 * FUNCTION
 *  widget_unlock_MMI_lock_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_unlock_MMI_lock_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not circular waiting */
    ASSERT(!WIPC_CTX->WAP_is_waiting || !WIPC_CTX->MMI_is_waiting);
    WIPC_CTX->WAP_is_waiting = 0;
    WIPC_CTX->MMI_is_waiting = 0;

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_UNLOCK_MMI_LOCK);

    if (!WIDGET_TRY_MMI_LOCK())
    {
		WIDGET_SIGNAL_MMI_LOCK();
    }
}

/* Cancel all RPC to MMI after enter idle screen */


/*****************************************************************************
 * FUNCTION
 *  widget_validate_MMI_RPC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_validate_MMI_RPC(kal_uint32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (arg == WIPC_CTX->idlescreen_seq_no)
    {
        return KAL_TRUE;
    }
    else
    {
    
        ASSERT(WIPC_CTX->idlescreen_seq_no > arg);  /* Overflow? */
    
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_MMI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_MMI(func_void func, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr;
    mmiapi_remote_proc_call_struct *rpc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI, (kal_uint32) func, (int)is_blocking);

    if (WIDGET_IS_MMI_TASK())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_IN_MMI_TASK);
        func();
        return;
    }

    if (srv_shutdown_is_running())
    {
        return;
    }

    /* Not in MMI task */
    ASSERT(WIDGET_IS_WAP_TASK() && !WIPC_CTX->WAP_is_waiting /* Impossible */ );

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    /* If MMI is sleeping for WIPC_CTX->WAP_extq_mutex. WAP task can manually unlock the mutex 
       to give MMI task a chance to run. */
    if (WIPC_CTX->MMI_is_waiting && is_blocking && !WIPC_CTX->MMI_try_to_lock_extq_mutex /* MMI drawing unfinished */ )
#else /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    if (WIPC_CTX->MMI_is_waiting && is_blocking)
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    {
        /* MMI is already waiting for WAP to do something */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_WAIT_WAP_TASK);
        WAP_DBG_ASSERT(0);  /* However, MMI can not process extq now, this function might not complete successfully */
        func();
        return;
    }

    /* MMI is not blocked */
    rpc = (mmiapi_remote_proc_call_struct*) construct_local_para(sizeof(mmiapi_remote_proc_call_struct), TD_CTRL);

    rpc->type = MMIAPI_RPC_VOID;
    rpc->func_ptr = (void*)func;
    rpc->finish_callback = is_blocking ? widget_unlock_MMI_lock_hdlr : NULL;
    rpc->blocking_data = NULL;
    rpc->validate_callback = widget_validate_MMI_RPC;
    rpc->optional_param = WIPC_CTX->idlescreen_seq_no;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rpc;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);

    /* WAP and MMI has the same priority, it keeps execution */

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    if (is_blocking && WIPC_CTX->MMI_try_to_lock_extq_mutex)
    {
        /* MMI is sleeping for WIPC_CTX->WAP_extq_mutex. unlock the mutex to give MMI task a chance to run. */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_UNLOCK_Q_MUTEX);
        WIPC_CTX->extq_mutex_locked_by_WAP = 0;
        kal_give_mutex(WIPC_CTX->WAP_extq_mutex);

        WIDGET_WAIT_MMI_LOCK();

        kal_take_mutex(WIPC_CTX->WAP_extq_mutex);
        ASSERT(!WIPC_CTX->extq_mutex_locked_by_MMI);
        WIPC_CTX->extq_mutex_locked_by_WAP = 1;
    }
    else
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    if (is_blocking)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_WAP_BLOCKED);
        WIPC_CTX->WAP_is_waiting = 1;
        WIDGET_WAIT_MMI_LOCK();
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_ASYNC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_WAP
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_WAP(func_void func, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr;
    mmiapi_remote_proc_call_struct *rpc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP, (kal_uint32) func, (int)is_blocking);

    if (WIDGET_IS_WAP_TASK())
    {
        /* Note that WAP internal queue might not be finished after function returns */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_IN_WAP_TASK);
        func();
        // It will always process internal queue after this.
        // widget_send_update_event();
        return;
    }

    if (srv_shutdown_is_running())
    {
        return;
    }

    /* Not in WAP task */
    ASSERT(WIDGET_IS_MMI_TASK() /* Java? */  && !WIPC_CTX->MMI_is_waiting /* Impossible */ );

    if (WIPC_CTX->WAP_is_waiting && is_blocking)
    {
        /* WAP is already waiting for MMI to do something */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_WAIT_MMI_TASK);
        WAP_DBG_ASSERT(0);  /* However, WAP can not process extq and internal queue now, this function might not complete successfully */
        func();
        return;
    }

    /* WAP is not blocked */
    rpc = (mmiapi_remote_proc_call_struct*) construct_local_para(sizeof(mmiapi_remote_proc_call_struct), TD_CTRL);

    rpc->type = MMIAPI_RPC_VOID;
    rpc->func_ptr = (void*)func;
    rpc->finish_callback = is_blocking ? widget_unlock_MMI_lock_hdlr : NULL;
    rpc->blocking_data = NULL;
    rpc->validate_callback = NULL;
    rpc->optional_param = 0;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rpc;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    /* WAP and MMI has the same priority, it keeps execution */
    if (is_blocking)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_MMI_BLOCKED);
        WIPC_CTX->MMI_is_waiting = 1;
        WIDGET_WAIT_MMI_LOCK();
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_ASYNC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_MMI_i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  arg             [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_MMI_i(func_int func, int arg, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr;
    mmiapi_remote_proc_call_struct *rpc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I, (kal_uint32) func, arg, (int)is_blocking);

    if (WIDGET_IS_MMI_TASK())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_IN_MMI_TASK);
        func(arg);
        return;
    }

    if (srv_shutdown_is_running())
    {
        return;
    }

    /* Not in MMI task */
    ASSERT(WIDGET_IS_WAP_TASK() && !WIPC_CTX->WAP_is_waiting /* Impossible */ );

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    if (WIPC_CTX->MMI_is_waiting && is_blocking && !WIPC_CTX->MMI_try_to_lock_extq_mutex /* MMI drawing unfinished */ )
#else 
    if (WIPC_CTX->MMI_is_waiting && is_blocking)
#endif 
    {
        /* MMI is already waiting for WAP to do something */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_WAIT_WAP_TASK);
        WAP_DBG_ASSERT(0);  /* However, MMI can not process extq now, this function might not complete successfully */
        func(arg);
        return;
    }

    /* MMI is not blocked */
    rpc = (mmiapi_remote_proc_call_struct*) construct_local_para(sizeof(mmiapi_remote_proc_call_struct), TD_CTRL);

    rpc->type = MMIAPI_RPC_INTEGER;
    rpc->func_ptr = (void*)func;
    rpc->finish_callback = is_blocking ? widget_unlock_MMI_lock_hdlr : NULL;
    rpc->_u.i = arg;
    rpc->blocking_data = NULL;
    rpc->validate_callback = widget_validate_MMI_RPC;
    rpc->optional_param = WIPC_CTX->idlescreen_seq_no;
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rpc;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);

    /* WAP and MMI has the same priority, it keeps execution */
#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    if (is_blocking && WIPC_CTX->MMI_try_to_lock_extq_mutex)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_UNLOCK_Q_MUTEX);
        WIPC_CTX->extq_mutex_locked_by_WAP = 0;
        kal_give_mutex(WIPC_CTX->WAP_extq_mutex);

        WIDGET_WAIT_MMI_LOCK();

        kal_take_mutex(WIPC_CTX->WAP_extq_mutex);
        ASSERT(!WIPC_CTX->extq_mutex_locked_by_MMI);
        WIPC_CTX->extq_mutex_locked_by_WAP = 1;
    }
    else
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 
    if (is_blocking)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_WAP_BLOCKED);
        WIPC_CTX->WAP_is_waiting = 1;
        WIDGET_WAIT_MMI_LOCK();
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_MMI_I_ASYNC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_WAP_i
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  arg             [IN]        
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_WAP_i(func_int func, int arg, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr;
    mmiapi_remote_proc_call_struct *rpc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I, (kal_uint32) func, arg, (int)is_blocking);

    if (WIDGET_IS_WAP_TASK())
    {
        /* Note that WAP internal queue might not be finished after function returns */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I_IN_WAP_TASK);
        func(arg);
        // It will always process internal queue after this.
        // widget_send_update_event();
        return;
    }

    if (srv_shutdown_is_running())
    {
        return;
    }

    /* Not in WAP task */
    ASSERT(WIDGET_IS_MMI_TASK() /* Java? */  && !WIPC_CTX->MMI_is_waiting /* Impossible */ );

    if (WIPC_CTX->WAP_is_waiting && is_blocking)
    {
        /* WAP is already waiting for MMI to do something */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I_WAIT_MMI_TASK);
        WAP_DBG_ASSERT(0);  /* However, WAP can not process extq and internal queue now, this function might not complete successfully */
        func(arg);
        return;
    }

    /* WAP is not blocked */
    rpc = (mmiapi_remote_proc_call_struct*) construct_local_para(sizeof(mmiapi_remote_proc_call_struct), TD_CTRL);

    rpc->type = MMIAPI_RPC_INTEGER;
    rpc->func_ptr = (void*)func;
    rpc->finish_callback = is_blocking ? widget_unlock_MMI_lock_hdlr : NULL;
    rpc->_u.i = arg;
    rpc->blocking_data = NULL;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rpc;
    rpc->validate_callback = NULL;
    rpc->optional_param = 0;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    /* WAP and MMI has the same priority, it keeps execution */

    if (is_blocking)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I_MMI_BLOCKED);
        WIPC_CTX->MMI_is_waiting = 1;
        WIDGET_WAIT_MMI_LOCK();
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXECUTE_WAP_I_ASYNC);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_MMI_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  arg             [IN]         
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_MMI_p(func_ptr func, void *arg, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_execute_MMI_i((func_int) func, (int)arg, is_blocking);
}


/*****************************************************************************
 * FUNCTION
 *  widget_execute_WAP_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  func            [IN]        
 *  arg             [IN]         
 *  is_blocking     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_execute_WAP_p(func_ptr func, void *arg, kal_bool is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_execute_WAP_i((func_int) func, (int)arg, is_blocking);
}

/******************************************************************************
 *
 * Context of GUI and fullscreen editor
 *
 ******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_init_GUI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_GUI()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * We do not reset all flags of WGUI_CTX including
     * paint_seqnum, paint_seqnum_on_form_scroll, has_status_icons, form_with_sliding_bar, ...
     */

    memset(WGUI_CTX, 0, sizeof(widget_gui_context_struct));
    WGUI_CTX->display_size.width = (short)MMI_SUBMENU_CONTENT_WIDTH;
    WGUI_CTX->display_size.height = (short)MMI_SUBMENU_CONTENT_HEIGHT;
    WGUI_CTX->default_display_size.width = (short)MMI_SUBMENU_CONTENT_WIDTH;
    WGUI_CTX->default_display_size.height = (short)MMI_SUBMENU_CONTENT_HEIGHT;
    WGUI_CTX->display_pos.x = (short)MMI_SUBMENU_CONTENT_X;
    WGUI_CTX->display_pos.y = (short)MMI_SUBMENU_CONTENT_Y;
    WGUI_CTX->current_pos = WGUI_CTX->display_pos;
#ifdef WIDGET_RESIDENT_STATUS_ICON
    WGUI_CTX->status_icons_pane_bottom.y = MMI_title_y - 1;
#endif
#ifdef WIDGET_DRAW_STATUS_BAR
    WGUI_CTX->bearer_type = WIDGET_GPRS;
#endif

#ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */

    WGUI_CTX->widget_root.flag = WIDGET_ROOT_TYPE;
    WGUI_CTX->cursor_shadow_color.r = WIDGET_CURSOR_SHADOW_COLOR_R;
    WGUI_CTX->cursor_shadow_color.g = WIDGET_CURSOR_SHADOW_COLOR_G;
    WGUI_CTX->cursor_shadow_color.b = WIDGET_CURSOR_SHADOW_COLOR_B;
    WGUI_CTX->cursor_shadow_color.alpha = WIDGET_CURSOR_SHADOW_COLOR_A;

#ifndef WIDGET_VIDEO_TWO_LAYER_SUPPORT
    WGUI_CTX->top_gdi_layer_is_button_bar = 1;
#endif

#ifdef __MMI_BACKGROUND_CALL__
    WGUI_CTX->register_ucm_callback_in_mmi_task = 1;
#endif /* __MMI_BACKGROUND_CALL__ */



#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef WIDGET_ANIMATED_GIF_SUPPORT
/* under construction !*/
#endif
/* under construction !*/
#ifdef WIDGET_DRAW_STATUS_BAR
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef WIDGET_DRAW_STATUS_BAR
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef WIDGET_RESIDENT_STATUS_ICON
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 
#ifdef WIDGET_DRAW_STATUS_BAR
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef WIDGET_VIDEO_TWO_LAYER_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*   __MMI_WAP_MOUSE_POINTER_SUPPORT__ */  
#ifdef __MMI_BACKGROUND_CALL__
/* under construction !*/
#endif /* __MMI_BACKGROUND_CALL__ */
#endif /* 0 */
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_GUI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_GUI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_release_paint_command_queue();
    // TODO: also release all marquee, blinking text... etc. even though they are released in HDIa_widgetReleaseAll
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_fullscreen_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    WEDITOR_CTX->active_object = NULL;
}

/******************************************************************************
 *
 * Message notification mechanism
 * (Migrated from mmiapi_wap.c)
 *
 ******************************************************************************/

/*
 *    Issues to consider:
 * o MO/MT Call
 * o Alarm
 * o Profile Alert Type 
 * o If we entered message menu, the notification should be cleared.
 * o Keypad lock
 * o Wait MEA/BRA UI shutdown before display another notification
 * o (Unfinished) SubLCD 
 *
 * Note:
 * We always display the latest provision/push/MMS. 
 *
 * EntryIdleScreen will
 * o Cleanup history
 * o Terminate WAP UI (blocking & synchronous)
 * o Display WAP message popup (keypad unlocked)
 * o Display message prompt (keypad locked)
 *
 */
// TODO: Ask - vibrator no automatically resume?

#define WIDGET_MSG_NOTIFICATION_NONE            (0)
#define WIDGET_MSG_NOTIFICATION_PUSH            (1)
#define WIDGET_MSG_NOTIFICATION_MMS	            (2)
#define WIDGET_MSG_NOTIFICATION_DRM_RIGHT       (3)
#ifdef MSF_MODID_PRS
#define WIDGET_MSG_NOTIFICATION_PROVISION       (4)
#endif


/*****************************************************************************
 * FUNCTION
 *  widget_get_scrollbar_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 widget_get_scrollbar_width()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Scrollbar width. It should sync with ThemeRes.c. */
    #ifdef __COSMOS_MMI_PACKAGE__
	return UI_SCROLLBAR_WIDER_WIDTH/2;
    #endif
    #if defined(__MMI_FTE_SUPPORT__)
	return UI_SCROLLBAR_WIDER_WIDTH;
    #else
    return UI_SCROLLBAR_WIDTH;
    #endif /* __MMI_FTE_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  widget_is_shutdown_UI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 widget_is_shutdown_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WGUI_CTX->is_shutdown_UI;
}

#ifndef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  wap_entry_wap_transition_animation
 * DESCRIPTION
 *  Entry function of ASM transtion animation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_entry_wap_transition_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAP_ENTRY_WAP_TRANSITION_ANIM); 
     if(mmi_frm_scrn_enter(GRP_ID_ROOT, WAP_BRA_SCREEN_TRANSITION_ANIMATION, NULL, wap_entry_wap_transition_animation, MMI_FRM_SMALL_SCRN))
     {
        /* draw the blank softkey if no softkey button */
        show_softkey_background();
        ShowCategory66Screen(
            (U16) WIDGET_STR_ID_PLEASE_WAIT,
            (U16) 0,
            0,
            0,
            0,
            0,
            (U8*) GetString(WIDGET_STR_ID_PLEASE_WAIT),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);

        ClearAllKeyHandler();   /* End key is still valid */
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
     }
}

/*****************************************************************************
 * FUNCTION
 *  widget_MMI_close_wap_transition_animation
 * DESCRIPTION
 *  Close the ASM transtion animation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_close_wap_transition_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_CLOSE_WAP_TRANSITION_ANIM); 
    if (GetExitScrnID() == WAP_BRA_SCREEN_TRANSITION_ANIMATION)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WIDGET_CALLS_GOBACKHISTORY);  
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        ret = mmi_frm_scrn_close(GRP_ID_ROOT, WAP_BRA_SCREEN_TRANSITION_ANIMATION);
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WIDGET_CALLS_DELETE_SCREEN_IF_PRESENT, ret); 
    }
}


void HDIa_widgetExtCloseWAPTransitionAnimation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We should not do anything in idlescreen in order to prevent deadlock */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_CLOSE_WAP_TRANSITION_ANIM); 
    if (WIPC_CTX->MMI_is_waiting)
    {
        /* Typically on BRA/MEA UI shutdown in idle screen */
        widget_MMI_close_wap_transition_animation();
    }
    else
    {
        widget_execute_MMI(widget_MMI_close_wap_transition_animation, KAL_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDisplayWAPTransitionAnimation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_MMS      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtDisplayWAPTransitionAnimation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_DISPLAY_WAP_TRANSITION_ANIM); 
    if (!widget_allow_create_new_MMI_screen())
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DISPLAY_TRANSITION_ANIMATION_NOT_ALLOW);
        return;
    }

    if (GetExitScrnID() == WAP_BRA_SCREEN_TRANSITION_ANIMATION || mmi_frm_scrn_is_present(GRP_ID_ROOT, WAP_BRA_SCREEN_TRANSITION_ANIMATION, MMI_FRM_NODE_ALL_FLAG))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DISPLAY_TRANSITION_ANIMATION_ALREADY_EXIST);
        return;
    }

    widget_execute_MMI(wap_entry_wap_transition_animation, KAL_TRUE);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  widget_dialog_get_popup_event
 * DESCRIPTION
 *  Refresh wap screen
 * PARAMETERS
 *  
 * RETURNS
 *  void 
 *****************************************************************************/
void widget_dialog_get_popup_event(MsfDialogType type, mmi_event_notify_enum *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(type)
	{
	case MsfUnfinishedError:
	case MsfPromptEmpty:
	case MsfFailure:
		*event = MMI_EVENT_FAILURE;
		break;

	case MsfInfo:
		*event = MMI_EVENT_INFO;
		break;

	case MsfAlert:
	case MsfWarning:
		*event = MMI_EVENT_WARNING;
		break;

	case MsfPromptSaveDone:
	case MsfSuccess:
		*event = MMI_EVENT_SUCCESS;
		break;

	case MsfProgress:
		*event = MMI_EVENT_PROGRESS;
		break;

	case MsfPrompt:
	case MsfConfirmation:
	case MsfQuery:
		*event = MMI_EVENT_QUERY;
		break;

	case MsfMessageSent:
		*event = MMI_EVENT_MESSAGE_SENT;
		break;
	default:
		*event = MMI_EVENT_ERROR;
	}
}

/*****************************************************************************
 * FUNCTION
 *  widget_MMI_stop_dialog_sound_if_present
 * DESCRIPTION
 *  Stop a playing widget sound (should be used inside of widget screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_stop_dialog_tone_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_image_id icon = 0;
    ctk_tone_id tone = 0;
    kal_bool image_bottom = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
	WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_STOP_DIALOG_TONE); 
	widget_dialog_get_attributes((WGUI_CTX->current_dialog)->dialog_type, &icon, &tone, &image_bottom);
	if (tone)
	{
		WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_STOP_SOUND_FILE_IF_PRESENT, tone);
		srv_profiles_stop_tone(tone);
	}
	
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStopDialogTone
 * DESCRIPTION
 *  Stop a playing widget sound (should be used inside of widget screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtStopDialogTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_STOP_DIALOG_TONE); 
    if (WGUI_CTX->current_dialog)
    {		
	 widget_execute_MMI(widget_MMI_stop_dialog_tone_if_present, KAL_TRUE);		
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paintbox_exit_function
 * DESCRIPTION
 *  Exit function of Paintbox
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
void widget_paintbox_exit_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if (WGUI_CTX->is_widget_screen)
	{
		WGUI_CTX->is_widget_screen = 0;
	#ifdef __MMI_TOUCH_SCREEN__
        widget_MMI_remove_pen_handler_if_necessary(NULL);
    #endif 

    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        widget_stop_all_image_nb_draw();
    #endif
    #ifdef WIDGET_PRECACHE_IMAGE
        widget_MMI_free_precached_image_if_any();
    #endif 

#ifdef WIDGET_DRAW_STATUS_BAR
		widget_close_status_icons_if_present();
#endif

		WGUI_CTX->is_painted = 0;
		while (WGUI_CTX->lock_buffer_level > 0)
		{
			WGUI_CTX->lock_buffer_level--;
			gui_unlock_double_buffer();
		}
	}
	
}
#ifdef __COSMOS_MMI_PACKAGE__
gdi_handle paintbox_layer_handle;
gdi_handle image_layer_handle;
PU8 layer_buf_ptr;
extern GDI_RESULT gdi_layer_save_jpeg_file(gdi_handle layer_handle, PS8 file_name);

/*****************************************************************************
 * FUNCTION
 *  widget_paintbox_create_doubble_buffer
 * DESCRIPTION
 *  for allocating memory to paintbox layer handle
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
//extern void vrt_set_video_layer(vrt_sys_video_layer_index_enum index, gdi_handle layer, vrt_s32 order);
void widget_paintbox_create_doubble_buffer( 
        U32 x,
        U32 y,
        U32 w,
        U32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	fixed_list_menu_prev_layer_handle = MMI_fixed_list_menu.act_layer_handle;	//MAUI_03240037

 gdi_layer_create_double_using_outside_memory(
        x,
        y,
        w,
        h,
        &paintbox_layer_handle,
        (PU8) layer_buf_ptr,
        (S32) ((w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2);

	gdi_layer_push_and_set_active(paintbox_layer_handle);    
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_WHITE);
	gdi_layer_pop_and_restore_active();


 


}

/*****************************************************************************
 * FUNCTION
 *  widget_create_web_page_bmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
void widget_create_web_page_bmp (PS8 file_name)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_save_jpeg_file(paintbox_layer_handle, (char*)(file_name));
}

/*****************************************************************************
 * FUNCTION
 *  widget_paintbox_recreate_double_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
void widget_paintbox_recreate_double_buffer( 
        U32 x,
        U32 y,
        U32 w,
        U32 h)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	    if(paintbox_layer_handle)
		{
			gdi_layer_free(paintbox_layer_handle);
			paintbox_layer_handle = NULL;

			gdi_layer_create_double_using_outside_memory(
			x,
			y,
			w,
			h,
			&paintbox_layer_handle,
			(PU8) layer_buf_ptr,
			(S32) ((w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2);
		
	gdi_layer_push_and_set_active(paintbox_layer_handle);    
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_WHITE);
	gdi_layer_pop_and_restore_active();

		}

 
 

}

PU8 buffer_ptr;
gdi_handle temp_layer_handle;
/*****************************************************************************
 * FUNCTION
 *  widget_remove_full_screen_mode_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
void widget_remove_full_screen_mode_icon(void)
{
	if(temp_layer_handle)
    {
        gdi_layer_free(temp_layer_handle);
        temp_layer_handle = NULL;
    #ifdef WAP_USE_ASM
        widget_internal_mem_free(MSF_MODID_BRS, buffer_ptr);
    #endif
    }
}
/*****************************************************************************
 * FUNCTION
 *  widget_paintbox_free_doubble_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
void widget_paintbox_free_doubble_buffer(void)
{
    if(paintbox_layer_handle)
    {
        gdi_layer_free(paintbox_layer_handle);
        paintbox_layer_handle = NULL;
}

	
	//MAUI_03240037 starts

	 if(MMI_fixed_list_menu.act_layer_handle != fixed_list_menu_prev_layer_handle)
		{
			MMI_fixed_list_menu.act_layer_handle = fixed_list_menu_prev_layer_handle;
		}

	 //MAUI_03240037 ends
}
#endif

/*****************************************************************************
 * FUNCTION
 *  widget_paintbox_entry_function
 * DESCRIPTION
 *  Exit function of Paintbox
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
void widget_paintbox_entry_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_back_from_call_screen = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_uint16 i;
	WGUI_CTX->is_widget_screen = 1;
    WGUI_CTX->is_back_history = mmi_frm_is_in_backward_scenario()? KAL_TRUE : KAL_FALSE;
	/* Initialize global variables */
//    widget_enable_clear_all_handler();

    /* initialize keys table */
    /* if (widget_all_keys[0] == 0xffff)
    {*/

    memset(widget_all_keys,0,sizeof(widget_all_keys));
        for (i = 0; i < MAX_KEYS; i++)
        {
			if (((i == KEY_LSK) || (i == KEY_RSK)) || (i == KEY_END))
			{
				/* Dont register these 3 keys*/
			}
			else
			{
				widget_all_keys[i] = i;
			}
        }
    
    if (WGUI_CTX->is_back_history && (CALL_MANAGEMENT_BASE <= mmi_frm_scrn_get_active_id()) && (mmi_frm_scrn_get_active_id() <= CALL_MANAGEMENT_BASE_MAX))
    {
        /* goback history from the call related screen */
        is_back_from_call_screen = KAL_TRUE;
    }
    
    if (WGUI_CTX->is_back_history)
    {
        /* need to paint the screen again */
        WGUI_CTX->is_painted_after_first_focus_changed = 0;
    }
    
    
  //  if (!widget_is_current_window_type(WIDGET_EDITOR_TYPE) && (widget_is_current_window_type(WIDGET_PAINTBOX_TYPE) ||   /* Back to paintbox */
  //      (!return_from_ctk && (last_screen_id != WAP_SCREEN_DELETE_ALL) && (last_screen_id != WAP_SCREEN_OPTION_GROUP) && WGUI_CTX->is_back_history))) /* MsfDialog should not display on top of MT screen */
  //  {
   //     widget_clear_screen();
  //  }
    
    if (is_back_from_call_screen)
    {
        /* If goback from the call related screens, we also need to clear the screen. */
        widget_clear_screen();
    }
    if (WGUI_CTX->in_paintbox)
    {
    widget_paintbox_redraw();
    }
    //widget_paint();
    if (WGUI_CTX->is_back_history &&  WGUI_CTX->current_window && IS_DIALOG_TYPE(WGUI_CTX->current_window))
    {
        /* need to paint the screen again */
        widget_paint();
    }
 if (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_DONE)
    {
        if (WGUI_CTX->in_paintbox || WGUI_CTX->in_editor)
        {
            widget_key_ind_handler(KEY_LSK, KEY_EVENT_UP);
            WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
        }
    }
    else if (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_CANCEL)
    {
        if (WGUI_CTX->in_paintbox || WGUI_CTX->in_editor)
        {
            widget_key_ind_handler(KEY_RSK, KEY_EVENT_UP);
/*            WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE; MAUI_02728065 */
        }

    }
    else if (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_DENY_ENTRY)
    {
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    }

     WEDITOR_CTX->leave_from_fullscreen = KAL_FALSE;   

     if (WENTER_MENU_CTX->state == WIDGET_ENTER_MENU_RETURN_OK)
    {
        if (WGUI_CTX->in_paintbox)  /* Default actions are created by BRS */
        {
#ifdef MSF_CFG_BRW_ACCESSKEY_SUPPORT
            if (WGUI_CTX->is_access_key_trigger == KAL_TRUE)
            {
                /* If enter fullscreen menu by access key, we don't need to execute LSK, EVENT_IP action */
                WGUI_CTX->is_access_key_trigger = KAL_FALSE;
            }
#endif /* MSF_CFG_BRW_ACCESSKEY_SUPPORT */
                widget_key_ind_handler(KEY_LSK, KEY_EVENT_UP);
            }
        else
        {
            /* We do not handle choice menu in MsfForm */
        }
        widget_init_fullscreen_menu();
    }

    
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtResumeRendering
 * DESCRIPTION
 *  Delete Editor Screens from WAP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtResumeRendering(MSF_UINT8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->resume_rendering = (kal_bool)flag;
	if (flag)
	{
		widget_paintbox_entry_function();
		//widget_paintbox_redraw();
	}	   
	else
	{
		widget_paintbox_exit_function();
	}

}

/*****************************************************************************
 * FUNCTION
 *  widget_get_screen_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 widget_get_screen_id(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef BROWSER_SUPPORT    
#ifdef OBIGO_Q03C_BROWSER    
	if (mmi_brw_is_rendered_page_present())
#else
	if (1)
#endif		
	{
		return wap_get_screen_id();
	}
	else
#endif
	{
		return WAP_SCREEN_WIDGET;
	}
}

#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetUpdateMousePointerParameters()
 * DESCRIPTION : This API is an interface for BRS to update the co-ordinates of Mouse Pointer and tells
 * widget which image to use to draw mouse icon on screen. i.e update the position of Mouse Pointer when user performs the Navigation on rendered page.
 * Here co-ordinates passed by BRS are relative to Paintbox size. It's the responsibilty
 * of BRS to pass the co-ordinates within the range of PaintBox. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetUpdateMousePointerParameters(int x, int y, int is_hand_tool_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->mouse_position.x = x;
    WGUI_CTX->mouse_position.y = y;
    if (is_hand_tool_image)
    { 
         WGUI_CTX->is_link_select_image = TRUE;
    }
    else
    {
        WGUI_CTX->is_link_select_image = FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetMousePointerPos()
 * DESCRIPTION : This API will return the current mouse poiter location. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void HDIa_widgetGetMousePointerPos(MsfPosition *mouse_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT (mouse_pos);
    mouse_pos->x = WGUI_CTX->mouse_position.x;
    mouse_pos->y = WGUI_CTX->mouse_position.y;
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetMousePointerSize()
 * DESCRIPTION : This API fills mouse pointer size  in passed pointer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void HDIa_widgetGetMousePointerSize(MsfSize *mouse_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->is_link_select_image)
    {
        mouse_size->height = WGUI_CTX->link_select_tool_size.height;
        mouse_size->width = WGUI_CTX->link_select_tool_size.width; 
    }
    else
    {
        mouse_size->height = WGUI_CTX->mouse_pointer_size.height ;
        mouse_size->width = WGUI_CTX->mouse_pointer_size.width;  
    }
}
#endif /*   __MMI_WAP_MOUSE_POINTER_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 * HDIa_widgetGetScrollBarPenState()
 * DESCRIPTION : This API is called in WAP task. 
 * PARAMETERS
 * void
 * RETURNS
 * void
 *****************************************************************************/
kal_bool HDIa_widgetGetScrollBarPenState(void)
{
	
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__ 
        vertical_scrollbar vert_bar;
	horizontal_scrollbar hor_bar;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    vert_bar = WGUI_CTX->vbar;
    hor_bar = WGUI_CTX->hbar;

	kal_wap_trace(MOD_WAP, TRACE_INFO, (S8*) "ARK: [vbar_State] = %d, [hbar_state] = %d", (vert_bar.pen_state).state, (hor_bar.pen_state).state);		
	if (((vert_bar.pen_state).state == GUI_SCROLLBAR_PEN_STATE_INVALID) && ((hor_bar.pen_state).state == GUI_SCROLLBAR_PEN_STATE_INVALID))
	{
		g_v_bar_pen_state = (vert_bar.pen_state).state;
		g_h_bar_pen_state = (hor_bar.pen_state).state;
		return FALSE;
	}
	if (g_v_bar_pen_state != 0)
	{
		if(((vert_bar.pen_state).state == g_v_bar_pen_state))
		{
			return FALSE;
		}
	}
	else
	{
		g_v_bar_pen_state = (vert_bar.pen_state).state;
		kal_wap_trace(MOD_WAP, TRACE_INFO, (S8*) "ARK:[V_BAR] vibrate [g_v_bar_pen_state] = %d, [g_h_bar_pen_state] = %d", g_v_bar_pen_state, g_h_bar_pen_state);
		return TRUE;

	}
	if (g_h_bar_pen_state != 0)
	{
		if(((hor_bar.pen_state).state == g_h_bar_pen_state))
		{
			return FALSE;
		}
	}
	else
	{
		g_h_bar_pen_state = (hor_bar.pen_state).state;
		kal_wap_trace(MOD_WAP, TRACE_INFO, (S8*) "ARK:[H_BAR] vibrate [g_v_bar_pen_state] = %d, [g_h_bar_pen_state] = %d", g_v_bar_pen_state, g_h_bar_pen_state);
		return TRUE;
	}
#else
                         return FALSE;
#endif
}

/*****************************************************************************
 * FUNCTION
 * HDIa_widgetPlayToneAndVibration()
 * DESCRIPTION : This API is called in WAP task. Framework API to play Tone and Vibration should be called in MMI task.
 * So here in this API we will just set our global flag and depending upon flag value we wil play tone and vibration in MMI.
 * PARAMETERS
 * void
 * RETURNS
 * void
 *****************************************************************************/
void HDIa_widgetPlayToneAndVibration(void)
{
	
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    WGUI_CTX->play_tone_and_vibration = KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 * HDIa_widgetPlayVibration()
 * DESCRIPTION : This API is called in WAP task. Framework API to play Vibration should be called in MMI task.
 * So here in this API we will just set our global flag and depending upon flag value we wil play vibration in MMI.
 * PARAMETERS
 * void
 * RETURNS
 * void
 *****************************************************************************/
void HDIa_widgetPlayVibration(void)
{
	
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    WGUI_CTX->play_only_vibration = KAL_TRUE;
}

/* This part of code has been moved from Idle screen files to this file. This mecanism was used in MMS V01 to show 
* New MMS popup. In 10A Idle has changed this mechanism and now they have new event based mechanism. Since in 10A projects
* MMS V01 will not be enabled. So currently we are not implementing new event based mechanism.This Code is of no use. It
* is just for future reference. In future we might remove this code */



/*****************************************************************************
 * FUNCTION
 * HDIa_widgetContentChangeNotifyFlagSet()
 * DESCRIPTION : This API will set flag to notify BRS if content of page is changed and re-rendering is required.
 * PARAMETERS
 * int
 * RETURNS
 * void
 *****************************************************************************/
void HDIa_widgetContentChangeNotifyFlagSet(void)
{
	extern int content_change_flag;
#ifdef SLIM_WAP_MMS
	content_change_flag = 1;
#else
	content_change_flag = 0;
#endif
}
