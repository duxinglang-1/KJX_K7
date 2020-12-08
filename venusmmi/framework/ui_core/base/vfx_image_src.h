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
 *  vfx_image_src.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus Image Source types
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_IMAGE_SRC_H__
#define __VFX_IMAGE_SRC_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxSize
#include "vfx_basic_type.h"
// For VfxWString
#include "vfx_string.h"

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"

#include "vrt_datatype.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// Represents a Null type of VfxImageSrc
#define VFX_IMAGE_SRC_NULL              VfxImageSrc()


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Image source type
enum VfxImageSrcTypeEnum
{
    VFX_IMAGE_SRC_TYPE_NULL = 0,        // Null image
    VFX_IMAGE_SRC_TYPE_RES_ID,          // Image from resource ID (Only for VfxImageSrc)
    VFX_IMAGE_SRC_TYPE_MEM,             // Image from a memory pointer with image resource 8-bytes header
    VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER,    // Image from image buffer (Only for VfxImageSrc)
    VFX_IMAGE_SRC_TYPE_PATH,            // Image from file path
    VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA,   // Image file raw data in memory
    VFX_IMAGE_SRC_TYPE_MRE_RES_ID,      // Image from MRE resource ID

    VFX_IMAGE_SRC_TYPE_END_OF_ENUM    
};


/***************************************************************************** 
 * Class VfxImageBuffer
 *****************************************************************************/

/*
 * VfxImageBuffer is a structure descripts an image buffer.
 */
class VfxImageBuffer : public VfxBase
{
// Variable
public:
    // Pointer to the image buffer.
    VfxU8  *ptr;
    // Memory address difference of two lines
    VfxU32  pitchBytes;
    // Width of the image buffer, in pixel.
    VfxU32  width;
    // Height of the image buffer, in pixel.
    VfxU32  height;
    // The color format of the image buffer.
    //
    // SEE ALSO: VfxColorTypeEnum
    VfxColorTypeEnum colorFormat;

// Constructor    
public:
    // Default constructor
    VfxImageBuffer() 
    {
    }

    // Copy constructor
    VfxImageBuffer(const VfxImageBuffer &other) 
    {
        assignWith(other);
    }
    
    // Constructor with vrt_image_buffer_struct
    VfxImageBuffer(const vrt_image_buffer_struct &other);

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Constructor with vm_image_buffer_struct
    VfxImageBuffer(const vm_image_buffer_struct &other);
#endif

    // Internal used. Init vrt_image_buffer_struct with VfxImageBuffer
    void initVrtImageBuffer(vrt_image_buffer_struct &vrt_image_buffer) const;

// Operator
public:
    // Assign operator
    VfxImageBuffer &operator =(const VfxImageBuffer &other)
    {
        assignWith(other);
        return *this;
    }

    // Compare operator
    VfxBool operator ==(const VfxImageBuffer &other) const
    {
        return compareWith(other);
    }

    // Compare operator
    VfxBool operator !=(const VfxImageBuffer &other) const
    {
        return !compareWith(other);
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    operator vm_image_buffer_struct() const;
#endif

// Methods
public:
    // Return the image buffer size
    VfxSize getSize() const
    {
        return VfxSize(width, height);
    }

private:
    void assignWith(const VfxImageBuffer &other);
    VfxBool compareWith(const VfxImageBuffer &other) const;
};


/***************************************************************************** 
 * Class VfxImageBuffer
 *****************************************************************************/

/*
 * VfxImageBuffer is a structure descripts an image buffer.
 */
class VfxFileRawData : public VfxBase
{
// Variable
public:
    // Pointer to the image buffer.
    VfxU8  *ptr;
    //Image Memory size
    VfxU32  imageSize;
    // Image format
    VfxFileRawDataFormatEnum imageFormat;

// Constructor    
public:
    // Default constructor
    VfxFileRawData() 
    {
    }

    VfxFileRawData(VfxU8 *_ptr, VfxU32 _imageSize, VfxFileRawDataFormatEnum _imageFormat) :
        ptr(_ptr),
        imageSize(_imageSize),
        imageFormat(_imageFormat)
    {
    }
        
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Constructor with vm_file_raw_data_format_enum
    VfxFileRawData(const vm_file_raw_data_struct &other);
#endif

    VfxFileRawData(const VfxFileRawData &other) 
    {
        assignWith(other);
    }

    void initVrtImageBuffer(vrt_file_raw_data_buffer_struct &vrt_image_buffer) const;

// Operator
public:
    // Compare operator
    VfxBool operator ==(const VfxFileRawData &other) const
    {
        return compareWith(other);
    }

