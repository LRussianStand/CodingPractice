#include <string>
#include<iostream>
#include <sstream>
using namespace std;
int main(){
	double a = 123.32;
	string res;
	stringstream ss;         // ������ss
	ss << a;   
	ss >> res;  
	                 //����ssת�����ַ���
	return 0;
}
