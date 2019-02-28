#include<iostream>
#include<stdio.h> 
using namespace std;

bool contianNumber(int *callatzNum , int key){
	if (callatzNum != NULL){
		if(*callatzNum++ == key){
			return true;
		}
//		calatzNum++;
	}
	return false;
}
void addNumber(int *callatzNum , int number){
	while(number != 1){
		*callatzNum++ = number;
		if(number % 2 == 0){
			number /= 2;
		}else{
			number = number*3/2;
		}
	} 
}
int main(){
	freopen("1005.txt" , "r" , stdin);
	int *callatzNum = 0;
	int num , number;
	int *result = 0;
	cin>>num;
	while(num != 0){
		cin>>number;
		cout<<number;
		if(!contianNumber(callatzNum , number)){
			addNumber(callatzNum , number);//add the number from callatz
			*result++ = number; 
		}
		num--;
	}
	while(result != NULL){
		cout<<*result++<<" ";
	}
	cout<<endl;
	return 0;
}
