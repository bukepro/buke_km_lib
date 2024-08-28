#include "BukeKmInterface.h"
#include <Windows.h>

int main() {
	//buke_km64.dll or buke_km32.dll
	bool b = buke_LoadDll("buke_km64.dll");
	if (!b) {
		MessageBoxA(NULL, "failed", "", MB_OK | MB_TOPMOST);
		return -1;
	}

	buke_MouseMove(100, 100);
	Sleep(2000);
	buke_MouseLeftDown();
	Sleep(20);
	buke_MouseLeftUp();
	Sleep(1000);
	buke_KeyboardDown(91);
	Sleep(20);
	buke_KeyboardUp(91);
	Sleep(2000);
	buke_InputString("123@Abc.com");
	MessageBoxA(NULL, "ok", "", MB_OK | MB_TOPMOST);
	return 0;
}