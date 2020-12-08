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
 *  vapp_contact_entry.h
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "vapp_phb_gprot.h"

#ifndef __CONTACT_ENTRY_H__
#define __CONTACT_ENTRY_H__

#include "vfx_uc_include.h"

#include "mmi_rp_vapp_contact_def.h"
#include "mmi_rp_srv_phb_def.h"

#include "vapp_contact_storage.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "ProfilesSrvGprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * enum
 *****************************************************************************/ 
typedef enum
{
    VAPP_CONTACT_TYPE_DEFAULT,  // will deside by contact id or storage type
    VAPP_CONTACT_TYPE_PHONE,    // phone contact
    VAPP_CONTACT_TYPE_SIM,      // SIM contact
    VAPP_CONTACT_TYPE_USIM,     // USIM contact
    VAPP_CONTACT_TYPE_CARD,     // card
    VAPP_CONTACT_TYPE_MYCARD,   // mycard
    VAPP_CONTACT_TYPE_TOTAL     // enum end
} vapp_contact_type_enum;


/***************************************************************************** 
 * Class VappContactFieldBase
 *****************************************************************************/ 
class VappContactFieldBase: public VfxBase
{
public:
    // default constructor
    VappContactFieldBase()
        : m_label(), m_type(0)
    {}

    // constructor
    VappContactFieldBase(const VfxWString &label, VfxU32 type)
        : m_label(label), m_type(type)
    {}

    // copy constructor
    VappContactFieldBase(const VappContactFieldBase& field)
    {
        m_label = field.getLabel();
        m_type = field.getType();
    }

    // operator=
    VappContactFieldBase& operator= (const VappContactFieldBase& field)
    {
        m_label = field.getLabel();
        m_type = field.getType();

        return *this;
    }

    // set label
    void setLabel(const VfxWString &label)
    {
        m_label = label;
    }

    // get label
    const VfxWString& getLabel() const
    {
        return m_label;
    }

    // set type
    void setType(VfxU32 type)
    {
        m_type = type;
    }

    // get type
    VfxU32 getType() const
    {
        return m_type;
    }

private:
    VfxWString m_label;
    VfxU32     m_type;
};


/***************************************************************************** 
 * Class VappContactField
 *****************************************************************************/ 
class VappContactField: public VappContactFieldBase
{
public:
    // default constructor
    VappContactField()
        : VappContactFieldBase(), m_subType(0), m_subId(MMI_PHB_SUB_ID_NEW), m_primary(VFX_FALSE)
    {};

    // constructor
    VappContactField(const VfxWString& label, VfxU32 type, VfxU32 subType, VfxU32 subId, VfxBool isPrimary)
        : VappContactFieldBase(label, type), m_subType(subType), m_subId(subId), m_primary(isPrimary)
    {}

    // copy constructor
    VappContactField(const VappContactField& field)
        : VappContactFieldBase(field)
    {
        m_subType = field.getSubType();
        m_subId = field.getSubId();
        m_primary = field.getPrimary();
    };

    // operator=
    VappContactField& operator= (const VappContactField& field)
    {
        VappContactFieldBase::operator=(field);

        m_subType = field.getSubType();
        m_subId = field.getSubId();
        m_primary = field.getPrimary();

        return *this;
    }

    // set subType
    void setSubType(VfxU32 subType)
    {
        m_subType = subType;
    }

    // get subType
    VfxU32 getSubType() const
    {
        return m_subType;
    }

    // set subId
    void setSubId(VfxU32 subId)
    {
        m_subId = subId;
    }

    // get subId
    VfxU32 getSubId() const
    {
        return m_subId;
    }

    // set primary
    void setPrimary(VfxBool primary)
    {
        m_primary = primary;
    }

    // get primary
    VfxBool getPrimary() const
    {
        return m_primary;
    }

private:
    // sub type
    VfxU32 m_subType;

    // sub id
    VfxU32 m_subId;

    // primary
    VfxBool m_primary;
};


/***************************************************************************** 
 * Class VappContactName
 *****************************************************************************/ 
class VappContactName: public VappContactFieldBase
{
public:
    // default constructor
    VappContactName()
        : VappContactFieldBase(VFX_WSTR_RES(VAPP_PHB_STR_NAME), MMI_PHB_CONTACT_FIELD_NAME)
    {
        m_family[0] = 0;
        m_given[0] = 0;
    }

    // constructor
    VappContactName(
        const VfxWChar* family,
        const VfxWChar* given,
        const VfxWString &label = VFX_WSTR_RES(VAPP_PHB_STR_NAME),
        VfxU32 type = MMI_PHB_CONTACT_FIELD_NAME)
        : VappContactFieldBase(label, type)
    {
        setFamily(family);
        setGiven(given);
    }

    // copy constructor
    VappContactName(const VappContactName& name)
        : VappContactFieldBase(name)
    {
        setFamily(name.getFamilyBuf());
        setGiven(name.getGivenBuf());
    }

    // operator=
    VappContactName& operator= (const VappContactName& name)
    {
        VappContactFieldBase::operator=(name);

        setFamily(name.getFamilyBuf());
        setGiven(name.getGivenBuf());

        return *this;
    }

    // set family
    void setFamily(const VfxWChar* family)
    {
        if (family == NULL)
        {
            m_family[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_family, (WCHAR*)family, MMI_PHB_NAME_FIELD_LENGTH);
            srv_phb_remove_invalid_name((U16*)m_family);
        }
    }

    // set given
    void setGiven(const VfxWChar* given)
    {
        if (given == NULL)
        {
            m_given[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_given, (WCHAR*)given, MMI_PHB_NAME_FIELD_LENGTH);
            srv_phb_remove_invalid_name((U16*)m_given);
        }
    }

    // get family
    VfxWChar* getFamilyBuf() const
    {
        return (VfxWChar*)m_family;
    }

    // get given
    VfxWChar* getGivenBuf() const
    {
        return (VfxWChar*)m_given;
    }

    // get name
    VfxWString getString() const
    {
        VfxWChar name[MMI_PHB_NAME_LENGTH + 1];
        srv_phb_convert_to_name(name, (U16*)m_given, (U16*)m_family, MMI_PHB_NAME_LENGTH);
        return VFX_WSTR_MEM(name);
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_NAME_FIELD_LENGTH;
    }

