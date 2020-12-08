#ifndef __VAPP_CAMCO_EXPRESS_GPROT_H_
#define __VAPP_CAMCO_EXPRESS_GPROT_H_

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

#ifndef __VAPP_CAMCO__

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

#define CAMCO_OSD_BYTE_PER_PIXEL                (GDI_MAINLCD_BIT_PER_PIXEL >> 3)

// one for video frame and one for quick view
// quick view buffer:
//       file list buffer
//       video thumbnail buffer
//       rotate buffer (if with motion sensor)
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
#define CAMCO_PREVIEW_LAYER_SIZE                (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL * 2)
#else
#if (SRV_FMGR_FOLDER_FILELIST_MEM_SIZE > 10*1024)
#define CAMCO_PREVIEW_LAYER_SIZE                (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL +  SRV_FMGR_FOLDER_FILELIST_MEM_SIZE)
#else
#define CAMCO_PREVIEW_LAYER_SIZE                (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL +  10*1024)
#endif
#endif

#define MMI_CAMCO_APP_MEM_SIZE  (CAMCO_PREVIEW_LAYER_SIZE)
#define MMI_CAMCO_SCR_MEM_SIZE  0

// 0 mean 50Hz , 1 mean 60Hz
// customer can config that for different product
// define in vapp_camco_express_app.cpp
extern const U8 g_vapp_camco_banding_setting;

/*****************************************************************************
* Extern callback (others APP should not use these)
*****************************************************************************/
extern mmi_ret storageChangeNotifyHdlr(mmi_event_struct *evt);
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

#endif

#endif /* __MMI_CAMCORDER__ */

#endif /* __VAPP_CAMCO_H_ */

