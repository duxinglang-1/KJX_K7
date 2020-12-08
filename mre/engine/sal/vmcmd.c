#include "mredef.h"
#include "stack_msgs.h"
#include "MRESrvGprot.h"
#include "MREAppmgrsrvGprot.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "Conversions.h"


#define VM_MRE_CMD_INSTALL          "install"
#define VM_MRE_CMD_UNINSTALL        "uninstall"
#define VM_MRE_CMD_LAUNCH           "launch"
#define VM_MRE_CMD_EXIT             "exit"



static void vm_mre_cmd_launch_cb(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
    
}

static VMINT vm_mre_cmd_operate_string(VMSTR str)
{
    VMWSTR path;
    VMINT ret = 0;
    VMWCHAR buff[INJECT_STRING_TO_MODULE_MAX_LENGTH];
    
    if (NULL == str || 0 == str[0])
    {
        return -999;
    }

    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2,(char *)str, (char *)buff, INJECT_STRING_TO_MODULE_MAX_LENGTH*2);
    
    if (0 ==strncmp(str,VM_MRE_CMD_INSTALL,strlen(VM_MRE_CMD_INSTALL)))
    //INSTALL
    {
    
        path = buff+strlen(VM_MRE_CMD_INSTALL)+1;
        ret = srv_mre_appmgr_install_app(path,SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL,NULL)?0:-1;
        
    }
    else if (0 == strncmp(str,VM_MRE_CMD_UNINSTALL,strlen(VM_MRE_CMD_UNINSTALL)))
    //UNINSTALL
    {
    
        U16 app_name_tmp[MMI_APP_NAME_MAX_LEN];
        mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN];

        path = buff+strlen(VM_MRE_CMD_UNINSTALL)+1;
        
        srv_mre_appmgr_generate_identification((U16 *)path, app_name_tmp);
        mmi_ucs2_to_asc(app_name,(CHAR *)app_name_tmp);
        mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8, (char *)app_name_tmp, (char *)app_name, MMI_APP_NAME_MAX_LEN);

        ret = srv_mre_appmgr_app_uninstall(app_name)?0:-1;
        
    }
    else if (0 == strncmp(str,VM_MRE_CMD_LAUNCH,strlen(VM_MRE_CMD_LAUNCH)))
    //LAUNCH
    {
    
        path = buff+strlen(VM_MRE_CMD_LAUNCH)+1;
        
        ret = (VMINT)srv_mre_launch_app_ex(path,vm_mre_cmd_launch_cb);
        
    }
    else if (0 == strncmp(str,VM_MRE_CMD_EXIT,strlen(VM_MRE_CMD_EXIT)))
    //EXIT
    {
    
        VM_P_HANDLE handle;
        
        path = buff+strlen(VM_MRE_CMD_EXIT)+1;
        
        handle = vm_pmng_get_handle(path);
        if (0 == handle)
        {
            ret = 1;
        }
        else
        {
            ret = vm_pmng_delete_process(handle);            
        }
        
    }
	else
	{
		return -999;
	}
    {
        MYQUEUE Message; 
        mmi_mre_cmd_rsp_struct *event = NULL; 
        event = (mmi_mre_cmd_rsp_struct*) OslConstructDataPtr(sizeof(mmi_mre_cmd_rsp_struct)); 
        event->error_code= (kal_int32)ret; 
        strcpy((kal_char*)event->cmd_str,(const kal_char*)str); 
        Message.oslSrcId = MOD_MMI; 
        Message.oslDestId = MOD_MMI; 
        Message.oslMsgId = MSG_ID_MMI_MRE_CMD_RSP; 
        Message.oslDataPtr = (oslParaType*) event; 
        Message.oslPeerBuffPtr = NULL; 
        OslMsgSendExtQueue(&Message); 
    }
    return ret;
}

mmi_ret vm_mre_cmd_operate_req_handler(ilm_struct *ilm_ptr)
{
    tst_inject_string_struct* pdata = (tst_inject_string_struct*)ilm_ptr;
    if (-999 == vm_mre_cmd_operate_string(pdata->string))
	{
		return 0;
	}
    return 1;
}

void vm_mre_cmd_init(void)
{
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_MRE_CMD_REQ,(PsFuncPtr) vm_mre_cmd_operate_req_handler,MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_TST_INJECT_STRING,(PsFuncPtr) vm_mre_cmd_operate_req_handler, MMI_TRUE);;
}

