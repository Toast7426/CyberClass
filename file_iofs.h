#pragma once
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

bool fileExists(const std::string& filename)
{
	ifstream file(filename);
	return file.good();
}
int getNumLong(int num)
{
	int num_long;
	if (num < 10 && num >= 0)
	{
		num_long = 1;
	}
	if (num < 100 && num >= 10)
	{
		num_long = 2;
	}
	if (num < 1000 && num >= 100)
	{
		num_long = 3;
	}
	if (num < 10000 && num >= 1000)
	{
		num_long = 4;
	}
	if (num >= 10000 || num < 0)
	{
		num_long = 5/*不符合格式*/;
	}
	return num_long;
}
void fileManager(int line, int data)
{
	if (fileExists("properties.txt"))
	{
		fstream iofs("properties.txt", ios::in | ios::out);
		for (int i = 1; i < line; i++)//循环移动到指定元素
		{
			iofs.seekp(4, ios::cur);
		}
		if (getNumLong(data) == 5)
		{
			cout << "The value to be written is not supported" << endl;
		}
		else
		{
			for (int i = 0; i < 4 - getNumLong(data); i++)//使元素写入位置对齐
			{
				iofs << "0";
			}
			iofs << data;
			iofs.close();
			cout << "Successful!" << endl;
		}
	}
	else
	{
		cout << "Can not open 'properties.txt'" << endl;
	}
}
//文件操作（写）

int fileManagerR(int dayOfWeek, int sequence, bool ifRead, string* reCourse/*课程字符串，Return Course*/)
{
	if (fileExists("table.txt") && fileExists("properties.txt"))
	{
		if (dayOfWeek == 255)//读取每日课程
		{
			fstream ifs("properties.txt", ios::in);
			char num[4];//接收fstream的字符
			string s_num[4];//接收num的字符，准备拼接字符串
			int coursesEachDay;//接收s_x转换的int型
			string s_x;//接收拼接好的字符串

			ifs.seekg(12, ios::cur);

			for (int i = 0; i < 4; i++)
			{
				ifs.get(num[i]);
				s_num[i] = num[i];
				if (i == 3)
				{
					s_x = s_num[0] + s_num[1] + s_num[2] + s_num[3];//拼接字符串
					coursesEachDay = std::atoi(s_x.c_str());//转换字符串至int型
				}
			}

			ifs.close();

			return coursesEachDay;
		}
		if (ifRead == true)//读取情况
		{
			fstream ifs("table.txt", ios::in);
			char byteCourse[4];//接收fstream的单个字符
			string strByteCourse[4];//准备拼接字符串
			string strCourse;//接收拼接好的字符串
			int rangeDayOfWeek = 1;

			int breakSum = 0;

			while (rangeDayOfWeek < dayOfWeek/*此时的文件读取指针不在当日时，进行循环*/)
			{
				char nowPointer;
				ifs.get(nowPointer);

				breakSum++;
				if (breakSum == 100)
				{
					*reCourse = "null";
					ifs.close();
					return 0;
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
					*reCourse = strCourse;
				}
			}
			ifs.close();
			return 0;
		}
		else//写入（更改）情况
		{
			fstream iofs("table.txt", ios::out | ios::in);
			int rangeDayOfWeek = 1;

			while (rangeDayOfWeek < dayOfWeek/*此时的文件读取指针不在当日时，进行循环*/)
			{
				char nowPointer;
				iofs.get(nowPointer);
				if (nowPointer == '\n')
				{
					rangeDayOfWeek++;
				}
			}
			iofs.seekp(sequence * 4 - 4, ios::cur);
			iofs << *reCourse;
			iofs.close();
			return 0;
		}
	}
	else
	{
		cout << "Can not open 'properties.txt' or 'table.txt'" << endl;
		return 0;
	}
}
//文件操作（课表）

char* fileManagerT(int sequence, char* p_num)
{
	fstream iofs("time.txt", ios::in | ios::out);
	iofs.seekg(sequence * 8 - 8);
	for (int i = 0; i < 8; i++)
	{
		iofs.get(p_num[i]);
	}
	iofs.close();
	return p_num;
}
//读取time.txt
