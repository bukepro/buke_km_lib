#ifndef BUKE_KM_INTERFACE_H
#define BUKE_KM_INTERFACE_H

extern bool buke_LoadDll(const char* filepath);

extern void buke_SetScale(float scale);
extern void buke_SetMouseMoveTrack(int delay, int step);

extern void buke_MouseMove(int x, int y);
extern void buke_MouseMoveR(int rx, int ry);
extern void buke_MouseLeftDown();
extern void buke_MouseLeftUp();
extern void buke_MouseRightDown();
extern void buke_MouseRightUp();
extern void buke_Mouse4Down();
extern void buke_Mouse4Up();
extern void buke_Mouse5Down();
extern void buke_Mouse5Up();
extern void buke_MouseMiddleDown();
extern void buke_MouseMiddleUp();
extern void buke_MouseWheelDown();
extern void buke_MouseWheelUp();

extern void buke_KeyboardDown(unsigned short vk);
extern void buke_KeyboardUp(unsigned short  vk);

extern void buke_InputString(const char* str);

#endif
