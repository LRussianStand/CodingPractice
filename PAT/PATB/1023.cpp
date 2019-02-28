#include<iostream>
using namespace std;

int main(){
	freopen("1023.txt" , "r" , stdin);
	int number[10] , num , index=0;
	char minNumber[50];
	while(cin>>num){
		number[index++] = num;//下标代表数字 存的值代表个数 
	}
	index=0;
	for(int i=0 ; i<10 ; i++){
		if(number[i] > 0){
			for(int j=0 ; j<number[i] ; j++){
				minNumber[index++] = i + '0';
			}
		}
	}
	if(minNumber[0] == '0'){
		for(int i=1 ; i<index ; i++){
			if(minNumber[i] != '0'){
				char temp = minNumber[i];
				minNumber[i] = minNumber[0];
				minNumber[0] = temp;
				break;
			}
		}
	}
	for(int i=0 ;i<index ; i++){
		cout<<minNumber[i];
	}	
	return 0;
} 
