#ifndef __VAPP_CAMCO_H_
#define __VAPP_CAMCO_H_

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

#ifdef __VAPP_CAMCO__

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

#if defined(__MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__) || defined(__MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__)
#define CAMCO_CAM_MULTISHOT_BUFFER_SIZE         (MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE + MMI_CAMCO_CAM_CACHE_IMAGE_SIZE * MMI_CAMCO_CAM_CACHE_IMAGE_COUNT)
#elif defined(__MMI_CAMCO_FEATURE_CAM_BESTSHOT__) 
#define CAMCO_CAM_MULTISHOT_BUFFER_SIZE         (MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE)
#else 
#define CAMCO_CAM_MULTISHOT_BUFFER_SIZE         (0)
#endif 

#define CAMCO_OSD_BYTE_PER_PIXEL                (GDI_MAINLCD_BIT_PER_PIXEL >> 3)

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
#define CAMCO_OSD_OVERLAY_PALETTE_SIZE          (256*4)
#else
#define CAMCO_OSD_OVERLAY_PALETTE_SIZE          (0)
#endif

// one for video frame and two for quick view
// quick view buffer:
//       burst shot ==> switch captured pciture buffer
//       add frame  ==> overlay buffer when capture 
#define CAMCO_PREVIEW_LAYER_SIZE                (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL * 3)  


#define MMI_CAMCO_APP_MEM_SIZE  (CAMCO_CAM_MULTISHOT_BUFFER_SIZE + CAMCO_PREVIEW_LAYER_SIZE + CAMCO_OSD_OVERLAY_PALETTE_SIZE)
#define MMI_CAMCO_SCR_MEM_SIZE  0


/***************************************************************************** 
* Extern callback (others APP should not use these)
*****************************************************************************/
extern mmi_ret storageChangeNotifyHdlr(mmi_event_struct *evt);
extern void mmi_camco_init_app(void);
extern mmi_ret vapp_camco_pre_key_hdlr(mmi_event_struct *event);
extern mmi_id vapp_camco_launch_app(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include "vfx_mc_include.h"

extern void vapp_camco_cam_get_max_capture_resolution(VfxS32 *width_p, VfxS32 *height_p);
extern VfxU32 vapp_camco_rec_get_min_external_request_size(void);
extern VfxU16 vapp_camco_setting_get_banding(void);
extern VfxU16 vapp_camco_get_storage(void);

#endif

#endif /* __MMI_CAMCORDER__ */ 

#endif /* __VAPP_CAMCO_H_ */ 

