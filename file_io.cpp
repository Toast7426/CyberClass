#include <fstream>
#include <string>
#include <iostream>
#include "output2cmd.h"
using namespace std;

bool fileExists(const string filename)
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
		num_long = 5;
	}
	return num_long;
}
void fileManager(int line, int data)
{
	if (fileExists("DB_properties.txt"))
	{
		fstream iofs("DB_properties.txt", ios::in | ios::out);
		for (int i = 1; i < line; i++)//循环移动到指定元素
		{
			iofs.seekp(4, ios::cur);
		}
		if (getNumLong(data) == 5)
		{
			Output("ERROR:The value to be written is not supported", ERROR_FONT);
		}
		else
		{
			for (int i = 0; i < 4 - getNumLong(data); i++)//使元素写入位置对齐
			{
				iofs << "0";
			}
			iofs << data;
			iofs.close();
			Output("Successful!");
		}
	}
	else
	{
		Output("ERROR:Can not open 'DB_properties.txt'", ERROR_FONT);
	}
}

int fileManagerR(int dayOfWeek, int sequence, bool ifRead, string* reCourse)
{
	if (fileExists("DB_classschedule.txt") && fileExists("DB_properties.txt"))
	{
		if (dayOfWeek == 255)//读取每日课程
		{
			fstream ifs("DB_properties.txt", ios::in);
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
					coursesEachDay = atoi(s_x.c_str());//转换字符串至int型
				}
			}
			ifs.close();
			return coursesEachDay;
		}
		else if (ifRead == true)//读取情况
		{
			fstream ifs("DB_classschedule.txt", ios::in);
			char byteCourse[4];//接收fstream的单个字符
			string strByteCourse[4];//准备拼接字符串
			string strCourse;//接收拼接好的字符串
			int rangeDayOfWeek = 1;

			int breakSum = 0;
			while (rangeDayOfWeek < dayOfWeek/*此时的文件读取指针不在当日时，进行循环*/)
			{
				char nowPointer;
				ifs.get(nowPointer);//get函数有读取后自动向后移位的特性

				breakSum++;
				if (breakSum == 70)
				{
					*reCourse = "null";
					ifs.close();
					Output("WARING:\"DB_classschedule.txt\"is incomplete", WARNING_FONT);
					Output("WARING:Please init classschedule", WARNING_FONT);
					return 0;//这种情况下，文件缺失要读取的那一行
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
					strCourse =
						strByteCourse[0] +
						strByteCourse[1] +
						strByteCourse[2] +
						strByteCourse[3];
					//拼接字符串
					*reCourse = strCourse;
				}
			}
			ifs.close();
			return 0;
		}
		else if (ifRead == false)//写入（更改）情况
		{
			fstream iofs("DB_classschedule.txt", ios::in | ios::out);
			int rangeDayOfWeek = 1;

			int breakSum = 0;
			while (rangeDayOfWeek < dayOfWeek/*此时的文件写入指针不在当日时，进行循环*/)
			{
			    char nowPointer;
				iofs.get(nowPointer);

				breakSum++;
				if (breakSum == 70)
				{
					iofs.close();
					Output("WARING:\"DB_classschedule.txt\"is incomplete", WARNING_FONT);
					Output("WARING:Please init classschedule", WARNING_FONT);
					return 0;//这种情况下，文件缺失要写入的那一行
				}
				if (nowPointer == '\n')
				{
					rangeDayOfWeek++;
					breakSum = 0;
				}
			}
			if (sequence * 4 - 4 == 0)
			{
				iofs.seekp(4, ios::cur);//代码是这样的
				iofs.seekp(-4, ios::cur);//用户只要看它跑起来就行了，开发者要考虑的可就多了
				iofs << *reCourse;
			}
			else
			{
			    iofs.seekp(sequence * 4 - 4, ios::cur);
			    iofs << *reCourse;
			}
			iofs.close();
			return 0;
		}
	}
	else
	{
	    Output("ERROR:Can not open 'DB_properties.txt' or 'DB_classschedule.txt'", ERROR_FONT);
	    return 0;
    }
}

void fileManagerT(int dayOfWeek, int sequence, bool beginTime, char* p_num)
{
	fstream ifs("DB_timetable.txt", ios::in);
	int rangeDayOfWeek = 1;
	int breakSum = 0;
	while (rangeDayOfWeek < dayOfWeek/*此时的文件写入指针不在当日时，进行循环*/)
	{
		char nowPointer;
		ifs.get(nowPointer);

		breakSum++;
		if (breakSum == 130)
		{
			Output("WARING:\"DB_timetable.txt\"is incomplete", WARNING_FONT);
			Output("WARING:Please init timetable", WARNING_FONT);
			rangeDayOfWeek = 7;
			ifs.close();//这种情况下，文件缺失要读取的那一行
		}
		if (nowPointer == '\n')
		{
			rangeDayOfWeek++;
			breakSum = 0;
		}
	}

	if (beginTime == true)
	{
	    ifs.seekg(sequence * 8 - 8, ios::cur);
	}
	if (beginTime == false)
	{
		ifs.seekg(sequence * 8 - 4, ios::cur);
		//一节课的起始和终止时间为7：50和8：45，那么它的时间数据存储为07500845
		//故读取结束时间需向后移四位
	}
	for (int i = 0; i < 4; i++)
	{
		ifs.get(p_num[i]);
	}
	ifs.close();
}
void fileManagerT(int dayOfWeek, int sequence, bool beginTime, int timeValue)
{
	fstream iofs("DB_timetable.txt", ios::in | ios::out);
	int rangeDayOfWeek = 1;
	int breakSum = 0;
	while (rangeDayOfWeek < dayOfWeek/*此时的文件写入指针不在当日时，进行循环*/)
	{
		char nowPointer;
		iofs.get(nowPointer);

		breakSum++;
		if (breakSum == 130)
		{
			Output("WARING:\"DB_timetable.txt\"is incomplete", WARNING_FONT);
			Output("WARING:Please init timetable", WARNING_FONT);
			rangeDayOfWeek = 7;
			iofs.close();//这种情况下，文件缺失要读取的那一行
		}
		if (nowPointer == '\n')
		{
			rangeDayOfWeek++;
			breakSum = 0;
		}
	}

	if (beginTime == true)
	{
		if (sequence * 8 - 8 == 0)
		{
			iofs.seekp(8, ios::cur);//代码是这样的
			iofs.seekp(-8, ios::cur);//用户只要看它跑起来就行了，开发者要考虑的可就多了
		}
		else
		{
			iofs.seekp(sequence * 8 - 8, ios::cur);
		}
	}
	if (beginTime == false)
	{
		iofs.seekp(sequence * 8 - 4, ios::cur);
		//一节课的起始和终止时间为7：50和8：45，那么它的时间数据存储为07500845
		//故读取结束时间需向后移四位
	}
	if (getNumLong(timeValue) == 5)
	{
		Output("ERROR:The value to be written is not supported", ERROR_FONT);
	}
	else
	{
		for (int i = 0; i < 4 - getNumLong(timeValue); i++)//使元素写入位置对齐
		{
			iofs << "0";
		}
		iofs << timeValue;
	}
	iofs.close();
}
