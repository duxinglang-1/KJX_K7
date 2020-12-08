#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_VENUS_SHELL_MSG_VIEWER">

#ifdef __MMI_VUI_SHELL_MSG_VIEWER__

#define SHELL_ROOT_PATH         CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\"
#define SHELL_MSG_VIEWER_PATH   SHELL_ROOT_PATH"MsgViewer\\\\"

    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_SHELL_MSG_VIEWER_TITLE"/>
    <STRING id="STR_ID_SHELL_MSG_VIEWER_NO_MESSAGE"/>
    <STRING id="STR_ID_SHELL_MSG_VIEWER_TODAY"/>
    <STRING id="STR_ID_SHELL_MSG_VIEWER_DELETE_MESSAGE"/>
    <STRING id="STR_ID_SHELL_MSG_VIEWER_INITIALIZING"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_READ">               SHELL_MSG_VIEWER_PATH"List_Read.png"               </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_UNREAD">             SHELL_MSG_VIEWER_PATH"List_Unread.png"             </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_SWITCH_NORMAL">   SHELL_MSG_VIEWER_PATH"Listview_Nor.png"            </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_SWITCH_DISABLED"> SHELL_MSG_VIEWER_PATH"Listview_Dis.png"            </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_SWITCH_PRESSED">  SHELL_MSG_VIEWER_PATH"Listview_Pre.png"            </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_CREATE_NORMAL">   SHELL_MSG_VIEWER_PATH"Mes_Create_Nor.png"          </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_CREATE_DISABLED"> SHELL_MSG_VIEWER_PATH"Mes_Create_Dis.png"          </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_CREATE_PRESSED">  SHELL_MSG_VIEWER_PATH"Mes_Create_Pre.png"          </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_REPLY_NORMAL">    SHELL_MSG_VIEWER_PATH"Mes_Reply_Nor.png"           </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_REPLY_DISABLED">  SHELL_MSG_VIEWER_PATH"Mes_Reply_Dis.png"           </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_TB_REPLY_PRESSED">   SHELL_MSG_VIEWER_PATH"Mes_Reply_Pre.png"           </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_NO_MESSAGE">         SHELL_MSG_VIEWER_PATH"NOMessage.png"               </IMAGE>
    <IMAGE id = "IMG_ID_SHELL_MSG_VIEWER_NEW_MESSAGE">        SHELL_MSG_VIEWER_PATH"New_Msg.png"                 </IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

#endif /* __MMI_VUI_SHELL_MSG_VIEWER__ */

</APP>

