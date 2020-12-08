# Define source file lists to SRC_LIST
ifeq ($(strip $(MMIDIR)),plutommi)
  SRC_LIST = vendor\InputMethod\GUOBI\adaptation\src\guobiplutoengine.c
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
  SRC_LIST = vendor\InputMethod\GUOBI\adaptation\src\guobiengine.c
endif

# Define include path lists to INC_DIR
ifeq ($(strip $(MMIDIR)),plutommi)
INC_DIR = applib\mem\include \
          vendor\InputMethod\GUOBI\adaptation\inc \
          plutommi\Framework\IndicLanguages\IndicLanguagesInc \
          plutommi\mmi\inc \
          plutommi\Framework\Interface \
          plutommi \
          plutommi\CUI\Inc\
          plutommi\Framework\InputMethod\Inc \
          plutommi\Framework\InputMethod\Engine\Engine_Inc \
          plutommi\Framework\InputMethod\ui\ui_Inc \
          plutommi\MMI\Setting\SettingInc \
          hal\system\dcmgr\inc
endif

ifeq ($(strip $(MMIDIR)),lcmmi)
INC_DIR = vendor\InputMethod\GUOBI\adaptation\include \
          lcmmi\mmi\IndicLanguages\IndicLanguagesInc \
          lcmmi\mmi\inc \
          lcmmi \
          lcmmi\mmi\InputMethod\Inc \
          lcmmi\mmi\InputMethod\Engine\Engine_Inc \
          lcmmi\mmi\InputMethod\ui\ui_Inc \
          lcmmi\Customer\CustomerInc \
          lcmmi\gui\gui_inc \
          interface\fs \
          lcmmi\mmi\DebugLevels\DebugLevelInc \
          lcmmi\mmi\asyncevents\AsyncEventsInc \
          lcmmi\mmi\Audio\AudioInc \
          lcmmi\mmi\callmanagement\CommonFiles\CommonInc \
          lcmmi\mmi\callmanagement\outgoingcallmanagement\outgoinginc \
          lcmmi\mmi\callmanagement\incomingcallmanagement\incominginc \
          lcmmi\mmi\Calls\CallsInc \
          lcmmi\mmi\Connect\ConnectInc \
          lcmmi\mmi\custresource \
          lcmmi\mmi\DateTime\DateTimeInc \
          lcmmi\mmi\EMS\EmsInc \
          lcmmi\mmi\FontData \
          lcmmi\mmi\framework\tasks\tasksinc \
          lcmmi\mmi\framework\osl\oslInc \
          lcmmi\mmi\framework\history\historyInc \
          lcmmi\mmi\framework\EventHandling\EventsInc \
          lcmmi\mmi\FunAndGames\FunAndGamesInc \
          lcmmi\mmi\gui\gui_inc \
          lcmmi\MMI\IdleScreen\IdleScreenInc \
          lcmmi\MMI\IdleScreen\IdleScreenInc\DemoAppInc\ \
          lcmmi\mmi\inc\ImgID \
          lcmmi\mmi\inc\MenuID \
          lcmmi\mmi\inc\StringID \
          lcmmi\mmi\MainMenu\MainMenuInc \
          lcmmi\mmi\Messages\MessagesInc \
          lcmmi\mmi\miscframework\miscframeworkinc \
          lcmmi\mmi\phonebook\PhonebookInc \
          lcmmi\mmi\sat\satInc \
          lcmmi\mmi\Setting\SettingInc \
          lcmmi\MtkApp\MtkAppInc \
          lcmmi\MtkApp\EngineerMode\EngineerModeInc \
          lcmmi\MtkApp\SoundRecorder\SoundRecorderInc \
          lcmmi\MtkApp\Camera\CameraInc \
          lcmmi\MtkApp\AudioPlayer\AudioPlayerInc \
          lcmmi\MtkApp\FileMgr\FileMgrInc \
          lcmmi\MtkApp\GDI\GDIInc \
          lcmmi\MMI\CommonScreens\CommonScreensInc \
          lcmmi\mmi\BIDI\BIDIInc
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = MMI_ON_HARDWARE_P \
            __EMS__ \
            SIM_APP_TOOLKIT \
            TETRIS_GAME_APP \
            CM_APPLICATION_ENABLE \
            MESSAGES_APPLICATION \
            __UCS2_ENCODING \
            CELLBROADCAST_APP \
            __CB__ \
            VM_SUPPORT \
            SHORTCUTS_APP \
          	EMS_LITTLE_ENDIAN \
            EMS_MEM_MANAGEMENT 
            

 
