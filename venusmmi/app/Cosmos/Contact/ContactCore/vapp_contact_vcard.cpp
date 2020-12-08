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
 *  vapp_contact_vcard.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VCARD__

#include "vapp_contact_entry.h"
#include "vapp_contact_vcard.h"
#include "vapp_contact_op.h"
#include "mmi_rp_vapp_contact_def.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "PhbSrvGprot.h"
#include "FileMgrSrvGprot.h"
#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------*/
/* VappContactvCard                                               */
/*----------------------------------------------------------------*/
VappContactvCard::VappContactvCard()
{
}


VappContactvCard::VappContactvCard(mmi_phb_contact_id id)
    : m_contact(NULL),
      m_id(id),
      m_path(NULL)
{}


VappContactvCard::VappContactvCard(Contact *contact)
    : m_contact(contact),
      m_path(NULL)
{
    m_id = contact->getId();
}


void VappContactvCard::onDeinit()
{
    if (m_path)
    {
        VFX_FREE_MEM(m_path);
    }

    VfxObject::onDeinit();
}


VfxS32 VappContactvCard::buildFileName()
{
    clearTempvCardFile();

    if (NULL == m_path) // memory leak
    {
        VFX_ALLOC_MEM(m_path, sizeof(VfxWChar) * (SRV_FMGR_PATH_MAX_LEN + 1), this);
    }
    
    kal_wsprintf(m_path, "%c:\\%s", VCARD_DRV, VCARD_FOLDER_NAME);

    FS_HANDLE fh = FS_CreateDir(m_path);
    if (fh != FS_NO_ERROR && fh != FS_FILE_EXISTS)
    {
        return (VfxS32)fh;
    }

    VfxWChar *name;
    VfxWChar temp_name[MMI_PHB_NAME_LENGTH+ 1];

    if (m_contact)
    {
        srv_phb_convert_to_name(
            temp_name,
            (U16*)(m_contact->getName().getGivenBuf()),
            (U16*)(m_contact->getName().getFamilyBuf()),
            MMI_PHB_NAME_LENGTH);
    }
    else
    {
        ContactEntry entry(m_id);
        srv_phb_convert_to_name(
            temp_name,
            (U16*)(entry.getName().getGivenBuf()),
            (U16*)(entry.getName().getFamilyBuf()),
            MMI_PHB_NAME_LENGTH);
    }

    name = (VfxWChar*)srv_fmgr_path_skip_leading_space(temp_name);

    //unnamed
    if (mmi_wcslen(name) == 0)
    {
        mmi_wcscpy(temp_name, VFX_WSTR_RES(VAPP_PHB_STR_UNNAMED).getBuf());
    }

    kal_wsprintf(
        m_path,
        "%c:\\%s\\%w%s",
        VCARD_DRV,
        VCARD_FOLDER_NAME,
        name,
        VCARD_FILE_EXT);

    fh = FS_Open(m_path, FS_READ_ONLY);
    FS_Close(fh);
    if (fh == FS_INVALID_FILENAME)
    {
        kal_wsprintf(
            m_path,
            "%c:\\%s\\~vcard%s",
            VCARD_DRV,
            VCARD_FOLDER_NAME,
            VCARD_FILE_EXT);
    }

    return FS_NO_ERROR;
}


