#pragma once

/// <summary>
/// 打印徽标
/// </summary>
/*void sign();*/

/// <summary>
/// 打印徽标
/// </summary>
void ExSign();

/// <summary>
/// 打印信息
/// </summary>
void information();

/// <summary>
/// 引导函数
/// </summary>
void chooseFunction();

/// <summary>
/// 判断输入数值是否在范围内（多用处）
/// </summary>
/// <returns>如果最小值&lt;=输入值&lt;=最大值，则返回true‌，否则返回false</returns>
bool valueIfAllow(int min, int max, int input);

/// <summary>
/// 初始化数据库
/// </summary>
void init();

/// <summary>
/// 自动计算窗口合适的大小和位置
/// </summary>
void setPos();

/// <summary>
/// 设置背景不透明度
/// </summary>
void alphaValue();

/// <summary>
/// 设置字号和颜色
/// </summary>
void font();

/// <summary>
/// 为editCourseTable所调用,更改一个单元的定位（顺次后移）
/// </summary>
void cursorMove(int* dayOfWeek_p, int* sequence_p, int courses_each_day);

/// <summary>
/// 编辑课表
/// </summary>
void editCourseTable();

/// <summary>
/// 为editTimeTable所调用,更改一个单元的定位（顺次后移）
/// </summary>
void cursorMove(int* sequence_p, int courses_each_day);

/// <summary>
/// 编辑时间表
/// </summary>
void editTimeTable();

/// <summary>
/// 编辑刷新频率
/// </summary>
void editRefreshTime();

/// <summary>
/// 添加到系统开机启动文件夹
/// </summary>
void addToStartup();

/// <summary>
/// 设置窗口前置属性
/// </summary>
void foreground();

/// <summary>
/// 用于关闭或重启InfoDP
/// </summary>
void EndProcess();
