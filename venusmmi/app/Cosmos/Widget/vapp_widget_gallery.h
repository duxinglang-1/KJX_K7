/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_gallery.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the gallery widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_GALLERY_H
#define VAPP_WIDGET_GALLERY_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_GALLERY__)


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"

#include "vapp_widget_gallery_viewer.h"
#include "vapp_widget_gallery_control_bar.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_WIDGET_GALLERY_SIZE_WIDTH          386
#define VAPP_WIDGET_GALLERY_SIZE_HEIGHT         286
#define VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_X   45
#define VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_Y   21
#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_WIDGET_GALLERY_SIZE_WIDTH          246
#define VAPP_WIDGET_GALLERY_SIZE_HEIGHT         204
#define VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_X   17
#define VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_Y   16
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#define VAPP_WIDGET_GALLERY_SIZE_WIDTH          194
#define VAPP_WIDGET_GALLERY_SIZE_HEIGHT         144
#define VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_X   11
#define VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_Y   11
#else
#define VAPP_WIDGET_GALLERY_SIZE_WIDTH          246
#define VAPP_WIDGET_GALLERY_SIZE_HEIGHT         204
#define VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_X   12
#define VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_Y   11
#endif

#define VAPP_WIDGET_GALLERY_AUTO_HIDE_CONTROL_BAR_MSEC  8000


/*****************************************************************************
 * Gallery Widget
 *****************************************************************************/
class VappWidgetGallery : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetGallery);

public:
    enum
    {
        WIDTH = VAPP_WIDGET_GALLERY_SIZE_WIDTH,
        HEIGHT = VAPP_WIDGET_GALLERY_SIZE_HEIGHT
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetGallery();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();

    virtual void onSerializeView(VfxArchive *ar);

    virtual void onRestoreView(VfxArchive *ar);

    virtual void onEnterEditMode();

    virtual void onExitEditMode();

    virtual VfxPoint onGetEditButtonOffset();

    virtual void onTap(const VfxPoint &pos);

    virtual void onDrag(VfxPenEvent &event);

    virtual void onMove(VfxPenEvent &event);

    virtual void onDrop(VfxPenEvent &event);

    virtual void onAbort(VfxPenEvent &event);

    virtual void onFocus();

    virtual void onDefocus();

// Method
public:
    VappWidgetGalleryViewer* getGalleryViewer();
    void restartHideControlBarTimer();
    static mmi_ret eventHandler(mmi_event_struct *event);

private:
    void onHideControlBarTimeout(VfxTimer* pTimer);
    void onUSBEnterMS();
    void onUSBExitMS();
    void onMemoryCardPlugInOut(mmi_event_struct *event);
    void onStorageChanged(mmi_event_struct *event);
    void refreshGalleryWidget();
    VfxWString getSelectedFolderPath();
    VfxS32 isSameFolder(const CHAR *string1, const CHAR *string2);

// Variable
private:
    VfxBool             m_resetFlag;    
    VfxWString  m_checkFolderPath;
    VfxTimer            *m_timerHideControlBar;

    VappWidgetGalleryViewer *m_galleryViewer;

    VappWidgetGalleryControlBar *m_controlBar;
};
#endif
#endif /* VAPP_WIDGET_GALLERY_H */
