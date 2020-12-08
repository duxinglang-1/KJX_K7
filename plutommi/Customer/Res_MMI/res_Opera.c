/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   Res_Opera.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui-level functions for touch screen.
 *
 *	
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef OPERA_V10_BROWSER

#include "MMI_features.h"
#include "MMIDataType.h"
#include "PopulateRes.h"
#include "CustDataProts.h"
#include "GlobalMenuItems.h"
#include "opera_res_def.h"


/*****************************************************************************
 * FUNCTION
 *  PopulateOperaRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateOperaRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*---bream resource generated code---*/
    ADD_APPLICATION_STRING2(STR_ID_OPERA_1, "Unable to connect to the Internet. Please check your settings.", "opera::str_boot_connection_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_2, "Could not start the application.", "opera::str_boot_general_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_3, "Installing...", "opera::str_boot_installing");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_4, "Cannot finish installation because of insufficient storage space.", "opera::str_boot_storage_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_5, "About Opera", "opera::str_about_opera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_6, "Accept", "opera::str_accept");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_7, "Accept cookies", "opera::str_accept_cookies");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_8, "Activate", "opera::str_activate");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_9, "Add", "opera::str_add");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_10, "Add Bookmark", "opera::str_add_bookmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_11, "Add %s", "opera::str_add_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_12, "Address", "opera::str_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_13, "Advanced", "opera::str_advanced");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_14, "Agree", "opera::str_agree");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_15, "All rights reserved", "opera::str_all_rights_reserved");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_16, "This site wants to know your location.", "opera::str_allow_page_to_use_location");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_17, "Are you sure?", "opera::str_are_you_sure");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_18, "Add", "opera::str_assign");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_19, "Add to Speed Dial", "opera::str_assign_speeddial");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_20, "Back", "opera::str_back");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_21, "Use ALT + click on trackwheel to open menu, and ALT + trackwheel for horizontal scrolling.", "opera::str_bb_navigation_help");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_22, "Navigation Help", "opera::str_bb_navigation_help_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_23, "bookmark operation failed", "opera::str_bookmark_operation_fail_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_24, "Set as Readonly", "opera::str_bookmark_set_readonly");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_25, "Set as Writable", "opera::str_bookmark_set_writable");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_26, "Bookmarks", "opera::str_bookmarks");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_27, "Loading...", "opera::str_boot_loading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_28, "Cancel", "opera::str_cancel");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_29, "Cancel Editing", "opera::str_cancel_editing");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_30, "Change", "opera::str_change");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_31, "Change settings", "opera::str_change_settings");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_32, "Check", "opera::str_check");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_33, "Clear", "opera::str_clear");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_34, "Clear All", "opera::str_clear_all");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_35, "Clear cache", "opera::str_clear_cache");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_36, "Are you sure you want to clear the cache?", "opera::str_clear_cache_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_37, "Clear Cache", "opera::str_clear_cache_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_38, "Clear cookies", "opera::str_clear_cookies");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_39, "Clear all saved cookies?", "opera::str_clear_cookies_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_40, "Clear Cookies", "opera::str_clear_cookies_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_41, "Clear history", "opera::str_clear_history");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_42, "You are about to clear your entire browsing history. Do you wish to continue?", "opera::str_clear_history_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_43, "Clear History", "opera::str_clear_history_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_44, "Clear passwords", "opera::str_clear_passwords");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_45, "Clear all saved usernames and passwords?", "opera::str_clear_passwords_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_46, "Clear Passwords", "opera::str_clear_passwords_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_47, "Failed to copy text due to too many characters selected.", "opera::str_clipboard_place_text_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_48, "Clipboard Failure", "opera::str_clipboard_place_text_error_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_49, "Close Tab", "opera::str_close_tab");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_50, "Network profile need to change in case of loading service message or luanching from sat. That need to close all connections, do you want to do it ?", "opera::str_confirm_change_network_profile_for_loading_service_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_51, "Unable to connect. Please review your network settings.", "opera::str_connection_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_52, "Connection Failed", "opera::str_connection_failed_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_53, "Continue", "opera::str_continue");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_54, "Copy", "opera::str_copy");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_55, "Copyright (c) %s", "opera::str_copyright_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_56, "Create", "opera::str_create");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_57, "Create new tab", "opera::str_create_new_tab");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_58, "Add Search Engine", "opera::str_create_search");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_59, "Cut", "opera::str_cut");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_60, "Cycle tabs left", "opera::str_cycle_tabs_left");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_61, "Cycle tabs right", "opera::str_cycle_tabs_right");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_62, "Default browser", "opera::str_default_browser");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_63, "Delete", "opera::str_delete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_64, "Delete Download", "opera::str_delete_download");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_65, "Delete File", "opera::str_delete_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_66, "Delete Folder", "opera::str_delete_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_67, "Do you want to delete %s and all its contents?", "opera::str_delete_folder_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_68, "Delete \"%s\"?", "opera::str_delete_x_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_69, "Deny", "opera::str_deny");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_70, "Disagree", "opera::str_disagree");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_71, "Dismiss", "opera::str_dismiss");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_72, "documents", "opera::str_documents");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_73, "Done", "opera::str_done");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_74, "Download complete", "opera::str_download_complete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_75, "Download failed", "opera::str_download_failed");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_76, "Download Failed", "opera::str_download_failed_caption");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_77, "Downloading %0 failed. Please try again.", "opera::str_download_failed_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_78, "Download File", "opera::str_download_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_79, "Downloading File", "opera::str_downloading_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_80, "Downloads", "opera::str_downloads");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_81, "Edit", "opera::str_edit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_82, "Edit Bookmark", "opera::str_edit_bookmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_83, "Edit Folder", "opera::str_edit_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_84, "Edit Saved Page", "opera::str_edit_saved_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_85, "Edit Search Engine", "opera::str_edit_search_engine");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_86, "English", "opera::str_english");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_87, "Enter address", "opera::str_enter_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_88, "Enter Address", "opera::str_enter_address_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_89, "Enter Text", "opera::str_enter_text_caption");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_90, "End User License Agreement", "opera::str_eula");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_91, "Exit", "opera::str_exit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_92, "There are still active downloads. Do you want to cancel them and close the application?", "opera::str_exit_with_downloads_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_93, "Extensions", "opera::str_extensions");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_94, "Feeds", "opera::str_feeds");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_95, "Find in Page", "opera::str_find_in_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_96, "Folder", "opera::str_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_97, "Font size", "opera::str_font_size");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_98, "Forward", "opera::str_forward");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_99, "Fullscreen", "opera::str_fullscreen");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_100, "Fullscreen Edit", "opera::str_fullscreen_edit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_101, "Fullscreen edit", "opera::str_fullscreen_edit_setting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_102, "Go", "opera::str_go");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_103, "Go to Address...", "opera::str_go_to_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_104, "Google Privacy Policy", "opera::str_google_location_link_pp");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_105, "Google Terms of Service", "opera::str_google_location_link_tos");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_106, "To share your location you must agree to:", "opera::str_google_location_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_107, "Terms of Service", "opera::str_google_location_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_108, "Help", "opera::str_help");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_109, "Shortcuts", "opera::str_help_shortcuts");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_110, "History", "opera::str_history");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_111, "Homepage", "opera::str_homepage");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_112, "Image quality", "opera::str_image_quality");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_113, "High", "opera::str_image_quality_high");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_114, "Low", "opera::str_image_quality_low");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_115, "Medium", "opera::str_image_quality_medium");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_116, "System is busy now, pleasse try later.", "opera::str_in_processing");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_117, "Busy now", "opera::str_in_processing_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_118, "Information", "opera::str_information");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_119, "Only support http://, https://, file://, opera:, about:, c:, d: and e:", "opera::str_invalid_url");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_120, "This item is read-only and cannot be modified.", "opera::str_item_modification_denied_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_121, "Landscape", "opera::str_landscape");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_122, "Large", "opera::str_large");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_123, "Learn more", "opera::str_learn_more");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_124, "Email", "opera::str_link_auth_email");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_125, "Please enter email address.", "opera::str_link_auth_email_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_126, "Email address already in use.", "opera::str_link_auth_email_inuse");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_127, "Invalid email address.", "opera::str_link_auth_email_invalid");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_128, "Logging in...", "opera::str_link_auth_login_progress");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_129, "Password", "opera::str_link_auth_password");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_130, "Please enter password.", "opera::str_link_auth_password_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_131, "The password is too short.", "opera::str_link_auth_password_invalid");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_132, "Creating user...", "opera::str_link_auth_signup_progress");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_133, "Username", "opera::str_link_auth_username");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_134, "Please enter username.", "opera::str_link_auth_username_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_135, "Username already in use.", "opera::str_link_auth_username_inuse");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_136, "Wrong username or password.", "opera::str_link_auth_wrong_credentials");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_137, "I have an account", "opera::str_link_have_account");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_138, "Opera Link is a free service that synchronizes your bookmarks, Speed Dial, and search engines between all your computers and phones.", "opera::str_link_intro");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_139, "Login", "opera::str_link_login_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_140, "Sign Up", "opera::str_link_signup_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_141, "You are switching Opera accounts. Another Opera user has synchronized his or her data with this device. If you continue, all existing bookmarks, Speed Dial entries and search engines will be erased from this device. Do you want to continue?", "opera::str_link_switch_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_142, "Your browser data has been synchronized.", "opera::str_link_sync_complete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_143, "Synchronizing your data...", "opera::str_link_sync_progress");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_144, "Reload Image in Full Quality", "opera::str_load_full_quality_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_145, "Load image", "opera::str_load_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_146, "Load images", "opera::str_load_images");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_147, "Loading", "opera::str_loading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_148, "Login", "opera::str_login");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_149, "Manage", "opera::str_manage");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_150, "Manage Search Engines", "opera::str_manage_search_engines");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_151, "Mark", "opera::str_mark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_152, "Tab number reaches maximum, can not open more tab.", "opera::str_max_tab_count_reached");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_153, "Medium", "opera::str_medium");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_154, "Menu", "opera::str_menu");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_155, "Address can't be empty.", "opera::str_message_empty_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_156, "Minimize", "opera::str_minimize");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_157, "Mobile view", "opera::str_mobile_view");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_158, "music", "opera::str_music");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_159, "Name", "opera::str_name");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_160, "Network Profile", "opera::str_network_profile");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_161, "Network test...", "opera::str_network_test");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_162, "Do you want the automated network test to run next time you load a page?", "opera::str_network_test_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_163, "Network Test", "opera::str_network_test_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_164, "New Folder", "opera::str_new_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_165, "Next", "opera::str_next");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_166, "No", "opera::str_no");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_167, "No active downloads", "opera::str_no_active_downloads");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_168, "No matches found.", "opera::str_no_matches_found");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_169, "There is not enough disk space available (%0) to download this file (%1). Do you want to continue?", "opera::str_not_enough_space_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_170, "Not Enough Disk Space", "opera::str_not_enough_space_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_171, "Not Supported", "opera::str_not_supported_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_172, "Notice", "opera::str_notice");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_173, "Network protocol", "opera::str_obml_network_type");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_174, "HTTP", "opera::str_obml_network_type_http");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_175, "Socket", "opera::str_obml_network_type_socket");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_176, "Off", "opera::str_off");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_177, "OK", "opera::str_ok");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_178, "Older", "opera::str_older");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_179, "On", "opera::str_on");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_180, "Only clicked", "opera::str_only_clicked");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_181, "Out of Memory Warning", "opera::str_oom_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_182, "Open", "opera::str_open");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_183, "Open Image", "opera::str_open_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_184, "Open in New Tab", "opera::str_open_in_new_tab");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_185, "Opera Link", "opera::str_opera_link");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_186, "Options", "opera::str_options");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_187, "Other...", "opera::str_other");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_188, "Out of Memory", "opera::str_out_of_memory");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_189, "This page has been cleared to save memory. Please press reload to visit it again.", "opera::str_out_of_memory_browser_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_190, "The system is running low on memory and cannot display the page correctly. You can try to display more of the page content by reloading the page or clearing the history.", "opera::str_out_of_memory_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_191, "Out of Space", "opera::str_out_of_space");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_192, "Password", "opera::str_password");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_193, "Paste", "opera::str_paste");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_194, "Pause", "opera::str_pause");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_195, "pictures", "opera::str_pictures");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_196, "Plug-ins", "opera::str_plugins");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_197, "Pop-ups", "opera::str_pop_ups");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_198, "Press", "opera::str_press");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_199, "Privacy", "opera::str_privacy");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_200, "Connecting", "opera::str_progress_connecting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_201, "Uploading", "opera::str_progress_uploading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_202, "Protocol", "opera::str_protocol");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_203, "Reload", "opera::str_reload");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_204, "Do you want to reload all pages?", "opera::str_reload_pages_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_205, "Remember choice", "opera::str_remember_choice");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_206, "Remember Password", "opera::str_remember_password_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_207, "Remember passwords", "opera::str_remember_passwords");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_208, "Restart", "opera::str_restart");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_209, "Resume", "opera::str_resume");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_210, "Safe Mode", "opera::str_safe_mode");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_211, "Opera Mini is running in safe mode. All extensions are currently disabled.", "opera::str_safe_mode_desc");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_212, "Save", "opera::str_save");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_213, "Failed to save data because of disk full.", "opera::str_save_ds_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_214, "Save Data Failure", "opera::str_save_ds_error_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_215, "Save Image...", "opera::str_save_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_216, "Failed to save image. Please check available storage space.", "opera::str_save_image_failed");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_217, "Save Page", "opera::str_save_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_218, "Failed to Save Page", "opera::str_save_page_fail");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_219, "Failed to save the page", "opera::str_save_page_fail_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_220, "Save %s", "opera::str_save_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_221, "Saved Pages", "opera::str_saved_pages");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_222, "The protocol used in %O is not supported", "opera::str_scheme_not_supported");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_223, "Search", "opera::str_search");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_224, "Do you want to search again?", "opera::str_search_again_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_225, "Not found", "opera::str_search_fail_caption");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_226, "Search With...", "opera::str_search_with");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_227, "Security Warning", "opera::str_security_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_228, "Select", "opera::str_select");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_229, "Select address", "opera::str_select_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_230, "Select folder for saving pages.", "opera::str_select_dir_save_page_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_231, "Select File", "opera::str_select_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_232, "Select Folder", "opera::str_select_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_233, "Select Text", "opera::str_select_text");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_234, "Click to select start and end position.", "opera::str_select_text_keyboard_hybrid_info");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_235, "Select your starting position. Press \"Start\" where you want to start selecting text.", "opera::str_select_text_keyboard_info");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_236, "Send", "opera::str_send");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_237, "There are active network connection. If you want to set profile, please close all connections. Do you want to do it?", "opera::str_set_network_profile");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_238, "Set saved pages folder...", "opera::str_set_saved_pages_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_239, "Settings", "opera::str_settings");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_240, "Share to Facebook", "opera::str_share_2_facebook");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_241, "Share Location", "opera::str_share_location");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_242, "Shortcuts", "opera::str_shortcuts");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_243, "Show", "opera::str_show");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_244, "Sign Up", "opera::str_sign_up");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_245, "Small", "opera::str_small");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_246, "sounds", "opera::str_sounds");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_247, "Start", "opera::str_start");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_248, "Start Page", "opera::str_start_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_249, "Start page links", "opera::str_start_page_links_setting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_250, "Stop", "opera::str_stop");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_251, "Switch to %s", "opera::str_switch_to_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_252, "Third parties", "opera::str_third_parties");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_253, "Title", "opera::str_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_254, "Empty Address", "opera::str_title_empty_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_255, "Today", "opera::str_today");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_256, "Tools", "opera::str_tools");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_257, "Unable to Save Page", "opera::str_unable_to_save_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_258, "The current page is loaded from a saved page and cannot be saved again.", "opera::str_unable_to_save_page_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_259, "Uncheck", "opera::str_uncheck");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_260, "Unmark", "opera::str_unmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_261, "Unused Speed Dial", "opera::str_unused_speed_dial");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_262, "Use", "opera::str_use");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_263, "Opera Virtual Keyboard", "opera::str_use_virtual_keyboard");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_264, "Username", "opera::str_username");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_265, "video", "opera::str_video");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_266, "Always", "opera::str_virtual_keyboard_always");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_267, "Never", "opera::str_virtual_keyboard_never");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_268, "Only for addresses", "opera::str_virtual_keyboard_only_addresses");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_269, "Opera keyboard", "opera::str_virtual_keyboard_opera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_270, "Replace existing username and password?", "opera::str_wand_replace_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_271, "Save username and password?", "opera::str_wand_save_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_272, "Warning", "opera::str_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_273, "Yes", "opera::str_yes");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_274, "Yesterday", "opera::str_yesterday");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_275, "Zoom", "opera::str_zoom");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_276, "Zoom In", "opera::str_zoom_in");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_277, "Zoom Out", "opera::str_zoom_out");
