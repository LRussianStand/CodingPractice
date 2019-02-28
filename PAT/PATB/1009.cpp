#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	freopen("1009.txt" , "r" , stdin);
	string inputString , temp;
	string target[80];
	int index = 0 , first = 0 , end = 0;
	getline(cin , inputString);
	for(int i=0 ; i<inputString.length() ; i++){
		if(inputString[i] == ' '){
			end = i-1;
			temp = inputString.substr(first , end-first+1); 
//			cout<<temp;
			first = end+2;
			target[index++] = temp;
		}
		if(i == inputString.length()-1){
			target[index++] = inputString.substr(first , i+1);
		}
	}
	for(int i=index-1 ; i>= 0 ; i--){
		if(i!= 0){
			cout<<target[i]<<" ";	
		}else{
			cout<<target[i];
		}
	}
	
	return 0;
} 
