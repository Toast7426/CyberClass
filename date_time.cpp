#include <Windows.h>

//��ȡ����
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

//��ȡСʱ
int hourRead()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int tmp = st.wHour;
    return tmp;
}

//��ȡ����
int minuteRead()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    int tmp = st.wMinute;
    return tmp;
}
