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

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_v2p_nmgr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *    This file is used to provide C-style function for PLUTO NMGR
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_frm_gprot.h"
#include "Wgui_categories_util.h"
#include "NotificationGProt.h"
#include "NotificationSettingSrvGprot.h"

#ifdef __cplusplus
}   /* extern "C" */
#endif
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vadp_p2v_uc.h"
#include "vcp_status_icon_bar.h"
#include "vcp_global_popup.h"

#ifdef __COSMOS_MMI_PACKAGE__

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_proc_func scrn_group_proc;    
    void *proc_user_data;
} mmi_nmgr_cb_evt_struct;

typedef struct
{
    mmi_nmgr_balloon_pattern_enum pattern;
    S32 x;
    S32 y;
    mmi_nmgr_balloon_type_enum balloon_type;
    WCHAR *text;
	MMI_BOOL has_status_bar;
} balloon_info_struct;

class VadpBaloonScr: public VfxAppCatScr
{
public:
	VadpBaloonScr() {
		setIsSmallScreen();
	}
	VadpBaloonScr(void *arg, MMI_ID id) : m_arg(arg), m_ScrnId(id){
		setIsSmallScreen();
	}
protected:
	virtual void onInit();
	virtual void onDeinit();
	virtual void onEntered(VfxBool isBackward);
	virtual void onBalloonLeave(VfxObject *obj);
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
private:
	void *m_arg;
	MMI_ID m_ScrnId;
	balloon_info_struct *m_info;
	VfxWString m_text;
};
static void vadp_v2p_nmgr_display_info_balloon_int(
    mmi_nmgr_balloon_pattern_enum pattern,
    S32 x,
    S32 y,
    mmi_nmgr_balloon_type_enum balloon_type,
    WCHAR *text);
static VadpBaloonScr *pScr = NULL; 
static mmi_frm_screen_rotate_enum rotate_degree;
extern "C" void vadp_v2p_nmgr_close_balloon(mmi_nmgr_balloon_pattern_enum pattern)
{
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    if (pattern == MMI_NMGR_BALLOON_UNDER_STATUS_BAR)
    {
        balloon->cancelCurrentUpperItem();
    }
    else if(pattern == MMI_NMGR_BALLOON_ABOVE_TOOL_BAR)
    {
        balloon->cancelCurrentBottomItem();
    }
}

extern "C" void vadp_v2p_nmgr_upper_balloon_move(S32 x, S32 y)
{
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    VfxPoint point(x, y);
    balloon->moveCurrentUpperItem(point);
}

void VadpBaloonScr::onEntered(VfxBool isBackward)
{
	VfxAppCatScr::onEntered(isBackward);
	if (isBackward) return; 
	vadp_v2p_nmgr_display_info_balloon_int(
		m_info->pattern,
		m_info->x,
		m_info->y,
		m_info->balloon_type,
		m_info->text);
}

void VadpBaloonScr::onDeinit()
{
	VFX_FREE_MEM(m_info);
	VfxAppCatScr::onDeinit();
}

void VadpBaloonScr::onInit()
{
	VfxAppCatScr::onInit();

	VFX_ALLOC_MEM(m_info, sizeof(balloon_info_struct), this);
	memcpy(m_info, m_arg, sizeof(balloon_info_struct));

	if (m_info->has_status_bar == MMI_TRUE)
	{
		VcpStatusIconBar *icon_bar;
		VFX_OBJ_CREATE(icon_bar, VcpStatusIconBar, this);
	}
	m_text.loadFromMem(m_info->text);
	m_info->text = VFX_CONST_CAST(m_text.getBuf(), WCHAR *);
	VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
	balloon->m_signalBallonClosed.connect(this, &VadpBaloonScr::onBalloonLeave);
}

void VadpBaloonScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
	VfxScrRotateTypeEnum r = VFX_SCR_ROTATE_TYPE_0;
	switch (rotate_degree)
	{
		case MMI_FRM_SCREEN_ROTATE_0:
		{
			r = VFX_SCR_ROTATE_TYPE_0;
		}
		break;

		case MMI_FRM_SCREEN_ROTATE_90:
		{
		    r = VFX_SCR_ROTATE_TYPE_90;
		}
		break;

		case MMI_FRM_SCREEN_ROTATE_180:
		{
			r = VFX_SCR_ROTATE_TYPE_180;
		}
		break;

		case MMI_FRM_SCREEN_ROTATE_270:
		{
			r = VFX_SCR_ROTATE_TYPE_270;
		}
		break;
	}
	param.rotateTo = r;
}