VfxWChar* VappContactvCard::getFile(VfxS32 *result)
{
    // build file name
    *result = buildFileName();

    if (*result != FS_NO_ERROR && *result != FS_FILE_EXISTS)
    {
        return NULL;
    }

    // build vcard
    VB_HANDLE vb;
    vcard_object_struct *vcard;

    VFX_ALLOC_MEM(vcard, sizeof(vcard_object_struct), this);
    memset(vcard, 0, sizeof(vcard_object_struct));

    vb = vcard_open_builder(m_path, VCARD_OPEN_MODE_DEFAULT, result);
    if (!vb)
    {
        VFX_FREE_MEM(vcard);
        return NULL;
    }

    srv_phb_contact handle = NULL;

    if (m_contact)
    {
        buildVcard(vcard);
    }
    else
    {
        handle = srv_phb_read_contact(m_id, NULL, NULL);
        srv_phb_contact_to_vcard_object(handle, vcard);
    }

    *result = (VfxS32)vcard_build(vb, vcard);
    if (*result == VCARD_RESULT_FAIL)
    {
        *result = vcard_get_build_error(vb);
        vcard_close_builder(vb);

        VFX_FREE_MEM(vcard);
        return NULL;
    }

    if (!m_contact && handle)
    {
        srv_phb_free_contact(handle);
    }

    vcard_close_builder(vb);
    VFX_FREE_MEM(vcard);

    return m_path;
}


void VappContactvCard::clearTempvCardFile()
{
    WCHAR buffer[SRV_FMGR_PATH_MAX_LEN + 1], file_name[SRV_FMGR_PATH_MAX_LEN + 1], *path, *filter;
    FS_DOSDirEntry file_info;

    path = buffer;
    filter = buffer;

    kal_wsprintf(filter, VCARD_TEMP_FILE_FILTER, VCARD_DRV, VCARD_FOLDER_NAME);
    FS_HANDLE handle = FS_FindFirst(filter, 0, 0, &file_info, file_name, SRV_FMGR_PATH_MAX_LEN);

    if (handle < 0)
    {
        return;
    }
    else
    {
        do
        {
            kal_wsprintf(path, "%c:\\%s\\%w", VCARD_DRV, VCARD_FOLDER_NAME, file_name);
            FS_Delete(path);
        } while (FS_FindNext(handle, &file_info, file_name, SRV_FMGR_PATH_MAX_LEN) == FS_NO_ERROR);
    }
    FS_FindClose(handle);
}


void VappContactvCard::buildVcard(vcard_object_struct *vcard)
{
    if (m_contact)
    {
        if (m_contact->getType() == VAPP_CONTACT_TYPE_MYCARD)
        {
            vcard->n.given = m_contact->getName().getGivenBuf();
        #ifdef __MMI_PHB_LAST_NAME_FIELD__
            vcard->n.family = m_contact->getName().getFamilyBuf();
        #endif
            VfxU32 index = 0;
            VfxU32 count = m_contact->getNumberCount();
            while (count > 0)
            {
                VappContactNumber &num = m_contact->getNumber(index);
                vcard->tel[index].tel = num.getBuf();
                vcard_tel_type_enum type = VCARD_TEL_TYPE_TOTAL;
                switch (num.getSubType())
                {
                    case MMI_PHB_NUM_TYPE_NONE:
                    case MMI_PHB_NUM_TYPE_MOBILE:
                        type = VCARD_TEL_TYPE_CELL;
                        break;
                        
                    case MMI_PHB_NUM_TYPE_HOME:
                        type = VCARD_TEL_TYPE_HOME;
                        break;
                        
                    case MMI_PHB_NUM_TYPE_OFFICE:
                        type = VCARD_TEL_TYPE_WORK;
                        break;

                    case MMI_PHB_NUM_TYPE_FAX:
                        type = VCARD_TEL_TYPE_FAX;
                        break;
                }
                vcard->tel[index].type = type;
                vcard->tel[index++].is_preferred = (num.getPrimary()) ? MMI_TRUE : MMI_FALSE;
                count--;
            }

            index = 0;
            count = m_contact->getEmailCount();
            while (count > 0)
            {
                VappContactEmail &email = m_contact->getEmail(index);
                vcard->email[index].email = email.getBuf();
                switch (email.getSubType())
                {
                    case MMI_PHB_EMAIL_TYPE_NONE:
                        vcard->email[index].type = VCARD_EMAIL_TYPE_INTERNET;
                        break;

                    case MMI_PHB_EMAIL_TYPE_HOME:
                        vcard->email[index].type = VCARD_EMAIL_TYPE_HOME;
                        break;
                        
                    case MMI_PHB_EMAIL_TYPE_OFFICE:
                        vcard->email[index].type = VCARD_EMAIL_TYPE_WORK;
                        break;
                        
                    default:
                        vcard->email[index].type = VCARD_EMAIL_TYPE_TOTAL;
                        break;
                }
                vcard->email[index++].is_preferred = (email.getPrimary()) ? MMI_TRUE : MMI_FALSE;
                count--;
            }
        }
    }
}


