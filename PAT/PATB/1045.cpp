#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("1045.txt" , "r" , stdin);
	int num,index=0;
	int number[100000],mainNum[10000];
	cin>>num;
	while(cin>>num){
		number[index++] = num;
	}
	int temp,flag , mainIndex=0;
	for(int i=0 ; i<index ; i++){
		temp = number[i];
		flag = 1;
		for(int j=i+1 ; j<index ; j++){
			if(number[j] < temp){
				flag = 0;break;//�ұ�Ԫ���б���С��  
			}
		}
		for(int j=0 ; j<i ; j++){
			if(number[j] > temp){
				flag = 0; break;//���Ԫ���б����� 
			} 
		} 
		if(flag){
			mainNum[mainIndex++] = number[i];
		} 
	}
	sort(mainNum , mainNum+mainIndex);
	cout<<mainIndex<<endl;
	for(int i=0 ; i<mainIndex ; i++){
		cout<<mainNum[i];
		if(i+1 != mainIndex){
			cout<<" ";
		}
	}
	return 0;
}
