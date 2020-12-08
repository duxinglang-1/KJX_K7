#include "MMIDataType.h"
#include "vmsys.h"
#include "vmpromng.h"

void vm_frm_init(void);

mmi_id vm_frm_get_group_id(VM_P_HANDLE pHandle);

VMINT vm_frm_entry_app_screen(VM_P_HANDLE pHandle);

VMINT vm_frm_exit_app_screen(VM_P_HANDLE pHandle);

MMI_BOOL vm_frm_is_active(void);

