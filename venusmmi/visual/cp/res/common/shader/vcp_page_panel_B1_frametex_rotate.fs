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
 *  Jimmy Su (mtk02981)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 20 2012 peggy.yeh
 * [MAUI_03152133] [Moved Files from p4 service] CP Folder restructure 2 : resource file
 * Back out changelist 613108
 *
 * 07 15 2011 facer.pei
 * [MAUI_02968950] 11B Patch
 * SSE integrate with resgen .
 *
 * 06 29 2011 jimmy.su
 * [MAUI_02624362] VRT checkins
 * - support built-in v3d_Opacity
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
precision mediump float;

// builtin uniforms
uniform float v3d_Opacity;

// custom uniforms
uniform vec3 uAmbient;

uniform vec3 uDiffuse;
uniform sampler2D uDiffuseSampler;

uniform float uOpacity;

uniform vec3 uSpecular;
uniform float uShininess;

uniform bool isRotate;

// built-in uniforms

// varying
varying vec2 vTexCoord;
varying vec3 vLight;
varying vec3 vView;
varying vec3 vNormal;


void main()
{

    // base texture
    vec2 tempTexCoord;
    if (isRotate)
    {
         tempTexCoord = vec2(1.0 - vTexCoord.y, 1.0 - vTexCoord.x);
    }
    else
    {
        tempTexCoord = vec2(vTexCoord.x, 1.0 - vTexCoord.y);
    }
    // we should flip texcoord for frame texture
    gl_FragColor = texture2D(uDiffuseSampler, tempTexCoord);
    gl_FragColor.a *= (uOpacity * v3d_Opacity);

    // alpha test
    if (gl_FragColor.a == 0.0)
        discard;

    // world space vector
    vec3 light = normalize(vLight);
    vec3 view = normalize(vView);
    vec3 normal = normalize(vNormal);
    vec3 refl = reflect(-view, normal);

    // diffuse
    float diffuse = max(0.0, dot(normal, light));

    // specular
    float specular = pow(max(0.0, dot(light, refl)), uShininess);

    gl_FragColor.rgb *= (uAmbient + uDiffuse * diffuse);
    // if not back-light. light.z == dot(face_normal, light)
    gl_FragColor.rgb += uSpecular * specular * float(diffuse > -light.z);
}