/*---bream resource generated code---*/

/*---language resource generated code---*/
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_0, "The date %1 is not allowed for this form. Only certain dates are allowed for this field.", "LNG:0");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_1, "The value %1 is not allowed by a script on the page!", "LNG:1");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_2, "Warning", "LNG:2");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_3, "Help", "LNG:3");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_4, "Unable to verify the Web site's identity (OCSP error).", "LNG:4");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_5, "Client Certificate", "LNG:5");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_6, "This page may not be secure. For details, see the security tab.\n\nYou need to approve or reject the loading of this page.", "LNG:6");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_7, "Aug", "LNG:7");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_8, "Certificate version", "LNG:8");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_9, "Feb", "LNG:9");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_10, "XML parsing failed", "LNG:10");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_11, "Ins", "LNG:11");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_12, "Validated Certificate", "LNG:12");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_13, "The certificate is valid, but permission denied.", "LNG:13");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_14, "The certificate for \"%1\" is signed by the unknown Certificate Authority \"%2\". It is not possible to verify that this is a valid certificate.", "LNG:14");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_15, "You tried to access the address %s, which is currently unavailable. Please make sure that the Web address (URL) is correctly spelled and punctuated, then try reloading the page.", "LNG:15");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_16, "You are about to send a request to this server. Continue?", "LNG:16");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_17, "Exponent:", "LNG:17");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_18, "Reparse document as HTML", "LNG:18");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_19, "A different client certificate is already installed for this key. Installation failed.", "LNG:19");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_20, "Connecting to remote host %s...", "LNG:20");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_21, "Loading of external frame source <a href=\"%s\">%s</a> suppressed (click to view).", "LNG:21");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_22, "DH Public Key", "LNG:22");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_23, "Tabbed browsing", "LNG:23");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_24, "No matches found", "LNG:24");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_25, "Always continue when data is requested from my computer", "LNG:25");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_26, "syntax error", "LNG:26");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_27, "Name", "LNG:27");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_28, "Size", "LNG:28");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_29, "Time", "LNG:29");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_30, "Type", "LNG:30");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_31, "Show all", "LNG:31");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_32, "Accept", "LNG:32");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_33, "The online certificate validation (OCSP) server reports that validation failed because the server is offline, please try again later.", "LNG:33");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_34, "Could not connect to remote server", "LNG:34");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_35, "Redirection Status", "LNG:35");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_36, "Do you want to import the private key and these attached certificate(s)?", "LNG:36");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_37, "By long-clicking with your finger, you can perform actions such as opening a link in a new tab, editing a Speed Dial, and copying and pasting text.", "LNG:37");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_38, "Modulus:", "LNG:38");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_39, "Choose...", "LNG:39");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_40, "Automatic Proxy Configuration failed. \nProxy Configuration is automatically disabled for this session.", "LNG:40");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_41, "The encryption method used by the server is not considered secure.", "LNG:41");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_42, "PageUp", "LNG:42");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_43, "Sep", "LNG:43");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_44, "This certificate was downloaded from \"%1\" using a connection that is not secure", "LNG:44");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_45, "Size", "LNG:45");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_46, "Select Certificate", "LNG:46");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_47, "Warning: While decoding this file Opera encountered errors.", "LNG:47");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_48, "The online certificate validation (OCSP) server reports that validation failed because the request should have been signed.", "LNG:48");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_49, "Security is disabled.", "LNG:49");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_50, "Browse several Web sites at the same time, jumping from one to another with ease.", "LNG:50");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_51, "Server certificate expired", "LNG:51");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_52, "Low encryption level", "LNG:52");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_53, "Open the <a href=\"http://help.opera.com/\">Opera Help</a>.", "LNG:53");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_54, "Network socket resource problems. Try again", "LNG:54");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_55, "Image", "LNG:55");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_56, "Jan", "LNG:56");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_57, "Remote server or file not found", "LNG:57");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_58, "Public key", "LNG:58");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_59, "December", "LNG:59");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_60, "Unable to complete secure transaction", "LNG:60");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_61, "Signature algorithm", "LNG:61");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_62, "Address not available from this machine", "LNG:62");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_63, "Friday", "LNG:63");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_64, "The presented certificate has an unknown Certificate Authority.", "LNG:64");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_65, "To get started, scroll down to the End User License Agreement and press <b>%s</b>!", "LNG:65");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_66, "Internal communication error", "LNG:66");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_67, "Preview", "LNG:67");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_68, "%u bit private key. Generated %s.\nURL: %s", "LNG:68");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_69, "Cached Items", "LNG:69");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_70, "Wrong format!", "LNG:70");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_71, "%1 is not a valid Web address", "LNG:71");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_72, "The loading of the URL has been blocked for security reasons.", "LNG:72");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_73, "Resent-From", "LNG:73");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_74, "Security Information", "LNG:74");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_75, "July", "LNG:75");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_76, "June", "LNG:76");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_77, "March", "LNG:77");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_78, "Dec", "LNG:78");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_79, "URLs cached", "LNG:79");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_80, "HTTP gateway timed out", "LNG:80");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_81, "Address not found:", "LNG:81");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_82, "Plug-ins", "LNG:82");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_83, "Tuesday", "LNG:83");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_84, "Newsgroups", "LNG:84");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_85, "Bcc", "LNG:85");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_86, "Jul", "LNG:86");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_87, "Jun", "LNG:87");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_88, "The certificate for \"%1\" is not valid before %2. Is the clock on your computer correct?", "LNG:88");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_89, "Unknown error detected.", "LNG:89");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_90, "The %s plug-in is not installed. \nClick on the plug-in content area for more information.", "LNG:90");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_91, "Export all domains", "LNG:91");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_92, "Monday", "LNG:92");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_93, "DSA Component G", "LNG:93");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_94, "DSA Component P", "LNG:94");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_95, "DSA Component Q", "LNG:95");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_96, "Private Key (X)", "LNG:96");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_97, "Public Key (Y)", "LNG:97");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_98, "Too few files specified. You listed %1 and minimum is %2.", "LNG:98");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_99, "This site specifies a level of encryption that is not secure. You have manually disabled some of the strongest encryption methods, and this may have forced the server to select the current level. We recommend that you re-enable strong encryption before proceeding. Do you wish to continue using a low encryption level?", "LNG:99");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_100, "Please enter the new master password", "LNG:100");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_101, "Preview all domains", "LNG:101");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_102, "HTTP gateway failed", "LNG:102");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_103, "Unknown extension object ID ", "LNG:103");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_104, "Network socket blocking", "LNG:104");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_105, "Settings saved", "LNG:105");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_106, "There seems to be a problem on this server.\n\nIf loading does not finish properly, please stop the request and re-submit the form.", "LNG:106");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_107, "Proxy authentication failed. Content should not be trusted.", "LNG:107");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_108, "The server did not recognize the content type", "LNG:108");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_109, "Error", "LNG:109");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_110, "To start browsing, type an address, or select a Speed Dial or bookmark. Zoom in with a single tap, and scroll effortlessly with the flick of a finger.", "LNG:110");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_111, "Password", "LNG:111");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_112, "Your certificate has been installed, and you can use it, but Opera could not verify it. The signer of this certificate is missing. Please install the signer's certificate if available.", "LNG:112");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_113, "The server's certificate held an invalid name expression", "LNG:113");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_114, "Secure connection: fatal error (%u)", "LNG:114");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_115, "Remember passwords", "LNG:115");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_116, "The HTTP address is too long", "LNG:116");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_117, "(Memory)", "LNG:117");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_118, "HTTP request data was too long", "LNG:118");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_119, "The certificate was revoked because a newer certificate has been issued.", "LNG:119");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_120, "Reply-to", "LNG:120");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_121, "Save", "LNG:121");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_122, "Sunday", "LNG:122");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_123, "Transmission failure.", "LNG:123");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_124, "Always continue when data is requested from my computer", "LNG:124");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_125, "Subject", "LNG:125");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_126, "This Winsock implementation lacks important functionality.", "LNG:126");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_127, "Frame content not displayed", "LNG:127");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_128, "Could not access proxy server. Server is not available", "LNG:128");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_129, "Not valid after", "LNG:129");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_130, "Warning: Web Address Contains a Username", "LNG:130");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_131, "Remote server accepted the request - no content returned", "LNG:131");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_132, "Wrong certificate name", "LNG:132");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_133, "Form validation failed", "LNG:133");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_134, "Extensions", "LNG:134");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_135, "Generated by Opera.", "LNG:135");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_136, "Fri", "LNG:136");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_137, "bits", "LNG:137");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_138, "Up", "LNG:138");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_139, "Certificate Authorities", "LNG:139");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_140, "The online certificate validation (OCSP) server reports that validation failed because you are not authorized to validate this certificate.", "LNG:140");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_141, "The key of the certificate was encrypted using an unsupported method, possibly one that is not considered strong enough.", "LNG:141");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_142, "Repeated attempts failed to load this page completely.\n\nThere may be a problem on the server.", "LNG:142");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_143, " (Critical)", "LNG:143");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_144, "The server timed out", "LNG:144");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_145, "Could not write to file. Disk full.", "LNG:145");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_146, "Authentication failed. Content should not be trusted.", "LNG:146");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_147, "The address is no longer available", "LNG:147");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_148, "A page on your private intranet requests data from your computer. For security reasons, automatic access is blocked, but you may choose to continue.", "LNG:148");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_149, "Opera Link", "LNG:149");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_150, "Week", "LNG:150");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_151, "The server is using an outdated security protocol version.", "LNG:151");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_152, "The server's name \"%1\" does not match the certificate's name \"%2\". Somebody may be trying to eavesdrop on you.", "LNG:152");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_153, "The server could not send the requested part of the file", "LNG:153");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_154, "Personal certificates", "LNG:154");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_155, "Failed to connect to server. The reason may be that the encryption methods supported by the server are not enabled in the security preferences.\n\nPlease note that some encryption methods are no longer supported, and that access will not be possible until the Web site has been upgraded to use strong encryption.", "LNG:155");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_156, "An internal error occurred.", "LNG:156");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_157, "Blank page", "LNG:157");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_158, "Alt", "LNG:158");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_159, "End", "LNG:159");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_160, "Tab", "LNG:160");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_161, "Linked script not loaded", "LNG:161");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_162, "A client certificate uniquely identifies you during transactions.\n\nInstall this client certificate?", "LNG:162");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_163, "Invalid, or non-verifiable certificate.", "LNG:163");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_164, "Mon", "LNG:164");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_165, "The Web site does not permit its content to be displayed in a frame. It must be displayed in a separate window.", "LNG:165");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_166, "Filename", "LNG:166");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_167, "Backspace", "LNG:167");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_168, "No acceptable SSL 2 encryption methods found.", "LNG:168");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_169, "Access to this port is disabled for security reasons", "LNG:169");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_170, "Activated 40 second timeout. Waiting for data...", "LNG:170");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_171, "Quick find", "LNG:171");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_172, "Could not locate remote server", "LNG:172");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_173, "Executing JavaScript...", "LNG:173");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_174, "Default", "LNG:174");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_175, "These are the personal certificates registered in the database.", "LNG:175");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_176, "Incorrect Winsock version", "LNG:176");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_177, "prime1:", "LNG:177");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_178, "prime2:", "LNG:178");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_179, "Signature", "LNG:179");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_180, "Security warning", "LNG:180");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_181, "Server Certificate", "LNG:181");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_182, "Open file", "LNG:182");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_183, "Searching for complete server name...", "LNG:183");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_184, "Access denied to this file", "LNG:184");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_185, "Sun", "LNG:185");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_186, "Could not connect to remote server", "LNG:186");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_187, "Address", "LNG:187");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_188, "The file %1 is too large. It must be %2 bytes or smaller.", "LNG:188");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_189, "Connecting to proxy...", "LNG:189");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_190, "Offline mode is enabled. Cannot open\n\n%s\n\nDo you want to switch to online mode?", "LNG:190");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_191, "Opera Turbo", "LNG:191");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_192, "All encryption methods are disabled in Preferences.", "LNG:192");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_193, "Javascript Confirm", "LNG:193");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_194, "Security warning:\n\nYou are about to go to an address containing a username.\n\nUsername: %s \nServer: %s\n\nAre you sure you want to go to this address?", "LNG:194");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_195, "The certificate was revoked because the Certificate Authority has been compromised, and some or all certificates issued by this authority can no longer be trusted.", "LNG:195");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_196, "You need to enable JavaScript to access this content. Press F12, select \"Enable JavaScript\", then reload the page.", "LNG:196");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_197, "Tue", "LNG:197");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_198, "AM", "LNG:198");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_199, "The certificate for \"%1\" expired %2. The webmaster should update the certificate(s).", "LNG:199");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_200, "Opera's servers compress Web pages up to 70%, greatly reducing the cost of browsing.", "LNG:200");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_201, "October", "LNG:201");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_202, "Connection", "LNG:202");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_203, "Click to activate and use this control", "LNG:203");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_204, "Fingerprint", "LNG:204");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_205, "Unknown protocol", "LNG:205");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_206, "Scroll at warp speed using your phone's keypad. Hit 2 to go up, 4 to go left, 6 to go right and 8 to go down. %s snaps the view to the content. Hit 5 to zoom in and out.", "LNG:206");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_207, "Effortlessly remember your passwords, logging in to your favorite sites with a single click.", "LNG:207");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_208, "Completed request to %s", "LNG:208");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_209, ", this plug-in is disabled", "LNG:209");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_210, "To start browsing, type an address, or select a Speed Dial or bookmark. Zoom in with a single click, and scroll effortlessly with the keypad.", "LNG:210");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_211, "Connecting to network/modem...", "LNG:211");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_212, "This certificate has expired. You should delete it, and install an updated certificate.", "LNG:212");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_213, "Uploading file(s) to server", "LNG:213");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_214, "Enter", "LNG:214");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_215, "Right", "LNG:215");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_216, "Shift", "LNG:216");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_217, "Space", "LNG:217");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_218, "Error", "LNG:218");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_219, "Secure connection: fatal error (%u) from server.", "LNG:219");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_220, "Invalid address", "LNG:220");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_221, "None found", "LNG:221");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_222, "The certificate was revoked because the site has changed owners.", "LNG:222");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_223, "Wed", "LNG:223");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_224, "This site is using an outdated encryption method which is no longer classified as secure. It cannot sufficiently protect sensitive data. Do you wish to continue?", "LNG:224");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_225, "The input is not valid.", "LNG:225");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_226, "Basic Authentication: Clear text", "LNG:226");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_227, "A page on the public Internet requests data from your private intranet. For security reasons, automatic access is blocked, but you may choose to continue.", "LNG:227");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_228, "Looking up hostname %s...", "LNG:228");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_229, "Character:", "LNG:229");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_230, "Version", "LNG:230");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_231, "Downloading data from %s", "LNG:231");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_232, "The server's certificate did not match its hostname. Accept?", "LNG:232");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_233, "The proxy server requested a login authentication method that is not supported.", "LNG:233");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_234, "This URL is not in the list of URLs that can be authenticated by the given realm.\nCannot send Authentication credentials.", "LNG:234");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_235, "Introduction", "LNG:235");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_236, "Waiting (#%2) for connection to %1", "LNG:236");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_237, "Maximum size(KB)", "LNG:237");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_238, "Internal program error.", "LNG:238");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_239, "Opera was not able to connect to the server. The server may be using the unsupported SSL 2 protocol, which is not considered safe enough for secure communication. The site owner should upgrade to TLS 1.0 or newer.", "LNG:239");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_240, "publicExponent:", "LNG:240");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_241, "The certificate installation failed.", "LNG:241");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_242, "Valid to", "LNG:242");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_243, "Not valid before", "LNG:243");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_244, "The server does not support secure TLS renegotiation. The site owner should upgrade the server.", "LNG:244");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_245, "Third parties", "LNG:245");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_246, "Handshake failed due to export restrictions.", "LNG:246");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_247, "Reset", "LNG:247");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_248, "Network socket problems. Please check your network drivers.", "LNG:248");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_249, "Please enter master password", "LNG:249");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_250, "May", "LNG:250");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_251, "November", "LNG:251");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_252, "Setting up secure connection...", "LNG:252");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_253, "This is a searchable index", "LNG:253");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_254, "Always continue when data is requested from this server on my private intranet", "LNG:254");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_255, "Followup-To", "LNG:255");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_256, "The server requests identification in the form of a client certificate.\n\nYou may send one of the following certificates:", "LNG:256");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_257, "Problem encountered while decoding data. Possibly due to corrupted data.", "LNG:257");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_258, "Synchronize your bookmarks, Speed Dial, and search engines between your mobile phone and desktop computer. To get started, enable Opera Link from the settings menu.", "LNG:258");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_259, "HTTP preconditions failed", "LNG:259");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_260, "The certificate was revoked because the key associated with the certificate has been compromised, and the certificate cannot be trusted.", "LNG:260");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_261, "The endpoint was not in an appropriate state", "LNG:261");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_262, "To use a client certificate, Opera requires your master password.", "LNG:262");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_263, "Organization", "LNG:263");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_264, "Wednesday", "LNG:264");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_265, "Domain", "LNG:265");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_266, "Connection closed by remote server", "LNG:266");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_267, "Too many files specified. You listed %1 and maximum is %2.", "LNG:267");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_268, "Nov", "LNG:268");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_269, "Internal cache error", "LNG:269");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_270, "Export", "LNG:270");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_271, "The certificate was revoked because this site is no longer in operation", "LNG:271");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_272, "The response from the online certificate validation (OCSP) server was too old.", "LNG:272");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_273, "Invalid OBML configuration", "LNG:273");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_274, "Build", "LNG:274");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_275, "Java security", "LNG:275");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_276, "Folder Listing", "LNG:276");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_277, "Some changes may require a restart to take effect.", "LNG:277");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_278, "Go to <a href=\"http://www.opera.com/support/\">Opera's online support desk</a>.", "LNG:278");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_279, "September", "LNG:279");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_280, "None", "LNG:280");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_281, "You have been denied access to this WML deck.\n\nYou have not reached this deck in the correct order.", "LNG:281");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_282, "Secure connection: warning (%u) from server", "LNG:282");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_283, "The server wants to negotiate a connection that does *not* encrypt the data, but only verifies integrity. If you continue, the data can be read by anyone, but not modified.", "LNG:283");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_284, "Today", "LNG:284");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_285, "DH Generator", "LNG:285");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_286, "DH Modulus", "LNG:286");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_287, "Please set a master password to protect your client certificates and saved passwords", "LNG:287");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_288, "Wrong password, please enter the correct master password", "LNG:288");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_289, "The remote server lacks necessary functionality", "LNG:289");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_290, "KB", "LNG:290");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_291, "Oct", "LNG:291");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_292, "%1 specified one or more files that could not be found", "LNG:292");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_293, "Go to your favorite Web pages with just one click, using a set of visual bookmarks.", "LNG:293");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_294, "Certificate authorities certify the identity of Web sites. You should only install certificate authorities from sites you trust.\n\nInstall this certificate authority?", "LNG:294");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_295, "Transmission stopped!", "LNG:295");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_296, "Javascript Alert", "LNG:296");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_297, "Open transport error", "LNG:297");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_298, "Cc", "LNG:298");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_299, "To", "LNG:299");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_300, "HTTP content length was required", "LNG:300");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_301, "Issuer", "LNG:301");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_302, "The certificate for \"%1\" does not contain all the required information", "LNG:302");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_303, "Server name:", "LNG:303");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_304, "Remote server timed out. Please try again later.", "LNG:304");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_305, "Could not find proxy server", "LNG:305");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_306, "%1 is not a number!", "LNG:306");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_307, "The remote server refuses to perform the request.\nThis address is not available.", "LNG:307");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_308, "The certificate is unknown.", "LNG:308");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_309, "Request queued for sending to %s...", "LNG:309");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_310, "Browse for Folder", "LNG:310");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_311, "The signatures of this certificate could not be verified. While this can be caused by the issuer using the wrong method to sign the certificate, it can also be caused by attempts to modify or fake the certificate.", "LNG:311");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_312, "Certificate expired", "LNG:312");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_313, "Certificate Name", "LNG:313");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_314, "DH Private Key", "LNG:314");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_315, "HTTP expectation failed", "LNG:315");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_316, "modulus:", "LNG:316");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_317, "One of the certificates presented by the server has expired. Do you wish to accept the certificate?", "LNG:317");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_318, "There was an error in the response returned by the online certificate validation (OCSP) server.", "LNG:318");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_319, "The server tried redirecting to an invalid address.\nPlease report this to the webmaster of the site.", "LNG:319");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_320, "session cookie", "LNG:320");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_321, "The certificate has been revoked by its issuer. It is no longer valid. In the worst case it may be used by criminals for fraudulent purposes. The Web site owner must immediately replace the certificate.", "LNG:321");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_322, "Plug-in content", "LNG:322");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_323, "Date", "LNG:323");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_324, "From", "LNG:324");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_325, "Network not available. Contact your system administrator.", "LNG:325");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_326, "Cannot display content. <a href=\"%s\">Download %s.</a>", "LNG:326");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_327, "Could not connect to proxy server", "LNG:327");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_328, "Power scrolling", "LNG:328");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_329, "Line:", "LNG:329");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_330, "<no username found>", "LNG:330");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_331, "The server's certificate chain is incomplete, and the signer(s) are not registered. Accept?", "LNG:331");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_332, "Receiving data from %s...", "LNG:332");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_333, "Out of memory.", "LNG:333");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_334, "Customize preferences for the following host(s)", "LNG:334");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_335, "These are the certificate authorities registered in the database.", "LNG:335");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_336, "exponent1:", "LNG:336");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_337, "exponent2:", "LNG:337");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_338, "You have asked to be warned about certificates from \"%1\"", "LNG:338");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_339, "Import key and certificate", "LNG:339");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_340, "Attempt to connect to secure server could not be completed, and automatic reconnection was not possible. Please try again.", "LNG:340");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_341, "Please enter the old master password", "LNG:341");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_342, "You need to enable JavaScript to use this document. Then reload the page.", "LNG:342");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_343, "Load document in a new window", "LNG:343");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_344, "The address type is unknown or unsupported", "LNG:344");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_345, "Issued By", "LNG:345");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_346, "Issued to", "LNG:346");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_347, "You have to specify a value", "LNG:347");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_348, "The server was unable to send acceptable data", "LNG:348");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_349, "The URL", "LNG:349");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_350, "contains characters that are not valid in the location they are found.", "LNG:350");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_351, "Cookie Offered", "LNG:351");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_352, "Welcome to %s!", "LNG:352");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_353, "Security protocol", "LNG:353");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_354, "Move up", "LNG:354");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_355, "Unknown signature algorithm ", "LNG:355");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_356, "The response from the online certificate validation (OCSP) server could not be validated.", "LNG:356");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_357, "cookie", "LNG:357");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_358, "Security operations are not available.", "LNG:358");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_359, "Please click to download and activate plug-in.", "LNG:359");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_360, "Certificate warning", "LNG:360");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_361, "PageDown", "LNG:361");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_362, "External e-mail frame", "LNG:362");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_363, "Apr", "LNG:363");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_364, "Mar", "LNG:364");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_365, "Waiting for DNS confirmation of cookie domain(s)...", "LNG:365");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_366, "The online certificate validation (OCSP) server reports that validation failed because of an unspecified server error.", "LNG:366");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_367, "Security Issue", "LNG:367");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_368, "The online certificate validation (OCSP) server reports that validation failed because of an unknown error.", "LNG:368");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_369, "The number %1 is not allowed for this form. Only certain numbers are allowed for this field.", "LNG:369");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_370, "Unknown algorithm", "LNG:370");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_371, "File does not exist", "LNG:371");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_372, "Warning: Cross Network Request", "LNG:372");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_373, "Could not open file", "LNG:373");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_374, "Submit", "LNG:374");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_375, "%1 is too low. The lowest value you can use is %2.", "LNG:375");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_376, "About Opera", "LNG:376");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_377, "The server is using a short public encryption key, which is not considered to be secure.", "LNG:377");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_378, "The reason for their presence may be a mistyped URL, but the URL may also be an attempt to trick you into visiting a Web site which you might mistake for a site you trust.", "LNG:378");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_379, "Handshake failed because the server requires encryption methods more secure than those enabled.", "LNG:379");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_380, "Drives", "LNG:380");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_381, "The entered text is too large! You used %1 letters and the limit is %2.", "LNG:381");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_382, "Network problem", "LNG:382");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_383, "B", "LNG:383");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_384, "Install Certificate", "LNG:384");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_385, "The URL was redirected to %s. Please click the link to go there.", "LNG:385");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_386, "You can enable the automatic redirection in Preferences.", "LNG:386");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_387, "privateExponent:", "LNG:387");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_388, "Minimum size(KB)", "LNG:388");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_389, "Remove", "LNG:389");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_390, "Opera Software is grateful to the groups and individuals above for their contributions.", "LNG:390");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_391, "Sat", "LNG:391");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_392, "Continue", "LNG:392");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_393, "Unknown fieldname", "LNG:393");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_394, "April", "LNG:394");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_395, "Do you want to import the private key stored in this file?", "LNG:395");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_396, "Conflict with existing resource on server", "LNG:396");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_397, "The HTTP version was not accepted", "LNG:397");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_398, "Do you want to allow local JavaScript files to control secure pages? You should only allow this if you know what your JavaScript files contain and understand the security implications.", "LNG:398");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_399, "Changing the master password failed.", "LNG:399");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_400, "Install Certificate", "LNG:400");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_401, "coefficient:", "LNG:401");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_402, "This certificate cannot be used for this purpose.", "LNG:402");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_403, "The service is overloaded or offline. Please try again later.", "LNG:403");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_404, "Handshake failed because the server does not want to accept the enabled SSL/TLS protocol versions.", "LNG:404");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_405, "The HTTP request method was not accepted by the server", "LNG:405");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_406, "Need help?", "LNG:406");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_407, "Private key", "LNG:407");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_408, "Preferences Editor", "LNG:408");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_409, "Saturday", "LNG:409");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_410, "The address is too long.", "LNG:410");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_411, "Thu", "LNG:411");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_412, "Public key algorithm", "LNG:412");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_413, "You can accept or refuse this %s%s.", "LNG:413");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_414, "May", "LNG:414");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_415, "Directory", "LNG:415");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_416, "Connect to Debugger", "LNG:416");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_417, "The online certificate validation (OCSP) server reports that validation failed because of a malformed request.", "LNG:417");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_418, "Digest Authentication: Password not passed directly", "LNG:418");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_419, "The server is using a public encryption key with a length that only provides medium security.", "LNG:419");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_420, "Add", "LNG:420");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_421, "%1 is not in the format this page requires!", "LNG:421");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_422, "Add files", "LNG:422");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_423, "Long-click menus", "LNG:423");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_424, "Sending request to %s...", "LNG:424");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_425, "Thursday", "LNG:425");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_426, "Serial number", "LNG:426");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_427, "None", "LNG:427");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_428, "Please re-enter the new master password", "LNG:428");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_429, "The server requested a login authentication method that is not supported.", "LNG:429");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_430, "PM", "LNG:430");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_431, "August", "LNG:431");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_432, "Intermediate", "LNG:432");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_433, "Platform", "LNG:433");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_434, "Information from this secure page will be submitted to a page that is not secure on %s.\n\nSubmitting sensitive information is strongly discouraged.", "LNG:434");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_435, "January", "LNG:435");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_436, "%1 is not a legal e-mail address", "LNG:436");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_437, "ltr", "LNG:437");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_438, "No changes to save in this section", "LNG:438");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_439, "Site Specific Preferences", "LNG:439");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_440, "Validated Servername", "LNG:440");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_441, "JavaScript", "LNG:441");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_442, "%1 is too high. The highest value you can use is %2.", "LNG:442");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_443, "This form is being submitted via e-mail, revealing your name and e-mail address to the recipient. Do you want to continue?", "LNG:443");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_444, "Could not connect to proxy server. Access denied", "LNG:444");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_445, "Secure connection: warning (%u)", "LNG:445");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_446, "Ctrl", "LNG:446");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_447, "Down", "LNG:447");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_448, "Home", "LNG:448");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_449, "Left", "LNG:449");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_450, "Meta", "LNG:450");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_451, "List all domains", "LNG:451");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_452, "The server requested an ANONYMOUS connection, it is therefore impossible to verify the identity of the server. Is this a service that would normally be anonymous, and are you willing to send data to this anonymous server?", "LNG:452");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_453, "Make sure your Internet connection is active and check whether other applications that rely on the same connection are working.", "LNG:453");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_454, "Access denied", "LNG:454");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_455, "Please enter a password to protect the exported private key", "LNG:455");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_456, "Invalid URL", "LNG:456");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_457, "Please enter the password protecting the key", "LNG:457");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_458, "A Java applet is requesting to run with privileges which may allow it to harm your computer.\n\nYou should only accept this request if you know and trust the originating Web site.", "LNG:458");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_459, "The certificate has expired.", "LNG:459");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_460, "Move down", "LNG:460");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_461, "A page on the public Internet requests data from your computer. For security reasons, automatic access is blocked, but you may choose to continue.", "LNG:461");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_462, "List", "LNG:462");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_463, "Unsupported certificate.", "LNG:463");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_464, "Del", "LNG:464");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_465, "No home page defined. Please define one.", "LNG:465");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_466, "The client certificate had no matching private key in the database.", "LNG:466");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_467, "February", "LNG:467");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_468, "The certificate's chain was not ordered correctly.", "LNG:468");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_469, "Waiting for user-confirmation of cookie(s)...", "LNG:469");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_470, "The root certificate from \"%1\" is not known to Opera. Opera cannot decide if this certificate can be trusted.", "LNG:470");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_471, "Speed Dial", "LNG:471");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_472, "Esc", "LNG:472");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_473, "By long-clicking with the select button, you can perform actions such as opening a link in a new tab, editing a Speed Dial, and copying and pasting text.", "LNG:473");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_LNG_474, "The server does not support secure TLS renegotiation. The site owner must upgrade the server.", "LNG:474");
/*---language resource generated code---*/

    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_1, "Opera", "Opera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_2, "Browser has occurred memory error", "Memory Error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_3, "Browser has occurred initialize error", "Init Error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_4, "Invalid parameters to browser", "Invalid Parameters");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_5, "System busy for browser", "Busy");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_6, "Failed in browser", "Failed");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_7, "Go", "Ime Go");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_8, "Search", "Ime Search");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_9, "Next", "Ime Next");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_10, "Done", "Ime Done");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_11, "Delete", "Ime Delete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_12, "Creating a new folder failed", "Bream Creating a new folder failed");	
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_13, "Cancel", "Ime Cancel");	
    ADD_APPLICATION_STRING2(STR_ID_OPERA_MMI_14, "Manage", "Ime Manage");
	
    ADD_APPLICATION_STRING2(STR_ID_OPERA_SEND_BOOKMARK_SMS, "Send as text message", "Send bookmark by sms");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_SEND_BOOKMARK_MMS, "Send as multimedia message", "Send bookmark by mms");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_SEND_BOOKMARK_EMAIL, "Send as Email", "Send bookmark by email");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_SEND_BOOKMARK_BT, "Send via Bluetooth", "Send bookmark by bt");

