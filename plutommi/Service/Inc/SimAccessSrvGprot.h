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
 *  SimAccessSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SIM access Service Global prototype declaration
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_SIM_GPROT_H__
#define __SRV_SIM_GPROT_H__

#include "MMIDataType.h"
#include "kal_general_types.h"

#define SRV_SIM_MAX_ACCESS  (20)

/* SIM action Type */
typedef enum
{
   SRV_SIM_READ_RECORD = 0,
   SRV_SIM_WRITE_RECORD,
   SRV_SIM_READ_BINARY,
   SRV_SIM_WRITE_BIANRY,
   SRV_SIM_GET_FILE_INF,

   SRV_SIM_ACTION_END   
}srv_sim_action_enum;

/* define callback structure */ 
typedef struct
{
    MMI_BOOL result; 
    U16 cause; 
    void* data;
    void* user_data;
    mmi_sim_enum sim_id;
    srv_sim_action_enum action;
} srv_sim_cb_struct;


/* SMS data informatin */
typedef struct
{
    U16 length;
    U8  *data;
} srv_sim_data_struct;


/* SMS sim file informatin, will return this struct from callback when caller call srv_sim_get_file_info */
typedef struct
{
    U16 file_size;
    U8  num_of_rec;
    U8  file_type;
} srv_sim_file_info_struct;


/*****************************************************************************
 * <GROUP  CallBackFunctions>		
 *
 * FUNCTION
 *  SrvSimCallbackFunc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
*****************************************************************************/
typedef void(*SrvSimCallbackFunc)(srv_sim_cb_struct* callback_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sim_read_record
 * DESCRIPTION
 *  Read record data from SIM 
 * PARAMETERS
 *  file_index  [IN]        File index, please use default index from sim_file_index_enum
 *  file_path   [IN]        file path, if file index be set as 0, caller need to set file path using sim_file_id_enum
 *  record_index      [IN]        index current record need to write
 *  record_size      [IN]        length of current record
 *  sim_id      [IN]    SIM id, please refer to the enum: mmi_sim_enum
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sim_read_record(
            U16 file_index, /* sim_file_index_enum */
            U8 *file_path, /* sim_file_id_enum */
            U16 record_index,
            U16 record_size,
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sim_read_binary
 * DESCRIPTION
 *  Read binary data from SIM 
 * PARAMETERS
 *  file_index  [IN]        File index, please use default index from sim_file_index_enum
 *  file_path   [IN]        file path, if file index be set as 0, caller need to set file path using sim_file_id_enum
 *  offset      [IN]        offset current data need to write
 *  length      [IN]        length of current data
 *  sim_id      [IN]    SIM id, please refer to the enum: mmi_sim_enum
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sim_read_binary(
            U16 file_index, /* sim_file_index_enum */
            U8 *file_path, /* sim_file_id_enum */
            U16 offset,
            U16 length,
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sim_write_record
 * DESCRIPTION
 *  Write record data to SIM 
 * PARAMETERS
 *  file_index  [IN]        File index, please use default index from sim_file_index_enum
 *  file_path   [IN]        file path, if file index be set as 0, caller need to set file path using sim_file_id_enum
 *  record_index      [IN]        index current record need to write
 *  record_size      [IN]        length of current record
 *  data       [IN]        Data
 *  sim_id      [IN]    SIM id, please refer to the enum: mmi_sim_enum
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sim_write_record(
            U16 file_index, /* sim_file_index_enum */
            U8 *file_path, /* sim_file_id_enum */
            U16 record_index,
            U16 record_size,
            U8* data,   /* The max length is 255 */
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data);
            

/*****************************************************************************
 * FUNCTION
 *  srv_sim_write_binary
 * DESCRIPTION
 *  Write binary data to SIM 
 * PARAMETERS
 *  file_index  [IN]        File index, please use default index from sim_file_index_enum
 *  file_path   [IN]        file path, if file index be set as 0, caller need to set file path using sim_file_id_enum
 *  offset      [IN]        offset current data need to write
 *  length      [IN]        length of current data
 *  data       [IN]        Data
 *  sim_id      [IN]    SIM id, please refer to the enum: mmi_sim_enum
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sim_write_binary(
            U16 file_index, /* sim_file_index_enum */
            U8 *file_path, /* sim_file_id_enum */
            U16 offset,
            U16 length,
            void* data,  /* The max length is 255 */
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_get_file_info
 * DESCRIPTION
 *  Get SIM file information
 * PARAMETERS
 *  file_index  [IN]        File index, please use default index from sim_file_index_enum
 *  file_path   [IN]        file path, if file index be set as 0, caller need to set file path using sim_file_id_enum
 *  sim_id      [IN]    SIM id, please refer to the enum: mmi_sim_enum
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_sim_get_file_info(
            U16 file_index, /* sim_file_index_enum */
            U8 *file_path, /* sim_file_id_enum */
            mmi_sim_enum sim_id,
            SrvSimCallbackFunc callback,
            void *user_data);

#endif /* __SRV_SIM_GPROT_H__ */
