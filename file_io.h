#pragma once
#include <string>
using namespace std;

/// <summary>
/// 校验文件是否存在‌
/// </summary>
/// <param name="filename">要检查的文件名‌</param>
/// <returns>文件是否存在‌</returns>
bool FileExists(const string filename);

/// <summary>
/// 写入配置文件（DB_properties.txt）中的数据
/// </summary>
/// <param name="line">写入位置（配置项）</param>
/// <param name="data">写入数据‌</param>
void FileManagerDBP_Out(const int line, const int data);

/// <summary>
/// 仅用于获取每日课程数
/// </summary>
/// <returns>每日课程数‌</returns>
int FileManagerDBP_CoursesEachDay_In();

/// <summary>
/// 读取课表文件（DB_classschedule.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="*reCourse">课程字符串，其用于存储要读取的课程名称</param>
void FileManagerDBC_In(const int dayOfWeek, const int sequence,
	string* reCourse);

/// <summary>
/// 写入课表文件（DB_classschedule.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="*wrCourse">课程字符串，其用于接收要写入的课程名称</param>
void FileManagerDBC_Out(const int dayOfWeek, const int sequence,
	string* wrCourse);

/// <summary>
/// 读取时间文件（DB_timetable.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="beginTime">为true时，将课程开始时间返回于*p_num</param>
/// <param name="beginTime">为false时，将课程结束时间返回于*p_num</param>
/// <param name="*p_num">以字符串形式返回时间（7：50记作0750）‌</param>
void FileManagerDBT_In(const int dayOfWeek, const int sequence,
	const bool beginTime, char* p_num);

/// <summary>
/// 写入时间文件（DB_timetable.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="beginTime">为true时，将timeValue作为课程开始时间写入</param>
/// <param name="beginTime">为false时，将timeValue作为课程结束时间写入</param>
/// <param name="timeValue">以数值形式传入时间（7：50记作750）‌</param>
void FileManagerDBT_Out(const int dayOfWeek, const int sequence,
	const bool beginTime, const int timeValue);

/// <summary>
/// 得到一个十进制数的位数（多用处）
/// </summary>
/// <param name="num">要进行判断的十进制数</param>
/// <returns>返回位数，num为负数或大于9999时返回值为5‌</returns>
int GetNumLong(const int num);