void VadpBaloonScr::onBalloonLeave(VfxObject *obj)
{
	VcpInfoBalloon *balloon = VFX_STATIC_CAST(obj, VcpInfoBalloon*);
	balloon->m_signalBallonClosed.disconnect(this, &VadpBaloonScr::onBalloonLeave);
	mmi_frm_group_close(m_ScrnId);	
}

#define VADP_NMGR_BALLOON_CAT_SCR_HEAP_SIZE  4096
static mmi_ret scrn_proc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_SCRN_ACTIVE:
		{
			mmi_frm_scrn_active_evt_struct *p = (mmi_frm_scrn_active_evt_struct *)evt;
			mmi_frm_scrn_clear_attribute(p->group_id, p->scrn_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
			set_small_screen();
			VfxAppCatScr::initalizeWithScrAsmSize(VADP_NMGR_BALLOON_CAT_SCR_HEAP_SIZE);
			VFX_OBJ_CREATE_EX(pScr, VadpBaloonScr, VfxAppCatScr::getContext(), (p->user_data, p->scrn_id));
			break;
		}
		case EVT_ID_SCRN_INACTIVE:
		{
			VFX_OBJ_CLOSE(pScr);
			VfxAppCatScr::deinitalize();
		}
	}
	return MMI_RET_OK;
}

static void create_pluto_screen(void *arg)
{
	MMI_ID id;
	rotate_degree = mmi_frm_get_screen_rotate();
	id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_frm_scrn_create(id, id, scrn_proc, arg);
}

static void vadp_v2p_nmgr_display_info_balloon_int(
    mmi_nmgr_balloon_pattern_enum pattern,
    S32 x,
    S32 y,
    mmi_nmgr_balloon_type_enum balloon_type,
    WCHAR *text)
{
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    VfxWString string;
    string.loadFromMem(text);
    VcpInfoBalloonTypeEnum type;
    switch (balloon_type)
    {
        case MMI_NMGR_BALLOON_TYPE_FAILURE:
            type = VCP_INFO_BALLOON_TYPE_FAILURE;
            break;
            
        case MMI_NMGR_BALLOON_TYPE_INFO:
            type = VCP_INFO_BALLOON_TYPE_INFO;
            break;
            
        case MMI_NMGR_BALLOON_TYPE_WARNING:
            type = VCP_INFO_BALLOON_TYPE_WARNING;
            break;
            
        case MMI_NMGR_BALLOON_TYPE_SUCCESS:
            type = VCP_INFO_BALLOON_TYPE_SUCCESS;
            break;
            
        case MMI_NMGR_BALLOON_TYPE_PROGRESS:
            type = VCP_INFO_BALLOON_TYPE_PROGRESS;
            break;
        default:
            type = VCP_INFO_BALLOON_TYPE_TOTAL;
            VFX_ASSERT(0);
            break;
    }
    if (pattern == MMI_NMGR_BALLOON_UNDER_STATUS_BAR)
    {
        VfxPoint point(x, y);
        balloon->addItem(type, string, point);
    }
    else
    {
	    balloon->addItem(type, string);
    }
}

extern "C" void vadp_v2p_nmgr_display_info_balloon(
    mmi_nmgr_balloon_pattern_enum pattern,
    S32 x,
    S32 y,
    mmi_nmgr_balloon_type_enum balloon_type,
    WCHAR *text)
{
	if (vadp_p2v_uc_is_in_venus() == VFX_FALSE)
	{
		balloon_info_struct info;
		info.pattern = pattern;
		info.x       = x;
		info.y       = y;
		info.balloon_type = balloon_type;
		info.text = text;
		info.has_status_bar = wgui_status_icon_bar_is_display(WGUI_STATUS_ICON_BAR_H_BAR);
		create_pluto_screen((void *)&info);
	}
	else
	{
		vadp_v2p_nmgr_display_info_balloon_int(
			pattern,
			x,
			y,
			balloon_type,
			text);
	}
}

