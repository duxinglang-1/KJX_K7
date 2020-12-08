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
*  vapp_certman_base_ui.cpp
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
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__  

#include "vapp_certman_base_ui.h"
#include "mmi_rp_vapp_certman_def.h"
#include "GlobalResDef.h"
#include "vapp_certman_util.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif


VappCertmanDetailsPage::VappCertmanDetailsPage(VfxU32 job_id, VfxU32 cert_id) : cert_details(job_id, cert_id, this)
{
}


VappCertmanDetailsPage::VappCertmanDetailsPage(VfxU32 cert_id) : cert_details(cert_id, this)
{
}


void VappCertmanDetailsPage::onInit(void)
{
    VfxPage::onInit();

    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_DETAILS));
    this->setTopBar(titleBar);

    setuptoolbar();

    VFX_OBJ_CREATE(text, VcpTextView, this);

    VfxRect page_rect = getRect();
    VfxRect rect(0, 0, page_rect.size.width, page_rect.size.height);
    text->setRect(rect);

    text->setMargins(
        VAPP_CERTMAN_TEXT_LEFT_MARGIN_DEFAULT,
        VAPP_CERTMAN_TEXT_TOP_MARGIN_DEFAULT,
        VAPP_CERTMAN_TEXT_RIGHT_MARGIN_DEFAULT,
        VAPP_CERTMAN_TEXT_BOTTOM_MARGIN_DEFAULT
    );

    text->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    text->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    
    cert_details.cert_info[0] = '\0';
    cert_details.cert_info[1] = '\0';

    text->setText((VfxWChar*)cert_details.cert_info, VFX_TRUE);

    VFX_OBJ_CREATE(progress_popup, VcpActivityIndicator, getMainScr());
    progress_popup->setPos((page_rect.size.width)/2, (page_rect.size.height)/2);
    progress_popup->start();
}


void VappCertmanDetailsPage::drawpage(void)
{
    DrawLabel();
    DrawIssuer();
    DrawSubject();
    DrawValidFrom();
    DrawValidTo();
    DrawCertFormat();
    DrawAlgorithm();
    DrawSerial();
    DrawFingerPrint();
}


