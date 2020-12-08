#ifndef __VAPP_AUTOCAP_H_
#define __VAPP_AUTOCAP_H_

#include "MMI_features.h"
#include "MMI_features_camcorder.h"

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))
/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_features.h"
#include "MMI_features_camcorder.h"
#include "gdi_include.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Extern Global interface
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

#define AUTOCAP_CAM_MULTISHOT_BUFFER_SIZE         (MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_MEM_SIZE)

#define AUTOCAP_OSD_BYTE_PER_PIXEL                (GDI_MAINLCD_BIT_PER_PIXEL >> 3)


#define AUTOCAP_PREVIEW_LAYER_SIZE                (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * AUTOCAP_OSD_BYTE_PER_PIXEL)  


#define MMI_AUTOCAP_APP_MEM_SIZE  (AUTOCAP_CAM_MULTISHOT_BUFFER_SIZE + AUTOCAP_PREVIEW_LAYER_SIZE + MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_CLIP_MEM_SIZE)
#define MMI_AUTOCAP_SCR_MEM_SIZE  0

#define MMI_AUTOCAP_MAV_APP_MEM_SIZE (AUTOCAP_PREVIEW_LAYER_SIZE)

typedef struct
{
    kal_bool               isMultiAngleViewMode;
    kal_bool               is3DCameraMode;

}vapp_autocap_param_struct;


/***************************************************************************** 
* Extern callback (others APP should not use these)
*****************************************************************************/
//extern mmi_ret storageChangeNotifyHdlr(mmi_event_struct *evt);
extern void mmi_autocap_init_app(void);

extern mmi_id vapp_autocap_launch_app(void);
extern mmi_id vapp_3d_camera_launch_app(void);

#ifdef __cplusplus
}
#endif

#endif /* #if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__)) */

#endif /* __VAPP_CAMCO_H_ */ 