    // is empty
    VfxBool isEmpty()
    {
        if (m_family[0] == 0 && m_given[0] == 0)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }

private:
    VfxWChar m_family[MMI_PHB_NAME_FIELD_LENGTH + 1];
    VfxWChar m_given[MMI_PHB_NAME_FIELD_LENGTH + 1];
};


#ifdef __MMI_PHB_USIM_SUPPORT__
/***************************************************************************** 
 * Class VappContactNickname
 *****************************************************************************/ 
class VappContactNickname: public VappContactFieldBase
{
public:
    // default constructor
    VappContactNickname()
        : VappContactFieldBase(VFX_WSTR_RES(VAPP_PHB_STR_NICKNAME), MMI_PHB_CONTACT_FIELD_NICK)
    {
        m_value[0] = 0;
    }

    // constructor
    VappContactNickname(
        const VfxWChar* value,
        const VfxWString &label = VFX_WSTR_RES(VAPP_PHB_STR_NICKNAME),
        VfxU32 type = MMI_PHB_CONTACT_FIELD_NICK)
        : VappContactFieldBase(label, type)
    {
        setValue(value);
    }

    // copy constructor
    VappContactNickname(const VappContactNickname& nickname)
        : VappContactFieldBase(nickname)
    {
        setValue(nickname.getBuf());
    }

    // operator=
    VappContactNickname& operator= (const VappContactNickname& nickname)
    {
        VappContactFieldBase::operator=(nickname);

        setValue(nickname.getBuf());

        return *this;
    }

    // set nickname
    void setValue(const VfxWChar* value)
    {
        if (value == NULL)
        {
            m_value[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_value, (WCHAR*)value, MMI_PHB_NAME_FIELD_LENGTH);
            srv_phb_remove_invalid_name((U16*)value);
        }
    }

    // get nickname
    VfxWString getString() const
    {
        return VFX_WSTR_MEM(m_value);
    }

    // get buffer
    VfxWChar* getBuf() const
    {
        return (VfxWChar*) m_value;
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_NAME_FIELD_LENGTH;
    }

    // is empty
    VfxBool isEmpty()
    {
        return (m_value[0] != 0) ? VFX_FALSE : VFX_TRUE;
    }

private:
    VfxWChar m_value[MMI_PHB_NAME_FIELD_LENGTH + 1];
};
#endif /* __MMI_PHB_USIM_SUPPORT__ */


/***************************************************************************** 
 * Class VappContactNumber
 *****************************************************************************/ 
class VappContactNumber: public VappContactField
{
public:
    // default constructor
    VappContactNumber()
        : VappContactField(
            VFX_WSTR_RES(VAPP_PHB_STR_MOBILE),
            MMI_PHB_CONTACT_FIELD_NUMBER,
            MMI_PHB_NUM_TYPE_MOBILE,
            MMI_PHB_SUB_ID_NEW,
            VFX_FALSE)
    {
        m_value[0] = 0;
    }

    // constructor
    VappContactNumber(const VfxWChar* value)
        : VappContactField(
            VFX_WSTR_RES(VAPP_PHB_STR_MOBILE),
            MMI_PHB_CONTACT_FIELD_NUMBER,
            MMI_PHB_NUM_TYPE_MOBILE,
            MMI_PHB_SUB_ID_NEW,
            VFX_FALSE)
    {
        setValue(value);
    }

    // constructor
    VappContactNumber(
        const VfxWChar* value,
        const VfxWString &label,
        VfxU32 type,
        VfxU32 subType,
        VfxU32 subId,
        VfxBool isPrimary = VFX_FALSE)
        : VappContactField(label, type, subType, subId, isPrimary)
    {
        if (label.isEmpty())
        {
            setSubType(MMI_PHB_NUM_TYPE_MOBILE);
            setLabel(VFX_WSTR_RES(VAPP_PHB_STR_MOBILE));
        }

        setValue(value);
    }

    // copy constructor
    VappContactNumber(const VappContactNumber& number)
        : VappContactField(number)
    {
        setValue(number.getBuf());
    }

    // operator=
    VappContactNumber& operator= (const VappContactNumber& number)
    {
        VappContactField::operator=(number);

        setValue(number.getBuf());

        return *this;
    }

    // set number
    void setValue(const VfxWChar* value)
    {
        if (value == NULL)
        {
            m_value[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_value, (WCHAR*)value, MMI_PHB_NUMBER_LENGTH + 1);
            srv_phb_remove_invalid_number((U16*)m_value);
        }
    }

    // get number
    VfxWString getString() const
    {
        return VFX_WSTR_MEM(m_value);
    }

    // get buffer
    VfxWChar* getBuf() const
    {
        return (VfxWChar*) m_value;
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_NUMBER_LENGTH + 1;
    }

    // is empty
    VfxBool isEmpty()
    {
        return (m_value[0] != 0) ? VFX_FALSE : VFX_TRUE;
    }

private:
    VfxWChar m_value[MMI_PHB_NUMBER_LENGTH + 1 + 1];
};


/***************************************************************************** 
 * Class VappContactEmail
 *****************************************************************************/ 
class VappContactEmail: public VappContactField
{
public:
    // default constructor
    VappContactEmail()
        : VappContactField(
            VFX_WSTR_RES(VAPP_PHB_STR_WORK),
            MMI_PHB_CONTACT_FIELD_EMAIL,
            MMI_PHB_EMAIL_TYPE_OFFICE,
            MMI_PHB_SUB_ID_NEW,
            VFX_FALSE)
    {
        m_value[0] = 0;
    }

    // constructor
    VappContactEmail(const VfxWChar* value)
        : VappContactField(
            VFX_WSTR_RES(VAPP_PHB_STR_WORK),
            MMI_PHB_CONTACT_FIELD_EMAIL,
            MMI_PHB_EMAIL_TYPE_OFFICE,
            MMI_PHB_SUB_ID_NEW,
            VFX_FALSE)
    {
        setValue(value);
    }

    // constructor
    VappContactEmail(
        const VfxWChar* value,
        const VfxWString &label,
        VfxU32 type,
        VfxU32 subType,
        VfxU32 subId,
        VfxBool isPrimary = VFX_FALSE)
        : VappContactField(label, type, subType, subId, isPrimary)
    {
        if (label.isEmpty())
        {
            setSubType(MMI_PHB_EMAIL_TYPE_OFFICE);
            setLabel(VFX_WSTR_RES(VAPP_PHB_STR_WORK));
        }

        setValue(value);
    }

    // copy constructor
    VappContactEmail(const VappContactEmail& email)
        : VappContactField(email)
    {
        setValue(email.getBuf());
    }

