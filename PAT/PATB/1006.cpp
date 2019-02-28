#include<iostream>
using namespace std;

//如果是n位 
int main(){
	freopen("1006.txt" , "r" , stdin);
	int number;
	cin>>number;
	if(number > 1000){
		cin>>number;
	}
	int num[3] = {0,0,0};
	//提取每一位 
	for(int i=2 ; i>=0 ; i--){
		num[i] = number % 10;
		number = number / 10;
	}
	for(int i=0 ; i<num[0] ; i++){
		cout<<"B";
	}
	for(int i=0 ; i<num[1] ; i++){
		cout<<"S";
	}
	for(int i=0 ; i<num[2] ; i++){
		cout<<i+1;
	}
	return 0;
} 
