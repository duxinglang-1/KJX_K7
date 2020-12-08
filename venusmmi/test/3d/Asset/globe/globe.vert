/**************************************************************************
 *
 * Copyright (c) 2011 MediaTek Inc. All Rights Reserved.
 * --------------------
 * This software is protected by copyright and the information contained
 * herein is confidential. The software may not be copied and the information
 * contained herein may not be used or disclosed except with the written
 * permission of MediaTek Inc.
 *
 **************************************************************************
 *   $Id$ 
 *   $Revision$
 *   $DateTime$
 ***************************************************************************/
/** \file
 * A simple vertex shader example
 *
 */

attribute vec2 v3d_Position;

varying vec4 v_position;
varying vec3 u_light;
varying vec3 u_lightHalf;

uniform ivec2 v3d_ViewportSize;
uniform vec2 v3d_Scale;
uniform vec2 v3d_Bias;
uniform mat4 u_invProjection;
uniform float u_lightAngle;

void main()
{
  vec2 size = vec2(v3d_ViewportSize);
  vec2 pos = v3d_Position * v3d_Scale + v3d_Bias;
  gl_Position.x = (pos.x * 2.0 - size.x) / size.x;
  gl_Position.y = (size.y - pos.y * 2.0) / size.y;
  gl_Position.zw = vec2(0.0, 1.0);
  v_position = u_invProjection * gl_Position;
  u_light = vec3(sin(u_lightAngle), 0.0, cos(u_lightAngle));
  u_lightHalf = normalize(u_light + vec3(0.0, 0.0, 1.0));
}

