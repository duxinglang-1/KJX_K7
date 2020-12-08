/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_shell_fc.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  shell favorite contact
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SHELL_fc_H__
#define __VAPP_SHELL_fc_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_FAV_CONTACT__
#include "ShellApp\base\vapp_shell_panel.h"

#include "vfx_uc_include.h"
#include "vcp_wheel_menu.h"
#include "ui_core\base\vfx_basic_type.h"
#include "vapp_msg_data_provider.h"

#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_image_src.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"
#include "vfx_control.h"
#include "vfx_input_event.h"
#include "vcp_frame_effect.h"
#include "vrt_datatype.h"
#include "vfx_base_popup.h"
#include "vfx_timer.h"
#include "vcp_segment_button.h"
#include "vcp_list_menu.h"
#include "vcp_waiting_icon.h"
#include "vcp_button.h"
#include "vcp_tab_bar.h"
#include "vfx_sys_memory.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_rp_app_venus_shell_fc_def.h"
#include "UcmGprot.h"
#include "FilemgrSrvGprot.h"
#include "UmSrvGprot.h"
#include "UcmGprot.h"
#include "CallLogSrvGprot.h"

#include "custom_phb_config.h"
#include "customer_email_num.h"
#include "MMIDataType.h"
#include "UmSrvDefs.h"
#include "kal_non_specific_general_types.h"

#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define SHELL_FC_MSG_COUNT          (50)
#define SHELL_FC_CALL_COUNT         (50)

// NVRAM INFO
#define SHELL_FC_COUNT              (8)
#define SHELL_FC_LIST_COUNT         (10)
#define SHELL_FC_MAX_COUNT          (0xFFFF * SHELL_FC_COUNT)

#define SHELL_FC_MENU_BEHIND_CELL_COUNT     (2)
#define SHELL_FC_MENU_AHEAD_CELL_COUNT      (2)


/***************************************************************************** 
 * Config the parameter
 *****************************************************************************/
#ifdef __MMI_VUI_SHELL_FAV_CONTACT_SLIM__
 
#ifdef __MMI_MAINLCD_320X480__
// VappShellFCMenu

#define SHELL_FC_MENU_CELL_Y_POS            (191)
#define SHELL_FC_MENU_CELL_WIDTH            (235)
#define SHELL_FC_MENU_CELL_HEIGHT           (115)

#define SHELL_FC_MENU_CELL_NAME_X_POS       (70)
#define SHELL_FC_MENU_CELL_NAME_WIDTH       (120)
#define SHELL_FC_MENU_CELL_NAME_GAP          (5)

#define SHELL_FC_MENU_CELL_IMG_X_POS        (178)
#define SHELL_FC_MENU_CELL_IMG_WIDTH        (88)
#define SHELL_FC_MENU_CELL_IMG_HEIGHT       (88)
#define SHELL_FC_MENU_CELL_IMG_GAP          (13)

#define SHELL_FC_MENU_CELL_TRANS_WIDTH      (320)

#define SHELL_FC_TOOLBAR_X_POS              (35)
#define SHELL_FC_TOOLBAR_Y_POS              (344)
#define SHELL_FC_TOOLBAR_WIDTH              (250)
#define SHELL_FC_TOOLBAR_HEIGHT             (50)

// VappShellDetail
#define SHELL_FC_DETAIL_IMG_X_POS           (10)
#define SHELL_FC_DETAIL_IMG_Y_POS           (10)

#define SHELL_FC_DETAIL_IMG_ADD_WIDTH       (80)
#define SHELL_FC_DETAIL_IMG_ADD_HIGHT       (15)

#define SHELL_FC_DETAIL_LIST_Y_POS          (107)

#define SHELL_FC_DETAIL_BACK_X_POS          (240)
#define SHELL_FC_DETAIL_BACK_Y_POS          (6)
#define SHELL_FC_DETAIL_BACK_WIDTH          (70)
#define SHELL_FC_DETAIL_BACK_HIGHT          (30)

#define SHELL_FC_DETAIL_NAME_X_POS          (130)
#define SHELL_FC_DETAIL_NAME_Y_POS          (62)
#define SHELL_FC_DETAIL_NAME_WIDTH          (175)
#define SHELL_FC_DETAIL_NAME_HIGHT          (48)
// FONT
#define SHELL_FC_MENU_CELL_ADD_FONT         (15)
#define SHELL_FC_MENU_CELL_NAME_FONT        (20)
#define SHELL_FC_MENU_CELL_TITILE_FONE      (14)
#define SHELL_FC_DETAIL_ADD_IMG_FONT        (12)

#elif defined(__MMI_MAINLCD_240X400__)
// VappShellFCMenu
#define SHELL_FC_MENU_CELL_Y_POS            (155)
#define SHELL_FC_MENU_CELL_WIDTH            (210)
#define SHELL_FC_MENU_CELL_HEIGHT           (100)

#define SHELL_FC_MENU_CELL_NAME_X_POS       (65)
#define SHELL_FC_MENU_CELL_NAME_WIDTH       (100)
#define SHELL_FC_MENU_CELL_NAME_GAP          (5)

#define SHELL_FC_MENU_CELL_IMG_X_POS        (160)
#define SHELL_FC_MENU_CELL_IMG_WIDTH        (77)
#define SHELL_FC_MENU_CELL_IMG_HEIGHT       (77)
#define SHELL_FC_MENU_CELL_IMG_GAP          (10)

#define SHELL_FC_MENU_CELL_TRANS_WIDTH      (240)

#define SHELL_FC_TOOLBAR_X_POS              (20)
#define SHELL_FC_TOOLBAR_Y_POS              (280)
#define SHELL_FC_TOOLBAR_WIDTH              (200)
#define SHELL_FC_TOOLBAR_HEIGHT             (40)