/*popup stack node*/
typedef struct _mmi_nmgr_alert_popup_node_struct
{
    VfxS32 popup_handle;
    VcpConfirmPopup *popup_scrn;
    VfxBool is_button_pressed_launch;
    mmi_frm_nmgr_alert_struct popup_info;
    struct _mmi_nmgr_alert_popup_node_struct *next;
} mmi_nmgr_alert_popup_node_struct;
/*popup stack list*/
typedef struct
{
    U32 list_counter;    
    mmi_nmgr_alert_popup_node_struct *next;    
} mmi_nmgr_alert_popup_list_struct;

static mmi_nmgr_alert_popup_list_struct g_nmgr_popup_list = {0,NULL};
    
class VappNMGRAlertTwoButtonPopup : public VcpConfirmPopup
{
    VFX_DECLARE_CLASS(VappNMGRAlertTwoButtonPopup);
public:        
    VappNMGRAlertTwoButtonPopup();
    VappNMGRAlertTwoButtonPopup(void* user_data);
    virtual ~VappNMGRAlertTwoButtonPopup(){if(m_popup_node)mmi_frm_end_scenario(m_popup_node->popup_info.scen_id);};
    void onButtonClickCB(VfxObject* sender, VfxId id);
    void setButtonText(const VfxWString &text);

protected:
    virtual void onInit();        
    mmi_nmgr_alert_popup_node_struct* m_popup_node;    
};

VFX_IMPLEMENT_CLASS("VappNMGRAlertTwoButtonPopup", VappNMGRAlertTwoButtonPopup, VcpConfirmPopup);

class VappNMGRAlertOneButtonPopup : public VcpConfirmPopup
{
    VFX_DECLARE_CLASS(VappNMGRAlertOneButtonPopup);
public:    
    VappNMGRAlertOneButtonPopup();
    VappNMGRAlertOneButtonPopup(void* user_data);
    virtual ~VappNMGRAlertOneButtonPopup(){if(m_popup_node)mmi_frm_end_scenario(m_popup_node->popup_info.scen_id);};
    void onButtonClickCB(VfxObject* sender, VfxId id);	

protected:
    virtual void onInit();    
    mmi_nmgr_alert_popup_node_struct* m_popup_node;    
};

VFX_IMPLEMENT_CLASS("VappNMGRAlertOneButtonPopup", VappNMGRAlertOneButtonPopup, VcpConfirmPopup);

VappNMGRAlertTwoButtonPopup::VappNMGRAlertTwoButtonPopup()	
{
    m_popup_node = NULL;            
}

VappNMGRAlertTwoButtonPopup::VappNMGRAlertTwoButtonPopup(void* user_data)	
{
   m_popup_node = (mmi_nmgr_alert_popup_node_struct *)user_data;       
}

void VappNMGRAlertTwoButtonPopup::onButtonClickCB(VfxObject* sender, VfxId id)
{
    m_popup_node->is_button_pressed_launch= VFX_FALSE; 	
    if(sender == m_button[0])
    {
        m_popup_node->is_button_pressed_launch= VFX_TRUE; 	        
    }
    leave(VFX_TRUE);
}


void VappNMGRAlertTwoButtonPopup::setButtonText(const VfxWString &text)
{
    m_button[0]->setText(text);    
}


