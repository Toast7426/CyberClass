#pragma once
#include <iostream>
#include <fstream>
#include <string>  
#include "file_iofs.h"
using namespace std;
//函数使用小驼峰
//变量使用下划线

void sign()
{
	cout << " ______                   ____                   __________       __________"
		<< "\n";
	cout << "|\\_   _\\                 |\\  _\\                 |\\  ______ \\     |\\  ______ \\"
		<< "\n";
	cout << "\\|_\\  \\|                  \\\\ \\|                  \\\\ \\    \\\\ \\     \\\\ \\    \\\\ \\"
		<< "\n";
	cout << "   \\\\  \\    _  ______    __\\\\ \\__   ________      \\\\ \\    \\\\ \\     \\\\ \\___// /"
		<< "\n";
	cout << "    \\\\  \\   |\\/ ____ \\   \\|_|\\ \\_| |\\  ____ \\      \\\\ \\    \\\\ \\     \\\\  ____/"
		<< "\n";
	cout << "     \\\\  \\   \\\\ \\  \\\\ \\      \\\\ \\   \\\\ \\  \\\\ \\      \\\\ \\    \\\\ \\     \\\\ \\___|"
		<< "\n";
	cout << "      \\\\  \\_  \\\\ \\  \\\\ \\      \\\\ \\   \\\\ \\__\\\\ \\      \\\\ \\___// /      \\\\ \\"
		<< "\n";
	cout << "     |\\_____\\  \\\\_\\  \\\\_\\      \\\\_\\   \\\\_______\\      \\\\_\\____/        \\\\_\\"
		<< "\n";
	cout << "     \\|_____|   \\|_|  \\|_|      \\|_|   \\|_______|      \\|_____|         \\|_|"
		<< "\n";
}

void information()
{
	cout << "GitHub:" <<
		"https://github.com/Toast7426/CyberClass" << endl;
	cout << "哔哩哔哩:" <<
		"https://space.bilibili.com/3493280968870105?spm_id_from=333.1007.0.0" << endl;
}

void chooseFunction();
bool fileExists(const std::string& filename);
int getNumLong(int num);
void fileManager(int line, int data);
int fileManagerR(int dayOfWeek, int sequence, bool ifRead, string* reCourse);
bool valueIfAllow(int min, int max, int input);
void init();
void setPos();
void alphaValue();
void font();
void cursorMove(int* dayOfWeek_p, int* sequence_p, int lineLength);
void editCourseTable();
void editTimeTable();
void editUpdateTime();
void addToStartup();
void foreground();
//声明函数

void chooseFunction()
{
	while (true)
	{
		cout << "/*================================";
		cout << "================================*/\n";
		cout << "Enter the number to choose the functions\n";
		cout << "0.The information of \"Cyber Class\"\n";
		cout << "1.Init\n";
		cout << "2.Set window position\n";
		cout << "3.Set alpha value\n";
		cout << "4.Set font\n";
		cout << "5.Edit course table\n";
		cout << "6.Edit timetable\n";
		cout << "7.Edit update time\n";
		cout << "8.Add to 'startup'\n";
		cout << "9.Set Foreground\n";
		cout << "/*- - - - - - - - - - - - - - - - ";
		cout << "- - - - - - - - - - - - - - - - */" << endl;
		int enter_num;
		cin >> enter_num;
		switch (enter_num)
		{
		case (0):
		{
			information();
			break;
		}
		case (1):
		{
			init();
			break;
		}
		case (2):
		{
			setPos();
			break;
		}
		case (3):
		{
			alphaValue();
			break;
		}
		case (4):
		{
			font();
			break;
		}
		case (5):
		{
			editCourseTable();
			break;
		}
		case (6):
		{
			editTimeTable();
			break;
		}
		case (7):
		{
			editUpdateTime();
			break;
		}
		case (8):
		{
			addToStartup();
			break;
		}
		case (9):
		{
			foreground();
			break;
		}
		}
	}
}
//引导函数

bool valueIfAllow(int min, int max, int input)
{
	if (input >= min && input <= max)
	{
		return true;
	}
	else
	{
		cout << "The value is limited" << endl;
		return false;
	}
}
//判断输入数值是否在范围内

