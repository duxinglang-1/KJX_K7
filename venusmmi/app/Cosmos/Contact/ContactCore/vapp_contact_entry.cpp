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
 *  vapp_phb_entry.cpp
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
 * removed!
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

#include "vapp_contact_entry.h"
#include "mmi_rp_vapp_contact_def.h"
#include "vapp_phb_gprot.h"

VfxWString getNumLabelByType(mmi_phb_num_type_enum type)
{
    VfxWString label;

    switch (type)
    {
    case MMI_PHB_NUM_TYPE_NONE:
    case MMI_PHB_NUM_TYPE_MOBILE:
        label.loadFromRes(VAPP_PHB_STR_MOBILE);
        break;

    case MMI_PHB_NUM_TYPE_HOME:
        label.loadFromRes(VAPP_PHB_STR_HOME);
        break;

    case MMI_PHB_NUM_TYPE_OFFICE:
        label.loadFromRes(VAPP_PHB_STR_WORK);
        break;

    case MMI_PHB_NUM_TYPE_FAX:

        label.loadFromRes(VAPP_PHB_STR_FAX);
        break;

    default:
        label.loadFromMem(srv_phb_get_field_type_label(type, MMI_PHB_CONTACT_FIELD_ID_NUMBER, PHB_STORAGE_NVRAM));
        break;
    }

    return label;
}


VfxWString getEmailLabelByType(mmi_phb_email_type_enum type)
{
    VfxWString label;

    switch (type)
    {
    case MMI_PHB_EMAIL_TYPE_NONE:
        label.loadFromRes(VAPP_PHB_STR_EMAIL);
        break;

    case MMI_PHB_EMAIL_TYPE_HOME:
        label.loadFromRes(VAPP_PHB_STR_HOME);
        break;

    case MMI_PHB_EMAIL_TYPE_OFFICE:
        label.loadFromRes(VAPP_PHB_STR_WORK);
        break;

    default:
        label.loadFromMem(srv_phb_get_field_type_label(type, MMI_PHB_CONTACT_FIELD_ID_EMAIL, PHB_STORAGE_NVRAM));
        break;
    }

    return label;
}


/***************************************************************************** 
 * Class Contact
 *****************************************************************************/
Contact::Contact():
    m_type(VAPP_CONTACT_TYPE_PHONE),
    m_id(MMI_PHB_INVALID_CONTACT_ID),
    m_storage(PHB_STORAGE_NVRAM),
    m_groupId(MMI_PHB_INVALID_GROUP_ID)
{
}


Contact::Contact(vapp_contact_type_enum type):
    m_type(type),
    m_id(MMI_PHB_INVALID_CONTACT_ID),
    m_groupId(MMI_PHB_INVALID_GROUP_ID)
{
    switch (type)
    {
        case VAPP_CONTACT_TYPE_DEFAULT:  // will deside by contact id or storage type
        case VAPP_CONTACT_TYPE_PHONE:    // phone contact
            m_storage = PHB_STORAGE_NVRAM;
            break;

        case VAPP_CONTACT_TYPE_SIM:      // SIM contact
        case VAPP_CONTACT_TYPE_USIM:     // USIM contact
            m_storage = PHB_STORAGE_SIM;
            break;

        case VAPP_CONTACT_TYPE_CARD:     // card
#ifdef __MMI_PHB_MYCARD__
        case VAPP_CONTACT_TYPE_MYCARD:   // mycard
#endif /* __MMI_PHB_MYCARD__ */
            m_storage = PHB_STORAGE_NVRAM;
            break;
    }
}


Contact::Contact(mmi_phb_contact_id id):
    m_id(id)
{
    VFX_ASSERT(srv_phb_check_entry_exist(id));
    
    m_storage = ContactStorage::getStorage(id);
    m_groupId = MMI_PHB_INVALID_GROUP_ID;
    m_type = VAPP_CONTACT_TYPE_DEFAULT;
}


void Contact::onInit()
{
    VfxObject::onInit();

    VFX_OBJ_CREATE(m_number, ContactNumberStack, this);
    VFX_OBJ_CREATE(m_email, ContactEmailStack, this);

    m_ring.setType(MMI_PHB_CONTACT_FIELD_RING);
    m_image.setType(MMI_PHB_CONTACT_FIELD_IMAGE);

    read();
}


vapp_contact_type_enum Contact::getType()
{
    return m_type;
}


mmi_phb_contact_id Contact::getId() const
{
    return m_id;
}


VfxU32 Contact::getAbility()
{
    return srv_phb_get_support_field(m_storage);
}


void Contact::setStorage(phb_storage_enum storage)
{
    if (m_storage == PHB_STORAGE_NVRAM && storage != PHB_STORAGE_NVRAM)
    {
        VfxWChar name[MMI_PHB_NAME_LENGTH + 1];
        srv_phb_convert_to_name(name, (U16*)m_name.getGivenBuf(), (U16*)m_name.getFamilyBuf(), MMI_PHB_NAME_LENGTH);
        m_name.setFamily(NULL);
        m_name.setGiven(name);
        srv_phb_truncate_name(m_name.getGivenBuf(), storage);
    }

    m_storage = storage;
}


