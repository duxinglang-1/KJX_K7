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
 *  vapp_music_player.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player App, screen, tabpage, subpage
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"
#include "Vfx_config.h"

#include "vapp_music_player.h"
#include "vapp_music_player_sound_setting.h"
#include "vapp_music_player_playerbase.h"
#include "vapp_music_player_util.h"
#include "vapp_music_player_service.h"
#include "vapp_screen_lock_gprot.h"
#include "mmi_rp_vapp_music_player_def.h"
#include "GlobalResDef.h"
#include "NotificationGProt.h"
#include "Vapp_ncenter.h"
#include "mmi_rp_app_cosmos_global_def.h" // For cosmos theme color
#include "vfx_adp_device.h"
#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#include "Gdi_include.h"
#include "aud_defs.h"
#include "med_main.h"
#include "AppMgrSrvGProt.h"
#include "ShutdownSrvGprot.h"
#include "gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#include "vapp_ncenter_gprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#ifdef __cplusplus
}
#endif

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(__MTK_TARGET__) && defined(__MAUI_SOFTWARE_LA__)
#ifdef __cplusplus
extern "C"
{
#endif
#include "SST_sla.h"
#ifdef __cplusplus
}
#endif
#define SWLA_BEGIN(_symbol_) SLA_CustomLogging(##_symbol_##, SA_start);
#define SWLA_END(_symbol_) SLA_CustomLogging(##_symbol_##, SA_stop);
#else
#define SWLA_BEGIN(_symbol_)
#define SWLA_END(_symbol_)
#endif

/***************************************************************************** 
 * App Launcher
 *****************************************************************************/

// Lauching function

extern "C" mmi_id vapp_music_player_launch_app(void *param)
{
#ifdef __MMI_USB_SUPPORT__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        vapp_usb_unavailable_popup(0);
        return GRP_ID_INVALID;
    }
#endif /* __MMI_USB_SUPPORT__ */ 

    VfxApp *app = VfxAppLauncher::findApp(VAPP_MUSIC_PLAYER, VFX_OBJ_CLASS_INFO(VappMusicPlayerApp), VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if(app)
    {
        VFX_ASSERT(0);
    }
    else
    {
        VfxAppLauncherParam p(VAPP_MUSIC_PLAYER, VFX_OBJ_CLASS_INFO(VappMusicPlayerApp), GRP_ID_ROOT);
        p.setArgument(param, sizeof(VfxBool*));
        return VfxAppLauncher::launchEx(p); 
    }
}

// From main menu
extern "C" MMI_ID vapp_music_player_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    MMI_ID app_id = 0;

    if (param == NULL && param_size == 0)
    {
        VfxBool isNotLaunchFromMainMenu = VFX_FALSE;
        app_id = vapp_music_player_launch_app((void*)(&isNotLaunchFromMainMenu));
    }
    else
    {
        switch (param->cat)
        {
            case MMI_LAUNCH_APP_IN_OPEN_CATEGORY:
                app_id = vapp_music_player_launch_app(param->param);
                break;

            default:
                break;
        }
    }
    return app_id;
}

extern "C" mmi_ret vapp_music_player_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

#ifdef __AFX_RT_TEST__
VtstTestResultEnum vtst_rt_vapp_music_player(VfxU32 param)
{
    vapp_music_player_launch_app(NULL);
    return VTST_TR_OK;
}
#endif


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VappMusicPlayerApp* VappMusicPlayerApp::g_this = NULL;


/***************************************************************************** 
 * VappMusicPlayerApp Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerApp", VappMusicPlayerApp, VfxApp);

void VappMusicPlayerApp::onRun(void * args, VfxU32 argSize)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_RUN);

    SWLA_BEGIN("MR1");

    VfxApp::onRun(args, argSize);

    SWLA_END("MR1");

    m_isLaunchByMainMenu = *((VfxBool*)args) == VFX_FALSE;

    init1stStage();
}

void VappMusicPlayerApp::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_DEINIT);

    if (m_actionMode == ACTION_REFRESH)
    {
        m_provider->refreshDBCancel();
    }

    onAppClosingShrinkDB();

    setIsDying();

    m_ctrlPlayback = NULL;

    // Disconnect NCenter singal
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (NCenter)
    {
        NCenter->m_signalEvent.disconnect(this, &VappMusicPlayerApp::onNCenterStatus);
    }

    registerCBEvent(EVT_ID_SRV_SHUTDOWN_DEINIT, VFX_FALSE);
    registerCBEvent(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VFX_FALSE);
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, VFX_FALSE);

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
    registerCBEvent(EVT_ID_ORIENTATION_CHANGED, VFX_FALSE);
#endif

    if (m_mplayerSrv->getIsDying() || m_mplayerSrv->getActiveCount() == 0)
    {
        m_mplayerSrv->sendOpenCloseEvent(VFX_FALSE);
    }

    g_this = NULL;

	vapp_ncenter_disable_leave();
	
    VfxApp::onDeinit();
}

void VappMusicPlayerApp::updateWaitIconPos(VfxBool autoCheck, VfxBool isPortrait)
{
    if (m_waitIcon)
    {
        if (autoCheck)
        {
            VfxScrRotateTypeEnum rotateType = vfx_adp_srs_get_value();

            isPortrait = rotateType != MMI_FRM_SCREEN_ROTATE_90 && rotateType != MMI_FRM_SCREEN_ROTATE_270;
        }

        VfxU32 width = isPortrait ? GDI_LCD_WIDTH : GDI_LCD_HEIGHT;
        VfxU32 height = isPortrait ? GDI_LCD_HEIGHT : GDI_LCD_WIDTH;

        if (m_waitIcon)
        {
            m_waitIcon->setPos(width/2, (height - MMI_STATUS_BAR_HEIGHT)/2);    
        }
    }
}

mmi_ret VappMusicPlayerApp::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC, evt->evt_id);
    
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_SHUTDOWN_DEINIT:
        {
            onProcShutDownDeinit();
            
            break;
        }

        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
        {
            return onProcPreLockRouting();
        }   

        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            if(m_actionMode != ACTION_FATAL_ERROR)
            {
                onProcUcmStatusChange();
            }

            return MMI_RET_OK;
        }

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
        case EVT_ID_ORIENTATION_CHANGED:
        {
            if (!vfx_adp_srs_is_paused())
            {
                mmi_frm_auto_rotate_evt_struct *rotate = (mmi_frm_auto_rotate_evt_struct*)evt;
                mmi_frm_screen_rotate_enum degree = rotate->new_degree;

                vfxPostInvoke1(this, &VappMusicPlayerApp::onProcOrientationChange, degree);
            }
            break;
        }
#endif

        default:
            break;
    }

    return VfxApp::onProc(evt);
}

void VappMusicPlayerApp::onProcEnterUsbMsMode()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_EVT_ID_USB_ENTER_MS_MODE, m_actionMode);

#ifdef __MMI_USB_SUPPORT__
    if (m_actionMode == ACTION_RESET || m_actionMode == ACTION_LAUNCHING)
    {
        m_mplayerSrv->openDBCancel();
        setActionMode(ACTION_NONE);
    }
    else if (m_actionMode == ACTION_REFRESH)
    {
        m_provider->refreshDBCancel();
        setActionMode(ACTION_NONE);
    }
    else if (m_actionMode == ACTION_ADD_TO_PLAYLIST || m_actionMode == ACTION_PLAYLIST_ADD_SONG)
    {
        m_provider->addToPlaylistCancel();
    }

    setIsDying();
#endif
}

void VappMusicPlayerApp::onProcShutDownDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_EVT_ID_SRV_SHUTDOWN_DEINIT);

    if (m_provider)
    {
        m_provider->saveRepeatShuffle();
    }
}

mmi_ret VappMusicPlayerApp::onProcPreLockRouting()
{
    if (m_popupWaiting && 
       (m_actionMode == ACTION_RESET 
     || m_actionMode == ACTION_REFRESH
     || m_actionMode == ACTION_ADD_TO_PLAYLIST
     || m_actionMode == ACTION_PLAYLIST_ADD_SONG))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_PRE_LOCK_ROUTING_1, m_actionMode);

        return MMI_RET_ERR;
    }
    else if (m_popupIndicator && 
            (m_actionMode == ACTION_DELETE
          || m_actionMode == ACTION_PLAYLIST_REMOVE))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_PRE_LOCK_ROUTING_2, m_actionMode);

        return MMI_RET_ERR;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_PRE_LOCK_ROUTING_3, m_actionMode);

        return MMI_RET_OK;
    }
}

void VappMusicPlayerApp::onProcUcmStatusChange()
{
    VfxBool makingCall = isMakingCall();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_UCM_STATUS_CHANGE_MAKING_CALL_D, makingCall);

    if(makingCall)
    {
        // cancel all processing action on receiving incoming call
        closeAllPopup();
    }
    
    //VfxBool noPlayback = m_ctrlPlayback->getPlayState() == PB_STATE_NONE;

    if(makingCall)
    {
        if (m_coverFlow)
        {
#ifdef __COSMOS_3D_V10__
            if (!isGroupTopActive())
            {
                // if APP is top active, cover flow page will be closed in coverFlowPage::onExited2()
                exitCoverFlow();
            }
#else
            m_coverFlow->setEnablePlaybackUI(VFX_FALSE);
#endif
        }

        if (m_nowPlaying)
        {
            m_nowPlaying->setEnablePlaybackUI(VFX_FALSE);
        }
    }
    else
    {
        // Disable some UI if no playback
        if (m_coverFlow)
        {
            m_coverFlow->onPlaybackStateChange(m_ctrlPlayback->getPlayState());
        }

        if (m_nowPlaying)
        {
            m_nowPlaying->onPlaybackStateChange(m_ctrlPlayback->getPlayState());  
        }
    }
}

void VappMusicPlayerApp::onProcOrientationChange(mmi_frm_screen_rotate_enum degree)
{
    m_curGblOrientation = degree;
    
    // no action if app is not top active
    if (!isGroupTopActive() || m_curGblOrientation == m_curAppOrientation)
    {
        return;
    }

    m_curAppOrientation = degree;

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__    

    // handle screen rotate

    VfxMainScr *scr = VFX_OBJ_DYNAMIC_CAST(getTopScreen(), VfxMainScr);
    if(scr)
    {
        VfxPage *page = scr->getPage();
        if (page)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROC_ORIENTATION_CHANGE_DEGREE_D, degree);

            VfxBool isCoverFlowPage = VFX_TRUE;
#ifdef __COSMOS_3D_V10__
            isCoverFlowPage = page->isKindOf(VFX_OBJ_CLASS_INFO(VappMusicPlayerCoverFlow3DPage));
#else
            isCoverFlowPage = page->isKindOf(VFX_OBJ_CLASS_INFO(VappMusicPlayerCoverFlowPage));
#endif

            if (degree == MMI_FRM_SCREEN_ROTATE_90
             || degree == MMI_FRM_SCREEN_ROTATE_270)
            {
                if(!isCoverFlowPage)
                {
                    onScreenRotate(degree == MMI_FRM_SCREEN_ROTATE_90 ? VFX_SCR_ROTATE_TYPE_90 : VFX_SCR_ROTATE_TYPE_270);
                }
            }
            else
            {
                if(isCoverFlowPage)
                {
                    onScreenRotate(VFX_SCR_ROTATE_TYPE_0);
                }
            }
        }
    }
#endif // __COSMOS_MUSICPLY_COVER_FLOW__
}

void VappMusicPlayerApp::onNCenterStatus(VappNCenterEventEnum evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_NCENTER_STATUS, evt);
    
    switch (evt)
    {
        case VAPP_NCENTER_EVENT_ENTER:
            {
                m_isNCenterVisable = VFX_TRUE;
            }
            break;

        case VAPP_NCENTER_EVENT_ENTERED:
            {
                VappMusicPlayerSubPage *page = getCurrPage();
                if (page)
                {
                    page->deactivateSearchEditor();                    
                }

                m_snapGblOrientation = m_curGblOrientation;
            }
            break;

        case VAPP_NCENTER_EVENT_EXITED:
            {
                m_isNCenterVisable = VFX_FALSE;

                VfxScrRotateTypeEnum rotateType = vfx_adp_srs_get_value();

                if (rotateType == VFX_SCR_ROTATE_TYPE_90)
                {
                    m_curGblOrientation = MMI_FRM_SCREEN_ROTATE_90;
                }
                else if (rotateType == VFX_SCR_ROTATE_TYPE_270)
                {
                    m_curGblOrientation = MMI_FRM_SCREEN_ROTATE_270;
                }
                else
                {
                    m_curGblOrientation = MMI_FRM_SCREEN_ROTATE_0;
                }

                if (m_snapGblOrientation != m_curGblOrientation)
                {
                    vfxPostInvoke1(this, &VappMusicPlayerApp::onProcOrientationChange, m_curGblOrientation);
                }
            }
            break;

        default:
            break;
    }
}

VfxAppCloseAnswerEnum VappMusicPlayerApp::onProcessClose(VfxAppCloseOption options, VfxAppCloseReason reason)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROCESS_CLOSE,m_actionMode, m_ctrlPlayback->getPlayState());

    // close by OOM
    if (reason & VFX_APP_CLOSE_REASON_OOM_FLAG)
    {
        //m_mplayerSrv->closeMusicPlayer();
        return VFX_APP_CLOSE_ANSWER_YES;
    }

    // handle home key / end key here
    if (options & VFX_APP_CLOSE_OPTION_BG_FLAG)
    {
        if (m_actionMode == ACTION_FATAL_ERROR)
        {
            m_mplayerSrv->closeMusicPlayer();
            return VFX_APP_CLOSE_ANSWER_YES;
        }
        else if (m_actionMode == ACTION_LAUNCHING)
        {
            stopInit2ndStage();

            m_mplayerSrv->closeMusicPlayer();

            return VFX_APP_CLOSE_ANSWER_YES;
        }

        // cancel all actions
        closeAllPopup();

        // cacnel selection
        if (isSelecting())
        {
            // do not need to switch off multi-select UI since APP is leaving
            m_provider->selectEnd();
            setActionMode(ACTION_NONE);
        }

        if (getCurrListMenu())
        {
            getCurrListMenu()->setIsFreezed(VFX_TRUE);
        }

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
        if (!m_mplayerSrv->getMemoryCardReady())
        {
            // close music player service since it can not work without memory card
            m_mplayerSrv->closeMusicPlayer();
        }
#endif

        return VFX_APP_CLOSE_ANSWER_YES;
    }

    return VFX_APP_CLOSE_ANSWER_YES;
}

void VappMusicPlayerApp::onAppClosingShrinkDB()
{
    SrvDBStateEnum DBState = m_mplayerSrv->getDBState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_APP_CLOSING_SHRINK_DB, DBState);

    if (DBState == DB_OPENING || DBState == DB_CLOSE || m_actionMode == ACTION_FATAL_ERROR)
    {
        m_mplayerSrv->closeMusicPlayer();
    }
    else if (DBState == DB_NORMAL)
    {
        // shrink memory
        m_mplayerSrv->initPLSV();
    }
    else if (DBState == DB_SHRINK)
    {
        // Close App while launching from BG, do nothing
    }
}

void VappMusicPlayerApp::onGroupActive(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_GROUP_ACTIVE);

    if (!m_mplayerSrv)
    {
        m_mplayerSrv = getMusicPlayerSrv();
    }

    //sendShowHideEvent(VFX_TRUE);

    updateWaitIconPos();

    if (m_snapGblOrientation != m_curGblOrientation)
    {
        // use post invoke to make sure isGroupTopActive() return TRUE
        vfxPostInvoke1(this, &VappMusicPlayerApp::onProcOrientationChange, m_curGblOrientation);
    }
}

void VappMusicPlayerApp::onGroupInactive(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_GROUP_INACTIVE, m_actionMode, m_ctrlPlayback->getPlayState());

    if (m_nowPlaying)
    {
        m_nowPlaying->closeMetaParser();
    }

    if (m_coverFlow)
    {
        m_coverFlow->closeMetaParser();
    }

    if (m_provider)
    {
        m_provider->freeMediaCache();

        if (!m_isDying)
        {
            VappMusicPlayerListMenu *listMenu = getCurrListMenu();
            if (listMenu)
            {
                listMenu->setIsFreezed(VFX_FALSE);
            }

            // close confirm popup and clear action mode since user may resume interrupt play in lock screen
            if (m_popupConfirm && (m_actionMode == ACTION_RESET || m_actionMode == ACTION_REFRESH))
            {
                popupConfirmClose();
                setActionMode(ACTION_NONE);
            }

            // stop the resetting or refreshing, since refreshing will allocate the foreground memory
            if (m_popupWaiting && (m_actionMode == ACTION_RESET || m_actionMode == ACTION_REFRESH))
            {
                // this case is going to shut down when doing refresh, cancel refresh DB directly instead of using post event
                popupWaitingClose();

                if (m_actionMode == ACTION_RESET || m_actionMode == ACTION_LAUNCHING)
                {
                    m_mplayerSrv->openDBCancel();

                    // Since the reset action can't be canceled, so exit app in abort by other app
                    if(m_actionMode == ACTION_RESET)
                    {
                        //exit();                        
                        m_mplayerSrv->closeMusicPlayer();
                        return;
                    }

                    setActionMode(ACTION_NONE);
                }
                else if (m_actionMode == ACTION_REFRESH)
                {
                    m_provider->refreshDBCancel();
                    setActionMode(ACTION_NONE);
                    //MAUI_03104522: Update count if refresh is interrupted. (It will not update count in page onEnter())
                    m_provider->updateCount();
                }
            }
        }
        else if (m_actionMode == ACTION_FATAL_ERROR && m_isDying)
        {
            //exit();            
            m_mplayerSrv->closeMusicPlayer();
            return;
        }
    }

    m_snapGblOrientation = m_curGblOrientation;

    //sendShowHideEvent(VFX_FALSE);
}

void VappMusicPlayerApp::onGroupHidden(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_GROUP_HIDDEN);

    VfxApp::onGroupHidden();
}

void VappMusicPlayerApp::onGroupUnhidden(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_GROUP_UNHIDDEN, m_actionMode);
       
    VfxApp::onGroupUnhidden();
}

void VappMusicPlayerApp::init1stStage(void)
{
    SWLA_BEGIN("MR2");  

    m_mplayerSrv = getMusicPlayerSrv();
    VFX_ASSERT(m_mplayerSrv);
    SrvDBStateEnum DBState = m_mplayerSrv->getDBState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_INIT_1ST_STAGE, DBState);

    VFX_OBJ_CREATE(m_rootScreen, VappMusicPlayerScreen, this);
    m_rootScreenWeakPtr = m_rootScreen;

    m_mplayerSrv->checkMemoryCardReady();
    m_mplayerSrv->m_signalMDICallback.connect(this, &VappMusicPlayerApp::onMDICallback);

    m_ctrlPlayback = m_mplayerSrv->getCtrlPlayback();

    if (DBState == DB_CLOSE)
    {        
        setActionMode(ACTION_LAUNCHING);
        m_mplayerSrv->setDBState(DB_OPENING);
        // set srv DB state to OPENING, then OPEN DB in 2nd state initialization
    }
    else if (DBState == DB_SHRINK)
    {
        setActionMode(ACTION_LAUNCHING_FROM_BG);
    }
    else if (DBState == DB_OPENING)
    {
        setActionMode(ACTION_LAUNCHING);
    }
    else
    {
        VFX_ASSERT(0);
    }

    SWLA_END("MR2");
    SWLA_BEGIN("MR3");
    VFX_OBJ_CREATE(m_tabPage, VappMusicPlayerTabPage, m_rootScreen);
    SWLA_END("MR3");
    SWLA_BEGIN("MR4");
    disableTabPageTab(VFX_TRUE);

    m_ctrlPlayback->m_signalPlaybackStateChange.connect(this, &VappMusicPlayerApp::onPlaybackStateChange);
    m_ctrlPlayback->m_signalShowHideWaitIcon.connect(this, &VappMusicPlayerApp::onShowHideWaitIcon);
    m_ctrlPlayback->setIsAppMode(VFX_TRUE);

    SWLA_END("MR4");
    SWLA_BEGIN("MR5");

    m_rootScreen->pushPage(VIEW_TYPE_TAB_PAGE, m_tabPage);
    m_rootScreen->show();

    SWLA_END("MR5");
    SWLA_BEGIN("MR6");

    VFX_OBJ_CREATE(m_searchTimer, VfxTimer, this);
    m_searchTimer->setStartDelay(300);
    m_searchTimer->m_signalTick.connect(this, &VappMusicPlayerApp::onSearchTimerTick);

    m_searchText.setEmpty();
    m_preSearchText.setEmpty();

    VFX_OBJ_CREATE(m_delayUpdatePrevNext, VfxTimer, this);
    m_delayUpdatePrevNext->setStartDelay(5);
    m_delayUpdatePrevNext->m_signalTick.connect(this, &VappMusicPlayerApp::onPrevNextDelayUpdateTimeout);

    // Get NCenter singleton and connect signal
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (NCenter)
    {
        NCenter->m_signalEvent.connect(this, &VappMusicPlayerApp::onNCenterStatus);
    }

    registerCBEvent(EVT_ID_SRV_SHUTDOWN_DEINIT, VFX_TRUE);
    registerCBEvent(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VFX_TRUE);
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_UCM_STATUS_CHANGE, VFX_TRUE);

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
    // regiester orientation event for cover flow
    registerCBEvent(EVT_ID_ORIENTATION_CHANGED, VFX_TRUE);
#endif

    // register AVRCP
    g_this = this;

    m_longTapComm.action = ACTION_NONE;
    m_longTapComm.index = 0;

    m_playAfterAction.raised = VFX_FALSE;
    m_playAfterAction.delayPlay = VFX_FALSE;
    m_playAfterAction.isNext = VFX_FALSE;
    m_playAfterAction.nextMode = AUTO_NEXT;

    VfxScrRotateTypeEnum rotateType = vfx_adp_srs_get_value();
    if (rotateType == VFX_SCR_ROTATE_TYPE_90)
    {
        m_curGblOrientation = MMI_FRM_SCREEN_ROTATE_90;
    }
    else if (rotateType == VFX_SCR_ROTATE_TYPE_270)
    {
        m_curGblOrientation = MMI_FRM_SCREEN_ROTATE_270;
    }
    else
    {
        m_curGblOrientation = MMI_FRM_SCREEN_ROTATE_0;
    }
    m_snapGblOrientation = m_curGblOrientation;

    m_mplayerSrv->sendOpenCloseEvent(VFX_TRUE);

    SWLA_END("MR6");
}

void VappMusicPlayerApp::init2ndStage(VfxBool showWaiting)
{
    SWLA_BEGIN("MR7");

    SrvDBStateEnum DBState = m_mplayerSrv->getDBState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_INIT_2ND_STAGE, DBState, m_actionMode);

    m_delayInitStage = showWaiting ? 0 : 1;

    if (m_actionMode == ACTION_LAUNCHING || m_actionMode == ACTION_LAUNCHING_FROM_BG)
    {
        // Start a timer to init PLSV
        VFX_OBJ_CREATE(m_delayPLSVTimer, VfxTimer, this);
        m_delayPLSVTimer->setStartDelay(showWaiting ? 10 : 1);
        m_delayPLSVTimer->m_signalTick.connect(this, &VappMusicPlayerApp::init2ndStageTimerTimeout);
        m_delayPLSVTimer->start();

        // Disable tab
        disableTabPageTab(VFX_TRUE);
    }

    SWLA_END("MR7");
}

void VappMusicPlayerApp::stopInit2ndStage(void)
{
    SrvDBStateEnum DBState = m_mplayerSrv->getDBState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_STOP_INIT_2ND_STAGE, DBState, m_actionMode);

    if(m_delayPLSVTimer)
    {
        m_delayPLSVTimer->stop();
        VFX_OBJ_CLOSE(m_delayPLSVTimer);
    }

    if (m_actionMode == ACTION_LAUNCHING || m_actionMode == ACTION_LAUNCHING_FROM_BG)
    {
        m_mplayerSrv->openDBCancel();
    }
}

void VappMusicPlayerApp::init2ndStageTimerTimeout(VfxTimer *timer)
{
    SWLA_BEGIN("MR8");

    SrvDBStateEnum DBState = m_mplayerSrv->getDBState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_INIT_2ND_STAGE_TIMEOUT, m_delayInitStage, DBState, m_actionMode);

    switch(m_delayInitStage)
    {
        case 0:
            {
                // Show wait icon
                showWaitIcon();

                // Use timer to let icon show and then blocking init PLSV
                m_delayPLSVTimer->setStartDelay(1);
                m_delayPLSVTimer->start();
                
                m_delayInitStage = 1;
            }
            break;

        case 1:
            {
                getProvider();

                VappMusicPlayerSubPage *page = getTabPage(FUNC_ID_TAB_ALL_SONG);
                page->initListMenu(VCP_LIST_MENU_CELL_STYLE_CUSTOM, VFX_TRUE);
                page->onEnter(VFX_FALSE);

                // Use timer to avoid enableSearchBar() in initListMenu() block progress icon show
                m_delayPLSVTimer->setStartDelay(0);
                m_delayPLSVTimer->start();
                
                m_delayInitStage = 2;
            }
            break;

        case 2:
            {
                if ((DBState == DB_OPENING || DBState == DB_SHRINK)
                 && (m_actionMode == ACTION_LAUNCHING || m_actionMode == ACTION_LAUNCHING_FROM_BG))
                {
                    m_mplayerSrv->initPLSV();
                }
                else if (DBState == DB_NORMAL && (m_actionMode == ACTION_LAUNCHING || m_actionMode == ACTION_LAUNCHING_FROM_BG))
                {
                    // already opening DB ok during App launching and init2ndStage connecting App::onPLSVCallback to signal
                    // the OPEN OK callback will not be handled by App::onPLSVCallback
                    m_mplayerSrv->signalOpenDBOK();
                }

                if (m_delayPLSVTimer)
                {
                    VFX_OBJ_CLOSE(m_delayPLSVTimer);
                    m_delayPLSVTimer = NULL;
                }

                // send this event again after content provider is created, so that widget could get the correct provider pointer now
                m_mplayerSrv->sendOpenCloseEvent(VFX_TRUE);

                VappMusicPlayerSubPage *page = getTabPage(FUNC_ID_TAB_ALL_SONG);
                page->updateAll();
            }
            break;

        default:
            break;
    }

    SWLA_END("MR8");
}

void VappMusicPlayerApp::setIsUnhiddenByNCenter()
{
    m_isLaunchByMainMenu = VFX_FALSE;
}

void VappMusicPlayerApp::checkLaunchToNowPlaying()
{
    if (!m_isLaunchByMainMenu)
    {
        // go to now playing if lauchned by widget or NCenter and is playing song
        VfxBool isLaunchToNowPlaying = VFX_FALSE;
        if (m_ctrlPlayback)
        {
            PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
            if ((state == PB_STATE_PLAY 
              || state == PB_STATE_PAUSE
              || state == PB_STATE_STOP
              || state == PB_STATE_SEEKING
              || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING 
              || state == PB_STATE_BT_CONNECTING_WHILE_RESUME
              || state == PB_STATE_INTERRUPTED
              || state == PB_STATE_OPEN
              || state == PB_STATE_SWITCHING_PLAY)
              && m_mplayerSrv->getActiveCount() > 0)
            {
                if (m_curGblOrientation != MMI_FRM_SCREEN_ROTATE_0)
                {
                    m_curAppOrientation = m_curGblOrientation;
                }
                
                isLaunchToNowPlaying = VFX_TRUE;
            }
        }
        
        if (isLaunchToNowPlaying)
        {
            if (m_actionMode == ACTION_LAUNCHING_FROM_BG)
            {
                getProvider();
                m_mplayerSrv->initPLSV();
            }

            if (m_actionMode != ACTION_FATAL_ERROR)
            {
                closeAllPopup();

                goToRoot();

                goToNowPlaying();

                m_nowPlaying->m_isLaunchToNowPlaying = VFX_TRUE;
            }
        }

        m_isLaunchByMainMenu = VFX_FALSE;

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_CHECK_LAUNCH_TO_NP, 0, isLaunchToNowPlaying);
        return;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_CHECK_LAUNCH_TO_NP, 1, 0);
}

void VappMusicPlayerApp::setIsDying()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SET_IS_DYING);

    if (m_actionMode == ACTION_RESET 
     || m_actionMode == ACTION_LAUNCHING 
     || m_actionMode == ACTION_REOPENING_DB 
     || m_actionMode == ACTION_REOPENING_DB_REALLOC)
    {
        m_mplayerSrv->openDBCancel();

        setActionMode(ACTION_NONE);
    }

    m_isDying = VFX_TRUE;

    // DB is not necessarily closed, but better not to access when APP is dying
    if (m_provider)
    {
        m_provider->setIsReady(VFX_FALSE);
    }
}

VfxBool VappMusicPlayerApp::getIsDying()
{
    return m_isDying;
}

VfxBool VappMusicPlayerApp::isMakingCall()
{
    return m_mplayerSrv->isMakingCall();
}

VfxBool VappMusicPlayerApp::blockActionInCall(VfxBool showMessage)
{
    return m_mplayerSrv->blockActionInCall(showMessage);
}

void VappMusicPlayerApp::turnOnBackLight()
{
    m_mplayerSrv->turnOnBackLight();
}

VfxBool VappMusicPlayerApp::isBackLightOn()
{
    return m_mplayerSrv->isBackLightOn();
}

void VappMusicPlayerApp::sendShowHideEvent(VfxBool isShow)
{
    // send APP show/hide event
    VappMusicPlayerShowHideEvtStruct evt;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_MUSICPLY_SHOW_HIDE);
    evt.isShow = isShow;

    // Get detail info
    srv_plst_media_details_struct *detailInfo = NULL;
    VFX_ALLOC_MEM(detailInfo, sizeof(srv_plst_media_details_struct), this);
    
    if(m_mplayerSrv->getCurrDetailInfo(detailInfo))
    {
        vfx_sys_wcscpy(evt.artist, detailInfo->artist);
        vfx_sys_wcscpy(evt.title, detailInfo->title);
    }
    else if(m_mplayerSrv->getActiveCount() == 0)
    {
        kal_mem_set(evt.artist, 0, sizeof(evt.artist));
        vfx_sys_wcscpy(evt.artist, (const VfxWChar*)GetString(STR_ID_VAPP_MUSIC_PLAYER_NO_SONG_PLAYING));
        vfx_sys_wcscpy(evt.title, (const VfxWChar *)GetString(STR_ID_VAPP_MUSIC_PLAYER));
    }
    else
    {
        vfx_sys_wcscpy(evt.artist, (const VfxWChar*)GetString(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST));
        vfx_sys_wcscpy(evt.title, (const VfxWChar *)GetString(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG));
    }
    
    VFX_FREE_MEM(detailInfo);
    
    MMI_FRM_CB_EMIT_EVENT(&evt);
}

void VappMusicPlayerApp::eventHandler(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_EVENT_HANDLER, id, m_actionMode);

    switch (id)
    {
    case FUNC_ID_TB_BTN_COVER_FLOW:
        goToCoverFlow(VFX_SCR_ROTATE_TYPE_270);
        break;

    case FUNC_ID_TB_BTN_NOW_PLAYING:
        goToNowPlaying();
        break;

    case FUNC_ID_TB_BTN_ADD_TO_PLAYLIST:
        onFuncAddToPlaylist();
        break;

    case FUNC_ID_TB_BTN_NEW_PLAYLIST:
        onFuncNewPlaylist();
        break;

    case FUNC_ID_TB_BTN_PLAY:
        if (blockActionInCall())
        {
            break;
        }

        if (m_provider && m_provider->getCount() > 0)
        {
            goToNowPlaying(0, VFX_TRUE);
        }
        break;

    case FUNC_ID_TB_BTN_REFRESH:
        setActionMode(ACTION_REFRESH);

        // clear the focus of search bar, or list menu will be scrolled to top after popup is closed
        if(isTabPage())
        {
            VappMusicPlayerSubPage *page = getCurrPage();
            if (page)
            {
                page->resetFocusChild();
            }
        }

        popupConfirm(
            VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_REFRESH_HINT),
            VFX_WSTR_RES(STR_GLOBAL_CONTINUE), 
            VCP_POPUP_TYPE_WARNING
            );
        break;

    case FUNC_ID_TB_BTN_DELETE:
        setActionMode(ACTION_DELETE);
        onFuncDeleteStep1();
        break;

    case FUNC_ID_TB_BTN_PLAYLIST_ADD_SONG:
        {
            setActionMode(ACTION_PLAYLIST_ADD_SONG);

            // save list menu view state here because after create new screen, getCurrListMenu() would get incorrect one
            VappMusicPlayerListMenu *listMenu = getCurrListMenu();
            if (listMenu)
            {
                listMenu->savePosition();
            }

            VfxBool ret = m_rootScreen->goToNextPage(VIEW_TYPE_VIEW_SELECT, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TITLE_ADD_TO_PLST));
            if (!ret) return;
        }
        break;

    case FUNC_ID_TB_BTN_PLAYLIST_ARRANGE:
        {
            onFuncRearrangeStart();
        }
        break;

    case FUNC_ID_TB_BTN_PLAYLIST_REMOVE:
        setActionMode(ACTION_PLAYLIST_REMOVE);
        onFuncDeleteStep1();
        break;

    case FUNC_ID_TB_BTN_PLAYLIST_RENAME:
        onFuncPlaylistRename();
        break;

    // Confirm toolbar button
    case FUNC_ID_TB_BTN_OK:
        if (m_actionMode == ACTION_DELETE || m_actionMode == ACTION_PLAYLIST_REMOVE)
        {
            onFuncDeleteStep2();
        }
        else if (m_actionMode == ACTION_ADD_TO_PLAYLIST)
        {           
            onFuncAddToPlaylistSelect();
        }
        else if (m_actionMode == ACTION_PLAYLIST_ADD_SONG)
        {
            onFuncPlaylistAddSong();
        }
        break;

    case FUNC_ID_TB_BTN_CANCEL:
        if (m_actionMode == ACTION_PLAYLIST_ADD_SONG)
        {
            VappMusicPlayerSubPage *page = getCurrPage();
            if (page)
            {
                pageMultiSelectOff(page);
                page->exit();
            }
            onKeyBack();
        }
        else if (m_actionMode == ACTION_ADD_TO_PLAYLIST 
              || m_actionMode == ACTION_DELETE
              || m_actionMode == ACTION_PLAYLIST_REMOVE)
        {
            // Multi select page with cancel button
            pageMultiSelectOff(getPageBeforeAction());
            setActionMode(ACTION_NONE);
            m_longTapComm.action = ACTION_NONE;
            m_selectItemIdx = VAPP_MUSICPLY_DEF_LARGE_NUM;
        }
        else
        {
            // this case should not happen
            VFX_ASSERT(0);
        }
        break;
    
    case FUNC_ID_TB_BTN_SELECT_ALL:
        {
            if (m_provider->isSelectAll())
            {
                m_provider->deselectAll();
            }
            else
            {
                m_provider->selectAll();
            }

            updateSelectingUI();        

            VappMusicPlayerListMenu *listMenu = getCurrListMenu();
            listMenu->updateAllControls();
        }
        break;

    
    // Popup
    case VCP_CONFIRM_POPUP_BUTTON_OK:
    case VCP_CONFIRM_POPUP_BUTTON_USER_1:   // confirm ok
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_EVENT_HANDLER_OK_ACTION_D, m_actionMode);

        if (m_actionMode == ACTION_RESET)
        {
            m_mplayerSrv->setPlayAfterSwitchSong(VFX_TRUE);
            
            m_ctrlPlayback->clearInterruptState();
            
            onStop();
            
            onFuncResetDB();
            
            m_mplayerSrv->sendPlayStopEvent();
        }
        else if (m_actionMode == ACTION_REFRESH)
        {
            onFuncRefreshDB();
        }
        else if (m_actionMode == ACTION_DELETE || m_actionMode == ACTION_PLAYLIST_REMOVE)
        {
            if (m_actionMode == ACTION_DELETE)
            {
                popupProgress(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETING));
            }
            else
            {
                popupProgress(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVING));
            }

            if (m_longTapComm.action == ACTION_DELETE || m_longTapComm.action == ACTION_PLAYLIST_REMOVE)
            {
                m_provider->del(m_longTapComm.index);
            }
            else
            {
                VappMusicPlayerSubPage *page = getCurrPage();
                if (page && page->m_cellTimer)
                {
                    page->m_cellTimer->stop();
                }
                
                m_provider->delSelected();
            }
        }
        else if (m_actionMode == ACTION_PLAYLIST_NEW || m_actionMode == ACTION_PLAYLIST_RENAME)
        {
            // confirm duplicated name
            if (m_popupInput)
            {
                m_popupInput->show(VFX_TRUE);
            }
        }
        else if (m_actionMode == ACTION_FATAL_ERROR)
        {
            // fail to open DB or enter first view
            setIsDying();
            //exit(); // Will close app object immediately
            m_mplayerSrv->closeMusicPlayer();
            return;
        }
        
        m_popupConfirm = NULL;
        break;

    case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
    case VCP_CONFIRM_POPUP_BUTTON_USER_2:   // confirm cancel
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_EVENT_HANDLER_CANCEL_ACTION_D, m_actionMode);

        if (m_actionMode == ACTION_FATAL_ERROR && m_isDying)
        {
            //exit(); // Will close app object immediately            
            m_mplayerSrv->closeMusicPlayer();
            return;
        }
        else if ((m_actionMode != ACTION_DELETE && m_actionMode != ACTION_PLAYLIST_REMOVE))
        {
            setActionMode(ACTION_NONE);
            if (isSelecting())
            {
                m_provider->selectEnd();
                updateContent();
            }
        }
        else if (m_longTapComm.action == ACTION_DELETE || m_longTapComm.action == ACTION_PLAYLIST_REMOVE)
        {
            setActionMode(ACTION_NONE);
            m_longTapComm.action = ACTION_NONE;
        }
        
        m_popupConfirm = NULL;
        break;

    case VCP_POPUP_BUTTON_NO_PRESSED:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_EVENT_HANDLER_NO_PRESS_ACTION_D, m_actionMode);
        
        if (m_actionMode == ACTION_FATAL_ERROR)
        {
            // Will close app directly
            eventHandler(NULL, VCP_CONFIRM_POPUP_BUTTON_OK);
            return;
        }

        m_popupConfirm = NULL;
        break;
    };
}

void VappMusicPlayerApp::onListMenuItemTapped(VcpListMenu *sender, VfxU32 index)
{
    const PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_LIST_MENU_ITEM_TAPPED, index, state, m_actionMode);

    if (m_actionMode == ACTION_FATAL_ERROR)
    {
        return; 
    }

    VappMusicPlayerListMenu *listMenu = getCurrListMenu();
    if (listMenu && (listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION
                  || listMenu->getMenuMode() == VCP_LIST_MENU_MODE_REORDER))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_LIST_MENU_ITEM_TAPPED_LIST_MENU_MODE_INVALID);
        return;
    }

    VappMusicPlayerScreen* scr = m_rootScreen;
    ViewTypeEnum curViewType = scr->getViewStack();
    
    switch (curViewType)
    {
        // tap a song and go to now playing
        case VIEW_TYPE_ALL_SONGS:
        case VIEW_TYPE_ARTIST_SONG:
        case VIEW_TYPE_ALBUM_SONG:
        case VIEW_TYPE_PLAYLIST_SONG:
        case VIEW_TYPE_ARTIST_ALBUM_SONG:
        {
            if (blockActionInCall())
            {
                break;
            }

            // Stop error timer when tap to play a new song (To avoid jump to next file after info ballon disappear)
            if(m_nowPlaying != NULL)
            {
                m_nowPlaying->clearErrorMessage();
            }

            m_mplayerSrv->setPlayAfterSwitchSong(VFX_TRUE);

            // Keep duration of current tapped item (this cache will updated in getItemText when user tap the item)
            ListItemDataStruct listItemCache = m_provider->getListItemCache();
            
            // Go to now playing screen and play
            goToNowPlaying(index, VFX_TRUE);

            break;
        }
        // tap a song in cover flow album detail panel
        case VIEW_TYPE_COVER_FLOW_SONG:
            {
                if (blockActionInCall())
                {
                    break;
                }

                m_mplayerSrv->setPlayAfterSwitchSong(VFX_TRUE);

                SongInfoStruct info;
                info.index = index;
                m_mplayerSrv->setActive(info.index);
                m_mplayerSrv->getCurrInfo(info);

                m_mplayerSrv->initActiveListValidState();
                
                if(m_coverFlow != NULL)
                {
                    m_coverFlow->clearErrorMessage();
                }

                playerPagePlaySong(info, PAGE_SWITCH_DIR_NONE, VFX_FALSE);
            }
            break;

        // tap an item and go to next level
        case VIEW_TYPE_ARTIST:
        case VIEW_TYPE_ALBUM:
        case VIEW_TYPE_ARTIST_ALBUM:
        case VIEW_TYPE_PLAYLIST:
        case VIEW_TYPE_PLAYLIST_ADD_ARTIST:
        case VIEW_TYPE_PLAYLIST_ADD_ALBUM:
            {
                // Get the title for next page
                VfxWString str;
                if (curViewType == VIEW_TYPE_ARTIST_ALBUM)
                {
                    if (index == 0)
                    {
                        VappMusicPlayerSubPage *page = getCurrPage();
                        if (page)
                        {
                            str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_ALL_SONGS_OF); // Pre string
                            str += page->getTitleBar()->getTitle();
                            str += VfxWString().loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_ALL_SONGS_OF_POST); // Post string (For Chinese)
                        }
                    }
                    else
                    {
                        m_provider->getTitle(index-1, str);
                    }
                }
                else
                {
                    m_provider->getTitle(index, str);
                }

                ViewTypeEnum nextView = VIEW_TYPE_NONE;

                if (curViewType == VIEW_TYPE_ARTIST)
                {
                    m_selectItemCount = m_provider->getHintCount(index, SRV_PLST_VIEW_MEDIA);
                    m_selectItemId = m_provider->getID(index);
                    index = m_selectItemId;
                    nextView = VIEW_TYPE_ARTIST_ALBUM;
                }
                else if(curViewType == VIEW_TYPE_ALBUM)
                {
                    m_selectItemId = m_provider->getID(index);
                    index = m_selectItemId;
                    nextView = VIEW_TYPE_ALBUM_SONG;
                }
                else if(curViewType == VIEW_TYPE_ARTIST_ALBUM)
                {
                    if (index == 0)
                    {
                        nextView = VIEW_TYPE_ARTIST_SONG;
                        index = m_selectItemId;
                    }
                    else
                    {
                        nextView = VIEW_TYPE_ARTIST_ALBUM_SONG;
                        index--;
                    }
                }
                else if(curViewType == VIEW_TYPE_PLAYLIST)
                {
                    m_selectItemIdx = index;
                    m_selectItemId = m_provider->getID(index);
                    nextView = VIEW_TYPE_PLAYLIST_SONG;
                }
                else if(curViewType == VIEW_TYPE_PLAYLIST_ADD_ARTIST)
                {
                    nextView = VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG;
                }
                else if(curViewType == VIEW_TYPE_PLAYLIST_ADD_ALBUM)
                {
                    nextView = VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG;
                }

                // freeze the page before set view type
                if (listMenu)
                {
                    listMenu->setIsFreezed(VFX_TRUE);
                }

                scr->goToNextPage(nextView, str, index);
            }
            break;

        case VIEW_TYPE_PLAYLIST_SELECT:
            if(m_actionMode == ACTION_ADD_TO_PLAYLIST)
            {
                if (index == 0)
                {
                    // new playlist
                    onFuncNewPlaylist();
                    
                    if (listMenu)
                    {
                        listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
                        listMenu->updateAllItems();
                    }
                }
                else
                {
                    m_selectItemIdx = index - 1;

                    if (listMenu)
                    {
                        listMenu->setIsUnhittable(VFX_TRUE);
                    }

                    // delay executing add to playlist and popup waiting to let list menu high light disappear
                    VfxTimer *t;
                    VFX_OBJ_CREATE(t, VfxTimer, this);
                    t->setStartDelay(100);
                    t->m_signalTick.connect(this, &VappMusicPlayerApp::postProcAddToPlaylist);
                    t->start();
                }
            }
            break;

        case VIEW_TYPE_NOW_PLAYING_LIST:
            // tap a song of now playing list to play and go back to now playing
            {
                if (blockActionInCall())
                {
                    break;
                }

                // Stop error timer when tap to play a new song (To avoid jump to next file after info ballon disappear)
                if(m_nowPlaying != NULL)
                {
                    m_nowPlaying->clearErrorMessage();
                }

                // Pop page and go back to now playing
                scr->popPage();
                
                SongInfoStruct info;
                info.index = index;
                // Set active but not update database, update it when onEntered() by calling setActiveToDBUseCurrent()
                m_mplayerSrv->setActive(info.index, VFX_FALSE);
                m_mplayerSrv->getCurrInfo(info);

                m_mplayerSrv->initActiveListValidState();

                m_doPlayOnEntered = VFX_TRUE;
                if (m_nowPlaying)
                {
                    nowPlayingSetFavorite();
                }

                nowPlayingPlaySong(info);

                // set view type after play song, so that clearLyrics triggered by onPlaybackStateChange will hide lyrics without animation (isTop() return FALSE)
                setViewType(VIEW_TYPE_NOW_PLAYING, CHANGE_VIEW_MODE_BACK, index);
                if (checkPLSVAction() == VFX_FALSE) return;
            }
            break;

        case VIEW_TYPE_VIEW_SELECT:
            {
                // freeze the page before set view type
                if (listMenu)
                {
                    listMenu->setIsFreezed(VFX_TRUE);
                }

                if (index == 0)
                {
                    m_rootScreen->goToNextPage(VIEW_TYPE_PLAYLIST_ADD_ALL_SONG, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_SONG));
                }
                else if (index == 1)
                {
                    m_rootScreen->goToNextPage(VIEW_TYPE_PLAYLIST_ADD_ARTIST, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_ARTIST));
                }
                else if (index == 2)
                {
                    m_rootScreen->goToNextPage(VIEW_TYPE_PLAYLIST_ADD_ALBUM, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_ALBUM));
                }
                else
                {
                    VFX_ASSERT(0);
                }
            }
            break;

        default:
            break;
    }
}

void VappMusicPlayerApp::onListMenuItemLongTapped(VcpListMenu *sender, VfxU32 index)
{
    PlaybackStateEnum state = m_ctrlPlayback->getPlayState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_LIST_MENU_ITEM_LONG_TAPPED, index, state, m_actionMode);

    ViewTypeEnum viewType = getViewType();

    if (m_actionMode == ACTION_FATAL_ERROR)
    {
        return; 
    }
    else if (m_actionMode == ACTION_ADD_TO_PLAYLIST && viewType == VIEW_TYPE_PLAYLIST_SELECT)
    {
        // not handle long tapping in VIEW_TYPE_PLAYLIST_SELECT
        return;
    }

    // show VcpMenuPopup
    VfxWString title;
    VcpListMenuTextColorEnum color;
    m_provider->getItemText(index, VCP_LIST_MENU_FIELD_TEXT, title, color);
    m_longTapComm.index = index;

    switch (viewType)
    {
        case VIEW_TYPE_ALL_SONGS:
        case VIEW_TYPE_ARTIST_SONG:
        case VIEW_TYPE_ARTIST_ALBUM_SONG:
        case VIEW_TYPE_ALBUM_SONG:
        {
            VappMusicPlayerMenuPopupItemStruct itemList[2];
            itemList[0].id = FUNC_ID_CM_ADD_TO_PLAYLIST;
            itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO_PLST);
            itemList[1].id = FUNC_ID_CM_DELETE;
            itemList[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            popupMenu(title, itemList, 2);
            
            break;
        }

        case VIEW_TYPE_ARTIST:
        case VIEW_TYPE_ARTIST_ALBUM:
        case VIEW_TYPE_ALBUM:
        {
            if (viewType == VIEW_TYPE_ARTIST_ALBUM)
            {
                // Consider the first item is All songs (Artist's album view)
                m_longTapComm.index--;
            }

            if (index == 0 && viewType == VIEW_TYPE_ARTIST_ALBUM)
            {
                // "All songs of artist" not support long tap
                /*
                VappMusicPlayerMenuPopupItemStruct itemList[2];
                itemList[0].id = FUNC_ID_CM_PLAY;
                itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
                itemList[1].id = FUNC_ID_CM_ADD_TO_PLAYLIST;
                itemList[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO_PLST);
                popupMenu(title, itemList, 2);
                */
                return;
            }
            else
            {
                VappMusicPlayerMenuPopupItemStruct itemList[3];
                itemList[0].id = FUNC_ID_CM_PLAY;
                itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
                itemList[1].id = FUNC_ID_CM_ADD_TO_PLAYLIST;
                itemList[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO_PLST);
                itemList[2].id = FUNC_ID_CM_DELETE;
                itemList[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
                popupMenu(title, itemList, 3);
            }
            break;
        }

        case VIEW_TYPE_PLAYLIST:
        {
            if (index == 0)
            {
                if (m_provider->getHintCount(0, SRV_PLST_VIEW_MEDIA) > 0)
                {
                    VappMusicPlayerMenuPopupItemStruct itemList[1];
                    itemList[0].id = FUNC_ID_CM_PLAY;
                    itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
                    popupMenu(title, itemList, 1);
                }
                else
                {
                    return;
                }
            }
            else
            {
                if (m_provider->getHintCount(index, SRV_PLST_VIEW_MEDIA) > 0)
                {
                    VappMusicPlayerMenuPopupItemStruct itemList[3];
                    itemList[0].id = FUNC_ID_CM_PLAY;
                    itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
                    itemList[1].id = FUNC_ID_CM_RENAME;
                    itemList[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_RENAME);
                    itemList[2].id = FUNC_ID_CM_DELETE;
                    itemList[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
                    popupMenu(title, itemList, 3);
                }
                else
                {
                    VappMusicPlayerMenuPopupItemStruct itemList[2];
                    itemList[0].id = FUNC_ID_CM_RENAME;
                    itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_RENAME);
                    itemList[1].id = FUNC_ID_CM_DELETE;
                    itemList[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
                    popupMenu(title, itemList, 2);
                }
            }
            break;
        }
        
        case VIEW_TYPE_PLAYLIST_SONG:
        {
            VappMusicPlayerMenuPopupItemStruct itemList[1];
            itemList[0].id = FUNC_ID_CM_REMOVE;
            itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
            popupMenu(title, itemList, 1);
            break;
        }
        case VIEW_TYPE_NOW_PLAYING_LIST:
        {
            VappMusicPlayerMenuPopupItemStruct itemList[1];
            if (m_provider->getActiveListType() == SRV_PLST_ACTIVE_LIST_AUDIO)
            {
                itemList[0].id = FUNC_ID_CM_DELETE;
                itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            }
            else if (m_provider->getActiveListType() == SRV_PLST_ACTIVE_LIST_PLST)
            {
                itemList[0].id = FUNC_ID_CM_REMOVE;
                itemList[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
            }
            else
            {
                // this case should not happen
                itemList[0].str.format("Unknow type remove");
            }
            popupMenu(title, itemList, 1);
            break;
        }
        default:
        {
            return;
        }
    };

    // clear the focus of search bar, or list menu will be scrolled to top after popup is closed
    if(isTabPage())
    {
        VappMusicPlayerSubPage *page = getCurrPage();
        if (page)
        {
            page->resetFocusChild();
        }
    }

    // Touch feedback for long press
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
}

