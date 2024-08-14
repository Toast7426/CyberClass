#include <iostream>
#include <string>
using namespace std;

void Output(string textStr, string attributeValue)
{
	string attribute = "\033[" + attributeValue + "m";
	cout << attribute << textStr << "\033[0m" << endl;
}

void Output(string textStr)
{
	cout << textStr << endl;
}

void OutputWR(string textStr, string attributeValue)
{
	string attribute = "\033[" + attributeValue + "m";
	cout << attribute << textStr << "\033[0m";
}

void OutputWR(string textStr)
{
	cout << textStr;
}
