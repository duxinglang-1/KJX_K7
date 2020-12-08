# 1 "temp/res/todolist.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/todolist.c"

# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 3 "temp/res/todolist.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 4 "temp/res/todolist.c" 2


<?xml version = "1.0" encoding = "UTF-8"?>

<APP
    id = "APP_TODOLIST"
# 18 "temp/res/todolist.c"
    >

    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_srv_vcalendar_def.h"/>
    <INCLUDE file = "mmi_rp_srv_vobject_def.h"/>
    <INCLUDE file = "mmi_rp_app_calendar_def.h"/>
    <INCLUDE file = "Mmi_rp_app_alarm_def.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <INCLUDE file = "OrganizerResDef.h"/>

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->

    <STRING id = "STR_TODO_LIST_USE_TEMPLATE"/>
        <STRING id = "STR_TODO_LIST_DELETE_ONE_TASK_QUERY"/>
        <STRING id = "STR_TODO_LIST_DELETE_ALL_TASK_QUERY"/>
        <STRING id = "STR_TODO_TEMPLATE_1"/>
        <STRING id = "STR_TODO_TEMPLATE_2"/>
        <STRING id = "STR_TODO_TEMPLATE_3"/>
        <STRING id = "STR_TODO_TEMPLATE_4"/>
        <STRING id = "STR_TODO_TEMPLATE_5"/>
        <STRING id = "STR_TODO_TEMPLATE_6"/>
        <STRING id = "STR_TODO_TEMPLATE_7"/>
        <STRING id = "STR_TODO_TEMPLATE_8"/>
        <STRING id = "STR_TODO_TEMPLATE_9"/>
        <STRING id = "STR_TODO_TEMPLATE_10"/>
        <STRING id = "STR_TODO_TEMPLATE_NOT_ENOUGH_SPACE"/>
    <STRING id = "STR_TODO_REPEAT"/>
    <STRING id = "STR_TODO_ALARM_BEFORE_5_MINS"/>
        <STRING id = "STR_TODO_ALARM_BEFORE_10_MINS"/>
    <STRING id = "STR_TODO_ALARM_BEFORE_15_MINS"/>
    <STRING id = "STR_TODO_ALARM_BEFORE_30_MINS"/>
    <STRING id = "STR_TODO_SET_REPEAT_ONCE"/>
    <STRING id = "STR_TODO_REPEAT_INVALID"/>
    <STRING id = "STR_ID_TDL_TODAY"/>
    <STRING id = "STR_ID_TDL_SELECT"/>
    <STRING id = "STR_ID_TDL_NO_CONTENT"/>
    <STRING id = "STR_ID_TDL_CATEGORY"/>
        <STRING id = "STR_ID_TODO_STATUS_UNDONE"/>
    <STRING id = "STR_TODO_ALARM_OFF_DONE"/>
# 77 "temp/res/todolist.c"
        <STRING id = "ORGANIZER_MENU_TODOLIST_STRINGID"/>
    <STRING id = "STR_TODO_LIST_LIST_FULL_MSG"/>
    <STRING id = "STR_ID_TDL_NO_TASKS"/>
    <STRING id = "STR_ID_TDL_TASK_DELETED"/>
        <STRING id = "STR_ID_TDL_TASKS_DELETED"/>
        <STRING id = "STR_ID_TDL_ADD_TASK"/>
    <STRING id = "STR_ID_TDL_TASKS"/>
    <STRING id = "STR_ID_TODO_STATUS"/>
    <STRING id = "STR_TODO_LIST_VIEW_UNDONE"/>
    <STRING id = "STR_TODO_LIST_JUMP_TO_DATE"/>
    <STRING id = "STR_TODO_LIST_OVERWRITE_QUERY"/>
    <STRING id = "STR_TODO_LIST_DELETE_ALL_QUERY"/>
    <STRING id = "STR_TODO_LIST_DELETE_OVERDUE_QUERY"/>
    <STRING id = "STR_TODO_LIST_DELETE_OVERDUE"/>
    <STRING id = "STR_ID_TDL_DUETIME"/>



        <STRING id = "STR_TODO_LIST_WRONG_DATE_MSG"/>
    <STRING id = "STR_TODO_START_TIME"/>
    <STRING id = "STR_TODO_END_TIME"/>
    <STRING id = "STR_TODO_LOCATION"/>
        <STRING id = "STR_ID_TDL_CAL"/>
        <STRING id = "STR_ID_TDL_NO_EVENTS"/>
        <STRING id = "STR_ID_TDL_CAL_FULL"/>
    <STRING id = "STR_ID_TDL_ADD_APPOINTMENT"/>
        <STRING id = "STR_ID_TDL_ADD_EVENT"/>
        <STRING id = "STR_ID_TDL_EVENTS"/>

    <STRING id = "STR_TODO_REMINDER"/>
    <STRING id = "STR_TODO_MEETING"/>
    <STRING id = "STR_TODO_COURSE"/>
    <STRING id = "STR_TODO_DATE"/>
    <STRING id = "STR_TODO_CALL"/>
    <STRING id = "STR_TODO_ANNIVERSARY"/>
    <STRING id = "STR_TODO_BIRTHDAY"/>

    <STRING id = "STR_ID_TDL_EVENT_DELETED"/>
    <STRING id = "STR_ID_TDL_EVENT_INVALID_END_TIME"/>
