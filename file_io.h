#pragma once
#include <string>
using namespace std;

/// <summary>
/// 校验文件是否存在‌
/// </summary>
/// <param name="filename">要检查的文件名‌</param>
/// <returns>文件是否存在‌</returns>
bool fileExists(const string filename);

/// <summary>
/// 写入配置文件（properties.txt）中的数据
/// </summary>
/// <param name="line">写入位置（配置项）</param>
/// <param name="data">写入数据‌</param>
void fileManager(int line, int data);

/// <summary>
/// 读取和写入课表文件（table.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="ifRead">true时读取课表，将结果返回于*reCourse，false时将*reCourse中数据写入课表</param>
/// <param name="*reCourse">课程字符串，参数ifRead为true时，其用于存储要读取的课程名称</param>
/// <param name="*reCourse">课程字符串，参数ifRead为false时，其用于接收要写入的课程名称</param>
/// <returns>参数dayOfWeek为255时返回每日课程数，其余情况无意义‌</returns>
int fileManagerR(int dayOfWeek, int sequence, bool ifRead, string* reCourse);

/// <summary>
/// 读取时间文件（time.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="beginTime">为true时，将课程开始时间返回于*p_num</param>
/// <param name="beginTime">为false时，将课程结束时间返回于*p_num</param>
/// <param name="*p_num">以字符串形式返回时间（7：50记作0750）‌</param>
void fileManagerT(int dayOfWeek, int sequence, bool beginTime, char* p_num);

/// <summary>
/// 写入时间文件（time.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="beginTime">为true时，将课程开始时间于timeValue写入</param>
/// <param name="beginTime">为false时，将课程结束时间于timeValue写入</param>
/// <param name="timeValue">以数值形式传入时间（7：50记作750）‌</param>
void fileManagerT(int dayOfWeek, int sequence, bool beginTime, int timeValue);

/// <summary>
/// 得到一个十进制数的位数（多用处）
/// </summary>
/// <param name="num">要进行判断的十进制数</param>
/// <returns>返回位数，num为负数或大于9999时返回值为5‌</returns>
int getNumLong(int num);
