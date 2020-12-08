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
 *  TcardSrvGProtSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  T Card service internal prototype declaration
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
*****************************************************************************/
#ifndef SRV_TCARDSRVPROT_H
#define SRV_TCARDSRVPROT_H

#include "MMI_features.h"
#ifdef __SRV_TCARD_DATA_STORE__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "Fs_gprot.h"
#include "FileMgrSrvGProt.h"
#include "TcardSrvGprot.h"
#include "Tcard_config.h"



    
    
#define SRV_TCARD_MAX_PATH_LEN      (SRV_FMGR_PATH_MAX_LEN + 1)
#define SRV_TCARD_CACHE_LEN      (12 * 1024)

typedef U16 TCARD_CHECKSUM;

#define SRV_TCARD_SERVICE_FOLDER_NAME      "\\@Tcard\\" 
#define SRV_TCARD_ORIGINAL_FILE_EXT_NAME      ".o" 
#define SRV_TCARD_BACKUP_FILE_EXT_NAME      ".bak"  

/****************************************************/
/*                                                  */
/*               Enum                               */
/*                                                  */
/****************************************************/
typedef struct _srv_tcard_hdl_node_struct
{
    FS_HANDLE file_hdl;
    struct srv_tcard_hdl_node_struct * next_node;
}srv_tcard_hdl_node_struct;

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
#endif

/*for init only*/
typedef struct
{
    U16 total_num; /*the total_num of the tcard_file_mgr_common_table*/
    U16 curr_index; /*the index that initing*/
} srv_tcard_init_cnxt_struct;




extern TCARD_CHECKSUM srv_tcard_checksum_compute_by_hd(FS_HANDLE hd, U32 position);
extern TCARD_CHECKSUM srv_tcard_checksum_compute_by_buffer(const CHAR* buf, U32 len);


extern void srv_tcard_init(void);

extern void srv_tcard_deinit(void);

#endif /*__SRV_TCARD_DATA_STORE__*/

#endif



