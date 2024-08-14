#include <Windows.h>

//读取星期
int dateRead()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int tmp = st.wDayOfWeek;
    if (tmp == 0)
    {
        return 6;//Sunday
    }
    else
    {
        return tmp - 1;//Monday2Saturday
    }
}

//读取小时
int hourRead()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int tmp = st.wHour;
    return tmp;
}

//读取分钟
int minuteRead()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int tmp = st.wMinute;
    return tmp;
}
