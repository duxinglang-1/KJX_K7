# Define source file lists to SRC_LIST
SRC_LIST = MoDIS_VC9\MoDIS\w32_av_lib.cpp \
           MoDIS_VC9\MoDIS\w32_dspl_layer.c \
           MoDIS_VC9\MoDIS\w32_winmain.c \
           MoDIS_VC9\MoDIS\w32_util.cpp

SRC_LIST += MoDIS_VC9\MoDIS\mtk_simulator.rc \
            MoDIS_VC9\MoDIS\resource.h \
            MoDIS_VC9\MoDIS\StdAfx.h \
            MoDIS_VC9\MoDIS\picture\bitmap23.bmp \
            MoDIS_VC9\MoDIS\picture\mtk.bmp \
            MoDIS_VC9\MoDIS\mtk_icon.ICO \
            MoDIS_VC9\MoDIS\mtk_simulator.ICO

#  Define include path lists to INC_DIR
INC_DIR = MoDIS_VC9\MoDIS \
					hal\display\wfd\inc\modis_lcd \
					hal\display \
					hal\display\common\include

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P

