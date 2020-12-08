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
 * A simple fragment shader example
 *
 */

precision mediump float;

uniform sampler2D u_texture;
uniform sampler2D u_night;
uniform sampler2D u_gloss;

uniform vec3 u_centre;
uniform float u_centre_sqr;
uniform float u_rot;

varying vec4 v_position;
varying vec3 u_light;
varying vec3 u_lightHalf;

const float pi = 3.14159265;
const float mult1 = 1.0 / pi;
const float mult2 = 0.5 / pi;
void main()
{
  // This is a vector from eye/camera position in world space for this pixel
  vec3 dir = normalize( v_position.xyz );
  
  float dot_dir_centre = dot( dir, u_centre );
  
  float dist_sqr = u_centre_sqr - dot_dir_centre * dot_dir_centre;
  
  if( dist_sqr > 1.0 ) // 'Just missed', so do atmosphere glow
  {
    if( dist_sqr > 1.4 )
    {
      gl_FragColor = vec4( 0.0, 0.0, 0.0, 1.0 );
    }
    else
    {
      float sqr_prw = pow( 1.4 - dist_sqr, 5.0 );
      gl_FragColor = 120.0 * pow( dot( dir, u_light ), 20.0 ) *
                     vec4( sqr_prw, sqr_prw, sqr_prw, 1.0 );
    }
  }
  else
  {
    vec3 surfacePoint = dir * ( dot_dir_centre - sqrt( 1.0 - dist_sqr ) );
    vec3 normal = normalize( surfacePoint - u_centre );

    float dot_normal_light = dot( normal, u_light );
    float diffuse = max( dot_normal_light, 0.0 );
    
    float halfDot = max( dot( normal, u_lightHalf ), 0.0 );
    
    float y = mult1 * acos( normal.y );
    float x = mult2 * asin( normal.x ) + u_rot;

    // The pixels on the edge of the globe blackened to hide the case
    // where the wrong mipmap level is chosen.    
    float att = ( dist_sqr > 0.999 ) ? 0.0 : 1.0;

    // Combine the textures depending on light direction.
    gl_FragColor = att *
      ( diffuse * texture2D( u_texture, vec2( x, y ) ) + // Daytime
      (1.0-diffuse)*texture2D( u_night, vec2( x, y ) ) + // Nighttime
      vec4( 0.8, 0.6, 0.6, 1.0 ) *
      pow( halfDot, 20.0 ) * texture2D( u_gloss, vec2( x, y ) ) ); //Specular
  }
}
