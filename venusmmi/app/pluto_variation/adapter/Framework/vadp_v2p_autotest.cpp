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
 *  vadp_v2p_autotest.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *    This file is used to provide C-style function for auto test
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_ENGINE__)
 
#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_frm_gprot.h"
#include "Conversions.h"

#include "mmi_msg_struct.h"
#include "FileMgrSrvGProt.h"
#include "AppMgrSrvGprot.h"
#include "gpiosrvgprot.h"
#include "TimerEvents.h"

#ifdef __cplusplus
}   /* extern "C" */
#endif

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_base_picker.h"
#include <ctype.h>
#ifdef __COSMOS_MMI__
#include "vapp_screen_lock_gprot.h"
#endif

#define _MIN(a,b) (a<b)? a:b

#define VST_MAX_TEXT_LEN	64	// max. string len in VfxTextFrame

#define VADP_AT_MAX_FILEPATH 	30
#define VADP_AT_FOLDER    		L":\\AutoTest\\"

#define VST_DUMP_FILE      		(VfxWChar *)L"AutoTest.log"
#define VST_DUMP_MAX_STRLEN		255

#define VADP_AT_APP_INFO_FILE	(VfxWChar *)L"AppInfo.log"

#define AT_DUMP_START() \
            VfxChar *_str_buf = NULL;   \
            VFX_SYS_ALLOC_MEM(_str_buf, VST_DUMP_MAX_STRLEN);   \
            VFX_ASSERT(_str_buf)

#define AT_DUMP_END()   \
    VFX_SYS_FREE_MEM(_str_buf)

#define AT_DUMP(_h, ...)    do { \
								VfxU32 len, write_size; \
								kal_sprintf(_str_buf, __VA_ARGS__); \
								len = strlen(_str_buf); \
								VFX_ASSERT(len < VST_DUMP_MAX_STRLEN); \
								FS_Write(_h, _str_buf, len, &write_size); \
							} while(0)


/***************************************************************************** 
 * Class VadpAutoTest
 *****************************************************************************/

class VadpAutoTest : VfxObject
{
//    VFX_DECLARE_CLASS(VadpAutoTest);
public:
	VadpAutoTest() {};
	virtual ~VadpAutoTest() {};

	static void queryAppInfo();

	static void dumpSceneTree(void);
	static void debugDumpFrame(FS_HANDLE handle, VfxFrame *frame, VfxU32 level);
	static void getDumpFilename(VfxWChar *file, VfxChar *str, VfxU32 len);
	static VfxBool createFile(VfxWChar *filename, FS_HANDLE *pHandle);
	static void sendRsp(VfxBool result, VfxWChar *file);
};

//VFX_IMPLEMENT_CLASS("VadpAutoTest", VfxAutoTest, VfxBase);


void VadpAutoTest::getDumpFilename(VfxWChar *file, VfxChar *str, VfxU32 len)
{
	VfxWChar *tmp = NULL;

	VFX_SYS_ALLOC_MEM(tmp, sizeof(VfxWChar)*len);
	memset(tmp, 0, sizeof(VfxWChar)*len);
	
    tmp[0] = SRV_FMGR_PUBLIC_DRV;
    mmi_ucs2cat((CHAR *)tmp, (CHAR *)VADP_AT_FOLDER);
	mmi_ucs2cat((CHAR *)tmp, (CHAR *)file);
	VFX_ASSERT((U32)mmi_ucs2strlen((const CHAR *)tmp) <= len);

	mmi_chset_convert(CHSET_UCS2, CHSET_UTF8, (char*)tmp, (char*)str, len);
	VFX_SYS_FREE_MEM(tmp);
}


