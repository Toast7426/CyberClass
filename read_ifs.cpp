#include <string>
#include <fstream>
using namespace std;

int ReadDBP(const int line) {
	fstream ifs("DB_properties.txt", ios::in);
	// ���в���
	for (int i = 1; i < line; i++)
	{
		ifs.seekg(4, ios::cur);
	}
	char charSingle[4];  // ����fstream���ַ�
	string charSingle_str[4];  // ����num���ַ���׼��ƴ���ַ���
	int valueReturn;  // ����s_xת����int��
	string valueReturn_str;  // ����ƴ�Ӻõ��ַ���
	// ����ȡ�����ַ���ת��Ϊ��ֵ
	for (int i = 0; i < 4; i++)
	{
		ifs.get(charSingle[i]);
		charSingle_str[i] = charSingle[i];
		if (i == 3)
		{
			valueReturn_str = charSingle_str[0] + charSingle_str[1]
				+ charSingle_str[2] + charSingle_str[3];  // ƴ���ַ���
			valueReturn = std::atoi(valueReturn_str.c_str());  // ת���ַ�����int��
		}
	}
	ifs.close();
	return valueReturn;
}

int ReadDBC(const int dayOfWeek, const int sequence, string* p  /*�γ��ַ���*/) {
	fstream ifs("DB_classschedule.txt", ios::in);
	int dayOfWeekInRange = 1;
	int sumToBreak = 0;  // ��ֹ�ļ���������ʱ������ѭ��
	while (dayOfWeekInRange < dayOfWeek  /*��ʱ���ļ���ȡָ�벻�ڵ���ʱ������ѭ��*/)
	{
		char nowPointer;  // ���ڵ��ļ�ָ��
		ifs.get(nowPointer);
		sumToBreak++;
		if (sumToBreak == 100)
		{
			ifs.close();  // ��������£��ļ�ȱʧҪ��ȡ����һ��
			return 0;
		}
		if (nowPointer == '\n')
		{
			dayOfWeekInRange++;
			sumToBreak = 0;
		}
	}
	// ���ļ�ָ�����ն�λ��Ҫ��ȡ�Ŀγ��ַ�������λ��
	ifs.seekg(sequence * 4 - 4, ios::cur);
	// ����ȡ�����ַ���ƴ��Ϊstring������ָ��
	char courseByte[4];  // ����fstream�ĵ����ַ�
	string courseByte_str[4];  // ׼��ƴ���ַ���
	string courseReturn;  // ����ƴ�Ӻõ��ַ���
	for (int i = 0; i < 4; i++)
	{
		ifs.get(courseByte[i]);
		courseByte_str[i] = courseByte[i];
		if (i == 3)
		{
			courseReturn = courseByte_str[0] + courseByte_str[1]
				+ courseByte_str[2] + courseByte_str[3];  // ƴ���ַ���
			*p = courseReturn;
		}
	}
	ifs.close();
	return 0;
}

int ReadDBT(const int dayOfWeek, const int sequence, const bool beginTime) {
	fstream ifs("DB_timetable.txt", ios::in);
	int dayOfWeekInRange = 1;
	int sumToBreak = 0;  // ��ֹ�ļ���������ʱ������ѭ��
	while (dayOfWeekInRange < dayOfWeek  /*��ʱ���ļ�д��ָ�벻�ڵ���ʱ������ѭ��*/)
	{
		char nowPointer;  // ���ڵ��ļ�ָ��
		ifs.get(nowPointer);
		sumToBreak++;
		if (sumToBreak == 200)
		{
			ifs.close();  // ��������£��ļ�ȱʧҪ��ȡ����һ��
			return 0;
		}
		if (nowPointer == '\n')
		{
			dayOfWeekInRange++;
			sumToBreak = 0;
		}
	}
	// ���ļ�ָ�����ն�λ��Ҫ��ȡ�Ŀγ��ַ�������λ��
	if (beginTime == true)
	{
		ifs.seekp(sequence * 8 - 8, ios::cur);
	}
	if (beginTime == false)
	{
		ifs.seekp(sequence * 8 - 4, ios::cur);
		// һ�ڿε���ʼ����ֹʱ��Ϊ7��50��8��45����ô����ʱ�����ݴ洢Ϊ07500845
		// �ʶ�ȡ����ʱ�����������λ
	}
	char timeByte[4];
	string timeByte_str[4];  // ׼��ƴ���ַ���
	int returnTime;
	string returnTime_str;  // ����ƴ�Ӻõ��ַ���
	for (int i = 0; i < 4; i++)
	{
		ifs.get(timeByte[i]);
		timeByte_str[i] = timeByte[i];
	}
	for (int i = 0; i < 4; i++)
	{
		returnTime_str = timeByte_str[0] + timeByte_str[1]
			+ timeByte_str[2] + timeByte_str[3];  // ƴ���ַ���
		returnTime = std::atoi(returnTime_str.c_str());  // ת���ַ�����int��
	}
	ifs.close();
	return returnTime;
}