// VappShellDetail
#define SHELL_FC_DETAIL_IMG_X_POS           (7)
#define SHELL_FC_DETAIL_IMG_Y_POS           (7)

#define SHELL_FC_DETAIL_IMG_ADD_WIDTH       (70)
#define SHELL_FC_DETAIL_IMG_ADD_HIGHT       (14)

#define SHELL_FC_DETAIL_LIST_Y_POS          (92)

#define SHELL_FC_DETAIL_BACK_X_POS          (180)
#define SHELL_FC_DETAIL_BACK_Y_POS          (6)
#define SHELL_FC_DETAIL_BACK_WIDTH          (55)
#define SHELL_FC_DETAIL_BACK_HIGHT          (30)

#define SHELL_FC_DETAIL_NAME_X_POS          (117)
#define SHELL_FC_DETAIL_NAME_Y_POS          (52)
#define SHELL_FC_DETAIL_NAME_WIDTH          (115)
#define SHELL_FC_DETAIL_NAME_HIGHT          (40)

// FONT
#define SHELL_FC_MENU_CELL_ADD_FONT         (12)
#define SHELL_FC_MENU_CELL_NAME_FONT        (16)
#define SHELL_FC_MENU_CELL_TITILE_FONE      (10)
#define SHELL_FC_DETAIL_ADD_IMG_FONT        (10)

#elif defined(__MMI_MAINLCD_240X320__)

// VappShellFCMenu
#define SHELL_FC_MENU_CELL_Y_POS            (125)
#define SHELL_FC_MENU_CELL_WIDTH            (230)
#define SHELL_FC_MENU_CELL_HEIGHT           (110)

#define SHELL_FC_MENU_CELL_NAME_X_POS       (60)
#define SHELL_FC_MENU_CELL_NAME_WIDTH       (100)
#define SHELL_FC_MENU_CELL_NAME_GAP          (7)

#define SHELL_FC_MENU_CELL_IMG_X_POS        (170)
#define SHELL_FC_MENU_CELL_IMG_WIDTH        (76)
#define SHELL_FC_MENU_CELL_IMG_HEIGHT       (76)
#define SHELL_FC_MENU_CELL_IMG_GAP          (10)

#define SHELL_FC_MENU_CELL_TRANS_WIDTH      (240)

#define SHELL_FC_TOOLBAR_X_POS              (20)
#define SHELL_FC_TOOLBAR_Y_POS              (224)
#define SHELL_FC_TOOLBAR_WIDTH              (200)
#define SHELL_FC_TOOLBAR_HEIGHT             (40)


// VappShellDetail
#define SHELL_FC_DETAIL_IMG_X_POS           (13)
#define SHELL_FC_DETAIL_IMG_Y_POS           (5)

#define SHELL_FC_DETAIL_IMG_ADD_WIDTH       (70)
#define SHELL_FC_DETAIL_IMG_ADD_HIGHT       (14)

#define SHELL_FC_DETAIL_LIST_Y_POS          (86)

#define SHELL_FC_DETAIL_BACK_X_POS          (180)
#define SHELL_FC_DETAIL_BACK_Y_POS          (5)
#define SHELL_FC_DETAIL_BACK_WIDTH          (55)
#define SHELL_FC_DETAIL_BACK_HIGHT          (30)

#define SHELL_FC_DETAIL_NAME_X_POS          (112)
#define SHELL_FC_DETAIL_NAME_Y_POS          (56)
#define SHELL_FC_DETAIL_NAME_WIDTH          (120)
#define SHELL_FC_DETAIL_NAME_HIGHT          (40)

// FONT
#define SHELL_FC_MENU_CELL_ADD_FONT         (14)
#define SHELL_FC_MENU_CELL_NAME_FONT        (22)
#define SHELL_FC_MENU_CELL_TITILE_FONE      (10)
#define SHELL_FC_DETAIL_ADD_IMG_FONT        (12)

#endif

#else /* __MMI_VUI_SHELL_FAV_CONTACT_SLIM__ */

#ifdef __MMI_MAINLCD_320X480__
// VappShellFCMenu

#define SHELL_FC_MENU_CELL_Y_POS            (175)
#define SHELL_FC_MENU_CELL_WIDTH            (290)
#define SHELL_FC_MENU_CELL_HEIGHT           (140)
//#define SHELL_FC_MENU_CELL_X_AXIS_RADIUS    (35)
//#define SHELL_FC_MENU_CELL_Y_AXIS_RADIUS    (175)
//#define SHELL_FC_MENU_CELL_ROTATE_ANGLE     (72)
//#define SHELL_FC_MENU_CELL_ROTATE_ANGLE_Y   (25)
//#define SHELL_FC_MENU_CELL_X_SHIFT          (10)

#define SHELL_FC_MENU_CELL_NAME_X_POS       (85)
#define SHELL_FC_MENU_CELL_NAME_WIDTH       (135)
#define SHELL_FC_MENU_CELL_NAME_GAP          (7)

#define SHELL_FC_MENU_CELL_IMG_X_POS        (220)
#define SHELL_FC_MENU_CELL_IMG_WIDTH        (100)
#define SHELL_FC_MENU_CELL_IMG_HEIGHT       (100)
#define SHELL_FC_MENU_CELL_IMG_GAP          (17)

#define SHELL_FC_MENU_CELL_TRANS_WIDTH      (320)

#define SHELL_FC_TOOLBAR_X_POS              (35)
#define SHELL_FC_TOOLBAR_Y_POS              (344)
#define SHELL_FC_TOOLBAR_WIDTH              (250)
#define SHELL_FC_TOOLBAR_HEIGHT             (50)

// VappShellDetail
#define SHELL_FC_DETAIL_IMG_X_POS           (10)
#define SHELL_FC_DETAIL_IMG_Y_POS           (10)