#ifdef OPERA_WEBVIEW
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_MMI_1, "Opera Webview", "Opera Webview");
/*---webview bream resource generated code---*/
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_1, "Unable to connect to the Internet. Please check your settings.", "opera::str_boot_connection_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_2, "Could not start the application.", "opera::str_boot_general_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_3, "Installing...", "opera::str_boot_installing");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_4, "Cannot finish installation because of insufficient storage space.", "opera::str_boot_storage_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_5, "About Opera", "opera::str_about_opera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_6, "Accept", "opera::str_accept");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_7, "Accept cookies", "opera::str_accept_cookies");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_8, "Activate", "opera::str_activate");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_9, "Add", "opera::str_add");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_10, "Add Bookmark", "opera::str_add_bookmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_11, "Add %s", "opera::str_add_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_12, "Address", "opera::str_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_13, "Advanced", "opera::str_advanced");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_14, "Agree", "opera::str_agree");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_15, "All rights reserved", "opera::str_all_rights_reserved");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_16, "This site wants to know your location.", "opera::str_allow_page_to_use_location");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_17, "Are you sure?", "opera::str_are_you_sure");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_18, "Add", "opera::str_assign");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_19, "Add to Speed Dial", "opera::str_assign_speeddial");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_20, "Back", "opera::str_back");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_21, "Set as Readonly", "opera::str_bookmark_set_readonly");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_22, "Set as Writable", "opera::str_bookmark_set_writable");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_23, "Bookmarks", "opera::str_bookmarks");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_24, "Loading...", "opera::str_boot_loading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_25, "Cancel", "opera::str_cancel");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_26, "Cancel Editing", "opera::str_cancel_editing");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_27, "Change", "opera::str_change");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_28, "Check", "opera::str_check");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_29, "Clear", "opera::str_clear");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_30, "Clear All", "opera::str_clear_all");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_31, "Clear cache", "opera::str_clear_cache");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_32, "Are you sure you want to clear the cache?", "opera::str_clear_cache_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_33, "Clear Cache", "opera::str_clear_cache_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_34, "Clear cookies", "opera::str_clear_cookies");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_35, "Clear all saved cookies?", "opera::str_clear_cookies_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_36, "Clear Cookies", "opera::str_clear_cookies_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_37, "Clear history", "opera::str_clear_history");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_38, "You are about to clear your entire browsing history. Do you wish to continue?", "opera::str_clear_history_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_39, "Clear History", "opera::str_clear_history_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_40, "Clear passwords", "opera::str_clear_passwords");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_41, "Clear all saved usernames and passwords?", "opera::str_clear_passwords_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_42, "Clear Passwords", "opera::str_clear_passwords_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_43, "Close Tab", "opera::str_close_tab");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_44, "Network profile need to change in case of loading service message or luanching from sat. That need to close all connections, do you want to do it ?", "opera::str_confirm_change_network_profile_for_loading_service_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_45, "Unable to connect. Please review your network settings.", "opera::str_connection_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_46, "Continue", "opera::str_continue");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_47, "Copy", "opera::str_copy");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_48, "Copyright (c) %s", "opera::str_copyright_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_49, "Create", "opera::str_create");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_50, "Create new tab", "opera::str_create_new_tab");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_51, "Add Search Engine", "opera::str_create_search");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_52, "Cut", "opera::str_cut");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_53, "Cycle tabs left", "opera::str_cycle_tabs_left");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_54, "Cycle tabs right", "opera::str_cycle_tabs_right");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_55, "Default browser", "opera::str_default_browser");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_56, "Delete", "opera::str_delete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_57, "Delete File", "opera::str_delete_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_58, "Deny", "opera::str_deny");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_59, "Disagree", "opera::str_disagree");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_60, "Dismiss", "opera::str_dismiss");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_61, "documents", "opera::str_documents");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_62, "Done", "opera::str_done");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_63, "Download complete", "opera::str_download_complete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_64, "Download failed", "opera::str_download_failed");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_65, "Download File", "opera::str_download_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_66, "Downloading File", "opera::str_downloading_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_67, "Downloads", "opera::str_downloads");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_68, "Edit", "opera::str_edit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_69, "Edit Bookmark", "opera::str_edit_bookmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_70, "Edit Folder", "opera::str_edit_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_71, "Edit Saved Page", "opera::str_edit_saved_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_72, "Edit Search Engine", "opera::str_edit_search_engine");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_73, "English", "opera::str_english");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_74, "Enter address", "opera::str_enter_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_75, "Enter Address", "opera::str_enter_address_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_76, "Enter Text", "opera::str_enter_text_caption");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_77, "End User License Agreement", "opera::str_eula");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_78, "Exit", "opera::str_exit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_79, "There are still active downloads. Do you want to cancel them and close the application?", "opera::str_exit_with_downloads_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_80, "Extensions", "opera::str_extensions");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_81, "Feeds", "opera::str_feeds");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_82, "Find in Page", "opera::str_find_in_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_83, "Folder", "opera::str_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_84, "Font size", "opera::str_font_size");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_85, "Forward", "opera::str_forward");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_86, "Fullscreen", "opera::str_fullscreen");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_87, "Fullscreen Edit", "opera::str_fullscreen_edit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_88, "Fullscreen edit", "opera::str_fullscreen_edit_setting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_89, "Go", "opera::str_go");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_90, "Go to Address...", "opera::str_go_to_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_91, "Google Privacy Policy", "opera::str_google_location_link_pp");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_92, "Google Terms of Service", "opera::str_google_location_link_tos");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_93, "To share your location you must agree to:", "opera::str_google_location_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_94, "Terms of Service", "opera::str_google_location_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_95, "Help", "opera::str_help");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_96, "Shortcuts", "opera::str_help_shortcuts");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_97, "History", "opera::str_history");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_98, "Homepage", "opera::str_homepage");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_99, "Image quality", "opera::str_image_quality");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_100, "High", "opera::str_image_quality_high");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_101, "Low", "opera::str_image_quality_low");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_102, "Medium", "opera::str_image_quality_medium");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_103, "Landscape", "opera::str_landscape");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_104, "Large", "opera::str_large");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_105, "Email", "opera::str_link_auth_email");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_106, "Please enter email address.", "opera::str_link_auth_email_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_107, "Email address already in use.", "opera::str_link_auth_email_inuse");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_108, "Invalid email address.", "opera::str_link_auth_email_invalid");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_109, "Logging in...", "opera::str_link_auth_login_progress");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_110, "Password", "opera::str_link_auth_password");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_111, "Please enter password.", "opera::str_link_auth_password_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_112, "The password is too short.", "opera::str_link_auth_password_invalid");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_113, "Username", "opera::str_link_auth_username");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_114, "Please enter username.", "opera::str_link_auth_username_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_115, "Username already in use.", "opera::str_link_auth_username_inuse");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_116, "Wrong username or password.", "opera::str_link_auth_wrong_credentials");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_117, "I have an account", "opera::str_link_have_account");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_118, "Login", "opera::str_link_login_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_119, "Your browser data has been synchronized.", "opera::str_link_sync_complete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_120, "Synchronizing your data...", "opera::str_link_sync_progress");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_121, "Reload Image in Full Quality", "opera::str_load_full_quality_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_122, "Load image", "opera::str_load_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_123, "Load images", "opera::str_load_images");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_124, "Loading", "opera::str_loading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_125, "Login", "opera::str_login");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_126, "Manage", "opera::str_manage");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_127, "Manage Search Engines", "opera::str_manage_search_engines");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_128, "Mark", "opera::str_mark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_129, "Tab number reaches maximum, can not open more tab.", "opera::str_max_tab_count_reached");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_130, "Medium", "opera::str_medium");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_131, "Menu", "opera::str_menu");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_132, "Minimize", "opera::str_minimize");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_133, "Mobile view", "opera::str_mobile_view");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_134, "music", "opera::str_music");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_135, "Name", "opera::str_name");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_136, "Network Profile", "opera::str_network_profile");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_137, "Network test...", "opera::str_network_test");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_138, "Do you want the automated network test to run next time you load a page?", "opera::str_network_test_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_139, "Network Test", "opera::str_network_test_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_140, "New Folder", "opera::str_new_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_141, "Next", "opera::str_next");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_142, "No", "opera::str_no");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_143, "No active downloads", "opera::str_no_active_downloads");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_144, "Network protocol", "opera::str_obml_network_type");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_145, "HTTP", "opera::str_obml_network_type_http");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_146, "Socket", "opera::str_obml_network_type_socket");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_147, "Off", "opera::str_off");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_148, "OK", "opera::str_ok");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_149, "Older", "opera::str_older");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_150, "On", "opera::str_on");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_151, "Only clicked", "opera::str_only_clicked");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_152, "Out of Memory Warning", "opera::str_oom_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_153, "Open", "opera::str_open");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_154, "Open Image", "opera::str_open_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_155, "Open in New Tab", "opera::str_open_in_new_tab");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_156, "Opera Link", "opera::str_opera_link");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_157, "Options", "opera::str_options");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_158, "Other...", "opera::str_other");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_159, "Out of Memory", "opera::str_out_of_memory");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_160, "This page has been cleared to save memory. Please press reload to visit it again.", "opera::str_out_of_memory_browser_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_161, "The system is running low on memory and cannot display the page correctly. You can try to display more of the page content by reloading the page or clearing the history.", "opera::str_out_of_memory_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_162, "Password", "opera::str_password");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_163, "Paste", "opera::str_paste");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_164, "Pause", "opera::str_pause");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_165, "pictures", "opera::str_pictures");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_166, "Plug-ins", "opera::str_plugins");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_167, "Pop-ups", "opera::str_pop_ups");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_168, "Press", "opera::str_press");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_169, "Privacy", "opera::str_privacy");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_170, "Connecting", "opera::str_progress_connecting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_171, "Uploading", "opera::str_progress_uploading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_172, "Protocol", "opera::str_protocol");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_173, "Reload", "opera::str_reload");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_174, "Remember choice", "opera::str_remember_choice");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_175, "Remember Password", "opera::str_remember_password_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_176, "Remember passwords", "opera::str_remember_passwords");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_177, "Restart", "opera::str_restart");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_178, "Resume", "opera::str_resume");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_179, "Save", "opera::str_save");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_180, "Save Image...", "opera::str_save_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_181, "Save Page", "opera::str_save_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_182, "Save %s", "opera::str_save_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_183, "Saved Pages", "opera::str_saved_pages");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_184, "Search", "opera::str_search");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_185, "Search With...", "opera::str_search_with");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_186, "Security Warning", "opera::str_security_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_187, "Select", "opera::str_select");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_188, "Select address", "opera::str_select_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_189, "Select File", "opera::str_select_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_190, "Select Folder", "opera::str_select_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_191, "Select Text", "opera::str_select_text");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_192, "Click to select start and end position.", "opera::str_select_text_keyboard_hybrid_info");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_193, "Select your starting position. Press \"Start\" where you want to start selecting text.", "opera::str_select_text_keyboard_info");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_194, "Send", "opera::str_send");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_195, "There are active network connection. If you want to set profile, please close all connections. Do you want to do it?", "opera::str_set_network_profile");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_196, "Set saved pages folder...", "opera::str_set_saved_pages_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_197, "Settings", "opera::str_settings");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_198, "Share to Facebook", "opera::str_share_2_facebook");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_199, "Share Location", "opera::str_share_location");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_200, "Shortcuts", "opera::str_shortcuts");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_201, "Show", "opera::str_show");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_202, "Sign Up", "opera::str_sign_up");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_203, "Small", "opera::str_small");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_204, "sounds", "opera::str_sounds");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_205, "Start", "opera::str_start");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_206, "Start Page", "opera::str_start_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_207, "Start page links", "opera::str_start_page_links_setting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_208, "Stop", "opera::str_stop");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_209, "Switch to %s", "opera::str_switch_to_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_210, "Third parties", "opera::str_third_parties");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_211, "Title", "opera::str_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_212, "Today", "opera::str_today");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_213, "Tools", "opera::str_tools");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_214, "Uncheck", "opera::str_uncheck");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_215, "Unmark", "opera::str_unmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_216, "Unused Speed Dial", "opera::str_unused_speed_dial");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_217, "Use", "opera::str_use");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_218, "Opera Virtual Keyboard", "opera::str_use_virtual_keyboard");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_219, "Username", "opera::str_username");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_220, "video", "opera::str_video");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_221, "Always", "opera::str_virtual_keyboard_always");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_222, "Never", "opera::str_virtual_keyboard_never");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_223, "Only for addresses", "opera::str_virtual_keyboard_only_addresses");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_224, "Opera keyboard", "opera::str_virtual_keyboard_opera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_225, "Replace existing username and password?", "opera::str_wand_replace_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_226, "Save username and password?", "opera::str_wand_save_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_227, "Yes", "opera::str_yes");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_228, "Yesterday", "opera::str_yesterday");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_229, "Zoom", "opera::str_zoom");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_230, "Zoom In", "opera::str_zoom_in");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_WEBVIEW_231, "Zoom Out", "opera::str_zoom_out");
/*---webview bream resource generated code---*/
#endif

    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_BOOT_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\data-ri.rsc","bream data resource file");
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_SKIN_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\skin-qvga.rsc","bream skin resource file");
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__)
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_SKIN_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\skin-hvga.rsc","bream skin resource file");
#elif defined(__MMI_MAINLCD_480X800__)
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_SKIN_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\skin-vga.rsc","bream skin resource file");
#else
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_SKIN_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\skin.rsc","bream skin resource file");
#endif
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_BREAM_A_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\bream\\\\a","bream program bin");

