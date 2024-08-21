#include <Windows.h>
#include <string>
using namespace std;
#include "read_ifs.h"
#include "date_time.h"

wstring string2LPCWSTR(const string& str) {
    int len;
    int slength = (int)str.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, buf, len);
    wstring r(buf);
    delete[] buf;
    return r;
}

void OnPaint(HWND hWnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    SetBkColor(hdc, RGB(0, 0, 0));   // ������ɫ
    SetBkMode(hdc, TRANSPARENT);
    HFONT hFont = CreateFont(
        -ReadDBP(6),
        -ReadDBP(6) / 2,
        0,
        0,
        400,
        0, 0, 0,
        GB2312_CHARSET,
        0, 0, 0, 0,
        L"Microsoft YaHei UI");
    HGDIOBJ nOldFont = SelectObject(hdc, hFont);
    for (int i = 1; i <= ReadDBP(4); i++)
    {
        string course;  // �γ�����
        ReadDBC(ReadDate(), i, &course);
        wstring wstr = string2LPCWSTR(course);
        LPCWSTR l_course = wstr.c_str();  // ��stringת��ΪLPCWSTR
        if (
            ReadDBT(ReadDate(), i, true)  /*�γ̿�ʼʱ��*/
            <= ReadHour() * 100 + ReadMinute()  /*����ʱ��*/ &&
            ReadHour() * 100 + ReadMinute()  /*����ʱ��*/
            <= ReadDBT(ReadDate(), i, false)  /*�γ̽���ʱ��*/)
        {
            SetTextColor(hdc, RGB(ReadDBP(7), ReadDBP(8), ReadDBP(9)));  // ������ɫ
            int textPositionX = ReadDBP(3)*3*i - 3*ReadDBP(3) + ReadDBP(3)/10;
            TextOut(hdc, textPositionX, 0, l_course, 2);
        }
        else
        {
            SetTextColor(hdc, RGB(255, 255, 255));  // ������ɫ
            int textPositionX = ReadDBP(3)*3*i - 3*ReadDBP(3) + ReadDBP(3)/10;
            TextOut(hdc, textPositionX, 0, l_course, 2);
        }
    }
    // ��ʾ����

    for (int j = 0; j < 3; j++)  // ʡ�Ժ�...
    {
        // ����һ����͸���ľ���
        HBRUSH hDrawBrush = CreateSolidBrush(RGB(255, 255, 255));
        RECT rectToDraw = {
            ReadDBP(3)*3*ReadDBP(4) - ReadDBP(3)*3/5 + j*ReadDBP(3)*2/5,
            ReadDBP(3) / 5 * 2,
            ReadDBP(3)*3*ReadDBP(4) - ReadDBP(3)*2/5 + j*ReadDBP(3)*2/5,
            ReadDBP(3) / 5 * 3 };
        FillRect(hdc, &rectToDraw, hDrawBrush);
        DeleteObject(hDrawBrush);  // �ͷ���Դ
    }
    EndPaint(hWnd, &ps);
    InvalidateRect(hWnd, NULL, TRUE);
}