#define SHELL_FC_DETAIL_IMG_ADD_WIDTH       (80)
#define SHELL_FC_DETAIL_IMG_ADD_HIGHT       (15)

#define SHELL_FC_DETAIL_LIST_Y_POS          (117)

#define SHELL_FC_DETAIL_BACK_X_POS          (240)
#define SHELL_FC_DETAIL_BACK_Y_POS          (6)
#define SHELL_FC_DETAIL_BACK_WIDTH          (70)
#define SHELL_FC_DETAIL_BACK_HIGHT          (30)

#define SHELL_FC_DETAIL_NAME_X_POS          (130)
#define SHELL_FC_DETAIL_NAME_Y_POS          (62)
#define SHELL_FC_DETAIL_NAME_WIDTH          (175)
#define SHELL_FC_DETAIL_NAME_HIGHT          (48)
// FONT
#define SHELL_FC_MENU_CELL_ADD_FONT         (15)
#define SHELL_FC_MENU_CELL_NAME_FONT        (28)
#define SHELL_FC_MENU_CELL_TITILE_FONE      (14)
#define SHELL_FC_DETAIL_ADD_IMG_FONT        (12)

#elif defined(__MMI_MAINLCD_240X400__)
// VappShellFCMenu
#define SHELL_FC_MENU_CELL_Y_POS            (155)
#define SHELL_FC_MENU_CELL_WIDTH            (210)
#define SHELL_FC_MENU_CELL_HEIGHT           (100)

#define SHELL_FC_MENU_CELL_NAME_X_POS       (65)
#define SHELL_FC_MENU_CELL_NAME_WIDTH       (100)
#define SHELL_FC_MENU_CELL_NAME_GAP          (5)

#define SHELL_FC_MENU_CELL_IMG_X_POS        (160)
#define SHELL_FC_MENU_CELL_IMG_WIDTH        (77)
#define SHELL_FC_MENU_CELL_IMG_HEIGHT       (77)
#define SHELL_FC_MENU_CELL_IMG_GAP          (10)

#define SHELL_FC_MENU_CELL_TRANS_WIDTH      (240)

#define SHELL_FC_TOOLBAR_X_POS              (20)
#define SHELL_FC_TOOLBAR_Y_POS              (280)
#define SHELL_FC_TOOLBAR_WIDTH              (200)
#define SHELL_FC_TOOLBAR_HEIGHT             (40)


// VappShellDetail
#define SHELL_FC_DETAIL_IMG_X_POS           (7)
#define SHELL_FC_DETAIL_IMG_Y_POS           (7)

#define SHELL_FC_DETAIL_IMG_ADD_WIDTH       (70)
#define SHELL_FC_DETAIL_IMG_ADD_HIGHT       (14)

#define SHELL_FC_DETAIL_LIST_Y_POS          (92)

#define SHELL_FC_DETAIL_BACK_X_POS          (180)
#define SHELL_FC_DETAIL_BACK_Y_POS          (6)
#define SHELL_FC_DETAIL_BACK_WIDTH          (55)
#define SHELL_FC_DETAIL_BACK_HIGHT          (30)

#define SHELL_FC_DETAIL_NAME_X_POS          (117)
#define SHELL_FC_DETAIL_NAME_Y_POS          (52)
#define SHELL_FC_DETAIL_NAME_WIDTH          (115)
#define SHELL_FC_DETAIL_NAME_HIGHT          (40)

// FONT
#define SHELL_FC_MENU_CELL_ADD_FONT         (12)
#define SHELL_FC_MENU_CELL_NAME_FONT        (16)
#define SHELL_FC_MENU_CELL_TITILE_FONE      (10)
#define SHELL_FC_DETAIL_ADD_IMG_FONT        (10)

#elif defined(__MMI_MAINLCD_240X320__)

// VappShellFCMenu
#define SHELL_FC_MENU_CELL_Y_POS            (125)
#define SHELL_FC_MENU_CELL_WIDTH            (230)
#define SHELL_FC_MENU_CELL_HEIGHT           (110)

#define SHELL_FC_MENU_CELL_NAME_X_POS       (85)
#define SHELL_FC_MENU_CELL_NAME_WIDTH       (110)
#define SHELL_FC_MENU_CELL_NAME_GAP          (2)

#define SHELL_FC_MENU_CELL_IMG_X_POS        (165)
#define SHELL_FC_MENU_CELL_IMG_WIDTH        (76)
#define SHELL_FC_MENU_CELL_IMG_HEIGHT       (76)
#define SHELL_FC_MENU_CELL_IMG_GAP          (10)

#define SHELL_FC_MENU_CELL_TRANS_WIDTH      (240)

#define SHELL_FC_TOOLBAR_X_POS              (20)
#define SHELL_FC_TOOLBAR_Y_POS              (200)
#define SHELL_FC_TOOLBAR_WIDTH              (200)
#define SHELL_FC_TOOLBAR_HEIGHT             (40)


// VappShellDetail
#define SHELL_FC_DETAIL_IMG_X_POS           (13)
#define SHELL_FC_DETAIL_IMG_Y_POS           (5)

#define SHELL_FC_DETAIL_IMG_ADD_WIDTH       (70)
#define SHELL_FC_DETAIL_IMG_ADD_HIGHT       (14)

#define SHELL_FC_DETAIL_LIST_Y_POS          (86)

#define SHELL_FC_DETAIL_BACK_X_POS          (180)
#define SHELL_FC_DETAIL_BACK_Y_POS          (5)
#define SHELL_FC_DETAIL_BACK_WIDTH          (55)
#define SHELL_FC_DETAIL_BACK_HIGHT          (30)

