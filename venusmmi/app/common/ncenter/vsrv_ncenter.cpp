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
 *  vapp_ncenter.cpp
 *
 * Project:
 * --------
 *  COSMOS Notification Center
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vsrv_ncenter.h"

#ifdef __MMI_NCENTER_SUPPORT__


#include "vapp_platform_context.h"
#include "kal_trace.h"

extern "C"
{
#include "Unicodexdcl.h"    /* for mmi_ucs2ncpy */
#include "mmi_common_app_trc.h"
#include "MMI_trc.h"
#include "GeneralSettingSrvGprot.h" // for EVT_ID_SETTING_LANGUAGE_CHANGED
}


/***************************************************************************** 
 * define
 *****************************************************************************/

#define TRACE(a) VFX_TRACE (a)



static VfxU32 g_vfxNCenterMemPool[NOTI_MEM_POOL_KB * 1024 / sizeof(VfxU32)];


static vrt_bool vfx_nmanager_ngroup_equal(const void *value1, const void *value2)
{
    const VsrvNGroup* rv1 = *(const VsrvNGroup* *)value1;
    const VsrvNGroup* rv2 = *(const VsrvNGroup* *)value2;

    return rv1->getId() == rv2->getId() ? VFX_TRUE : VFX_FALSE;
}


/**********************************************************************
 * External Interfaces:
 **********************************************************************/
    

extern "C"
{
        

vsrv_ngroup_handle vsrv_ncenter_create_ngroup(vsrv_ngroup_type type, vsrv_ngroup_id gid)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    if (type == VSRV_NGROUP_TYPE_BASE)
    {
        VsrvNGroup *group = NULL;        
        VSRV_NGROUP_CREATE_EX(group, VsrvNGroup, (gid));        
        return group;       
    }
    else if (type == VSRV_NGROUP_TYPE_SINGLE_TITLE)
    {
        VsrvNGroupSingleTitle *group = NULL;        
        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (gid));        
        return group;               
    }
    return NULL;
#else
    return NULL;
#endif    
   

}


vsrv_notification_handle vsrv_ncenter_create_notification(vsrv_notification_type type, vsrv_ngroup_handle ghandle, vsrv_notification_id nid)
{
#ifdef __MMI_NCENTER_SUPPORT__     
    if (type == VSRV_NOTIFICATION_TYPE_BASE)
    {        
        VsrvNotification *noti = NULL;
        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotification, ((VsrvNGroup*) ghandle, nid));
        return noti;    
    }
    else if (type == VSRV_NOTIFICATION_TYPE_EVENT)
    {        
        VsrvNotificationEvent *noti = NULL;
        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*) ghandle, nid));
        return noti;        
    }
    else if (type == VSRV_NOTIFICATION_TYPE_ONGOING)
    {
        VsrvNotificationOngoing *noti = NULL;
        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationOngoing, ((VsrvNGroup*) ghandle, nid));
        return noti; 
    }
    return NULL;
#else
    return NULL;
#endif 
}


vsrv_ngroup_handle vsrv_ncenter_query_ngroup(vsrv_ngroup_id gid)
{
#ifdef __MMI_NCENTER_SUPPORT__ 
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    return nm ? nm->queryNGroup(gid) : NULL;
#else
    return NULL;
#endif     
}

vsrv_ngroup_entry vsrv_ncenter_get_ngroup_entry()
{       
#ifdef __MMI_NCENTER_SUPPORT__     
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    VfxList <VsrvNGroup*>::It it = nm->getNGroups();
    return it.getHandle();    
#else
    return NULL;
#endif         
}
vsrv_notification_entry vsrv_ncenter_get_notification_entry(vsrv_ngroup_handle ghandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    VsrvNGroup *ng = (VsrvNGroup*) ghandle;
    VfxList <VsrvNotification*>::It it = ng->getNotifications();
    return it.getHandle();    
#else
    return NULL;
#endif         
}
vsrv_ngroup_entry vsrv_ncenter_get_next_ngroup_entry(vsrv_ngroup_entry gentry)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    return vrt_list_entry_get_next(gentry);     
#else
    return NULL;
