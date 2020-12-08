#ifndef _MRE_DEF_H
#define _MRE_DEF_H

#include "MMI_features.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "mmi_lib_res_range_def.h"
#include "tst_def.h"

#define VM_MRE_CMD_MAX_PATH INJECT_STRING_TO_MODULE_MAX_LENGTH

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32   error_code;
    kal_uint8   cmd_str[VM_MRE_CMD_MAX_PATH] ;//
}
mmi_mre_cmd_rsp_struct;

typedef enum
{
    EVT_ID_MRE_STATUSBAR_BEGIN = MRE_BASE + 1, /* BASE_ID + 1 */
    EVT_ID_MRE_NOTIFICATION_MESSAGE,
}mmi_vm_statusbar_event_enum;

// MPR Notification-Center 1.0 adapter <20120320.Zhibo Tong> START 
typedef enum
{
    EVT_ID_MPR_STATUSBAR_BEGIN = MRE_BASE + 10, /* BASE_ID + 10 */
    EVT_ID_MPR_NCENTER_FIRST_CELL_NEW_MESSAGE,
    EVT_ID_MPR_NCENTER_SECOND_CELL_NEW_MESSAGE,
//    EVT_ID_MPR_NCENTER_THIRD_CELL_NEW_MESSAGE,
//    EVT_ID_MPR_NCENTER_FOURTH_CELL_NEW_MESSAGE,
}mmi_vm_mpr_event_enum;
// MPR Notification-Center 1.0 adapter <20120320.Zhibo Tong> END

#endif /* _MRE_DEF_H */
