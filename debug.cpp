#include "debug_h.h"

int main()
{
	system("@echo off\ntaskkill /f /t /im Project_test.exe");//暂时关闭进程
	sign();
	chooseFunction();
	return 0;
}