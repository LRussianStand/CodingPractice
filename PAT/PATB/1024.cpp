#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	freopen("1024.txt" , "r" , stdin);
	string num;
	cin>>num;
	double result;
	int flag=1;
	if(num[0] == '-'){
		flag = -1;
	} 
	int numbIndex ;
	for(int i=1 ; i<num.length() ; i++){
		if(num[i] >= '0' && num[i] <= '9'){
			numbIndex = i;
		}
		if(num[i] =='E'){
			break;
		} 
	}
	int powFlag = 1 , powN = 0;
	
	for(int i=numbIndex+1 ; i<num.length() ; i++){
		if(num[i] == '-'){
			powFlag = -1;
		}
		if(num[i] >= '0' && num[i] <= '9'){
			powN = powN*10 + num[i] - '0';
		}
	}
	if(powFlag == -1){
		powN = -powN;
	}
	powN = powN-(numbIndex-2);
	int nums = 0;
	for(int i=1 ; i<= numbIndex ; i++){
		if(num[i] >= '0' && num[i] <= '9'){
			nums = nums*10+num[i]-'0';
		}
	}
	result = nums*pow(10 , powN);
	if(flag == -1){
		result = -result;
	}
	if(powN > 0){
		cout<<fixed<<(long long int)result;
	}else{
		cout<<fixed<<setprecision(abs(powN))<<result;	
	}
	
//	cout<<setiosflags(ios::fixed)<<setprecision(abs(powN))<<result;
	return 0;
}