#define SHELL_FC_DETAIL_NAME_X_POS          (112)
#define SHELL_FC_DETAIL_NAME_Y_POS          (50)
#define SHELL_FC_DETAIL_NAME_WIDTH          (120)
#define SHELL_FC_DETAIL_NAME_HIGHT          (40)

// FONT
#define SHELL_FC_MENU_CELL_ADD_FONT         (12)
#define SHELL_FC_MENU_CELL_NAME_FONT        (16)
#define SHELL_FC_MENU_CELL_TITILE_FONE      (10)
#define SHELL_FC_DETAIL_ADD_IMG_FONT        (10)

#endif /* __MMI_MAINLCD_240X320__ */


#endif /* __MMI_VUI_SHELL_FAV_CONTACT_SLIM__ */

#define SHELL_FC_NUM_COUNT (MMI_PHB_OPT_NUM_COUNT + 1)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    SHELL_FC_ACTION_NONE,
    SHELL_FC_MAKE_CALL,
    SHELL_FC_SEND_MSG,
    SHELL_FC_SEND_MAIL,
    SHELL_FC_ACTION_TOTAL
} VappShellFCActionType;

typedef enum
{
    VAPP_SHELL_FC_LIST_DETAIL,
    VAPP_SHELL_FC_LIST_MSG,
    VAPP_SHELL_FC_LIST_CH,
    VAPP_SHELL_FC_LIST_TOTAL
} VappShellFCListType;


/***************************************************************************** 
 * Declare
 *****************************************************************************/
class VappShellFCFrame;

/***************************************************************************** 
 * Class ContactCache
 *****************************************************************************/ 
class ContactCache
{
public:
    static void init();
    static void init(VfxU16 storeIndex);    
    static VfxWChar* getInfo(VfxU16 storeIndex, mmi_phb_num_type_enum infoType, VfxU32 infoId);

private:
    static VfxWChar name[MMI_PHB_NAME_LENGTH + 1];
    static VfxWChar number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    static VfxWChar homeNumber[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    static VfxWChar officeNumber[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    static VfxWChar faxNumber[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    static VfxWChar email1[MMI_PHB_EMAIL_LENGTH + 1];
    static VfxWChar email2[MMI_PHB_EMAIL_LENGTH + 1];
    static VfxWChar title[MMI_PHB_TITLE_LENGTH + 1];

    static VfxU16     m_storeIndex;
};


/***************************************************************************** 
 * Class VappShellFC
 *****************************************************************************/
class VappShellFC : public VfxObject
{
    VFX_DECLARE_CLASS(VappShellFC);
public:
    class number
    {
    public:
        mmi_phb_num_type_enum m_numType[SHELL_FC_NUM_COUNT];
        VfxU32                m_numId[SHELL_FC_NUM_COUNT];
        VfxU8                 m_numCnt;
    };
public:
    // constructor
    VappShellFC() :
        m_img(VFX_IMAGE_SRC_NULL),
        m_buf(VFX_WSTR_EMPTY),
        m_storeIndex(0xffff),
        m_ID(0),
        m_getNumberIndex(0),
        m_getEmailIndex(0)
        {}

public:
    // init cache
    void initCache();
    
    // set FC data
    void set(VfxU16 storeIndex, VfxU8 id);

    // set new store index
    void set(VfxU16 storeIndex);
    
    // update the contact's image
    void removeImg();

    // has image
    VfxBool hasImg();
    
    // set image
    void setImg();

    // set image
    void setImg(VfxWString& path);
    
    // add image
    void addImg();

    // take photo
    void takeImg();

    // has number
    VfxBool hasNumber();

    // getFieldFlag
    VfxU32 getFieldFlag();

    // get mobile number counts
    VfxU8 getMobileNumberCount();

    // get number counts
    VfxU8 getNumberCount();

    // get email counts
    VfxU8 getEmailCount();
    
    // begain to get number
    VfxU8 getNumber();
    
    // must call get number first, then call this function
    VfxWString& getNextNumber(mmi_phb_num_type_enum *numType, VfxU32 *numId);

    // get image
    const VfxImageSrc& getImg() const;

    // get contact's info reference by type
    VfxWString& getInfo(mmi_phb_num_type_enum infoType, VfxU32 infoId);
    
    // get content
    VfxS32 getEmail();

    // get next email address, must call getEmail first
    VfxWString& getNextEmail(mmi_phb_num_type_enum *numType, VfxU32 *numId);
    
public:
    // get fc's store index
    VfxU16 getStoreIndex();

    // get fc's ID
    VfxU8 getId();

    // check if the fc is valid
    VfxBool isFCValid();

private:
    VfxImageSrc     m_img;              // for performence
    VfxWString      m_buf;            // for performence
    VfxU16          m_storeIndex;       // store index, sync to phonebook
    VfxU8           m_ID;               // wheel index, fixed index in the storage

    // for get info
    VfxU32          m_getNumberIndex;
    VfxU32          m_getEmailIndex;

    number          m_number;
};


/***************************************************************************** 
 * Class ContactUISrv
 *****************************************************************************/
class ContactUISrv
{
public:
    // plutommi cb function
    static mmi_ret proc(mmi_event_struct *evt);

    // make call call back
    static void makeCallCb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para);

    // make call to selected number
    static void makeCall(VfxU16 storeIndex, const VfxWString number, VfxU32 numberType);
    
    // send message to selected address
    static void sendMsg(VfxU16 storeIndex, VfxWString &addr, VfxU32 addrType);

    // view selected message
    static void viewMsg(VfxU32 msgId, srv_um_msg_enum msgType);

    // send email to selected address
    static void sendEmail(VfxU16 storeIndex, VfxWString &addr, VfxU32 addrType);

    // get clog list
    //static void getCHList();

    // get msg list
    //static void getMsgList();

    // clog, msg cache data
    //static srv_clog_call_log_struct m_clog[SHELL_FC_LIST_COUNT];
    //static srv_um_msg_info_struct m_msg[SHELL_FC_LIST_COUNT];
};


/***************************************************************************** 
 * Class VappShellFCList
 *****************************************************************************/
class VappShellFCList : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappShellFCList);

public:
    // constructor
    VappShellFCList();

public:
    // init cache
    void initCache();