#endif         

}


vsrv_notification_entry vsrv_ncenter_get_next_notification_entry(vsrv_notification_entry nentry)
{
#ifdef __MMI_NCENTER_SUPPORT__    
   return vrt_list_entry_get_next(nentry); 
#else
    return NULL;
#endif

}

vsrv_ngroup_handle vsrv_ncenter_get_ngroup(vsrv_ngroup_entry gentry)
{        
#ifdef __MMI_NCENTER_SUPPORT__     
    vsrv_ngroup_handle ghandle = (vsrv_ngroup_handle)*(VsrvNGroup* *)vrt_list_entry_get_value(gentry);
    return ghandle;
#else
    return NULL;
#endif
}
vsrv_notification_handle vsrv_ncenter_get_notification(vsrv_notification_entry nentry)
{    
#ifdef __MMI_NCENTER_SUPPORT__     
    vsrv_notification_handle nhandle = (vsrv_notification_handle)*(VsrvNotification* *)vrt_list_entry_get_value(nentry);
    return nhandle;
#else
    return NULL;
#endif    
}

vsrv_notification_handle vsrv_ncenter_get_prev_notification(vsrv_notification_handle nhandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*)nhandle;
    return noti ? noti->getPrevious() : NULL;    
#else
    return NULL;
#endif    
}

vsrv_notification_handle vsrv_ncenter_get_next_notification(vsrv_notification_handle nhandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*)nhandle;
    return noti ? noti->getNext() : NULL;        
#else
    return NULL;
#endif    

}


vsrv_notification_handle vsrv_ncenter_query_notification(vsrv_ngroup_handle ghandle, vsrv_notification_id nid)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);        
    return nm->queryNotification((VsrvNGroup*) ghandle, nid);    
#else
    return NULL;
#endif    

}

BOOL vsrv_ncenter_close_ngroup(vsrv_ngroup_handle ghandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNGroup *ng = (VsrvNGroup*)ghandle;
    VSRV_NGROUP_CLOSE(ng);
    return VFX_TRUE;
#else
    return VFX_TRUE;
#endif    


}
BOOL vsrv_ncenter_close_notification(vsrv_notification_handle nhandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*)nhandle;
    VSRV_NOTIFICATION_CLOSE(noti);
    return VFX_TRUE;
#else
     return VFX_TRUE;
#endif    
}

vsrv_ngroup_id vsrv_ncenter_get_ngroup_id(vsrv_ngroup_handle ghandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNGroup *ng = (VsrvNGroup*) ghandle;
    return ng ? ng->getId() : VSRV_NGROUP_INVALID_ID;
#else
    return VSRV_NGROUP_INVALID_ID;
#endif        
}

vsrv_notification_id vsrv_ncenter_get_notification_id(vsrv_notification_handle nhandle)
{
#ifdef __MMI_NCENTER_SUPPORT__     
    VsrvNotification *n = (VsrvNotification*) nhandle;
    return n ? n->getId() : VSRV_NOTIFICATION_INVALID_ID;
#else
    return VSRV_NGROUP_INVALID_ID;
#endif            
}


BOOL vsrv_ncenter_set_ngroup_title_str(vsrv_ngroup_handle ghandle, WCHAR* text)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNGroup *ng = (VsrvNGroup*) ghandle;
    if (ng && ng->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
    {
//        VFX_ASSERT(vfx_sys_wcslen(text) < 100);
        VfxWString str;
        str.loadFromMem(text);
        VsrvNGroupSingleTitle *g = (VsrvNGroupSingleTitle*) ng;
        g->setTitle(str);
        return VFX_TRUE;        
    }

    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif     
}

