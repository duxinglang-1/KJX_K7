#######################################################################################
# Define source file lists to                                                         #
#######################################################################################
SRC_LIST = custom\drv\gsensor_sensor\yamaha\gsensor_sensor_I2C.c \
                   custom\drv\gsensor_sensor\yamaha\yas_acc_driver-mma8452q.c \
                   custom\drv\gsensor_sensor\yamaha\yas_simple.c \
                   custom\drv\gsensor_sensor\yamaha\yas_acc_calibration.c\
                   custom\drv\gsensor_sensor\yamaha\yas_acc_driver.c\
                   custom\drv\gsensor_sensor\yamaha\yas_utility.c\
                   custom\drv\gsensor_sensor\yamaha\sensor.c 

                   
#######################################################################################
#Define include path lists to                                                         #
#######################################################################################

INC_DIR = drv\include \
          hal\storage\mc\inc \
          hal\peripheral\inc \
          hal\display \
          hal\display\ddv1\include\lcd_c_model \
          hal\display\ddv1\include \
          inc \
          sst\include \
          media\image\include \
          interface\hal \
          interface\hal\mm_comm \
          interface\hal\display \
          interface\hal\display\ddv1 \
          hal\display\common\include \
          interface\hal\drv_sw_def \
          interface\hal\display\common \
          interface\hal\display\lcm_if \
          interface\hal\display\exception \
          hal\display \
          hal\display\flatten\inc \
          interface\hal\display\flatten \
          plutommi\Framework\GDI\GDIInc \
          plutommi\mtkapp\filemgr\filemgrinc \
          hal\mm_comm\inc \
          slc\inc \
          custom\drv\gsensor_sensor\yamaha
#######################################################################################
#   Define the specified compile options to                                         #
######################################################################################
COMP_DEFS = MMI_ON_HARDWARE_P 

#######################################################################################
#    Define the source file search paths to                                          #
#######################################################################################
SRC_PATH = custom\drv\gsensor_sensor\yamaha