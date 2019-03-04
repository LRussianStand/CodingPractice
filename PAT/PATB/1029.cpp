#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
bool m[150];
int main(){
	freopen("1029.txt" , "r" , stdin);
	string a, b;
	char ch;
	while (1) {
		ch = toupper(getchar());
		if (ch == '\n')break;
		if (!m[(int)ch]++) 
			a += ch;
	}
	cout<<a<<endl;
	getline(cin, b);
	for (int i = 0; i < b.length(); i++) 
		a.erase(remove(a.begin(), a.end(), toupper(b[i])), a.end());    //É¾³ý»µ¼ü
	cout << a;
	return 0;
}