# 124 "temp/res/todolist.c"
    <STRING id = "STR_TODO_NO_CONTENT_TO_SELECT"/>

        <!--End String Resource Area-->
    <!--End String Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->






        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Image Resource Area-->
        <!--Image Resource Area-->

    <IMAGE id = "IMG_TODO_LIST_DATE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\OT_CALEN.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_TIME">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\OT_TIME.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_NOTE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\OT_NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ALARM">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\OT_ALARM.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_REPEAT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\OT_REPT.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_DETAILS">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\OT_DETAILS.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ALARM_TIME">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\OT_ALARMTIME.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_ALARM">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\daily\\\\alarm.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_LOCATION">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\OT_LOCATION.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_PRIORITY">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\\OT_PRIORITY.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_STATUS">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\\OT_PRIORITY.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_DONE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\\daily\\\\done.png"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_UNDONE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\\daily\\\\undone.png"</IMAGE>


        <IMAGE id = "ORGANIZER_MENU_TODOLIST_IMAGEID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\SB_OLIST.bmp"</IMAGE>



    <IMAGE id = "IMG_TODO_LIST_ICON_REMINDER">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\icon\\\\reminder.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_MEETING">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\icon\\\\meeting.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_COURSE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\icon\\\\course.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_DATE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\icon\\\\date.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\icon\\\\call.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_ANNIVERSIRY">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\icon\\\\celebrate.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_BIRTHDAY_REMINDER">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToDoList\\\\icon\\\\birthday.bmp"</IMAGE>


    <!--End Image Resource Area-->
        <!--End Image Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->

    <SCREEN id = "SCR_TDL_EDIT_NOTE"/>
    <SCREEN id = "SCR_TDL_NOTE_OPTION"/>
    <SCREEN id = "SCR_TDL_LIST_TEMPLATE"/>
    <SCREEN id = "SCR_TDL_REMINDER"/>
    <SCREEN id = "SCR_TDL_EDIT_LOCATION"/>
    <SCREEN id = "SCR_BIRTHDAY_OPTION"/>
    <SCREEN id = "SCR_ID_TDL_SEARCH"/>
    <SCREEN id = "SCR_ID_TDL_SEARCH_BY_TIME"/>
    <SCREEN id = "SCR_ID_TDL_SEARCH_BY_NOTE"/>
    <SCREEN id = "SCR_ID_TDL_SEARCH_BY_LOC"/>
    <SCREEN id = "SCR_ID_TDL_SEARCH_RES_LIST"/>
    <SCREEN id = "SCR_ID_TDL_SEARCH_KEYWORD_OPTION"/>
    <SCREEN id = "SCR_ID_TDL_BR_ADD"/>
    <SCREEN id = "SCR_ID_TDL_BR_VIEW"/>
    <SCREEN id = "SCR_ID_TDL_BR_LIST"/>
    <SCREEN id = "SCR_ID_TDL_DIARY_REMINDER_OPTION"/>
    <SCREEN id = "SCR_ID_TDL_HS_SELECT_TYPE"/>
    <SCREEN id = "SCR_ID_TDL_HS_ADD_SELECT_TYPE"/>
    <SCREEN id = "SCR_ID_TDL_ADD_SELECT_TYPE"/>
    <SCREEN id = "SCR_ID_TDL_DELETE_ALL"/>
    <SCREEN id = "SCR_ID_TDL_DELETE_ALL_ABORT"/>
    <SCREEN id = "SCR_ID_TDL_DELET_ALL_PASSCODE"/>
    <SCREEN id = "SCR_ID_TDL_JUMP_TO_DATE"/>
    <SCREEN id = "SCR_ID_TDL_VIEW_UNDONE"/>
    <SCREEN id = "SCR_ID_TDL_JUMP_TO_DATE_TASK_LIST"/>
    <SCREEN id = "SCR_ID_TDL_UNDONE_OPTION_LIST"/>
    <SCREEN id = "SCR_ID_TDL_DAILY_TASK_OPTION"/>
    <SCREEN id = "SCR_ID_TDL_DETAILS_EDIT"/>
    <SCREEN id = "SCR_TDL_TASK_DAILY_LIST"/>
    <SCREEN id = "SCR_TDL_TASK_ALL_LIST"/>
    <SCREEN id = "SCR_TDL_IMPS_LIST"/>
    <SCREEN id = "SCR_TDL_SELECT_CATEGORY"/>
    <SCREEN id = "SCR_TDL_REPEAT_SELECT_TYPE"/>
    <SCREEN id = "SCR_TDL_ALARM_SELECT_TYPE"/>
    <SCREEN id = "SCR_TDL_ALARM_SELECT_CUSTOM"/>
    <SCREEN id = "SCR_TDL_VIEW"/>
    <SCREEN id = "SCR_TDL_TOTAL"/>
        <SCREEN id = "SCR_TDL_EDIT_OPTIONS_LIST"/>

        <!--Screen Group Id-->
        <SCREEN id = "GRP_ID_TDL_BEGIN"/>
        <SCREEN id = "GRP_ID_TDL_MAIN"/>
        <SCREEN id = "GRP_ID_TDL_VIEW"/>
        <SCREEN id = "GRP_ID_TDL_EDIT"/>
        <SCREEN id = "GRP_ID_TDL_EDIT_OPTIONS"/>
    <SCREEN id = "GRP_ID_TDL_SEARCH"/>
    <SCREEN id = "GRP_ID_TDL_REMINDER"/>
    <SCREEN id = "GRP_ID_TDL_GOTO_DATE"/>
    <SCREEN id = "GRP_ID_TDL_DELETE"/>
    <SCREEN id = "GRP_ID_TDL_HOME_SCREEN"/>
    <SCREEN id = "GRP_ID_TDL_BR_SAVE"/>
    <SCREEN id = "GRP_ID_TDL_BR_VIEW"/>
    <SCREEN id = "GRP_ID_TDL_BR_REMINDER"/>
    <SCREEN id = "GRP_ID_TDL_END"/>
    <SCREEN id = "SCR_TDL_CAL_DAILY_LIST"/>
    <SCREEN id = "SCR_TDL_CAL_ALL_LIST"/>

        <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Item Area-->
        <!--Menu Item Area-->
