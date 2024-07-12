#include <Windows.h>
#include <string>
using namespace std;
#include "read_ifs.h"
#include "date_time.h"

LPCWSTR str2LPCWSTR(string str)
{
    int len = str.length();
    int lenbf = MultiByteToWideChar(CP_ACP, 0, str.c_str(), len, 0, 0);
    wchar_t* buffer = new wchar_t[lenbf];
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), len, buffer, sizeof(wchar_t) * lenbf);
    buffer[len] = 0;
    return buffer;
}

void OnPaint(HWND hWnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    SetBkColor(hdc, RGB(0, 0, 0));//背景颜色
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
        string course;//课程名称
        fileManagerR(dateRead(), i, &course);
        LPCWSTR l_course = str2LPCWSTR(course);
        int lin01;
        lin01 = hourRead();
        if (fileManagerT(dateRead() * read(4) + 2 * i - 1)/*课程开始时间*/ <=
            hourRead() * 100 + minuteRead()/*现在时间*/ &&
            hourRead() * 100 + minuteRead()/*现在时间*/ <=
            fileManagerT(dateRead() * read(4) + 2 * i)/*课程结束时间*/)
        {
            SetTextColor(hdc, RGB(read(7), read(8), read(9)));//字体颜色
            int tex = read(3) * 3 * i - 3 * read(3) + read(3) / 10;
            TextOut(hdc, tex, 0, l_course, 2);
        }
        else
        {
            SetTextColor(hdc, RGB(255, 255, 255));//字体颜色
            int tex = read(3) * 3 * i - 3 * read(3) + read(3) / 10;
            TextOut(hdc, tex, 0, l_course, 2);
        }
        delete l_course;
        l_course = nullptr;//释放内存
    }
    //显示文字

    for (int j = 0; j <= 2; j++)//省略号...
    {
        // 绘制一个不透明的矩形
        HBRUSH hDrawBrush = CreateSolidBrush(RGB(255, 255, 255));
        RECT drawRect = { read(3) * 3 * read(4) - read(3) * 3 / 5 + j * read(3) * 2 / 5,
            read(3) / 5 * 2,
            read(3) * 3 * read(4) - read(3) * 2 / 5 + j * read(3) * 2 / 5,
            read(3) / 5 * 3 };
        FillRect(hdc, &drawRect, hDrawBrush);
        // 释放资源
        DeleteObject(hDrawBrush);
    }
    EndPaint(hWnd, &ps);
    InvalidateRect(hWnd, NULL, TRUE);
}
