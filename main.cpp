#include <Windows.h>
#include "read_ifs.h"
#include "display.h"

// 窗口类名称
#define WINDOW_CLASS_NAME L"WindowClass"

const short sleepTime_S = ReadDBP(10) * 1000;
DWORD TIMER = 0;  // 两个关于时间的全局变量，使WM_PAINT消息大部分时间只响应而不实际处理
// 窗口过程函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg)
    {
    case WM_PAINT:
    {
        // 控制数据刷新速度，减少读取硬盘
        if (GetTickCount() > TIMER + sleepTime_S)
        {
            OnPaint(hwnd);
            TIMER = GetTickCount();
        }
        Sleep(16);  // 防止拖动窗口时cpu占用过高
        return 0;
    }
    case WM_LBUTTONDBLCLK:
    {
        // 鼠标双击时关闭窗口
        PostQuitMessage(0);
        return 0;
    }
    case WM_LBUTTONDOWN:
    {
        // 点击省略号时
        POINT mousePoint;
        mousePoint.x = LOWORD(lParam);
        mousePoint.y = HIWORD(lParam);
        if (mousePoint.x <= ReadDBP(1) &&
            mousePoint.x >= ReadDBP(3) * ReadDBP(4) * 3 - ReadDBP(3))
        {
            STARTUPINFO si = { sizeof(si) };
            PROCESS_INFORMATION pi;
            TCHAR szCommandLine[] = TEXT("InfoDP_console");
            CreateProcess(NULL, szCommandLine, NULL, NULL, false, CREATE_NEW_PROCESS_GROUP, NULL, NULL, &si, &pi);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
        // 鼠标左键按下时开始拖动窗口
        SendMessage(hwnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
        return 0;
    }
    default:
    {
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    }
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {
    // 注册窗口类
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    wc.lpszClassName = WINDOW_CLASS_NAME;
    wc.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);
    // 创建窗口
    // 是否置于顶层
    DWORD style;
    if (ReadDBP(11))
    {style = WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST;}
    else
    {style = WS_EX_LAYERED | WS_EX_TOOLWINDOW;}
    // 是否启用二层窗口提供半透明背景
    // 窗口不透明度为零时，hwnd为主窗口
    if (int alphaValue = ReadDBP(5))
    {
        HWND BGhwnd = CreateWindowEx(
            style, WINDOW_CLASS_NAME, L"InfoDP",
            WS_POPUP | WS_VISIBLE | WS_SYSMENU,
            ReadDBP(2), 0, ReadDBP(1), ReadDBP(3), NULL, NULL, hInstance, NULL);
        SetLayeredWindowAttributes(BGhwnd, RGB(0, 0, 0), alphaValue, LWA_ALPHA);
        HWND hwnd = CreateWindowEx(
            style, WINDOW_CLASS_NAME, L"InfoDP",
            WS_POPUP | WS_VISIBLE | WS_SYSMENU | WS_CHILD,
            ReadDBP(2), 0, ReadDBP(1), ReadDBP(3), BGhwnd, NULL, hInstance, NULL);
        SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    }
    else
    {
        HWND hwnd = CreateWindowEx(style, WINDOW_CLASS_NAME, L"InfoDP",
            WS_POPUP | WS_VISIBLE | WS_SYSMENU,
            ReadDBP(2), 0, ReadDBP(1), ReadDBP(3), NULL, NULL, hInstance, NULL);
        SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    }
    

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}
