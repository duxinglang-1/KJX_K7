#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
<APP id="SRV_VENUS_COMPONENT_PAGE_PANEL">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
    </THEME>
#else
#endif
	<BINARY3D id="VCP_FRG_PAGE_PANEL_CURL_L" base_path="current">"shader\\\\vcp_page_panel_curl_l.fs"</BINARY3D>
      <BINARY3D id="VCP_VTX_PAGE_PANEL_CURL_L" base_path="current">"shader\\\\vcp_page_panel_curl_l.vs"</BINARY3D>
      <BINARY3D id="VCP_FRG_PAGE_PANEL_CURL_U" base_path="current">"shader\\\\vcp_page_panel_curl_u.fs"</BINARY3D>
      <BINARY3D id="VCP_VTX_PAGE_PANEL_CURL_U" base_path="current">"shader\\\\vcp_page_panel_curl_u.vs"</BINARY3D>      
	<BINARY3D id="VCP_FRG_PAGE_PANEL_CURL_R" base_path="current">"shader\\\\vcp_page_panel_curl_r.fs"</BINARY3D>
      <BINARY3D id="VCP_VTX_PAGE_PANEL_CURL_R" base_path="current">"shader\\\\vcp_page_panel_curl_r.vs"</BINARY3D>
      <BINARY3D id="VCP_FRG_PAGE_PANEL_CURL_D" base_path="current">"shader\\\\vcp_page_panel_curl_d.fs"</BINARY3D>
      <BINARY3D id="VCP_VTX_PAGE_PANEL_CURL_D" base_path="current">"shader\\\\vcp_page_panel_curl_d.vs"</BINARY3D>
      <BINARY3D id="VCP_FRG_PAGE_PANEL_RIPPLE" base_path="current">"shader\\\\vcp_page_panel_ripple.fs"</BINARY3D>
      


#ifndef RES_BIN_V3D_THEME_ROOT
#ifndef __COSMOS_MMI__
#define RES_BIN_V3D_THEME_ROOT          CUST_IMG_PATH"\\\\MainLCD"
#else
#define RES_BIN_V3D_THEME_ROOT          RES_THEME_ROOT
#endif
#define RES_BIN_V3D_COMMON_PATH         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\Common\\\\"
#define RES_BIN_V3D_COMMON_SHADER_PATH  RES_BIN_V3D_COMMON_PATH"\\\\Shader\\\\"
#define RES_BIN_V3D_COMMON_IMAGE_PATH   RES_BIN_V3D_COMMON_PATH"\\\\Image\\\\"
#endif /* RES_BIN_V3D_THEME_ROOT */

<!------------------ Triangle effect --------------------->
#ifndef RES_BIN_V3D_THEME_ROOT
#define RES_BIN_V3D_THEME_ROOT          RES_THEME_ROOT
#define RES_BIN_V3D_COMMON_PATH         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\Common\\\\"
#define RES_BIN_V3D_COMMON_SHADER_PATH  RES_BIN_V3D_COMMON_PATH"\\\\Shader\\\\"
#define RES_BIN_V3D_COMMON_IMAGE_PATH   RES_BIN_V3D_COMMON_PATH"\\\\Image\\\\"
#endif /* RES_BIN_V3D_THEME_ROOT */

<!------------------ triangle resource ------------------->
    <BINARY3D id="VCP_SCN_PAGE_PANEL_TRIANGLE">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\SSE-Triangle\\\\SSE-Triangle.scn"</BINARY3D>
    <BINARY3D id="VCP_ANI_PAGE_PANEL_TRIANGLE">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\SSE-Triangle\\\\SSE-Triangle.ani"</BINARY3D>

<!------------------ cube resource ------------------->
    <BINARY3D id="VCP_SCN_PAGE_PANEL_CUBE">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\SSE-Cube\\\\SSE-Cube.scn"</BINARY3D>
    <BINARY3D id="VCP_ANI_PAGE_PANEL_CUBE">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\SSE-Cube\\\\SSE-Cube.ani"</BINARY3D>

<!------------------ brick resource ------------------->
    <BINARY3D id="VCP_SCN_PAGE_PANEL_BRICK">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\SSE-Brick\\\\SSE-Brick.scn"</BINARY3D>
    <BINARY3D id="VCP_ANI_PAGE_PANEL_BRICK">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\SSE-Brick\\\\SSE-Brick.ani"</BINARY3D>

<!------------------ twist resource ------------------->
    <BINARY3D id="VCP_SCN_PAGE_PANEL_TWIST">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\SSE-Twist\\\\SSE-Twist.scn"</BINARY3D>
    <BINARY3D id="VCP_ANI_PAGE_PANEL_TWIST">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\SSE-Twist\\\\SSE-Twist.ani"</BINARY3D>

<!--------------  3D Circle ------------------>
	<BINARY3D id="VCP_VTX_PAGE_PANEL_3D_CIRCLE" base_path="current">"shader\\\\vcp_page_panel_3D_Circle.vs"</BINARY3D>
	<BINARY3D id="VCP_FRG_PAGE_PANEL_3D_CIRCLE" base_path="current">"shader\\\\vcp_page_panel_3D_Circle.fs"</BINARY3D>
	
<!------------------ rotate shader --------------------->
    <BINARY3D id="VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE" base_path="current">"shader\\\\vcp_page_panel_B1_frametex_rotate.fs"</BINARY3D>
    
<!------------------ simple shader --------------------->
    <BINARY3D id="VCP_FRG_PAGE_PANEL_SIMPLE" base_path="current">"shader\\\\vcp_page_panel_simple.fs"</BINARY3D>
    

<!------------------ fusion shader --------------------->    
    <BINARY3D id="VCP_FRG_PAGE_PANEL_FUSION" base_path="current">"shader\\\\vcp_page_panel_fusion.fs"</BINARY3D>
    <IMAGE    id="IMG_ID_VCP_PAGE_PANEL_FUSION">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\PagePanel\\\\Fusion\\\\vcp_page_panel_fusion.ktx"</IMAGE>
</APP>
#endif
