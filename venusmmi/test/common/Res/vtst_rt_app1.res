#include "vfx_config.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "FW_TEST1" type="venus" name="STR_FW_TEST1">
#ifdef __VENUS_3D_UI_ENGINE__
    <MEMORY heap="500 * 1024" extra_base = "1400 * 1024"/>
#else
    <MEMORY base="10*1024 + base(FW_TEST4)" heap="10*1024" fg="15*1024 + fg(FW_TEST4)" vrt_mem_factor="0.0001"/>
#endif
    <APPCONCURRENT concurrent="FW_TEST1, FW_TEST3"/>
    <APPCONCURRENT concurrent="FW_TEST1, FW_TEST2"/>    
</APP>

