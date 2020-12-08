#include "mmi_features.h"
#include "custresdef.h"
#include "vfx_sys_config.h"
<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_MMS_2__
<APP id = "VCUI_MMS" name = "STR_VCUI_MMS" type="venus">
#ifdef __MMI_MMS_USE_ASM__  
    #ifndef __MMI_MESSAGE_SLIM__
        <MEMORY heap = "300 * 1024" extra_base="base(SRV_MDI_VDOPLY_CIF) + SRV_MMS_MMA_ASM_MEM_POOL_SIZE" fg="fg(SRV_MDI_VDOPLY_CIF) + GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2" inc="MmsSrvGprot.h"/>
    #else
        <MEMORY heap = "300 * 1024" extra_base="0 + SRV_MMS_MMA_ASM_MEM_POOL_SIZE" fg="0" inc="MmsSrvGprot.h"/>
    #endif
#else
    #ifndef __MMI_MESSAGE_SLIM__
        <MEMORY heap = "300 * 1024" extra_base="base(SRV_MDI_VDOPLY_CIF)" fg="fg(SRV_MDI_VDOPLY_CIF) + GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2"
        #if defined(__COSMOS_3D_V10__)
            vrt_mem_factor="6"
        #endif
        />
    #else
        <MEMORY heap = "300 * 1024" extra_base="0" fg="0"
        #if defined(__COSMOS_3D_V10__)
            vrt_mem_factor="6"
        #endif
        />
    #endif
#endif /* __MMI_MMS_USE_ASM__ */
</APP>
#endif /* __MMI_MMS_2__ */