    // operator=
    VappContactEmail& operator= (const VappContactEmail& email)
    {
        VappContactField::operator=(email);

        setValue(email.getBuf());

        return *this;
    }

    // set email
    void setValue(const VfxWChar* value)
    {
        if (value == NULL)
        {
            m_value[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_value, (WCHAR*)value, MMI_PHB_EMAIL_LENGTH);
        }
    }

    // get email
    VfxWString getString() const
    {
        return VFX_WSTR_MEM(m_value);
    }

    // get buffer
    VfxWChar* getBuf() const
    {
        return (VfxWChar*) m_value;
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_EMAIL_LENGTH;
    }

    // is empty
    VfxBool isEmpty()
    {
        return (m_value[0] != 0) ? VFX_FALSE : VFX_TRUE;
    }

private:
    VfxWChar m_value[MMI_PHB_EMAIL_LENGTH + 1];
};


#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
/***************************************************************************** 
 * Class VappContactCompany
 *****************************************************************************/ 
class VappContactCompany: public VappContactFieldBase
{
public:
    VappContactCompany():
        VappContactFieldBase(VFX_WSTR_RES(VAPP_PHB_STR_COMPANY), MMI_PHB_CONTACT_FIELD_COMPANY)
    {
        m_value[0] = 0;
    }

    VappContactCompany(
        const VfxWChar* value,
        const VfxWString &label = VFX_WSTR_RES(VAPP_PHB_STR_COMPANY),
        VfxU32 type = MMI_PHB_CONTACT_FIELD_COMPANY)
        : VappContactFieldBase(label, type)
    {
        setValue(value);
    }

    VappContactCompany(const VappContactCompany& company):
        VappContactFieldBase(company)
    {
        setValue(company.getBuf());
    }

    VappContactCompany& operator= (const VappContactCompany& company)
    {
        VappContactFieldBase::operator=(company);

        setValue(company.getBuf());

        return *this;
    }

    // set company
    void setValue(const VfxWChar* value)
    {
        if (value == NULL)
        {
            m_value[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_value, (WCHAR*)value, MMI_PHB_COMPANY_LENGTH);
        }
    }

    // get company
    VfxWString getString() const
    {
        return VFX_WSTR_MEM(m_value);
    }

    // get buffer
    VfxWChar* getBuf() const
    {
        return (VfxWChar*) m_value;
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_COMPANY_LENGTH;
    }

    // is empty
    VfxBool isEmpty()
    {
        return (m_value[0] != 0) ? VFX_FALSE : VFX_TRUE;
    }

private:
    VfxWChar m_value[MMI_PHB_COMPANY_LENGTH + 1];
};
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */


#ifdef __MMI_PHB_INFO_FIELD__
/***************************************************************************** 
 * Class VappContactTitle
 *****************************************************************************/ 
class VappContactTitle: public VappContactFieldBase
{
public:
    VappContactTitle():
        VappContactFieldBase(VFX_WSTR_RES(VAPP_PHB_STR_TITLE), MMI_PHB_CONTACT_FIELD_TITLE)
    {
        m_value[0] = 0;
    }

    VappContactTitle(
        const VfxWChar* value,
        const VfxWString &label = VFX_WSTR_RES(VAPP_PHB_STR_TITLE),
        VfxU32 type = MMI_PHB_CONTACT_FIELD_TITLE)
        : VappContactFieldBase(label, type)
    {
        setValue(value);
    }

    VappContactTitle(const VappContactTitle& title):
        VappContactFieldBase(title)
    {
        setValue(title.getBuf());
    }

    VappContactTitle& operator= (const VappContactTitle& title)
    {
        VappContactFieldBase::operator=(title);

        setValue(title.getBuf());

        return *this;
    }

    // set title
    void setValue(const VfxWChar* value)
    {
        if (value == NULL)
        {
            m_value[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_value, (WCHAR*)value, MMI_PHB_TITLE_LENGTH);
        }
    }

    // get title
    VfxWString getString() const
    {
        return VFX_WSTR_MEM(m_value);
    }

    // get buffer
    VfxWChar* getBuf() const
    {
        return (VfxWChar*) m_value;
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_TITLE_LENGTH;
    }

    // is empty
    VfxBool isEmpty()
    {
        return (m_value[0] != 0) ? VFX_FALSE : VFX_TRUE;
    }

private:
    VfxWChar m_value[MMI_PHB_TITLE_LENGTH + 1];
};


/***************************************************************************** 
 * Class VappContactURL
 *****************************************************************************/ 
class VappContactURL: public VappContactFieldBase
{
public:
    VappContactURL():
        VappContactFieldBase(VFX_WSTR_RES(VAPP_PHB_STR_URL), MMI_PHB_CONTACT_FIELD_URL)
    {
        m_value[0] = 0;
    }

    VappContactURL(const VfxWChar* value,
        const VfxWString &label = VFX_WSTR_RES(VAPP_PHB_STR_URL),
        VfxU32 type = MMI_PHB_CONTACT_FIELD_URL)
        : VappContactFieldBase(label, type)
    {
        setValue(value);
    }

    VappContactURL(const VappContactURL& url):
        VappContactFieldBase(url)
    {
        setValue(url.getBuf());
    }

    VappContactURL& operator= (const VappContactURL& url)
    {
        VappContactFieldBase::operator=(url);

        setValue(url.getBuf());

        return *this;
    }

    // set url
    void setValue(const VfxWChar* value)
    {
        if (value == NULL)
        {
            m_value[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_value, (WCHAR*)value, MMI_PHB_URL_LENGTH);
        }
    }

    // get url
    VfxWString getString() const
    {
        return VFX_WSTR_MEM(m_value);
    }

    // get buffer
    VfxWChar* getBuf() const
    {
        return (VfxWChar*) m_value;
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_URL_LENGTH;
    }

    // is empty
    VfxBool isEmpty()
    {
        return (m_value[0] != 0) ? VFX_FALSE : VFX_TRUE;
    }

private:
    VfxWChar m_value[MMI_PHB_URL_LENGTH + 1];
};


/***************************************************************************** 
 * Class VappContactNote
 *****************************************************************************/ 
class VappContactNote: public VappContactFieldBase
{
public:
    VappContactNote():
        VappContactFieldBase(VFX_WSTR_RES(VAPP_PHB_STR_NOTE), MMI_PHB_CONTACT_FIELD_NOTE)
    {
        m_value[0] = 0;
    }