    // Compare operator
    VfxBool operator !=(const VfxFileRawData &other) const
    {
        return !compareWith(other);
    }
    
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    operator vm_file_raw_data_struct() const;   
#endif	

private:
    void assignWith(const VfxFileRawData &other);
    VfxBool compareWith(const VfxFileRawData &other) const;
};


/***************************************************************************** 
 * Class VfxImageSrc
 *****************************************************************************/

/*
 * VfxImageSrc descripts a image source
 *
 * NOTE: 
 *  VfxImageSrc supports image from resource, image buffer and file.
 */
class VfxImageSrc : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    //
    // NOTES: The defualt image source type is null image
    VfxImageSrc() : m_type(VFX_IMAGE_SRC_TYPE_NULL)
    {
    }
    
    // Construct with a resource ID
    explicit VfxImageSrc(VfxResId resId) : m_type(VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        initWithResId(resId);
    }

    // Construct with a resource ID
    explicit VfxImageSrc(const VfxU8 *mem) : m_type(VFX_IMAGE_SRC_TYPE_MEM)
    {
        initWithMem(mem);
    }

    // Construct with a image buffer
    explicit VfxImageSrc(const VfxImageBuffer &imgBuf) : m_type(VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER)
    {
        initWithImageBuffer(imgBuf);
    }

    // Construct with a path
    explicit VfxImageSrc(const VfxWString &path) : m_type(VFX_IMAGE_SRC_TYPE_PATH)
    {
        initWithPath(path);
    }
    
    // Construct with a file raw data in memory
    explicit VfxImageSrc(const VfxFileRawData &imgBuf) : m_type(VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA)
    {
        initWithFileRawData(imgBuf);
    }

    // Construct with a file raw data in memory
    explicit VfxImageSrc(VfxU8 *mem, VfxU32 imageSize, VfxFileRawDataFormatEnum imageFormat = VFX_FILE_FORMAT_TYPE_AUTO) : m_type(VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA)
    {
        initWithFileRawData(VfxFileRawData(mem, imageSize, imageFormat));
    }
    
    // Copy constructor
    VfxImageSrc(const VfxImageSrc &other) : m_type(other.m_type)
    {
        initWith(other);
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Constructor
    VfxImageSrc(const vm_image_source_struct &other);
#endif

    // Destructor
    ~VfxImageSrc()
    {
        deinit();
    }

// Operator
public:
    // Assigned with another image source.
    //
    // RETURNS: Reference to the image source.
    VfxImageSrc &operator = (const VfxImageSrc &other);
    
    // Compared with another image source
    //
    // RETURNS: Return VFX_TRUE the image source is equal to the input.    
    VfxBool operator == (const VfxImageSrc &other) const
    {
        return compareWith(other);
    }
    
    // Compared with another image source.
    //
    // RETURNS: Return VFX_TRUE the image source is *NOT* equal to the input.
    VfxBool operator != (const VfxImageSrc &other) const
    {
        return !compareWith(other);
    }    

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    operator vm_image_source_struct() const;
#endif

// Method
public:
    // Return the source type of the image
    //
    // RETURNS: The source type of the image
    VfxImageSrcTypeEnum getType() const
    {
        return m_type;
    }

    // Check if the image is a null image.
    //
    // RETURNS: Return VFX_TRUE if this is a null image.
    VfxBool isNull() const
    {
        return m_type == VFX_IMAGE_SRC_TYPE_NULL;
    }

    //  Set the image to be a null image
    void setNull()
    {
        deinit();
    }

    // Return the resource ID of the image source.
    //
    // RETURNS: The resource ID of the image source.
    VfxResId getResId() const
    {
        return m_type == VFX_IMAGE_SRC_TYPE_RES_ID ?
            m_value.resIdValue : VFX_RES_ID_NULL;
    }

    // Return the memory pointer with image resource 8-bytes header
    //
    // RETURNS: The memory pointer
    //  Assert if the image source type is not VFX_IMAGE_SRC_TYPE_MEM.
    const VfxU8 *getMem() const
    {
        VFX_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_MEM);
        return m_value.memValue;
    }
    

