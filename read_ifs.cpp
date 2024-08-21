#include <string>
#include <fstream>
using namespace std;

int ReadDBP(const int line) {
	fstream ifs("DB_properties.txt", ios::in);
	// 换行操作
	for (int i = 1; i < line; i++)
	{
		ifs.seekg(4, ios::cur);
	}
	char charSingle[4];  // 接收fstream的字符
	string charSingle_str[4];  // 接收num的字符，准备拼接字符串
	int valueReturn;  // 接收s_x转换的int型
	string valueReturn_str;  // 接收拼接好的字符串
	// 将读取到的字符串转换为数值
	for (int i = 0; i < 4; i++)
	{
		ifs.get(charSingle[i]);
		charSingle_str[i] = charSingle[i];
		if (i == 3)
		{
			valueReturn_str = charSingle_str[0] + charSingle_str[1]
				+ charSingle_str[2] + charSingle_str[3];  // 拼接字符串
			valueReturn = std::atoi(valueReturn_str.c_str());  // 转换字符串至int型
		}
	}
	ifs.close();
	return valueReturn;
}

int ReadDBC(const int dayOfWeek, const int sequence, string* p  /*课程字符串*/) {
	fstream ifs("DB_classschedule.txt", ios::in);
	int dayOfWeekInRange = 1;
	int sumToBreak = 0;  // 防止文件不足七行时进入死循环
	while (dayOfWeekInRange < dayOfWeek  /*此时的文件读取指针不在当日时，进行循环*/)
	{
		char nowPointer;  // 现在的文件指针
		ifs.get(nowPointer);
		sumToBreak++;
		if (sumToBreak == 100)
		{
			ifs.close();  // 这种情况下，文件缺失要读取的那一行
			return 0;
		}
		if (nowPointer == '\n')
		{
			dayOfWeekInRange++;
			sumToBreak = 0;
		}
	}
	// 将文件指针最终定位到要读取的课程字符串所在位置
	ifs.seekg(sequence * 4 - 4, ios::cur);
	// 将读取到的字符串拼接为string并赋给指针
	char courseByte[4];  // 接收fstream的单个字符
	string courseByte_str[4];  // 准备拼接字符串
	string courseReturn;  // 接收拼接好的字符串
	for (int i = 0; i < 4; i++)
	{
		ifs.get(courseByte[i]);
		courseByte_str[i] = courseByte[i];
		if (i == 3)
		{
			courseReturn = courseByte_str[0] + courseByte_str[1]
				+ courseByte_str[2] + courseByte_str[3];  // 拼接字符串
			*p = courseReturn;
		}
	}
	ifs.close();
	return 0;
}

int ReadDBT(const int dayOfWeek, const int sequence, const bool beginTime) {
	fstream ifs("DB_timetable.txt", ios::in);
	int dayOfWeekInRange = 1;
	int sumToBreak = 0;  // 防止文件不足七行时进入死循环
	while (dayOfWeekInRange < dayOfWeek  /*此时的文件写入指针不在当日时，进行循环*/)
	{
		char nowPointer;  // 现在的文件指针
		ifs.get(nowPointer);
		sumToBreak++;
		if (sumToBreak == 200)
		{
			ifs.close();  // 这种情况下，文件缺失要读取的那一行
			return 0;
		}
		if (nowPointer == '\n')
		{
			dayOfWeekInRange++;
			sumToBreak = 0;
		}
	}
	// 将文件指针最终定位到要读取的课程字符串所在位置
	if (beginTime == true)
	{
		ifs.seekp(sequence * 8 - 8, ios::cur);
	}
	if (beginTime == false)
	{
		ifs.seekp(sequence * 8 - 4, ios::cur);
		// 一节课的起始和终止时间为7：50和8：45，那么它的时间数据存储为07500845
		// 故读取结束时间需向后移四位
	}
	char timeByte[4];
	string timeByte_str[4];  // 准备拼接字符串
	int returnTime;
	string returnTime_str;  // 接收拼接好的字符串
	for (int i = 0; i < 4; i++)
	{
		ifs.get(timeByte[i]);
		timeByte_str[i] = timeByte[i];
	}
	for (int i = 0; i < 4; i++)
	{
		returnTime_str = timeByte_str[0] + timeByte_str[1]
			+ timeByte_str[2] + timeByte_str[3];  // 拼接字符串
		returnTime = std::atoi(returnTime_str.c_str());  // 转换字符串至int型
	}
	ifs.close();
	return returnTime;
}
