#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "console.h"
#include "file_io.h"
#include "color_define.h"
#include "output2cmd.h"
using namespace std;

void ExSign() {
	Output(" ______                   ____                   __________       __________", SIGN_FONT);
	Output("|\\_   _\\                 |\\  _\\                 |\\  ______ \\     |\\  ______ \\", SIGN_FONT);
	Output("\\|_\\  \\|                  \\\\ \\|                  \\\\ \\    \\\\ \\     \\\\ \\    \\\\ \\", SIGN_FONT);
	Output("   \\\\  \\    _  ______    __\\\\ \\__   ________      \\\\ \\    \\\\ \\     \\\\ \\___// /", SIGN_FONT);
	Output("    \\\\  \\   |\\/ ____ \\   \\|_|\\ \\_| |\\  ____ \\      \\\\ \\    \\\\ \\     \\\\  ____/", SIGN_FONT);
	Output("     \\\\  \\   \\\\ \\  \\\\ \\      \\\\ \\   \\\\ \\  \\\\ \\      \\\\ \\    \\\\ \\     \\\\ \\___|", SIGN_FONT);
	Output("      \\\\  \\_  \\\\ \\  \\\\ \\      \\\\ \\   \\\\ \\__\\\\ \\      \\\\ \\___// /      \\\\ \\", SIGN_FONT);
	Output("     |\\_____\\  \\\\_\\  \\\\_\\      \\\\_\\   \\\\_______\\      \\\\_\\____/        \\\\_\\", SIGN_FONT);
	Output("     \\|_____|   \\|_|  \\|_|      \\|_|   \\|_______|      \\|_____|         \\|_|", SIGN_FONT);
}

void PrintInformation() {
	Output("Vision1.2.008", REMIND_FONT);
	Output("GitHub:", HIGHLIGHT_FONT);
	Output("https://github.com/Toast7426/CyberClass", URL_FONT);
	Output("��������::", HIGHLIGHT_FONT);
	Output("https://space.bilibili.com/3493280968870105?spm_id_from=333.1007.0.0", URL_FONT);
	Output("Bugs?Can't run?How about Windows8 compatibility mode?", REMIND_FONT);
}

