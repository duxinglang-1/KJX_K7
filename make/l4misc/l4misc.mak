# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(PS_FOLDER))\l4\uem\src\uem_proc_cmd.c \
           $(strip $(PS_FOLDER))\l4\uem\src\uem_proc_msg.c \
           $(strip $(PS_FOLDER))\l4\uem\src\uem_main.c \
           $(strip $(PS_FOLDER))\l4\uem\src\uem_msg_hdlr.c \
           $(strip $(PS_FOLDER))\l4\uem\src\uem_at_cmd.c \
           $(strip $(PS_FOLDER))\l4\uem\src\uem_utility.c \
           $(strip $(PS_FOLDER))\l4\uem\src\uem_gpio_ctrl.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_common.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_config.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_context.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_control_block.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_data_desc.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_data_entry_table.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_approve.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_delete.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_delete_ln.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_read.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_read_ln.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_sat.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_search.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_startup.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_startup_ln.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_write.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_handler_write_ln.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_ilm.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_main.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_name_num_index.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_nvram_access.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_pindex.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_sap.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_se.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_sim_access.c \
           $(strip $(PS_FOLDER))\l4\phb\src\phb_utils.c \
           $(strip $(PS_FOLDER))\l4\l4a\src\l4a_callback.c \
           $(strip $(PS_FOLDER))\l4\l4a\src\l4a_cmd.c

ifneq ($(filter __MOD_L4A__, $(strip $(MODULE_DEFS))),)
	SRC_LIST += $(strip $(PS_FOLDER))\l4\l4a\src\l4a_main.c
endif
 
#  Define include path lists to INC_DIR
INC_DIR = $(strip $(PS_FOLDER))\l4\csm \
          $(strip $(PS_FOLDER))\l4\csm\cc\include \
          $(strip $(PS_FOLDER))\l4\csm\ss\include \
          $(strip $(PS_FOLDER))\l4\include \
          $(strip $(PS_FOLDER))\l4\uem\include \
          $(strip $(PS_FOLDER))\l4\smu\include \
          $(strip $(PS_FOLDER))\l4\atci\include \
          $(strip $(PS_FOLDER))\l4\l4c\include\common \
          $(strip $(PS_FOLDER))\l4\l4c\include\proc \
          $(strip $(PS_FOLDER))\l4\phb\include \
          $(strip $(PS_FOLDER))\l4\smsal\include \
          $(strip $(PS_FOLDER))\l4\rac\include \
          $(strip $(PS_FOLDER))\l4\l4a\include \
          $(strip $(PS_FOLDER))\l4\tcm\include \
          $(strip $(PS_FOLDER))\interfaces\local_inc \
          nvram\include \
          applib\misc\include \
          interface\mmi \
          interface\meta \
          custom\atci\include \
          interface\hwdrv \
          hal\drv_def \
          hal\peripheral\inc \
          custom\common\hal_public
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = SMG_REL_97 \
            __MOD_UEM__ \
            UART_ENABLE \
            __MOD_CSM__ \
            __MOD_SMU__ \
            __MOD_NVRAM__ \
            __MOD_PHB__ \
            __MOD_SMSAL__ \
            __MOD_ATCI__ \
            __MOD_L4C__ \
            __SMS_PDU_MODE__ \
            __SMS_ME_STORAGE__ \
            MP3_SUPPORT \
            __EMS__ \
            SMS_SHOW_REPORT_IN_SIM \
            __UEM_DRV_KPDQUEUE__ \
            __CB_MMI_MASK__ \
            EMS_LITTLE_ENDIAN \
            EMS_MEM_MANAGEMENT \
            SAVE_MSG_TO_SAME_STORAGE \
            DATA_DOWNLOAD \
            __PHB_USIM_MULTI_ADN__
 
 