BOOL vsrv_ncenter_set_ngroup_title_id(vsrv_ngroup_handle ghandle, S32 resId)
{
#ifdef __MMI_NCENTER_SUPPORT__     
    VsrvNGroup *ng = (VsrvNGroup*) ghandle;
    if (ng && ng->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
    {
        VfxWString str((VfxResId)resId);
        VsrvNGroupSingleTitle *g = (VsrvNGroupSingleTitle*) ng;
        g->setTitle(str);
        return VFX_TRUE;        
    }
    return VFX_FALSE;

#else
    return VFX_FALSE;
#endif     

}




BOOL vsrv_ncenter_get_ngroup_title(vsrv_ngroup_handle ghandle, WCHAR* text, U32 bufsize)
{
#ifdef __MMI_NCENTER_SUPPORT__     
    VsrvNGroup *ng = (VsrvNGroup*) ghandle;
    if (ng && ng->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
    {
        VfxWString str;       
        str = ((VsrvNGroupSingleTitle*) ng)->getTitle();               
        mmi_ucs2ncpy((CHAR*)text, (const CHAR*)str.getBuf(), bufsize);
        return VFX_TRUE;        
    }
    return VFX_FALSE;    

#else
    return VFX_FALSE;
#endif  

}


BOOL vsrv_ncenter_set_notification_icon(vsrv_notification_handle nhandle, mmi_image_src_struct icon)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
        VfxImageSrc img;
        if (icon.type == MMI_IMAGE_SRC_TYPE_RES_ID)
        {
            img.setResId(icon.data.res_id);
        }
        else if(icon.type == MMI_IMAGE_SRC_TYPE_PATH)
        {
            VfxWString str;
            str.loadFromMem(icon.data.path);
            img.setPath(str);
        }
        else if(icon.type == MMI_IMAGE_SRC_TYPE_MEM)
        {           
            img.setMem(icon.data.mem);
        }
        else if(icon.type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY)
        {
            img = VfxImageSrc(icon.data.image.image_ptr, icon.data.image.image_len);            
        }
        

        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            ((VsrvNotificationEvent*) noti)->setIcon(img);
        }
        else
        {
            ((VsrvNotificationOngoing*) noti)->setIcon(img);            
        }
        return VFX_TRUE;        
    }

    return VFX_FALSE;   

#else
    return VFX_FALSE;
#endif    
}

BOOL vsrv_ncenter_get_notification_icon(vsrv_notification_handle nhandle, mmi_image_src_struct *icon)
{
#ifdef __MMI_NCENTER_SUPPORT__     
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
        VfxImageSrc img;
        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            img = ((VsrvNotificationEvent*) noti)->getIcon();
        }
        else
        {
            img = ((VsrvNotificationOngoing*) noti)->getIcon();            
        }

        if (img.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
        {
            icon->type = MMI_IMAGE_SRC_TYPE_RES_ID;
            icon->data.res_id = img.getResId();
        }
        else if(img.getType() == VFX_IMAGE_SRC_TYPE_PATH)
        {
            icon->type = MMI_IMAGE_SRC_TYPE_PATH;
            VfxWString str = img.getPath();                       
            mmi_ucs2ncpy((CHAR*)icon->data.path, (const CHAR*)str.getBuf(), MMI_MAX_FILE_NAME_LEN+1);
        }
        else if(img.getType() == VFX_IMAGE_SRC_TYPE_MEM)
        {
            icon->type = MMI_IMAGE_SRC_TYPE_MEM;
            icon->data.mem = (U8*) img.getMem();            
        }
        return VFX_TRUE;        
    }

    return VFX_FALSE;   

#else
    return VFX_FALSE;
#endif    
}


BOOL vsrv_ncenter_set_notification_maintext_str(vsrv_notification_handle nhandle, WCHAR* text)
{
#ifdef __MMI_NCENTER_SUPPORT__     
    VsrvNotification *noti = (VsrvNotification*) nhandle;           
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
//        VFX_ASSERT(vfx_sys_wcslen(text) < 100); 
        VfxWString str;
        str.loadFromMem(text);
        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            ((VsrvNotificationEvent*) noti)->setMainText(str);
        }
        else
        {
            ((VsrvNotificationOngoing*) noti)->setMainText(str);         
        }
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif      
}