void VappCertmanDetailsPage::DrawLabel(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    if (display_cert->label && mmi_ucs2strlen((CHAR*) display_cert->label))
    {
        VfxWString label;
        text->addDetail(VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_LABEL), VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
        if (display_cert->dcs_label == CERTMAN_DCS_ASCII)
        {
            label.format("\n%s\n", display_cert->label);
        }
        else
        {
            /* because display_cert->label is not aligned to 2 byte memory */
            VfxWChar temp_label[CERTMAN_LABEL_SIZE];
            mmi_ucs2ncpy((CHAR*)temp_label, (const CHAR *)display_cert->label, CERTMAN_LABEL_LENGTH);
            temp_label[CERTMAN_LABEL_SIZE-1] = '\0';
            temp_label[CERTMAN_LABEL_SIZE-2] = '\0';
           
			label.format("\n");
			VfxWString temp;
			temp.loadFromMem((const VfxWChar*)temp_label);
			label += temp;
			//temp.clear();
			temp.format("\n");
			label += temp;
        }
        text->addDetail(label, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
        /* newline must be inserted with the string itself. Not as a separate detail.
           Otherwise textview spacing won't be correct */
        //text->addDetail(VFX_WSTR("\n"), VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
    }
}


void VappCertmanDetailsPage::DrawIssuer(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    text->addDetail(VfxWString(STR_ID_VAPP_CERTMAN_CERT_ISSUER), VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
    VfxWString issuer;
    if (display_cert->issuer.names[CERTMAN_NAMETYPE_COMMON_NAME])
    {
        VfxWString common_name;
        if (display_cert->issuer.dcs[CERTMAN_NAMETYPE_COMMON_NAME] == CERTMAN_DCS_ASCII)
        {
            common_name.format("\n%s", display_cert->issuer.names[CERTMAN_NAMETYPE_COMMON_NAME]);
        }
        else
        {
            
			common_name.format("\n");
			VfxWString temp;
			temp.loadFromMem((const VfxWChar *)display_cert->issuer.names[CERTMAN_NAMETYPE_COMMON_NAME]);
			common_name += temp;
        }
        issuer += common_name;
    }

    if (display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION])
    {
        VfxWString org_name;
        if (display_cert->issuer.dcs[CERTMAN_NAMETYPE_ORGANISATION] == CERTMAN_DCS_ASCII)
        {
            org_name.format("\n%s", display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION]);
        }
        else
        {
            
			org_name.format("\n");
			VfxWString temp;
			temp.loadFromMem((const VfxWChar *)display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION]);
			org_name += temp;
        }
        issuer += org_name;
    }

    if (display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION_UNIT])
    {
        VfxWString org_unit;
        if (display_cert->issuer.dcs[CERTMAN_NAMETYPE_ORGANISATION_UNIT] == CERTMAN_DCS_ASCII)
        {
            org_unit.format("\n%s", display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION_UNIT]);
        }
        else
        {
           // org_unit.format("\n%ls", display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION_UNIT]);
			org_unit.format("\n");
			VfxWString temp;
			temp.loadFromMem((const VfxWChar *)display_cert->issuer.names[CERTMAN_NAMETYPE_ORGANISATION_UNIT]);
			org_unit += temp ;

        }
        issuer += org_unit;
    }

    if (display_cert->issuer.names[CERTMAN_NAMETYPE_LOCALITY])
    {
        VfxWString locality;
        if (display_cert->issuer.dcs[CERTMAN_NAMETYPE_LOCALITY] == CERTMAN_DCS_ASCII)
        {
            locality.format("\n%s", display_cert->issuer.names[CERTMAN_NAMETYPE_LOCALITY]);
        }
        else
        {
            //locality.format("\n%ls", display_cert->issuer.names[CERTMAN_NAMETYPE_LOCALITY]);
			locality.format("\n");
			VfxWString temp;
			temp.loadFromMem((const VfxWChar *)display_cert->issuer.names[CERTMAN_NAMETYPE_LOCALITY]);
			locality += temp;
        }
        issuer += locality;
    }

    if (display_cert->issuer.names[CERTMAN_NAMETYPE_STATE])
    {
        VfxWString state;
        if (display_cert->issuer.dcs[CERTMAN_NAMETYPE_STATE] == CERTMAN_DCS_ASCII)
        {
            state.format("\n%s", display_cert->issuer.names[CERTMAN_NAMETYPE_STATE]);
        }
        else
        {
            //state.format("\n%ls", display_cert->issuer.names[CERTMAN_NAMETYPE_STATE]);
			state.format("\n");
			VfxWString temp;
			temp.loadFromMem((const VfxWChar *)display_cert->issuer.names[CERTMAN_NAMETYPE_STATE]);
			state += temp;
        }
        issuer += state;
    }

    if (display_cert->issuer.names[CERTMAN_NAMETYPE_COUNTRY])
    {
        VfxWString country;
        if (display_cert->issuer.dcs[CERTMAN_NAMETYPE_COUNTRY] == CERTMAN_DCS_ASCII)
        {
            country.format("\n%s", display_cert->issuer.names[CERTMAN_NAMETYPE_COUNTRY]);
        }
        else
        {
            //country.format("\n%ls", display_cert->issuer.names[CERTMAN_NAMETYPE_COUNTRY]);
			country.format("\n");
			VfxWString temp;
			temp.loadFromMem((const VfxWChar *)display_cert->issuer.names[CERTMAN_NAMETYPE_COUNTRY]);
			country += temp;
        }
    }
    issuer += VFX_WSTR("\n");
    text->addDetail(issuer, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
}


