#pragma once

#ifndef PLUGIN_MSG
#define PLUGIN_MSG (WM_APP+1000)
#endif

typedef enum _tagPLUGIN_MSG_ID
{
	//Plug-in ->Modis UI
	PM_OPENED,	//Plug-in opened
	PM_CLOSED,	//Plug-in closed
	PM_WRITE_READY,	//Plug-in write data to MoDIS ready
	PM_READ_READY,	//Plug-in ready to read data from MoDIS
	PM_HIDE_ALL,	//Hide all windows
	PM_SHOW_ALL,	//Show all hide windows

	//Modis UI -> Plug-in
	PM_MOVE, 

}	PLUGIN_MSG_ID;

typedef struct
{
	UINT uiInt;
	plugin_information info;
}	PLUG_IN_INT_PARAM;