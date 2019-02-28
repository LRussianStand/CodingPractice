#include<iostream>
#include<iomanip>
#define CLK 100
using namespace std;
long c1, c2;  //ע�ⷶΧ
long c;
int main(){
	freopen("1026.txt" , "r" , stdin);
	cin >> c1 >> c2;
	c = c2 - c1;
	int hour = c / (3600 * CLK);
	c = c % (3600 * CLK);
	int min = c / (60 * CLK);
	c = c % (60 * CLK);
	int second = (double)c / CLK + 0.5;
	cout.fill('0');
	cout << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << second;
	cout << endl;
}
