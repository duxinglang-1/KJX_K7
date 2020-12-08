# 1 "temp/res/MDI_Mem.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/MDI_Mem.c"
# 248 "temp/res/MDI_Mem.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 249 "temp/res/MDI_Mem.c" 2

<?xml version="1.0" encoding="UTF-8"?>


<!----------------------------------------------------------------------------------------
******** MDI_AUDIO
------------------------------------------------------------------------------------------>
<APP id="SRV_MDI_AUDPLY" name="STR_MDI_AUDPLY">
    <MEMORY base="MED_AUD_PLY_BASE_MEM" fg="MED_AUD_PLY_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_AUD_INFO" name="STR_MDI_AUD_INFO">
    <MEMORY base="MED_AUD_INFO_BASE_MEM" fg="MED_AUD_INFO_FG_MEM" inc="med_global.h"/>
</APP>


<!----------------------------------------------------------------------------------------
******** MDI_VIDEO
------------------------------------------------------------------------------------------>


<APP id="SRV_MDI_VDOPLY" name="STR_MDI_VDOPLY">
    <MEMORY base="MED_VDOPLY_BASE_MEM" fg="MED_VDOPLY_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_V" name="STR_MDI_VDOPLY_V">
    <MEMORY base="MED_VDOPLY_V_BASE_MEM" fg="MED_VDOPLY_V_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_A" name="STR_MDI_VDOPLY_A" >
    <MEMORY base="MED_VDOPLY_A_BASE_MEM" fg="MED_VDOPLY_A_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_QVGA" name="STR_MDI_VDOPLY_QVGA" >
    <MEMORY base="MED_VDOPLY_QVGA_BASE_MEM" fg="MED_VDOPLY_QVGA_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_CIF" name="STR_MDI_VDOPLY_CIF" >
    <MEMORY base="MED_VDOPLY_CIF_BASE_MEM" fg="MED_VDOPLY_CIF_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_PREVIEW" name="STR_MDI_VDOPLY_PREVIEW" >
    <MEMORY base="MED_VDOPLY_PREVIEW_BASE_MEM" fg="MED_VDOPLY_PREVIEW_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_INFO" name="STR_MDI_VDOPLY_INFO" >
    <MEMORY base="MED_VDOPLY_INFO_BASE_MEM" fg="MED_VDOPLY_INFO_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_MP4" name="STR_MDI_VDOPLY_MP4" >
    <MEMORY base="MED_VDOPLY_MP4_BASE_MEM" fg="MED_VDOPLY_MP4_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_SUBTITLE" name="STR_MDI_VDOPLY_SUBTITLE" >
    <MEMORY base="MED_VDOPLY_SUBTITLE_BASE_MEM" fg="MED_VDOPLY_SUBTITLE_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_QVGA_MPEG4SP" name="STR_MDI_VDOPLY_QVGA_MPEG4SP" >
    <MEMORY base="MED_VDOPLY_QVGA_MPEG4SP_BASE_MEM" fg="MED_VDOPLY_QVGA_MPEG4SP_FG_MEM" inc="med_global.h"/>
</APP>



<!----------------------------------------------------------------------------------------
******** MDI_VIDEO_STREAMING
------------------------------------------------------------------------------------------>
# 331 "temp/res/MDI_Mem.c"
<!----------------------------------------------------------------------------------------
******** MDI_CAMERA
------------------------------------------------------------------------------------------>


<APP id="SRV_MDI_CAMERA_STANDARD" name="STR_MDI_CAMERA_STANDARD">
    <MEMORY base="max(MAX_MED_CAM_CAP_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_FULL" name="STR_MDI_CAMERA_FULL">
    <MEMORY base="max(max(max(max(MAX_MED_CAM_CAP_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE) + MED_CAM_BG_STITCH_EXT_MEM_SIZE,MED_CAM_PANORAMA_STITCH_SIZE), MAX_CAM_HDR_EXT_MEM_SIZE), MAX_CAM_MAV_WORKING_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_ONLY_CAP_LCD" name="STR_MDI_CAMERA_ONLY_CAP_LCD">
    <MEMORY base="max(MAX_MED_CAM_CAP_LCD_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_ONLY_CAP_LCD_DISABLE_JAIA" name="STR_MDI_CAMERA_ONLY_CAP_LCD_DISABLE_JAIA">
    <MEMORY base="max(MIN_CAM_CAPTURE_LCD_ISP_BUF_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_CAP_VGA_BELOW" name="STR_MDI_CAMERA_CAP_VGA_BELOW">
    <MEMORY base="max(MAX_MED_CAM_CAP_VGA_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_AUTORAMA" name="STR_MDI_CAMERA_AUTORAMA">
    <MEMORY base="max(MAX_CAM_PREVIEW_EXT_MEM_SIZE + MED_CAM_BG_STITCH_EXT_MEM_SIZE,MED_CAM_PANORAMA_STITCH_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_CAP_HDR" name="STR_MDI_CAMERA_CAP_HDR">
    <MEMORY base="max(max(MAX_MED_CAM_CAP_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE), MAX_CAM_HDR_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_CAP_MAV" name="STR_MDI_CAMERA_CAP_MAV">
    <MEMORY base="max(MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE, MAX_CAM_MAV_WORKING_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>


<!----------------------------------------------------------------------------------------
******** MDI_WEBCAM
------------------------------------------------------------------------------------------>







<!----------------------------------------------------------------------------------------
******** MDI_VT
------------------------------------------------------------------------------------------>






<!----------------------------------------------------------------------------------------
******** MDI_VIDEO_RECORDER
------------------------------------------------------------------------------------------>
# 402 "temp/res/MDI_Mem.c"
<!----------------------------------------------------------------------------------------
******** MDI_ATV
------------------------------------------------------------------------------------------>