void init()
{
	char init_file;
	cout << "Are you sure to init 'properties.txt'/'table.txt'?(p/t/n)" << endl;
	cin >> init_file;
	if(init_file == 'p')
	{
	    fstream ofsP("properties.txt", ios::out);
	    ofsP << "0850";//窗口宽_l1
	    ofsP << "0375";//X坐标_l2
	    ofsP << "0050";//窗口高_l3
		ofsP << "0008";//每日课程_l4
		ofsP << "0255";//透明度_l5
		ofsP << "0034";//字体_l6
		ofsP << "0200";//字体颜色R_l7
		ofsP << "0200";//字体颜色G_l8
		ofsP << "0255";//字体颜色B_l9
		ofsP << "0200";//刷新间隔_l10
		ofsP << "0000";//窗口前置_l11
		ofsP.close();
		cout << "Successful!" << endl;
	}
	else if (init_file == 't')
	{
		fstream ofsT("table.txt", ios::out);
		char initLine[64] = { " " };
		for (int i = 1; i <= 7; i++);
		{
		    ofsT << initLine << "\n";//防止读取课表时while卡死等问题
		}
		ofsT.close();
		cout << "Successful!" << endl;
	}
	else
	{
		cout << "Cancel" << endl;
	}
}
//初始化

void setPos()
{
	int screen_wide;
	int lesson_num;
	int window_high;
	cout << "Enter 'screen_wide'" << endl;
	cin >> screen_wide;
	cout << "Enter 'lesson_num'" << endl;
	cin >> lesson_num;
	cout << "Enter 'window_high'" << endl;
	cin >> window_high;
	int window_wide;
	int window_Xpos;
	window_wide = 3 * lesson_num * window_high + window_high;
	window_Xpos = screen_wide / 2 - window_wide / 2;
	fileManager(1, window_wide);
	fileManager(2, window_Xpos);
	fileManager(3, window_high);
	fileManager(4, lesson_num);
}
//计算坐标

void alphaValue()
{
	int alpha;
	cout << "Enter 'alpha'(1~255)" << endl;
	cin >> alpha;
	if (valueIfAllow(1, 255, alpha))
	{
		fileManager(5, alpha);
	}
}
//Alpha值

struct ms_RGB {
	short red;
	short green;
	short blue;
};//颜色结构体
const struct ms_RGB C_VISUALSTUDIO_PURPLE = { 0x9c, 0x5a, 0xd1 };
const struct ms_RGB C_PYTHON_YELLO = { 0xff, 0xde, 0x57 };
const struct ms_RGB C_WINDOWS_BLUE = { 0x00, 0x78, 0xd7 };
const struct ms_RGB C_BLENDER_ORANGE = { 0xe8, 0x7d, 0x0d };
const struct ms_RGB C_MIKU_GREEN = { 0x27, 0xc5, 0xbb };
void font()
{
	int font_size;
	cout << "Enter 'font_size'" << endl;
	cin >> font_size;
	fileManager(6, font_size);

	cout << "Please choose color\n";
	cout << "1.VISUALSTUDIO_PURPLE\t2.PYTHON_YELLO\t3.WINDOWS_BLUE\n";
	cout << "4.BLENDER_ORANGE\t5.MIKU_GREEN" << endl;
	int color_num;
	cin >> color_num;
	switch(color_num)
	{
	case(1):
	{
		fileManager(7, C_VISUALSTUDIO_PURPLE.red);//写入(red)
		fileManager(8, C_VISUALSTUDIO_PURPLE.green);//写入(green)
		fileManager(9, C_VISUALSTUDIO_PURPLE.blue);//写入(blue)
		break;
	}
	case(2):
	{
		fileManager(7, C_PYTHON_YELLO.red);
		fileManager(8, C_PYTHON_YELLO.green);
		fileManager(9, C_PYTHON_YELLO.blue);
		break;
	}
	case(3):
	{
		fileManager(7, C_WINDOWS_BLUE.red);
		fileManager(8, C_WINDOWS_BLUE.green);
		fileManager(9, C_WINDOWS_BLUE.blue);
		break;
	}
	case(4):
	{
		fileManager(7, C_BLENDER_ORANGE.red);
		fileManager(8, C_BLENDER_ORANGE.green);
		fileManager(9, C_BLENDER_ORANGE.blue);
		break;
	}
	case(5):
	{
		fileManager(7, C_MIKU_GREEN.red);
		fileManager(8, C_MIKU_GREEN.green);
		fileManager(9, C_MIKU_GREEN.blue);
		break;
	}
	}
}
//设置字号和颜色

