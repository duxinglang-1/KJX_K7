#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VCUI_VIDEOCLIPPER" name="STR_CUI_VIDEOCLIPPER" type="venus">
    <MEMORY heap="1024*300" extra_base="base(SRV_MDI_VDOCLIP)" fg ="fg(SRV_MDI_VDOCLIP)+total(SRV_MDI_VDOPLY)+GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2"
        #ifdef __COSMOS_3D_V10__
        vrt_mem_factor="2.0f"
        #endif
    />
</APP>