void ChooseFunction() {
	while (true)
	{
		Output("/*================================================================*/", REMIND_FONT);
		Output("Enter the number to choose the functions", HIGHLIGHT_FONT);
		Output("0.The information of \"Cyber Class\"", HIGHLIGHT_FONT);
		Output("1.Init", HIGHLIGHT_FONT);
		Output("2.Set window position", HIGHLIGHT_FONT);
		Output("3.Set alpha value(Experimental)", HIGHLIGHT_FONT);
		Output("4.Set font", HIGHLIGHT_FONT);
		Output("5.Edit course table", HIGHLIGHT_FONT);
		Output("6.Edit timetable", HIGHLIGHT_FONT);
		Output("7.Edit refresh time", HIGHLIGHT_FONT);
		Output("8.Add to \"startup\"", HIGHLIGHT_FONT);
		Output("9.Set Foreground", HIGHLIGHT_FONT);
		Output("10.End 'InfoDP'", HIGHLIGHT_FONT);
		Output("/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */", REMIND_FONT);
		string inputNum_str;
		cin >> inputNum_str;
		int inputNum = atoi(inputNum_str.c_str());  // ת���Է�ֹ������"a"�����ĺ��
		switch (inputNum)
		{
		case (0):
		{
			PrintInformation();
			break;
		}
		case (1):
		{
			Init();
			break;
		}
		case (2):
		{
			SetPos();
			break;
		}
		case (3):
		{
			SetAlphaValue();
			break;
		}
		case (4):
		{
			SetFont();
			break;
		}
		case (5):
		{
			int dayOfWeek = 1;  // ��sequence��ͬ��λ���ڱ༭�Ŀγ�
			int sequence = 1;  // ��dayOfWeek��ͬ��λ���ڱ༭�Ŀγ�
			bool con/*continue*/ = true;  // conΪtrue,������༭�α�
			while (con)
			{
				EditCourseTable(&dayOfWeek, &sequence, &con);  // ���߼�ѭ��
			}
			break;
		}
		case (6):
		{
			int dayOfWeek;  // ��sequence��ͬ��λ���ڱ༭�Ŀγ�
			int sequence = 1;  // ��dayOfWeek��ͬ��λ���ڱ༭�Ŀγ�
			bool con/*continue*/ = true;  // conΪtrue,������༭ʱ���
			Output("Enter 'dayOfWeek'", HIGHLIGHT_FONT);
			cin >> dayOfWeek;
			if (!IfValueAllow(1, 7, dayOfWeek))
			{
				dayOfWeek = 1;
			}
			while (con)
			{
				EditTimeTable(&dayOfWeek, &sequence, &con);  // ���߼�ѭ��
			}
			break;
		}
		case (7):
		{
			EditRefreshTime();
			break;
		}
		case (8):
		{
			AddToStartup();
			break;
		}
		case (9):
		{
			SetForeground();
			break;
		}
		case (10):
		{
			EndProcess();
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

bool IfValueAllow(const int min, const int max, const int input) {
	if (input >= min && input <= max)
	{
		return true;
	}
	else
	{
		Output("ERROR:The value is limited", ERROR_FONT);
		return false;
	}
}

void Init() {
	Output("To init 'properties'/'timetable'/'classschedule'?(p/t/c)", REMIND_FONT);
	Output("Press any other key to cancel", REMIND_FONT);
	char fileToInit;
	cin >> fileToInit;
	if (fileToInit == 'P' || fileToInit == 'p')
	{
		fstream ofsP("DB_properties.txt", ios::out);
		ofsP << "0850";  // ���ڿ�_l1
		ofsP << "0375";  // X����_l2
		ofsP << "0050";  // ���ڸ�_l3
		ofsP << "0008";  // ÿ�տγ�_l4
		ofsP << "0255";  // ͸����_l5
		ofsP << "0034";  // ����_l6
		ofsP << "0200";  // ������ɫR_l7
		ofsP << "0200";  // ������ɫG_l8
		ofsP << "0255";  // ������ɫB_l9
		ofsP << "0200";  // ˢ�¼��_l10
		ofsP << "0000";  // ����ǰ��_l11
		ofsP.close();
		Output("Sucessful!");
	}
	else if (fileToInit == 'T' || fileToInit == 't')
	{
		fstream ofsT("DB_timetable.txt", ios::out);
		char initLine[129] = { " " };
		initLine[128] = '\n';
		for (int i = 1; i <= 7; i++)
		{
			for (int j = 0; j <= 128; j++)
			{
				ofsT << initLine[j];  // ��ֹ��ȡʱ���ʱwhile����������
			}
		}
		ofsT.close();
		Output("Successful!");
	}
	else if (fileToInit == 'C' || fileToInit == 'c')
	{
		fstream ofsC("DB_classschedule.txt", ios::out);
		char initLine[65] = { " " };
		initLine[64] = '\n';
		for (int i = 1; i <= 7; i++)
		{
			for (int j = 0; j <= 64; j++)
			{
			    ofsC << initLine[j];  // ��ֹ��ȡ�α�ʱwhile����������
			}
		}
		ofsC.close();
		Output("Successful!");
	}
	else
	{
		Output("Cancel");
	}
}

void SetPos() {
	int screenWide;
	int lessonCount;
	int windowHigh;
	Output("Enter 'screen_wide'(px)", HIGHLIGHT_FONT);
	cin >> screenWide;
	Output("Enter 'number of courses per day'", HIGHLIGHT_FONT);
	cin >> lessonCount;
	Output("Enter 'window_high'(px)", HIGHLIGHT_FONT);
	cin >> windowHigh;
	int windowWide;
	int windowXPos;
	windowWide = 3 * lessonCount * windowHigh + windowHigh;
	windowXPos = screenWide / 2 - windowWide / 2;
	FileManagerDBP_Out(1, windowWide);
	FileManagerDBP_Out(2, windowXPos);
	FileManagerDBP_Out(3, windowHigh);
	FileManagerDBP_Out(4, lessonCount);
}

void SetAlphaValue() {
	int alphaValue;
	Output("Enter 'alpha'(0(disable)~255)", HIGHLIGHT_FONT);
	cin >> alphaValue;
	if (IfValueAllow(0, 255, alphaValue))
	{
		FileManagerDBP_Out(5, alphaValue);
	}
}

void SetFont() {
	int fontSize;
	Output("Enter 'font_size'", HIGHLIGHT_FONT);
	Output("Best font size for window height", HIGHLIGHT_FONT);
	Output("38-50px\t50-70px\t74-100px", HIGHLIGHT_FONT);
	cin >> fontSize;
	FileManagerDBP_Out(6, fontSize);

	Output("Please choose color", HIGHLIGHT_FONT);
	Output("1.VISUALSTUDIO_PURPLE\t2.PYTHON_YELLO\t3.WINDOWS_BLUE", HIGHLIGHT_FONT);
	Output("4.BLENDER_ORANGE\t5.MIKU_GREEN", HIGHLIGHT_FONT);
	string colorNum_str;
	cin >> colorNum_str;
	int colorNum = atoi(colorNum_str.c_str());  // ת���Է�ֹ������"a"�����ĺ��
	switch (colorNum)
	{
	case(1):
	{
		FileManagerDBP_Out(7, C_VISUALSTUDIO_PURPLE.red);  // д��(red)
		FileManagerDBP_Out(8, C_VISUALSTUDIO_PURPLE.green);  // д��(green)
		FileManagerDBP_Out(9, C_VISUALSTUDIO_PURPLE.blue);  // д��(blue)
		break;
	}
	case(2):
	{
		FileManagerDBP_Out(7, C_PYTHON_YELLO.red);
		FileManagerDBP_Out(8, C_PYTHON_YELLO.green);
		FileManagerDBP_Out(9, C_PYTHON_YELLO.blue);
		break;
	}
	case(3):
	{
		FileManagerDBP_Out(7, C_WINDOWS_BLUE.red);
		FileManagerDBP_Out(8, C_WINDOWS_BLUE.green);
		FileManagerDBP_Out(9, C_WINDOWS_BLUE.blue);
		break;
	}
	case(4):
	{
		FileManagerDBP_Out(7, C_BLENDER_ORANGE.red);
		FileManagerDBP_Out(8, C_BLENDER_ORANGE.green);
		FileManagerDBP_Out(9, C_BLENDER_ORANGE.blue);
		break;
	}
	case(5):
	{
		FileManagerDBP_Out(7, C_MIKU_GREEN.red);
		FileManagerDBP_Out(8, C_MIKU_GREEN.green);
		FileManagerDBP_Out(9, C_MIKU_GREEN.blue);
		break;
	}
	default:
	{
		break;
	}
	}
}

void MoveCursor(int* dayOfWeek_p, int* sequence_p, const int courseCountEachDay) {
	if (*sequence_p == courseCountEachDay)  /*������ƶ�����һ��*/
	{
		if (*dayOfWeek_p == 7)
		{
			*dayOfWeek_p = 1;
			*sequence_p = 1;
		}
		else
		{
			(*dayOfWeek_p)++;
			*sequence_p = 1;
		}
	}
	else
	{
		(*sequence_p)++;
	}
}
void EditCourseTable(int* dayOfWeek, int* sequence, bool* con) {
	Output("- . - . - . - . - . - . - . - .  . - . - . - . - . - . - . - . -", REMIND_FONT);
	int courseCountEachDay = FileManagerDBP_CoursesEachDay_In();
	// ��ȡÿ�տγ�
	string courseName;
	for (int i = 1; i <= 7/*�˴�'7'��Ϊһ��7��*/; i++)  // ���У���ά���
	{
		for (int j = 1; j <= courseCountEachDay; j++)  // ����
		{
			FileManagerDBC_In(i, j, &courseName);
			if (i == *dayOfWeek && j == *sequence && courseName != "null")
			{
				OutputWR(courseName + "]\t", REMIND_FONT);  // ���ָ�������ںͿγ����ڱ���ӡ���������ӹ��
			}
			else if (courseName == "null")
			{
				i = 8;
				j = courseCountEachDay + 1;
				// ������DB_classschedule.txt�����߸�����ʱ���˳�ѭ��
			}
			else
			{
				OutputWR(courseName + "\t");
			}
			if (j == courseCountEachDay)
			{
				OutputWR("\n");
			}
		}
	}
	// ��ӡ�α�

	Output("Enter 'course_name' or 'dayOfWeek' or \"quit\" or \"delete\"", HIGHLIGHT_FONT);
	Output("'course_name' MUST BE 4 BYTES LONG!", REMIND_FONT);
	string courseChanged;
	cin >> courseChanged;
	// ��������
	// �����������߼�����

	if (courseChanged >= "1" && courseChanged <= "7")  // ��ʱcourse_changed��������
	{
		*dayOfWeek = atoi(courseChanged.c_str());  // ת��string�͵�int��
		Output("Enter 'sequence'", HIGHLIGHT_FONT);
		cin >> *sequence;
		if (IfValueAllow(1, courseCountEachDay, *sequence) == false)
		{
			*sequence = courseCountEachDay;  // ��ֹ����������֣���������
			Output("Now,sequence=" + *sequence);
		}
		Output("Enter 'course'", HIGHLIGHT_FONT);
		cin >> courseChanged;

		if (courseChanged == "delete")
		{
			courseChanged = "    ";
			FileManagerDBC_Out(*dayOfWeek, *sequence, &courseChanged);
			MoveCursor(dayOfWeek, sequence, courseCountEachDay);
		}
		else
		{
			FileManagerDBC_Out(*dayOfWeek, *sequence, &courseChanged);
			MoveCursor(dayOfWeek, sequence, courseCountEachDay);
		}
	}
	// ���һ�����Ĵ��򣬸��Ŀγ�

	else if (courseChanged == "quit")
	{
		*con = false;
	}
	// ��������˳�

	else if (courseChanged == "delete")
	{
		courseChanged = "    ";
		FileManagerDBC_Out(*dayOfWeek, *sequence, &courseChanged);
		MoveCursor(dayOfWeek, sequence, courseCountEachDay);
	}
	// �������˳�������ɾ��

	else
	{
		FileManagerDBC_Out(*dayOfWeek, *sequence, &courseChanged);
		MoveCursor(dayOfWeek, sequence, courseCountEachDay);
	}
	// ����ģ�˳��������Ŀγ�
}

void MoveCursor(int* sequence_p, const int courseCountEachDay) {
	if (*sequence_p == courseCountEachDay)
	{
		*sequence_p = 1;
	}
	else
	{
		(*sequence_p)++;
	}
}
void EditTimeTable(int* dayOfWeek, int* sequence, bool* con) {
	Output("- . - . - . - . - . - . - . - .  . - . - . - . - . - . - . - . -", REMIND_FONT);
	Output("Day of week:" + to_string(*dayOfWeek));
	int courseCountEachDay = FileManagerDBP_CoursesEachDay_In();
    // ����fileManageR��ȡÿ�տγ�
	for (int i = 1; i <= courseCountEachDay; i++)
	{
		char timeBegin[4];
		char timeEnd[4];
		FileManagerDBT_In(*dayOfWeek, i, true, timeBegin);
		FileManagerDBT_In(*dayOfWeek, i, false, timeEnd);
		string classTime =
			"Lesson No." + to_string(i) + ":  " +
			timeBegin[0] + timeBegin[1] + ":" + timeBegin[2] + timeBegin[3] + "-" +
			timeEnd[0] + timeEnd[1] + ":" + timeEnd[2] + timeEnd[3];  // Lesson No.1:��ʼʱ��-����ʱ��
		if (*sequence == i)
		{
			Output(classTime + "]", REMIND_FONT);
		}
		else
		{
			Output(classTime);
		}
	}
	Output("Input \"next\" to choose next course,\"quit\" to stop editing", HIGHLIGHT_FONT);
	Output("Input time(formal) to change the begining time", HIGHLIGHT_FONT);
	Output("Example:Please write \"07:50\" as \"750\",\"13:55\" as \"1355\"", REMIND_FONT);
	string timeInput;
	cin >> timeInput;
	if (timeInput == "next")
	{
		MoveCursor(sequence, courseCountEachDay);
	}
	else if (timeInput == "quit")
	{
		*con = false;
	}
	else
	{
		int timeInput_int;
		timeInput_int = atoi(timeInput.c_str());
		FileManagerDBT_Out(*dayOfWeek, *sequence, true, timeInput_int);
		Output("Input ending time", HIGHLIGHT_FONT);
		cin >> timeInput_int;
		FileManagerDBT_Out(*dayOfWeek, *sequence, false, timeInput_int);
		MoveCursor(sequence, courseCountEachDay);
	}
}

void EditRefreshTime() {
	Output("Enter Tick_time(once / Xs)(2~600s)", HIGHLIGHT_FONT);
	int time_tt;
	cin >> time_tt;
	if (IfValueAllow(2, 600, time_tt))
	{
		FileManagerDBP_Out(10, time_tt);  // �߼�ˢ�¼��(s)
	}
}

void AddToStartup() {
	Output("Please enter your user name", HIGHLIGHT_FONT);
	string username;
	cin >> username;
	Output("Please copy the shortcut to 'C:\\Users\\" + username + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup'", HIGHLIGHT_FONT);
	Output("Press 'c' to continue", HIGHLIGHT_FONT);
	char con;
	cin >> con;
	string command = "explorer.exe    C:\\Users\\" + username + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";
	if (con == 'C' || con == 'c')
	{
		system(command.c_str());
	}
}

void SetForeground() {
	Output("Set foreground/Unset foreground(s/u)", HIGHLIGHT_FONT);
	char foregroundOperation;
	cin >> foregroundOperation;
	if (foregroundOperation == 'S' || foregroundOperation == 's')
	{
		FileManagerDBP_Out(11, 1);
	}
	else if (foregroundOperation == 'U' || foregroundOperation == 'u')
	{
		FileManagerDBP_Out(11, 0);
	}
}

void EndProcess() {
	Output("End/Restart 'InfoDP'?(e/r)", HIGHLIGHT_FONT);
	Output("Press any other key to cancel", HIGHLIGHT_FONT);
	char processOperation;
	cin >> processOperation;
	if (processOperation == 'E' || processOperation == 'e')
	{
	    system("taskkill /f /t /im InfoDP.exe");
	}
	else if (processOperation == 'R' || processOperation == 'r')
	{
		system("taskkill /f /t /im InfoDP.exe");
		STARTUPINFO si = { sizeof(si) };
		PROCESS_INFORMATION pi;
		TCHAR szCommandLine[] = TEXT("InfoDP");
		CreateProcess(NULL, szCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}
