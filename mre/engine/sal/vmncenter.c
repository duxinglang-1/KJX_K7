#include "mmi_features.h"
#include "vmstatusbar.h"
#include "vmcert.h"
#include "vmgettag.h"
#include "MRESrvGprot.h"
#include "PnSrvGprot.h"
#include "mmi_rp_app_mre_def.h"
#include "app_mem_med.h"
#include "gdi_include.h"
#include "GlobalResDef.h"    
#include "MREAppMgrSrvGprot.h"
#include "vmmem.h"
#include "Conversions.h"
#include "vmpn.h"
#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ncenter.h"


#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_app_manager_def.h"
#define STR_ID_LAUNCH_FAIL STR_ID_VAPP_AM_POPUP_LAUNCH_FAIL
#else
#include "mmi_rp_app_am_def.h"
#define STR_ID_LAUNCH_FAIL STR_ID_AM_FAIL_TO_START
#endif


typedef struct
{
    U16* path;
    U8*  img;
}vm_ongoing_data;

void vm_ncenter_event_cb(vsrv_notification_handle handle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    U16* path = (U16*)*(U32*)userData;
    if (VSRV_NINTENT_TYPE_LAUNCH == intent.type)
    {
        srv_mre_launch_app_ex(path,NULL);
        vsrv_ncenter_close_notification(handle);
    }  
}

mmi_ret vm_ncenter_event_handler(mmi_event_struct *event)
{
    vsrv_ngroup_handle group_hdl;
    vsrv_notification_handle noti_hdl;
    mmi_image_src_struct imag;
    vm_status_bar_icon_t* icon_data = (vm_status_bar_icon_t*)event->user_data;
    mmi_mre_data* data = icon_data->ncenter_cell_buf;
    U32 tmpdata;
    
    group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_MRE+1);
    ASSERT(group_hdl != NULL);

    vsrv_ncenter_set_ngroup_title_str(group_hdl,L"MRE");
    noti_hdl = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT,group_hdl,(vsrv_notification_id)icon_data);
    ASSERT(noti_hdl != NULL);

    vsrv_ncenter_set_notification_maintext_str(noti_hdl,(WCHAR*)L"Unread Message");
    vsrv_ncenter_set_notification_subtext_str(noti_hdl,(WCHAR*)data->subText);

    imag.type = MMI_IMAGE_SRC_TYPE_MEM;
    imag.data.mem = icon_data->ncenter_cell_buf->imageBuffer;
    vsrv_ncenter_set_notification_icon(noti_hdl, imag);
    tmpdata = (U32)icon_data->fullFilename;
    vsrv_ncenter_set_notification_intent_callback(noti_hdl, vm_ncenter_event_cb, (void *)&tmpdata, 4);
    vsrv_ncenter_notify_notification(noti_hdl);
    return 0;
}

void vm_ncenter_close_notification(void* data)
{
    vsrv_ngroup_handle group_hdl;
    vsrv_notification_handle noti_hdl;
    
    group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_MRE+1);
    ASSERT(group_hdl != NULL);  
    
    noti_hdl = vsrv_ncenter_query_notification(group_hdl, (vsrv_notification_id) data);
    if (noti_hdl)
    {
        vsrv_ncenter_close_notification(noti_hdl);
    }
}

void vm_ncenter_ongoing_cb(vsrv_notification_handle handle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    vm_ongoing_data data;
    memcpy(&data,userData,sizeof(data));
    if (VSRV_NINTENT_TYPE_LAUNCH == intent.type)
    {
        srv_mre_launch_app_ex(data.path,NULL);
        
    }
    else if(VSRV_NINTENT_TYPE_TERMINATE == intent.type)
    {
        srv_mre_close_app(data.path);
    }
    else if (VSRV_NINTENT_TYPE_LANGUAGE_CHANGED == intent.type)
    {
        WCHAR text[260]={0};
        U32 size;
        void* name;
        
        if (srv_mre_get_app_name(data.path ,NULL,&size))
        {
            name = _vm_kernel_malloc(size);
            if (!name)
            {
                MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"vm_ncenter_ongoing_cb error1!");
                return;
            }
            if (!srv_mre_get_app_name(data.path,(U16*)name,&size))
            {                
                MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"vm_ncenter_ongoing_cb error2!");
            }
        }
        
        kal_wstrcpy(text, (WCHAR*)GetString(STR_GLOBAL_EXIT));
        kal_wstrcat(text,L" ");
        kal_wstrcat(text,(WCHAR*) name);
        kal_wstrcat(text,L"?");
    
        vsrv_ncenter_set_notification_questiontext_str(handle, text);
        _vm_kernel_free(name);
        vsrv_ncenter_notify_notification(handle);
    }
    
    if (VSRV_NINTENT_TYPE_TERMINATE == intent.type || VSRV_NINTENT_TYPE_LAUNCH == intent.type )
    {
        vsrv_ncenter_close_notification(handle);
        if (data.img)
        {
            _vm_kernel_free(data.img);
            data.img = NULL;
        }
    }
}