phb_storage_enum Contact::getStorage()
{
    return m_storage;
}


void Contact::setName(const VappContactName& name)
{
    m_name = name;
}


VappContactName& Contact::getName()
{
    return m_name;
}


#ifdef __MMI_PHB_USIM_SUPPORT__
void Contact::setNickname(const VappContactNickname &nickname)
{
    m_nickname = nickname;
}


VappContactNickname& Contact::getNickname()
{
    return m_nickname;
}
#endif /* __MMI_PHB_USIM_SUPPORT__ */


void Contact::resetNumber()
{
    m_number->reset();
}


VfxU32 Contact::getNumberCount()
{
    return m_number->getCount();
}


VfxU32 Contact::getNumberMaxCount()
{
    return srv_phb_get_support_field_count(m_storage, MMI_PHB_CONTACT_FIELD_ID_NUMBER);
}


void Contact::setNumber(const VappContactNumber& number, VfxU32 index)
{
    m_number->setValue(number, index);
}


VappContactNumber& Contact::getNumber(VfxU32 index)
{
    return m_number->getValue(index);
}


void Contact::removeNumber(VfxU32 index)
{
    m_number->clear(index);
}


void Contact::resetEmail()
{
    m_email->reset();
}


VfxU32 Contact::getEmailCount()
{
    return m_email->getCount();
}


VfxU32 Contact::getEmailMaxCount()
{
    return srv_phb_get_support_field_count(m_storage, MMI_PHB_CONTACT_FIELD_ID_EMAIL);
}


void Contact::setEmail(const VappContactEmail& email, VfxU32 index)
{
    m_email->setValue(email, index);
}


VappContactEmail& Contact::getEmail(VfxU32 index)
{
    return m_email->getValue(index);
}


void Contact::removeEmail(VfxU32 index)
{
    m_email->clear(index);
}


#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
void Contact::setCompany(const VappContactCompany &company)
{
    m_company = company;
}


VappContactCompany& Contact::getCompany()
{
    return m_company;
}
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */


#ifdef __MMI_PHB_INFO_FIELD__
void Contact::setTitle(const VappContactTitle &title)
{
    m_title = title;
}


VappContactTitle& Contact::getTitle()
{
    return m_title;
}


void Contact::setNote(const VappContactNote& note)
{
    m_note = note;
}


VappContactNote& Contact::getNote()
{
    return m_note;
}


void Contact::setAddress(const VappContactAddress& address)
{
    m_address = address;
}


VappContactAddress& Contact::getAddress()
{
    return m_address;
}
#endif /* __MMI_PHB_INFO_FIELD__ */


#ifdef __MMI_PHB_BIRTHDAY_FIELD__
VappContactBday& Contact::getBday()
{
    return m_bday;
}
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
void Contact::setBday(const VappContactBday& bday)
{
    m_bday = bday;
}
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */


void Contact::setRingTone(const VappContactRes& ring)
{
    m_ring = ring;
    m_ring.setType(MMI_PHB_CONTACT_FIELD_RING);
}


VappContactRes& Contact::getRingTone()
{
    return m_ring;
}


void Contact::setImage(const VappContactRes& img)
{
    m_image = img;
    m_image.setType(MMI_PHB_CONTACT_FIELD_IMAGE); // replace before FIELD_IMAGE with 0
}


VappContactRes& Contact::getImage()
{
    return m_image;
}

#ifdef __MMI_PHB_CALLER_GROUP__
void Contact::setGroupId(VfxU8 groupId)
{
    m_groupId = groupId;
}
#endif /* __MMI_PHB_CALLER_GROUP__ */

#ifdef __MMI_PHB_CALLER_GROUP__
VfxU32 Contact::getGroupId() const
{
    return m_groupId;
}

#endif /* __MMI_PHB_CALLER_GROUP__ */

#ifdef __MMI_PHB_CALLER_GROUP__
VfxWString Contact::getGroupName()
{
    srv_phb_group_info_struct groupInfo;
    if (m_groupId != MMI_PHB_INVALID_GROUP_ID && srv_phb_get_group_info(m_groupId, &groupInfo) == SRV_PHB_NO_ERROR)
    {
        return VFX_WSTR_MEM((VfxWChar*) groupInfo.group_name);
    }
    else
    {
        return VFX_WSTR_EMPTY;
    }
}
#endif /* __MMI_PHB_CALLER_GROUP__ */

