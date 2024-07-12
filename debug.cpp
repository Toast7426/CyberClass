#include "debug_h.h"

int main()
{
	system("taskkill /f /t /im Project_test.exe");//暂时关闭进程
	sign();
	chooseFunction();
	return 0;
}