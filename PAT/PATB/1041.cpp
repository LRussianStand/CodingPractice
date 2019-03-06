#include<iostream>
using namespace std;

struct student{
	string id;
	int test;
	int exam;
} students[1000];

int main(){
	freopen("1041.txt", "r" , stdin);
	int num , findNum, index=0;
	cin>>num;
	while(num){
		cin>>students[index].id>>students[index].test>>students[index].exam;
		num--;index++; 
	} 
	cin>>findNum;
	for(int i=0 ; i <findNum ; i++){
		cin>>num;
		for(int j = 0 ; j<index ; j++){
			if(num == students[j].test){
				cout<<students[j].id<<" "<<students[j].exam;
				if(i+1 != findNum) 
					cout<<endl;
			}
		}
	}
	return 0;
} 
