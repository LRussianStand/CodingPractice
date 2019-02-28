#include<iostream>
#include<stdio.h> 
using namespace std;
int callatzNum[100000];
int length = 0;
int lengthRes = 0;

bool contianNumber(int key){
	for(int i=0 ; i<length ; i++){
		if(callatzNum[i] == key){
			return true;
		}
	}
	return false;
}

void addResult(int nums[100] , int lengthNum){
	int result[100];
	int index = 0;
	for(int i=0 ; i<lengthNum ; i++){
		if(!(contianNumber(nums[i])) ){
			
			result[index++] = nums[i];
		}	
	}
	for(int i=0 ; i<index ; i++){
		int max = i;
		for(int j=i+1 ; j<index ; j++){
			if(result[j] > result[max]){
				max = j;
			}
		}
		if(i+1 == index){
			cout<<result[max];
		}else{
			cout<<result[max]<<" ";	
		} 
		int a = result[max];
		result[max] = result[i];
		result[i] = a; 
	
			
	}
}

void addNumber(int nums[100] , int lengthNum){
	for(int i=0 ; i<lengthNum ; i++){
		int number = nums[i];
		while(number){
			if(number == 1){
				callatzNum[length++] = number;
				break;
			}
			if(number % 2 == 0){
				number /= 2;
				callatzNum[length++] = number;
			}else{
				number = (number*3+1)/2;
				callatzNum[length++] = number;
			}	
		}
	}
	addResult(nums , lengthNum);
} 

int main(){
	freopen("1005.txt" , "r" , stdin);
	int num , number;
	int nums[100];
	int index = 0;
	cin>>num;
	while(num != 0){
		cin>>number;
		nums[index++] = number;
		num--;
	}
	addNumber(nums , index);
	return 0;
}
