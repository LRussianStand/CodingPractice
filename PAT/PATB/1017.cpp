#include<iostream>
#include<cstring>
using namespace std;

int main(){
// 	freopen("1017.txt" , "r" , stdin);
	string number;
	char num[1000];
	int index = 0 , a , temp ,remainder=0;
	cin>>number>>a;
	
	for(int i=0 ; i<number.length() ; i++){
		temp = (number[i]-'0') + remainder*10;
		remainder = temp%a;
		num[index++] = temp/a+'0'; 
	}
	int i=0;
	if(num[0] == '0' && index >1){
	  i=1;
	}
	for(; i<index ; i++){
		cout<<num[i];
	}
	cout<<" "<<remainder;
	return 0;
}