    // build cache
    void buildCache();

    // check is ready
    VfxBool isReady() const;

    // get count
    VfxU16 getCount();
    
    // get the favorite contact
    VappShellFC* getFC(VfxU8 id);

    // get focused contact
    VappShellFC* getFocusFC();
    
    // get the focused ID
    VfxU8 getFocusID();

    // set the focused ID
    void setFocusID(VfxU8 focusID);
    
    // add a favorite contact
    void add(VappShellFC* fc);

    // add a favorite contact to focus
    void add();
    
    // remove a favorite contact
    void remove(VappShellFC* fc);

    // remove focus contact
    void remove();
    
    // save the new contact list to NVRAM
    void save();

    // check store index exist
    VfxS32 exist(VfxU16 storeIndex);

public:
    void regLisener();
    void deregLisener();
    static void lisenerCb(VfxS32 result, VfxU16 storeIndex, void* userData);
    static mmi_ret lisener(mmi_event_struct* param);
    
protected:
    // read Nvram and build the contact list
    virtual void onInit();
    virtual void onDeinit();

public:
    // singal to UI component
    VfxSignal2 <VappShellFCList*, mmi_event_struct*>    m_signalFCContent;

private:
    // buidl fc list
    void build();

    // set ready flag
    void setReady(VfxBool ready);
    
private:
    VappShellFC m_FC[SHELL_FC_COUNT];
    VfxU8       m_focusID;
    VfxBool     m_isReady;
};


/***************************************************************************** 
 * Class VappFCAddFrame
 *****************************************************************************/
class VappFCAddFrame : public VfxFrame
{    
public:
    VappFCAddFrame() : m_addImage(NULL), m_addImgStr(NULL){}

public:
    // set img
    void setImg(VfxS32 resId);

    // set text
    void setText(const VfxWString& text, VfxU8 fontSize, VfxU8 line);

    // commit the new setting, must be call after setXXX
    void commit();
    
protected:
    virtual void onInit();
    virtual void onDeinit();
    
private:
    VfxImageFrame*      m_addImage;
    VfxTextFrame*       m_addImgStr;
};


/***************************************************************************** 
 * Class VappFCNameFrame
 *****************************************************************************/
class VappFCNameFrame : public VfxFrame
{
public:
    enum vapp_fc_name_mode
    {
        VAPP_FC_NAME_LEFT,
        VAPP_FC_NAME_CENTER
    };
public:
    VappFCNameFrame():m_name(NULL), m_title(NULL), m_FC(NULL) {}

public:
    void set(VappShellFC* fc, vapp_fc_name_mode mode);
    void setName(VfxWString& name);
    void setTitle(VfxWString& title);

    void commit();
    
protected:
    virtual void onInit();
    virtual void onDeinit();
    
private:
    VfxTextFrame*       m_name;
    VfxTextFrame*       m_title;
    VappShellFC*        m_FC;
};

/***************************************************************************** 
 * Class VappFCImage
 *****************************************************************************/
class VappFCImage : public VfxFrame
{
    typedef VfxFrame Super;
    typedef VappFCImage Self;
    
public:
    VappFCImage() : m_img(NULL){};

public:
    void setCenterImg(const VfxImageSrc& img);
    
protected:
    virtual void onInit();
    virtual void onDeinit();
private:
    VfxImageFrame *m_img;
};


/***************************************************************************** 
 * Class VappFCImageButton
 *****************************************************************************/
class VappFCImageButton : public VfxControl
{
private:
    typedef VfxControl Super;
    
public:
    VappFCImageButton() :
        m_addImg(NULL),
        m_FCImg(NULL),
        m_FCImgShadow(NULL){};

public:
    // set and update function, always rebuild VappFCAddFrame
    void set(VappShellFC *fc);

    VfxSignal2 <VfxObject*, VfxId> m_signalClicked;

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    );
    
private:
    VappFCAddFrame      *m_addImg;
    VappFCImage         *m_FCImg;
    VfxImageFrame       *m_FCImgShadow;          // image shadow    
};


/***************************************************************************** 
 * Class VappShellFC3DScr
 *****************************************************************************/
class VappShellFC3DScr : public VcpWheelMenu
{
    VFX_DECLARE_CLASS(VappShellFC3DScr);
    
private:
    typedef VcpWheelMenu Super;
    typedef VappShellFC3DScr Self;

public:
    // Contstructor
    VappShellFC3DScr(){};
    VappShellFC3DScr(VappShellFCList *FCList);
    
public:
    enum ToolBarID
    {
        SHELL_FC_SEG_ID_MAKE_CALL,
        SHELL_FC_SEG_ID_SEND_MSG,
        SHELL_FC_SEG_ID_DELETE,
        SHELL_FC_SEG_ID_TOTAL
    };
    
    struct FCMenuCellData // Modify
    {
        VfxS32 cell;
        VfxS32 subcell;
        VfxU32 tick;
    };
    
    class MenuCell : public  VfxControl
    {
    public:
        enum InfoDispSeq
        {
            FC_NAME,
            FC_MOBILE_NUMBER,
            FC_HOME_NUMBER,
            FC_OFFICE_NUMBER,
            FC_FAX_NUMBER,
            FC_HOME_EMAIL,
            FC_WORK_EMAIL,
            FC_SEQ_TOTAL
        };
    public:
        MenuCell(VappShellFC *fc);
        
        VappShellFC3DScr* getMenu();

