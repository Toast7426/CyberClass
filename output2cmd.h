#pragma once
#include <string>
using namespace std;

/// <summary>
/// 输出字符串
/// </summary>
/// <param name="textStr">要输出的字符串‌</param>
/// <param name="attributeValue">输出字符串的‌属性</param>
void Output(string textStr, string attributeValue);

/// <summary>
/// 输出字符串
/// </summary>
/// <param name="textStr">要输出的字符串‌</param>
void Output(string textStr);

/// <summary>
/// 输出字符串(WithoutReturn)
/// </summary>
/// <param name="textStr">要输出的字符串‌</param>
/// <param name="attributeValue">输出字符串的‌属性</param>
void OutputWR(string textStr, string attributeValue);

/// <summary>
/// 输出字符串(WithoutReturn)
/// </summary>
/// <param name="textStr">要输出的字符串‌</param>
void OutputWR(string textStr);

#define REMIND_FONT "1;93"
#define WARNING_FONT "33"
#define ERROR_FONT "31"
#define URL_FONT "4;94"
#define HIGHLIGHT_FONT "1"//引导输入
#define SIGN_FONT "32"