void VappMusicPlayerApp::onMenuItemTapped(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_MENU_ITEM_TAPPED, event);

    if (m_actionMode == ACTION_FATAL_ERROR)
    {
        return; 
    }

    if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        VfxId id = item->getId();
        switch (id)
        {
            case FUNC_ID_CM_PLAY:
                if (blockActionInCall())
                {
                    break;
                }

                if (getViewType() == VIEW_TYPE_PLAYLIST)
                {
                    m_selectItemId = m_provider->getID(m_longTapComm.index);

                    if (m_provider->getHintCount(m_longTapComm.index, SRV_PLST_VIEW_MEDIA) > 0)
                    {
                        goToNowPlaying(m_longTapComm.index, VFX_TRUE);
                    }
                }
                else
                {
                    if (m_provider->getCount() > 0)
                    {
                        goToNowPlaying(m_longTapComm.index, VFX_TRUE);
                    }
                }
                break;

            case FUNC_ID_CM_ADD_TO_PLAYLIST:
                setActionMode(ACTION_ADD_TO_PLAYLIST);
                m_longTapComm.action = ACTION_ADD_TO_PLAYLIST;
                onFuncAddToPlaylistSelect();
                break;

            case FUNC_ID_CM_DELETE:
            case FUNC_ID_CM_REMOVE:
                if (id == FUNC_ID_CM_DELETE)
                {
                    setActionMode(ACTION_DELETE);
                    m_longTapComm.action = ACTION_DELETE;
                }
                else
                {
                    setActionMode(ACTION_PLAYLIST_REMOVE);
                    m_longTapComm.action = ACTION_PLAYLIST_REMOVE;
                }

                onFuncDeleteStep2(VFX_FALSE);
                break;

            case FUNC_ID_CM_RENAME:
                onFuncPlaylistRename();
                break;
        };
    }

    m_popupMenu = NULL;
}

void VappMusicPlayerApp::onListMenuDragStateChange(VfxBool isDragStart)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_LIST_MENU_DRAG_STATE_CHANGE, isDragStart, m_mplayerSrv->getIsFindNextTimerSuspended());

    if(isDragStart)
    {
        if(m_mplayerSrv->isFindNextTimerEnabled() && !m_mplayerSrv->getIsFindNextTimerSuspended())
        {
            m_mplayerSrv->stopFindNextTimer();
            
            m_mplayerSrv->setIsFindNextTimerSuspended(VFX_TRUE);

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_LIST_MENU_DRAG_STATE_CHANGE_ENABLE);
        }
    }
    else
    {
        if (m_mplayerSrv->getIsFindNextTimerSuspended())
        {
            m_mplayerSrv->startFindNextTimer();

            m_ctrlPlayback->setPlayState(PB_STATE_SWITCHING_PLAY);

            m_ctrlPlayback->registerInterruptCallback();

            m_mplayerSrv->setIsFindNextTimerSuspended(VFX_FALSE);
        }
    }
}

void VappMusicPlayerApp::onListMenuDragCell(VfxBool isStartDrag, VfxU32 index)
{
    m_reorderCurrIdx = index;

    if (isStartDrag)
    {
        // keep the start index
        if (m_reorderStartIdx == 0xFFFFFFFF)
        {
            m_reorderStartIdx = index;
        }
    }
    else
    {
        doListMenuCellSwap();
    }
}

void VappMusicPlayerApp::doListMenuCellSwap()
{
    // change the position and update content
    if (m_reorderStartIdx != m_reorderCurrIdx)
    {
        rearrangeSwapPos(m_reorderStartIdx, m_reorderCurrIdx);
        updateContent();
    }

    m_reorderStartIdx = 0xFFFFFFFF;
    m_reorderCurrIdx = 0xFFFFFFFF;
}

void VappMusicPlayerApp::rearrangeSwapPos(VfxU32 index1, VfxU32 index2)
{
    m_provider->rearrangeSwapPos(index1, index2);

    VfxBool temp = m_mplayerSrv->getSongValid(index1);
    m_mplayerSrv->setSongValid(index1, m_mplayerSrv->getSongValid(index2));
    m_mplayerSrv->setSongValid(index2, temp);

    temp = m_mplayerSrv->getSongLyricsState(index1);
    m_mplayerSrv->setSongLyricsState(index1, m_mplayerSrv->getSongLyricsState(index2));
    m_mplayerSrv->setSongLyricsState(index2, temp);
}

void VappMusicPlayerApp::onItemSelectionStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VfxU32 idx = index;

    if (getViewType() == VIEW_TYPE_ARTIST_ALBUM)
    {
        // The first item in VIEW_TYPE_ARTIST_ALBUM is "All songs"
        idx -= 1;
    }
    // The first item in VIEW_TYPE_PLAYLIST is "Favorite", but now service will count in favorite, so no need to -1

    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_provider->select(idx);
    }
    else
    {
        m_provider->deselect(idx);
    }
    updateSelectingUI();
}

void VappMusicPlayerApp::updateSelectingUI()
{
    VappMusicPlayerSubPage *page = getCurrPage();
    if (page)
    {
        VcpToolBar *bar = page->getToolBar();
        if (bar)
        {
            bar->setDisableItem(FUNC_ID_TB_BTN_OK, m_provider->isSelectNone());

            if (m_provider->isSelectAll())
            {
                bar->changeItem(FUNC_ID_TB_BTN_SELECT_ALL, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_UNSELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            }
            else
            {
                bar->changeItem(FUNC_ID_TB_BTN_SELECT_ALL,  VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_SELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            }
        }
    }
}

void VappMusicPlayerApp::onSearchTextChange(VcpTextEditor *editor)
{
    VfxWeakPtr<VcpEditing> editorWPtr = editor->m_editing;
    if (!editorWPtr.isValid())
    {
        return;
    }

    m_searchText.loadFromMem(editor->getText());

    if (m_provider->isSearching() || !m_searchText.isEmpty())
    {
        m_searchTimer->stop();
        m_searchTimer->start();

        VappMusicPlayerSubPage *page = VFX_OBJ_DYNAMIC_CAST(m_tabPage->getTabPage(m_tabPage->getCurrTab()), VappMusicPlayerSubPage);
        if (page)
        {
            // Block user to hit toolbar and list menu until searching is done
            VcpToolBar *bar = page->getToolBar();
            if (bar)
            {
                bar->setIsUnhittable(!m_searchText.isEmpty());
            }

            if (page->getListMenu() && m_searchText != m_preSearchText)
            {
                page->getListMenu()->setIsUnhittable(!m_searchText.isEmpty());
            }
        }
    }
}

void VappMusicPlayerApp::onSearchTimerTick(VfxTimer *timer)
{
    VappMusicPlayerSubPage* page = getCurrPage();

    if (m_searchText.isEmpty())
    {
        m_preSearchText.setEmpty();
        
        // Show toolbar if clear text to empty
        if (page && !page->isBarOn(VFX_PAGE_BAR_LOCATION_BOTTOM))
        {
            page->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
        }

        // only update root screen
        updateContent(-1, VFX_TRUE, VFX_TRUE, VFX_TRUE);

        searchCancel();
    }
    else 
    {
        // Hide toolbar once input characters, user may press toolbar at this moment
        if (page && page->isBarOn(VFX_PAGE_BAR_LOCATION_BOTTOM))
        {
            page->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_FALSE);
        }
    
        if (m_provider)
        {
            m_searchTimer->stop();

            if (m_searchText != m_preSearchText)
            {
                // Stop decode image
                m_provider->freeMediaCache();

                //Force stop list scrolling. Prevent get data from PLSV
                VappMusicPlayerListMenu *listMenu = getCurrListMenu();
                if (listMenu)
                {
                    listMenu->stopScrolling();
                }
                
                // do search
                m_provider->searchStart();
                m_provider->search(m_searchText);

                // Clear screen to searching
                updateContent(-1, VFX_TRUE, VFX_FALSE);
                m_preSearchText = m_searchText;
            }

            m_searchText.setEmpty();
        }
    }
}

void VappMusicPlayerApp::searchCancel()
{
    if (m_provider)
    {
        if (m_searchTimer)
        {
            m_searchTimer->stop();
        }

        VfxBool resetMC = VFX_FALSE;

        if (getRootScreen()->getViewStack() == VIEW_TYPE_ALBUM && m_provider->isSearching())
        {
            // clear the search text and current list is not in background
            resetMC = VFX_TRUE;
        }

        VfxBool isSearching = m_provider->isSearching();

        m_provider->searchEnd();

        if (resetMC)
        {
            m_provider->resetMediaCache();
        }

        m_searchText.setEmpty();
        m_preSearchText.setEmpty();

        if (m_tabPage)
        {
            VappMusicPlayerSubPage *page = getTabPage(m_tabPage->getCurrTab());
            if (page)
            {
                page->clearSearchEditor();

                if (!page->isBarOn(VFX_PAGE_BAR_LOCATION_BOTTOM))
                {
                    VfxAutoAnimate::begin();
                    VfxAutoAnimate::setDisable(VFX_TRUE);
                    page->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
                    VfxAutoAnimate::commit();
                }

                VcpToolBar *bar = page->getToolBar();
                if (bar)
                {
                    bar->setIsUnhittable(VFX_FALSE);
                }

                VappMusicPlayerListMenu *listMenu = page->getListMenu();
                if (listMenu)
                {
                    listMenu->setIsUnhittable(VFX_FALSE);
                    
                    // If list is really doing searching, reset list
                    if (isSearching)
                    {
                        listMenu->resetPosition();
                        listMenu->resetAllItems();
                        m_provider->clearCurrCache();
                    }
                }                
            }
        }
    }
}

void VappMusicPlayerApp::onPlaybackStateChange(PlaybackStateEnum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PLAYBACK_STATE_CHANGE, state);

    /* Show highlight in the list if the song is open */
    if (m_provider)
    {
        VfxBool byState = state != PB_STATE_NONE 
                       && state != PB_STATE_CLOSE 
                       /*&& (state != PB_STATE_STOP || (state == PB_STATE_STOP && !m_ctrlPlayback->isSongPausable(NULL)))*/;
        m_provider->setShowPlayIcon((byState || m_mplayerSrv->getIsDelayPlay()) && m_actionMode != ACTION_PLAYLIST_SONG_ARRANGE);
    }
}

#ifdef __MMI_AVRCP_SUPPORT__