void VappCertmanDetailsPage::DrawSubject(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    text->addDetail(VfxWString(STR_GLOBAL_SUBJECT), VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
    VfxWString subject;
    if (display_cert->subject.names[CERTMAN_NAMETYPE_COMMON_NAME])
    {
        VfxWString common_name;
        if (display_cert->subject.dcs[CERTMAN_NAMETYPE_COMMON_NAME] == CERTMAN_DCS_ASCII)
        {
            common_name.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_COMMON_NAME]);
        }
        else
        {
            common_name.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_COMMON_NAME]);
        }
        subject += common_name;
    }

    if (display_cert->subject.names[CERTMAN_NAMETYPE_ORGANISATION])
    {
        VfxWString org_name;
        if (display_cert->subject.dcs[CERTMAN_NAMETYPE_ORGANISATION] == CERTMAN_DCS_ASCII)
        {
            org_name.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_ORGANISATION]);
        }
        else
        {
            org_name.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_ORGANISATION]);
        }
        subject += org_name;
    }

    if (display_cert->subject.names[CERTMAN_NAMETYPE_ORGANISATION_UNIT])
    {
        VfxWString org_unit;
        if (display_cert->subject.dcs[CERTMAN_NAMETYPE_ORGANISATION_UNIT] == CERTMAN_DCS_ASCII)
        {
            org_unit.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_ORGANISATION_UNIT]);
        }
        else
        {
            org_unit.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_ORGANISATION_UNIT]);
        }
        subject += org_unit;
    }

    if (display_cert->subject.names[CERTMAN_NAMETYPE_LOCALITY])
    {
        VfxWString locality;
        if (display_cert->subject.dcs[CERTMAN_NAMETYPE_LOCALITY] == CERTMAN_DCS_ASCII)
        {
            locality.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_LOCALITY]);
        }
        else
        {
            locality.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_LOCALITY]);
        }
        subject += locality;
    }

    if (display_cert->subject.names[CERTMAN_NAMETYPE_STATE])
    {
        VfxWString state;
        if (display_cert->subject.dcs[CERTMAN_NAMETYPE_STATE] == CERTMAN_DCS_ASCII)
        {
            state.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_STATE]);
        }
        else
        {
            state.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_STATE]);
        }
        subject += state;
    }

    if (display_cert->subject.names[CERTMAN_NAMETYPE_COUNTRY])
    {
        VfxWString country;
        if (display_cert->issuer.dcs[CERTMAN_NAMETYPE_COUNTRY] == CERTMAN_DCS_ASCII)
        {
            country.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_COUNTRY]);
        }
        else
        {
            country.format("\n%s", display_cert->subject.names[CERTMAN_NAMETYPE_COUNTRY]);
        }
        subject += country;
    }
    subject += VFX_WSTR("\n");
    text->addDetail(subject, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
}


