#include<iostream>
#include<cstring>
using namespace std;

int main(){
	freopen("1021.txt" , "r" , stdin);
	int num[10] ={0};
	string number ;
	cin>>number;
	for(int i=0 ; i<number.length() ; i++){
		num[number[i] - '0']++;
	}	
	for(int i=0 ; i<10 ; i++){
		if(num[i]!= 0){
			cout<<i<<":"<<num[i]<<endl;
		}
	}
	return 0;
}
