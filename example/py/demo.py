from ctypes import *
import time

buke_km = CDLL('buke_km64.dll', winmode=0)

res = buke_km.Init(0,0)
if res == False:
	print("failed")
	exit()

buke_km.MouseMove(100, 100)
time.sleep(2);
buke_km.MouseLeftDown();
time.sleep(0.02);
buke_km.MouseLeftUp();
time.sleep(1);
buke_km.KeyboardDown(91);
time.sleep(0.02);
buke_km.KeyboardUp(91);
time.sleep(2);
buke_km.InputString(b"123@Abc.com");