    // Return the image buffer of the image source.
    //
    // RETURNS: The image buffer of the image source.
    //  Assert if the image source type is not VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER.
    const VfxImageBuffer &getImageBuffer() const
    {
        VFX_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER);
        VFX_DEV_ASSERT(m_value.imgBufPtr != NULL);
        return *m_value.imgBufPtr;
    }

    const VfxFileRawData &getImageRawDataBuffer() const
    {
        VFX_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA);
        VFX_DEV_ASSERT(m_value.fileRawDataPtr != NULL);
        return *m_value.fileRawDataPtr;
    }    

    // Return the path of the image source.
    //
    // RETURNS: The path of the image source.
    //  Assert if the image source type is not VFX_IMAGE_SRC_TYPE_PATH.
    const VfxWString &getPath() const
    {
        VFX_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_PATH);
        VFX_DEV_ASSERT(m_value.fileInfoPtr != NULL);
        return m_value.fileInfoPtr->path;
    }

    // Internal used
    // Return the info of the image source.
    //
    // RETURNS: The info of the image source.
    //  Assert if the image source type is not VFX_IMAGE_SRC_TYPE_PATH.
    const vrt_sys_image_info_struct *getImageFileInfo() const
    {
        VFX_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_PATH);
        VFX_DEV_ASSERT(m_value.fileInfoPtr != NULL);
        return &m_value.fileInfoPtr->imageInfo;
    }
	
    // Set the image source to a given resource ID.
    //
    // NOTE: The type of image source becomes VFX_IMAGE_SRC_TYPE_RES_ID.
    void setResId(
        VfxResId resId
    );

    // Set the image source to a given memory pointer with image resource 8-bytes header
    //
    // NOTE: The type of image source becomes VFX_IMAGE_SRC_TYPE_RES_MEM.
    void setMem(
        const VfxU8 *mem
    );

    // Set the image source to a given image buffer.
    //
    // NOTE: The type of image source becomes VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER.
    void setImageBuffer(
        const VfxImageBuffer &imgBuf
    );

    // Set the image source to a given path.
    //
    // NOTE: The type of image source becomes VFX_IMAGE_SRC_TYPE_PATH.
    void setPath(
        const VfxWString &path
    );
    
    // Return the image size.
    //
    // RETURNS: The size of the image
    const VfxSize &getSize() const
    {
        return m_cachedSize;
    }

    // Check if the image is an empty image.
    //
    // RETURNS: Return VFX_TRUE if this is an empty image or a null image.
    //
    // SEE ALSO: isNull
    VfxBool isEmpty() const
    {
        return m_cachedSize.isEmpty();
    }
    
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Internal used.
    VfxS32 getHandle() const
    {
        VFX_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_MRE_RES_ID);
        return m_value.mreResIdValue.handle;
    }

    // Internal used.
    VfxResId getMreResId() const
    {
        VFX_ASSERT(m_type == VFX_IMAGE_SRC_TYPE_MRE_RES_ID);
        return m_value.mreResIdValue.id;
    }
#endif

    // Internal used.
    //  To invalidate the cached data in this image source.
    void invalidate();

// Implementation
private:
    VfxImageSrcTypeEnum m_type;

    class FileInfo : public VfxBase
    {
    public:
        VfxWString path;
        vrt_sys_image_info_struct imageInfo;
    };

    union
    {
        VfxResId        resIdValue;
        const VfxU8    *memValue;
        VfxImageBuffer *imgBufPtr;
        VfxFileRawData *fileRawDataPtr;
        FileInfo       *fileInfoPtr;
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        struct 
        {
            VfxResId    id;
            VfxS32      handle;
        } mreResIdValue;
#endif
    } m_value;

    // The cached image dimension
    VfxSize m_cachedSize;

// Implementation
private:
    void initWithResId(VfxResId resId);
    void initWithMem(const VfxU8 *mem);
    void initWithImageBuffer(const VfxImageBuffer &imgBuf);
    void initWithPath(const VfxWString &path);
    void initWithFileRawData(const VfxFileRawData &fileRawData);
    void initWith(const VfxImageSrc &other);
    void deinit();
    
    void assignWithResId(VfxResId resId);
    void assignWithMem(const VfxU8 *mem);
    void assignWithImageBuffer(const VfxImageBuffer &imgBuf);
    void assignWithPath(const VfxWString &path);
    void assignWithFileInfo(const FileInfo &path);
    void assignWithFileRawData(const VfxFileRawData &fileRawData);
    void assignWith(const VfxImageSrc &other);
    
    VfxBool compareWith(const VfxImageSrc &other) const;

    void updateCachedSize();
};


/***************************************************************************** 
 * Class VfxImageList
 *****************************************************************************/

