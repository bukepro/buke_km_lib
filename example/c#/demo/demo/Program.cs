using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace demo
{
    internal class Program
    {
        static void Main(string[] args)
        {
            if(!buke_km.Init(0, 0))
            {
                Console.WriteLine("Failed");
                return;
            }

            buke_km.MouseMove(100, 100);
            System.Threading.Thread.Sleep(2000);
            buke_km.MouseLeftDown();
            System.Threading.Thread.Sleep(20);
            buke_km.MouseLeftUp();
            System.Threading.Thread.Sleep(1000);
            buke_km.KeyboardDown(91);
            System.Threading.Thread.Sleep(20);
            buke_km.KeyboardUp(91);
            System.Threading.Thread.Sleep(2000);
            buke_km.InputString("123@Abc.com");

        }
    }

    public class buke_km
    {
        public const string buke_km_dll_name = "buke_km32.dll";
        [DllImport(buke_km_dll_name, EntryPoint = "Init", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Init(Int32 pwd, byte key);

        [DllImport(buke_km_dll_name, EntryPoint = "SetScale", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetScale(float scale);

        [DllImport(buke_km_dll_name, EntryPoint = "SetMouseMoveTrack", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetMouseMoveTrack(Int32 delay, Int32 step);

        [DllImport(buke_km_dll_name, EntryPoint = "MouseMove", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseMove(Int32 x, Int32 y);

        [DllImport(buke_km_dll_name, EntryPoint = "MouseMoveR", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseMoveR(Int32 x, Int32 y);

        [DllImport(buke_km_dll_name, EntryPoint = "MouseLeftDown", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseLeftDown();

        [DllImport(buke_km_dll_name, EntryPoint = "MouseLeftUp", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseLeftUp();

        [DllImport(buke_km_dll_name, EntryPoint = "MouseRightDown", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseRightDown();

        [DllImport(buke_km_dll_name, EntryPoint = "MouseRightUp", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseRightUp();

        [DllImport(buke_km_dll_name, EntryPoint = "MouseMiddleDown", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseMiddleDown();

        [DllImport(buke_km_dll_name, EntryPoint = "MouseMiddleUp", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseMiddleUp();

        [DllImport(buke_km_dll_name, EntryPoint = "MouseWheelDown", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseWheelDown();

        [DllImport(buke_km_dll_name, EntryPoint = "MouseWheelUp", CallingConvention = CallingConvention.Cdecl)]
        public static extern void MouseWheelUp();

        [DllImport(buke_km_dll_name, EntryPoint = "KeyboardDown", CallingConvention = CallingConvention.Cdecl)]
        public static extern void KeyboardDown(Int32 key);

        [DllImport(buke_km_dll_name, EntryPoint = "KeyboardUp", CallingConvention = CallingConvention.Cdecl)]
        public static extern void KeyboardUp(Int32 key);

        [DllImport(buke_km_dll_name, EntryPoint = "InputString", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void InputString(string str);

    }
}