/*this line below is for perload.bin configuration, which is mainly for speed dial, bookmark, homepage, search engine config*/
#if defined (__OP02__) /*if defined CU compile optoin*/
    #if defined(__MMI_MAINLCD_240X320__)
	    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_qvga.bin","preload files");
    #elif defined(__MMI_MAINLCD_240X400__)
	    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_wqvga.bin","preload files");
    #elif defined(__MMI_MAINLCD_320X480__)
	    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_hvga.bin","preload files");
    #else
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload.bin","preload files");
    #endif
#elif defined (__OP01_3G__)/*if defined CMCC compile option*/
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload.bin","preload files");
#else /*if is open market*/
    #if defined (__GOOGLE_SEARCH_SUPPORT__)/*__GOOGLE_SEARCH_SUPPORT__*/
        #if defined (__MMI_GB_WINGUO__)
            ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_google_winguo.bin","preload files");
        #else
            #if defined(__MMI_MAINLCD_240X320__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_google_qvga.bin","preload files");
            #elif defined(__MMI_MAINLCD_240X400__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_google_wqvga.bin","preload files");
            #elif defined(__MMI_MAINLCD_320X480__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_google_hvga.bin","preload files");
            #else
                ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_google.bin","preload files");
            #endif 
        #endif
    #elif (defined(__MMI_SEARCH_WEB_BAIDU__) || defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__))/*__MMI_SEARCH_WEB_BAIDU__ || __MMI_VUI_WIDGET_BAIDU_SEARCH__*/
        #if defined (__MMI_GB_WINGUO__)
            ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_baidu_winguo.bin","preload files");
        #else
            #if defined(__MMI_MAINLCD_240X320__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_baidu_qvga.bin","preload files");
            #elif defined(__MMI_MAINLCD_240X400__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_baidu_wqvga.bin","preload files");
            #elif defined(__MMI_MAINLCD_320X480__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_baidu_hvga.bin","preload files");
            #else
                ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_baidu.bin","preload files");
            #endif 
        #endif
    #else /*google search off, baidu search off*/
        #if defined (__MMI_GB_WINGUO__)
            ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_winguo.bin","preload files");
        #else
            #if defined(__MMI_MAINLCD_240X320__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_qvga.bin","preload files");
            #elif defined(__MMI_MAINLCD_240X400__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_wqvga.bin","preload files");
            #elif defined(__MMI_MAINLCD_320X480__)
    	        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload_hvga.bin","preload files");
            #else
                ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_PRELOAD_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\preload.bin","preload files");
            #endif 
        #endif
    #endif /*__GOOGLE_SEARCH_SUPPORT__*/
