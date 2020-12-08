# Define source file lists to SRC_LIST
SRC_LIST = hal\display\common\src\lcm_proxy.c \
           hal\display\common\src\owfimage.c \
           hal\display\common\src\owfnativestream.c \
           hal\display\lcd_if_manager\src\lcd_if_manager.c \
           hal\display\lcd_power_manager\src\lcd_power_mgr.c \
           hal\display\lcd_tear_manager\src\lcd_tear_manager.c \
           hal\display\wfc\src\wfc_autonomous.c \
           hal\display\wfc\src\wfcapi.c \
           hal\display\wfd\src\wfdapi.c \
           hal\display\common\src\lcd_em.c \
           hal\display\wfd\src\modis_lcd\wfd_lcd_modis.c \
           hal\display\wfd\src\modis_lcd\wfd_hwdevice_modis.c
           
SRC_LIST += hal\display\ddv1\src\modis_lcd\modis_lcd.c
           
# Define include path lists to INC_DIR
INC_DIR = drv\include \
          hal\storage\mc\inc \
          hal\peripheral\inc \
          hal\display \
          hal\display\ddv1\include \
          inc \
          sst\include \
          media\image\include \
          interface\hal \
          interface\hal\mm_comm \
          interface\hal\display \
          interface\hal\display\ddv1 \
          hal\display\common\include \
          hal\display\wfd\inc\modis_lcd \
          hal\display\wfd\inc \
          hal\display\lcd_tear_manager\inc \
          interface\hal\drv_sw_def \
          interface\hal\display\common \
          interface\hal\display\exception \
          hal\display \
          plutommi\Framework\GDI\GDIInc \
          plutommi\mtkapp\filemgr\filemgrinc \
          hal\mm_comm\inc \
          kal\include \
          hal\display\lcd_c_model\inc \
          interface\hal\display\ddv1 \
          interface\hwdrv \
          plutommi\Framework\GDI\GDIInc \
          btmt\rf_desense
          
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK
 