S32 vm_ncenter_enter_bg_cb(S32 sender, U32 msg_id, S32 wparam, S32 lparam)
{
    vsrv_ngroup_handle group_hdl;
    vsrv_notification_handle noti_hdl;
    vm_ongoing_data data;
    mmi_image_src_struct imag;
    U32 size = 0;
    WCHAR* text=NULL,*name=NULL;
    mmi_app_package_char install_name[60]={0};
    
    if (VM_MSG_HIDE != msg_id)
    {
        return 0;
    }

    data.path = (U16*)wparam;
    data.img = NULL;
    group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_MRE);
    ASSERT(group_hdl != NULL);    

    vsrv_ncenter_set_ngroup_title_str(group_hdl,L"MRE");
    
    noti_hdl = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING,group_hdl,(vsrv_notification_id)wparam);
    ASSERT(noti_hdl != NULL);

    vsrv_ncenter_set_notification_autoclose(noti_hdl,MMI_FALSE,
                VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH|VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE);
    //get app name    
    if (srv_mre_get_app_name(data.path ,NULL,&size))
    {
        name = _vm_kernel_malloc(size);
        if (!name)
        {
            goto error;
        }
        if (!srv_mre_get_app_name(data.path,(U16*)name,&size))
        {                
            goto error;
        }
        vsrv_ncenter_set_notification_maintext_str(noti_hdl, (WCHAR*) name);
    }
    else
    {
        goto error;
    }
    
    
    text = _vm_kernel_malloc(size+30);
    if (!text)
    {
        goto error;
    }

    kal_wstrcpy(text, (WCHAR*)GetString(STR_GLOBAL_EXIT));
    kal_wstrcat(text,L" ");
    kal_wstrcat(text,(WCHAR*) name);
    kal_wstrcat(text,L"?");
    
    vsrv_ncenter_set_notification_questiontext_str(noti_hdl, text);
    
    _vm_kernel_free(name);
    _vm_kernel_free(text);
    
    size = 0;
     //get app icon    
    imag.type = MMI_IMAGE_SRC_TYPE_RES_ID;
    imag.data.res_id = IMAGE_MRE_LARGE_ICON;
    {
        U16 install_name_w[60]={0};
        srv_mre_appmgr_generate_identification((U16 *)wparam,install_name_w);
        mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8,(char *)install_name_w, (char *)install_name, MMI_APP_NAME_MAX_LEN);
    }
    if (srv_mre_appmgr_is_app_installed(install_name))
    {
        if (MMI_RET_OK != srv_mre_appmgr_get_app_image(install_name,&imag))
        {
            goto getMemImage;
        }
    }
    else
    {
getMemImage:    
        size = 0;
        if (srv_mre_get_app_image(data.path,NULL,&size))
        {
            U32 tag_size = 4;
            U8  tag_buf[4];
            
            memset(tag_buf, 0, 4);

            if (vm_get_vm_tag((PS16) data.path, VM_CE_INFO_ADV_ICON, &tag_buf, &tag_size) != GET_TAG_TRUE)
            {
                tag_buf[0] = 0;
            }
            
            data.img = _vm_kernel_malloc(size+8);
            if (data.img)
            {
                if (tag_buf[0] == 1)
                {
                    srv_mre_get_app_image(data.path,(U8*)data.img,&size);
                }
                else
                {
                    if (srv_mre_get_app_image(data.path,(U8*)data.img+8,&size))
                    {

                        S32 width = 0;
                        S32 height = 0;
                        U32 width_height;
                    
                        gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_GIF, (U8*)data.img+8, size, &width, &height);
                        //construct 8 bytes head
                        // set width and height.    
                        width_height  = ((width & 0XFFF) << 12) | (height & 0XFFF);	
                        // set frames
                        // construct 8 byte file header.
                        data.img[0] = GDI_IMAGE_TYPE_GIF;
                        data.img[1] = 1;
                        data.img[2] = size & 0xff;
                        data.img[3] = (size & 0xff00) >> 8;
                        data.img[4] = (size & 0xff0000) >> 16;
                        data.img[5] = (width_height & 0xff);
                        data.img[6] = (width_height & 0xff00) >> 8;
                        data.img[7] = (width_height & 0xff0000) >> 16;
                        //
                    }
                }
                imag.type = MMI_IMAGE_SRC_TYPE_MEM;
                imag.data.mem = data.img;
            }
        }
    }    
    
    vsrv_ncenter_set_notification_icon(noti_hdl,imag);
    
    vsrv_ncenter_set_notification_intent_callback(noti_hdl, vm_ncenter_ongoing_cb, (void *)&data, sizeof(data));
    vsrv_ncenter_notify_notification(noti_hdl);
    return 1;
        