    VappContactNote(
        const VfxWChar* value,
        const VfxWString &label = VFX_WSTR_RES(VAPP_PHB_STR_NOTE),
        VfxU32 type = MMI_PHB_CONTACT_FIELD_NOTE)
        : VappContactFieldBase(label, type)
    {
        setValue(value);
    }

    VappContactNote(const VappContactNote& note):
        VappContactFieldBase(note)
    {
        setValue(note.getBuf());
    }

    VappContactNote& operator= (const VappContactNote& note)
    {
        VappContactFieldBase::operator=(note);

        setValue(note.getBuf());

        return *this;
    }

    // set note
    void setValue(const VfxWChar* value)
    {
        if (value == NULL)
        {
            m_value[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_value, (WCHAR*)value, MMI_PHB_NOTE_LENGTH);
        }
    }

    // get note
    VfxWString getString() const
    {
        return VFX_WSTR_MEM(m_value);
    }

    // get buffer
    VfxWChar* getBuf() const
    {
        return (VfxWChar*) m_value;
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_NOTE_LENGTH;
    }

    // is empty
    VfxBool isEmpty()
    {
        return (m_value[0] != 0) ? VFX_FALSE : VFX_TRUE;
    }

private:
    VfxWChar m_value[MMI_PHB_NOTE_LENGTH + 1];
};


/***************************************************************************** 
 * Class VappContactAddress
 *****************************************************************************/ 
class VappContactAddress: public VappContactFieldBase
{
public:
    // default constructor
    VappContactAddress():
        VappContactFieldBase(VFX_WSTR_RES(VAPP_PHB_STR_ADDRESS), MMI_PHB_CONTACT_FIELD_ADDRESS)
    {
        m_pobox[0] = 0;
        m_extension[0] = 0;
        m_street[0] = 0;
        m_city[0] = 0;
        m_state[0] = 0;
        m_postalcode[0] = 0;
        m_country[0] = 0; 
    }

    // constructor
    VappContactAddress(const VappContactAddress& addr):
        VappContactFieldBase(addr)
    {
        setPobox(addr.getPoboxBuf());
        setExtension(addr.getExtensionBuf());
        setPostalcode(addr.getPostalcodeBuf());
        setStreet(addr.getStreetBuf());
        setCity(addr.getCityBuf());
        setCountry(addr.getCountryBuf());
        setState(addr.getStateBuf());
    }

    // operator=
    VappContactAddress& operator= (const VappContactAddress& addr)
    {
        VappContactFieldBase::operator=(addr);

        setPobox(addr.getPoboxBuf());
        setExtension(addr.getExtensionBuf());
        setPostalcode(addr.getPostalcodeBuf());
        setStreet(addr.getStreetBuf());
        setCity(addr.getCityBuf());
        setCountry(addr.getCountryBuf());
        setState(addr.getStateBuf());

        return *this;
    }

    // set pobox
    void setPobox(const VfxWChar *pobox)
    {
        if (pobox == NULL)
        {
            m_pobox[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_pobox, (WCHAR*)pobox, MMI_PHB_ADDRESS_LENGTH);
        }
    }

    // get pobox
    VfxWChar* getPoboxBuf() const
    {
        return (VfxWChar*)m_pobox;
    }

    // set extension
    void setExtension(const VfxWChar *extension)
    {
        if (extension == NULL)
        {
            m_extension[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_extension, (WCHAR*)extension, MMI_PHB_ADDRESS_LENGTH);
        }
    }

    // get extension
    VfxWChar* getExtensionBuf() const
    {
        return (VfxWChar*)m_extension;
    }

    // set street
    void setStreet(const VfxWChar *street)
    {
        if (street == NULL)
        {
            m_street[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_street, (WCHAR*)street, MMI_PHB_ADDRESS_LENGTH);
        }
    }

    // get street
    VfxWChar* getStreetBuf() const
    {
        return (VfxWChar*)m_street;
    }

    // set city
    void setCity(const VfxWChar *city)
    {
        if (city == NULL)
        {
            m_city[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_city, (WCHAR*)city, MMI_PHB_ADDRESS_LENGTH);
        }
    }

    // get city
    VfxWChar* getCityBuf() const
    {
        return (VfxWChar*)m_city;
    }

    // set state
    void setState(const VfxWChar *state)
    {
        if (state == NULL)
        {
            m_state[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_state, (WCHAR*)state, MMI_PHB_ADDRESS_LENGTH);
        }
    }

    // get state
    VfxWChar* getStateBuf() const
    {
        return (VfxWChar*)m_state;
    }

    // set postalcode
    void setPostalcode(const VfxWChar *postalcode)
    {
        if (postalcode == NULL)
        {
            m_postalcode[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_postalcode, (WCHAR*)postalcode, MMI_PHB_ADDRESS_LENGTH);
        }
    }

    // get postalcode
    VfxWChar* getPostalcodeBuf() const
    {
        return (VfxWChar*)m_postalcode;
    }

    // set country
    void setCountry(const VfxWChar *country)
    {
        if (country == NULL)
        {
            m_country[0] = 0;
        }
        else
        {
            mmi_wcsncpy((WCHAR*)m_country, (WCHAR*)country, MMI_PHB_ADDRESS_LENGTH);
        }
    }

    // get country
    VfxWChar* getCountryBuf() const
    {
        return (VfxWChar*)m_country;
    }

    // get address
    VfxWString getString()
    {
        VfxWString address;
        VfxBool append = VFX_FALSE;

        if (m_pobox[0])
        {
            address += VFX_WSTR_MEM(m_pobox);
            append = VFX_TRUE;
        }

        if (m_extension[0])
        {
            if (append)
            {
                address += VFX_WSTR_RES(VAPP_PHB_STR_COMMA);
            }
            address += VFX_WSTR_MEM(m_extension);
            append = VFX_TRUE;
        }

        if (m_street[0])
        {
            if (append)
            {
                address += VFX_WSTR_RES(VAPP_PHB_STR_COMMA);
            }
            address += VFX_WSTR_MEM(m_street);
            append = VFX_TRUE;
        }

        if (m_city[0])
        {
            if (append)
            {
                address += VFX_WSTR_RES(VAPP_PHB_STR_COMMA);
            }
            address += VFX_WSTR_MEM(m_city);
            append = VFX_TRUE;
        }

        if (m_state[0])
        {
            if (append)
            {
                address += VFX_WSTR_RES(VAPP_PHB_STR_COMMA);
            }
            address += VFX_WSTR_MEM(m_state);
            append = VFX_TRUE;
        }

        if (m_postalcode[0])
        {
            if (append)
            {
                address += VFX_WSTR_RES(VAPP_PHB_STR_COMMA);
            }
            address += VFX_WSTR_MEM(m_postalcode);
            append = VFX_TRUE;
        }

        if (m_country[0])
        {
            if (append)
            {
                address += VFX_WSTR_RES(VAPP_PHB_STR_COMMA);
            }
            address += VFX_WSTR_MEM(m_country);
        }

        return address;
    }

