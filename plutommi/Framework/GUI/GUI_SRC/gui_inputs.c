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
 *   gui_inputs.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   General Editor - UI component
 *
 *   [Single-line input box]
 *   [Multi-line input box]
 *   [Dialer input box]
 *
 * Author:
 * -------
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#undef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR

//#include "WguiCategoryGprot.h"
#include "MMI_features.h"
//#include "GlobalDefs.h"
//#include "kal_non_specific_general_types.h"
//#include "lcd_sw_rnd.h"
//#include "mmi_frm_gprot.h"
//#include "SimDetectionGprot.h"
#include "ProfilesSrvGprot.h"
#include "wgui_include.h"
#include "gui_touch_feedback.h"

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
#endif 
/* MTK Arabic Connectivity issue */

#ifdef __MMI_ZI_V7__
#include "ezicmn.h"
#endif 
#if defined (__MMI_ZI_ARABIC__) || defined (__MMI_ZI_PERSIAN__)
#include "zi8ARshape.h"
#endif /* defined (__MMI_ZI_ARABIC__) || defined (__MMI_ZI_PERSIAN__) */ 
/* MTK End */

/* if needs to modify this define ,remember to update the define in ChatGType.h */
 /* slim_2_2 */ //#define MAX_MSG_SIZE_UCS2   256

#define EDIT_MAX(a, b)   ((a) > (b) ? (a) : (b))
#define EDIT_MIN(a, b)   ((a) < (b) ? (a) : (b))


#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
extern U32 add_template_multiline_flag;
#define MAX_EDITOR_DISP_LEN      60

#endif /* __MMI_INDIC_ALG__ */ 


/* MTK Elvis for R2L characters */
#include "BIDIDEF.h"
//#include "BIDIProt.h"



#include "LangModuleGProt.h"
/* start vijay 20050221 */
#ifdef __MMI_TOUCH_SCREEN__
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* end vijay */

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
/* PMT HIMANSHU START 20050825 */
//#include "IdleAppDef.h"
//#include "SimDetectionGprot.h"
/* PMT HIMANSHU END 20050825 */
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 

/* MTK Elvis 20031126 */


#if defined(__MMI_DUAL_SIM_MASTER__)
//#include "MTPNP_PFAL_CC.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
MMI_BOOL gui_multi_line_input_box_clear_wcss(multi_line_input_box *b);
#endif

#if defined (__MMI_ARSHAPING_ENGINE__)
//#include "ArabicGProt.h"

// for total text shaping
U16 shaping_str[MAX_SHOW_STRING_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
U16 OrgToSha[MAX_SHOW_STRING_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
S32 unshaped_text_len = 0;
S32 shaped_text_len;
#endif /* __MMI_ARSHAPING_ENGINE__ */ 

#include "gui_inputs_internal.h"

#include "phbsrvgprot.h"

    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "gui_inputs.h"
    #include "wgui_inputs.h"
    #include "gui_data_types.h"
    #include "gui_theme_struct.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "gui.h"
    #include "gui_config.h"
    #include "wgui_categories_list.h"
    #include "gdi_include.h"
    #include "gui_switch.h"
    #include "mmi_frm_timer_gprot.h"
    #include "mmi_frm_history_gprot.h"
    #include "string.h"
    #include "Gsm7BitNationalLang.h"
    #include "wgui_categories_res.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_cb_mgr_gprot.h"
    #include "wgui_categories_inputs.h"
    #include "Unicodexdcl.h"
    #include "CustThemesRes.h"
    #include "gui_scrollbars.h"
    #include "ImeGprot.h"
    #include "kal_public_api.h"
    #include "MMI_fw_trc.h"
    #include "mmi_fw_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
    #include "gui_ems.h"
    #include "ems.h"
    #include "PixcomFontEngine.h"
    #include "gui_themes.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_categories_util.h"
    #include "gdi_const.h"
    #include "gdi_datatype.h"
    #include "wgui.h"
    #include "gui_typedef.h"
    #include "GlobalConstants.h"
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
#include "IndicEngineGprot.h"
#endif
#ifdef __MMI_VUI_ENGINE__
    #include "vadp_p2v_uc.h"
    #include "vadp_p2v_inputbox.h"
#endif
    #include "mmi_fw_trc.h"
    #include "CustDataRes.h"
    #include "wgui_draw_manager.h"
    #include "FontRes.h"

#include "wgui_fixed_menus.h"

/* Global variable */
gui_editor_line_unit_struct g_editor_line;

#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

extern U8 mtkmultitap_ire_bengali_ndicator;
static U8 to_decide_to_reshuffle_inline = 0;
#endif


static multi_line_input_box *cursor_multiline_input = NULL;

extern void wgui_redraw_remaining_characters_display(void);

static multi_line_input_box *backup_b;
void gui_multiline_predefined_cursor_move_timer_hdlr(void);

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
extern void (*dialing_keypad_phonebook_handler) (void); /* Added to disable Phonebook function key */
#endif

/* MTK Terry for inline multiline issue */
extern void (*complete_inline_item_edit) (void);

extern void UI_draw_horizontal_line(S32 x1, S32 x2, S32 y, color c);
color gui_richtext_strikethrough_color = {255, 112, 125, 240};
color gui_richtext_default_text_bg_color = {255, 255, 255, 100};
#if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) || defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
static MMI_BOOL pen_check_func_key_bound_ext(S32 x, S32 y, dialing_keypad_struct *dialing_keypad);
#endif  /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
/* barcode */
color gui_hilite_underline_color = {0, 0, 220};

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
#define PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED        0x20
#define PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER     0x40
#define PIXTEL_UI_WCSS_STAR_INPUT               0x80

/* Prevent automatically changing input method while deleting characters 
   and also avoid reentrance of gui_change_WCSS_input_method() */
static U8 WCSS_input_change_enable = 1;

void gui_change_WCSS_input_method(multi_line_input_box *b);

/* Force to change input method regardless of multitap state */
static U8 WCSS_Esc_Char = 0;

extern MMI_BOOL is_fisrt_entry_WCSS_editor;

#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

#ifdef __MMI_INDIC_ALG__

extern BOOL cancelWidth;
#endif 
/* for R2L characters */


#ifdef __MMI_BIDI_ALG__
/* MTK End */
U8 MMI_bidi_input_type = BIDI_L;
U16 pwcWord[MAX_TEXT_LENGTH];
#endif /* __MMI_BIDI_ALG__ */ 
BOOL r2lMMIFlag;

/* MTK Terry for 0x81 encoding support for Phone Book */
extern S16 MMI_current_input_ext_type;

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
U8 hilited_item_changed = 0;
extern void wgui_redraw_input_information_bar(void);
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
/* GUI: multitap input object functions            */
extern U8 wgui_inputbox_information_flag;
extern S32 wgui_inputbox_information_bar_height;
extern void inline_fixed_list_goto_previous_item(void);
extern void inline_fixed_list_goto_next_item(void);

extern S32 mmi_is_redrawing_bk_screens(void);
/* Auto scroll of Multiline Input text */
extern void multiline_inputbox_vertical_scroll(void);

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
#include "SmsGuiInterfaceType.h"
#include "SettingProfile.h"
#include "MessagesResourceData.h"
#include "MessagesExDcl.h"
extern nsm_msg_struct g_nsm_msg_context;


#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__)
extern S32 wgui_inputbox_buffer_size;
#endif 

#if defined(__MMI_SMART_MESSAGE_MT__)
#include "MessagesExDcl.h"
#include "MessagesResourceData.h"
extern nsm_picmsg_text_struct picmsg_text_struct;
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

U8 numeric_leading_zero = TRUE;
static U8 g_multi_create_flag = 0;

UI_information_bar_theme *current_information_bar_theme = NULL;
UI_header_information_text_theme *current_header_information_text_theme = NULL;

static S32 in_multiline_shown_flag = 0;

static S32 cursor_force_stop = 0;

gui_line_struct g_visible_multiline_line_info;
gui_line_struct g_multiline_line_info;

#ifdef __MMI_EDITOR_SSP_SUPPORT__

#ifdef __MMI_EDITOR_SSP_PARABOLIC_SUPPORT__
static MMI_BOOL gui_input_box_ssp_calculate_parabolic_parameter(S32 max_y); 
static S32 gui_input_box_ssp_calculate_parabolic_y(S32 x); 
#endif /* __MMI_EDITOR_SSP_PARABOLIC_SUPPORT__ */

#endif /* __MMI_EDITOR_SSP_SUPPORT__ */


#ifdef __MMI_TOUCH_DIAL_SCREEN__
MMI_ID_TYPE dialing_key_image[] = 
{
#if defined(__MMI_SLIM_IMG_RES__) && defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_FTE_SUPPORT__)
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
    IMG_DIALING_P,
#else /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ && !__MMI_FTE_SUPPORT__ */
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__)
    IMG_DIALING_KEY_1,
    IMG_DIALING_KEY_2,
    IMG_DIALING_KEY_3,
    IMG_DIALING_KEY_STAR,
    IMG_DIALING_KEY_4,
    IMG_DIALING_KEY_5,
    IMG_DIALING_KEY_6,
    IMG_DIALING_KEY_0,
    IMG_DIALING_KEY_7,
    IMG_DIALING_KEY_8,
    IMG_DIALING_KEY_9,
    IMG_DIALING_KEY_HASH,
#else /* __MMI_FTE_SUPPORT__ && __MMI_MAINLCD_320X240__ */
    IMG_DIALING_KEY_1,
    IMG_DIALING_KEY_2,
    IMG_DIALING_KEY_3,
    IMG_DIALING_KEY_4,
    IMG_DIALING_KEY_5,
    IMG_DIALING_KEY_6,
    IMG_DIALING_KEY_7,
    IMG_DIALING_KEY_8,
    IMG_DIALING_KEY_9,
    IMG_DIALING_KEY_STAR,
    IMG_DIALING_KEY_0,
    IMG_DIALING_KEY_HASH,
#endif /* __MMI_FTE_SUPPORT__ && __MMI_MAINLCD_320X240__ */
#endif /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ && !__MMI_FTE_SUPPORT__ */
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)

#if !defined(__MMI_FTE_SUPPORT__)
    IMG_DIALING_KEY_PHB,
#endif /* !defined(__MMI_FTE_SUPPORT__) */

    IMG_DIALING_KEY_CALL,
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	\
	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    IMG_DIALING_KEY_CALL_SLAVE,
#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

#ifdef __MMI_CAT_VIDEO_CALL__
    IMG_DIALING_KEY_VIDEO,
#endif

#if defined(__MMI_FTE_SUPPORT__)
    IMG_DIALING_KEY_PHB,
#endif /* defined(__MMI_FTE_SUPPORT__) */

#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
};

#if defined(__MMI_FTE_SUPPORT__)

static MMI_ID_TYPE dialing_key_down_image[] = 
{
    IMG_DIALING_KEY_1_DOWN,
    IMG_DIALING_KEY_2_DOWN,
    IMG_DIALING_KEY_3_DOWN,
    IMG_DIALING_KEY_4_DOWN,
    IMG_DIALING_KEY_5_DOWN,
    IMG_DIALING_KEY_6_DOWN,
    IMG_DIALING_KEY_7_DOWN,
    IMG_DIALING_KEY_8_DOWN,
    IMG_DIALING_KEY_9_DOWN,
    IMG_DIALING_KEY_STAR_DOWN,
    IMG_DIALING_KEY_0_DOWN,
    IMG_DIALING_KEY_HASH_DOWN,
#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    IMG_DIALING_KEY_CALL,
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	\
	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    IMG_DIALING_KEY_CALL_SLAVE,
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
#ifdef __MMI_CAT_VIDEO_CALL__
    IMG_DIALING_KEY_VIDEO,
#endif

    IMG_DIALING_KEY_PHB,
#endif /* defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
};

static MMI_ID_TYPE dialing_key_func_button_image[] = 
{
#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    IMG_DIALING_KEY_CALL_BUTTON_UP,
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	\
	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    IMG_DIALING_KEY_CALL_BUTTON_UP,
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
#ifdef __MMI_CAT_VIDEO_CALL__
    IMG_DIALING_KEY_VIDEO_BUTTON_UP,
#endif
    IMG_DIALING_KEY_PHB_BUTTON_UP,
#endif /* defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    0
};

static MMI_ID_TYPE dialing_key_func_button_down_image[] = 
{
#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    IMG_DIALING_KEY_CALL_BUTTON_DOWN,
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	\
	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    IMG_DIALING_KEY_CALL_BUTTON_DOWN,
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
#ifdef __MMI_CAT_VIDEO_CALL__
    IMG_DIALING_KEY_VIDEO_BUTTON_DOWN,
#endif
    IMG_DIALING_KEY_PHB_BUTTON_DOWN,
#endif /* defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    0
};

static MMI_ID_TYPE dialing_key_func_button_disable_image[] = 
{
#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    IMG_DIALING_KEY_CALL_BUTTON_DISABLED,
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	\
	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    IMG_DIALING_KEY_CALL_BUTTON_DISABLED,
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
#ifdef __MMI_CAT_VIDEO_CALL__
    IMG_DIALING_KEY_VIDEO_BUTTON_DISABLED,
#endif
    IMG_DIALING_KEY_PHB_BUTTON_DISABLED,
#endif /* defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    0
};

#endif /* defined(__MMI_FTE_SUPPORT__) */

#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

/* MTK Elvis 20040611 for color dialing font */

const color_dialing_font color_dialing_font_map[] = 
{
    {'*', {255, 0, 0, 100}},
    {'#', {0, 0, 247, 100}},
    {'+', {0, 0, 247, 100}},
    {'p', {255, 0, 0, 100}},
    {'w', {0, 255, 0, 100}},
    {'0', {0, 255, 0, 100}},
    {'1', {255, 0, 0, 100}},
    {'2', {0, 255, 0, 100}},
    {'3', {0, 0, 247, 100}},
    {'4', {255, 0, 0, 100}},
    {'5', {0, 255, 0, 100}},
    {'6', {0, 0, 247, 100}},
    {'7', {255, 0, 0, 100}},
    {'8', {0, 255, 0, 100}},
    {'9', {0, 0, 247, 100}},
    {0, {0, 0, 0, 100}},
};

#if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) || defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
#define IS_FUNC_KEY 1
#define IS_NOT_FUNC_KEY 0
#endif  /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
static MMI_BOOL gui_multi_line_input_box_insert_multitap_character_wcss(multi_line_input_box *b, UI_character_type c);
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/
static S32 gui_multi_line_input_box_get_remaining_length(multi_line_input_box *b);

const U8 g_newline_symbol_LF[4] = {0x0A, 0x00, 0x00, 0x00};
const U8 g_newline_symbol_CRLF[6] = {0x0D, 0x00, 0x0A, 0x00, 0x00, 0x00};

/* Used for Singleline editor adjust view for cursor position */
#define GUI_INPUTS_SL_LOCATE_CURSOR_ADJUST_WIDTH    30
#define GUI_INPUTS_SL_LOCATE_CURSOR_L2R_EXTRA_WIDTH  6
#define GUI_INPUTS_SL_LOCATE_CURSOR_R2L_EXTRA_WIDTH  9

static void gui_single_line_input_box_ascii_encoding_handling(single_line_input_box *b, UI_character_type old_c, UI_character_type c);

static void UI_inputbox_stop_cursor_callback(void);
static void UI_inputbox_start_cursor_callback(void);

gui_inputs_draw_back_ground_funcptr g_inputs_background_filler = NULL;

gui_inputs_pen_scroll_cb g_inputs_pen_scroll_cb = NULL;

static MMI_BOOL g_cursor_change_evt_on = MMI_TRUE;

#ifdef __MMI_FTE_SUPPORT__
static MMI_BOOL g_editor_background_transparent = MMI_FALSE;
#endif

#if GUI_INPUTS_KEYWORDS_SUPPORT
#include "app_usedetails.h"
static HILITE_STR g_inputs_hilite_list[GUI_INPUTS_KEYWORDS_MAX_COUNT];

// lcoal function
static void* gui_inputs_ml_malloc(U32 size);
static void gui_inputs_ml_free(void* p);
static kal_bool gui_inputs_ml_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num);
static MMI_BOOL gui_inputs_ml_keyword_is_overlap(HILITE_STR hilite1, HILITE_STR hilite2);
static U32 gui_inputs_ml_parse_keywords_by_type(multi_line_input_box *b, EDITOR_HILITE_TYPE type, HILITE_STR *list, applib_mem_alloc_fn mallocF, applib_mem_free_fn freeF);
#endif


/*****************************************************************************
 * FUNCTION
 *  set_leading_zero
 * DESCRIPTION
 *  set the flag..whether zero is allowed as first number or not
 *  Input Parameter      u8 u8type
 * PARAMETERS
 *  u8type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_leading_zero(U8 u8type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numeric_leading_zero = u8type;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_multitap_input
 * DESCRIPTION
 *  Applies the given theme to a multitap input object
 *  
 *  Note: Each key on a keypad requires one multitap input object.
 *  For example, the text for multitap input for key 2 would be "ABC2"
 * PARAMETERS
 *  b               [?]         
 *  x               [IN]        Is the left-top corner
 *  y               [IN]        Is the left-top corner
 *  width           [IN]        Is the width of the multitap-input object
 *  height          [IN]        Is the height of the multitap-input object
 *  text            [IN]        Is a pointer to the string containing all the characters
 *  m(?)            [IN]        Is the multitap input object
 *  possible(?)     [IN]        With this multitap-input object.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_multitap_input(multitap_input *b, S32 x, S32 y, S32 width, S32 height, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags = 0;
    b->text = text;
    b->length = gui_strlen(b->text);
    b->current_position = b->length - 1;
    b->input_complete_callback = UI_dummy_function;
    b->input_callback = UI_dummy_function_character;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multitap_input_callbacks
 * DESCRIPTION
 *  Sets the callback functions for a multitap input object
 *  
 *  See the documentation for the operation of the callback functions.
 * PARAMETERS
 *  b                           [?]         
 *  input_callback              [IN]        Is the function that is called whenever the
 *  input_complete_callback     [IN]        Is the function that is called when
 *  the(?)                      [IN]        Input character is confirmed.
 *  m(?)                        [IN]        Is the multitap input object
 *  This(?)                     [IN]        Causes the timer associated witht the multitap object
 *  state(?)                    [IN]        Of the multitap inputobject changes
 *  to(?)                       [IN]        Expire and call the input_complete_callback function)
 *  ke(?)                       [IN]        (Ex: in "ABC2", the user has selected "B" and releases the key,
 *  in(?)                       [IN]        (Ex: in "ABC2", the user has selected "B" and releases the key,
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multitap_input_callbacks(
        multitap_input *b,
        void (*input_callback) (UI_character_type),
        void (*input_complete_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->input_complete_callback = input_complete_callback;
    b->input_callback = input_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_change_multitap_input_state
 * DESCRIPTION
 *  Causes the multitap input object to change its state
 *  
 *  Example, if "ABC2" is now highlighting "A", calling this
 *  function will cause it to highlight "B".
 *  This also causes the input_callback function to be called.
 *  This function is normally called on key-down or key-repeat
 * PARAMETERS
 *  b           [?]         
 *  m(?)        [IN]        Is the multitap input object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_change_multitap_input_state(multitap_input *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Terry for null multitap */
    if (0 == b->length)
    {
        return;
    }
    b->current_position++;
    if (b->current_position >= b->length)
    {
        b->current_position = 0;
    }
	
    b->input_callback(b->text[b->current_position]);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multitap_input_complete
 * DESCRIPTION
 *  Completes the input in the current multitap object
 *  
 *  This also causes the input_complete_callback function to be called.
 *  This function is normally called on key-up
 * PARAMETERS
 *  b           [?]         
 *  m(?)        [IN]        Is the multitap input object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multitap_input_complete(multitap_input *b)
{
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Gurinder - It will chnage the cursor location on multitap complete */
    /*
     * Justin: it will not invokes gui_show_multi_line_inputbox on multitap completion
     * * and it needs to change input method by itself
     */
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE)
    {
        /* To Solve Input Mode Change Bug - Gurinder 4/5/2003 */
        WCSS_Esc_Char = 1;
        gui_change_WCSS_input_method(&MMI_multiline_inputbox);
    }
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    b->current_position = b->length - 1;
    b->input_complete_callback();
}



/*****************************************************************************
 * FUNCTION
 *  UI_dummy_validation_function
 * DESCRIPTION
 *  dummy validation function
 * PARAMETERS
 *  text            [IN]        
 *  cursor_p        [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_validation_function(UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(text);
    UI_UNUSED_PARAMETER(cursor_p);
    UI_UNUSED_PARAMETER(text_length);
}

/* GUI: Blinking cursor functions   */

S32 UI_cursor_x1 = 0;                   /* cursor x1 postioon */
S32 UI_cursor_y1 = 0;                   /* cursor y1 position */
S32 UI_cursor_x2 = 0;                   /* cursor x2 postion */
S32 UI_cursor_y2 = 0;                   /* cursor y2position */

color UI_cursor_color = {0, 0, 0, 0};   /* cursor color black */

#if(UI_BLINKING_CURSOR_SUPPORT)

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__)
#define UI_CURSOR_BACKUP_BITMAP_SIZE   512
#define UI_CURSOR_MAX_HEIGHT           80
#else
#define UI_CURSOR_BACKUP_BITMAP_SIZE   256
#define UI_CURSOR_MAX_HEIGHT           40
#endif

extern void StopTimer(U16 nTimerId);
extern void StartNonAlignTimer(U16 timerid, U32 delay, FuncPtr funcPtr);
extern void StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr);
U8 UI_cursor_backup_bitmap_data[UI_CURSOR_BACKUP_BITMAP_SIZE];
U8 UI_cursor_blink_flag = 0;            /* blinking flag of cursor */

#ifdef GUI_INPUT_BOX_FLOATING_COUNTER
S32 floating_counter_x1 = 0;
S32 floating_counter_y1 = 0;
S32 floating_counter_x2 = 0;
S32 floating_counter_y2 = 0;
#endif
/* cusror bitmap */
gdi_image_cache_bmp_struct UI_cursor_backup_bitmap=
{
    0,
    0,
    UI_cursor_backup_bitmap_data
};


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_blink_cursor
 * DESCRIPTION
 *  show blinking crusor in input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_inputbox_blink_cursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_cursor_x1 == 0 && UI_cursor_y1 == 0 && UI_cursor_x2 == 0 && UI_cursor_y2 == 0)
    {
        return;
    }

    gui_reset_clip();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    if (UI_cursor_blink_flag)   /* if blinking curosr flag is set */
    {
        gui_fill_rectangle(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2, UI_cursor_color);
        UI_cursor_blink_flag = 0;
    }
    else
    {
        gdi_image_cache_bmp_draw(UI_cursor_x1, UI_cursor_y1, &UI_cursor_backup_bitmap);
        UI_cursor_blink_flag = 1;
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

    StartTimer(BLINKING_CURSOR, UI_CURSOR_WAIT_TIME, UI_inputbox_blink_cursor);
}

#ifdef GUI_INPUT_BOX_FLOATING_COUNTER
/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_register_floating_counter_position
 * DESCRIPTION
 *  save the current floating counter position
 * PARAMETERS
 *  x1                  [IN]      x1
 *  y1                  [IN]      y1
 *  x2                  [IN]      x2
 *  y2                  [IN]      y2
 * RETURNS
 *  void
 *****************************************************************************/
void UI_inputbox_register_floating_counter_position(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    floating_counter_x1 = x1;
    floating_counter_y1 = y1;
    floating_counter_x2 = x2;
    floating_counter_y2 = y2;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_start_cursor
 * DESCRIPTION
 *  start blinking crusor in input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_inputbox_start_cursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GUI_INPUT_BOX_FLOATING_COUNTER
    if (!(floating_counter_x2 < UI_cursor_x1 
        || floating_counter_x1 >UI_cursor_x2 
        || floating_counter_y1 > UI_cursor_y2 
        || floating_counter_y2 < UI_cursor_y1)
        && (floating_counter_x1 != 0
            || floating_counter_y1 != 0
            || floating_counter_x2 != 0
            || floating_counter_y2 != 0))
    {
        return;
    }
#endif

    if (cursor_force_stop)
    {
        UI_inputbox_blink_cursor();
    }   
    
    cursor_force_stop = 0;
}


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_stop_cursor_ext
 * DESCRIPTION
 *  stop blinking crusor in input box
 * PARAMETERS
 *  x1                  [IN]      x1
 *  y1                  [IN]      y1
 *  x2                  [IN]      x2
 *  y2                  [IN]      y2
 *  flag                [IN]      to indicate if need to stop other operation, like SSP, cipboard
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL UI_inputbox_stop_cursor_ext(S32 x1, S32 y1, S32 x2, S32 y2, MMI_BOOL flag)
{

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    if (flag)
    {
        mmi_pen_point_struct point = {0, 0};
        
        gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
    }
#endif


#if(UI_BLINKING_CURSOR_SUPPORT)
    if (!IsMyTimerExist(BLINKING_CURSOR))
    {
        return MMI_FALSE;
    }

    if (x2 < UI_cursor_x1 || x1 >UI_cursor_x2 || y1 > UI_cursor_y2 || y2 < UI_cursor_y1 )
    {
        cursor_force_stop = 0;
        return MMI_FALSE;
    }

    if (UI_cursor_blink_flag)   /* if blinking curosr flag is set */
    {
        gui_push_clip();
        gui_reset_clip();
#if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
#endif 
        gui_fill_rectangle(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2, UI_cursor_color);
        UI_cursor_blink_flag = 0;

#if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        gui_pop_clip();
    }

    cursor_force_stop = 1;

    StopTimer(BLINKING_CURSOR);
#endif

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_stop_cursor
 * DESCRIPTION
 *  stop blinking crusor in input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL UI_inputbox_stop_cursor(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return UI_inputbox_stop_cursor_ext(x1, y1, x2, y2, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_stop_cursor_callback
 * DESCRIPTION
 *  stop blinking crusor in input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void UI_inputbox_stop_cursor_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    UI_inputbox_stop_cursor(0, 0, UI_device_width - 1, UI_device_height -1);
}


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_start_cursor_callback
 * DESCRIPTION
 *  stop blinking crusor in input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void UI_inputbox_start_cursor_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_inputbox_start_cursor();
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_register_cursor_callback
 * DESCRIPTION
 *  regitser cursor stop/start callback for icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_inputs_register_cursor_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor_force_stop = 0;
    wgui_icon_bar_register_pause_interactive_UI_callback(UI_inputbox_stop_cursor_callback);
    wgui_icon_bar_register_resume_interactive_UI_callback(UI_inputbox_start_cursor_callback);
}


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_show_cursor
 * DESCRIPTION
 *  show blinking crusor in input box
 * PARAMETERS
 *  x1      [IN]        X1 position of cursor
 *  y1      [IN]        Y1 position of cursor
 *  x2      [IN]        X2 position of cursor
 *  y2      [IN]        Y2 position of cursor
 *  c       [IN]        Color of cursor
 * RETURNS
 *  void
 *****************************************************************************/
void UI_inputbox_show_cursor(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BLINKING_CURSOR);

    UI_cursor_x1 = x1;
    UI_cursor_y1 = y1;
    UI_cursor_x2 = x2;
    UI_cursor_y2 = y2;
    UI_cursor_color = c;
    
#ifdef __MMI_VUI_ENGINE__
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_update_cursor();
        return;
    }
    else
#endif
    {
        if (y2 - y1 > UI_CURSOR_MAX_HEIGHT)
        {
            y1 = y2 - UI_CURSOR_MAX_HEIGHT;
            UI_cursor_y1 = y1;
        }
    }

    if (!mmi_is_redrawing_bk_screens())
    {
        gdi_image_cache_bmp_get(x1, y1, x2, y2, &UI_cursor_backup_bitmap);  /* get bitmp of bliknkig cursor */
        gui_fill_rectangle(x1, y1, x2, y2, c);
        StartTimer(BLINKING_CURSOR, UI_CURSOR_WAIT_TIME, UI_inputbox_blink_cursor);
        UI_cursor_blink_flag = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_hide_cursor
 * DESCRIPTION
 *  hide and stop cursor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_inputbox_hide_cursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_cursor_blink_flag == 0)
    {
        UI_inputbox_blink_cursor();
    }

    StopTimer(BLINKING_CURSOR);
}


void UI_inputbox_pre2_show_cursor(void)
{
    if (UI_cursor_x1 == 0 && UI_cursor_y1 == 0 && UI_cursor_x2 == 0 && UI_cursor_y2 == 0)
    {
        return;
    }

    gui_reset_clip();
    gui_lock_double_buffer();
    UI_inputbox_show_cursor(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2, UI_cursor_color);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2);

}
void UI_inputbox_pre_show_cursor(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    StopTimer(BLINKING_CURSOR);

    if (y2 - y1 > UI_CURSOR_MAX_HEIGHT)
    {
        y1 = y2 - UI_CURSOR_MAX_HEIGHT;
    }
    
    UI_cursor_x1 = x1;
    UI_cursor_y1 = y1;
    UI_cursor_x2 = x2;
    UI_cursor_y2 = y2;
    UI_cursor_color = c;
    StartTimer(BLINKING_CURSOR, 1, UI_inputbox_pre2_show_cursor);
    UI_cursor_blink_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_move_cursor
 * DESCRIPTION
 *  show blinking crusor in input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_inputbox_move_cursor(
            S32 offset_x, 
            S32 offset_y,
            S32 clip_x1,
            S32 clip_y1,
            S32 clip_x2,
            S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsMyTimerExist(BLINKING_CURSOR))
        return;

    StopTimer(BLINKING_CURSOR);

    UI_cursor_x1 += offset_x;
    UI_cursor_x2 += offset_x;
    UI_cursor_y1 += offset_y;
    UI_cursor_y2 += offset_y;
    
    if (UI_cursor_y1 > 0 && UI_cursor_y2 > 0)
    {
        if (UI_cursor_y1 > clip_y2 || UI_cursor_y2 < clip_y1)
            return;
        else
        {
            UI_cursor_y1 = EDIT_MAX(UI_cursor_y1, clip_y1);
            UI_cursor_y2 = EDIT_MIN(UI_cursor_y2, clip_y2);

            UI_inputbox_pre_show_cursor(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2, UI_cursor_color);
        }
    }
}
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 

void UI_inputbox_pre2_show_fixed_cursor(void)
{
    gui_reset_clip();
    gui_lock_double_buffer();
    gui_fill_rectangle(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2, UI_cursor_color);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2);
}

void UI_inputbox_pre_show_fixed_cursor(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    StopTimer(BLINKING_CURSOR);
    
    UI_cursor_x1 = x1;
    UI_cursor_y1 = y1;
    UI_cursor_x2 = x2;
    UI_cursor_y2 = y2;
    UI_cursor_color = c;
    StartTimer(BLINKING_CURSOR, 1, UI_inputbox_pre2_show_fixed_cursor);
}

/* GUI: single line input box functions   */

UI_single_line_input_box_theme *current_single_line_input_box_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_single_line_input_box_current_theme
 * DESCRIPTION
 *  Applies the current theme for the single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_single_line_input_box_current_theme(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = current_single_line_input_box_theme->normal_filler;
    b->disabled_filler = current_single_line_input_box_theme->disabled_filler;
    b->selected_filler = current_single_line_input_box_theme->selected_filler;
    b->normal_text_color = current_single_line_input_box_theme->normal_text_color;
    b->disabled_text_color = current_single_line_input_box_theme->disabled_text_color;
    b->selected_text_color = current_single_line_input_box_theme->selected_text_color;
    b->selection_color = current_single_line_input_box_theme->selection_color;
    b->selection_text_color = current_single_line_input_box_theme->selection_text_color;
    b->cursor_color = current_single_line_input_box_theme->cursor_color;
    b->text_font = current_single_line_input_box_theme->text_font;
    b->text_gap = current_single_line_input_box_theme->text_gap;
    b->mask_character = current_single_line_input_box_theme->mask_character;
    b->flags |= current_single_line_input_box_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_single_line_input_box_theme
 * DESCRIPTION
 *  Applies the given theme to the single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  t       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_single_line_input_box_theme(single_line_input_box *b, UI_single_line_input_box_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = t->normal_filler;
    b->disabled_filler = t->disabled_filler;
    b->selected_filler = t->selected_filler;
    b->normal_text_color = t->normal_text_color;
    b->disabled_text_color = t->disabled_text_color;
    b->selected_text_color = t->selected_text_color;
    b->selection_color = t->selection_color;
    b->selection_text_color = t->selection_text_color;
    b->cursor_color = t->cursor_color;
    b->text_font = t->text_font;
    b->text_gap = t->text_gap;
    b->mask_character = t->mask_character;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_clear
 * DESCRIPTION
 *  clearthe single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_clear(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        b->text_length = 0;
        b->allocated_length = 0;
        b->available_length = 0;
    }
    else
    {
        b->text[0] = '\0';
        b->text[1] = 0;
        b->text_length = 2;
    }
    b->current_text_p = b->text;
    b->last_position_p = b->text;
    b->UCS2_count = 0;
    b->GSM_ext_count = 0;
    b->non_ascii_count = 0;
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH ||
        b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ASCII_ENCODING_BASE_LENGTH)
    {
        b->available_length = b->allocated_length;
    }
}

#if 0  /* slim_2_2 */ //
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
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_create_single_line_input_box_set_buffer
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  Also, the buffer should be allocated and passed to this function.
 *  The buffer retains the string passed.
 * VJ
 * PARAMETERS
 *  b                   [IN]        Is the single-line inputbox object (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the inputbox
 *  height              [IN]        Is the height of the inputbox
 *  buffer              [IN]        Is the buffer the inputbox should use (pre-allocated)
 *  length              [IN]        Is the length of the buffer
 *  text_length         [IN]        
 *  edit_position       [IN]        Is the cursor_position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_single_line_input_box_set_buffer(
        single_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type text;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(b, 0, sizeof(single_line_input_box));

    b->x = x;                           /* start x position of single lien input box */
    b->y = y;                           /* stat y position of single line inputr box */
    b->width = width;                   /* width of single line input box */
    b->height = height;                 /* heightof ingle lien input box */
    b->text = (UI_buffer_type) buffer;  /* set text of single lie input box */
    b->current_text_p = b->text;
    b->allocated_length = length;
    b->available_length = length;
    b->UCS2_count = 0;
    b->show_action_flag = 1;
    b->last_cursor_offset = -1;

    if (b->text != NULL)
    {
        text = b->text;
        for (i = 0; i < edit_position; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            UI_TEST_GSM_INCREMENT_COUNT(dummy_c, b->GSM_ext_count);
            UI_TEST_NON_ASCII_INCREMENT_COUNT(dummy_c, b->non_ascii_count);

            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
        }
        b->current_text_p = text;
        for (i = edit_position; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            UI_TEST_GSM_INCREMENT_COUNT(dummy_c, b->GSM_ext_count);
            UI_TEST_NON_ASCII_INCREMENT_COUNT(dummy_c, b->non_ascii_count);
        }
        b->text_length = text_length;
        b->last_position_p = b->current_text_p;
    }
    else
    {
        b->text_length = 0;
    }
    b->text_offset_x = 0;
    b->flags = 0;
    b->ext_flags = 0;
    b->grid_width = 0;
    /* set theme of single line input box */
    gui_set_single_line_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    /* native editor default gap */
    b->margin.left_margin = b->margin.right_margin = GUI_SINGLE_LINE_LEFT_RIGHT_MARGIN;
    b->margin.top_margin = b->margin.down_margin = GUI_SINGLE_LINE_TOP_DOWN_MARGIN;
    b->text_x = b->margin.left_margin + b->text_gap;
    /* Autocalculate the text position based on font   */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_Y)
    {
        S32 string_height;

        gui_set_font(b->text_font);
        string_height = gui_get_character_height();
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 2;
    }

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    gui_input_box_ssp_set_client_callback(
        gui_singleline_ssp_update_client, 
        gui_singleline_ssp_get_client_info, 
        b);
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    gui_inputs_register_cursor_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_single_line_input_box_set_buffer_first_position
 * DESCRIPTION
 *  set the current text to first position straing of text
 *  
 *  The object should be allocated before calling this function.
 *  Also, the buffer should be allocated and passed to this function.
 *  The buffer retains the string passed.
 * VJ
 * PARAMETERS
 *  b                   [IN]        Is the single-line inputbox object (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the inputbox
 *  height              [IN]        Is the height of the inputbox
 *  buffer              [IN]        Is the buffer the inputbox should use (pre-allocated)
 *  length              [IN]        Is the length of the buffer
 *  text_length         [IN]        
 *  edit_position       [IN]        Is the cursor_position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_single_line_input_box_set_buffer_first_position(
        single_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(b, 0, sizeof(single_line_input_box));
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->current_text_p = b->text;
    b->allocated_length = length;
    b->available_length = length;
    b->UCS2_count = 0;
    b->text_offset_x = 0;
    b->flags = 0;
    b->ext_flags = 0;
    b->grid_width = 0;
    b->show_action_flag = 1;
    gui_set_single_line_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    b->margin.left_margin = b->margin.right_margin = GUI_SINGLE_LINE_LEFT_RIGHT_MARGIN;
    b->margin.top_margin = b->margin.down_margin = GUI_SINGLE_LINE_TOP_DOWN_MARGIN;
    b->text_x = b->margin.left_margin + b->text_gap;
    b->text_length = text_length;
    /* Autocalculate the text position based on font   */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_Y)
    {
        S32 string_height;

        gui_set_font(b->text_font);
        string_height = gui_get_character_height();
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 2;
    }

    gui_inputs_register_cursor_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_single_line_input_box
 * DESCRIPTION
 *  Moves a single line input box
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object (pre-allocated)
 *  x       [IN]        Is the left-top corner
 *  y       [IN]        Is the left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_single_line_input_box(single_line_input_box *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_set_margin
 * DESCRIPTION
 *  set margin for singleline input box
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  top         [IN]        top >0: set new value; -1: use default value
 *  down        [IN]        down >0: set new value; -1: use default value
 *  left        [IN]        left >0: set new value; -1: use default value
 *  right       [IN]        right >0: set new value; -1: use default value
 * RETURNS
 *  byte
 *****************************************************************************/
void gui_single_line_input_box_set_margin(single_line_input_box *b, S32 top, S32 down, S32 left, s32 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (top >= 0)
    {
        b->margin.top_margin = (U8)top;
    }
    
    if (down >= 0)
    {    
        b->margin.down_margin = (U8)down;
    }
    
    if (left >= 0)
    {
        b->margin.left_margin = (U8)left;

        /* has been computed in create function, so recomputed */
        b->text_x = b->margin.left_margin + b->text_gap;
    }
    
    if (right >= 0)
    {
        b->margin.right_margin = (U8)right;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_show_cursor
 * DESCRIPTION
 *  Displays the cursor in a single-line inputbox (internal function)
 *  
 *  This function is used internally.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  x           [IN]        Is the left-top corner of the cursor
 *  y           [IN]        Is the left-top corner of the cursor
 *  height      [IN]        Is the height of cursor
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_show_cursor(single_line_input_box *b, S32 x, S32 y, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = b->cursor_color;
    S32 x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(&x1, &y1, &x2, &y2);

    /* Should not show half cursor (clipped) */
    if (x == (x1 - 1))
    {
        x--;
    }
    else if (x == x2)
    {
        x++;
    }

    if (y < y1)
    {
        height -= (y1 - y + 1);
        y = y1 + 1;
    }
    if ((y + height - 1) > y2)
    {
        height -= (y + height - 1) - y2;
    }

#if(UI_BLINKING_CURSOR_SUPPORT)
    if (y > y2 
        || (y + height) < y1 
        || x+1 < x1 
        || x > x2)
        StopTimer(BLINKING_CURSOR);
    else
        /* UI_inputbox_pre_show_cursor(x, y, x + 1, y + height - 1, c); */
        UI_inputbox_show_cursor(x, y, x + 1, y + height - 1, c);
#else 
    UI_cursor_x1 = x;
    UI_cursor_y1 = y;
    UI_cursor_x2 = x+1;
    UI_cursor_y2 = y+height - 1;

    gui_fill_rectangle(x, y, x + 1, y + height - 1, c);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_single_line_input_box
 * DESCRIPTION
 *  Displays a single-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK modify for stacked character--Thai */
void gui_show_single_line_input_box(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_single_line_input_box_ext(b, -1, -1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_single_line_input_box_ext
 * DESCRIPTION
 *  Displays a single-line inputbox
 * PARAMETERS
 *  b               [IN]        Is the single-line inputbox object
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK modify for stacked character--Thai */
void gui_show_single_line_input_box_ext(single_line_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    single_line_input_box_show_struct bs_struct;
    single_line_input_box_show_struct* bs = &bs_struct;
#ifdef __MMI_BIDI_ALG__
    MMI_BOOL arabic_char_flag = MMI_FALSE;
#endif /* __MMI_BIDI_ALG__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (b->show_action_flag == 0)
        return;
    
    /* init the structure bs */
    gui_init_single_line_show_struct(b, bs);
    
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    gdi_push_and_set_alpha_blending_source_layer(gui_inputs_get_source_layer());
#endif
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    overwrite_current_language_for_hindi_rules_based_on_input_method();
#endif 
    
#ifdef __MMI_BIDI_ALG__
    /* get the text BIDI type*/
    bs->default_direction = gui_get_single_line_text_language_type(b, &arabic_char_flag);
    bs->arabic_char_flag = (pBOOL)arabic_char_flag;
#endif /* __MMI_BIDI_ALG__ */ 
    
     /* translate the text buffer to shaping buffer if nessary */
#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
    gui_translate_single_line_buffer_to_shaping(b, bs);
#endif /* defined (__MMI_ARSHAPING_ENGINE__)*/ 


    /* Setup runtime variables */
    bs->current_cursor_p = b->current_text_p;  /* points to the character at which the cursor is positioned */
    bs->previous_cursor_p = b->current_text_p;
    bs->current_text_p = b->text;
    
    if (bs->previous_cursor_p && bs->previous_cursor_p != b->text)
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(bs->previous_cursor_p, dummy_c);
    }
    
#ifdef __MMI_BIDI_ALG__
    /* try to apply the BIDI alg to the current text content */
    gui_translate_single_line_bidi_text(b, bs);
#endif

    bs->move_to_x = move_to_x;
    bs->move_to_y = move_to_y;
    
    if (((-1) != move_to_x) || ((-1) != move_to_y))
    {
        bs->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
        bs->find_new_cursor_flag = FINDING_CURSOR;
    }
    
    bs->x1 = b->x;                  /* start x position of single line input box */
    bs->y1 = b->y;                  /* start y position of single line input box */
    bs->x2 = bs->x1 + b->width - 1;     /* end x position of single line input box */
    bs->y2 = bs->y1 + b->height - 1;    /* end y position of single line input box */
    bs->sy1 = bs->y1;
    bs->sy2 = bs->y2;
    b->text_width = 0;
    
    /* draw the background */
    gui_draw_single_line_background(b, bs);
    if (bs->y1 + b->text_y < bs->sy1)
    {
        bs->y1 = bs->sy1 - b->text_y;
    }
    
    if (bs->current_text_p != NULL)
    {
        if (bs->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            bs->multitap_flag = 1;
        }
        
        if ((bs->flags & UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE) && (!bs->multitap_flag))
        {
            bs->overwrite_flag = 1;
        }

        /* adjust the cursor_p for language special requirement*/
        gui_adjust_single_line_cursor_for_language(b, bs);
        
        /* Draw the line*/
        gui_push_text_clip();
    #ifdef __MMI_FTE_SUPPORT__
        if (b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND)
        {
            /* For datatime/IP... controls */
            gui_set_text_clip_preset(bs->x1, bs->y1, bs->x2, bs->y2);
        }
        else
    #endif
        {
            gui_set_text_clip_preset(bs->x1 + b->margin.left_margin + b->left_width, bs->y1, bs->x2 - b->margin.right_margin - b->right_width, bs->y2);
        }
        gui_draw_single_line_one_line(b, bs);
        gui_pop_text_clip();
    }
    
    gui_pop_text_clip();
    gui_pop_clip();
    /* MTK Elvis for R2L characters */
    
    /* draw lefter and righter area */
    gui_draw_single_line_callback_area(b, bs);

    /* notify the cursor pos change */
    gui_single_line_cursor_info_update(b);
    
    gui_single_line_show_special_remaining_counter(b);
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    restore_current_language_for_hindi_rules();
#endif 

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
    gui_retore_single_line_buffer_from_shaping(b, bs);
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    gdi_pop_and_restore_alpha_blending_source_layer();
#endif

    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_cursor_info_update
 * DESCRIPTION
 *  
 *  
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_cursor_info_update(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cursor_offset;
    gui_evt_inputs_cursor_changed_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cursor_offset = (b->current_text_p - b->text)/ENCODING_LENGTH;
    if (cursor_offset != b->last_cursor_offset)
    {
        b->last_cursor_offset = cursor_offset;
        
        if (gui_inputs_get_cursor_change_event_state())
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_GUI_INPUTS_CURSOR_CHANGED);
            evt.cursor_pos = cursor_offset;
            if (!mmi_frm_is_event_posted((mmi_event_struct*)&evt))
            {
                MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            }
        }
    }
}
#if 0  /* slim_2_2 */ //
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
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_locate_cursor_no_draw
 * DESCRIPTION
 *  calculate the position ofcusror of single line input box
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_locate_cursor_no_draw(single_line_input_box *b)
{
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b);
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_locate_cursor
 * DESCRIPTION
 *  calculate the position ofcusror of single line input box
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_locate_cursor(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MTK Elvis for R2L characters */
#ifdef __MMI_BIDI_ALG__
    PMT_BIDI_TYPES default_direction = BIDI_L;
    MMI_BOOL arabic_char_flag;
#endif /* __MMI_BIDI_ALG__ */ 
    S32 adjust_width;
    U16 left_gap, right_gap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single line input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;

    /* For datatime/IP... controls */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
    {
#ifdef __MMI_INLINE_SLIM__
        b->text_offset_x = 0;
        return;
#else
        adjust_width = 0;
#endif		
    }
    else
    {
        adjust_width = GUI_INPUTS_SL_LOCATE_CURSOR_ADJUST_WIDTH;
    }

#ifdef __MMI_FTE_SUPPORT__
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND)
    {
        /* For datatime/IP... controls */
        left_gap = b->left_width;
        right_gap = b->right_width;
    }
    else
#endif
    {
        left_gap = b->left_width + b->margin.left_margin;
        right_gap = b->right_width + b->margin.right_margin;
    }

#ifdef __MMI_BIDI_ALG__
    default_direction = gui_get_single_line_text_language_type(b, &arabic_char_flag);
    if (default_direction == BIDI_L)
    {
#endif /* __MMI_BIDI_ALG__ */ 
        if ((b->cursor_x + adjust_width - ((left_gap + right_gap) >> 2) + b->text_offset_x) > ((b->width - right_gap) - b->text_x)
            && b->text_width >= ((b->width - right_gap - left_gap) - b->text_x - 2))
        {
            b->text_offset_x = -(b->cursor_x + adjust_width + ((right_gap + left_gap) >> 2) - ((b->width - right_gap - left_gap) - b->text_x));
            if ((b->text_offset_x + b->text_width) < ((b->width - right_gap - left_gap) - GUI_INPUTS_SL_LOCATE_CURSOR_L2R_EXTRA_WIDTH))
            {
                b->text_offset_x = ((b->width - right_gap - left_gap) - GUI_INPUTS_SL_LOCATE_CURSOR_L2R_EXTRA_WIDTH) - (b->text_width);
            }
        }
        else if ((b->cursor_x + b->text_offset_x + 2) < (b->text_x + adjust_width - ((right_gap + left_gap) >> 2)))
        {
            b->text_offset_x = -(b->cursor_x - 2 - adjust_width + ((right_gap + left_gap) >> 2));
        }

        if (b->text_offset_x < 0)
        {
            if ((b->text_offset_x + b->text_width) < (b->width - right_gap - left_gap - GUI_INPUTS_SL_LOCATE_CURSOR_L2R_EXTRA_WIDTH))
            {
                b->text_offset_x = (b->width - right_gap - left_gap - GUI_INPUTS_SL_LOCATE_CURSOR_L2R_EXTRA_WIDTH) - (b->text_width);
            }
        }

        /* Reset text_offset_x if text length < editor length */
        if ((b->text_offset_x > 0) || (b->text_width < (b->width - right_gap - left_gap) - GUI_INPUTS_SL_LOCATE_CURSOR_L2R_EXTRA_WIDTH))
        {
            b->text_offset_x = 0;
        }
    #ifdef __MMI_BIDI_ALG__
    }
    else
    {
        if (b->cursor_x < b->text_offset_x)
        {
            b->text_offset_x = b->cursor_x;
        }
        else if (b->cursor_x - (b->width - right_gap - left_gap) + adjust_width > b->text_offset_x)
        {
            b->text_offset_x =  b->cursor_x - (b->width - right_gap - left_gap) + adjust_width;
        }
        /* Adjust view */
        if (b->cursor_x < adjust_width)
        {
            b->text_offset_x -= adjust_width;
        }
        if (b->text_offset_x < (b->width - right_gap - left_gap - GUI_INPUTS_SL_LOCATE_CURSOR_R2L_EXTRA_WIDTH - b->text_width))
        {
            b->text_offset_x = b->width - right_gap - left_gap - GUI_INPUTS_SL_LOCATE_CURSOR_R2L_EXTRA_WIDTH - b->text_width;
        }
        /* Reset text_offset_x if text length < editor length */
        if ((b->text_offset_x > 0) || (b->text_width < (b->width - right_gap - left_gap) - GUI_INPUTS_SL_LOCATE_CURSOR_R2L_EXTRA_WIDTH))
        {
            b->text_offset_x = 0;
        }
    }
    #endif /* __MMI_BIDI_ALG__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_delete_character
 * DESCRIPTION
 *  Deletes a character before the current cursor position (Backspace)
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_single_line_input_box_delete_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        b->current_text_p = b->input_mode_cursor_p;
    }

    #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__    
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE;
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        b->highlight_start_position = NULL;
        b->highlight_end_position = NULL;
        return gui_single_line_input_box_delete_all(b);
    }
    #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/

    if (b->current_text_p != b->text)
    {
        if(b->change_event_handler)
        {
            UI_buffer_type tmp_p = b->current_text_p;

            UI_STRING_GET_PREVIOUS_CHARACTER(tmp_p,dummy_c);
            
            if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c))
                return MMI_FALSE;
        }
    }
    else
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_change();
        }
        return MMI_FALSE;
    }
    
    current_text_p = b->current_text_p;
    previous_text_p = b->current_text_p;
    if (previous_text_p == b->text)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_change();
        }
        return MMI_FALSE;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(previous_text_p, dummy_c); /* get previous caharcter */

    gui_single_line_input_box_ascii_encoding_handling(b, dummy_c, 0);

    b->text_length -= ((S32) current_text_p - (S32) previous_text_p);   /* update text length ..decrease value */
    b->current_text_p = previous_text_p;    /* set teh current_tet_p equalto previous */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
    {
        UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(dummy_c, b->UCS2_count, b->allocated_length, b->available_length);
    }
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CHECK_GSM_EXTENDED)
    {
        UI_TEST_GSM_DECREMENT_COUNT(dummy_c, b->GSM_ext_count);
    }
    
    while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
    }
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    }
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;

    //gui_show_single_line_input_box(b);          /* show single line input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate the cursor position of single lie input box */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->input_mode_cursor_p, dummy_c);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the current cursor position (Delete)
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_delete_current_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_text_p = b->current_text_p;
    previous_text_p = b->current_text_p;
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);    /* get next character */
    if (!UI_STRING_END_OF_STRING_CHARACTER(current_character))  /* check for end of string */
    {
        if (b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(
                current_character,
                b->allocated_length,
                b->UCS2_count,
                b->available_length);
        }
        if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CHECK_GSM_EXTENDED)
        {
            UI_TEST_GSM_DECREMENT_COUNT(current_character, b->GSM_ext_count);
        }
        while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
        }
        b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
        if (b->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
        }
        //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
        //gui_show_single_line_input_box(b);          /* show single line input box */
        //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
        //gui_single_line_input_box_locate_cursor(b); /* locate cursor postion */
        gui_single_line_input_box_locate_cursor_no_draw(b);
        b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);  /* call validation callback func */
        b->change_callback();
    }
    else
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_change();    /* play tone */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_delete_all
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_single_line_input_box_delete_all(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    UI_buffer_type p = b->text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(p, c);
    UI_UNUSED_PARAMETER(c);
    /* MTK Elvis 20040611 donot play tone while text buffer is zero */
    if (b->text_length <= ENCODING_LENGTH)
    {
        return MMI_FALSE;
    }

    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETEALL,0))
            return MMI_FALSE;
    }
    #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__    
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE)
    {
         b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE;
         b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
         b->highlight_start_position = NULL;
         b->highlight_end_position = NULL;
    }
    #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/ 

    gui_single_line_input_box_clear(b);         /* initialize single line input box to default */
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single line input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor position of sigle lien input box */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between Insert and Overwrite modes
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_toggle_insert_mode(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE;
    }
    else
    {
        b->flags |= UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_insert_character_in_pos
 * DESCRIPTION
 *  Inserts a character at the desired position
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 *  pos     [IN]        Is the inserted position in bytes
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_insert_character_in_pos(single_line_input_box *b, UI_character_type c, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p_insert, p1;
    UI_character_type old_c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->last_position_p - b->text) >= (b->available_length))
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_insert();
        }
        return;
    }

    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,(U16)c))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
    }

    p_insert = b->text + pos;
    if (b->current_text_p >= p_insert)
        b->current_text_p += ENCODING_LENGTH;

    p1 = p_insert;
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(p_insert, old_c);
        UI_STRING_INSERT_CHARACTER(p1, c);
        c = old_c;
    }
    UI_STRING_INSERT_CHARACTER(p1, c);  /* insert character */
    
    b->text_length += ENCODING_LENGTH;
    
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single lien input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor psotion */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_delete_character_in_pos
 * DESCRIPTION
 *  Inserts a character at the current cursor position
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  pos     [IN]        Is the desired position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_delete_character_in_pos(single_line_input_box *b, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p_insert, p1;
    UI_character_type c;
    UI_character_type dummy_c = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pos >= b->text_length - ENCODING_LENGTH)
        return;

    if(b->change_event_handler)
    {
        UI_buffer_type tmp_p = b->text + pos;
        
        UI_STRING_GET_NEXT_CHARACTER(tmp_p,dummy_c);
        
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c))
            return;
    }
    
    p_insert = b->text + pos;
    if (b->current_text_p > p_insert)
        b->current_text_p -= ENCODING_LENGTH;
    p1 = p_insert;
    
    UI_STRING_GET_NEXT_CHARACTER(p1, c);
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, c);
        UI_STRING_INSERT_CHARACTER(p_insert, c);
    }
    
    b->text_length -= ENCODING_LENGTH;
    
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single lien input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor psotion */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_insert_character
 * DESCRIPTION
 *  Inserts a character at the current cursor position
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_single_line_input_box_insert_character(single_line_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U8 flag = 0;
    U32 b_flags = b->flags;
    MMI_BOOL input_mode_flag = MMI_FALSE;
    S32 text_length = b->text_length;
    U32 temp_0x81 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        b->current_text_p = b->input_mode_cursor_p;
        input_mode_flag = MMI_TRUE;
    }
    #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE)
    {
        if (input_mode_flag)
        {
            gui_single_line_input_box_stop_input(b);
        }
        gui_single_line_input_box_delete_all(b);
        if (input_mode_flag)
        {
            gui_single_line_input_box_start_input(b);
        }
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE;
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        b->highlight_start_position = NULL;
        b->highlight_end_position = NULL;
    }
    #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/

    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,(U16)c))
        {
            /* play the error tone in change event handler */
            //UI_editor_play_tone_cannot_insert();    /* play error tone */
            return MMI_FALSE;
        }
    }

    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
    {
        if((text_length >> 1) -1 < b->available_length - 3) // current character count = text lenght /2 - NULL
        {
            if(text_length >=2) // NULL should use at least 2 bytes
            {
                ((U16*)b->text)[(text_length/2)-1] = c;
                ((U16*)b->text)[(text_length/2)  ] = 0;
                temp_0x81 = srv_phb_convert_to_0x81((U16*) b->text, MMI_FALSE);
                ((U16*)b->text)[(text_length/2)-1] = 0;
            }
        }
        else
            temp_0x81 = srv_phb_convert_to_0x81((U16*) b->text, MMI_FALSE);
    }
    
    if ((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING) && (0 != temp_0x81))
    {
        if ((text_length >> 1) >= (b->allocated_length >> 1) - 3)
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return MMI_FALSE;
        }
    }
    else
    {
        if (b_flags & UI_SINGLE_LINE_INPUT_BOX_CHECK_GSM_EXTENDED)
        {
            if (b->UCS2_count == 0 && !UI_TEST_UCS2_CHARACTER(c))
            {
                text_length += (b->GSM_ext_count * ENCODING_LENGTH);
            }
        }

        if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
            UI_TEST_UCS2_CHARACTER(c))
        {
            if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                (b->text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
            {
                if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
                {
                    UI_editor_play_tone_cannot_insert();
                }
                return MMI_FALSE;
            }
            else if (b->text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
            {
                if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
                {
                    UI_editor_play_tone_cannot_insert();
                }
                return MMI_FALSE;
            }
        }

        if ((b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ASCII_ENCODING_BASE_LENGTH) && (b->non_ascii_count == 0) &&
            !UI_TEST_ASCII_CHARACTER(c))
        {
            if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
            {
                if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
                {
                    UI_editor_play_tone_cannot_insert();
                }
                return MMI_FALSE;
            }
            else if (text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
            {
                if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
                {
                    UI_editor_play_tone_cannot_insert();
                }
                return MMI_FALSE;
            }
        }
    }
    p1 = p2 = b->current_text_p;
    if (b_flags & UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE)
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next caharater */
        if ((p1 == b->last_position_p) && ((b->last_position_p - b->text) >= b->available_length))
        {
            return MMI_FALSE;
        }
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of character */
        {

            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert caharactr */

            gui_single_line_input_box_ascii_encoding_handling(b, old_c, c);

            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->current_text_p = p2;

            //MTK Elvis for R2L characters
            //It is not required to increase the length while in overwrite mode
            //b->text_length+=ENCODING_LENGTH;     //incraese length of text
            //MTK end
        }
        else
        {
            p1 = b->current_text_p;

            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);   /* get next character */
            while (!UI_STRING_END_OF_STRING_CHARACTER(c))   /* check for end of character */
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
                UI_STRING_INSERT_CHARACTER(p2, c);          /* insert character */
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);

            gui_single_line_input_box_ascii_encoding_handling(b, old_c, c);

            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }
    else
    {
        if ((b->text_length >= (b->available_length)) &&
            !((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING) && (0 != temp_0x81)))
        {
            if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_insert();
            }
            return MMI_FALSE;
        }
        /* check if leading zero flag is set or not ,
           if leading zero flag is false and if character is not zero then a chatracter is insert */
        if (numeric_leading_zero == FALSE)
        {
            if (b->text[0] == 48)
            {
                if (p1 == b->text)
                {
                    if (c == 48)
                    {
                         UI_editor_play_tone_invalid_data();
                         return MMI_FALSE;
                    }
                }
                else if ((b->text_length == 4) || (p1 == b->text + ENCODING_LENGTH))
                {
                    if (c == 48)
                    {
                        UI_editor_play_tone_invalid_data();
                        return MMI_FALSE;
                    }

                    if (c != 46) /* '.' */ 
                    {
                        p1 = b->text;
                        flag = 2;
                        UI_STRING_INSERT_CHARACTER(p1, c);  /* insert a charcter */
                    }
                }
            }
            else if ((p1 == b->text) && (b->text_length > ENCODING_LENGTH) && (b->text[0] != '.'))
            {
                if (c == '0')
                {
                    UI_editor_play_tone_invalid_data();
                    return MMI_FALSE;
                }
            }
        }
        if (flag == 0)
        {
            if ((b->flags & UI_SINGLE_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) &&
                (b->UCS2_count == 0))
            {
                if (UI_TEST_GSM_EXTENDED(c))
                {
                    if ((text_length + ENCODING_LENGTH) >= b->available_length)
                    {
                        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
                        {
                            UI_editor_play_tone_cannot_insert();
                        }
                        return MMI_FALSE;
                    }
                }
                else
                {
                    if (text_length >= b->available_length)
                    {
                        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
                        {
                            UI_editor_play_tone_cannot_insert();
                        }
                        return MMI_FALSE;
                    }
                }
            }

            UI_TEST_GSM_INCREMENT_COUNT(c, b->GSM_ext_count);
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);   /* get next character */

            gui_single_line_input_box_ascii_encoding_handling(b, 0, c);

            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c, b->UCS2_count, b->allocated_length, b->available_length);
                }
            }

            while (!UI_STRING_END_OF_STRING_CHARACTER(c))   /* check for end of string */
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }

    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single lien input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor psotion */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);

    
    if (flag == 0 && (b->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE))
    {
        UI_STRING_GET_NEXT_CHARACTER(b->input_mode_cursor_p, dummy_c);
    }

    return MMI_TRUE;
}

#if 0  /* slim_2_2 */ //
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
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_first_position
 * DESCRIPTION
 *  check for overflow..if the length is equal to availabel lengt or not
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte return true if length is equa to available length else false
 *****************************************************************************/
U8 gui_single_line_input_box_test_first_position(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->current_text_p == b->text)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_last_position
 * DESCRIPTION
 *  check for overflow..if the length is equal to availabel lengt or not
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte return true if length is equa to available length else false
 *****************************************************************************/
U8 gui_single_line_input_box_test_last_position(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    
    if (b->text_length == ENCODING_LENGTH           /* content is empty */
        || current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_last_character_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_single_line_input_box_test_last_character_position(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_last_position_overflow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_single_line_input_box_test_last_position_overflow(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag1 = 0;
    U8 flag2 = 0;
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        flag1 = 1;
    }
    if ((b->last_position_p - b->text) >= (b->available_length))
    {
        flag2 = 1;
    }
    if (flag1 && flag2)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_get_text_length
 * DESCRIPTION
 *  Return text length
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  S32 :- return text length
 *****************************************************************************/
S32 gui_single_line_input_box_get_text_length(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((b->text_length) >> 1) - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_insert_multitap_character
 * DESCRIPTION
 *  Inserts a multitap character at the current cursor position
 *  
 *  This function is normally used as the input_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_single_line_input_box_insert_multitap_character(single_line_input_box *b, UI_character_type c)
{
#if 1
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter = 0;
    S32 multitap_char_num = 0;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

    S32 str_len;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        if (b->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE)
        {
            /* because b->cursor_p will be adjust for languge for show, so we use b->input_mode_cursor_p to cal multitap number */
            multitap_char_num = (b->input_mode_cursor_p - b->input_start_cursor_p) / ENCODING_LENGTH;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

           if(to_decide_to_reshuffle_inline == 1)
           {                                                            
                str_len =(b->input_start_cursor_p+4) - (b->text) ;
                ire_reshuffling_editor_buffer_for_bengali_spec(b->text, str_len);
                to_decide_to_reshuffle_inline = 0;
           }
#endif

            for (counter = 0; counter < multitap_char_num; counter++)
            {
                gui_single_line_input_box_delete_character(b);
            }
        }
        else
        {
            gui_single_line_input_box_delete_character(b);
        }
    }
    
    if(gui_single_line_input_box_insert_character(b, c) == MMI_FALSE)
    {
        //b->show_action_flag = 1;
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
        return MMI_FALSE;
    }
    else
    {
        b->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    }

    gui_single_line_input_box_locate_cursor_no_draw(b);


    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    return MMI_TRUE; 
}
#endif
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
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))
/* under construction !*/
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
    #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__
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
    #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/
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
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_confirm_multitap_character
 * DESCRIPTION
 *  Completes the multitap input sequence.
 *  
 *  This function is normally used as the input_complete_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_confirm_multitap_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;

    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b);
    gui_single_line_input_box_locate_cursor_no_draw(b);
}



/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_get_previous_character
 * DESCRIPTION
 *  get  the previous character
 * PARAMETERS
 *  b               [IN]        Is the single-line inputbox object
 *  c               [?]         
 *  means(?)        [OUT]       None, 1 means have one, save in c
 * RETURNS
 *  void
 *****************************************************************************/
U8 gui_single_line_input_box_get_previous_character(single_line_input_box *b, UI_character_type *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        return 0;
    }
    if (b->current_text_p == b->text)
    {
        return 0;
    }
    *c = (*(b->current_text_p - 2)) | (*(b->current_text_p - 1)) << 8;
    return 1;
}

/* msz065_20050420 Peng Hua add for multitap thai input method end */


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_previous
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_single_line_input_box_previous(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_lm_cluster_info cur_cluster;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return MMI_FALSE;
    }
    if (b->current_text_p == b->text)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return MMI_FALSE;
    }
    #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE;
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        b->highlight_start_position = NULL;
        b->highlight_end_position = NULL;
    }
    #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/

    gui_single_line_input_box_confirm_multitap_character(b);

    mmi_lm_get_prev_cluster(b->text, b->text + b->text_length - ENCODING_LENGTH, b->current_text_p, MMI_TRUE, &cur_cluster);

    b->current_text_p = cur_cluster.data_ptr;

    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single line input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    return MMI_TRUE;
}

#if 0  /* slim_2_2 */ //
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
#endif 

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_next
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_single_line_input_box_next(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p;
    UI_character_type current_character;
    mmi_lm_cluster_info cur_cluster;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* text buffer is empty and want to navigate next --> play error tone if not disable tones */
    if (b->text == NULL)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return MMI_FALSE;
    }
    #ifdef __MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_AUTO_CLEAR_HIGHLIGHT_MODE;
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        b->highlight_start_position = NULL;
        b->highlight_end_position = NULL;
        
        return MMI_TRUE;
    }
    #endif /*__MMI_EDITOR_SL_AUTO_CLEAR_HILITE_MODE__*/

    gui_single_line_input_box_confirm_multitap_character(b);
    
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
    /* if current character is end of string and want to navigate next --> play error tone if not disable tones */
    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return MMI_FALSE;
    }

    mmi_lm_get_next_cluster(b->current_text_p, b->text + b->text_length, b->current_text_p, MMI_TRUE, &cur_cluster);
    b->current_text_p = cur_cluster.data_ptr;

    ///b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b);
    gui_single_line_input_box_locate_cursor_no_draw(b);

    return MMI_TRUE;
}

#if 0  /* slim_2_2 */ //
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
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_resize_single_line_input_box
 * DESCRIPTION
 *  Changes the size of the single-line inputbox.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_single_line_input_box(single_line_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;
    b->height = height;
    /* Autocalculate the text position based on font   */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_Y)
    {
        S32 string_height;

        gui_set_font(b->text_font);
        string_height = gui_get_character_height();
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 2;
    }
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single inout box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    gui_single_line_input_box_locate_cursor_no_draw(b);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_goto_first_character
 * DESCRIPTION
 *  Move the cursor to first chahrcter
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_goto_first_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->current_text_p = b->text;
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single line input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    gui_single_line_input_box_locate_cursor_no_draw(b);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_goto_last_character
 * DESCRIPTION
 *  Move the cursor to last  chahrcter
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_goto_last_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->current_text_p = b->text;
    if (b->text != NULL)
    {
        while (!done)
        {
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
        }
        if (b->current_text_p != b->text)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
        }
    }
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single line inut box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    gui_single_line_input_box_locate_cursor_no_draw(b);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_highlight_cursor_end
 * DESCRIPTION
 *  Move the cursor to last  chahrcter
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  S32 count return the number of charcters traverse
 *****************************************************************************/
S32 gui_single_line_input_box_highlight_cursor_end(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->current_text_p;
    UI_buffer_type current_position = b->current_text_p;
    UI_buffer_type previous_position;
    UI_buffer_type last_position_p = b->last_position_p;
    U8 done = 0;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_PREVIOUS_CHARACTER(last_position_p, current_character);
    /* Move cursor backwards until a break character is encountered   */
    while (!done)
    {
        previous_position = current_position;
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        count++;
        if (UI_STRING_SPACE_CHARACTER(current_character))
        {
            break;  /* check for space */
        }
    }
    b->highlight_start_position = previous_position;
    current_position = saved_current_position;
    /* Move cursor forwards until a break character is encountered */
    if (current_position >= last_position_p)
    {
        done = 1;
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
    {
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);      /* get next character */
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);  /* get previous charcter */
        if (UI_STRING_SPACE_CHARACTER(current_character))   /* check for space */
        {
            done = 1;
            b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
        else
        {
            done = 0;
            b->flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
    }
    while (!done)
    {
        if (current_position >= last_position_p)
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        count++;
        if (UI_STRING_SPACE_CHARACTER(current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
            break;
        }
    }
    b->highlight_end_position = current_position;
    b->current_text_p = current_position;
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single line input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_highlight_cursor_number
 * DESCRIPTION
 *  Move the cursor to last  chahrcter
 * PARAMETERS
 *  b               [IN]        Is the single-line inputbox object
 *  numOfChar       [IN]        
 * RETURNS
 *  S32 count return the number of charcters traverse
 *****************************************************************************/
S32 gui_single_line_input_box_highlight_cursor_number(single_line_input_box *b, S32 numOfChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->current_text_p;
    UI_buffer_type current_position = b->current_text_p;

    /* UI_buffer_type previous_position; */
    UI_character_type current_character;
    S32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        current_position = b->input_mode_cursor_p;
    }

    for (i = 0; i < numOfChar; i++)
    {
        /* previous_position=current_position; */
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);  /* get previous charcter */
        count++;
    }

    b->highlight_start_position = current_position;
    current_position = saved_current_position;
    b->highlight_end_position = current_position;
    b->current_text_p = current_position;
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single lien input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    UI_UNUSED_PARAMETER(current_character);
    return (count);
}

/* for second word highlight */


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_highlight_cursor_number_backward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  numOfChar       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_single_line_input_box_highlight_cursor_number_backward(single_line_input_box *b, S32 numOfChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->current_text_p;
    UI_buffer_type current_position = b->current_text_p;

    /* UI_buffer_type previous_position; */
    UI_character_type current_character = 0xff;
    S32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < numOfChar; i++)
    {
        /* previous_position=current_position; */
        if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);      /* get previous charcter */
        count++;
    }

    current_position = saved_current_position;
    b->current_text_p = current_position;
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single lien input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_highlight_cursor_start
 * DESCRIPTION
 *  Move the cursor to last  chahrcter
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  S32 count return the number of charcters traverse
 *****************************************************************************/
S32 gui_single_line_input_box_highlight_cursor_start(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->current_text_p;
    UI_buffer_type current_position = b->current_text_p;
    UI_buffer_type previous_position;
    UI_buffer_type last_position_p = b->last_position_p;
    U8 done = 0;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_position == b->text)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);      /* get previous charcter */
    /* Move cursor forwards until a break character is encountered */
    while (!done)
    {
        if (current_position >= last_position_p)
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        count++;
        if (UI_STRING_SPACE_CHARACTER(current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
            break;
        }
    }
    b->highlight_end_position = current_position;
    current_position = saved_current_position;
    /* Move cursor backwards until a break character is encountered   */
    if (current_position == b->text)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
    if (UI_STRING_SPACE_CHARACTER(current_character))   /* check for space */
    {
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    else
    {
        done = 0;
        b->flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    while (!done)
    {
        previous_position = current_position;
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        count++;
        if (UI_STRING_SPACE_CHARACTER(current_character))
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    b->current_text_p = previous_position;
    //b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_single_line_input_box(b);          /* show single line input box */
    //b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    gui_single_line_input_box_locate_cursor_no_draw(b);
    return (count);
}

#if 0  /* slim_2_2 */ //
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
#endif
/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_insert_string
 * DESCRIPTION
 *  insert a string in single lien input box at particular poistion
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  s       [IN]        String to insert
 *  o       [IN]        Index
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_single_line_input_box_insert_multitap_string(single_line_input_box *b, UI_string_type s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    U8 done = 0;
    S32 count = 0;
    UI_character_type c;
    UI_buffer_type text = (UI_buffer_type) s;
    S32 counter = 0;
    S32 characters_deleted = 0;
    S32 strlen = 0;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	UI_buffer_type temp_texp_p;
	S32 str_len;
#endif
#ifdef __MMI_EDITOR_SINGLE_SUPPORT_MULTIGRAPH__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->ext_flags & UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        b->current_text_p = b->input_mode_cursor_p;
    } 
    characters_deleted = (b->current_text_p - b->input_start_cursor_p);
#ifndef __MMI_MULTITAP_BANGLA_SPEC__    
    if(characters_deleted == 0)
    {
        UI_editor_play_tone_cannot_insert();
        return 0;
    }
#endif    
    strlen = mmi_ucs2strlen((CHAR*)s);

    /* loop to return in case we dont have space to enter the character */
    if(b->change_event_handler)
    {
        if (!(b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_STRING,(U16)(strlen - characters_deleted/ENCODING_LENGTH))))
        {
            UI_editor_play_tone_cannot_insert();
            return 0;
        }

        /*
        if (wgui_get_cat2001_buf_used_size() + strlen - characters_deleted/ENCODING_LENGTH > (wgui_singleline_inputbox_buffer_size - 1))
        {
            return 0;
        } 
        */
    }
    
    /* Return if editor is full */
    if ((b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0))
    {
        if ((b->flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
            (b->text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
        {
            if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_insert();
                return 0;
            }
        }
        
        else if (b->text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
        {
            if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_insert();
                return 0;
            }
        }
    }
    
    
    if ((b->text_length - characters_deleted + strlen >= (b->available_length)))
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_insert();
            return 0;
        }
    }

    /* Go back the number of times to insert new candidate */
    for(counter = 0; counter < characters_deleted / ENCODING_LENGTH; counter++)
    {
        gui_single_line_input_box_delete_character(b);
    }
    while (!done)
    {
        UI_STRING_GET_NEXT_CHARACTER(text, c);
        if (UI_STRING_END_OF_STRING_CHARACTER(c))
        {
            done = 1;
            break;
        }
        /* Check if we can insert the character */
        if(gui_single_line_input_box_insert_character(b, c) ==  MMI_FALSE)
        {
            S32 i = 0;
            for(i = 0; i < count; i++)
            {
                gui_single_line_input_box_delete_character(b);
            }
            done = 1;
            return 0;
        }
        count++;
    }
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	if(mtkmultitap_ire_bengali_ndicator == 1)
	{
		temp_texp_p =  (UI_buffer_type) s;
		if(( temp_texp_p[0] | (temp_texp_p[1] << 8)) == 0x09b0)
			{
				temp_texp_p += 2;
				if(( temp_texp_p[0] | (temp_texp_p[1] << 8)) == 0x09cd)
				{                                                                    
					str_len =(b->input_start_cursor_p+4) - (b->text) ;
					ire_shuffling_editor_buffer_for_bengali_spec(b->text, str_len);
					to_decide_to_reshuffle_inline = 1;
				}
			}
	}
#endif
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
#endif /*__MMI_EDITOR_SINGLE_SUPPORT_MULTIGRAPH__*/    
    return (count);
}
/* GUI: multiline input box functions              */

UI_multi_line_input_box_theme *current_multi_line_input_box_theme = NULL;

#define UI_MULTI_LINE_INPUT_BOX_NUMBER_OF_BREAK_CHARACTERS     2        /* 15 */
#define MULTILINE_INPUTBOX_DISPLAY_WHOLE_LINES              1
#define MULTILINE_INPUTBOX_USE_CRLF_COMBINATION             1
/* To use this flag, turn ON EMS_DISPLAY_SPECIAL_CHARACTERS also (outside this file)   */
#define MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS       0
#define MULTILINE_INPUTBOX_USE_GSM_EXTENDED                 1

UI_character_type multi_line_input_box_break_characters[] = { ' ',
    /*
     * '.',
     * ',',
     * '\\',
     * '/',
     * '-',
     * ':',
     * ';',
     * '?',
     * '!',
     * '|',
     * '+',
     * '=',
     * '_',
     */
    '\n'
};

/* Linear search. Should be improved to something else   */
#define UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(c,flag)                                               \
      {  S32 _ii_;                                                                                    \
         flag=0;                                                                                      \
         for(_ii_=0;_ii_<UI_MULTI_LINE_INPUT_BOX_NUMBER_OF_BREAK_CHARACTERS;_ii_++)                   \
         {  if((UI_character_type)c==(UI_character_type)multi_line_input_box_break_characters[_ii_])  \
            {  flag=1;                                                                                \
               break;                                                                                 \
            }                                                                                         \
         }                                                                                            \
      }


/* Basic Latin,Latin 1,Latin Extended A, Latin Extended B */
/* Cyrillic */
/* Latin Extended Additional  */
/* Combining Marks  */
/* Basic Arabic  */
/* Arabic Presentation Forms-A */
/* Arabic Presentation Forms-B */




/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_show_cursor
 * DESCRIPTION
 *  show cursor of  multiline input box
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object
 *  x           [IN]        
 *  y           [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void gui_multi_line_input_box_show_cursor(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 height,
        S32 clip_x1,
        S32 clip_y1,
        S32 clip_x2,
        S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = b->cursor_color;
    S32 x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.06 Fix Cursor Clipping issue when storing cursor area to bmp */
    gdi_layer_get_clip(&x1, &y1, &x2, &y2);

    cursor_multiline_input = b;

    if (y1 > clip_y1)
        clip_y1 = y1;
    if (y2 < clip_y2)
        clip_y2 = y2;

    gdi_layer_push_clip();
    gdi_layer_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    if (x > clip_x2)
    {
        x = clip_x2;
    }
    x--;
    if (x < clip_x1)
    {
        x = clip_x1;
    }
    if (y < clip_y1)
    {
        height -= (clip_y1 - y + 1);
        y = clip_y1 + 1;
    }
    if ((y + height - 1) > clip_y2)
    {
        height -= (y + height - 1) - clip_y2;
    }
#if(UI_BLINKING_CURSOR_SUPPORT)
    if (y > (b->y + b->height) || (y + height) < b->y)
        StopTimer(BLINKING_CURSOR);
    else
        UI_inputbox_show_cursor(x, y, x + 1, y + height - 1, c);
#else 
    UI_cursor_x1 = x;
    UI_cursor_y1 = y;
    UI_cursor_x2 = x+1;
    UI_cursor_y2 = y+height - 1;

    gui_fill_rectangle(x, y, x + 1, y + height - 1, c);
#endif 
    gdi_layer_pop_clip();
}




/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_current_theme
 * DESCRIPTION
 *  Applies the current theme to the multi-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_input_box_current_theme(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = current_multi_line_input_box_theme->normal_filler;
    b->disabled_filler = current_multi_line_input_box_theme->disabled_filler;
    b->focussed_filler = current_multi_line_input_box_theme->selected_filler;
    b->text_filler = NULL;  /* Disabled by default */
    b->special_text_color = current_multi_line_input_box_theme->special_text_color;
    b->normal_text_color = current_multi_line_input_box_theme->normal_text_color;
    b->disabled_text_color = current_multi_line_input_box_theme->disabled_text_color;
    b->focussed_text_color = current_multi_line_input_box_theme->selected_text_color;
    b->selector_color = current_multi_line_input_box_theme->selection_color;
    b->selected_text_color = current_multi_line_input_box_theme->selection_text_color;
    b->cursor_color = current_multi_line_input_box_theme->cursor_color;
    b->text_font = current_multi_line_input_box_theme->text_font;
    b->mask_character = current_multi_line_input_box_theme->mask_character;
    b->text_gap = current_multi_line_input_box_theme->text_gap;
    b->flags |= current_multi_line_input_box_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_theme
 * DESCRIPTION
 *  Applies the given theme to the multi-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  t       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_input_box_theme(multi_line_input_box *b, UI_multi_line_input_box_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = t->normal_filler;
    b->disabled_filler = t->disabled_filler;
    b->focussed_filler = t->selected_filler;
    b->text_filler = NULL;  /* Disabled by default */
    b->special_text_color = t->special_text_color;
    b->normal_text_color = t->normal_text_color;
    b->disabled_text_color = t->disabled_text_color;
    b->focussed_text_color = t->selected_text_color;
    b->boundary_color = t->boundary_color;
    b->selector_color = t->selection_color;
    b->selected_text_color = t->selection_text_color;
    b->cursor_color = t->cursor_color;
    b->text_font = t->text_font;
    b->text_gap = t->text_gap;
    b->mask_character = t->mask_character;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_clear
 * DESCRIPTION
 *  Initilize the multi-line inputbox to default
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_clear(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        b->text_length = 0;
        b->allocated_length = 0;
        b->available_length = 0;
        return;
    }
    else
    {
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if(!gui_multi_line_input_box_clear_wcss(b))
#endif 
        {
            b->text[0] = '\0';
            b->text[1] = 0;
            b->text_length = 2;
        }
    }
    b->cursor_p = b->text;
    b->last_position_p = b->text;
    b->UCS2_count = 0;
    b->GSM_ext_count = 0;
    b->non_ascii_count = 0;
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) ||
        (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_USE_ASCII_ENCODING_BASE_LENGTH))
    {
        b->available_length = b->allocated_length;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_text_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object   (pre-allocated)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_input_box_text_size(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->normal_filler->flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
    {
        b->edit_height = b->height - b->text_y - 1 - 4;
    }
    else if (b->normal_filler->flags & UI_FILLED_AREA_BORDER)
    {
        b->edit_height = b->height - b->text_y - 1 - 2;
    }
    else
        b->edit_height = b->height - b->text_y - 1;
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_reset_create_flag
 * DESCRIPTION
 *
 * PARAMETERS
 *  void   
 * RETURNS
 *  U8 the old value
 *****************************************************************************/
U8 gui_multi_line_reset_create_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 old = g_multi_create_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_multi_create_flag = 0;
    return old;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_set_create_flag
 * DESCRIPTION
 *
 * PARAMETERS
 *  void   
 * RETURNS
 *  U8  the old value
 *****************************************************************************/
U8 gui_multi_line_set_create_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 old = g_multi_create_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_multi_create_flag = 1;
    return old;
}

#if 0  /* slim_2_2 */ //
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
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* under construction !*/
#if(UI_BLINKING_CURSOR_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT 
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_FTE_SUPPORT__
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
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */
/* under construction !*/
#if(UI_BLINKING_CURSOR_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT 
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_FTE_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  gui_create_multi_line_input_box_set_buffer
 * DESCRIPTION
 *  Creates a multi-line inputbox object,
 *  Starts with a given string and allows the user to edit it.
 * PARAMETERS
 *  b                   [IN]        Is the multi-line inputbox object   (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the multi-line inputbox
 *  height              [IN]        Is the height of the multi-line inputbox
 *  buffer              [IN]        Is the buffer to use          (pre-allocated)
 *  length              [IN]        Is the length of the buffer         (buffer size)
 *  text_length         [IN]        Is the number of characters in the text
 *  edit_position       [IN]        Is the start position of the cursor
 *  Note(?)             [IN]        The buffer should contain a valid string.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_multi_line_input_box_set_buffer(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /* MTK Elvis to init this parameter */
    UI_character_type dummy_c = '\0';

    
    UI_buffer_type text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* so many members need to be set zero. To avoid non-initialized bug, use memset*/
    memset(b, 0, sizeof(multi_line_input_box));

    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->allocated_length = length;
    b->available_length = length;
    b->text_length = text_length;
    b->cursor_fixed_x = -1;
    b->cursor_p = b->text;
    b->show_action_flag = 1;
	b->force_stop_line_index = -1;
    memset(&g_visible_multiline_line_info, 0, sizeof(g_visible_multiline_line_info));
    memset(&g_multiline_line_info, 0, sizeof(g_multiline_line_info));
    b->visible_line_info = &g_visible_multiline_line_info;
    b->line_info = &g_multiline_line_info;
    
    if (b->text != NULL)
    {
/* PMT START FOR_7.17INDIC */
        text = b->text;
        UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
        text = b->text;
        for (i = 0; i < text_length/2; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
           
        }
/* PMT END FOR_7.17INDIC */
        text = b->text;
        UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
        text = b->text;
        for (i = 0; i < edit_position; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
/* PMT START FOR_7.17INDIC */
//REMOVED
/* PMT END FOR_7.17INDIC */

            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);

            UI_TEST_NON_ASCII_INCREMENT_COUNT(dummy_c, b->non_ascii_count);

            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
            if (UI_TEST_GSM_EXTENDED(dummy_c))
            {
                b->GSM_ext_count++;
            }
        }
        b->cursor_p = text;
        for (i = edit_position; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);

/* PMT START FOR_7.17INDIC */
//REMOVED
/* PMT END FOR_7.17INDIC */
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);

            UI_TEST_NON_ASCII_INCREMENT_COUNT(dummy_c, b->non_ascii_count);
            
            if (UI_TEST_GSM_EXTENDED(dummy_c))
            {
                b->GSM_ext_count++;
            }
        }
        b->last_position_p = b->cursor_p;
    }
    /* set theme of multiline input bx */
    gui_set_multi_line_input_box_current_theme(b);

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    if (MMI_multi_line_inputbox_present)
    {
        /* native editor in inline, default gap value*/
        b->margin.left_margin = b->margin.right_margin = GUI_MULTI_LINE_LEFT_RIGHT_MARGIN;
        b->margin.top_margin = b->margin.down_margin = GUI_MULTI_LINE_TOP_DOWN_MARGIN;
        
        b->text_x = b->text_gap + b->margin.left_margin;
        b->text_y = b->margin.top_margin;
    }
    else
#endif
    {
        /* native editor, default gap value*/
        b->margin.left_margin = b->margin.right_margin = 2;
        b->margin.top_margin = 2;
        b->margin.down_margin = 0;
        
        b->text_x = b->text_gap + b->margin.left_margin;
        b->text_y = b->margin.top_margin;
    }    
    
    b->text_x2_gap_width = 0;
    b->edit_width = b->width - (b->text_x + b->text_x2_gap_width);
    //b->edit_height = b->height - (b->text_y * 2);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        gui_create_vertical_scrollbar(
            &b->vbar,
            b->x + b->width - current_multi_line_input_box_theme->vbar_width - 1,
            b->y + 1,
            current_multi_line_input_box_theme->vbar_width,
            b->height - 2);
        b->edit_width -= b->vbar.width;

#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
        gui_vertical_scrollbar_enable_clear_background(&b->vbar, MMI_FALSE);
#endif
    }
    
    gui_multi_line_input_box_register_infobar_callback(b,NULL,NULL,0);

    b->last_cursor_offset = -1;
#ifdef __MMI_TOUCH_SCREEN__
    b->pen_scroll_after_delay = -1;
    b->pen_scroll_delay_time = 100;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if(UI_BLINKING_CURSOR_SUPPORT)
    if (cursor_multiline_input == b)
        StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 

    gui_set_multi_line_input_box_text_size(b);

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT 
    gui_inputs_cache_create(b);
#endif

    gui_multi_line_set_create_flag();

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    gui_input_box_ssp_set_client_callback(
        gui_multiline_ssp_update_client, 
        gui_multiline_ssp_get_client_info, 
        b);
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    cursor_multiline_input = NULL;

    gui_inputs_register_cursor_callback();
#ifdef __MMI_FTE_SUPPORT__
    g_editor_background_transparent = MMI_FALSE;
#endif
}

//Gurinder - 5/5/2004 Inline Multiline Box History Control
//Duplicate Function With No Position Reset.


/*****************************************************************************
 * FUNCTION
 *  gui_create_multi_line_input_box_set_buffer_no_text_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [?]         
 *  x                   [IN]        
 *  y                   [IN]        
 *  width               [IN]        
 *  height              [IN]        
 *  buffer              [IN]        
 *  length              [IN]        
 *  text_length         [IN]        
 *  edit_position       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_multi_line_input_box_set_buffer_no_text_reset(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    UI_character_type dummy_c = 0;
    UI_buffer_type text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* so many members need to be set zero. To avoid non-initialized bug, use memset*/
    memset(b, 0, sizeof(multi_line_input_box));

    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->allocated_length = length;
    b->available_length = length;
    b->text_length = text_length;
    b->cursor_fixed_x = -1;
    b->cursor_p = b->text;
    if (b->text != NULL)
    {
        text = b->text;
        for (i = 0; i < edit_position; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);

            UI_TEST_NON_ASCII_INCREMENT_COUNT(dummy_c, b->non_ascii_count);
            
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
            if (UI_TEST_GSM_EXTENDED(dummy_c))
            {
                b->GSM_ext_count++;
            }
        }
        b->cursor_p = text;
        for (i = edit_position; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            UI_TEST_NON_ASCII_INCREMENT_COUNT(dummy_c, b->non_ascii_count);
            if (UI_TEST_GSM_EXTENDED(dummy_c))
            {
                b->GSM_ext_count++;
            }
        }
        b->last_position_p = b->cursor_p;
    }

	b->force_stop_line_index = -1;
    memset(&g_visible_multiline_line_info, 0, sizeof(g_visible_multiline_line_info));
    memset(&g_multiline_line_info, 0, sizeof(g_multiline_line_info));
    b->visible_line_info = &g_visible_multiline_line_info;
    b->line_info = &g_multiline_line_info;

    /* set theme of multiline input bx */
    gui_set_multi_line_input_box_current_theme(b);
    b->text_x = 2 + b->text_gap;
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    if (MMI_multi_line_inputbox_present)
    {
        b->margin.left_margin = b->margin.right_margin = GUI_MULTI_LINE_LEFT_RIGHT_MARGIN;
        b->margin.top_margin = b->margin.down_margin = GUI_MULTI_LINE_TOP_DOWN_MARGIN;        
        b->text_x = b->text_gap + b->margin.left_margin;
        b->text_y = b->margin.top_margin;
    }
    else
#endif
    {
        b->margin.left_margin = b->margin.right_margin = 2;
        b->margin.top_margin = 2;
        b->margin.down_margin = 0;
        
        b->text_x = b->text_gap + b->margin.left_margin;
        b->text_y = b->margin.top_margin;
    }

    b->text_x2_gap_width = 0;
    b->edit_width = b->width - (b->text_x + b->text_x2_gap_width);
    //b->edit_height = b->height - (b->text_y * 2);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    gui_create_vertical_scrollbar(
        &b->vbar,
        b->x + b->width - current_multi_line_input_box_theme->vbar_width - 1,
        b->y + 1,
        current_multi_line_input_box_theme->vbar_width,
        b->height - 2);
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        b->edit_width -= b->vbar.width;
    }
    gui_multi_line_input_box_register_infobar_callback(b,NULL,NULL,0);
    b->last_cursor_offset = -1;

#ifdef __MMI_TOUCH_SCREEN__
    b->pen_scroll_after_delay = -1;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if(UI_BLINKING_CURSOR_SUPPORT)
    if (cursor_multiline_input == b)
        StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 

    gui_set_multi_line_input_box_text_size(b);

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT 
    gui_inputs_cache_create(b);
#endif

    cursor_multiline_input = NULL;

    gui_inputs_register_cursor_callback();
#ifdef __MMI_FTE_SUPPORT__
    g_editor_background_transparent = MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_multi_line_input_box
 * DESCRIPTION
 *  Moves a multi-line input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  x       [IN]        Is the new position (left-top corner)
 *  y       [IN]        Is the new position (left-top corner)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_multi_line_input_box(multi_line_input_box *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->cursor_fixed_x = -1;
    gui_move_vertical_scrollbar(&b->vbar, b->x + b->width - b->vbar.width - 1, b->y + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_multi_line_input_box
 * DESCRIPTION
 *  Moves a multi-line input box
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object
 *  width       [IN]        
 *  height      [IN]        
 *  x(?)        [IN]        Is the new position (left-top corner)
 *  y(?)        [IN]        Is the new position (left-top corner)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_multi_line_input_box(multi_line_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_resize_multi_line_input_box_no_draw(b, width, height);

    //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(b);   /* show multiline input box */
    //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_no_draw(b);
}

void gui_resize_multi_line_input_box_no_draw(multi_line_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width_change = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width != b->width || height != b->height)
    {
        b->cursor_fixed_x = -1;
    //    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }
    
    if (width != b->width)
        width_change = 1;
    
    b->width = width;
    b->height = height;
    b->edit_width = b->width - (b->text_x + b->text_x2_gap_width);
    //b->edit_height = b->height - (b->text_y * 2);
    gui_set_multi_line_input_box_text_size(b);

#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR;
    }
#endif /* __MMI_FTE_EDITOR_SCROLLBAR_STYLE__*/

    if (mmi_fe_get_r2l_state())
    {
        gui_move_vertical_scrollbar(&b->vbar, b->x, b->y + 1);
    }
    else
    {
        gui_move_vertical_scrollbar(&b->vbar, b->x + b->width - b->vbar.width - 1, b->y + 1);
    }
    gui_resize_vertical_scrollbar(&b->vbar, b->vbar.width, b->height - 2);

#ifndef __MMI_EDITOR_FORCE_AUTO_SCROLLBAR__
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__) || defined(__UI_LINEBASE_IN_MULTILINE_EDITOR__)/**/
    if (!((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)|| 
        (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)))
    {
        gui_set_vertical_scrollbar_range(&b->vbar, 0);
        gui_set_vertical_scrollbar_scale(&b->vbar, 0);
    }
#endif /*__UI_PAGING_IN_MULTILINE_EDITOR__  __UI_LINEBASE_IN_MULTILINE_EDITOR__ */ /**/  
#endif /*__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__*/

    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        b->edit_width -= b->vbar.width;
    }
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (width_change)
    {
        gui_mlc_all_line_update();
    }
#endif
    
    if (cursor_multiline_input == b)
        StopTimer(BLINKING_CURSOR);
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_set_margin
 * DESCRIPTION
 *  set margin for multiline input box
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object
 *  top         [IN]        top >0: set new value; -1: use default value
 *  down        [IN]        down >0: set new value; -1: use default value
 *  left        [IN]        left >0: set new value; -1: use default value
 *  right       [IN]        right >0: set new value; -1: use default value
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_set_margin(multi_line_input_box *b, S32 top, S32 down, S32 left, s32 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (top >= 0)
    {
        b->margin.top_margin = (U8)top;

        /* has been computed in create function, so recomputed */
        b->text_y = b->margin.top_margin;        
        gui_set_multi_line_input_box_text_size(b);
    }
    
    if (down >= 0)
    {    
        b->margin.down_margin = (U8)down;
    }
    
    if (left >= 0)
    {
        b->margin.left_margin = (U8)left;

        /* has been computed in create function, so recomputed */
        b->text_x = b->margin.left_margin + b->text_gap;        
        b->edit_width = b->width - b->margin.left_margin - b->margin.right_margin - 2 * b->text_gap;
        if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
        {            
            b->edit_width -= b->vbar.width;
        }
    }
    
    if (right >= 0)
    {
        b->margin.right_margin = (U8)right;
        b->edit_width = b->width - b->margin.left_margin - b->margin.right_margin - 2 * b->text_gap;
        if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
        {            
            b->edit_width -= b->vbar.width;
        }
    }    
}
#if 0  /* slim_2_2 */ //
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
#endif 

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_first_position
 * DESCRIPTION
 *  check forif cursor is at first position of  multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_first_position(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->cursor_p == b->text)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_last_position
 * DESCRIPTION
 *  check forif cursor is at last  position of  multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_last_position(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_first_line
 * DESCRIPTION
 *  check if cursor is at first line of  multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_first_line(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->line_before_cursor_line_p == b->cursor_line_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_last_line
 * DESCRIPTION
 *  check if cursor is at last line of  multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_last_line(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->line_after_cursor_line_p == b->cursor_line_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_last_position_overflow
 * DESCRIPTION
 *  check forif cursor is at last  position of  multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_last_position_overflow(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag1 = 0;
    U8 flag2 = 0;
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        flag1 = 1;
    }
    if ((b->last_position_p - b->text) >= (b->available_length))
    {
        flag2 = 1;
    }
    if (flag1 && flag2)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_get_text_length
 * DESCRIPTION
 *  return the text length of multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
S32 gui_multi_line_input_box_get_text_length(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((b->text_length) >> 1) - 1);
}

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
/****************WCSS Related Functions***********************/

/* Cursor position previously set by WCSS editor.
   This variable is used to avoid unnecessary input method switching 
   when cursor is not moved. */
static UI_buffer_type WCSS_cursor_pos = NULL;
extern U8 *cat115buffer;


void gui_set_WCSS_Esc_Char(MMI_BOOL v)
{
    WCSS_Esc_Char = v;
}

/* Set # Key Depeding Upon The Value Of Status Parameter. */

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_clear_wcss
 * DESCRIPTION
 *  Initilize the multi-line inputbox to default
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_clear_wcss(multi_line_input_box *b)
{  
    if(b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE)
    {
        UI_buffer_type old_cursor=NULL;
        while(old_cursor != b->cursor_p)
        {
            old_cursor = b->cursor_p;
            gui_multi_line_input_box_next(b);
        }

        old_cursor = NULL;
        while(old_cursor != b->cursor_p)
        {
            old_cursor = b->cursor_p;
            gui_multi_line_input_box_delete_character(b);
        }
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_WCSS_input_method_change_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_set_WCSS_input_method_change_handler(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (status)
    {
        mmi_imm_config_change_input_mode(MMI_TRUE);
    }
    else
    {
        mmi_imm_config_change_input_mode(MMI_FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_reset_WCSS_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_reset_WCSS_cursor_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WCSS_cursor_pos = NULL;
}

/* Change the input method on cursor movement. */


/*****************************************************************************
 * FUNCTION
 *  gui_change_WCSS_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_change_WCSS_input_method(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL active_multitap;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE))
    {
        return;
    }
    active_multitap = mmi_imc_check_multitap_state();
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        active_multitap = MMI_TRUE;
    /* Prevent gui_show_multi_line_input_box() invokes this function recursively */
    WCSS_input_change_enable = 0;
    
    if (b->cursor_p - b->text >= b->allocated_length - 2
        && !active_multitap)
        gui_set_WCSS_input_method_change_handler(0);

    while (WCSS_cursor_pos != b->cursor_p &&
           (b->cursor_p - b->text) < (b->allocated_length - 2) /* out-of-edit area */ )
    {
        U16 temp_var;
        U8 input_method;

        UI_buffer_type prv_cursor_pos = WCSS_cursor_pos;

        temp_var = ((b->cursor_p - b->text) >> 1);

        /* If \c appears in the head of input format */
        if (temp_var == 0)
        {
            while (cat115buffer[temp_var] == 0xFF)
            {
                gui_multi_line_input_box_next(b);
                temp_var = ((b->cursor_p - b->text) >> 1);
            }
        }

        /* Set WCSS_cursor_pos if input mode is chaged here */
        if (WCSS_Esc_Char || !active_multitap)
        {
            WCSS_cursor_pos = b->cursor_p;
        }

        if (cat115buffer[temp_var] == 0xFF)
        {
            if (WCSS_Esc_Char || !active_multitap)
            {
                /* It always invokes gui_change_WCSS_input_method again (recursive) */
                if (prv_cursor_pos > b->cursor_p)
                {
                    gui_multi_line_input_box_previous(b);
                }
                else
                {
                    gui_multi_line_input_box_next(b);
                }
            }
            else
            {
                break;
            }
        }

        temp_var = ((b->cursor_p - b->text) >> 1);
        input_method = cat115buffer[temp_var] & 0x1F;

        if (WCSS_Esc_Char || !active_multitap)
        {
            /* If switch from 'm' to 'm', do not switch input method automatically. */
            if (!(cat115buffer[temp_var] & PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED) ||
                !prv_cursor_pos ||
                !(cat115buffer[(prv_cursor_pos - b->text) >> 1] & PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED)
                || ((cat115buffer[(prv_cursor_pos - b->text) >> 1] & PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED) 
                     && cat115buffer[(prv_cursor_pos - b->text) >> 1] != cat115buffer[temp_var]))
            {
                /* If entry category115 from history (prv_cursor_pos = WCSS_cursor_pos was set to NULL), 
                   we should not change the input method according the WCSS input format string to
                   keep the previous input method in history */
                if (prv_cursor_pos /* not first time in category screen */  ||
                    is_fisrt_entry_WCSS_editor /* input method was not set in history */ )
                {
                    if (mmi_imm_get_curr_input_mode() != (input_method & (~PIXTEL_UI_WCSS_STAR_INPUT)))
                    {
                        gui_lock_double_buffer();
                        gui_set_WCSS_input_method_change_handler(1);
                        mmi_imm_change_input_mode_for_wcss((mmi_imm_input_mode_enum)(input_method & (~PIXTEL_UI_WCSS_STAR_INPUT)));
                        change_multiline_information_bar_input_method();
                        gui_unlock_double_buffer();
                    }
                }
                is_fisrt_entry_WCSS_editor = MMI_FALSE;

                if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_123)
                {
                    mmi_imc_disable_symbol_picker();
                }
                else
                {
                    mmi_imc_enable_symbol_picker();
                }
            }

            if (((input_method & 0xFF) == IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC || (input_method & 0xFF) == IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC) && cat115buffer[temp_var] & PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED)     /* 'm' and 'M', not 'x' or 'X' */
            {
                if ((input_method & 0xFF) == IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC)
                {
                    mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_EXT_MULTITAP | IMM_INPUT_TYPE_EXT_ENGLISH_UPPERCASE, NULL, IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC);
                    gui_set_WCSS_input_method_change_handler(1);
                    mmi_imm_change_input_mode_for_wcss(IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC);
                    change_multiline_information_bar_input_method();
                }
                else
                {
                    mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_SENTENCE | IMM_INPUT_TYPE_EXT_MULTITAP, NULL, IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);            
                    gui_set_WCSS_input_method_change_handler(1);
                    mmi_imm_change_input_mode_for_wcss(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);
                    change_multiline_information_bar_input_method();
                }
                
            }
            else
            {
                gui_set_WCSS_input_method_change_handler(0);
            }
        }

        if (cat115buffer[((b->cursor_p - b->text) >> 1)] != 0xFF)
        {
            break;
        }
    }

    /* hjf: set again because cursor position is changed */
    if (WCSS_Esc_Char || !active_multitap)
        WCSS_cursor_pos = b->cursor_p;

    WCSS_input_change_enable = 1;
    WCSS_Esc_Char = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_WCSS_check_next_multitap_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_WCSS_check_next_multitap_input(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_var;
    U8 input_method;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_var = ((b->cursor_p - b->text) >> 1);
    while (cat115buffer[temp_var] == 0xFF)
    {
        temp_var++;
    }
    input_method = cat115buffer[temp_var] & 0x1F;
    if (input_method == IMM_INPUT_MODE_123 || input_method == IMM_INPUT_MODE_123_SYMBOLS)       /* Add Here Other Input Method For Which Multitap is not require. */
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Wrapper function for WCSS_input_change_enable Variable use to Enable Input Method Change
//While deleting the characters.


/*****************************************************************************
 * FUNCTION
 *  gui_WCSS_input_method_change_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_WCSS_input_method_change_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WCSS_input_change_enable;
}

/****************************WCSS Related Functions**************************/
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

/* Set The Editor Chnaged Variable To True On Contents Change. */


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_change(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->editor_changed = 1;
}

/* bar code */

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_go_to_hilite_no_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  idx         [IN]        
 *  by_pen      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_go_to_hilite_no_draw(multi_line_input_box *b, U16 idx)
{
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    if (idx <= b->hilite_str_number - 1)
    {

        b->highlight_start_position = (UI_buffer_type) (b->hilite_list[idx].str_addr);
        b->highlight_end_position = (UI_buffer_type) (b->hilite_list[idx].str_addr + b->hilite_list[idx].length * 2);
        b->current_hilite_idx = idx;
    }

    b->hilite_cb(b->current_hilite_idx);
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(idx);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_go_to_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  idx         [IN]        
 *  by_pen      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_go_to_hilite(multi_line_input_box *b, U16 idx, MMI_BOOL need_scroll_to_pos)
{
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    if (idx <= b->hilite_str_number - 1 && idx >= 0)
    {
        b->highlight_start_position = (UI_buffer_type) (b->hilite_list[idx].str_addr);
        b->highlight_end_position = (UI_buffer_type) (b->hilite_list[idx].str_addr + b->hilite_list[idx].length * 2);
        b->current_hilite_idx = idx;

        /* if hilite type is none, no need to scroll */
        if (b->hilite_list[idx].hilite_type == EDITOR_HILITE_NONE)
        {
            need_scroll_to_pos = MMI_FALSE;
        }
    }

    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_basic(b, -1, -1);   /* show multiline input box */
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    if (need_scroll_to_pos)
    {
        if(b->text_height > b->edit_height)
        {
            S32 highy = -b->curr_hilite_text_offset_y;
            S32 oy = -b->text_offset_y;

            // check if highlight begin is above the windows begin
            if( highy <= oy) 
            {
                // move window begin to highlight begin
                b->text_offset_y = b->curr_hilite_text_offset_y;
            }
            // check if highlight end is below the window end
            else if(oy+b->edit_height < highy + b->max_line_height*2)
            {
                // move window begin to the hightlight end - window height
                b->text_offset_y = - ( highy + b->max_line_height*2 -b->edit_height);
            }
        }
    }
    gui_show_multi_line_input_box(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);
    if(b->hilite_cb)
    {
        b->hilite_cb(b->current_hilite_idx);
    }
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(idx);
    UI_UNUSED_PARAMETER(need_scroll_to_pos);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}

S32 gui_multi_line_input_box_is_highligter_in_visible_area(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (-b->curr_hilite_text_offset_y < -b->text_offset_y) 
    {
        return -1;
    }
    else if(-b->curr_hilite_text_offset_y > -b->text_offset_y + b->edit_height)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_is_hilite_in_visible_range
 * DESCRIPTION
 *  Check if specific hilite index in the visible range
 * PARAMETERS
 *  b                [IN]        multiline inputbox object
 *  hilite_idx       [IN]        hilite index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_is_hilite_in_visible_range(multi_line_input_box *b, U16 hilite_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
	if (!b->hilite_list || (hilite_idx >= b->hilite_str_number))
	{
		return MMI_FALSE;
	}

    if (hilite_idx == 0 ||
        hilite_idx == b->hilite_str_number - 1)
    {
        return MMI_TRUE;
    }

    if ((b->hilite_list[hilite_idx].str_addr - (S8*)b->text + b->hilite_list[hilite_idx].length * ENCODING_LENGTH) > (b->visible_start * ENCODING_LENGTH)
            && (b->hilite_list[hilite_idx].str_addr - (S8*)b->text) < (b->visible_end * ENCODING_LENGTH))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/


    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(hilite_idx);
    return MMI_FALSE;  

    
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_find_hilite_in_visible_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_multi_line_input_box_find_hilite_in_visible_range(multi_line_input_box *b, MMI_BOOL b_first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hilite_no = b->hilite_str_number;
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    if (!b_first)
    {
        i = hilite_no - 1;
    }

    while(i >= 0 && i < hilite_no)
    {
        if ((b->hilite_list[i].str_addr - (S8*)b->text + b->hilite_list[i].length * ENCODING_LENGTH) > (b->visible_start * ENCODING_LENGTH)
            && (b->hilite_list[i].str_addr - (S8*)b->text) < (b->visible_end * ENCODING_LENGTH))
        {
            return i;
        }

        if (b_first)
        {
            i++;
        }
        else
        {
            i--;
        }
    }
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(b_first);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_next_line_with_hilite_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_next_line_with_hilite_list(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = b->current_hilite_idx;
    UI_buffer_type start_p = NULL;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    if(b->hilite_str_number == 0)
    {
        gui_multi_line_input_box_next_line(b);
        return;
    }
    
    /* if the current hilite is not at the visible area, locate to the first hilite at the visible area */
    /* if ((b->hilite_list[b->current_hilite_idx].str_addr - (S8*)b->text) >= (b->visible_end * ENCODING_LENGTH)
        || (b->hilite_list[b->current_hilite_idx].str_addr - (S8*)b->text + b->hilite_list[b->current_hilite_idx].length * ENCODING_LENGTH)
        <= (b->visible_start * ENCODING_LENGTH)) */

    ret = gui_multi_line_input_box_is_highligter_in_visible_area(b);
    
    if (ret)
    {
        if (ret < 0)
        {
            index = gui_multi_line_input_box_find_hilite_in_visible_range(b, MMI_TRUE);
        }
        else
        {
            index = gui_multi_line_input_box_find_hilite_in_visible_range(b, MMI_FALSE);
        }
        
        if (index >= 0 && (b->current_hilite_idx != index))
        {
            gui_multi_line_input_box_go_to_hilite(b, (U16)index, MMI_FALSE);
            return;
        }
        else
        {
            gui_multi_line_input_box_next_line(b);
            return;
        }
    }
    else
    {
        if (b->current_hilite_idx < b->hilite_str_number - 1)
        {
            /* attemp to the next hilite */
            index = b->current_hilite_idx + 1;
            start_p = (UI_buffer_type) (b->hilite_list[index].str_addr);
            if (start_p < (b->text + b->visible_end * ENCODING_LENGTH))
            {
                gui_multi_line_input_box_go_to_next_hilite_ext(b, MMI_FALSE);
                return;
            }
        }

        gui_multi_line_input_box_next_line(b);
    }
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_previous_line_with_hilite_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_previous_line_with_hilite_list(multi_line_input_box *b)
{
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = b->current_hilite_idx;
    UI_buffer_type end_p = NULL;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(b->hilite_str_number == 0)
    {
        gui_multi_line_input_box_previous_line(b);
        return;
    }
    
    /* if the current hilite is not at the visible area, locate to the first hilite at the visible area */
    /* if ((b->hilite_list[b->current_hilite_idx].str_addr - (S8*)b->text) >= (b->visible_end * ENCODING_LENGTH)
        || (b->hilite_list[b->current_hilite_idx].str_addr - (S8*)b->text + b->hilite_list[b->current_hilite_idx].length * ENCODING_LENGTH)
        <= (b->visible_start * ENCODING_LENGTH)) */
    ret = gui_multi_line_input_box_is_highligter_in_visible_area(b);
    if (ret && b->current_hilite_idx != (b->hilite_str_number - 1))
    {
        if (ret < 0)
            index = gui_multi_line_input_box_find_hilite_in_visible_range(b, MMI_TRUE);
        else
            index = gui_multi_line_input_box_find_hilite_in_visible_range(b, MMI_FALSE);
        
        if (index >= 0 && (b->current_hilite_idx != index))
        {
            gui_multi_line_input_box_go_to_hilite(b, (U16)index, MMI_FALSE);
            return;
        }
        else
        {
            gui_multi_line_input_box_previous_line(b);
            return;
        }
    }
    else
    {
        if (b->current_hilite_idx > 0)
        {
            /* attemp to the next hilite */
            index = b->current_hilite_idx - 1;
            end_p = (UI_buffer_type) (b->hilite_list[index].str_addr + b->hilite_list[index].length * ENCODING_LENGTH);
            if (end_p > (b->text + b->visible_start * ENCODING_LENGTH))
            {
                gui_multi_line_input_box_go_to_pre_hilite_ext(b, MMI_FALSE);
                return;
            }
        }

        gui_multi_line_input_box_previous_line(b);
    }
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_go_to_pre_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_go_to_pre_hilite(multi_line_input_box *b)
{
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    
    gui_multi_line_input_box_go_to_pre_hilite_ext(b, MMI_TRUE);
    
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/

    UI_UNUSED_PARAMETER(b);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
* FUNCTION
*  gui_multi_line_input_box_go_to_pre_hilite_ext
* DESCRIPTION
*  
* PARAMETERS
*  b       [?]     
* RETURNS
*  void
*****************************************************************************/
void gui_multi_line_input_box_go_to_pre_hilite_ext(multi_line_input_box *b, MMI_BOOL b_adjust_y)
{
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    if(b->hilite_str_number == 0) return; // no hilite, no need to scroll anything

    if (b->current_hilite_idx > 0)
    {
        b->current_hilite_idx--;
        b->highlight_start_position = (UI_buffer_type) (b->hilite_list[b->current_hilite_idx].str_addr);
        b->highlight_end_position =
            (UI_buffer_type) (b->hilite_list[b->current_hilite_idx].str_addr +
                              b->hilite_list[b->current_hilite_idx].length * 2);

    }

    if (b_adjust_y)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_basic(b, -1, -1);   /* show multiline input box */
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        
        if(b->text_height > b->edit_height)
        {
            b->text_offset_y = b->curr_hilite_text_offset_y;
        }
    }

    gui_show_multi_line_input_box(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);
    b->hilite_cb(b->current_hilite_idx);
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(b_adjust_y);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_go_to_next_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_go_to_next_hilite(multi_line_input_box *b)
{
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    
    gui_multi_line_input_box_go_to_next_hilite_ext(b, MMI_TRUE);

    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
* FUNCTION
*  gui_multi_line_input_box_go_to_next_hilite_ext
* DESCRIPTION
*  
* PARAMETERS
*  b       [?]     
* RETURNS
*  void
*****************************************************************************/
void gui_multi_line_input_box_go_to_next_hilite_ext(multi_line_input_box *b, MMI_BOOL b_adjust_y)
{
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    if(b->hilite_str_number == 0) return; // no hilite, no need to scroll anything

    if (b->current_hilite_idx < b->hilite_str_number - 1)
    {
        b->current_hilite_idx++;
        b->highlight_start_position = (UI_buffer_type) (b->hilite_list[b->current_hilite_idx].str_addr);
        b->highlight_end_position =
            (UI_buffer_type) (b->hilite_list[b->current_hilite_idx].str_addr +
                              b->hilite_list[b->current_hilite_idx].length * 2);

    }

    if (b_adjust_y)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_basic(b, -1, -1);   /* show multiline input box */
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        
        if(b->text_height > b->edit_height)
        {
            b->text_offset_y = b->curr_hilite_text_offset_y;
        }
    }

    gui_show_multi_line_input_box(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);

    b->hilite_cb(b->current_hilite_idx);
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(b_adjust_y);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_is_pos_inside_hilite_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  current_pos     [IN]        
 *  hilite_idx      [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_is_pos_inside_hilite_ext(
            multi_line_input_box *b,
            UI_buffer_type current_pos,
            U16 *hilite_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    U16 hilite_no = b->hilite_str_number;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_pos)
    {
        for (i = 0; i < hilite_no; i++)
        {
            if (((CHAR*)current_pos >= b->hilite_list[i].str_addr) &&
                ((CHAR*)current_pos < b->hilite_list[i].str_addr + b->hilite_list[i].length * 2))
            {
                *hilite_idx = i;
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(current_pos);
    UI_UNUSED_PARAMETER(hilite_idx);
    return MMI_FALSE;
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_is_pos_inside_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  current_pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_is_pos_inside_hilite(multi_line_input_box *b, UI_buffer_type current_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    U16 hilite_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gui_multi_line_input_box_is_pos_inside_hilite_ext(b, current_pos, &hilite_idx));
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(current_pos);
    return MMI_FALSE;
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_is_pen_down_in_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_is_pen_down_in_hilite(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
    UI_buffer_type current_pos = b->cursor_p;
    U16 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_multi_line_input_box_is_pos_inside_hilite_ext(b, current_pos, &idx))
    {
        b->current_hilite_idx = idx;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    
    UI_UNUSED_PARAMETER(b);
    return MMI_FALSE;
    
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}



/***Ritesh started here***/

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_get_next_page_callback
 * DESCRIPTION
 *  callback function for demand of next page by multiline editor
 * PARAMETERS
 *  b       [IN]        (instance of multi_line_input_box)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_get_next_page_callback(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_index;
    S32 cursor_move;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mbj06060 add for cursor movement at paging mode
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        cursor_move = (b->previous_shared_bytes + GUI_PAGE_SIZE_IN_UCS2) - b->page_details[PAGE_ZERO].shared_no_of_bytes;
        b->cursor_p -= cursor_move;

        if (b->cursor_p < b->text)
            b->cursor_p = b->text;
    }
    
    memcpy(b->text, b->page_details[PAGE_ZERO].shared_data, b->page_details[PAGE_ZERO].shared_no_of_bytes);

    for (page_index = 0; page_index < GUI_NO_OF_PAGES - 1; page_index++)
    {
        memcpy(
            b->text + (GUI_PAGE_SIZE_IN_UCS2 * page_index) + b->page_details[PAGE_ZERO].shared_no_of_bytes,
            b->text + b->previous_shared_bytes + (GUI_PAGE_SIZE_IN_UCS2 * (page_index + 1)),
            GUI_PAGE_SIZE_IN_UCS2);
    }
    b->previous_shared_bytes = b->page_details[PAGE_ZERO].shared_no_of_bytes;

    b->start_id++;
    b->end_id++;
    b->page_details[PAGE_ZERO].page_id = b->start_id;
          
    ASSERT(b->get_page_cb);
    b->get_page_cb(
        b->end_id,
        b->end_id,
        b->text + (GUI_PAGE_SIZE_IN_UCS2 * PAGE_THREE) + b->page_details[PAGE_ZERO].shared_no_of_bytes);
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_ML_PAGING_REQUEST_NEXT_DATA, b->end_id);
    b->text_length = (mmi_ucs2strlen((const CHAR*)b->text)+1)*ENCODING_LENGTH;
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_mlc_all_line_update();
#endif

    show_multiline_inputbox_no_draw();
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_get_previous_page_callback
 * DESCRIPTION
 *  callback function for previous page
 * PARAMETERS
 *  b       [IN]        (instance of multi_line_input_box)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_get_previous_page_callback(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 page_index;
    S32 cursor_move;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->page_details[0].page_id > 0)
    {
        //mbj06060 add for cursor movement at paging mode
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
        {
            cursor_move = GUI_PAGE_SIZE_IN_UCS2 - b->previous_shared_bytes;
            b->cursor_p += cursor_move;
            
            if (b->cursor_p > b->text + b->text_length)
                b->cursor_p = b->text + b->text_length;
        }
        
        b->page_zero_prev_height = b->page_details[PAGE_ZERO].page_height;
        for (page_index = GUI_NO_OF_PAGES - 1; page_index != 0; page_index--)
        {
            memcpy(
                b->text + (GUI_PAGE_SIZE_IN_UCS2 * page_index) + b->previous_shared_bytes,
                b->text + (b->previous_shared_bytes * ENCODING_LENGTH) + (GUI_PAGE_SIZE_IN_UCS2 * (page_index - 1)),
                GUI_PAGE_SIZE_IN_UCS2 - b->previous_shared_bytes);
            memcpy(
                b->text + (GUI_PAGE_SIZE_IN_UCS2 * page_index),
                b->text + (GUI_PAGE_SIZE_IN_UCS2 * (page_index - 1)) + b->previous_shared_bytes,
                b->previous_shared_bytes);
        }

        ASSERT(b->get_page_cb);
        b->get_page_cb(b->start_id - 1, b->start_id - 1, b->text);
        MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_ML_PAGING_REQUEST_PRE_DATA, b->start_id - 1);
        b->previous_shared_bytes = 0;

        b->text_length = (mmi_ucs2strlen((const CHAR*)b->text)+1)*ENCODING_LENGTH;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_mlc_all_line_update();
#endif

        show_multiline_inputbox_no_draw();
        b->start_id--;
        b->end_id--;
    }
}

#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 
/***** ritesh ended here*****/


/*****************************************************************************
 * FUNCTION
 *  gui_show_multi_line_input_box
 * DESCRIPTION
 *  Displays the multi-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 EMS_object_width_cache[];
extern U8 EMS_object_height_cache[];

extern void (*wgui_inline_edit_DONE_function) (void);


void gui_show_multi_line_input_box(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_multi_line_input_box_ext(b, (-1), (-1));
}

/*****************************************************************************
 * FUNCTION
 *  gui_show_multi_line_input_box_no_draw
 * DESCRIPTION
 *  Displays the multi-line inputbox £¬not draw ,just update editor data
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_multi_line_input_box_no_draw(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 saved_flags = b->flags;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
     b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
     gui_show_multi_line_input_box(b);
     b->flags = saved_flags;
}

/*****************************************************************************
 * FUNCTION
 *  gui_show_multi_line_input_box_ext_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

/*****************************************************************************
    while()
    {
        // P1BEGIN
        while()
        {
        }
        // P1END

        bidi_main

        // P2BEGIN
        while()
        {
        }
        // P2END
    }

 ******************************************************************************/
void gui_show_multi_line_input_box_ext_internal(multi_line_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    U32 flags;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if (!g_editor_background_transparent)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    }
#endif
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    flags = b->flags;
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
    {
        gdi_push_and_set_alpha_blending_source_layer(gui_inputs_get_source_layer());
    }
#endif

#ifndef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_show_multi_line_input_box_basic(b, move_to_x, move_to_y);
#else
    
    if (gui_inputs_cache_is_valid())
    {
        MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_ML_ENTER_SHOWN_WITH_CACHE);
        
        gui_show_multi_line_input_box_ext_internal_with_cache(b, move_to_x, move_to_y);

        if (gui_inputs_cache_get_error_code() <= 0)
        {
            MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_ML_ENTER_SHOWN);
            g_editor_line.line_char = temp_line_char;
            gui_show_multi_line_input_box_basic(b, move_to_x, move_to_y);
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_ML_ENTER_SHOWN);
        g_editor_line.line_char = temp_line_char;
        gui_show_multi_line_input_box_basic(b, move_to_x, move_to_y);
    }
    
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
        gdi_pop_and_restore_alpha_blending_source_layer();
#endif
}


void gui_show_multi_line_input_box_basic(multi_line_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    multi_line_input_box_show_struct bs_struct;
    multi_line_input_box_show_struct* bs = &bs_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    g_editor_line.line_char = temp_line_char;
#endif
    
    /* set enter shown function flag */
    in_multiline_shown_flag = 1;

    /* init the structure bs*/
    gui_init_multi_line_show_struct(b, bs);
    
    /* Clear cursor blink x, y position*/
    if (cursor_multiline_input == b)
    {
        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && !(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
        {
            UI_cursor_x1 = 0;
            UI_cursor_y1 = 0;
            UI_cursor_x2 = 0;
            UI_cursor_y2 = 0;
        }
    }
    
    if (((-1) != move_to_x) || ((-1) != move_to_y))
    {
        /* The previouse cursor x offset is invalid*/
        b->cursor_fixed_x = -1;
        bs->find_new_cursor_flag = FINDING_CURSOR;
        bs->move_to_x = move_to_x;
        bs->move_to_y = move_to_y;
    }
    else
    {
        bs->find_new_cursor_flag = NORMAL_CURSOR;
        bs->move_to_x = move_to_x;
        bs->move_to_y = move_to_y;
    }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_PREVIOUSE_LINE
        || b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_NEXT_LINE)
    {
    /* In these case, we need to find the cursor_p. 
        */
        bs->find_new_cursor_flag = FINDING_CURSOR;
    }
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
    {
        overwrite_current_language_for_hindi_rules_based_on_input_method();
    }
#endif 
    
    /* init the multiline structure */
    gui_init_multi_line_input_box_for_show(b, bs);
    
    /* init the cursor related information */
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (!gui_inputs_cache_is_valid())
#endif
    {
        if (!bs->find_new_cursor_flag)
        {
            b->line_before_cursor_line_p = b->text;
            b->cursor_line_p = b->text;
            b->line_after_cursor_line_p = b->text;
            b->line_after_cursor_line_last_p = b->text;
        }
    }

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
    /* adjust the cursor for icon_callback */
    if (b->icon_callback 
        && !(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE))
    {
        b->cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, b->cursor_p, 1);
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/ 

#ifdef __MMI_BIDI_ALG__
    /* get the text BIDI type*/
    gui_get_multi_line_text_language_type(b, bs);
#endif /* __MMI_BIDI_ALG__ */ 
    
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__) || defined(__UI_LINEBASE_IN_MULTILINE_EDITOR__)/**/   
    if ( b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE||
        b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)
    {
        if (b->override_direction == 1)
            bs->default_direction = BIDI_L;
        else if (b->override_direction == 2)
            bs->default_direction = BIDI_R;
    }
#endif /*__UI_PAGING_IN_MULTILINE_EDITOR__  __UI_LINEBASE_IN_MULTILINE_EDITOR__ */ /**/   

    /* Current implementation does not support icon_callback on overwrite mode */
    MMI_DBG_ASSERT(!(bs->flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE) || !b->icon_callback);
    
    /* Setup runtime variables */
    bs->current_cursor_p = b->cursor_p;  /* points to the character at which the cursor is positioned */
    bs->previous_cursor_p = b->cursor_p;
   
    /* prepare the layout area*/
    gui_prepare_multi_line_show_area(b, bs);
    
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    /*
    * Evertime the cursor position is changed, GUI will invoke the current function,
    * there is no other place to hook it cleanly.
    * However, it's protected by the flag UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE
    */
    if (b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE && gui_WCSS_input_method_change_enable())
    {
        /* gui_change_WCSS_input_method() will change cursor position */
        gui_change_WCSS_input_method(b);
        bs->current_cursor_p = b->cursor_p;
        bs->previous_cursor_p = b->cursor_p;
    }
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ /* MMI_WCSS_INPUT_FORMAT_SUPPORT_ */
    
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
    {
        gdi_get_alpha_blending_source_layer(&bs->scr_layer);
    }
#endif

    /* draw the editor background*/
    gui_draw_multi_line_background_area(b, bs);
    
    /* update the text area range */
    gui_set_multi_line_text_area_range(b, bs);
    
    /* begin to analyse text*/
    if (b->text != NULL)
    {
        /* Setup clipping for text and icon */
        gui_setup_multi_line_text_clip(b, bs);
        
        /* Set the default text font*/
        gui_set_multi_line_default_font(b, bs);
        
        if (bs->previous_cursor_p && bs->previous_cursor_p != b->text)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(bs->previous_cursor_p, dummy_c);
        }
        
        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            bs->multitap_flag = 1;
        }
        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
        {
            bs->overwrite_flag = 1;
        }
        if (bs->default_direction == BIDI_L)
        {
            /* normal direction layount*/
            bs->xx = bs->x1 + b->text_x + b->text_offset_x;
        }
#ifdef __MMI_BIDI_ALG__      
        else
        {
            /* from right to left, text_x and text_offset_x is moved to the right*/
            bs->xx = bs->x1;
        }
#endif /* __MMI_BIDI_ALG__ */      
        
        bs->yy = bs->y1 + b->text_y + b->text_offset_y + bs->border_y;
        bs->ty = b->header_height + b->header_gap;
        b->max_line_height = 0;
        bs->current_text_p = b->text;
        g_editor_line.line_height = 0;    

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        if (gui_inputs_cache_is_valid() && b->cache_begin_callback)
            b->cache_begin_callback(b, bs);
#endif

        /***************MULTILINE BIG LOOP BEGIN *****************************/
        while (!bs->end_line && (bs->edit_width >= 0))
        {
            /* start to check the text content line by line*/
            gui_prepare_multi_line_new_line_loop(b, bs);
            
            /* restore the default font size */
            gui_set_font(&(bs->rich_text.curr_font)); 
            
            /* find one line to break */
            bs->end_line = !gui_find_multi_line_one_line(b, bs);
            if (g_editor_line.line_unit_count == 0)
                bs->end_line = 1;

            /* adjust the current line height by the min_line_height */
            if (g_editor_line.line_height > g_editor_line.line_ascent + g_editor_line.line_dscent)
            {
                g_editor_line.line_ascent += g_editor_line.line_height
                    - (g_editor_line.line_ascent + g_editor_line.line_dscent);
            }

            if (b->min_line_height > g_editor_line.line_height)
            {
                g_editor_line.line_ascent += b->min_line_height - g_editor_line.line_height;
                g_editor_line.line_height = b->min_line_height;
            }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            if (gui_inputs_cache_is_valid() && b->cache_line_ready_callback)
            {
             /*   if(bs->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE 
                    && bs->end_line 
                    && bs->line_counter > 0
                    && g_editor_line.line_unit_count == 0)
                {
                    g_editor_line.line_height = 0;
                    g_editor_line.line_ascent = 0;
                    g_editor_line.line_dscent = 0;
                }*/

                /* for marker separator */
                if (bs->rich_text.line_separator)
                {
                    if (!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                    { 
                        S32 yoffset = 12; /* separator-line space */
                        /* this separator followed line's g_editor_line.height includes 2 * yoffset */
                        g_editor_line.line_height += 2 * yoffset;
                    }
                }

                if (!b->cache_line_ready_callback(b, bs))
                {
                    /* the line information query is end or error, break it */
                    in_multiline_shown_flag = 0;
                    return;
                }
            }
#endif

            /* prepare to show the current line */
            gui_prepare_multi_line_one_line_show(b, bs);

            /* 
            * Now we can check the cursor line and the cursor_y, but we can't 
            * get the cursor_x, which need to be got at this line drawn(maybe bidi).
            */
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            if (!gui_inputs_cache_is_valid())
#endif
            gui_set_multi_line_cursor_information(b, bs);
            
            /* should not break before gui_set_multi_line_cursor_information to guarantee the
               cursor information save completely (like b->line_after_cursor_line_p)*/
            if (!gui_save_multi_line_visible_info(b, bs))
                break;
            
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
            /* calculate the paging information */
            #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
            if (!gui_inputs_cache_is_valid() 
                || b->cache_update_type == GUI_INPUT_BOX_CACHE_UPDATE_ALL)
            #endif
                gui_calculate_multi_line_paging_information(b, bs);
#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT        
            if (!gui_inputs_cache_is_valid())
#endif
            {
                if ((b->hilite_list != NULL && (bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
                    || (bs->yty + g_editor_line.line_height > bs->y1 - GUI_INPUT_BOX_ADDITION_AREA
                    && bs->yty < bs->y2 + GUI_INPUT_BOX_ADDITION_AREA))
                {
                    /* only draw the visible area */
#ifdef __MMI_BIDI_ALG__
                    /* try to apply the BIDI alg to the current text content */
                    gui_translate_multi_line_bidi_text(b, bs);
#endif
                    /* draw the current line */
                    gui_draw_multi_line_one_line(b, bs);
                }
            }
            
            gui_end_multi_line_new_line_loop(b, bs);
            
            if (bs->flags & UI_MULTI_LINE_INPUT_BOX_ONLY_SHOW_FIRST_LINE)
            {
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
                if (!gui_inputs_cache_is_valid())
#endif  
                {
                    /* Used by WAP to emulate single line input gadget  */
                    bs->end_line = 1;
                }
            }
        }
        
        gui_end_multi_line_text_display(b, bs);
    }
    else
    {
        bs->yy = bs->y1 + b->text_y + b->text_offset_y + bs->border_y;
    }

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    if (gui_inputs_cache_is_valid())
    {
        in_multiline_shown_flag = 0;
        return;
    }
#endif

    /* adjust the cursor_p for language special requirement*/
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    if (b->predefine_char_pos == NULL)
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/        
    {
        gui_adjust_multi_line_cursor_for_language(b, bs); 
    }

    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) 
        && (bs->flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)
        &&!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
    {
        gui_draw_multi_line_under_line(b, bs);
    }
    
    /* draw header, footer, lefter and righter */
    gui_draw_multi_line_callback_area(b, bs);
    
    /* Footer area should be included in b->text_height */
    bs->ty += b->footer_height;
    if (!bs->is_truncate)
    {
        b->text_height = bs->ty;
    }
    if (b->text_height < (EDIT_MAX(b->left_height, b->right_height)))
        b->text_height = EDIT_MAX(b->left_height, b->right_height);
    
    /* set the scroll bar position and draw the scroll bar */
    gui_set_multi_line_scroll_bar(b, bs);
    gui_show_multi_line_scroll_bar(b, bs);
    
    /* update some information outside of the multiline editor, but why? */
    gui_update_multi_line_extern_module_infomation(b, bs);
    
    /* adjust the text_offset_y by some reason: paging adjust, cursor adjust*/
    gui_adjust_multi_line_text_offset_y(b, bs);
    
    gui_multi_line_show_special_remaining_counter(b);
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    restore_current_language_for_hindi_rules();
#endif 
 
    /* add for predefine char limitation */
    if (!mmi_imc_is_clipboard_state())
    {
        backup_b = b;
        /* gui_start_timer(1, gui_multiline_predefined_cursor_move_timer_hdlr); */
        gui_multiline_predefined_cursor_move_timer_hdlr();
    }
    
    if (((b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL) ==
        UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL) && !b->vertical_scroll_on)
    {
#if(UI_BLINKING_CURSOR_SUPPORT)
        StopTimer(BLINKING_CURSOR);
#endif 
        gui_cancel_timer(multiline_inputbox_vertical_scroll);
        gui_start_timer(UI_MULTI_LINE_INIT_SCROLL, multiline_inputbox_vertical_scroll);
    }

    /* exit shown function */
    in_multiline_shown_flag = 0;

    UI_UNUSED_PARAMETER(dummy_c);
}

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
void gui_show_multi_line_input_box_ext_internal_with_cache(multi_line_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    UI_character_type dummy_c = 0;
    multi_line_input_box_show_struct bs_struct;
    multi_line_input_box_show_struct* bs = &bs_struct;
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    static S32 old_indic_rules = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* set enter shown function flag */
    in_multiline_shown_flag = 1;

    /* init the structure bs*/
    gui_init_multi_line_show_struct(b, bs);
    
    /* Clear cursor blink x, y position*/
    if (cursor_multiline_input == b)
    {
        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && !(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
        {
            UI_cursor_x1 = 0;
            UI_cursor_y1 = 0;
            UI_cursor_x2 = 0;
            UI_cursor_y2 = 0;
        }
    }

    if (gui_mlc_is_dirty(b))
    {
        gui_inputs_cache_create(b);
        gui_mlc_all_line_update();

        if (gui_inputs_cache_get_error_code() <= 0)
        {
            in_multiline_shown_flag = 0;
            return;
        }
    }

#if defined(__MMI_FTE_EDITOR_SCROLLBAR_STYLE__) || defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__)
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE
        || b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_ONLY_VISIBLE_LINE)
#else
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR
        || b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE
        || b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_ONLY_VISIBLE_LINE)
#endif

    {
        gui_inputs_cache_invalid();
        in_multiline_shown_flag = 0;
        return;
    }

    /* request the visible line cache ready */
    EDITOR_LOCK;

    while (gui_mlc_visible_line_shown_request() < 0)
    {
        if (gui_inputs_cache_get_error_code() <= 0)
        {
            in_multiline_shown_flag = 0;
            EDITOR_UNLOCK;
            return;
        }
        
        gui_mlc_partial_line_update();

        if (gui_inputs_cache_get_error_code() <= 0)
        {
            in_multiline_shown_flag = 0;
            EDITOR_UNLOCK;
            return;
        }
    }

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (gui_jump_multi_line_paging_visible_area(b) > 0)
    {
        gui_mlc_visible_line_shown_request();

        if (gui_inputs_cache_get_error_code() <= 0)
        {
            in_multiline_shown_flag = 0;
            EDITOR_UNLOCK;
            return;
        }
    }
#endif

    if (((-1) != move_to_x) || ((-1) != move_to_y))
    {
        /* The previouse cursor x offset is invalid*/
        b->cursor_fixed_x = -1;
        bs->find_new_cursor_flag = FINDING_CURSOR;
        bs->move_to_x = move_to_x;
        bs->move_to_y = move_to_y;
    }
    else
    {
        bs->find_new_cursor_flag = NORMAL_CURSOR;
        bs->move_to_x = move_to_x;
        bs->move_to_y = move_to_y;
    }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_PREVIOUSE_LINE
        || b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_NEXT_LINE)
    {
    /* In these case, we need to find the cursor_p. 
        */
        bs->find_new_cursor_flag = FINDING_CURSOR;
    }
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
    {
        overwrite_current_language_for_hindi_rules_based_on_input_method();
        if (old_indic_rules != (S32)indic_rules_current_set_language)
        {
            gui_mlc_all_line_update();
            old_indic_rules = (S32)indic_rules_current_set_language;
        }
    }
#endif 
    
    /* init the multiline structure */
    gui_init_multi_line_input_box_for_show(b, bs);
    
    /* init the cursor related information */
    if (!bs->find_new_cursor_flag)
    {
        b->line_before_cursor_line_p = b->text;
        b->cursor_line_p = b->text;
        b->line_after_cursor_line_p = b->text;
        b->line_after_cursor_line_last_p = b->text;
    }
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
    /* adjust the cursor for icon_callback */
    if (b->icon_callback 
        && !(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE))
    {
        b->cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, b->cursor_p, 1);
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/ 

#if defined ( __MMI_BIDI_ALG__)
    /* get the text BIDI type*/
    gui_get_multi_line_text_language_type(b, bs);
#endif /* __MMI_BIDI_ALG__ */ 
    
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__) || defined(__UI_LINEBASE_IN_MULTILINE_EDITOR__)/**/
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE||
        b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)
    {
        if (b->override_direction == 1)
            bs->default_direction = BIDI_L;
        else if (b->override_direction == 2)
            bs->default_direction = BIDI_R;
    }
#endif /*__UI_PAGING_IN_MULTILINE_EDITOR__  __UI_LINEBASE_IN_MULTILINE_EDITOR__ */ /**/

    /* Current implementation does not support icon_callback on overwrite mode */
    MMI_DBG_ASSERT(!(bs->flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE) || !b->icon_callback);
    
    /* Setup runtime variables */
    bs->current_cursor_p = b->cursor_p;  /* points to the character at which the cursor is positioned */
    bs->previous_cursor_p = b->cursor_p;
    
    /* prepare the layout area*/
    gui_prepare_multi_line_show_area(b, bs);
    
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    /*
    * Evertime the cursor position is changed, GUI will invoke the current function,
    * there is no other place to hook it cleanly.
    * However, it's protected by the flag UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE
    */
    if (b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE && gui_WCSS_input_method_change_enable())
    {
        /* gui_change_WCSS_input_method() will change cursor position */
        gui_change_WCSS_input_method(b);
        bs->current_cursor_p = b->cursor_p;
        bs->previous_cursor_p = b->cursor_p;
    }
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ /* MMI_WCSS_INPUT_FORMAT_SUPPORT_ */
    
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
    {
        gdi_get_alpha_blending_source_layer(&bs->scr_layer);
    }
#endif

    EDITOR_UNLOCK;
    /* draw the editor background*/
    gui_draw_multi_line_background_area(b, bs);

    if (gui_inputs_cache_get_error_code() <= 0)
    {
        if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
        {
            gui_pop_clip();
        }
        in_multiline_shown_flag = 0;
        return;
    }
    
    EDITOR_LOCK;
    /* update the text area range */
    gui_set_multi_line_text_area_range(b, bs);
    
    /* begin to analyse text*/
    if (b->text != NULL && gui_mlc_total_line_count() > 0)
    {
        /* Setup clipping for text and icon */
        gui_setup_multi_line_text_clip(b, bs);
        
        /* Set the default text font*/
        gui_set_multi_line_default_font(b, bs);
        
        if (bs->previous_cursor_p && bs->previous_cursor_p != b->text)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(bs->previous_cursor_p, dummy_c);
        }
        
        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            bs->multitap_flag = 1;
        }
        if (bs->flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
        {
            bs->overwrite_flag = 1;
        }
        if (bs->default_direction == BIDI_L)
        {
            /* normal direction layount*/
            bs->xx = bs->x1 + b->text_x + b->text_offset_x;
        }
#ifdef __MMI_BIDI_ALG__ /**/      
        else
        {
            /* from right to left, text_x and text_offset_x is moved to the right*/
            bs->xx = bs->x1;
        }
#endif /* __MMI_BIDI_ALG__ */   
        
        bs->yy = bs->y1 + b->text_y + b->text_offset_y + bs->border_y;
        bs->ty = b->header_height + b->header_gap;
        b->max_line_height = 0;
        b->n_lines = gui_mlc_total_line_count();
        bs->current_text_p = b->text;
        g_editor_line.line_height = 0;   

        /* set bs by visible line cache */
        gui_preset_multi_line_visible_line(b, bs);
        
        /***************MULTILINE BIG LOOP BEGIN *****************************/
        for(i=bs->sl.index; i<=bs->el.index; i++)
        {
            /* no visible line */
            if (i < 0)
                break;

            /* prepare to show the current line */
            gui_prepare_multi_line_one_line_context(b, bs);
            
            if (b->flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU)
            {
                S32 maxY = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
                S32 maxEditorY = bs->yy - b->text_offset_y + bs->edit_height;
                maxY = maxY > maxEditorY ? maxEditorY : maxY;
                if (bs->yty >= (bs->yy - b->text_offset_y)
                    && bs->yty + g_editor_line.line_height <= maxY)
                {
                    b->visible_end = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH
                                       + g_editor_line.line_char_count;
                    if (b->visible_start < 0)
                        b->visible_start = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;
                }

                /* Half line visible also counter */
                if (bs->yty + g_editor_line.line_height/2 >= (bs->yy - b->text_offset_y)
                    && bs->yty + g_editor_line.line_height/2 <= maxY)
                {
                    b->visible_end_ex = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH
                        + g_editor_line.line_char_count;
                    if (b->visible_start_ex < 0)
                        b->visible_start_ex = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;
                }
            }
            else
            {
                if (bs->yty >= (bs->yy - b->text_offset_y)
                    && bs->yty + g_editor_line.line_height <= (bs->yy - b->text_offset_y + bs->edit_height))
                {
                    b->visible_end = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH
                                       + g_editor_line.line_char_count;
                    if (b->visible_start < 0)
                        b->visible_start = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;
                }

                /* Half line visible also counter */
                if (bs->yty + g_editor_line.line_height/2 >= (bs->yy - b->text_offset_y)
                    && bs->yty + g_editor_line.line_height/2 <= (bs->yy - b->text_offset_y + bs->edit_height))
                {
                    b->visible_end_ex = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH
                        + g_editor_line.line_char_count;
                    if (b->visible_start_ex < 0)
                        b->visible_start_ex = (g_editor_line.line_start_p - b->text)/ENCODING_LENGTH;
                }
            }

            /* 
            * Now we can check the cursor line and the cursor_y, but we can't 
            * get the cursor_x, which need to be got at this line drawn(maybe bidi).
            */
            gui_set_multi_line_cursor_information(b, bs);
            
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
            /* calculate the paging information */
            gui_set_multi_line_paging_visible_information(b, bs);
#endif
            
            /* only draw the visible area */
#ifdef __MMI_BIDI_ALG__
            /* try to apply the BIDI alg to the current text content */
            gui_translate_multi_line_bidi_text(b, bs);
#endif
            /* draw the current line */
            EDITOR_UNLOCK;

            gui_draw_multi_line_one_line(b, bs);

            if (gui_inputs_cache_get_error_code() <= 0)
            {
                in_multiline_shown_flag = 0;
                return;
            }

            EDITOR_LOCK;

            gui_end_multi_line_new_line_loop(b, bs);
            
            if (bs->flags & UI_MULTI_LINE_INPUT_BOX_ONLY_SHOW_FIRST_LINE)
            {
                /* Used by WAP to emulate single line input gadget  */
                bs->end_line = 1;
            }

            if (bs->end_line)
                break;
        }

        /* visible line is completed */
        /* now we set the ty to the last line of the whole text */
        if (bs->el.index >= 0)
            bs->ty += gui_mlc_total_line_height() - (bs->el.offset_y + g_editor_line.line_height);
        else
            bs->ty = b->header_height + b->header_gap + gui_mlc_total_line_height();

        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_FIXED_TEXT_AREA)
        {
            bs->x1 = bs->backup_x1;
            bs->x2 = bs->backup_x2;
        }
    }
    
    /* adjust the cursor_p for language special requirement*/
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    if (b->predefine_char_pos == NULL)
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/          
    {
        gui_adjust_multi_line_cursor_for_language(b, bs); 
    }

    gui_find_multi_line_cursor_from_cache(b, bs);

    if (!(bs->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) 
        && (bs->flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)
        &&!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
    {
        gui_draw_multi_line_under_line(b, bs);
    }
    
    EDITOR_UNLOCK;

    /* draw header, footer, lefter and righter */
    gui_draw_multi_line_callback_area(b, bs);
    
    /* Footer area should be included in b->text_height */
    bs->ty += b->footer_height;

    if (gui_inputs_cache_is_not_in_update() && !bs->is_truncate)
        b->text_height = bs->ty;

    if (b->text_height < (EDIT_MAX(b->left_height, b->right_height)))
        b->text_height = EDIT_MAX(b->left_height, b->right_height);
    
    /* set the scroll bar position and draw the scroll bar */
    gui_set_multi_line_scroll_bar(b, bs);
    gui_show_multi_line_scroll_bar(b, bs);
    
    /* update some information outside of the multiline editor, but why? */
    gui_update_multi_line_extern_module_infomation(b, bs);
    
    /* adjust the text_offset_y by some reason: paging adjust, cursor adjust*/
    gui_adjust_multi_line_text_offset_y(b, bs);
    
    gui_multi_line_show_special_remaining_counter(b);
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    restore_current_language_for_hindi_rules();
#endif 
 
    /* add for predefine char limitation */
    if (!mmi_imc_is_clipboard_state())
    {
        backup_b = b;
        /* gui_start_timer(1, gui_multiline_predefined_cursor_move_timer_hdlr); */
        gui_multiline_predefined_cursor_move_timer_hdlr();
    }
    
    if (((b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL) ==
        UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL) && !b->vertical_scroll_on)
    {
#if(UI_BLINKING_CURSOR_SUPPORT)
        StopTimer(BLINKING_CURSOR);
#endif 
        gui_cancel_timer(multiline_inputbox_vertical_scroll);
        gui_start_timer(UI_MULTI_LINE_INIT_SCROLL, multiline_inputbox_vertical_scroll);
    }

    /* exit shown function */
    in_multiline_shown_flag = 0;

    UI_UNUSED_PARAMETER(dummy_c);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_multiline_predefined_cursor_move_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void                       
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multiline_predefined_cursor_move_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cursor_offset;
    gui_evt_inputs_cursor_changed_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor_offset = (backup_b->cursor_p - backup_b->text)/ENCODING_LENGTH;

    if (!(backup_b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
        && !(backup_b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW)
        &&cursor_offset != backup_b->last_cursor_offset)
    {
        backup_b->last_cursor_offset = cursor_offset;
        
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
        
        if (backup_b->predefine_char_pos != NULL
            && backup_b->cursor_move_callback != NULL)
        {
            backup_b->cursor_move_callback(cursor_offset);
        }
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/

        /* Post cursor changed event */
        if (gui_inputs_get_cursor_change_event_state())
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_GUI_INPUTS_CURSOR_CHANGED);
            evt.cursor_pos = cursor_offset;
            if (!mmi_frm_is_event_posted((mmi_event_struct*)&evt))
            {
                MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            }
        }
        
        backup_b->last_cursor_offset = cursor_offset;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_multi_line_input_box_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_multi_line_input_box_ext(multi_line_input_box *b, S32 move_to_x, S32 move_to_y)
{
    S32 text_offset_y;
    kal_uint32 begin_tick,end_tick;
    static S32 count = 0;
#if defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    U8 scrollbar_state;
#endif
    S32 cursor_offset = 0;
    S32 h_s_offset = 0;
    S32 h_e_offset = 0;
#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__) && defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    S32 saved_text_offset_y = 0;
#endif
#if defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    scrollbar_state = b->scrollbar_state;
#endif
#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__)
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        && !(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE)
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__ /**/
        &&!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
#endif /*__UI_PAGING_IN_MULTILINE_EDITOR__*/ /**/
        )
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR;
    }

#if defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
        && (b->pre_scrollbar_state && b->pre_height == b->height)
        && !b->scrollbar_state)
    {
        if (gui_inputs_cache_is_valid())
        {
            scrollbar_state = 1;
            gui_mlc_all_line_update();
        }
    }
#endif

#endif

    /* Get data if the buffer already dirty */
    if (b->is_dirty && b->get_data_cb)
    {
        /* Because cursor and highlight address will be changed, so we should save here */
        cursor_offset = b->cursor_p - b->text;
        h_s_offset = b->highlight_start_position - b->text;
        h_e_offset = b->highlight_end_position - b->text;
        if (b->get_data_cb(
                &b->text,
                &b->text_length,
                b->visible_line_info->start_line_index,
                b->visible_line_info->start_line_index + GUI_MAX_VISIBLE_LINE - 1))
        {
            b->cursor_p = b->text + cursor_offset;
            b->highlight_start_position = b->text + h_s_offset;
            b->highlight_end_position = b->text + h_e_offset;
            b->is_dirty = MMI_FALSE;
        }
        else
        {
            return;
        }
    }

    kal_get_time(&begin_tick);
#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__) && defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    saved_text_offset_y = b->text_offset_y;
#endif
    do
    {
        text_offset_y = b->text_offset_y;
        gui_show_multi_line_input_box_ext_internal(b, move_to_x, move_to_y);

        /* only locate the cursor once */
        move_to_x = -1;
        move_to_y = -1;
    }while( !(b->flags&UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && text_offset_y != b->text_offset_y);

#if defined(__MMI_EDITOR_FORCE_AUTO_SCROLLBAR__) && defined(GUI_INPUT_BOX_CACHE_SUPPORT)
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
        && scrollbar_state != b->scrollbar_state)
    {
        if (gui_inputs_cache_is_valid())
        {
            gui_mlc_all_line_update();
            b->text_offset_y = saved_text_offset_y;
            do
            {
                text_offset_y = b->text_offset_y;
                gui_show_multi_line_input_box_ext_internal(b, move_to_x, move_to_y);
            }while( !(b->flags&UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && text_offset_y != b->text_offset_y);
        }
    }
#endif

    kal_get_time(&end_tick);
    end_tick -= begin_tick;
    end_tick = kal_ticks_to_milli_secs(end_tick);
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_ML_LEAVE_SHOWN, count++, end_tick);

    UI_UNUSED_PARAMETER(scrollbar_state);
}
#if 0 /* slim_2_2 */ //
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
#endif
/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_delete_character_in_pos
 * DESCRIPTION
 *  Deletes a character before the current cursor position (Backspace)
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  pos     [IN]        Is the desired position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_delete_character_in_pos(multi_line_input_box *b, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p_insert, p1;
    UI_character_type c, dummy_c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clear the cursor saved position*/
    b->cursor_fixed_x = -1;

    if(b->change_event_handler)
    {
        UI_buffer_type tmp_p = b->text + pos;
        
        UI_STRING_GET_PREVIOUS_CHARACTER(tmp_p,dummy_c);
        
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c))
            return;
    }
    
    if(pos >= b->text_length - ENCODING_LENGTH)
        return;
    
    p_insert = b->text + pos;
    if (b->cursor_p > p_insert)
        b->cursor_p -= ENCODING_LENGTH;
    
    p1 = p_insert;
    UI_STRING_GET_NEXT_CHARACTER(p1, c);
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, c);
        UI_STRING_INSERT_CHARACTER(p_insert, c);
    }
    
    b->text_length -= ENCODING_LENGTH;
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_change_request(pos/ENCODING_LENGTH);
#endif

    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_delete_character
 * DESCRIPTION
 *  Deletes a character before the current cursor position (Backspace)
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_delete_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;
    UI_character_type dummy_c = 0;

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    U8 input_mode = 1;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;

    /* Clear the cursor saved position*/
    b->cursor_fixed_x = -1;

    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        b->cursor_p = b->input_mode_cursor_p;
    }

    if (b->cursor_p != b->text)
    {
        if(b->change_event_handler)
        {
            UI_buffer_type tmp_p = b->cursor_p;

            UI_STRING_GET_PREVIOUS_CHARACTER(tmp_p,dummy_c);
            
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
            /* WCSS editor handling */
            if ((b->predefine_char_pos != NULL) || (b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE))
            {
                /* Preventing the deletion callback of application when we are in multitap mode */
                if(!(b->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP) &&
                   !b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c))
                {
                    return;
                }
            }
            else
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/ 
            {
                if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c))
                    return;
            }
        }
    }

    current_text_p = b->cursor_p;
    previous_text_p = b->cursor_p;
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    WCSS_input_change_enable = 0;
    if (b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE)
    {
        if (b->cursor_p - 2 >= b->text)
        {
            UI_buffer_type cursor_p = b->cursor_p;
            BOOL has_editable_char = MMI_FALSE;

            while (cursor_p - 2 >= b->text)
            {
                if (cat115buffer[(cursor_p - 2 - b->text) >> 1] != 0xFF)
                {
                    has_editable_char = MMI_TRUE;
                    break;
                }
                cursor_p -= 2;
            }

            if (!has_editable_char) /* eg. "\-\-nnn" */
            {
                UI_editor_play_tone_cannot_change();
                WCSS_input_change_enable = 1;
                return;
            }

            input_mode = cat115buffer[(b->cursor_p - 2 - b->text) >> 1];
            while (input_mode == 0xFF && b->cursor_p - 2 >= b->text /* redundant check */ )
            {
                gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                input_mode = cat115buffer[(b->cursor_p - 2 - b->text) >> 1];
            }
            current_text_p = b->cursor_p;
            previous_text_p = b->cursor_p;
        }
    }
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    if (previous_text_p == b->text)
    {
        UI_editor_play_tone_cannot_change();    /* play tone */
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        WCSS_input_change_enable = 1;           /* change back to 1 after returing from this function */
    #endif 
        return;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(previous_text_p, dummy_c);
    if (UI_TEST_GSM_EXTENDED(dummy_c))
    {
        if (b->GSM_ext_count > 0)
        {
            b->GSM_ext_count--;
        }
    }
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
    if (b->icon_callback)
    {
        /* previous_text_p is the first character to be deleted */
        S32 gsm_char_cnt = 0;
        UI_buffer_type tmp_text_p = previous_text_p, tmp_p;
        UI_character_type tmp_c;

        tmp_text_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, tmp_text_p, 0);
        if(tmp_text_p != previous_text_p)
        {
            tmp_p = tmp_text_p;

            while(tmp_p <previous_text_p)
            {
                UI_STRING_GET_NEXT_CHARACTER(tmp_p, tmp_c);
                if (UI_TEST_GSM_EXTENDED(tmp_c))
                {
                    gsm_char_cnt++;
                }
            }

            /* avoid smart input method to delete the icon */
            if (b->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
            {
                if (previous_text_p >= b->highlight_end_position
                    || b->cursor_p <= b->highlight_start_position)
                {
                    previous_text_p = tmp_text_p;
                    b->GSM_ext_count -= gsm_char_cnt;
                }
            }
            else if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP))
            {
                previous_text_p = tmp_text_p;
                b->GSM_ext_count -= gsm_char_cnt;
            }
        }
        
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/

#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
    if (UI_TEST_LF_CHARACTER(dummy_c))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(previous_text_p, dummy_c);
        if (!UI_TEST_CR_CHARACTER(dummy_c)
        ||  (b->change_event_handler && !b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c)))
        {
            UI_STRING_GET_NEXT_CHARACTER(previous_text_p, dummy_c);
        }
    }
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    /* If In Non * Mode No Need To Decrease the text_length */
    if (((b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) && (input_mode & PIXTEL_UI_WCSS_STAR_INPUT)) ||
        !(b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE))
    {
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
        b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
        b->cursor_p = previous_text_p;

        gui_multi_line_input_box_ascii_encoding_handling(b, dummy_c, 0);

        if (b->flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(dummy_c, b->UCS2_count, b->allocated_length, b->available_length);
        }
        while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);     /* insert character */
        }
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    }   /* if non-WCSS or not in * mode */
    else if ((b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) && (!(input_mode & PIXTEL_UI_WCSS_STAR_INPUT)))
    {
        b->cursor_p = previous_text_p;
        if (input_mode & PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER)
        {
            current_character = 0x20;   /* ' ' */
        }
        else
        {
            current_character = 0x30;   /* '0' */
        }
        UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
    }
    WCSS_input_change_enable = 1;
    WCSS_Esc_Char = 1;
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_change_request((b->cursor_p - b->text)/ENCODING_LENGTH);
#endif

    if (b->show_action_flag)
    {
        gui_show_multi_line_input_box(b);   /* show multiline input box */
    }
    

    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    /* !!! Note : For for Nokia smart message write message screen */
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;
        if (g_nsm_msg_context.UCS2_count == 0)
        {
            MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
            wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
            wgui_redraw_input_information_bar();
        }
        g_nsm_msg_context.textlength = b->text_length;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR)
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
        if (picmsg_text_struct.ucs2_count == 0)
        {
            MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
            wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
            wgui_redraw_input_information_bar();
        }
    }

#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();

    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->input_mode_cursor_p, dummy_c);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_delete_all
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_delete_all(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    UI_buffer_type p = b->text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(p, c);
    UI_UNUSED_PARAMETER(c);
    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETEALL,0))
            return;
    }
    
    gui_multi_line_input_box_clear(b);  /* initilaize multiline box */
    b->cursor_p = b->text;
    b->cursor_line_position_counter = 0;
    b->text_offset_y = 0;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_change_request(0);
#endif
    //hjf, force to update text_offset_y, because cursor position is changed.
    //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);   /* show multiline input box */
    //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    /* For clear all characters from multiline input box */
#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)    /* For nsm2 write message only */
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        if (wgui_inputbox_information_flag)
        {
            wgui_redraw_remaining_characters_display();
        }

        g_nsm_msg_context.textlength = b->text_length;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR)
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        wgui_redraw_input_information_bar();
    }

#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the current cursor position (Delete)
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_delete_current_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clear the cursor saved position*/
    b->cursor_fixed_x = -1;

    current_text_p = b->cursor_p;
    previous_text_p = b->cursor_p;
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__    
    if (b->icon_callback)
    {
        /* current_text_p is the character next to the last character to be deleted */
        S32 cnt;

        if ((cnt = b->icon_callback(previous_text_p, MMI_FALSE, NULL, NULL, 0, 0)) > 0)
        {
            /* Delete an icon as character sequence */
            current_text_p = previous_text_p + ((cnt - 1) << 1);
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        }
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/  
#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
    if (UI_TEST_CR_CHARACTER(current_character))
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        if (!UI_TEST_LF_CHARACTER(current_character)
        ||  !b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
        }
    }
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 
    if (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {

        if (UI_TEST_GSM_EXTENDED(current_character))
        {
            if (b->GSM_ext_count > 0)
            {
                b->GSM_ext_count--;
            }
        }
        if (b->flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(
                current_character,
                b->UCS2_count,
                b->allocated_length,
                b->available_length);
        }
        while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
        }
        b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
        if (b->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            b->flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
        }
        //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        //gui_show_multi_line_input_box(b);   /* show multiline input box */
        //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_no_draw(b);
        
        b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
        b->change_callback();
    }
    else
    {
        UI_editor_play_tone_cannot_change();    /* play error tone */
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_character_in_pos
 * DESCRIPTION
 *  Inserts a character at the desired position
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [IN]        Is the character to be inserted
 *  pos     [IN]        Is the inserted position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_insert_character_in_pos(multi_line_input_box *b, UI_character_type c, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p_insert, p1;
    UI_character_type old_c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,(U16)c))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
    }
    
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
        UI_TEST_UCS2_CHARACTER(c))
    {
        if ((b->flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
            (b->text_length>= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
        if ((b->flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER) &&
            (b->text_length>= UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(b->available_length)))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
        else if (b->text_length>= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
        {
            UI_editor_play_tone_cannot_insert();    /* play eror tone */
            return;
        }
    }
    
    if (b->text_length >= b->available_length)
    {
        UI_editor_play_tone_cannot_insert();
        return;
    }
    
    p_insert = b->text + pos;
    if (b->cursor_p >= p_insert)
        b->cursor_p += ENCODING_LENGTH;

    p1 = p_insert;
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(p_insert, old_c);
        UI_STRING_INSERT_CHARACTER(p1, c);
        c = old_c;
    }
    UI_STRING_INSERT_CHARACTER(p1, c);  /* insert character */
    
    b->text_length += ENCODING_LENGTH;
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_change_request(pos/ENCODING_LENGTH);
#endif

    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();
}
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_inputbox_adjust_cursor_for_icon_callback
 * DESCRIPTION
 *  adjust the cursor position by the icon callback
 * PARAMETERS
 *  b               [IN]        Is the multi-line inputbox object
 *  direction       [IN]        if 0, to previouse position; or to the next position
 * RETURNS
 *  void
 *****************************************************************************/
UI_buffer_type gui_multi_line_inputbox_adjust_cursor_for_icon_callback(multi_line_input_box *b, UI_buffer_type current_p, U8 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type temp_text_p = b->text;
    S32 cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp_text_p < current_p)
    {
        cnt = b->icon_callback(temp_text_p, MMI_FALSE, NULL, NULL, 0, 0);
        if (cnt)
        {
            if (current_p > temp_text_p && current_p < temp_text_p + cnt*ENCODING_LENGTH)
            {
                if (direction == 0)
                {
                    /* to the previous */
                    return (temp_text_p);
                }
                else
                {
                    /* to the next */
                    return (temp_text_p + cnt*ENCODING_LENGTH);
                }
            }
            temp_text_p += cnt*ENCODING_LENGTH;
        }
        else
        {
            temp_text_p += ENCODING_LENGTH;
        }
    }

    return current_p;
}
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/ 

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_character
 * DESCRIPTION
 *  Inserts a character at the current cursor position
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_insert_character_internal(multi_line_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2, backup_p = b->cursor_p;
    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;
    S32 text_length = b->text_length;
    U8 GSM_extended_flag = 0;

    /* MTK Terry for 0x81 encoding support for Phone Book */
    U32 temp_0x81 = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;

    b->cursor_fixed_x = -1;
    
    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,(U16)c))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return MMI_FALSE;
        }
    }
    
    /* MTK Terry for 0x81 memory corrupt issue */
    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
    {
        if((text_length >> 1) -1 < b->available_length - 3) // current character count = text lenght /2 - NULL
        {
            if(text_length >=2) // NULL should use at least 2 bytes
            {
                ((U16*)MMI_multiline_inputbox.text)[(text_length/2)-1] = c;
                ((U16*)MMI_multiline_inputbox.text)[(text_length/2)  ] = 0;
                temp_0x81 = srv_phb_convert_to_0x81((U16*) b->text, MMI_FALSE);
                ((U16*)MMI_multiline_inputbox.text)[(text_length/2)-1] = 0;
            }
        }
        else
            temp_0x81 = srv_phb_convert_to_0x81((U16*) b->text, MMI_FALSE);
    }

    if ((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING) && (0 != temp_0x81))
    {
        if ((text_length >> 1) >= (b->allocated_length >> 1) - 3)
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return MMI_FALSE;
        }
    }
    else
    {
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED)
        {
            if (UI_TEST_GSM_EXTENDED(c))
            {
                GSM_extended_flag = 1;
            }
            if (b->UCS2_count == 0 && !UI_TEST_UCS2_CHARACTER(c))
            {
                text_length += (b->GSM_ext_count * ENCODING_LENGTH);
            }
        }

        if ((b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
            UI_TEST_UCS2_CHARACTER(c))
        {
            if ((b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
            {
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
            if ((b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER) &&
                (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(b->available_length)))
            {
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
            else if (text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
            {
                UI_editor_play_tone_cannot_insert();    /* play eror tone */
                return MMI_FALSE;
            }
        }

		if ((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_USE_ASCII_ENCODING_BASE_LENGTH) && (b->non_ascii_count == 0) &&
            !UI_TEST_ASCII_CHARACTER(c))
        {
            if ((b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
            {
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
            else if (text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
            {
                UI_editor_play_tone_cannot_insert();    /* play eror tone */
                return MMI_FALSE;
            }
        }

        if (b->UCS2_count == 0  && GSM_extended_flag 
        && (text_length >= (b->available_length - ENCODING_LENGTH)))
        {
            UI_editor_play_tone_cannot_insert();
            return MMI_FALSE;
        }
    }

    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if (b->predefine_char_pos == NULL)
#endif
        {
            b->cursor_p = b->input_mode_cursor_p;
        }
    }

    p1 = p2 = b->cursor_p;
    if (b_flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
        if ((p1 >= b->last_position_p) && (text_length >= b->available_length))
        {
            UI_editor_play_tone_cannot_insert();
            b->cursor_p = backup_p;
            return MMI_FALSE;
        }
        if (GSM_extended_flag)
        {
            b->GSM_ext_count++;
        }
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
        {

            UI_STRING_INSERT_CHARACTER(p2, c);
            
            gui_multi_line_input_box_ascii_encoding_handling(b, old_c, c);
            
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->cursor_p = p2;
        }
        else    /* UI_STRING_END_OF_STRING_CHARACTER(old_c) */
        {
            p1 = b->cursor_p;

            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c); /* get next character */
            while (!UI_STRING_END_OF_STRING_CHARACTER(c))   /* check for end of string */
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */

            gui_multi_line_input_box_ascii_encoding_handling(b, old_c, c);

            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }
    else    /* b_flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE */
    {
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DIALER_STYLE)
        {
            if ((b->text_length) >= (b->available_length))
            {
                UI_buffer_type p3, p4;
                UI_character_type cc;
                
                if (b->cursor_p != b->text)
                {
                    p3 = p4 = b->text;
                    UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                    while (p3 != b->cursor_p)
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                        UI_STRING_INSERT_CHARACTER(p4, cc);
                    }
                    UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c);   /* get previous character */
                    UI_STRING_INSERT_CHARACTER(b->cursor_p, c);       /* insert character */
                    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
                    {
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->input_start_cursor_p, dummy_c);
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->input_mode_cursor_p, dummy_c);
                    }
                }
            }
            else    /* (b->text_length)>=(b->available_length) */
            {
                UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))       /* check for end of string */
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);        /* get next character */
                    UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                b->text_length += ((S32) p2 - (S32) p1);
                UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
            }
        }
        else
        {
            if (text_length >= (b->available_length) &&
                !((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING) && (0 != temp_0x81)))
            {
                UI_editor_play_tone_cannot_insert();
                b->cursor_p = backup_p;
                return MMI_FALSE;
            }
            if (GSM_extended_flag)
            {
                b->GSM_ext_count++;
            }
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c); /* get next character */

            gui_multi_line_input_box_ascii_encoding_handling(b, 0, c);

            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c, b->UCS2_count, b->allocated_length, b->available_length);
                }
            }

            while (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
    if (b->icon_callback)
    {
        b->cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, b->cursor_p, 1);
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/    
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_change_request((b->cursor_p - b->text)/ENCODING_LENGTH);
#endif

    if (b->show_action_flag)
    {
        //hjf,force to update offset_y b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);
        //hjf,force to update offset_y b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }
    

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        if (wgui_inputbox_information_flag)
        {
            wgui_redraw_input_information_bar();
        }

        g_nsm_msg_context.textlength = b->text_length;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR)
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        wgui_redraw_input_information_bar();
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();

    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        UI_STRING_GET_NEXT_CHARACTER(b->input_mode_cursor_p, dummy_c);
    }

    UI_UNUSED_PARAMETER(dummy_c);
    return MMI_TRUE;
}

MMI_BOOL gui_multi_line_input_box_insert_character(multi_line_input_box *b, UI_character_type c)
{
    return gui_multi_line_input_box_insert_character_internal(b,c);
}
/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_newline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_insert_newline(multi_line_input_box *b)
{
    if(gui_multi_line_input_box_insert_character_internal(b,(UI_character_type)0x0A))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_current_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_multi_line_current_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type cursor_p = b->cursor_p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->cursor_p == b->text)
    {
        return 0;
    }
    else
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
        return current_character;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_next_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_multi_line_next_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type cursor_p = b->cursor_p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    UI_STRING_GET_NEXT_CHARACTER(cursor_p, current_character);
    return current_character;
}

#ifdef UI_EMS_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_current_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_EMS_current_character(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type current_character = 0;
    U8 *temp;

#ifdef __MMI_INDIC_ALG__

    U8 object_type_check;
    EMSObject *o;
    EMSPosition p = b->data->CurrentPosition;
    EMSData *data = b->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_type_check = gui_EMS_input_box_get_previous_object(data, &p, &current_character, &o);
    if (object_type_check == 2)
    {
        return 0;
    }

#endif /* __MMI_INDIC_ALG__ */ 

    if (b->data->CurrentPosition.OffsetToText == 0)
    {
        return 0;
    }
    else
    {
        temp = b->data->textBuffer + b->data->CurrentPosition.OffsetToText;
        UI_STRING_GET_PREVIOUS_CHARACTER(temp, current_character);
        return current_character;
    }
}
#endif /* UI_EMS_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_current_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_single_line_current_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p;
    UI_character_type current_character = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->current_text_p == 0)
    {
        return 0;
    }
    else
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
        return current_character;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_next_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_single_line_next_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p;
    UI_character_type current_character = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
    return current_character;
}

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_multitap_character_wcss
 * DESCRIPTION
 *  Inserts a multitap character at the current cursor position for WCSS editor
 *  Because WCSS multitap in too complicate, we don't use the delete/insert way to insert multitap character in WCSS
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gui_multi_line_input_box_insert_multitap_character_wcss(multi_line_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2, backup_p = b->cursor_p;

    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;
    S32 text_length = b->text_length;
    S32 counter = 0;
    /* MTK Terry for 0x81 support for Phone Book */
    U8 multitap_ucs2 = 0;
    U32 temp_0x81 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // check can be changed or not 
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if (b->predefine_char_pos == NULL)
#endif
        {
            b->cursor_p = b->input_mode_cursor_p;
        }

    }

    b->cursor_fixed_x = -1;
    
    if((b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        && b->cursor_p == b->text)
    {
        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
    }

    if(b->change_event_handler)
    {
       UI_buffer_type tmp_p = b->cursor_p;
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(tmp_p, dummy_c);

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
            if (b->predefine_char_pos != NULL)
            {
                b->cursor_move_callback((tmp_p - b->text)/ENCODING_LENGTH);

                if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,c))
                {
                    b->cursor_move_callback((b->cursor_p - b->text)/ENCODING_LENGTH);
                    UI_editor_play_tone_cannot_insert();    /* play error tone */
                    return MMI_FALSE;
                }
            }
            else
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/      
            {
                if (c != dummy_c)
                {
                    if(b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,dummy_c))
                    {
                        if (tmp_p == b->text)
                        {
                            UI_STRING_INSERT_CHARACTER(tmp_p, 0);
                            tmp_p -= ENCODING_LENGTH;
                        }

                        if (!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,c))
                        {
                            UI_editor_play_tone_cannot_insert();    /* play error tone */
                            UI_STRING_INSERT_CHARACTER(tmp_p, dummy_c);
                            return MMI_FALSE;
                        }
                        
                        if (tmp_p == b->text)
                        {
                            UI_STRING_INSERT_CHARACTER(tmp_p, dummy_c);
                        }
                    }
                }
                
            }
        }
        else
        {
            if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,c))
            {
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
        }
    }
    
    p1 = p2 = b->cursor_p;

    if ((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
        /* &&(b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP) */ )
    {
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            if(text_length >=4 ) // one character + NULL should use at least 4 bytes
            {
                S32 last_char_pos = (text_length/2) -1 -1;
                old_c = ((U16*)MMI_multiline_inputbox.text)[last_char_pos];
                ((U16*)MMI_multiline_inputbox.text)[last_char_pos] = c;

                temp_0x81 = srv_phb_convert_to_0x81((U16*) b->text, MMI_FALSE);

                if (b->UCS2_count == 1
                    && !UI_TEST_UCS2_CHARACTER(c)
                    && UI_TEST_UCS2_CHARACTER(old_c))
                {
                    multitap_ucs2 = 1;
                }

                ((U16*)MMI_multiline_inputbox.text)[last_char_pos] = old_c;
            }
        }
        else
        {
            if((text_length >> 1) -1 < b->available_length - 3) // current character count = text lenght /2 - NULL
            {
                if(text_length >=2) // NULL should use at least 2 bytes
                {
                    ((U16*)MMI_multiline_inputbox.text)[(text_length/2)-1] = c;
                    ((U16*)MMI_multiline_inputbox.text)[(text_length/2)  ] = 0;
                    temp_0x81 = srv_phb_convert_to_0x81((U16*) b->text, MMI_FALSE);
                    ((U16*)MMI_multiline_inputbox.text)[(text_length/2)-1] = 0;
                }
            }
        }
    }

    if ((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING) && (0 != temp_0x81))
    {
        if (!(b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP))
        {
            if ((text_length >> 1) >= (b->allocated_length >> 1) - 3)
                
            {
                b->cursor_p = backup_p;
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
        }
        else
        {
            if (((text_length >> 1) - 1) >= (b->allocated_length >> 1) - 3)
                
            {
                b->cursor_p = backup_p;
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
        }

    }
    else
    {
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED)
        {
            /* No support for inserting GSM extended characters through multitap */
            if (UI_TEST_GSM_EXTENDED(c))
            {
                b->cursor_p = backup_p;
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
            if (b->UCS2_count == 0)
            {
                text_length += (b->GSM_ext_count * ENCODING_LENGTH);
            }
        }

        if ((b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            && (b->UCS2_count > 0 || UI_TEST_UCS2_CHARACTER(c))
            && !multitap_ucs2)
        {
            if ((b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP
                && (b->text_length - 2 > (b->allocated_length >> 1) - 1) || (b->text_length - 2 >= b->available_length))
                || (!(b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
                && b->text_length - 2 >= (b->allocated_length >> 1) - 1))
            {
                b->cursor_p = backup_p;
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
        }

        if ((b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
            UI_TEST_UCS2_CHARACTER(c))
        {

/* slim_2_2 */ //
            if (((b->flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                  ((b->text_length - 2 + 2) >= ((b->available_length >> 1) - 1))) ||
                 ((b->text_length - 2) >= ((b->available_length-2) >> 1)))
            {
                if ((b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
/* MTI START MAUI_00054333 */
                 (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length))
                 &&(!(b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)) )
/* MTI END MAUI_00054333 */
                {
                    b->cursor_p = backup_p;
                    UI_editor_play_tone_cannot_insert();    /* play error tone */
                    return MMI_FALSE;
                }
                else if ((b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER) &&
                         (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(b->available_length)))
                {
                    b->cursor_p = backup_p;
                    UI_editor_play_tone_cannot_insert();    /* play error tone */
                    return MMI_FALSE;
                }
                else if (text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
                {
                    b->cursor_p = backup_p;
                    UI_editor_play_tone_cannot_insert();
                    return MMI_FALSE;
                }
            }

        }

        /* MTK Terry for 0x81 encoding */
        /* if (text_length > b->available_length)
        {
            UI_editor_play_tone_cannot_insert();
            return;
        } */
    }

    if (b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        /* We need to delete the characters if more than one character is entered as replacing 
         * one character is handled by multitap logic. We can get the count by using input_start_cursor_p
         */
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
        {
            /* Here - 1 is used as the last candidate is handled by logic in while loop below */
            for(counter = 0; counter < (b->cursor_p - b->input_start_cursor_p) / ENCODING_LENGTH - 1; counter++)
            {
                gui_multi_line_input_box_delete_character(b);
            }
        }

        UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c);
        p1 = p2 = b->cursor_p;

        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))
        {
            UI_STRING_INSERT_CHARACTER(p2, c);
            gui_multi_line_input_box_ascii_encoding_handling(b, old_c, c);
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->cursor_p = p2;

        }
        else    /* UI_STRING_END_OF_STRING_CHARACTER(old_c) */
        {
            p1 = b->cursor_p;
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c); /* get next character */

            while (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            gui_multi_line_input_box_ascii_encoding_handling(b, old_c, c);
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(old_c, c, b->UCS2_count, b->allocated_length, b->available_length);
            }
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }
    else    /* b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP */
    {
        p1 = p2 = b->cursor_p;
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
        {
            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
            if ((p1 == b->last_position_p) && (text_length >= b->available_length))
            {
                b->cursor_p = backup_p;
                UI_editor_play_tone_cannot_insert();
                return MMI_FALSE;
            }
            if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))
            {

                UI_STRING_INSERT_CHARACTER(p2, c);
                gui_multi_line_input_box_ascii_encoding_handling(b, old_c, c);
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->cursor_p = p2;
            }
            else    /* !UI_STRING_END_OF_STRING_CHARACTER(old_c) */
            {
                p1 = b->cursor_p;
                UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                gui_multi_line_input_box_ascii_encoding_handling(b, old_c, c);
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->text_length += ((S32) p2 - (S32) p1);
            }
        }
        else    /* b_flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE */
        {
            if (text_length >= b->available_length && (0 == temp_0x81))
            {
                b->cursor_p = backup_p;
                UI_editor_play_tone_cannot_insert();
                return MMI_FALSE;
            }
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
            gui_multi_line_input_box_ascii_encoding_handling(b, 0, c);
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c, b->UCS2_count, b->allocated_length, b->available_length);
                }
            }
            while (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            b->text_length += ((S32) p2 - (S32) p1);
        }
        b->flags |= UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;

        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
        {
            UI_STRING_GET_NEXT_CHARACTER(b->input_mode_cursor_p, dummy_c);
        }
    }
    
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__     
    if (b->icon_callback)
    {
        b->cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, b->cursor_p, 1);
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/    
    
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_change_request((b->cursor_p - b->text)/ENCODING_LENGTH);
#endif

    //hjf,force to update offset_y  b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);   /* show multiline input box */
    //hjf,force to update offset_y b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);

        if (wgui_inputbox_information_flag)
        {
            wgui_redraw_input_information_bar();
        }

        g_nsm_msg_context.textlength = b->text_length;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR)
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        wgui_redraw_input_information_bar();
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);    /* call validation callback func */
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);

    return MMI_TRUE;
}
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_multitap_character
 * DESCRIPTION
 *  Inserts a multitap character at the current cursor position
 *  We use delete/insert way to insert a multitap character for normal editor.
 *  This function is normally used as the input_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_insert_multitap_character(multi_line_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter = 0;
    S32 multitap_char_num = 0;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	S32 str_len;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    /* WCSS editor handling */
    if ((b->predefine_char_pos != NULL) || (b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE))
    {
        return gui_multi_line_input_box_insert_multitap_character_wcss(b, c);
    }
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/

    b->show_action_flag = 0;

    if (b->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
        {
            /* because b->cursor_p will be adjust for languge for show, so we use b->input_mode_cursor_p to cal multitap number */
            multitap_char_num = (b->input_mode_cursor_p - b->input_start_cursor_p) / ENCODING_LENGTH;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	if(to_decide_to_reshuffle_inline == 1)
	{
		                                                             
					str_len =(b->input_start_cursor_p+4) - (b->text) ;
				ire_reshuffling_editor_buffer_for_bengali_spec(b->text, str_len);
					to_decide_to_reshuffle_inline = 0;
	}
#endif
			
            for (counter = 0; counter < multitap_char_num; counter++)
            {
                gui_multi_line_input_box_delete_character(b);
            }
        }
        else
        {
            gui_multi_line_input_box_delete_character(b);
        }
    }

    if(gui_multi_line_input_box_insert_character_internal(b, c) == MMI_FALSE)
    {
        b->show_action_flag = 1;
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
        return MMI_FALSE;
    }
    else
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
    }

    b->show_action_flag = 1;

    //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(b);          
    //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_no_draw(b);
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_multitap_string
 * DESCRIPTION
 *  Inserts a multitap character at the current cursor position
 *  
 *  This function is normally used as the input_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_multi_line_input_box_insert_multitap_string(multi_line_input_box *b, PU8 s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    U8 done = 0;
    S32 count = 0;
    UI_character_type c;
    UI_buffer_type text = (UI_buffer_type) s;
    S32 counter = 0;
    S32 characters_deleted = 0;
    S32 rem = 0; 
    S32 strlen = 0;
    S32 index = 0;
    S32 backup_ucs2_count = b->UCS2_count;
    PU8 cursor_p = b->cursor_p;
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	UI_buffer_type temp_texp_p;
	S32 str_len;
#endif
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_MULTIGRAPH__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if (b->predefine_char_pos == NULL)
#endif
        {
            b->cursor_p = b->input_mode_cursor_p;
        }

    }
    characters_deleted = (b->cursor_p - b->input_start_cursor_p);
    /* In case we are deleting the ucs2 character we need to 
        get the correct remaining character count */

    for(index = 0; index < characters_deleted / ENCODING_LENGTH; index++)
    {
        UI_character_type ch = 0;
        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, ch);
        UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(ch, b->UCS2_count, b->allocated_length, b->available_length);
    }
    rem = gui_multi_line_input_box_get_remaining_length(b);
    /* Restore the original count of ucs2 characters */
    if(b->UCS2_count == 0 && b->UCS2_count != backup_ucs2_count)
    {
        if (b->flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
        {
            b->available_length=UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->allocated_length);  
        }
        else
        {
            b->available_length=UI_UCS2_STRING_HALF_LENGTH(b->allocated_length);
        }
    }
    b->UCS2_count = backup_ucs2_count;
    strlen = mmi_ucs2strlen((CHAR*)text);
    if (strlen > rem + (characters_deleted >> 1))
    {
        UI_editor_play_tone_cannot_insert();
        return -1;
    }

    
    /* Go back the number of times to insert new candidate */
    for(counter = 0; counter < characters_deleted / ENCODING_LENGTH; counter++)
    {
        gui_multi_line_input_box_delete_character(b);
    }
    while (!done)
    {
        UI_STRING_GET_NEXT_CHARACTER(text, c);
        if (UI_STRING_END_OF_STRING_CHARACTER(c))
        {
            done = 1;
            break;
        }
        /* Break the loop if we cannot insert the character */
        if(gui_multi_line_input_box_insert_character_internal(b, c) == MMI_FALSE)
        {
            done = 1;
            break;
        }
        count++;
    }

	
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	if(mtkmultitap_ire_bengali_ndicator == 1)
	{
		temp_texp_p =  (UI_buffer_type) s;
		if(( temp_texp_p[0] | (temp_texp_p[1] << 8)) == 0x09b0)
			{
				temp_texp_p += 2;
				if(( temp_texp_p[0] | (temp_texp_p[1] << 8)) == 0x09cd)
				{                                                                    
					str_len =(b->input_start_cursor_p+4) - (b->text) ;
					ire_shuffling_editor_buffer_for_bengali_spec(b->text, str_len);
					to_decide_to_reshuffle_inline = 1;
				}
			}
	}
#endif
    #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        gui_mlc_change_request((b->cursor_p - b->text)/ENCODING_LENGTH);
    #endif
    if(count > 0)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
    }
    //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(b);          
    //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_no_draw(b);
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_MULTIGRAPH__*/    
    return (count);
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_confirm_multitap_character
 * DESCRIPTION
 *  Completes the multitap input sequence
 *  
 *  This function is normally used as the input_complete_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_confirm_multitap_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_mlc_change_request(0);
#endif

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/


    if (b->predefine_char_pos != NULL)
    {
        s32 cursor_offset;
        
        cursor_offset = (b->cursor_p - b->text)/ENCODING_LENGTH;
        b->cursor_move_callback(cursor_offset);
    }
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_get_previous_character
 * DESCRIPTION
 *  get the previous character
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 gui_multi_line_input_box_get_previous_character(multi_line_input_box *b, UI_character_type *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        return 0;
    }
    if (b->cursor_p == b->text)
    {
        return 0;
    }
    /* c = (data->textBuffer[current_position->OffsetToText-1]|(data->textBuffer[current_position->OffsetToText-2]<<8)); */
    *c = (*(b->cursor_p - 2)) | (*(b->cursor_p - 1)) << 8;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_previous
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_previous(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->cursor_p;
    S32 cursor_offset;
    mmi_lm_cluster_info cur_cluster;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return MMI_FALSE;
    }
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;

    if (b->cursor_p == b->text)
    {
        UI_editor_play_tone_cannot_navigate();
        return MMI_FALSE;
    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    if (b->predefine_char_pos)
    {
        cursor_offset = (b->cursor_p - b->text)/ENCODING_LENGTH;

        /* Clear the cursor saved position*/
        b->cursor_fixed_x = -1;

        if (gui_multi_line_input_box_backword_cursor_pos(b, &cursor_offset))
        {
            b->cursor_p = b->text + cursor_offset * ENCODING_LENGTH;
            if (b->cursor_p == current_text_p)
                return MMI_TRUE;

            if (b->show_action_flag)
            {
                //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                //gui_show_multi_line_input_box(b);   /* show multiline input box */
                //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box_no_draw(b);

                if (b->cursor_p != current_text_p)
                {
                    return MMI_TRUE;
                }
            }
        }
        else
        {
            UI_editor_play_tone_cannot_navigate();
            
            return MMI_FALSE;
        }
    }
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/

    mmi_lm_get_prev_cluster(b->line_before_cursor_line_p, b->text + b->text_length - 2, b->cursor_p, MMI_TRUE, &cur_cluster);

    b->cursor_p = cur_cluster.data_ptr;
    
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__     
    if (b->icon_callback)
    {
        b->cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, b->cursor_p, 0);
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/ 

    current_text_p = b->cursor_p;
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);

#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
    if (UI_TEST_LF_CHARACTER(dummy_c) && (b->cursor_p != b->text))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c);
        if (!UI_TEST_CR_CHARACTER(dummy_c))
        {
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
        }
    }
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 

    /* Clear the cursor saved position*/
    b->cursor_fixed_x = -1;
    
    if (b->show_action_flag)
    {
        //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        //gui_show_multi_line_input_box(b);   /* show multiline input box */
        //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_no_draw(b);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_next
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_next(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->cursor_p;
    UI_character_type current_character;
    mmi_lm_cluster_info cur_cluster;
    S32 cursor_offset, new_offset;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return MMI_FALSE;
    }

    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        UI_editor_play_tone_cannot_navigate();
        return MMI_FALSE;
    }
    
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    if (b->predefine_char_pos)
    {
        new_offset = cursor_offset = (b->cursor_p - b->text)/ENCODING_LENGTH;
        if (gui_multi_line_input_box_forword_cursor_pos(b, &new_offset))
        {
            b->cursor_p = b->text + new_offset * ENCODING_LENGTH;

            if (b->show_action_flag)
            {
                //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                //gui_show_multi_line_input_box(b);   /* show multiline input box */
                //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box_no_draw(b);
            }
            
            /* Clear the cursor saved position*/
            b->cursor_fixed_x = -1;

            return (new_offset - cursor_offset) == 0 ? MMI_FALSE : MMI_TRUE;
        }
        else
        {
            UI_editor_play_tone_cannot_navigate();

            /* Clear the cursor saved position*/
            b->cursor_fixed_x = -1;

            return MMI_FALSE;
        }        
    }
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/

    if (b->line_before_cursor_line_p >= b->text
        && b->line_before_cursor_line_p <= b->cursor_p)
        mmi_lm_get_next_cluster(b->line_before_cursor_line_p, b->text + b->text_length, b->cursor_p, MMI_TRUE, &cur_cluster);
    else
        mmi_lm_get_next_cluster(b->text, b->text + b->text_length, b->cursor_p, MMI_TRUE, &cur_cluster);
    
    b->cursor_p = cur_cluster.data_ptr;
#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__     
    if (b->icon_callback)
    {
        b->cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, b->cursor_p, 1);
    }
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/

#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
    if (UI_TEST_CR_CHARACTER(current_character))
    {
        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, current_character);
        if (!UI_TEST_LF_CHARACTER(current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, current_character);
        }
    }
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 
    
    /* Clear the cursor saved position*/
    b->cursor_fixed_x = -1;
    
    if (b->show_action_flag)
    {
        //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        //gui_show_multi_line_input_box(b);   /* show multiline input box */
        //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_no_draw(b);
    }

    return MMI_TRUE;
}

#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_handle_CRLF_navigation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_handle_CRLF_navigation(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type cursor_p = b->cursor_p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(cursor_p, current_character);
    if (UI_TEST_LF_CHARACTER(current_character))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
        if (UI_TEST_CR_CHARACTER(current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, current_character);
        }
    }
}
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 

/* Used for move to next and previous line */


#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_handle_icon_navigation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_handle_icon_navigation(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type cursor_p = b->cursor_p;
    UI_character_type dummy_c;
    S32 cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!b->icon_callback)
    {
        return;
    }

    UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, dummy_c);
    for (cnt = 2; cnt <= MMI_MULTILINE_ICON_MAX_STRING_LEN; cnt++)
    {
        /* Inside character sequence */
        if (b->icon_callback(cursor_p, MMI_FALSE, NULL, NULL, 0, 0) >= cnt)
        {
            b->cursor_p = cursor_p;
            break;
        }
    }

    UI_UNUSED_PARAMETER(dummy_c);
}
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_previous_line
 * DESCRIPTION
 *  Moves the cursor to the previous line
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_previous_line(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh;
    S32 cursor_offset;
    UI_buffer_type save_text_p;
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilited_item_changed = 0;
    /* MTK Terry For Font Type when Key Down or UP */
    save_text_p = b->cursor_p;
    gui_set_font(b->text_font);
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        if (b->text_offset_y < 0)
        {
            /* Note that scrolling offset might be exactly one line if UI_MULTI_LINE_INPUT_BOX_RICHTEXT is set. */
            fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
            b->text_offset_y += fh;
            if (b->text_offset_y > 0)
            {
                b->text_offset_y = 0;
            }
        }
        else if (b->flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) /* Pixtel - 2/16/04 - Gurinder - Move to the previos item on up key in case on inline box. */
        {
            //Gurinder - 20/4/2004 - Use Inline Navigation Function Instead Of Noraml Text Menu
            //gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
            //show_fixed_list();
            //inline_fixed_list_goto_previous_item();
            hilited_item_changed = 1;
        }
    }
    else
    {
#ifdef __MMI_EDITOR_SSP_SUPPORT__ 
        if (b->cursor_line_p == b->text)
        {
            gui_show_multi_line_input_box(b);
        }
#endif
        if (b->line_before_cursor_line_p == b->cursor_line_p)
        {
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
            if (MMI_multi_line_inputbox_present)
            {
                //handle_inline_full_screen_edit_close();
                //Gurinder - 20/4/2004 - Use Inline Navigation Function Instead Of Noraml Text Menu
                //gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
                //show_fixed_list();
                //inline_fixed_list_goto_previous_item();
                hilited_item_changed = 1;
            }
            else
        #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
            if (b->header_height > 0 && b->text_offset_y < 0)
            {
                b->text_offset_y += 20;
                if (b->text_offset_y > 0)
                {
                    b->text_offset_y = 0;
                }
                //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                //gui_show_multi_line_input_box(b);   /* show multiline input box */
                //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box_no_draw(b);
                
                StopTimer(BLINKING_CURSOR);
            }
            else if (b->header_height == 0 && b->text_offset_y < 0)
            {
                b->text_offset_y = 0;
                //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                //gui_show_multi_line_input_box(b);
                //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box_no_draw(b);
            }
            else
            {
                if (b->header_height > 0)
                b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                UI_editor_play_tone_cannot_navigate();  /* play error tone */
            }
            return;
        }

        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_PREVIOUSE_LINE;
        gui_show_multi_line_input_box(b);   /* show multiline input box */
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_PREVIOUSE_LINE;        

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
        gui_multi_line_input_box_handle_icon_navigation(b);
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/    
    #if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
        gui_multi_line_input_box_handle_CRLF_navigation(b);
    #endif 

        gui_show_multi_line_input_box(b);   /* show multiline input box */
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    if (b->predefine_char_pos)
    {
        cursor_offset = (b->cursor_p - b->text)/ENCODING_LENGTH;
        if (!gui_multi_line_input_box_test_cursor_pos(b, cursor_offset))
        {
            if (gui_multi_line_input_box_backword_cursor_pos(b, &cursor_offset))
            {
                b->cursor_p = b->text + cursor_offset * ENCODING_LENGTH;
                gui_show_multi_line_input_box(b);   /* show multiline input box */
            }
            else
            {
                gui_show_multi_line_input_box(b);
                b->cursor_p = save_text_p;
                UI_editor_play_tone_cannot_navigate();
            }
        }
        return;
    }
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/  
        
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_next_line
 * DESCRIPTION
 *  Moves the cursor to the next line
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_next_line(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MTK Terry Redesign the next line operation */
    /* Some issues happened because the dh is not the same as the b->text_height and we can't get the next line height */
    /* We use b->text_height instead of dh and adjust the move distance when reaching the last line of the text */
    S32 fh /* ,dh */ ;
    S32 cursor_offset;
    UI_buffer_type save_text_p;
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilited_item_changed = 0;
    /* MTK Terry For Font Type when Key Down or UP */
    save_text_p = b->cursor_p;
    gui_set_font(b->text_font);
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        /* Note that scrolling offset might be exactly one line if UI_MULTI_LINE_INPUT_BOX_RICHTEXT is set. */
        fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
        if (fh <= 0)
        {
            fh = 1;
        }
        /* Leo add: enlarge the hidden area to show all strings when strings with different languages */
        //dh=(b->edit_height/fh);   /*MTK Terry roll back for stop watch title display need to discuss with Leo*/
        //dh=(b->edit_height/fh)-1;
        //dh*=fh;
        //START TARUN PMT 20041023 Added for sms chat issue
        //if ( (b->text_offset_y-fh)!=(-(b->text_height-(dh+fh)))) /*Comment this line here and have no idea why to need this line*/
        //END TARUN PMT 20041023
        {
            /* MTK Terry for In-Line Multiline Next Line Behavior */
            if ((b->text_offset_y /*-fh */ ) > (-(b->text_height - b->edit_height /* dh */ )))
            {
                b->text_offset_y -= fh;

                if (b->text_offset_y < b->edit_height - b->text_height)
                {
                    b->text_offset_y = b->edit_height - b->text_height;
                }
            }
            else if (b->flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU)
            {
                //Gurinder - 20/4/2004 - Use Inline Navigation Function Instead Of Noraml Text Menu
                //gui_fixed_list_menu_goto_first_item(&MMI_fixed_list_menu);
                /* MTK Terry for in line multiline read only to clear g_mmi_wgui_halfline_marquee_scroll_enable */
                if (complete_inline_item_edit)
                {
                    complete_inline_item_edit();
                }
                inline_fixed_list_goto_next_item();
                hilited_item_changed = 1;
                //show_fixed_list();
                //Fix List Navigation Problem With Read Only Control - Gurinder - 3/27/2004.
                //register_fixed_list_keys();
                //End
            }
        }
    }
    else    /* b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE */
    {
#ifdef __MMI_EDITOR_SSP_SUPPORT__ 
        if (b->cursor_line_p == b->text)
        {
            gui_show_multi_line_input_box(b);
        }
#endif
        if (b->line_after_cursor_line_p == b->cursor_line_p)
        {
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
            if (MMI_multi_line_inputbox_present)
            {
                //handle_inline_full_screen_edit_close();
                //Gurinder - 20/4/2004 - Use Inline Navigation Function Instead Of Noraml Text Menu
                //inline_fixed_list_goto_next_item();
                //gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
                //show_fixed_list();
                hilited_item_changed = 1;
            }
            else
        #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
            if (b->footer_height > 0 && (b->text_offset_y + b->text_height > b->edit_height))
            {
                b->text_offset_y -= 20;
                if (b->text_offset_y < b->edit_height - b->text_height)
                {
                    b->text_offset_y = b->edit_height - b->text_height;
                }
                //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
               // gui_show_multi_line_input_box(b);   /* show multiline input box */
                //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box_no_draw(b);
                
                StopTimer(BLINKING_CURSOR);
            }
            else if (b->text_offset_y + b->text_height > b->edit_height && b->header_height > 0)
            {
                b->text_offset_y -= 20;
                if (b->text_offset_y < b->edit_height - b->text_height)
                {
                    b->text_offset_y = b->edit_height - b->text_height;
                }

                //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                //gui_show_multi_line_input_box(b);   /* show multiline input box */
                //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box_no_draw(b);
                
                StopTimer(BLINKING_CURSOR);
            }
            else
            {
                if (b->footer_height > 0)
                b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                UI_editor_play_tone_cannot_navigate();
            }
            return;
        }
        /* MTK Terry for Move Down by Width */
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_NEXT_LINE;
        gui_show_multi_line_input_box(b);   /* show multiline input box */
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_NEXT_LINE;

#ifdef __MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__ 
        gui_multi_line_input_box_handle_icon_navigation(b);
#endif /*__MMI_EDITOR_MULTILINE_SUPPORT_ICON_CALLBACK__*/  
    #if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
        gui_multi_line_input_box_handle_CRLF_navigation(b);
    #endif 

        gui_show_multi_line_input_box(b);   /* show multiline input box */
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    if (b->predefine_char_pos)
    {
        cursor_offset = (b->cursor_p - b->text)/ENCODING_LENGTH;
        if (!gui_multi_line_input_box_test_cursor_pos(b, cursor_offset))
        {
            if (gui_multi_line_input_box_forword_cursor_pos(b, &cursor_offset))
            {
                b->cursor_p = b->text + cursor_offset * ENCODING_LENGTH;
                gui_show_multi_line_input_box(b);   /* show multiline input box */
            }
            else
            {
                b->cursor_p = save_text_p;
                gui_show_multi_line_input_box(b);
                UI_editor_play_tone_cannot_navigate();
            }
        }
        return;
    }
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/
    UI_UNUSED_PARAMETER(dummy_c);
}



/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_previous_page
 * DESCRIPTION
 *  Moves the cursor to the previous page
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_previous_page(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        gui_paging_multi_line_input_box_previous_page(b);
    }
    else
    {
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
        UI_UNUSED_PARAMETER(b);
        /* Feature not available */
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_next_page
 * DESCRIPTION
 *  Moves the cursor to the next page
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_next_page(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        gui_paging_multi_line_input_box_next_page(b);
    }
    else
    {
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */       
        UI_UNUSED_PARAMETER(b);
        /* Feature not available */
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
}


#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__

/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_previous_page
 * DESCRIPTION
 *  show the previous page of the book
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_previous_page(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 fh;

    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }

        if (b->text_offset_y < 0)
        {
            fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
            if (b->end_id == b->last_page_id && b->last_page_flag == 1 && b->edit_height_displayed_lines == 0)
            {
                /* prev_height=height of the text in the last page which can be a maximum of the window height.This variable is used to 
                   maintain the text relocation */
                b->text_offset_y += b->last_window_text_height;
                b->last_page_flag = 0;
            }
            else
            {
                b->text_offset_y += b->edit_height_displayed_lines;
            }
            if (b->text_offset_y >= -(b->page_details[PAGE_ZERO].page_height - b->edit_height_displayed_lines) &&
                b->size_of_total_data > GUI_PAGE_SIZE)
            {
                gui_paging_multi_line_input_box_get_previous_page_callback(b);
                if (b->page_details[PAGE_ZERO].page_id != 0)
                {
                    b->text_offset_y -= b->page_details[PAGE_ZERO].page_height;
                    /*
                     * to maintain the text relocation issue we save the height of page at 0th index before a new page entry.According to 
                     * paging algorithm,after a new page entry ,page at 0th index will come to index 1 of the buffer.If the height of the saved value differs 
                     * with the height of page at index 1 then this condition will be tested
                     */
                    b->page_details[PAGE_ZERO].page_id = b->start_id;
                    if (b->page_zero_prev_height != b->page_details[PAGE_ONE].page_height)
                    {
                        b->text_offset_y -= fh;
                    }
                }
            }
            if (b->text_offset_y > 0)
            {
                b->text_offset_y = 0;
            }
        }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        //gui_show_multi_line_input_box(b);
        //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_no_draw(b);
    }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }

    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_next_page
 * DESCRIPTION
 *  show the next page of the book
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_next_page(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh;

    UI_character_type dummy_c = 0;

    /* static S32 percentage_offset = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }
        fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
        if (fh <= 0)
        {
            fh = 1;
        }
        if ((b->text_offset_y) > (-(b->text_height - b->edit_height)))
        {
            b->text_offset_y -= b->edit_height_displayed_lines; /* ritesh */
            if (b->text_offset_y <=
                -(b->page_details[PAGE_ZERO].page_height + b->page_details[PAGE_ONE].page_height +
                  b->page_details[PAGE_TWO].page_height - b->edit_height_displayed_lines))
            {
                if (b->end_id < b->last_page_id)
                {
                    b->text_offset_y += b->page_details[PAGE_ZERO].page_height;
                    gui_paging_multi_line_input_box_get_next_page_callback(b);
                }
                else
                {
                    if (b->text_offset_y - b->edit_height_displayed_lines < -b->text_height && b->last_page_flag == 0)
                    {
                        b->last_window_text_height = b->text_height + b->text_offset_y;
                        b->last_page_flag = 1;
                    }
                }
            }

            if (b->text_offset_y < b->edit_height - b->text_height)
            {
                b->text_offset_y = b->edit_height_displayed_lines - b->text_height;
            }
        }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);

        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
        gui_show_multi_line_input_box(b);
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }
    
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_next_line_in_paging
 * DESCRIPTION
 *  show the next line of current page
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_next_line_in_paging(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh;
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {

        fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
        if (fh <= 0)
        {
            fh = 1;
        }
        if ((b->text_offset_y) > (-(b->text_height - b->edit_height)))
        {
            if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE && b->scroll_speed != 0 &&
                b->next_line_scroll_flag == 0)
            {
                b->text_offset_y -= (fh * b->scroll_speed) / GUI_SCROLL_STEPS_LINE_BY_LINE;     /* ritesh */

            }
            else
            {
                b->text_offset_y -= fh;
                b->next_line_scroll_flag = 0;
            }
            /* if text_offset_y reaches to the height of last page -  currently dispalyed height then we need next page */
            if (b->text_offset_y <=
                -(b->page_details[PAGE_ZERO].page_height + b->page_details[PAGE_ONE].page_height +
                  b->page_details[PAGE_TWO].page_height - b->edit_height_displayed_lines))
            {
                if (b->last_page_id > 0 && (b->end_id <= b->last_page_id - 1))
                {
                    b->text_offset_y += b->page_details[PAGE_ZERO].page_height;
                    gui_paging_multi_line_input_box_get_next_page_callback(b);
                }
            }
            if (b->text_offset_y < b->edit_height - b->text_height)
            {
                b->text_offset_y = b->edit_height - b->text_height;
            }
            
            if (b->text_offset_y > 0)
                b->text_offset_y = 0;
        }
    }
    else
    {
        gui_multi_line_input_box_next_line(b);
        if (b->text_offset_y <=
            -(b->page_details[PAGE_ZERO].page_height + b->page_details[PAGE_ONE].page_height +
            b->page_details[PAGE_TWO].page_height - b->edit_height_displayed_lines))
        {
            if (b->last_page_id > 0 && (b->end_id <= b->last_page_id - 1))
            {
                b->text_offset_y += b->page_details[PAGE_ZERO].page_height;
                gui_paging_multi_line_input_box_get_next_page_callback(b);
            }
        }
        
        if (b->text_offset_y < b->edit_height - b->text_height)
        {
            b->text_offset_y = b->edit_height - b->text_height;
        }

        if (b->text_offset_y > 0)
            b->text_offset_y = 0;
    }

    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_previous_line_in_paging
 * DESCRIPTION
 *  show the previous line of current page
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_previous_line_in_paging(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh;

    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        if (b->text_offset_y < 0)
        {
            fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
            b->text_offset_y += fh;
            if (b->text_offset_y >= -(b->page_details[PAGE_ZERO].page_height - b->edit_height_displayed_lines)) /* if text_offset_y reaches to height of page at 0th index */
            {
                gui_paging_multi_line_input_box_get_previous_page_callback(b);
                if (b->page_details[0].page_id != PAGE_ZERO)
                {
                    b->text_offset_y -= b->page_details[PAGE_ZERO].page_height;
                    b->page_details[PAGE_ZERO].page_id = b->start_id;
                    /*
                     * to maintain the text relocation issue we save the height of page at 0th index before a new page entry.According to 
                     * paging algorithm,after a new page entry ,page at 0th index will come to index 1 of the buffer.If the height of the saved value differs 
                     * with the height of page at index 1 then this condition will be tested
                     */
                    if (b->page_zero_prev_height != b->page_details[PAGE_ONE].page_height)
                    {
                        b->text_offset_y -= fh;
                    }
                }
            }

            if (b->text_offset_y > 0)
            {
                b->text_offset_y = 0;
            }
        }
    }
    else
    {
        gui_multi_line_input_box_previous_line(b);
        if (b->text_offset_y >= -(b->page_details[PAGE_ZERO].page_height - b->edit_height_displayed_lines)) /* if text_offset_y reaches to height of page at 0th index */
        {
            gui_paging_multi_line_input_box_get_previous_page_callback(b);
            if (b->page_details[0].page_id != PAGE_ZERO)
            {
                b->page_details[PAGE_ZERO].page_id = b->start_id;
            }
        }

        if (b->text_offset_y > 0)
        {
           b->text_offset_y = 0;
        } 
    }

    UI_UNUSED_PARAMETER(dummy_c);
}
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between Insert and Overwrite modes
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_toggle_insert_mode(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE;
    }
    else
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_highlight_cursor_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_multi_line_input_box_highlight_cursor_end(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->cursor_p;
    UI_buffer_type current_position = b->cursor_p;
    UI_buffer_type previous_position;
    UI_buffer_type last_position_p = b->last_position_p;
    U8 done = 0, bflag;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_PREVIOUS_CHARACTER(last_position_p, current_character);
    /* Move cursor backwards until a break character is encountered   */
    while (!done)
    {
        previous_position = current_position;
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        count++;
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    current_position = saved_current_position;
    /* Move cursor forwards until a break character is encountered */
    if (current_position >= last_position_p)
    {
        done = 1;
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
    {
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            done = 1;
            b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
        else
        {
            done = 0;
            b->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
    }

    while (!done)
    {
        if (current_position >= last_position_p)
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        count++;
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
            break;
        }
    }
    b->highlight_end_position = current_position;
    b->cursor_p = current_position;
    //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(b);
    //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_no_draw(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_highlight_cursor_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_multi_line_input_box_highlight_cursor_start(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->cursor_p;
    UI_buffer_type current_position = b->cursor_p;
    UI_buffer_type previous_position;
    UI_buffer_type last_position_p = b->last_position_p;
    U8 done = 0, bflag;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_position == b->text)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
    /* Move cursor forwards until a break character is encountered */
    while (!done)
    {
        if (current_position >= last_position_p)
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        count++;
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
            break;
        }
    }
    b->highlight_end_position = current_position;
    current_position = saved_current_position;
    /* Move cursor backwards until a break character is encountered   */
    if (current_position == b->text)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
    UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
    if (bflag)
    {
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    else
    {
        done = 0;
        b->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }

    while (!done)
    {
        previous_position = current_position;
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        count++;
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    b->cursor_p = previous_position;
    //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(b);
    //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box_no_draw(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_highlight_cursor_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  n       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_multi_line_input_box_highlight_cursor_number(multi_line_input_box *b, S32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->cursor_p;
    UI_buffer_type current_position = b->cursor_p;
    UI_buffer_type previous_position;
    U8 done = 0, bflag = 0;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE)
    {
        current_position = b->input_mode_cursor_p;
        saved_current_position = b->input_mode_cursor_p;
    }

    if (current_position == b->text)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    b->highlight_end_position = current_position;
    /* Move cursor backwards until n characters count out or a break character is encountered    */
    while (!done)
    {
        previous_position = current_position;
        if (n <= 0)
        {
            break;
        }
        if (current_position <= b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);

        if (UI_TEST_CR_CHARACTER(current_character) || UI_TEST_LF_CHARACTER(current_character))
            break;
        
        /* UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag) if (bflag)
        {
            break;
        }*/
        count++;
        n--;
    }

    b->highlight_start_position = previous_position;
    
    if (current_position == saved_current_position)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else if (!(bflag && (count == 0)))
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    b->highlight_start_position = previous_position;
    
    if (b->show_action_flag)
    {
        gui_show_multi_line_input_box(b);
    }
    
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    return (count);
}

/* GUI: dialer input box functions              */

UI_dialer_input_box_theme *current_dialer_input_box_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_dialer_input_box_current_theme
 * DESCRIPTION
 *  Applies the current theme for the single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_dialer_input_box_current_theme(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text_color = current_dialer_input_box_theme->normal_text_color;
    b->background_filler = current_dialer_input_box_theme->normal_filler;
    b->selection_color = current_dialer_input_box_theme->selection_color;
    b->selection_text_color = current_dialer_input_box_theme->selection_text_color;
    b->cursor_color = current_dialer_input_box_theme->cursor_color;
    b->text_font = current_dialer_input_box_theme->text_font;
    b->text_gap = current_dialer_input_box_theme->text_gap;
    b->flags |= current_dialer_input_box_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_dialer_input_box_theme
 * DESCRIPTION
 *  Applies the given theme to the single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  t       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_dialer_input_box_theme(dialer_input_box *b, UI_dialer_input_box_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text_color = t->normal_text_color;
    b->background_filler = t->normal_filler;
    b->selection_color = t->selection_color;
    b->selection_text_color = t->selection_text_color;
    b->cursor_color = t->cursor_color;
    b->text_font = t->text_font;
    b->text_gap = t->text_gap;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_clear
 * DESCRIPTION
 *  Initilaize dialer input box to defualtr
 * PARAMETERS
 *  b       [IN]        Is the dialer inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_clear(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        b->text_length = 0;
        b->allocated_length = 0;
        b->available_length = 0;
    }
    else
    {
        b->text[0] = '\0';
        b->text[1] = 0;
        b->text_length = 2;
    }
    b->current_text_p = b->text;
    b->last_position_p = b->text;
    b->UCS2_count = 0;
    #if 0 /* slim_2_2 */ //
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_dialer_input_box
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  The buffer is automatically allocated by the inputbox.
 *  The buffer is set to blank on creation of this object.
 *  See also gui_destroy_dialer_input_box()
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the inputbox
 *  height      [IN]        Is the height of the inputbox
 *  length      [IN]        Is the length of the buffer to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_dialer_input_box(dialer_input_box *b, S32 x, S32 y, S32 width, S32 height, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) gui_malloc(length * sizeof(UI_character_type));
    b->allocated_length = length;
    b->available_length = length;

    gui_dialer_input_box_clear(b);
    b->current_text_p = b->text;
    b->flags = 0;
    gui_set_dialer_input_box_current_theme(b);
    b->validation_callback = UI_dummy_validation_function;
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->UCS2_count = 0;
    b->fixed_cursor_x = -1;
}

#if 0 /* slim_2_2 */ //
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
#endif

#ifdef __MMI_EDITOR_DIALER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  gui_create_dialer_input_box_set_buffer
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  Also, the buffer should be allocated and passed to this function.
 *  The buffer retains the string passed.
 * PARAMETERS
 *  b                   [IN]        Is the single-line inputbox object (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the inputbox
 *  height              [IN]        Is the height of the inputbox
 *  buffer              [IN]        Is the buffer the inputbox should use (pre-allocated)
 *  length              [IN]        Is the length of the buffer
 *  text_length         [IN]        
 *  edit_position       [IN]        Is the cursor_position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_dialer_input_box_set_buffer(
        dialer_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type text;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->current_text_p = b->text;
    b->allocated_length = length;
    b->available_length = length;
    b->UCS2_count = 0;
    if (b->text != NULL)
    {
        text = b->text;
        for (i = 0; i < edit_position; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
        }
        b->current_text_p = text;
        for (i = edit_position; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
        }
        b->text_length = text_length;
        b->last_position_p = b->current_text_p;
    }
    else    /* b->text!=NULL */
    {
        b->text_length = 0;
    }
    b->flags = 0;
    gui_set_dialer_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    b->fixed_cursor_x = -1;

#ifdef __MMI_FIXED_DIALER_FONT__
    b->bottom_line_index = 0;
    memset(b->line_start_p, 0, sizeof(UI_buffer_type)*MAX_DIALER_LINE_COUNT);
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_dialer_input_box
 * DESCRIPTION
 *  Moves a single line input box
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object (pre-allocated)
 *  x       [IN]        Is the left-top corner
 *  y       [IN]        Is the left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_dialer_input_box(dialer_input_box *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_show_cursor
 * DESCRIPTION
 *  Displays the cursor in a single-line inputbox (internal function)
 *  
 *  This function is used internally.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  x           [IN]        Is the left-top corner of the cursor
 *  y           [IN]        Is the left-top corner of the cursor
 *  height      [IN]        Is the height of cursor
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_show_cursor(dialer_input_box *b, S32 x, S32 y, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = b->cursor_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_BLINKING_CURSOR_SUPPORT)
    if (y > (b->y + b->height) || (y + height) < b->y)
        StopTimer(BLINKING_CURSOR);
    else
        UI_inputbox_pre_show_cursor(x, y, x + 1, y + height - 1, c);
#else 
    UI_inputbox_pre_show_fixed_cursor(x, y, x+1, y+height-1, c);
#endif 
}

/* MTK Elvis for color dialing font */


/*****************************************************************************
 * FUNCTION
 *  gui_get_dialing_font_color
 * DESCRIPTION
 *  get dialing font color
 * PARAMETERS
 *  c       [IN]        Is the single-line inputbox object
 * RETURNS
 *  color
 *****************************************************************************/
color gui_get_dialing_font_color(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nIdx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (nIdx = 0; color_dialing_font_map[nIdx].ch; nIdx++)
    {
        if (color_dialing_font_map[nIdx].ch == c)
        {
            return color_dialing_font_map[nIdx].c;
        }
    }
    return color_dialing_font_map[nIdx].c;
}




/*****************************************************************************
 * FUNCTION
 *  gui_show_dialer_input_box
 * DESCRIPTION
 *  Displays a single-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dialer_input_box(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_dialer_input_box_ext(b, (-1), (-1));
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_dialer_input_box_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dialer_input_box_ext(dialer_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

#ifdef __MMI_COLOR_DIALLING_FONT__
    color c = {255, 255, 255, 100};
    UI_filled_area background_filler = *(b->background_filler);
    UI_filled_area *f = &background_filler;
#else
    UI_filled_area *f = b->background_filler;
#endif

    U8 selection_flag = 0;
    UI_character_type current_character;
    S32 character_width = 0;
    UI_buffer_type previous_text_p;
    UI_buffer_type current_text_p = b->text;
    U32 flags = b->flags;
    S32 text_x, right_x, text_y, character_height;
    U8 cursor_displayed_flag = 0;
    U8 cusrsor_set_flag = 0;
    S32 text_gap = b->text_gap;
    S32 first_position_flag = 0, cursor_x = 0, cursor_y = 0;
    color b_normal_text_color = b->text_color;
    color b_selection_text_color = b->selection_text_color;
    color b_selection_color = b->selection_color;
    mmi_fe_get_string_info_param_struct query;

    /* UI_character_type  mask_character=b->mask_character; */
    UI_buffer_type b_current_text_p = b->current_text_p;
    UI_buffer_type b_text = b->text;
    b->first_position_p = b->text;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_cursor_x1 = 0;
    UI_cursor_y1 = 0;
    UI_cursor_x2 = 0;
    UI_cursor_y2 = 0;

    x1 = b->x;
    y1 = b->y;
    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;
    gui_set_clip(x1, y1, x2, y2);

#ifdef __MMI_COLOR_DIALLING_FONT__
    f->c = c;
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (!(flags & UI_DIALER_INPUT_BOX_DISABLE_DRAW))
    {
        gdi_push_and_set_alpha_blending_source_layer(gui_inputs_get_source_layer());
    }
#endif

    if (f == NULL)
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    else
        gui_draw_filled_area(x1, y1, x2, y2, f);

    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_font(b->text_font);
    
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)b->text;
    query.n = mmi_ucs2strlen((const char*)b->text);

#ifdef __MMI_FIXED_DIALER_FONT__
    if (b->bottom_line_index > 0)
    {
        query.n = (b->line_start_p[b->bottom_line_index - 1] - b->text) / ENCODING_LENGTH;
    }
#endif

    query.enableTruncated = MMI_FALSE;
    query.w = text_gap;
    mmi_fe_get_string_widthheight(&query);
    
    Get_CharWidthHeight(0x31, &character_width, &character_height);
    right_x = (b->width % (character_width + text_gap))/2;
    if (right_x == 0)
        right_x = (character_width + text_gap)/2;
    
#ifdef __MMI_FIXED_DIALER_FONT__
    b->n_lines = 1 + b->bottom_line_index;
#else
    b->n_lines = 1;
#endif

    if (current_text_p != NULL)
    {
        if (flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
        {
            selection_flag = 1;
        }

        if (query.pHeight != 0)
            character_height = query.pHeight;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
        /* If there is no gap in the top/buttom of the character, add a gap for the line */
        if (query.pHeight == (query.maxAscent + query.maxDescent))
            character_height++;
#endif
        
        current_character = (UI_character_type) - 1;
        current_text_p = b->last_position_p;

#ifdef __MMI_FIXED_DIALER_FONT__
        if (b->bottom_line_index > 0)
        {
            current_text_p = b->line_start_p[b->bottom_line_index - 1];
        }
#endif
        text_x = x2 - right_x;
        text_y = y2 - character_height;

#ifndef __MMI_COLOR_DIALLING_FONT__
        if (!(current_MMI_theme->dialer_inputbox_text_border_color->r == 0
            && current_MMI_theme->dialer_inputbox_text_border_color->g == 0
            && current_MMI_theme->dialer_inputbox_text_border_color->b == 255))
        {
            text_y--;
            character_height += 2;
        }
#endif

        if (b_text != current_text_p)
        {
            gui_set_text_color(b_normal_text_color);
            while (current_text_p != b_text)
            {
                previous_text_p = current_text_p;
                UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
                character_width = gui_get_character_width(current_character);

#ifdef __MMI_FIXED_DIALER_FONT__
                b->line_start_p[b->n_lines - 1] = current_text_p;
#endif
                if ((text_x - (character_width + text_gap)) <= x1)
                {

#ifdef __MMI_FIXED_DIALER_FONT__
                    b->line_start_p[b->n_lines - 1] = previous_text_p;
                    b->line_start_p[b->n_lines] = current_text_p;
#endif
                    b->n_lines++;   /* vandana */
                    cursor_x = text_x - 1;
                    cursor_y = text_y;
                    text_x = x2 - right_x;
                    text_y -= character_height;
                    if (text_y < y1 && first_position_flag == 0)
                    {
                        b->first_position_p = previous_text_p;
                        first_position_flag = 1;
#ifndef __MMI_FIXED_DIALER_FONT__
                        break;
#endif
                    }
                }

#ifdef __MMI_FIXED_DIALER_FONT__
                if (first_position_flag)
                {
                    text_x -= (character_width + text_gap);
                    continue;
                }
#endif

                if ((-1) == move_to_x && (-1) == move_to_y)
                {
                    if (previous_text_p == b_current_text_p)
                    {
                        if (selection_flag)
                        {
                            text_x -= (character_width + text_gap);
                            gui_fill_rectangle(
                                text_x,
                                text_y,
                                text_x + character_width-1,
                                text_y + character_height-1,
                                b_selection_color);
                            gui_set_text_color(b_selection_text_color);
                            /* MTK Elvis for R2L characters */

                            FONT_CANCEL_WIDTH(1);
                            ShowString_n_baseline(text_x, text_y, *UI_font, 0, (U8*)&current_character, 1, query.baseline);                       
                            FONT_CANCEL_WIDTH(0);
                            gui_set_text_color(b_normal_text_color);
                            cursor_displayed_flag = 1;
                        }
                        else
                        {
                            if (!cursor_displayed_flag)
                            {
                                if (!(flags & UI_DIALER_INPUT_BOX_DISABLE_DRAW) &&
                                    !(flags & UI_DIALER_INPUT_BOX_DISABLE_CURSOR_DRAW))
                                {
                                    #if 0 /* slim_2_2 */ // 
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
                                    #endif    
                                    {
                                        gui_dialer_input_box_show_cursor(b, text_x - 1, text_y, character_height);
                                        b->cursor_x = (text_x - 1);
                                        b->cursor_y = text_y;
                                        if (text_x == (x2 - right_x))
                                            b->fixed_cursor_x = -1;
                                    }
                                }
                                cursor_displayed_flag = 1;
                            }
                            text_x -= (character_width + text_gap);

#ifdef __MMI_COLOR_DIALLING_FONT__
                            gui_set_text_color(gui_get_dialing_font_color(current_character));
                            FONT_CANCEL_WIDTH(1);
                            {
                                ShowString_n_baseline(text_x, text_y, *UI_font, 0, (U8*)&current_character, 1, query.baseline);
                            }
                            FONT_CANCEL_WIDTH(0);
#else
                            /* use this theme only after 07B*/
                            gui_set_text_color(*(current_MMI_theme->dialer_inputbox_text_color));
                            gui_set_text_border_color(*(current_MMI_theme->dialer_inputbox_text_border_color));
                            {
                                UI_character_type string[2];

                                string[0] = current_character;
                                string[1] = 0;
                                FONT_CANCEL_WIDTH(1);
                                {
                                    mmi_fe_show_string_bordered_baseline(text_x, text_y, (U8*)string, query.baseline, 0);
                                }
                                FONT_CANCEL_WIDTH(0);
                            }
#endif 
                        }
                    }
                    else    /* previous_text_p==b_current_text_p */
                    {
                        text_x -= (character_width + text_gap);

                    #ifdef __MMI_COLOR_DIALLING_FONT__
                        gui_set_text_color(gui_get_dialing_font_color(current_character));
                        FONT_CANCEL_WIDTH(1);
                        {
                            ShowString_n_baseline(text_x, text_y, *UI_font, 0, (U8*)&current_character, 1, query.baseline);
                        }
                        FONT_CANCEL_WIDTH(0);
                    #else
                        /* use this theme only after 07B*/
                        gui_set_text_color(*(current_MMI_theme->dialer_inputbox_text_color));
                        gui_set_text_border_color(*(current_MMI_theme->dialer_inputbox_text_border_color));
                        {
                            UI_character_type string[2];
                            
                            string[0] = current_character;
                            string[1] = 0;
                            FONT_CANCEL_WIDTH(1);
                            {
                                mmi_fe_show_string_bordered_baseline(text_x, text_y, (U8*)string, query.baseline, 0);
                            }
                            FONT_CANCEL_WIDTH(0);
                        }
                    #endif                
                    }
                }
                else    /* (-1) == move_to_x && (-1) == move_to_y */
                {
                    text_x -= (character_width + text_gap);
                    if (((text_x) < move_to_x) && ((text_y + character_height) >= move_to_y) && (text_y < move_to_y) &&
                        (!cusrsor_set_flag))
                    {
                        b->cursor_x = text_x - 1;
                        b->cursor_y = text_y;
                        b->current_text_p = previous_text_p;
                        cusrsor_set_flag = 1;
                    }
                }
            }
        }
        if (!cursor_displayed_flag 
            && ((-1) == move_to_x) && ((-1) == move_to_y)
            && b->current_text_p == b->text)
        {
            if (!(flags & UI_DIALER_INPUT_BOX_DISABLE_DRAW) && !(flags & UI_DIALER_INPUT_BOX_DISABLE_CURSOR_DRAW))
            {
                #if 0 /* slim_2_2 */ // 
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
                #endif
                {
                    gui_dialer_input_box_show_cursor(b, text_x - 1, text_y, character_height);
                    b->cursor_x = (text_x - 1);
                    b->cursor_y = text_y;
                }
            }
        }

        if (!cursor_displayed_flag && first_position_flag && ((-1) == move_to_x) && ((-1) == move_to_y))
        {
            if (!(flags & UI_DIALER_INPUT_BOX_DISABLE_DRAW) 
                && !(flags & UI_DIALER_INPUT_BOX_DISABLE_CURSOR_DRAW)
 /* slim_2_2 */ //                && !(flags & UI_DIALER_INPUT_BOX_SHOW_BLOCK_CURSOR)
                && !(flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP))
            {
                b->current_text_p = b->first_position_p;
                gui_dialer_input_box_show_cursor(b, cursor_x, cursor_y, character_height);
                b->cursor_x = cursor_x;
                b->cursor_y = cursor_y;
            }
        }

        if ((((-1) != move_to_x) || ((-1) != move_to_y)) && (!cusrsor_set_flag))
        {
            b->cursor_x = text_x - 1;
            b->cursor_y = text_y;
            b->current_text_p = current_text_p;
            cusrsor_set_flag = 1;
        }
    }

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (!(flags & UI_DIALER_INPUT_BOX_DISABLE_DRAW))
        gdi_pop_and_restore_alpha_blending_source_layer();
#endif
}


#ifdef __MMI_FIXED_DIALER_FONT__
S32 gui_dialer_input_box_get_cursor_line_index(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->current_text_p == b->text)
        return b->n_lines - 1;

    for (i=0; i<b->n_lines; i++)
    {
        if (b->current_text_p > b->line_start_p[i])
            return i;
    }

    return b->n_lines - 1;
}
#endif

#if 0 /* slim_2_2 */ //
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
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_delete_character
 * DESCRIPTION
 *  Deletes a character before the current cursor position (Backspace)
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_delete_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_text_p = b->current_text_p;
    previous_text_p = b->current_text_p;
    if (previous_text_p == b->text)
    {
        UI_editor_play_tone_cannot_change();
        return;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(previous_text_p, dummy_c);
    b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
    b->current_text_p = previous_text_p;
    #if 0 /* slim_2_2 */ //
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
    }
    if (b->flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
    {
        b->flags &= ~UI_DIALER_INPUT_BOX_STATE_MULTITAP;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(b->last_position_p, current_character);

#ifdef __MMI_FIXED_DIALER_FONT__
    gui_dialer_input_box_refresh_for_fixed_font(b);
#endif

    /* gui_dialer_inputbox_locate_cursor(b); */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the current cursor position (Delete)
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_delete_current_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_text_p = b->current_text_p;
    previous_text_p = b->current_text_p;
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
    if (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        #if 0 /* slim_2_2 */ // 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
        }
        b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
        if (b->flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
        {
            b->flags &= ~UI_DIALER_INPUT_BOX_STATE_MULTITAP;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(b->last_position_p, current_character);
        /* gui_dialer_inputbox_locate_cursor(b); */
        b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
        b->change_callback();
    }
    else
    {
        UI_editor_play_tone_cannot_change();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_delete_all
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_delete_all(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    UI_buffer_type p = b->text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(p, c);
    UI_UNUSED_PARAMETER(c);
    /* MTK Elvis 20040611 donot play tone while the text buffer is zero */

    gui_dialer_input_box_clear(b);
#ifdef __MMI_FIXED_DIALER_FONT__
    gui_dialer_input_box_refresh_for_fixed_font(b);
#endif
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between Insert and Overwrite modes
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_toggle_insert_mode(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE)
    {
        b->flags &= ~UI_DIALER_INPUT_BOX_OVERWRITE_MODE;
    }
    else
    {
        b->flags |= UI_DIALER_INPUT_BOX_OVERWRITE_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_insert_character
 * DESCRIPTION
 *  Inserts a character at the current cursor position
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_insert_character(dialer_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->fixed_cursor_x = -1;
    #if 0 /* slim_2_2 */ //
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
    #endif
    p1 = p2 = b->current_text_p;
    if (b_flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE)
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
        if ((p1 == b->last_position_p) && ((b->text_length) >= b->available_length))
        {
            return;
        }
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
        {
            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
            #if 0 /* slim_2_2 */ //
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
            #endif
            b->current_text_p = p2;
        }
        else    /* !UI_STRING_END_OF_STRING_CHARACTER(old_c) */
        {
            if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_buffer_type p3, p4;
                    UI_character_type cc;

                    if (b->current_text_p != b->text)
                    {
                        p3 = p4 = b->text;
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                        while (p3 != b->current_text_p)
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                            UI_STRING_INSERT_CHARACTER(p4, cc);
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);   /* get previous character */
                        UI_STRING_INSERT_CHARACTER(b->current_text_p, c);       /* insert character */
                    }
                }
                else    /* (b->text_length)>=(b->available_length) */
                {
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    #if 0 /* slim_2_2 */ //
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
                    #endif
                    while (!UI_STRING_END_OF_STRING_CHARACTER(c))       /* check for end of string */
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);        /* get next character */
                        UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                        c = old_c;
                    }
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    b->text_length += ((S32) p2 - (S32) p1);
                    UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
                }
            }
            else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_editor_play_tone_cannot_insert();
                    return;
                }
                p1 = b->current_text_p;
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))   /* check for end of string */
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
                    UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                #if 0 /* slim_2_2 */ //
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
                #endif
                b->text_length += ((S32) p2 - (S32) p1);
            }
        }
    }
    else    /* b_flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE */
    {
        if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
        {
            if ((b->text_length) >= (b->available_length))
            {
                UI_buffer_type p3, p4;
                UI_character_type cc;

                if (b->current_text_p != b->text)
                {
                    p3 = p4 = b->text;
                    UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                    while (p3 != b->current_text_p)
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                        UI_STRING_INSERT_CHARACTER(p4, cc);
                    }
                    UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                    UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                }
                else
                {
                    UI_editor_play_tone_cannot_insert();
                    return;
                }
            }
            else    /* (b->text_length)>=(b->available_length) */
            {
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                #if 0 /* slim_2_2 */ //
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
                #endif
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                b->text_length += ((S32) p2 - (S32) p1);
                UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
            }
        }
        else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
        {
            if ((b->text_length) >= (b->available_length))
            {
                UI_editor_play_tone_cannot_insert();
                return;
            }
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
            #if 0 /* slim_2_2 */ //
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
            #endif
            while (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            b->text_length += ((S32) p2 - (S32) p1);
            UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
        }
    }
    /* gui_dialer_inputbox_locate_cursor(b); */
#ifdef __MMI_FIXED_DIALER_FONT__
    gui_dialer_input_box_refresh_for_fixed_font(b);
#endif
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
}

#if 0 /* slim_2_2 */ //
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
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_first_position
 * DESCRIPTION
 *  check if current cursorposition is at first character
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_first_position(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->current_text_p == b->text)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_last_position
 * DESCRIPTION
 *  return text length of dialer nut box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_last_position(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_first_line
 * DESCRIPTION
 *  check if current cursorposition is at first line
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_first_line(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, y2;
    S32 y_up;
    S32 character_height;
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(MMI_dialer_inputbox.text_font);
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)MMI_dialer_inputbox.text;
    query.n = mmi_ucs2strlen((const char*)MMI_dialer_inputbox.text);
    query.enableTruncated = MMI_FALSE;
    query.w = MMI_dialer_inputbox.text_gap;
    mmi_fe_get_string_widthheight(&query);

    character_height = query.pHeight;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query.pHeight == query.baseline)
        character_height++;
#endif

#ifndef __MMI_COLOR_DIALLING_FONT__
    if (!(current_MMI_theme->dialer_inputbox_text_border_color->r == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->g == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->b == 255))
        character_height += 2;
#endif

    y1 = MMI_dialer_inputbox.y;
    y2 = y1 + MMI_dialer_inputbox.height - 1;
    y_up = y2 - character_height * (MMI_dialer_inputbox.n_lines - 1) - character_height/2;

    
    if (MMI_dialer_inputbox.n_lines > 1
        && MMI_dialer_inputbox.cursor_y > y_up)    
    {
        return (0);
    }
    return (1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_last_line
 * DESCRIPTION
 *  check if current cursorposition is at last line
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_last_line(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, y2;
    S32 y_last;
    S32 character_height;
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(MMI_dialer_inputbox.text_font);
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)MMI_dialer_inputbox.text;
    query.n = mmi_ucs2strlen((const char*)MMI_dialer_inputbox.text);
    query.enableTruncated = MMI_FALSE;
    query.w = MMI_dialer_inputbox.text_gap;
    mmi_fe_get_string_widthheight(&query);

    character_height = query.pHeight;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query.pHeight == query.baseline)
        character_height++;
#endif

#ifndef __MMI_COLOR_DIALLING_FONT__
    if (!(current_MMI_theme->dialer_inputbox_text_border_color->r == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->g == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->b == 255))
        character_height += 2;
#endif

    y1 = MMI_dialer_inputbox.y;
    y2 = y1 + MMI_dialer_inputbox.height - 1;
    y_last = y2 - character_height - 2;

#if( defined(__MMI_TOUCH_DIAL_SCREEN__))
    if ((MMI_dialer_inputbox.cursor_y + 1) < y_last && (MMI_dialer_inputbox.n_lines > 1))
#else
    if ((MMI_dialer_inputbox.cursor_y + 2) < y_last && (MMI_dialer_inputbox.n_lines > 1))
#endif
    {    
        return (0);
    }
    return (1);
}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_last_character_position
 * DESCRIPTION
 *  return text length of dialer nut box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_last_character_position(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_last_position_overflow
 * DESCRIPTION
 *  return text length of dialer nut box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_last_position_overflow(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag1 = 0;
    U8 flag2 = 0;
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        flag1 = 1;
    }
    if ((b->text_length) >= (b->available_length))
    {
        flag2 = 1;
    }
    if (flag1 && flag2)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_get_text_length
 * DESCRIPTION
 *  return text length of dialer nut box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  S32 return txt length of dialer iput box
 *****************************************************************************/
S32 gui_dialer_input_box_get_text_length(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((b->text_length) >> 1) - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_insert_multitap_character
 * DESCRIPTION
 *  Inserts a multitap character at the current cursor position
 *  
 *  This function is normally used as the input_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_insert_multitap_character(dialer_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->fixed_cursor_x = -1;
    #if 0 /* slim_2_2 */ //
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
    #endif
    if ((b_flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP) && (b->current_text_p != b->text))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
        p1 = p2 = b->current_text_p;
        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);        /* get next character */
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
        {
            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
            #if 0 /* slim_2_2 */ //
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
            #endif
            b->current_text_p = p2;
        }
        else    /* !UI_STRING_END_OF_STRING_CHARACTER(old_c) */
        {
            if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_buffer_type p3, p4;
                    UI_character_type cc;

                    if (b->current_text_p != b->text)
                    {
                        p3 = p4 = b->text;
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);   /* get next character */
                        while (p3 != b->current_text_p)
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                            UI_STRING_INSERT_CHARACTER(p4, cc);
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                        UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                    }
                }
                else    /* (b->text_length)>=(b->available_length) */
                {
                    p1 = b->current_text_p;
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    while (!UI_STRING_END_OF_STRING_CHARACTER(c))       /* check for end of string */
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);        /* get next character */
                        UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                        c = old_c;
                    }
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    #if 0 /* slim_2_2 */ //
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
                    #endif
                    b->text_length += ((S32) p2 - (S32) p1);
                }
            }
            else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
            {
                p1 = b->current_text_p;
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                #if 0 /* slim_2_2 */ //
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
                #endif
                b->text_length += ((S32) p2 - (S32) p1);
            }
        }
    }
    else    /* (b_flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP) && (b->current_text_p!=b->text) */
    {
        p1 = p2 = b->current_text_p;
        if (b_flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE)
        {
            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
            if ((p1 == b->last_position_p) && ((b->text_length) >= b->available_length))
            {
                if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
                {
                    UI_buffer_type p3, p4;
                    UI_character_type cc;

                    if (b->current_text_p != b->text)
                    {
                        p3 = p4 = b->text;
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);   /* get next character */
                        while (p3 != b->current_text_p)
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                            UI_STRING_INSERT_CHARACTER(p4, cc);
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                        UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                    }
                    return;
                }
                else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
                {
                    UI_editor_play_tone_cannot_insert();    /* play error tone of cannot insert */
                    return;
                }
            }
            if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
            {
                UI_STRING_INSERT_CHARACTER(p2, c);
                #if 0 /* slim_2_2 */ //
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
                #endif
                b->current_text_p = p2;
            }
            else    /* !UI_STRING_END_OF_STRING_CHARACTER(old_c) */
            {
                if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
                {
                    if ((b->text_length) >= (b->available_length))
                    {
                        UI_buffer_type p3, p4;
                        UI_character_type cc;

                        if (b->current_text_p != b->text)
                        {
                            p3 = p4 = b->text;
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);       /* get */
                            while (p3 != b->current_text_p)
                            {
                                UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                                UI_STRING_INSERT_CHARACTER(p4, cc);
                            }
                            UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                            UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                        }
                    }
                    else    /* (b->text_length)>=(b->available_length) */
                    {
                        p1 = b->current_text_p;
                        UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                        while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                            UI_STRING_INSERT_CHARACTER(p2, c);
                            c = old_c;
                        }
                        UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                        #if 0 /* slim_2_2 */ //
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
                        #endif
                        b->text_length += ((S32) p2 - (S32) p1);
                    }
                }
                else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
                {
                    if ((b->text_length) >= (b->available_length))
                    {
                        UI_editor_play_tone_cannot_insert();
                        return;
                    }
                    p1 = b->current_text_p;
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                        UI_STRING_INSERT_CHARACTER(p2, c);
                        c = old_c;
                    }
                    UI_STRING_INSERT_CHARACTER(p2, c);  /* insert chatracte */
                    #if 0 /* slim_2_2 */ //
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
                    #endif
                    b->text_length += ((S32) p2 - (S32) p1);
                }
            }
        }
        else    /* b_flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE */
        {
            if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_buffer_type p3, p4;
                    UI_character_type cc;

                    if (b->current_text_p != b->text)
                    {
                        p3 = p4 = b->text;
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                        while (p3 != b->current_text_p)
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                            UI_STRING_INSERT_CHARACTER(p4, cc);
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                        UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                    }
                    else
                    {
                        UI_editor_play_tone_cannot_insert();
                        return;
                    }
                }
                else    /* (b->text_length)>=(b->available_length) */
                {
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    #if 0 /* slim_2_2 */ //
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
                    #endif
                    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                        UI_STRING_INSERT_CHARACTER(p2, c);
                        c = old_c;
                    }
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    b->text_length += ((S32) p2 - (S32) p1);
                    UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
                }
            }
            else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_editor_play_tone_cannot_insert();
                    return;
                }
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                #if 0 /* slim_2_2 */ //
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
                #endif
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                b->text_length += ((S32) p2 - (S32) p1);
                UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
            }
        }
        b->flags |= UI_DIALER_INPUT_BOX_STATE_MULTITAP;
    }
    /* gui_dialer_inputbox_locate_cursor(b); */

#ifdef __MMI_FIXED_DIALER_FONT__
    gui_dialer_input_box_refresh_for_fixed_font(b);
#endif
    
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_confirm_multitap_character
 * DESCRIPTION
 *  Completes the multitap input sequence.
 *  
 *  This function is normally used as the input_complete_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_confirm_multitap_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_DIALER_INPUT_BOX_STATE_MULTITAP;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_previous
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_previous(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }

    if (b->current_text_p == b->text)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }

#ifndef __MMI_FIXED_DIALER_FONT__
    if (b->current_text_p == b->first_position_p)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
#endif

    b->fixed_cursor_x = -1;
    UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);

#ifdef __MMI_FIXED_DIALER_FONT__
    if (b->current_text_p <= b->first_position_p
        && b->current_text_p != b->text)
    {
        b->bottom_line_index++;
    }
#endif
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_next
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_next(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
    b->fixed_cursor_x = -1;
    b->current_text_p = current_text_p;

#ifdef __MMI_FIXED_DIALER_FONT__
    {
        S32 index;
        
        index = gui_dialer_input_box_get_cursor_line_index(b);
        if (index < b->bottom_line_index)
            b->bottom_line_index--;
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_dialer_input_box
 * DESCRIPTION
 *  Changes the size of the single-line inputbox.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_dialer_input_box(dialer_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;
    b->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_goto_first_character
 * DESCRIPTION
 *  go to first charcter of dialer input box
 * PARAMETERS
 *  b       [IN]        Dialer input bx
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_goto_first_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->current_text_p = b->text;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_goto_last_character
 * DESCRIPTION
 *  go to last charcter of dialer input box
 * PARAMETERS
 *  b       [IN]        Dialer input bx
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_goto_last_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->current_text_p = b->text;
    if (b->text != NULL)
    {
        while (!done)
        {
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
        }
        if (b->current_text_p != b->text)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
        }
    }
}

#else  /*  __MMI_EDITOR_DIALER_SUPPORT__ */
void gui_show_dialer_input_box_ext(dialer_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}


#endif /*  __MMI_EDITOR_DIALER_SUPPORT__ */
/* Interfaces to play error tones in the editors   */

#include "SettingProfile.h"

U8 UI_editor_tones_flag = 1;


/*****************************************************************************
 * FUNCTION
 *  UI_editor_Play_tone
 * DESCRIPTION
 *  play tone with editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void UI_editor_Play_tone(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!UI_editor_tones_flag)
    {
        return;
    }
    StopCurrentKeyPadTone(); /*stop current tone*/
    srv_prof_play_tone(tone_type,NULL);
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
#endif

/*****************************************************************************
 * FUNCTION
 *  UI_editor_disable_tones
 * DESCRIPTION
 *  disable editor tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_editor_disable_tones(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_editor_tones_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  UI_editor_enable_tones
 * DESCRIPTION
 *  enabel editor tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_editor_enable_tones(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_editor_tones_flag = 1;
}

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
/* Check the chracter for WCSS permitted input character */


/*****************************************************************************
 * FUNCTION
 *  UI_check_WCSS_normal_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]        
 *  input_type      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S8 UI_check_WCSS_normal_character(UI_character_type c, U8 *input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((UI_character_type) c == (UI_character_type) 0x41))    /* 'A' */
    {
        *input_type = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x61))       /* 'a' */
    {
        *input_type = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x4E))       /* 'N' */
    {
        *input_type = IMM_INPUT_MODE_123;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x6E))       /* 'n' */
    {
        *input_type = IMM_INPUT_MODE_123_SYMBOLS;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x58))       /* 'X' */
    {
        *input_type = IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x78))       /* 'x' */
    {
        *input_type = IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x4D))       /* 'M' */
    {
        *input_type =
            IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER |
            PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x6D))       /* 'm' */
    {
        *input_type =
            IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER |
            PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED;
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Insert default chracter 0 or ' ' according to input format character. */


/*****************************************************************************
 * FUNCTION
 *  UI_insert_WCSS_default_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [?]         
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 *UI_insert_WCSS_default_character(U8 *str, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (c)
    {
        case 0x41:
        case 0x61:
        case 0x58:
        case 0x78:
        case 0x4D:
        case 0x6D:
            c = 0x20;   /* ' ' */
            break;

        case 0x4E:
        case 0x6E:
            c = 0x30;   /* '0' */
            break;
        default:
            /* Keep default value of c */
            break;
    }
    (*((str))++) = (U8) (((c) & 0xff));
    (*((str))++) = (U8) (((c) >> 8));
    return str;
}


/*****************************************************************************
 * FUNCTION
 *  gui_parse_WCSS_string
 * DESCRIPTION
 *  Parse the WCSS format string, check for invalid format and create default string.
 * PARAMETERS
 *  s1                  [IN]        IN input format
 *  s2                  [IN]        OUT   text buffer
 *  s3                  [IN]        OUT   parsed format (typically cat115buffer)
 *  str_len             [IN]        IN length of dchar including '\0'
 *  reserve_data        [IN]        IN whether history is present
 *  for(?)              [OUT]       Invalid format
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_parse_WCSS_string(U8 *s1, U8 *s2, U8 *s3, S16 str_len, U8 reserve_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c, dst_ch;
    U8 input_type;
    U8 *original_s2 = s2;
    U8 *prev_s2;
    U8 *original_s3 = s3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(s1, c) while (!UI_STRING_END_OF_STRING_CHARACTER(c) && str_len > 1)
    {
        if (UI_check_WCSS_normal_character(c, &input_type))
        {
            *s3++ = input_type;
            if (reserve_data == 0)
            {
                s2 = UI_insert_WCSS_default_character(s2, c);
            }
            else
            {
                /* Default string might be shorter than required by s1 (input format) */
                prev_s2 = s2;
                UI_STRING_GET_NEXT_CHARACTER(s2, dst_ch);
                if (dst_ch == 0)
                {
                    reserve_data = 0;
                    s2 = UI_insert_WCSS_default_character(prev_s2, c);
                }
            }

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            str_len--;
        }
        else if (c == 0x5C) /* '\\' */
        {
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                goto parse_error;
            }

            *s3++ = 0xff;   /* Not editable character */
            if (reserve_data == 0)
            {
                UI_STRING_INSERT_CHARACTER(s2, c);
            }
            else
            {
                /* Default string might be shorter than required by s1 (input format) */
                prev_s2 = s2;
                UI_STRING_GET_NEXT_CHARACTER(s2, dst_ch);
                if (dst_ch == 0)
                {
                    reserve_data = 0;
                    s2 = prev_s2;
                    UI_STRING_INSERT_CHARACTER(s2, c);
                }
            }

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            str_len--;
        }
        else if (c == 0x2A) /* '*' */
        {
            S16 i = 0;

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (UI_STRING_END_OF_STRING_CHARACTER(c) || (!UI_check_WCSS_normal_character(c, &input_type)))
            {
                goto parse_error;
            }

            for (i = 0; i < str_len - 1; i++)
            {
                /* Setup format only. No default value for * format */
                /* s2 = UI_insert_WCSS_default_character(s2, c); */
                *s3++ = input_type | PIXTEL_UI_WCSS_STAR_INPUT;
            }

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                goto parse_error;
            }
            c = 0;
            break;
        }
        else if ((c >= 0x31) && (c <= 0x39))    /* '1' - '9' */
        {
            S16 n = c - 0x30;
            S16 i = 0;

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            while ((c >= 0x30) && (c <= 0x39))  /* '0' - '9' */
            {
                n *= 10;
                n += (c - 0x30);
                UI_STRING_GET_NEXT_CHARACTER(s1, c);
            }
            if (UI_STRING_END_OF_STRING_CHARACTER(c) || (!UI_check_WCSS_normal_character(c, &input_type)))
            {
                goto parse_error;
            }

            if (n > str_len - 1)
            {
                goto parse_error;
            }

            for (i = 0; i < n; i++)
            {
                *s3++ = input_type;
                if (reserve_data == 0)
                {
                    s2 = UI_insert_WCSS_default_character(s2, c);
                }
                else
                {
                    /* Default string might be shorter than required by s1 (input format) */
                    prev_s2 = s2;
                    UI_STRING_GET_NEXT_CHARACTER(s2, dst_ch);
                    if (dst_ch == 0)
                    {
                        reserve_data = 0;
                        s2 = UI_insert_WCSS_default_character(prev_s2, c);
                    }
                }
            }

            str_len -= n;
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
        }
        else
        {
            goto parse_error;
        }
    }

    /* Buffer size smaller than required by input-format */
    if (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        goto parse_error;
    }

    *s3 = '\0';
    if (reserve_data == 0)
    {
        *s2++ = 0;
        *s2 = 0;
    }
    return 0;

  parse_error:
    *original_s3 = '\0';
    if (reserve_data == 0)
    {
        *original_s2++ = 0;
        *original_s2 = 0;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  get_category_115_format_buffer_length
 * DESCRIPTION
 *  Get the exact length of WCSS input format buffer
 * PARAMETERS
 *  s1              [IN]        IN input format
 *  buffer_size     [IN]        IN maximum length of dchar including '\0'
 * RETURNS
 *  0        Variable length
 *  -1       Invalid format
 *  otherwise
 *****************************************************************************/
S32 get_category_115_format_buffer_length(U8 *s1, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    U8 input_type;
    S32 special_char = 0;
    S32 format_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(s1, c) while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        if (UI_check_WCSS_normal_character(c, &input_type))
        {
            format_length++;
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
        }
        else if (c == 0x5C) /* '\\' */
        {
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                return -1;
            }
            special_char++;
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
        }
        else if (c == 0x2A) /* '*' */
        {
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (UI_STRING_END_OF_STRING_CHARACTER(c) || (!UI_check_WCSS_normal_character(c, &input_type)))
            {
                return -1;
            }
            else
            {
                if (format_length + special_char <= buffer_size - 1)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
        }
        else if ((c >= 0x31) && (c <= 0x39))    /* '1' - '9' */
        {
            S16 n = c - 0x30;

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            while ((c >= 0x30) && (c <= 0x39))  /* '0' - '9' */
            {
                n *= 10;
                n += (c - 0x30);
                UI_STRING_GET_NEXT_CHARACTER(s1, c);
            }
            if (UI_STRING_END_OF_STRING_CHARACTER(c) || (!UI_check_WCSS_normal_character(c, &input_type)))
            {
                return -1;
            }

            format_length += n;

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
        }
        else
        {
            return -1;
        }
    }

    /* Note: we allow the case that format_length == 0. However, user cannot
       edit at all */
    if (format_length + special_char <= buffer_size - 1)
    {
        return (format_length + special_char);
    }
    else
    {
        return -1;
    }
}

#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

#ifdef __MMI_TOUCH_DIAL_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  gui_dialing_screen_map_number_key
 * DESCRIPTION
 *  map number from key pad to right key number for using
 * PARAMETERS
 *  input_number      [?]         number from key pad  
 * RETURNS
 *  right key number for using
 *****************************************************************************/
static S32 gui_dialing_screen_map_number_key(S32 input_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 output_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__)
    if (input_number <= 3)
    {
        output_number = input_number;
    }
	else if (input_number == 4)
	{
	    output_number = MMI_DIALING_KEY_STAR;
	}
	else if ((input_number >= 5) && (input_number <=7))
	{
	    output_number = input_number - 1;
	}
	else if (input_number == 8)
	{
	    output_number = MMI_DIALING_KEY_ZERO;
	}
	else if ((input_number >= 9) && (input_number <= 11))
	{
	    output_number = input_number - 2;
	}
	else if (input_number == 12)
	{
	    output_number = MMI_DIALING_KEY_HASH;
	}
#else /* __MMI_FTE_SUPPORT__ && __MMI_MAINLCD_320X240__ */
    output_number = input_number;
#endif /* __MMI_FTE_SUPPORT__ && __MMI_MAINLCD_320X240__ */
    return output_number;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialing_screen_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad      [?]         
 *  x                   [IN]        
 *  y                   [IN]        
 *  item_index          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialing_screen_translate_pen_position(dialing_keypad_struct *dialing_keypad, S32 x, S32 y, S32 *item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_height = 0, total_width = 0, func_key_width = 0;
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_height += dialing_keypad->keypad_y;
    total_width += dialing_keypad->keypad_x;
    *item_index = -1;   /* 053005 Calvin added for function key */

    for (i = 0; i < dialing_keypad->n_rows; i++)
    {
        total_height += dialing_keypad->key_height;
        if (total_height > y)
        {
            for (j = 0; j < dialing_keypad->n_column; j++)
            {
                total_width += dialing_keypad->key_width;
                if (total_width > x)
                {
                    *item_index = gui_dialing_screen_map_number_key((S32)(i * dialing_keypad->n_column + j + 1));
                    dialing_keypad->selected_key_x =
                        dialing_keypad->keypad_x + (dialing_keypad->key_width) * j +
                        (dialing_keypad->horizontal_gap) * j;
                    dialing_keypad->selected_key_y =
                        dialing_keypad->keypad_y + (dialing_keypad->key_height) * i +
                        (dialing_keypad->vertical_gap) * i;
                    dialing_keypad->key_type = *item_index;
                    break;
                }
                else
                {
                    total_width += dialing_keypad->horizontal_gap;
                    if (total_width > x)
                    {
                        *item_index = -1;
                        break;
                    }
                }

            }
            break;
        }
        else
        {
            total_height += dialing_keypad->vertical_gap;
            if (total_height > y)
            {
                *item_index = -1;
                break;
            }
        }
    }

    /* 053005 Calvin added for function key */
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    if (*item_index != -1)
    {
        return;
    }

    total_height = dialing_keypad->keypad_func_y;
    total_width = dialing_keypad->keypad_func_x;

    if (x < dialing_keypad->keypad_func_x || y < dialing_keypad->keypad_func_y) /* 110105 dialing handle Calvin added */
    {
        return;
    }

    for (i = 0; i < dialing_keypad->func_n_rows; i++)
    {
        total_height += dialing_keypad->func_key_height;
        if (total_height > y)
        {
            for (j = 0; j < dialing_keypad->func_n_column; j++)
            {
                func_key_width = dialing_keypad->func_key_width;
            #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
                if (i * dialing_keypad->func_n_column + j == 0)
                {
                     func_key_width = dialing_keypad->call_key_width;
                }
            #endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
                total_width += func_key_width;
                if (total_width > x)
                {
                    *item_index =
                        dialing_keypad->n_rows * dialing_keypad->n_column + i * dialing_keypad->func_n_column + j + 1;
                    if (j == 0)
                    {
                        dialing_keypad->selected_key_x = dialing_keypad->keypad_func_x;
                    }
                    else
                    {
                        dialing_keypad->selected_key_x = total_width - func_key_width;
                    }
                    dialing_keypad->selected_key_y =
                        dialing_keypad->keypad_func_y + (dialing_keypad->func_key_height) * i +
                        (dialing_keypad->func_vertical_gap) * i;
                    dialing_keypad->key_type = *item_index;
                    break;
                }
                else
                {
                    total_width += dialing_keypad->func_horizontal_gap;
                    if (total_width > x)
                    {
                        *item_index = -1;
                        return;
                    }
                }

            }
            break;
        }
        else
        {
            total_height += dialing_keypad->func_vertical_gap;
            if (total_height > y)
            {
                *item_index = -1;
                return;
            }
        }
    }
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    /* Calvin end */
}

/***********************************************************************
   __GDI_MEMORY_PROFILE_2__ is used to decide whether multilayer is on or off.
   if multilayer is enable, no buffer is used.
   we can use one layer for keypad bg image, and another for selected keys.
***********************************************************************/
#ifndef __GDI_MEMORY_PROFILE_2__
U8 key_buffer[(MMI_DIALING_KEY_WIDTH + 1) * (MMI_DIALING_KEY_HEIGHT + 1) * 2];
#endif 

#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && (defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__))
static U8 fun_key_emergency_call = 0;

/*****************************************************************************
 * FUNCTION
 *  gui_enable_dialing_emergency_func_key
 * DESCRIPTION
 *  enable the functionality of dialing emergency function keys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_dialing_emergency_func_key(MMI_BOOL IsEmergency)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fun_key_emergency_call = 0;
	if (IsEmergency)
	{
	    fun_key_emergency_call = 1;
	}
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialing_emergency_call_show_string
 * DESCRIPTION
 *  display the string "Emergency Call" at call button
 * PARAMETERS
 *  x1		[IN]
 *  y1		[IN]
 *  x2		[IN]
 *  y2		[IN]
 *  _text		[IN]		string
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialing_emergency_call_show_string(S32 x1, S32 y1, S32 x2, S32 y2, UI_string_type _text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 width, height;
	S32 clip_x1, clip_y1, clip_x2, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (_text == NULL)
	{
	    return ;
	}
	gui_set_font(&MMI_medium_font);
	gui_measure_string(_text, &width, &height);
	if (y2 - y1 > height)
	{
	    clip_y1 = y1 + ((y2 - y1 - height)>>1);
		clip_y2 = clip_y1 + height;
	}
	else
	{
	    clip_y1 = y1;
		clip_y2 = y2;
	}
	if (x2 - x1 > width)
	{
	    clip_x1 = x1 + ((x2 - x1 - width)>>1);
		clip_x2 = clip_x1 + width;
	}
	else
	{
	    clip_x1 = x1;
		clip_x2 = x2;
		width = x2 - x1 - 1;
	}
	gui_push_and_set_clip(clip_x1 - 1, clip_y1 - 1, clip_x2 + 1, clip_y2 + 1);
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    gui_set_text_color(*current_MMI_theme->CM_screen_text_color);
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
    gui_set_text_color(*current_MMI_theme->list_normal_text_color);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */
	gui_print_truncated_text(clip_x1, clip_y1, width, _text);
    gui_pop_clip();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_dialing_key_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad      [?]         
 *  item_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialing_key_select(dialing_keypad_struct *dialing_keypad, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 width, height;
    S32 key_width, key_height;
    MMI_ID_TYPE image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 053005 Calvin added for function key */
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    if (item_index >= MMI_DIALING_KEY_FUNC)
    {
        key_width = dialing_keypad->func_key_width;
        key_height = dialing_keypad->func_key_height;
	#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
        if (item_index == MMI_DIALING_KEY_FUNC)
        {
            key_width = dialing_keypad->call_key_width;
        }
	#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
    }
    else
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    {
        key_width = dialing_keypad->key_width;
        key_height = dialing_keypad->key_height;
    }
    /* Calvin end */

    x1 = dialing_keypad->selected_key_x;
    y1 = dialing_keypad->selected_key_y;
    /* 053005 Calvin added for function key */
    x2 = x1 + key_width - 1;
    y2 = y1 + key_height - 1;
    /* Calvin end */
#ifndef __GDI_MEMORY_PROFILE_2__
    dialing_keypad->selected_key_bitmap.buf_ptr = key_buffer;   /* (U8*)gui_malloc((MMI_DIALING_KEY_WIDTH+1)*(MMI_DIALING_KEY_HEIGHT+1)*2); */
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &dialing_keypad->selected_key_bitmap);
    gdi_layer_pop_clip();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

    if (0<= (item_index-1) && (item_index-1) < sizeof(dialing_key_image) / sizeof(dialing_key_image[0]))
    {
#if defined(__MMI_FTE_SUPPORT__)
        image_id = dialing_key_down_image[item_index - 1];
    #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && (defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__))
		if ((fun_key_emergency_call) && (image_id == IMG_DIALING_KEY_CALL))
		{
		    image_id = IMG_DIALING_KEY_EMERGENCY_CALL;
		}
	#endif 
#else /* defined(__MMI_FTE_SUPPORT__) */
        image_id = dialing_key_image[item_index - 1];
#endif /* defined(__MMI_FTE_SUPPORT__) */

#if defined(__MMI_SLIM_IMG_RES__) && defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_FTE_SUPPORT__)
        width = key_width;
        height = key_height;
#else /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ && !__MMI_FTE_SUPPORT__ */
        gui_measure_image(get_image(image_id), &width, &height);

		x1 = x1 + ((key_width - width) >> 1);
		y1 = y1 + ((key_height - height) >> 1);

#endif /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ && !__MMI_FTE_SUPPORT__ */


#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_FTE_SUPPORT__)
        {
            GDI_HANDLE act_layer;
            PU8 bg_img;

            /* set current layer as source layer */
            gdi_layer_get_active(&act_layer);
            gdi_push_and_set_alpha_blending_source_layer(act_layer);

#if defined(__MMI_FTE_SUPPORT__)
            //gdi_image_draw_resized(0, 0, UI_device_width, UI_device_height, get_image(IMG_DIALING_SCREEN));            
            gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);            
            bg_img = (item_index >= MMI_DIALING_KEY_FUNC) ? (get_image(dialing_key_func_button_down_image[item_index - MMI_DIALING_KEY_FUNC])) : (get_image(IMG_DIALING_KEY_BUTTON_DOWN));
		#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && (defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__))
			if ((fun_key_emergency_call) && (item_index == MMI_DIALING_KEY_FUNC))
			{
			    bg_img = get_image(IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_DOWN);
			}
		#endif
#else /* defined(__MMI_FTE_SUPPORT__) */
            gdi_image_draw(0, 0, current_MMI_theme->dialing_screen_bg_image);
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)
            bg_img = current_MMI_theme->dialing_screen_skey_down_image;
#else /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
            bg_img = (item_index >= MMI_DIALING_KEY_FUNC) ? (current_MMI_theme->dialing_screen_lkey_down_image) : (current_MMI_theme->dialing_screen_skey_down_image);
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
#endif /* defined(__MMI_FTE_SUPPORT__) */
        #if defined(__MMI_FTE_SUPPORT__)
		    if (item_index >= MMI_DIALING_KEY_FUNC)
		    {
		        gdi_image_draw_resized(dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, key_width, key_height, bg_img);
		    }
			else
			{
			    gdi_image_draw_resized(dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width, dialing_keypad->key_height, bg_img);
			}
		#else /* __MMI_FTE_SUPPORT__ */
            gdi_image_draw(x1, y1, bg_img);                         /* background */
		#endif /* __MMI_FTE_SUPPORT__ */
#if defined(__MMI_FTE_SUPPORT__)
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && (defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__))
            if ((fun_key_emergency_call) && (item_index == MMI_DIALING_KEY_FUNC))
            {
            #if defined(__MMI_MAINLCD_320X240__)
                gui_show_image(x1, y1, get_image(image_id));            /* foreground */
            #else /* __MMI_MAINLCD_320X240__ */
                gui_dialing_emergency_call_show_string((x2 - key_width + 1), (y2 - key_height + 1), x2, y2, (UI_string_type)L"Emergency Call");
            #endif /* __MMI_MAINLCD_320X240__ */
            }
			else
			{
			    gui_show_image(x1, y1, get_image(image_id));            /* foreground */
			}
		#else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && (defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)) */
            gui_show_image(x1, y1, get_image(image_id));            /* foreground */
		#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && (defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)) */
#else /* defined(__MMI_FTE_SUPPORT__) */
            gui_show_image(x1 + 1, y1 + 1, get_image(image_id));    /* foreground */
#endif /* defined(__MMI_FTE_SUPPORT__) */

            gdi_pop_and_restore_alpha_blending_source_layer();
        }
#else /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
#if defined(__MMI_SLIM_IMG_RES__) && defined(__MMI_MAINLCD_240X320__)
        {
            GDI_HANDLE act_layer;

			act_layer = dm_get_layer_handle(0);
			gdi_push_and_set_alpha_blending_source_layer(act_layer);
			gdi_image_draw_resized_id(x1, y1, key_width, key_height, image_id);
			gdi_pop_and_restore_alpha_blending_source_layer();
        }
#else /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ */
        gui_show_image(x1, y1, get_image(image_id));
#endif /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ */
#endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
    }

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialing_key_unselect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialing_key_unselect(dialing_keypad_struct *dialing_keypad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, x2, y1, y2;

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    S32 item_index = dialing_keypad->key_type;
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = dialing_keypad->selected_key_x;
    y1 = dialing_keypad->selected_key_y;

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    if (item_index >= MMI_DIALING_KEY_FUNC)
    {
        x2 = x1 + dialing_keypad->func_key_width - 1;
        y2 = y1 + dialing_keypad->func_key_height - 1;
	#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
		if (item_index == MMI_DIALING_KEY_FUNC)
		{
		    x2 = x1 + dialing_keypad->call_key_width - 1;
		}
	#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
    }
    else
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    {
        x2 = x1 + dialing_keypad->key_width - 1;
        y2 = y1 + dialing_keypad->key_height - 1;
    }

    gdi_layer_push_and_set_clip(x1, y1, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gdi_image_cache_bmp_draw(x1, y1, &dialing_keypad->selected_key_bitmap);
#endif 
    gdi_layer_pop_clip();

}

/* 110105 dialing deflect Calvin Start */
#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__

static U8 fun_key_phb = 0,  fun_key_call = 0;
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
static U8 fun_key_call_slave = 0;
#endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ && (!(__MMI_DYNAMIC_SIM_DYNAMIC_UI__ || __MMI_DIALER_DYNAMIC_CALL_UI__)) */

#ifdef __MMI_CAT_VIDEO_CALL__
static U8 fun_key_video = 0;
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_reset_dialing_func_key_flag
 * DESCRIPTION
 *  reset the functionality of dialing function keys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_reset_dialing_func_key_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fun_key_phb = fun_key_call = 1;
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    fun_key_call_slave = 1;
#endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ && (!(__MMI_DYNAMIC_SIM_DYNAMIC_UI__ || __MMI_DIALER_DYNAMIC_CALL_UI__)) */

#ifdef __MMI_CAT_VIDEO_CALL__
    fun_key_video = 1;
#endif

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
    fun_key_emergency_call = 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gui_show_dialing_key
 * DESCRIPTION
 *  Shows the phonebook icon on the dialing screen.
 * PARAMETERS
 *  key             [IN]        
 *  enableFlag      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dialing_key(gui_dialing_key key, BOOL enableFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, i, j, index;
    S32 item_index = 0;
    MMI_ID_TYPE item_icon;
    S32 width, height, func_key_width, func_key_height;
#if defined(__MMI_FTE_SUPPORT__)
    MMI_ID_TYPE img_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x2 = 0;
    switch (key)
    {
        case MMI_DIALING_KEY_PHB:
            if (enableFlag)
            {
                item_icon = IMG_DIALING_KEY_PHB;
                fun_key_phb = 1;
            }
            else
            {
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_FTE_SUPPORT__)
                item_icon = IMG_DIALING_KEY_PHB;
#else /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
                item_icon = IMG_DIALING_KEY_PHB_DISABLED;
#endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
                fun_key_phb = 0;
            }
            break;

#ifdef __MMI_CAT_VIDEO_CALL__
        case MMI_DIALING_KEY_VIDEO:
            if (enableFlag)
            {
                item_icon = IMG_DIALING_KEY_VIDEO;
                fun_key_video = 1;
            }
            else
            {
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)
                item_icon = IMG_DIALING_KEY_VIDEO;
#else /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
                item_icon = IMG_DIALING_KEY_VIDEO_DISABLED;
#endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
                fun_key_video = 0;
            }
            break;
#endif /* __MMI_CAT_VIDEO_CALL__ */    

        case MMI_DIALING_KEY_CALL:
            if (enableFlag)
            {
                item_icon = IMG_DIALING_KEY_CALL;
			#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
				if (fun_key_emergency_call)
				{
				    item_icon = IMG_DIALING_KEY_EMERGENCY_CALL;
				}
			#endif 
                fun_key_call = 1;
            }
            else
            {
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_FTE_SUPPORT__)
                item_icon = IMG_DIALING_KEY_CALL;
			#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
				if (fun_key_emergency_call)
				{
				    item_icon = IMG_DIALING_KEY_EMERGENCY_CALL;
				}
			#endif 
#else /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
                item_icon = IMG_DIALING_KEY_CALL_DISABLED;
			#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
				if (fun_key_emergency_call)
				{
				    item_icon = IMG_DIALING_KEY_EMERGENCY_CALL_DISABLED;
				}
			#endif
#endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
                fun_key_call = 0;
            }
            break;
            
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	\
	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
        case MMI_DIALING_KEY_CALL_SLAVE:
            if (enableFlag)
            {
                item_icon = IMG_DIALING_KEY_CALL_SLAVE;
                fun_key_call_slave = 1;
            }
            else
            {
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_FTE_SUPPORT__)
                item_icon = IMG_DIALING_KEY_CALL_SLAVE;
#else /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
                item_icon = IMG_DIALING_KEY_CALL_SLAVE_DISABLED;
#endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
                fun_key_call_slave = 0;
            }
            break;
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
        default:
            return;
    }

    item_index = key - (MMI_DIALING_KEY_FUNC);
    
    for (i = 0; i < MMI_DIALING_KEYPAD_FUNC_ROWS; i++)
    {
        func_key_height = MMI_DIALING_FUNC_KEY_HEIGHT;
        y1 = MMI_DIALING_KEYPAD_FUNC_Y + (func_key_height + MMI_DIALING_FUNC_KEY_VERTICAL_GAP)*i;
        y2 = y1 + func_key_height - 1;
        for (j = 0; j < MMI_DIALING_KEYPAD_FUNC_COLOMNS; j++)
        {
            index = i*MMI_DIALING_KEYPAD_FUNC_COLOMNS + j;
            /* calculate position */
            func_key_width = MMI_DIALING_FUNC_KEY_WIDTH;
        #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
            if (index == 0)
            {
            #if defined(__MMI_CAT_VIDEO_CALL__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
                func_key_width = MMI_DIALING_FUNC_KEY_WIDTH;
            #else /* __MMI_CAT_VIDEO_CALL__ */
                func_key_width = MMI_DIALING_FUNC_KEY_WIDTH + MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP + MMI_DIALING_FUNC_KEY_WIDTH;
            #endif /* __MMI_CAT_VIDEO_CALL__ */
            }
        #endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
            if (j == 0)
            {
                x1 = MMI_DIALING_KEYPAD_FUNC_X;
            }
            else
            {
                x1 = x2 + MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP + 1;
            }
            x2 = x1 + func_key_width - 1;
            if (index == item_index)
            {
                break;
            }
		}
        if (index == item_index)
        {
            break;
        }
    }
	
    gdi_layer_push_and_set_clip(x1, y1, x2, y2);

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_FTE_SUPPORT__)
    if (!enableFlag)
    {        
        GDI_HANDLE act_layer;

        /* set current layer as source layer */
        gdi_layer_get_active(&act_layer);
        gdi_push_and_set_alpha_blending_source_layer(act_layer);

#if defined(__MMI_FTE_SUPPORT__)
        //gdi_image_draw_resized(0, 0, UI_device_width, UI_device_height, get_image(IMG_DIALING_SCREEN));
        gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);
		img_id = dialing_key_func_button_disable_image[item_index];
	#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
		if ((fun_key_emergency_call) && (item_index == 0))
		{
		    img_id = IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_DISABLED;
		}
	#endif
	    gdi_image_draw_resized(x1, y1, 
			(x2 - x1), (y2 - y1 + 1), get_image(img_id));
        gui_measure_image(get_image(item_icon), &width, &height); 
        gui_draw_image_with_alpha_transparent( (U8*) get_image(item_icon), (x1 + ((func_key_width - width) >> 1)), (y1 + ((func_key_height- height) >> 1)), 125);
#else /* defined(__MMI_FTE_SUPPORT__) */
        gdi_image_draw(0, 0, current_MMI_theme->dialing_screen_bg_image);
        gdi_image_draw(x1, y1, current_MMI_theme->dialing_screen_lkey_disable_image);
        
		gui_measure_image(get_image(item_icon), &width, &height); 
        gdi_image_draw((x1 + ((func_key_width - width) >> 1)), (y1 + ((func_key_height- height) >> 1)), (U8*) get_image(item_icon));
#endif /* defined(__MMI_FTE_SUPPORT__) */

        gdi_pop_and_restore_alpha_blending_source_layer();
    }
#else /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
	gui_measure_image(get_image(item_icon), &width, &height);
    gdi_image_draw((x1 + ((func_key_width - width) >> 1)), (y1 + ((func_key_height- height) >> 1)), (U8*) get_image(item_icon));
#endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */

    gdi_layer_pop_clip();
}
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 
/* 110105 dialing deflect Calvin Start */

#if (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__) || defined(__MMI_FTE_SUPPORT__)) && defined(__MMI_TOUCH_DIAL_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  gui_show_dialing_keypad
 * DESCRIPTION
 *  Shows dialing keypad
 * PARAMETERS
 *  dialing_keypad  [IN]    dialing keypad struct
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dialing_keypad(dialing_keypad_struct *dialing_keypad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, item_index, x1, y1, x2, y2;
    GDI_HANDLE act_layer;
    MMI_ID_TYPE img_id;
    S32 width, height;
#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    S32 key_width, key_height, index;
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x2 = 0; x1 = 0;
    /* set current layer as source layer */
    gdi_layer_get_active(&act_layer);
    gdi_push_and_set_alpha_blending_source_layer(act_layer);

    /* show 0~9, *, # */
    for (i = 0 ; i < dialing_keypad->n_rows ; i++)
    {
        y1 = dialing_keypad->keypad_y + (dialing_keypad->key_height + dialing_keypad->vertical_gap)*i;
        y2 = y1+ dialing_keypad->key_height - 1;
        for (j = 0 ; j < dialing_keypad->n_column ; j++)
        {
            item_index = i*dialing_keypad->n_column + j;

            /* calculate position */
            x1 = dialing_keypad->keypad_x + (dialing_keypad->key_width + dialing_keypad->horizontal_gap)*j;
            x2 = x1 + dialing_keypad->key_width - 1;

            /* show each key */
            gdi_layer_push_and_set_clip(x1, y1, x2, y2);

#if defined(__MMI_FTE_SUPPORT__)
            gdi_image_draw_resized(x1, y1, 
                dialing_keypad->key_width, dialing_keypad->key_height,
                get_image(IMG_DIALING_KEY_BUTTON_UP));
            gui_measure_image(get_image(dialing_key_image[item_index]), &width, &height);           
            gui_show_image(x1 + ((dialing_keypad->key_width - width) >> 1), 
                y1 + ((dialing_keypad->key_height - height) >> 1), 
                get_image(dialing_key_image[item_index]));           /* foreground */
#else /* defined(__MMI_FTE_SUPPORT__) */
            gdi_image_draw(x1, y1, current_MMI_theme->dialing_screen_skey_up_image);    /* background */
            gui_show_image(x1, y1, get_image(dialing_key_image[item_index]));           /* foreground */
#endif /* defined(__MMI_FTE_SUPPORT__) */


            gdi_layer_pop_clip();
        }
    }

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    /* show function keys */
    for (i = 0 ; i < dialing_keypad->func_n_rows ; i++)
    {
        key_height = dialing_keypad->func_key_height;
		y1 = dialing_keypad->keypad_func_y + (key_height + dialing_keypad->func_vertical_gap)*i;
		y2 = y1 + key_height - 1;
        for (j = 0 ; j < dialing_keypad->func_n_column ; j++)
        {
            index = i*dialing_keypad->func_n_column + j;
            item_index = dialing_keypad->n_rows * dialing_keypad->n_column + index;
            
            /* calculate position */
            key_width = dialing_keypad->func_key_width;
        #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
            if (index == 0)
            {
                key_width = dialing_keypad->call_key_width;
            }
        #endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
            if (j == 0)
            {
                x1 = dialing_keypad->keypad_func_x;
            }
            else
            {
                x1 = x2 + dialing_keypad->func_horizontal_gap + 1;
            }
            x2 = x1 + key_width - 1;

            /* show each key */
            gdi_layer_push_and_set_clip(x1, y1, x2, y2);

#if defined(__MMI_FTE_SUPPORT__)
			img_id = dialing_key_func_button_image[index];
		#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
			if ((fun_key_emergency_call) && (index == 0))
			{
			    img_id = IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_UP;
			}
		#endif
            gdi_image_draw_resized(x1, y1, key_width, key_height, get_image(img_id));
#else /* defined(__MMI_FTE_SUPPORT__) */
#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)
            gdi_image_draw(x1, y1, current_MMI_theme->dialing_screen_skey_up_image);    /* background for Dual SIM */
#else /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
            gdi_image_draw(x1, y1, current_MMI_theme->dialing_screen_lkey_up_image);    /* Function key background for Single SIM */
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
#endif /* defined(__MMI_FTE_SUPPORT__) */

		#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__))
			if ((fun_key_emergency_call) && (index == 0))
			{
            #if defined(__MMI_MAINLCD_320X240__)
                img_id = IMG_DIALING_KEY_EMERGENCY_CALL;
                gui_measure_image(get_image(img_id), &width, &height);
                gui_show_image((x1 + ((key_width - width) >> 1)), (y1 + ((key_height - height) >> 1)), get_image(img_id));
            #else /* __MMI_MAINLCD_320X240__ */
                gui_dialing_emergency_call_show_string(x1, y1, x2, y2, (UI_string_type)L"Emergency Call");
            #endif /* __MMI_MAINLCD_320X240__ */
			}
			else
			{
			    img_id = dialing_key_image[item_index];
				gui_measure_image(get_image(img_id), &width, &height);
				gui_show_image((x1 + ((key_width - width) >> 1)), (y1 + ((key_height - height) >> 1)), get_image(img_id));
			}
		#else
		    img_id = dialing_key_image[item_index];
		    gui_measure_image(get_image(img_id), &width, &height);
		    gui_show_image((x1 + ((key_width - width) >> 1)), (y1 + ((key_height - height) >> 1)), get_image(img_id));
		#endif

            gdi_layer_pop_clip();
        }
    }
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */

    gdi_pop_and_restore_alpha_blending_source_layer();
}
#endif /* (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)) && defined(__MMI_TOUCH_DIAL_SCREEN__) */
/*****************************************************************************
 * FUNCTION
 *  gui_dialing_screen_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad          [?]         
 *  x                       [IN]        
 *  y                       [IN]        
 *  pen_event               [IN]        
 *  menu_event              [?]         
 *  dialing_key_param       [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_dialing_screen_translate_pen_event(
        dialing_keypad_struct *dialing_keypad,
        S32 x,
        S32 y,
        mmi_pen_event_type_enum pen_event,
        gui_dialing_key_pen_enum *menu_event,
        gui_pen_event_param_struct *dialing_key_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    S32 item_index;
    S32 x1, y1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = TRUE;
    *menu_event = GUI_DIALING_PEN_NONE;

    /* 053005 Calvin */
#if defined (__MMI_MAINLCD_240X320__) && defined (__MMI_TOUCH_DIAL_SCREEN__)
    x1 = dialing_keypad->keypad_x;
    y1 = dialing_keypad->keypad_y;
#else /* defined (__MMI_MAINLCD_240X320__) && defined (__MMI_TOUCH_DIAL_SCREEN__) */ 
    x1 = dialing_keypad->keypad_x;
    y1 = dialing_keypad->keypad_y;
#endif /* defined (__MMI_MAINLCD_240X320__) && defined (__MMI_TOUCH_DIAL_SCREEN__) */ 
    /* Calvin end */

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, x1, y1, dialing_keypad->keypad_width, dialing_keypad->keypad_height))
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                if (item_index == -1)   /* No key is selected */
                {
                    ret = FALSE;
                }
        #ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__                
                if (item_index == MMI_DIALING_KEY_PHB 
                    && fun_key_phb == 0)
                {
                    ret = FALSE; /* Disable Phonebook function key */
                }
#ifdef __MMI_CAT_VIDEO_CALL__
                else if (item_index == MMI_DIALING_KEY_VIDEO 
                    && fun_key_video == 0)
                {
                    ret = FALSE; /* Disable video function key */
                }            
#endif /* __MMI_CAT_VIDEO_CALL__ */

        #endif
                /* PMT HIMANSHU START 20050825 */
        #if !defined(__MMI_DUAL_SIM_MASTER__)
            #ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
                else if (item_index == MMI_DIALING_KEY_CALL 
                    && fun_key_call == 0)
                {
                    ret = FALSE;
                }
            #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 
        #else   /* __MMI_DUAL_SIM_MASTER__ */
            #ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
                else if (item_index == MMI_DIALING_KEY_CALL 
                    && fun_key_call == 0)
                {
                    ret = FALSE;
                }
			#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	\
				&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
                else if (item_index == MMI_DIALING_KEY_CALL_SLAVE 
                    && fun_key_call_slave == 0)
                {
                    ret = FALSE;
                }
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
            #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 
        #endif  /* __MERCURY_MASTER__ */
                /* PMT HIMANSHU END 20050825 */
                else
                {
                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN_VIBRATE);
                    gui_dialing_key_select(dialing_keypad, item_index);
                }
            }
            else
            {
                ret = FALSE;
            }
            break;
        case MMI_PEN_EVENT_UP:
            if (PEN_CHECK_BOUND
                (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                 dialing_keypad->key_height)
                 #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) || defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
				 || pen_check_func_key_bound_ext(x, y, dialing_keypad)
           #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                 )
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                gui_dialing_key_unselect(dialing_keypad);
                if (item_index > MMI_DIALING_KEY_START && item_index < MMI_DIALING_KEY_STAR)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, item_index);
                }
                else
                {
                    switch (item_index)
                    {
                        case MMI_DIALING_KEY_STAR:
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, KEY_STAR);
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_STAR;
                            break;
                        case MMI_DIALING_KEY_ZERO:
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, 0);
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                            break;
                        case MMI_DIALING_KEY_HASH:
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, KEY_POUND);
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_HASH;
                            break;
                            /* 071005 Calvin added for function key */
                    #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
                        case MMI_DIALING_KEY_PHB:
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_PHB;
                            break;
#ifdef __MMI_CAT_VIDEO_CALL__                            
                        case MMI_DIALING_KEY_VIDEO:
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_VIDEO;
                            break;                            
#endif /* __MMI_CAT_VIDEO_CALL__ */    

                        case MMI_DIALING_KEY_CALL:
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_CALL;
                            break;
			 #if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)	\
			 	&& (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
                        case MMI_DIALING_KEY_CALL_SLAVE:
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_CALL_SLAVE;
                            break;
             #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                    #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
                            /* Calvin end */
                    }
                }
            }
            else
            {
                gui_dialing_key_unselect(dialing_keypad);
                ret = TRUE;
            }
            break;
        case MMI_PEN_EVENT_MOVE:
            if (!PEN_CHECK_BOUND
                (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                 dialing_keypad->key_height)
           #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) || defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                 &&!pen_check_func_key_bound_ext(x, y, dialing_keypad)
           #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ || __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
          )
            {
                if (dialing_keypad->key_type == MMI_DIALING_KEY_STAR)
                {
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, KEY_STAR);
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_STAR;
                }
                else
                {
                    *menu_event = GUI_DIALING_KEYPAD_HIGHLIGHT_CHANGED;
                }

            }
            else if (PEN_CHECK_BOUND
                     (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                      dialing_keypad->key_height)
                     #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) || defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                    ||pen_check_func_key_bound_ext(x, y, dialing_keypad)
            #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ || __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
           )
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                gui_dialing_key_select(dialing_keypad, item_index);
                //*menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                //GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param,item_index );
            }
            break;
        case MMI_PEN_EVENT_LONG_TAP:
            if (PEN_CHECK_BOUND
                (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                 dialing_keypad->key_height)
                 #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) || defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                 ||pen_check_func_key_bound_ext(x, y, dialing_keypad)
           #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ || __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                 )
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                /* start vijay 20050624vijay...chngaes done for activating silent mode */
                if (item_index >= MMI_DIALING_KEY_START && item_index <= MMI_DIALING_KEY_STAR)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, item_index);
                }
                else if (item_index == MMI_DIALING_KEY_HASH)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_HASH;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, KEY_POUND);
                }
                /* end vijay */
            }
            break;
        case MMI_PEN_EVENT_REPEAT:
            if (PEN_CHECK_BOUND
                (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                 dialing_keypad->key_height)
                 #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) || defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                 ||pen_check_func_key_bound_ext(x, y, dialing_keypad)
           #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ || __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                 )
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                if (item_index > MMI_DIALING_KEY_START && item_index < MMI_DIALING_KEY_STAR)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, item_index);
                }
                else if (item_index == MMI_DIALING_KEY_STAR)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_STAR;
                }
                else if (item_index == MMI_DIALING_KEY_ZERO)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, 0);
                }
                else if (item_index == MMI_DIALING_KEY_HASH)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_HASH;
                }
            }
            else
            {
                ret = FALSE;
            }
            break;
    }
    return ret;
}
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ /* __MMI_TOUCH_SCREEN__ */
/* end vijay */
#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  pen_event                       [IN]        
 *  x                               [IN]        
 *  y                               [IN]        
 *  single_line_input_box_event     [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_single_line_input_box_translate_pen_event(
        single_line_input_box *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_single_line_input_box_pen_enum *single_line_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    {
        mmi_pen_point_struct point;
        
        point.x = x;
        point.y = y;
        
        if (b->state == GUI_INPUT_BOX_STATE_SELECTING_TEXT)
        {
            if (gui_input_box_ssp_get_state() != GUI_INPUT_BOX_SSP_STATE_UNFOCUS)
            {
                gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
            }
        }
        else
        {
            if (gui_input_box_ssp_get_userdata() != (void*)b)
            {
                gui_input_box_ssp_set_client_callback(
                    gui_singleline_ssp_update_client, 
                    gui_singleline_ssp_get_client_info, 
                    b);
            }
            
            gui_input_box_ssp_pen_translate(point, pen_event);
        }
    }
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
            {
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                *single_line_input_box_event = GUI_SINGLE_LINE_INPUT_BOX_PEN_TEXT_DOWN;
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;
        case MMI_PEN_EVENT_UP:
            if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
            {
                *single_line_input_box_event = GUI_SINGLE_LINE_INPUT_BOX_PEN_TEXT_UP;
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;
        case MMI_PEN_EVENT_MOVE:
        case MMI_PEN_EVENT_LONG_TAP:
        case MMI_PEN_EVENT_REPEAT:
        case MMI_PEN_EVENT_ABORT:
            if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
            {
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;
    }
    return ret;
}

static multi_line_input_box *gui_pen_scroll_multi_line_input_box = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_scroll_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  offset_y                        [IN]        
 *  multi_line_input_box_event      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_multi_line_input_box_scroll_by_pen(
                multi_line_input_box *b,
                S32 offset_y,
                gui_multi_line_input_box_pen_enum *multi_line_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* int move_gap = b->text_offset_y + offset_y; */
    int line_height;
    S32 x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    b->text_offset_y = -offset_y;
    /* W05.35 For Scroll Issue with Header Height */
    /* W06.02 Fix Cursor Display Issue */
    /* W06.26 Remove compile warnings and review cursor position issue */
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
    {
        StopTimer(BLINKING_CURSOR);
    }

    if (b->cursor_fixed_x == -1)
        b->cursor_fixed_x = b->cursor_x;
    x = b->cursor_fixed_x;

    if (b->max_line_height)
    {
        line_height = b->max_line_height;
    }
    else
    {
        line_height = b->min_line_height;
    }

    if ((b->cursor_y) < -(b->text_offset_y))
    {
        if (-b->text_offset_y + b->edit_height + b->min_line_height >= b->text_height)
            gui_show_multi_line_input_box_ext(b, x, b->y + b->edit_height - 1);
        else
            gui_show_multi_line_input_box_ext(b, x, b->y + b->edit_height - line_height);
    }
    else if((b->cursor_y + line_height) > b->edit_height - b->text_offset_y)
    {
        if (b->text_offset_y == 0)
            gui_show_multi_line_input_box_ext(b, x, b->y + b->header_height + b->text_y + 1);
        else
        {
            if (b->header_height > 0
                && b->text_offset_y + b->header_height + b->text_y + 1 < b->height
                && b->text_offset_y + b->header_height + b->text_y + 1 > 0)
                gui_show_multi_line_input_box_ext(b, x, b->y + b->text_offset_y + b->header_height + b->text_y + 1);
            else
                gui_show_multi_line_input_box_ext(b, x, b->y + line_height);
        }
    }
    /*
    if ((b->cursor_y) < -(b->text_offset_y) ||
        (b->cursor_y + line_height) > b->edit_height - b->text_offset_y)
    {
        S32 new_UI_cursor_y1 = UI_cursor_y1;
        if (move_gap > 0)
        {
            new_UI_cursor_y1 = UI_cursor_y1 + line_height;
        }
        if ((new_UI_cursor_y1 + line_height) > (b->y + b->edit_height))
        {
            new_UI_cursor_y1 = b->y + b->edit_height - line_height;
        }
        else if (new_UI_cursor_y1 < b->y)
        {
            new_UI_cursor_y1 = b->y  + line_height;
        }
        gui_show_multi_line_input_box_ext(b, x, new_UI_cursor_y1);
    }
    */

    /* Reset cursor_fixed_x to x because it will be changed in gui_show_EMS_input_box_ext */
    b->cursor_fixed_x = x;
    if (b->height >= (2 * line_height))
        b->text_offset_y = -offset_y;

    b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    gui_show_multi_line_input_box(b);

    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_scroll_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_scroll_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = gui_pen_scroll_multi_line_input_box;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_multi_line_input_box = NULL;

    if (!b)
    {
        return;
    }

    gui_multi_line_input_box_scroll_by_pen(b, b->pen_scroll_after_delay, &multi_line_input_box_event);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_abort_scroll_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_multi_line_input_box_abort_scroll_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_multi_line_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_start_scroll_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_multi_line_input_box_start_scroll_timer(multi_line_input_box *b, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* assert that no two input box at the same time */
    MMI_DBG_ASSERT(!gui_pen_scroll_multi_line_input_box || gui_pen_scroll_multi_line_input_box == b);

    b->pen_scroll_after_delay = value;
    gui_pen_scroll_multi_line_input_box = b;

    gui_cancel_timer(gui_multi_line_input_box_scroll_timer_hdlr);
    gui_start_timer(b->pen_scroll_delay_time, gui_multi_line_input_box_scroll_timer_hdlr);

    gui_add_cleanup_hook(gui_multi_line_input_box_abort_scroll_timer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_set_pen_scroll_delay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  delay_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_set_pen_scroll_delay(multi_line_input_box *b, S32 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(delay_time < (S32) 0x0000FFFF);
    b->pen_scroll_delay_time = (S16) delay_time;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  pen_event                       [IN]        
 *  x                               [IN]        
 *  y                               [IN]        
 *  multi_line_input_box_event      [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_multi_line_input_box_translate_pen_event(
        multi_line_input_box *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_multi_line_input_box_pen_enum *multi_line_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    gui_multi_line_input_box_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    BOOL scroll_bar_active = MMI_TRUE;
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    mmi_pen_point_struct point;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.04 Fix UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR issue in Touch Screen */
#ifdef __MMI_EDITOR_SSP_SUPPORT__
    point.x = x;
    point.y = y;
#endif

#ifdef __MMI_EDITOR_SSP_SUPPORT__
    if (b->state == GUI_INPUT_BOX_STATE_SELECTING_TEXT)
    {
        if (gui_input_box_ssp_get_state() != GUI_INPUT_BOX_SSP_STATE_UNFOCUS)
        {
            gui_input_box_ssp_pen_translate(point, MMI_PEN_EVENT_ABORT);
        }
    }
    else
    {
        if (!(pen_event == MMI_PEN_EVENT_DOWN 
            && !PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
            && !(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND 
                 && b->hide_callback == NULL))
        { 
            if (gui_input_box_ssp_get_userdata() != (void*)b)
            {
                gui_input_box_ssp_set_client_callback(
                    gui_multiline_ssp_update_client, 
                    gui_multiline_ssp_get_client_info, 
                    b);
            }
            
            gui_input_box_ssp_pen_translate(point, pen_event);
        }
    }
#endif /* __MMI_EDITOR_SSP_SUPPORT__ */

#ifdef __MMI_FTE_EDITOR_SCROLLBAR_STYLE__
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || (b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR))
#else
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (b->vbar.scale >= b->vbar.range)))
#endif
    {
        scroll_bar_active = FALSE;
    }
    else
    {
        scroll_bar_active = TRUE;
    }

    pen_state = &b->pen_state;
    ret = MMI_TRUE;

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__) || defined(__UI_LINEBASE_IN_MULTILINE_EDITOR__)/**/
    if (((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE) ||
         (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CONTENT_REQUEST_MODE))
        && PEN_CHECK_BOUND(x, y, b->vbar.x, b->vbar.y, b->vbar.width,b->height))
    {
        ret = MMI_TRUE;
        if (pen_event != MMI_PEN_EVENT_UP)
        {
            pen_state->pen_on_scroll_bar = 1;
        }
        *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR;
        return ret;
    }
#endif /*__UI_PAGING_IN_MULTILINE_EDITOR__  __UI_LINEBASE_IN_MULTILINE_EDITOR__ */ /**/  

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_scroll_bar)
    {
        if (scroll_bar_active)
        {
            gui_vertical_scrollbar_translate_pen_event(&b->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
            if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
            {
                if (b->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
                {
                    gui_multi_line_input_box_start_scroll_timer(b, scrollbar_param._u.i);
                }
                else
                {
                    gui_multi_line_input_box_scroll_by_pen(b, scrollbar_param._u.i, multi_line_input_box_event);
                }
            }

            if (PEN_CHECK_BOUND(x, y, b->vbar.x, b->vbar.y, b->vbar.width,b->height))
            {
                *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR;
            }
        }
        else
        {
            ret = MMI_FALSE;    
        }   
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
                {
                    /* When the text is empty, max_line_height equals zero */
                    if (b->max_line_height)
                    {
                        gui_vertical_scrollbar_set_minimum_pen_offset(&b->vbar, b->max_line_height);
                    }
                    else
                    {
                        gui_vertical_scrollbar_set_minimum_pen_offset(&b->vbar, b->min_line_height);
                    }

                    pen_state->pen_on_scroll_bar = 0;
                    if (scroll_bar_active /* !(b->flags&UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR) */  &&
                        gui_vertical_scrollbar_translate_pen_event(
                            &b->vbar,
                            MMI_PEN_EVENT_DOWN,
                            x,
                            y,
                            &scrollbar_event,
                            &scrollbar_param))
                    {
                        pen_state->pen_on_scroll_bar = 1;

                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            if (b->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
                            {
                                gui_multi_line_input_box_start_scroll_timer(b, scrollbar_param._u.i);
                            }
                            else
                            {
                                gui_multi_line_input_box_scroll_by_pen(
                                    b,
                                    scrollbar_param._u.i,
                                    multi_line_input_box_event);
                            }
                        }
                        *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR;
                    }
                    else
                    {
                        /* Only play feedback when in editor mode or view mode with scroll bar */
                        if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) || (b->vbar.scale < b->vbar.range))
                        {
                            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                        }
                        *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_DOWN;
                        
                        if (b->pen_down_control_area_callback != NULL)
                        {
                            if (b->header_height > 0 && b->y + b->text_offset_y + b->header_height >= y)
                            {
                                *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                                b->pen_down_control_area_callback(0, x, y - (b->y + b->text_offset_y));
                            }
                            else if(b->footer_height > 0 &&b->y + b->text_offset_y + b->text_height - b->footer_height < y)
                            {
                                *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                                b->pen_down_control_area_callback(1, x, y - (b->y + b->text_offset_y + b->text_height - b->footer_height));
                            }
                            else if ((b->x + b->left_width < x) && (b->x + b->width - b->right_width >= x))
                            {
                                b->pen_down_control_area_callback(2, x, y - (b->y + b->text_offset_y) - b->header_height);
                            }
                        }
                        else if (b->pen_control_area_callback != NULL)
                        {
                            if (b->header_height > 0 && b->y + b->text_offset_y + b->header_height >= y)
                            {
                                *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                                b->pen_control_area_callback(GUI_INPUT_BOX_AREA_HEADER, MMI_PEN_EVENT_DOWN, x, y - (b->y + b->text_offset_y));
                            }
                            else if(b->footer_height > 0 &&b->y + b->text_offset_y + b->text_height - b->footer_height < y)
                            {
                                if (y - (b->y + b->text_offset_y + b->text_height - b->footer_height) < b->footer_height)
                                {
                                    *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                                    b->pen_control_area_callback(GUI_INPUT_BOX_AREA_FOOTER, MMI_PEN_EVENT_DOWN, x, y - (b->y + b->text_offset_y + b->text_height - b->footer_height));
                                }
                            }
                            else if ((b->x + b->left_width < x) && (b->x + b->width - b->right_width >= x))
                            {
                                b->pen_control_area_callback(GUI_INPUT_BOX_AREA_TEXT, MMI_PEN_EVENT_DOWN, x, y - (b->y + b->text_offset_y) - b->header_height);
                            }
                        }
                        else
                        {
                            if ((b->header_height > 0 && b->y + b->text_offset_y + b->header_height >= y) ||
                                (b->footer_height > 0 &&b->y + b->text_offset_y + b->text_height - b->footer_height < y))
                            {
                                *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                            }
                        }
                    }
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_UP:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height) &&
                    (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) || (b->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)))
                {
                    *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_UP;

                    if (b->pen_down_control_area_callback != NULL)
                    {
                        if (b->header_height > 0 && b->y + b->text_offset_y + b->header_height >= y)
                        {
                            *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                        }
                        else if(b->footer_height > 0 &&b->y + b->text_offset_y + b->text_height - b->footer_height < y)
                        {
                            *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                        }
                    }
                    else if (b->pen_control_area_callback != NULL)
                    {
                        if (b->header_height > 0 && b->y + b->text_offset_y + b->header_height >= y)
                        {
                            *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                            b->pen_control_area_callback(GUI_INPUT_BOX_AREA_HEADER, MMI_PEN_EVENT_UP, x, y - (b->y + b->text_offset_y));
                        }
                        else if(b->footer_height > 0 &&b->y + b->text_offset_y + b->text_height - b->footer_height < y)
                        {
                            if (y - (b->y + b->text_offset_y + b->text_height - b->footer_height) < b->footer_height)
                            {
                                *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_CONTROL_AREA;
                                b->pen_control_area_callback(GUI_INPUT_BOX_AREA_FOOTER, MMI_PEN_EVENT_UP, x, y - (b->y + b->text_offset_y + b->text_height - b->footer_height));
                            }
                        }
                        else if ((b->x + b->left_width < x) && (b->x + b->width - b->right_width >= x))
                        {
                            b->pen_control_area_callback(GUI_INPUT_BOX_AREA_TEXT, MMI_PEN_EVENT_UP, x, y - (b->y + b->text_offset_y) - b->header_height);
                        }
                    }
                }
                else
                {
                    if (b->pen_control_area_callback)
                    {
                        b->pen_control_area_callback(GUI_INPUT_BOX_AREA_END, MMI_PEN_EVENT_UP, 0, 0);
                    }
                    ret = MMI_FALSE;
                }
                break;
            case MMI_PEN_EVENT_LONG_TAP:
                if ((b->header_height > 0 && b->y + b->text_offset_y + b->header_height >= y) ||
                    (b->footer_height > 0 &&b->y + b->text_offset_y + b->text_height - b->footer_height < y))
                {
                    ret = MMI_FALSE;
                }
                else if ((b->x + b->left_width < x) && (b->x + b->width - b->right_width >= x))
                {
                    if (b->pen_control_area_callback != NULL)
                    {
                        b->pen_control_area_callback(GUI_INPUT_BOX_AREA_TEXT, MMI_PEN_EVENT_LONG_TAP, x, y - (b->y + b->text_offset_y) - b->header_height);
                    }
                }
            case MMI_PEN_EVENT_MOVE:
            case MMI_PEN_EVENT_REPEAT:
            case MMI_PEN_EVENT_ABORT:
                if (PEN_CHECK_BOUND(x, y, b->vbar.x, b->vbar.y, b->vbar.width,b->height) && scroll_bar_active)
                {
                    *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR;
                }
                else if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
                {
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;
        }
    }

    if (pen_event == MMI_PEN_EVENT_UP
        || pen_event == MMI_PEN_EVENT_ABORT)
    {
        b->pen_state.pen_on_scroll_bar = 0;
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_get_remaining_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 gui_multi_line_input_box_get_remaining_length(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n, max_n;
    U32 temp_0x81 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = (b->text_length >> 1) - 1;
    max_n = (b->available_length >> 1) - 1;
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) && (b->UCS2_count == 0))
    {
        n += b->GSM_ext_count;
    }
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) && (b->text[0] == '+'))
    {
        n--;
        max_n--;
    }
    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
    {
        temp_0x81 = srv_phb_convert_to_0x81((U16*) b->text, MMI_FALSE);
        if (0 != temp_0x81)
        {
            max_n = (b->allocated_length >> 1) - 4;
            n = temp_0x81 - 3;
        }
    }
    return max_n - n;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_get_remaining_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int gui_single_line_input_box_get_remaining_length(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n, max_n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = (b->text_length >> 1) - 1;
    max_n = (b->available_length >> 1) - 1;
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) && (b->UCS2_count == 0))
    {
        n += b->GSM_ext_count;
    }
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) && (b->text[0] == '+'))
    {
        n--;
        max_n--;
    }
    return max_n - n;
}

void gui_multi_line_input_box_register_infobar_callback(
                        multi_line_input_box *b,
                        void(*redraw_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                        void(*reminder_char_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                        U32 height)
{
    if(height == 0)   height = INFORMATION_BAR_HEIGHT;
    
    b->infobar_redraw_callback = redraw_callback;
    b->infobar_reminder_char_callback = reminder_char_callback;
    wgui_inputbox_information_bar_height = height;
}

void gui_multi_line_input_box_register_change_event_handler(
                        multi_line_input_box *b,
                        MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C))
{
    b->change_event_handler = handler;
}

void gui_single_line_input_box_register_change_event_handler(
                        single_line_input_box *b,
                        MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C))
{
    b->change_event_handler = handler;
}

/*****************************************************************************
 * FUNCTION
 *  gui_get_multi_line_input_box_default_font_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN]
 *  text_font   [OUT]
 * RETURNS
 *  
 *****************************************************************************/
void gui_get_multi_line_input_box_default_font_style(
                        multi_line_input_box *b,
                        UI_font_type text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *text_font = *(b->text_font);
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_default_font_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN/OUT]
 *  text_font   [IN]
 * RETURNS
 *  
 *****************************************************************************/
void gui_set_multi_line_input_box_default_font_style(
                        multi_line_input_box *b,
                        UI_font_type text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(b->text_font) = *text_font;
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_default_bg_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN/OUT]
 *  c           [IN]
 *  b_set       [IN]
 * RETURNS
 *  
*****************************************************************************/
void gui_set_multi_line_input_box_default_bg_color(
                          multi_line_input_box *b, 
                          color c, 
                          MMI_BOOL b_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b_set)
    {
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR;
        b->default_bg_color = c;
    }
    else
    {
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_underline_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  
 *****************************************************************************/
void gui_set_multi_line_input_box_underline_color(multi_line_input_box *b, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    b->underline_color = c;
}


#if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) || defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
/*****************************************************************************
 * FUNCTION
 *  pen_check_func_key_bound
 * DESCRIPTION
 *  
 * PARAMETERS
 * x                    [IN]
 * y                    [IN]
 * selected_key_x       [IN]
 * selected_key_y       [IN]
 * keypad_func_x        [IN]
 * keypad_func_y        [IN]
 * func_key_width       [IN]    
 * func_key_height      [IN]
 * func_n_rows      [IN]
 * func_n_column        [IN]

 * RETURNS
 * MMI_BOOL
*****************************************************************************/
MMI_BOOL pen_check_func_key_bound(S32 x,S32 y,
                                  S32 selected_key_x,S32 selected_key_y,
                                  S32 keypad_func_x,S32 keypad_func_y, 
                                  S32 func_key_width,S32 func_key_height,
                                  S32 func_n_rows,S32 func_n_column)
{
    MMI_BOOL is_func_key_flag = (MMI_BOOL)IS_NOT_FUNC_KEY;
    if(x>keypad_func_x&&y>keypad_func_y&&
        x<selected_key_x+func_key_width*func_n_rows&&
        y<selected_key_y+func_key_height*func_n_column)
        if(PEN_CHECK_BOUND
            (x, y, selected_key_x, selected_key_y, func_key_width,
            func_key_height))
        {
            is_func_key_flag = (MMI_BOOL)IS_FUNC_KEY;
        }
        return is_func_key_flag;
}


/*****************************************************************************
 * FUNCTION
 *  pen_check_func_key_bound_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 * x                    [IN]
 * y                    [IN]
 * dialing_keypad		[IN]		dialing keypad struct information

 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
static MMI_BOOL pen_check_func_key_bound_ext(S32 x, S32 y, dialing_keypad_struct *dialing_keypad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_func_key_flag = (MMI_BOOL)IS_NOT_FUNC_KEY;
    S32 func_key_width;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    func_key_width = dialing_keypad->func_n_rows * dialing_keypad->func_key_width;
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
    if (dialing_keypad->key_type == MMI_DIALING_KEY_CALL)
    {
        func_key_width = func_key_width - dialing_keypad->func_key_width + dialing_keypad->call_key_width;
    }
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
    
    if (x > dialing_keypad->keypad_func_x && y > dialing_keypad->keypad_func_y 
        && x < dialing_keypad->selected_key_x + func_key_width
        && y < dialing_keypad->selected_key_y + dialing_keypad->func_key_height * dialing_keypad->func_n_column)
    {
        func_key_width = dialing_keypad->func_key_width;
    #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
        if (dialing_keypad->key_type == MMI_DIALING_KEY_CALL)
        {
            func_key_width = dialing_keypad->call_key_width;
        }
    #endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
        if (PEN_CHECK_BOUND(x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, func_key_width, dialing_keypad->func_key_height))
        {
            is_func_key_flag = (MMI_BOOL)IS_FUNC_KEY;
        }
    }
    return is_func_key_flag;
}
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ || __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_cursor_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 *  cursor_offset [IN]
 * RETURNS
 *  void
 *****************************************************************************/
BOOL gui_multi_line_input_box_test_cursor_pos(multi_line_input_box *b, S32 cursor_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 m;
    S16* predefine_array = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/  
    predefine_array = b->predefine_char_pos;

    if (b->predefine_char_pos == NULL) /* no prefer character limitation*/
        return MMI_TRUE;

    while ((m = *(predefine_array++)) != -1)
    {
        if (m == cursor_offset)
            return MMI_FALSE;
    }
#else
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(cursor_offset);    
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_forword_cursor_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 *  cursor_offset [IN]
 * RETURNS
 *  void
 *****************************************************************************/
BOOL gui_multi_line_input_box_forword_cursor_pos(multi_line_input_box *b, S32* cursor_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    UI_buffer_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = b->text + (*cursor_offset)*ENCODING_LENGTH;
    
    UI_STRING_GET_NEXT_CHARACTER(p, c);
    if (c == 0)
        return MMI_TRUE;
    
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    if (b->predefine_char_pos == NULL)
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/          
    {
        *cursor_offset += 1;
        return MMI_TRUE;
    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    *cursor_offset += 1;
    while (c != 0)
    {
        if (gui_multi_line_input_box_test_cursor_pos(b, *cursor_offset))
            return MMI_TRUE;

        UI_STRING_GET_NEXT_CHARACTER(p, c);
        *cursor_offset += 1;
    }
    return MMI_FALSE;    
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/    

}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_backword_cursor_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 *  cursor_offset [IN]
 * RETURNS
 *  void
 *****************************************************************************/
BOOL gui_multi_line_input_box_backword_cursor_pos(multi_line_input_box *b, S32* cursor_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    UI_buffer_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = b->text + (*cursor_offset)*ENCODING_LENGTH;

    if (*cursor_offset == 0)
        return MMI_TRUE;
    
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/    
    if (b->predefine_char_pos == NULL)
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/
    {
        *cursor_offset -= 1;
        return MMI_TRUE;
    }

#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    UI_STRING_GET_PREVIOUS_CHARACTER(p, c);
    *cursor_offset -= 1;
    while (p >= b->text)
    {
        if (gui_multi_line_input_box_test_cursor_pos(b, *cursor_offset))
            return MMI_TRUE;

        UI_STRING_GET_PREVIOUS_CHARACTER(p, c);
        *cursor_offset -= 1;
    }

    UI_UNUSED_PARAMETER(c);
    return MMI_FALSE;
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/  
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_set_predefine_char_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 *  cursor_offset [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_set_predefine_char_pos(multi_line_input_box *b, S16* predefine_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__ /**/
    b->predefine_char_pos = predefine_pos;
#else /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(predefine_pos);    
#endif /*__MMI_WCSS_INPUT_FORMAT_SUPPORT__*/ /**/
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_start_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 *  cursor_offset [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_start_input(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE;
    
    b->input_mode_cursor_p = b->cursor_p;
    b->input_start_cursor_p = b->cursor_p;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_stop_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 *  cursor_offset [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_stop_input(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_INPUT_METHOD_MODE;
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	to_decide_to_reshuffle_inline = 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_start_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 *  cursor_offset [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_start_input(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE;
    
    b->input_mode_cursor_p = b->current_text_p;
    b->input_start_cursor_p = b->current_text_p;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_stop_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 *  cursor_offset [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_stop_input(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_INPUT_METHOD_MODE;
    b->input_mode_cursor_p = NULL;
    b->input_start_cursor_p = NULL;
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))

	to_decide_to_reshuffle_inline = 0;
#endif
}
/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_is_in_shown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]
 * RETURNS
 *  S32    1: in shown function 0: not
 *****************************************************************************/
S32 gui_multi_line_input_box_is_in_shown(multi_line_input_box *b)
{
    return in_multiline_shown_flag;
}

#if defined(__MMI_ARSHAPING_ENGINE__)
S32 gui_multi_line_mapping_org_to_sha(S32 position)
{
    if(position > unshaped_text_len)  // temp solution, it should not happen !
        return (position - unshaped_text_len) + shaped_text_len;
    
    MMI_ASSERT(0<=position && position<=unshaped_text_len+1); // include NULL char
    return OrgToSha[position];
}

S32 gui_multi_line_mapping_org_to_sha_forward(S32 position)
{
    S32 i;
    
    if(position > unshaped_text_len)  // temp solution, it should not happen !
        return (position - unshaped_text_len) + shaped_text_len;
    
    MMI_ASSERT(0<=position && position<=unshaped_text_len+1); // include NULL char
    if (position > 0)
    {
        if (OrgToSha[position - 1] == OrgToSha[position])
        {
            for (i=position; i<=unshaped_text_len+1; i++)
            {
                if (OrgToSha[i] != OrgToSha[i-1])
                {
                    position = i;
                    break;
                }
            }
        }
    }
    
    return OrgToSha[position];
}


S32 gui_multi_line_mapping_sha_to_org(S32 position)
{
    int l,r,m;
    if(position > shaped_text_len)  // temp solution for b->line_after_cursor_line_last_p, we should remove this variable.
        return (position - shaped_text_len) + unshaped_text_len;

    MMI_ASSERT(0<= position && position <= shaped_text_len+1);
    
    l = 0;
    r = unshaped_text_len+1; // include NULL char
    m = 0;
    while(l<=r)
    {
		int cmp;
        m = (l+r) >> 1;
		cmp = OrgToSha[m] - position;
        if(cmp==0 ) 
			break;
		else if(cmp<0) 
			l=m+1; 
		else 
			r=m-1;
    }

    // seek to the first position
    while(m>0)
        if(OrgToSha[m-1]==position) m--; else break;

    return m;
}
#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
/*****************************************************************************
* FUNCTION
*  gui_get_multi_line_visible_area
* DESCRIPTION
*  
* PARAMETERS
*  b       [?]     
*  y1      [?] 
*  y2      [?]   
* RETURNS
*  void
*****************************************************************************/
void gui_get_multi_line_visible_area(multi_line_input_box *b, S32 *y1, S32 *y2)
{
    *y1 = -(b->text_offset_y) - (b->header_height+b->header_gap);
    *y2 = *y1 + b->edit_height;

    if(*y1 < 0)
        *y1 = 0;

    if(*y2 < 0)
        *y2 = 0;
    
    if (*y2 - *y1 > UI_DEVICE_HEIGHT)
        *y2 = *y1 + UI_DEVICE_HEIGHT;
}
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
gdi_handle gui_inputs_get_source_layer(void)
{
    gdi_handle layer[4], layer_bottom;

    gdi_layer_get_blt_layer(&layer[0], &layer[1], &layer[2], &layer[3]);
    layer_bottom = dm_get_layer_handle(0);
    
    if (layer_bottom)
        layer[0] = layer_bottom;

    return layer[0];
}
#endif

#ifdef __MMI_FIXED_DIALER_FONT__
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_prev_line_for_fixed_font
 * DESCRIPTION
 *  move to prev line of dialer inputr box
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_prev_line_for_fixed_font(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cursor_line;
    UI_buffer_type current_text_p = b->last_position_p;
    S32 cur_x = b->cursor_x + 1, right_x, text_x, text_gap = b->text_gap, character_width;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->fixed_cursor_x == -1)
        b->fixed_cursor_x = cur_x;
    else
        cur_x = b->fixed_cursor_x;
    
    cursor_line = gui_dialer_input_box_get_cursor_line_index(b);

    if (cursor_line == 0)
    {
        UI_editor_play_tone_cannot_navigate();
    }
    else
    {
        if (cursor_line > 1)
        {
            current_text_p = b->line_start_p[cursor_line - 2];
        }
        
        character_width = gui_get_character_width(0x31);
        right_x = (b->width % (character_width + text_gap))/2;
        if (right_x == 0)
            right_x = (character_width + text_gap)/2;
        text_x = b->x + b->width - 1 - right_x;
        while (current_text_p > b->line_start_p[cursor_line - 1])
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
            character_width = gui_get_character_width(current_character);

            text_x = (text_x - (character_width + text_gap));

            if (text_x < cur_x)
            {
                b->current_text_p = current_text_p + ENCODING_LENGTH;
                break;
            }
        }
        
        if (current_text_p == b->line_start_p[cursor_line - 1])
        {
            b->current_text_p = current_text_p + ENCODING_LENGTH;
        }

        if (b->bottom_line_index > 0
            && b->current_text_p > b->line_start_p[b->bottom_line_index - 1])
        {
            b->bottom_line_index--;    
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_refresh_for_fixed_font
 * DESCRIPTION
 *  move to prev line of dialer inputr box
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_refresh_for_fixed_font(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_bottom_index, cursor_line;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_bottom_index = b->bottom_line_index;

    b->flags |= UI_DIALER_INPUT_BOX_DISABLE_DRAW;
    b->bottom_line_index = 0;
    gui_show_dialer_input_box(b);
    

    cursor_line = gui_dialer_input_box_get_cursor_line_index(b);
    if (cursor_line < old_bottom_index)
    {
        b->bottom_line_index = cursor_line;
    }
    else
        b->bottom_line_index = old_bottom_index;

    gui_show_dialer_input_box(b);
    b->flags &= ~UI_DIALER_INPUT_BOX_DISABLE_DRAW;

    if (b->current_text_p <= b->first_position_p
        && b->current_text_p != b->text)
    {
        b->bottom_line_index++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_next_line_for_fixed_font
 * DESCRIPTION
 *  move to prev line of dialer inputr box
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_next_line_for_fixed_font(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cursor_line;
    UI_buffer_type current_text_p = b->last_position_p;
    S32 cur_x = b->cursor_x + 1, right_x, text_x, text_gap = b->text_gap, character_width;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->fixed_cursor_x == -1)
        b->fixed_cursor_x = cur_x;
    else
        cur_x = b->fixed_cursor_x;

    cursor_line = gui_dialer_input_box_get_cursor_line_index(b);

    if (cursor_line == MMI_dialer_inputbox.n_lines - 1)
    {
        UI_editor_play_tone_cannot_navigate();
    }
    else
    {
        current_text_p = b->line_start_p[cursor_line];

        character_width = gui_get_character_width(0x31);
        right_x = (b->width % (character_width + text_gap))/2;
        if (right_x == 0)
            right_x = (character_width + text_gap)/2;
        text_x = b->x + b->width - 1 - right_x;
        while (current_text_p > b->line_start_p[cursor_line+1])
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
            character_width = gui_get_character_width(current_character);

            text_x = (text_x - (character_width + text_gap));

            if (text_x < cur_x)
            {
                b->current_text_p = current_text_p + ENCODING_LENGTH;
                break;
            }
        }
        
        if (text_x >= cur_x)
        {
            if (current_text_p == b->text)
            {
                b->current_text_p = b->text;
            }
            else
            {
                b->current_text_p = current_text_p + ENCODING_LENGTH;
            }
        }

        if (b->current_text_p <= b->first_position_p && b->first_position_p != b->text)
        {
            b->bottom_line_index++;    
        }
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_prev_line
 * DESCRIPTION
 *  move to prev line of dialer inputr box
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_prev_line(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->last_position_p, prev_text_p, temp_text_p;
    UI_character_type current_character;
    S32 character_height;
    S32 cur_x = b->cursor_x + 1;
    S32 cur_y = b->cursor_y;
    S32 x1, y1, x2, y2, right_x;
    S32 text_x, text_y, text_gap, character_width;
    U8 flag = 0;
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_gap = b->text_gap;
    x1 = b->x;
    y1 = b->y;

    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;

    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }

    gui_set_font(b->text_font);

#ifdef __MMI_FIXED_DIALER_FONT__
    gui_dialer_input_box_prev_line_for_fixed_font(b);
    return;
#endif
    
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)b->text;
    query.n = mmi_ucs2strlen((const char*)b->text);
    query.enableTruncated = MMI_FALSE;
    query.w = text_gap;
    mmi_fe_get_string_widthheight(&query);
    
    character_height = query.pHeight;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query.pHeight <= (query.baseline + 2))
        character_height++;
#endif
    
    character_width = gui_get_character_width(0x31);
    right_x = (b->width % (character_width + text_gap))/2;
    if (right_x == 0)
        right_x = (character_width + text_gap)/2;

    text_x = x2 - right_x;
    text_y = y2 - character_height;

#ifndef __MMI_COLOR_DIALLING_FONT__
    if (!(current_MMI_theme->dialer_inputbox_text_border_color->r == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->g == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->b == 255))
    {
        text_y--;
        character_height += 2;
    }
#endif

    if (b->fixed_cursor_x == -1)
        b->fixed_cursor_x = cur_x;
    else
        cur_x = b->fixed_cursor_x;
    
    temp_text_p = current_text_p;
    if (b->n_lines > 0)
    {
        cur_y = cur_y + character_height;
        do
        {
            prev_text_p = current_text_p;
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
            if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
            {
                if (text_y != cur_y)
                {
                    prev_text_p = temp_text_p;
                }
                if (prev_text_p)
                {
                    b->current_text_p = prev_text_p;
                }
                return;
            }

            character_width = gui_get_character_width(current_character);

            b->current_text_p = prev_text_p;
            if ((text_y == cur_y) && ((text_x == cur_x) || (text_x < cur_x)))
            {
                flag = 1;
            }
            /* MTK Terry for dialer box Key Down Issue */
            text_x = (text_x - (character_width + text_gap));
            /* MTK Terry for dialer box Key Down Issue when lines > 2 */
            if (text_x <= x1)
            {
                if (text_y == cur_y)
                {
                    return;
                }
                text_x = x2 - right_x;
                text_y -= character_height;
                UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
                if (text_y < y1)
                {
                    break;
                }
            }
        } while ((flag == 0));
    }
    else
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_next_line
 * DESCRIPTION
 *  move to net line of dialer inputr box
 * PARAMETERS
 *  b       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_next_line(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p, prev_text_p, temp_text_p;
    UI_buffer_type backup_curret_text_p = b->current_text_p;
    UI_character_type current_character;

    /* U8 index = 0;  */
    S32 character_height;
    S32 cur_x = b->cursor_x + 1;
    S32 cur_y = b->cursor_y;
    S32 x1, y1, x2, y2, right_x;
    S32 text_x, text_y, text_gap, character_width;
    U8 flag = 0;
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_gap = b->text_gap;
    x1 = b->x;
    y1 = b->y;

    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;

    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }

    gui_set_font(b->text_font);
    
#ifdef __MMI_FIXED_DIALER_FONT__
    gui_dialer_input_box_next_line_for_fixed_font(b);
    return;
#endif

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)b->text;
    query.n = mmi_ucs2strlen((const char*)b->text);
    query.enableTruncated = MMI_FALSE;
    query.w = text_gap;
    mmi_fe_get_string_widthheight(&query);

    text_x = cur_x;
    text_y = cur_y;

    if (b->fixed_cursor_x == -1)
        b->fixed_cursor_x = cur_x;
    else
        cur_x = b->fixed_cursor_x;
    
    character_width = gui_get_character_width(0x31);
    character_height = query.pHeight;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query.pHeight <= (query.baseline + 2))
        character_height++;
#endif

#ifndef __MMI_COLOR_DIALLING_FONT__
    if (!(current_MMI_theme->dialer_inputbox_text_border_color->r == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->g == 0
        && current_MMI_theme->dialer_inputbox_text_border_color->b == 255))
        character_height += 2;
#endif

    right_x = (b->width % (character_width + text_gap))/2;
    if (right_x == 0)
        right_x = (character_width + text_gap)/2;
    
    temp_text_p = current_text_p;
    if (b->n_lines > 0)
    {
        cur_y = cur_y - character_height;

        do
        {
            prev_text_p = current_text_p;
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
            if (prev_text_p == b->text)
            {
                if (text_y != cur_y)
                {
                    b->current_text_p = temp_text_p;
                    return;
                }
                if (prev_text_p)
                {
                    b->current_text_p = prev_text_p;
                }
                return;
            }
            character_width = gui_get_character_width(current_character);
            text_x = (text_x - (character_width + text_gap));

            if (text_x <= x1)
            {
                text_x = x2 - right_x;
                text_y -= character_height;
                current_text_p = prev_text_p;
                if (text_y < y1)
                {
                    b->current_text_p = backup_curret_text_p;
                    UI_editor_play_tone_cannot_navigate();
                    return;
                }
            }
            b->current_text_p = current_text_p;

            if ((text_y == cur_y) && ((text_x == cur_x) || (text_x < cur_x)))
            {
                flag = 1;
            }

        } while ((flag == 0));

    }
    else
    {
        UI_editor_play_tone_cannot_navigate();
        return;

    }
    UI_UNUSED_PARAMETER(y2);
}

/*****************************************************************************
* FUNCTION
*  gui_inputs_get_char_info_for_all_lang
* DESCRIPTION
*  To get maximum char height regardless of language
* PARAMETERS
*  size:        [IN]        the font size
* RETURNS
*  S32  
*****************************************************************************/
S32 gui_inputs_get_char_info_for_all_lang(U8 size, S32 *ascent_p, S32 *dscent_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 ascent = 0, dscent = 0, height = 0, backup_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (backup_size == size && height != 0)
    {
        if (ascent_p != NULL)
            *ascent_p = ascent;
        
        if (dscent_p != NULL)
            *dscent_p = dscent;

        return height;
    }
    
    GDI_LOCK;
    mmi_fe_get_char_info_of_all_lang(size, &height, &ascent, &dscent);
    GDI_UNLOCK;
    
    backup_size = size;

    if (ascent_p != NULL)
        *ascent_p = ascent;

    if (dscent_p != NULL)
        *dscent_p = dscent;

    return height;
}
/*****************************************************************************
 * FUNCTION
 *  gui_multi_single_line_input_box_ascii_encoding_handling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_single_line_input_box_ascii_encoding_handling(
                                                            UI_character_type old_c, UI_character_type c,
                                                            S32 *non_ascii_count,
                                                            S32 *available_length,
                                                            S32 *allocated_length,
                                                            U32 flags
                                                             )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
    {
        if (!UI_TEST_ASCII_CHARACTER(old_c) && (*non_ascii_count > 0) && (old_c != 0))
        {
            *non_ascii_count = *non_ascii_count - 1;
            if (*non_ascii_count == 0)
            {
                *available_length = *allocated_length;
            }
        }
        if (!UI_TEST_ASCII_CHARACTER(c) && (c != 0))
        {
            if (*non_ascii_count == 0)
            {
                *available_length = UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(*allocated_length);
            }
            *non_ascii_count = *non_ascii_count + 1;
        }
    }
    else
    {
        if (!UI_TEST_ASCII_CHARACTER(old_c) && (*non_ascii_count > 0) && (old_c != 0))
        {
            *non_ascii_count = *non_ascii_count - 1;
            if (*non_ascii_count == 0)
            {
                *available_length = *allocated_length;
            }
        }
        if (!UI_TEST_ASCII_CHARACTER(c) && (c != 0))
        {
            if (*non_ascii_count == 0)
            {
                *available_length = UI_UCS2_STRING_HALF_LENGTH(*allocated_length);
            }
            *non_ascii_count = *non_ascii_count + 1;
        }
    }       
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_ascii_encoding_handling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_ascii_encoding_handling(multi_line_input_box *b, UI_character_type old_c, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_USE_ASCII_ENCODING_BASE_LENGTH)
    {
        gui_multi_single_line_input_box_ascii_encoding_handling(old_c,  c,
                                                                &b->non_ascii_count,
                                                                &b->available_length,
                                                                &b->allocated_length,
                                                                b->flags); 
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
    #endif
}


/*****************************************************************************
* FUNCTION
*  gui_single_line_input_box_ascii_encoding_handling
* DESCRIPTION
*  
* PARAMETERS
*  b       [IN]        
* RETURNS
*  void
*****************************************************************************/
void gui_single_line_input_box_ascii_encoding_handling(single_line_input_box *b, UI_character_type old_c, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ASCII_ENCODING_BASE_LENGTH)
    {
        gui_multi_single_line_input_box_ascii_encoding_handling(old_c,  c,
                                                                &b->non_ascii_count,
                                                                &b->available_length,
                                                                &b->allocated_length,
                                                                b->flags); 
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
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_single_line_callback_area
 * DESCRIPTION
 *  Draw single line left/right area
 * PARAMETERS
 *  b       [?]     
 *  bs      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_single_line_callback_area(single_line_input_box *b, single_line_input_box_show_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Draw left region */
    if (!(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW) && b->left_callback)
    {
        /* Not overlapped with border */
        b->left_callback(
            bs->x1 + b->margin.left_margin,
            bs->sy1 + ((bs->sy2 - bs->sy1 + 1) - b->left_height) / 2,
            bs->x1 + b->margin.left_margin, bs->sy1 + 1, bs->x1 + b->margin.left_margin + b->left_width, bs->sy2 - 1);
    }
    
    /* Draw right region */
    if (!(bs->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW) && b->right_callback)
    {
        /* Not overlapped with border */
        b->right_callback(
            bs->x2 - b->right_width - b->margin.right_margin,
            bs->sy1 + ((bs->sy2 - bs->sy1 + 1) - b->right_height) / 2,
            bs->x2 - b->right_width - b->margin.right_margin, bs->sy1 + 1, bs->x2, bs->sy2 - 1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_set_callback_area
 * DESCRIPTION
 *  Set single line left/right area
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_set_callback_area(
         single_line_input_box *b,
         U32 left_width,
         U32 left_height,
         void (*left_callback) (S32 x, S32 y, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2),
         U32 right_width,
         U32 right_height,
         void (*right_callback) (S32 x, S32 y, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->left_width = left_width;
    b->left_height = left_height;
    b->left_callback = left_callback;
    b->right_width = right_width;
    b->right_height = right_height;
    b->right_callback = right_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_set_default_text
 * DESCRIPTION
 *  Set single line default text
 * PARAMETERS
 *  b              [IN]             singleline inputbox object
 *  default_text   [IN]             default text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_set_default_text(single_line_input_box *b, UI_string_type default_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->default_text = default_text;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_set_default_text
 * DESCRIPTION
 *  Set multi line default text
 * PARAMETERS
 *  b              [IN]             singleline inputbox object
 *  default_text   [IN]             default text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_set_default_text(multi_line_input_box *b, UI_string_type default_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->default_text = default_text;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_ml_register_pen_control_area_callback
 * DESCRIPTION
 *  Register multline inputbox control area pen callback
 * PARAMETERS
 *  b              [IN]             multiline inputbox object
 *  f              [IN]             control area pen callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_inputs_ml_register_pen_control_area_callback(
        multi_line_input_box *b,
        void (*f)(gui_input_box_area_enum area_type, mmi_pen_event_type_enum pen_event, S32 x, S32 y))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->pen_control_area_callback = f;
}



#ifdef __MMI_TOUCH_SCREEN__

#ifdef __MMI_EDITOR_SSP_SUPPORT__
static S32 g_ssp_pen_down_y;
static S32 g_ssp_pen_move_y;
static S32 g_ssp_pen_down_x;
static S32 g_ssp_pen_move_x;

static gui_input_box_ssp_state_enum g_ssp_state;

static S32 g_ssp_start_offset;
static S32 g_ssp_free_run_momentum;
static S32 g_ssp_free_run_final_pos;
static gui_input_box_ssp_free_run_mode_enum g_ssp_free_run_mode;

static U32 g_ssp_pen_down_time;

static gui_input_box_ssp_update_client update_client_callback = NULL;
static gui_input_box_ssp_get_client_info get_client_info_callback = NULL;
static gui_input_box_ssp_notify_status notify_client_status = NULL;
static void *input_box_user_data = NULL;

static MMI_BOOL gui_input_box_ssp_try_free_run_recover(void);
static void gui_input_box_ssp_enter_free_run_recover_mode(S32 final_y_offset, S32 momentum);

S32 g_ssp_speed_multiples = 10;
S32 g_ssp_parabolic_mode = GUI_INPUT_BOX_SSP_PARABOLIC_MODEL_CENTER_X;

static U8  g_ssp_free_run_update_frame_interval = GUI_INPUT_BOX_SSP_FRAME_UPDATE_INTERVAL;
static U8  g_ssp_free_run_move_y_threshold = GUI_INPUT_BOX_SSP_FREE_RUN_MOVEMENT_Y_THRESOLD;
static U8 g_ssp_focus_to_move_y_threshold = GUI_INPUT_BOX_SSP_FOCUS_TO_HOLD_STATE_Y_THRESHOLD;
static U8 g_ssp_pos_delta = GUI_INPUT_BOX_SSP_POS_DELTA;
static U16 g_ssp_free_run_threshold_time = GUI_INPUT_BOX_SSP_FREE_RUN_THRESHOLD_TIME;
static U16 g_ssp_free_run_mass_range_threshold_speed = GUI_INPUT_BOX_SSP_FREE_RUN_MASS_RANGE_SPEED;
static float g_ssp_free_run_scroll_coefficient = GUI_INPUT_BOX_SSP_FREE_RUN_SCROLL_COEFFICIENT;
static float g_ssp_free_run_recover_coefficient = GUI_INPUT_BOX_SSP_FREE_RUN_RECOVER_COEFFICIENT;
static float g_ssp_free_run_sensitivity = GUI_INPUT_BOX_SSP_FREE_RUN_SENSITIVITY;

#ifdef __MMI_EDITOR_SSP_PARABOLIC_SUPPORT__
static double parabolic_a, parabolic_b, parabolic_c;  /* for parabolic */
static S32 g_ssp_current_x;
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_set_parameters
 * DESCRIPTION
 *  set the parameters for editor ssp
 * PARAMETERS
 *  param   [IN] ssp params
 * RETURNS
 *  void
 *****************************************************************************/
void gui_input_box_ssp_set_parameters(const gui_input_box_ssp_params_struct* params)
{
    g_ssp_free_run_update_frame_interval = params->free_run_update_frame_interval;
    g_ssp_free_run_move_y_threshold = params->free_run_move_y_threshold;
    g_ssp_focus_to_move_y_threshold = params->focus_to_move_y_threshold;
    g_ssp_pos_delta = params->pos_delta;
    g_ssp_free_run_threshold_time = params->free_run_threshold_time;
    g_ssp_free_run_mass_range_threshold_speed = params->free_run_mass_range_threshold_speed;
    g_ssp_free_run_scroll_coefficient = params->free_run_scroll_coefficient;
    g_ssp_free_run_recover_coefficient = params->free_run_recover_coefficient;
    g_ssp_free_run_sensitivity = params->free_run_sensitivity;

}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_get_parameters
 * DESCRIPTION
 *  get the parameters for editor ssp
 * PARAMETERS
 *  param   [OUT] ssp params
 * RETURNS
 *  void
 *****************************************************************************/
void gui_input_box_ssp_get_parameters(gui_input_box_ssp_params_struct* params)
{
    params->free_run_update_frame_interval = g_ssp_free_run_update_frame_interval;
    params->free_run_move_y_threshold = g_ssp_free_run_move_y_threshold;
    params->focus_to_move_y_threshold = g_ssp_focus_to_move_y_threshold;
    params->pos_delta = g_ssp_pos_delta;
    params->free_run_threshold_time = g_ssp_free_run_threshold_time;
    params->free_run_mass_range_threshold_speed = g_ssp_free_run_mass_range_threshold_speed;
    params->free_run_scroll_coefficient = g_ssp_free_run_scroll_coefficient;
    params->free_run_recover_coefficient = g_ssp_free_run_recover_coefficient;
    params->free_run_sensitivity = g_ssp_free_run_sensitivity;

}

/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_get_parameters
 * DESCRIPTION
 *  get the parameters for editor ssp
 * PARAMETERS
 *  param   [OUT] ssp params
 * RETURNS
 *  void
 *****************************************************************************/
void gui_input_box_ssp_reset_parameter()
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_ssp_free_run_update_frame_interval = GUI_INPUT_BOX_SSP_FRAME_UPDATE_INTERVAL;
    g_ssp_free_run_move_y_threshold = GUI_INPUT_BOX_SSP_FREE_RUN_MOVEMENT_Y_THRESOLD;
    g_ssp_focus_to_move_y_threshold = GUI_INPUT_BOX_SSP_FOCUS_TO_HOLD_STATE_Y_THRESHOLD;
    g_ssp_pos_delta = GUI_INPUT_BOX_SSP_POS_DELTA;
    g_ssp_free_run_threshold_time = GUI_INPUT_BOX_SSP_FREE_RUN_THRESHOLD_TIME;
    g_ssp_free_run_mass_range_threshold_speed = GUI_INPUT_BOX_SSP_FREE_RUN_MASS_RANGE_SPEED;
    g_ssp_free_run_scroll_coefficient = GUI_INPUT_BOX_SSP_FREE_RUN_SCROLL_COEFFICIENT;
    g_ssp_free_run_recover_coefficient = GUI_INPUT_BOX_SSP_FREE_RUN_RECOVER_COEFFICIENT;
    g_ssp_free_run_sensitivity = GUI_INPUT_BOX_SSP_FREE_RUN_SENSITIVITY;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_get_state
 * DESCRIPTION
 *  get current state of ssp
 * PARAMETERS
 *  void
 * RETURNS
 *  gui_input_box_ssp_state_enum
 *****************************************************************************/
gui_input_box_ssp_state_enum gui_input_box_ssp_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return g_ssp_state;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_get_userdata
 * DESCRIPTION
 *  get the ssp userdata
 * PARAMETERS
 *  
 * RETURNS
 *  return ssp userdata
 *****************************************************************************/
void* gui_input_box_ssp_get_userdata(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return input_box_user_data;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_pen_down_hdlr
 * DESCRIPTION
 *  Pen down handler of Smooth Scrolling by Pen.
 * PARAMETERS
 *  point       [IN]    pen point
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    S32 total_offset;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    g_ssp_pen_down_y = (S32)point.y;
    g_ssp_pen_down_x = (S32)point.x;
    
    get_client_info_callback(input_box_user_data, &total_offset, &g_ssp_start_offset, NULL);

#ifdef __EDITOR_SSP_NO_RECOVER__
    if (total_offset == 0)
        return MMI_FALSE;
#endif

    g_ssp_free_run_mode = GUI_INPUT_BOX_SSP_FREE_RUN_MODE_RECOVER;

    switch (g_ssp_state)
    {
        case GUI_INPUT_BOX_SSP_STATE_UNFOCUS:
            g_ssp_state = GUI_INPUT_BOX_SSP_STATE_FOCUS;
            ret = MMI_FALSE;
            break;

        case GUI_INPUT_BOX_SSP_STATE_FREE_RUN:
            gui_cancel_timer(gui_input_box_ssp_update_frame);        
            g_ssp_state = GUI_INPUT_BOX_SSP_STATE_HOLD;                     
            break;

        default:
            break;
    }

    if (notify_client_status)
        notify_client_status(input_box_user_data, g_ssp_state);

    kal_get_time(&g_ssp_pen_down_time);
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_change_speed_multiple
 * DESCRIPTION
 *  change the ssp multiples to smooth speed
 * PARAMETERS
 *  point       [IN]    pen point
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
void gui_input_box_ssp_change_speed_multiple(S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_ssp_speed_multiples = value;
    /* MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"[Editor SSP] g_ssp_speed_multiples = %d", g_ssp_speed_multiples); */
}



/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_change_parabolic_model
 * DESCRIPTION
 *  change the ssp parabolic model
 * PARAMETERS
 *  point       [IN]    pen point
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
void gui_input_box_ssp_change_parabolic_model(S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ssp_parabolic_mode = value;
    /* MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"[Editor SSP] g_ssp_parabolic_mode = %d", g_ssp_parabolic_mode); */
}


/*****************************************************************************
 * FUNCTION
 *  gui_ssp_pen_up_hdlr
 * DESCRIPTION
 *  Pen up handler of Smooth Scrolling by Pen.
 * PARAMETERS
 *  point       [IN]    pen point
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_pen_up_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 pen_up_time, pen_down_to_up_delta_time;
    S32 pen_down_to_up_delta = 0;
    S32 speed;
    S32 cur_offset, max_offset;
    S32 move_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ssp_state == GUI_INPUT_BOX_SSP_STATE_UNFOCUS)
    {
        return MMI_FALSE;
    }

    if (g_ssp_state == GUI_INPUT_BOX_SSP_STATE_HOLD)
    {
        kal_get_time(&pen_up_time);

        pen_down_to_up_delta_time = kal_ticks_to_milli_secs(pen_up_time - g_ssp_pen_down_time);
        
        get_client_info_callback(input_box_user_data, &max_offset, &cur_offset, &move_type);
        
        if (move_type == GUI_INPUT_BOX_SSP_BY_Y)
            pen_down_to_up_delta = (S32)point.y - g_ssp_pen_down_y;
        else if (move_type == GUI_INPUT_BOX_SSP_BY_X)
            pen_down_to_up_delta = (S32)point.x - g_ssp_pen_down_x;

        if (pen_down_to_up_delta_time == 0)
            pen_down_to_up_delta_time = 1;

        speed = GUI_INPUT_BOX_ABS(pen_down_to_up_delta)*1000/pen_down_to_up_delta_time;

        /* MMI_PRINT(MOD_MMI_FW,TRACE_GROUP_8,"[Editor SSP]distance = %d pixels time = %d ms Speed = %d pixel/s",GUI_INPUT_BOX_ABS(pen_down_to_up_delta), pen_down_to_up_delta_time, speed);*/
            
        if ((pen_down_to_up_delta_time < 2 * g_ssp_free_run_threshold_time) &&
            (GUI_INPUT_BOX_ABS(pen_down_to_up_delta) > g_ssp_free_run_move_y_threshold))
        {
            S32 pos_delta;
            
            //pos_delta = GUI_INPUT_BOX_ABS(pen_down_to_up_delta) * g_ssp_pos_delta;
            if (speed > g_ssp_free_run_mass_range_threshold_speed)
                pos_delta = max_offset / 3;
            else if (pen_down_to_up_delta_time < g_ssp_free_run_threshold_time)
                pos_delta = (speed / g_ssp_speed_multiples ) * g_ssp_pos_delta;
            else
                pos_delta = speed / g_ssp_speed_multiples;

            g_ssp_free_run_momentum = pen_down_to_up_delta;
            if (g_ssp_free_run_momentum < 0)
            {
                pos_delta = -pos_delta;
            }

            /* free run mode */
            g_ssp_state = GUI_INPUT_BOX_SSP_STATE_FREE_RUN;            
            g_ssp_free_run_mode = GUI_INPUT_BOX_SSP_FREE_RUN_MODE_RUN;

#ifdef __MMI_EDITOR_SSP_PARABOLIC_SUPPORT__
            g_ssp_current_x = 1;
            gui_input_box_ssp_calculate_parabolic_parameter(-pos_delta);
            g_ssp_free_run_momentum = gui_input_box_ssp_calculate_parabolic_y(
                (g_ssp_parabolic_mode / GUI_INPUT_BOX_SSP_PARABOLIC_FRAME_COUNTER) * g_ssp_current_x);
#else
            g_ssp_free_run_momentum = (S32)((float)-pos_delta * g_ssp_free_run_sensitivity);
            if (speed > g_ssp_free_run_mass_range_threshold_speed)
                g_ssp_free_run_momentum *= 2;
#endif
            g_ssp_free_run_final_pos = cur_offset - pos_delta;

            gui_start_timer(g_ssp_free_run_update_frame_interval, gui_input_box_ssp_update_frame);

            if (notify_client_status)
                notify_client_status(input_box_user_data, g_ssp_state);

            return MMI_TRUE;
        }

        /* go recover mode if the menu is scrolled out of normal */
        if (gui_input_box_ssp_try_free_run_recover())
        {
            return MMI_TRUE;
        }
    }

    g_ssp_state = GUI_INPUT_BOX_SSP_STATE_UNFOCUS;

    if (notify_client_status)
        notify_client_status(input_box_user_data, g_ssp_state);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_pen_move_hdlr
 * DESCRIPTION
 *  Pen move handler of Smooth Scrolling by Pen.
 * PARAMETERS
 *  point       [IN]    pen point
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_pen_move_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    S32 move_type;
    S32 delta = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    
    /* do not handle move events when unfocused */
    if (g_ssp_state == GUI_INPUT_BOX_SSP_STATE_UNFOCUS)
        return MMI_FALSE;

    get_client_info_callback(input_box_user_data, NULL, NULL, &move_type);
    
    /* update pen move y */
    g_ssp_pen_move_y = (S32)point.y;
    g_ssp_pen_move_x = (S32)point.x;
    
    switch (g_ssp_state)
    {
        case GUI_INPUT_BOX_SSP_STATE_FOCUS:
            /* 
             * go to hold state when 
             * 1. the pen moves to the neighbor item, and
             * 2. the offset from pen down y exceed the GUI_SSP_FOCUS_TO_HOLD_STATE_Y_THRESHOLD 
             */
             if (move_type == GUI_INPUT_BOX_SSP_BY_Y)
                delta = g_ssp_pen_move_y - g_ssp_pen_down_y;
             else if (move_type == GUI_INPUT_BOX_SSP_BY_X)
                delta = g_ssp_pen_move_x - g_ssp_pen_down_x;
             
            if ((GUI_INPUT_BOX_ABS(delta) > g_ssp_focus_to_move_y_threshold))
            {

                g_ssp_state = GUI_INPUT_BOX_SSP_STATE_HOLD;
                /* trigger GUI_INPUT_BOX_SSP_STATE_HOLD state */
                if (notify_client_status)
                    notify_client_status(input_box_user_data, g_ssp_state);
                return gui_input_box_ssp_pen_move_hdlr(point);
            }
            ret = MMI_FALSE;
            break;

        case GUI_INPUT_BOX_SSP_STATE_HOLD:      
            gui_start_timer(g_ssp_free_run_update_frame_interval, gui_input_box_ssp_update_frame);
            break;

        default:       
            break;
    }
   
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_pen_abort_hdlr
 * DESCRIPTION
 *  Pen abort handler of Smooth Scrolling by Pen.
 * PARAMETERS
 *  point       [IN]    pen point
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_pen_abort_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ssp_state == GUI_INPUT_BOX_SSP_STATE_FREE_RUN
        && g_ssp_free_run_mode == GUI_INPUT_BOX_SSP_FREE_RUN_MODE_RECOVER)
    {
        if (update_client_callback)
        {
            update_client_callback(input_box_user_data, g_ssp_free_run_final_pos);
        }
    }

    g_ssp_state = GUI_INPUT_BOX_SSP_STATE_UNFOCUS;
    gui_cancel_timer(gui_input_box_ssp_update_frame);
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_is_scrolling
 * DESCRIPTION
 *  Check the ssp whether has been or is being scrolling
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_TRUE 
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_is_scrolling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ssp_state == GUI_INPUT_BOX_SSP_STATE_UNFOCUS
        || g_ssp_state == GUI_INPUT_BOX_SSP_STATE_FOCUS)
        return MMI_FALSE;
    else
        return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_update_frame
 * DESCRIPTION
 *  Updates a SSP frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_input_box_ssp_update_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset = 0;
    S32 max_offset, cur_offset, move_type;
    S32 old_momentum;
    kal_uint32 begin_tick,end_tick;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(get_client_info_callback != NULL && update_client_callback != NULL);
    
    get_client_info_callback(input_box_user_data, &max_offset, &cur_offset, &move_type);

    if (move_type == GUI_INPUT_BOX_SSP_BY_Y)
        offset = g_ssp_pen_down_y - g_ssp_pen_move_y + g_ssp_start_offset;
    else if (move_type == GUI_INPUT_BOX_SSP_BY_X)
        offset = g_ssp_pen_down_x - g_ssp_pen_move_x + g_ssp_start_offset;
    
    switch (g_ssp_state)
    {
        case GUI_INPUT_BOX_SSP_STATE_HOLD:
            /* recover */
            if ((max_offset > 0) && (offset > max_offset))
            {
                offset = max_offset;
            }
            else if (offset < 0)
                offset = 0;

            kal_get_time(&begin_tick);
            update_client_callback(input_box_user_data, offset);
            kal_get_time(&end_tick);
            end_tick -= begin_tick;
            end_tick = kal_ticks_to_milli_secs(end_tick);
            MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_SSP_CLIENT_UPDATE, end_tick);
            break;

        case GUI_INPUT_BOX_SSP_STATE_FREE_RUN:
            /* free run */
            if (g_ssp_free_run_mode == GUI_INPUT_BOX_SSP_FREE_RUN_MODE_RUN)
            {
                
#ifdef __MMI_EDITOR_SSP_PARABOLIC_SUPPORT__
                offset = cur_offset + g_ssp_free_run_momentum;
                g_ssp_current_x ++;
                if (g_ssp_current_x > GUI_INPUT_BOX_SSP_PARABOLIC_FRAME_COUNTER)
                    g_ssp_free_run_momentum = 0;
                else
                {
                    S32 x1, x2;
                    
                    x2 = (g_ssp_parabolic_mode / GUI_INPUT_BOX_SSP_PARABOLIC_FRAME_COUNTER) * g_ssp_current_x;
                    x1 = (g_ssp_parabolic_mode / GUI_INPUT_BOX_SSP_PARABOLIC_FRAME_COUNTER) * (g_ssp_current_x - 1);
                    g_ssp_free_run_momentum = gui_input_box_ssp_calculate_parabolic_y(x2) - gui_input_box_ssp_calculate_parabolic_y(x1) ;
                }
#else
                offset = cur_offset + g_ssp_free_run_momentum;
                
                old_momentum = g_ssp_free_run_momentum;
                g_ssp_free_run_momentum = (S32)((float)g_ssp_free_run_momentum * g_ssp_free_run_scroll_coefficient);

                /* make sure converge to zero */
                // if (old_momentum == g_ssp_free_run_momentum)
                if (GUI_INPUT_BOX_ABS(GUI_INPUT_BOX_ABS(old_momentum) - GUI_INPUT_BOX_ABS(g_ssp_free_run_momentum)) 
                    < GUI_INPUT_BOX_SSP_FREE_RUN_STOP_Y_RANGE)
                {
                    g_ssp_free_run_momentum = 0;
                }
#endif
            }
            else
            {   
                /* recover mode */
                old_momentum = g_ssp_free_run_momentum;
                g_ssp_free_run_momentum = (S32)((float)g_ssp_free_run_momentum * g_ssp_free_run_recover_coefficient);

                /* make sure converge to zero */
                // if (old_momentum == g_ssp_free_run_momentum)
                if (GUI_INPUT_BOX_ABS(GUI_INPUT_BOX_ABS(old_momentum) - GUI_INPUT_BOX_ABS(g_ssp_free_run_momentum)) 
                    < g_ssp_free_run_move_y_threshold)
                {
                    g_ssp_free_run_momentum = 0;
                }

                offset = g_ssp_free_run_final_pos + g_ssp_free_run_momentum;
            }
            
            if (offset < 0)
            {
                // directly to beginning
                offset = 0;
                gui_input_box_ssp_enter_free_run_recover_mode(0, offset);
            }
            else if (offset > max_offset)
            {
                // directly to end
                offset = max_offset;
                gui_input_box_ssp_enter_free_run_recover_mode(max_offset, offset - max_offset);
            }

            kal_get_time(&begin_tick);
            update_client_callback(input_box_user_data, offset);
            kal_get_time(&end_tick);
            end_tick -= begin_tick;
            end_tick = kal_ticks_to_milli_secs(end_tick);
            MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_SSP_CLIENT_UPDATE, end_tick);

            /* running or running -> recover */
            if (g_ssp_free_run_momentum)
            {
                gui_start_timer(g_ssp_free_run_update_frame_interval, gui_input_box_ssp_update_frame);
            }
            else
            {   /* g_gui_ssp_free_run_momentum == 0 */
                /* try to recover if the menu is not in the normal position */
                if (gui_input_box_ssp_try_free_run_recover())
                {
                    return;
                }

                g_ssp_state = GUI_INPUT_BOX_SSP_STATE_UNFOCUS;
                if (notify_client_status)
                    notify_client_status(input_box_user_data, g_ssp_state);
                return;
            }
            break;
    }

    #ifdef WIN32
    kal_sleep_task(1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_enter_free_run_recover_mode
 * DESCRIPTION
 *  Enters the SSP recover mode.
 * PARAMETERS
 *  final_y_offset       [IN]   the final menu y offset
 *  momentum             [IN]   move range to recover
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_input_box_ssp_enter_free_run_recover_mode(S32 final_y_offset, S32 momentum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ssp_state = GUI_INPUT_BOX_SSP_STATE_FREE_RUN;
    g_ssp_free_run_mode = GUI_INPUT_BOX_SSP_FREE_RUN_MODE_RECOVER;            
    g_ssp_free_run_momentum = momentum;
    g_ssp_free_run_final_pos = final_y_offset;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_try_free_run_recover
 * DESCRIPTION
 *  Tries to enter the recover mode as possible.
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_TRUE if recovering is executed; otherwise, MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL gui_input_box_ssp_try_free_run_recover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_offset, cur_offset;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_client_info_callback(input_box_user_data, &max_offset, &cur_offset, NULL);

    if ((!max_offset && cur_offset) || (cur_offset < 0))
    {   
        /* 
         * always go back to origin
         */
        gui_input_box_ssp_enter_free_run_recover_mode(0, cur_offset);
        gui_start_timer(g_ssp_free_run_update_frame_interval, gui_input_box_ssp_update_frame);

        return MMI_TRUE;
    }
    else if (max_offset && (cur_offset > max_offset))
    {
        /*
         * multi page: go back to the last y
         */
        gui_input_box_ssp_enter_free_run_recover_mode(max_offset, cur_offset - max_offset);
        gui_start_timer(g_ssp_free_run_update_frame_interval, gui_input_box_ssp_update_frame);   

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_pen_pre_hdlr
 * DESCRIPTION
 *  Pre-pen handler of Smooth Scrolling by Pen.
 * PARAMETERS
 *  point               [IN]    pen point
 *  pen_event           [IN]    pen event
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_pen_translate(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            return gui_input_box_ssp_pen_down_hdlr(point);

        case MMI_PEN_EVENT_UP:
            return gui_input_box_ssp_pen_up_hdlr(point);

        case MMI_PEN_EVENT_MOVE:
            return gui_input_box_ssp_pen_move_hdlr(point);

        case MMI_PEN_EVENT_ABORT:
            return gui_input_box_ssp_pen_abort_hdlr(point);

        default:
            /* ignored events */
            break;
    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_set_client_callback_ext
 * DESCRIPTION
 *  set input box ssp client instance
 * PARAMETERS
 *                 
 *  
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_set_client_callback_ext(
            gui_input_box_ssp_update_client callback1, 
            gui_input_box_ssp_get_client_info callback2, 
            gui_input_box_ssp_notify_status callback3,
            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point = {0, 0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ssp_state = GUI_INPUT_BOX_SSP_STATE_UNFOCUS;

    gui_input_box_ssp_pen_abort_hdlr(point);
    
    update_client_callback = callback1;
    get_client_info_callback = callback2;
    notify_client_status = callback3;
    input_box_user_data = user_data;

    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_set_client_callback
 * DESCRIPTION
 *  set input box ssp client instance
 * PARAMETERS
 *                 
 *  
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_set_client_callback(
            gui_input_box_ssp_update_client callback1, 
            gui_input_box_ssp_get_client_info callback2, 
            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_input_box_ssp_set_client_callback_ext(callback1, callback2, NULL, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multiline_ssp_update_client
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
void gui_multiline_ssp_update_client(void *user_data, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = (multi_line_input_box *)user_data;
    U32 saved_ext_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text_offset_y == -offset)
        return;
    
    b->text_offset_y = -offset;

    //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    //gui_show_multi_line_input_box(b);
    //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    
#ifdef __MMI_VUI_ENGINE__
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_update_view_for_SSP(b->venus_text_view);
        return;
    }
#endif

    saved_ext_flag = b->ext_flags;
    b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_FIXED_Y_OFFSET | GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    gui_show_multi_line_input_box(b);
    b->ext_flags = saved_ext_flag;
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        b->x,
        b->y,
        b->x + b->width,
        b->y + b->height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_multiline_ssp_get_client_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
void gui_multiline_ssp_get_client_info(void *user_data, S32 *total_offset, S32 *cur_offset, S32 *move_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = (multi_line_input_box *)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_offset)
    {
        *total_offset = b->text_height - b->edit_height;
        if (*total_offset < 0)
            *total_offset = 0;
    }

    if (cur_offset)
    {
        *cur_offset = -b->text_offset_y;
    }

    if (move_type)
    {
        *move_type = GUI_INPUT_BOX_SSP_BY_Y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_singleline_ssp_update_client
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
void gui_singleline_ssp_update_client(void *user_data, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *b = (single_line_input_box *)user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text_offset_x == -offset)
        return;
    
    b->text_offset_x = -offset;

#ifdef __MMI_VUI_ENGINE__
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_update_view_for_SSP(b->venus_text_view);
            return;
        }
#endif

    gui_show_single_line_input_box(b);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        b->x,
        b->y,
        b->x + b->width,
        b->y + b->height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_singleline_ssp_get_client_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset              [IN]    the new offset position
 * RETURNS
 *  MMI_TRUE if this pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
void gui_singleline_ssp_get_client_info(void *user_data, S32 *total_offset, S32 *cur_offset, S32 *move_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    single_line_input_box *b = (single_line_input_box *)user_data;
    U16 left_gap, right_gap;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_offset)
    {
#ifdef __MMI_FTE_SUPPORT__
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND)
    {
        left_gap = b->left_width;
        right_gap = b->right_width;
    }
    else
#endif
    {
        left_gap = b->left_width + b->margin.left_margin;
        right_gap = b->right_width + b->margin.right_margin;
    }

#ifdef __MMI_FTE_SUPPORT__
        *total_offset = b->text_width - (b->width - left_gap - right_gap - 
            b->text_x);
#else
        *total_offset = b->text_width - (b->width - 6);
#endif
        
        if (*total_offset < 0)
            *total_offset = 0;
        
        if (left_gap + right_gap >= b->width)
            *total_offset = 0; 
    }

    if (cur_offset)
    {
        *cur_offset = -b->text_offset_x;
    }
    
    if (move_type)
    {
        *move_type = GUI_INPUT_BOX_SSP_BY_X;
    }
}

#ifdef __MMI_EDITOR_SSP_PARABOLIC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_calculate_parabolic_parameter
 * DESCRIPTION
 *  y = ax*2 + bx + c
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_TRUE if the correct parameter is created; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL gui_input_box_ssp_calculate_parabolic_parameter(S32 max_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    double x = g_ssp_parabolic_mode , y = max_y; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* y = ax*2 - 2*g_ssp_parabolic_mode*ax */

    parabolic_a = -y / (g_ssp_parabolic_mode * g_ssp_parabolic_mode);
    parabolic_b = -2*g_ssp_parabolic_mode*parabolic_a;
    parabolic_c = 0;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_input_box_ssp_calculate_parabolic_parameter
 * DESCRIPTION
 *  y = ax*2 + bx + c
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_TRUE if the correct parameter is created; otherwise, MMI_FALSE.
 *****************************************************************************/
S32 gui_input_box_ssp_calculate_parabolic_y(S32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    double y; 

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* we assume x of point mapping to the max y of parabolic is 10 */
    y = parabolic_a*x*x + parabolic_b*x + parabolic_c;

    return (S32)y;
}
#endif

#endif /* __MMI_EDITOR_SSP_SUPPORT__ */
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_show_special_remaining_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b              [IN]    multiline inputbox instance
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_show_special_remaining_counter(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef GUI_INPUT_BOX_FLOATING_COUNTER
    S32 x1, y1, x2, y2;
    S32 max_n, n, w, h;
    U8 temp_0x81 = 0;
    UI_character_type str[32];
    stFontAttribute    small_font = {0, 0, 0, SMALL_FONT, 0, 1};
    color c = *current_MMI_theme->remaining_length_text_color;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_inputbox_register_floating_counter_position(0, 0, 0, 0);

    if (b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW
        || b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE
        || b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE
        || (!mmi_imc_is_connected())
        || b->is_hide_floating_counter)
        return;
    
#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_connected() && mmi_imc_clipboard_is_editor_read_only())
    {
        return;
    }
#endif

    if (b->get_remaining_counter == NULL)
    {
        n = (b->text_length >> 1) - 1;
        max_n = (b->available_length >> 1) - 1;
        
        /* Compute the remaining counter */
        if ((b->flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) &&
            (b->UCS2_count == 0))
        {
            n += b->GSM_ext_count;
        }
        
        if ((b->flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) &&
            (b->text[0] == '+'))
        {
            n--;
            max_n--;
        }
        
        if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
        {
            temp_0x81 = srv_phb_convert_to_0x81((U16*) b->text, MMI_FALSE);
            if (0 != temp_0x81)
            {
                max_n = (b->allocated_length >> 1) - 4;
                n = temp_0x81 - 3;
            }
        }
        
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_DISPLAY_REMAINING_COUNTER)
        {
            if (n < max_n - GUI_INPUT_BOX_FLOATING_COUNTER_DISPLAY_THRESHOLD)
                return;
        }
        
        /* Compute the position */
        gui_sprintf(str, "%d/%d", n, max_n);
    }
    else
    {
        if (!b->get_remaining_counter((UI_character_type *)str, 32 * ENCODING_LENGTH))
            return;
    }

    gui_set_font(&small_font);
    gui_measure_string(str, &w, &h);
    
    if (!mmi_fe_get_r2l_state())
    {
        x2 = b->x + b->width - 1 - GUI_INPUT_BOX_FLOATING_COUNTER_GAP_X;
        x1 = x2 - w - 1;
    }
    else
    {
        x1 = b->x + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_X;
        x2 = x1 + w + 1;
    }

    y1 = b->y + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_Y;
    if (b->header_height > 0)
    {
        /* if header exist, go with the header */
        y1 += (b->text_y + b->header_height + b->header_gap + b->text_offset_y);
    }
    
    /* can not draw outside of the editor area */
    if (y1 < b->y + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_Y)
    {
        y1 = b->y + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_Y;
    }
    if (y1 > b->y + b->height - h - GUI_INPUT_BOX_FLOATING_COUNTER_GAP_Y)
    {
        y1 = b->y + b->height - h - GUI_INPUT_BOX_FLOATING_COUNTER_GAP_Y;
    }
    y2 = y1 + h + 1;
    
    gui_push_clip();
    gui_reset_clip();
    
    gdi_image_draw_resized_blend2layers(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y1 - 1, 
        x2 - (x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT) + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y2 - (y1 - 1) + 1, 
        current_MMI_theme->inputbox_remaining_counter_bg);

    UI_inputbox_register_floating_counter_position(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT,
        y1 - 1,
        x2 + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT,
        y2 + 1);

    UI_inputbox_stop_cursor_ext(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y1 - 1, 
        x2 + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y2 + 1,
        MMI_FALSE);

    if (!mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x2 - 1 - w, y1 + 1);
    }
    else
    {
        gui_move_text_cursor(x1 + 1 + w, y1 + 1);
    }
    
    gui_set_font(&small_font);
    gui_set_text_color(c);
    gui_print_text(str);
    gui_pop_clip();
    
    gui_set_font(b->text_font);
#endif /* GUI_INPUT_BOX_FLOATING_COUNTER */
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_show_special_remaining_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b              [IN]    single line inputbox instance
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_show_special_remaining_counter(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef GUI_INPUT_BOX_FLOATING_COUNTER
    S32 x1, y1, x2, y2;
    S32 max_n, n, w, h;
    UI_character_type str[32];
    gdi_handle act_layer;
    stFontAttribute    small_font = {0, 0, 0, SMALL_FONT, 0, 1};
    color c = *current_MMI_theme->remaining_length_text_color;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_inputbox_register_floating_counter_position(0, 0, 0, 0);
    
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW
        || b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        || (!mmi_imc_is_connected())
        || !b->show_special_counter)
        return;

    n = (b->text_length >> 1) - 1;
    max_n = (b->available_length >> 1) - 1;
    
    /* Compute the remaining counter */
    if ((b->flags & UI_SINGLE_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) &&
        (b->UCS2_count == 0))
    {
        n += b->GSM_ext_count;
    }
    
    if ((b->flags & UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) &&
        (b->text[0] == '+'))
    {
        n--;
        max_n--;
    }

    if (b->ext_flags & GUI_SINGLE_LINE_INPUT_BOX_AUTO_DISPLAY_REMAINING_COUNTER)
    {
        if (n < max_n - GUI_INPUT_BOX_FLOATING_COUNTER_DISPLAY_THRESHOLD)
            return;
    }
    
    /* Compute the position */
    gui_sprintf(str, "%d/%d", n, max_n);

    gui_set_font(&small_font);
    gui_measure_string(str, &w, &h);
    
    if (!mmi_fe_get_r2l_state())
    {
        x2 = b->x + b->width - 1 - GUI_INPUT_BOX_FLOATING_COUNTER_GAP_X;
        x1 = x2 - w - 1;
    }
    else
    {
        x1 = b->x + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_X;
        x2 = x1 + w + 1;
    }

    y1 = b->y + GUI_INPUT_BOX_FLOATING_COUNTER_GAP_Y;
    y2 = y1 + h + 1;

    if (!mmi_fe_get_r2l_state())
    {
        gui_move_text_cursor(x2 - 1 - w, y1 + 1);
    }
    else
    {
        gui_move_text_cursor(x1 + 1 + w, y1 + 1);
    }
    
    gui_push_clip();
    gui_reset_clip();
    
    gdi_layer_get_active(&act_layer);
    gdi_push_and_set_alpha_blending_source_layer(act_layer);
    gdi_image_draw_resized(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y1 - 1, 
        x2 - (x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT) + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y2 - (y1 - 1) + 1, 
        current_MMI_theme->inputbox_remaining_counter_bg);
    gdi_pop_and_restore_alpha_blending_source_layer();
    
    UI_inputbox_register_floating_counter_position(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT,
        y1 - 1,
        x2 + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT,
        y2 + 1);

    UI_inputbox_stop_cursor_ext(x1 - GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y1 - 1, 
        x2 + GUI_INPUT_BOX_FLOATING_COUNTER_INDENT, 
        y2 + 1,
        MMI_FALSE);

    gui_set_text_color(c);
    gui_print_text(str);
    gui_pop_clip();
    
    gui_set_font(b->text_font);
#endif /* GUI_INPUT_BOX_FLOATING_COUNTER */
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_register_redraw_background_filler
 * DESCRIPTION
 *  Register filler editor background filler function when redraw
 * PARAMETERS
 *  f              [IN]        redraw background function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_inputs_register_redraw_background_filler(gui_inputs_draw_back_ground_funcptr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_inputs_background_filler = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_set_cursor_change_event_state
 * DESCRIPTION
 *  Set cursor change event state
 * PARAMETERS
 *  b_enable              [IN]        enable or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_inputs_set_cursor_change_event_state(MMI_BOOL b_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cursor_change_evt_on = b_enable;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_get_cursor_change_event_state
 * DESCRIPTION
 *  Get cursor change event state
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_inputs_get_cursor_change_event_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_cursor_change_evt_on;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_set_transparent_background
 * DESCRIPTION
 *  Set force transparent editor background or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void gui_inputs_set_transparent_background(MMI_BOOL b_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    g_editor_background_transparent = b_trans;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_set_pen_scrollbar_cb
 * DESCRIPTION
 *  Set scrollbar pen callback
 * PARAMETERS
 *  f              [IN]         scrollbar pen callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_inputs_set_pen_scrollbar_cb(gui_inputs_pen_scroll_cb f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_inputs_pen_scroll_cb = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_ml_hide_floating_counter
 * DESCRIPTION
 *  hide multiline floating counter
 * PARAMETERS
 *  value              [IN]         hide or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_inputs_ml_hide_floating_counter(multi_line_input_box *b, MMI_BOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->is_hide_floating_counter = value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_ml_set_hilite_list
 * DESCRIPTION
 *  Set mulltiline hilite list
 * PARAMETERS
 *  b              [IN]    single line inputbox instance
 * hilite_list     [IN]    hilite list
 * number_of_list  [IN]    hilite list number
 * curr_hilite_idx [IN]    current hilite index
 * hilite_cb       [IN]    the callback when the hilite is highlighted(Usually register as set LSK/RSK according to hilite type)
 * click_cb        [IN]    the callback when the hilite is clicked(Usually register as GO TO function)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_inputs_ml_set_hilite_list(
        multi_line_input_box *b,
        HILITE_STR *hilite_list,
        U16 number_of_list,
        U16 curr_hilite_idx,
        void (*hilite_cb)(S32 idx),
        void (*click_cb)(S32 idx))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
     
    if (hilite_list)
    {
        b->hilite_list = hilite_list;
        b->hilite_str_number = number_of_list;
    }
    b->current_hilite_idx = curr_hilite_idx;
    b->hilite_cb = hilite_cb;
#ifdef __MMI_TOUCH_SCREEN__
    b->hilite_click_cb = click_cb;
#endif
    b->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;

    gui_multi_line_input_box_go_to_hilite(b, b->current_hilite_idx, MMI_TRUE);

    
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(hilite_list);
    UI_UNUSED_PARAMETER(number_of_list);
    UI_UNUSED_PARAMETER(curr_hilite_idx);
    UI_UNUSED_PARAMETER(hilite_cb);
    UI_UNUSED_PARAMETER(click_cb);
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_ml_get_hilite_list
 * DESCRIPTION
 *  get hilite list from editor
 * PARAMETERS
 * b                [IN]            editor input box pointer
 * list             [IN]            hilite list
 * RETURNS
 *  U32
 *****************************************************************************/
U32 gui_inputs_ml_get_hilite_list(multi_line_input_box *b, HILITE_STR **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     #ifdef __MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__
     
    *list = b->hilite_list;
    return b->hilite_str_number;

    
    #else /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
    UI_UNUSED_PARAMETER(b);
    UI_UNUSED_PARAMETER(list);
    return 0;
    #endif /*__MMI_EDITOR_MULTILINE_SUPPORT_HILITE_LIST__*/
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_set_clip_preset
 * DESCRIPTION
 *  set preset clip
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_inputs_set_clip_preset(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prev_x1, prev_y1, prev_x2, prev_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(&prev_x1, &prev_y1, &prev_x2, &prev_y2);

    if (x1 > prev_x1)
    {
        prev_x1 = x1;
    }
    if (y1 > prev_y1)
    {
        prev_y1 = y1;
    }
    if (x2 < prev_x2)
    {
        prev_x2 = x2;
    }
    if (y2 < prev_y2)
    {
        prev_y2 = y2;
    }
    
    if (prev_x1 > prev_x2 || prev_y1 > prev_y2)
    {
        prev_x1 = 0;
        prev_x2 = 0;
        prev_y1 = 0;
        prev_y2 = 0;
    }

    gdi_layer_set_clip(prev_x1, prev_y1, prev_x2, prev_y2);

}


#if GUI_INPUTS_KEYWORDS_SUPPORT

/*****************************************************************************
 * FUNCTION
 *  gui_inputs_ml_malloc
 * DESCRIPTION
 *  function to call OslMalloc
 * PARAMETERS
 *  size        [IN]        size to malloc
 * RETURNS
 *  address be malloced
 *****************************************************************************/
static void* gui_inputs_ml_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void* p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    p = OslMalloc(size);
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_free
 * DESCRIPTION
 *  function to call OslMfree
 * PARAMETERS
 *  p        [IN]        address to be free
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_inputs_ml_free(void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    OslMfree(p);
    p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_ml_check_stop_func
 * DESCRIPTION
 *  function to check the condition of stop extract address
 * PARAMETERS
 *  p        [IN]        address to be free
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool gui_inputs_ml_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num >= GUI_INPUTS_KEYWORDS_MAX_COUNT)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_ml_keyword_is_overlap
 * DESCRIPTION
 *  Check if two hilite is overlap
 * PARAMETERS
 * b                 [IN]            editor input box pointer
 * hilite1          [IN]             hilite1
 * hilite2          [IN]             hilite2
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gui_inputs_ml_keyword_is_overlap(HILITE_STR hilite1, HILITE_STR hilite2)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((hilite1.str_addr >= (hilite2.str_addr + hilite2.length * ENCODING_LENGTH)) ||
        ((hilite1.str_addr + hilite1.length * ENCODING_LENGTH) <= hilite2.str_addr))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  gui_inputs_set_clip_preset
 * DESCRIPTION
 *  set preset clip
 * PARAMETERS
 * b                [IN]            editor input box pointer
 * type            [IN]            keyword type
 * list              [OUT]         keyword parsed from text content
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 gui_inputs_ml_parse_keywords_by_type(multi_line_input_box *b, EDITOR_HILITE_TYPE type, HILITE_STR *list, applib_mem_alloc_fn mallocF, applib_mem_free_fn freeF)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *curr_addr_list = NULL;
    kal_bool is_stopped = KAL_FALSE;
    applib_addr_type_enum addrType = APPLIB_ADDR_TYPE_EMAIL;
    U32 list_cnt = 0;
    applib_address_node_struct *pNode = NULL;
    HILITE_STR *pAdd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
    case EDITOR_HILITE_NUMBER:
        addrType = APPLIB_ADDR_TYPE_PHONENUMBER;
        break;
    case EDITOR_HILITE_EMAIL:
        addrType = APPLIB_ADDR_TYPE_EMAIL;
        break;
    case EDITOR_HILITE_URL:
        addrType = APPLIB_ADDR_TYPE_URL;
        break;
    case EDITOR_HILITE_USSD:
        addrType = APPLIB_ADDR_TYPE_USSD;
        break;
    default:
        // not support
        return 0;
    }

    curr_addr_list = applib_get_exclusive_address_list_from_text_ext(
                                        addrType,
                                        gui_inputs_ml_malloc,
                                        gui_inputs_ml_free,
                                        gui_inputs_ml_check_stop_func,
                                        APPLIB_INPUT_DATA_TYPE_UNICODE,
                                        (char *)b->text,
                                        b->text_length,
                                        &is_stopped);

    pNode = curr_addr_list;
    // convert to text format
    while (pNode)
    {
        // add to result list 
        pAdd = &list[list_cnt];
        pAdd->str_addr = (CHAR*)(b->text + pNode->pos);
        pAdd->length = (U16)(pNode->length / ENCODING_LENGTH);
        pAdd->hilite_type = type;
        
        pNode = pNode->next;
        list_cnt++;
    }

    applib_free_address_list((applib_address_node_struct **)&curr_addr_list, gui_inputs_ml_free);

    return list_cnt;
    
}



/*****************************************************************************
 * FUNCTION
 *  gui_inputs_ml_parse_keywords
 * DESCRIPTION
 *  Parse keyword from editor text buffer
 *  Type support: email, url, phone number, ussd
 *  Limitation:
 *   1. Support max 10 keywords for each type and total 40 keywords.
 *   2. Support max 2k text buffer size (1k text length) with default memory malloc/free function. 
 *      If the text buffer large then 2K bytes, please pass custom memory malloc/free function
 *  After parse the keyword from text buffer, use gui_inputs_ml_get_hilite_list to get result list
 * PARAMETERS
 * b               : [IN]            editor input box pointer
 * type            : [IN]            keyword type, the type is defined in EDITOR_HILITE_TYPE
 * mallocF         : [IN]            custom memory malloc function
 * freeF           : [IN]            custom memory free function
 * RETURNS
 *  U32: keyword number
 *****************************************************************************/
U32 gui_inputs_ml_parse_keywords(multi_line_input_box *b, U32 type, applib_mem_alloc_fn mallocF, applib_mem_free_fn freeF)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HILITE_STR list_url[GUI_INPUTS_KEYWORDS_EACH_TYPE_MAX_COUNT];
    HILITE_STR list_email[GUI_INPUTS_KEYWORDS_EACH_TYPE_MAX_COUNT];
    HILITE_STR list_number[GUI_INPUTS_KEYWORDS_EACH_TYPE_MAX_COUNT];
    HILITE_STR list_ussd[GUI_INPUTS_KEYWORDS_EACH_TYPE_MAX_COUNT];
    U32 url_cnt = 0;
    U32 email_cnt = 0;
    U32 number_cnt = 0;
    U32 ussd_cnt = 0;
    U32 total_cnt = 0;
    U32 url_idx = 0;
    U32 email_idx = 0;
    U32 number_idx = 0;
    U32 ussd_idx = 0;
    EDITOR_HILITE_TYPE addType = EDITOR_HILITE_NONE;
    HILITE_STR addTempObj;
    S32 offset = b->text_length;
    applib_mem_alloc_fn mallcFunction = mallocF;
    applib_mem_free_fn freeFunction = freeF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mallcFunction == NULL || freeFunction == NULL)
    {
        // Only Support max 2k text buffer size (1k text length) with default memory malloc/free function. 
        // Please pass custom memory malloc/free function
        MMI_ASSERT(b->text_length < 2 * 1024);

        mallcFunction = gui_inputs_ml_malloc;
        freeFunction = gui_inputs_ml_free;
    }

    if (type & EDITOR_HILITE_NUMBER)
    {
        number_cnt = gui_inputs_ml_parse_keywords_by_type(b, EDITOR_HILITE_NUMBER, list_number, mallcFunction, freeFunction);
    }

    if (type & EDITOR_HILITE_EMAIL)
    {
        email_cnt = gui_inputs_ml_parse_keywords_by_type(b, EDITOR_HILITE_EMAIL, list_email, mallcFunction, freeFunction);
    }

    if (type & EDITOR_HILITE_URL)
    {
        url_cnt = gui_inputs_ml_parse_keywords_by_type(b, EDITOR_HILITE_URL, list_url, mallcFunction, freeFunction);
    }

    if (type & EDITOR_HILITE_USSD)
    {
        ussd_cnt = gui_inputs_ml_parse_keywords_by_type(b, EDITOR_HILITE_USSD, list_ussd, mallcFunction, freeFunction);
    }

    // sort keyword by priority (urlObj > emailObj > ussdObj > phoneNumberObj)
    // and delete redunant keyword which is overlapped
    while (number_idx < number_cnt || email_idx < email_cnt || url_idx < url_cnt || ussd_idx < ussd_cnt)
    {
        offset = b->text_length;
        addType = EDITOR_HILITE_NONE;

        // get add object by min offset
        if (url_idx < url_cnt && (list_url[url_idx].str_addr - b->text) < offset)
        {
            offset = (list_url[url_idx].str_addr - b->text);
            addType = EDITOR_HILITE_URL;
        }
        if (email_idx < email_cnt && (list_email[email_idx].str_addr - b->text) < offset)
        {
            offset = (list_email[email_idx].str_addr - b->text);
            addType = EDITOR_HILITE_EMAIL;
        }
        if (ussd_idx < ussd_cnt && (list_ussd[ussd_idx].str_addr - b->text) < offset)
        {
            offset = (list_ussd[ussd_idx].str_addr - b->text);
            addType = EDITOR_HILITE_USSD;
        }
        if (number_idx < number_cnt && (list_number[number_idx].str_addr - b->text) < offset)
        {
            offset = (list_number[number_idx].str_addr - b->text);
            addType = EDITOR_HILITE_NUMBER;
        }

        // check if the object is overlap by priority
        // Priority: URL > Email > USSD > phonenumber
        // Example: www.123456.com, URL will be saved while phonenumber will be ignored
        if (addType == EDITOR_HILITE_URL)
        {
            addTempObj = list_url[url_idx];

            // proceed the object if overlap with email object
            while (email_idx < email_cnt && gui_inputs_ml_keyword_is_overlap(list_email[email_idx], list_url[url_idx]))
            {
                email_idx++;
            }
            while (ussd_idx < ussd_cnt && gui_inputs_ml_keyword_is_overlap(list_ussd[ussd_idx], list_url[url_idx]))
            {
                ussd_idx++;
            }
            while (number_idx < number_cnt && gui_inputs_ml_keyword_is_overlap(list_number[number_idx], list_url[url_idx]))
            {
                number_idx++;
            }
            url_idx++;
        }
        else if (addType == EDITOR_HILITE_EMAIL)
        {
            if (url_idx < url_cnt && gui_inputs_ml_keyword_is_overlap(list_email[email_idx], list_url[url_idx]))
            {
                //addTempObj = urlObj;
                email_idx++;
                continue;
            }
            else
            {
                addTempObj = list_email[email_idx];
                while (ussd_idx < ussd_cnt && gui_inputs_ml_keyword_is_overlap(list_ussd[ussd_idx], list_email[email_idx]))
                {
                    ussd_idx++;
                }
                while (number_idx < number_cnt && gui_inputs_ml_keyword_is_overlap(list_number[number_idx], list_email[email_idx]))
                {
                    number_idx++;
                }
            }
            email_idx++;
        }
        else if (addType == EDITOR_HILITE_USSD)
        {
            if (url_idx < url_cnt && gui_inputs_ml_keyword_is_overlap(list_ussd[ussd_idx], list_url[url_idx]))
            {
                ussd_idx++;
                continue;
            }
            else if (email_idx < email_cnt && gui_inputs_ml_keyword_is_overlap(list_ussd[ussd_idx], list_email[email_idx]))
            {
                ussd_idx++;
                continue;
            }
            else
            {
                addTempObj = list_ussd[ussd_idx];
                while (number_idx < number_cnt && gui_inputs_ml_keyword_is_overlap(list_number[number_idx], list_ussd[ussd_idx]))
                {
                    number_idx++;
                }
            }
            ussd_idx++;
        }
        else if (addType == EDITOR_HILITE_NUMBER)
        {
            // phonenumber
            if (url_idx < url_cnt && gui_inputs_ml_keyword_is_overlap(list_number[number_idx], list_url[url_idx]))
            {
                number_idx++;
                continue;
            }
            else if (email_idx < email_cnt && gui_inputs_ml_keyword_is_overlap(list_number[number_idx], list_email[email_idx]))
            {
                number_idx++;
                continue;
            }
            else if (ussd_idx < ussd_cnt && gui_inputs_ml_keyword_is_overlap(list_number[number_idx], list_ussd[ussd_idx]))
            {
                number_idx++;
                continue;
            }
            else
            {
                addTempObj = list_number[number_idx];
            }
            number_idx++;
        }
        else
        {
            break;
        }

        // add to result list
        g_inputs_hilite_list[total_cnt++] = addTempObj;
    }

    if (total_cnt > 0)
    {
        b->hilite_list = g_inputs_hilite_list;
        b->hilite_str_number = (U16)total_cnt;
    }
    else
    {
        b->hilite_list = NULL;
        b->hilite_str_number = 0;
    }
    return total_cnt;
}

#endif /* GUI_INPUTS_KEYWORDS_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_set_auto_display_remaining_counter
 * DESCRIPTION
 *  set multiline auto display remaining counter
 * PARAMETERS
 *  b       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_set_auto_display_remaining_counter(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_AUTO_DISPLAY_REMAINING_COUNTER;
}

