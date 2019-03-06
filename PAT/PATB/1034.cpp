#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
long long max(long long a, long long b) {		//��ȡ���Լ��
	return b == 0 ? a : max(b, a % b);
}
long long classify(long long a[4]) {		//�������
	a[0] = 0;	//��ʼ����������
	a[3] = 1;   //��ʼ������
	if (a[1] < 0) {
		a[1] = abs(a[1]);
		a[3] *= -1;  //�����۳�
	}
	if (a[2] < 0) {
		a[2] = abs(a[2]);
		a[3] *= -1;
	}
	long long i = max(a[1], a[2]);
	a[1] /= i;
	a[2] /= i;
	if (a[2]) {			//ȷ����ĸ��Ϊ0������Ϊ��������
		a[0] = a[1] / a[2];
		a[1] %= a[2];
	}
	return 0;
}
string show(long long a[4]) {			//����ĿҪ�󷵻ظ÷���
	string s;
	if (a[2] == 0)         //��ĸΪ0������
		return "Inf"; 
	if (a[0] == 0 && a[1] == 0)   //�������ֺͷ���ͬʱΪ0�����ء�0��
		return "0";
	if (a[0])    //�������ִ��ڣ������
		s += (to_string(a[0]));
	if (a[0] && a[1])   //��������ڷ������֣��м���' '(�ո�
		s += ' ';
	if (a[1])       //���Ӵ��ڣ�������������
		s += (to_string(a[1]) + '/' + to_string(a[2]));
	if (a[3] == -1)      //���Ϊ��������Ҫ�Ӹ��ź�����
		s = "(-" + s + ")";
	return s;
}
int main()
{
	long long a[4], b[4], c[4][4];  //����ֱ�洢�������֡����ӡ���ĸ�ͷ��š�
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
