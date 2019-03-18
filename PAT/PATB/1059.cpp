#include <string>
#include<iostream>
#include <sstream>
using namespace std;
int main(){
	double a = 123.32;
	string res;
	stringstream ss;         // 定义流ss
	ss << a;   
	ss >> res;  
	                 //将流ss转化成字符串
	return 0;
}