        // TODO:
        VfxS32 getMenuPos();
        void setHighlight(VfxBool isHighLight, VfxBool isAnim);

        // check with facer
        void adjustPos(const VfxRect &value);
        void click();

        void setFC(VappShellFC* fc);
        VappShellFC* getFC();
        void onDeleteName();
        
    //Override
    public:
        virtual void onUpdateCell();
        virtual void setBounds(const VfxRect &value);

    protected:
        virtual void onInit();
        virtual void onDeinit();

    public:
        // signal to parent frame
        VfxSignal2<MenuCell*, VappShellFC*> m_signalClick;
        void onDeleteCellFinished(VfxFrame *obj, VfxBool complete);

    private:
        VappShellFC         *m_FC;
        VappFCNameFrame     *m_FCName;
        VappFCAddFrame      *m_FCAdd;
        VfxImageFrame       *m_bgImg;
        VappFCImage         *m_FCImg;
        VfxBool             m_highlight;
        VcpFrameEffect          *m_deleteEffect;        // delete effect
        VcpFrameEffect          *m_deleteEffect2;        // delete effect        
    };

protected:
    // Override
    virtual void onInit();
    virtual void onDeinit();

public:
    // on init view life cycle
    void onInitView();

    // on deinit life cycle
    void onDeinitView();

    // on enter view life cycle
    void onEnterView();
    void onEnterViewEffect();
    
    // on exit view life cycle
    void onExitView(VfxBool keepData);
    void onExitViewEffect();
    
    virtual void onStateChangeFinished(
        VcpWheelMenuState finishedstate // [IN] finished state.
        );

// Override
public:
    virtual VfxS32 getSubCellCount();
    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame);
    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);

    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
    virtual void onDragStart();
    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

    // 1, if the tapped cell is focused, notify the cell
    // 2, change the tapped cell to focused one
    virtual void onTap(VfxPoint pt);

    virtual VfxS32 getCount();
    virtual VfxS32 getBehindCount();
    virtual VfxS32 getAheadCount();


public:
    static vrt_render_dirty_type_enum myFrameEffectCB(
                        VfxS32                      cell,           // [IN] the cell index
                        VfxS32                      subCell,        // [IN] the sub cell index
                        VfxFloat                    cellRelPos,     // [IN] the cell position
                        vrt_frame_visual_property_struct * target_frame,
                        VfxFloat                    fPos,
                        VfxS32                      focus,
                        VfxRect                     viewBounds,
                        void                        *userData,
                        VfxU32                      userDataSize,
                        VcpWheelMenuState           state,          // [IN] the state of Menu
                        VfxFloat                    level           // [IN] the level of state
                        );
    
    
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();
    
public:
    // before enter view, call this api to refresh content
    void onUpdateCell();

    // set visible flag
    void setToolBarVisible(VfxBool visible);

    // set moving flag
    void setMenuMoving(VfxBool moving);

    // toolbar config
    void toolBarConfig();

    // make call
    void makeCall();

    // send message
    void sendMsg();

    // delete cell
    void deleteCell();

public:
    // contact content update event
    void onUpdateContent(VappShellFCList*, mmi_event_struct*);

    // click number to make call
    void onCommandCallClick(VfxObject *obj, VfxId id);

    // click number to send message
    void onCommandMsgClick(VfxObject* obj, VfxId id);

    // segment bar click event
    void onToolBarClick(VfxObject* button, VfxId id);

    void onPreDeleteCell(VfxObject* obj, VfxId id);

    void onDeleteCell(VfxBasePopup* obj, VfxBasePopupStateEnum state);

    void onTimerTick(VfxTimer *source);

public:
    // signal to parent frame to add new fc or show detail screen
    VfxSignal2<VappShellFC3DScr*, VappShellFC*> m_signalTap;
    
private:
    VfxBool                 m_toolBarVisible;       // VFX_FALSE: 1, FC menu list moving; 2, no focused FC
    VcpSegmentButton*       m_toolBar;              // tool bar object. Notice disable property,                                                    // ex: send msg segment and no mobile number, then disable it
    VfxBool                 m_isMoving;             // is moving
    VappShellFCList*        m_FCList;               // FC object list
    VfxS32                  m_count;
    VfxBool                 m_delete;
    VfxTimer*               m_timer;
};


/***************************************************************************** 
 * Class VappShellListCHProvider
 *****************************************************************************/
class VappShellListDetailProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VappShellListDetailProvider(VappShellFC* fc):
        m_list(NULL),
        m_info(NULL),
        m_count(0),
        m_oldCount(0),
        m_history(NULL)
    {
        m_FC = fc;
        for (VfxU8 i = 0; i < 10; i++)
        {
            m_action[i].m_action = SHELL_FC_ACTION_NONE;
        }
    }

public:
    void setFC(VappShellFC *fc);

    // get contact's data, must be call before show list
    void getContent(VfxBool sync);
    
    class Action: public VfxBase
    {
    public:
        mmi_phb_num_type_enum m_infoType;
        VfxU32 m_infoId;
        VfxU8  m_action;
    };

    void setFCHistory(VfxU16 oldCount, VcpListMenuHistoryStruct * history);
    void reStoreHistory(VfxBool sync);
    
// Overridable
public:

    // Set the list menu pointer to content provider
    virtual void setMenu(VcpListMenu *);

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    // Free the image resource for the image fields of list cell
    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        );

    // Get the item count of the lis menu
    virtual VfxU32 getCount() const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    // Swap two items, user should update its internal data of the two items
    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        );

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should creat and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,   // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame        
        );

    // Uer should release the resource of the content frame which is created by 
    // itself, such as image resource
    virtual void closeItemCustomContentFrame(
        VfxU32 index,  // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
        );
protected:
    virtual void onInit();
    virtual void onDeinit();
    
