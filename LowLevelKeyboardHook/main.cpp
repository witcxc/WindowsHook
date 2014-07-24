//**************************************
// Name: LowLevel Windows API Keyboard Hook
// Description:Sets a global keyboard hook in the current process low level using the Windows API
// By: aaron blair
//
//This code is copyrighted and has// limited warranties.Please see http://www.Planet-Source-Code.com/vb/scripts/ShowCode.asp?txtCodeId=11920&lngWId=3//for details.//**************************************

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
// function declaration.
LRESULT CALLBACK LowLevelKeyboardProc( int nCode, WPARAM wParam, LPARAM lParam );
int main()
{
	// Retrieve the applications instance
HINSTANCE appInstance = GetModuleHandle(NULL);
	// Set a global Windows Hook to capture keystrokes.
	SetWindowsHookEx( WH_KEYBOARD_LL, LowLevelKeyboardProc, appInstance, 0 );
MSG msg;
while(GetMessage(&msg, NULL, 0, 0) > 0)
{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
}
 
return 0;
}
LRESULT CALLBACK LowLevelKeyboardProc( int nCode, WPARAM wParam, LPARAM lParam )
{
	// Declare our pointer to the KBDLLHOOKSTRUCT
	KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
	switch( wParam )
	{
	case WM_KEYUP: // When the key has been pressed and released
		{
			switch( pKeyBoard->vkCode ) // Check to see what key has been pushed
			{
			//case VK_RETURN: // The return/enter key has been pressed
			//	DWORD timestamp = pKeyBoard->time; // This shows our timestamp when the key was pushed.
			//	printf("Enter Key Pressed %u", timestamp ); // Show us when the key has been pushed
			//break;
			default:
				printf("%c  ",pKeyBoard->vkCode);
			}
		}
	default:
		return CallNextHookEx( NULL, nCode, wParam, lParam );
	}
	return 0;
}