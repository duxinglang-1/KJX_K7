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
*  vapp_certman_base_ui.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
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
 * removed!
 *
 * removed!
 * removed!
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
*
 * removed!
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef __VAPP_CERTMAN_BASE_UI_H__
#define __VAPP_CERTMAN_BASE_UI_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "vapp_certman_data.h"


/* WVGA */
#ifdef __MMI_MAINLCD_480X800__

#define VAPP_CERTMAN_TEXT_RIGHT_MARGIN_DEFAULT 14
#define VAPP_CERTMAN_TEXT_LEFT_MARGIN_DEFAULT 14
#define VAPP_CERTMAN_TEXT_TOP_MARGIN_DEFAULT 14
#define VAPP_CERTMAN_TEXT_BOTTOM_MARGIN_DEFAULT 14

#endif /* __MMI_MAINLCD_480X800__ */

/* HVGA */
#ifdef __MMI_MAINLCD_320X480__

#define VAPP_CERTMAN_TEXT_RIGHT_MARGIN_DEFAULT 8
#define VAPP_CERTMAN_TEXT_LEFT_MARGIN_DEFAULT 8
#define VAPP_CERTMAN_TEXT_TOP_MARGIN_DEFAULT 8
#define VAPP_CERTMAN_TEXT_BOTTOM_MARGIN_DEFAULT 8

#endif /* __MMI_MAINLCD_320X480__ */

/* QVGA or WQVGA */
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

#define VAPP_CERTMAN_TEXT_RIGHT_MARGIN_DEFAULT 5
#define VAPP_CERTMAN_TEXT_LEFT_MARGIN_DEFAULT 5
#define VAPP_CERTMAN_TEXT_TOP_MARGIN_DEFAULT 5
#define VAPP_CERTMAN_TEXT_BOTTOM_MARGIN_DEFAULT 5

#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) */

/* Details page base class */
class VappCertmanDetailsPage : public VfxPage, public VappCertmanDataUser
{
    void drawpage(void);
    VcpActivityIndicator *progress_popup;
public:
    VappCertmanDetailsPage(VfxU32 job_id, VfxU32 cert_id);
    VappCertmanDetailsPage(VfxU32 cert_id);
    void VappCertmanDataRspHndlr(void* msg);
    void onInit(void);
protected:
    VappCertmanCertDetailsData cert_details;
    VcpTextView *text;
    VcpToolBar *toolbar;
    virtual void setuptoolbar(void){}
    virtual void DrawLabel();
    virtual void DrawIssuer();
    virtual void DrawSubject();
    virtual void DrawValidFrom();
    virtual void DrawValidTo();
    virtual void DrawCertFormat();
    virtual void DrawAlgorithm();
    virtual void DrawSerial();
    virtual void DrawFingerPrint();

    virtual void HandleDetailsPageError(certman_error_enum err);
};


/* key usage page */
class VappCertmanKeyUsagePage : public VfxPage, public IVcpListMenuContentProvider, public VappCertmanDataUser
{
    void setMenu(VcpListMenu *)
    {
    }

    VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        )
    {
        // move to .cpp if required
    }

    VfxU32 getCount() const;

    // Get the state of a list item
    VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        )
    {
        return VFX_FALSE;
    }

    VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        )
    {
        return NULL;
    }

    void closeItemCustomContentFrame(
        VfxU32 index,  // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
        )
    {
        // move to .cpp if required
    }

    VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

    VcpListMenu *listmenu;

    void m_signalTapCertItem(VcpListMenu *sender, VfxU32 index);
    void m_signalCertFocusChanged(VcpListMenu *sender, VfxU32 Currindex, VfxU32 Previndex);

public:
    virtual void onToolBarClick(VfxObject* sender, VfxId id) = 0;
    void VappCertmanDataRspHndlr(void* msg);
    void onInit(void);
    VappCertmanKeyUsagePage(VfxU32 key_purpose_all, VfxU32 key_purpose);
    typedef enum
    {
        KEY_OK_BUTTON_ID,
        KEY_CANCEL_BUTTON_ID
    }vapp_key_usage_page_button_enum;

protected:
    VappCertmanKeyUsageListData list_data;
};

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_BASE_UI_H__ */