    // get buffer
    void getBuf(mmi_phb_address_struct *address)
    {
        mmi_wcscpy(address->city, m_city);
        mmi_wcscpy(address->country, m_country);
        mmi_wcscpy(address->extension, m_extension);
        mmi_wcscpy(address->pobox, m_pobox);
        mmi_wcscpy(address->postalcode, m_postalcode);
        mmi_wcscpy(address->state, m_state);
        mmi_wcscpy(address->street, m_street);
    }

    // get length
    VfxU32 getLength()
    {
        return MMI_PHB_ADDRESS_LENGTH;
    }

    // is empty
    VfxBool isEmpty()
    {
        if (m_pobox[0] == 0 && m_extension[0] == 0 && m_street[0] == 0 && m_city[0] == 0 && m_state[0] == 0 && m_postalcode[0] == 0 && m_country[0] == 0)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }

private:
    VfxWChar m_pobox[MMI_PHB_ADDRESS_LENGTH + 1];       /* pobox field */
    VfxWChar m_extension[MMI_PHB_ADDRESS_LENGTH + 1];   /* extension field */
    VfxWChar m_street[MMI_PHB_ADDRESS_LENGTH + 1];      /* street field */
    VfxWChar m_city[MMI_PHB_ADDRESS_LENGTH + 1];        /* city field */
    VfxWChar m_state[MMI_PHB_ADDRESS_LENGTH + 1];       /* state field */
    VfxWChar m_postalcode[MMI_PHB_ADDRESS_LENGTH + 1];  /* postalcode field */
    VfxWChar m_country[MMI_PHB_ADDRESS_LENGTH + 1];     /* country field */
};
#endif /* __MMI_PHB_INFO_FIELD__ */


/***************************************************************************** 
 * Class VappContactBday
 *****************************************************************************/
#ifdef  __MMI_PHB_BIRTHDAY_FIELD__
class VappContactBday: public VappContactFieldBase
{
public:
    VappContactBday()
        : m_year(0), m_month(0), m_day(0)
    {}

    VappContactBday(
        VfxU16 year,
        VfxU8 month,
        VfxU8 day,
        const VfxWString &label = VFX_WSTR_RES(VAPP_PHB_STR_BDAY),
        VfxU32 type = MMI_PHB_CONTACT_FIELD_BDAY)
        : VappContactFieldBase(label, type), m_year(year), m_month(month), m_day(day)
    {}

    VappContactBday(const VappContactBday& bday)
        : VappContactFieldBase(bday)
    {
        m_year = bday.getYear();
        m_month = bday.getMonth();
        m_day = bday.getDay();
    }

    VappContactBday& operator= (const VappContactBday& bday)
    {
        VappContactFieldBase::operator=(bday);

        m_year = bday.getYear();
        m_month = bday.getMonth();
        m_day = bday.getDay();

        return *this;
    }

    void setYear(VfxU16 year)
    {
        m_year = year;
    }

    VfxU16 getYear() const
    {
        return m_year;
    }

    void setMonth(VfxU8 month)
    {
        m_month = month;
    }

    VfxU8 getMonth() const
    {
        return m_month;
    }

    void setDay(VfxU8 day)
    {
        m_day = day;
    }

    VfxU8 getDay() const
    {
        return m_day;
    }

    VfxBool checkBday()
    {
        if (m_year >= MMI_PHB_BDAY_MIN_YEAR_INT && m_year <= MMI_PHB_BDAY_MAX_YEAR_INT
            && m_month > 0 && m_month <= 12 && m_day > 0 && m_day <= 31)
        {
            return VFX_TRUE;
        }

        return VFX_FALSE;
    }

    VfxWString getString()
    {
        if (!checkBday())
        {
            return VFX_WSTR_EMPTY;
        }

        VfxDateTime data;
        data.setDate(m_year, m_month, m_day);

        VfxWChar dataStr[15];
        data.getDateTimeString(
            VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY,
            dataStr,
            15);

        return VFX_WSTR_MEM(dataStr);
    }

private:
    VfxU16 m_year;
    VfxU8 m_month;
    VfxU8 m_day;
};
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

/***************************************************************************** 
 * Class VappContactRes
 *****************************************************************************/ 
class VappContactRes: public VappContactFieldBase
{
public:
    VappContactRes()
        : m_path(), m_resId(0)
    {}

    VappContactRes(const VfxWChar* path, VfxU16 resId, VfxU32 type)
        : VappContactFieldBase(VFX_WSTR_EMPTY, type), m_path(VFX_WSTR_MEM(path)), m_resId(resId)
    {}

    VappContactRes(const VfxWChar* path, VfxU16 resId, const VfxWString &label, VfxU32 type)
        : VappContactFieldBase(label, type), m_path(VFX_WSTR_MEM(path)), m_resId(resId)
    {}

    VappContactRes(const VappContactRes& res)
        : VappContactFieldBase(res)
    {
        m_path = res.getPath();
        m_resId = res.getResId();
    }

    VappContactRes& operator= (const VappContactRes& res)
    {
        VappContactFieldBase::operator=(res);

        m_path = res.getPath();
        m_resId = res.getResId();

        return *this;
    }

    void setPath(const VfxWString &path)
    {
        m_path = path;
    }

    VfxWString getPath() const
    {
        return m_path;
    }

    void setResId(VfxU16 resId)
    {
        m_resId = resId;
    }

    VfxU16 getResId() const
    {
        return m_resId;
    }