BOOL vsrv_ncenter_set_notification_maintext_id(vsrv_notification_handle nhandle, S32 resId)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;           
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
        VfxWString str((VfxResId)resId);
        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            ((VsrvNotificationEvent*) noti)->setMainText(str);
        }
        else
        {
            ((VsrvNotificationOngoing*) noti)->setMainText(str);         
        }
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif    

}


BOOL vsrv_ncenter_get_notification_maintext(vsrv_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
        VfxWString str;

        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            str = ((VsrvNotificationEvent*) noti)->getMainText();
        }
        else
        {
            str = ((VsrvNotificationOngoing*) noti)->getMainText();         
        }
        mmi_ucs2ncpy((CHAR*)text, (const CHAR*)str.getBuf(), bufsize);
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif        
}


BOOL vsrv_ncenter_set_notification_subtext_str(vsrv_notification_handle nhandle, WCHAR* text)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;     
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
//        VFX_ASSERT(vfx_sys_wcslen(text) < 100);  
        VfxWString str;
        str.loadFromMem(text);
        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            ((VsrvNotificationEvent*) noti)->setSubText(str);
        }
        else
        {
            ((VsrvNotificationOngoing*) noti)->setSubText(str);         
        }
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif        
}

BOOL vsrv_ncenter_set_notification_subtext_id(vsrv_notification_handle nhandle, S32 resId)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;     
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
//        VFX_ASSERT(vfx_sys_wcslen(text) < 100);  
        VfxWString str((VfxResId)resId);
        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            ((VsrvNotificationEvent*) noti)->setSubText(str);
        }
        else
        {
            ((VsrvNotificationOngoing*) noti)->setSubText(str);         
        }
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif        
}


BOOL vsrv_ncenter_get_notification_subtext(vsrv_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT || noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
//        VFX_ASSERT(vfx_sys_wcslen(text) < 100);  
        VfxWString str;

        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            str = ((VsrvNotificationEvent*) noti)->getSubText();
        }
        else
        {
            str = ((VsrvNotificationOngoing*) noti)->getSubText();         
        }
        mmi_ucs2ncpy((CHAR*)text, (const CHAR*)str.getBuf(), bufsize);
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif        
}

BOOL vsrv_ncenter_set_notification_questiontext_str(vsrv_notification_handle nhandle, WCHAR* text)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
//        VFX_ASSERT(vfx_sys_wcslen(text) < 100);  
        VfxWString str;
        str.loadFromMem(text);
        ((VsrvNotificationOngoing*) noti)->setQuestionText(str);         
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif        
}

BOOL vsrv_ncenter_set_notification_questiontext_id(vsrv_notification_handle nhandle, S32 resId)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
//        VFX_ASSERT(vfx_sys_wcslen(text) < 100);  
        VfxWString str((VfxResId)resId);
        ((VsrvNotificationOngoing*) noti)->setQuestionText(str);         
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif        
}


BOOL vsrv_ncenter_get_notification_questiontext(vsrv_notification_handle nhandle, WCHAR* text, U32 bufsize)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti && (noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
        VfxWString str;        
        str = ((VsrvNotificationOngoing*) noti)->getSubText();                 
        mmi_ucs2ncpy((CHAR*)text, (const CHAR*)str.getBuf(), bufsize);
        return VFX_TRUE;        
    }
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif        
}
BOOL vsrv_ncenter_set_notification_timestamp(vsrv_notification_handle nhandle, applib_time_struct* timestamp)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    VfxDateTime date;
    if (noti && date.setDateTime(timestamp))
    {        
        noti->setTimeStamp(date);
        return VFX_TRUE;      
    }
    return VFX_FALSE; 
#else
    return VFX_FALSE;
#endif        
}