private:
    VcpListMenu     *m_list;
    VappShellFC     *m_FC;
    VfxTextFrame    *m_info;
    VfxU8           m_count;

    VfxU16          m_oldCount;
    VcpListMenuHistoryStruct *m_history;
    
public:    
    Action m_action[10];
};


/***************************************************************************** 
 * Class VappThreadList
 *****************************************************************************/
#ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
class VappMsgListProvider : public VfxObject, public IVcpListMenuContentProvider
{
private:
    typedef VfxObject Super;
    typedef VappMsgListProvider Self;
    
public:
    VappMsgListProvider():
        m_list(NULL),
        m_msgList(NULL),
        m_msgHandle(NULL),
        m_waitingIcon(NULL),
        m_msgInfo(NULL),
        m_sync(VFX_FALSE),
        m_FC(NULL),
        m_info(NULL),
        m_oldCount(0),
        m_history(NULL)
    {
    }

public:
    void setFC(VappShellFC* fc);

    // refresh content after switch tab
    void refresh();

    VfxBool isUpdating()
    {
        return m_msgList->isUpdating();
    }
    
    // get contact's data, must be call before show list
    void getContent(VfxBool sync);

    void onGetMsgInfoFinished(srv_um_get_msg_info_result result);

    void preDeinit();

    void onMsgListUpdated();
    void onMsgListReleased();

    VfxU32 getMsgId(VfxS32 index);
    srv_um_msg_enum getMsgType(VfxS32 index);

    void setFCHistory(VfxU16 oldCount, VcpListMenuHistoryStruct * history);
    void reStoreHistory(VfxBool sync);
    
    static mmi_ret onUmSrvReadyNotify(mmi_event_struct *param);
    static mmi_ret onUmSrvRefreshNotify(mmi_event_struct *param);
        
// Overridable
public:

    // Set the list menu pointer to content provider
    virtual void setMenu(VcpListMenu *);

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    // Free the image resource for the image fields of list cell
    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        );

    // Get the item count of the lis menu
    virtual VfxU32 getCount() const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    // Swap two items, user should update its internal data of the two items
    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        );

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should creat and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,   // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    // Uer should release the resource of the content frame which is created by 
    // itself, such as image resource
    virtual void closeItemCustomContentFrame(
        VfxU32 index,  // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
        );
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void showHelpInfo();

private:
    VcpListMenu             *m_list;
    VappMsgList             *m_msgList;
    VappMsgDataProvider     *m_msgHandle;
    VcpWaitingIcon          *m_waitingIcon;
    srv_um_msg_info_struct  *m_msgInfo;
    VfxBool                 m_sync;
    VappShellFC             *m_FC;
    VfxTextFrame            *m_info;

    VfxU16                  m_oldCount;
    VcpListMenuHistoryStruct *m_history;    
};

#endif

/***************************************************************************** 
 * Class VappShellListCHProvider
 *****************************************************************************/
class VappShellListCHProvider : public VfxObject, public IVcpListMenuContentProvider
{

public:
    VappShellListCHProvider():
        m_list(NULL),
        m_FC(NULL),
        m_sync(VFX_FALSE),
        m_count(0),
        m_info(NULL),
        m_hdlr(0),
        m_numId(0),
        m_viewed(VFX_FALSE)
    {}
    
    void setFC(VappShellFC *fc);

    void getContent(VfxBool sync);

    void refresh();

    void getClogDone();

    void onCommandClick(VfxObject * obj, VfxId id);

    void onTapItem(VfxU32 index);

    void createCLogInstance(SRV_CLOG_HANDLE &hdlr) const;

    static mmi_ret onClogChangeNotify(mmi_event_struct *param);

    void setViewed(VfxBool viewed);

    VfxBool hasViewed();

    void clearMissedNum();
    
    
// Overridable
public:

    // Set the list menu pointer to content provider
    virtual void setMenu(VcpListMenu *);

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    // Free the image resource for the image fields of list cell
    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        );

    // Get the item count of the lis menu
    virtual VfxU32 getCount() const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    // Swap two items, user should update its internal data of the two items
    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        );

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should creat and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,   // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    // Uer should release the resource of the content frame which is created by 
    // itself, such as image resource
    virtual void closeItemCustomContentFrame(
        VfxU32 index,  // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
        );
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void showHelpInfo();
    
private:
    VcpListMenu     *m_list;
    VappShellFC     *m_FC;
    VfxBool         m_sync;
    VfxU8           m_count;
    VfxTextFrame    *m_info;
    SRV_CLOG_HANDLE m_hdlr;
    VfxU8           m_numId;
    VfxWString      m_number;
    VfxBool         m_viewed;

    
    static VfxU32   m_logs[SHELL_FC_CALL_COUNT];
    static VfxU8    m_index;
    static VfxS32   getClogCb(
                        SRV_CLOG_HANDLE handle,
                        VfxS32 pid, 
                        void *req_data,
                        void* cnf_data, 
                        MMI_BOOL more,
                        srv_clog_ret_enum ret);  
};


/***************************************************************************** 
 * Class VappShellFCDetailScr
 *****************************************************************************/
class VappShellFCDetailScr : public VfxControl
{
private:
    typedef VfxControl Super;
    typedef VappShellFCDetailScr Self;
    
public:
    class ListHistory
    {
    public:
        VfxU8 id;
        VfxU8 infoListIndex;
        VfxU8 msgsListIndex;
        VfxU8 callsListIndex;

        VfxU16 infoListCount;
        VfxU16 msgsListCount;

        VcpListMenuHistoryStruct infoListHistory;
        VcpListMenuHistoryStruct msgsListHistory;

        VfxU16 storeIndex;
    };

