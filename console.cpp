#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "console.h"
#include "file_io.h"
#include "color_define.h"
#include "output2cmd.h"
using namespace std;

/*void sign()
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
}*/

void ExSign()
{
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

void information()
{
	Output("Vision1.2.007[Beta]", REMIND_FONT);
	Output("GitHub:", HIGHLIGHT_FONT);
	Output("https://github.com/Toast7426/CyberClass", URL_FONT);
	Output("哔哩哔哩::", HIGHLIGHT_FONT);
	Output("https://space.bilibili.com/3493280968870105?spm_id_from=333.1007.0.0", URL_FONT);
	Output("Bugs?Can't run?How about Windows8 compatibility mode?", REMIND_FONT);
}

void chooseFunction()
{
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
		int inputNum = atoi(inputNum_str.c_str());
		switch (inputNum)
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
			editRefreshTime();
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

bool valueIfAllow(int min, int max, int input)
{
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

void init()
{
	Output("To init 'properties'/'timetable'/'classschedule'?(p/t/c)", REMIND_FONT);
	Output("Press any other key to cancel", REMIND_FONT);
	char init_file;
	cin >> init_file;
	if (init_file == 'P' || init_file == 'p')
	{
		fstream ofsP("DB_properties.txt", ios::out);
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
	else if (init_file == 'T' || init_file == 't')
	{
		fstream ofsT("DB_timetable.txt", ios::out);
		char initLine[129] = { " " };
		initLine[128] = '\n';
		for (int i = 1; i <= 7; i++)
		{
			for (int j = 0; j <= 128; j++)
			{
				ofsT << initLine[j];//防止读取时间表时while卡死等问题
			}
		}
		ofsT.close();
		Output("Successful!");
	}
	else if (init_file == 'C' || init_file == 'c')
	{
		fstream ofsC("DB_classschedule.txt", ios::out);
		char initLine[65] = { " " };
		initLine[64] = '\n';
		for (int i = 1; i <= 7; i++)
		{
			for (int j = 0; j <= 64; j++)
			{
			    ofsC << initLine[j];//防止读取课表时while卡死等问题
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

void setPos()
{
	int screen_wide;
	int lesson_num;
	int window_high;
	Output("Enter 'screen_wide'(px)", HIGHLIGHT_FONT);
	cin >> screen_wide;
	Output("Enter 'number of courses per day'", HIGHLIGHT_FONT);
	cin >> lesson_num;
	Output("Enter 'window_high'(px)", HIGHLIGHT_FONT);
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

void alphaValue()
{
	int alpha;
	Output("Enter 'alpha'(0(disable)~255)", HIGHLIGHT_FONT);
	cin >> alpha;
	if (valueIfAllow(0, 255, alpha))
	{
		fileManager(5, alpha);
	}
}

void font()
{
	int font_size;
	Output("Enter 'font_size'", HIGHLIGHT_FONT);
	Output("Best font size for window height", HIGHLIGHT_FONT);
	Output("38-50px\t50-70px\t74-100px", HIGHLIGHT_FONT);
	cin >> font_size;
	fileManager(6, font_size);

	Output("Please choose color", HIGHLIGHT_FONT);
	Output("1.VISUALSTUDIO_PURPLE\t2.PYTHON_YELLO\t3.WINDOWS_BLUE", HIGHLIGHT_FONT);
	Output("4.BLENDER_ORANGE\t5.MIKU_GREEN", HIGHLIGHT_FONT);
	int color_num;
	cin >> color_num;
	switch (color_num)
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

void cursorMove(int* dayOfWeek_p, int* sequence_p, int courses_each_day)
{
	if (*sequence_p == courses_each_day)/*将光标移动到下一个*/
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
void editCourseTable()
{
	int dayOfWeek = 1;//与sequence共同定位正在编辑的课程
	int sequence = 1;//与dayOfWeek共同定位正在编辑的课程
	bool con/*continue*/ = true;//con为true,则持续编辑课表
	while (con)
	{
		int courses_each_day = fileManagerR(255, NULL, NULL, NULL);
		//借用fileManageR读取每日课程
		Output("- . - . - . - . - . - . - . - .  . - . - . - . - . - . - . - . -", REMIND_FONT);
		string course;
		for (int i = 1; i <= 7/*此处'7'意为一周7天*/; i++)//横行（二维表格）
		{
			for (int j = 1; j <= courses_each_day; j++)//竖行
			{
				fileManagerR(i, j, true, &course);
				if (i == dayOfWeek && j == sequence && course != "null")
				{
					OutputWR(course + "] ", REMIND_FONT);//如果指定的日期和课程正在被打印，在其后添加光标
				}
				else if (course == "null")
				{
					i = 8;
					j = courses_each_day + 1;
					/*当发现DB_classschedule.txt不满七个横行时，退出循环*/
				}
				else
				{
					OutputWR(course + "  ");
				}
				if (j == courses_each_day)
				{
					OutputWR("\n");
				}
			}
		}
		//打印课表

		Output("Enter 'course_name' or 'dayOfWeek' or \"quit\" or \"delete\"", HIGHLIGHT_FONT);
		Output("'course_name' MUST BE 4 BYTES LONG!", REMIND_FONT);
		string course_changed;
		cin >> course_changed;
		//引导输入
		//接下来进行逻辑处理

		if (course_changed >= "1" && course_changed <= "7")//此时course_changed代表星期
		{
			dayOfWeek = atoi(course_changed.c_str());//转换string型到int型
			Output("Enter 'sequence'", HIGHLIGHT_FONT);
			cin >> sequence;
			if (valueIfAllow(1, courses_each_day, sequence) == false)
			{
				sequence = courses_each_day;//防止输入过大数字，引发问题
				Output("Now,sequence=" + sequence);
			}
			Output("Enter 'course'", HIGHLIGHT_FONT);
			cin >> course_changed;

			if (course_changed == "delete")
			{
				course_changed = "    ";
			    fileManagerR(dayOfWeek, sequence, false, &course_changed);
				cursorMove(&dayOfWeek, &sequence, courses_each_day);
			}
			else
			{
				fileManagerR(dayOfWeek, sequence, false, &course_changed);
				cursorMove(&dayOfWeek, &sequence, courses_each_day);
			}
		}
		//情况一：更改次序，更改课程

		else if (course_changed == "quit")
		{
			con = false;
		}
		//情况二：退出

		else if (course_changed == "delete")
		{
			course_changed = "    ";
			fileManagerR(dayOfWeek, sequence, false, &course_changed);
			cursorMove(&dayOfWeek, &sequence, courses_each_day);
		}
		//情况三：顺序继续后删除

		else
		{
			fileManagerR(dayOfWeek, sequence, false, &course_changed);
			cursorMove(&dayOfWeek, &sequence, courses_each_day);
		}
		//情况四：顺序继续更改课程
	}

}

void cursorMove(int* sequence_p, int courses_each_day)
{
	if (*sequence_p == courses_each_day)
	{
		*sequence_p = 1;
	}
	else
	{
		(*sequence_p)++;
	}
}
void editTimeTable()
{
	int dayOfWeek;
	int sequence = 1;
	cout << "Enter 'dayOfWeek'" << endl;
	cin >> dayOfWeek;
	if (!valueIfAllow(1, 7, dayOfWeek))
	{
		dayOfWeek = 1;
	}
	bool con/*continue*/ = true;//con为true,则持续编辑时间表
	while (con)
	{
		cout << "Day of week:" << dayOfWeek << endl;
		int courseEachDay = fileManagerR(255, NULL, NULL, NULL);
        //借用fileManageR读取每日课程
		Output("- . - . - . - . - . - . - . - .  . - . - . - . - . - . - . - . -", REMIND_FONT);
		for (int i = 1; i <= courseEachDay; i++)
		{
		    char timeBegin[4];
			char timeEnd[4];
			fileManagerT(dayOfWeek, i, true, timeBegin);
			fileManagerT(dayOfWeek, i, false, timeEnd);
			string iStr = to_string(i);
			string classTime =
				"Lesson No." + iStr + ":  " +
				timeBegin[0] + timeBegin[1] + ":" + timeBegin[2] + timeBegin[3] + "-" +
				timeEnd[0] + timeEnd[1] + ":" + timeEnd[2] + timeEnd[3];//Lesson No.1:开始时间-结束时间
			if (sequence == i)
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
			cursorMove(&sequence, courseEachDay);
		}
		else if (timeInput == "quit")
		{
			con = false;
		}
		else
		{
			int timeInput_int;
			timeInput_int = atoi(timeInput.c_str());
			fileManagerT(dayOfWeek, sequence, true, timeInput_int);
			Output("Input ending time", HIGHLIGHT_FONT);
			cin >> timeInput_int;
			fileManagerT(dayOfWeek, sequence, false, timeInput_int);
			cursorMove(&sequence, courseEachDay);
		}//更改时间表
	}
}

void editRefreshTime()
{
	Output("Enter Tick_time(ms / once)(200~9999ms)", HIGHLIGHT_FONT);
	int time_tt;
	cin >> time_tt;
	if (valueIfAllow(200, 9999, time_tt))
	{
		fileManager(10, time_tt);//逻辑刷新间隔(ms)
	}
}

void addToStartup()
{
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

void foreground()
{
	Output("Set foreground/Unset foreground(s/u)", HIGHLIGHT_FONT);
	char if_foreground;
	cin >> if_foreground;
	if (if_foreground == 'S' || if_foreground == 's')
	{
		fileManager(11, 1);
	}
	else if (if_foreground == 'U' || if_foreground == 'u')
	{
		fileManager(11, 0);
	}
}

void EndProcess()
{
	Output("End/Restart 'InfoDP'?(e/r)", HIGHLIGHT_FONT);
	Output("Press any other key to cancel", HIGHLIGHT_FONT);
	char init_file;
	cin >> init_file;
	if (init_file == 'E' || init_file == 'e')
	{
	    system("taskkill /f /t /im InfoDP.exe");
	}
	else if (init_file == 'R' || init_file == 'r')
	{
		system("taskkill /f /t /im InfoDP.exe");
		WinExec("InfoDP.exe", SW_SHOW);
	}
}
