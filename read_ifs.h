#pragma once
#include <string>
using namespace std;

/// <summary>
/// 读取"properties.txt"
/// </summary>
/// <param name="line">配置项‌</param>
/// <param name="line">窗口宽_l1‌</param>
/// <param name="line">X坐标_l2‌</param>
/// <param name="line">窗口高_l3‌</param>
/// <param name="line">每日课程_l4‌</param>
/// <param name="line">透明度_l5</param>
/// <param name="line">字体_l6</param>
/// <param name="line">字体颜色R_l7‌</param>
/// <param name="line">字体颜色G_l8‌</param>
/// <param name="line">字体颜色B_l9‌</param>
/// <param name="line">刷新间隔_l10‌</param>
/// <param name="line">窗口前置_l11‌</param>
/// <returns>配置项值‌</returns>
int read(int line);

/// <summary>
/// 校验文件是否存在‌
/// </summary>
/// <param name="filename">要检查的文件名‌</param>
/// <returns>文件是否存在‌</returns>
bool fileExists(const std::string& filename);

/// <summary>
/// 读取课表文件（table.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="ifRead">true时读取课表，将结果返回于*reCourse，false时将*reCourse中数据写入课表</param>
/// <param name="*p">课程字符串</param>
/// <returns>参数dayOfWeek为255时返回每日课程数，其余情况无意义‌</returns>
int fileManagerR(int dayOfWeek, int sequence, string* p);

/// <summary>
/// 读取"time.txt"
/// </summary>/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="beginTime">为true时，将课程开始时间返回</param>
/// <param name="beginTime">为false时，将课程结束时间返回</param>
int fileManagerT(int dayOfWeek, int sequence, bool beginTime);