error:
    if (name)
    {
        _vm_kernel_free(name);
    }
    if (text)
    {
        _vm_kernel_free(text);
    }
    vsrv_ncenter_close_notification(noti_hdl);
    return 2;
}


S32 vm_ncenter_exit_bg_cb(S32 sender, U32 msg_id, S32 wparam, S32 lparam)
{
    vsrv_ngroup_handle group_hdl;
    vm_ongoing_data data;  
    
    vsrv_notification_handle noti_hdl;

    if (VM_MSG_PAINT != msg_id && VM_MSG_QUIT != msg_id)
    {
        return 0;
    }
    
    group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,APP_MRE);
    ASSERT(group_hdl != NULL);  
    
    noti_hdl = vsrv_ncenter_query_notification(group_hdl,wparam);
    if (noti_hdl)
    {
        
        memcpy(&data,vsrv_ncenter_get_notification_userdata(noti_hdl),sizeof(data));
        if (data.img)
        {
            _vm_kernel_free(data.img);
            data.img = NULL;
        }
        vsrv_ncenter_close_notification(noti_hdl);
    }
    
    return 1;
}
#ifdef __MRE_SAL_PN__
typedef struct
{
    U32 app_id;
    U32 index;
}vm_ncenter_push_data;

static vm_ncenter_push_launch_cb(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
    if (SRV_MRE_LAUNCH_APP_ASM_READY == evt)
    {
        srv_mre_launch_app_result_enum result;
        result = srv_mre_launch_app_ex(app_path,vm_ncenter_push_launch_cb);  
        if (SRV_MRE_LAUNCH_APP_SYS_ASYN_ASM != result && SRV_MRE_LAUNCH_APP_SUCCESS != result)
        {
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_FAILURE,
            	                     (WCHAR*)GetString(STR_ID_LAUNCH_FAIL));
        }
    }
}

void vm_ncenter_push_cb(vsrv_notification_handle handle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    if (VSRV_NINTENT_TYPE_LAUNCH == intent.type)
    {
        mmi_ret ret;
        vm_ncenter_push_data data;
        srv_mre_appmgr_push_installed_info_struct readInfo;
		multiple_payload_internal_struct  payload;
		U32 custom_key_flag = 0;
        srv_mre_launch_app_result_enum result;
        int fd;
        
        memcpy(&data,userData,sizeof(data));
        ret = srv_mre_push_receiver_file_read(data.app_id,&readInfo,0);
        if(SRV_MRE_PUHS_TYPE_SUCCESS != ret)
    	{
    		MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"vm_ncenter_push_cb error!");
    		return;
    	}
    	vm_pmng_set_push_app_flag(data.index);
		memset(&payload,0,sizeof(multiple_payload_internal_struct));
	   ret = srv_mre_load_message_by_index(&payload,data.app_id,data.index);
	   //call aidan
	   custom_key_flag = srv_pns_has_custom_payload(payload.payload);
	   if(custom_key_flag==0)
	   {
			readInfo.click_rate.ncenter_launch_count ++;
	   }
	   else
	   {
		   readInfo.click_rate.ncenter_launch_has_custom_key_count ++;
	   }
		srv_mre_push_receiver_file_write(data.app_id, &readInfo,0);

        result = srv_mre_launch_app_ex(readInfo.app_path,vm_ncenter_push_launch_cb);  
        if (SRV_MRE_LAUNCH_APP_SYS_ASYN_ASM != result && SRV_MRE_LAUNCH_APP_SUCCESS != result)
        {
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_FAILURE,
            	                     (WCHAR*)GetString(STR_ID_LAUNCH_FAIL)); 
        }
    }
	else if (VSRV_NINTENT_TYPE_CLEAR == intent.type)
	{
		vm_ncenter_push_data data;
		memcpy(&data,userData,sizeof(data));
		srv_mre_clear_message_by_index(data.app_id,data.index);
	}
}