class VfxImageList : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    VfxImageList() : 
        m_imgDescArray(NULL), 
        m_imgDescCount(0)
    {
    }

    // Copy constructor
    VfxImageList(const VfxImageList &other);

    // Destructor    
    ~VfxImageList()
    {
        clear();
    }

// Operator
public:
    // Assigned with another image list.
    //
    // RETURNS: Reference to the image list.
    VfxImageList &operator = (const VfxImageList &other)
    {
        assignWith(other);
        return *this;
    }

    // Helper operator. Return the image source with the given key.
    //
    // SEE ALSO: getItem
    //
    // RETURNS: The image list with the given key. 
    //  Return null image source if the key is not exist.
    const VfxImageSrc &operator [] (
        VfxId key   // [IN] The given key to find
    ) const
    {
        return getItem(key);
    }

// Method
public:
    // Return number of image source in the image list
    //
    // RETURNS: Number of image source in the image list
    VfxU32 getCount() const
    {
        return m_imgDescCount;
    }

    // Check if the image list is empty.
    //
    // RETURNS: Return VFX_TRUE if this is an empty image list.
    VfxBool isEmpty() const
    {
        return m_imgDescArray == NULL;
    }

    // Not support yet
    //void loadFromResId(VfxResId resId);

    // Add a image source to the image list.
    void setItem(
        VfxId key,                      // [IN] The key to add
        const VfxImageSrc &imgSrc       // [IN] The image source to add
    );
    
    // Helper method. 
    //  Add a image source with resource ID to the image list.
    void setItemWithResId(
        VfxId key,                      // [IN] The key to add 
        VfxResId resId                  // [IN] The resource ID to add
    )
    {
        setItem(key, VfxImageSrc(resId));
    }
    
    // Helper method. 
    //  Add a image source with image buffer to the image list.
    void setItemWithImageBuffer(
        VfxId key,                      // [IN] The key to add 
        const VfxImageBuffer &imgBuf    // [IN] The image buffer to add
    )
    {
        setItem(key, VfxImageSrc(imgBuf));
    }
        
    // Helper method. 
    //  Add a image source with path to the image list.
    void setItemWithPath(
        VfxId key,                      // [IN] The key to add 
        const VfxWString &path          // [IN] The path to add
    )
    {
        setItem(key, VfxImageSrc(path));
    }
    
    // Return the image source with the given key.
    //
    // RETURNS: The image list with the given key. 
    //  Return null image source if the key is not exist.
    const VfxImageSrc &getItem(VfxId key) const
    {
        return getItemWithIndex(findElement(key));
    }

    // Return the image source with index.
    //
    // RETURNS: The image list with the given key. 
    //  Return null image source if the key is not exist.
    const VfxImageSrc &getItemWithIndex(VfxU32 index) const;

    // Remove the item with given key. 
    //  If the key is not exist, do nothing.
    void removeItem(
        VfxId key                       // [IN] The key to remove
    )
    {
        removeElement(findElement(key));
    }

// Implimentation
private:
    enum
    {
        MIN_IMG_DESC_ARRAY_SIZE = 4
    };

    class ImageDescArrayElement : public VfxBase
    {
    public:
        VfxId   key;
        VfxImageSrc value;
    };

    typedef ImageDescArrayElement *ImageDescArrayElementPtr;

    ImageDescArrayElementPtr *m_imgDescArray;
    VfxU32 m_imgDescCount;


    VfxU32 needArraySize(VfxU32 count)
    {
        return (count + MIN_IMG_DESC_ARRAY_SIZE - 1) / MIN_IMG_DESC_ARRAY_SIZE * MIN_IMG_DESC_ARRAY_SIZE;
    }

    void prepareArray(VfxU32 arraySize);
    
    void createElement(VfxU32 index, VfxId key, const VfxImageSrc &value);
    void assignElement(VfxU32 index, VfxId key, const VfxImageSrc &value);
    void copyElements(ImageDescArrayElementPtr *to, const ImageDescArrayElementPtr *from, VfxU32 count);

    void cloneWithOtherArray(const ImageDescArrayElementPtr *m_imgDescArray, VfxU32 count);
    void assignWithOtherArray(const ImageDescArrayElementPtr *m_imgDescArray, VfxU32 count);
        
    void assignWith(const VfxImageList &other);
    void clear();    

    VfxU32 findElement(VfxId key) const;
    void addElement(VfxId key, const VfxImageSrc &value);
    void removeElement(VfxU32 index);
};


#endif /* __VFX_IMAGE_SRC_H__ */