void VappNMGRAlertTwoButtonPopup::onInit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    VcpConfirmPopup::onInit();    
    /*Create the button "user defined"*/
    VFX_OBJ_CREATE(m_button[0], VcpScrollingTextButton, m_backgroundBottom);
    m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_button[0]->setInnerRect(VfxRect(
                                VCP_CONFIRM_POPUP_BUTTON_X, 
                                VCP_CONFIRM_POPUP_BUTTON_Y, 
                                VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                         ));
    m_button[0]->setText(VFX_WSTR_MEM((VfxWChar *)m_popup_node->popup_info.popup_para.popup_button_string));
    ((VcpScrollingTextButton*)m_button[0])->setScrollOnHighlight(VFX_TRUE);
    m_button[0]->setIsHighlighted(VFX_TRUE);

    // Set up the click callback here
    m_button[0]->m_signalClicked.connect(this, &VappNMGRAlertTwoButtonPopup::onButtonClickCB);
    /*Create the button "cancel"*/
    VFX_OBJ_CREATE(m_button[1], VcpScrollingTextButton, m_backgroundBottom);
    m_button[1]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_button[1]->setInnerRect(VfxRect(
                                VCP_CONFIRM_POPUP_BUTTON_X, 
                                VCP_CONFIRM_POPUP_BUTTON_Y + VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP, 
                                VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                            ));
    m_button[1]->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
    m_cancelButtonIndex = 1;
    m_button[1]->setStyle(VCP_BUTTON_STYLE_GREY);
    m_button[1]->setTextColor(VfxColor(VFX_COLOR_WHITE));
    
    // Set up the click callback here
    m_button[1]->m_signalClicked.connect(this, &VappNMGRAlertTwoButtonPopup::onButtonClickCB);
    m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);	
    m_bottomRegionHeight = 2 * VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BUTTON_GAP + VCP_CONFIRM_POPUP_BOTTOM_HEIGHT;

    checkUpdate();
}


VappNMGRAlertOneButtonPopup::VappNMGRAlertOneButtonPopup()	
{
    m_popup_node = NULL;       
}

VappNMGRAlertOneButtonPopup::VappNMGRAlertOneButtonPopup(void* user_data)	
{   
    m_popup_node =  (mmi_nmgr_alert_popup_node_struct *)user_data;
}
 
void VappNMGRAlertOneButtonPopup::onButtonClickCB(VfxObject* sender, VfxId id)
{
    m_popup_node->is_button_pressed_launch= VFX_FALSE; 	    
    leave(VFX_TRUE);
}

void VappNMGRAlertOneButtonPopup::onInit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VcpConfirmPopup::onInit();    
    /*Create button and set its content*/
    VFX_OBJ_CREATE(m_button[0], VcpScrollingTextButton, m_backgroundBottom);
    m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    /*Set its size*/
    m_button[0]->setInnerRect(VfxRect(
                                VCP_CONFIRM_POPUP_BUTTON_X, 
                                VCP_CONFIRM_POPUP_BUTTON_Y, 
                                VCP_CONFIRM_POPUP_BUTTON_WIDTH, 
                                VCP_CONFIRM_POPUP_BUTTON_HEIGHT
                            ));
    /*Set the string content*/
    m_button[0]->setText(VFX_WSTR_RES(STR_GLOBAL_OK));
    m_cancelButtonIndex = 1;
    m_button[0]->setStyle(VCP_BUTTON_STYLE_GREY);
    m_button[0]->setTextColor(VfxColor(VFX_COLOR_WHITE));
    
    /* Set up the click callback here */
    m_button[0]->m_signalClicked.connect(this, &VappNMGRAlertOneButtonPopup::onButtonClickCB);
    m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);	
    m_bottomRegionHeight = VCP_CONFIRM_POPUP_BUTTON_HEIGHT + VCP_CONFIRM_POPUP_BOTTOM_HEIGHT;

    checkUpdate();
}

static mmi_ret nmgr_cb_func(mmi_event_struct *param)
{
    mmi_event_struct evt;
    mmi_nmgr_cb_evt_struct *p = (mmi_nmgr_cb_evt_struct *)param;
    MMI_FRM_INIT_EVENT(&evt, p->evt_id);    
    MMI_FRM_SEND_EVENT(&evt, p->scrn_group_proc, p->proc_user_data);   
    /*free user data*/
    if( p->proc_user_data!=NULL)
    {
        mmi_frm_nmgr_mem_free((void *) p->proc_user_data);
    }
    return MMI_RET_OK;
}