#endif /*__OP02__*/
/*this line above is for perload.bin configuration, which is mainly for speed dial, bookmark, homepage, search engine config*/

#ifdef OPERA_WEBVIEW
	ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_WEBVIEW_BOOT_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\WebviewAudio\\\\data-ri.rsc","bream data resource file");
	ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_WEBVIEW_SKIN_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\WebviewAudio\\\\skin.rsc","bream skin resource file");
	ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_WEBVIEW_BREAM_A_RESOURCE,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaWebview\\\\bream\\\\a","bream program bin");
#endif

    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\encoding.bin","deployment file1");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_2,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\html40_entities.dtd","deployment file2");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_3,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\operarc","deployment file3");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_4,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\override.ini","deployment file4");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_5,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\wml1_entities.dtd","deployment file5");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_6,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\skin\\\\standard_skin.zip","deployment file6");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_7,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\about.css","deployment file7");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_8,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\bookmarks.css","deployment file8");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_9,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\cache.css","deployment file9");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_10,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\certinfo.css","deployment file10");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_11,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\config.css","deployment file11");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_12,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\contentblock.css","deployment file12");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_13,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\debug.css","deployment file13");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_14,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\dir.css","deployment file14");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_15,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\drives.css","deployment file15");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_16,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\error.css","deployment file16");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_17,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\eula.css","deployment file17");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_18,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\history.css","deployment file18");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_19,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\im.css","deployment file19");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_20,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\image.css","deployment file20");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_21,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\info.css","deployment file21");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_22,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\learn_more.css","deployment file22");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_23,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\mathml.css","deployment file23");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_24,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\message.css","deployment file24");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_25,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\mime.css","deployment file25");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_26,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\opera.css","deployment file26");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_27,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\plugins.css","deployment file27");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_28,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\private.css","deployment file28");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_29,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\search.css","deployment file29");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_30,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\selftest.css","deployment file30");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_31,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\small-wml.css","deployment file31");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_32,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\speeddial.css","deployment file32");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_33,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\warning.css","deployment file33");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_34,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\webfeed.css","deployment file34");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_35,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\webstorage.css","deployment file35");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_36,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\wml.css","deployment file36");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_37,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\bar.png","deployment file37");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_38,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\bkgd-rev.png","deployment file38");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_39,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\bkgd.png","deployment file39");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_40,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\bullet.png","deployment file40");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_41,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\busy_anim.png","deployment file41");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_42,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\center.png","deployment file42");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_43,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\customize.gif","deployment file43");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_44,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\darkBox.png","deployment file44");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_45,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\defaultFavicon.png","deployment file45");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_46,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\error.png","deployment file46");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_47,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\file.png","deployment file47");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_48,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\flag.png","deployment file48");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_49,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\folder.png","deployment file49");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_50,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\hanger.png","deployment file50");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_51,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\header-expanded.png","deployment file51");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_52,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\header.png","deployment file52");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_53,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\link.png","deployment file53");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_54,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\link_hvga.png","deployment file54");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_55,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\link_vga.png","deployment file55");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_56,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\longclick.png","deployment file56");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_57,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\longclick_hvga.png","deployment file57");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_58,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\longclick_vga.png","deployment file58");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_59,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\opera-icon-red.png","deployment file59");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_60,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\opera-icon-white.png","deployment file60");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_61,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\opera.png","deployment file61");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_62,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\Opera_256x256.png","deployment file62");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_63,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\page-bot.png","deployment file63");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_64,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\passwords.png","deployment file64");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_65,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\passwords_hvga.png","deployment file65");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_66,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\passwords_vga.png","deployment file66");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_67,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\red_center.png","deployment file67");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_68,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\red_left.png","deployment file68");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_69,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\red_right.png","deployment file69");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_70,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\reload.gif","deployment file70");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_71,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\root.png","deployment file71");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_72,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\scroll.png","deployment file72");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_73,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\scroll_hvga.png","deployment file73");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_74,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\scroll_vga.png","deployment file74");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_75,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\search.png","deployment file75");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_76,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\section.png","deployment file76");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_77,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\smartGroup.png","deployment file77");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_78,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\speeddial-close-hover.png","deployment file78");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_79,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\speeddial-close.png","deployment file79");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_80,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\speeddial.png","deployment file80");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_81,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\speeddial_hvga.png","deployment file81");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_82,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\speeddial_vga.png","deployment file82");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_83,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\tabs.png","deployment file83");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_84,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\tabs_hvga.png","deployment file84");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_85,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\tabs_vga.png","deployment file85");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_86,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\tooltiptail.png","deployment file86");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_87,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\top.png","deployment file87");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_88,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\top.svg","deployment file88");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_89,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\turbo.png","deployment file89");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_90,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\turbo_hvga.png","deployment file90");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_91,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\turbo_vga.png","deployment file91");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_92,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\images\\\\warning.png","deployment file92");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_93,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\accessibility.css","deployment file93");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_94,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\altdebugger.css","deployment file94");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_95,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\classid.css","deployment file95");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_96,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\contrastbw.css","deployment file96");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_97,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\contrastwb.css","deployment file97");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_98,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\disablebreaks.css","deployment file98");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_99,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\disablefloats.css","deployment file99");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_100,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\disableforms.css","deployment file100");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_101,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\disablepositioning.css","deployment file101");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_102,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\disabletables.css","deployment file102");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_103,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\outline.css","deployment file103");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_104,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\structureblock.css","deployment file104");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_105,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\structureinline.css","deployment file105");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_106,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\structuretables.css","deployment file106");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_107,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\tablelayout.css","deployment file107");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_108,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\styles\\\\user\\\\toc.css","deployment file108");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_109,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\bream\\\\config.ini","deployment file109");
    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_DPF_110,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Audio\\\\OperaMobile\\\\jsplugins\\\\jsplugins.ini","deployment file110");

	ADD_APPLICATION_IMAGE2(IMG_ID_OPERA_MMI_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v1_official\\\\Resource\\\\Images\\\\Opera.ico","Opera icon");

}

#endif /* OPERA_V10_BROWSER */

