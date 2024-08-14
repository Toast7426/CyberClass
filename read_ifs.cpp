#include <string>
#include <fstream>
#include "date_time.h"
using namespace std;

int read(int line)
{
	fstream ifs("DB_properties.txt", ios::in);

	char num[4];//����fstream���ַ�
	string s_num[4];//����num���ַ���׼��ƴ���ַ���
	int x;//����s_xת����int��
	string s_x;//����ƴ�Ӻõ��ַ���

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
			s_x = s_num[0] + s_num[1] + s_num[2] + s_num[3];//ƴ���ַ���
			x = std::atoi(s_x.c_str());//ת���ַ�����int��
		}
	}

	ifs.close();
	return x;
}

bool fileExists(const std::string& filename)
{
	ifstream file(filename);
	return file.good();
}
int fileManagerR(int dayOfWeek, int sequence, string* p/*�γ��ַ���*/)
{
	fstream ifs("DB_classschedule.txt", ios::in);
	char byteCourse[4];//����fstream�ĵ����ַ�
	string strByteCourse[4];//׼��ƴ���ַ���
	string strCourse;//����ƴ�Ӻõ��ַ���
	int rangeDayOfWeek = 0;

	int breakSum = 0;//��ֹ�ļ���������ʱ������ѭ��

	while (rangeDayOfWeek < dayOfWeek/*��ʱ���ļ���ȡָ�벻�ڵ���ʱ������ѭ��*/)
	{
		char nowPointer;/*���ڵ��ļ�ָ��*/
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
			strCourse = strByteCourse[0] + strByteCourse[1] + strByteCourse[2] + strByteCourse[3];//ƴ���ַ���
			*p = strCourse;
		}
	}
	ifs.close();
	return 0;
}

int fileManagerT(int dayOfWeek, int sequence, bool beginTime)
{
	fstream ifs("DB_timetable.txt", ios::in);
	int rangeDayOfWeek = 1;
	int breakSum = 0;
	char num[4];
	while (rangeDayOfWeek < dayOfWeek/*��ʱ���ļ�д��ָ�벻�ڵ���ʱ������ѭ��*/)
	{
		char nowPointer;
		ifs.get(nowPointer);

		breakSum++;
		if (breakSum == 200)
		{
			ifs.close();//��������£��ļ�ȱʧҪ��ȡ����һ��
			return 0;
		}
		if (nowPointer == '\n')
		{
			rangeDayOfWeek++;
			breakSum = 0;
		}
	}

	if (beginTime == true)
	{
		ifs.seekp(sequence * 8 - 8, ios::cur);
	}
	if (beginTime == false)
	{
		ifs.seekp(sequence * 8 - 4, ios::cur);
		//һ�ڿε���ʼ����ֹʱ��Ϊ7��50��8��45����ô����ʱ�����ݴ洢Ϊ07500845
		//�ʶ�ȡ����ʱ�����������λ
	}
	string numByte_str[4];//׼��ƴ���ַ���
	string num_str;//����ƴ�Ӻõ��ַ���
	for (int i = 0; i < 4; i++)
	{
		ifs.get(num[i]);
		numByte_str[i] = num[i];
	}
	ifs.close();
	int returnTime;
	for (int i = 0; i < 4; i++)
	{
		num_str = numByte_str[0] + numByte_str[1] + numByte_str[2] + numByte_str[3];//ƴ���ַ���
		returnTime = std::atoi(num_str.c_str());//ת���ַ�����int��
	}
	return returnTime;
}
