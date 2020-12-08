/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * Filename: pn2lvn
 * ---------
 *
 * Project:
 * --------
 *  Venus Shader Library
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *  Jimmy Su (mtk02981)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 20 2012 yufei.shen
 * [MAUI_03295699] [COSMOS 6260] Gallery Slim check in
 * .
 *
 * 11 16 2012 paul.deng
 * NULL
 * .
 *
 * 04 15 2012 callia.wong
 * [MAUI_03113849] [COSMOS SLIM] check-in
 * .merge from 11B
 *
 * 11 21 2011 ping-hsun.wu
 * [MAUI_03073925] [V3D] Non-FBO screen rotation
 * merge to MAUI
 *  - revise code of screen rotate
 *  - move rotate rt into render device
 *  - add screen rotate matrix into 3d transforms
 *  - update 3d transform
 *  - update vertex shaders
 *  - fix sw owner draw buffer size
 *  - fix shelter owner draw
 *
 * 11 21 2011 ping-hsun.wu
 * [MAUI_03073925] [V3D] Non-FBO screen rotation
 * merge to 11B
 *  - revise code of screen rotate
 *  - move rotate rt into render device
 *  - add screen rotate matrix into 3d transforms
 *  - update 3d transform
 *  - update vertex shaders
 *  - fix sw owner draw buffer size
 *  - fix shelter owner draw
 *
 * 11 10 2011 ping-hsun.wu
 * [MAUI_03073925] [V3D] Non-FBO screen rotation
 * - update vertex shaders
 *
 * 08 12 2011 pablo.sun
 * [MAUI_02986150] [COSMOS 3D]3D slideshow check-in
 * .use per-vertex lighting in table
 *
 * 06 29 2011 ping-hsun.wu
 * [MAUI_02944930] 3D Asset Conversion
 * - revise function of reflection coefficient
 *  - fix view space to world space in essl
 *
 * 06 22 2011 ping-hsun.wu
 * [MAUI_02944930] 3D Asset Conversion
 * - fix shader variable type
 *
 * 05 18 2011 jimmy.su
 * [MAUI_02624362] VRT checkins
 * Fix shaders
 * - non-pow-2 repeat issue
 * - fix essl shader compile error
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// custom uniforms
uniform vec3 uLightPos;

// built-in uniforms
uniform mat4 v3d_MVPSMatrix;
uniform mat4 v3d_ModelMatrix;
uniform mat4 v3d_ViewMatrixInverse;
uniform mat4 v3d_ModelMatrixInverseTranspose;
uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;
uniform vec4 v3d_TexCoordScale;
uniform vec4 v3d_TexCoordBias;

// custom uniforms
uniform vec3 uAmbient;
uniform vec3 uDiffuse;


// attribute
attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;
attribute vec2 v3d_TexCoord;

// varying
varying vec3 vColor;
varying vec2 vTexCoord;

void main()
{
    // scale and bias
    vec4 position = v3d_Position * v3d_PositionScale + v3d_PositionBias;
    vec2 texCoord = v3d_TexCoord * v3d_TexCoordScale.xy + v3d_TexCoordBias.xy; 
    
    // projective
    gl_Position = v3d_MVPSMatrix * position;

    // to world space
    vec4 vPos = v3d_ModelMatrix * position;
    vec3 vLight = uLightPos - vPos.xyz;
    vec3 vView = v3d_ViewMatrixInverse[3].xyz - vPos.xyz;
    //vView = (v3d_ViewMatrixInverse * vec4(0.0, 0.0, 0.0, 1.0)).xyz - vPos.xyz;
    vec3 vNormal = (v3d_ModelMatrixInverseTranspose * vec4(v3d_Normal, 1.0)).xyz;
                  
    // world space vector
    vec3 light = normalize(vLight);
    vec3 view = normalize(vView);
    vec3 normal = normalize(vNormal);

    // diffuse
    float diffuse = max(0.0, dot(normal, light));
    vColor.rgb = (uAmbient + uDiffuse * diffuse);
    vTexCoord = texCoord;
}


