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
 *   Res_Opera_v11.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef OPERA_V11_BROWSER

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
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_0, "Unable to connect to the Internet. Please check your settings.", "opera::str_boot_connection_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_1, "Could not start the application.", "opera::str_boot_general_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_2, "Installing...", "opera::str_boot_installing");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_3, "Cannot finish installation because of insufficient storage space.", "opera::str_boot_storage_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_4, "About Opera", "opera::str_about_opera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_5, "Accept", "opera::str_accept");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_6, "Accept cookies", "opera::str_accept_cookies");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_7, "Activate", "opera::str_activate");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_8, "Add", "opera::str_add");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_9, "Add Bookmark", "opera::str_add_bookmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_10, "Add to %s", "opera::str_add_to");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_11, "Add to Home Screen", "opera::str_add_to_home_screen");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_12, "Add %s", "opera::str_add_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_13, "Address", "opera::str_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_14, "Social Networks", "opera::str_address_social_networks");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_15, "Adobe Flash", "opera::str_adobe_flash");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_16, "Advanced", "opera::str_advanced");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_17, "Agree", "opera::str_agree");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_18, "All rights reserved", "opera::str_all_rights_reserved");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_19, "This site wants to use your camera.", "opera::str_allow_page_to_use_camera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_20, "This site wants to know your location.", "opera::str_allow_page_to_use_location");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_21, "Are you sure?", "opera::str_are_you_sure");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_22, "Add", "opera::str_assign");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_23, "Add to Speed Dial", "opera::str_assign_speeddial");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_24, "Back", "opera::str_back");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_25, "Use ALT + click on trackwheel to open menu, and ALT + trackwheel for horizontal scrolling.", "opera::str_bb_navigation_help");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_26, "Navigation Help", "opera::str_bb_navigation_help_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_27, "Bookmarks", "opera::str_bookmarks");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_28, "Loading...", "opera::str_boot_loading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_29, "Please wait while %s gathers information about your fonts. This might take a few minutes.", "opera::str_calc_font_data_desc");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_30, "Font Data Calculation", "opera::str_calc_font_data_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_31, "Wave your device like this to calibrate your compass:", "opera::str_calibrate_compass");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_32, "Cancel", "opera::str_cancel");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_33, "Cancel Editing", "opera::str_cancel_editing");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_34, "Verification of server certificate failed. Please check the date setting in your device.", "opera::str_cert_verification_failed");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_35, "Change", "opera::str_change");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_36, "Check", "opera::str_check");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_37, "Clear", "opera::str_clear");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_38, "Clear All", "opera::str_clear_all");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_39, "Clear cache", "opera::str_clear_cache");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_40, "Are you sure you want to clear the cache?", "opera::str_clear_cache_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_41, "Clear Cache", "opera::str_clear_cache_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_42, "Clear cookies", "opera::str_clear_cookies");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_43, "Clear all saved cookies?", "opera::str_clear_cookies_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_44, "Clear Cookies", "opera::str_clear_cookies_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_45, "Clear history", "opera::str_clear_history");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_46, "You are about to clear your entire browsing history. Do you wish to continue?", "opera::str_clear_history_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_47, "Clear History", "opera::str_clear_history_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_48, "Clear passwords", "opera::str_clear_passwords");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_49, "Clear all saved usernames and passwords?", "opera::str_clear_passwords_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_50, "Clear Passwords", "opera::str_clear_passwords_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_51, "Click to play", "opera::str_click_to_play");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_52, "Close", "opera::str_close");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_53, "Close Tab", "opera::str_close_tab");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_54, "Content blocked by operator.", "opera::str_connection_blocked");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_55, "Problem reading from server.", "opera::str_connection_cannot_read");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_56, "Unable to connect. Please review your network settings.", "opera::str_connection_error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_57, "Internet access not yet available. Would you like to connect through another browser?", "opera::str_connection_error_unknow_data");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_58, "Connection Failed", "opera::str_connection_failed_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_59, "Continue", "opera::str_continue");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_60, "Copy", "opera::str_copy");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_61, "Copyright (c) %s", "opera::str_copyright_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_62, "Create", "opera::str_create");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_63, "Add Search Engine", "opera::str_create_search");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_64, "Cut", "opera::str_cut");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_65, "Data Savings", "opera::str_data_savings_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_66, "Opera Turbo is currently disabled. To save data please enable it.", "opera::str_data_usage_opera_turbo_button_off");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_67, "Opera Turbo is currently enabled.", "opera::str_data_usage_opera_turbo_button_on");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_68, "Original size", "opera::str_data_usage_original_size");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_69, "Received size", "opera::str_data_usage_received_size");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_70, "Reset", "opera::str_data_usage_reset");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_71, "Session", "opera::str_data_usage_session");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_72, "Data Usage", "opera::str_data_usage_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_73, "Total", "opera::str_data_usage_total");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_74, "Default browser", "opera::str_default_browser");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_75, "Delete", "opera::str_delete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_76, "Delete Download", "opera::str_delete_download");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_77, "Delete File", "opera::str_delete_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_78, "Delete Folder", "opera::str_delete_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_79, "Do you want to delete %s and all its contents?", "opera::str_delete_folder_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_80, "Delete \"%s\"?", "opera::str_delete_x_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_81, "Deny", "opera::str_deny");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_82, "Disabled", "opera::str_disabled");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_83, "Disagree", "opera::str_disagree");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_84, "Dismiss", "opera::str_dismiss");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_85, "documents", "opera::str_documents");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_86, "Done", "opera::str_done");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_87, "Download complete", "opera::str_download_complete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_88, "Download failed", "opera::str_download_failed");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_89, "Download Failed", "opera::str_download_failed_caption");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_90, "Downloading %0 failed. Please try again.", "opera::str_download_failed_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_91, "Download File", "opera::str_download_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_92, "Downloading File", "opera::str_downloading_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_93, "Downloads", "opera::str_downloads");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_94, "Edit", "opera::str_edit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_95, "Edit Bookmark", "opera::str_edit_bookmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_96, "Edit Folder", "opera::str_edit_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_97, "Edit Saved Page", "opera::str_edit_saved_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_98, "Edit Search Engine", "opera::str_edit_search_engine");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_99, "Enabled", "opera::str_enabled");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_100, "Enter address", "opera::str_enter_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_101, "Enter Text", "opera::str_enter_text_caption");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_102, "To protect your browsing security some random data is needed.", "opera::str_entropy_needed_1");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_103, "Please press the number keys or move the pointer until the indicator is full.", "opera::str_entropy_needed_2");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_104, "Please tap or drag your finger across the screen until the indicator is full.", "opera::str_entropy_needed_2_touch");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_105, "Error Loading Page", "opera::str_error_loading_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_106, "Update failed. You can open the page and save it manually. Open now?", "opera::str_error_saving_page_load_instead");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_107, "Error Updating Page", "opera::str_error_updating_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_108, "Exit", "opera::str_exit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_109, "Exit button", "opera::str_exit_button");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_110, "There are still active downloads. Do you want to cancel them and close the application?", "opera::str_exit_with_downloads_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_111, "Feeds", "opera::str_feeds");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_112, "Find in Page", "opera::str_find_in_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_113, "Folder", "opera::str_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_114, "Font size", "opera::str_font_size");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_115, "Forward", "opera::str_forward");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_116, "Fullscreen", "opera::str_fullscreen");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_117, "Fullscreen Edit", "opera::str_fullscreen_edit");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_118, "Fullscreen edit", "opera::str_fullscreen_edit_setting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_119, "Go", "opera::str_go");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_120, "Go to Address...", "opera::str_go_to_address");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_121, "Google Privacy Policy", "opera::str_google_location_link_pp");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_122, "Google Terms of Service", "opera::str_google_location_link_tos");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_123, "To share your location you must agree to:", "opera::str_google_location_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_124, "Terms of Service", "opera::str_google_location_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_125, "Help", "opera::str_help");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_126, "History", "opera::str_history");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_127, "Image quality", "opera::str_image_quality");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_128, "High", "opera::str_image_quality_high");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_129, "Low", "opera::str_image_quality_low");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_130, "Medium", "opera::str_image_quality_medium");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_131, "Import", "opera::str_import");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_132, "Import Bookmark", "opera::str_import_bookmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_133, "Information", "opera::str_information");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_134, "Invalid Profile", "opera::str_invalid_network_profile");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_135, "This item is read-only and cannot be modified.", "opera::str_item_modification_denied_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_136, "Landscape", "opera::str_landscape");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_137, "Large", "opera::str_large");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_138, "Learn more", "opera::str_learn_more");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_139, "Email", "opera::str_link_auth_email");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_140, "Please enter email address.", "opera::str_link_auth_email_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_141, "Email address already in use.", "opera::str_link_auth_email_inuse");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_142, "Invalid email address.", "opera::str_link_auth_email_invalid");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_143, "Logging in...", "opera::str_link_auth_login_progress");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_144, "Password", "opera::str_link_auth_password");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_145, "Please enter password.", "opera::str_link_auth_password_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_146, "The password is too short.", "opera::str_link_auth_password_invalid");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_147, "Creating user...", "opera::str_link_auth_signup_progress");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_148, "Username", "opera::str_link_auth_username");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_149, "Please enter username.", "opera::str_link_auth_username_empty");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_150, "Username already in use.", "opera::str_link_auth_username_inuse");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_151, "Username contains invalid characters.", "opera::str_link_auth_username_invalid");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_152, "Username is too short.", "opera::str_link_auth_username_short");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_153, "Wrong username or password.", "opera::str_link_auth_wrong_credentials");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_154, "I have an account", "opera::str_link_have_account");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_155, "Opera Link is a free service that synchronizes your bookmarks, Speed Dial, and search engines between all your computers and phones.", "opera::str_link_intro");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_156, "Login", "opera::str_link_login_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_157, "Sign Up", "opera::str_link_signup_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_158, "You are switching Opera accounts. Another Opera user has synchronized his or her data with this device. If you continue, all existing bookmarks, Speed Dial entries and search engines will be erased from this device. Do you want to continue?", "opera::str_link_switch_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_159, "Your browser data has been synchronized.", "opera::str_link_sync_complete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_160, "Synchronizing your data...", "opera::str_link_sync_progress");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_161, "Reload Image in Full Quality", "opera::str_load_full_quality_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_162, "Load images", "opera::str_load_images");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_163, "Loading", "opera::str_loading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_164, "Login", "opera::str_login");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_165, "Manage", "opera::str_manage");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_166, "Manage Search Engines", "opera::str_manage_search_engines");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_167, "Mark", "opera::str_mark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_168, "Medium", "opera::str_medium");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_169, "Menu", "opera::str_menu");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_170, "Minimize", "opera::str_minimize");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_171, "Move", "opera::str_move");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_172, "music", "opera::str_music");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_173, "Name", "opera::str_name");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_174, "Navigation bar", "opera::str_navigation_bar");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_175, "The network is available now, press YES to switch to a new tab and start browsing internet with Opera Turbo.", "opera::str_network_available_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_176, "Network Available", "opera::str_network_available_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_177, "Network Profile", "opera::str_network_profile");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_178, "Network test...", "opera::str_network_test");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_179, "New Folder", "opera::str_new_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_180, "Next", "opera::str_next");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_181, "No", "opera::str_no");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_182, "No matches found.", "opera::str_no_matches_found");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_183, "There is not enough disk space available (%0) to download this file (%1). Do you want to continue?", "opera::str_not_enough_space_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_184, "Not Enough Disk Space", "opera::str_not_enough_space_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_185, "Not Supported", "opera::str_not_supported_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_186, "Off", "opera::str_off");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_187, "OK", "opera::str_ok");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_188, "Older", "opera::str_older");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_189, "On", "opera::str_on");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_190, "Open", "opera::str_open");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_191, "Open Image", "opera::str_open_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_192, "Open in New Tab", "opera::str_open_in_new_tab");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_193, "Opera Link", "opera::str_opera_link");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_194, "Options", "opera::str_options");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_195, "Other...", "opera::str_other");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_196, "Out of Memory", "opera::str_out_of_memory");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_197, "This page has been cleared to save memory. Please press Reload to visit it again.", "opera::str_out_of_memory_browser_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_198, "The system is running low on memory and cannot display the page correctly. You can try to display more of the page content by reloading the page or clearing the history.", "opera::str_out_of_memory_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_199, "Password", "opera::str_password");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_200, "Paste", "opera::str_paste");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_201, "Pause", "opera::str_pause");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_202, "pictures", "opera::str_pictures");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_203, "Place", "opera::str_place");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_204, "%s Bookmarks", "opera::str_platform_bookmarks");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_205, "Please wait while the page is updating.", "opera::str_please_wait_downloading_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_206, "Plug-ins", "opera::str_plugins");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_207, "Press", "opera::str_press");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_208, "Privacy", "opera::str_privacy");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_209, "Connecting", "opera::str_progress_connecting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_210, "Loading", "opera::str_progress_loading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_211, "Uploading", "opera::str_progress_uploading");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_212, "Reload", "opera::str_reload");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_213, "Remember choice", "opera::str_remember_choice");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_214, "Remember Password", "opera::str_remember_password_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_215, "Remember passwords", "opera::str_remember_passwords");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_216, "Remove from Bookmarks", "opera::str_remove_from_bookmarks");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_217, "Remove from Speed Dial", "opera::str_remove_from_speeddial");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_218, "Restart", "opera::str_restart");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_219, "Resume", "opera::str_resume");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_220, "Retry", "opera::str_retry");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_221, "Safe Mode", "opera::str_safe_mode");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_222, "Opera Mini is running in safe mode. All extensions are currently disabled.", "opera::str_safe_mode_desc");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_223, "Save", "opera::str_save");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_224, "Save Image...", "opera::str_save_image");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_225, "Save Page", "opera::str_save_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_226, "Failed to Save Page", "opera::str_save_page_fail");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_227, "Failed to save the page", "opera::str_save_page_fail_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_228, "This page needs to be updated in order to work in this version of Opera Mini. Update now?", "opera::str_save_page_redownload_question");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_229, "Save %s", "opera::str_save_x");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_230, "Saved Pages", "opera::str_saved_pages");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_231, "Saving Page", "opera::str_saving_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_232, "The protocol used in %O is not supported", "opera::str_scheme_not_supported");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_233, "Search", "opera::str_search");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_234, "Do you want to search again?", "opera::str_search_again_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_235, "Not found", "opera::str_search_fail_caption");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_236, "Search With...", "opera::str_search_with");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_237, "Security", "opera::str_security");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_238, "Security Warning", "opera::str_security_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_239, "Select", "opera::str_select");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_240, "Select a folder...", "opera::str_select_a_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_241, "Select folder for saving pages.", "opera::str_select_dir_save_page_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_242, "Select File", "opera::str_select_file");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_243, "Select Folder", "opera::str_select_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_244, "Select Text", "opera::str_select_text");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_245, "Click to select start and end position.", "opera::str_select_text_keyboard_hybrid_info");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_246, "Select your starting position. Press \"Start\" where you want to start selecting text.", "opera::str_select_text_keyboard_info");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_247, "There are active network connections, change profile will close all of them, would you like to continue?", "opera::str_set_network_profile");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_248, "Saved pages folder...", "opera::str_set_saved_pages_folder");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_249, "Settings", "opera::str_settings");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_250, "Share", "opera::str_share");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_251, "Share Location", "opera::str_share_location");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_252, "Show", "opera::str_show");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_253, "Sign Up", "opera::str_sign_up");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_254, "Single column view", "opera::str_single_column_view");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_255, "Small", "opera::str_small");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_256, "sounds", "opera::str_sounds");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_257, "Start", "opera::str_start");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_258, "Start Page", "opera::str_start_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_259, "Start page links", "opera::str_start_page_links_setting");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_260, "Status bar", "opera::str_status_bar");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_261, "Stop", "opera::str_stop");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_262, "Suggestions", "opera::str_suggestions");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_263, "Third parties", "opera::str_third_parties");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_264, "Title", "opera::str_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_265, "Today", "opera::str_today");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_266, "Tools", "opera::str_tools");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_267, "Touchscreen feedback", "opera::str_touchscreen_feedback");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_268, "Unable to Save Page", "opera::str_unable_to_save_page");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_269, "The current page is loaded from a saved page and cannot be saved again.", "opera::str_unable_to_save_page_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_270, "Uncheck", "opera::str_uncheck");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_271, "Unmark", "opera::str_unmark");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_272, "Use", "opera::str_use");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_273, "Use Camera", "opera::str_use_camera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_274, "Username", "opera::str_username");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_275, "Version", "opera::str_version");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_276, "video", "opera::str_video");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_277, "Always", "opera::str_virtual_keyboard_always");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_278, "Never", "opera::str_virtual_keyboard_never");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_279, "Only for addresses", "opera::str_virtual_keyboard_only_addresses");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_280, "Opera keyboard", "opera::str_virtual_keyboard_opera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_281, "Replace existing username and password?", "opera::str_wand_replace_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_282, "Save username and password?", "opera::str_wand_save_confirm");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_283, "Warning", "opera::str_warning");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_284, "This site needs more than %0 of storage space on your device. Allow?", "opera::str_webstorage_quota_increase");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_285, "Network is not available. You might be connected to a WIFI hotspot which requires authentication, would you like to start the authentication process?", "opera::str_wifi_auth_message");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_286, "WIFI Authentication", "opera::str_wifi_auth_title");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_287, "Text wrapping", "opera::str_wrap_text");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_288, "Yes", "opera::str_yes");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_289, "Yesterday", "opera::str_yesterday");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_290, "Zoom", "opera::str_zoom");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_291, "Zoom In", "opera::str_zoom_in");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_292, "Zoom Out", "opera::str_zoom_out");
/*---bream resource generated code---*/