    VfxWString getString()
    {
        if (getType() == MMI_PHB_CONTACT_FIELD_RING)
        {
            if (m_resId == 0 && m_path.isEmpty())
            {
                return VFX_WSTR_RES(VAPP_PHB_STR_DEFAULT);
            }
            else if (!m_path.isEmpty())
            {
                return VFX_WSTR_MEM(srv_fmgr_path_get_filename_const_ptr(m_path.getBuf()));
            }
            else
            {
                VfxU16 offset;
                srv_prof_audio_resource_type_enum type = srv_prof_get_audio_info_from_audio_resourece(m_resId, &offset);
                if (type == SRV_PROF_AUDIO_RES_NONE)
                {
                    return VFX_WSTR_RES(VAPP_PHB_STR_DEFAULT);
                }
                else
                {
                    return VFX_WSTR_RES(srv_prof_get_string_id_from_audio_resourece(type, offset));
                }
            }
        }
        return VFX_WSTR_EMPTY;
    }

    VfxImageSrc getImageSrc()
    {
        if (getType() == MMI_PHB_CONTACT_FIELD_IMAGE)
        {
            if (!m_path.isEmpty())
            {
                return VfxImageSrc(m_path);
            }
            else if (m_resId != 0 && m_resId != IMG_PHB_DEFAULT)
            {
                return VfxImageSrc(m_resId);
            }
        }

        return VfxImageSrc();
    }

private:
    VfxWString m_path;
    VfxU16 m_resId;
};


/*
 * Notice: the object in the vector must be inherit from VfxBase directly
 */
/***************************************************************************** 
 * Class ContactStack
 *****************************************************************************/
template <class _contact_stack_base>
class ContactStack: public VfxObject
{
public:
    class Element: public VfxBase
    {
    public:
        _contact_stack_base m_element;
    };

    typedef Element* ElementPtr;

public:
    ContactStack():
        m_elementArray(NULL),
        m_size(0),
        m_top(0){}

    ContactStack(VfxU32 size):
        m_elementArray(NULL),
        m_size(size),
        m_top(0){}

    const _contact_stack_base& operator[] (VfxU32 index) const
    {
        VFX_ASSERT(index < m_size);

        return m_elementArray[index]->m_element;
    }

    // set size
    void setSize(VfxU32 size)
    {
        freeStack();

        m_size = size;

        buildStack();
    }

    // get size
    VfxU32 getSize() const
    {
        return m_size;
    }

    // get count
    VfxU32 getCount() const
    {
        return m_top;
    }

    void pushValue(const _contact_stack_base& base)
    {
        VFX_ASSERT(m_top < m_size);

        m_elementArray[m_top++]->m_element = base;
    }

    _contact_stack_base& popValue()
    {
        VFX_ASSERT(m_top > 0);

        return m_elementArray[--m_top]->m_element;
    }

    _contact_stack_base& getValue(VfxU32 index)
    {
        VFX_ASSERT(index < m_size);

        return m_elementArray[index]->m_element;
    }

    void setValue(const _contact_stack_base& base, VfxU32 index)
    {
        VFX_ASSERT(index < m_size);

        if (index >= m_top)
        {
            pushValue(base);
        }
        else
        {
            m_elementArray[index]->m_element = base;
        }
    }

    void insertValue(const _contact_stack_base& base, VfxU32 index)
    {
        VFX_ASSERT(index < m_size);

        if (index < m_top)
        {
            VFX_ASSERT(m_top < m_size);

            VfxU32 i = m_top - 1;

            while (i >= index)
            {
                m_elementArray[i + 1]->m_element = m_elementArray[i]->m_element;
                i--;
            }
        }

        m_elementArray[index]->m_element = base;
        m_top++;

        setValue(base, index);
    }

    void removeValue(VfxU32 index)
    {
        VFX_ASSERT(index < m_size);
        VFX_ASSERT(index < m_top);
        VFX_ASSERT(m_top > 0);

        m_top--;

        while (index < m_top)
        {
            m_elementArray[index]->m_element = m_elementArray[index + 1]->m_element;
            index++;
        }
    }

    VfxS32 find(const _contact_stack_base& base)
    {
        VfxU32 i;

        for (i = 0; i < m_top; i++)
        {
            if (m_elementArray[i]->m_element == base)
            {
                return i;
            }
        }

        return -1;
    }

    void reset()
    {
        m_top = 0;
    }

protected:
    virtual void onInit()
    {
        VfxObject::onInit();

        buildStack();
    }

    virtual void onDeinit()
    {
        freeStack();

        VfxObject::onDeinit();
    }

private:
    void buildStack()
    {
        if (m_size == 0)
        {
            return;
        }

        VFX_ALLOC_MEM(m_elementArray, sizeof(ElementPtr) * m_size, this);

        for (VfxU32 i = 0; i < m_size; i++)
        {
            VFX_ALLOC_NEW(m_elementArray[i], Element, this);
        }
    }

    void freeStack()
    {
        if (m_size == 0)
        {
            return;
        }

        for (VfxU32 i = 0; i < m_size; i++)
        {
            VFX_DELETE(m_elementArray[i]);
        }

        VFX_FREE_MEM(m_elementArray);
    }

private:
    ElementPtr *m_elementArray;
    VfxU32      m_size;
    VfxU32      m_top;
};


/***************************************************************************** 
 * Class VappContactStackList
 *****************************************************************************/
template <class _contact_list_base>
class VappContactStackList: public VfxObject
{
public:
    class Element: public VfxBase
    {
    public:
        _contact_list_base* m_element;
        Element *m_next;
        Element *m_prev;
    };

public:
    VappContactStackList():
        m_head(NULL),
        m_tail(0),
        m_top(0)
    {}

    // get count
    VfxU32 getCount() const
    {
        return m_top;
    }

    const _contact_list_base& operator[] (VfxU32 index) const
    {
        VFX_ASSERT(index < m_top);

        Element *element = m_head;

        while (index > 0)
        {
            element = element->m_next;
            index--;
        }

        _contact_list_base *base = element->m_element;

        return *base;
    }

    void pushValue(_contact_list_base* base)
    {
        Element* node;
        VFX_ALLOC_MEM(node, sizeof(Element), this);

        node->m_element = base;
        node->m_prev = m_tail;
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

        m_top++;
    }

    _contact_list_base* popValue()
    {
        VFX_ASSERT(m_top > 0);

        Element* node = m_tail;
        m_tail = node->m_prev;

        m_top--;

        if (m_top == 0)
        {
            m_head = NULL;
        }

        _contact_list_base *value = node->m_element;

        VFX_FREE_MEM(node);

        return value;
    }

