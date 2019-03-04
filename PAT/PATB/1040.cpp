#include<iostream>
#include<string.h>
using namespace std;

int main(){
	freopen("1040.txt" , "r" , stdin);
	string PAT;
	cin>>PAT;
	cout<<findNumPat(PAT);
	return 0; 
} 
