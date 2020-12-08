#ifndef __BACKUP_RESTORE_SRV_IPROT_H__
#define __BACKUP_RESTORE_SRV_IPROT_H__

#include "CloudSrvGprot.h"

extern void srv_cloud_close_done(srv_cloud_type_enum type);

extern MMI_BOOL srv_cloud_is_uid_exist(U16 * index, srv_cloud_uid_struct *uid, 
                                     srv_cloud_type_enum type);
#ifdef __SMS_CLOUD_SUPPORT__ 
extern S32 srv_cloud_store_server_sms_uid(srv_cloud_uid_struct *uid);
#endif
extern S32 srv_cloud_set_backup_flag( U16 index, MMI_BOOL flag, srv_cloud_type_enum type);

extern void srv_cloud_post_error_evt(srv_cloud_type_enum type, srv_cloud_error_type_enum error_code);

extern void srv_cloud_post_close_done(srv_cloud_type_enum type);

extern void srv_cloud_post_get_data_ind(MMI_BOOL flag, srv_cloud_type_enum type);

extern void srv_cloud_post_backup_begin_evt(srv_cloud_type_enum type);

#endif /* __BACKUP_RESTORE_SRV_IPROT_H__ */