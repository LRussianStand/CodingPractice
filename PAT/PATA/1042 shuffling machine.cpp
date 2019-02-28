#include<iostream>
using namespace std;

int main(){
	freopen("1042.txt" , "r" , stdin);
	int times;
	cin>>times;
	int randomNum[55],start[55] , end[55];
	for(int i=1 ; i<55 ; i++){
		cin>>randomNum[i];
	}
	for(int i=1 ; i<55 ; i++){
		start[i] = i;
	}
	while(times){
		//调整位置 由i位置 调到randomNum位置 
		for(int i=1 ; i<55 ; i++){
			end[randomNum[i]] = start[i];
		}
	
		for(int i=1 ; i<55 ; i++){
			start[i] = end[i];
		}
		times--;
	}
	for(int i=1 ; i<55 ; i++){
		if(i != 1) printf(" ");
		if(end[i] <= 13){
			cout<<'S'<<end[i];
		}else if(end[i] <= 26){
			cout<<'H'<<end[i]-13;
		}else if(end[i] <= 39){
			cout<<'C'<<end[i]-26;
		}else if(end[i] <= 52){
			cout<<'D'<<end[i]-39;
		}else{
			cout<<'J'<<end[i]-52;
		}
	}
	return 0;
}
