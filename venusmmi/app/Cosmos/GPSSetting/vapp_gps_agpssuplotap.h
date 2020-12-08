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
 *  AGPSSUPLOTAP.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _AGPSSUPLOTAP_H_
#define _AGPSSUPLOTAP_H_

#ifdef __MMI_AGPS_OTAP__

typedef enum
{
    MMI_SUPL_NS_OMA_BOOTSTRAP,   /* L1 node */
    MMI_SUPL_NS_OMA_PROXY,       /* L1 node */
    MMI_SUPL_NS_OMA_APP,         /* L1 node */
    MMI_SUPL_NS_OMA_APPADDR,
    MMI_SUPL_NS_OMA_TOTAL
} mmi_supl_ns_oma_enum;

typedef struct
{
    U32 account_id;
    U16 name[AGPS_MAX_PROFILE_NAME_LEN];
    U16 addr[AGPS_MAX_PROFILE_ADDR_LEN];
    U8 nap_id[MMI_SUPL_OTA_HASH_LEN];
    U8 proxy_id[MMI_SUPL_OTA_HASH_LEN];
    U8 match_index;
    MMI_BOOL addr_type_valid;
    MMI_BOOL wait_fill_addr;
    MMI_BOOL is_used;
} mmi_supl_profile_struct;

typedef struct
{
#if(MMI_SIM_TOTAL > 1)
    mmi_supl_profile_struct profile_list[NVRAM_EF_AGPS_PROFILE_TOTAL * NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL];
#else
    mmi_supl_profile_struct profile_list[NVRAM_EF_AGPS_PROFILE_TOTAL];
#endif

    S32 sel_profile_index;
    S32 config_handle;
    S16 curr_index;
    U16 config_id;
    U16 sim_id;
    MMI_BOOL is_update;
    MMI_BOOL is_install;
    MMI_BOOL is_backkey;
    U8 provurl[MMI_SUPL_OTA_HASH_LEN];
    U8 count;
    mmi_id cur_gid;
    mmi_id cui_id;
} vapp_gps_suplota_context_struct;

extern "C" void mmi_supl_handle_app_configure(mmi_cca_app_configure_ind_struct *newconfigdoc);
extern void vapp_gps_suplota_select(void);
extern void vapp_gps_suplota_check_next_profile(void);
extern void vapp_gps_suplota_install_status(void);
static void vapp_gps_suplota_init(mmi_cca_app_configure_ind_struct *ind);
static void vapp_gps_suplota_handle_ota(mmi_cca_app_configure_ind_struct *ind);
static cca_status_enum vapp_gps_suplota_process_callback_nodes(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum vapp_gps_suplota_parse_bootstrap(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum vapp_gps_suplota_parse_proxy(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum vapp_gps_suplota_handle_proxy_params(cca_core_data_struct *data, void *user_data);
static cca_status_enum vapp_gps_suplota_parse_app(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum vapp_gps_suplota_handle_app_params(cca_core_data_struct *data, void *user_data);
static cca_status_enum vapp_gps_suplota_parse_appaddr(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum vapp_gps_suplota_handle_appaddr_params(cca_core_data_struct *data, void *user_data);

static void vapp_gps_suplota_is_valid_info(void);
static MMI_BOOL vapp_gps_suplota_check_one_profile(U8 index);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static MMI_BOOL vapp_gps_suplota_match_profile(U8 index);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
static void vapp_gps_suplota_entry_ota_setting(void);
static U8 vapp_gps_suplota_abort(void* dummy);
static void vapp_gps_suplota_skip_confirm(void);
static void vapp_gps_suplota_skip_yes(void);
static void vapp_gps_suplota_install(void);
static void vapp_gps_suplota_save_a_profile(U8 index);
static void vcui_gps_suplota_entry_ota_prof_list(void);
//static void vapp_gps_suplota_prof_list_highlight_hdlr(S32 index);
void vapp_gps_suplota_select(void);

static S16 vapp_gps_suplota_get_empty_item_index(void);

static void vcui_gps_suplota_send_cca_conf_rsp(cca_status_enum status);

static MMI_BOOL vcui_gps_suplota_is_ascii_string(const U8 *utf8_str);

void vapp_gps_suplota_install_status(void);
void vapp_gps_suplota_check_next_profile(void);
static MMI_BOOL vapp_gps_suplota_is_in_use(U8 index);
static MMI_BOOL vapp_gps_suplota_is_empty_profile(U8 index);
extern "C" mmi_id vcui_gps_cca_install_create(mmi_id parent_id);
extern "C" void vcui_gps_cca_install_set_param(mmi_id cui_id,void(*install)(void), void(*skip)(void));
extern "C" void vcui_gps_cca_install_run(mmi_id cui_id);
extern "C" void vcui_gps_cca_install_stop(mmi_id cui_id);


class VappGPSSettingOTAPCuiScr: public VfxMainScr
{
    VFX_DECLARE_CLASS(VappGPSSettingOTAPCuiScr);
    // Override
    public:
        virtual void on1stReady();
};

class VappGPSSettingOTAPCuiPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGPSSettingOTAPCuiPage);
    public:
        virtual void onInit();
        virtual void onQueryRotateEx(VfxScreenRotateParam &);
        virtual void onBack();
        void ConfirmSelected(VfxObject* obj, VfxId id);

    public:
        enum {
            INSTALL_PAGE_ID_TOOLBAR_INSTALL = 0,
            INSTALL_PAGE_ID_TOOLBAR_SKIP
        } ;

#if defined(__MMI_MAINLCD_320X480__)
	enum {
            LEFT_GAPS = 8,
            RIGHT_GAPS = 8,
            TOP_GAPS = 8,
            BOTTOM_GAPS = 8
	};
#elif defined(__MMI_MAINLCD_480X800__)
	enum {
            LEFT_GAPS = 14,
            RIGHT_GAPS = 14,
            TOP_GAPS = 14,
            BOTTOM_GAPS = 14
        };
#else
        enum {
            LEFT_GAPS = 5,
            RIGHT_GAPS = 5,
            TOP_GAPS = 5,
            BOTTOM_GAPS = 5
        } ;
#endif

    protected:
        void onToolbarTapped(
            VfxObject* sender,  // sender
            VfxId id            // id
        );
};

/*******************************************************************************
* Export CUI API
*******************************************************************************/
/* Create GPS CUI*/
class VappGPSSettingOTAPCui: public VfxCui
{
    VFX_DECLARE_CLASS(VappGPSSettingOTAPCui);

public:
// Constructor / Destructor
    VappGPSSettingOTAPCui() : m_scr(NULL),install(NULL),skip(NULL) {}
    virtual ~VappGPSSettingOTAPCui() {}

// Override
public:
    // initial parameter and entry main src
    virtual void onRun(
        void *arg,          // parameter
        VfxU32 argSize      // parameter size
    );
    virtual mmi_ret onProc(
        mmi_event_struct * evt
    );

    virtual void onInit();

    virtual void onDeinit();
    void (*install)(void);
    void (*skip)(void);
// Method

// Implementation

private:
    VappGPSSettingOTAPCuiScr *m_scr;
};

#endif /* __MMI_AGPS_OTAP__ */

#endif /* _AGPSSUPLOTAP_H_ */


