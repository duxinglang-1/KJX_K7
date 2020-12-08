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
 *  vapp_gallery_util.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#include "vapp_gallery_util.h"


/*****************************************************************************
 * Utility functions
 *****************************************************************************/
int getBytePerPixel(vrt_color_type_enum cf)
{
    return vrt_bytes_of_pixel(cf);
}

gdi_color_format convertCF_VRT2GDI(vrt_color_type_enum cf)
{
    switch (cf)
    {
    case VRT_COLOR_TYPE_RGB565:
        return GDI_COLOR_FORMAT_16;
    case VRT_COLOR_TYPE_RGB888:
        return GDI_COLOR_FORMAT_24;
    case VRT_COLOR_TYPE_ARGB8888:
        return GDI_COLOR_FORMAT_32;
    case VRT_COLOR_TYPE_PARGB8888:
        return GDI_COLOR_FORMAT_32_PARGB;
    case VRT_COLOR_TYPE_UYVY422:
        return GDI_COLOR_FORMAT_UYVY422;
    case VRT_COLOR_TYPE_PARGB6666:
        return GDI_COLOR_FORMAT_PARGB6666;
    default:
        VFX_ASSERT(0);
    }
    return 0;
}

vrt_color_type_enum convertCF_GDI2VRT(gdi_color_format cf)
{
    switch (cf)
    {
        case GDI_COLOR_FORMAT_16:
            return VRT_COLOR_TYPE_RGB565;

        case GDI_COLOR_FORMAT_24:
            return VRT_COLOR_TYPE_RGB888;

        case GDI_COLOR_FORMAT_32:
            return VRT_COLOR_TYPE_ARGB8888;

        case GDI_COLOR_FORMAT_32_PARGB:
            return VRT_COLOR_TYPE_PARGB8888;

        case GDI_COLOR_FORMAT_UYVY422:
            return VRT_COLOR_TYPE_UYVY422;
        case GDI_COLOR_FORMAT_PARGB6666:
            return VRT_COLOR_TYPE_PARGB6666;
        default:
            VRT_ASSERT(0);
            break;
    }

    return VRT_COLOR_TYPE_UNKNOWN;
}

U64 msecToSec(U64 timeMsec)
{
    const VfxU64 seconds_offset = (500 < (timeMsec % 1000))? 1 : 0;
    const U64 timeSec = timeMsec / MSEC_PER_SEC + seconds_offset;
    return timeSec;
}

// format miliseconds into "HH:MM:SS" format.
// if hideHourIfZero is VFX_TRUE, then "MM:SS" is used when the time is less than 1 hour.
void formatTimeText(VfxWString &timeText, U64 timeMsec, VfxBool hideHourIfZero)
{
    const VfxU32 seconds = (VfxU32)(msecToSec(timeMsec));
    const VfxU32 minutes = seconds / 60;
    const VfxU32 hours = minutes / 60;
    const VfxU32 sec_part = seconds % 60;
    const VfxU32 min_part = minutes % 60;
    const VfxU32 hour_part = vfxMin((VfxU32)99, hours); // clamp at 99 hours
    if(hideHourIfZero && 0 == hours)
    {
        timeText.format("%02d:%02d", min_part, sec_part);
    }
    else
    {
        timeText.format("%d:%02d:%02d", hour_part, min_part, sec_part);
    }
}

void formatSizeText(VfxWString &sizeText, VfxU32 sizeInBytes)
{
	const VfxChar unitChar[] = {"BKMG"};
	VfxU8 i = 0;
	VfxU64 unit = 1;
	VfxU64 uTotal = 0;

	while (sizeInBytes >= 1024 * unit && i < 4)
    {
        unit *= 1024;
        i++;
    }

	uTotal = (VfxU64)(((VfxFloat)sizeInBytes/unit)*100);
	sizeText = VfxWString().format("%d",(uTotal/100));
	sizeText += VfxWString().format("%c",unitChar[i]);
	if (i > 0)
	{
		sizeText += VFX_WSTR("B");
	}
}


VfxId convertItemIdFromMenuPos(const VcpMenuPos &pos)
{
    // convert VcpMenuPos (VfxS32, VfxS32) into VfxId (VfxU32) by keep 16-bit part of group and position.
    // this means we cannot support over 65535 groups and positions.
    VFX_ASSERT(pos.group < 0xFFFF);
    VFX_ASSERT(pos.pos < 0xFFFF);
    const VfxId itemId = ((pos.group & 0xFFFF) << 16) | (pos.pos & 0xFFFF);
    return itemId;
}