    enum
    {
        VAPP_SHELL_FC_DETAIL_INFO,
        VAPP_SHELL_FC_DETAIL_CLOG,
        VAPP_SHELL_FC_DETAIL_MSG,
        VAPP_SHELL_FC_DETAIL_TOTAL
    };

    enum
    {
        VAPP_SHELL_FC_TAKE_PHOTO,
        VAPP_SHELL_FC_SELECT_FILE,
        VAPP_SHELL_FC_DELETE_IMG,
        VAPP_SHELL_FC_IMG_MAX_ITEM
    };
public:
    // Contstructor
    VappShellFCDetailScr():
        m_FCImg(NULL),
        m_name(NULL),
        m_back(NULL),
        m_detList(NULL),
        m_detListProvider(NULL),
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        m_msgs(NULL),
        m_msgListProvider(NULL),
    #endif
        m_calls(NULL),
        m_clogListProvider(NULL),
        m_tab(NULL),
        m_currTab(VAPP_SHELL_FC_DETAIL_INFO),
        m_FC(NULL),
        m_msgInfo(NULL),
        m_effect(NULL),
        m_state(0) {}

public:
    // set focused fc to detail screen
    void setFC(VappShellFC* fc);

    // on init view life cycle
    void onInitView();

    // on deinit view life cycle
    void onDeinitView();
    
    // on enter view life cycle
    void onEnterView();
    void onEnterViewEffect();

    // on exit view life cycle
    void onExitView(VfxBool keepData);
    void onExitViewEffect();

    void onEffectFinisted(VfxFrame *obj, VfxBool isCompleted);

public:
    void onUpdateContent(VappShellFCList*, mmi_event_struct*);
    void onSwitchTab(VfxObject* obj, VfxId itemId);
    void onTapItem(VcpListMenu* list, VfxU32 index);
    void onBackButton(VfxObject* obj, VfxId id);
    void onTabImage(VfxObject *obj, VfxId id);
    void onTabImageCb(VfxObject *obj, VfxId id);

public:
    void initHistory();
    void storeHistory();
    void getHistory();

protected:
    virtual void onInit();
    virtual void onDeinit();

public:
    // signal to parent frame to add new fc or show detail screen
    VfxSignal0 m_signalBack;

private:
    void configTab();
    void onTimeChanged(
        VfxU32 flag     // [IN] Bit-OR flag indicating the change
    );

private:
    // details
    VappFCImageButton*  m_FCImg;                // FC image
    VappFCNameFrame*    m_name;                 // FC name
    VcpButton*          m_back;                 // back button
    
    VcpListMenu*        m_detList;              // details list
    VappShellListDetailProvider* m_detListProvider;
    
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    VcpListMenu*        m_msgs;                 // FC messages
    VappMsgListProvider*         m_msgListProvider;
    #endif 
    
    VcpListMenu*        m_calls;                // FC call history
    VappShellListCHProvider*     m_clogListProvider;
    
    VcpTabBar*          m_tab;                  // FC tab command
    VfxU8               m_currTab;              // current tab list

    VappShellFC*        m_FC;                   // favorite contact list
    srv_um_msg_info_struct  *m_msgInfo;         // message info struct

    VcpFrameEffect      *m_effect;              // fade out effect

    VfxBool             m_state;                // enter view or exit view
    static ListHistory  m_history;              // history data for redraw screen
};


/***************************************************************************** 
 * Class VappShellFCFrame
 *****************************************************************************/
class VappShellFCFrame : public VappShellPanel
{
    VFX_DECLARE_CLASS(VappShellFCFrame);
    
    VAPP_SHELL_PANEL_CREATE(VappShellFCFrame, VFX_FALSE);

public:
    // screen info
    enum VappShellFCScr
    {
        VAPP_SHELL_FC_SCR_MENU,
        VAPP_SHELL_FC_SCR_DETAIL,
        VAPP_SHELL_FC_SCR_TOTAL
    };

public:
    // Contstructor
    VappShellFCFrame();

public:
    // update screen info
    void onUpdateContent(VappShellFCList*, mmi_event_struct*);

    // back from detail screen
    void onBackDetailScr();

    // tap menu cell, invoke detail screen or go to contact selector CUI
    void onTapMenuCell(VappShellFC3DScr* scr, VappShellFC* fc);

protected:
    // get panel string id
    virtual VfxS32 getPanelStrId()
    {
        return VAPP_SHELL_FC_STR_FC;
    }
    // init/deinit
    virtual void onInit();
    virtual void onDeinit();

    // init view, create/destroy components
    virtual void onInitView();
    virtual void onDeinitView();

    // update components data
    virtual void onEnterView();
    virtual void onExitView(ShellExitCauseEnum cause);

    // detail screen handler
    void onEnterDetailView();
    void onExitDetailView();
    
private:
    void setState(VappShellFCScr curr_state)
    {
        m_activeScr = curr_state;
    }
    VappShellFCScr getState() const
    {
        return m_activeScr;
    }

    void stateConfig();
    
private:
    // layout
    // VappShellFCFrame    ---->  3D mode frame   ---->   VappShellFCMenu
    //                                                    VcpSegmentButton
    //                            details frame   ---->   VcpImageButton
    //                                            ---->   VcpButton
    //                                            ---->   VcpListMenu(VcpListMenu, VcpListMenu)
    //                                            ---->   VcpTabButton
    
    VappShellFCScr          m_activeScr;            // screen info

    VappShellFCList         *m_FCList;               // FC object list

    VappShellFC3DScr        *m_FC3DScr;              // 3D menu frame
    VappShellFCDetailScr    *m_FCDetailScr;          // FC details info frame
    VfxImageFrame           *m_bg;
    VcpWaitingIcon          *m_info;                // waiting icon
};



#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#endif /* __MMI_VUI_SHELL_FAV_CONTACT__ */
#endif /* __VAPP_SHELL_fc_H__ */



