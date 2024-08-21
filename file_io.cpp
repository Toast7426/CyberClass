#include <fstream>
#include <string>
#include <iostream>
#include "output2cmd.h"
using namespace std;

bool FileExists(const string filename) {
	ifstream file(filename);
	return file.good();
}
int GetNumLong(const int num) {
	int numLong;
	if (num < 10 && num >= 0)
	{
		numLong = 1;
	}
	if (num < 100 && num >= 10)
	{
		numLong = 2;
	}
	if (num < 1000 && num >= 100)
	{
		numLong = 3;
	}
	if (num < 10000 && num >= 1000)
	{
		numLong = 4;
	}
	if (num >= 10000 || num < 0)
	{
		numLong = 5;
	}
	return numLong;
}
void FileManagerDBP_Out(const int line, const int data) {
	if (!FileExists("DB_properties.txt"))
	{
		Output("ERROR:Can not open 'DB_properties.txt'", ERROR_FONT);
		return;
	}
	fstream iofs("DB_properties.txt", ios::in | ios::out);
	for (int i = 1; i < line; i++)//ѭ���ƶ���ָ��Ԫ��
	{
		iofs.seekp(4, ios::cur);
	}
	if (GetNumLong(data) == 5)
	{
		Output("ERROR:The value to be written is not supported", ERROR_FONT);
	}
	else
	{
		for (int i = 0; i < 4 - GetNumLong(data); i++)//ʹԪ��д��λ�ö���
		{
			iofs << "0";
		}
		iofs << data;
		iofs.close();
		Output("Successful!");
	}
}

int FileManagerDBP_CoursesEachDay_In() {
	if (!FileExists("DB_properties.txt"))
	{
		Output("ERROR:Can not open 'DB_classschedule.txt'", ERROR_FONT);
		return 0;
	}
	fstream ifs("DB_properties.txt", ios::in);
	char num[4];//����fstream���ַ�
	string s_num[4];//����num���ַ���׼��ƴ���ַ���
	int coursesEachDay;//����s_xת����int��
	string s_x;//����ƴ�Ӻõ��ַ���

	ifs.seekg(12, ios::cur);

	for (int i = 0; i < 4; i++)
	{
		ifs.get(num[i]);
		s_num[i] = num[i];
		if (i == 3)
		{
			s_x = s_num[0] + s_num[1] + s_num[2] + s_num[3];//ƴ���ַ���
			coursesEachDay = atoi(s_x.c_str());//ת���ַ�����int��
		}
	}
	ifs.close();
	return coursesEachDay;
}

void FileManagerDBC_In(const int dayOfWeek, const int sequence,
	string* reCourse) {
	if (!FileExists("DB_classschedule.txt"))
	{
		Output("ERROR:Can not open 'DB_properties.txt'", ERROR_FONT);
		return;
	}
	fstream ifs("DB_classschedule.txt", ios::in);
	char byteCourse[4];//����fstream�ĵ����ַ�
	string strByteCourse[4];//׼��ƴ���ַ���
	string strCourse;//����ƴ�Ӻõ��ַ���
	int rangeDayOfWeek = 1;

	int breakSum = 0;
	while (rangeDayOfWeek < dayOfWeek/*��ʱ���ļ���ȡָ�벻�ڵ���ʱ������ѭ��*/)
	{
		char nowPointer;
		ifs.get(nowPointer);//get�����ж�ȡ���Զ������λ������

		breakSum++;
		if (breakSum == 70)
		{
			*reCourse = "null";
			ifs.close();
			Output("WARING:\"DB_classschedule.txt\"is incomplete", WARNING_FONT);
			Output("WARING:Please init classschedule", WARNING_FONT);
			return;//��������£��ļ�ȱʧҪ��ȡ����һ��
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
			//ƴ���ַ���
			*reCourse = strCourse;
		}
	}
	ifs.close();
	return;
}