    void insertValue(_contact_list_base* base, VfxU32 index)
    {
        Element* node;
        VFX_ALLOC_MEM(node, sizeof(Element), this);

        node->m_element = base;
        node->m_prev = NULL;
        node->m_next = NULL;

        if (m_head == NULL)
        {
            m_head = node;
            m_tail = node;
        }
        else if (index >= m_top)
        {
            m_tail->m_next = node;
            node->m_prev = m_tail;
            m_tail = node;
        }
        else
        {
            Element *temp1 = m_head;
            VfxU32 i = 0;

            while (i < index)
            {
                
                temp1 = temp1->m_next;
                i++;
            }

            Element *temp2 = temp1->m_prev;

            temp1->m_prev = node;
            node->m_next = temp1;
            node->m_prev = temp2;
            temp2->m_next = node;
        }

        m_top++;
    }

    _contact_list_base* removeValue(VfxU32 index)
    {
        VFX_ASSERT(index < m_top);
        VFX_ASSERT(m_top > 0);

        Element *node = m_head;
        VfxU32 i = 0;

        while (i < index)
        {
            node = node->m_next;
            i++;
        }

        return clearNode(node);
    }

    _contact_list_base* clearNode(Element* node)
    {
        VFX_ASSERT(node != NULL);

        if (node->m_prev)
        {
            node->m_prev->m_next = node->m_next;
        }
        else
        {
            m_head = node->m_next;
        }

        if (node->m_next)
        {
            node->m_next->m_prev = node->m_prev;
        }
        else
        {
            m_tail = node->m_prev;
        }

        m_top--;

        _contact_list_base *element = node->m_element;

        VFX_FREE_MEM(node);

        return element;
    }

    Element* getHead()
    {
        return m_head;
    }

    Element* getTail()
    {
        return m_tail;
    }

    Element* getNext(Element* node)
    {
        return (node ? node->m_next : NULL);
    }

protected:
    virtual void onDeinit()
    {
        VFX_ASSERT(m_top == 0);

        VfxObject::onDeinit();
    }

private:
    Element *m_head;
    Element *m_tail;
    VfxU32   m_top;
};

typedef VappContactStackList<VappContactFieldBase> VappContactFieldStack;
typedef VappContactFieldStack::Element   VappContactFieldStackNode;


/***************************************************************************** 
 * Class VappContactFieldList
 *****************************************************************************/ 
template <class _contact_field_base>
class VappContactFieldList: public VfxObject
{
public:
    VappContactFieldList()
        : m_stack(NULL)
    {}

    VfxU32 getCount()
    {
        return m_stack->getCount();
    }

    void pushValue(const _contact_field_base& base)
    {
        VappContactFieldBase *value = buildValue(base);

        m_stack->pushValue(value);
    }

    _contact_field_base* popValue()
    {
        return m_stack->popValue();
    }

    _contact_field_base& getValue(VfxU32 index)
    {
        VFX_ASSERT(index < getCount());

        VappContactFieldStackNode *node = m_stack->getHead();
        VfxU32 i = 0;

        while (i < index)
        {
            node = node->m_next;
            i++;
        }

        return *((_contact_field_base*) node->m_element);
    }

    void setValue(const _contact_field_base& base, VfxU32 index)
    {
        if (index >= getCount())
        {
            pushValue(base);
        }
        else
        {
            VappContactFieldStackNode *node = m_stack->getHead();
            VfxU32 i = 0;

            while (i < index)
            {
                i++;
                node = node->m_next;
            }

            if (node == NULL)
            {
                pushValue(base);
            }
            else
            {
                VappContactFieldBase *temp = node->m_element;
                node->m_element = buildValue(base);
                VFX_DELETE(temp);
            }
        }
    }

    void insertValue(const _contact_field_base& base, VfxU32 index)
    {
        VappContactFieldBase *value = buildValue(base);

        m_stack->insertValue(value, index);
    }

    void clear(VfxU32 index)
    {
        VappContactFieldBase *base = m_stack->removeValue(index);

        VFX_DELETE(base);
    }

    void reset()
    {
        VfxU32 count = m_stack->getCount();

        for (VfxU32 i = 0; i < count; i++)
        {
            VappContactFieldBase *base = m_stack->popValue();

            VFX_DELETE(base);
        }
    }

protected:
    virtual void onInit()
    {
        VfxObject::onInit();

        VFX_OBJ_CREATE(m_stack, VappContactFieldStack, this);
    }

    virtual void onDeinit()
    {
        reset();
        VFX_OBJ_CLOSE(m_stack);

        VfxObject::onDeinit();
    }

private:
    VappContactFieldBase* buildValue(const _contact_field_base& base)
    {
        _contact_field_base *value;
        VFX_ALLOC_NEW(value, _contact_field_base, this);

        *value = base;

        return value;
    }

private:
    VappContactFieldStack *m_stack;
};

typedef VappContactFieldList<VappContactNumber> ContactNumberStack;
typedef VappContactFieldList<VappContactEmail> ContactEmailStack;


/***************************************************************************** 
 * Class Contact
 *****************************************************************************/ 
class Contact: public VfxObject
{
public:
    // default constructor
    Contact();

    // contact type
    Contact(vapp_contact_type_enum type);

    // contact id
    Contact(mmi_phb_contact_id id);

    // get contact type
    vapp_contact_type_enum getType();

    // get contact id
    mmi_phb_contact_id getId() const;

    // get ability
    VfxU32 getAbility();

    // set storage
    void setStorage(phb_storage_enum storage);

    // get storage
    phb_storage_enum getStorage();

    // set name
    void setName(const VappContactName& name);

    // get name
    VappContactName& getName();

#ifdef __MMI_PHB_USIM_SUPPORT__
    // set nickname
    void setNickname(const VappContactNickname &nickname);

    // get nickname
    VappContactNickname& getNickname();
#endif /* __MMI_PHB_USIM_SUPPORT__ */

    // reset number
    void resetNumber();

    // get number count
    VfxU32 getNumberCount();

    // get max count
    VfxU32 getNumberMaxCount();

    // set number
    void setNumber(const VappContactNumber& number, VfxU32 index = 0);

    // get number
    VappContactNumber& getNumber(VfxU32 index);

    // remove number
    void removeNumber(VfxU32 index);

    // reset email
    void resetEmail();

    // get email count
    VfxU32 getEmailCount();

    // get email max count
    VfxU32 getEmailMaxCount();

    // set email
    void setEmail(const VappContactEmail& email, VfxU32 index = 0);

    // get email
    VappContactEmail& getEmail(VfxU32 index);

    // remove email
    void removeEmail(VfxU32 index);

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    // set company
    void setCompany(const VappContactCompany &company);