# 249 "temp/res/todolist.c"
        <MENU id="ORGANIZER_TODOLIST_MENU" type="APP_MAIN" parent="MAIN_MENU_ORGANIZER_MENUID"
              str="ORGANIZER_MENU_TODOLIST_STRINGID" img="ORGANIZER_MENU_TODOLIST_IMAGEID" highlight="mmi_tdl_highlight_menu"
              shortcut="ON" shortcut_img="ORGANIZER_MENU_TODOLIST_IMAGEID" launch="mmi_tdl_entry_task_view_all">
    </MENU>

    <MENUITEM id = "MITEM_TODO_LIST_VIEW_UNDONE" str = "STR_TODO_LIST_VIEW_UNDONE"/>
    <MENUITEM id = "MITEM_TODO_LIST_JUMP_TO_DATE" str = "STR_TODO_LIST_JUMP_TO_DATE"/>
    <MENUITEM id = "MITEM_TODO_LIST_DELETE_ALL_OVERDUE" str = "STR_TODO_LIST_DELETE_OVERDUE"/>

    <MENUITEM id = "MITEM_TODO_LIST_VIEW" str = "STR_GLOBAL_VIEW"/>
    <MENUITEM id = "MITEM_TODO_LIST_ADD" str = "STR_GLOBAL_ADD"/>
    <MENUITEM id = "MITEM_TODO_LIST_EDIT" str = "STR_GLOBAL_EDIT"/>
    <MENUITEM id = "MITEM_TODO_LIST_DELETE" str = "STR_GLOBAL_DELETE"/>
    <MENUITEM id = "MITEM_TODO_LIST_DELETE_ALL" str = "STR_GLOBAL_DELETE_ALL"/>
    <MENU id = "MITEM_TODO_LIST_USE_TEMPLATE" type = "OPTION" str = "STR_GLOBAL_USE_TEMPLATE">
    </MENU>


    <MENUITEM id = "MENU_VCLNDR_SEND_BY_FILEMGR" str = "@OID:STR_ID_VOBJ_FORWARD_TO_FILE_MGR"/>

    <MENU id="MENU_VCLNDR_FORWARD" type="OPTION" str="@OID:STR_ID_VCLNDR_FORWARD">

        <MENUITEM id="MENU_VCLNDR_SEND_BY_SMS" str="STR_GLOBAL_AS_TEXT_MESSAGE"/>


        <MENUITEM id="MENU_VCLNDR_SEND_BY_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG"/>







    </MENU>


    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_1" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID default = "TRUE">MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_ADD</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_SEARCH</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL_OVERDUE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_JUMP_TO_DATE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW_UNDONE</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>


    </MENU>


    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_SEARCH" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>


    </MENU>

    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_GOTO_DATE" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_JUMP_TO_DATE</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>


    </MENU>

    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_VEVENT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_ADD</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_SEARCH</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>




        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>


    </MENU>

    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_VIEW_UNDONE" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>

        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>


    </MENU>
