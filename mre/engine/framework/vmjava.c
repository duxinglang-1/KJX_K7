#include "vmswitch.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "vmjava.h"

#ifdef __J2ME__                           

extern void mmi_java_mre_cb(vm_cmd_enum cmd, vm_cmd_info_struct *vm_cmd_info); 
extern kal_bool mmi_java_mre_is_removed(kal_char* mids_storage_id);


void vm_process_java_app( vm_cmd_enum cmd, vm_cmd_info_struct *info)
{
		VM_P_HANDLE process_handle = vm_pmng_get_current_handle();
		info->process_handle = process_handle;
		mmi_java_mre_cb(cmd, info);
}

VMINT vm_java_is_removed(VMSTR mids_storage_id)
{
	return mmi_java_mre_is_removed(mids_storage_id);
}

void mmi_mre_report_status( vm_cmd_enum cmd, VM_P_HANDLE process_handle, vm_java_report_status_t vm_java_report_status, vm_process_result_enum error_code, VMSTR mids_storage_id)
{
	if(cmd == VM_CMD_JAVA_INSTALL)
	{
		if (vm_pmng_set_ctx(process_handle) == VM_PMNG_OP_OK)
		{
			if (vm_java_report_status != NULL)
			{
				vm_java_report_status(error_code, mids_storage_id);
			}
			vm_pmng_reset_ctx();
		}	  
	}
}

#endif
