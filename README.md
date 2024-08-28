**布灵键鼠** buke_km Q群: 972847677  

这是免费版本，使用时需要联网。
This is the free version, which requires internet connection to use.  

若有无法加载的系统，备好iso/gho/vmware包，发给本人，有时间进行解决。   
If there is a system that cannot be loaded, prepare the iso/gho/vmware package and send it to me for resolution when you have time.  
邮箱(email): 1475419685@qq.com  

# 介绍(Introduction)
一款windows平台下键盘鼠标模拟库。支持驱动键鼠+HID键鼠。
A keyboard and mouse simulation library for the Windows platform.
Support driver keyboard and mouse+HID keyboard and mouse.

# 测试工具(Testing tool)
![Image](https://github.com/user-attachments/assets/e56f8354-9565-47eb-909f-15c065aa713c)

# 使用文档(Document)
加载DLL  =>  调用Init  =>  调用键鼠接口
Load dll  =>  Call the init function  =>  Call others

# 接口函数(Interface)
## Init
初始化键鼠库，成功初始化后才能使用其它函数。
Initialize the keyboard and mouse library, and only after successful initialization can other functions be used.

| 参数(Parameters) | 类型(Type) | 说明(Description) |
| ---|---|--- |
| pwd | int32 | 直接填0即可(fill in 0) |
| key | int8 | 直接填0即可(fill in 0) |

返回值: 成功返回1 失败返回0
Return value: Success returns 1, failure returns 0

## SetScale
设置系统缩放比, 不设置此项将智能判断缩放比, 如果错误, 可手动进行设置。
Set the system zoom ratio. Not setting this option will intelligently determine the zoom ratio. If it is incorrect, it can be manually set.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
 | scale | float | 缩放比为125%, 填写1.25。缩放比为150, 填写1.5 Zoom ratio is 125%, fill in 1.25. Scale ratio is 150, fill in 1.5 | 

返回值: 无
Return value: none

## SetMouseMoveTrack
设置鼠标移动轨迹, 不设置此项鼠标是瞬间移动到指定位置。
Set the mouse movement trajectory. If not set, the mouse will instantly move to the specified position.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
 | delay | int32 | 取值范围1-1000, 0表示关闭, 数值越小速度越快。The value range is 1-1000, with 0 indicating shutdown, and the smaller the value, the faster the speed. | 
 | step | int32 | 取值范围0.01-0.20, 数值越小移动的步数越多。 | The value range is 0.01-0.20, and the smaller the value, the more steps it moves. | 

返回值: 无
Return value: none

## MouseMove
鼠标移动到屏幕指定坐标。
Move the mouse to the specified coordinates on the screen.

| 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
| x | int32 | 横坐标(x-axis) | 
| y | int32 | 纵坐标(y-axis) | 

返回值: 无
Return value: none

## MouseMoveR
以当前坐标为起始点, 向指定坐标移动指定距离。
Starting from the current coordinates, move a specified distance towards the designated coordinates.

参数(Parameters) | 类型(Type)	 | 说明(Description) | 
| ---|---|--- |
 | rx	 | int32 | 横坐标(x-axis) | 
 | ry	 | int32 | 纵坐标(y-axis) | 

返回值: 无
Return value: none

## MouseLeftDown
鼠标左键按下。
Just as its name implies.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
返回值: 无
Return value: none

## MouseLeftUp
鼠标左键抬起。
Just as its name implies.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
返回值: 无
Return value: none

## MouseRightDown
鼠标右键按下。
Just as its name implies.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
返回值: 无
Return value: none

## MouseRightUp
鼠标右键抬起。
Just as its name implies.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
返回值: 无
Return value: none

## MouseMiddleDown
鼠标中键按下。
Just as its name implies.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
返回值: 无
Return value: none

## MouseMiddleUp
鼠标中键抬起。
Just as its name implies.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
返回值: 无
Return value: none

## MouseWheelDown
鼠标滚轮向下滚动。
Just as its name implies.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
返回值: 无
Return value: none

## MouseWheelUp
鼠标滚轮向上滚动。
Just as its name implies.

 | 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
返回值: 无
Return value: none

## KeyboardDown
键盘按下。
Just as its name implies.

| 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
| key | int32 | 参见键鼠测试工具上对应键码, 其实就是VK虚拟键码 Refer to the corresponding key code on the Testing tool. | 

返回值: 无
Return value: none

## KeyboardUp
键盘抬起。
Just as its name implies.

| 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
| key | int32 | 参见键鼠测试工具上对应键码, 其实就是VK虚拟键码 Refer to the corresponding key code on the Testing tool. | 

返回值: 无
Return value: none

## InputString
自动模拟按出指定字符串的效果。
Automatically simulate the effect of pressing a specified string.

| 参数(Parameters) | 类型(Type) | 说明(Description) | 
| ---|---|--- |
| str	 | char* | 一段ansi字符串，例如: 1234XX@Abc.com  An ANSI string, for example: 1234XX@Abc.com | 

返回值: 无
Return value: none
