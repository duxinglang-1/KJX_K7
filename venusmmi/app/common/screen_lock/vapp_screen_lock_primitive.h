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
 *  vapp_screen_lock_primitive.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the screen lock's primitive class.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_PRIMITIVE_H
#define VAPP_SCREEN_LOCK_PRIMITIVE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_def.h"

/* Pluto MMI headers: */
extern "C"
{
#include "MMIDataType.h"
}


/*****************************************************************************
 * Screen Lock ID Class
 *****************************************************************************/

class VappScreenLockId : public VfxBase
{
// Enum
public:
    // Type kind. Each source of the screen lock can choose its favorite type
    // kind to distinguish its screen lock.
    enum TypeKindEnum
    {
        // Unknown type kind.
        TYPE_KIND_UNKNOWN,

        // Use integer to distinguish different screen locks.
        TYPE_KIND_INTEGER,

        // Use string to distinguish different screen locks.
        TYPE_KIND_STRING,

        // End of enum
        TYPE_KIND_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockId();

    // Construct a ID using the source and integer type.
    VappScreenLockId(
        VappScreenLockSrcEnum source,   // [IN] Source
        VfxS32 type                     // [IN] Type
    );

    // Construct a ID using the source and string type.
    VappScreenLockId(
        VappScreenLockSrcEnum source,   // [IN] Source
        const VfxChar *type             // [IN] Type
    );

    // Copy constructor
    VappScreenLockId(
        const VappScreenLockId &other
    );

    // Default destructor
    ~VappScreenLockId();

// Operator
public:
    // Assign operator
    VappScreenLockId &operator =(
        const VappScreenLockId &other
    );

    // Equal operator
    VfxBool operator ==(
        const VappScreenLockId &other
    ) const;

    // Inequal operator
    VfxBool operator !=(
        const VappScreenLockId &other
    ) const;

// Method
public:
    // This function assigns the screen lock ID from other screen lock ID.
    void assignWith(
        const VappScreenLockId &other   // [IN] Other screen lock ID
    );

    // This fucntion assigns the screen lock ID using the integer type.
    void assignWith(
        VappScreenLockSrcEnum source,   // [IN] Source
        VfxS32 type                     // [IN] Integer type
    );

    // This function assigns the screen lock ID using the string type.
    void assignWith(
        VappScreenLockSrcEnum source,   // [IN] Source
        const VfxChar *type             // [IN] String type
    );

    // This function compares the screen lock ID with other screen lock ID.
    // RETURNS: On the same, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool compareWith(
        const VappScreenLockId &other   // [IN] Other screen lock ID
    ) const;

    // This function gets the screen lock's source.
    // RETURNS: screen lock source.
    VappScreenLockSrcEnum getSource() const;

    // This function gets the type kind used to distinguish different screen
    // lock under this source.
    // RETURNS: type kind.
    TypeKindEnum getTypeKind() const;

    // This function gets the integer type. Note that it will assert if this
    // screen lock ID does not use integer type kind.
    // RETURNS: type using integer.
    VfxS32 getIntType() const;

    // This function gets the string type. Note that it will assert if this
    // screen lock ID does not use string type kind. Also note that this
    // function directly returns the type string stored in this screen lock ID,
    // so please pay attention when you manipulate this type string.
    // RETURNS: type using string.
    const VfxChar *getStringType() const;

// Method
public:
    // This function decodes the screen lock ID from the archive.
    void decodeFromArchive(
        VfxArchive *ar      // [IN] Archive
    );

    // This function encodes the screen lock ID to the archive.
    void encodeToArchive(
        VfxArchive *ar      // [OUT] Archive
    ) const;

// Method
public:
    // This function news a screen lock ID array with the specified size.
    // RETURNS: Widget ID array
    static VappScreenLockId **newArray(
        VfxS32 size,                // [IN] Size of the array
        VfxObject *parent           // [IN] Object parent
    );

    // This function deletes a screen lock ID array.
    static void deleteArray(
        VappScreenLockId **array,   // [IN] Widget ID array
        VfxS32 size                 // [IN] Size of the array
    );

// Variable
private:
    // The source of the screen lock.
    VappScreenLockSrcEnum m_source;

    // Kind of the type.
    TypeKindEnum m_typeKind;

    // The type of the screen lock. Use union for different type kinds.
    union
    {
        // Integer type kind.
        VfxS32 ival;

        // String type kind.
        VfxChar sval[MMI_APP_NAME_MAX_LEN];
    } m_type;

// Implementation
private:
    // This function clears the type value.
    void clear();

    // This function assign the type string.
    void assignTypeString(
        const VfxChar *typeString   // [IN] Type string
    );
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */
#endif /* VAPP_SCREEN_LOCK_PRIMITIVE_H */