VfxBool VappMusicPlayerApp::AVRCPCommHandler(U8 command_type)
{
    VfxBool isCoverFlow;
    VappMusicPlayerPlayerBase *player = getTopPlayer(isCoverFlow);
    if (player == NULL)
    {
        return VFX_FALSE;
    }

    switch(command_type)
    {
        case SRV_AVRCP_POP_PLAY:
        case SRV_AVRCP_POP_PAUSE:
            player->playpause();
            return VFX_TRUE;

        case SRV_AVRCP_POP_STOP:
            player->stop();
            player->updateTimeInfo();
            if(!isCoverFlow && m_nowPlaying)
            {
                m_nowPlaying->updateLyrics();
            }
            return VFX_TRUE;
    }

    return VFX_FALSE;
}

#endif /*__MMI_AVRCP_SUPPORT__*/

void VappMusicPlayerApp::exitOnError(VfxResId strID)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_EXIT_ON_ERROR, m_actionMode);

    // open fail, show popup and exit app
    setIsDying();
    setActionMode(ACTION_FATAL_ERROR);
    
    // Show popup when player active or during set show process
    if(isGroupActive())
    {
        if (!m_popupConfirm)
        {
            popupConfirm(
                VFX_WSTR_RES(strID),
                VFX_WSTR_RES(STR_GLOBAL_OK),
                VCP_POPUP_TYPE_FAILURE,
                VCP_CONFIRM_BUTTON_SET_OK,
                VCP_POPUP_BUTTON_TYPE_WARNING
                );
        }
    }
    // Close app directly if encounter error in background
    else
    {
        //vfxPostInvoke0(this, &VappMusicPlayerApp::exit);
        vfxPostInvoke0(m_mplayerSrv, &VappMusicPlayerService::closeMusicPlayer);
    }

}

void VappMusicPlayerApp::onPLSVCallback(srv_plst_cb_evt_enum cb_event, S32 result, VfxU32 ca_para_2)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PLSVCALLBACK, cb_event, result, ca_para_2, m_actionMode);
    
    switch (cb_event)
    {
        case SRV_PLST_CB_EVT_OPEN:
            if (result == SRV_PLST_ASYNC)
            {
                // async opening, show waiting
                setActionMode(ACTION_LAUNCHING);
                showWaitIcon();
            }
            else if ((m_actionMode == ACTION_LAUNCHING || m_actionMode == ACTION_LAUNCHING_FROM_BG) && result == SRV_PLST_OK)
            {
                // open successfully, hide waiting and enter first view if not seeking or connect BT
                PlaybackStateEnum playState = m_ctrlPlayback->getPlayState();
                if (playState == PB_STATE_SEEKING
                 || playState == PB_STATE_BT_CONNECTING
                 || playState == PB_STATE_BT_CONNECTING_WHILE_PLAYING
                 || playState == PB_STATE_BT_CONNECTING_WHILE_RESUME)
                {
                    showWaitIcon();
                }             
                else
                {
                    hideWaitIcon();
                }

                // Enable tab page after PLSV init
                disableTabPageTab(VFX_FALSE);

            #ifdef __COSMOS_MUSICPLY_CARD_ONLY__
                if (!m_mplayerSrv->getMemoryCardReady())
                {
                    setActionMode(ACTION_NONE);
                    return;
                }
            #endif

                // reset PLSV view stack & screen view stack
                m_provider->resetPLSV();
                m_rootScreen->popViewStack();

                m_provider->initRepeatShuffle();

                const VfxBool ret = setViewType(VIEW_TYPE_ALL_SONGS, CHANGE_VIEW_MODE_ENTER);
                if (ret)
                {
                    setActionMode(ACTION_NONE);
                    setSubPageEntering(VFX_FALSE);
                    
                    VappMusicPlayerSubPage *page = getCurrPage();
                    if (page)
                    {
                        page->disableToolbar(VFX_FALSE);
                        page->disableSearchBar(VFX_FALSE);
                    }

                    // count & active count will be updated in CtrlPLSV::PLSVCallback()
                    updateContent(-1, VFX_FALSE, VFX_FALSE);
                }
                else if (checkPLSVAction(VFX_FALSE) == VFX_FALSE)
                {
                    setActionMode(ACTION_FATAL_ERROR);
                    setIsDying();

                    if (!m_popupConfirm)
                    {
                        VfxResId strID = m_provider->getErrorStrId(m_plsvReturnValue);
                        popupConfirm(
                            VFX_WSTR_RES(strID),
                            VFX_WSTR_RES(STR_GLOBAL_OK),
                            VCP_POPUP_TYPE_FAILURE,
                            VCP_CONFIRM_BUTTON_SET_OK,
                            VCP_POPUP_BUTTON_TYPE_WARNING
                            );    
                    }
                }

                if (m_nowPlayingSetViewType)
                {
                    // When launch to now playing by Widget or NCenter, we set view type here since PLSV is not ready when laucnhing
                    setViewType(VIEW_TYPE_NOW_PLAYING, CHANGE_VIEW_MODE_ENTER, 0, VFX_TRUE);
                    m_nowPlayingSetViewType = VFX_FALSE;
                }
            }
            else if ((m_actionMode == ACTION_REOPENING_DB || m_actionMode == ACTION_REOPENING_DB_REALLOC) && result == SRV_PLST_OK)
            {
                setActionMode(ACTION_NONE);
                
                onMemoryCardChange();
            }
            else if (result < SRV_PLST_OK)
            {
                // open fail, show popup and exit app
                exitOnError(m_provider->getErrorStrId(result));
            }
            else if (m_actionMode == ACTION_RESET)
            {
                if (!getIsDying())
                {
                    // Reset DB complete, update DB to rescan data
                    setActionMode(ACTION_REFRESH);

                    popupWaitingClose();
                    onFuncRefreshDB();

                    m_ctrlPlayback->setPlayState(PB_STATE_NONE);
                }
            }
            else if (m_actionMode == ACTION_REFRESH)
            {
                m_provider->refreshDBCancel();
                setActionMode(ACTION_NONE);   
                closeAllPopup();

                VappMusicPlayerSubPage *page = getCurrTabPage();
                if (page)
                {
                    page->resetAll();
                }
            }
            else if(m_actionMode == ACTION_NONE)
            {
                // Cancel reset, update toolbar state
                updateToolbarItemState();
            }

            m_provider->freeMediaCache();
            
            break;
            
        case SRV_PLST_CB_EVT_UPDATE:
            {
                popupWaitingClose();

                if (result == SRV_PLST_OK)
                {
                    goToRoot();
                }
            
                m_provider->resetMediaCache();
                updateContent(-1, VFX_TRUE, VFX_TRUE, VFX_TRUE);

                // fold the toolbar after action 
                VappMusicPlayerSubPage* page = getCurrPage();
                if (page)
                {
                    VcpToolBar *bar = page->getToolBar();
                    if (bar && !bar->isFolded())
                    {
                        bar->switchFoldMode();
                    }
                }
                
                setActionMode(ACTION_NONE);
                m_provider->onRefreshComplete();

                if (result != SRV_PLST_OK)
                {
                    exitOnError(m_provider->getErrorStrId(result));
                }
                else
                {
                    // turn on back light to restart back light timer
                    if (!isBackLightOn() && vapp_screen_lock_is_allowed_launch())
                    {
                        vapp_screen_lock_launch();
                    }
                }
            }
            break;
            
        case SRV_PLST_CB_EVT_DELETE_ACTIVE_MEDIA:
            // Trying to delete current playing song, this case should only happen in list view
            // only deny deleting if active song is playing or paused
            if (m_actionMode == ACTION_DELETE || m_actionMode == ACTION_PLAYLIST_REMOVE)
            {
                if(m_mplayerSrv->isUndeletableState())
                {
                    VfxResId resID = 0;
                    
                    if (m_provider->getActiveListType() == SRV_PLST_ACTIVE_LIST_AUDIO)
                    {
                        resID = STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_DELETE;
                    }
                    else if (m_provider->getActiveListType() == SRV_PLST_ACTIVE_LIST_PLST)
                    {
                        resID = STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_REMOVE;
                    }
                    showBalloon(MMI_NMGR_BALLOON_TYPE_FAILURE, VFX_WSTR_RES(resID));
                }
                else
                {
                    // Pick next file after delete
                    m_playAfterAction.raised = VFX_TRUE;
                    m_playAfterAction.isNext = VFX_TRUE;
                    m_playAfterAction.nextMode = AUTO_NEXT;
                    m_playAfterAction.delayPlay= VFX_FALSE;
                    break;
                }

                if (m_longTapComm.action == ACTION_DELETE || m_longTapComm.action == ACTION_PLAYLIST_REMOVE)
                {
                    popupProgressClose();
                    updateContent(m_longTapComm.index, VFX_TRUE, VFX_TRUE);

                    m_longTapComm.action = ACTION_NONE;
                    setActionMode(ACTION_NONE);
                }
                else
                {
                    // Use post invoke to let service clear cache first, then update count and content
                    //onFuncDeleteStop();
                    vfxPostInvoke0(this, &VappMusicPlayerApp::onFuncDeleteStop);
                }

                break;
            }

        case SRV_PLST_CB_EVT_DELETE_LIST:
            if (m_popupIndicator)
            {
                if (result == SRV_PLST_OK)
                {
                    m_popupIndicator->setProgress(1);
                    m_popupIndicator->setIsDisabled(VFX_TRUE);
                }
            }

            if (m_actionMode == ACTION_DELETE
             || m_actionMode == ACTION_PLAYLIST_REMOVE)
            {
                VfxTimer *t;
                VFX_OBJ_CREATE(t, VfxTimer, this);
                t->setStartDelay(VCP_PROGRESS_INDICATOR_PATTERN_MOTION_TIME);
                t->m_signalTick.connect(this, &VappMusicPlayerApp::postProcFuncDeleteStop);
                t->start();

                if (result < SRV_PLST_OK)
                {
                    VfxResId resID = 0;
                    
                    if (m_provider->getActiveListType() == SRV_PLST_ACTIVE_LIST_AUDIO)
                    {
                        resID = STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_DELETE;
                    }
                    else if (m_provider->getActiveListType() == SRV_PLST_ACTIVE_LIST_PLST)
                    {
                        resID = STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_REMOVE;
                    }

                    if (resID != 0)
                    {
                        showBalloon(MMI_NMGR_BALLOON_TYPE_FAILURE, VFX_WSTR_RES(resID));
                    }
                }
            }
            break;

        case SRV_PLST_CB_EVT_DELETE_PROGRESS:
            if (m_popupIndicator)
            {
                m_popupIndicator->setProgress(VfxFloat(ca_para_2)/100.0f);
            }
            break;

        case SRV_PLST_CB_EVT_ADD_TO_PLST:
            {
                // turn on back light to restart back light timer
                if (!isBackLightOn() && vapp_screen_lock_is_allowed_launch())
                {
                    vapp_screen_lock_launch();
                }

                popupWaitingClose();
                
                if (result == SRV_PLST_OK)
                {
                    // do not show balloon until the 2nd screen is closed
                    //showBalloon(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_MENU_ADD_TO_PLST));
                }
                else if (result == SRV_PLST_RET_PLST_FULL)
                {
                    //showBalloon(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_MAX_PLST_SONG));
                    popupConfirm(
                        VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_MAX_PLST_SONG),
                        VFX_WSTR_RES(STR_GLOBAL_OK),
                        VCP_POPUP_TYPE_FAILURE,
                        VCP_CONFIRM_BUTTON_SET_OK,
                        VCP_POPUP_BUTTON_TYPE_WARNING
                        );    
                }
                else if (result < SRV_PLST_OK)
                {
                    // usually be serious error, exit app
                    exitOnError(m_provider->getErrorStrId(result));
                    break;
                }

                // update playlist song count
                VappMusicPlayerListMenu *listMenu = getCurrListMenu();
                if (listMenu)
                {
                    listMenu->setIsDisabled(VFX_TRUE);
                    listMenu->setIsFreezed(VFX_FALSE);
                    listMenu->updateItem(m_selectItemIdx + 1);
                }

                // delay 0 ms to display updated playlist song count before closing
                VfxTimer *t;
                VFX_OBJ_CREATE(t, VfxTimer, this);
                t->setStartDelay(0);
                t->m_signalTick.connect(this, &VappMusicPlayerApp::postProcFuncAddToPlaylistStop);
                t->start();                
            }
            break;

        case SRV_PLST_CB_EVT_SEARCH:
            {
                // Move hide toolbar to async search begin
            
                updateContent();
                if (getViewType() == VIEW_TYPE_ALBUM)
                {
                    m_provider->resetMediaCache();
                }

                VappMusicPlayerSubPage *page = getCurrPage();
                if (page && page->getListMenu())
                {
                    // list menu is disabled on search text changed to block item tapped before content is updated to search result
                    page->getListMenu()->setIsUnhittable(VFX_FALSE);
                }
            }
            break;

        case SRV_PLST_CB_EVT_MSDC_PLUG_OUT: // SD card out
        case SRV_PLST_CB_EVT_MSDC_PLUG_IN:  // SD card in
            {
                if (m_actionMode == ACTION_FATAL_ERROR)
                {
                    return;
                }
                // Cancel refresh directly, it use post event in closeAllPopup(). 
                // The PLSV m_isReady flag is set to false when reopenDB async and will not stop it
                else if(m_actionMode == ACTION_REFRESH)
                {
                    m_provider->refreshDBCancel();
                    setActionMode(ACTION_NONE);
                }

                hideWaitIcon();

                closeAllPopup();

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__

                cancelCheckDuplicatedPlaylist();

                SrvDBStateEnum DBState = m_mplayerSrv->getDBState();
                if (DBState == DB_NORMAL)
                {
                    // Plug out memory card, close DB and set content empty

                    VfxBool disableUI = getViewType() == VIEW_TYPE_ALL_SONGS;
                    
                    goToRoot();

                    if (disableUI)
                    {
                        VappMusicPlayerSubPage *page = getCurrPage();
                        if (page)
                        {
                            page->disableToolbar(VFX_TRUE);

                            VappMusicPlayerListMenu *listMenu = page->getListMenu();
                            if (listMenu)
                            {
                                listMenu->setIsUnhittable(VFX_TRUE);
                            }
                            page->disableSearchBar(VFX_TRUE);
                        }
                    }

                    m_mplayerSrv->closeDB();
                }
                else if (DBState == DB_OPENING)
                {
                    // Plug in memory card, open DB and update content

                    stopInit2ndStage();

                    if (m_mplayerSrv->getMemoryCardReady())
                    {
                        // restore DBState after stopInit2ndStage()
                        m_mplayerSrv->setDBState(DB_OPENING);

                        setActionMode(ACTION_LAUNCHING);
                        
                        // To trigger init2ndStage()
                        if (m_tabPage->getCurrTab() == FUNC_ID_TAB_ALL_SONG)
                        {
                            init2ndStage(VFX_FALSE);
                        }
                        else
                        {
                            m_tabPage->setCurrTab(FUNC_ID_TAB_ALL_SONG);
                        }
                    }
                }

                // use post invoke here to let previous tab could be disabled too
                vfxPostInvoke1(this, &VappMusicPlayerApp::disableTabPageTab, VFX_TRUE);
#else
                onMemoryCardChange();

                VfxS32 reopenResult = m_mplayerSrv->reopenDB(cb_event == SRV_PLST_CB_EVT_MSDC_PLUG_IN);
                if (reopenResult == SRV_PLST_OK)
                {
                    // open success
                    m_needCheckDuplicatedPlaylist = (cb_event == SRV_PLST_CB_EVT_MSDC_PLUG_IN);
                }
#endif
            }
            break;

        default:
            break;
    };
}

void VappMusicPlayerApp::onMDICallback(VfxS32 result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_MDICALLBACK, result);

    switch (result)
    {
        // For playback
        case VAPP_MUSICPLY_PRE_END_OF_FILE:
            /* Draw full length slider to show end of file */
            playerPageMaximizeSlider();
            break;

        case MDI_AUDIO_END_OF_FILE:
            // If the DB is refreshing, do not go to next. Just stop it
            if(m_actionMode == ACTION_REFRESH && m_popupWaiting)
            {
                m_ctrlPlayback->stop();
            }
            break;

        case MDI_AUDIO_TERMINATED:
            break;

        // For duration
        case MDI_AUDIO_DUR_UPDATED:
            {
                if (m_nowPlaying)
                {
                    m_nowPlaying->MDICallbackHandler(result);
                }

            #ifdef __COSMOS_MUSICPLY_COVER_FLOW__
                if (m_coverFlow)
                {
                    m_coverFlow->MDICallbackHandler(result);

                    if (getViewType() == VIEW_TYPE_COVER_FLOW_SONG)
                    {
                        m_coverFlow->updateAlbumPanelItem(-1);
                    }
                }
            #endif // __COSMOS_MUSICPLY_COVER_FLOW__

                // Commit to play list first when change song
                if ((0xFFFFFFFF != m_reorderStartIdx) && (m_reorderStartIdx != m_reorderCurrIdx))
                {
                    rearrangeSwapPos(m_reorderStartIdx, m_reorderCurrIdx);
                    m_reorderStartIdx = m_reorderCurrIdx;
                }

                // only update content if current view is a list view
                if (!m_nowPlaying && !m_coverFlow)
                {
                    // update the whole content since we can't be sure if active song is in current page
                    if (m_actionMode != ACTION_DELETE && m_actionMode != ACTION_PLAYLIST_REMOVE && !m_popupIndicator)
                    {
                        updateContent(-1, VFX_FALSE, VFX_FALSE);
                    }
                }
            }
            break;

        // For seek
        case AUD_SEEK_REASON_DONE:
            {
                // m_playStateBeforeSeek can be set before seeking or be set by resumeInterruptPlay() (interruptedInfo.state)
                PlaybackStateEnum state = m_ctrlPlayback->m_playStateBeforeSeek;

                // normal seeking should only handle PLAY state, the other states are from interrupted state
                if (state == PB_STATE_NONE  // this case is interrupedInfo.state cleared by clearInterruptState(TRUE, FALSE) in VappMusicPlayerApp::onPrevNext()
                 || state == PB_STATE_PLAY
                 || state == PB_STATE_SWITCHING_PLAY
                 || state == PB_STATE_SEEKING
                 || state == PB_STATE_BT_CONNECTING
                 || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING
                 || state == PB_STATE_BT_CONNECTING_WHILE_RESUME
                 || (!m_ctrlPlayback->isSongPausable(NULL) && state == PB_STATE_STOP))
                {
                    if (m_coverFlow)
                    {
                        // Not update slider value when play afer seek
                        m_coverFlow->play(VFX_WSTR(""), VFX_TRUE, VFX_FALSE);
                    }
                    else if (m_nowPlaying)
                    {
                        // Not update slider value when play afer seek
                        m_nowPlaying->play(VFX_WSTR(""), VFX_TRUE, VFX_FALSE);
                    }
                }
                else if (state == PB_STATE_PAUSE
                      || state == PB_STATE_STOP
                      || state == PB_STATE_INTERRUPTED
                      || state == PB_STATE_OPEN)
                {
                    if (m_nowPlaying)
                    {
                        m_nowPlaying->updateLyrics();
                    }
                }
            }
            break;

        case AUD_SEEK_REASON_FAIL:
        case AUD_SEEK_REASON_TERMINATED:
            break;

        // For interrupt
        case VAPP_MUSICPLY_INTERRUPT_CB_INTERRUPT:
            if (getNowPlaying())
            {
                getNowPlaying()->clearErrorMessage();
                getNowPlaying()->updateTimeInfo();
            }

            if (getCoverFlow())
            {
                getCoverFlow()->clearErrorMessage();
                getCoverFlow()->updateTimeInfo();
            }

            m_playAfterAction.raised = VFX_FALSE;
            break;

        case VAPP_MUSICPLY_INTERRUPT_CB_RESUME:
            if (getNowPlaying())
            {
                getNowPlaying()->updateTimeInfo();
            }
            
            if (getCoverFlow())
            {
                getCoverFlow()->updateTimeInfo();
            }
            break;

        // For playback error
        default:
            {
                if (result == MDI_AUDIO_BUSY)
                {
                    // only show message in DEVICE BUSY case
                    VfxResId strID = isMakingCall() ? STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL : m_ctrlPlayback->getMDIErrorMessage(result);
                        
                    if (m_coverFlow)
                    {
                        m_coverFlow->showErrorMessage(VFX_WSTR_RES(strID), VFX_FALSE);
                        m_ctrlPlayback->setPlayState(PB_STATE_SWITCHING_PLAY);
                    }
                    else if (m_nowPlaying)
                    {
                        m_nowPlaying->showErrorMessage(VFX_WSTR_RES(strID), VFX_FALSE);
                        m_ctrlPlayback->setPlayState(PB_STATE_SWITCHING_PLAY);
                    }
                }
            }   
            break;
    };
}

void VappMusicPlayerApp::onPlayerPageCallback(VfxS32 action)
{
//gcb
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PLAYER_PAGE_CALLBACK, action);

    switch(VappMusicPlayerPlayerPageCallbackEnum(action))
    {
        case FUNC_ID_PAGE_ENTERED:
            // Open file when enter page, if switch not play, just open it
            if (m_doPlayOnEntered)
            {
                SongInfoStruct info;
                m_mplayerSrv->getCurrInfo(info);
                
                VappMusicPlayerNowPlayingPage* nowPlaying = getNowPlaying();
                if (nowPlaying)
                {
                    if(m_ctrlPlayback->getPlayState() == PB_STATE_SWITCHING_PLAY)
                    {
                        if (nowPlaying->open(info.filepath))
                        {
                            nowPlaying->play(info.filepath);
                        }
                    }
                    else
                    {
                        nowPlaying->open(info.filepath);
                    }
                }
                // Update current playing info to database
                m_provider->setActiveToDBUseCurrent();
                m_doPlayOnEntered = VFX_FALSE;
            }
            break;

        case FUNC_ID_BTN_SETTING:
            goToSetting();
            break;

        
        case FUNC_ID_GO_TO_SOUND_EFFECT:
            goToSoundEffect();
            break;

        case FUNC_ID_SOUND_EFFECT_CLOSE:
            backFromSoundEffect();
            break;

        case FUNC_ID_BTN_ADD_TO_FAVORITE:
            {
                VappMusicPlayerContentProvider *provider = getProvider();
                if (provider->isActiveSongInFavorite())
                {
                    m_nowPlaying->setFavoriteBtn(VFX_TRUE);
                    
                    VfxBool isPlayingFav = provider->isPlayingFavorite();

                    provider->removeActiveSongFromFavorite();
                    provider->updateCount();
                    provider->updateActiveCount();
                    provider->updateActiveIndex();
                    provider->updateActiveID();

                    if (isPlayingFav)
                    {
                        // jump to next song if remove current song from Favorites, or stop if no more song in the list
                        const VfxU32 activeCount = provider->getActiveCount();

                        m_mplayerSrv->initActiveListValidState();

                        if (activeCount > 0)
                        {
                            const PlaybackStateEnum state = getCtrlPlayback()->getPlayState();

                            m_mplayerSrv->onNext(CURRENT, VFX_FALSE);
                            
                            if (m_nowPlaying)
                            {
                                if (state == PB_STATE_PLAY && m_ctrlPlayback->getPlayState() == PB_STATE_OPEN && activeCount == 1)
                                {
                                    // this is a work around for the case:
                                    // 2 songs A, B is in the Favorite and A is playing
                                    // Remove A from Favorite, onNext will get info of B and return EMPTY
                                    m_nowPlaying->play(VFX_WSTR(""), VFX_TRUE);
                                }
                            }
                        }
                        else
                        {
                            m_mplayerSrv->clearActivePlaylist();

                            SongInfoStruct info;
                            info.id = 0;
                            info.index = 0;
                            playerPagePlaySong(info, PAGE_SWITCH_DIR_RIGHT, VFX_FALSE);
                            
                            getNowPlaying()->setEmpty();

                            m_mplayerSrv->sendPlayStopEvent();
                        }
                    }
                    else if (provider->getActiveCount() == 0)
                    {
                        m_mplayerSrv->clearActivePlaylist();
                        
                        SongInfoStruct info;
                        info.id = 0;
                        info.index = 0;
                        playerPagePlaySong(info, PAGE_SWITCH_DIR_RIGHT, VFX_FALSE);
                        
                        getNowPlaying()->setEmpty();

                        m_mplayerSrv->sendPlayStopEvent();
                    }
                }
                else
                {
                    provider->addActiveSongToFavorite();
                    provider->updateCount();
                    provider->updateActiveCount();

                    if (provider->isPlayingFavorite())
                    {
                        m_mplayerSrv->initActiveListValidState();
                    }

                    m_nowPlaying->setFavoriteBtn(VFX_FALSE);
                    showBalloon(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_SAVE_TO_FAV));
                }
            }
            break;

        case FUNC_ID_BTN_REPEAT:
            if (m_nowPlaying)
            {
                m_nowPlaying->setRepeat((VfxU32)getProvider()->nextRepeatState());
            }
            break;

        case FUNC_ID_BTN_SHUFFLE:
            if (m_nowPlaying)
            {
                m_nowPlaying->setShuffle((VfxU32)getProvider()->nextShuffleState());
            }
            break;

        case FUNC_ID_BTN_BACK_TO_LIST:
            {
                goToRoot();
            }
            break;

        case FUNC_ID_BTN_NOW_PLAYING_LIST:
            m_rootScreen->goToNextPage(VIEW_TYPE_NOW_PLAYING_LIST, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TITLE_NOW_PLAYING_PLST));
            break;

        case FUNC_ID_BTN_PREV:
            m_mplayerSrv->onPrev(VFX_TRUE);
            break;

        case FUNC_ID_BTN_NEXT:
            m_mplayerSrv->onNext(NEXT, VFX_TRUE);
            break;

        case FUNC_ID_BTN_PLAY_PAUSE:
            m_mplayerSrv->setPlayAfterSwitchSong(VFX_TRUE);
            break;

        case FUNC_ID_SLIDER_PRESSED:
            break;

        case FUNC_ID_SLIDER_RELEASE:
            if (m_playAfterAction.raised)
            {
                // this case is dragging the slider on playing invalid file
                
                m_playAfterAction.raised = VFX_FALSE;

                //MAUI_03210887
                PlaybackStateEnum playState = m_ctrlPlayback->getPlayState();
                if ((PB_STATE_CLOSE == playState)
                    || (PB_STATE_SWITCHING_PLAY == playState)
                    || (PB_STATE_SWITCHING_NOT_PLAY == playState))
                
                {
                    onPrevNext(m_playAfterAction.isNext, m_playAfterAction.nextMode, m_playAfterAction.delayPlay, 0);
                }
            }
            break;

        case PARSE_LYRICS_OK:
            m_mplayerSrv->setSongLyricsState(m_provider->getActiveIndex(), VFX_TRUE);
            break;

        case PARSE_LYRICS_FAIL:
            m_mplayerSrv->setSongLyricsState(m_provider->getActiveIndex(), VFX_FALSE);
            break;

        default:
            break;
    };
}

VappMusicPlayerCtrlPlayback* VappMusicPlayerApp::getCtrlPlayback()
{
    return m_ctrlPlayback;
}

VappMusicPlayerContentProvider* VappMusicPlayerApp::getProvider()
{
    if (m_provider == NULL)
    {
        SWLA_BEGIN("MP5");
        VFX_OBJ_CREATE(m_provider, VappMusicPlayerContentProvider, this);
        m_provider->setCBReceiver(this);
        m_provider->m_signalPLSVReturn.connect(this, &VappMusicPlayerApp::onPLSVReturn);
        m_provider->m_signalPLSVCallback.connect(this, &VappMusicPlayerApp::onPLSVCallback);
        SWLA_END("MP5");
    }

    return m_provider;
}

VappMusicPlayerNowPlayingPage* VappMusicPlayerApp::getNowPlaying()
{
    return m_nowPlaying;
}

void VappMusicPlayerApp::clearNowPlayingPtr(VappMusicPlayerNowPlayingPage *nowPlaying)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_CLEAR_NOW_PLAYING_PTR);

    if (nowPlaying == m_nowPlaying)
    {
        m_nowPlaying = NULL;
    }
}

#ifdef __COSMOS_3D_V10__
VappMusicPlayerCoverFlow3DPage* VappMusicPlayerApp::getCoverFlow()
{
    return m_coverFlow;
}

void VappMusicPlayerApp::clearCoverFlowPtr(VappMusicPlayerCoverFlow3DPage *coverFlow)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_CLEAR_COVER_FLOW_PTR);

    if (coverFlow == m_coverFlow)
    {
        m_coverFlow = NULL;
    }
}

#else
VappMusicPlayerCoverFlowPage* VappMusicPlayerApp::getCoverFlow()
{
    return m_coverFlow;
}

void VappMusicPlayerApp::clearCoverFlowPtr(VappMusicPlayerCoverFlowPage *coverFlow)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_CLEAR_COVER_FLOW_PTR);

    if (coverFlow == m_coverFlow)
    {
        m_coverFlow = NULL;
    }
}
#endif

VappMusicPlayerPlayerBase* VappMusicPlayerApp::getTopPlayer(VfxBool &isCoverFlow)
{
    VappMusicPlayerPlayerBase *player = NULL;

    VfxWeakPtr<VappMusicPlayerNowPlayingPage> nowPlayingWPtr = m_nowPlaying;
#ifdef __COSMOS_3D_V10__
    VfxWeakPtr<VappMusicPlayerCoverFlow3DPage> coverFlowWPtr = m_coverFlow;
#else
    VfxWeakPtr<VappMusicPlayerCoverFlowPage> coverFlowWPtr = m_coverFlow;
#endif
    
    if (coverFlowWPtr.isValid() || nowPlayingWPtr.isValid())
    {
        if (coverFlowWPtr.isValid())
        {
            player = m_coverFlow;
            isCoverFlow = VFX_TRUE;
        }
        else if (nowPlayingWPtr.isValid())
        {
            player = m_nowPlaying;
            isCoverFlow = VFX_FALSE;
        }
    }

    return player;
}

ViewTypeEnum VappMusicPlayerApp::getPreViewType()
{
    if (m_rootScreen->getViewStackCount() > 1)
    {
        return m_rootScreen->getViewStack(m_rootScreen->getViewStackCount()-2);
    }
    else
    {
        return VIEW_TYPE_NONE;
    }
}

ChangeViewMode VappMusicPlayerApp::getChangeViewMode()
{
	if (m_provider)
	{
		return m_provider->getChangeViewMode();
	}

	return CHANGE_VIEW_MODE_NONE;
}

ViewTypeEnum VappMusicPlayerApp::getViewType()
{
    VappMusicPlayerScreen* scr = m_rootScreen;
    if (scr)
    {
        return scr->getViewStack();
    }
    else
    {
        return VIEW_TYPE_NONE;
    }
}

