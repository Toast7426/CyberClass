#include <Windows.h>

// ��ȡ����
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

// ��ȡСʱ
int ReadHour() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    int hour = st.wHour;
    return hour;
}

// ��ȡ����
int ReadMinute() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    int minute = st.wMinute;
    return minute;
}
