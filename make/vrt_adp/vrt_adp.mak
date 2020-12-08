# Define source file lists to SRC_LIST
ifneq ($(filter __ARM9_MMU__ __ARM11_MMU__, $(strip $(MODULE_DEFS))),)
CFLAGS += --forceinline
CPLUSFLAGS += --forceinline
endif
SRC_LIST = venusmmi\vrt\adp\vrt_system.c \
           venusmmi\vrt\adp\vrt_trace.c
 
# Define include path lists to INC_DIR
INC_DIR = plutommi\Framework\DebugLevels\debuglevelinc \
          plutommi\Framework\CommonFiles\commoninc \
          plutommi\Framework\Tasks\tasksinc \
          plutommi\Framework\History\historyInc \
          plutommi\Framework\EventHandling\EventsInc \
          plutommi\Framework\MemManager\MemManagerInc \
          plutommi\Framework\NVRAMManager\NVRAMManagerInc \
          plutommi\Framework\ThemeManager\ThemeManagerInc \
          plutommi\Framework\CommonScreens\CommonScreensInc \
          plutommi\MMI\DateTime\DateTimeInc \
          plutommi\Framework\GUI\gui_inc \
          plutommi\Framework\GUI\oem_inc \
          plutommi\MMI\IdleScreen\IdleScreenInc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi\mmi\inc\MenuID \
          plutommi\Framework\InputMethod\Inc \
          plutommi\mmi\miscframework\miscframeworkinc \
          fs\fat\include \
          plutommi\MtkApp\Camera\CameraInc \
          plutommi\MtkApp\Video\VideoInc \
          plutommi\Framework\GDI\GDIInc \
          drm\include \
          applib\misc\include \
          venusmmi\vrt\interface \
          venusmmi\vrt\adp
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK
 
 
