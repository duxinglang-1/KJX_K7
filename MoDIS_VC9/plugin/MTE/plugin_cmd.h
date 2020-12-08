//Plugin
#include "plugin.h"
#include "plugin_hlpr.h"

BOOL RunCmd(HWND hParent, MTE_CMD cmd, mte_data_struct& dataRead, void* pIntData)
{
	BOOL bRet = TRUE;
	SMHandle handle = NULL;

	do
	{
		handle = CreateShareMem(PLUGIN_NAME_MTE, sizeof(mte_data_struct));
		if(NULL == handle)
		{
			bRet = FALSE;
			break;
		}

		/* Write mte cmd flag*/
		mte_data_struct data;
		ZeroMemory(&data, sizeof(data));
		data.cmd = cmd;
		if(!Write(handle, (void*)(&data), sizeof(data)))
		{
			bRet = FALSE;
			break;
		}

		/*Send a interrupt to MoDIS to notify it to write data*/
		::SendMessage(hParent, PLUGIN_MSG, (WPARAM)PM_READ_READY, (LPARAM)pIntData);

		/*Wait for "Write COMPLETE'" event from MoDIS*/
		HANDLE handleEvent = CreateEventA(NULL, TRUE, FALSE, PLUGIN_EVENT_MTE);
		while (TRUE)
		{
			DWORD dRet=::MsgWaitForMultipleObjects(1, &handleEvent, FALSE, INFINITE, QS_ALLINPUT);
			if (WAIT_OBJECT_0+1 == dRet)
			{
				MSG msg;
				while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			else
			{
				break;
			}	
		}
		ResetEvent(handleEvent);
		CloseHandle(handleEvent);
		if(!bRet)
			break;

		/* Read mte data*/
		ZeroMemory(&dataRead, sizeof(dataRead));
		if(!Read(handle, (void*)(&dataRead), sizeof(dataRead)))
		{
			bRet = FALSE;
			break;
		}

		/*Clear SM data*/
		ZeroMemory(&data, sizeof(data));
		if(!Write(handle, (void*)(&data), sizeof(data)))
		{
			bRet = FALSE;
			break;
		}

	}while(0);

	if(NULL != handle)
		DestroyShareMem(handle);

	return bRet;
}