VfxBool VappMusicPlayerApp::setViewType(ViewTypeEnum viewType, ChangeViewMode mode, VfxU32 index, VfxBool useRootScr)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SET_VIEW_TYPE, viewType, mode, index, m_actionMode);

    if(m_provider && !m_provider->getIsReady())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SET_VIEW_TYPE_SERVICE_NOT_READY);
        return VFX_FALSE;
    }

    if (m_actionMode == ACTION_FATAL_ERROR || m_actionMode == ACTION_REOPENING_DB || m_actionMode == ACTION_REOPENING_DB_REALLOC)
    {
        return VFX_FALSE;
    }

    if (viewType == getViewType())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SET_VIEW_TYPE_SAME);
        return VFX_TRUE;
    }
    else if (mode == CHANGE_VIEW_MODE_SWITCH && (viewType == VIEW_TYPE_PLAYLIST_SELECT || viewType == VIEW_TYPE_VIEW_SELECT))
    {
        // these 2 types should not be SWITCH mode
        return VFX_TRUE;
    }

    VfxBool resetMC = ((m_resetMcOnBack || m_provider->isSearching()) && viewType == VIEW_TYPE_ALBUM && mode == CHANGE_VIEW_MODE_BACK);

    if (!(viewType == VIEW_TYPE_PLAYLIST_SELECT && mode == CHANGE_VIEW_MODE_ENTER))
    {
        if (m_provider->isSearching() && (viewType == VIEW_TYPE_ALBUM_SONG && mode == CHANGE_VIEW_MODE_ENTER))
        {
            // set this flag to reset media cache when back from search result album song to album
            // do not handle playlist select here because searching can't be canceled before adding to playlist is completed
            m_resetMcOnBack = VFX_TRUE;
        }

        if (m_provider->isSearching() && mode == CHANGE_VIEW_MODE_ENTER)
        {
            m_resetListOnBack = VFX_TRUE;
        }
        searchCancel();
    }
    
    switch (mode)
    {
    case CHANGE_VIEW_MODE_ENTER:
        m_rootScreen->pushViewStack(viewType);
        break;

    case CHANGE_VIEW_MODE_BACK:
        m_rootScreen->popViewStack();
        break;

    case CHANGE_VIEW_MODE_SWITCH:
        m_rootScreen->popViewStack();
        m_rootScreen->pushViewStack(viewType);
        break;      
    };

    VfxBool ret = VFX_FALSE;

    if (m_provider)
    {
        ret = m_provider->setViewType(viewType, mode, index);
        ret = ret && checkPLSVAction();

        if (ret == VFX_FALSE)
        {
            return VFX_FALSE;
        }

        if (resetMC)
        {
            m_provider->resetMediaCache();

            m_resetMcOnBack = VFX_FALSE;
        }

        // Check for duplicated playlist name on phone and memory card for one time
        if (m_needCheckDuplicatedPlaylist
        && (viewType == VIEW_TYPE_PLAYLIST || viewType == VIEW_TYPE_PLAYLIST_SELECT)
        && !m_coverFlowToNowPlaying)
        {
            startCheckDuplicatedPlaylist(); 
        }
    }

    // clear the focus of search bar text editor
    VappMusicPlayerSubPage *tabPage = getCurrTabPage();
    if (tabPage)
    {
        tabPage->resetFocusChild();
    }

    return VFX_TRUE;
}

void VappMusicPlayerApp::updateContent(VfxS32 index, VfxBool updateCount, VfxBool updateActive, VfxBool bReset)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_UPDATE_CONTENT_INDEX, index, updateCount, updateActive, bReset);

    if (!isGroupActive())
    {
        // do not update content if APP is hidden to avoid blocking UI
        return;
    }

    if (m_actionMode == ACTION_RESET)
    {
        // do not send any PLSV commands before DB opening complete
        return;
    }

    // Update count will take much time if there are many entries
    if (updateCount)
    {
        m_provider->updateCount();

        // update song count of VIEW_ARTIST_ALBUM
        m_selectItemCount = VAPP_MUSICPLY_DEF_LARGE_NUM;
    }

    if(updateActive)
    {
        m_provider->updateActiveCount();
        m_provider->updateActiveIndex();
        m_provider->updateActiveID();
        m_provider->resetHighLighIndex();
    }

    VappMusicPlayerSubPage* page = getCurrPage();
    if (NULL == page)
    {
        return;
    }
    
    if (!bReset)
    {
        if (index == -1)
        {
            page->updateAll();
        }
        else
        {
            page->updateItem((VfxU32)index);
        }
    }
    else
    {
        page->resetAll();
    }
    
    if (index == -1)
    {
        updateToolbarItemState();
    }
}

void VappMusicPlayerApp::updateHighLight()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_UPDATE_HIGH_LIGHT);

    if (!isGroupActive())
    {
        // do not update if APP is hidden to avoid blocking UI
        return;
    }

    const VfxS32 preIdx = m_provider->getPreHighLightIndex();
    const VfxS32 curIdx = m_provider->getHighLightIndex();

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
    if (getViewType() == VIEW_TYPE_COVER_FLOW_SONG && m_coverFlow)
    {
        m_coverFlow->updateAlbumPanelItem((VfxU32)preIdx);
        m_coverFlow->updateAlbumPanelItem((VfxU32)curIdx);
    }
    else
#endif // __COSMOS_MUSICPLY_COVER_FLOW__
    {
        VappMusicPlayerSubPage* page = getCurrPage();
        if (page)
        {
            if (preIdx >= 0)
            {
                page->updateItem((VfxU32)preIdx);
            }

            if (curIdx >= 0)
            {
                page->updateItem((VfxU32)curIdx);
            }
        }
    }
}

void VappMusicPlayerApp::updateToolbarItemState()
{   
    vfxPostInvoke1(this, &VappMusicPlayerApp::doUpdateToolbarItemState, getViewType());
}

void VappMusicPlayerApp::doUpdateToolbarItemState(ViewTypeEnum requestView)
{
    VappMusicPlayerSubPage *page = getCurrPage();

    if (!page || page->getViewType() != requestView)
    {
        return;
    }

    if (page && !m_checkDuplicatedPlaylistRunning)
    {
        VcpToolBar *bar = page->getToolBar();
        if (bar)
        {
            // VIEW_TYPE_PLAYLIST should ignore "Favorite", VIEW_TYPE_ARTIST_ALBUM should ignore "All songs"
            VappMusicPlayerContentProvider *provider = getProvider();
            ViewTypeEnum viewType = getViewType();
            VfxU32 count = provider->getCount();
            VfxBool isDisable = count == ((viewType == VIEW_TYPE_PLAYLIST || viewType == VIEW_TYPE_ARTIST_ALBUM) ? 1 : 0);

            bar->setDisableItem(FUNC_ID_TB_BTN_SELECT_ALL, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_PLAY, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_ADD_TO_PLAYLIST, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_PLAY, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_DELETE, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_PLAYLIST_REMOVE, isDisable);
            bar->setDisableItem(FUNC_ID_TB_BTN_PLAYLIST_ARRANGE, count <= 1);

            // Do not let user to go to nowplaing if list service is not ready
            bar->setDisableItem(FUNC_ID_TB_BTN_NOW_PLAYING, !provider->getIsReady());
            bar->setDisableItem(FUNC_ID_TB_BTN_REFRESH, !provider->getIsReady());
            bar->setDisableItem(FUNC_ID_TB_BTN_COVER_FLOW, !provider->getIsReady());            
        }
    }
}

ActionEnum VappMusicPlayerApp::getActionMode()
{
    return m_actionMode;
}

void VappMusicPlayerApp::popToPage(ViewTypeEnum viewType)
{
    ViewTypeEnum view = getViewType();
    VfxBool ret = VFX_TRUE;
    VfxU32 counter = MUSICPLY_MAX_VIEW_STACK_DEPTH;

    for (; view != viewType && ret && counter >= 0; --counter)
    {
        ret = setViewType(getPreViewType(), CHANGE_VIEW_MODE_BACK);

        if (view != VIEW_TYPE_COVER_FLOW_SONG)
        {
            m_rootScreen->popPage();
        }

        view = getViewType();
        VFX_ASSERT(view != VIEW_TYPE_NONE);
    }
}

void VappMusicPlayerApp::goToRoot(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_GO_TO_ROOT, m_actionMode);

    // MAUI_03093166, since it should already in root screen here force to use root screen to get page.
    // TODO: It's better to use only 1 screen in music player app
    pageMultiSelectOff(getPageBeforeAction());

    while (m_rootScreen->getViewStackCount() > 1)
    {
        ViewTypeEnum view = m_rootScreen->popViewStack();

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_GO_TO_ROOT_VIEW_D, view);

        switch (view)
        {
            case VIEW_TYPE_NOW_PLAYING:
                if (m_nowPlaying)
                {
                    m_nowPlaying->clearLyrics();
                    m_nowPlaying = NULL;
                }
                break;

            case VIEW_TYPE_COVER_FLOW:
                m_coverFlow = NULL;
                break;

        #ifdef __COSMOS_MUSICPLY_COVER_FLOW__
            case VIEW_TYPE_COVER_FLOW_SONG:
            {
                // cover flow song is not a page
                m_coverFlow->hideAlbumDetailPanel(VFX_FALSE);
                continue;
            }
        #endif //__COSMOS_MUSICPLY_COVER_FLOW__
        }

        m_rootScreen->popPage();
    };

    if (m_provider && isSelecting())
    {
        m_provider->selectEnd();
        if (checkPLSVAction() == VFX_FALSE) return;
    }

    // in some scenario action mode will be set to NONE, so close the existing popups here
    if (m_popupInput)
    {
        VFX_OBJ_CLOSE(m_popupInput);
        m_popupInput = NULL;
    }

    if (m_popupConfirm)
    {
        m_popupConfirm->exit(VFX_TRUE);
        m_popupConfirm = NULL;
    }

    // reset action mode if not: launching, reopening, fatal error
    if(m_actionMode > ACTION_FATAL_ERROR)
    {
        setActionMode(ACTION_NONE);
    }
    m_resetMcOnBack = VFX_FALSE;
    m_selectItemIdx = VAPP_MUSICPLY_DEF_LARGE_NUM;

    if (m_provider)
    {
        m_provider->resetPLSV();
        if (checkPLSVAction() == VFX_FALSE) return;

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
        if (m_mplayerSrv->getMemoryCardReady())
#endif
        {
            m_provider->setViewType(VIEW_TYPE_ALL_SONGS, CHANGE_VIEW_MODE_ENTER);
            if (checkPLSVAction() == VFX_FALSE) return;
        }
    }

    VappMusicPlayerSubPage *page;
    for(VfxU32 id = FUNC_ID_TAB_ARTIST ; id <= FUNC_ID_TAB_PLAYLIST ; id++)
    {
        page = getTabPage(id);
        if (page)
        {
            page->disableSearchBar(VFX_TRUE);            
            VFX_OBJ_CLOSE(page);
        }
    }

    m_rootScreen->clearViewStack();
    m_rootScreen->pushViewStack(VIEW_TYPE_ALL_SONGS);
    m_tabPage->setCurrTab(FUNC_ID_TAB_ALL_SONG);

    // clear search
    searchCancel();

    // Only clear search editor in all song page, other page already close in this function
    page = getTabPage(FUNC_ID_TAB_ALL_SONG);
    if (page)
    {
        page->resetFocusChild();
        page->clearSearchEditor();
 
        if (page->getListMenu())
        {
            page->getListMenu()->resetAllItems();
        }
        else
        {
            // this case is launch to nowplaying
            page->initListMenu(VCP_LIST_MENU_CELL_STYLE_CUSTOM, VFX_TRUE);
        }
    }
}

void VappMusicPlayerApp::goToNowPlaying(VfxS32 index, VfxBool isStartPlay)
{
    PlaybackStateEnum playState = m_ctrlPlayback->getPlayState();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_GO_TO_NOW_PLAYING, index, isStartPlay, playState);

    // MAUI_03093166, Assume will only enter now playing from root screen, use root screen here
    // TODO: It's better to use only 1 screen in music player app
    VappMusicPlayerScreen* scr = getRootScreen();

    // initialize now playing
    if (m_nowPlaying == NULL)
    {
        VFX_OBJ_CREATE(m_nowPlaying, VappMusicPlayerNowPlayingPage, scr);
        m_nowPlaying->setCtrlPlayback(m_ctrlPlayback);
        m_nowPlaying->setRepeat(m_provider->getRepeat());
        m_nowPlaying->setShuffle(m_provider->getShuffle());
        m_nowPlaying->m_signalCallback.connect(this, &VappMusicPlayerApp::onPlayerPageCallback);
    }
    
    SongInfoStruct info;
    if (isStartPlay)
    {
        info.index = index;
        // Set active but not update database, update it when onEntered() by calling setActiveToDBUseCurrent()
        m_mplayerSrv->setActive(info.index, VFX_FALSE);
        m_mplayerSrv->initActiveListValidState();

        m_mplayerSrv->stopFindNextTimer();

        m_nowPlaying->clearErrorMessage();
        m_ctrlPlayback->clearInterruptState();
    }   
    m_mplayerSrv->getCurrInfo(info);

    if (m_actionMode == ACTION_LAUNCHING_FROM_BG)
    {
        m_nowPlayingSetViewType = VFX_TRUE;
    }
    else
    {
        // MAUI_03093166, Assume will only enter now playing from root screen, use root screen here
        setViewType(VIEW_TYPE_NOW_PLAYING, CHANGE_VIEW_MODE_ENTER, 0, VFX_TRUE);
        if (checkPLSVAction() == VFX_FALSE) return;
    }

    // set song info and play song if necessary
    if (isStartPlay)
    {
        m_doPlayOnEntered = VFX_TRUE;
        m_ctrlPlayback->setPlayState(PB_STATE_SWITCHING_PLAY);
        nowPlayingPlaySong(info);
    }
    else if (playState != PB_STATE_NONE)
    {
        playerPageSetInfo(m_nowPlaying);
        if (info.filepath.isEmpty())
        {
            // Stop and close file and set state to NONE in set Empty
            m_nowPlaying->stop();
            m_nowPlaying->closeFile();
            m_nowPlaying->setEmpty();
        }
        else
        {
            m_nowPlaying->updateTimeInfo();
        }
    }
    else if (playState == PB_STATE_NONE)
    {
        m_nowPlaying->setEmpty();
    }

    if (!isStartPlay && playState == PB_STATE_NONE)
    {
        // set default album cover
        VfxWString str;
        m_nowPlaying->setAlbumCover(0, str, PAGE_SWITCH_DIR_NONE);
    }
    else
    {
        // set favorite button state
        nowPlayingSetFavorite();
    }

    if (isMakingCall())
    {
        m_nowPlaying->setEnablePlaybackUI(VFX_FALSE);
    }

    scr->pushPage(VIEW_TYPE_NOW_PLAYING, m_nowPlaying);
}

void VappMusicPlayerApp::nowPlayingPlaySong(SongInfoStruct &info, VfxBool delayPlay)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_NOW_PLAYING_PLAY_SONG, m_mplayerSrv->getPlayAfterSwitchSong());

    if (m_nowPlaying)
    {
        m_mplayerSrv->stopDelayPlayTimer();

        m_nowPlaying->stop();
        m_nowPlaying->closeFile();
        
        if (delayPlay)
        {
            m_mplayerSrv->startDelayPlayTimer();

            m_ctrlPlayback->registerInterruptCallback();

            m_ctrlPlayback->setPlayState(m_mplayerSrv->getPlayAfterSwitchSong() ? PB_STATE_SWITCHING_PLAY : PB_STATE_SWITCHING_NOT_PLAY);
        }
        else
        {
            if (m_doPlayOnEntered)
            {
                // open only, hold the play action until now playing page onEntered
                // now move open to VappMusicPlayerApp::onPlayerPageCallback()
                //m_nowPlaying->open(info.filepath.getBuf());

                // reset duration to 0 before open
                m_ctrlPlayback->resetDuration();

                if (m_ctrlPlayback->getPlayState() != PB_STATE_PLAYBACK_FAIL)
                {
                    m_ctrlPlayback->setPlayState(PB_STATE_SWITCHING_PLAY);
                }
            }
            else
            {
                PlaybackStateEnum state = m_ctrlPlayback->getPlayState();

                if (!m_mplayerSrv->getActiveFilePath().isEmpty() 
                 && state != PB_STATE_INTERRUPTED
                 && state != PB_STATE_SWITCHING_NOT_PLAY)
                {
                    if (info.retValue == SRV_PLST_RET_EMPTY || !m_mplayerSrv->getPlayAfterSwitchSong())
                    {
                        // If song is valid, then open it and stop on the song
                        if(m_mplayerSrv->getSongValid(info.index))
                        {
                            m_nowPlaying->open(info.filepath);
                            m_nowPlaying->stop();
                        }
                        // Just set file path to control playback. (Open it will open fail and jump to next song to play)
                        else
                        {
                            m_ctrlPlayback->setFilePath(info.filepath);
                            m_ctrlPlayback->stop();
                        }
                    }
                    else
                    {
                        m_nowPlaying->play(m_mplayerSrv->getActiveFilePath());
                    }
                }
            }
        }

        m_nowPlaying->resetSlider();

        m_nowPlaying->updateTimeInfo();

        playerPageSetInfo(m_nowPlaying);
    }
}

VfxBool VappMusicPlayerApp::onPlaybackFail(VfxS32 result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PLAYBACK_FAIL, result);

    const VfxBool isTopActive = isGroupTopActive();
    const ViewTypeEnum viewType = getViewType();
    const VfxBool isPlayerPage = (m_coverFlow && (viewType == VIEW_TYPE_COVER_FLOW || viewType == VIEW_TYPE_COVER_FLOW_SONG))
                              || (m_nowPlaying && viewType == VIEW_TYPE_NOW_PLAYING);

    if (isTopActive && isPlayerPage)
    {
        VfxResId strID = m_ctrlPlayback->getMDIErrorMessage(result);
        
        if (m_coverFlow)
        {
            m_coverFlow->showErrorMessage(VFX_WSTR_RES(strID));
        }
        else if (m_nowPlaying)
        {
            m_nowPlaying->showErrorMessage(VFX_WSTR_RES(strID));

            // Hide lyrics panel if fail to play
            if (m_mplayerSrv->getSongLyricsState(m_mplayerSrv->getActiveIndex()))
            {
                m_nowPlaying->clearLyrics();
            }
        }

        return VFX_TRUE;
    }

    return VFX_FALSE;
}

void VappMusicPlayerApp::coverFlowPlaySong(SongInfoStruct &info, VfxBool delayPlay)
{
    if (m_coverFlow)
    {
        m_mplayerSrv->stopDelayPlayTimer();

        m_coverFlow->stop();
        m_coverFlow->closeFile();

        if (delayPlay)
        {
            m_mplayerSrv->startDelayPlayTimer();

            m_ctrlPlayback->registerInterruptCallback();

            m_ctrlPlayback->setPlayState(m_mplayerSrv->getPlayAfterSwitchSong() ? PB_STATE_SWITCHING_PLAY : PB_STATE_SWITCHING_NOT_PLAY);
        }
        else
        {
            PlaybackStateEnum state = m_ctrlPlayback->getPlayState();

            if (!m_mplayerSrv->getActiveFilePath().isEmpty() 
             && state != PB_STATE_INTERRUPTED
             && state != PB_STATE_SWITCHING_NOT_PLAY
             && (info.retValue == SRV_PLST_RET_EMPTY || !m_mplayerSrv->getPlayAfterSwitchSong()))
            {
                // If song is valid, then open it and stop on the song
                if(m_mplayerSrv->getSongValid(info.index))
                {
                    m_coverFlow->open(info.filepath);
                    m_coverFlow->stop();
                }
                // Just set file path to control playback. (Open it will open fail and jump to next song to play)
                else
                {
                    m_ctrlPlayback->setFilePath(info.filepath);
                    m_ctrlPlayback->setPlayState(PB_STATE_PLAYBACK_FAIL);
                }
            }
            else
            {
                m_coverFlow->play(m_mplayerSrv->getActiveFilePath());
            }
        }

        m_coverFlow->resetSlider();
        m_coverFlow->updateTimeInfo();

        playerPageSetInfo(m_coverFlow);
    }
}

void VappMusicPlayerApp::playerPageSetInfo(VappMusicPlayerPlayerBase *playerPage)
{
    if (playerPage)
    {
        // set title and artist text
        srv_plst_media_details_struct *detailInfo = NULL;
        VFX_ALLOC_MEM(detailInfo, sizeof(srv_plst_media_details_struct), this);

        VfxWString title, artist, count;

        if(m_mplayerSrv->getCurrDetailInfo(detailInfo))
        {
            title.loadFromMem(detailInfo->title);
            artist.loadFromMem(detailInfo->artist);
            count.format("%d / %d", m_provider->getActiveIndex()+1, m_provider->getActiveCount());
        }
        else if (m_provider->getActiveCount() == 0)
        {
            title.format("");
            artist.format("");
            count.format("");
        }
        else
        {
            title.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG);
            artist.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST);
            count.format("%d / %d", m_provider->getActiveIndex()+1, m_provider->getActiveCount());
        }

        VFX_FREE_MEM(detailInfo);

        if (checkPLSVAction() == VFX_FALSE) return;

        playerPage->setInfoText(title, artist, count);
    }
}

void VappMusicPlayerApp::nowPlayingSetFavorite()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_NOW_PLAYING_SET_FAVORITE);

    if (m_provider->isActiveSongInFavorite())
    {
        m_nowPlaying->setFavoriteBtn(VFX_FALSE);
    }
    else
    {
        m_nowPlaying->setFavoriteBtn(VFX_TRUE);
    }
}

void VappMusicPlayerApp::goToSetting()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_GO_TO_SETTING);

    setViewType(VIEW_TYPE_SETTING, CHANGE_VIEW_MODE_ENTER);
}

void VappMusicPlayerApp::goToSoundEffect()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_GO_TO_SOUND_EFFECT);

    setViewType(VIEW_TYPE_SETTING_SOUND_EFFECT, CHANGE_VIEW_MODE_ENTER);
}

void VappMusicPlayerApp::backFromSoundEffect()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_BACK_FROM_SOUND_EFFECT);

    setViewType(VIEW_TYPE_SETTING, CHANGE_VIEW_MODE_BACK);
}

void VappMusicPlayerApp::closeSetting()
{
    if (m_rootScreen->getViewStack() == VIEW_TYPE_SETTING_SOUND_EFFECT)
    {
        VfxPage *settingPage = m_rootScreen->getPage(m_rootScreen->getTopPageId());
        VappMusicPlayerSettingRadioPage *radioPage = VFX_OBJ_DYNAMIC_CAST(settingPage, VappMusicPlayerSettingRadioPage);
        if (radioPage)
        {
            // restore unsaved sound effect and pop the radio page
            radioPage->restoreValue();
            m_rootScreen->popPage();
            setViewType(VIEW_TYPE_SETTING, CHANGE_VIEW_MODE_BACK);

            if (checkPLSVAction(VFX_FALSE) == VFX_FALSE) return;
        }       
    }

    if (m_rootScreen->getViewStack() == VIEW_TYPE_SETTING)
    {
        // pop the setting page
        m_rootScreen->popPage();
        setViewType(VIEW_TYPE_NOW_PLAYING, CHANGE_VIEW_MODE_BACK);

        if (checkPLSVAction(VFX_FALSE) == VFX_FALSE) return;
    }
}

void VappMusicPlayerApp::goToCoverFlow(VfxScrRotateTypeEnum pageOrientation)
{
#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_GO_TO_COVER_FLOW);

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    if (!m_mplayerSrv->getMemoryCardReady())
    {
        return;
    }
#endif

#ifdef __COSMOS_3D_V10__
    if (isMakingCall())
    {
        return;
    }
#endif

    if (m_coverFlow)
    {
        return;
    }

    VappMusicPlayerListMenu *listMenu = getCurrListMenu();

    if (isSelecting())
    {
        // cancel all selecting action
        if (m_actionMode == ACTION_ADD_TO_PLAYLIST || m_actionMode == ACTION_PLAYLIST_ADD_SONG)
        {
            onFuncAddToPlaylistStop();
        }
        else
        {
            pageMultiSelectOff(getCurrPage(), VFX_FALSE);
            setActionMode(ACTION_NONE);
        }
    }
    else if (m_actionMode == ACTION_PLAYLIST_SONG_ARRANGE)
    {
        onFuncRearrangeStop();
    }

    if (listMenu)
    {
        listMenu->setIsFreezed(VFX_TRUE);
        //vfxPostInvoke1(listMenu, &VappMusicPlayerListMenu::setIsFreezed, VFX_FALSE);
    }

    if(isTabPage())
    {
        VappMusicPlayerSubPage *page = getCurrPage();
        if (page)
        {
            page->resetFocusChild();
        }
    }

    VappMusicPlayerScreen* scr = m_rootScreen;

    setViewType(VIEW_TYPE_COVER_FLOW, CHANGE_VIEW_MODE_ENTER);

    if (checkPLSVAction() == VFX_FALSE) return;
    
    if (m_coverFlow == NULL)
    {
#ifdef __COSMOS_3D_V10__
        VFX_OBJ_CREATE_EX(m_coverFlow, VappMusicPlayerCoverFlow3DPage, scr, (pageOrientation));
#else
        VFX_OBJ_CREATE_EX(m_coverFlow, VappMusicPlayerCoverFlowPage, scr, (pageOrientation));
#endif        
    }

    m_coverFlow->setCtrlPlayback(m_ctrlPlayback);
    m_coverFlow->m_signalCallback.connect(this, &VappMusicPlayerApp::onPlayerPageCallback);

    // initialize control panel's info & album cover
    VfxImageBuffer imgBuf;
    imgBuf.ptr = NULL;
    if (m_ctrlPlayback->getPlayState() == PB_STATE_NONE)
    {
        m_coverFlow->setEmpty();
    }
    else
    {
        playerPageSetInfo(m_coverFlow);
        m_coverFlow->updateTimeInfo();

        SongInfoStruct info;
        info.id = 0;
        info.index = 0;

        m_mplayerSrv->getCurrInfo(info);

        if (info.filepath.isEmpty())
        {
            m_coverFlow->setEmpty();
        }
        else
        {
            m_mplayerSrv->getAlbumCoverByDefaultBuffer(info.id, imgBuf);
            //if (checkPLSVAction() == VFX_FALSE) return;
        }
    }
    m_coverFlow->setAlbumCover(imgBuf);

    if (isMakingCall())
    {
        m_coverFlow->setEnablePlaybackUI(VFX_FALSE);
    }

    scr->pushPage(VIEW_TYPE_COVER_FLOW, m_coverFlow);

#endif //__COSMOS_MUSICPLY_COVER_FLOW__
}

void VappMusicPlayerApp::exitCoverFlow()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_EXIT_COVER_FLOW);
    
#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
    if (m_coverFlow)
    {
        if (getViewType() == VIEW_TYPE_COVER_FLOW_SONG)
        {
            m_coverFlow->hideAlbumDetailPanel(VFX_FALSE);
            onKeyBack();
        }
        onKeyBack();
        
        m_rootScreen->popPage();
    }
#endif //__COSMOS_MUSICPLY_COVER_FLOW__
}

VappMusicPlayerScreen* VappMusicPlayerApp::getRootScreen()
{
    if(m_rootScreenWeakPtr.isValid())
    {
        return m_rootScreen;
    }
    return NULL;
}

VappMusicPlayerSubPage* VappMusicPlayerApp::getCurrPage()
{
    if (getIsDying() || (getRootScreen() == NULL))
    {
        // this case is to block VcpTabCtrlPage from updating when AP is gonna closed
        return NULL;
    }

    VappMusicPlayerScreen* scr = getRootScreen();

    if (scr == getRootScreen() && scr->getViewStackCount() == 1)
    {
        if (m_tabPage)
        {
            VappMusicPlayerSubPage *page = VFX_OBJ_DYNAMIC_CAST(m_tabPage->getTabPage(m_tabPage->getCurrTab()), VappMusicPlayerSubPage);
            VfxWeakPtr<VappMusicPlayerSubPage> pageWPtr = page;
            return pageWPtr.isValid() ? page : NULL;
        }
    }
    else if (getViewType() == VIEW_TYPE_NOW_PLAYING)
    {
        // currunt page is now playing page
        return NULL;
    }
    else if (getViewType() == VIEW_TYPE_COVER_FLOW || getViewType() == VIEW_TYPE_COVER_FLOW_SONG)
    {
        // currunt page is cover flow page
        return NULL;
    }
    else
    {
        VfxPage *page = scr->getPage(scr->getTopPageId());
        VappMusicPlayerSubPage *subPage = VFX_OBJ_DYNAMIC_CAST(page, VappMusicPlayerSubPage);
        if (subPage)
        {
            VfxWeakPtr<VappMusicPlayerSubPage> pageWPtr = subPage;
            return pageWPtr.isValid() ? subPage : NULL;
        }
        else
        {
            // currunt page is setting page or sound effect page
            return NULL;
        }
    }

    return NULL;
}

VappMusicPlayerSubPage* VappMusicPlayerApp::getPageBeforeAction()
{
    // get the page before add to playlist or playlist add song

    VappMusicPlayerSubPage *page;

    if (m_actionMode == ACTION_ADD_TO_PLAYLIST && getViewType() == VIEW_TYPE_PLAYLIST_SELECT)
    {
        if (m_rootScreen->getViewStackCount() > 2)
        {
            ViewTypeEnum preViewType = getPreViewType();
            page = VFX_OBJ_DYNAMIC_CAST(m_rootScreen->getPage(preViewType), VappMusicPlayerSubPage);
        }
        else
        {
            page = getCurrTabPage();
        }
    }
    else if (m_actionMode == ACTION_PLAYLIST_ADD_SONG)
    {
        //page = VFX_OBJ_DYNAMIC_CAST(m_rootScreen->getPage(VIEW_TYPE_PLAYLIST_SONG), VappMusicPlayerSubPage);
        page = getCurrTabPage();
    }
    else
    {
        page = getCurrPage();
    }

    return page;
}

VappMusicPlayerSubPage* VappMusicPlayerApp::getTabPage(VfxId ID)
{
    VfxPage *page = m_tabPage->getTabPage(ID);
    return VFX_OBJ_DYNAMIC_CAST(page, VappMusicPlayerSubPage);
}

VappMusicPlayerSubPage* VappMusicPlayerApp::getCurrTabPage()
{
    return getTabPage(m_tabPage->getCurrTab());
}

VfxBool VappMusicPlayerApp::closeTabPage(VfxId ID)
{
    VfxPage *page = m_tabPage->getTabPage(ID);
    if (page)
    {
        VFX_OBJ_CLOSE(page);

        if (ID == FUNC_ID_TAB_ALBUM)
        {
            m_provider->freeMediaCache();
        }
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappMusicPlayerApp::disableTabPageTab(VfxBool isDisable)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_DISABLE_TAB_PAGE, isDisable);

    if(m_tabPage)
    {
        m_tabPage->disableAllTab(isDisable);
    }
}

VappMusicPlayerListMenu* VappMusicPlayerApp::getCurrListMenu()
{
    VappMusicPlayerSubPage *page = getCurrPage();
    if (page)
    {
        return page->getListMenu();
    }
    
    return NULL;
}

