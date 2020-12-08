/*******************************************************************************
 * 
 * Filename:
 * ---------
 *	btdrv_struct.h
 *
 * Project:
 * --------
 *   MAUI MTK Bluetooth Chip
 *
 * Description:
 * ------------
 *   This file contains defined configures which are both used in bt driver and bt stack
 *
 * Author:
 * -------
 * -------
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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

#ifndef BTDRV_STRUCT_H
#define BTDRV_STRUCT_H
#include "kal_general_types.h"

//bluetooth_struct.h
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 trim_value;
} bt_set_ana_trim_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 name[32];
    kal_uint8 bd_addr[6];
    kal_uint8 dcs;
} bt_set_bd_param_req_struct;

#endif 
 
