#pragma once
/// <summary>
/// 打印徽标
/// </summary>
void ExSign();

/// <summary>
/// 打印信息
/// </summary>
void PrintInformation();

/// <summary>
/// 引导函数
/// </summary>
void ChooseFunction();

/// <summary>
/// 判断输入数值是否在范围内（多用处）
/// </summary>
/// <returns>如果最小值&lt;=输入值&lt;=最大值，则返回true‌，否则返回false</returns>
bool IfValueAllow(const int min, const int max, const int input);

/// <summary>
/// 初始化数据库
/// </summary>
void Init();

/// <summary>
/// 自动计算窗口合适的大小和位置
/// </summary>
void SetPos();

/// <summary>
/// 设置背景不透明度
/// </summary>
void SetAlphaValue();

/// <summary>
/// 设置字号和颜色
/// </summary>
void SetFont();

/// <summary>
/// 为EditCourseTable所调用,更改一个单元的定位（顺次后移）
/// </summary>
void MoveCursor(int* dayOfWeek_p, int* sequence_p, const int courseCountEachDay);

/// <summary>
/// 编辑课表
/// </summary>
void EditCourseTable(int* dayOfWeek, int* sequence, bool* con);

/// <summary>
/// 为EditTimeTable所调用,更改一个单元的定位（顺次后移）
/// </summary>
void MoveCursor(int* sequence_p, const int courseCountEachDay);

/// <summary>
/// 编辑时间表
/// </summary>
void EditTimeTable(int* dayOfWeek, int* sequence, bool* con);

/// <summary>
/// 编辑刷新频率
/// </summary>
void EditRefreshTime();

/// <summary>
/// 添加到系统开机启动文件夹
/// </summary>
void AddToStartup();

/// <summary>
/// 设置窗口前置属性
/// </summary>
void SetForeground();

/// <summary>
/// 用于关闭或重启InfoDP
/// </summary>
void EndProcess();
