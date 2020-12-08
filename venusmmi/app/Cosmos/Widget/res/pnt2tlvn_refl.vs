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
 *  Andy Kauo (mtk03823)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 21 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * . [Clock] Particle & Reflection(stencil buffer) check in and bugs fixed.
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// custom uniforms
uniform vec3 uLightPos;
uniform vec3 uReflectPos;
uniform vec3 uReflectDir;
uniform float uReflectOff;

// built-in uniforms
uniform mat4 v3d_VPMatrix;
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
attribute vec2 v3d_TexCoord;

// varying
varying vec2 vTexCoord;
varying vec3 vLight;
varying vec3 vView;
varying vec3 vNormal;

void main()
{
    // scale and bias
    vec4 position = v3d_Position * v3d_PositionScale + v3d_PositionBias;
    vec2 texCoord = v3d_TexCoord * v3d_TexCoordScale.xy + v3d_TexCoordBias.xy; 

    // to world space
    vec4 vPos = v3d_ModelMatrix * position;
    //vec4 vRefl = vec4(reflect(vPos.xyz - uReflectPos, normalize(uReflectDir)) + uReflectPos, vPos.w);
    vec3 vPlane = uReflectPos + uReflectDir * uReflectOff;
    float IdotN = dot(vPos.xyz - vPlane, uReflectDir);
    vec4 vRefl = IdotN > 0.0 ? vec4(vPos.xyz - 2.0 * IdotN * uReflectDir, vPos.w) : vPos;

    // projective
    gl_Position = v3d_VPMatrix * vRefl;
    vTexCoord = texCoord;

    vLight = uLightPos - vPos.xyz;
    vView = v3d_ViewMatrixInverse[3].xyz - vPos.xyz;
    //vView = (v3d_ViewMatrixInverse * vec4(0.0, 0.0, 0.0, 1.0)).xyz - vPos.xyz;
    vNormal = (v3d_ModelMatrixInverseTranspose * vec4(v3d_Normal, 1.0)).xyz;
}