//#ifdef __MMI_VCARD__
/*----------------------------------------------------------------*/
/* ContactVcardViewerData                                         */
/*----------------------------------------------------------------*/
ContactVcardViewerData::ContactVcardViewerData()
{
    m_countHandle = NULL;
    m_activeCount = 0;
}


ContactVcardViewerData::ContactVcardViewerData(VfxWString path)
{
    m_countHandle = NULL;
    setPath(path);
    m_activeCount = 0;
}

#ifdef __MMI_MULTI_VCARD__
void ContactVcardViewerData::vcard_parser_callback(
                kal_int32 error_code,
                kal_int32 object_count,
                kal_int32 *object_offset,
                void *user_data)
{
    ContactVcardViewerData *op = (ContactVcardViewerData *)user_data;
    op->m_totalCount = object_count;
    op->m_activeCount = 0;
    vcard_close_parser(op->m_countHandle);
    op->m_countHandle = NULL;
    op->m_signalPassDone.emit();
}
#endif

void ContactVcardViewerData::onInit()
{
    m_totalCount = 0xffffffff;

    VfxS32 error_code;
    m_handle = vcard_open_parser((kal_wchar *)m_path.getBuf(), VCARD_PROPERTY_ALL, (kal_int32 *)&error_code);
    VfxS32 result = vcard_parse(m_handle, &m_vcard);
    m_isSingleVcard = (result == VCARD_RESULT_MORE) ? VFX_FALSE : VFX_TRUE;

    if (!m_isSingleVcard)
    {
        m_countHandle = vcard_open_parser((kal_wchar *)m_path.getBuf(), VCARD_PROPERTY_NONE, (kal_int32 *)&error_code);
        if (m_countHandle)
        {
#ifdef __MMI_MULTI_VCARD__
            vcard_multi_parse_ex(m_countHandle, (kal_int32 *)m_offset, MMI_PHB_PHONE_ENTRIES, &ContactVcardViewerData::vcard_parser_callback, this);
#endif
        }
        else
        {
            m_totalCount = 0;
            m_signalPassDone.emit();
        }
    }
    else
    {
        m_totalCount = 1;
    }
}


void ContactVcardViewerData::onDeinit()
{
    if (m_countHandle)
    {
        vcard_close_parser(m_countHandle);
        m_countHandle = NULL;
    }
    vcard_close_parser(m_handle);
}


VfxWString &ContactVcardViewerData::getName()
{
    srv_phb_convert_to_name(
            m_name,
            m_vcard->n.given,
            m_vcard->n.family,
            MMI_PHB_NAME_LENGTH);
    srv_phb_remove_invalid_name(m_name);
    return m_valueReturn.loadFromMem(m_name);
}


VfxImageSrc &ContactVcardViewerData::getImage()
{
    m_imageScr.setPath(VFX_WSTR_MEM(m_vcard->photo.file_name));
    return m_imageScr;
}


