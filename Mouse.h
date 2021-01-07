#include <windows.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
HHOOK hMouseHook;

LRESULT WINAPI GetMouse(int nCode, WPARAM wParam, LPARAM lParam){
	MSLLHOOKSTRUCT * pMouseStruct = (MSLLHOOKSTRUCT *)lParam; // WH_MOUSE_LL struct

	FILE *MOUSE;
	MOUSE = fopen("mouse.txt", "a");

	if (nCode == 0)	{ // we have information in wParam/lParam ? If yes, let's check it:
		if (pMouseStruct != NULL){ // Mouse struct contain information?
			switch (wParam){

			case WM_LBUTTONUP:{
				string result = "LEFT CLICK UP. Mouse Coordinates: x = " + to_string(pMouseStruct->pt.x) + " | y = " + to_string(pMouseStruct->pt.y)+"\n";
				fprintf(MOUSE, "%s",result.c_str());

			}break;

			case WM_LBUTTONDOWN:{
				string result = "LEFT CLICK DOWN. Mouse Coordinates: x = " + to_string(pMouseStruct->pt.x) + " | y = " + to_string(pMouseStruct->pt.y)+"\n";
				fprintf(MOUSE, "%s",result.c_str());
			}break;

			case WM_RBUTTONUP:{
				string result = "RIGHT CLICK UP. Mouse Coordinates: x = " + to_string(pMouseStruct->pt.x) + " | y = " + to_string(pMouseStruct->pt.y)+"\n";
				fprintf(MOUSE, "%s",result.c_str());
			}break;

			case WM_RBUTTONDOWN:{
				string result = "RIGHT CLICK DOWN. Mouse Coordinates: x = " + to_string(pMouseStruct->pt.x) + " | y = " + to_string(pMouseStruct->pt.y)+"\n";
				fprintf(MOUSE, "%s",result.c_str());
			}break;

			}
		}
	}

	fclose(MOUSE);

	return CallNextHookEx(hMouseHook, nCode, wParam, lParam);
}

