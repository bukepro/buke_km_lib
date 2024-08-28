#include "BukeKmInterface.h"
#include <iostream>
#include <string>
#include <Windows.h>

#define BUKE_KM_FUN_INIT "Init"
#define BUKE_KM_FUN_SET_SCALE "SetScale"
#define BUKE_KM_FUN_SET_MOUSE_MOVE_TRACK "SetMouseMoveTrack"
#define BUKE_KM_FUN_MOUSE_MOVE "MouseMove"
#define BUKE_KM_FUN_MOUSE_MOVE_R "MouseMoveR"
#define BUKE_KM_FUN_MOUSE_LEFT_DOWN "MouseLeftDown"
#define BUKE_KM_FUN_MOUSE_LEFT_UP "MouseLeftUp"
#define BUKE_KM_FUN_MOUSE_RIGHT_DOWN "MouseRightDown"
#define BUKE_KM_FUN_MOUSE_RIGHT_UP "MouseRightUp"
#define BUKE_KM_FUN_MOUSE_MIDDLE_DOWN "MouseMiddleDown"
#define BUKE_KM_FUN_MOUSE_MIDDLE_UP "MouseMiddleUp"
#define BUKE_KM_FUN_MOUSE_MOUSE_4_DOWN "Mouse4Down"
#define BUKE_KM_FUN_MOUSE_MOUSE_4_UP "Mouse4Up"
#define BUKE_KM_FUN_MOUSE_MOUSE_5_DOWN "Mouse5Down"
#define BUKE_KM_FUN_MOUSE_MOUSE_5_UP "Mouse5Up"
#define BUKE_KM_FUN_MOUSE_MOUSE_WHEEL_DOWN "MouseWheelDown"
#define BUKE_KM_FUN_MOUSE_MOUSE_WHEEL_UP "MouseWheelUp"

#define BUKE_KM_FUN_KEYBOARD_DOWN "KeyboardDown"
#define BUKE_KM_FUN_KEYBOARD_UP "KeyboardUp"

#define BUKE_KM_FUN_INPUT_STRING "InputString"

typedef bool(__cdecl* PFNInit)(unsigned int pwd, unsigned char key);
typedef void(__cdecl* PFNSetScale)(float scale);
typedef void(__cdecl* PFNSetMouseMoveTrack)(int delay, int step);
typedef bool(__cdecl* PFNMouseMove)(int, int);
typedef void(__cdecl* PFNMouseMoveR)(int rx, int ry);
typedef void(__cdecl* PFNMouseLeftDown)();
typedef void(__cdecl* PFNMouseLeftUp)();
typedef void(__cdecl* PFNMouseRightDown)();
typedef void(__cdecl* PFNMouseRightUp)();
typedef void(__cdecl* PFNMouseMiddleDown)();
typedef void(__cdecl* PFNMouseMiddleUp)();
typedef void(__cdecl* PFNMouse4Down)();
typedef void(__cdecl* PFNMouse4Up)();
typedef void(__cdecl* PFNMouse5Down)();
typedef void(__cdecl* PFNMouse5Up)();
typedef void(__cdecl* PFNMouseWheelDown)();
typedef void(__cdecl* PFNMouseWheelUp)();

typedef void(__cdecl* PFNKeyboardDown)(unsigned short vk);
typedef void(__cdecl* PFNKeyboardUp)(unsigned short vk);
typedef void(__cdecl* PFNInputString)(const char*);

HMODULE g_dll = nullptr;

PFNInit g_pfnInit = nullptr;
PFNSetScale g_pfnSetScale = nullptr;
PFNSetMouseMoveTrack g_pfnSetMouseMoveTrack = nullptr;
PFNMouseMove g_pfnMouseMove = nullptr;
PFNMouseMoveR g_pfnMouseMoveR = nullptr;
PFNMouseLeftDown g_pfnMouseLeftDown = nullptr;
PFNMouseLeftUp g_pfnMouseLeftUp = nullptr;
PFNMouseRightDown g_pfnMouseRightDown = nullptr;
PFNMouseRightUp g_pfnMouseRightUp = nullptr;
PFNMouseMiddleDown g_pfnMouseMiddleDown = nullptr;
PFNMouseMiddleUp g_pfnMouseMiddleUp = nullptr;
PFNMouse4Down g_pfnMouse4Down = nullptr;
PFNMouse4Up g_pfnMouse4Up = nullptr;
PFNMouse5Down g_pfnMouse5Down = nullptr;
PFNMouse5Up g_pfnMouse5Up = nullptr;
PFNMouseWheelDown g_pfnMouseWheelDown = nullptr;
PFNMouseWheelUp g_pfnMouseWheelUp = nullptr;

PFNKeyboardDown g_pfnKeyboardDown = nullptr;
PFNKeyboardUp g_pfnKeyboardUp = nullptr;

PFNInputString g_pfnInputString = nullptr;