VfxBool ContactVcardViewerData::checkNumberValid(VfxU16 index)
{
    if (m_vcard->tel[index].tel && m_vcard->tel[index].tel[0] != 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxWString &ContactVcardViewerData::getNumberLabel(VfxU16 index)
{
    switch(m_vcard->tel[index].type)
    {
        case VCARD_TEL_TYPE_CELL:
            return m_valueReturn.loadFromMem(VFX_WSTR_RES(VAPP_PHB_STR_MOBILE));
        case VCARD_TEL_TYPE_HOME:
            return m_valueReturn.loadFromMem(VFX_WSTR_RES(VAPP_PHB_STR_HOME));
        case VCARD_TEL_TYPE_WORK:
            return m_valueReturn.loadFromMem(VFX_WSTR_RES(VAPP_PHB_STR_WORK));
        case VCARD_TEL_TYPE_FAX:
            return m_valueReturn.loadFromMem(VFX_WSTR_RES(VAPP_PHB_STR_FAX));
        default:
            return m_valueReturn.loadFromMem(VFX_WSTR_RES(VAPP_PHB_STR_MOBILE));
    }
}


VfxWString &ContactVcardViewerData::getNumber(VfxU16 index)
{
    return m_valueReturn.loadFromMem(m_vcard->tel[index].tel);
}


VfxBool ContactVcardViewerData::checkEmailValid(VfxU16 index)
{
    if (m_vcard->email[index].email && m_vcard->email[index].email[0] != 0)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxWString &ContactVcardViewerData::getEmailLabel(VfxU16 index)
{
    switch(m_vcard->email[index].type)
    {
        case VCARD_EMAIL_TYPE_HOME:
            return m_valueReturn.loadFromMem(VFX_WSTR_RES(VAPP_PHB_STR_HOME));
        case VCARD_EMAIL_TYPE_WORK:
            return m_valueReturn.loadFromMem(VFX_WSTR_RES(VAPP_PHB_STR_WORK));
        default:
            return m_valueReturn.loadFromMem(VFX_WSTR_RES(VAPP_PHB_STR_EMAIL));
    }
}


VfxWString &ContactVcardViewerData::getEmail(VfxU16 index)
{
    return m_valueReturn.loadFromMem(m_vcard->email[index].email);
}


#ifdef __MMI_PHB_INFO_FIELD__
VfxBool ContactVcardViewerData::addressIsValid(VfxU32 index)
{
    if (m_vcard->adr[index].country[0] != 0 ||
        m_vcard->adr[index].extended[0] != 0 ||
        m_vcard->adr[index].locality[0] != 0 ||
        m_vcard->adr[index].postal_code[0] != 0 ||
        m_vcard->adr[index].post_office[0] != 0 ||
        m_vcard->adr[index].region[0] != 0 ||
        m_vcard->adr[index].street[0] != 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


VfxBool ContactVcardViewerData::checkAddressValid(VfxU16 index, VappVcardAddressFieldEnum sub_index)
{
    VfxBool result = VFX_FALSE;
    switch (sub_index)
    {
        case VAPP_VCARD_ADDRESS_POST_OFFICE:
            if (m_vcard->adr[index].post_office && m_vcard->adr[index].post_office[0] != 0)
            {
                result = VFX_TRUE;
            }
            break;
        case VAPP_VCARD_ADDRESS_EXTEND_ADDRESS:
            if (m_vcard->adr[index].extended && m_vcard->adr[index].extended[0] != 0)
            {
                result = VFX_TRUE;
            }
            break;
        case VAPP_VCARD_ADDRESS_STREET:
            if (m_vcard->adr[index].street && m_vcard->adr[index].street[0] != 0)
            {
                result = VFX_TRUE;
            }
            break;
        case VAPP_VCARD_ADDRESS_LOCALITY:
            if (m_vcard->adr[index].locality && m_vcard->adr[index].locality[0] != 0)
            {
                result = VFX_TRUE;
            }
            break;
        case VAPP_VCARD_ADDRESS_REGION:
            if (m_vcard->adr[index].region && m_vcard->adr[index].region[0] != 0)
            {
                result = VFX_TRUE;
            }
            break;
        case VAPP_VCARD_ADDRESS_POSTAL_CODE:
            if (m_vcard->adr[index].postal_code && m_vcard->adr[index].postal_code[0] != 0)
            {
                result = VFX_TRUE;
            }
            break;
        case VAPP_VCARD_ADDRESS_COUNTRY:
            if (m_vcard->adr[index].country && m_vcard->adr[index].country[0] != 0)
            {
                result = VFX_TRUE;
            }
            break;
    }

    return result;
}


VfxWString &ContactVcardViewerData::getAddressTitle(VfxU16 index, VappVcardAddressFieldEnum sub_index)
{
    switch (sub_index)
    {
        case VAPP_VCARD_ADDRESS_POST_OFFICE:
            m_valueReturn.loadFromRes(VAPP_PHB_STR_POBOX);
            break;
        case VAPP_VCARD_ADDRESS_EXTEND_ADDRESS:
            m_valueReturn.loadFromRes(VAPP_PHB_STR_EXTENSION);
            break;
        case VAPP_VCARD_ADDRESS_STREET:
            m_valueReturn.loadFromRes(VAPP_PHB_STR_STREET);
            break;
        case VAPP_VCARD_ADDRESS_LOCALITY:
            m_valueReturn.loadFromRes(VAPP_PHB_STR_CITY);
            break;
        case VAPP_VCARD_ADDRESS_REGION:
            m_valueReturn.loadFromRes(VAPP_PHB_STR_STATE);
            break;
        case VAPP_VCARD_ADDRESS_POSTAL_CODE:
            m_valueReturn.loadFromRes(VAPP_PHB_STR_POSTALCODE);
            break;
        case VAPP_VCARD_ADDRESS_COUNTRY:
            m_valueReturn.loadFromRes(VAPP_PHB_STR_COUNTRY);
            break;
    }

    return m_valueReturn;
}


VfxWString &ContactVcardViewerData::getAddress(VfxU16 index, VappVcardAddressFieldEnum sub_index)
{
    switch (sub_index)
    {
        case VAPP_VCARD_ADDRESS_POST_OFFICE:
            m_valueReturn.loadFromMem(m_vcard->adr[index].post_office);
            break;
        case VAPP_VCARD_ADDRESS_EXTEND_ADDRESS:
            m_valueReturn.loadFromMem(m_vcard->adr[index].extended);
            break;
        case VAPP_VCARD_ADDRESS_STREET:
            m_valueReturn.loadFromMem(m_vcard->adr[index].street);
            break;
        case VAPP_VCARD_ADDRESS_LOCALITY:
            m_valueReturn.loadFromMem(m_vcard->adr[index].locality);
            break;
        case VAPP_VCARD_ADDRESS_REGION:
            m_valueReturn.loadFromMem(m_vcard->adr[index].region);
            break;
        case VAPP_VCARD_ADDRESS_POSTAL_CODE:
            m_valueReturn.loadFromMem(m_vcard->adr[index].postal_code);
            break;
        case VAPP_VCARD_ADDRESS_COUNTRY:
            m_valueReturn.loadFromMem(m_vcard->adr[index].country);
            break;
    }

    return m_valueReturn;
}
#endif /* __MMI_PHB_INFO_FIELD__ */


VfxWString &ContactVcardViewerData::getBirthday()
{
    VfxDateTime data;
    data.setDate((VfxU32)m_vcard->bday.year, (VfxU32)m_vcard->bday.month, (VfxU32)m_vcard->bday.day);

    m_valueReturn = data.getDateTimeString(
        (VfxU32)(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY));

    return m_valueReturn;
}


#ifdef __MMI_PHB_INFO_FIELD__
VfxWString &ContactVcardViewerData::getTitle()
{
    return m_valueReturn.loadFromMem(m_vcard->title.title);
}
#endif /* __MMI_PHB_INFO_FIELD__ */


#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
VfxWString &ContactVcardViewerData::getCompany()
{
    return m_valueReturn.loadFromMem(m_vcard->org.name);
}
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */


#ifdef __MMI_PHB_INFO_FIELD__
VfxWString &ContactVcardViewerData::getNote()
{
    return m_valueReturn.loadFromMem(m_vcard->note.note);
}
#endif /* __MMI_PHB_INFO_FIELD__ */


VfxU16 ContactVcardViewerData::queryCount(VappVcardFieldEnum field)
{
    switch (field)
    {
        case VAPP_VCARD_NAME_FIELD:
            return getNameCount();
        case VAPP_VCARD_NUMBER_FIELD:
            return getNumberCount();
        case VAPP_VCARD_EMAIL_FIELD:
            return getEmailCount();
    #ifdef __MMI_PHB_INFO_FIELD__
        case VAPP_VCARD_ADDRESS_FIELD:
            return getAddressCount();
    #endif /* __MMI_PHB_INFO_FIELD__ */
        case VAPP_VCARD_BIRTHDAY_FIELD:
            return getBirthdayCount();
    #ifdef __MMI_PHB_INFO_FIELD__
        case VAPP_VCARD_TITLE_FIELD:
            return getTitleCount();
    #endif /* __MMI_PHB_INFO_FIELD__ */
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        case VAPP_VCARD_COMPANY_FIELD:
            return getCompanyCount();
    #endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
    #ifdef __MMI_PHB_INFO_FIELD__
        case VAPP_VCARD_NOTE_FIELD:
            return getNoteCount();
    #endif /* __MMI_PHB_INFO_FIELD__ */
    }

    return 0;
}


VfxU16 ContactVcardViewerData::getNameCount()
{
    if (m_vcard->n.family[0] == 0 && m_vcard->n.given[0] == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


VfxU16 ContactVcardViewerData::getNumberCount()
{
    VfxU16 result = 0;

    for (VfxU32 i = 0; i < VCARD_MAX_TEL_COUNT; i++)
    {
        if (m_vcard->tel[i].tel[0] != 0)
        {
            result++;
        }
    }

    return result;
}


VfxU16 ContactVcardViewerData::getEmailCount()
{
    VfxU16 result = 0;

    for (VfxU32 i = 0; i < VCARD_MAX_EMAIL_COUNT; i++)
    {
        if (m_vcard->email[i].email[0] != 0)
        {
            result++;
        }
    }

    return result;
}


#ifdef __MMI_PHB_INFO_FIELD__
VfxU16 ContactVcardViewerData::getAddressCount()
{
    VfxU16 result = 0;

    for (VfxU32 i = 0; i < VCARD_MAX_ADR_COUNT; i++)
    {
        if (addressIsValid(i))
        {
            result++;
        }
    }

    return result;
}
#endif /* __MMI_PHB_INFO_FIELD__ */


VfxU16 ContactVcardViewerData::getBirthdayCount()
{
    if (m_vcard->bday.year == 0 && m_vcard->bday.month == 0 && m_vcard->bday.day == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


#ifdef __MMI_PHB_INFO_FIELD__
VfxU16 ContactVcardViewerData::getTitleCount()
{
    if (m_vcard->title.title[0] == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */


#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
VfxU16 ContactVcardViewerData::getCompanyCount()
{
    if (m_vcard->org.name[0] == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */


#ifdef __MMI_PHB_INFO_FIELD__
VfxU16 ContactVcardViewerData::getNoteCount()
{
    if (m_vcard->note.note[0] == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */

#ifdef __MMI_MULTI_VCARD__
void ContactVcardViewerData::getFront()
{
    vcard_multi_preview(m_handle, &m_vcard, m_offset[--m_activeCount]);
}


void ContactVcardViewerData::getNext()
{
    vcard_multi_preview(m_handle, &m_vcard, m_offset[++m_activeCount]);
}
#endif

void ContactVcardViewerData::setPath(const VfxWString &path)
{
    m_path.loadFromMem(path.getBuf());
}

//#endif /* __MMI_MULTI_VCARD__ */

#endif /* __MMI_VCARD__ */

