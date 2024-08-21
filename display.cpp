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
    SetBkColor(hdc, RGB(0, 0, 0));   // 背景颜色
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
        string course;  // 课程名称
        ReadDBC(ReadDate(), i, &course);
        wstring wstr = string2LPCWSTR(course);
        LPCWSTR l_course = wstr.c_str();  // 将string转换为LPCWSTR
        if (
            ReadDBT(ReadDate(), i, true)  /*课程开始时间*/
            <= ReadHour() * 100 + ReadMinute()  /*现在时间*/ &&
            ReadHour() * 100 + ReadMinute()  /*现在时间*/
            <= ReadDBT(ReadDate(), i, false)  /*课程结束时间*/)
        {
            SetTextColor(hdc, RGB(ReadDBP(7), ReadDBP(8), ReadDBP(9)));  // 字体颜色
            int textPositionX = ReadDBP(3)*3*i - 3*ReadDBP(3) + ReadDBP(3)/10;
            TextOut(hdc, textPositionX, 0, l_course, 2);
        }
        else
        {
            SetTextColor(hdc, RGB(255, 255, 255));  // 字体颜色
            int textPositionX = ReadDBP(3)*3*i - 3*ReadDBP(3) + ReadDBP(3)/10;
            TextOut(hdc, textPositionX, 0, l_course, 2);
        }
    }
    // 显示文字

    for (int j = 0; j < 3; j++)  // 省略号...
    {
        // 绘制一个不透明的矩形
        HBRUSH hDrawBrush = CreateSolidBrush(RGB(255, 255, 255));
        RECT rectToDraw = {
            ReadDBP(3)*3*ReadDBP(4) - ReadDBP(3)*3/5 + j*ReadDBP(3)*2/5,
            ReadDBP(3) / 5 * 2,
            ReadDBP(3)*3*ReadDBP(4) - ReadDBP(3)*2/5 + j*ReadDBP(3)*2/5,
            ReadDBP(3) / 5 * 3 };
        FillRect(hdc, &rectToDraw, hDrawBrush);
        DeleteObject(hDrawBrush);  // 释放资源
    }
    EndPaint(hWnd, &ps);
    InvalidateRect(hWnd, NULL, TRUE);
}
