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
 *  Ping-Hsun Wu (mtk03719)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 26 2011 szuwei.lin
 * [MAUI_02991920] [V3D] Check-in
 * .
 *
 * 07 26 2011 szuwei.lin
 * [MAUI_02991920] [V3D] Check-in
 * .
 *
 * 07 12 2011 ping-hsun.wu
 * [MAUI_02944930] 3D Asset Conversion
 * - update rt test content (skin mesh)
 *
 * 06 20 2011 ping-hsun.wu
 * [MAUI_02944930] 3D Asset Conversion
 * - fix shaders
 * 
 *    - non-power-of-2 repeat
 *    - essl compile error
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

precision mediump float;

uniform sampler2D uDiffuseSampler;
uniform sampler2D uSpecularSampler;
uniform float uAmbient;     // ambient intensity
uniform vec3 uDiffuse;      // diffuse intensity
uniform vec3 uSpecular;     // specular intensity
uniform float uShininess;   // specular power

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec3 vLight;
varying vec3 vView;
varying vec3 vNormal;
varying vec2 vTexCoord;

void main()
{
    vec3 light = normalize(vLight);
    vec3 view = normalize(vView);
    vec3 normal = normalize(vNormal);

    // texture
    gl_FragColor = texture2D(uDiffuseSampler, vTexCoord);

    // ambient + diffuse
    gl_FragColor.rgb *= uDiffuse * min(1.0, uAmbient + max(0.0, dot(normal, light)));

    // specular
    float specular = pow(max(0.0, dot(view, reflect(-light, normal))), uShininess);
    specular *= texture2D(uSpecularSampler, vTexCoord).a;
    gl_FragColor.rgb += uSpecular * specular;

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