mmi_id findRootAppId(VfxObject *obj)
{
    mmi_id appId = NULL;
    VfxApp *pApp = NULL;
    VfxScreen *topScr = NULL;

    // object's parent-child relation may different in frame tree and object tree
    // our target is find root app, so we traverse frame tree first
    do
    {
        VfxFrame* pFrame = VFX_OBJ_DYNAMIC_CAST(obj, VfxFrame);
        if(NULL == pFrame)
        {
            break;
        }
        for(VfxFrame *f = pFrame; f != NULL; f = f->getParentFrame())
        {
            topScr = VFX_OBJ_DYNAMIC_CAST(f, VfxScreen);
            if(topScr)
            {
                break;
            }
        }
    }while(0);

    // than traverse object tree to get app instance
    VfxObject *pObj = (topScr) ? topScr : obj;
    for(; pObj != NULL; pObj = pObj->getParent())
    {
        pApp = VFX_OBJ_DYNAMIC_CAST(pObj, VfxApp);
        if(pApp != NULL)
        {
            appId = pApp->getGroupId();
            return appId;
        }
    }

    // root is not VfxApp, why?
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_UTIL_FIND_ROOT_APP_GROUP_ID_FAILED);
    return NULL;
}

VfxBool isAnyParentHidden(VfxFrame *frame)
{
    for(VfxFrame *parent = frame->getParentFrame(); parent != NULL; parent = parent->getParentFrame())
    {
        if(parent->getHidden())
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void hideFrameAnimated(VfxFrame *frame)
{
    if(NULL == frame)
    {
        return;
    }
    VfxAutoAnimate::begin();
    frame->setAutoAnimate(VFX_TRUE);
    frame->setIsUnhittable(VFX_TRUE);
    frame->setOpacity(0.0f);
    VfxAutoAnimate::commit();
    frame->setAutoAnimate(VFX_FALSE);
}

void showFrameImmediately(VfxFrame *frame)
{
    if(NULL == frame)
    {
        return;
    }
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    frame->setIsUnhittable(VFX_FALSE);
    frame->setOpacity(1.0f);
    VfxAutoAnimate::commit();
}

void intersectFmgrFilter(FMGR_FILTER &dst, const FMGR_FILTER &src)
{
    for(VfxS32 i = 0; i < sizeof(dst.mask) / sizeof(dst.mask[0]); ++i)
    {
        dst.mask[i] &= src.mask[i];
    }
    return;
}

void copyFmgrFilter(FMGR_FILTER *pdst, const FMGR_FILTER &src)
{
    if(pdst)
    {
        kal_mem_cpy(pdst, &src, sizeof((pdst->mask)));
    }
    return;
}

VfxBool is3DRedBlueImage(const WCHAR* path, U16 gdiImgFileTypeHint)
{
    // we have to parse EXIF to check if 3D red blue image, 
    // so this utilty is supported while both __3D_IMAGE_SUPPORT__ and EXIF_SUPPORT enable
#if defined(__3D_IMAGE_SUPPORT__) && defined(EXIF_SUPPORT)
    // pre check
    do
    {
        U16 fileType = gdiImgFileTypeHint;

        if(NULL == path)
        {
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][Util] is3DRedBlueImage[%d], err[%d][%d]", gdiImgFileTypeHint, -100, -999);               
            return VFX_FALSE; 
        }
        // check file type, 3D red blue must be JPEG file type
        if(GDI_IMAGE_TYPE_INVALID == fileType)
        {
            fileType = gdi_image_get_type_from_file((CHAR*)path);
        }
        if(GDI_IMAGE_TYPE_JPG != fileType && GDI_IMAGE_TYPE_JPG_FILE != fileType)
        {
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][Util] is3DRedBlueImage[%d], err[%d][%d]", gdiImgFileTypeHint, -200, fileType);
            return VFX_FALSE; 
        }
    }while(0);

    // query desciption
    kal_char desc[10];
    gdi_image_jpeg_get_desc_from_file(path, desc);
    const S32 result = strcmp(desc, "3D"); 
    const VfxBool isRBImg = ((0 == result) ? VFX_TRUE : VFX_FALSE);
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][Util] is3DRedBlueImage[%d], isRBImg[%d]", gdiImgFileTypeHint, isRBImg);
    return isRBImg;
#endif
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][Util] is3DRedBlueImage[%d], err[%d][%d]", gdiImgFileTypeHint, -300, -999); 
    return VFX_FALSE; 
}