VfxBool VappMusicPlayerApp::isListMenuPenDown()
{
    return getCurrListMenu() && getCurrListMenu()->getIsPenDown();
}

VfxU32 VappMusicPlayerApp::getSelectItemIdx()
{
    return m_selectItemIdx;
}

VfxU32 VappMusicPlayerApp::getSelectItemId()
{
    return m_selectItemId;
}

VfxU32 VappMusicPlayerApp::getSelectItemCount()
{
    // Update the total artist count if is is changed when delete in artist album view
    if(getViewType() == VIEW_TYPE_ARTIST_ALBUM)
    {
        if(m_selectItemCount == VAPP_MUSICPLY_DEF_LARGE_NUM)
        {
            m_selectItemCount = m_provider->getFixedCount(VIEW_TYPE_ARTIST, m_selectItemId);
        }
    }

    return m_selectItemCount;
}

VfxBool VappMusicPlayerApp::isSelecting()
{
    if (m_provider)
    {
        return m_provider->isSelectStart();
    }

    return VFX_FALSE;
}

VfxBool VappMusicPlayerApp::isTabPage()
{
    // If stack only have one item, or not any item in view(DB async opening), then it must on the tab page
    if ((m_rootScreen->getViewStackCount() == 1) || (m_rootScreen->getViewStackCount() == 0))
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappMusicPlayerApp::resetPenInput()
{
    if(!isGroupActive())
    {
        return;
    }

#ifdef __MMI_TOUCH_SCREEN__
    if (!m_isNCenterVisable)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_RESET_PEN_INPUT);

        mmi_pen_reset();
    }
#endif
}

void VappMusicPlayerApp::resetKeyInput()
{
    if(getViewType() != VIEW_TYPE_NOW_PLAYING || !isGroupActive())
    {
        return;
    }

    VfxKeypad *key = VFX_OBJ_GET_INSTANCE(VfxKeypad);
    if (key)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_RESET_KEY_INPUT);

        key->reset();
    }
}

void VappMusicPlayerApp::onKeyBack()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_KEY_BACK);

    // Close all popup and cancel action
    if (closeAllPopup())
    {
        return;
    }

    ViewTypeEnum preViewType = getPreViewType();

    if (m_actionMode == ACTION_DELETE
     || (m_actionMode == ACTION_ADD_TO_PLAYLIST && getViewType() != VIEW_TYPE_PLAYLIST_SELECT)
     || m_actionMode == ACTION_PLAYLIST_REMOVE
     || (preViewType != VIEW_TYPE_NONE && isSelecting()))
    {
        // handle these cases as pressing cancel button
        eventHandler(NULL, FUNC_ID_TB_BTN_CANCEL);
    }
    else if (m_actionMode == ACTION_PLAYLIST_SONG_ARRANGE)
    {
        onFuncRearrangeStop();
    }
    else
    {
        const ViewTypeEnum viewType = getViewType();

        if (viewType == VIEW_TYPE_ARTIST_SONG)
        {
            // Back from artist all songs
            setViewType(preViewType, CHANGE_VIEW_MODE_BACK, m_selectItemId);

            if (checkPLSVAction() == VFX_FALSE) return;
        }
        else if(isTabPage())
        {
            const PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
            if (state == PB_STATE_NONE || state == PB_STATE_CLOSE)
            {
                // This case is when tab ctrl page got the focus
                setIsDying();
            }
            return;
        }
        else
        {
            if (m_actionMode == ACTION_ADD_TO_PLAYLIST && viewType == VIEW_TYPE_PLAYLIST_SELECT)
            {
                // close playlist selection page
                preViewType = getPreViewType();
            }
            else if (m_actionMode == ACTION_PLAYLIST_ADD_SONG && viewType == VIEW_TYPE_VIEW_SELECT)
            {
                // close view type select page
                setActionMode(ACTION_NONE);
            }
            else if (preViewType == VIEW_TYPE_ARTIST || preViewType == VIEW_TYPE_PLAYLIST)
            {
                m_selectItemIdx = VAPP_MUSICPLY_DEF_LARGE_NUM;
            }

            setViewType(preViewType, CHANGE_VIEW_MODE_BACK);

            if (checkPLSVAction() == VFX_FALSE) return;

            VappMusicPlayerListMenu *listMenu = getCurrListMenu();
            if (listMenu)
            {
                vfxPostInvoke1(listMenu, &VappMusicPlayerListMenu::setIsFreezed, VFX_FALSE);
            }
        }
    }
}

void VappMusicPlayerApp::onScreenRotate(VfxScrRotateTypeEnum rotateTo)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_SCREEN_ROTATE, rotateTo);
    
    if (m_ctrlPlayback == NULL || m_provider == NULL || m_isEntering)
    {
        return;
    }

    if (hasPopup() || m_actionMode != ACTION_NONE)
    {
        // some scenarios that will block entering / leaving cover flow:
        // there's a popup or in the multi selection mode
        return;
    }

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__   

    if(rotateTo == VFX_SCR_ROTATE_TYPE_90 || rotateTo == VFX_SCR_ROTATE_TYPE_270)
    {   
        goToCoverFlow(rotateTo);
    }
    else
    {
#ifdef __COSMOS_3D_V10__
        VappMusicPlayerCoverFlow3DPage *coverFlow = getCoverFlow();
        m_coverFlowToNowPlaying = coverFlow->m_hasStartPlayback;
#else
        VappMusicPlayerCoverFlowPage *coverFlow = getCoverFlow();
        m_coverFlowToNowPlaying = coverFlow->m_hasStartPlayback;
#endif  

        if (coverFlow)
        {
            // exit cover flow on rotate to 0 or 180
            exitCoverFlow();

            // go to nowplaying if start playback in cover flow
            if (m_coverFlowToNowPlaying)
            {
                ViewTypeEnum viewType = getViewType();
                if (viewType == VIEW_TYPE_NOW_PLAYING_LIST)
                {
                    // exit active playlist page to now playing
                    VappMusicPlayerSubPage *page = getCurrPage();
                    if (page)
                    {
                        page->exit();
                    }
                    onKeyBack();
                    playerPageSetInfo(m_nowPlaying);
                }
                else if (viewType == VIEW_TYPE_NOW_PLAYING)
                {
                    playerPageSetInfo(m_nowPlaying);
                }
                else if (viewType == VIEW_TYPE_SETTING || viewType == VIEW_TYPE_SETTING_SOUND_EFFECT)
                {
                    closeSetting();
                }
                else if (!m_nowPlaying)
                {
                    goToNowPlaying();
                }
                else
                {
                    // should not happen
                }

                // this flag is used to block duplicated playlist checking when going back from coverflow to nowplaying
                m_coverFlowToNowPlaying = VFX_FALSE;
            }
        }
    }
#endif //__COSMOS_MUSICPLY_COVER_FLOW__
}

void VappMusicPlayerApp::playerPagePlaySong(SongInfoStruct &info, VappMusicPlayerPageSwitchDirEnum dir, VfxBool delayPlay)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_PLAYER_PAGE_PLAY_SONG, m_mplayerSrv->getPlayAfterSwitchSong());

    m_mplayerSrv->setIsDelayPlay(delayPlay);

    const ViewTypeEnum viewType = getViewType();

    m_mplayerSrv->stopFindNextTimer();

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
    if (m_coverFlow && (viewType == VIEW_TYPE_COVER_FLOW || viewType == VIEW_TYPE_COVER_FLOW_SONG))
    {
        VfxImageBuffer imgBuf;
        m_mplayerSrv->getAlbumCoverByDefaultBuffer(info.id, imgBuf);
        //if (checkPLSVAction() == VFX_FALSE) return;

        m_coverFlow->setAlbumCover(imgBuf);

        if (m_nowPlaying)
        {
            nowPlayingSetFavorite();

            m_nowPlaying->setAlbumCover(info.id, info.filepath, dir);
            
            playerPageSetInfo(m_nowPlaying);
        }

        if (getViewType() == VIEW_TYPE_COVER_FLOW_SONG)
        {
            updateHighLight();
        }

        // play song after handling album cover
        coverFlowPlaySong(info, delayPlay);
    }
    else 
#endif // __COSMOS_MUSICPLY_COVER_FLOW__
    if (m_nowPlaying && (VIEW_TYPE_NOW_PLAYING <= viewType && viewType <= VIEW_TYPE_SETTING_SOUND_EFFECT))
    {   
        nowPlayingSetFavorite();

        m_nowPlaying->setAlbumCover(info.id, info.filepath, dir);

        if (getViewType() == VIEW_TYPE_NOW_PLAYING_LIST)
        {
            updateHighLight();
        }

        // play song after handling album cover
        nowPlayingPlaySong(info, delayPlay);
    }
    else
    {
        m_mplayerSrv->onPlay(delayPlay);  

        const ViewTypeEnum viewType = getViewType();
        if (viewType == VIEW_TYPE_ALL_SONGS 
         || viewType == VIEW_TYPE_ARTIST_SONG
         || viewType == VIEW_TYPE_ARTIST_ALBUM_SONG
         || viewType == VIEW_TYPE_ALBUM_SONG
         || (viewType == VIEW_TYPE_PLAYLIST_SONG && m_actionMode != ACTION_PLAYLIST_SONG_ARRANGE)
         || viewType == VIEW_TYPE_PLAYLIST_ADD_ALL_SONG
         || viewType == VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG
         || viewType == VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG)
        {
            if (m_provider->isActiveView(viewType) && !m_provider->isSearching())
            {
                updateHighLight();
            }
            else
            {
                updateContent(-1, VFX_FALSE, VFX_FALSE);
            }
        }
    }

    ////>m_ctrlPlayback->clearInterruptState(VFX_TRUE, VFX_TRUE);
}

void VappMusicPlayerApp::playerPageResetErrorMsg()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_PLAYER_PAGE_RESET_ERROR_MSG);

    if (m_coverFlow)
    {
        m_coverFlow->clearErrorMessage();
    }
    if (m_nowPlaying)
    {
        m_nowPlaying->clearErrorMessage();
    }
}

void VappMusicPlayerApp::playerPageResetSlider()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_PLAYER_PAGE_RESET_SLIDER);

    if (m_coverFlow)
    {
        m_coverFlow->resetSlider();
    }
    if (m_nowPlaying)
    {
        m_nowPlaying->resetSlider();
    }
}

void VappMusicPlayerApp::playerPageMaximizeSlider()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_PLAYER_PAGE_MAXIMIZE_SLIDER);

    if (m_coverFlow && !m_coverFlow->m_sliderDragging)
    {
        m_coverFlow->maximizeSlider();
    }
    if (m_nowPlaying && !m_nowPlaying->m_sliderDragging)
    {
        m_nowPlaying->maximizeSlider();
    }
}

void VappMusicPlayerApp::onPrevNext(VfxBool isNext, GetNextModeEnum nextMode, VfxBool delayPlay, VfxS32 plsvRet)
{
    if (plsvRet < SRV_PLST_OK && plsvRet != SRV_PLST_RET_EMPTY)
    {
        // suppose this case only happens by plugging out memory card while seeking, do not close APP since this is not a critical error
        /*
        // handle fail to get next song
        m_mplayerSrv->onStop();
        
        VfxResId strID = m_provider->getErrorStrId(plsvRet);
        exitOnError(strID);
        */
        
        return;
    }

    if(m_delayUpdatePrevNext)
    {
        m_delayUpdatePrevNext->stop();
    }

    // Swap song first if in reorder mode
    if (m_actionMode == ACTION_PLAYLIST_SONG_ARRANGE)
    {
        // Check if dragging song
        VfxBool isDragging = getCurrListMenu()->getIsDraggingCell();
        
        if (isDragging && m_reorderStartIdx != 0xFFFFFFFF && m_reorderStartIdx != m_reorderCurrIdx)
        {
            doListMenuCellSwap();
        }
    }

    if ((m_coverFlow && m_coverFlow->m_sliderDragging) || (m_nowPlaying && m_nowPlaying->m_sliderDragging)
     ||((m_actionMode == ACTION_RESET && m_popupWaiting)
     || (m_actionMode == ACTION_REFRESH && m_popupWaiting)
     || (m_actionMode == ACTION_ADD_TO_PLAYLIST && m_popupWaiting)
     || (m_actionMode == ACTION_PLAYLIST_ADD_SONG && m_popupWaiting)
     || (m_actionMode == ACTION_DELETE && m_popupIndicator)
     || (m_actionMode == ACTION_PLAYLIST_REMOVE && m_popupIndicator)))
    {
        // hold the song switching if play to end of file or getting next command from AVRCP while dragging slider
        // or during these actions
        m_playAfterAction.raised = VFX_TRUE;
        m_playAfterAction.isNext = isNext;
        m_playAfterAction.nextMode = nextMode;
        m_playAfterAction.delayPlay = delayPlay;

        resetKeyInput();

        return;
    }

    // Stop playback first to let list service have time to run
    if (m_coverFlow)
    {
        m_coverFlow->stop();
    }
    else if (m_nowPlaying)
    {
        m_nowPlaying->stop();
    }
    else
    {
        m_ctrlPlayback->stop();
    }

    // If change song before page onEntered(), do not handle FUNC_ID_PAGE_ENTERED
    m_doPlayOnEntered = VFX_FALSE;
    
    playerPageResetErrorMsg();
    playerPageResetSlider();

    SongInfoStruct info;
    m_mplayerSrv->getCurrInfo(info);

    if (info.id == 0 && info.index == 0)
    {
        // handle fail to get next song
        if (m_coverFlow)
        {
            m_coverFlow->stop();
            m_coverFlow->updateCurrTime();
        }

        if (m_nowPlaying)
        {
            m_nowPlaying->stop();
            m_nowPlaying->updateCurrTime();
        }
    }
    else
    {
        // successfully get next song, try to start playback
        playerPagePlaySong(info, isNext ? PAGE_SWITCH_DIR_RIGHT : PAGE_SWITCH_DIR_LEFT, delayPlay);

        // The index does not update in next() function, start a timer to update after song switched
        if(m_nowPlaying && nextMode == NEXT)
        {
            m_delayUpdatePrevNext->start();
        }
    }

    resetKeyInput();
}

void VappMusicPlayerApp::onPrevNextDelayUpdateTimeout(VfxTimer *Timer)
{
    m_provider->updateActiveIndex();

    if(m_nowPlaying)
    {
        VfxWString count;

        count.format("%d / %d", m_provider->getActiveIndex()+1, m_provider->getActiveCount());
        m_nowPlaying->setSongCountInfoText(count);
        m_provider->setHighLighIndex(m_provider->getActiveIndex());
    }
}

void VappMusicPlayerApp::onStop()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_STOP);

    // Do not call this function, call VappMusicPlayerService::onStop() instead

    m_mplayerSrv->stopFindNextTimer();

    playerPageResetErrorMsg();
    playerPageResetSlider();
}

void VappMusicPlayerApp::onMemoryCardChange()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_MEMORY_CARD_CHANGE, 0);

    goToRoot();

    if (!isGroupTopActive())
    {
        // in hidden state, goToRoot will skip the following update
        m_provider->updateCount();
        m_provider->updateActiveCount();
        m_provider->updateActiveIndex();
        m_provider->updateActiveID();
        m_provider->resetHighLighIndex();
    }

    m_ctrlPlayback->setPlayState(PB_STATE_NONE);
    
    updateToolbarItemState();

    VfxTimer *t;
    VFX_OBJ_CREATE(t, VfxTimer, this);
    t->setStartDelay(300);
    t->m_signalTick.connect(this, &VappMusicPlayerApp::handlePostMemoryCardChange);
    t->start();
}

void VappMusicPlayerApp::handlePostMemoryCardChange(VfxTimer *t)
{
    m_provider->freeMediaCache();

    VFX_OBJ_CLOSE(t);
}

void VappMusicPlayerApp::setActionMode(ActionEnum action)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SET_ACTION_MODE, action);
    m_actionMode = action;
}

void VappMusicPlayerApp::onFuncNewPlaylist()
{
    setActionMode(ACTION_PLAYLIST_NEW);

    // set default playlist name
    VfxU32 serial = 1;
    VfxWString playlistName;
    VfxWString serialText;
    do
    {
        playlistName.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_DEF_PLST_NAME);
        serialText.format("%02d", serial++);
        playlistName += serialText;
    }while(m_provider->isPlaylistExist(playlistName));

    popupInput(
        VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_NEW_PLAYLIST), 
        VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_PLST_NAME), 
        playlistName, 
        VAPP_MUSICPLY_PLAYLIST_NAME_MAX
        );
}

void VappMusicPlayerApp::onFuncAddToPlaylist()
{
    setActionMode(ACTION_ADD_TO_PLAYLIST);
    pageMultiSelectOn(getCurrPage(), VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO_PLST));
}

void VappMusicPlayerApp::onFuncAddToPlaylistStop()
{
    if (m_actionMode == ACTION_ADD_TO_PLAYLIST || m_actionMode == ACTION_PLAYLIST_ADD_SONG)
    {
        VappMusicPlayerListMenu *listMenu = getPageBeforeAction()->getListMenu();
        if (listMenu)
        {
            listMenu->setIsFreezed(VFX_FALSE);
        }
    }

    if (m_actionMode == ACTION_ADD_TO_PLAYLIST)
    {
        setViewType(getPreViewType(), CHANGE_VIEW_MODE_BACK, 0);
        if (checkPLSVAction() == VFX_FALSE) return;

        m_rootScreen->popPage();

        if (m_longTapComm.action == ACTION_ADD_TO_PLAYLIST)
        {
            m_longTapComm.action = ACTION_NONE;
            m_longTapComm.index = 0;

            if (m_provider->isSearching())
            {
                searchCancel();
                updateContent(-1, VFX_FALSE, VFX_FALSE, VFX_TRUE);
            }
        }
        else
        {
            pageMultiSelectOff(getPageBeforeAction(), VFX_FALSE);
        }

        // Reset valid list if it is active playing list for adding
        if(m_provider->getHighLightPlayListId() == m_playListId)
        {
            m_mplayerSrv->initActiveListValidState();
        }

        m_selectItemIdx = VAPP_MUSICPLY_DEF_LARGE_NUM;
    }
    else if (m_actionMode == ACTION_PLAYLIST_ADD_SONG)
    {
        popToPage(VIEW_TYPE_PLAYLIST_SONG);
        pageMultiSelectOff(getPageBeforeAction(), VFX_FALSE);

        // Reset valid list if it is active playing list for adding
        if(m_provider->isActiveView(VIEW_TYPE_PLAYLIST_SONG))
        {
            m_mplayerSrv->initActiveListValidState();
        }

        if (checkPLSVAction() == VFX_FALSE) return;

        updateContent();
        updateToolbarItemState();
    }   

    setActionMode(ACTION_NONE);
}

void VappMusicPlayerApp::postProcFuncAddToPlaylistStop(VfxTimer *t)
{
    VFX_OBJ_CLOSE(t);

    onFuncAddToPlaylistStop();

    showBalloon(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_MENU_ADD_TO_PLST));

    if (m_playAfterAction.raised)
    {
        // this case is for trying to change to next song during deleting progress
        // hold the action until the deleting complete

        m_playAfterAction.raised = VFX_FALSE;

        if (m_playAfterAction.isNext)
        {
            m_mplayerSrv->onNext(m_playAfterAction.nextMode, m_playAfterAction.delayPlay);
        }
        else
        {
            m_mplayerSrv->onPrev( m_playAfterAction.delayPlay);
        }
    }
}

void VappMusicPlayerApp::onFuncAddToPlaylistSelect()
{
    //setViewType(VIEW_TYPE_PLAYLIST_SELECT, CHANGE_VIEW_MODE_ENTER, index);
    VfxBool ret = m_rootScreen->goToNextPage(VIEW_TYPE_PLAYLIST_SELECT, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TITLE_ADD_TO_PLST));
    if (!ret) return;

    if(m_checkDuplicatedPlaylistRunning)
    {
        showWaitIcon(VFX_TRUE);
    }
}

void VappMusicPlayerApp::postProcAddToPlaylist(VfxTimer *t)
{
    popupWaiting(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_Popup_ADDING));
    
    const VfxBool isMulti = m_longTapComm.action == ACTION_NONE;
    vfxPostInvoke2(this, &VappMusicPlayerApp::doAddToPlaylist, m_selectItemIdx, isMulti);
}

void VappMusicPlayerApp::onFuncPlaylistAddSong()
{
    // stop list menu scrolling to prevent querying data from PLSV
    VappMusicPlayerListMenu *listMenu = getCurrListMenu();
    if (listMenu)
    {
        listMenu->stopScrolling();
    }
    
    popupWaiting(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_Popup_ADDING));

    const VfxBool isMulti = m_longTapComm.action == ACTION_NONE;
    vfxPostInvoke2(this, &VappMusicPlayerApp::doAddToPlaylist, m_selectItemIdx, isMulti);
}

void VappMusicPlayerApp::doAddToPlaylist(VfxU32 index, VfxBool isMulti)
{
    m_playListId = m_provider->getID(index);

    if (isMulti)
    {
        m_provider->addSelectedToPlaylist(index);
    }
    else
    {
        // for long tap action
        m_provider->addToPlaylist(m_longTapComm.index, index);
    }
}

void VappMusicPlayerApp::onFuncDeleteStep1()
{
    if (m_actionMode == ACTION_DELETE)
    {
        pageMultiSelectOn(getCurrPage(), VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE));
    }
    else if (m_actionMode == ACTION_PLAYLIST_REMOVE)
    {
        pageMultiSelectOn(getCurrPage(), VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE));
    }
}

void VappMusicPlayerApp::onFuncDeleteStep2(VfxBool isMulti)
{
    // Step2: popup confirm

    VfxWString strHint;
    VfxWString strBtn;

    switch (getViewType())
    {
        case VIEW_TYPE_ALL_SONGS:
        case VIEW_TYPE_ARTIST_SONG:
        case VIEW_TYPE_ARTIST_ALBUM_SONG:
        case VIEW_TYPE_ALBUM_SONG:
            if (isMulti)
            {
                VfxWString selectCount;
                selectCount.format("(%d)?", m_provider->getSelectingCount());
                strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_HINT);
                strHint += selectCount;
            }
            else
            {
                strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_SONG);
            }
            strBtn.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_BTN_DELETE);
            break;

        case VIEW_TYPE_PLAYLIST_SONG:
            if (isMulti)
            {
                VfxWString selectCount;
                selectCount.format("(%d)?", m_provider->getSelectingCount());
                strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVE_HINT);
                strHint += selectCount;
            }
            else
            {
                strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_RMV_SONG);
            }
            strBtn.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
            break;

        case VIEW_TYPE_NOW_PLAYING_LIST:
            if (m_provider->getActiveListType() == SRV_PLST_ACTIVE_LIST_AUDIO)
            {
                strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_SONG);
                strBtn.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_BTN_DELETE);
            }
            else if (m_provider->getActiveListType() == SRV_PLST_ACTIVE_LIST_PLST)
            {
                strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_RMV_SONG);
                strBtn.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
            }
            else
            {
                // should not have other case
                VFX_ASSERT(0);
            }
            break;

        case VIEW_TYPE_ARTIST:
            {
                if (isMulti)
                {
                    VfxWString selectCount;
                    selectCount.format("(%d)?", m_provider->getSelectingCount());
                    strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_ARTIST_HINT);
                    strHint += selectCount;
                }
                else
                {
                    strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_ARTIST);
                }
                strBtn.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_BTN_DELETE);
            }
            break;

        case VIEW_TYPE_ALBUM:
        case VIEW_TYPE_ARTIST_ALBUM:
            {
                if (isMulti)
                {
                    VfxWString selectCount;
                    selectCount.format("(%d)?", m_provider->getSelectingCount());
                    strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_ALBUM_HINT);
                    strHint += selectCount;
                }
                else
                {
                    strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_ALBUM);
                }
                strBtn.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_BTN_DELETE);
            }
            break;

        case VIEW_TYPE_PLAYLIST:
            {
                if (isMulti)
                {
                    VfxWString selectCount;
                    selectCount.format("(%d)?", m_provider->getSelectingCount());
                    strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_PLST_HINT);
                    strHint += selectCount;
                }
                else
                {
                    strHint.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_PLST);
                }
                strBtn.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_BTN_DELETE);
            }
            break;

        default:
            break;
    };

    popupConfirm(
        strHint,
        strBtn,
        VCP_POPUP_TYPE_WARNING,
        VCP_CONFIRM_BUTTON_SET_USER_DEFINE,
        VCP_POPUP_BUTTON_TYPE_WARNING
        );
}

void VappMusicPlayerApp::onFuncDeleteStop()
{
    pageMultiSelectOff(getPageBeforeAction());
    setActionMode(ACTION_NONE);
    m_longTapComm.action = ACTION_NONE;

    m_provider->resetMediaCache();
    
    updateContent(); 
    
    //MAUI_03214587: Update count if delete is interrupted. 
    //(It will not update count in page onEnter() or updateContent())
    if (!isGroupActive())
    {
        m_provider->updateCount();
    }
    
    m_mplayerSrv->initActiveListValidState();

    // Update view if nubmer or info changed by delete
    onFuncDeleteStopUpdateView();

    popupProgressClose();

    const VfxU32 activeCount = m_provider->getActiveCount();
    if (m_playAfterAction.raised && (activeCount > 0))
    {
        // this case is for trying to change to next song during deleting progress
        // hold the action until the deleting complete
        m_playAfterAction.raised = VFX_FALSE;
        onPrevNext(m_playAfterAction.isNext, m_playAfterAction.nextMode, m_playAfterAction.delayPlay, 0);
    }

    // turn on back light to restart back light timer
    if (!isBackLightOn() && vapp_screen_lock_is_allowed_launch())
    {
        vapp_screen_lock_launch();
    }
}

void VappMusicPlayerApp::postProcFuncDeleteStop(VfxTimer *t)
{
    VFX_OBJ_CLOSE(t);

    onFuncDeleteStop();
}

void VappMusicPlayerApp::onFuncDeleteStopUpdateView()
{
    const VfxU32 activeCount = m_provider->getActiveCount();
    
    // If active count become 0, then clear active list and state
    if (activeCount == 0)
    {
        m_ctrlPlayback->setPlayState(PB_STATE_NONE);
        m_ctrlPlayback->clearInterruptState();
        m_mplayerSrv->clearActivePlaylist();
    }

    ViewTypeEnum viewtype = getViewType();

    // Update nowplaying screen info if back from now playing list
    if (viewtype == VIEW_TYPE_NOW_PLAYING_LIST && m_nowPlaying)
    {
        if (activeCount > 0)
        {
            playerPageSetInfo(m_nowPlaying);
        }
        else
        {
            m_nowPlaying->setEmpty();
        }

        if(m_rootScreen->isViewInStack(VIEW_TYPE_ARTIST_SONG) ||
           m_rootScreen->isViewInStack(VIEW_TYPE_ARTIST_ALBUM) ||
           m_rootScreen->isViewInStack(VIEW_TYPE_ARTIST_ALBUM_SONG))
        {
            // Invalidate the all artist number and update after back
            m_selectItemCount = VAPP_MUSICPLY_DEF_LARGE_NUM;
        }
    }
    else if (viewtype == VIEW_TYPE_ARTIST_ALBUM_SONG)
    {
        // Invalidate the all artist number and update after back
        m_selectItemCount = VAPP_MUSICPLY_DEF_LARGE_NUM;
    }
    else if (viewtype == VIEW_TYPE_ARTIST_SONG)
    {
        m_selectItemCount = m_provider->getCount();
    }

}

void VappMusicPlayerApp::onFuncPlaylistRename()
{
    setActionMode(ACTION_PLAYLIST_RENAME);
    VfxWString name;
    if (getViewType() == VIEW_TYPE_PLAYLIST)
    {
        // Enter this case by long press
        m_provider->getTitle(m_longTapComm.index, name);
    }
    else
    {
        // Enter this case by toolbar button
        if (getCurrPage())
        {
            VappMusicPlayerSubPage *page = getCurrPage();
            if (page)
            {
                name = page->getTitleBar()->getTitle();
            }
        }
    }

    popupInput(
        VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVE_TITLE), 
        VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_PLST_NAME), 
        name, 
        VAPP_MUSICPLY_PLAYLIST_NAME_MAX
        );
}

void VappMusicPlayerApp::onFuncRearrangeStart()
{
    setActionMode(ACTION_PLAYLIST_SONG_ARRANGE);
    m_provider->rearrangeStart();

    VappMusicPlayerListMenu *listMenu = getCurrListMenu();
    if (listMenu)
    {
        listMenu->setMenuMode(VCP_LIST_MENU_MODE_REORDER, VFX_TRUE);
        listMenu->setItemHighlightHidden(VFX_TRUE);
        
        // disconnect the tap event during reorder mode
        listMenu->m_signalItemTapped.disconnect(this, &VappMusicPlayerApp::onListMenuItemTapped);
        listMenu->m_signalItemLongTapped.disconnect(this, &VappMusicPlayerApp::onListMenuItemLongTapped);
        listMenu->m_signalDragCell.connect(this, &VappMusicPlayerApp::onListMenuDragCell);
    }

    updateContent();

    VappMusicPlayerSubPage *page = getCurrPage();
    if (page)
    {
        VcpToolBar *bar = page->getToolBar();
        if (bar)
        {
            bar->setIsUnhittable(VFX_TRUE);
        }

        page->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_FALSE);
    }

    // do not show high light
    m_provider->setShowPlayIcon(VFX_FALSE);
}

void VappMusicPlayerApp::onFuncRearrangeStop()
{
    m_provider->rearrangeEnd();

    VappMusicPlayerListMenu *listMenu = getCurrListMenu();
    if (listMenu)
    {
        listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        listMenu->setItemHighlightHidden(VFX_FALSE);        
    
        // reconnect the tap event after reorder mode    
        listMenu->m_signalItemTapped.connect(this, &VappMusicPlayerApp::onListMenuItemTapped);
        listMenu->m_signalItemLongTapped.connect(this, &VappMusicPlayerApp::onListMenuItemLongTapped);
        listMenu->m_signalDragCell.disconnect(this, &VappMusicPlayerApp::onListMenuDragCell);
    }

    updateContent();
    VappMusicPlayerSubPage *page = getCurrPage();
    if (page)
    {
        VcpToolBar *bar = page->getToolBar();
        if (bar)
        {
            bar->setIsUnhittable(VFX_FALSE);
        }

        page->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
    }
    setActionMode(ACTION_NONE);

    // reset m_showPlayIcon to show high light
    PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
    VfxBool byState = (state != PB_STATE_NONE) && (state != PB_STATE_CLOSE);
    m_provider->setShowPlayIcon(byState || m_mplayerSrv->getIsDelayPlay());
}

