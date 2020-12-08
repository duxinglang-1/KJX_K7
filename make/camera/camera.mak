# Define source file lists to SRC_LIST
ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
SRC_LIST = hal\camera\cal\src\cal_main.c \
           hal\camera\cal\src\cal_task_main.c \
           hal\camera\cal\src\cal_low_task_main.c \
           hal\camera\cal\src\cal_high_task_main.c \
           hal\camera\cal\src\cal_cb.c \
           hal\camera\cal\src\cal_feature_ctrl.c \
           hal\camera\cal\src\cal_cct_feature_ctrl.c \
           hal\camera\cal\src\cal_camera_nvram.c \
           hal\camera\cal\src\cal_scenario_ctrl.c \
           hal\camera\cal\src\cal_webcam.c \
           hal\camera\cal\src\cal_profiling.c \
           hal\camera\isp\src\isp_main.c \
           hal\camera\isp\src\isp_webcam.c \
           hal\camera\isp\src\isp_feature.c \
           hal\camera\isp\src\isp_comm_if.c \
           hal\camera\isp\src\isp_control.c \
           hal\camera\isp\src\isp_driver_if.c \
           hal\camera\isp\src\isp_isr.c \
           hal\camera\mdp_cam_if\src\idp_cam_if.c
endif

ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
SRC_LIST = hal\camera\cal\src\cal_main.c
endif

#  Define include path lists to INC_DIR
INC_DIR = hal\camera\cal\inc \
          hal\camera\isp\inc \
          hal\camera\mdp_cam_if\inc \
          hal\mdp\include \
          hal\video \
          hal\postproc\postproc_if\inc \
          hal\postproc\face_detect\inc \
          hal\postproc\smile_detect\inc \
          hal\postproc\panorama\inc \
          hal\postproc\hdr\inc \
          hal\graphics\jpeg\encode\common\inc \
          hal\graphics\jpeg\decode\common\inc \
          hal\graphics\jpeg\common\inc \
          hal\graphics\jpeg\exif\inc \
          hal\graphics\jpeg\jaia\inc \
          hal\graphics\g2d\common\inc \
          hal\mm_comm\inc \
          hal\connectivity\usb_driver\inc \
          hal\display \
          interface\hal\camera \
          interface\hal\postproc \
          interface\hal\graphics \
          interface\hal\mdp \
          interface\hal\display\ddv1 \
          interface\hal\connectivity\usb_driver \
          hal\display\common\include \
          btmt\rf_desense \
          hal\system\dcmgr\inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