S32 vm_ncenter_push_new_message(U32 app_id, U32 unique_appid,U32 index) 
{
#ifdef __MMI_PNS__
    mmi_ret ret;
    U32 i=0;
	srv_pns_msg_mps_struct msg;
	srv_pns_result pns_ret  				 = SRV_PNS_NO_ERROR;
	srv_mre_appmgr_push_installed_info_struct readInfo;

	vsrv_ngroup_handle group_hdl;
	vsrv_notification_entry noti_entry;
    vsrv_notification_handle noti_hdl,first_noti,tmp_noti;
    CHAR  app_install_pacakge[MMI_APP_NAME_MAX_LEN]={0};
    WCHAR app_name[MMI_APP_NAME_MAX_LEN]={0};
    WCHAR strbuf[SRV_PNS_ALERT_TEXT_MAX_LEN];
    mmi_image_src_struct image;
    vm_ncenter_push_data data;
	multiple_payload_internal_struct  payload;

    data.app_id = app_id;
    data.index = index;
    
    memset(&readInfo,0,sizeof(srv_mre_appmgr_push_installed_info_struct));
	memset(&payload,0,sizeof(multiple_payload_internal_struct));
    ret = srv_mre_push_receiver_file_read(app_id,&readInfo,0);
	if(SRV_MRE_PUHS_TYPE_SUCCESS != ret)
	{
		ASSERT(0);
	}
	ret = srv_mre_load_message_by_index(&payload,app_id,index);
	memset(&msg,0,sizeof(msg));
    pns_ret = srv_pns_get_mps_info((char*)(payload.payload),(srv_pns_msg_mps_struct*)&msg);	
    if(SRV_PNS_NO_ERROR != pns_ret){
        ASSERT(0);
    }

    mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)readInfo.app_install_name,(char*)app_install_pacakge,SRV_PNS_ALERT_TEXT_MAX_LEN); 
    
    ret = srv_mre_appmgr_get_app_name(app_install_pacakge,app_name);
    ASSERT(ret == MMI_RET_OK);
    
    group_hdl = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE,unique_appid);
    ASSERT(group_hdl != NULL);  

    vsrv_ncenter_set_ngroup_title_str(group_hdl,app_name);


    noti_entry = vsrv_ncenter_get_notification_entry(group_hdl);
	if (noti_entry)
	{
		first_noti = vsrv_ncenter_get_notification(noti_entry);
		tmp_noti = first_noti;
		while (tmp_noti)
		{
			tmp_noti = vsrv_ncenter_get_next_notification(tmp_noti);
			i++;
		}

		if (i >= MRE_PUSH_MAX_PAYLOAD)
		{
			//reach max num!!
			vsrv_ncenter_close_notification(first_noti);
		}
	}
    noti_hdl = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT,group_hdl,index);
	 
	vsrv_ncenter_set_notification_autoclose(noti_hdl,MMI_FALSE,VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH);
    ret = srv_mre_appmgr_get_app_image(app_install_pacakge,&image);  
    ASSERT(ret == MMI_RET_OK);
    
    vsrv_ncenter_set_notification_icon(noti_hdl, image);

    if (msg.mainResId)
    {
        void* str_buff=NULL;
        U32 size = 0;
        if (SRV_MRE_APPMGR_APP_TYPE_ROM == srv_mre_appmgr_get_app_type(app_install_pacakge))
        {
            ASSERT(vm_res_get_string_and_size_from_rom(readInfo.app_path, msg.mainResId, &str_buff, &size));
        }
        else
        {
            if (vm_res_get_string_and_size_from_file(readInfo.app_path, msg.mainResId, NULL, &size))
            {
                str_buff = _vm_kernel_malloc(size);
                if (str_buff)
                {
                    vm_res_get_string_and_size_from_file(readInfo.app_path, msg.mainResId, str_buff, &size);
                    vsrv_ncenter_set_notification_maintext_str(noti_hdl,str_buff);
                    _vm_kernel_free(str_buff);
                }
                else
                {
                    MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"mainResId error 2!");
                }
            }
            else
            {
                MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"mainResId error 1!");
            }
        }        
    }
    else
    {
        mmi_chset_convert(MMI_CHSET_UTF8,MMI_CHSET_UCS2,(char*)msg.main,(char*)strbuf,100*2);        
        vsrv_ncenter_set_notification_maintext_str(noti_hdl,strbuf);
    }
    
    if (msg.hintResId)
    {
        void* str_buff=NULL;
        U32 size = 0;
        if (SRV_MRE_APPMGR_APP_TYPE_ROM == srv_mre_appmgr_get_app_type(app_install_pacakge))
        {
            ASSERT(vm_res_get_string_and_size_from_rom(readInfo.app_path, msg.hintResId, &str_buff, &size));
        }
        else
        {
            if (vm_res_get_string_and_size_from_file(readInfo.app_path, msg.hintResId, NULL, &size))
            {
                str_buff = _vm_kernel_malloc(size);
                if (str_buff)
                {
                    vm_res_get_string_and_size_from_file(readInfo.app_path, msg.hintResId, str_buff, &size);
                    vsrv_ncenter_set_notification_subtext_str(noti_hdl,str_buff);
                }
                else
                {
                    MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"hintResId error 2!");
                }
            }
            else
            {
                MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"hintResId error 1!");
            }
        }        
    }
    else
    {
        mmi_chset_convert(MMI_CHSET_UTF8,MMI_CHSET_UCS2,(char*)msg.hint,(char*)strbuf,100*2);
        vsrv_ncenter_set_notification_subtext_str(noti_hdl,strbuf);
    }
    
    vsrv_ncenter_set_notification_timestamp(noti_hdl,&(payload.receive_time));
    vsrv_ncenter_set_notification_intent_callback(noti_hdl, vm_ncenter_push_cb, &data, sizeof(data));
	vsrv_ncenter_notify_notification(noti_hdl);
    return 0;
