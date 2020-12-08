
#include "MMI_features.h"


#ifdef __MMI_NCENTER_SUPPORT__


#include "vsrv_ncenter.h"
#include "vapp_ncenter_gprot.h"
#include "SatSrvGprot.h"
#include "Vsrv_notification.h"
#include "Vapp_sat_pluto.h"


#ifdef __cplusplus
extern "C"{
#endif
#include "NwNameSrvGprot.h"
#include "ImeiSrvGprot.h"
#ifdef __cplusplus
}
#endif

#define VAPP_SAT_NCENTER_EVENT_CELL_MAIN_TEXT_X         (50)
#define VAPP_SAT_NCENTER_EVENT_CELL_TEXT_SIZE           (20)
#define VAPP_SAT_NCENTER_EVENT_CELL_ICON_X              (10)




/***************************************************************************** 
 * Class VappSatNcell
 *****************************************************************************/

class VappSatContextNcell : public VappNCenterEventCell
{
	VFX_DECLARE_CLASS(VappSatContextNcell);

public:
	VappSatContextNcell();
	virtual ~VappSatContextNcell();    //MAUI_03318704

public:
	virtual void onInit();
	virtual void updateElements();
    void createBaseCellWithMarquee(void *viewData);
private:
	VcpMarquee *m_cText;

};

class VappSatNcell : public VsrvNCell
{
	VFX_DECLARE_CLASS(VappSatNcell);
	
protected:
	virtual void onCreateView(void * viewData,VfxU32 viewDataSize);
	//virtual void onCloseView(void )
	//virtual void onCloseView();


private:
	VappSatContextNcell *m_notification;
};



VFX_IMPLEMENT_CLASS("VappSatNcell", VappSatNcell, VsrvNCell);

void VappSatNcell::onCreateView(void * viewData,VfxU32 viewDataSize)
{
	    VFX_OBJ_CREATE(m_notification, VappSatContextNcell, this);
        m_notification->setNotification(getNotification());
        setSize(m_notification->getSize());

		m_notification->setIsDisabled(VFX_TRUE);
        m_notification->createBaseCellWithMarquee(viewData);
}


VFX_IMPLEMENT_CLASS("VappSatContextNcell", VappSatContextNcell, VappNCenterEventCell);
VappSatContextNcell::VappSatContextNcell()
{
}

VappSatContextNcell::~VappSatContextNcell()
{
}

void VappSatContextNcell::onInit()
{
	VappNCenterEventCell::onInit();
}

void VappSatContextNcell::updateElements()
{

	VappNCenterEventCell::updateElements();
}

void VappSatContextNcell::createBaseCellWithMarquee(void *viewData)
{
	srv_sat_setup_idle_display_event_struct *idle_mode_text_ext = (srv_sat_setup_idle_display_event_struct *)viewData;
	
	srv_nw_name_service_indication_struct tmp_indication;
	if(srv_imei_is_valid(idle_mode_text_ext->sim_id))
	{
		srv_nw_name_get_service_indication_string(idle_mode_text_ext->sim_id, &tmp_indication);
		m_mainText->setString(VFX_WSTR_MEM(tmp_indication.line2));
	}
	else
	{
		if(idle_mode_text_ext->sim_id == MMI_SIM1)
		{
			m_mainText->setString(VFX_WSTR("SIM 1 Toolkit"));

		}		
#if MMI_MAX_SIM_NUM >= 2
		else if(idle_mode_text_ext->sim_id == MMI_SIM2)
		{
			m_mainText->setString(VFX_WSTR("SIM 2 Toolkit"));
		}
#if MMI_MAX_SIM_NUM >= 3
		else if(idle_mode_text_ext->sim_id == MMI_SIM3)
		{
			m_mainText->setString(VFX_WSTR("SIM 3 Toolkit"));

		}
#if MMI_MAX_SIM_NUM >= 4	
		else if(idle_mode_text_ext->sim_id == MMI_SIM4)
		{
			m_mainText->setString(VFX_WSTR("SIM 4 Toolkit"));
	
		}
#endif
#endif
#endif

	}	
	
	
	VFX_OBJ_CREATE(m_cText, VcpMarquee, this);
	//srv_nw_name_get_service_indication_string(mmi_sim_enum sim,srv_nw_name_service_indication_struct * service_indication)
  
	

#ifndef __SAT_DISABLE_ICON_SUPPORT__
	const U8* icon_data = srv_sat_get_idle_display_icon(idle_mode_text_ext->sim_id);
	if(icon_data)
      m_icon->setImgContent(VfxImageSrc(icon_data));

#endif //__SAT_DISABLE_ICON_SUPPORT__
    
	m_cText->setPos(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X, VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y);
	m_cText->setAnchor(0, 1.0f);
	m_cText->setPos(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X, VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y);
	
	m_cText->setAutoResized(VFX_TRUE);
	
	m_cText->setSize(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH, m_subText->getSize().height);
	m_cText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);


    m_cText->setMovableFrame(VFX_WSTR_MEM(srv_sat_get_idle_display_text(idle_mode_text_ext->sim_id)), VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE)));
    m_cText->setTextColor(VFX_COLOR_RES(VFX_COLOR_BLACK));
    m_cText->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
    m_cText->startScroll();
	
	
	VsrvNotificationEvent* noti = (VsrvNotificationEvent*)m_noti;
	VfxDateTime currTime, notiTime = noti->getTimeStamp();
	currTime.setCurrentTime();
	if (notiTime.getYear() == currTime.getYear()&&
            notiTime.getMonth() == currTime.getMonth() &&
            notiTime.getDay() == currTime.getDay())
    {
        m_rightText->setString(noti->getTimeStamp().getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE)); 
    }
    else
    {
		m_rightText->setString(noti->getTimeStamp().getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY));                                        
    } 
	
}