/*---language resource generated code---*/
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_0, "The date %1 is not allowed for this form. Only certain dates are allowed for this field.", "LNG:0");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_1, "Warning", "LNG:1");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_2, "Help", "LNG:2");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_3, "Unable to verify the website's identity (OCSP error).", "LNG:3");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_4, "This page may not be secure. For details, see the security tab.\n\nYou need to approve or reject the loading of this page.", "LNG:4");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_5, "Certificate version", "LNG:5");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_6, "XML parsing failed", "LNG:6");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_7, "Ins", "LNG:7");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_8, "The certificate is valid, but permission denied.", "LNG:8");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_9, "The certificate for \"%1\" is signed by the unknown Certificate Authority \"%2\". It is not possible to verify that this is a valid certificate.", "LNG:9");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_10, "You tried to access the address %s, which is currently unavailable. Please make sure that the web address (URL) is correctly spelled and punctuated, then try reloading the page.", "LNG:10");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_11, "You are about to send a request to this server. Continue?", "LNG:11");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_12, "Exponent:", "LNG:12");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_13, "Reparse document as HTML", "LNG:13");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_14, "A different client certificate is already installed for this key. Installation failed.", "LNG:14");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_15, "Connecting to remote host %s...", "LNG:15");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_16, "Star", "LNG:16");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_17, "Loading of external frame source <a href=\"%s\">%s</a> suppressed (click to view).", "LNG:17");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_18, "DH Public Key", "LNG:18");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_19, "Tabbed browsing", "LNG:19");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_20, "No matches found", "LNG:20");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_21, "Always continue when data is requested from my computer", "LNG:21");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_22, "syntax error", "LNG:22");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_23, "Name", "LNG:23");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_24, "Size", "LNG:24");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_25, "Time", "LNG:25");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_26, "Type", "LNG:26");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_27, "Show all", "LNG:27");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_28, "Accept", "LNG:28");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_29, "The online certificate validation (OCSP) server reports that validation failed because the server is offline, please try again later.", "LNG:29");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_30, "Could not connect to remote server", "LNG:30");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_31, "Redirection Status", "LNG:31");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_32, "Do you want to import the private key and these attached certificate(s)?", "LNG:32");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_33, "By long-clicking with your finger, you can perform actions such as opening a link in a new tab, editing a Speed Dial, and copying and pasting text.", "LNG:33");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_34, "Modulus:", "LNG:34");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_35, "Plug-in disabled", "LNG:35");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_36, "Choose...", "LNG:36");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_37, "Automatic Proxy Configuration failed. \nProxy Configuration is automatically disabled for this session.", "LNG:37");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_38, "The encryption method used by the server is not considered secure.", "LNG:38");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_39, "PageUp", "LNG:39");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_40, "This certificate was downloaded from \"%1\" using a connection that is not secure", "LNG:40");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_41, "Size", "LNG:41");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_42, "Reload", "LNG:42");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_43, "Select Certificate", "LNG:43");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_44, "Opera was not able to connect to the server, because the server does not communicate via any secure protocol known to Opera.", "LNG:44");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_45, "Warning: While decoding this file Opera encountered errors.", "LNG:45");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_46, "The online certificate validation (OCSP) server reports that validation failed because the request should have been signed.", "LNG:46");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_47, "Security is disabled.", "LNG:47");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_48, "Browse several websites at the same time, switching between sites with ease.", "LNG:48");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_49, "Server certificate expired", "LNG:49");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_50, "Low encryption level", "LNG:50");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_51, "Open in background tab", "LNG:51");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_52, "The address %s is blocked by the content blocker.", "LNG:52");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_53, "Open the <a href=\"http://www.opera.com/mobile/help/\">Opera Help</a>.", "LNG:53");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_54, "Network socket resource problems. Try again", "LNG:54");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_55, "Opera has detected that this website does not have consistent support for secure TLS renegotiation. Connections to those parts of the site lacking this support will be refused. The site owner must fix the site.", "LNG:55");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_56, "Image", "LNG:56");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_57, "Remote server or file not found", "LNG:57");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_58, "Public key", "LNG:58");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_59, "December", "LNG:59");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_60, "Unable to complete secure transaction", "LNG:60");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_61, "Signature algorithm", "LNG:61");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_62, "Address not available from this machine", "LNG:62");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_63, "The presented certificate has an unknown Certificate Authority.", "LNG:63");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_64, "To get started, scroll down to the End User License Agreement and press <b>%s</b>!", "LNG:64");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_65, "Internal communication error", "LNG:65");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_66, "Preview", "LNG:66");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_67, "%u bit private key. Generated %s.\nURL: %s", "LNG:67");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_68, "The server initiated TLS renegotiation; it was denied by Opera, because the server does not support secure renegotiation. The site owner must patch the server. Continuing without renegotiation.", "LNG:68");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_69, "Cached Items", "LNG:69");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_70, "Click for plug-in", "LNG:70");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_71, "Wrong format!", "LNG:71");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_72, "Please enter a valid web address", "LNG:72");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_73, "The loading of the URL has been blocked for security reasons.", "LNG:73");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_74, "Resent-From", "LNG:74");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_75, "Stop", "LNG:75");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_76, "July", "LNG:76");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_77, "June", "LNG:77");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_78, "March", "LNG:78");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_79, "URLs cached", "LNG:79");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_80, "HTTP gateway timed out", "LNG:80");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_81, "Address not found:", "LNG:81");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_82, "Newsgroups", "LNG:82");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_83, "Bcc", "LNG:83");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_84, "The certificate for \"%1\" is not valid before %2. Is the clock on your computer correct?", "LNG:84");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_85, "Unknown error detected.", "LNG:85");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_86, "Export all domains", "LNG:86");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_87, "DSA Component G", "LNG:87");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_88, "DSA Component P", "LNG:88");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_89, "DSA Component Q", "LNG:89");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_90, "Private Key (X)", "LNG:90");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_91, "Public Key (Y)", "LNG:91");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_92, "This site specifies a level of encryption that is not secure. You have manually disabled some of the strongest encryption methods, and this may have forced the server to select the current level. We recommend that you re-enable strong encryption before proceeding. Do you wish to continue using a low encryption level?", "LNG:92");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_93, "Please enter the new master password", "LNG:93");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_94, "Preview all domains", "LNG:94");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_95, "HTTP gateway failed", "LNG:95");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_96, "Unknown extension object ID ", "LNG:96");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_97, "Connected to", "LNG:97");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_98, "Network socket blocking", "LNG:98");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_99, "Settings saved", "LNG:99");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_100, "There seems to be a problem on this server.\n\nIf loading does not finish properly, please stop the request and re-submit the form.", "LNG:100");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_101, "Proxy authentication failed. Content should not be trusted.", "LNG:101");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_102, "The server did not recognize the content type", "LNG:102");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_103, "Please choose an application to open the %1: link:", "LNG:103");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_104, "Error", "LNG:104");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_105, "To start browsing, type an address, or select a Speed Dial or bookmark. Zoom in with a tap, and scroll effortlessly with the flick of a finger.", "LNG:105");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_106, "Password", "LNG:106");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_107, "Your certificate has been installed, and you can use it, but Opera could not verify it. The signer of this certificate is missing. Please install the signer's certificate if available.", "LNG:107");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_108, "The server's certificate held an invalid name expression", "LNG:108");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_109, "Secure connection: fatal error (%u)", "LNG:109");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_110, "Vega backend", "LNG:110");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_111, "The HTTP address is too long", "LNG:111");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_112, "(Memory)", "LNG:112");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_113, "HTTP request data was too long", "LNG:113");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_114, "The certificate was revoked because a newer certificate has been issued.", "LNG:114");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_115, "Reply-to", "LNG:115");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_116, "Save", "LNG:116");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_117, "Software", "LNG:117");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_118, "Transmission failure.", "LNG:118");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_119, "Always continue when data is requested from my computer", "LNG:119");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_120, "Subject", "LNG:120");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_121, "This Winsock implementation lacks important functionality.", "LNG:121");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_122, "Frame content not displayed", "LNG:122");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_123, "Disconnect", "LNG:123");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_124, "Could not access proxy server. Server is not available", "LNG:124");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_125, "%s is missing", "LNG:125");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_126, "Not valid after", "LNG:126");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_127, "Warning: Web Address Contains a Username", "LNG:127");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_128, "Remote server accepted the request - no content returned", "LNG:128");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_129, "Wrong certificate name", "LNG:129");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_130, "Form validation failed", "LNG:130");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_131, "Extensions", "LNG:131");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_132, "Browser identification", "LNG:132");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_133, "Back", "LNG:133");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_134, "Generated by Opera.", "LNG:134");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_135, "Fri", "LNG:135");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_136, "bits", "LNG:136");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_137, "Up", "LNG:137");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_138, "Certificate Authorities", "LNG:138");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_139, "The online certificate validation (OCSP) server reports that validation failed because you are not authorized to validate this certificate.", "LNG:139");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_140, "The key of the certificate was encrypted using an unsupported method, possibly one that is not considered strong enough.", "LNG:140");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_141, "Repeated attempts failed to load this page completely.\n\nThere may be a problem on the server.", "LNG:141");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_142, " (Critical)", "LNG:142");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_143, "The server timed out", "LNG:143");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_144, "Could not write to file. Disk full.", "LNG:144");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_145, "Authentication failed. Content should not be trusted.", "LNG:145");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_146, "The address is no longer available", "LNG:146");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_147, "A page on your private intranet requests data from your computer. For security reasons, automatic access is blocked, but you may choose to continue.", "LNG:147");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_148, "contains a port number that is not in the range 1 to 65535.", "LNG:148");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_149, "Opera Link", "LNG:149");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_150, "Week", "LNG:150");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_151, "The server is using an outdated security protocol version.", "LNG:151");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_152, "Go Online", "LNG:152");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_153, "The server's name \"%1\" does not match the certificate's name \"%2\". Somebody may be trying to eavesdrop on you.", "LNG:153");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_154, "The server could not send the requested part of the file", "LNG:154");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_155, "Personal certificates", "LNG:155");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_156, "Failed to connect to server. The reason may be that the encryption methods supported by the server are not enabled in the security preferences.\n\nPlease note that some encryption methods are no longer supported, and that access will not be possible until the website has been upgraded to use strong encryption.", "LNG:156");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_157, "An internal error occurred.", "LNG:157");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_158, "Alt", "LNG:158");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_159, "End", "LNG:159");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_160, "Tab", "LNG:160");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_161, "Linked script not loaded", "LNG:161");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_162, "A client certificate uniquely identifies you during transactions.\n\nInstall this client certificate?", "LNG:162");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_163, "Invalid, or non-verifiable certificate.", "LNG:163");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_164, "Mon", "LNG:164");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_165, "The website does not permit its content to be displayed in a frame. It must be displayed in a separate window.", "LNG:165");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_166, "Filename", "LNG:166");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_167, "Backspace", "LNG:167");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_168, "No acceptable SSL/TLS encryption methods found.", "LNG:168");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_169, "Access to this port is disabled for security reasons", "LNG:169");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_170, "Activated 40 second timeout. Waiting for data...", "LNG:170");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_171, "Quick find", "LNG:171");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_172, "Could not locate remote server", "LNG:172");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_173, "Executing JavaScript...", "LNG:173");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_174, "Click on the star to save your favorite webpages.", "LNG:174");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_175, "Open in new tab", "LNG:175");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_176, "Default", "LNG:176");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_177, "These are the personal certificates registered in the database.", "LNG:177");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_178, "Incorrect Winsock version", "LNG:178");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_179, "prime1:", "LNG:179");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_180, "prime2:", "LNG:180");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_181, "Signature", "LNG:181");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_182, "Security warning", "LNG:182");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_183, "Click for info", "LNG:183");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_184, "Open file", "LNG:184");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_185, "Wednesday", "LNG:185");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_186, "Searching for complete server name...", "LNG:186");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_187, "Access denied to this file", "LNG:187");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_188, "Sun", "LNG:188");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_189, "Could not connect to remote server", "LNG:189");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_190, "Address", "LNG:190");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_191, "The file %1 is too large. It must be %2 bytes or smaller.", "LNG:191");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_192, "Connecting to proxy...", "LNG:192");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_193, "%1 requests access to your camera.", "LNG:193");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_194, "Offline mode is enabled. Cannot open\n\n%s\n\nDo you want to switch to online mode?", "LNG:194");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_195, "Opera Turbo", "LNG:195");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_196, "Specification:", "LNG:196");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_197, "All encryption methods are disabled in Preferences.", "LNG:197");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_198, "Javascript Confirm", "LNG:198");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_199, "Security warning:\n\nYou are about to go to an address containing a username.\n\nUsername: %s \nServer: %s\n\nAre you sure you want to go to this address?", "LNG:199");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_200, "The certificate was revoked because the Certificate Authority has been compromised, and some or all certificates issued by this authority can no longer be trusted.", "LNG:200");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_201, "Tue", "LNG:201");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_202, "AM", "LNG:202");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_203, "The certificate for \"%1\" expired %2. The webmaster should update the certificate(s).", "LNG:203");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_204, "Opera's servers compress webpages up to 70%, greatly reducing the cost of browsing.", "LNG:204");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_205, "October", "LNG:205");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_206, "Connection", "LNG:206");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_207, "Fingerprint", "LNG:207");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_208, "Unknown protocol", "LNG:208");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_209, "Scroll at warp speed using your phone's keypad. Hit 2 to go up, 4 to go left, 6 to go right and 8 to go down. %s snaps the view to the content. Hit 5 to zoom in and out.", "LNG:209");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_210, "Completed request to %s", "LNG:210");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_211, "To start browsing, type an address, or select a Speed Dial or bookmark. Zoom in with a single click, and scroll effortlessly with the keypad.", "LNG:211");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_212, "Connecting to network/modem...", "LNG:212");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_213, "This certificate has expired. You should delete it, and install an updated certificate.", "LNG:213");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_214, "Uploading file(s) to server", "LNG:214");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_215, "Enter", "LNG:215");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_216, "Right", "LNG:216");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_217, "Shift", "LNG:217");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_218, "Space", "LNG:218");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_219, "Error", "LNG:219");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_220, "Could not verify the signatures for the site certificate's revocation information.", "LNG:220");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_221, "Secure connection: fatal error (%u) from server.", "LNG:221");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_222, "Invalid address", "LNG:222");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_223, "This document had an invalid XSLT stylesheet. Error message from the XSLT engine:", "LNG:223");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_224, "The certificate was revoked because the site has changed owners.", "LNG:224");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_225, "Wed", "LNG:225");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_226, "This site is using an outdated encryption method which is no longer classified as secure. It cannot sufficiently protect sensitive data. Do you wish to continue?", "LNG:226");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_227, "Other...", "LNG:227");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_228, "The input is not valid.", "LNG:228");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_229, "Basic Authentication: Clear text", "LNG:229");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_230, "A page on the public Internet requests data from your private intranet. For security reasons, automatic access is blocked, but you may choose to continue.", "LNG:230");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_231, "Looking up hostname %s...", "LNG:231");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_232, "Character:", "LNG:232");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_233, "Version", "LNG:233");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_234, "The server's certificate did not match its hostname. Accept?", "LNG:234");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_235, "The proxy server requested a login authentication method that is not supported.", "LNG:235");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_236, "Close tab", "LNG:236");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_237, "This URL is not in the list of URLs that can be authenticated by the given realm.\nCannot send Authentication credentials.", "LNG:237");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_238, "Introduction", "LNG:238");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_239, "Waiting (#%2) for connection to %1", "LNG:239");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_240, "Maximum size(KB)", "LNG:240");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_241, "Internal program error.", "LNG:241");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_242, "publicExponent:", "LNG:242");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_243, "Apr", "LNG:243");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_244, "Aug", "LNG:244");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_245, "Dec", "LNG:245");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_246, "Feb", "LNG:246");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_247, "Jan", "LNG:247");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_248, "Jul", "LNG:248");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_249, "Jun", "LNG:249");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_250, "Mar", "LNG:250");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_251, "May", "LNG:251");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_252, "Nov", "LNG:252");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_253, "Oct", "LNG:253");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_254, "Sep", "LNG:254");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_255, "The certificate installation failed.", "LNG:255");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_256, "Valid to", "LNG:256");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_257, "Not valid before", "LNG:257");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_258, "The server does not support secure TLS renegotiation. The site owner should upgrade the server.", "LNG:258");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_259, "Third parties", "LNG:259");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_260, "Handshake failed due to export restrictions.", "LNG:260");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_261, "Please choose an application to open the following content type:\n%1", "LNG:261");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_262, "Reset", "LNG:262");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_263, "Network socket problems. Please check your network drivers.", "LNG:263");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_264, "Please enter master password", "LNG:264");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_265, "May", "LNG:265");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_266, "November", "LNG:266");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_267, "Setting up secure connection...", "LNG:267");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_268, "This is a searchable index", "LNG:268");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_269, "Always continue when data is requested from this server on my private intranet", "LNG:269");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_270, "%1 wants to know your current location.", "LNG:270");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_271, "Followup-To", "LNG:271");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_272, "The server requests identification in the form of a client certificate.\n\nYou may send one of the following certificates:", "LNG:272");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_273, "Save Image", "LNG:273");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_274, "Problem encountered while decoding data. Possibly due to corrupted data.", "LNG:274");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_275, "Synchronize your bookmarks, Speed Dial, and search engines between your mobile phone and desktop computer. To get started, enable Opera Link from the settings menu.", "LNG:275");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_276, "HTTP preconditions failed", "LNG:276");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_277, "The certificate was revoked because the key associated with the certificate has been compromised, and the certificate cannot be trusted.", "LNG:277");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_278, "The endpoint was not in an appropriate state", "LNG:278");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_279, "To use a client certificate, Opera requires your master password.", "LNG:279");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_280, "Organization", "LNG:280");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_281, "Domain", "LNG:281");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_282, "Connection closed by remote server", "LNG:282");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_283, "Tuesday", "LNG:283");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_284, "Too many files specified. You listed %1 and maximum is %2.", "LNG:284");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_285, "Plug-in is missing for this content. Click the placeholder to install the plug-in.", "LNG:285");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_286, "Internal cache error", "LNG:286");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_287, "Export", "LNG:287");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_288, "The certificate was revoked because this site is no longer in operation", "LNG:288");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_289, "The response from the online certificate validation (OCSP) server was too old.", "LNG:289");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_290, "Invalid OBML configuration", "LNG:290");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_291, "Build", "LNG:291");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_292, "Java security", "LNG:292");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_293, "Folder Listing", "LNG:293");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_294, "Strong warning: this feature enables remote debugging. By connecting to the indicated IP address, you give unrestricted access to your entire browser session.", "LNG:294");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_295, "For your safety, only connect to a trusted source.", "LNG:295");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_296, "Some changes may require a restart to take effect.", "LNG:296");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_297, "Go to <a href=\"http://www.opera.com/support/\">Opera's online support desk</a>.", "LNG:297");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_298, "The server initiated TLS renegotiation; it was permitted by Opera, although the server does not support secure renegotiation. The site owner should patch the server.", "LNG:298");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_299, "Failed to connect to debugger at", "LNG:299");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_300, "September", "LNG:300");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_301, "None", "LNG:301");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_302, "You have been denied access to this WML deck.\n\nYou have not reached this deck in the correct order.", "LNG:302");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_303, "Secure connection: warning (%u) from server", "LNG:303");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_304, "The server wants to negotiate a connection that does *not* encrypt the data, but only verifies integrity. If you continue, the data can be read by anyone, but not modified.", "LNG:304");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_305, "Today", "LNG:305");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_306, "DH Generator", "LNG:306");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_307, "DH Modulus", "LNG:307");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_308, "Please set a master password to protect your client certificates and saved passwords", "LNG:308");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_309, "Wrong password, please enter the correct master password", "LNG:309");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_310, "The remote server lacks necessary functionality", "LNG:310");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_311, "KB", "LNG:311");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_312, "Please Confirm", "LNG:312");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_313, "%1 specified one or more files that could not be found", "LNG:313");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_314, "Go to your favorite webpages with just one click, using a set of visual bookmarks.", "LNG:314");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_315, "Certificate authorities certify the identity of websites. You should only install certificate authorities from sites you trust.\n\nInstall this certificate authority?", "LNG:315");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_316, "Transmission stopped!", "LNG:316");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_317, "Javascript Alert", "LNG:317");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_318, "Open transport error", "LNG:318");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_319, "Cc", "LNG:319");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_320, "To", "LNG:320");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_321, "HTTP content length was required", "LNG:321");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_322, "Issuer", "LNG:322");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_323, "The certificate for \"%1\" does not contain all the required information", "LNG:323");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_324, "Server name:", "LNG:324");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_325, "Remote server timed out. Please try again later.", "LNG:325");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_326, "Could not find proxy server", "LNG:326");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_327, "Please enter a number", "LNG:327");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_328, "The remote server refuses to perform the request.\nThis address is not available.", "LNG:328");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_329, "JavaScript", "LNG:329");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_330, "Forward", "LNG:330");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_331, "The certificate is unknown.", "LNG:331");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_332, "Port number", "LNG:332");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_333, "Request queued for sending to %s...", "LNG:333");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_334, "Browse for Folder", "LNG:334");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_335, "Could not verify the site certificate's signatures. The issuer may be using the wrong method to sign the certificate, or someone may have attempted to modify or fake the certificate.", "LNG:335");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_336, "Certificate expired", "LNG:336");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_337, "Certificate Name", "LNG:337");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_338, "DH Private Key", "LNG:338");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_339, "HTTP expectation failed", "LNG:339");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_340, "modulus:", "LNG:340");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_341, "One of the certificates presented by the server has expired. Do you wish to accept the certificate?", "LNG:341");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_342, "There was an error in the response returned by the online certificate validation (OCSP) server.", "LNG:342");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_343, "The server tried redirecting to an invalid address.\nPlease report this to the webmaster of the site.", "LNG:343");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_344, "session cookie", "LNG:344");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_345, "Unknown server", "LNG:345");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_346, "The certificate has been revoked by its issuer. It is no longer valid. In the worst case it may be used by criminals for fraudulent purposes. The website owner must immediately replace the certificate.", "LNG:346");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_347, "Date", "LNG:347");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_348, "From", "LNG:348");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_349, "Network not available. Contact your system administrator.", "LNG:349");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_350, "Cannot display content. <a href=\"%s\">Download %s.</a>", "LNG:350");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_351, "Could not connect to proxy server", "LNG:351");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_352, "Power scrolling", "LNG:352");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_353, "Payment Required", "LNG:353");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_354, "Line:", "LNG:354");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_355, "<no username found>", "LNG:355");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_356, "The server's certificate chain is incomplete, and the signer(s) are not registered. Accept?", "LNG:356");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_357, "Receiving data from %s...", "LNG:357");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_358, "Out of memory.", "LNG:358");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_359, "Customize preferences for the following host(s)", "LNG:359");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_360, "These are the certificate authorities registered in the database.", "LNG:360");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_361, "exponent1:", "LNG:361");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_362, "exponent2:", "LNG:362");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_363, "You have asked to be warned about certificates from \"%1\"", "LNG:363");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_364, "Import key and certificate", "LNG:364");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_365, "Attempt to connect to secure server could not be completed, and automatic reconnection was not possible. Please try again.", "LNG:365");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_366, "Please enter the old master password", "LNG:366");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_367, "You need to enable JavaScript to use this document. Then reload the page.", "LNG:367");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_368, "Load document in a new window", "LNG:368");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_369, "The address type is unknown or unsupported", "LNG:369");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_370, "This is a required field", "LNG:370");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_371, "The server was unable to send acceptable data", "LNG:371");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_372, "The URL", "LNG:372");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_373, "contains characters that are not valid in the location they are found.", "LNG:373");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_374, "Cookie Offered", "LNG:374");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_375, "Welcome to %s!", "LNG:375");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_376, "Move up", "LNG:376");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_377, "Unknown signature algorithm ", "LNG:377");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_378, "The response from the online certificate validation (OCSP) server could not be validated.", "LNG:378");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_379, "cookie", "LNG:379");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_380, "Security operations are not available.", "LNG:380");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_381, "Please click to download and activate plug-in.", "LNG:381");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_382, "Certificate warning", "LNG:382");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_383, "PageDown", "LNG:383");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_384, "External email frame", "LNG:384");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_385, "Waiting for DNS confirmation of cookie domain(s)...", "LNG:385");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_386, "The online certificate validation (OCSP) server reports that validation failed because of an unspecified server error.", "LNG:386");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_387, "Security Issue", "LNG:387");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_388, "New tab", "LNG:388");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_389, "The online certificate validation (OCSP) server reports that validation failed because of an unknown error.", "LNG:389");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_390, "The number %1 is not allowed for this form. Only certain numbers are allowed for this field.", "LNG:390");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_391, "Unknown algorithm", "LNG:391");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_392, "File does not exist", "LNG:392");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_393, "Warning: Cross Network Request", "LNG:393");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_394, "Could not open file", "LNG:394");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_395, "Submit", "LNG:395");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_396, "Please enter a number greater than or equal to %2", "LNG:396");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_397, "Web Address Blocked", "LNG:397");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_398, "About Opera", "LNG:398");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_399, "The server is using a short public encryption key, which is not considered to be secure.", "LNG:399");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_400, "The reason for the problem may be a mistyped URL, but the URL may also be an attempt to trick you into visiting a website which you might mistake for a site you trust.", "LNG:400");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_401, "Handshake failed because the server requires encryption methods more secure than those enabled.", "LNG:401");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_402, "Drives", "LNG:402");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_403, "The entered text is too large! You used %1 letters and the limit is %2.", "LNG:403");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_404, "Friday", "LNG:404");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_405, "Network problem", "LNG:405");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_406, "B", "LNG:406");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_407, "Install Certificate", "LNG:407");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_408, "The URL was redirected to %s. Please click the link to go there.", "LNG:408");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_409, "You can enable the automatic redirection in Preferences.", "LNG:409");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_410, "privateExponent:", "LNG:410");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_411, "Minimum size(KB)", "LNG:411");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_412, "Remove", "LNG:412");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_413, "Opera Software is grateful to the groups and individuals above for their contributions.", "LNG:413");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_414, "Sat", "LNG:414");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_415, "Continue", "LNG:415");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_416, "Unknown fieldname", "LNG:416");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_417, "April", "LNG:417");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_418, "Do you want to import the private key stored in this file?", "LNG:418");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_419, "Conflict with existing resource on server", "LNG:419");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_420, "The HTTP version was not accepted", "LNG:420");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_421, "Do you want to allow local JavaScript files to control secure pages? You should only allow this if you know what your JavaScript files contain and understand the security implications.", "LNG:421");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_422, "Changing the master password failed.", "LNG:422");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_423, "Install Certificate", "LNG:423");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_424, "coefficient:", "LNG:424");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_425, "This certificate cannot be used for this purpose.", "LNG:425");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_426, "Click to manage plug-ins", "LNG:426");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_427, "The service is overloaded or offline. Please try again later.", "LNG:427");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_428, "Handshake failed because the server does not want to accept the enabled SSL/TLS protocol versions.", "LNG:428");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_429, "The HTTP request method was not accepted by the server", "LNG:429");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_430, "Need help?", "LNG:430");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_431, "Private key", "LNG:431");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_432, "Preferences Editor", "LNG:432");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_433, "Saturday", "LNG:433");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_434, "The address is too long.", "LNG:434");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_435, "Thu", "LNG:435");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_436, "Public key algorithm", "LNG:436");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_437, "You can accept or refuse this %s%s.", "LNG:437");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_438, "Directory", "LNG:438");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_439, "Connect to Debugger", "LNG:439");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_440, "The online certificate validation (OCSP) server reports that validation failed because of a malformed request.", "LNG:440");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_441, "Digest Authentication: Password not passed directly", "LNG:441");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_442, "Monday", "LNG:442");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_443, "Connect", "LNG:443");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_444, "The server is using a public encryption key with a length that only provides medium security.", "LNG:444");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_445, "Add", "LNG:445");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_446, "Please use the required format", "LNG:446");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_447, "Add files", "LNG:447");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_448, "Thursday", "LNG:448");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_449, "Long-click menus", "LNG:449");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_450, "Sending request to %s...", "LNG:450");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_451, "Serial number", "LNG:451");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_452, "IP address", "LNG:452");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_453, "Please re-enter the new master password", "LNG:453");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_454, "The server requested a login authentication method that is not supported.", "LNG:454");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_455, "PM", "LNG:455");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_456, "Missing plug-in", "LNG:456");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_457, "August", "LNG:457");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_458, "Intermediate", "LNG:458");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_459, "Platform", "LNG:459");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_460, "Information from this secure page will be submitted to a page that is not secure on %s.\n\nSubmitting sensitive information is strongly discouraged.", "LNG:460");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_461, "January", "LNG:461");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_462, "Please enter a valid email address", "LNG:462");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_463, "This document had no style information.", "LNG:463");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_464, "No changes to save in this section", "LNG:464");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_465, "Site Specific Preferences", "LNG:465");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_466, "JavaScript", "LNG:466");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_467, "Please enter a number less than or equal to %2", "LNG:467");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_468, "Sunday", "LNG:468");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_469, "This form is being submitted via email, revealing your name and email address to the recipient. Do you want to continue?", "LNG:469");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_470, "Could not connect to proxy server. Access denied", "LNG:470");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_471, "Secure connection: warning (%u)", "LNG:471");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_472, "Ctrl", "LNG:472");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_473, "Down", "LNG:473");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_474, "Home", "LNG:474");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_475, "Left", "LNG:475");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_476, "Meta", "LNG:476");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_477, "List all domains", "LNG:477");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_478, "Disconnected", "LNG:478");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_479, "The server requested an ANONYMOUS connection, it is therefore impossible to verify the identity of the server. Is this a service that would normally be anonymous, and are you willing to send data to this anonymous server?", "LNG:479");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_480, "Make sure your Internet connection is active and check whether other applications that rely on the same connection are working.", "LNG:480");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_481, "Access denied", "LNG:481");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_482, "Please enter a password to protect the exported private key", "LNG:482");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_483, "Invalid URL", "LNG:483");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_484, "Please enter the password protecting the key", "LNG:484");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_485, "GPU Summary", "LNG:485");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_486, "A Java applet is requesting to run with privileges which may allow it to harm your computer.\n\nYou should only accept this request if you know and trust the originating website.", "LNG:486");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_487, "The certificate has expired.", "LNG:487");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_488, "Move down", "LNG:488");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_489, "A page on the public Internet requests data from your computer. For security reasons, automatic access is blocked, but you may choose to continue.", "LNG:489");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_490, "List", "LNG:490");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_491, "Unsupported certificate.", "LNG:491");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_492, "Del", "LNG:492");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_493, "No home page defined. Please define one.", "LNG:493");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_494, "The client certificate had no matching private key in the database.", "LNG:494");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_495, "February", "LNG:495");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_496, "The certificate's chain was not ordered correctly.", "LNG:496");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_497, "Waiting for user-confirmation of cookie(s)...", "LNG:497");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_498, "The root certificate from \"%1\" is not known to Opera. Opera cannot decide if this certificate can be trusted.", "LNG:498");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_499, "Speed Dial", "LNG:499");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_500, "Esc", "LNG:500");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_501, "By long-clicking with the select button, you can perform actions such as opening a link in a new tab, editing a Speed Dial, and copying and pasting text.", "LNG:501");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_502, "Error:", "LNG:502");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_LNG_503, "The server does not support secure TLS renegotiation. The site owner must upgrade the server.", "LNG:503");
/*---language resource generated code---*/

    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_1, "Opera", "Opera");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_2, "Out of disk, browser can not launch", "Disk Error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_3, "Browser has occurred initialize error", "Init Error");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_4, "Invalid parameters to browser", "Invalid Parameters");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_5, "System busy for browser", "Busy");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_6, "Failed in browser", "Failed");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_7, "Go", "Ime Go");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_8, "Search", "Ime Search");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_9, "Next", "Ime Next");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_10, "Done", "Ime Done");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_11, "Delete", "Ime Delete");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_12, "Creating a new folder failed", "Bream Creating a new folder failed");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_MMI_13, "Cancel", "Ime Cancel");

    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_SEND_BOOKMARK_SMS, "Send as text message", "Send bookmark by sms");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_SEND_BOOKMARK_MMS, "Send as multimedia message", "Send bookmark by mms");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_SEND_BOOKMARK_EMAIL, "Send as Email", "Send bookmark by email");
    ADD_APPLICATION_STRING2(STR_ID_OPERA_V11_SEND_BOOKMARK_BT, "Send via Bluetooth", "Send bookmark by bt");