VfxBool Contact::getLabelSupport()
{
    if (m_storage == PHB_STORAGE_NVRAM
        /* myler check */
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        || m_storage == PHB_STORAGE_TCARD
    #endif
        )
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void Contact::buildSrvContact(srv_phb_contact handle, VfxBool isNew)
{
    srv_phb_reset_contact(handle, MMI_PHB_CONTACT_FIELD_ALL);

    // set name
    srv_phb_contact_set_fname(handle, m_name.getGivenBuf());
    srv_phb_contact_set_lname(handle, m_name.getFamilyBuf());

#ifdef __MMI_PHB_USIM_SUPPORT__
    // set nickname
    srv_phb_contact_set_nick(handle, m_nickname.getBuf());
#endif

    // set number
    for (VfxU32 i = 0; i < m_number->getCount(); i++)
    {
        srv_phb_number_struct phb_number;
        VappContactNumber& number = m_number->getValue(i);

        if (isNew)
        {
            phb_number.sub_id = MMI_PHB_SUB_ID_NEW;
        }
        else
        {
            phb_number.sub_id = (mmi_phb_sub_id) number.getSubId();
        }
        phb_number.index = 0;
        phb_number.type = (U8) number.getSubType();

        mmi_sim_enum call, message;
        srv_phb_get_preferred_sim(number.getBuf(), MMI_PHB_INVALID_CONTACT_ID, SRV_PHB_NUMBER_OP_TYPE_DIAL, &call);
        srv_phb_get_preferred_sim(number.getBuf(), MMI_PHB_INVALID_CONTACT_ID, SRV_PHB_NUMBER_OP_TYPE_MESSAGE, &message);
        phb_number.last_used_sim = (U8) ((message << 4) + call);

        mmi_wcscpy(phb_number.number, number.getBuf());
        mmi_wcscpy(phb_number.label, number.getLabel().getBuf());
        phb_number.is_default = (number.getPrimary()) ? MMI_TRUE : MMI_FALSE;

        srv_phb_contact_add_number(handle, &phb_number);
    }

    // set email
    for (VfxU32 i = 0; i < m_email->getCount(); i++)
    {
        VappContactEmail& email = m_email->getValue(i);
        srv_phb_contact_add_email_ex(
            handle,
            (mmi_phb_sub_id) email.getSubId(),
            0,
            (U8) email.getSubType(),
            email.getBuf(),
            email.getLabel().getBuf());
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    // set company
    srv_phb_contact_set_company(handle, m_company.getBuf());
#endif

#ifdef __MMI_PHB_INFO_FIELD__
    // set title
    srv_phb_contact_set_title(handle, m_title.getBuf());

    // set note
    srv_phb_contact_add_note_ex(handle, 0, 0, m_note.getBuf());

    // set address
    {
        mmi_phb_address_struct *address = (mmi_phb_address_struct*) mmi_frm_temp_alloc(sizeof(mmi_phb_address_struct));

        m_address.getBuf(address);

        srv_phb_contact_add_address_ex(
            handle,
            0,
            0,
            address);

        mmi_frm_temp_free(address);
    }
#endif /* __MMI_PHB_INFO_FIELD__ */

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
  // set bday
    {
        srv_phb_bday_struct bday;
        bday.b_year = m_bday.getYear();
        bday.b_month = m_bday.getMonth();
        bday.b_day = m_bday.getDay();

        srv_phb_contact_set_bday(handle, &bday);
    }
#endif
    // set ring tone
    srv_phb_contact_set_ringtone_ex(handle, m_ring.getResId(), m_ring.getPath().getBuf());

    // set image
    srv_phb_contact_set_image_ex(handle, m_image.getResId(), m_image.getPath().getBuf());

    // set group
    srv_phb_contact_set_group_ex(handle, m_groupId);
}

#ifdef __MMI_PHB_MYCARD__
void Contact::buildMycard(mmi_phb_my_number_struct *myNumber)
{
    memset(myNumber, 0, sizeof(mmi_phb_my_number_struct));

    mmi_wcscpy(myNumber->name, m_name.getGivenBuf());
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    mmi_wcscpy(myNumber->l_name, m_name.getFamilyBuf());
#endif

    VfxU32 i = m_number->getCount();
    VfxU32 j = 0;

    if (j < i)
    {
        VappContactNumber& number = m_number->getValue(j++);

        mmi_wcscpy(myNumber->number, number.getBuf());
        myNumber->number_type = number.getSubType();
    }

    if (j < i)
    {
        VappContactNumber& number = m_number->getValue(j++);

        mmi_wcscpy(myNumber->homeNumber, number.getBuf());
        myNumber->homeNumber_type = number.getSubType();
    }

    if (j < i)
    {
        VappContactNumber& number = m_number->getValue(j++);

        mmi_wcscpy(myNumber->officeNumber, number.getBuf());
        myNumber->officeNumber_type = number.getSubType();
    }

    if (j < i)
    {
        VappContactNumber& number = m_number->getValue(j++);

        mmi_wcscpy(myNumber->faxNumber, number.getBuf());
        myNumber->faxNumber_type = number.getSubType();
    }

    i = m_email->getCount();
    j = 0;

    if (j < i)
    {
        VappContactEmail& email = m_email->getValue(j++);

        mmi_wcscpy(myNumber->emailAddress, email.getBuf());
        myNumber->emailAddress_type = email.getSubType();
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__    
    if (j < i)
    {
        VappContactEmail& email = m_email->getValue(j++);

        mmi_wcscpy(myNumber->emailAddress2, email.getBuf());
        myNumber->emailAddress2_type = email.getSubType();
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
}
#endif /* __MMI_PHB_MYCARD__ */

void Contact::read()
{
	#ifdef __MMI_PHB_MYCARD__
    if (m_type == VAPP_CONTACT_TYPE_MYCARD)
    {
        readMycard();
    }
    else
	#endif /* __MMI_PHB_MYCARD__ */
    {
        readContact();
    }
}


void Contact::readContact()
{
    if (m_id == MMI_PHB_INVALID_CONTACT_ID)
    {
        return;
    }

    srv_phb_contact handle = srv_phb_read_contact(m_id, NULL, NULL);
    srv_phb_group_struct *group = srv_phb_contact_get_group(handle);

    // one contact only can set to one group
    if (group)
    {
        VFX_ASSERT(group->group_count <= 1);
        if (group->group_count == 0)
        {
            m_groupId = MMI_PHB_INVALID_GROUP_ID;
        }
        else
        {
            m_groupId = group->group_id[0];
        }
    }
    else
    {
        m_groupId = MMI_PHB_INVALID_GROUP_ID;
    }

    VfxU32 fieldMask;
    srv_phb_get_field(m_id, &fieldMask);

    // get name
    if (fieldMask & MMI_PHB_CONTACT_FIELD_NAME)
    {
        VfxWChar* fname = srv_phb_contact_get_fname(handle);
        VfxWChar* lname = srv_phb_contact_get_lname(handle);
        m_name = VappContactName(lname, fname, VFX_WSTR_EMPTY, MMI_PHB_CONTACT_FIELD_NAME);
    }

#ifdef __MMI_PHB_USIM_SUPPORT__
    // get nickname
    if (fieldMask & MMI_PHB_CONTACT_FIELD_NICK)
    {
        VfxWChar* nickname = srv_phb_contact_get_nick(handle);
        m_nickname.setValue(nickname);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

    // get number
    if (fieldMask & MMI_PHB_CONTACT_FIELD_NUMBER)
    {
        srv_phb_iterator looper = srv_phb_contact_get_number_iterator(handle);
        srv_phb_number_struct *number = NULL;

        for (VfxU32 i = 0; i < srv_phb_contact_get_number_count(handle); i++)
        {
            number = srv_phb_contact_get_number_next(&looper);
            m_number->pushValue(VappContactNumber(
                                VFX_WSTR_MEM(number->number),
                                getNumLabelByType((mmi_phb_num_type_enum) number->type),
                                MMI_PHB_CONTACT_FIELD_NUMBER,
                                number->type,
                                number->sub_id,
                                (number->is_default != MMI_FALSE) ? VFX_TRUE : VFX_FALSE));
        }
    }

    // get email
    if (fieldMask & MMI_PHB_CONTACT_FIELD_EMAIL)
    {
        srv_phb_iterator looper = srv_phb_contact_get_email_iterator(handle);
        srv_phb_email_struct *email = NULL;

        for (VfxU32 i = 0; i < srv_phb_contact_get_email_count(handle); i++)
        {
            email = srv_phb_contact_get_email_next(&looper);
            m_email->pushValue(VappContactEmail(
                                VFX_WSTR_MEM(email->email),
                                getEmailLabelByType((mmi_phb_email_type_enum)email->type),
                                MMI_PHB_CONTACT_FIELD_EMAIL,
                                email->type,
                                email->sub_id,
                                VFX_FALSE));
        }
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    // get company
    if (fieldMask & MMI_PHB_CONTACT_FIELD_COMPANY)
    {
        VfxWChar *company = srv_phb_contact_get_company(handle);
        m_company.setValue(company);
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */

#ifdef __MMI_PHB_INFO_FIELD__
    // get title
    if (fieldMask & MMI_PHB_CONTACT_FIELD_TITLE)
    {
        VfxWChar *title = srv_phb_contact_get_title(handle);
        m_title.setValue(title);
    }

    // get note
    if (fieldMask & MMI_PHB_CONTACT_FIELD_NOTE)
    {
        srv_phb_iterator looper = srv_phb_contact_get_note_iterator(handle);
        srv_phb_note_struct *note = srv_phb_contact_get_note_next(&looper);
        m_note.setValue(note->note);
    }

    // get address
    if (fieldMask & MMI_PHB_CONTACT_FIELD_ADDRESS)
    {
        srv_phb_iterator looper = srv_phb_contact_get_address_iterator(handle);
        srv_phb_address_struct *address = srv_phb_contact_get_address_next(&looper);
        m_address.setCity(address->address.city);
        m_address.setCountry(address->address.country);
        m_address.setExtension(address->address.extension);
        m_address.setPobox(address->address.pobox);
        m_address.setPostalcode(address->address.postalcode);
        m_address.setState(address->address.state);
        m_address.setStreet(address->address.street);
    }
#endif /* __MMI_PHB_INFO_FIELD__ */

    // get bday
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    if (fieldMask & MMI_PHB_CONTACT_FIELD_BDAY)
    {
        srv_phb_bday_struct *bday = srv_phb_contact_get_bday(handle);
        m_bday.setYear(bday->b_year);
        m_bday.setMonth(bday->b_month);
        m_bday.setDay(bday->b_day);
    }
#endif

    // get ring tone
    if (fieldMask & MMI_PHB_CONTACT_FIELD_RING)
    {
        srv_phb_res_struct *res = srv_phb_contact_get_ringtone(handle);
        m_ring = VappContactRes(VFX_WSTR_MEM(res->res_path), res->res_id, MMI_PHB_CONTACT_FIELD_RING);
    }

    // get image
    if (fieldMask & MMI_PHB_CONTACT_FIELD_IMAGE)
    {
        srv_phb_res_struct *res = srv_phb_contact_get_image(handle);
        m_image = VappContactRes(VFX_WSTR_MEM(res->res_path), res->res_id, MMI_PHB_CONTACT_FIELD_IMAGE);
    }

    srv_phb_free_contact(handle);
}

#ifdef __MMI_PHB_MYCARD__

void Contact::readMycard()
{
    mmi_phb_my_number_struct *myNumber = (mmi_phb_my_number_struct*) mmi_frm_temp_alloc(sizeof(mmi_phb_my_number_struct));

    srv_phb_read_my_number(myNumber);

    m_name = VappContactName(
            #ifdef __MMI_PHB_LAST_NAME_FIELD__
                myNumber->l_name,
            #else
                NULL,
            #endif
                myNumber->name,
                VFX_WSTR_EMPTY,
                MMI_PHB_CONTACT_FIELD_NAME);

    if (myNumber->number[0])
    {
        m_number->pushValue(VappContactNumber(
                         VFX_WSTR_MEM(myNumber->number),
                         getNumLabelByType((mmi_phb_num_type_enum)(myNumber->number_type)),
                         MMI_PHB_CONTACT_FIELD_NUMBER,
                         myNumber->number_type,
                         0,
                         VFX_FALSE));
    }

    if (myNumber->homeNumber[0])
    {
        m_number->pushValue(VappContactNumber(
                         VFX_WSTR_MEM(myNumber->homeNumber),
                         getNumLabelByType((mmi_phb_num_type_enum)(myNumber->homeNumber_type)),
                         MMI_PHB_CONTACT_FIELD_NUMBER,
                         myNumber->homeNumber_type,
                         0,
                         VFX_FALSE));
    }

    if (myNumber->officeNumber[0])
    {
        m_number->pushValue(VappContactNumber(
                         VFX_WSTR_MEM(myNumber->officeNumber),
                         getNumLabelByType((mmi_phb_num_type_enum)(myNumber->officeNumber_type)),
                         MMI_PHB_CONTACT_FIELD_NUMBER,
                         myNumber->officeNumber_type,
                         0,
                         VFX_FALSE));
    }

    if (myNumber->faxNumber[0])
    {
        m_number->pushValue(VappContactNumber(
                         VFX_WSTR_MEM(myNumber->faxNumber),
                         getNumLabelByType((mmi_phb_num_type_enum)(myNumber->faxNumber_type)),
                         MMI_PHB_CONTACT_FIELD_NUMBER,
                         myNumber->faxNumber_type,
                         0,
                         VFX_FALSE));
    }

    if (myNumber->emailAddress[0])
    {
        m_email->pushValue(VappContactEmail(
                         VFX_WSTR_MEM(myNumber->emailAddress),
                         getEmailLabelByType((mmi_phb_email_type_enum)(myNumber->emailAddress_type)),
                         MMI_PHB_CONTACT_FIELD_EMAIL,
                         myNumber->emailAddress_type,
                         0,
                         VFX_FALSE));
    }

#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__    
    if (myNumber->emailAddress2[0])
    {
        m_email->pushValue(VappContactEmail(
                         VFX_WSTR_MEM(myNumber->emailAddress2),
                         getEmailLabelByType((mmi_phb_email_type_enum)(myNumber->emailAddress2_type)),
                         MMI_PHB_CONTACT_FIELD_EMAIL,
                         myNumber->emailAddress2_type,
                         0,
                         VFX_FALSE));
    }
#endif

    mmi_frm_temp_free(myNumber);
}

#endif /* __MMI_PHB_MYCARD__ */
/***************************************************************************** 
 * Class ContactEntry
 *****************************************************************************/ 
ContactEntry::ContactEntry(mmi_phb_contact_id id):
    m_id(id),
    m_contact(NULL),
    m_filter(NULL),
    m_numLooper(NULL),
    m_emailLooper(NULL)
{
    createHandle();
}


ContactEntry::~ContactEntry()
{
    closeHandle();
}


VfxBool ContactEntry::isValid(mmi_phb_contact_id id)
{
    if (srv_phb_check_entry_exist(id))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool ContactEntry::isValid()
{
    if (srv_phb_check_entry_exist(m_id))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxU32 ContactEntry::getFieldMask()
{
    if (!isValid())
    {
        return 0;
    }

    VfxU32 fieldMask;
    srv_phb_get_field(m_id, &fieldMask);

    return fieldMask;
}


mmi_phb_contact_id ContactEntry::getId() const
{
    return m_id;
}


VappContactName ContactEntry::getName()
{
    if (!isValid())
    {
        return VappContactName();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_NAME);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    return VappContactName(
               VFX_WSTR_MEM(srv_phb_contact_get_lname(m_contact)),
               VFX_WSTR_MEM(srv_phb_contact_get_fname(m_contact)));
}


#ifdef __MMI_PHB_USIM_SUPPORT__
VappContactNickname ContactEntry::getNickname()
{
    if (!isValid())
    {
        return VappContactNickname();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_NICK);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    return VappContactNickname(srv_phb_contact_get_nick(m_contact));
}
#endif /* __MMI_PHB_USIM_SUPPORT__ */


VfxU32 ContactEntry::getNumberCount()
{
    if (!isValid())
    {
        return 0;
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_NUMBER);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    return srv_phb_contact_get_number_count(m_contact);
}


VfxU32 ContactEntry::getNumber()
{
    if (!isValid())
    {
        return 0;
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_NUMBER);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);
    m_numLooper = srv_phb_contact_get_number_iterator(m_contact);

    return srv_phb_contact_get_number_count(m_contact);
}


VappContactNumber ContactEntry::getNextNumber()
{
    if (!isValid())
    {
        return VappContactNumber();
    }

    srv_phb_number_struct *number = srv_phb_contact_get_number_next(&m_numLooper);
    if (number)
    {
        return VappContactNumber(
                   VFX_WSTR_MEM(number->number),
                   getNumLabelByType((mmi_phb_num_type_enum) number->type),
                   MMI_PHB_CONTACT_FIELD_NUMBER,
                   number->type,
                   number->sub_id,
                   (number->is_default != MMI_FALSE) ? VFX_TRUE : VFX_FALSE);
    }

    return VappContactNumber();
}


VappContactNumber ContactEntry::getNumberById(mmi_phb_sub_id id)
{
    if (!isValid())
    {
        return VappContactNumber();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_NUMBER);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    srv_phb_number_struct *number = srv_phb_contact_get_number_by_sub_id(m_contact, id);
    if (number)
    {
        return VappContactNumber(
                   VFX_WSTR_MEM(number->number),
                   getNumLabelByType((mmi_phb_num_type_enum) number->type),
                   MMI_PHB_CONTACT_FIELD_NUMBER,
                   number->type,
                   number->sub_id,
                   (number->is_default != MMI_FALSE) ? VFX_TRUE : VFX_FALSE);
    }

    return VappContactNumber();
}


VfxU32 ContactEntry::getEmailCount()
{
    if (!isValid())
    {
        return 0;
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_EMAIL);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    return srv_phb_contact_get_email_count(m_contact);
}


VfxU32 ContactEntry::getEmail()
{
    if (!isValid())
    {
        return 0;
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_EMAIL);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);
    m_emailLooper = srv_phb_contact_get_email_iterator(m_contact);

    return srv_phb_contact_get_email_count(m_contact);
}


VappContactEmail ContactEntry::getNextEmail()
{
    if (!isValid())
    {
        return VappContactEmail();
    }

    srv_phb_email_struct *email = srv_phb_contact_get_email_next(&m_emailLooper);
    if (email)
    {
        return VappContactEmail(
                   VFX_WSTR_MEM(email->email),
                   getEmailLabelByType((mmi_phb_email_type_enum)email->type),
                   MMI_PHB_CONTACT_FIELD_EMAIL,
                   email->type,
                   email->sub_id,
                   VFX_FALSE);
    }

    return VappContactEmail();
}


VappContactEmail ContactEntry::getEmailById(mmi_phb_sub_id id)
{
    if (!isValid())
    {
        return VappContactEmail();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_EMAIL);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    srv_phb_email_struct *email = srv_phb_contact_get_email_by_sub_id(m_contact, id);
    if (email)
    {
        return VappContactEmail(
                   VFX_WSTR_MEM(email->email),
                   getEmailLabelByType((mmi_phb_email_type_enum)email->type),
                   MMI_PHB_CONTACT_FIELD_EMAIL,
                   email->type,
                   email->sub_id,
                   VFX_FALSE);
    }

    return VappContactEmail();
}


#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
VappContactCompany ContactEntry::getCompany()
{
    if (!isValid())
    {
        return VappContactCompany();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_COMPANY);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    return VappContactCompany(srv_phb_contact_get_company(m_contact));
}
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */


#ifdef __MMI_PHB_INFO_FIELD__
VappContactTitle ContactEntry::getTitle()
{
    if (!isValid())
    {
        return VappContactTitle();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_TITLE);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    return VappContactTitle(srv_phb_contact_get_title(m_contact));
}


VappContactNote ContactEntry::getNote()
{
    if (!isValid())
    {
        return VappContactNote();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_NOTE);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    srv_phb_iterator looper = srv_phb_contact_get_note_iterator(m_contact);

    if (srv_phb_contact_get_note_count(m_contact))
    {
        srv_phb_note_struct* note = srv_phb_contact_get_note_next(&looper);

        return VappContactNote(note->note);
    }

    return VappContactNote();
}


VappContactAddress ContactEntry::getAddress()
{
    if (!isValid())
    {
        return VappContactAddress();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_ADDRESS);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    srv_phb_iterator looper = srv_phb_contact_get_address_iterator(m_contact);

    if (srv_phb_contact_get_address_count(m_contact))
    {
        srv_phb_address_struct* address = srv_phb_contact_get_address_next(&looper);
        VappContactAddress addr;

        addr.setCity(address->address.city);
        addr.setCountry(address->address.country);
        addr.setExtension(address->address.extension);
        addr.setPobox(address->address.pobox);
        addr.setPostalcode(address->address.postalcode);
        addr.setState(address->address.state);
        addr.setStreet(address->address.street);

        return addr;
    }

    return VappContactAddress();
}
#endif /* __MMI_PHB_INFO_FIELD__ */


#ifdef __MMI_PHB_BIRTHDAY_FIELD__
VappContactBday ContactEntry::getBday()
{
    if (!isValid())
    {
        return VappContactBday();
    }

    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_BDAY);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    srv_phb_bday_struct *bday = srv_phb_contact_get_bday(m_contact);
    if (bday)
    {
        return VappContactBday(bday->b_year, bday->b_month, bday->b_day);
    }

    return VappContactBday();
}
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

VappContactRes ContactEntry::getRingTone()
{
    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_RING);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    srv_phb_res_struct *res = srv_phb_contact_get_ringtone(m_contact);
    if (res)
    {
        return VappContactRes(
                   VFX_WSTR_MEM(res->res_path),
                   res->res_id,
                   VFX_WSTR_RES(VAPP_PHB_STR_RING),
                   MMI_PHB_CONTACT_FIELD_RING);
    }

    return VappContactRes();
}


VappContactRes ContactEntry::getImage()
{
    srv_phb_filed_filter_set_field(m_filter, MMI_PHB_CONTACT_FIELD_IMAGE);
    m_contact = srv_phb_read_contact(m_id, m_filter, m_contact);

    srv_phb_res_struct *res = srv_phb_contact_get_image(m_contact);
    if (res)
    {
        return VappContactRes(
                   VFX_WSTR_MEM(res->res_path),
                   0,
                   MMI_PHB_CONTACT_FIELD_IMAGE);
    }

    return VappContactRes();
}


phb_storage_enum ContactEntry::getStorage()
{
    return ContactStorage::getStorage(m_id);
}


mmi_sim_enum ContactEntry::getPreferSim(mmi_phb_sub_id id, VfxBool call)
{
    mmi_sim_enum sim = MMI_SIM_NONE;
    phb_storage_enum storage = getStorage();

    if (storage == PHB_STORAGE_NVRAM && call)
    {
        VappContactNumber number = getNumberById(id);
        srv_phb_get_preferred_sim(number.getBuf(), MMI_PHB_INVALID_CONTACT_ID, SRV_PHB_NUMBER_OP_TYPE_DIAL, &sim);
    }
    else if (storage == PHB_STORAGE_NVRAM && !call)
    {
        VappContactNumber number = getNumberById(id);
        srv_phb_get_preferred_sim(number.getBuf(), MMI_PHB_INVALID_CONTACT_ID, SRV_PHB_NUMBER_OP_TYPE_MESSAGE, &sim);
    }
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    else if (storage == PHB_STORAGE_TCARD && call)
    {
        VappContactNumber number = getNumberById(id);
        srv_phb_get_preferred_sim(number.getBuf(), MMI_PHB_INVALID_CONTACT_ID, SRV_PHB_NUMBER_OP_TYPE_DIAL, &sim); // after phb srv it, myler
    }
    else if (storage == PHB_STORAGE_TCARD && !call)
    {
        VappContactNumber number = getNumberById(id);
        srv_phb_get_preferred_sim(number.getBuf(), MMI_PHB_INVALID_CONTACT_ID, SRV_PHB_NUMBER_OP_TYPE_MESSAGE, &sim);
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
    else
    {
        sim = mmi_frm_index_to_sim(storage - PHB_STORAGE_SIM);
    }

    return sim;
}


void ContactEntry::createHandle()
{
    // create filter
    if (m_filter == NULL)
    {
        m_filter = srv_phb_create_field_filter();
    }
}


void ContactEntry::closeHandle()
{
    // release contact filter
    if (m_filter)
    {
        srv_phb_free_field_filter(m_filter);
        m_filter = NULL;
    }

    // release contact handle
    if (m_contact)
    {
        srv_phb_free_contact(m_contact);
        m_contact = NULL;
    }
}


/***************************************************************************** 
 * Class ContactFieldType
 *****************************************************************************/
ContactFieldType::ContactFieldType(
    mmi_phb_contact_field_id_enum field,
    phb_storage_enum storage):
    m_field(field),
    m_storage(storage),
    m_typeCount(0)
{
}


void ContactFieldType::onInit()
{
    VfxObject::onInit();

    m_typeCount = srv_phb_get_field_type_list(m_typeArray, m_field, m_storage);
}


VfxU32 ContactFieldType::getTotalCustomTypeCount()
{
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    return MMI_PHB_FIELD_LABEL_COUNT;
#else
    return 0;
#endif
}


VfxU32 ContactFieldType::getDefaultTypeCount()
{
    VfxU32 count = 0;

    switch (m_field)
    {
        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
            count = MMI_PHB_NUM_TYPE_TOTAL - 1;
            break;

        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
            count = MMI_PHB_EMAIL_TYPE_TOTAL - 1;
            break;
    }

    return count;
}


VfxU32 ContactFieldType::getCustomTypeCount()
{
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    return m_typeCount - getDefaultTypeCount();
#else
    return 0;
#endif    
}


VfxU32 ContactFieldType::getDefaultType(VfxU32 index)
{
    return m_typeArray[index];
}


VfxU32 ContactFieldType::getCustomType(VfxU32 index)
{
    return m_typeArray[index + getDefaultTypeCount()];
}


VfxWString ContactFieldType::getLabel(VfxU32 type)
{
    if (m_field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        return getNumLabelByType((mmi_phb_num_type_enum)type);
    }
    else if (m_field == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        return getEmailLabelByType((mmi_phb_email_type_enum)type);
    }

    return VFX_WSTR_EMPTY;
}


#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
VfxS32 ContactFieldType::addType(VfxWChar* label)
{
    VfxS32 type = srv_phb_add_field_type(label, m_field);

    m_typeCount = srv_phb_get_field_type_list(m_typeArray, m_field, m_storage);

    return type;
}


VfxBool ContactFieldType::deleteType(VfxU32 type)
{
    VfxBool result = (srv_phb_delete_field_type((VfxU8) type, m_field) != MMI_FALSE) ? VFX_TRUE : VFX_FALSE;

    m_typeCount = srv_phb_get_field_type_list(m_typeArray, m_field, m_storage);

    return result;
}
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */


mmi_phb_contact_field_id_enum ContactFieldType::getFieldType()
{
    return m_field;
}


/***************************************************************************** 
 * Class VappContactFieldObjList
 *****************************************************************************/
VappContactFieldObjList::VappContactFieldObjList()
    :m_head(NULL),
     m_tail(NULL),
     m_count(0)
{}


void VappContactFieldObjList::onDeinit()
{
    FieldNode *loop = m_head;

    while (loop)
    {
        FieldNode *node = loop;

        loop = loop->m_next;

        VFX_DELETE(node->m_field);

        VFX_FREE_MEM(node);
    }

    VfxObject::onDeinit();
}


void VappContactFieldObjList::setField(const VfxWChar* data, VfxU32 length, VfxU32 id, VfxU32 type)
{
    FieldNode *node;
    VFX_ALLOC_MEM(node, sizeof(FieldNode), this);

    node->m_next = NULL;

    if (m_head == NULL)
    {
        m_head = node;
        m_tail = node;
    }
    else
    {
        m_tail->m_next = node;
        m_tail = node;
    }

    m_count++;

    switch (type)
    {
        case MMI_PHB_CONTACT_FIELD_NAME:
        {
            VappContactName *name;
            VFX_ALLOC_NEW_EX(name, VappContactName, this, (NULL, data));
            node->m_field = name;
            break;
        }
        case MMI_PHB_CONTACT_FIELD_NUMBER:
        {
            VappContactNumber *number;
            VFX_ALLOC_NEW_EX(number, VappContactNumber, this, (data));
            node->m_field = number;
            break;
        }
        case MMI_PHB_CONTACT_FIELD_EMAIL:
        {
            VappContactEmail *email;
            VFX_ALLOC_NEW_EX(email, VappContactEmail, this, (data));
            node->m_field = email;
            break;
        }
        case MMI_PHB_CONTACT_FIELD_IMAGE:
        {
            VappContactRes *image;
            VFX_ALLOC_NEW_EX(image, VappContactRes, this, (data, id, type));
            node->m_field = image;
            break;
        }
    }
}


VappContactFieldObjList::FieldNode* VappContactFieldObjList::getHead()
{
    return m_head;
}


VappContactFieldObjList::FieldNode* VappContactFieldObjList::getTail()
{
    return m_tail;
}


VfxU32 VappContactFieldObjList::getCount() const
{
    return m_count;
}