/**************************************************************
 * Function Defination                                        *
 **************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_send_NCenter_notification
 * DESCRIPTION
 *  send notification to the NCenter.
 * PARAMETERS
 *  mmi_event_struct , APP_ID
 * RETURNS
 *  mmi_ret
 *****************************************************************************/

mmi_ret vapp_send_NCenter_notification (mmi_event_struct *evt, int app_id)
{    

    VFX_ASSERT(evt != NULL);
	srv_sat_setup_idle_display_event_struct *idle_mode_text = (srv_sat_setup_idle_display_event_struct *)evt;

	VsrvNGroupSingleTitle *group = NULL;
	VSRV_NGROUP_CREATE_EX(group , VsrvNGroupSingleTitle, (app_id));
	
	VsrvNotificationCustom *noti = NULL;

	if(idle_mode_text->present)
	{
		mmi_frm_notification_para_struct noti_status;
        noti_status.option = 0;
        noti_status.text = srv_sat_get_idle_display_text(idle_mode_text->sim_id);
       
		mmi_frm_nmgr_notify(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SAT_IDLE_TEXT, &noti_status);

		VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationCustom , (group, mmi_frm_sim_to_index(idle_mode_text->sim_id)));

	    group->setTitle(VFX_WSTR("SIM Toolkit"));
		noti->setCurrentTime();
		noti->setCategory(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT);
		noti->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappSatNcell), VSRV_NVIEWER_TYPE_GENERAL, evt, sizeof(srv_sat_setup_idle_display_event_struct));
		noti->setAutoLaunch(VFX_FALSE);
		noti->setAutoClose(VFX_FALSE);	
		noti->setFlag(VSRV_NOTIFICATION_FLAG_NO_FOCUS | VSRV_NOTIFICATION_FLAG_NO_CLEAR_BUTTON, VFX_TRUE);  //MAUI_03195824
		noti->notify();		
	

	}
	else
	{
		VSRV_NOTIFICATION_CLOSE_EX(group, mmi_frm_sim_to_index(idle_mode_text->sim_id));
	}
	if(group->getCount() == 0)
	{
		VSRV_NGROUP_CLOSE_EX(app_id);
	}
	return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  create_scroll_text
 * DESCRIPTION
 *  calls the fuction for Ncenter.
 * PARAMETERS
 *  mmi_event_struct, app_id
 * RETURNS
 *  void
 *****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif
void mmi_SAT_create_scroll_text(mmi_event_struct *evt, int app_id)
{
	vapp_send_NCenter_notification(evt,app_id);
}

#ifdef __cplusplus
}
#endif

#endif