    // get company
    VappContactCompany& getCompany();
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */

#ifdef __MMI_PHB_INFO_FIELD__
    // set title
    void setTitle(const VappContactTitle &title);

    // get title
    VappContactTitle& getTitle();

    // set note
    void setNote(const VappContactNote& note);

    // get note
    VappContactNote& getNote();

    // set address
    void setAddress(const VappContactAddress& address);

    // get address
    VappContactAddress& getAddress();
#endif /* __MMI_PHB_INFO_FIELD__ */

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    // set bday
    void setBday(const VappContactBday& bday);
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    // get bday
    VappContactBday& getBday();
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */
    // set ring tone
    void setRingTone(const VappContactRes& ring);

    // get ring tone
    VappContactRes& getRingTone();

    // set image
    void setImage(const VappContactRes& img);

    // get image
    VappContactRes& getImage();
#ifdef __MMI_PHB_CALLER_GROUP__
    void setGroupId(VfxU8 groupId);

    VfxU32 getGroupId() const;

    VfxWString getGroupName();
#endif /* MMI_PHB_CALLER_GROUP__  */
    VfxBool getLabelSupport();

    void read();

public:
    void buildSrvContact(srv_phb_contact handle, VfxBool isNew);
#ifdef __MMI_PHB_MYCARD__
    void buildMycard(mmi_phb_my_number_struct *myNumber);
#endif /* __MMI_PHB_MYCARD__ */

protected:
    virtual void onInit();

private:
    void readContact();
#ifdef __MMI_PHB_MYCARD__
    void readMycard();
#endif /* __MMI_PHB_MYCARD__ */
private:
    VappContactName         m_name;
#ifdef __MMI_PHB_USIM_SUPPORT__
    VappContactNickname     m_nickname;
#endif
    ContactNumberStack     *m_number;
    ContactEmailStack      *m_email;
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    VappContactCompany      m_company;
#endif
#ifdef __MMI_PHB_INFO_FIELD__
    VappContactTitle        m_title;
    VappContactNote         m_note;
    VappContactAddress      m_address;
#endif /* __MMI_PHB_INFO_FIELD__ */
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    VappContactBday         m_bday;
#endif 
    VappContactRes          m_ring;
    VappContactRes          m_image;
    vapp_contact_type_enum  m_type;
    mmi_phb_contact_id      m_id;
    phb_storage_enum        m_storage;
    VfxU8                   m_groupId;
};


/***************************************************************************** 
 * Class ContactEntry
 *****************************************************************************/ 
class ContactEntry: public VfxBase
{
public:
    ContactEntry(mmi_phb_contact_id id);

    virtual ~ContactEntry();

public:
    // get contact id
    mmi_phb_contact_id getId() const;

    // get field
    VfxU32 getFieldMask();

    // get name
    VappContactName getName();

#ifdef __MMI_PHB_USIM_SUPPORT__
    // get nickname
    VappContactNickname getNickname();
#endif

    // get number count
    VfxU32 getNumberCount();

    // get number: return number count, should call before getNextNumber
    VfxU32 getNumber();

    // get next number, must call getNumber first
    VappContactNumber getNextNumber();

    // get number by id
    VappContactNumber getNumberById(mmi_phb_sub_id id);

    // get email count
    VfxU32 getEmailCount();

    // get email: return email count, should call before getNextEmail
    VfxU32 getEmail();

    // get next email address, must call getEmail first
    VappContactEmail getNextEmail();

    // get email by id
    VappContactEmail getEmailById(mmi_phb_sub_id id);

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    // get company
    VappContactCompany getCompany();
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */

#ifdef __MMI_PHB_INFO_FIELD__
    // get title
    VappContactTitle getTitle();

    // get note
    VappContactNote getNote();

    // get address
    VappContactAddress getAddress();
#endif /* __MMI_PHB_INFO_FIELD__ */

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    // get bday    
    VappContactBday getBday();
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

    // get ring tone
    VappContactRes getRingTone();

    // get image
    VappContactRes getImage();

    // get storage
    phb_storage_enum getStorage();

    // get prefer SIM, VFX_TRUE for call, VFX_FALSE for message
    mmi_sim_enum getPreferSim(mmi_phb_sub_id id, VfxBool call = VFX_TRUE);

public:
    static VfxBool isValid(mmi_phb_contact_id id);

private:
    void createHandle();

    void closeHandle();

    VfxBool isValid();

    // default constructor
    ContactEntry(){};

private:
    mmi_phb_contact_id      m_id;
    srv_phb_contact         m_contact;
    srv_phb_field_filter    m_filter;
    srv_phb_iterator        m_numLooper;
    srv_phb_iterator        m_emailLooper;
};


/***************************************************************************** 
 * Class ContactFieldType
 *****************************************************************************/ 
class ContactFieldType: public VfxObject
{
public:
    ContactFieldType(mmi_phb_contact_field_id_enum field, phb_storage_enum storage);

    VfxU32 getDefaultTypeCount();

    VfxU32 getCustomTypeCount();

    VfxU32 getTotalCustomTypeCount();

    VfxU32 getDefaultType(VfxU32 index);

    VfxU32 getCustomType(VfxU32 index);

    VfxWString getLabel(VfxU32 type);

#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    VfxS32 addType(VfxWChar* label);

    VfxBool deleteType(VfxU32 type);
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */

    mmi_phb_contact_field_id_enum getFieldType();

protected:
    virtual void onInit();

private:
    ContactFieldType(){}

private:
    mmi_phb_contact_field_id_enum m_field;
    phb_storage_enum m_storage;
    VfxU8 m_typeArray[MMI_PHB_FIELD_LABEL_COUNT + 4];
    VfxU8 m_typeCount;
};

#define VAPP_PHB_CUSTOM_LABEL_LENGTH (10)


/***************************************************************************** 
 * Class VappContactFieldObjList
 *****************************************************************************/ 
class VappContactFieldObjList: public VfxObject
{
public:
    class FieldNode
    {
    public:
        VappContactFieldBase *m_field;
        FieldNode *m_next;
    };

public:
    VappContactFieldObjList();

    void setField(const VfxWChar* data, VfxU32 length, VfxU32 id, VfxU32 type);

    FieldNode* getHead();

    FieldNode* getTail();

    VfxU32 getCount() const;

protected:
    virtual void onDeinit();

private:
    FieldNode *m_head;
    FieldNode *m_tail;
    VfxU32 m_count;
};

#endif /* __CONTACT_ENTRY_H__ */

