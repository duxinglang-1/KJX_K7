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
 *  vapp_wallpaper_id.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WALLPAPER_ID_H__
#define __VAPP_WALLPAPER_ID_H__

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vapp_wallpaper_def.h"


/*****************************************************************************
 * Screen Lock ID Class
 *****************************************************************************/

class VappWallpaperId : public VfxBase
{
// Enum
public:
    // Type kind. Each source of the screen lock can choose its favorite type
    // kind to distinguish its screen lock.
    enum TypeKindEnum
    {
        // Unknown type kind.
        TYPE_KIND_UNKNOWN,

        // Use integer as ID
        TYPE_KIND_INTEGER,

        // Use string as ID
        TYPE_KIND_STRING,

        // Use 2 INT (e.g. HIWORD, LOWORD) as ID
        TYPE_KIND_INT_PAIR,

        // Use WString file path as ID
        TYPE_KIND_WSTRING,

        // End of enum
        TYPE_KIND_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperId();

    // Construct a ID using the source and integer type.
    VappWallpaperId(
        VappWallpaperFactorySrcEnum source,   // [IN] Source
        VfxS32 type                     // [IN] Type
    );

    // Construct a ID using the source and string type.
    VappWallpaperId(
        VappWallpaperFactorySrcEnum source,   // [IN] Source
        const VfxChar *type             // [IN] Type
    );

    // Copy constructor
    VappWallpaperId(
        const VappWallpaperId &other
    );

    // Default destructor
    ~VappWallpaperId();

// Operator
public:
    // Assign operator
    VappWallpaperId &operator =(
        const VappWallpaperId &other
    );

    // Equal operator
    VfxBool operator ==(
        const VappWallpaperId &other
    ) const;

    // Inequal operator
    VfxBool operator !=(
        const VappWallpaperId &other
    ) const;

// Method
public:
    // This function assigns the screen lock ID from other screen lock ID.
    void assignWith(
        const VappWallpaperId &other   // [IN] Other screen lock ID
    );

    // This fucntion assigns the screen lock ID using the integer type.
    void assignWith(
        VappWallpaperFactorySrcEnum source,   // [IN] Source
        VfxS32 type                     // [IN] Integer type
    );

    // This function assigns the screen lock ID using the string type.
    void assignWith(
        VappWallpaperFactorySrcEnum source,   // [IN] Source
        const VfxChar *type             // [IN] String type
    );

    // This fucntion assigns the screen lock ID using the integer pair type.
    void assignWith(
        VappWallpaperFactorySrcEnum source,     // [IN] Source
        VfxU32 first,                    // [IN] Integer type
        VfxU32 second
    );

    // This fucntion assigns the WString
    void assignWith(
        VappWallpaperFactorySrcEnum source,     // [IN] Source
        const VfxWChar *type                           // [IN] String type
    );

    // This function compares the screen lock ID with other screen lock ID.
    // RETURNS: On the same, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool compareWith(
        const VappWallpaperId &other   // [IN] Other screen lock ID
    ) const;

    // This function gets the screen lock's source.
    // RETURNS: screen lock source.
    VappWallpaperFactorySrcEnum getSource() const;

    // This function gets the type kind used to distinguish different screen
    // lock under this source.
    // RETURNS: type kind.
    TypeKindEnum getTypeKind() const;

    // This function gets the integer type. Note that it will assert if this
    // screen lock ID does not use integer type kind.
    // RETURNS: type using integer.
    VfxS32 getIntType() const;


    // This function gets the integer pair type. Note that it will assert if this
    // screen lock ID does not use integer pair type kind.
    // RETURNS: type using integer.
    void getIntPairType(VfxU32 &first, VfxU32 &second) const;

    // This function gets the string type. Note that it will assert if this
    // screen lock ID does not use string type kind. Also note that this
    // function directly returns the type string stored in this screen lock ID,
    // so please pay attention when you manipulate this type string.
    // RETURNS: type using string.
    const VfxChar *getStringType() const;

    const VfxWChar *getWStringType() const;

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
    static VappWallpaperId **newArray(
        VfxS32 size,                // [IN] Size of the array
        VfxObject *parent           // [IN] Object parent
    );

    // This function deletes a screen lock ID array.
    static void deleteArray(
        VappWallpaperId **array,   // [IN] Widget ID array
        VfxS32 size                 // [IN] Size of the array
    );

// Variable
private:
    // The factory source of the screen lock.
    VappWallpaperFactorySrcEnum m_source;

    // Kind of the type.
    TypeKindEnum m_typeKind;

    struct IntPair
    {
        VfxU32 first;
        VfxU32 second;
    };
    
    // The type of the screen lock. Use union for different type kinds.
    union
    {
        // Integer type kind.
        VfxS32 ival;
        // String type kind.
        VfxChar *sval;
        // IntPair type kind.
        IntPair pval;
        // WString type kind.
        VfxWChar *wsval;
    } m_type;

// Implementation
private:
    // This function clears the type value.
    void clear();

    // This function assign the type string.
    void assignTypeString(
        const VfxChar *typeString   // [IN] Type string
    );

    void assignTypeWString(
        const VfxWChar *typeWString // [IN] Type WString
    );
};

#endif /* __VAPP_WALLPAPER_ID_H__ */

