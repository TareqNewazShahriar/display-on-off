#include "stdafx.h"
#include <string.h>
#include <Windows.h>

enum class DISPLAY_STATUSES { ON = -1, LOW_POWER = 1, OFF = 2 };

int main(int argc, char *argv[])
{
	char param1[50] = "";

	if (argc > 1)
		strcpy(param1, strupr(argv[1]));
	else
		strcpy(param1, "off");

	if (strcmpi(param1, "off") == 0)
	{
		// Sleep(500);
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)DISPLAY_STATUSES::OFF);
	}
	else if (strcmpi(param1, "on") == 0) // pointless
	{
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)DISPLAY_STATUSES::ON);
	}
	else if (strcmpi(param1, "standby") == 0 || strcmpi(param1, "low") == 0 || strcmpi(param1, "low power") == 0 || strcmpi(param1, "lowpower") == 0) // i dont know whats going on
	{
		//Sleep(500); // Eliminate user's interaction for 500 ms
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)DISPLAY_STATUSES::LOW_POWER);
	}
	else if (strcmpi(param1, "help") == 0 || strcmpi(param1, "/help") == 0)
		puts("parameters: on / off / standby");

	exit(0);
}
