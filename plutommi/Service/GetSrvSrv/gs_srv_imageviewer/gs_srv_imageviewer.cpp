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
*   gs_srv_idlescreen.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IProfile implement file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_IMAGE_VIEWER__)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
	//#include "custom_mmi_default_value.h"
#include "imageviewcuigprot.h"
#include "GlobalResDef.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_imageviewer_impl.h"
#include "vmlog.h"

GS_IBase *CreateImageviewerService(U32 hd)
{
	ImageviewerService* service = NULL;
	GS_NEW_EX(service, ImageviewerService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
}


ImageviewerService::ImageviewerService(U32 handle):GS_CBase(handle)
{
	imgview_gid = GRP_ID_INVALID;
}
S32 CALLCC ImageviewerService::queryInterface(S32 iid, GS_IBase **pptr)
{
	/* Please notes: pptr may be a proxy, your call should not use it directly. */
	if (pptr == NULL)
		return 0;
	if (iid == IID_IMAGEVIEWER)
	{

		addRef();
		*pptr = BIND_PROXY(IImageviewer,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}

 

mmi_ret my_image_view_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 testevt = EVT_ID_GROUP_ENTER;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
            /* enter group ToDo1 */
            break;
        case EVT_ID_GROUP_ACTIVE:
            /* enter group ToDo2 */
            break;
        case EVT_ID_GROUP_FOCUSED:
            /* enter group ToDo3 */
            break;
        case EVT_ID_GROUP_GOBACK:
            /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_INACTIVE:
            /* gobackhistory ToDo2 */
            break;
        case EVT_ID_GROUP_EXIT:
            /* gobackhistory ToDo3 */
            break;
        case EVT_ID_GROUP_DEINIT:
            /* gobackhistory ToDo4 */
            break;
        case EVT_ID_IMGVIEW_CLOSE_GID:
            /* closegroup ToDo1 */
        {
            mmi_group_event_struct *cui_evt;

            cui_evt = (mmi_group_event_struct*) evt;
            cui_imgview_close(cui_evt->sender_id);
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

void CALLCC ImageviewerService::close()
{    
	//cui_imgview_close(0);
}


void CALLCC ImageviewerService::create()
{
	mmi_id temp_parent_gid;


	temp_parent_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, my_image_view_group_proc, NULL); 
	mmi_frm_group_enter(temp_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	if ((imgview_gid = cui_imgview_create(temp_parent_gid)) != GRP_ID_INVALID)
	{
		cui_imgview_set_app_id(imgview_gid, APP_IMAGEVIEWER);

	}
	else
	{
		mmi_frm_group_close(temp_parent_gid);
	}

}
void CALLCC ImageviewerService::run()
{
	if(this->imgview_gid != GRP_ID_INVALID)
	{
		cui_imgview_run(this->imgview_gid);
	}
}
void CALLCC ImageviewerService::setTitle(WCHAR* string)
{
	if(this->imgview_gid != GRP_ID_INVALID)
	{
		cui_imgview_set_title(imgview_gid, string, 0);
	}
}

void CALLCC ImageviewerService::setUIDirection(gs_imgview_ui_direction_enum direction)
{
	if(this->imgview_gid != GRP_ID_INVALID)
	{
		cui_imgview_set_ui_direction(imgview_gid, (cui_imgview_ui_direction_enum)  direction);
	}
}
void CALLCC ImageviewerService::setModeFileName(PS8 filename)
{
	if(this->imgview_gid != GRP_ID_INVALID)
	{
		cui_imgview_set_mode_filename(imgview_gid, filename);
	}
}
#endif

