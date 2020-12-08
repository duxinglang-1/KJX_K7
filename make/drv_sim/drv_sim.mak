# Define source file lists to SRC_LIST
SRC_LIST = MoDIS_VC9\drv_sim\src\w32_audio.c \
           MoDIS_VC9\drv_sim\src\w32_dummy_drv.c \
           MoDIS_VC9\drv_sim\src\w32_dummy_wndrv.c \
           MoDIS_VC9\drv_sim\src\w32_keys.c \
           MoDIS_VC9\drv_sim\src\w32_keys_dcl.c \
           MoDIS_VC9\drv_sim\src\w32_l1.c \
           MoDIS_VC9\drv_sim\src\w32_l4c.c \
           MoDIS_VC9\drv_sim\src\w32_uart.c \
           MoDIS_VC9\drv_sim\src\w32_uart_dcl.c \
           MoDIS_VC9\drv_sim\src\w32_memory_card.c

ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  SRC_LIST += MoDIS_VC9\drv_sim\src\w32_file_disk.c
endif

# If TCPIP_SUPPORT = NONE => Do not build modis_vc9\drv_sim\src\w32_socket.c
ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
  SRC_LIST += MoDIS_VC9\drv_sim\src\w32_socket.c \
              MoDIS_VC9\drv_sim\src\w32_abm.c
endif

#  Define include path lists to INC_DIR
INC_DIR = MoDIS_VC9\MoDIS \
          plutommi\Framework\GDI\GDIInc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          MoDIS_VC9\drv_sim\include \
          inet_ps\soc\include \
          drv\include \
          interface\hal\fmr

INC_DIR  += hal\peripheral\inc

ifneq ($(filter __GPS_SUPPORT__,$(strip $(MODULE_DEFS))),)
  SRC_LIST += MoDIS_VC9\drv_sim\src\w32_dummy_gpsdrv.c
  INC_DIR += gps\mnl\include
  INC_DIR += gps\bee\inc
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