void VappMusicPlayerApp::onFuncRefreshDB()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_FUNC_REFRESH_DB);

    // stop list menu scrolling to prevent querying data from PLSV
    VappMusicPlayerListMenu *listMenu = getCurrListMenu();
    if (listMenu)
    {
        listMenu->stopScrolling();
    }

    // Stop find next procedure
    m_mplayerSrv->stopFindNextTimer();
    m_mplayerSrv->stopDelayPlayTimer();

    // Pause the music play
    if (m_ctrlPlayback->getPlayState() == PB_STATE_PLAY)
    {
        if(m_ctrlPlayback->isSongSeekable(NULL))
        {
            m_ctrlPlayback->pause();
        }
        else
        {
            m_ctrlPlayback->stop();
        }
    }

    if (m_ctrlPlayback->getPlayState() == PB_STATE_SEEKING)
    {
        m_ctrlPlayback->m_playStateBeforeSeek = PB_STATE_PAUSE;
    }


    if (m_provider)
    {
        if (getViewType() != VIEW_TYPE_ALBUM)
        {
            m_provider->freeMediaCache();
        }

        m_tabPage->setCurrTab(FUNC_ID_TAB_ALL_SONG);
        m_provider->refreshDB();
        
        if (checkPLSVAction())
        {
            popupWaiting(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_REFRESHING));
        }
    }
}

void VappMusicPlayerApp::onFuncRefreshDBCancel()
{
    m_provider->refreshDBCancel();
    setActionMode(ACTION_NONE);

    // force unfreeze the list menu here, it may be freezed in onProcessClose
    if (getCurrListMenu())
    {
        getCurrListMenu()->setIsFreezed(VFX_FALSE);
    }

    updateContent(-1, VFX_TRUE, VFX_TRUE, VFX_TRUE);
}

void VappMusicPlayerApp::onFuncResetDB()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_FUNC_RESET_DB);

    // stop and close playback file, go to root, show waiting, reset DB
    m_mplayerSrv->onStop();
    
    goToRoot();

    setActionMode(ACTION_RESET);

    m_provider->freeMediaCache();

    m_provider->resetDB();

    m_mplayerSrv->clearActivePlaylist();

    if (checkPLSVAction())
    {
        popupWaiting(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_RESETTING), VFX_FALSE);
    }
}

void VappMusicPlayerApp::startCheckDuplicatedPlaylist(void)
{
    if (!m_needCheckDuplicatedPlaylist)
    {
        return;
    }

    if (m_checkDupliactedPlaylistTimer == NULL)
    {
        VFX_OBJ_CREATE(m_checkDupliactedPlaylistTimer, VfxTimer, this);
        m_checkDupliactedPlaylistTimer->setStartDelay(1);
        m_checkDupliactedPlaylistTimer->m_signalTick.connect(this, &VappMusicPlayerApp::checkDuplicatedPlaylistHdlr);
    }
    
    // To notify ctrlPLSV to return empty content while processing
    VappMusicPlayerSubPage *page = getCurrPage();
    if (page && page->m_contentProvider)
    {
        page->m_contentProvider->setCheckingDuplicatedPlaylist(VFX_TRUE);
    }
    m_checkDuplicatedPlaylistRunning = VFX_TRUE;
    checkDuplicatedPlaylistHdlr(NULL);
}

void VappMusicPlayerApp::checkDuplicatedPlaylistHdlr(VfxTimer *timer)
{
    if(!m_checkDuplicatedPlaylistRunning)
    {
        return;
    }

    VfxBool finish = checkDuplicatedPlaylist(timer == NULL);    // timer == NULL means it is the first round

    if(finish)
    {
        VappMusicPlayerSubPage *page = getCurrPage();
        if(page && page->m_contentProvider)
        {
            page->m_contentProvider->setCheckingDuplicatedPlaylist(VFX_FALSE);
            page->disableToolbar(VFX_FALSE);
            page->updateListMenuContent();
        }

        hideWaitIcon();
    }
}

VfxBool VappMusicPlayerApp::checkDuplicatedPlaylist(VfxBool isFristStart)
{
    VfxU32 count = m_provider->getCount();
    VfxWString name1;
    VfxWString name2;
    VfxWString newName;
    VfxU32 serial = 1;
    VfxWString serialText;
    VfxU8 counter = 0;

    static VfxU32 counterI;
    static VfxU32 counterJ;

    if (isFristStart)
    {
        counterI = 1;   // start from 1 to skip Favorite
        counterJ = counterI + 1;

        m_provider->getTitle(counterI, name1);
        m_dupListString = name1;
    }
    else
    {
        name1 = m_dupListString;
    }

    for ( ; counterI < count; )
    {
        
        for ( ; counterJ < count; counterJ++ )
        {
            counter ++ ;

            if(counter == 20)
            {
                m_checkDupliactedPlaylistTimer->start();
                return VFX_FALSE;
            }

            m_provider->getTitle(counterJ, name2);
            if (name1 == name2)
            {
                serial = 1;
                do
                {
                    VFX_ASSERT(serial <= 1000);

                    serialText.format("(%d)", serial++);
                    newName = name1;
                    newName += serialText;

                }while(m_provider->isPlaylistExist(newName));
                
                m_provider->renamePlaylist(newName, counterJ);
            }
        }
        counterI ++ ;
        counterJ = counterI + 1;

        m_provider->clearCurrCache();

        m_provider->getTitle(counterI, name1);
        m_dupListString = name1;

        m_provider->clearCurrCache();

    }

    m_checkDuplicatedPlaylistRunning = VFX_FALSE;
    m_needCheckDuplicatedPlaylist = VFX_FALSE;

    return VFX_TRUE;
}

void VappMusicPlayerApp::cancelCheckDuplicatedPlaylist()
{
    if (m_checkDuplicatedPlaylistRunning)
    {
        m_checkDupliactedPlaylistTimer->stop();
        m_checkDuplicatedPlaylistRunning = VFX_FALSE;
        m_dupListString.setEmpty();

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
        m_needCheckDuplicatedPlaylist = VFX_FALSE;
#else
        m_needCheckDuplicatedPlaylist = VFX_TRUE;
#endif

        VappMusicPlayerSubPage *page = getTabPage(FUNC_ID_TAB_PLAYLIST);
        if (page && page->m_contentProvider)
        {
            page->m_contentProvider->setCheckingDuplicatedPlaylist(VFX_FALSE);
        }

        hideWaitIcon();
    }
}

void VappMusicPlayerApp::pageMultiSelectOn(VappMusicPlayerSubPage *page, VfxWString str, VfxBool isAnim)
{
    if (page == NULL || isSelecting())
    {
        return;
    }

    m_provider->selectStart();

    VcpListMenu* listMenu = page->getListMenu();
    listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, isAnim);
    listMenu->m_signalItemSelectionStateChanged.connect(this, &VappMusicPlayerApp::onItemSelectionStateChanged);
    listMenu->m_signalItemTapped.disconnect(this, &VappMusicPlayerApp::onListMenuItemTapped);
    listMenu->m_signalItemLongTapped.disconnect(this, &VappMusicPlayerApp::onListMenuItemLongTapped);
    page->initConfirmToolbar3(str);
    page->disableSearchBar(VFX_TRUE);
    page->getListMenu()->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_TRUE);
    page->getToolBar()->setDisableItem(FUNC_ID_TB_BTN_OK, VFX_TRUE);
    // Most page do not need to update content when switch to multi-select mode
    if(page->getViewType() == VIEW_TYPE_PLAYLIST)
    {
        updateContent();
    }
}

void VappMusicPlayerApp::pageMultiSelectOff(VappMusicPlayerSubPage *page, VfxBool isAnim)
{
    if (page == NULL || !isSelecting())
    {
        return;
    }
    m_provider->selectEnd();

    if (page)
    {
        VcpListMenu* listMenu = page->getListMenu();
        listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, isAnim);
        listMenu->m_signalItemSelectionStateChanged.disconnect(this, &VappMusicPlayerApp::onItemSelectionStateChanged);
        listMenu->m_signalItemTapped.connect(this, &VappMusicPlayerApp::onListMenuItemTapped);
        listMenu->m_signalItemLongTapped.connect(this, &VappMusicPlayerApp::onListMenuItemLongTapped);
        page->restorePreToolBar();
        page->setListMenuControlMode(page->getViewType(), isAnim);
        page->disableSearchBar(VFX_FALSE);
    }
}

void VappMusicPlayerApp::popupConfirm(
                            VfxWString strHint, 
                            VfxWString strBtn, 
                            VcpPopupTypeEnum popupType, 
                            VcpConfirmPopupButtonSetEnum buttonSet, 
                            VcpPopupButtonTypeEnum buttonType)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_CONFIRM);

    VFX_OBJ_CREATE(m_popupConfirm, VcpConfirmPopup, m_rootScreen);
    m_popupConfirm->setInfoType(popupType);
    m_popupConfirm->setText(strHint);
    m_popupConfirm->setButtonSet(buttonSet);
    if (buttonSet == VCP_CONFIRM_BUTTON_SET_USER_DEFINE)
    {
        m_popupConfirm->setCustomButton(strBtn , VFX_WSTR_RES(STR_GLOBAL_CANCEL), buttonType, VCP_POPUP_BUTTON_TYPE_CANCEL);
    }
    m_popupConfirm->show(VFX_TRUE);
    m_popupConfirm->m_signalButtonClicked.connect(this, &VappMusicPlayerApp::eventHandler);
    m_popupConfirm->setAutoDestory(VFX_TRUE);
}

void VappMusicPlayerApp::popupConfirmClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_CONFIRM_CLOSE);

    if (m_popupConfirm)
    {
        if (isBackLightOn())
        {
            m_popupConfirm->exit(VFX_TRUE);
        }
        else
        {
            m_popupConfirm->exit(VFX_FALSE);
        }
        m_popupConfirm = NULL;
    }
}

void VappMusicPlayerApp::popupWaiting(VfxWString str, VfxBool withCancelBtn)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_WAITING);

    if (m_popupWaiting)
    {
        return;
    }

    VFX_OBJ_CREATE(m_popupWaiting, VcpIndicatorPopup, m_rootScreen);
    if (withCancelBtn)
    {
        m_popupWaiting->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        m_popupWaiting->m_signalCanceled.connect(this, &VappMusicPlayerApp::onWaitingCanceled);
    }   
    else
    {
        m_popupWaiting->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    }
    m_popupWaiting->setAutoDestory(VFX_TRUE);
    m_popupWaiting->setText(str);

    m_popupWaiting->show(VFX_TRUE);
}

void VappMusicPlayerApp::onWaitingCanceled(VfxObject* obj, VfxFloat curr_progress)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_WAITING_CANCELED);

    if (m_actionMode == ACTION_RESET)
    {
        if (isMakingCall())
        {
            // just skip here, AP will be closed in onGroupInactive()
            return;
        }
        
        SrvDBStateEnum DBState = m_mplayerSrv->getDBState();
        if (DBState == DB_OPENING)
        {
            m_mplayerSrv->openDBCancel();
        }

        // After reset, set the action to NONE and do not do the following refreshing in plsvcallback
        setActionMode(ACTION_NONE);

        updateContent();
    }
    else if (m_actionMode == ACTION_REFRESH)
    {
        vfxPostInvoke0(this, &VappMusicPlayerApp::onFuncRefreshDBCancel);
    }
    else if (m_actionMode == ACTION_ADD_TO_PLAYLIST || m_actionMode == ACTION_PLAYLIST_ADD_SONG)
    {
        m_provider->addToPlaylistCancel();
        
        if (m_actionMode == ACTION_ADD_TO_PLAYLIST && getViewType() == VIEW_TYPE_PLAYLIST_SELECT)
        {
            updateContent(m_selectItemIdx + 1, VFX_FALSE, VFX_FALSE, VFX_FALSE);
        }

        vfxPostInvoke0(this, &VappMusicPlayerApp::onFuncAddToPlaylistStop);
    }
    
    popupWaitingClose();
}

void VappMusicPlayerApp::popupWaitingClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_WAITING_CLOSE);

    if (m_popupWaiting)
    {
        if (isBackLightOn())
        {
            m_popupWaiting->exit(VFX_TRUE);
        }
        else
        {
            m_popupWaiting->exit(VFX_FALSE);
        }
        m_popupWaiting = NULL;
    }
}

void VappMusicPlayerApp::popupProgress(VfxWString str)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_PROGRESS);

    VFX_OBJ_CREATE(m_popupIndicator, VcpIndicatorPopup, m_rootScreen);
    m_popupIndicator->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_popupIndicator->setAutoDestory(VFX_TRUE);
    m_popupIndicator->m_signalCanceled.connect(this, &VappMusicPlayerApp::onProgressCanceled);
    m_popupIndicator->setText(str);
    m_popupIndicator->show(VFX_TRUE);
    m_popupIndicator->setProgress(0.0f);
}

void VappMusicPlayerApp::popupProgressClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_PROGRESS_CLOSE);

    if (m_popupIndicator)
    {
        if (isBackLightOn())
        {
            m_popupIndicator->exit(VFX_TRUE);
        }
        else
        {
            m_popupIndicator->exit(VFX_FALSE);
        }
        m_popupIndicator = NULL;
    }
}

void VappMusicPlayerApp::onProgressCanceled(VfxObject* obj, VfxFloat curr_progress)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_PROGRESS_CANCELED);

    if (m_popupIndicator)
    {
        m_popupIndicator = NULL;
    }

    if (curr_progress == 1.0)
    {
    
    }
    else
    {
        if (m_actionMode == ACTION_DELETE || m_actionMode == ACTION_PLAYLIST_REMOVE)
        {
            m_provider->delCancel();

            // Also cancel multi selection
            onKeyBack();

            updateContent();

            // Update view if nubmer or info changed by delete
            onFuncDeleteStopUpdateView();
        }
    }
}

void VappMusicPlayerApp::popupInput(VfxWString title, VfxWString hint, VfxWString defString, VfxS32 maxLen)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_INPUT);

    VFX_OBJ_CREATE(m_popupInput, VcpInputPopup, m_rootScreen);
    m_popupInput->setTitle(title);
    m_popupInput->setHintText(hint);
    m_popupInput->setAutoDestory(VFX_TRUE);
    //m_popupInput->setMaxLength(MUSICPLY_PLST_NAME_MAX_LENGTH);
    m_popupInput->m_signalButtonClicked.connect(this, &VappMusicPlayerApp::onInputPopupConfirm);

    VcpTextEditor *editor = m_popupInput->getInputbox();
    editor->setText(defString, maxLen);

    /* Set highlight for whole text */
    editor->setHighlight(0, m_popupInput->getText().getLength());

    editor->m_signalBeforeChange.connect(this, &VappMusicPlayerApp::popupInputTextBeforeChanged);

    m_popupInput->show(VFX_TRUE);

    m_oriPopupInputText = defString;
}

void VappMusicPlayerApp::popupInputTextBeforeChanged(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret)
{
    *ret = VFX_TRUE;

    switch (type)
    {
        case VCP_TEXT_CHANGE_INSERT_CHAR:
        case VCP_TEXT_CHANGE_INSERT_STR:
            if (m_actionMode == ACTION_PLAYLIST_NEW || m_actionMode == ACTION_PLAYLIST_RENAME)
            {
                const VfxU32 insTextLen = vfx_sys_wcslen(text);
                const VfxU32 curTextLen = m_popupInput->getText().getLength();
                if (insTextLen + curTextLen > MUSICPLY_PLST_NAME_MAX_LENGTH)
                {
                    m_popupInput->setErrorText(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_MAX_PLST_NAME));
                }
                else
                {
                    m_popupInput->setErrorText(VFX_WSTR(""));
                }
            }
            break;

        case VCP_TEXT_CHANGE_DELETE_CHAR:
        case VCP_TEXT_CHANGE_DELETE_ALL:
            if (m_actionMode == ACTION_PLAYLIST_NEW || m_actionMode == ACTION_PLAYLIST_RENAME)
            {
                m_popupInput->setErrorText(VFX_WSTR(""));
            }
            break;
    }
}

void VappMusicPlayerApp::onInputPopupConfirm(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_INPUT_POPUP_CONFIRM);

    switch (id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
            if (m_actionMode == ACTION_PLAYLIST_NEW ||
                m_actionMode == ACTION_PLAYLIST_RENAME)
            {
                VfxWString inputText;
                inputText = m_popupInput->getText();

                if (m_actionMode == ACTION_PLAYLIST_RENAME && inputText == m_oriPopupInputText)
                {
                    // do nothing if name was not changed
                    onInputPopupConfirm(NULL, VCP_INPUT_POPUP_BTN_CANCEL);
                    return;
                }

                VfxBool isValidName = VFX_TRUE;
                if (inputText == VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TITLE_FAVORITE))
                {
                    isValidName = VFX_FALSE;
                }
                else
                {
                    isValidName = !m_provider->isPlaylistExist(inputText);
                }
                
                if (!isValidName)
                {
                    // duplicated name
                    m_popupInput->setErrorText(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_PLST_NAME_EXIST));
                    return;
                }
                else
                {
                    // valid name
                    if (m_actionMode == ACTION_PLAYLIST_NEW)
                    {
                        m_provider->createPlaylist(inputText);
                        updateContent();
                    }
                    else if(m_actionMode == ACTION_PLAYLIST_RENAME)
                    {
                        if (getViewType() == VIEW_TYPE_PLAYLIST)
                        {
                            // Long press case
                            m_provider->renamePlaylist(inputText, m_longTapComm.index);

                            updateContent(m_longTapComm.index);
                        }
                        else if (getViewType() == VIEW_TYPE_PLAYLIST_SONG)
                        {
                            m_provider->renamePlaylist(inputText, m_selectItemIdx);

                            // update playlist name in titlebar
                            VappMusicPlayerSubPage *page = getCurrPage();
                            if (page)
                            {
                                page->getTitleBar()->setTitle(inputText);
                            }
                        }
                    }

                    if (getViewType() == VIEW_TYPE_PLAYLIST_SELECT)
                    {
                        // close new playlist input popup
                        setActionMode(ACTION_ADD_TO_PLAYLIST);

                        // directly add selected songs to new created playlist
                        VfxU32 listIndex = 1;
                        m_provider->getPlaylistIndexByName(inputText, &listIndex);
                        m_selectItemIdx = listIndex;
                        vfxPostInvoke0(this, &VappMusicPlayerApp::onFuncPlaylistAddSong);
                    }
                    else
                    {
                        // this case should be rename
                        setActionMode(ACTION_NONE);
                    }
                }
            }
            // do not break here, need to reset action mode

        case VCP_INPUT_POPUP_BTN_CANCEL:
            if (getViewType() == VIEW_TYPE_PLAYLIST_SELECT)
            {
                // close new playlist input popup
                setActionMode(ACTION_ADD_TO_PLAYLIST);
            }
            else
            {
                // this case should be rename
                setActionMode(ACTION_NONE);
            }
            break;
    }

    m_oriPopupInputText.setEmpty();

    if (m_popupInput)
    {
        // use VFX_OBJ_CLOSE instead of exit() to skip exiting animation
        //m_popupInput->exit(VFX_TRUE);
        VFX_OBJ_CLOSE(m_popupInput);
        m_popupInput = NULL;
    }
}

void VappMusicPlayerApp::popupMenu(VfxWString str, VappMusicPlayerMenuPopupItemStruct *itemList, VfxU32 itemCount)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_MENU);

    VFX_OBJ_CREATE(m_popupMenu, VcpMenuPopup, m_rootScreen);
    m_popupMenu->setTitle(str);
    m_popupMenu->setAutoDestory(VFX_TRUE);
    m_popupMenu->m_signalMenuCallback.connect(this, &VappMusicPlayerApp::onMenuItemTapped);

    for (VfxU32 i = 0; i < itemCount; i++)
    {
        m_popupMenu->addItem(itemList[i].id, itemList[i].str);
    }

    m_popupMenu->show(VFX_TRUE);
}

void VappMusicPlayerApp::popupMenuClose()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_POPUP_MENU_CLOSE);

    if (m_popupMenu)
    {
        if (isBackLightOn())
        {
            m_popupMenu->exit(VFX_TRUE);
        }
        else
        {
            m_popupMenu->exit(VFX_FALSE);
        }
        m_popupMenu = NULL;
    }
}

void VappMusicPlayerApp::showBalloon(mmi_nmgr_balloon_type_enum type, VfxWString str)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SHOW_BALLOON);

    if (str.isEmpty())
    {
        return;
    }

    // balloon will turn on back light, we should check if it's necessary to show
    if (isBackLightOn())
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            type,
            const_cast<WCHAR*>(str.getBuf()));
    }
}

void VappMusicPlayerApp::onShowHideWaitIcon(VfxBool isShow, VfxBool delayShow)
{
    if (isShow)
    {
        showWaitIcon(delayShow);
    }
    else
    {
        hideWaitIcon();
    }
}

void VappMusicPlayerApp::showWaitIcon(VfxBool delayShow)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SHOW_WAIT_ICON, delayShow);
    if (delayShow)
    {
        if (m_waitIconTimer == NULL)
        {
            VFX_OBJ_CREATE(m_waitIconTimer, VfxTimer, this);
            m_waitIconTimer->setStartDelay(300);
            m_waitIconTimer->m_signalTick.connect(this, &VappMusicPlayerApp::doShowWaitIcon);
        }

        m_waitIconTimer->stop();
        m_waitIconTimer->start();
    }
    else
    {
        doShowWaitIcon(NULL);
    }
}

void VappMusicPlayerApp::doShowWaitIcon(VfxTimer *timer)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SHOW_WAIT_ICON, 1);

    if (!m_waitIcon)
    {
        VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, m_rootScreen);
        m_waitIcon->setAnchor(0.5, 0.5);
        m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
        m_waitIcon->stop();
        m_waitIcon->setAutoAnimate(VFX_FALSE);
        updateWaitIconPos(VFX_FALSE, VFX_TRUE);
    }

    m_waitIcon->bringToFront();
    m_waitIcon->setHidden(VFX_FALSE);
    m_waitIcon->start();
}

void VappMusicPlayerApp::hideWaitIcon()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_HIDE_WAIT_ICON);
    if (m_waitIconTimer)
    {
        m_waitIconTimer->stop();
    }

    if (m_waitIcon)
    {
        if (m_waitIcon->isAnimating())
        {
            m_waitIcon->stop();
        
            m_waitIcon->setHidden(VFX_TRUE);
            m_waitIcon->sendToBack();
        }
    }

}

VfxBool VappMusicPlayerApp::hasPopup()
{
    return m_popupWaiting 
        || m_popupIndicator
        || m_popupInput
        || m_popupConfirm
        || m_popupMenu;
}

VfxBool VappMusicPlayerApp::closeAllPopup(VfxBool doClose)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_CLOSE_ALL_POPUP_D, doClose);

    VfxBool closePopup = VFX_FALSE;

    // Cancel all popup before going to background
    if (m_popupWaiting)
    {
        if (!doClose)
        {
            m_popupWaiting = NULL;
        }
        onWaitingCanceled(NULL, 0);

        closePopup = VFX_TRUE;
    }

    if (m_popupIndicator)
    {
        if (!doClose)
        {
            m_popupIndicator = NULL;
        }
        popupProgressClose();
        onProgressCanceled(NULL, 0);
        
        closePopup = VFX_TRUE;
    }

    if (m_popupInput)
    {
        if (!doClose)
        {
            m_popupInput = NULL;
        }
        onInputPopupConfirm(NULL, VCP_INPUT_POPUP_BTN_CANCEL);

        closePopup = VFX_TRUE;
    }

    if (m_popupConfirm)
    {
        if (!doClose)
        {
            m_popupConfirm = NULL;
        }
        popupConfirmClose();
        eventHandler(NULL, VCP_CONFIRM_POPUP_BUTTON_CANCEL);
        eventHandler(NULL, VCP_CONFIRM_POPUP_BUTTON_USER_2);

        closePopup = VFX_TRUE;
    }

    if (m_popupMenu)
    {
        popupMenuClose();

        closePopup = VFX_TRUE;
    }

    return closePopup;
}

VfxU32 VappMusicPlayerApp::getReorderStartIndex()
{
    return m_reorderStartIdx;
}

void VappMusicPlayerApp::setReorderStartIndex(const VfxU32 idx)
{
    m_reorderStartIdx = idx;
}

void VappMusicPlayerApp::onPLSVReturn(VfxS32 ret)
{
    switch (srv_plst_caller_handler_enum(ret))
    {
        case SRV_PLST_VERSION_WRONG:
        case SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH:
        case SRV_PLST_RET_ERR_DISK_NOT_ENOUGH:
        case SRV_PLST_RET_ERR_SERVICE_MAX_SUPPORT:
        case SRV_PLST_RET_ERR_MEMORY_CONRRUPT:
        case SRV_PLST_RET_ERR_DB_CONRRUPT:
        case SRV_PLST_RET_ERR_DESTROY_FAIL:
        case SRV_PLST_RET_ERR_SQLITE_ERR:
        case SRV_PLST_RET_ERR_PARAM_ERR:
        case SRV_PLST_RET_ERR_UNKOWN_ERR:
        case SRV_PLST_RET_ERR_FS_ERROR:
        case SRV_PLST_RET_ERR_FATAL_ERROR:
        case SRV_PLST_RET_ITEM_EXIST:
        case SRV_PLST_RET_EMPTY:
        case SRV_PLST_RET_ERR_META_PAESER:
        case SRV_PLST_RET_ERR_GDI_ERR:
        case SRV_PLST_RET_ERR_DB_NOT_FOUND:
        case SRV_PLST_RET_ERR_DB_CRASH:
        case SRV_PLST_RET_DELETE_ACTIVE:
        case SRV_PLST_RET_DB_FULL:
        case SRV_PLST_RET_PLST_FULL:
        case SRV_PLST_RET_ERR_IMG_FORMAT_ERROR:    
            m_plsvReturnValue = ret;
            break;

        default:
            m_plsvReturnValue = SRV_PLST_OK;
            break;
    }
}

VfxBool VappMusicPlayerApp::checkPLSVAction(VfxBool showPopup, VfxBool resetValue)
{
    VfxBool isOK = VFX_TRUE;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_CHECK_PLSVACTION, m_plsvReturnValue);

    if (m_plsvReturnValue !=  SRV_PLST_OK && m_plsvReturnValue !=  SRV_PLST_RET_EMPTY)
    {
        if (showPopup)
        {
            VfxResId strID = m_provider->getErrorStrId(m_plsvReturnValue);
            popupConfirm(
                VFX_WSTR_RES(strID),
                VFX_WSTR_RES(STR_GLOBAL_OK),
                VCP_POPUP_TYPE_FAILURE,
                VCP_CONFIRM_BUTTON_SET_OK,
                VCP_POPUP_BUTTON_TYPE_WARNING
                );

            // pause playback to avoid some other playback issue
            PlaybackStateEnum state = m_ctrlPlayback->getPlayState();
            if (state == PB_STATE_PLAY 
             || state == PB_STATE_BT_CONNECTING_WHILE_PLAYING
             || state == PB_STATE_BT_CONNECTING_WHILE_RESUME)
            {
                if (m_coverFlow)
                {
                    m_coverFlow->pause();
                }
                else if (m_nowPlaying)
                {
                    m_nowPlaying->pause();
                }
                else
                {
                    m_ctrlPlayback->pause();
                }
            }
            else if (state == PB_STATE_INTERRUPTED)
            {
                m_ctrlPlayback->clearInterruptState();
            }
        }

        isOK = VFX_FALSE;
        setActionMode(ACTION_FATAL_ERROR);
    }
    
    if (resetValue)
    {
        m_plsvReturnValue = SRV_PLST_OK;
    }
    
    return isOK;
}

void VappMusicPlayerApp::setSubPageEntering(VfxBool entering)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_SET_SUB_PAGE_ENTERING, entering);

    m_isEntering = entering;
}

