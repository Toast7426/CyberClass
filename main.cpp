#include <Windows.h>
#include "read_ifs.h"
#include "display.h"
#include "date_time.h"
//#include <iostream>
//using namespace std;
//#pragma comment(linker,"/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")

// ����������
#define CLASS_NAME L"WindowClass"

// ���ڹ��̺���
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    case WM_PAINT:
    {
        OnPaint(hwnd);
        return 0;
    }
    case WM_LBUTTONDBLCLK:
    {
        // ���˫��ʱ�رմ���
        PostQuitMessage(0);
        return 0;
    }
    case WM_LBUTTONDOWN:
    {
        // ����������ʱ��ʼ�϶�����
        SendMessage(hwnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
        return 0;
    }
    default:
    {
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ע�ᴰ����
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    wc.lpszClassName = CLASS_NAME;
    wc.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);

    // ��������
    DWORD style;
    if (read(11) == 1)
    {
        style = WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST;
    }
    else
    {
        style = WS_EX_LAYERED | WS_EX_TOOLWINDOW;
    }
    HWND hwnd = CreateWindowEx(
        style,
        CLASS_NAME,
        L"InfoDP",
        WS_POPUP | WS_VISIBLE | WS_SYSMENU,
        read(2),
        0,
        read(1),
        read(3),
        NULL,
        NULL,
        hInstance,
        NULL);

    //AllowSetForegroundWindow(hwnd);

    // ���ô���͸����
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // ��Ϣѭ��
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        Sleep(read(10));
    }
    return 0;
}
