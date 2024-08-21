#pragma once
#include <string>
using namespace std;

/// <summary>
/// 读取配置文件（DB_properties.txt）中的数据
/// </summary>
/// <param name="line">配置项‌</param>
/// <param name="line">窗口宽_l1‌</param>
/// <param name="line">X坐标_l2‌</param>
/// <param name="line">窗口高_l3‌</param>
/// <param name="line">每日课程_l4‌</param>
/// <param name="line">透明度_l5</param>
/// <param name="line">字号_l6</param>
/// <param name="line">字体颜色R_l7‌</param>
/// <param name="line">字体颜色G_l8‌</param>
/// <param name="line">字体颜色B_l9‌</param>
/// <param name="line">数据刷新间隔_l10‌</param>
/// <param name="line">窗口前置_l11‌</param>
/// <returns>配置项值‌</returns>
int ReadDBP(const int line);

/// <summary>
/// 读取课表文件（DB_classschedule.txt）中的数据
/// </summary>
/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="*p">用于返回课程字符串</param>
/// <returns>恒返回0‌</returns>
int ReadDBC(const int dayOfWeek, const int sequence, string* p);

/// <summary>
/// 读取时间表文件（DB_timetable.txt）中的数据
/// </summary>/// <param name="dayOfWeek">星期（用于定位）</param>
/// <param name="sequence">次序（用于定位）‌</param>
/// <param name="beginTime">为true时，将课程开始时间返回</param>
/// <param name="beginTime">为false时，将课程结束时间返回</param>
/// <returns>‌课程开始/结束时间</returns>
int ReadDBT(const int dayOfWeek, const int sequence, const bool beginTime);