#if !defined (__GOOGLE_SEARCH_SUPPORT__) && (defined(__MMI_SEARCH_WEB_BAIDU__) || defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__))
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\preload_baidu_qvga.bin", "preload resources");
    #elif defined(__MMI_MAINLCD_240X400__)
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\preload_baidu_wqvga.bin", "preload resources");
    #elif defined(__MMI_MAINLCD_320X480__)
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\preload_baidu_hvga.bin", "preload resources");
    #else
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\preload_baidu.bin", "preload resources");
    #endif
#else /* !defined (__GOOGLE_SEARCH_SUPPORT__) && (defined(__MMI_SEARCH_WEB_BAIDU__) || defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__)) */
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\preload_qvga.bin", "preload resources");
    #elif defined(__MMI_MAINLCD_240X400__)
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\preload_wqvga.bin", "preload resources");
    #elif defined(__MMI_MAINLCD_320X480__)
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\preload_hvga.bin", "preload resources");
    #else
        ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\preload.bin", "preload resources");
    #endif
#endif /* !defined (__GOOGLE_SEARCH_SUPPORT__) && (defined(__MMI_SEARCH_WEB_BAIDU__) || defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__)) */

    ADD_APPLICATION_AUDIO2(ADO_ID_OPERA_V11_ADO_2,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Audio\\\\whitelist.txt", "Whitelist");

    ADD_APPLICATION_IMAGE2(IMG_ID_OPERA_V11_MMI_1,"..\\\\..\\\\..\\\\vendor\\\\opera\\\\browser\\\\v11_official\\\\Resource\\\\Images\\\\Opera.ico", "Opera icon");
}

#endif /* OPERA_V11_BROWSER */