bool buke_LoadDll(const char* filepath) {
	if (g_dll) {
		return true;
	}

	HMODULE hDll = LoadLibraryA(filepath);
	if (!hDll) {
		std::string str_err = "Failed to load dll, err: " + std::to_string(GetLastError());
		MessageBoxA(NULL, str_err.c_str(), "", MB_OK);
		return false;
	}
	g_pfnInit = (PFNInit)GetProcAddress(hDll, BUKE_KM_FUN_INIT);
	g_pfnSetScale = (PFNSetScale)GetProcAddress(hDll, BUKE_KM_FUN_SET_SCALE);
	g_pfnSetMouseMoveTrack = (PFNSetMouseMoveTrack)GetProcAddress(hDll, BUKE_KM_FUN_SET_MOUSE_MOVE_TRACK);

	g_pfnMouseMove = (PFNMouseMove)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MOVE);
	g_pfnMouseMoveR = (PFNMouseMoveR)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MOVE_R);
	g_pfnMouseLeftDown = (PFNMouseLeftDown)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_LEFT_DOWN);
	g_pfnMouseLeftUp = (PFNMouseLeftUp)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_LEFT_UP);
	g_pfnMouseRightDown = (PFNMouseRightDown)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_RIGHT_DOWN);
	g_pfnMouseRightUp = (PFNMouseRightUp)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_RIGHT_UP);
	g_pfnMouseMiddleDown = (PFNMouseMiddleDown)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MIDDLE_DOWN);
	g_pfnMouseMiddleUp = (PFNMouseMiddleUp)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MIDDLE_UP);
	g_pfnMouse4Down = (PFNMouse4Down)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MOUSE_4_DOWN);
	g_pfnMouse4Up = (PFNMouse4Up)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MOUSE_4_UP);
	g_pfnMouse5Down = (PFNMouse5Down)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MOUSE_5_DOWN);
	g_pfnMouse5Up = (PFNMouse5Up)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MOUSE_5_UP);
	g_pfnMouseWheelDown = (PFNMouseWheelDown)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MOUSE_WHEEL_DOWN);
	g_pfnMouseWheelUp = (PFNMouseWheelUp)GetProcAddress(hDll, BUKE_KM_FUN_MOUSE_MOUSE_WHEEL_UP);

	g_pfnKeyboardDown = (PFNKeyboardDown)GetProcAddress(hDll, BUKE_KM_FUN_KEYBOARD_DOWN);
	g_pfnKeyboardUp = (PFNKeyboardUp)GetProcAddress(hDll, BUKE_KM_FUN_KEYBOARD_UP);

	g_pfnInputString = (PFNInputString)GetProcAddress(hDll, BUKE_KM_FUN_INPUT_STRING);

	if (!g_pfnInit ||
		!g_pfnMouseMove || !g_pfnMouseMoveR ||
		!g_pfnMouseLeftDown || !g_pfnMouseLeftUp || !g_pfnMouseRightDown || !g_pfnMouseRightUp || !g_pfnMouseMiddleDown || !g_pfnMouseMiddleUp ||
		!g_pfnMouse4Down || !g_pfnMouse4Up || !g_pfnMouse5Down || !g_pfnMouse5Up ||
		!g_pfnMouseWheelDown || !g_pfnMouseWheelUp ||
		!g_pfnInputString) {
		FreeLibrary(hDll);
		return false;
	}

	if (!g_pfnInit(0, 0)) {
		FreeLibrary(hDll);
		return false;
	}

	g_dll = hDll;
	return true;
}

void buke_SetScale(float scale) {
	g_pfnSetScale(scale);
}

void buke_SetMouseMoveTrack(int delay, int step) {
	g_pfnSetMouseMoveTrack(delay, step);
}

void buke_MouseMove(int x, int y) {
	g_pfnMouseMove(x, y);
}

void buke_MouseMoveR(int rx, int ry) {
	g_pfnMouseMoveR(rx, ry);
}

void buke_MouseLeftDown() {
	g_pfnMouseLeftDown();
}

void buke_MouseLeftUp() {
	g_pfnMouseLeftUp();
}

void buke_MouseRightDown()
{
	g_pfnMouseRightDown();
}

void buke_MouseRightUp()
{
	g_pfnMouseRightUp();
}

void buke_Mouse4Down()
{
	g_pfnMouse4Down();
}

void buke_Mouse4Up()
{
	g_pfnMouse4Up();
}

void buke_Mouse5Down() {
	g_pfnMouse5Down();
}

void buke_Mouse5Up() {
	g_pfnMouse5Up();
}

void buke_MouseMiddleDown() {
	g_pfnMouseMiddleDown();
}

void buke_MouseMiddleUp() {
	g_pfnMouseMiddleUp();
}

void buke_MouseWheelDown() {
	g_pfnMouseWheelDown();
}

void buke_MouseWheelUp() {
	g_pfnMouseWheelUp();
}

void buke_KeyboardDown(unsigned short  vk) {
	g_pfnKeyboardDown(vk);
}

void buke_KeyboardUp(unsigned short  vk) {
	g_pfnKeyboardUp(vk);
}

void buke_InputString(const char* str) {
	g_pfnInputString(str);
}