BOOL vsrv_ncenter_get_notification_timestamp(vsrv_notification_handle nhandle, applib_time_struct *timestamp)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti)
    {
        *timestamp = noti->getTimeStamp().getDateTime();
        return VFX_TRUE;              
    }    
    return VFX_FALSE;
#else
    return VFX_FALSE;
#endif        
}
BOOL vsrv_ncenter_set_notification_intent_callback(vsrv_notification_handle nhandle, vsrv_nitent_funcptr callback, void *userdata, U32 userdata_size)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti)
    {
        noti->setIntentCallback((VsrvNitentFuncptr)callback, userdata, (VfxU32)userdata_size);
        return VFX_TRUE;                  
    }
    return VFX_FALSE;    
#else
    return VFX_FALSE;
#endif        
}

void* vsrv_ncenter_get_notification_userdata(vsrv_notification_handle nhandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    return noti ? noti->getUserData() : NULL;
#else
    return NULL
#endif        
}
U32 vsrv_ncenter_get_notification_userdata_size(vsrv_notification_handle nhandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    return noti ? noti->getUserDataSize() : 0;
#else
    return 0;
#endif        
}

BOOL vsrv_ncenter_notify_notification(vsrv_notification_handle nhandle)
{   
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti)
    {
        noti->notify();
        return VFX_TRUE;
    }
    return VFX_FALSE;    
#else
    return VFX_FALSE;
#endif        
}

BOOL vsrv_ncenter_send_intent(vsrv_nviewer_type viewer, vsrv_nintent_type type, vsrv_notification_handle nhandle)    
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);     
    nm->sendIntent(viewer, type, (VsrvNotification*) nhandle);
    return VFX_TRUE;    
#else
    return VFX_FALSE;
#endif        
}


BOOL vsrv_ncenter_set_notification_autoclose(vsrv_notification_handle nhandle, BOOL auto_close, vsrv_notification_flag flag)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti)
    {
        noti->setAutoClose((VfxBool)auto_close, flag);
        return VFX_TRUE;
    }
    return VFX_FALSE;    
#else
    return VFX_FALSE;
#endif        
    
}

BOOL vsrv_ncenter_get_notification_autoclose(vsrv_notification_handle nhandle, vsrv_notification_flag flag)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti)
    {
        return noti->getAutoClose(flag);
    }
    return VFX_FALSE; 
#else
    return VFX_FALSE;
#endif        
}

BOOL vsrv_ncenter_set_notification_autolaunch(vsrv_notification_handle nhandle, BOOL auto_launch)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti)
    {        
        noti->setAutoLaunch((VfxBool)auto_launch);
        return VFX_TRUE;
    }
    return VFX_FALSE; 
#else
    return VFX_FALSE;
#endif        
}

BOOL vsrv_ncenter_get_notification_autolaunch(vsrv_notification_handle nhandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti)
    {
        return noti->getAutoLaunch();
    }
    return VFX_FALSE; 
#else
    return VFX_FALSE;
#endif        
}

BOOL vsrv_ncenter_get_notification_is_stable(vsrv_notification_handle nhandle)
{
#ifdef __MMI_NCENTER_SUPPORT__    
    VsrvNotification *noti = (VsrvNotification*) nhandle;
    if (noti)
    {        
        return noti->getIsStable();
    }
    return VFX_FALSE; 
#else
    return VFX_FALSE;
#endif        
}



#ifdef __cplusplus
    }   /* extern "C" */
#endif 




/***************************************************************************** 
* Class VappNCenter 
*****************************************************************************/

VFX_IMPLEMENT_CLASS("VsrvNCenter", VsrvNCenter, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VsrvNCenter);
 
VsrvNCenter::VsrvNCenter() :   
    m_context(NULL)
{
}

static mmi_ret vsrvNCenterEventHandler(mmi_event_struct *event)
{
    switch(event->evt_id)
    {
        case EVT_ID_SETTING_LANGUAGE_CHANGED:
            vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VSRV_NCENTER, VSRV_NINTENT_TYPE_LANGUAGE_CHANGED, NULL);
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}
 
