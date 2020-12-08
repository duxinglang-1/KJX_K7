attribute vec2 v3d_Position;
attribute vec4 v3d_Color;
attribute vec2 v3d_TexCoord;

varying vec4 vColor;
varying vec2 vTexCoord;

uniform ivec2 v3d_ViewportSize;
uniform vec2 v3d_Scale;
uniform vec2 v3d_Bias;
uniform ivec2 v3d_Anchor;
uniform float v3d_Time;

void main()
{
	vColor = v3d_Color;
	vTexCoord = v3d_TexCoord;
	
	vec2 size = vec2(v3d_ViewportSize);
	vec2 pos = v3d_Position * v3d_Scale + v3d_Bias;

	/* rotate */
	vec2 anchor = vec2(v3d_Anchor);
	vec2 radius = (pos - anchor) * 0.7;
	vec2 rot = vec2(cos(v3d_Time), sin(v3d_Time));
	pos = anchor + vec2(rot.x * radius.x + rot.y * radius.y, rot.y * radius.x - rot.x * radius.y);
	
	/* convert to screen space */
	gl_Position.x = (pos.x * 2.0 - size.x) / size.x;
	gl_Position.y = (size.y - pos.y * 2.0) / size.y;
	gl_Position.zw = vec2(0.0, 1.0);
}