VfxBool VadpAutoTest::createFile(VfxWChar *filename, FS_HANDLE *pHandle)
{
    WCHAR drv[2] = {0};
    WCHAR *folderpath = NULL;

	VFX_ASSERT(pHandle);
	
    VFX_SYS_ALLOC_MEM(folderpath, sizeof(WCHAR)*VADP_AT_MAX_FILEPATH);
    VFX_ASSERT(folderpath);
    memset(folderpath, 0, sizeof(WCHAR)*VADP_AT_MAX_FILEPATH);
    
    drv[0] = SRV_FMGR_PUBLIC_DRV;
    drv[1] = 0;
    mmi_ucs2cpy((CHAR *)folderpath, (CHAR *)drv);
    mmi_ucs2cat((CHAR *)folderpath, (CHAR *)VADP_AT_FOLDER);

	// create folder if not exists
	if ((*pHandle = FS_Open(folderpath, FS_OPEN_DIR | FS_READ_ONLY)) < 0)
	{
		if (FS_CreateDir(folderpath) < 0)
        {      
            VFX_SYS_FREE_MEM(folderpath);
			return VFX_FALSE;
	    }
	}

	FS_Close(*pHandle);

    mmi_ucs2cat((CHAR *)folderpath, (CHAR *)filename);
    *pHandle = FS_Open(folderpath, FS_READ_WRITE | FS_CREATE_ALWAYS);
    
    VFX_SYS_FREE_MEM(folderpath);
    
	if ((*pHandle) < 0)
		return VFX_FALSE;
    else
	    return VFX_TRUE;
}


void VadpAutoTest::sendRsp(VfxBool result, VfxWChar *file)
{
	// send back result
	mmi_inject_string_rsp_struct *rsp;
	
	rsp = (mmi_inject_string_rsp_struct*) OslConstructDataPtr(sizeof(mmi_inject_string_rsp_struct));

	if (result)
	{
		getDumpFilename(file, rsp->file, sizeof(rsp->file)/sizeof(kal_char));
	}
	else
	{
		memset(rsp->file, 0, sizeof(rsp->file));
	}

     mmi_frm_send_ilm(
            MOD_L4C,
            MSG_ID_MMI_INJECT_STRING_RSP,
            (oslParaType*) rsp,
            NULL);
}


void VadpAutoTest::dumpSceneTree()
{
	VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
	VfxFrame *rootFrame = renderer->getRootFrame();

	if (rootFrame == NULL)
	{
		// do nothing
		return;
	}

	FS_HANDLE handle;
	VfxBool result;

	result = createFile(VST_DUMP_FILE, &handle);
	if (result && (handle >= 0))
	{
		debugDumpFrame(handle, rootFrame, 0);
		FS_Close(handle);	
	}

	sendRsp(result, VST_DUMP_FILE);
}


