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
uniform sampler2D u_cloud;
uniform sampler2D u_night;
uniform sampler2D u_gloss;
uniform sampler2D u_dist;
//uniform sampler2D uBumpSampler;
//uniform float uBumpHeight;  // bump height

//uniform vec3 u_centre;
//uniform float u_centre_sqr;
uniform float u_rot;
uniform float u_rot_cloud;

uniform bool u_isBGRExt;

varying vec4 v_position;
varying vec2 v_texLookUp;

varying vec3 u_light;
varying vec3 u_lightHalf;

const float pi = 3.14159265;
const float mult1 = 1.0 / pi;
const float mult2 = 0.5 / pi;
void main()
{
  // discard unused area
  if(v_texLookUp.y > 1.0 || v_texLookUp.y < 0.0)
  {
      discard;
  } 
  // This is a vector from eye/camera position in world space for this pixel
  //vec3 dir = normalize( v_position.xyz );
  //vec4 lookup = texture2D( u_dist, vec2(v_texLookUp.x, (v_texLookUp.y-0.2)/0.6) ).brga;
  
  vec4 lookup;
  if(!u_isBGRExt)
  {
    lookup = texture2D( u_dist, v_texLookUp ).brga;
  }
  else
  {
    lookup = texture2D( u_dist, v_texLookUp ).rbga;
  }

  float dist_sqr = lookup.r*2.0;
  
  //float dot_dir_centre = dot( dir, u_centre );
  
  //float dist_sqr = u_centre_sqr - dot_dir_centre * dot_dir_centre;
  //float dist_sqr = 25.0 * ( 1.0 - dir.z * dir.z ); 

  if( dist_sqr > 1.6 )
  {
    discard;
  }

  if( dist_sqr > 0.96 ) // 'Just missed', so do atmosphere glow
  {
    vec3 dir = normalize ( v_position.xyz );
    float sqr_prw = pow( 1.6 - dist_sqr, 3.8 );
    float tmp = clamp(dot(dir , u_light), 0.0, 1.0);
    gl_FragColor = 9.0 * vec4( 0.36, 0.61, 1.0, 1.0 ) * pow( tmp, 5.0 ) *
                     vec4( sqr_prw, sqr_prw, sqr_prw, sqr_prw );
    gl_FragColor.a *= 0.8; 
  }
  else
  {
    //vec3 surfacePoint = dir * ( dot_dir_centre - sqrt( 1.0 - dist_sqr ) );
    //vec3 normal = normalize( surfacePoint - u_centre );
    
    vec3 normal = vec3( lookup.g *2.0 - 1.0, lookup.b*2.0-1.0, 0.0);
    normal.z = sqrt( 1.0 - ( normal.x * normal.x + normal.y * normal.y ) );

    float y = mult1 * acos( normal.y );
    float x = mult2 * asin( normal.x ) - u_rot;

    float x_cloud = mult2 * asin( normal.x ) - u_rot_cloud;

    // The pixels on the edge of the globe blackened to hide the case
    // where the wrong mipmap level is chosen.    
    float att = ( dist_sqr > 0.96 ) ? 0.0 : 1.0;

    float dot_normal_light = dot( normal, u_light );
    float diffuse = max( dot_normal_light, 0.0 );
    
    float halfDot = max( dot( normal, u_lightHalf ), 0.0 );
    // Combine the textures depending on light direction.
    gl_FragColor = att *
      ( diffuse * texture2D( u_texture, vec2( x, y ) ) + texture2D( u_cloud, vec2( x_cloud, y ) ) + // Daytime + Cloud
      (1.0-diffuse)*texture2D( u_night, vec2( x, y ) ) + 0.0 * (1.0-diffuse)*texture2D( u_cloud, vec2( x_cloud, y ) ) *0.8 + // Nighttime + Cloud
      vec4( 0.8, 0.6, 0.6, 1.0 ) *
      pow( halfDot, 20.0 ) * texture2D( u_gloss, vec2( x, y ) ) ); //Specular
  }
}