/***************************************************************************** 
 * VappMusicPlayerScreen Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerScreen", VappMusicPlayerScreen, VfxMainScr);

void VappMusicPlayerScreen::onInit()
{
    VfxMainScr::onInit();

    for (VfxU32 i = 0; i < MUSICPLY_MAX_VIEW_STACK_DEPTH; i++)
    {
        m_viewStack[i] = VIEW_TYPE_NONE;
    }
}

void VappMusicPlayerScreen::onDeinit()
{
    VfxMainScr::onDeinit();
}

void VappMusicPlayerScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->checkLaunchToNowPlaying();
    }
}

void VappMusicPlayerScreen::onEnter(VfxBool isBackward)
{
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    if (app)
    {
        app->updateWaitIconPos();
    }
}

void VappMusicPlayerScreen::onExited(VfxBool isBackward)
{
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);

    if (app && app->getActionMode() == ACTION_PLAYLIST_SONG_ARRANGE)
    {
        // cancel playlist song rearranging by incoming call or other interruption
        app->onKeyBack();
    }

    VfxMainScr::onExited(isBackward);
}

VfxU32 VappMusicPlayerScreen::getViewStackCount()
{
    return m_viewStackCount;
}

ViewTypeEnum VappMusicPlayerScreen::getViewStack(VfxU32 idx)
{
    if (m_viewStackCount == 0)
    {
        return VIEW_TYPE_NONE;
    }
    else if (idx == 9999)
    {
        return m_viewStack[m_viewStackCount-1];
    }
    else if(idx <= m_viewStackCount-1)
    {
        return m_viewStack[idx];
    }
    else
    {
        return VIEW_TYPE_NONE;
    }   
}

VfxBool VappMusicPlayerScreen::isViewInStack(ViewTypeEnum viewType)
{
    VfxU32 i;
    for(i = 0; i < m_viewStackCount; i++)
    {
        if(m_viewStack[i] == viewType)
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

VfxU32 VappMusicPlayerScreen::pushViewStack(ViewTypeEnum viewType)
{
    VFX_ASSERT(m_viewStackCount < MUSICPLY_MAX_VIEW_STACK_DEPTH);

    m_viewStack[++m_viewStackCount - 1] = viewType;
    return m_viewStackCount;
}

ViewTypeEnum VappMusicPlayerScreen::popViewStack()
{
    ViewTypeEnum ret = VIEW_TYPE_NONE;
    if (m_viewStackCount > 0)
    {
        ret = m_viewStack[m_viewStackCount-1];
        m_viewStack[m_viewStackCount-1] = VIEW_TYPE_NONE;
        m_viewStackCount--;
    }

    return ret;
}

void VappMusicPlayerScreen::clearViewStack()
{
    for (VfxU32 idx = 0; idx < MUSICPLY_MAX_VIEW_STACK_DEPTH; ++idx)
    {
        m_viewStack[idx] = VIEW_TYPE_NONE;
    }

    m_viewStackCount = 0;
}

VfxBool VappMusicPlayerScreen::goToNextPage(ViewTypeEnum viewType, VfxWString titleStr, VfxU32 index)
{
    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);

    VappMusicPlayerSubPage *page = NULL;
    VFX_OBJ_CREATE_EX(page, VappMusicPlayerSubPage, this, (VFX_TRUE));
    page->setTitleBarText(titleStr);
    page->setRect(getRect());
    page->setPageViewType(viewType);
    
    VcpListMenuCellStyleEnum style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;

    switch (viewType)
    {
    case VIEW_TYPE_ARTIST_ALBUM:
        {
            VappMusicPlayerToolbarItemStruct items[3];
            items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
            items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
            items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            items[1].id = FUNC_ID_TB_BTN_ADD_TO_PLAYLIST;
            items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO);
            items[1].iconResID = IMG_ID_VAPP_MUSICPLY_TB_NEW_PLAYLIST;
            items[2].id = FUNC_ID_TB_BTN_DELETE;
            items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            items[2].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
            page->setToolbar(items, 3);
            break;
        }
    case VIEW_TYPE_ARTIST_SONG:
    case VIEW_TYPE_ARTIST_ALBUM_SONG:
    case VIEW_TYPE_ALBUM_SONG:
        {
            VappMusicPlayerToolbarItemStruct items[4];
            items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
            items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
            items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            items[1].id = FUNC_ID_TB_BTN_ADD_TO_PLAYLIST;
            items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO);
            items[1].iconResID = IMG_ID_VAPP_MUSICPLY_TB_NEW_PLAYLIST;
            items[2].id = FUNC_ID_TB_BTN_PLAY;
            items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
            items[2].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAY_ALL;
            items[3].id = FUNC_ID_TB_BTN_DELETE;
            items[3].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            items[3].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
            page->setToolbar(items, 4);
            break;
        }

    case VIEW_TYPE_PLAYLIST_SONG:
        {
            if (app->getSelectItemIdx() == 0)
            {
                // Favorite can't be renamed
                VappMusicPlayerToolbarItemStruct items[5];
                items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
                items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
                items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
                items[1].id = FUNC_ID_TB_BTN_PLAYLIST_ADD_SONG;
                items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_SONG);
                items[1].iconResID = IMG_ID_VAPP_MUSICPLY_TB_ADD;
                items[2].id = FUNC_ID_TB_BTN_PLAY;
                items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
                items[2].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAY_ALL;
                items[3].id = FUNC_ID_TB_BTN_PLAYLIST_REMOVE;
                items[3].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
                items[3].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
                items[4].id = FUNC_ID_TB_BTN_PLAYLIST_ARRANGE;
                items[4].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_SORT);
                items[4].iconResID = IMG_ID_VAPP_MUSICPLY_TB_REARRANGE;
                page->setToolbar(items, 5);
            }
            else
            {
                VappMusicPlayerToolbarItemStruct items[6];
                items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
                items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
                items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
                items[1].id = FUNC_ID_TB_BTN_PLAYLIST_ADD_SONG;
                items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_SONG);
                items[1].iconResID = IMG_ID_VAPP_MUSICPLY_TB_ADD;
                items[2].id = FUNC_ID_TB_BTN_PLAY;
                items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
                items[2].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAY_ALL;
                items[3].id = FUNC_ID_TB_BTN_PLAYLIST_RENAME;
                items[3].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_RENAME);
                items[3].iconResID = IMG_ID_VAPP_MUSICPLY_TB_RENAME;
                items[4].id = FUNC_ID_TB_BTN_PLAYLIST_REMOVE;
                items[4].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE);
                items[4].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
                items[5].id = FUNC_ID_TB_BTN_PLAYLIST_ARRANGE;
                items[5].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_SORT);
                items[5].iconResID = IMG_ID_VAPP_MUSICPLY_TB_REARRANGE;
                page->setToolbar(items, 6);
            }
            break;
        }
        
    case VIEW_TYPE_PLAYLIST_SELECT:
        style = VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT;
        break;

    case VIEW_TYPE_VIEW_SELECT:
        style = VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT;

    default:
        break;

    };

    page->initListMenu(style);

    pushPage(viewType, page);
    app->setViewType(viewType, CHANGE_VIEW_MODE_ENTER, index);
    if (app->checkPLSVAction() == VFX_FALSE) return VFX_FALSE;

    if (viewType == VIEW_TYPE_PLAYLIST_ADD_ALL_SONG
     || viewType == VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG
     || viewType == VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG)
    {
        app->pageMultiSelectOn(page, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TITLE_ADD_TO_PLST));
    }

    return VFX_TRUE;
}

VfxBool VappMusicPlayerScreen::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
            case VFX_KEY_CODE_BACK:
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_PLAYER_SCREEN_ON_KEY_INPUT_BACK);

                    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
                    if (app->getIsDying())
                    {
                        return VFX_TRUE;
                    }

                    VfxPage *page = getPage(getTopPageId());
                    if (VFX_OBJ_DYNAMIC_CAST(page, VappMusicPlayerSettingRadioPage))
                    {
                        // Skip following process if currunt page is sound effect page
                        return VFX_TRUE;
                    }
                    else
                    {
                        if (app->getNowPlaying() && app->getNowPlaying()->m_isLaunchToNowPlaying && getViewStack() == VIEW_TYPE_NOW_PLAYING)
                        {
                            // if is launched by widget or NCenter, close APP and go back to home screen on pressing Back key
                            app->exit();
                        }
                        else
                        {
                            app->onKeyBack();
                        }
                    }
                }
                return VFX_TRUE;

#if 1//defined(__COSMOS_MUSICPLY_COVER_FLOW_TOOLBAR__)
            case VFX_KEY_CODE_POUND:
                {
                    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
                    if (app)
                    {
                        app->onScreenRotate(VFX_SCR_ROTATE_TYPE_270);
                    }
                }
                return VFX_TRUE;

            case VFX_KEY_CODE_STAR:
                {
                    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
                    if (app)
                    {
                        app->onScreenRotate(VFX_SCR_ROTATE_TYPE_0);
                    }
                }
                return VFX_TRUE;
#endif

// for debugging
#if defined(__COSMOS_MUSICPLY_DEBUG__)
            case VFX_KEY_CODE_CAMERA:
                vapp_screen_lock_launch();
                return VFX_TRUE;
#endif
        };
    }
    
    return VfxAppScr::onKeyInput(event);
}

void VappMusicPlayerScreen::onRotate(const VfxScreenRotateParam &param)
{
#ifdef __COSMOS_3D_V10__
    // Disable page rotation animation
    VfxRect parentBounds = getParentFrame()->getBounds();

    setAnchor(0.5f, 0.5f);
    setPos(parentBounds.size.width / 2, parentBounds.size.height / 2);
    setSize(parentBounds.size);

#else
    VfxMainScr::onRotate(param);

#endif
}


/***************************************************************************** 
 * VappMusicPlayerTabPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerTabPage", VappMusicPlayerTabPage, VcpTabCtrlPage);

void VappMusicPlayerTabPage::onInit()
{
    VcpTabCtrlPage::onInit();

    SWLA_BEGIN("MT1");
    addTab(FUNC_ID_TAB_ALL_SONG, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_SONG), VcpStateImage(IMG_ID_VAPP_MUSICPLY_TAB_SONG));
    addTab(FUNC_ID_TAB_ARTIST, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_ARTIST), VcpStateImage(IMG_ID_VAPP_MUSICPLY_TAB_ARTIST));
    addTab(FUNC_ID_TAB_ALBUM, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_ALBUM),  VcpStateImage(IMG_ID_VAPP_MUSICPLY_TAB_ALBUM));
    addTab(FUNC_ID_TAB_PLAYLIST, VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TAB_PLAYLIST),  VcpStateImage(IMG_ID_VAPP_MUSICPLY_TAB_PLAYLIST));
    setCurrTab(FUNC_ID_TAB_ALL_SONG);
    SWLA_END("MT1");
}

VfxPage *VappMusicPlayerTabPage::onCreateTabPage(VfxId tabId)
{ 
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_CREATE_TAB_PAGE, tabId);
    
    SWLA_BEGIN("MT2");

    VappMusicPlayerSubPage *page;
    VFX_OBJ_CREATE(page, VappMusicPlayerSubPage, this);
    ViewTypeEnum viewType = VIEW_TYPE_ALL_SONGS;

    setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT);
    //setBgColor(VRT_COLOR_WHITE);
    VcpListMenuCellStyleEnum style = VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT;
    
    switch(tabId)
    {
    case FUNC_ID_TAB_ALL_SONG:
        {
            VappMusicPlayerToolbarItemStruct items[6];

#ifdef __COSMOS_3D_V10__            
            items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
            items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
            items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            items[1].id = FUNC_ID_TB_BTN_ADD_TO_PLAYLIST;
            items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO);
            items[1].iconResID = IMG_ID_VAPP_MUSICPLY_TB_NEW_PLAYLIST;
            items[2].id = FUNC_ID_TB_BTN_PLAY;
            items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
            items[2].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAY_ALL;
            items[3].id = FUNC_ID_TB_BTN_DELETE;
            items[3].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            items[3].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
            items[4].id = FUNC_ID_TB_BTN_REFRESH;
            items[4].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REFRESH);
            items[4].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH;
    #if defined(__COSMOS_MUSICPLY_COVER_FLOW_TOOLBAR__) || defined(__COSMOS_MUSICPLY_DEBUG__)
            items[5].id = FUNC_ID_TB_BTN_COVER_FLOW;
            items[5].str.format("Cover Flow");
            items[5].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            page->setToolbar(items, 6);
    #else
            page->setToolbar(items, 5);
    #endif
#else
            items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
            items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
            items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            items[1].id = FUNC_ID_TB_BTN_ADD_TO_PLAYLIST;
            items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO);
            items[1].iconResID = IMG_ID_VAPP_MUSICPLY_TB_NEW_PLAYLIST;
            items[2].id = FUNC_ID_TB_BTN_PLAY;
            items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL);
            items[2].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAY_ALL;
            items[3].id = FUNC_ID_TB_BTN_DELETE;
            items[3].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            items[3].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
            items[4].id = FUNC_ID_TB_BTN_REFRESH;
            items[4].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REFRESH);
            items[4].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH;
    #if defined(__COSMOS_MUSICPLY_DEBUG__)
            items[5].id = FUNC_ID_TB_BTN_COVER_FLOW;
            items[5].str.format("Cover Flow");
            items[5].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            page->setToolbar(items, 6);
    #else
            page->setToolbar(items, 5);
    #endif
#endif
            viewType = VIEW_TYPE_ALL_SONGS;
            style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
            break;
        }

    case FUNC_ID_TAB_ARTIST:
        {
            VappMusicPlayerToolbarItemStruct items[4];
            items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
            items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
            items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            items[1].id = FUNC_ID_TB_BTN_ADD_TO_PLAYLIST;
            items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO);
            items[1].iconResID = IMG_ID_VAPP_MUSICPLY_TB_NEW_PLAYLIST;
            items[2].id = FUNC_ID_TB_BTN_DELETE;
            items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            items[2].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
            items[3].id = FUNC_ID_TB_BTN_REFRESH;
            items[3].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REFRESH);
            items[3].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH;
            page->setToolbar(items, 4);
            viewType = VIEW_TYPE_ARTIST;
            style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
            break;
        }

    case FUNC_ID_TAB_ALBUM:
        {
            VappMusicPlayerToolbarItemStruct items[4];
            items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
            items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
            items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            items[1].id = FUNC_ID_TB_BTN_ADD_TO_PLAYLIST;
            items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO);
            items[1].iconResID = IMG_ID_VAPP_MUSICPLY_TB_NEW_PLAYLIST;
            items[2].id = FUNC_ID_TB_BTN_DELETE;
            items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            items[2].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
            items[3].id = FUNC_ID_TB_BTN_REFRESH;
            items[3].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REFRESH);
            items[3].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH;
            page->setToolbar(items, 4);
            viewType = VIEW_TYPE_ALBUM;
            style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
            break;
        }

    case FUNC_ID_TAB_PLAYLIST:
        {
            VappMusicPlayerToolbarItemStruct items[4];
            items[0].id = FUNC_ID_TB_BTN_NOW_PLAYING;
            items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING);
            items[0].iconResID = IMG_ID_VAPP_MUSICPLY_TB_PLAYER;
            items[1].id = FUNC_ID_TB_BTN_NEW_PLAYLIST;
            items[1].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_ADD);
            items[1].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD;
            items[2].id = FUNC_ID_TB_BTN_DELETE;
            items[2].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE);
            items[2].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE;
            items[3].id = FUNC_ID_TB_BTN_REFRESH;
            items[3].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_REFRESH);
            items[3].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH;
            page->setToolbar(items, 4);
            viewType = VIEW_TYPE_PLAYLIST;
            break;
        }
    }

    page->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    page->setPageViewType(viewType);

    SWLA_END("MT2");
    SWLA_BEGIN("MT3");

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    VFX_ASSERT(app);
    if (app->getActionMode() != ACTION_LAUNCHING && app->getActionMode() != ACTION_LAUNCHING_FROM_BG)
    {
        page->initListMenu(style, tabId != FUNC_ID_TAB_PLAYLIST);
        page->updateAll();
    }

    SWLA_END("MT3");

    return page;     
}

void VappMusicPlayerTabPage::onTabSwitching(VfxId tabId)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_TAB_SWITCHING, m_preTabId, tabId);

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    VFX_ASSERT(app);

    VappMusicPlayerSubPage *subPage = VFX_OBJ_DYNAMIC_CAST(getTabPage(m_preTabId), VappMusicPlayerSubPage);
    if (subPage && app->isSelecting())
    {
        app->pageMultiSelectOff(subPage);
        app->setActionMode(ACTION_NONE);
    }

    if (tabId == m_closingTabId)
    {
        if (m_closeTabTimer)
        {
            m_closeTabTimer->stop();
            VFX_OBJ_CLOSE(m_closeTabTimer);
            m_closeTabTimer = NULL;
        }

        VappMusicPlayerSubPage *currPage = VFX_OBJ_DYNAMIC_CAST(getTabPage(tabId), VappMusicPlayerSubPage);
        if (currPage && !currPage->isBarOn(VFX_PAGE_BAR_LOCATION_BOTTOM))
        {
            currPage->toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
        }

        app->searchCancel();
    }

    //stop checking duplicated playlist
    if(m_preTabId == FUNC_ID_TAB_PLAYLIST)
    {
        app->cancelCheckDuplicatedPlaylist();
    }

    m_closingTabId = m_preTabId;

    m_preTabId = tabId;

    setIsUnhittable(VFX_TRUE);
}

void VappMusicPlayerTabPage::onTabSwitched(VfxId tabId)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_ON_TAB_SWITCHED, tabId);

    VFX_OBJ_CREATE(m_closeTabTimer, VfxTimer, this);
    m_closeTabTimer->m_signalTick.connect(this, &VappMusicPlayerTabPage::doTabPageClose);
    m_closeTabTimer->setStartDelay(100);
    m_closeTabTimer->start();

    setIsUnhittable(VFX_FALSE);

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    if (!getMusicPlayerSrv()->getMemoryCardReady())
    {
        return;
    }
#endif

    VappMusicPlayerSubPage *page = VFX_OBJ_DYNAMIC_CAST(getTabPage(tabId), VappMusicPlayerSubPage);
    VcpToolBar *bar = page->getToolBar();
    if (bar)
    {
        bar->setIsUnhittable(VFX_FALSE);
    }
    VappMusicPlayerListMenu *listMenu = page->getListMenu();
    if (listMenu)
    {
        listMenu->setIsUnhittable(VFX_FALSE);
    }
}

void VappMusicPlayerTabPage::doTabPageClose(VfxTimer *t)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_VAPP_DO_TAB_PAGE_CLOSE, m_closingTabId);

    VappMusicPlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    VFX_ASSERT(app);

    VappMusicPlayerSubPage *subPage = VFX_OBJ_DYNAMIC_CAST(getTabPage(m_closingTabId), VappMusicPlayerSubPage);
    if (subPage)
    {
        VFX_OBJ_CLOSE(subPage);
    }

    VFX_OBJ_CLOSE(m_closeTabTimer);
    m_closeTabTimer = NULL;
}

VfxBool VappMusicPlayerTabPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        VappMusicPlayerApp *app = getMusicPlayerApp();

        if (app->m_passBackKey)
        {
            back();
        }

        // Return False here, 'cause we want the key event pass to screen level to process view control
        return VFX_FALSE;
    }

    return VfxPage::onKeyInput(event);
}

void VappMusicPlayerTabPage::disableAllTab(VfxBool isDisable)
{
    setTabEnabled(FUNC_ID_TAB_ALL_SONG, !isDisable);
    setTabEnabled(FUNC_ID_TAB_ARTIST, !isDisable);
    setTabEnabled(FUNC_ID_TAB_ALBUM, !isDisable);
    setTabEnabled(FUNC_ID_TAB_PLAYLIST, !isDisable);    

    setIsDisabled(isDisable);
}

/***************************************************************************** 
 * VappMusicPlayerSubPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSubPage", VappMusicPlayerSubPage, VfxPage);


void VappMusicPlayerSubPage::onInit()
{
    SWLA_BEGIN("MP0");

    VfxPage::onInit();
    //setBgColor(VRT_COLOR_WHITE);

    m_app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappMusicPlayerApp);
    VFX_ASSERT(m_app);

    if (m_hasTitleBar)
    {
        VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
        m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
        setTopBar(m_titleBar);
    }

    SWLA_END("MP0");
}

void VappMusicPlayerSubPage::onDeinit()
{
    if (m_listMenu)
    {
        m_listMenu->m_signalStartFreerun.disconnect(this, &VappMusicPlayerSubPage::onMenuStartFreerun);
        m_listMenu->m_signalViewScrollEnd.disconnect(this, &VappMusicPlayerSubPage::onMenuScrollStopped);

        // Close list menu first to make sure it close before content provider
        VFX_OBJ_CLOSE(m_listMenu);
    }

    //stop checking duplicated playlist
    if(m_viewType == VIEW_TYPE_PLAYLIST || m_viewType == VIEW_TYPE_PLAYLIST_SELECT)
    {
        if(m_app->m_checkDupliactedPlaylistTimer != NULL)
        {
            m_app->m_checkDupliactedPlaylistTimer->stop();
            VFX_OBJ_CLOSE(m_app->m_checkDupliactedPlaylistTimer);
            m_app->m_checkDupliactedPlaylistTimer = NULL;
            m_app->m_checkDuplicatedPlaylistRunning = VFX_FALSE;
        }
    }

    VfxPage::onDeinit();
}

void VappMusicPlayerSubPage::onRotate(const VfxScreenRotateParam &param)
{

}

void VappMusicPlayerSubPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SUBPAGE_ON_ENTER, isBackward, m_viewType);

    SWLA_BEGIN("MP1");

    if (m_app->m_actionMode == ACTION_FATAL_ERROR)
    {
        return;
    }

    m_isBackward = isBackward;

    if (m_listMenu)
    {
        setListMenuControlMode(m_viewType, VFX_FALSE);

        m_app->getProvider()->setListMenu(m_listMenu);
        m_contentProvider->setListMenu(m_listMenu);

        // Unfreeze list menu at this moment
        m_listMenu->setIsFreezed(VFX_FALSE);

        // Connect search editor signal
        if (getSearchEditor())
        {
            m_app->m_searchText.setEmpty();
            m_app->m_preSearchText.setEmpty();
            getSearchEditor()->m_signalTextChanged.connect(m_app, &VappMusicPlayerApp::onSearchTextChange);
            // Clear search editor when first enter
            if(!isBackward)
            {
                clearSearchEditor();
                resetFocusChild();
            }

            if (m_app->m_resetListOnBack)
            {
                m_app->m_resetListOnBack = VFX_FALSE;
                m_listMenu->resetPosition();
                resetAll();
            }
        }
    }

    m_app->updateWaitIconPos(VFX_FALSE, VFX_TRUE);

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    if (!getMusicPlayerSrv()->getMemoryCardReady())
    {
        // Disable all toolbar icon
        disableToolbar(VFX_TRUE);
        if (m_listMenu)
        {
            m_listMenu->setIsUnhittable(VFX_TRUE);
        }
        disableSearchBar(VFX_TRUE);

        SWLA_END("MP1");
        return;
    }
#endif

    // If the view is all songs, album, artist, play list, show loading and update list content in onEntered() (since get count is slow)
    // Only apply on first enter, if set count to 0 when back, it will not keep list position
    if(!isBackward &&
       (m_viewType == VIEW_TYPE_ALL_SONGS || m_viewType == VIEW_TYPE_ARTIST || m_viewType == VIEW_TYPE_ALBUM || m_viewType == VIEW_TYPE_PLAYLIST))
    {
        m_app->showWaitIcon();
        m_app->setSubPageEntering(VFX_TRUE);
        
        if (m_app->m_actionMode != ACTION_LAUNCHING && m_app->getActionMode() != ACTION_LAUNCHING_FROM_BG)
        {
            // Inform content provider of this page that the screen is in entering transition and return list count as 0
            m_contentProvider->setEntering(VFX_TRUE);
            // Clear content to empty
            m_listMenu->resetAllItems();
        }

        // Disable all toolbar icon
        disableToolbar(VFX_TRUE);
    }
    else if (isBackward 
          && (m_viewType == VIEW_TYPE_PLAYLIST || m_viewType == VIEW_TYPE_PLAYLIST_SELECT)
          && (m_app->m_needCheckDuplicatedPlaylist))
    {
        m_app->showWaitIcon();
        m_app->setSubPageEntering(VFX_TRUE);
        if (!m_app->m_checkDuplicatedPlaylistRunning)
        {
            m_app->startCheckDuplicatedPlaylist();
        }
    }
    else
    {
        // For other case enter view directly
        updateListMenuContent();
    }

    SWLA_END("MP1");
}

void VappMusicPlayerSubPage::updateListMenuContent(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SUBPAGE_UPDATELISTMENUCONTENT, m_viewType);

    SWLA_BEGIN("MP2");

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    if (!getMusicPlayerSrv()->getMemoryCardReady())
    {
        SWLA_END("MP2");
        return;
    }
#endif

    // setViewType will return directly if this enter is not a page switch
    VfxBool ret = m_app->setViewType(m_viewType, CHANGE_VIEW_MODE_SWITCH);
    if (!ret)
    {
        // Disable go to now playing page if set view type fail
        VcpToolBar *bar = getToolBar();
        if (bar)
        {
            bar->setDisableItem(FUNC_ID_TB_BTN_NOW_PLAYING, !m_app->getProvider()->getIsReady());
            bar->setDisableItem(FUNC_ID_TB_BTN_REFRESH, !m_app->getProvider()->getIsReady());                
        }

        SWLA_END("MP2");
        return;
    }
    
    if (m_listMenu && (m_app->getActionMode() != ACTION_REFRESH))
    {
        ChangeViewMode mode = m_app->getProvider()->getChangeViewMode();
        if (mode == CHANGE_VIEW_MODE_BACK)
        {
            m_listMenu->restorePosition();
            if (isUsingMediaCache())
            {
                // Use reset to avoid update old count when go back
                m_listMenu->resetAllItems(VFX_TRUE);
            }
            else
            {
                m_app->updateContent();
            }
        }
        // For All songs, album, artist, do not update count to save time, it will update in setViewType
        else if((m_viewType == VIEW_TYPE_ALL_SONGS || m_viewType == VIEW_TYPE_ARTIST || m_viewType == VIEW_TYPE_ALBUM))
        {
            m_app->updateContent(-1, VFX_FALSE, VFX_TRUE);
        }
        // Other scenario not complete review yet, so still get count here
        else
        {
            m_app->updateContent();
        }
    }

    // Disable some toolbar buttons if there's no content
    m_app->updateToolbarItemState();

    SWLA_END("MP2");
}

void VappMusicPlayerSubPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SUBPAGE_ON_ENTERED, m_viewType);

    SWLA_BEGIN("MP3");

    if (!m_onEnteredTimer)
    {
        VFX_OBJ_CREATE(m_onEnteredTimer, VfxTimer, this);
        m_onEnteredTimer->setStartDelay(10);
        m_onEnteredTimer->m_signalTick.connect(this, &VappMusicPlayerSubPage::onEnteredPostProc);
    }
    m_onEnteredTimer->start();

    VfxWeakPtr<VappMusicPlayerSubPage> page = this;
    if(m_app->isGroupActive())
    {
        m_app->resetPenInput();
    }
    if(!page.isValid())
    {
        // resetPenInput may lead to unknown page routing, add a weak pointer checking for safety
        return;
    }
    m_app->resetKeyInput();
    if(!page.isValid())
    {
        return;
    }

    SWLA_END("MP3");
}

void VappMusicPlayerSubPage::onEnteredPostProc(VfxTimer *t)
{
    SWLA_BEGIN("MP4");

    VappMusicPlayerService *srv = getMusicPlayerSrv();
    SrvDBStateEnum DBState = srv->getDBState();
    VfxBool isReady = m_app->getProvider()->getIsReady();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SUBPAGE_ON_ENTERED_POST_PROC, m_viewType, DBState, m_app->m_actionMode);

    // For lauch music player case, delay play list init timing and reduce launch app time
    VfxBool isFirstLaunch = (m_viewType == VIEW_TYPE_ALL_SONGS) 
                         && (m_app->m_actionMode == ACTION_LAUNCHING || m_app->m_actionMode == ACTION_LAUNCHING_FROM_BG)
                         && (!m_isBackward || !isReady);

    if (isFirstLaunch)
    {
        if (DBState == DB_OPENING || DBState == DB_SHRINK)
        {
#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
            m_app->init2ndStage(srv->getMemoryCardReady());
#else
            m_app->init2ndStage();
#endif
        }
    }
    else if(!m_isBackward)
    {
        // For 4 tab page views, update content when screen switch effect done
        if (m_app->isTabPage())
        {
            updateListMenuContent();
        }
    }
    else if (m_isBackward && m_viewType == VIEW_TYPE_ALL_SONGS)
    {
        // this case is go to root
        updateListMenuContent();
    }

#ifdef __COSMOS_MUSICPLY_CARD_ONLY__
    if (!srv->getMemoryCardReady())
    {
        SWLA_END("MP4");
        return;
    }
#endif

    if(!m_app->m_checkDuplicatedPlaylistRunning)
    {
        PlaybackStateEnum pbState = m_app->getCtrlPlayback()->getPlayState();
        ActionEnum action = m_app->getActionMode();

        if (pbState != PB_STATE_SEEKING 
        && !(PB_STATE_BT_CONNECTING <= pbState && pbState <= PB_STATE_BT_CONNECTING_WHILE_INTERRUPTED)
        && action != ACTION_LAUNCHING 
        && action != ACTION_LAUNCHING_FROM_BG)
        {
            m_app->hideWaitIcon();
        }

        if(!isFirstLaunch)
        {
            if (!m_isBackward && (m_viewType == VIEW_TYPE_ALL_SONGS || m_viewType == VIEW_TYPE_ARTIST || m_viewType == VIEW_TYPE_ALBUM || m_viewType == VIEW_TYPE_PLAYLIST))
            {
                disableToolbar(VFX_FALSE);
            }
            else if (m_isBackward && m_viewType == VIEW_TYPE_ALL_SONGS)
            {
                // this case is go to root
                disableToolbar(VFX_FALSE);
            }
        }   
    }

    m_app->setSubPageEntering(VFX_FALSE);
    if(m_contentProvider)
    {
        m_contentProvider->setEntering(VFX_FALSE);
    }

    if (isUsingMediaCache())
    {
        m_app->getProvider()->setMediaCache();

        m_app->getProvider()->lockFirstVisibleCell();
    }

    resetChangeViewMode();

    VFX_OBJ_CLOSE(m_onEnteredTimer);
    m_onEnteredTimer = NULL;

    SWLA_END("MP4");
}

void VappMusicPlayerSubPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SUBPAGE_ON_EXIT, isBackward, m_viewType);

    if (m_viewType == VIEW_TYPE_PLAYLIST || m_viewType == VIEW_TYPE_PLAYLIST_SELECT)
    {
        m_app->cancelCheckDuplicatedPlaylist();
    }

    if (m_listMenu)
    {
        // deactive the focus of search input box to keep list in current position
        if (getSearchEditor())
        {
            getSearchEditor()->deactivate(VFX_TRUE);
        }

        // Freeze list menu at this moment
        m_listMenu->setIsFreezed(VFX_TRUE);

        m_listMenu->savePosition();
    }

    if (m_app->m_searchTimer)
    {
        m_app->m_searchTimer->stop();
    }

    if (isUsingMediaCache())
    {
        m_app->getProvider()->pauseMediaCache();
    }

    if (m_onEnteredTimer)
    {
        m_onEnteredTimer->stop();
        VFX_OBJ_CLOSE(m_onEnteredTimer);
        m_onEnteredTimer = NULL;

        if (m_app->m_isEntering)
        {
            m_app->hideWaitIcon();
        }
    }
}

void VappMusicPlayerSubPage::onExited()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SUBPAGE_ON_EXITED, m_viewType);

    if (m_app->getChangeViewMode() == CHANGE_VIEW_MODE_SWITCH && !m_app->getIsDying() && !m_app->getHidden())
    {
        if (m_listMenu)
        {
            // scroll list menu to the top, but somehow this process is quite slow
            m_listMenu->resetAllItems();
        }
    }

    if (m_app->getActionMode() == ACTION_ADD_TO_PLAYLIST
     && m_app->getViewType() == VIEW_TYPE_PLAYLIST_SELECT
     && (VIEW_TYPE_ALL_SONGS <= m_viewType && m_viewType <= VIEW_TYPE_ALBUM_SONG))
    {
        // restore toolbar and multi-select on page exited, to avoid too many animation running at the same time when going back
        restorePreToolBar();

        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    }

    VfxPage::onExited();
}

void VappMusicPlayerSubPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_SUBPAGE_ON_EXITED2, m_viewType);

    if (isUsingMediaCache())
    {
        // Close media cache if media cache is not running and next page is not using it, or going from search result to 2nd level
        // Close in onExited2() due to VRT may still access it after onExited(). Else shall close frame object when freee media cache
        if(m_app->getProvider()->getMediaCacheView() == VIEW_TYPE_NONE)
        {
            m_app->getProvider()->freeMediaCache();
        }
        else if (m_viewType == VIEW_TYPE_ALBUM && m_app->getActionMode() == ACTION_REFRESH)
        {
            m_app->getProvider()->freeMediaCache();
        }
    }
}

VfxBool VappMusicPlayerSubPage::isUsingMediaCache()
{
    VfxBool isUsingMC =  m_viewType == VIEW_TYPE_ALBUM
                      || m_viewType == VIEW_TYPE_ARTIST_ALBUM
                      || m_viewType == VIEW_TYPE_PLAYLIST_ADD_ALBUM
                      || m_viewType == VIEW_TYPE_COVER_FLOW;

    return isUsingMC;
}

void VappMusicPlayerSubPage::onBack()
{
    ViewTypeEnum viewType = m_app->getViewType();
    ActionEnum action = m_app->getActionMode();

    m_app->m_passBackKey = VFX_FALSE;

    if (action == ACTION_PLAYLIST_SONG_ARRANGE)
    {
        return;
    }
    else if (viewType == VIEW_TYPE_PLAYLIST_ADD_ALL_SONG
          || viewType == VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG
          || viewType == VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG)
    {
        m_app->pageMultiSelectOff(this);
    }
    else if (viewType == VIEW_TYPE_PLAYLIST_SELECT && action == ACTION_ADD_TO_PLAYLIST)
    {
        // Close playlist selection page

        VappMusicPlayerSubPage *prevPage = m_app->getPageBeforeAction();
        m_app->setViewType(prevPage->getViewType(), CHANGE_VIEW_MODE_BACK);
    }
    else if (viewType == VIEW_TYPE_VIEW_SELECT && action == ACTION_PLAYLIST_ADD_SONG)
    {
        // set to previous view type before closing
        if (m_listMenu)
        {
            m_listMenu->setIsFreezed(VFX_TRUE);
        }
    }
    else if (m_app->isSelecting())
    {
        // Do not close the page if in multi selecting
        // This case is delete or remove
        return;
    }
    else if (m_app->isTabPage())
    {
        m_app->setIsDying();
    }

    m_app->m_passBackKey = VFX_TRUE;

    VfxPage::onBack();
}

VfxBool VappMusicPlayerSubPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        back();

        // Return False here, 'cause we want the key event pass to screen level to process view control
        return VFX_FALSE;
    }

    return VfxPage::onKeyInput(event);
}

void VappMusicPlayerSubPage::onMenuStartFreerun(VcpScrollableView* view)
{
    if (m_viewType == VIEW_TYPE_ALBUM || m_viewType == VIEW_TYPE_ARTIST_ALBUM)
    {
        m_contentProvider->pauseMediaCache();
    }

    if (m_viewType ==VIEW_TYPE_ALL_SONGS || m_viewType == VIEW_TYPE_ARTIST || m_viewType == VIEW_TYPE_ALBUM)
    {
        m_cellTimer->stop();
        m_contentProvider->setMenuScrolling(VFX_TRUE);
    }
}

void VappMusicPlayerSubPage::onMenuScrollStopped(VcpBaseListMenu *menu)
{
    if (m_viewType == VIEW_TYPE_ALBUM || m_viewType == VIEW_TYPE_ARTIST_ALBUM)
    {
        m_contentProvider->resumeMediaCache();
    }

    if (m_viewType ==VIEW_TYPE_ALL_SONGS || m_viewType == VIEW_TYPE_ARTIST || m_viewType == VIEW_TYPE_ALBUM)
    {
        m_contentProvider->setMenuScrolling(VFX_FALSE);
        m_cellTimer->start();
    }
}

void VappMusicPlayerSubPage::updateCellTimerTimeout(VfxTimer *timer)
{
    VcpMenuRegion region;
    VfxS32 pos;

    region = m_listMenu->getRealContentRegion();
    pos = m_listMenu->findNextCellToLoad(region.begin.pos, region.end.pos, VFX_TRUE);

    if(pos >= 0)
    {
        updateItem(pos);
        m_cellTimer->start();
    }
}

void VappMusicPlayerSubPage::initTitleBar(VfxWString str)
{
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    m_titleBar->setTitle(str);
    setTopBar(m_titleBar);
}

void VappMusicPlayerSubPage::setTitleBarText(VfxWString str)
{
    if (m_titleBar)
    {
        m_titleBar->setTitle(str);
    }
}

void VappMusicPlayerSubPage::initListMenu(VcpListMenuCellStyleEnum style, VfxBool enableSearchBar)
{
    if (m_listMenu)
    {
        return;
    }

    VFX_OBJ_CREATE(m_listMenu, VappMusicPlayerListMenu, this);
    m_listMenu->setPos(0, 0);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setCellStyle(style);

    VcpListMenuThemeStruct themeData = m_listMenu->getThemeData();
    // Assign highlight color to green
    themeData.highlightTextColor = VRT_COLOR_MAKE(255, 94, 149, 18);
    m_listMenu->setThemeData(themeData);

    const ViewTypeEnum viewType = getViewType();
    if (viewType == VIEW_TYPE_PLAYLIST_SELECT)
    {
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    }
    else
    {
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    }
    
    setListMenuControlMode(viewType);

    m_listMenu->m_viewType = viewType;
    //m_listMenu->setContentProvider(m_app->getProvider());
    
    // Create a content provider for the list menu which point to m_provider
    VFX_OBJ_CREATE(m_contentProvider, VappMusicPlayerListMenuProvider, this);
    m_listMenu->setContentProvider(m_contentProvider);
    m_contentProvider->setDataProvider(m_app->getProvider());  // Set global data provider to this content provider
    m_contentProvider->setViewType(viewType);

    // Set list menu to provider for provider to reference back
    m_app->getProvider()->setListMenu(m_listMenu);
    m_contentProvider->setListMenu(m_listMenu);

    if (enableSearchBar)
    {
        m_enableSearchBar = VFX_TRUE;
        m_searchBar = m_listMenu->enableSearchBar();
        setSearchBarHint(viewType);
    }
    
    m_listMenu->m_signalItemTapped.connect(getApp(), &VappMusicPlayerApp::onListMenuItemTapped);
    m_listMenu->m_signalItemLongTapped.connect(getApp(), &VappMusicPlayerApp::onListMenuItemLongTapped);

    if (m_viewType == VIEW_TYPE_ALL_SONGS || m_viewType == VIEW_TYPE_ARTIST || m_viewType == VIEW_TYPE_ARTIST_ALBUM || m_viewType == VIEW_TYPE_ALBUM)
    {
        m_listMenu->m_signalStartFreerun.connect(this, &VappMusicPlayerSubPage::onMenuStartFreerun);
        m_listMenu->m_signalViewScrollEnd.connect(this, &VappMusicPlayerSubPage::onMenuScrollStopped);
    }

    if (m_viewType == VIEW_TYPE_ALL_SONGS || m_viewType == VIEW_TYPE_ARTIST || m_viewType == VIEW_TYPE_ALBUM)
    {
        VFX_OBJ_CREATE(m_cellTimer, VfxTimer, this);
        m_cellTimer->setStartDelay(10);
        m_cellTimer->m_signalTick.connect(this, &VappMusicPlayerSubPage::updateCellTimerTimeout);
    }
}

void VappMusicPlayerSubPage::setListMenuControlMode(ViewTypeEnum viewType, VfxBool isAnim)
{
    if (viewType == VIEW_TYPE_ALL_SONGS
     || viewType == VIEW_TYPE_ARTIST_SONG
     || viewType == VIEW_TYPE_ARTIST_ALBUM_SONG
     || viewType == VIEW_TYPE_ALBUM_SONG
     || viewType == VIEW_TYPE_PLAYLIST_SONG
     || viewType == VIEW_TYPE_NOW_PLAYING_LIST
     || viewType == VIEW_TYPE_PLAYLIST_ADD_ALL_SONG
     || viewType == VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG
     || viewType == VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG
     || viewType == VIEW_TYPE_PLAYLIST_SELECT)
    {
        m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, isAnim);
    }
    else
    {
        m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE, isAnim);
    }
}

void VappMusicPlayerSubPage::setToolbar(VappMusicPlayerToolbarItemStruct *itemsStruct, VfxU32 itemNum)
{
    VcpToolBar *toolbar;
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    toolbar->m_signalButtonTap.connect(getApp(), &VappMusicPlayerApp::eventHandler);

    m_preToolBar = getToolBar();
    setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, toolbar, VFX_FALSE);

    for (VfxU32 i = 0; i < itemNum; i++)
    {
        toolbar->addItem(itemsStruct[i].id, itemsStruct[i].str, itemsStruct[i].iconResID);
    }
}

ViewTypeEnum VappMusicPlayerSubPage::getViewType()
{
    return m_viewType;
}

void VappMusicPlayerSubPage::setPageViewType(ViewTypeEnum viewType)
{
    m_viewType = viewType;
}

void VappMusicPlayerSubPage::resetChangeViewMode()
{
    if (m_app->getProvider())
    {
        m_app->getProvider()->resetChangeViewMode();
    }
}

void VappMusicPlayerSubPage::initConfirmToolbar1()
{
    VappMusicPlayerToolbarItemStruct item[1];
    item[0].id = FUNC_ID_TB_BTN_OK;
    item[0].str.loadFromRes(STR_GLOBAL_OK);
    item[0].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_OK;
    
    setToolbar(item, 1);
}

void VappMusicPlayerSubPage::initConfirmToolbar2()
{
    VappMusicPlayerToolbarItemStruct items[2];
    items[0].id = FUNC_ID_TB_BTN_OK;
    items[0].str.loadFromRes(STR_GLOBAL_OK);
    items[0].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_OK;
    items[1].id = FUNC_ID_TB_BTN_CANCEL;
    items[1].str.loadFromRes(STR_GLOBAL_CANCEL);
    items[1].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL;
    
    setToolbar(items, 2);
}

void VappMusicPlayerSubPage::initConfirmToolbar3(VfxWString &str)
{
    VfxResId resId = (str == VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE) || str == VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE)) ? 
        VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE : VCP_IMG_TOOL_BAR_COMMON_ITEM_OK;
    
    VappMusicPlayerToolbarItemStruct items[3];
    items[0].id = FUNC_ID_TB_BTN_SELECT_ALL;
    items[0].str.loadFromRes(STR_ID_VAPP_MUSIC_PLAYER_TB_SELECT_ALL);
    items[0].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL;
    items[1].id = FUNC_ID_TB_BTN_OK;
    items[1].str = str;
    items[1].iconResID = resId;
    items[2].id = FUNC_ID_TB_BTN_CANCEL;
    items[2].str.loadFromRes(STR_GLOBAL_CANCEL);
    items[2].iconResID = VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL;
    
    setToolbar(items, 3);
}

void VappMusicPlayerSubPage::updateAll(VfxBool keepViewState)
{
    if (m_listMenu && !m_listMenu->getIsFreezed())
    {
        m_listMenu->updateAllItems();
    }
}

void VappMusicPlayerSubPage::updateItem(VfxU32 index)
{
    if (m_listMenu && !m_listMenu->getIsFreezed())
    {
        m_listMenu->updateItem(index);
        
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
    }
}

void VappMusicPlayerSubPage::resetAll(void)
{
    if (m_listMenu && !m_listMenu->getIsFreezed())
    {
        m_listMenu->resetAllItems();
    }
}

VcpTitleBar* VappMusicPlayerSubPage::getTitleBar()
{
    return static_cast<VcpTitleBar*>(VfxPage::getBar(VFX_PAGE_BAR_LOCATION_TOP));
}

VcpToolBar* VappMusicPlayerSubPage::getToolBar()
{
    return static_cast<VcpToolBar*>(VfxPage::getBar(VFX_PAGE_BAR_LOCATION_BOTTOM));
}

void VappMusicPlayerSubPage::restorePreToolBar()
{
    if (m_preToolBar)
    {
        // fold the toolbar after action 
        if (!m_preToolBar->isFolded())
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            m_preToolBar->switchFoldMode();
            VfxAutoAnimate::commit();
        }
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, m_preToolBar, VFX_TRUE);
        m_preToolBar = NULL;
    }
}

VappMusicPlayerListMenu* VappMusicPlayerSubPage::getListMenu()
{
    return m_listMenu;
}

void VappMusicPlayerSubPage::disableToolbar(VfxBool isDisable)
{
    VcpToolBar *bar = getToolBar();

    if (bar)
    {
        bar->setDisableItem(FUNC_ID_TB_BTN_SELECT_ALL, isDisable);
        bar->setDisableItem(FUNC_ID_TB_BTN_PLAY, isDisable);
        bar->setDisableItem(FUNC_ID_TB_BTN_NEW_PLAYLIST, isDisable);
        bar->setDisableItem(FUNC_ID_TB_BTN_ADD_TO_PLAYLIST, isDisable);
        bar->setDisableItem(FUNC_ID_TB_BTN_PLAY, isDisable);
        bar->setDisableItem(FUNC_ID_TB_BTN_DELETE, isDisable);
        bar->setDisableItem(FUNC_ID_TB_BTN_NOW_PLAYING, isDisable);
        bar->setDisableItem(FUNC_ID_TB_BTN_REFRESH, isDisable);
        bar->setDisableItem(FUNC_ID_TB_BTN_COVER_FLOW, isDisable);        
        bar->setDisableFoldButton(isDisable);
    }
}

void VappMusicPlayerSubPage::disableSearchBar(VfxBool isDisable)
{
    // The sub page does not set search bar
    if(!m_enableSearchBar)
    {
        return;
    }

    if (!m_searchBar)
    {
        return;
    }

    VcpTextEditor *editor = m_searchBar->getSearchEditor();

    VappMusicPlayerApp *app = getMusicPlayerApp();

    if(isDisable)
    {
        editor->m_signalTextChanged.disconnect(app, &VappMusicPlayerApp::onSearchTextChange);
    }
    else
    {
        editor->m_signalTextChanged.connect(app, &VappMusicPlayerApp::onSearchTextChange);
    }

    editor->setIsDisabled(isDisable);
}

void VappMusicPlayerSubPage::setSearchBarHint(ViewTypeEnum viewType)
{
    VfxResId hintStrID = STR_GLOBAL_SEARCH;
    switch (m_viewType)
    {
        case VIEW_TYPE_ALL_SONGS:
            hintStrID = STR_ID_VAPP_MUSIC_PLAYER_SEARCH_SONG;
            break;
    
        case VIEW_TYPE_ARTIST:
            hintStrID = STR_ID_VAPP_MUSIC_PLAYER_SEARCH_ARTIST;
            break;
    
        case VIEW_TYPE_ALBUM:
            hintStrID = STR_ID_VAPP_MUSIC_PLAYER_SEARCH_ALBUM;
            break;
    }
    
    if(m_searchBar)
    {
        m_searchBar->m_textEditor->setHint(hintStrID);
    }
}

VcpTextEditor* VappMusicPlayerSubPage::getSearchEditor()
{
    if (m_searchBar)
    {
        return m_searchBar->getSearchEditor();
    }
    else
    {
        return NULL;
    }
}

void VappMusicPlayerSubPage::clearSearchEditor()
{
    if (m_searchBar)
    {
        m_searchBar->getSearchEditor()->deleteAll();
    }
}

void VappMusicPlayerSubPage::deactivateSearchEditor()
{
    if (m_searchBar)
    {
        // deactive the focus of search input box to keep list in current position
        m_searchBar->getSearchEditor()->deactivate(VFX_TRUE);
    }
}

/***************************************************************************** 
 * VappMusicPlayerListMenu Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerListMenu", VappMusicPlayerListMenu, VcpListMenu);

void VappMusicPlayerListMenu::onInit()
{
    m_cellList.init(this);

    VcpListMenu::onInit();
}

VfxFrame* VappMusicPlayerListMenu::createCell(VfxS32 group,VfxS32 pos)
{
    // Create a link list to keep which cell is created
    VappMusicPlayerListCell cell;
    cell.pos = pos;
    cell.isSubTextLoad = VFX_FALSE;

    // Insert with sequence
    VfxList <VappMusicPlayerListCell>::It itr;
    for (itr = m_cellList.begin(); !itr.isNull(); ++itr)
    {
        VappMusicPlayerListCell &pCell = *itr;
        if(pCell.pos > pos)
        {
            m_cellList.pushFront(cell);
            return VcpListMenu::createCell(group,pos);
        }
    }

    // Append at the end if the pos is largest
    m_cellList.pushBack(cell);

    return VcpListMenu::createCell(group,pos);
}

void VappMusicPlayerListMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame) 
{
    VfxList <VappMusicPlayerListCell>::It itr;
    for (itr = m_cellList.begin(); !itr.isNull(); ++itr)
    {
        VappMusicPlayerListCell &pCell = *itr;
        if(pCell.pos == pos)
        {
            m_cellList.erase(itr);
            break;
        }
    }

    VcpListMenu::onCloseCell(group,pos, cellFrame);
}

void VappMusicPlayerListMenu::onUpdate()
{
    // FW will freeze the exiting page while switching, no need to handle this by APP anymore
    //if (!m_isFreezed)    
    if (1)
    {
        VcpListMenu::onUpdate();
    }
}

VfxBool VappMusicPlayerListMenu::updateViewForIme(VfxFrame * focusFrame)
{
    // Overide this function in scrollable to avoid focus jump to editor when IME disappear
    return MMI_TRUE;
}

void VappMusicPlayerListMenu::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_UPDATE_VIEW_FOR_IME:
        {          
            VfxFrameUpdateViewForImeData* data = (VfxFrameUpdateViewForImeData*)userData;
            data->ret = updateViewForIme(data->focusFrame);
            return;
        }
       
        default:
        {
            VcpListMenu::onObjectNotify(id, userData);
            return;
        }
    }
}

void VappMusicPlayerListMenu::savePosition()
{
    getViewState(&m_viewState);
}

void VappMusicPlayerListMenu::restorePosition()
{
    setViewState(&m_viewState);
}

void VappMusicPlayerListMenu::resetPosition()
{
    m_viewState.contentXOffset = 0;
    m_viewState.contentYOffset = 0;
    m_viewState.focusGroup = 0;
    m_viewState.focusPos = 0;

    restorePosition();
}

void VappMusicPlayerListMenu::setIsFreezed(VfxBool isFreezed)
{
    m_isFreezed = isFreezed;
}

VfxBool VappMusicPlayerListMenu::getIsFreezed()
{
    return m_isFreezed;
}

VfxBool VappMusicPlayerListMenu::getIsCustomStyle()
{
    return m_cellStyle == VCP_LIST_MENU_CELL_STYLE_CUSTOM;
}

VfxBool VappMusicPlayerListMenu::getIsPenDown()
{
    return m_isPenDown;
}

void VappMusicPlayerListMenu::onDragStart()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_LIST_MENU_ON_DRAG_START);

    VcpListMenu::onDragStart();

    m_isPenDown = VFX_TRUE;

    VappMusicPlayerApp *mApp = VFX_OBJ_DYNAMIC_CAST(findRootApp(this), VappMusicPlayerApp);
    if (mApp)
    {
        mApp->onListMenuDragStateChange(VFX_TRUE);
    }
}

void VappMusicPlayerListMenu::onDragEnd()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_LIST_MENU_ON_DRAG_END);

    VcpListMenu::onDragEnd();

    m_isPenDown = VFX_FALSE;

    VappMusicPlayerApp *mApp = VFX_OBJ_DYNAMIC_CAST(findRootApp(this), VappMusicPlayerApp);
    if (mApp)
    {
        mApp->onListMenuDragStateChange(VFX_FALSE);
    }
}

void VappMusicPlayerListMenu::startDragCell(VcpMenuPos pos, VfxFrame* dragCell)
{
    VcpListMenu::startDragCell(pos, dragCell);

    m_signalDragCell.emit(VFX_TRUE, pos.pos);
}

void VappMusicPlayerListMenu::endDragCell(VcpMenuPos pos, VfxFrame* dragCell)
{
    m_signalDragCell.postEmit(VFX_FALSE, pos.pos);

    VcpListMenu::endDragCell(pos, dragCell);
}

VfxBool VappMusicPlayerListMenu::getIsDraggingCell()
{
    return m_isDraggingCell;
}

VfxS32 VappMusicPlayerListMenu::findNextCellToLoad(VfxS32 begin, VfxS32 end, VfxBool setLoadAfterFind)
{
    if(begin < 0 || end < 0)
    {
        return -1;
    }

    VfxList <VappMusicPlayerListCell>::It itr;
    for (itr = m_cellList.begin(); !itr.isNull(); ++itr)
    {
        VappMusicPlayerListCell &pCell = *itr;

        for(VfxS32 j = begin ; j <= end ; j++)
        {
            if(j == pCell.pos && !pCell.isSubTextLoad)
            {
                if(setLoadAfterFind)
                {
                    pCell.isSubTextLoad = VFX_TRUE;
                }
                return j;
            }
        }
    }
    return -1;
}

VfxBool VappMusicPlayerListMenu::isCellSubTextLoad(VfxS32 pos)
{
    if(pos < 0)
    {
        return VFX_FALSE;
    }

    VfxList <VappMusicPlayerListCell>::It itr;
    for (itr = m_cellList.begin(); !itr.isNull(); ++itr)
    {
        VappMusicPlayerListCell &pCell = *itr;
        if(pCell.pos == pos)
        {
            return pCell.isSubTextLoad;
        }
    }


    return VFX_FALSE;
}


/***************************************************************************** 
 * VappMusicPlayerSongListCell Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSongListCell", VappMusicPlayerSongListCell, VcpListMenuCellTripleTextFrameEx);

void VappMusicPlayerSongListCell::onUpdateElements()
{
    VcpListMenuCellTripleTextFrameEx::onUpdateElements();

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (!app->isSelecting())
    {
        return;
    }

    VfxImageSrc img;
    IVcpListMenuContentProviderInt *contentProvider = getContentProvider();

    if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON_EXTRA1, img))
    {
        if (!m_extraImgFrame1)
        {
            VFX_OBJ_CREATE(m_extraImgFrame1, VfxImageFrame, this);
        }
        
        m_extraImgFrame1->setImgContent(img);
    }
    else if (m_extraImgFrame1)
    {
        VFX_OBJ_CLOSE(m_extraImgFrame1);
        m_extraImgFrame1 = NULL;
    }

    if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON_EXTRA2, img))
    {
        if (!m_extraImgFrame2)
        {
            VFX_OBJ_CREATE(m_extraImgFrame2, VfxImageFrame, this);
        }
        
        m_extraImgFrame2->setImgContent(img);
    }
    else if (m_extraImgFrame2)
    {
        VFX_OBJ_CLOSE(m_extraImgFrame2);
        m_extraImgFrame2 = NULL;
    }

    if (m_textFrame2)
    {
        VFX_OBJ_CLOSE(m_textFrame2);

        VfxFrame *tempTextFrame = createItemTextFrameInt(VCP_LIST_MENU_FIELD_SUB_TEXT1);

        if (tempTextFrame)
        {
            m_textFrame2 = tempTextFrame;
        }
    }

    if (m_textFrame3)
    {
        VFX_OBJ_CLOSE(m_textFrame3);

        VfxFrame *tempTextFrame = createItemTextFrameInt(VCP_LIST_MENU_FIELD_SUB_TEXT2);

        if (tempTextFrame)
        {
            m_textFrame3 = tempTextFrame;
        }
    }    
}

/***************************************************************************** 
 * VappMusicPlayerArtistListCell Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerArtistListCell", VappMusicPlayerArtistListCell, VcpListMenuCellMultiTextFrame);

void VappMusicPlayerArtistListCell::onUpdateElements()
{
    VcpListMenuCellMultiTextFrame::onUpdateElements();

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (!app->isSelecting())
    {
        return;
    }

    if (m_textFrame2)
    {
        VFX_OBJ_CLOSE(m_textFrame2);

        VfxFrame *tempTextFrame = createItemTextFrameInt(VCP_LIST_MENU_FIELD_SUB_TEXT1);

        if (tempTextFrame)
        {
            m_textFrame2 = tempTextFrame;
        }
    }
}

/***************************************************************************** 
 * VappMusicPlayerAlbumListCell Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerAlbumListCell", VappMusicPlayerAlbumListCell, VcpListMenuCellIconMultiTextFrame);

void VappMusicPlayerAlbumListCell::onLayoutElements()
{
    VcpListMenuCellIconMultiTextFrame::onLayoutElements();

    if (m_imageFrame)
    {
#if defined(__MMI_MAINLCD_240X320__)
        const VfxU32 LEFT_GAP = 6;
        const VfxU32 IMG_WIDTH = 40;
#elif defined(__MMI_MAINLCD_240X400__)
        const VfxU32 LEFT_GAP = 6;
        const VfxU32 IMG_WIDTH = 40;
#elif defined(__MMI_MAINLCD_320X480__)
        const VfxU32 LEFT_GAP = 3;
        const VfxU32 IMG_WIDTH = 45;
#else //(__MMI_MAINLCD_480X800__)
        const VfxU32 LEFT_GAP = 7;
        const VfxU32 IMG_WIDTH = 72;
#endif
        m_imageFrame->setRect(VfxRect(LEFT_GAP, (getBounds().getHeight() - m_imageFrame->getBounds().getHeight()) / 2,
                                      IMG_WIDTH, m_imageFrame->getRect().getHeight()));
        //m_imageFrame->setBorder(VRT_COLOR_MAKE(255, 200, 200, 200), 0);
        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_NONE);
    }

#if defined(__MMI_MAINLCD_240X320__)
    const VfxU32 shift = 16;
#elif defined(__MMI_MAINLCD_240X400__)
    const VfxU32 shift = 16;
#elif defined(__MMI_MAINLCD_320X480__)
    const VfxU32 shift = 0;
    return;
#else //(__MMI_MAINLCD_480X800__)
    const VfxU32 shift = 25;
#endif
    if (m_textFrame1)
    {
        VfxPoint pos1(m_textFrame1->getPos());
        VfxSize size1(m_textFrame1->getSize());
        m_textFrame1->setPos(pos1.x + shift, pos1.y);
        m_textFrame1->setSize(size1.width - shift, size1.height);

        m_textFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_textFrame2)
    {
        VfxPoint pos2(m_textFrame2->getPos());
        VfxSize size2(m_textFrame2->getSize());
        m_textFrame2->setPos(pos2.x + shift, pos2.y);
        m_textFrame2->setSize(size2.width - shift, size2.height);

        m_textFrame2->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}

void VappMusicPlayerAlbumListCell::onUpdateElements()
{
    VcpListMenuCellIconMultiTextFrame::onUpdateElements();

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (!app->isSelecting())
    {
        return;
    }

    IVcpListMenuContentProviderInt *contentProvider = getContentProvider();

    VfxImageSrc img;

    if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, img))
    {
        m_imageFrame->setImgContent(img);
    }

    if (m_textFrame2)
    {
        VFX_OBJ_CLOSE(m_textFrame2);

        VfxFrame *tempTextFrame = createItemTextFrameInt(VCP_LIST_MENU_FIELD_SUB_TEXT1);

        if (tempTextFrame)
        {
            m_textFrame2 = tempTextFrame;
        }
    }
}

void VappMusicPlayerAlbumListCell::enableImageBorder(VfxBool hasBorder)
{
#if defined(__MMI_MAINLCD_240X320__)
    const VfxU32 borderSize = 1;
#elif defined(__MMI_MAINLCD_240X400__)
    const VfxU32 borderSize = 1;
#elif defined(__MMI_MAINLCD_320X480__)
    const VfxU32 borderSize = 1;
#else //(__MMI_MAINLCD_480X800__)
    const VfxU32 borderSize = 2;
#endif

    //m_imageFrame->setBorderWidth(hasBorder ?  borderSize : 0);
    if(hasBorder)
    {
        m_imageFrame->setBorder(VRT_COLOR_MAKE(255, 200, 200, 200), borderSize);
    }
    else
    {
        m_imageFrame->setBorderWidth(0);
    }
}

/***************************************************************************** 
 * VappMusicPlayerAlbumSongCell Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerAlbumSongCell", VappMusicPlayerAlbumSongCell, VcpListMenuCellTripleTextFrameEx);

void VappMusicPlayerAlbumSongCell::onLayoutElements()
{
    VcpListMenuCellTripleTextFrameEx::onLayoutElements();

#if defined(__MMI_MAINLCD_320X480__)
        const VfxU32 LEFT_GAP = 3;
        const VfxU32 SERIAL_TEXT_WIDTH = 30;
#else //(__MMI_MAINLCD_480X800__)
        const VfxU32 LEFT_GAP = 7;
        const VfxU32 SERIAL_TEXT_WIDTH = 48;
#endif

    if (m_textSerial == NULL && m_textFrame1)
    {
        VFX_OBJ_CREATE(m_textSerial, VfxTextFrame, this);
        m_textSerial->setSize(SERIAL_TEXT_WIDTH, m_textFrame1->getSize().height);
        m_textSerial->setPos(LEFT_GAP, (getBounds().getHeight() - m_textFrame1->getBounds().getHeight()) / 2);
        m_textSerial->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_textSerial->setAutoResized(VFX_FALSE);
        m_textSerial->setAutoFontSize(VFX_TRUE);
        m_textSerial->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));
        
        VfxWString str;
        str.format("%d", m_serial);
        m_textSerial->setString(str);

        updateSerialColor();
    }   
    
    if (m_textFrame1)
    {
        m_textFrame1->setPos(m_textFrame1->getPos().x + LEFT_GAP + SERIAL_TEXT_WIDTH, m_textFrame1->getPos().y);
        m_textFrame1->setSize(m_textFrame1->getSize().width - (LEFT_GAP + SERIAL_TEXT_WIDTH), m_textFrame1->getSize().height);
        m_textFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_textFrame2)
    {
        m_textFrame2->setPos(m_textFrame2->getPos().x + LEFT_GAP + SERIAL_TEXT_WIDTH, m_textFrame2->getPos().y);
        m_textFrame2->setSize(m_textFrame2->getSize().width - (LEFT_GAP + SERIAL_TEXT_WIDTH), m_textFrame2->getSize().height);
        m_textFrame2->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}

void VappMusicPlayerAlbumSongCell::onUpdateElements()
{
    VcpListMenuCellTripleTextFrameEx::onUpdateElements();

    IVcpListMenuContentProviderInt *contentProvider = getContentProvider();

    if (m_textSerial)
    {
        VfxWString text;
        VcpListMenuTextColorEnum color;
        if (contentProvider->getItemText(getCell()->m_pos, VCP_LIST_MENU_FIELD_TEXT, text, color))
        {
            VcpListMenuCell *cell = (VcpListMenuCell*)getParent();
            m_textSerial->setColor(cell->getTextColor(color));
        }
    }

    VappMusicPlayerApp *app = getMusicPlayerApp();
    if (!app->isSelecting())
    {
        return;
    }

    VfxImageSrc img;
    if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON_EXTRA2, img))
    {
        m_extraImgFrame2->setImgContent(img);
    }

    if (m_textFrame2)
    {
        VFX_OBJ_CLOSE(m_textFrame2);

        VfxFrame *tempTextFrame = createItemTextFrameInt(VCP_LIST_MENU_FIELD_SUB_TEXT1);

        if (tempTextFrame)
        {
            m_textFrame2 = tempTextFrame;
        }
    }

    if (m_textFrame3)
    {
        VFX_OBJ_CLOSE(m_textFrame3);

        VfxFrame *tempTextFrame = createItemTextFrameInt(VCP_LIST_MENU_FIELD_SUB_TEXT2);

        if (tempTextFrame)
        {
            m_textFrame3 = tempTextFrame;
        }
    }
}

void VappMusicPlayerAlbumSongCell::setSerial(const VfxU32 serial)
{
    m_serial = serial;
}

void VappMusicPlayerAlbumSongCell::setIsPlaying(const VfxBool isPlaying)
{
    m_isPlaying = isPlaying;
    if (m_prePlaying != m_isPlaying)
    {
        m_prePlaying = m_isPlaying;
        updateSerialColor();
    }
}

void VappMusicPlayerAlbumSongCell::updateSerialColor()
{
    if (m_textSerial)
    {
        VcpListMenuCell *cell = (VcpListMenuCell*)getParent();
        if (m_isPlaying)
        {
            m_textSerial->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT));
        }
        else
        {
            m_textSerial->setColor(cell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
        }
    }
}


#endif //__COSMOS_MUSICPLY__
