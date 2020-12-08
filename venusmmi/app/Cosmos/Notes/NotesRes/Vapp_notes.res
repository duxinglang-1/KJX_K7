#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_NOTE_APP__

<APP id="VAPP_NOTES" 
package_name ="native.mtk.vapp_notes"
name ="STR_ID_VAPP_NOTES_APP_TITLE"
img ="IMG_ID_VAPP_NOTES_MAIN_MENU"
launch ="vapp_notes_app_launch" type="venus">
	<MEMORY base="500*1024" />


<CACHEDATA type="byte" id="NVRAM_NOTES_APP_NOTE_COLOR" restore_flag="TRUE">
     <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
     <DESCRIPTION> Byte Cache </DESCRIPTION>
     </CACHEDATA>

#define NOTES_ROOT_PATH         CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Note\\\\"
#define NOTES_TOOL_BAR_IMG_PATH         CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Components\\\\Toolbar\\\\CommonIcon\\\\"
#define NOTES_APP_MAIN_MENU_ICON_PATH        CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Mainmenu_Icon\\\\"
#define NOTES_VIEW_GLOABL_PATH               CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Theme1\\\\Common\\\\"
#define NOTES_VIEW_TITLE_BG_COLOR_PATH            CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Theme1\\\\Calendar\\\\"
    <!--Include Area-->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_YELLOW">           NOTES_ROOT_PATH"note_1.9slice.png"               </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_GREEN">             NOTES_ROOT_PATH"note_2.9slice.png"             </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_BLUE">               NOTES_ROOT_PATH"note_3.9slice.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_RED">                NOTES_ROOT_PATH"note_4.9slice.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_WHITE">            NOTES_ROOT_PATH"note_5.9slice.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ORANGE">          NOTES_ROOT_PATH"note_6.9slice.png"          </IMAGE>
     
    
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_YELLOW_BG">             NOTES_ROOT_PATH"bg_edit_1.9slice.png"               </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_GREEN_BG">              NOTES_ROOT_PATH"bg_edit_6.9slice.png"             </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_BLUE_BG">               NOTES_ROOT_PATH"bg_edit_5.9slice.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_RED_BG">                NOTES_ROOT_PATH"bg_edit_4.9slice.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_WHITE_BG">              NOTES_ROOT_PATH"bg_edit_3.9slice.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ORANGE_BG">             NOTES_ROOT_PATH"bg_edit_2.9slice.png"          </IMAGE>
    
     
	<IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ALL">          NOTES_ROOT_PATH"Note_all.png"          </IMAGE>
	<IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ONLY_YELLOW">           NOTES_ROOT_PATH"Note_D.png"               </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ONLY_GREEN">             NOTES_ROOT_PATH"Note_C.png"             </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ONLY_BLUE">               NOTES_ROOT_PATH"Note_B.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ONLY_RED">                NOTES_ROOT_PATH"Note_F.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ONLY_WHITE">            NOTES_ROOT_PATH"Note_A.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_CATEGROY_ONLY_ORANGE">          NOTES_ROOT_PATH"Note_E.png"          </IMAGE>
       

	<IMAGE id = "IMG_ID_VAPP_NOTES_PAPER_COLOR_YELLOW">           NOTES_ROOT_PATH"pc_yellow.png"               </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_PAPER_COLOR_GREEN">             NOTES_ROOT_PATH"pc_green.png"             </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_PAPER_COLOR_BLUE">               NOTES_ROOT_PATH"pc_blue.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_PAPER_COLOR_RED">                NOTES_ROOT_PATH"pc_pink.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_PAPER_COLOR_WHITE">            NOTES_ROOT_PATH"pc_white.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_PAPER_COLOR_ORANGE">          NOTES_ROOT_PATH"pc_orange.png"          </IMAGE>


	<IMAGE id = "IMG_ID_VAPP_NOTES_APP_BG_IMAGE">          NOTES_ROOT_PATH"bg.9slice.png"          </IMAGE>


	<IMAGE id = "IMG_ID_VAPP_NOTES_UNSELECT_ALL">          NOTES_TOOL_BAR_IMG_PATH"Unselect_All.png"          </IMAGE>
	<IMAGE id = "IMG_ID_VAPP_NOTES_ADD_NEW_NOTE">           NOTES_TOOL_BAR_IMG_PATH"Add_File.png"               </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_DELETE">             NOTES_TOOL_BAR_IMG_PATH"Delete.png"             </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_EDIT">               NOTES_TOOL_BAR_IMG_PATH"Edit.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_SEARCH">            NOTES_TOOL_BAR_IMG_PATH"Search.png"            </IMAGE>
    <IMAGE id = "IMG_ID_VAPP_NOTES_SELECT_ALL">          NOTES_TOOL_BAR_IMG_PATH"Select_All.png"          </IMAGE>
	<IMAGE id = "IMG_ID_VAPP_NOTES_CANCEL">            NOTES_TOOL_BAR_IMG_PATH"Cancel.png"            </IMAGE>
	<IMAGE id = "IMG_ID_VAPP_NOTES_CATEGORY">          NOTES_ROOT_PATH"icon_category.png"          </IMAGE>
	<IMAGE id = "IMG_ID_VAPP_NOTES_PAPER_COLOR">          NOTES_ROOT_PATH"icon_bg_color.png"          </IMAGE>
	<IMAGE id = "IMG_ID_VAPP_NOTES_EDIT_SAVE">          NOTES_TOOL_BAR_IMG_PATH"Save.png"          </IMAGE>
	
	<THEME>		
        <IMAGE id = "IMG_ID_VAPP_NOTES_MAIN_MENU" desc="Main menu notes icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Note.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_NOTES_VIEW_TITLE_BG" desc="title BG image"/>		
		 <IMAGE id="IMG_ID_VAPP_NOTES_VIEW_PREVIOUS_ITEM_GLOBAL" desc="Botton previous"/>
		<IMAGE id="IMG_ID_VAPP_NOTES_VIEW_NEXT_ITEM_GLOBAL" desc="Botton next"/>
    </THEME>	
	
	<IMAGE id = "IMG_ID_VAPP_NOTES_PC_HILIGHT_PENCIL_MARK">          NOTES_ROOT_PATH"hl_pc.png"          </IMAGE>

	<STRING id="STR_ID_VAPP_NOTES_APP_TITLE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTE_NEW_NOTE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTE_DELETE_NOTE_ASK"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTE_DELETE_MARKED_ASK"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTE_NOTE_DELETED"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTE_ITEM_LIMIT"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_PAPER_COLOR"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_NEW_NOTE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_EDIT_NOTE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_ADD_NOTE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_CATEGORY"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_DELETE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_EDIT"/>	
	<STRING id="STR_ID_VAPP_NOTES_NOTE_CANCEL"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_UNSELECT_ALL"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_SELECT_ALL"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_NO_NOTES"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_GREEN"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_RED"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_ORANGE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_WHITE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_BLUE"/>
	<STRING id="STR_ID_VAPP_NOTES_NOTES_YELLOW"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_GREEN_NO"/>  
    <STRING id="STR_ID_VAPP_NOTES_NOTES_RED_NO"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_ORANGE_NO"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_WHITE_NO"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_BLUE_NO"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_YELLOW_NO"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_DISCARD"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_SAVE"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_SEARCH_COUNT"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_PCS"/>
    <STRING id="STR_ID_VAPP_NOTES_NOTES_SEARCH"/>
    <STRING id="STR_ID_VAPP_NOTES_EDIT_EMPTY_TEXT"/>
    <STRING id="STR_ID_VAPP_NOTE_DELETE_STRING_2"/>
    <STRING id="STR_ID_VAPP_NOTES_DELETE_CONFIRM_ONE_STRING_1"/>
    <STRING id="STR_ID_VAPP_NOTES_DELETE_CONFIRM_STRING_1"/>
    <STRING id="STR_ID_VAAP_NOTES_DELETE_NOTES_TITLE"/>
    <STRING id="STR_ID_VAAP_NOTES_COLOR"/>
    <STRING id="STR_ID_VAPP_NOTES_HINT_SEARCHING"/>
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

</APP>

#endif /* __MMI_NOTE_APP__ */