void VsrvNCenter::onInit()
{
    VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    m_context->assignPool((VfxU8 *)g_vfxNCenterMemPool, NOTI_MEM_POOL_KB * 1024);

    VfxObject::onInit();   

    m_groups.init(this); 


    mmi_frm_cb_reg_event(EVT_ID_SETTING_LANGUAGE_CHANGED, vsrvNCenterEventHandler, NULL);
}

vrt_allocator_handle VsrvNCenter::getAllocator()
{
    return m_context->getAllocator();
}


void VsrvNCenter::sendIntent(VsrvNViewerType viewer, VsrvNIntentType type, VsrvNotification* noti, void* intentData)
{
    MMI_TRACE(TRACE_GROUP_10, TRC_VSRV_NCENTER_SEND_INTENT_NOTI, viewer, type, noti);

    
    VsrvNIntent intent;
    intent.viewer = viewer;
    intent.type = type;
    intent.intentData = intentData;
    
    if (noti)
    {
        if (checkNotification(noti))
        {
            noti->processIntent(intent);        
        }
    }
    else
    {
        VfxList <VsrvNGroup*>::It it;       
        for (it = m_groups.begin(); !it.isNull() ; ++it)
        {
            VsrvNGroup *group = *it;

            VfxList <VsrvNotification*>::It itt;        
            for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
            {
                VsrvNotification *n = *itt;
                n->processIntent(intent);
            }
        }
    }
    
}

void VsrvNCenter::sendIntent(VsrvNViewerType viewer, VsrvNIntentType type, VsrvNotificationType ntype, void* intentData)
{
    MMI_TRACE(TRACE_GROUP_10, TRC_VSRV_NCENTER_SEND_INTENT_NTYPE, viewer, type, ntype);

                
    VsrvNIntent intent;
    intent.viewer = viewer;
    intent.type = type;
    intent.intentData = intentData;

    VfxList <VsrvNGroup*>::It it;       
    for (it = m_groups.begin(); !it.isNull() ; ++it)
    {
        VsrvNGroup *group = *it;

        VfxList <VsrvNotification*>::It itt;        
        for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
        {
            VsrvNotification *n = *itt;
            if (n->getType() == ntype)
	        {
	            n->processIntent(intent); 
	        } 
        }
    }
}


VfxBool VsrvNCenter::_checkMemory(VfxS32 size)
{
    vfx_sys_mem_pool_status_struct current;
    m_context->statistics(current);

    VfxS32 targetSize = 3 * 1024;
    VfxS32 currentSize = current.total_size - current.used_size;

    if (currentSize < targetSize)
    {               
        while (currentSize < targetSize)
        {
            VsrvNotification *oldnoti = NULL;        
            VfxList <VsrvNGroup*>::It it;
            for (it = m_groups.begin(); !it.isNull(); ++it)  
            {                 
                VsrvNGroup* group = *it;        
                VfxList <VsrvNotification*>::It itt;        
                for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
                {                
                    VsrvNotification *noti = *itt;            

                    if (oldnoti == NULL)
                    {
                        oldnoti = noti;
                        continue;
                    }

                    VfxDateTime::CompareEnum result = oldnoti->getTimeStamp().compareWith(noti->getTimeStamp());
                    if (result != VfxDateTime::LESS)
                    {
                        oldnoti = noti;
                    } 
                }
            }     

            if (oldnoti)
            {
                MMI_TRACE(TRACE_GROUP_10, TRC_VSRV_NCENTER_OOM, oldnoti, oldnoti->getGroupId(), oldnoti->getId(), oldnoti->getType());            
                VSRV_NOTIFICATION_CLOSE(oldnoti);                
            }
            else
            {
                it = m_groups.rbegin();
                if (!it.isNull())
                {
                    VsrvNGroup* group = *it; 
                    VSRV_NGROUP_CLOSE(group);
                }   
                else
                {
                    VFX_DEV_ASSERT(0);
                    return VFX_FALSE;
                }                
            }
            
            m_context->statistics(current);
            currentSize = current.total_size - current.used_size;

        }               
    }

    return VFX_TRUE;
}



