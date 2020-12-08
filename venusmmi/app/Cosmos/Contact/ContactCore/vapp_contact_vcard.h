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
 *  vapp_contact_vcard.h
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

#ifndef __CONTACT_VCARD_H__
#define __CONTACT_VCARD_H__

#ifdef __MMI_VCARD__

#include "vfx_uc_include.h"
#include "vcp_include.h"

#include "vapp_contact_entry.h"
#include "vapp_contact_op.h"
#include "vapp_phb_gprot.h"


#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"
#include "vcard_lib.h"
#include "FileMgrSrvGprot.h"

#ifdef __cplusplus
}
#endif

#define VCARD_DRV                  SRV_FMGR_PRIVATE_DRV
#define VCARD_DEFAULT_NAME         "~vcard.vcf"
#define VCARD_FILE_EXT             ".vcf"
#define VCARD_TEMP_FILE_FILTER     "%c:\\%s\\*.vcf"
#define VCARD_FOLDER_NAME          "_vCard"

/*----------------------------------------------------------------*/
/* VappContactvCard                                               */
/*----------------------------------------------------------------*/
class VappContactvCard: public VfxObject
{
public:
    VappContactvCard();

    VappContactvCard(Contact *contact);

    VappContactvCard(mmi_phb_contact_id id);

    VfxWChar* getFile(VfxS32 *result);

    void clearTempvCardFile();

    VfxS32 buildFileName();

protected:
    virtual void onDeinit();

private:
    void buildVcard(vcard_object_struct *vcard);

private:
    Contact *m_contact;
    mmi_phb_contact_id m_id;
    VfxWChar* m_path;
};


//#ifdef __MMI_VCARD__
/*----------------------------------------------------------------*/
/* ContactVcardViewerData                                         */
/*----------------------------------------------------------------*/
class ContactVcardViewerData : public VfxObject
{
public:
    VfxSignal0 m_signalPassDone;

public:
    ContactVcardViewerData();
    ContactVcardViewerData(VfxWString path);

#ifdef __MMI_MULTI_VCARD__
    static void vcard_parser_callback(
                kal_int32 error_code,
                kal_int32 object_count,
                kal_int32 *object_offset,
                void *user_data);
#endif
    virtual void onInit();
    virtual void onDeinit();

    VfxU16 queryCount(VappVcardFieldEnum);
    VfxWString &getName();
    VfxImageSrc &getImage();
    VfxBool checkNumberValid(VfxU16 index);
    VfxWString &getNumberLabel(VfxU16 index);
    VfxWString &getNumber(VfxU16 index);
    VfxBool checkEmailValid(VfxU16 index);
    VfxWString &getEmailLabel(VfxU16 index);
    VfxWString &getEmail(VfxU16 index);
#ifdef __MMI_PHB_INFO_FIELD__
    VfxBool addressIsValid(VfxU32 index);
    VfxBool checkAddressValid(VfxU16 index, VappVcardAddressFieldEnum sub_index);
    VfxWString &getAddressTitle(VfxU16 index, VappVcardAddressFieldEnum sub_index);
    VfxWString &getAddress(VfxU16 index, VappVcardAddressFieldEnum sub_index);
#endif /* __MMI_PHB_INFO_FIELD__ */
    VfxWString &getBirthday();
#ifdef __MMI_PHB_INFO_FIELD__
    VfxWString &getTitle();
#endif
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    VfxWString &getCompany();
#endif
#ifdef __MMI_PHB_INFO_FIELD__
    VfxWString &getNote();
#endif
#ifdef __MMI_MULTI_VCARD__
    void getFront();
    void getNext();
#endif
    void setPath(const VfxWString &path);

    VfxU32 getTotalCount(){ return m_totalCount; }
    VfxU32 getActiveCount(){ return m_activeCount; }
    VfxBool isSingleVcard(){ return m_isSingleVcard; }

private:
    VfxU32               m_offset[MMI_PHB_PHONE_ENTRIES];
    vcard_object_struct *m_vcard;
    VfxU32               m_totalCount;
    VfxU32               m_activeCount;
    VfxWString           m_path;
    VfxU16               m_name[MMI_PHB_NAME_LENGTH + 1];
    VfxU16               m_birthday[8 + 1];
    VfxWString           m_valueReturn;
    VP_HANDLE            m_handle;
    VP_HANDLE            m_countHandle;
    VfxImageSrc          m_imageScr;
    VfxBool              m_isSingleVcard;

private:
    VfxU16 getNameCount();
    VfxU16 getNumberCount();
    VfxU16 getEmailCount();
#ifdef __MMI_PHB_INFO_FIELD__
    VfxU16 getAddressCount();
#endif
    VfxU16 getBirthdayCount();
#ifdef __MMI_PHB_INFO_FIELD__
    VfxU16 getTitleCount();
#endif
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    VfxU16 getCompanyCount();
#endif
#ifdef __MMI_PHB_INFO_FIELD__
    VfxU16 getNoteCount();
#endif
};

//#endif /* __MMI_MULTI_VCARD__ */

#endif /* __MMI_VCARD__ */

#endif /*__CONTACT_VCARD_H__ */

