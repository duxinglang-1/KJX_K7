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
 * Filename:
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
 *  Aaron Chen (mtk03252)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
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
 * 07 27 2011 aaron.chen
 * [MAUI_02956673] MAUI Trunk 11B Check In
 * Merge cover flow 3D.
 *
 * 07 20 2011 aaron.chen
 * [MAUI_02986541] Cosmos 3D MT6256 DEV Check In
 * Update shaders.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// custom uniforms
uniform vec3 uLightPos;
uniform float uYOffset;

uniform float uETA;
uniform float uRC;

// built-in uniforms
uniform mat4 v3d_MVPSMatrix;
uniform mat4 v3d_ModelMatrix;
uniform mat4 v3d_ViewMatrixInverse;
uniform mat4 v3d_ModelMatrixInverseTranspose;
uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;
uniform vec4 v3d_TexCoordScale;
uniform vec4 v3d_TexCoordBias;

// attribute
attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;

// varying
varying vec3 vLight;
varying vec3 vView;
varying vec3 vNormal;
varying vec2 vRIScaleBias;

void main()
{
    // scale and bias
    vec4 position = v3d_Position * v3d_PositionScale + v3d_PositionBias;
    position.y -= uYOffset;

    // projective
    gl_Position = v3d_MVPSMatrix * position;

    // to world space
    vec4 vPos = v3d_ModelMatrix * position;
    vLight = uLightPos - vPos.xyz;
    vView = v3d_ViewMatrixInverse[3].xyz - vPos.xyz;
    //vView = (v3d_ViewMatrixInverse * vec4(0.0, 0.0, 0.0, 1.0)).xyz - vPos.xyz;
    vNormal = (v3d_ModelMatrixInverseTranspose * vec4(v3d_Normal, 1.0)).xyz;

    float r0 = (1.0 - uETA) / (1.0 + uETA);
    r0 *= r0;
    vRIScaleBias = vec2(uRC + r0, max(1.0, pow(uETA, 15.0)) - r0);
}


