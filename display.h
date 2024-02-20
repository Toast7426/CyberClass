#pragma once
#include <string>
#include <iostream>
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
    PAINTSTRUCT ps = { 0 };
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
        LPCWSTR l_course = str2LPCWSTR(course);
        if (fileManagerT(dateRead() * read(4) + 2 * i - 1)/*�γ̿�ʼʱ��*/ <=
            hourRead() * 100 + minuteRead()/*����ʱ��*/ &&
            hourRead() * 100 + minuteRead()/*����ʱ��*/ <=
            fileManagerT(dateRead() * read(4) + 2 * i)/*�γ̽���ʱ��*/)
        {
            SetTextColor(hdc, RGB(read(7), read(8), read(9)));//������ɫ
            TextOut(hdc, read(3) * 2 * i - 2 * read(3) + read(3) / 10, 0, l_course, 2);
            SetTextColor(hdc, RGB(255, 255, 255));//������ɫ
        }
        else
        {
            SetTextColor(hdc, RGB(255, 255, 255));//������ɫ
            TextOut(hdc, read(3) * 2 * i - 2 * read(3) + read(3) / 10, 0, l_course, 2);
        }
    }
    //��ʾ����

    for (int j = 0; j <= 2; j++)//ʡ�Ժ�...
    {
        // ����һ����͸���ľ���
        HBRUSH hDrawBrush = CreateSolidBrush(RGB(255, 255, 255));
        RECT drawRect = { read(3) * 2 * read(4) + read(3) / 10 + read(3) / 5 * j,
            read(3) / 5 * 2,
            read(3) * 2 * read(4) + read(3) / 10 + read(3) / 5 * j + read(3) / 10,
            read(3) / 5 * 2 + read(3) / 10 };
        FillRect(hdc, &drawRect, hDrawBrush);

        // �ͷ���Դ
        DeleteObject(hDrawBrush);
    }
    EndPaint(hWnd, &ps);
}