static VfxBasePopup *two_button_confirm_popup(VfxObject* parent, void* userdata)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappNMGRAlertTwoButtonPopup *twobutton_alert_popup = NULL;	
    mmi_nmgr_alert_popup_node_struct *p = (mmi_nmgr_alert_popup_node_struct *)userdata;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_start_scenario(p->popup_info.scen_id);
    VFX_OBJ_CREATE_EX(twobutton_alert_popup, VappNMGRAlertTwoButtonPopup, parent, (p));
    /*Show image by its type*/
    switch(p->popup_info.popup_para.image_type)
    {
        case MMI_NMGR_IMG_RES_ID:
            twobutton_alert_popup->setImage(VfxImageSrc(p->popup_info.popup_para.image.id));
        break;
        case MMI_NMGR_IMG_FILE_PATH:
        {
            VfxImageSrc imgSrc;
            imgSrc.setPath(VfxWString().loadFromMem(p->popup_info.popup_para.image.file_path));
            twobutton_alert_popup->setImage(imgSrc);
        }
        break;
        case MMI_NMGR_IMG_DATA_BUFF:
        {
            VfxImageSrc imgSrc;
            imgSrc.setMem(p->popup_info.popup_para.image.data);
            twobutton_alert_popup->setImage(imgSrc);
        }
        break;
        case MMI_NMGR_IMG_RAW_DATA_BUFF:             
        {
            VfxFileRawDataFormatEnum format = VFX_FILE_FORMAT_TYPE_AUTO;  
    
            switch(p->popup_info.popup_para.image.raw_data.format)
            {
                case GDI_IMAGE_TYPE_BMP:
                    format = VFX_FILE_FORMAT_TYPE_BMP;
                break;        
                case GDI_IMAGE_TYPE_GIF:    
                    format = VFX_FILE_FORMAT_TYPE_GIF;
                break;                           
                case GDI_IMAGE_TYPE_JPG:    
                    format = VFX_FILE_FORMAT_TYPE_JPG;
                break;                           
                case GDI_IMAGE_TYPE_PNG:    
                    format = VFX_FILE_FORMAT_TYPE_PNG;
                break;                           
                case GDI_IMAGE_TYPE_ABM:    
                    format = VFX_FILE_FORMAT_TYPE_ABM;
                break;                           
                case GDI_IMAGE_TYPE_AB2:                        
                    format = VFX_FILE_FORMAT_TYPE_AB2;
                break;                                               
            }
            {
                VfxImageSrc imgSrc(p->popup_info.popup_para.image.raw_data.buff, 
                    p->popup_info.popup_para.image.raw_data.size, 
                    format);
                twobutton_alert_popup->setImage(imgSrc);
            }            
        }
        break;
    }
    twobutton_alert_popup->setText(VFX_WSTR_MEM((VfxWChar *)(p->popup_info.popup_para.popup_string)));
    twobutton_alert_popup->setAutoDestory(VFX_FALSE);
    p->popup_scrn = twobutton_alert_popup;
    return twobutton_alert_popup;
}

static VfxBasePopup *one_button_confirm_popup(VfxObject* parent, void* userdata)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappNMGRAlertOneButtonPopup *onebutton_alert_popup = NULL;
    mmi_nmgr_alert_popup_node_struct *p = (mmi_nmgr_alert_popup_node_struct *)userdata;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_start_scenario(p->popup_info.scen_id);
    VFX_OBJ_CREATE_EX(onebutton_alert_popup, VappNMGRAlertOneButtonPopup, parent, (p));
    onebutton_alert_popup->setText(VFX_WSTR_MEM((VfxWChar *)(p->popup_info.popup_para.popup_string)));
    /*Show image by its type*/
    switch(p->popup_info.popup_para.image_type)
    {
        case MMI_NMGR_IMG_RES_ID:
            onebutton_alert_popup->setImage(VfxImageSrc(p->popup_info.popup_para.image.id));
        break;
        case MMI_NMGR_IMG_FILE_PATH:
        {
            VfxImageSrc imgSrc;
            imgSrc.setPath(VfxWString().loadFromMem(p->popup_info.popup_para.image.file_path));
            onebutton_alert_popup->setImage(imgSrc);
        }
        break;
        case MMI_NMGR_IMG_DATA_BUFF:
        {
            VfxImageSrc imgSrc;
            imgSrc.setMem(p->popup_info.popup_para.image.data);
            onebutton_alert_popup->setImage(imgSrc);
        }
        break;
        case MMI_NMGR_IMG_RAW_DATA_BUFF:
        {
            VfxFileRawDataFormatEnum format = VFX_FILE_FORMAT_TYPE_AUTO;  
    
            switch(p->popup_info.popup_para.image.raw_data.format)
            {
                case GDI_IMAGE_TYPE_BMP:
                    format = VFX_FILE_FORMAT_TYPE_BMP;
                break;        
                case GDI_IMAGE_TYPE_GIF:    
                    format = VFX_FILE_FORMAT_TYPE_GIF;
                break;                           
                case GDI_IMAGE_TYPE_JPG:    
                    format = VFX_FILE_FORMAT_TYPE_JPG;
                break;                           
                case GDI_IMAGE_TYPE_PNG:    
                    format = VFX_FILE_FORMAT_TYPE_PNG;
                break;                           
                case GDI_IMAGE_TYPE_ABM:    
                    format = VFX_FILE_FORMAT_TYPE_ABM;
                break;                           
                case GDI_IMAGE_TYPE_AB2:                        
                    format = VFX_FILE_FORMAT_TYPE_AB2;
                break;                                               
            }
            {
                VfxImageSrc imgSrc(p->popup_info.popup_para.image.raw_data.buff, 
                    p->popup_info.popup_para.image.raw_data.size, 
                    format);
                onebutton_alert_popup->setImage(imgSrc);
            }            
        }
        break;
    }
    p->popup_scrn = onebutton_alert_popup;
    return onebutton_alert_popup;
}

