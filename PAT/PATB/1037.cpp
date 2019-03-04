#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	freopen("1037.txt" , "r" , stdin);
	int Pg,Ps,Pk,Ag,As,Ak;
	scanf("%d.%d.%d %d.%d.%d" , &Pg,&Ps,&Pk,&Ag,&As,&Ak);
	bool flag = false;
	int resultG,resultS,resultK;
	if(Pg>Ag){
		int temp;
		temp = Pg; Pg = Ag ; Ag = temp;
		temp = Ps; Ps = As ; As = temp;
		temp = Pk; Pk = Ak ; Ak = temp;
		flag = true;
	} 
	if(Ak>=Pk){
		resultK = Ak - Pk; 
	} else{
		resultK = Ak+29-Pk;
		As--;
	}
	if(As >= Ps){
		resultS = As - Ps;
	}else{
		resultS = As + 17 - Ps;
		Ag--;
	}
	resultG = Ag - Pg;
	if(flag){
		cout<<'-'<<resultG<<'.'<<resultS<<'.'<<resultK;
	}else{
		cout<<resultG<<'.'<<resultS<<'.'<<resultK; 
	}
	
	return 0;
}
