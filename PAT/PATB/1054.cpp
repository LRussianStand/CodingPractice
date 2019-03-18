#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

bool pdnum(string examp){
	
}
int main(){
	freopen("1054.txt" , "r" , stdin);
	double sum=0;
	string number;
	int N , count=0, flag , dianNum=0;
	stringstream ss;
	cin>>N;
	while(N){
		N--;
		cin>>number;
		flag = 1,dianNum=0;
		//判断是否是一个数字字符串 
		if(pdnum(number)){
			
		}
		
		if(flag){
			double numbers;
			ss<<number;
    		ss >> numbers;
    		if(numbers<=1000 && numbers>=-1000 ){
    			sum += numbers;count++;
			}else{
				cout<<"ERROR: "<<number<<" is not a legal number"<<endl;
			}
		}else{
			cout<<"ERROR: "<<number<<" is not a legal number"<<endl;
		}
	}
	if(count == 0){
		cout<<"The average of 0 numbers is Undefined";
	}else{
		cout<<"The average of "<<count<<" numbers is "<<sum/count;
	}
	return 0;
}