void FileManagerDBC_Out(const int dayOfWeek, const int sequence,
	string* wrCourse) {
	if (!FileExists("DB_classschedule.txt"))
	{
		Output("ERROR:Can not open 'DB_properties.txt'", ERROR_FONT);
		return;
	}
	fstream iofs("DB_classschedule.txt", ios::in | ios::out);
	int rangeDayOfWeek = 1;

	int breakSum = 0;
	while (rangeDayOfWeek < dayOfWeek/*��ʱ���ļ�д��ָ�벻�ڵ���ʱ������ѭ��*/)
	{
		char nowPointer;
		iofs.get(nowPointer);

		breakSum++;
		if (breakSum == 70)
		{
			iofs.close();
			Output("WARING:\"DB_classschedule.txt\"is incomplete", WARNING_FONT);
			Output("WARING:Please init classschedule", WARNING_FONT);
			return;//��������£��ļ�ȱʧҪд�����һ��
		}
		if (nowPointer == '\n')
		{
			rangeDayOfWeek++;
			breakSum = 0;
		}
	}
	if (sequence * 4 - 4 == 0)
	{
		iofs.seekp(4, ios::cur);//������������
		iofs.seekp(-4, ios::cur);//�û�ֻҪ���������������ˣ�������Ҫ���ǵĿɾͶ���
		iofs << *wrCourse;
	}
	else
	{
		iofs.seekp(sequence * 4 - 4, ios::cur);
		iofs << *wrCourse;
	}
	iofs.close();
	return;
}

void FileManagerDBT_In(const int dayOfWeek, const int sequence,
	const bool beginTime, char* p_num) {
	fstream ifs("DB_timetable.txt", ios::in);
	int rangeDayOfWeek = 1;
	int breakSum = 0;
	while (rangeDayOfWeek < dayOfWeek/*��ʱ���ļ�д��ָ�벻�ڵ���ʱ������ѭ��*/)
	{
		char nowPointer;
		ifs.get(nowPointer);

		breakSum++;
		if (breakSum == 130)
		{
			Output("WARING:\"DB_timetable.txt\"is incomplete", WARNING_FONT);
			Output("WARING:Please init timetable", WARNING_FONT);
			rangeDayOfWeek = 7;
			ifs.close();//��������£��ļ�ȱʧҪ��ȡ����һ��
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
		//һ�ڿε���ʼ����ֹʱ��Ϊ7��50��8��45����ô����ʱ�����ݴ洢Ϊ07500845
		//�ʶ�ȡ����ʱ�����������λ
	}
	for (int i = 0; i < 4; i++)
	{
		ifs.get(p_num[i]);
	}
	ifs.close();
}
void FileManagerDBT_Out(const int dayOfWeek, const int sequence,
	const bool beginTime, const int timeValue) {
	fstream iofs("DB_timetable.txt", ios::in | ios::out);
	int rangeDayOfWeek = 1;
	int breakSum = 0;
	while (rangeDayOfWeek < dayOfWeek/*��ʱ���ļ�д��ָ�벻�ڵ���ʱ������ѭ��*/)
	{
		char nowPointer;
		iofs.get(nowPointer);

		breakSum++;
		if (breakSum == 130)
		{
			Output("WARING:\"DB_timetable.txt\"is incomplete", WARNING_FONT);
			Output("WARING:Please init timetable", WARNING_FONT);
			rangeDayOfWeek = 7;
			iofs.close();//��������£��ļ�ȱʧҪ��ȡ����һ��
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
			iofs.seekp(8, ios::cur);//������������
			iofs.seekp(-8, ios::cur);//�û�ֻҪ���������������ˣ�������Ҫ���ǵĿɾͶ���
		}
		else
		{
			iofs.seekp(sequence * 8 - 8, ios::cur);
		}
	}
	if (beginTime == false)
	{
		iofs.seekp(sequence * 8 - 4, ios::cur);
		//һ�ڿε���ʼ����ֹʱ��Ϊ7��50��8��45����ô����ʱ�����ݴ洢Ϊ07500845
		//�ʶ�ȡ����ʱ�����������λ
	}
	if (GetNumLong(timeValue) == 5)
	{
		Output("ERROR:The value to be written is not supported", ERROR_FONT);
	}
	else
	{
		for (int i = 0; i < 4 - GetNumLong(timeValue); i++)//ʹԪ��д��λ�ö���
		{
			iofs << "0";
		}
		iofs << timeValue;
	}
	iofs.close();
}
