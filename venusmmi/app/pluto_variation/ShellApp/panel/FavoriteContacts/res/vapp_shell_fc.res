#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_VENUS_SHELL_FC">

#ifdef __MMI_VUI_SHELL_FAV_CONTACT__    

    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_SHELL_FC_STR_ADD_NEW_CONTACT"/>
    
    <STRING id="VAPP_SHELL_FC_STR_CALL_MOBILE"/>
    <STRING id="VAPP_SHELL_FC_STR_CALL_HOME"/>
    <STRING id="VAPP_SHELL_FC_STR_CALL_OFFIC"/>
    <STRING id="VAPP_SHELL_FC_STR_CALL_FAX"/>
    <STRING id="VAPP_SHELL_FC_STR_SEND_MSG"/>
    <STRING id="VAPP_SHELL_FC_STR_SEND_MAIL"/>
    
    <STRING id="VAPP_SHELL_FC_STR_DETAILS"/>
    <STRING id="VAPP_SHELL_FC_STR_MSGS"/>
    <STRING id="VAPP_SHELL_FC_STR_CALLS"/>
    
    <STRING id="VAPP_SHELL_FC_STR_MAKE_CALL"/>
    <STRING id="VAPP_SHELL_FC_STR_REMVOE_FC"/>
    
    <STRING id="VAPP_SHELL_FC_STR_NO_ANSWER"/>
    <STRING id="VAPP_SHELL_FC_STR_DURATION"/>
    <STRING id="VAPP_SHELL_FC_STR_MISSED"/>
    <STRING id="VAPP_SHELL_FC_STR_REJECTED"/>
    <STRING id="VAPP_SHELL_FC_STR_NO_CLOGS"/>
    <STRING id="VAPP_SHELL_FC_STR_NO_MSGS"/>
    <STRING id="VAPP_SHELL_FC_STR_NO_DETAILS"/>
    
    <STRING id="VAPP_SHELL_FC_STR_CONTACT_SELECTED"/>
    <STRING id="VAPP_SHELL_FC_STR_ADD_IMG"/>
    <STRING id="VAPP_SHELL_FC_STR_TAKE_PHOTO"/>
    <STRING id="VAPP_SHELL_FC_STR_SELECT_FILE"/>
    <STRING id="VAPP_SHELL_FC_STR_FC"/>
		
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\FavoriteContacts\\\\"
    
    <IMAGE id="VAPP_SHELL_FC_IMG_ADD"> 		ROOT_PATH"Add.png"</IMAGE>
    
    <IMAGE id="VAPP_SHELL_FC_IMG_CALL_DIS"> 	ROOT_PATH"MakeCall_Dis.png"</IMAGE>    
    <IMAGE id="VAPP_SHELL_FC_IMG_CALL_NOR"> 	ROOT_PATH"MakeCall_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_CALL_PRE"> 	ROOT_PATH"MakeCall_Pre.png"</IMAGE>
    
    <IMAGE id="VAPP_SHELL_FC_IMG_MSG_DIS"> 	ROOT_PATH"SendMessage_Dis.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_MSG_NOR"> 	ROOT_PATH"SendMessage_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_MSG_PRE"> 	ROOT_PATH"SendMessage_Pre.png"</IMAGE>
    
    <IMAGE id="VAPP_SHELL_FC_IMG_MIS_CALL"> 	ROOT_PATH"List_MissedCall.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_REC_MSG"> 	ROOT_PATH"List_ReceiveMessage.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_REC_CALL"> 	ROOT_PATH"List_ReceivedCall.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_SEND_MAIL"> 	ROOT_PATH"LIst_SendMaill.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_SEND_MSG"> 	ROOT_PATH"List_SendMessage.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_MAKE_CALL"> 	ROOT_PATH"List_MakeCall.png"</IMAGE>
    
    <IMAGE id="VAPP_SHELL_FC_IMG_DETAIL_NOR">   ROOT_PATH"Details_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_DETAIL_HIGH">  ROOT_PATH"Details_High.png"</IMAGE>
    
    <IMAGE id="VAPP_SHELL_FC_IMG_CALLS_NOR"> 	ROOT_PATH"AllCall_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_CALLS_HIGH">   ROOT_PATH"AllCall_High.png"</IMAGE>
    
    <IMAGE id="VAPP_SHELL_FC_IMG_MSGS_NOR"> 	ROOT_PATH"Message_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_MSGS_HIGH"> 	ROOT_PATH"Message_High.png"</IMAGE>  

#ifdef __MMI_VUI_SHELL_FAV_CONTACT_SLIM__
    <IMAGE id="VAPP_SHELL_FC_IMG_CONTACT_BG"> 		ROOT_PATH"Contact_BG_Slim.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_BG">  		ROOT_PATH"BackGroup_Slim.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_DEFAULT"> 	ROOT_PATH"DefaultContact_Slim.png"</IMAGE>    
#else
    <IMAGE id="VAPP_SHELL_FC_IMG_BG">  		ROOT_PATH"BackGroup.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_DEFAULT"> 	ROOT_PATH"DefaultContact.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_FC_IMG_CONTACT_BG"> 		ROOT_PATH"Contact_BG.png"</IMAGE>
#endif
    
    <IMAGE id="VAPP_SHELL_FC_IMG_CONTACT_SHADOW"> 	ROOT_PATH"DefaultContact_Shadow.png"</IMAGE>  
    <IMAGE id="VAPP_SHELL_FC_IMG_CONTACT_HIGH_GLOSS">   ROOT_PATH"Contact_HighGloss.png"</IMAGE>
          
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

#endif /* __MMI_VUI_SHELL_FAV_CONTACT__ */

</APP>

