#ifndef __VCUI_CAMCO_GPROT_H__
#define __VCUI_CAMCO_GPROT_H__

#include "MMI_features_camcorder.h"
#include "vfx_uc_include.h"

#ifdef __MMI_CAMCORDER__

#ifdef __VAPP_CAMCO__
#include "mmi_rp_vcui_camco_def.h"
#endif
#include "mmi_rp_vcui_standard_camera_def.h"
#include "mmi_rp_vcui_standard_recorder_def.h"
#include "mmi_rp_vcui_slim_camera_def.h"

typedef enum
{
    VCUI_CAMCO_EVENT_RESULT_SUCCESS = VCUI_STANDARD_CAMERA,
    VCUI_CAMCO_EVENT_RESULT_FAILED,

    VCUI_CAMCO_EVENT_ALL
} vcui_camco_event_enum;

typedef enum
{
    VCUI_CAMCO_CAMERA,
    VCUI_CAMCO_RECORDER,
    VCUI_CAMCO_FULL,
    VCUI_CAMCO_END

}vcui_camcor_mode_enum;


typedef enum
{

    VCUI_CAMCO_SETTING_NONE,
    VCUI_CAMCO_SETTING_COMMON_ONLY,
    VCUI_CAMCO_SETTING_FULL,
    VCUI_CAMCO_SETTING_END

}vcui_camco_setting_level_enum;


typedef enum
{
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE,
    VCUI_CAMCO_SETTING_LIMIT_CAPMODE,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE,
    VCUI_CAMCO_SETTING_LIMIT_RECQTY,
    VCUI_CAMCO_SETTING_LIMIT_RECLIMIT,
    VCUI_CAMCO_SETTING_LIMIT_END

}vcui_camco_setting_limit_type_enum;


typedef enum
{
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_WALLPAPER,
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_HLCD,
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_VGA,
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_1MP,
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_2MP,
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_3MP,
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_4MP,
    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_5MP,

    VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_WP_ONLY,
    //...

    VCUI_CAMCO_SETTING_LIMIT_CAPMODE_NORMAL_ONLY,
    VCUI_CAMCO_SETTING_LIMIT_CAPMODE_ADDFRAME_ONLY,
    VCUI_CAMCO_SETTING_LIMIT_CAPMODE_NORMAL_ADDFRAME,

    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_WALLPAPER,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_SQCIF,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_QQVGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_QCIF,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_QVGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_CIF,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_WQVGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_CIF2,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_HVGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_NHD,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_VGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_4CIF,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_D1,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_D12,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_WVGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_SVGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_WVGA2,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_FWVGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_XGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_720P,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_4VGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_SXGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_16CIF,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_4SVGA,
    VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_FHD,
    //...

    VCUI_CAMCO_SETTING_LIMIT_RECLIMIT_SIZE,
    VCUI_CAMCO_SETTING_LIMIT_RECLIMIT_TIME,


    VCUI_CAMCO_SETTING_LIMIT_RECQTY_MMS_QTY,

	VCUI_CAMCO_SETTING_LIMIT_INFO_END

}vcui_camco_setting_limit_info_enum;

typedef enum
{
    VCUI_CAMCO_ERR_NONE,
    VCUI_CAMCO_ERR_IN_CALL,
    VCUI_CAMCO_ERR_NW_IN_USE,
    VCUI_CAMCO_ERR_USB_MODE,
    VCUI_CAMCO_ERR_MTV_RUNNING,
    VCUI_CAMCO_ERR_FAILED_TO_CAPTURE,
    VCUI_CAMCO_ERR_MISC,

    VCUI_CAMCO_ERR_END

}vcui_camco_err_code_enum;


typedef struct
{
    vcui_camco_setting_limit_type_enum  type;
    vcui_camco_setting_limit_info_enum  detail;
    VfxU32                              additionalInfo;
    //======================================================
    // for additionalInfo cinfig
    //  if you config rec size limit
    //     please use  size in  KB.
    //  if you config rec time limit
    //     please use  time in  sec.
    //======================================================

}vcui_camco_setting_limit_struct;

typedef struct
{
    vcui_camcor_mode_enum               mode;                   // camera only /recorder only / both
    vcui_camco_setting_level_enum       level;                  // usable setting item level
    VfxU32                              settingLimitNum;        // limited setting number
    vcui_camco_setting_limit_struct    *settingLimitation;      // limited setting

} vcui_camco_param_struct;


typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    WCHAR* filePath;
    vcui_camco_err_code_enum errCode;

} vcui_camco_event_struct;

#ifndef __VAPP_CAMCO_EXPRESS__
extern void vcui_camcorder_struct_init(vcui_camco_param_struct *param);

extern mmi_id vcui_camcorder_create(mmi_id parent_gid, vcui_camco_param_struct *param);

extern void vcui_camcorder_run(mmi_id cui_gid);

extern void vcui_camcorder_close(mmi_id cui_gid);

extern vcui_camco_err_code_enum vcui_camcorder_launchable_check(void);

extern MMI_ID vcui_camcorder_get_err_string(vcui_camco_err_code_enum errCode);
#endif

extern void vcui_standard_camera_struct_init(vcui_camco_param_struct *param);

extern mmi_id vcui_standard_camera_create(mmi_id parent_gid, vcui_camco_param_struct *param);

extern void vcui_standard_camera_run(mmi_id cui_gid);

extern void vcui_standard_camera_close(mmi_id cui_gid);

extern vcui_camco_err_code_enum vcui_standard_camera_launchable_check(void);

extern MMI_ID vcui_standard_camera_get_err_string(vcui_camco_err_code_enum errCode);

extern void vcui_standard_recorder_struct_init(vcui_camco_param_struct *param);

extern void vcui_standard_recorder_recsize(VfxU32 limit);

extern mmi_id vcui_standard_recorder_create(mmi_id parent_gid, vcui_camco_param_struct *param);

extern void vcui_standard_recorder_run(mmi_id cui_gid);

extern void vcui_standard_recorder_close(mmi_id cui_gid);

extern vcui_camco_err_code_enum vcui_standard_recorder_launchable_check(void);

extern MMI_ID vcui_standard_recorder_get_err_string(vcui_camco_err_code_enum errCode);

extern void vcui_slim_camera_struct_init(vcui_camco_param_struct *param);

extern mmi_id vcui_slim_camera_create(mmi_id parent_gid, vcui_camco_param_struct *param);

extern void vcui_slim_camera_run(mmi_id cui_gid);

extern void vcui_slim_camera_close(mmi_id cui_gid);

extern vcui_camco_err_code_enum vcui_slim_camera_launchable_check(void);

extern MMI_ID vcui_slim_camera_get_err_string(vcui_camco_err_code_enum errCode);

#endif
#endif