static void nmgr_popup_clean_func(VfxId id, void *userdata)
{      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_alert_popup_node_struct *remove_node = NULL, *prev_remove_node=NULL;
    mmi_nmgr_alert_popup_node_struct *p = (mmi_nmgr_alert_popup_node_struct *)userdata;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Find out the node that will be removed*/    
    for(  remove_node = g_nmgr_popup_list.next; 
            remove_node!=NULL ; 
            prev_remove_node = remove_node, remove_node=remove_node->next)
    {
        if(remove_node->popup_handle == p->popup_handle)
        {            
            /*Remove the node from list*/
            if(prev_remove_node == NULL)
            {                        
                g_nmgr_popup_list.next = remove_node->next;
            }
            else
            {
                prev_remove_node->next = remove_node->next;
            }
            g_nmgr_popup_list.list_counter--;
            /*Call launch or cancel by pressed status*/
            if(p->popup_info.app_proc_para.scrn_group_proc)
            {
                mmi_nmgr_cb_evt_struct evt;
                if(p->is_button_pressed_launch == VFX_TRUE)
                {
                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_POPUP_APP_LAUNCH);
                }        
                else                
                {
                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_ALERT_END);
                }
                evt.scrn_group_proc = p->popup_info.app_proc_para.scrn_group_proc;
                evt.proc_user_data = NULL;
                if(p->popup_info.app_proc_para.data_size > 0)
                {
                    evt.proc_user_data = p->popup_info.app_proc_para.user_data;
                }
                MMI_FRM_POST_EVENT(&evt, &nmgr_cb_func, NULL);   
            }
            /*close the popup*/
            vcp_global_popup_cancel(remove_node->popup_handle);           
            /*free popup string*/
            if(remove_node->popup_info.popup_para.popup_string)
            {
                mmi_frm_nmgr_mem_free((void *)remove_node->popup_info.popup_para.popup_string);
            }
            /*free popup button*/
            if(remove_node->popup_info.popup_para.popup_button_string)
            {
                mmi_frm_nmgr_mem_free((void *)remove_node->popup_info.popup_para.popup_button_string);
            }
            /*free image file path*/            
            if(remove_node->popup_info.popup_para.image_type == MMI_NMGR_IMG_FILE_PATH
				&& remove_node->popup_info.popup_para.image.file_path !=NULL)
            {
                mmi_frm_nmgr_mem_free((void *)remove_node->popup_info.popup_para.image.file_path);
            }                 
            /*free remove node*/
            mmi_frm_nmgr_mem_free(remove_node);
            break;
        }
    }   
}


