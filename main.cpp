#include <Windows.h>
#include "read_ifs.h"
#include "display.h"
#include "date_time.h"

// 窗口类名称
#define CLASS_NAME L"WindowClass"

// 窗口过程函数
POINT mousePoint;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        OnPaint(hwnd);
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
        // 鼠标左键按下时开始拖动窗口
        int tempa = read(1);
        int tempb = read(3) * read(4) * 3 - read(3);
        if (mousePoint.x <= read(1) &&
            mousePoint.x >= read(3) * read(4) * 3 - read(3))
        {
            WinExec("InfoDP_console.exe", SW_SHOW);
        }
        SendMessage(hwnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
        return 0;
    }
    case WM_MOUSEMOVE:
    {
        mousePoint.x = LOWORD(lParam);
        mousePoint.y = HIWORD(lParam);
    }
    /*case WM_LBUTTONUP:
    {
        return 0;
    }*/
    default:
    {
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 注册窗口类
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    wc.lpszClassName = CLASS_NAME;
    wc.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);

    // 创建窗口
    DWORD style;
    if (read(11))
    {style = WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST;}
    else
    {style = WS_EX_LAYERED | WS_EX_TOOLWINDOW;}
    //是否置于顶层
    if (int alphaValue = read(5))
    {
        HWND BGhwnd = CreateWindowEx(style, CLASS_NAME, L"InfoDP",
            WS_POPUP | WS_VISIBLE | WS_SYSMENU,
            read(2), 0, read(1), read(3), NULL, NULL, hInstance, NULL);
        SetLayeredWindowAttributes(BGhwnd, RGB(0, 0, 0), alphaValue, LWA_ALPHA);
        HWND hwnd = CreateWindowEx(style, CLASS_NAME, L"InfoDP",
            WS_POPUP | WS_VISIBLE | WS_SYSMENU | WS_CHILD,
            read(2), 0, read(1), read(3), BGhwnd, NULL, hInstance, NULL);
        SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    }
    else
    {
        HWND hwnd = CreateWindowEx(style, CLASS_NAME, L"InfoDP",
            WS_POPUP | WS_VISIBLE | WS_SYSMENU,
            read(2), 0, read(1), read(3), NULL, NULL, hInstance, NULL);
        SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    }
    // 设置窗口透明度,为零时，hwnd为主窗口

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        Sleep(read(10));
    }
    return (int) msg.wParam;
}
