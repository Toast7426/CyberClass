#include <Windows.h>
#include "read_ifs.h"
#include "display.h"

// ����������
#define WINDOW_CLASS_NAME L"WindowClass"

const short sleepTime_S = ReadDBP(10) * 1000;
DWORD TIMER = 0;  // ��������ʱ���ȫ�ֱ�����ʹWM_PAINT��Ϣ�󲿷�ʱ��ֻ��Ӧ����ʵ�ʴ���
// ���ڹ��̺���
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg)
    {
    case WM_PAINT:
    {
        // ��������ˢ���ٶȣ����ٶ�ȡӲ��
        if (GetTickCount() > TIMER + sleepTime_S)
        {
            OnPaint(hwnd);
            TIMER = GetTickCount();
        }
        Sleep(16);  // ��ֹ�϶�����ʱcpuռ�ù���
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
        // ���ʡ�Ժ�ʱ
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

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {
    // ע�ᴰ����
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    wc.lpszClassName = WINDOW_CLASS_NAME;
    wc.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);
    // ��������
    // �Ƿ����ڶ���
    DWORD style;
    if (ReadDBP(11))
    {style = WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST;}
    else
    {style = WS_EX_LAYERED | WS_EX_TOOLWINDOW;}
    // �Ƿ����ö��㴰���ṩ��͸������
    // ���ڲ�͸����Ϊ��ʱ��hwndΪ������
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
    

    // ��Ϣѭ��
    MSG msg;
    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}
