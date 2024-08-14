#include <Windows.h>
#include <string>
using namespace std;
#include "read_ifs.h"
#include "date_time.h"

wstring string2LPCWSTR(const string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    wstring r(buf);
    delete[] buf;
    return r;
}

void OnPaint(HWND hWnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    SetBkColor(hdc, RGB(0, 0, 0));//������ɫ
    SetBkMode(hdc, TRANSPARENT);
    HFONT hFont = CreateFont(
        -read(6),
        -read(6) / 2,
        0, 0,
        400,
        0, 0, 0,
        GB2312_CHARSET,
        0, 0, 0, 0,
        L"Microsoft YaHei UI");
    HGDIOBJ nOldFont = SelectObject(hdc, hFont);

    for (int i = 1; i <= read(4); i++)
    {
        string course;//�γ�����
        fileManagerR(dateRead(), i, &course);
        wstring wstr = string2LPCWSTR(course);
        LPCWSTR l_course = wstr.c_str();
        //��stringת��ΪLPCWSTR
        int lin01;
        lin01 = hourRead();
        if (fileManagerT(dateRead(), i, true)/*�γ̿�ʼʱ��*/ <=
            hourRead() * 100 + minuteRead()/*����ʱ��*/ &&
            hourRead() * 100 + minuteRead()/*����ʱ��*/ <=
            fileManagerT(dateRead(), i, false)/*�γ̽���ʱ��*/)
        {
            SetTextColor(hdc, RGB(read(7), read(8), read(9)));//������ɫ
            int tex = read(3) * 3 * i - 3 * read(3) + read(3) / 10;
            TextOut(hdc, tex, 0, l_course, 2);
        }
        else
        {
            SetTextColor(hdc, RGB(255, 255, 255));//������ɫ
            int tex = read(3) * 3 * i - 3 * read(3) + read(3) / 10;
            TextOut(hdc, tex, 0, l_course, 2);
        }
    }
    //��ʾ����

    for (int j = 0; j <= 2; j++)//ʡ�Ժ�...
    {
        // ����һ����͸���ľ���
        HBRUSH hDrawBrush = CreateSolidBrush(RGB(255, 255, 255));
        RECT drawRect = { read(3) * 3 * read(4) - read(3) * 3 / 5 + j * read(3) * 2 / 5,
            read(3) / 5 * 2,
            read(3) * 3 * read(4) - read(3) * 2 / 5 + j * read(3) * 2 / 5,
            read(3) / 5 * 3 };
        FillRect(hdc, &drawRect, hDrawBrush);
        // �ͷ���Դ
        DeleteObject(hDrawBrush);
    }
    EndPaint(hWnd, &ps);
    InvalidateRect(hWnd, NULL, TRUE);
    Sleep(32);//��ֹ�϶�����ʱcpuռ�ù���
}