void VappCertmanDetailsPage::DrawValidFrom(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    VfxWString title_valid_from = VfxWString(STR_ID_VAPP_CERTMAN_CERT_VALID_FROM);
    title_valid_from += VFX_WSTR("\n");
    text->addDetail(title_valid_from, VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
    VfxWString valid_from;
    VfxDateTime date_time;
    date_time.setDate(display_cert->valid_from.nYear, display_cert->valid_from.nMonth, display_cert->valid_from.nDay);
    valid_from = date_time.getDateTimeString(VFX_DATE_TIME_DATE_YEAR|VFX_DATE_TIME_DATE_MONTH|VFX_DATE_TIME_DATE_DAY);
    valid_from += VFX_WSTR("\n");
    text->addDetail(valid_from, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
}


void VappCertmanDetailsPage::DrawValidTo(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    VfxWString title_valid_to = VfxWString(STR_ID_VAPP_CERTMAN_CERT_VALID_UPTO);
    title_valid_to += VFX_WSTR("\n");
    text->addDetail(title_valid_to, VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
    VfxWString valid_upto;
    VfxDateTime date_time;
    date_time.setDate(display_cert->valid_until.nYear, display_cert->valid_until.nMonth, display_cert->valid_until.nDay);
    valid_upto = date_time.getDateTimeString(VFX_DATE_TIME_DATE_YEAR|VFX_DATE_TIME_DATE_MONTH|VFX_DATE_TIME_DATE_DAY);
    valid_upto += VFX_WSTR("\n");
    text->addDetail(valid_upto, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
}


void VappCertmanDetailsPage::DrawCertFormat(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    if (display_cert->cert_type == CERTMAN_CERTTYPE_X509)
    {
        VfxWString title_cert_type = VfxWString(STR_ID_VAPP_CERTMAN_CERT_TYPE);
        title_cert_type += VFX_WSTR("\n");
        text->addDetail(title_cert_type, VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
        VfxWString cert_type = VfxWString(STR_ID_VAPP_CERTMAN_CERTTYPE_X509);
        cert_type += VFX_WSTR("\n");
        text->addDetail(cert_type, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
    }
}

void VappCertmanDetailsPage::DrawAlgorithm(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    VfxWString title_algo = VfxWString(STR_ID_VAPP_CERTMAN_ALGORITHM);
    title_algo += VFX_WSTR("\n");
    text->addDetail(title_algo, VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
    VfxWChar* alg_ptr = VappCertmanUtilities::vapp_certman_get_alg_string(display_cert->sigalg);
    VfxWString alg_name = VFX_WSTR_STATIC(alg_ptr);
    alg_name += VFX_WSTR("\n");
    text->addDetail(alg_name, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
}


void VappCertmanDetailsPage::DrawSerial(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    VfxWString title_serial = VfxWString(STR_ID_VAPP_CERTMAN_CERT_SERIAL_NO);
    title_serial += VFX_WSTR("\n");
    text->addDetail(title_serial, VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
    VfxWString serial;
    for (VfxU32 counter =0; counter < display_cert->serial_size; counter++)
    {
        VfxWString temp;
        temp.format("%02x ", display_cert->serial[counter]);
        serial += temp;
    }
    serial += VFX_WSTR("\n");
    text->addDetail(serial, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
}


void VappCertmanDetailsPage::DrawFingerPrint(void)
{
    const certman_cert_display_struct * display_cert = cert_details.GetDisplayStruct();
    VfxWString title_finger_print = VfxWString(STR_ID_VAPP_CERTMAN_CERT_FINGER_PRINT);
    title_finger_print += VFX_WSTR("\n");
    text->addDetail(title_finger_print, VCP_TEXT_DETAIL_TITLE, VAPP_CERTMAN_MAX_DISP_BUFF);
    VfxWString fingerprint;
    for (VfxU32 counter =0; counter < CERTMAN_SHA1_SIZE; counter++)
    {
        VfxWString temp;
        temp.format("%02x ", display_cert->fngrprt_sha1[counter]);
        fingerprint += temp;
    }
    text->addDetail(fingerprint, VCP_TEXT_DETAIL_CONTENT, VAPP_CERTMAN_MAX_DISP_BUFF);
}


void VappCertmanDetailsPage::VappCertmanDataRspHndlr(void* msg)
{
    VFX_OBJ_CLOSE(progress_popup);

    certman_error_enum err = *(certman_error_enum*)msg;

    if (err == CERTMAN_ERR_NONE)
    {
        drawpage();
    }
    else
    {
        HandleDetailsPageError(err);
    }
}


void VappCertmanDetailsPage::HandleDetailsPageError(certman_error_enum err)
{

}


VappCertmanKeyUsagePage::VappCertmanKeyUsagePage(VfxU32 key_purpose_all, VfxU32 key_purpose) : list_data(key_purpose_all, key_purpose)
{
}

void VappCertmanKeyUsagePage::onInit(void)
{
    VfxPage::onInit(); // call base class

    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_KEY_USAGE));
    this->setTopBar(titleBar);

    VcpToolBar *bbar;
    VFX_OBJ_CREATE(bbar, VcpToolBar, this);
    setBottomBar(bbar);

    bbar->addItem(KEY_OK_BUTTON_ID, VfxWString(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    bbar->addItem(KEY_CANCEL_BUTTON_ID, VfxWString(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    VFX_OBJ_CREATE(listmenu, VcpListMenu, this);

    VfxRect page_rect = getRect();
    VfxRect rect(0, 0, page_rect.size.width, page_rect.size.height);
    listmenu->setRect(rect);

    listmenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION);
    listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    listmenu->setContentProvider(this);

    listmenu->m_signalItemTapped.connect(this, &VappCertmanKeyUsagePage::m_signalTapCertItem);

    listmenu->m_signalFocusChanged.connect(this, &VappCertmanKeyUsagePage::m_signalCertFocusChanged);

    bbar->m_signalButtonTap.connect(this, &VappCertmanKeyUsagePage::onToolBarClick);

    listmenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
}


VfxBool VappCertmanKeyUsagePage::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
{
    text = VfxWString(STR_GLOBAL_EMPTY);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}


void VappCertmanKeyUsagePage::m_signalTapCertItem(VcpListMenu *sender, VfxU32 index)
{
    list_data.list_of_state[index] = !(list_data.list_of_state[index]);
}


void VappCertmanKeyUsagePage::m_signalCertFocusChanged(VcpListMenu *sender, VfxU32 Currindex, VfxU32 Previndex)
{

}


void VappCertmanKeyUsagePage::VappCertmanDataRspHndlr(void* msg)
{

}


VfxU32 VappCertmanKeyUsagePage::getCount(void)const
{
    return list_data.get_key_usage_count();
}


VfxBool VappCertmanKeyUsagePage::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    ) 
{
    if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text.format("%d", index);
    }
    else
    {
        text = list_data.get_all_key_usage_list_item(index);
    }
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}


VfxBool VappCertmanKeyUsagePage::getItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image              // [OUT] the image resource
    )
{
    return VFX_FALSE;
}


VcpListMenuItemStateEnum VappCertmanKeyUsagePage::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const
{
    if (list_data.list_of_state[index] == VFX_TRUE)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

#endif /* __COSMOS_MMI_PACKAGE__   */
#endif /* __CERTMAN_SUPPORT__ */