void VsrvNCenter::_initNotification(VsrvNotification* noti)
{       
    VFX_ASSERT(noti);

    VsrvNGroup* group = noti->getGroup();

    if (group)
    {
        //group->addNotification(noti);
        //m_signalNStatus.emit(noti, VSRV_NSTATUS_CREATE);
    }
    else
    {       
        VsrvNGroup* g = queryNGroup(noti->getGroupId());
        if (g == NULL)
        {
            VSRV_NGROUP_CREATE_EX(g, VsrvNGroup, (noti->getGroupId()));
        }
        if (g)
        {
            noti->setGroup(g);
            //m_signalNStatus.emit(noti, VSRV_NSTATUS_CREATE);
        }        

        MMI_TRACE(TRACE_GROUP_10, TRC_VSRV_NCENTER_INIT_NOTI, noti, noti->getGroupId(), noti->getId(), noti->getType());
    }    
}


VfxBool VsrvNCenter::checkNotification(VsrvNotification *noti)
{   
    VfxBool found = VFX_FALSE;
    
    VfxList <VsrvNGroup*>::It it;    
    for (it = m_groups.begin(); !it.isNull() ; ++it)
    {
        VsrvNGroup *group = *it;      
        VfxList <VsrvNotification*>::It itt;            
        for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
        {
            VsrvNotification *n = *itt;
            if(n == noti)
            {
                found = VFX_TRUE;
                break;
            }
        }  
    }

    if (found)
    {
        found = !noti->m_isOnDeinit;
    }
    
    return found;
    
}
    
void VsrvNCenter::_deinitNotification(VsrvNotification* noti)
{
    if (noti && checkNotification(noti))
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VSRV_NCENTER_DEINIT_NOTI, noti, noti->getGroupId(), noti->getId(), noti->getType());

        
        noti->m_isOnDeinit = VFX_TRUE;
        
        VsrvNIntent intent;
        intent.viewer = VSRV_NVIEWER_TYPE_VSRV_NCENTER;
        intent.type = VSRV_NINTENT_TYPE_CLOSE;
        noti->processIntent(intent); 
        m_signalNStatus.emit(noti, VSRV_NSTATUS_CLOSE); 


        VsrvNGroup* group = noti->getGroup();

        noti->_deinit();
        
        if (group)
        {
            group->removeNotification(noti);
            if (group->getCount() == 0)
            {
                VSRV_NGROUP_CLOSE(group);
            }
        }

        
    }    
}


VsrvNotification* VsrvNCenter::queryNotification(VsrvNGroup* group, VsrvNotificationId id)
{       
    VfxList <VsrvNGroup*>::It pos = m_groups.find(group);
    VFX_ASSERT(!pos.isNull() && !group->m_isOnDeinit);       
    return group->queryNotification(id);          
    
}

VsrvNotification* VsrvNCenter::queryNotification(VsrvNGroupId gid, VsrvNotificationId nid)
{
    VsrvNGroup* ngroup = queryNGroup(gid);

    if (ngroup)
    {
        return queryNotification(ngroup, nid);
    }
    return NULL;   
}