extern "C" MMI_BOOL vadp_v2p_nmgr_alert_popup_refresh(mmi_frm_nmgr_alert_struct *update_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_alert_popup_node_struct *find_node = NULL;
    mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for(  find_node = g_nmgr_popup_list.next; 
            find_node!= NULL ; 
            find_node = find_node->next)
    {
        /*Check if new node already exist in popup stack*/
        if(find_node->popup_info.app_id == update_info->app_id
            && find_node->popup_info.event_type == update_info->event_type
            && find_node->popup_info.popup_para.popup_type == update_info->popup_para.popup_type
            && find_node->popup_info.app_proc_para.scrn_group_proc == update_info->app_proc_para.scrn_group_proc)
        {
            MMI_ID active_id = mmi_frm_group_get_active_id();
            /*Check if the popup is active scrn*/           
            if(find_node->popup_handle == active_id)
            {/*If yes, refresh it directly*/                
                /*Cancel the old popup*/
                if(find_node->popup_info.app_proc_para.scrn_group_proc)
                {            
                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_ALERT_END);
                    MMI_FRM_SEND_EVENT(&evt, find_node->popup_info.app_proc_para.scrn_group_proc, find_node->popup_info.app_proc_para.user_data);   
                } 
                /*free old popup's info*/
                if(find_node->popup_info.popup_para.popup_string)
                {
                    mmi_frm_nmgr_mem_free((void *)find_node->popup_info.popup_para.popup_string);
                }
                /*free popup button*/
                if(find_node->popup_info.popup_para.popup_button_string)
                {
                    mmi_frm_nmgr_mem_free((void *)find_node->popup_info.popup_para.popup_button_string);
                }                
                /*free image file path*/
                if(find_node->popup_info.popup_para.image_type == MMI_NMGR_IMG_FILE_PATH
					&& find_node->popup_info.popup_para.image.file_path!=NULL)
                {
                    mmi_frm_nmgr_mem_free((void *)find_node->popup_info.popup_para.image.file_path);
                }                
                /*free user data*/
                if(find_node->popup_info.app_proc_para.data_size > 0
                    && find_node->popup_info.app_proc_para.user_data!=NULL)
                {
                    mmi_frm_nmgr_mem_free((void *)find_node->popup_info.app_proc_para.user_data);
                }
                /*Save new popup string*/
                find_node->popup_info.popup_para.popup_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(                
                (WCHAR *)update_info->popup_para.popup_string,
                MMI_FRM_NMGR_POPUP_TEXT_CHAR_COUNT
                );
                /*Save new popup button*/
                find_node->popup_info.popup_para.popup_button_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(
                (WCHAR *)update_info->popup_para.popup_button_string,
                MMI_FRM_NMGR_POPUP_TEXT_CHAR_COUNT);
                
                /*Copy image file path to temp buffer if needed*/
                memcpy(&find_node->popup_info.popup_para.image, &update_info->popup_para.image, sizeof(update_info->popup_para.image));
                if(update_info->popup_para.image_type == MMI_NMGR_IMG_FILE_PATH)
                {
                    find_node->popup_info.popup_para.image.file_path = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(
                    update_info->popup_para.image.file_path,
                    MMI_MAX_FILE_NAME_LEN
                    );
                }
                /*Save user data*/
                if(update_info->app_proc_para.data_size > 0)
                {                
                    find_node->popup_info.app_proc_para.user_data = mmi_frm_alloc_and_copy_data_to_nmgr_buff_internal( 
                    update_info->app_proc_para.user_data,
                    update_info->app_proc_para.data_size
                    );
                }
                /*Updata popup string and button string*/
                find_node->popup_scrn->setText(VFX_WSTR_MEM((VfxWChar *)find_node->popup_info.popup_para.popup_string));
                if(find_node->popup_info.popup_para.popup_type == MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE)
                {
                    VappNMGRAlertTwoButtonPopup *twobutton_alert_popup = (VappNMGRAlertTwoButtonPopup *)find_node->popup_scrn;	
                    twobutton_alert_popup->setButtonText(VFX_WSTR_MEM((VfxWChar *)find_node->popup_info.popup_para.popup_button_string));                    
                }
                
                return MMI_TRUE;
            }
            else
            {/*remove it*/                
                nmgr_popup_clean_func(NULL, find_node);
                return MMI_FALSE;
            }            
        }
    }       
    return MMI_FALSE;
}



