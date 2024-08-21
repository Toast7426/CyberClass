#include <Windows.h>

// 读取星期
int ReadDate() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    int date = st.wDayOfWeek;
    if (date == 0)
    {
        return 7;  // Sunday
    }
    else
    {
        return date;  // Monday2Saturday
    }
}

// 读取小时
int ReadHour() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    int hour = st.wHour;
    return hour;
}

// 读取分钟
int ReadMinute() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    int minute = st.wMinute;
    return minute;
}
