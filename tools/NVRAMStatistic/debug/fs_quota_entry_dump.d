../debug/fs_quota_entry_dump.o: fs_quota_entry_dump.c \
  ../../../custom/common/hal/flash_opt.h \
  ../../../custom/system/HEXING60A_11B_BB/custom_MemoryDevice.h \
  ../../../custom/system/HEXING60A_11B_BB/custom_FeatureConfig.h \
  ../../../interface/hal/peripheral/kbd_table.h \
  ../../../hal/system/bootloader/inc/bl_custom.h \
  ../../../kal/include/kal_general_types.h ../../../kal/include/clib.h \
  ../../../kal/include/clib_list.h \
  ../../../interface/hal/peripheral/dcl.h \
  ../../../interface/hal/peripheral/dcl_gpt.h \
  ../../../kal/include/kal_non_specific_general_types.h \
  ../../../kal/include/kal_release.h \
  ../../../kal/include/kal_public_defs.h \
  ../../../config/include/hal/stack_config.h \
  ../../../interface/hal/drv_sw_def/drv_sw_features_g2d.h \
  ../../../hal/drv_def/drv_features_g2d.h \
  ../../../hal/drv_def/drv_features_chip_select.h \
  ../../../hal/drv_def/drv_features_6260.h \
  ../../../hal/drv_def/drv_features_mdp.h \
  ../../../custom/common/hal_public/lcd_sw_inc.h \
  ../../../custom/drv/LCD/HEXING60A_11B_LCM/lcd_hw.h \
  ../../../custom/drv/Camera_common/sensor_capability.h \
  ../../../interface/hal/drv_sw_def/drv_sw_features_gif.h \
  ../../../hal/drv_def/drv_features_gif.h \
  ../../../interface/hal/drv_sw_def/drv_sw_features_jpeg.h \
  ../../../hal/drv_def/drv_features_jpeg.h \
  ../../../interface/hal/drv_sw_def/drv_sw_features_mmsysmisc.h \
  ../../../hal/drv_def/drv_features_mmsysmisc.h \
  ../../../interface/hal/drv_sw_def/drv_sw_features_kbd.h \
  ../../../hal/drv_def/drv_features_kbd.h \
  ../../../custom/codegen/HEXING60A_11B_BB/keypad_drv.h \
  ../../../interface/hal/drv_sw_def/drv_sw_features_png.h \
  ../../../hal/drv_def/drv_features_png.h \
  ../../../interface/hal/drv_sw_def/drv_sw_features_opengles.h \
  ../../../hal/drv_def/drv_features_opengles.h \
  ../../../config/include/hal/hal_task_config.h \
  ../../../config/include/app/app_task_config.h \
  ../../../config/include/hal/hisr_config_internal.h \
  ../../../config/include/hal/stack_msgs.h \
  ../../../config/include/hal/user_msgid_hal.h \
  ../../../config/include/app/user_msgid_app.h \
  ../../../ps/interfaces/sap/dt_sap.h ../../../ps/interfaces/sap/mm_sap.h \
  ../../../ps/interfaces/sap/cc_sap.h \
  ../../../ps/interfaces/sap/ciss_sap.h \
  ../../../ps/interfaces/sap/sms_sap.h \
  ../../../interface/ps/sap/sim_public_sap.h \
  ../../../ps/interfaces/sap/sim_ps_sap.h \
  ../../../interface/ps/sap/ps_public_l4_sap.h \
  ../../../ps/interfaces/sap/l4_sap.h \
  ../../../ps/l4/l4c/include/common/l4c_msg_hdlr_defs.h \
  ../../../ps/interfaces/sap/rr_sap.h \
  ../../../ps/interfaces/sap/llc_sap.h \
  ../../../ps/interfaces/sap/sndcp_sap.h \
  ../../../ps/interfaces/sap/sm_sap.h \
  ../../../ps/interfaces/sap/data_sap.h \
  ../../../interface/middleware/irda_sap.h \
  ../../../interface/middleware/ircomm_sap.h \
  ../../../interface/nvram/nvram_sap.h \
  ../../../interface/l1interface/sap/l1_sap.h \
  ../../../interface/hal/L1/hal_l1_sap.h \
  ../../../interface/l1interface/sap/l1hisr_sap.h \
  ../../../interface/l1interface/sap/ft_sap.h \
  ../../../tst/include/tstsap.h ../../../interface/os/sysservice_sap.h \
  ../../../interface/hal/video/vsrc_sap.h \
  ../../../interface/middleware/mexe_sap.h \
  ../../../interface/hal/audio/l1audio_sph_srv_sap.h \
  ../../../fmr/inc/fmr_sap.h ../../../ps/interfaces/sap/ratcm_sap.h \
  ../../../ps/interfaces/sap/ratdm_sap.h \
  ../../../ps/interfaces/sap/ndis_sap.h \
  ../../../ps/interfaces/sap/cmux_sap.h \
  ../../../ps/interfaces/sap/ppp_sap.h ../../../interface/gps/gps_sap.h \
  ../../../interface/gps/mnl_sap.h ../../../interface/nfc/nfc_sap.h \
  ../../../interface/nfc/nfc_reader_sap.h \
  ../../../interface/nfc/nfc_app_sap.h \
  ../../../interface/hal/camera/cal_sap.h \
  ../../../ps/interfaces/sap/ext_modem_sap.h \
  ../../../interface/wifi/wndrv_sap.h ../../../interface/wmt/wmt_sap.h \
  ../../../interface/inet_ps/xdm_sap.h ../../../interface/wifi/supc_sap.h \
  ../../../interface/inet_ps/saf_sap.h \
  ../../../interface/ps/sap/mmi_sap.h ../../../interface/ps/sap/abm_sap.h \
  ../../../interface/ps/sap/soc_sap.h \
  ../../../interface/ps/sap/tcpip_sap.h \
  ../../../ps/interfaces/sap/em_sap.h \
  ../../../interface/inet_ps/email_sap.h \
  ../../../interface/inet_ps/imps_sap.h \
  ../../../interface/inet_ps/sip_sap.h \
  ../../../interface/bt/bluetooth_sap.h \
  ../../../interface/ps/sap/dhcp_sap.h \
  ../../../interface/inet_ps/iperf_sap.h \
  ../../../interface/inet_ps/syncml_sap.h \
  ../../../interface/inet_ps/rtsp_sap.h \
  ../../../interface/inet_ps/dm_sap.h ../../../interface/mmi/drmt_sap.h \
  ../../../interface/inet_ps/emlst_sap.h \
  ../../../interface/inet_ps/dhcpd_sap.h ../../../interface/fs/fs_sap.h \
  ../../../interface/media/hal/med_hal_sap.h \
  ../../../interface/l1interface/sap/l1_ext_sap.h \
  ../../../interface/inet_ps/cardav_sap.h \
  ../../../interface/mmi/mmiapi_sap.h ../../../interface/mmi/mmi_um_sap.h \
  ../../../interface/wap/wap_sap.h ../../../interface/wap/wap_adp_sap.h \
  ../../../interface/wap/browser_sap.h \
  ../../../interface/wap/profile_sap.h ../../../interface/wap/ua_sap.h \
  ../../../interface/wap/wps_sap.h ../../../interface/wap/das_sap.h \
  ../../../interface/wap/mmc_sap.h ../../../interface/wap/mma_sap.h \
  ../../../interface/wap/mms_adp_sap.h ../../../interface/wap/bam_sap.h \
  ../../../interface/wap/pmg_sap.h ../../../interface/wap/mms_sap.h \
  ../../../interface/wap/q03c_mms_v01_adp_sap.h \
  ../../../j2me/interface/j2me_sap.h ../../../interface/misc_ps/udx_sap.h \
  ../../../interface/media/med_sap.h \
  ../../../interface/hal/video/mpl_sap.h \
  ../../../interface/media/med_v_sap.h \
  ../../../interface/misc_ps/obex_sap.h \
  ../../../interface/hal/video/vcodec_sap.h \
  ../../../interface/hal/peripheral/drv_sap.h \
  ../../../interface/hal/video/vcodec_v2_sap.h \
  ../../../interface/hal/video/vfile_sap.h \
  ../../../interface/mmi/fmt_sap.h ../../../mre/commoninc/mre_sap.h \
  ../../../interface/media/med_gps.h ../../../interface/media/med_rfid.h \
  ../../../interface/media/med_rfid_eint.h \
  ../../../kal/include/kal_public_api.h \
  ../../../interface/hal/peripheral/dcl_gpio.h \
  ../../../interface/hal/peripheral/dcl_uart.h \
  ../../../custom/common/hal_public/bt_common_config.h \
  ../../../interface/hal/peripheral/dcl_wdt.h \
  ../../../interface/hal/peripheral/dcl_adc.h \
  ../../../interface/hal/peripheral/dcl_bmt.h \
  ../../../interface/hal/peripheral/dcl_pfc.h \
  ../../../interface/hal/peripheral/dcl_rtc.h \
  ../../../interface/hal/peripheral/dcl_i2c.h \
  ../../../interface/hal/peripheral/dcl_i2c_owner.h \
  ../../../interface/hal/peripheral/dcl_aux.h \
  ../../../interface/hal/peripheral/dcl_pwm.h \
  ../../../interface/hal/peripheral/dclH_kbd.h \
  ../../../interface/hal/peripheral/dclS_kbd.h \
  ../../../interface/hal/peripheral/dcl_sts.h \
  ../../../kal/include/Kal_public_defs.h \
  ../../../interface/hal/peripheral/dcl_msdc.h \
  ../../../interface/hal/connectivity/usb_driver/dcl_usb_drv.h \
  ../../../interface/hal/connectivity/usb_driver/dcl_usb_hcd.h \
  ../../../interface/hal/connectivity/usb_driver/dcl_otg_drv.h \
  ../../../interface/hal/peripheral/dcl_irda.h \
  ../../../interface/hal/peripheral/dcl_sim.h \
  ../../../interface/hal/peripheral/dcl_pmu.h \
  ../../../interface/hal/peripheral/dcl_pw.h \
  ../../../interface/hal/peripheral/dcl_chr_det.h \
  ../../../interface/hal/peripheral/dcl_pxs.h \
  ../../../interface/hal/peripheral/dcl_f32k_clk.h \
  ../../../custom/system/HEXING60A_11B_BB/flash_opt_gen.h \
  ../../../interface/fs/fs_gprot.h \
  ../../../fs/common/include/fs_internal_def.h \
  ../../../kal/adaptation/include/app_ltlcom.h \
  ../../../kal/adaptation/include/stack_ltlcom.h \
  ../../../fs/common/include/fs_iprot.h
