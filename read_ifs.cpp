#include <string>
#include <fstream>
#include "date_time.h"
using namespace std;

int read(int line)
{
	fstream ifs("properties.txt", ios::in);

	char num[4];//接收fstream的字符
	string s_num[4];//接收num的字符，准备拼接字符串
	int x;//接收s_x转换的int型
	string s_x;//接收拼接好的字符串

	for (int i = 1; i < line; i++)
	{
		ifs.seekg(4, ios::cur);
	}


	for (int i = 0; i < 4; i++)
	{
		ifs.get(num[i]);
		s_num[i] = num[i];
		if (i == 3)
		{
			s_x = s_num[0] + s_num[1] + s_num[2] + s_num[3];//拼接字符串
			x = std::atoi(s_x.c_str());//转换字符串至int型
		}
	}

	ifs.close();
	return x;
}
//读取"properties.txt"

bool fileExists(const std::string& filename)
{
	ifstream file(filename);
	return file.good();
}
int fileManagerR(int dayOfWeek, int sequence, string* p/*课程字符串*/)
{
	fstream ifs("table.txt", ios::in);
	char byteCourse[4];//接收fstream的单个字符
	string strByteCourse[4];//准备拼接字符串
	string strCourse;//接收拼接好的字符串
	int rangeDayOfWeek = 0;

	int breakSum = 0;//防止文件不足七行时进入死循环

	while (rangeDayOfWeek < dayOfWeek/*此时的文件读取指针不在当日时，进行循环*/)
	{
		char nowPointer;/*现在的文件指针*/
		ifs.get(nowPointer);
		breakSum++;
		if (breakSum == 100)
		{
			break;
		}
		if (nowPointer == '\n')
		{
			rangeDayOfWeek++;
			breakSum = 0;
		}
	}
	ifs.seekg(sequence * 4 - 4, ios::cur);

	for (int i = 0; i < 4; i++)
	{
		ifs.get(byteCourse[i]);
		strByteCourse[i] = byteCourse[i];
		if (i == 3)
		{
			strCourse = strByteCourse[0] + strByteCourse[1] + strByteCourse[2] + strByteCourse[3];//拼接字符串
			*p = strCourse;
		}
	}
	ifs.close();
	return 0;
}
//读取"table.txt"

int fileManagerT(int sequence)
{
	fstream ifs("time.txt", ios::in);
	char num[4];//接收fstream的字符
	string s_num[4];//准备拼接字符串
	string s_x;//接收拼接好的字符串
	int x;
	ifs.seekg(sequence * 4 + dateRead() * read(4) * 4 - 4, ios::cur);
	for (int i = 0; i < 4; i++)
	{
		ifs.get(num[i]);
		s_num[i] = num[i];
		if (i == 3)
		{
			s_x = s_num[0] + s_num[1] + s_num[2] + s_num[3];//拼接字符串
			x = std::atoi(s_x.c_str());//转换字符串至int型
		}
	}
	ifs.close();
	return x;
}
//读取time.txt