void VadpAutoTest::debugDumpFrame(FS_HANDLE h, VfxFrame *frame, VfxU32 level)
{
    VFX_OBJ_ASSERT_VALID(frame);

    VfxFloat opacity = frame->forceGetOpacity();
    VfxBool   hidden  = frame->getHidden();

    // skip hidden frame
    if (hidden || (opacity == 0.0))
    	return;

    VfxClassInfo *  classInfo   = frame->getClassInfo();
    VfxPoint        pos         = frame->forceGetPos();         //frame->getPos();
    VfxRect         bounds      = frame->forceGetBounds();      //frame->getBounds();
    VfxFPoint       anchor      = frame->forceGetAnchor();      //frame->getAnchor();
    VfxTransform    transform   = frame->forceGetTransform();

    AT_DUMP_START();

    AT_DUMP(h, 
    	"[%d] %s\t(P)%d,%d\t(B)%d,%d,%d,%d\t(A)%1.1f,%1.1f", 
    	level,
    	classInfo->getClassName(),
    	pos.x,
    	pos.y,
    	bounds.origin.x,
    	bounds.origin.y,
    	bounds.size.width,
    	bounds.size.height,
    	anchor.x,
    	anchor.y);

    if (!transform.isIdentity())
    {
        if (transform.type == VRT_TRANSFORM_TYPE_AFFINE)
        {
            VfxAffineParameter *affine = &transform.data.affine;
            AT_DUMP(h, "\t(X)%1.2f,%1.2f,%1.2f,%1.2f,%1.2f", 
                    affine->sx, affine->sy, affine->rz, affine->tx, affine->ty);
        }
        else
        {
            VfxMatrix3x3 *mx = &transform.data.matrix3x3;
            AT_DUMP(h, "\t(X)%f,%f,%f,%f,%f,%f,%f,%f,%f",
                    mx->m[0], mx->m[1], mx->m[2], mx->m[3], mx->m[4],
                    mx->m[5], mx->m[6], mx->m[7], mx->m[8]);
        }
    }

    if (frame->isKindOf(VFX_OBJ_CLASS_INFO(VfxTextFrame)))
    {
    	VfxTextFrame *txtFrame = (VfxTextFrame *)frame;
    	VfxWString &wstr = (VfxWString &)txtFrame->getString();
    	if (wstr)
    	{
    		VfxChar *str = NULL;
            VFX_SYS_ALLOC_MEM(str, VST_MAX_TEXT_LEN + 1);
            VFX_ASSERT(str);
            
    		mmi_chset_convert(CHSET_UCS2,CHSET_UTF8,(char*)wstr.getBuf(),(char*)str,VST_MAX_TEXT_LEN);
    		AT_DUMP(h, "\t(T)%s", str);
            
            VFX_SYS_FREE_MEM(str);
    	}
    }
    else if (frame->isKindOf(VFX_OBJ_CLASS_INFO(VfxImageFrame)))
    {
    	VfxImageFrame *imgFrame = (VfxImageFrame *)frame;
    	AT_DUMP(h, "\t(I)%d", imgFrame->getResId());
    }
#ifdef __COSMOS_MMI__
    else if (frame->isKindOf(VFX_OBJ_CLASS_INFO(VcpBasePicker)))
    {
    	AT_DUMP(h, "\t(H)0x%x[%s]", frame->getObjHandle(), "VcpBasePicker");
    }
#endif
    /* VcpWheelMenu should be later than VcpBasePicker since VcpBasePicker is derived from VcpWheelMenu */
    else if (frame->isKindOf(VFX_OBJ_CLASS_INFO(VcpWheelMenu)))
    {
    	AT_DUMP(h, "\t(H)0x%x[%s]", frame->getObjHandle(), "VcpWheelMenu");
    }
    else if (frame->isKindOf(VFX_OBJ_CLASS_INFO(VcpScrollable)))
    {
    	AT_DUMP(h, "\t(H)0x%x[%s]", frame->getObjHandle(), "VcpScrollable");
    }
    else
    {
    	const VfxImageSrc &imgSrc = frame->getImgContent();
    	if (!imgSrc.isNull())
    	{
    		AT_DUMP(h, "\t(I)%d", imgSrc.getResId());
    	}
    	else if (level == 0)
    	{
    		AT_DUMP(h, "\t(R)%d", mmi_frm_get_screen_rotate());
    	}
    }

    AT_DUMP(h, "\t\n");

    AT_DUMP_END();

    VfxFrame *childFrame;
    for (childFrame = frame->getFirstChildFrame(); 
        childFrame != NULL; 
        childFrame = childFrame->getNextFrame())
    {
        debugDumpFrame(h, childFrame, level + 1);
    }
}


void VadpAutoTest::queryAppInfo()
{
	FS_HANDLE handle;
	VfxBool result;

	result = createFile(VADP_AT_APP_INFO_FILE, &handle);
	if (result && (handle >= 0))
	{
		U32 count = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
		U32 preCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
		U32 totalCount = count + preCount;
		mmi_app_package_name_struct * array = NULL;
		S32 i;
		U32 write_size, str_len;
		mmi_ret ret;
		
		VFX_SYS_ALLOC_MEM(array, sizeof(mmi_app_package_name_struct) * totalCount);
		memset(array, 0, sizeof(mmi_app_package_name_struct) * totalCount);

		ret = srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, array, sizeof(mmi_app_package_name_struct) * count);
		VFX_ASSERT(ret != MMI_RET_ERR);
		ret = srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, array + count, sizeof(mmi_app_package_name_struct) * preCount);
		VFX_ASSERT(ret != MMI_RET_ERR);

		for (i=0; i<(S32)totalCount; i++)
		{
			str_len = _MIN(strlen(array[i]), sizeof(mmi_app_package_name_struct));
			FS_Write(handle, &array[i], str_len, &write_size);
			FS_Write(handle, (void *)"\n", 1, &write_size);
		}

		VFX_SYS_FREE_MEM(array);
		FS_Close(handle);	
	}

	sendRsp(result, VADP_AT_APP_INFO_FILE);
}