extern "C" MMI_BOOL vadp_v2p_nmgr_alert_popup(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_alert_struct *p = (mmi_frm_nmgr_alert_struct *)arg;
    mmi_nmgr_alert_popup_node_struct *nmgr_popup_data = NULL;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*If new popup exceed maximum popup stack number, replace the oldest one*/
    if(g_nmgr_popup_list.list_counter == MMI_MAX_CONCURRENT_POPUP_NUM)    
    {//Remove the latest one
        mmi_nmgr_alert_popup_node_struct *remove_node = NULL;
        /*seek the oldest item*/
        for(  remove_node = g_nmgr_popup_list.next; 
            remove_node->next !=NULL ; 
            remove_node = remove_node->next);     
        /*remove the item*/            
        nmgr_popup_clean_func(NULL, remove_node); 
    }
    /*Alloc popup node*/
    nmgr_popup_data = (mmi_nmgr_alert_popup_node_struct *)mmi_frm_nmgr_mem_malloc(sizeof(mmi_nmgr_alert_popup_node_struct));
    MMI_ASSERT(nmgr_popup_data);
    memset(nmgr_popup_data, 0, sizeof(mmi_nmgr_alert_popup_node_struct));

    /*Save popup string*/    
    memcpy(&nmgr_popup_data->popup_info, p, sizeof(mmi_frm_nmgr_alert_struct));
    nmgr_popup_data->popup_info.popup_para.popup_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(
        (WCHAR *)p->popup_para.popup_string,
        MMI_FRM_NMGR_POPUP_TEXT_CHAR_COUNT
        );    
    /*Save popup button*/    
    nmgr_popup_data->popup_info.popup_para.popup_button_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(
        (WCHAR *)p->popup_para.popup_button_string,
        MMI_FRM_NMGR_POPUP_TEXT_CHAR_COUNT);
    /*Copy image file path to temp buffer if needed*/
    if(p->popup_para.image_type == MMI_NMGR_IMG_FILE_PATH)
    {
        nmgr_popup_data->popup_info.popup_para.image.file_path = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(
        p->popup_para.image.file_path,
        MMI_MAX_FILE_NAME_LEN
        );
    }
    /*Save user data*/
    if(p->app_proc_para.data_size > 0)
    {                
        nmgr_popup_data->popup_info.app_proc_para.user_data = mmi_frm_alloc_and_copy_data_to_nmgr_buff_internal( 
        p->app_proc_para.user_data,
        p->app_proc_para.data_size
        );
    }
    /*One button popup(Confirm)*/
    if(p->popup_para.popup_type == MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE)
    {    
        nmgr_popup_data->popup_handle = vcp_global_popup_generic_create(GRP_ID_ROOT,
        nmgr_popup_clean_func,
        one_button_confirm_popup,
        nmgr_popup_data 
        );	        
    }
    else
    {/*Two button popup(User defined + Cancel)*/
        nmgr_popup_data->popup_handle = vcp_global_popup_generic_create(GRP_ID_ROOT,
        nmgr_popup_clean_func,
        two_button_confirm_popup,
        nmgr_popup_data 
        );	
    }
    nmgr_popup_data->next = g_nmgr_popup_list.next;
    g_nmgr_popup_list.next = nmgr_popup_data;
    g_nmgr_popup_list.list_counter++;

    return MMI_TRUE;
}

extern "C" MMI_BOOL vadp_v2p_nmgr_alert_popup_is_defer()
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_alert_popup_node_struct *find_node = NULL;    
    MMI_ID active_id = mmi_frm_group_get_active_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for(  find_node = g_nmgr_popup_list.next; 
            find_node!= NULL ; 
            find_node = find_node->next)
    {
        /*If active ID is anyone of the stack popup, we will defer the new popup for one second delay*/
        if(find_node->popup_handle == active_id)
        {
            return MMI_TRUE;
        }
    }       
    return MMI_FALSE;
}



extern "C" void vadp_v2p_nmgr_alert_popup_cancel(MMI_ID app_id, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_alert_popup_node_struct *find_node = NULL;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for(  find_node = g_nmgr_popup_list.next; 
            find_node!= NULL ; 
            find_node = find_node->next)
    {
        /*Check if new node already exist in popup stack*/
        if(find_node->popup_info.app_id == app_id
            && find_node->popup_info.event_type == event_type)
        {            
            nmgr_popup_clean_func(NULL, find_node);            
        }            
    }       
    return;
}

#endif