void cursorMove(int* dayOfWeek_p, int* sequence_p, int lineLength)
{
	if (*sequence_p == lineLength)/*将光标移动到下一个*/
	{
		if (*dayOfWeek_p == 7)
		{
			*dayOfWeek_p = 1;
			*sequence_p = 1;
		}
		else
		{
			(*dayOfWeek_p)++;/*C6269引发错误*/
			*sequence_p = 1;
		}
	}
	else
	{
		(*sequence_p)++;/*C6269引发错误*/
	}
}
void editCourseTable()
{
	int dayOfWeek = 1;
	int sequence = 1;
	bool con/*continue*/ = true;//con为true,则持续编辑课表
	while (con)
	{
		int courses_each_day = fileManagerR(255, NULL, NULL, NULL);
		string course;
		for (int i = 1; i <= 7; i++)//横行（二维表格）
		{
			for (int j = 1; j <= courses_each_day; j++)//竖行
			{
				fileManagerR(i, j, true, &course);
				if (i == dayOfWeek && j == sequence && course != "null")
				{
					cout << course << "] ";//如果指定的日期和课程正在被打印，在其后添加光标
				}
				else if (course == "null")
				{
					i = 8;
					j = courses_each_day + 1;
					cout << "WARING:\"table.txt\"is incomplete";
					/*当发现table.txt不满七个横行时，给出警告并退出循环*/
				}
				else 
				{
					cout << course << "  ";
				}
			}
			cout << "\n";
		}
		//打印课表

		cout << "Enter 'course' or 'dayOfWeek' or \"quit\" or \"delete\"" << endl;
		cout << "'course' MUST BE 4 BYTES LONG!" << endl;
		string course_changed;
		cin >> course_changed;
		//引导输入
		//接下来进行逻辑处理

		if (course_changed >= "1" && course_changed <= "7")//此时course_changed代表星期
		{
			dayOfWeek = std::atoi(course_changed.c_str());
			cout << "Enter 'sequence'" << endl;
			cin >> sequence;
			if (valueIfAllow(1, courses_each_day, sequence) == false)
			{
				sequence = courses_each_day;//防止输入过大数字，引发问题
				cout << "Please enter correct number\n";
				cout << "Now,sequence=" << courses_each_day << endl;
			}
			cout << "Enter 'course'" << endl;
			cin >> course_changed;

			bool deleteCourse = false;
			if (course_changed == "delete")
			{
				course_changed = "    ";
				deleteCourse = true;
			}
			fileManagerR(dayOfWeek, sequence, false, &course_changed);

			if (deleteCourse == false)/*将光标移动到下一个,在操作为删除时，不移动*/
			{
				cursorMove(&dayOfWeek, &sequence, courses_each_day);
			}
		}
		//情况一：更改次序，更改课程

		else if(course_changed == "quit")
		{
			con = false;
		}
		//情况二：退出

		else if (course_changed == "delete")
		{
		    {
			    course_changed = "    ";
		    }
		    fileManagerR(dayOfWeek, sequence, false, &course_changed);
		}
		//情况三：顺序继续删除
		
		else
		{
			fileManagerR(dayOfWeek, sequence, false, &course_changed);
			cursorMove(&dayOfWeek, &sequence, courses_each_day);
		}
		//情况四：顺序继续更改课程
	}

}
//编辑课表

void editTimeTable()
{
	bool con/*continue*/ = true;
	while (con)
	{
		int dayOfWeek;
		char num[16];
		cout << "Enter 'dayOfWeek'" << endl;
		cin >> dayOfWeek;
		for (int i = 1; i <= fileManagerR(255, NULL, NULL, NULL); i++)
		{
			char* p_num = fileManagerT(dayOfWeek * fileManagerR(255, NULL, NULL, NULL) - fileManagerR(255, NULL, NULL, NULL)/*借用fileManageR读取每日课程*/ + i,
				&num[16]);
			cout << "Lesson No." << i << ":  ";//Lesson No.1:
			cout << p_num[0] << p_num[1] << ":" << p_num[2] << p_num[3] << "-";
			cout << p_num[4] << p_num[5] << ":" << p_num[6] << p_num[7] << endl;
		}
	}
}
//编辑时间表

void editUpdateTime()
{
	cout << "Enter TPS(ms / once)(50~9999ms)" << endl;
	int time_tps;
	cin >> time_tps;
	if (valueIfAllow(50, 9999, time_tps))
	{
	    fileManager(11, time_tps);//逻辑刷新间隔(ms)
	}
}
//编辑更新频率

void addToStartup()
{
	//cout << "Please copy the shortcut to 'C:\\Users\\Toast\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup'" << endl;
	cout << "Please enter your user name" << endl;
	string username;
	cin >> username;
	cout << "Please copy the shortcut to 'C:\\Users\\" << username << "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup'" << endl;
	cout << "Press 'c' to continue" << endl;
	char con;
	cin >> con;
	string command = "explorer.exe    C:\\Users\\" + username + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";
	if (con == 'c')
	{
	    system(command.c_str());
	}
}
//添加开机启动

void foreground()
{
	cout << "Set foreground(y/n)" << endl;
	char if_foreground;
	cin >> if_foreground;
	if (if_foreground == 'y')
	{
		fileManager(11, 1);
	}
	else if (if_foreground == 'n')
	{
		fileManager(11, 0);
	}
}
//设置前置