void VsrvNCenter::_initNGroup(VsrvNGroup* ngroup)
{       
    VFX_ASSERT(ngroup);


    if (ngroup->getParentGroup())
    {
        //add group tree
    }
    else
    {        
        VfxList <VsrvNGroup*>::It it;
        for (it = m_groups.begin(); !it.isNull(); ++it)
        {
            VsrvNGroup *g = *it;
            VfxDateTime::CompareEnum result = ngroup->getTimeStamp().compareWith(g->getTimeStamp());
            if (result != VfxDateTime::LESS)
            {
                break;             
            } 
        }                
        if (it.isNull())
        {
            m_groups.pushBack(ngroup);
        }
        else
        {
            m_groups.insert(it, ngroup);        
        }

        MMI_TRACE(TRACE_GROUP_10, TRC_VSRV_NCENTER_INIT_NGROUP, ngroup, ngroup->getId(), ngroup->getType());    
        
    }
       
}

        
void VsrvNCenter::_deinitNGroup(VsrvNGroup* ngroup)
{
   
    VfxList <VsrvNGroup*>::It pos = m_groups.find(ngroup);
    
    if(!pos.isNull() && !ngroup->m_isOnDeinit)
    {       
        MMI_TRACE(TRACE_GROUP_10, TRC_VSRV_NCENTER_DEINIT_NGROUP, ngroup, ngroup->getId(), ngroup->getType());            
        
        ngroup->m_isOnDeinit = VFX_TRUE;        
        ngroup->_deinit();
        m_groups.erase(pos);
    }    
}


VsrvNGroup* VsrvNCenter::queryNGroup(VsrvNGroupId id)
{
    if (id != VSRV_NGROUP_INVALID_ID)
    {
        VsrvNGroup ngroup(id);    
        VfxList <VsrvNGroup*>::It pos = m_groups.find(&ngroup, vfx_nmanager_ngroup_equal);   

        if (!pos.isNull())
        {
            return *pos;
        }
    }
    
    
    return NULL;
}





void VsrvNCenter::debugDump()
{    
    

    VfxList <VsrvNGroup*>::It it;
    

    TRACE(("\n================================\n"));        
    TRACE(("==============Notis=============\n"));
    TRACE(("================================\n"));

    for (it = m_groups.begin(); !it.isNull() ; ++it)
    {
        VsrvNGroup *group = *it;

        TRACE(("group : %x, id: %d, type: %d, timeStamp: %ws\n", group, group->getId(), group->getType(),
               group->getTimeStamp().getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY | 
                   VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE | VFX_DATE_TIME_TIME_SECOND).getBuf()));
      
        VfxList <VsrvNotification*>::It itt;        

        for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
        {
            VsrvNotification *n = *itt;
             TRACE(("    noti: %x, id: %x, type: %d, timeStamp: %ws\n", n, n->getId(), n->getType(),
                   n->getTimeStamp().getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY | 
                   VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE | VFX_DATE_TIME_TIME_SECOND).getBuf()));
        }  
    }
}


VfxBool VsrvNCenter::broadcast(VsrvNotification* noti, VfxBool oldIsStable)
{            
    VFX_ASSERT(noti);

    if (noti->getFlag() & VSRV_NOTIFICATION_FLAG_STABLE && !oldIsStable)
    {
        VsrvNGroup* group = noti->getGroup();
        VfxList <VsrvNGroup*>::It it, pos;        
        for (it = m_groups.begin(); ; ++it)
        {
            VsrvNGroup *g = *it;
            VfxDateTime::CompareEnum result = group->getTimeStamp().compareWith(g->getTimeStamp());
            if (result != VfxDateTime::LESS) //!LESS means newer
            {
                pos = it;
            } 
            if (g == group)
            {
                break;
            }
        }
        
        if (it != pos)
        {            
            m_groups.erase(it);            
            m_groups.insert(pos, group);        
        }

        VsrvNStatusType type = VSRV_NSTATUS_END;
        if (noti->getFlag() & VSRV_NOTIFICATION_FLAG_OLD)
        {
            type = VSRV_NSTATUS_UPDATE;
        }
        else
        {
            noti->_setFlag(VSRV_NOTIFICATION_FLAG_OLD, VFX_TRUE);
            type = VSRV_NSTATUS_CREATE;
        }

        m_signalNStatus.emit(noti, type);

        MMI_TRACE(TRACE_GROUP_10, TRC_VSRV_NCENTER_BROADCAST, noti, noti->getGroupId(), noti->getId(), noti->getType(), type);
    }    
    
    return VFX_TRUE;
}


#endif /*__MMI_NCENTER_SUPPORT__*/
