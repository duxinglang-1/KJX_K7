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
 *  vfx_shelter.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
#ifndef __VFX_SHELTER_H__
#define __VFX_SHELTER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxControl
#include "vfx_control.h"
#include "vfx_screen.h"


class VcpFrameEffect;

#ifdef __COSMOS_3D_V10_SHELTER__

#include "gles2\gl2.h"
#include "gles2\gl2ext.h"
#include "vfx_owner_draw.h"
#include "mmi_rp_v3d_global_shader_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/



#define VERTEX_POS_SIZE 3
#define VERTEX_TEXCOOR_SIZE 2

#define SHRINK_RATIO 2

    


typedef struct
{
    // Handle to a program object
    GLuint programObject;

    GLint uFrameAnchorLoc; 
    GLint uViewPortSizeLoc;
    GLint aPositionLoc;
    GLint aTexCoordLoc;
    GLint uBaseTexLoc;
    GLint uBaseTexSizeLoc;    
    GLint uLevelLoc;  

    GLuint textureId;    
    GLuint frameBuffer;
    GLuint textureBuffer;
    VfxSize textureSize;
    
} UserData_H;

typedef struct
{
    // Handle to a program object
    GLuint programObject;

    GLint uFrameAnchorLoc; 
    GLint uViewPortSizeLoc;
    GLint aPositionLoc;
    GLint aTexCoordLoc;
    GLint uBaseTexLoc;
    GLint uFrameTexLoc;    
    GLint uBaseTexSizeLoc;    
    GLint uLevelLoc;    
    GLint uDarknessLoc;    
        
} UserData_V;



/***************************************************************************** 
 * VfxShelterOwnerDraw
 *****************************************************************************/

class VfxShelterOwnerDraw : public VfxOwnerDraw
{
public:
    VfxShelterOwnerDraw(VfxSize size);

protected:
    virtual vrt_bool isUsingGLAPI() const { return VFX_TRUE; }
    
    virtual void onInitResource();
    virtual void onDeinitResource();
   
    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);  

    void bindStrokeFramebuffer(VfxSize texSize);

public:
    UserData_H m_dataH;
    UserData_V m_dataV;
    VfxSize m_size;
    VfxFloat m_level;
    VfxBool m_forceCopy;
};

#endif /*__COSMOS_3D_V10_SHELTER__*/


/***************************************************************************** 
 * VfxShelter
 *****************************************************************************/

class VfxShelter : public VfxControl
{

public:
    VfxShelter();

public:
	void show(VfxFrame *target, VfxBool isAnim);
	void hide(VfxBool isAnim);
	void exit();
    void processRotate(VfxScreenRotateParam param);
	void onRotateTimerTick(VfxTimer* source);

  
protected:
    virtual void onInit();      

public:
    virtual void setBounds(const VfxRect &value);

    VfxBool m_isHiding;
    VfxTimer* m_rotateTimer;
    VfxBool m_isRotating;


#ifdef __COSMOS_3D_V10_SHELTER__

public:
	void setShelterContent(VfxFrame *content);
	void setIsStatic(VfxBool isStatic);
	

private:
    void updateFrameEffect(VfxMsec duration);    
   	
    typedef struct
    {
        VfxShelterOwnerDraw* ownerdraw;
    } Shelter_data;

    VfxBool m_isStatic;
    VfxFrameWeakPtr m_content;
    VcpFrameEffect *m_frameEffect;


    VfxShelterOwnerDraw *m_ownerDrawV;
    VfxShelterOwnerDraw *m_ownerDrawH;  

    static  vrt_render_dirty_type_enum shelterFrameEffectCallBack(
         vrt_frame_visual_property_struct *target_frame,
         const vrt_frame_visual_property_struct *watch_frame,
         void *user_data,
         vrt_u32 user_data_size);

#endif /*__COSMOS_3D_V10_SHELTER__*/
};

#endif /* __VFX_SHELTER_H__ */