# 377 "temp/res/todolist.c"
    <MENU id = "MITEM_TDL_CATEGORY_TYPE" type = "APP_SUB" str = "STR_ID_TDL_CATEGORY">
        <MENUITEM id = "MITEM_TODO_LIST_REMINDER" str = "STR_TODO_REMINDER"/>
        <MENUITEM id = "MITEM_TODO_LIST_MEETING" str = "STR_TODO_MEETING"/>
        <MENUITEM id = "MITEM_TODO_LIST_COURSE" str = "STR_TODO_COURSE"/>
        <MENUITEM id = "MITEM_TODO_LIST_DATE" str = "STR_TODO_DATE"/>
        <MENUITEM id = "MITEM_TODO_LIST_CALL" str = "STR_TODO_CALL"/>
        <MENUITEM id = "MITEM_TODO_LIST_ANNIVERSARY" str = "STR_TODO_ANNIVERSARY"/>
        <MENUITEM id = "MITEM_TODO_LIST_BIRTHDAY" str = "STR_TODO_BIRTHDAY"/>
    </MENU>

    <MENU id = "MITEM_TDL_REPEAT_TYPE" type = "APP_SUB" str = "STR_ID_TDL_CATEGORY">
        <MENUITEM id = "MITEM_TDL_LIST_ONCE" str = "@OID:ALARM_ONCE_STRING"/>
        <MENUITEM id = "MITEM_TDL_LIST_DAILY" str = "@OID:ALARM_EVREYDAY_STRING"/>
        <MENUITEM id = "MITEM_TDL_LIST_DAYS" str = "STR_GLOBAL_CUSTOM"/>
        <MENUITEM id = "MITEM_TDL_LIST_WEEKLY" str = "@OID:ALARM_WEEKLY_STRING"/>
        <MENUITEM id = "MITEM_TDL_LIST_MONTHLY" str = "@OID:ALARM_MONTHLY_STRING"/>
        <MENUITEM id = "MITEM_TDL_LIST_YEARLY" str = "@OID:ALARM_YEARLY_STRING"/>



    </MENU>

    <MENU id = "MITEM_TDL_ALARM_TYPE" type = "APP_SUB" str = "STR_ID_TDL_CATEGORY">
        <MENUITEM id = "MITEM_TDL_ALM_OFF" str = "STR_GLOBAL_OFF"/>
        <MENUITEM id = "MITEM_TDL_ALM_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MITEM_TDL_ALM_BEFORE_5_MINS" str = "STR_TODO_ALARM_BEFORE_5_MINS"/>
        <MENUITEM id = "MITEM_TDL_ALM_BEFORE_10_MINS" str = "STR_TODO_ALARM_BEFORE_10_MINS"/>
        <MENUITEM id = "MITEM_TDL_ALM_BEFORE_15_MINS" str = "STR_TODO_ALARM_BEFORE_15_MINS"/>
        <MENUITEM id = "MITEM_TDL_ALM_BEFORE_30_MINS" str = "STR_TODO_ALARM_BEFORE_30_MINS"/>

    </MENU>

    <MENU id = "MITEM_TDL_EDIT_OPTIONS" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MITEM_TDL_EDIT_OPTIONS_SELECT" str = "STR_ID_TDL_SELECT"/>
        <MENUITEM id = "MITEM_TDL_EDIT_OPTIONS_SAVE" str = "STR_GLOBAL_SAVE"/>
    </MENU>
# 428 "temp/res/todolist.c"
        <!--End Menu Item Area-->
        <!--End Menu Item Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Event proc Area-->
    <!--Event proc Area-->






    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_tdl_reminder_notify_proc"/>
        <RECEIVER id="EVT_ID_SRV_TDL_OP" proc="mmi_tdl_set_reminder_proc"/>


    <!--Event proc Area-->
    <!--Event proc Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

</APP>