#endif	
    return 1;    
}

S32 vm_ncenter_push_delete_message(U32 app_id, U32 index) 
{
    vsrv_ngroup_handle group_hdl;
    vsrv_notification_handle noti_hdl;
    srv_mre_appmgr_push_installed_info_struct readInfo;
	
    memset(&readInfo,0,sizeof(srv_mre_appmgr_push_installed_info_struct));	
    ASSERT(SRV_MRE_PUHS_TYPE_SUCCESS == srv_mre_push_receiver_file_read(app_id,&readInfo,0));
	
    group_hdl = vsrv_ncenter_query_ngroup(readInfo.app_unique_id);
    if (!group_hdl)
    {
        MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"vm_ncenter_push_delete_message error 1!");
        return -1;
    }
    noti_hdl = vsrv_ncenter_query_notification(group_hdl,index);
    if (!noti_hdl)
    {
        MMI_PRINT(MOD_MRE,TRACE_GROUP_1,"vm_ncenter_push_delete_message error 2!");
        return -2;
    }
    vsrv_ncenter_close_notification(noti_hdl);
}


#endif

#endif
void vm_ncenter_init()
{
#ifdef __MMI_NCENTER_SUPPORT__
    //ongoing 
    srv_mre_reg_msg_proc(0,(SRV_MRE_MSG_PROC)vm_ncenter_enter_bg_cb);
    srv_mre_reg_msg_proc(0,(SRV_MRE_MSG_PROC)vm_ncenter_exit_bg_cb);
#endif    
}

S32 vm_mre_bg_exit_proc(S32 sender, U32 msg_id, S32 wparam, S32 lparam)
{
#ifdef __COSMOS_MMI_PACKAGE__                
	if (VM_MSG_CONFIRM_EXIT == msg_id)
	{	
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
	                     MMI_EVENT_INFO_BALLOON,
	                     MMI_NMGR_BALLOON_TYPE_WARNING,
	                     (WCHAR*)GetString(STR_MRE_POPUP_CONFLICTS));
	}                     
	else if (VM_MSG_FORCE_FREE == msg_id)
	{	
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
	                     MMI_EVENT_INFO_BALLOON,
	                     MMI_NMGR_BALLOON_TYPE_WARNING,
	                     (WCHAR*)GetString(STR_MRE_POPUP_FORCE_FREE));	                     
	}
	else
	{}	
#else
	if (VM_MSG_CONFIRM_EXIT == msg_id)
	{	
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT,MMI_EVENT_WARNING,(WCHAR*)GetString(STR_MRE_POPUP_CONFLICTS));  
	}                     
	else if (VM_MSG_FORCE_FREE == msg_id)
	{	
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT,MMI_EVENT_WARNING,(WCHAR*)GetString(STR_MRE_POPUP_FORCE_FREE));  
	}
	else
	{}	

#endif    
		                     
	return 0;
}

void vm_mre_register_callback(void)
{
    //bg exit
    srv_mre_reg_msg_proc(0,(SRV_MRE_MSG_PROC)vm_mre_bg_exit_proc);
}

