#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
long long max(long long a, long long b) {		//获取最大公约数
	return b == 0 ? a : max(b, a % b);
}
long long classify(long long a[4]) {		//化简分数
	a[0] = 0;	//初始化整数部分
	a[3] = 1;   //初始化符号
	if (a[1] < 0) {
		a[1] = abs(a[1]);
		a[3] *= -1;  //符号累乘
	}
	if (a[2] < 0) {
		a[2] = abs(a[2]);
		a[3] *= -1;
	}
	long long i = max(a[1], a[2]);
	a[1] /= i;
	a[2] /= i;
	if (a[2]) {			//确保分母不为0，化简为带分数。
		a[0] = a[1] / a[2];
		a[1] %= a[2];
	}
	return 0;
}
string show(long long a[4]) {			//按题目要求返回该分数
	string s;
	if (a[2] == 0)         //分母为0，报错
		return "Inf"; 
	if (a[0] == 0 && a[1] == 0)   //整数部分和分子同时为0，返回‘0’
		return "0";
	if (a[0])    //整数部分存在，则加入
		s += (to_string(a[0]));
	if (a[0] && a[1])   //如果还存在分数部分，中间有' '(空格）
		s += ' ';
	if (a[1])       //分子存在，则加入分数部分
		s += (to_string(a[1]) + '/' + to_string(a[2]));
	if (a[3] == -1)      //如果为负数，需要加负号和括号
		s = "(-" + s + ")";
	return s;
}
int main()
{
	long long a[4], b[4], c[4][4];  //数组分别存储整数部分、分子、分母和符号。
	char ch;
	cin >> a[1] >> ch >> a[2] >> b[1] >> ch >> b[2];
	c[0][1] = a[1] * b[2] + a[2] * b[1];
	c[0][2] = a[2] * b[2];
	c[1][1] = a[1] * b[2] - a[2] * b[1];
	c[1][2] = a[2] * b[2];
	c[2][1] = a[1] * b[1];
	c[2][2] = a[2] * b[2];
	c[3][1] = a[1] * b[2];
	c[3][2] = a[2] * b[1];
	classify(a);
	classify(b);
	classify(c[0]);
	classify(c[1]);
	classify(c[2]);
	classify(c[3]);
	cout << show(a) << " + " << show(b) << " = " << show(c[0]) << endl;
	cout << show(a) << " - " << show(b) << " = " << show(c[1]) << endl;
	cout << show(a) << " * " << show(b) << " = " << show(c[2]) << endl;
	cout << show(a) << " / " << show(b) << " = " << show(c[3]) << endl;
	return 0;
}