extern "C" {

// 
void vadp_at_scene_tree_dump(U8 delay_in_100ms)
{
	if (delay_in_100ms)
		StartTimer(KEY_TIMER_ID0, delay_in_100ms * 100, (FuncPtr)&VadpAutoTest::dumpSceneTree);
	else
		VadpAutoTest::dumpSceneTree();
}


/***************************************************************************** 
 * Query App Info
 *****************************************************************************/

void vadp_at_query_app_info(U8 idx)
{
	VadpAutoTest::queryAppInfo();
	VFX_UNUSED(idx);
}


/***************************************************************************** 
 * App Launch
 *****************************************************************************/

void vadp_at_app_launch(U8 idx, U8 *app_name)
{
	srv_appmgr_launch((const mmi_app_package_char *)app_name);
	VFX_UNUSED(idx);
}

/***************************************************************************** 
 * VK Control
 *****************************************************************************/

void vadp_at_vk_control(U8 idx)
{
	VcpTextEditor* pEditor = VcpTextEditor::getCurrentActivateEditor();
	
	if (pEditor)
	{
		switch(idx)
		{
		case 0:
			pEditor->hideSoftInput();
			break;
			
		case 1:
			pEditor->showSoftInput();
			break;
			
		default:
			VFX_ASSERT(0);
		}
	}
}

/***************************************************************************** 
 * Backlight Control
 *****************************************************************************/

void vadp_at_bl_control(U8 idx)
{
	switch (idx)
	{
	case 1:
		srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
		break;
	}
}

/***************************************************************************** 
 * Screen Lock
 *****************************************************************************/

static mmi_ret scr_lock_evt_cb(mmi_event_struct *evt)
{
	return MMI_RET_ERR;
}

void vadp_at_scr_lock(U8 idx)
{
#ifdef __COSMOS_MMI__
	switch(idx)
	{
	// disable
	case 0:
		mmi_frm_cb_reg_event(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, scr_lock_evt_cb, NULL);
		break;

	// enable
	case 1:
		mmi_frm_cb_dereg_event(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, scr_lock_evt_cb, NULL);
		break;

	// exit
	case 2:
		if (vapp_screen_lock_is_locked())
		{
			srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
			vapp_screen_lock_close();
		}
		break;
		
	default:
		VFX_ASSERT(0);
	}
#endif /* __COSMOS_MMI__ */

}


/***************************************************************************** 
 * Execute Command
 *****************************************************************************/

#define VAR_ARG_NUM_MAX     (10)    // max. number support for variable arguments

#define SKIP_NON_INTERESTED(_str)   while ((*_str != '\0') && ((*_str == ' ') || (*_str == ',')))  \
                                    { _str++; }

typedef void (*var_func_type)(U8 **arg_list, S32 arg_num);

typedef struct {
    const CHAR *str;
    var_func_type func;
} str_cmd_mapping_struct;


static VfxObject *get_obj_from_hex_str(U8 *hex_str)
{
	VfxObjHandle objHandle;
    VfxObject *obj = NULL;

    objHandle   = (VfxObjHandle)strtoul((const CHAR *)hex_str, NULL, 16);
    obj         = VfxObject::handleToObject(objHandle);
    return obj;
}

#ifdef __COSMOS_MMI__
static void set_picker_cmd(U8 **arg_list, S32 arg_num)
{
	VcpBasePicker *picker = NULL;
	
	if (arg_num >= 3)
	{
		picker = (VcpBasePicker *)get_obj_from_hex_str(arg_list[0]);
		if (picker && picker->isKindOf(VFX_OBJ_CLASS_INFO(VcpBasePicker)))
		{
			VfxS32 field = strtol((const CHAR *)arg_list[1], NULL, 10);
			VfxS32 focus = strtol((const CHAR *)arg_list[2], NULL, 10);
			picker->setFieldFocus(field, focus);
		}
	}
}
#endif /* __COSMOS_MMI__ */

static void set_wheel_focus_cmd(U8 **arg_list, S32 arg_num)
{
    VcpWheelMenu *wheelMenu = NULL;

    if (arg_num >= 2)
    {
		wheelMenu = (VcpWheelMenu *)get_obj_from_hex_str(arg_list[0]);
        if (wheelMenu && wheelMenu->isKindOf(VFX_OBJ_CLASS_INFO(VcpWheelMenu)))
        {
            VfxS32 focus = strtol((const CHAR *)arg_list[1], NULL, 10);
            wheelMenu->setFocus(focus);
        }
    }
}


static void set_list_scroll_cmd(U8 **arg_list, S32 arg_num)
{
    VcpListMenu *menu = NULL;

    if (arg_num >= 2)
    {
		menu = (VcpListMenu *)get_obj_from_hex_str(arg_list[0]);
        if (menu && menu->isKindOf(VFX_OBJ_CLASS_INFO(VcpListMenu)))
        {
            VfxS32 focus = strtol((const CHAR *)arg_list[1], NULL, 10);
			menu->setVisibleMenuItem(focus);
        }
    }
}


static void scroll_cmd(U8 **arg_list, S32 arg_num)
{
    VcpScrollable *scroll = NULL;

    if (arg_num >= 2)
    {
		scroll = (VcpScrollable *)get_obj_from_hex_str(arg_list[0]);
        if (scroll && scroll->isKindOf(VFX_OBJ_CLASS_INFO(VcpScrollable)))
        {
            VfxU8 direction = (VfxU8)*arg_list[1];
            VfxRect bounds = scroll->getViewBounds();
            VfxPoint contentOri = scroll->getContentOrigin();
            VfxSize contentSize = scroll->getContentSize();
            VfxRect rect = bounds;
            
            if ((direction == 'u') || (direction == 'U'))
            {
                rect.origin.y -= bounds.size.height;
                
                /* should not smaller than content's origin */
                if (rect.origin.y < contentOri.y)
                    rect.origin.y = contentOri.y;
            }
            else if ((direction == 'd') || (direction == 'D'))
            {
                rect.origin.y += bounds.size.height;

                /* should not exceed content size */
                if (rect.origin.y >  contentSize.height - bounds.size.height)
                    rect.origin.y = contentSize.height - bounds.size.height;
            }

            /* only do scroll if necessary */
            if (rect.origin.y != bounds.origin.y)
                scroll->scrollRectToVisible(rect);
        }
    }
}


const str_cmd_mapping_struct g_str_cmd_table[] = {
#ifdef __COSMOS_MMI__
    {"SET_PICKER", set_picker_cmd},
#endif
    {"SET_WHEEL_FOCUS", set_wheel_focus_cmd},
    {"SCROLL", scroll_cmd},
    {"SET_LIST_SCROLL", set_list_scroll_cmd}
    };


void vadp_at_execute_cmd(U8 idx, U8 *str)
{
    S32 i;
    S32 arg_num = 0;
    U8 *cmd = str;
    S32 cmd_size = 0;
    U8 *arg_list[VAR_ARG_NUM_MAX] = {0};

    // get cmd string
    while ((*str != '\0') && (*str != ',')) str++;
    cmd_size = (U32)str - (U32)cmd;

    SKIP_NON_INTERESTED(str);

    // get arg list
    while (*str != '\0')
    {
        U8 *arg = str;
        S32 arg_size = 0;

        while ((*str != '\0') && (*str != ',')) str++;

        arg_size = (U32)str - (U32)arg;
        arg_list[arg_num] = (U8 *)mmi_malloc(arg_size + 1);
        memcpy(arg_list[arg_num], arg, arg_size);
        arg_list[arg_num][arg_size] = '\0';

        arg_num++;
        VFX_ASSERT(arg_num < VAR_ARG_NUM_MAX);

        SKIP_NON_INTERESTED(str);
    }

    // look-up for corresponding function
    for (i=0; i<sizeof(g_str_cmd_table)/sizeof(str_cmd_mapping_struct); i++)
    {
        if (strncmp(g_str_cmd_table[i].str, (const CHAR *)cmd, cmd_size) == 0)
        {
            if (g_str_cmd_table[i].func)
	            g_str_cmd_table[i].func(arg_list, arg_num);
            break;
        }
    }

    for (i=0; i<arg_num; i++)
        mmi_mfree(arg_list[i]);	
}

}	// extern "C"


#endif // __COSMOS_MMI__

