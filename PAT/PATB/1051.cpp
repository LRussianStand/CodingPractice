#include<iostream>
#include<cmath> 
#include<iomanip>
#define MIN 0.01
using namespace std;

int main(){
	freopen("1051.txt", "r", stdin);
	double r1,p1,r2,p2,resR,resP;
	double a,ai,b,bi;
	cin>>r1>>p1>>r2>>p2;
	a = r1*cos(p1);
	ai = r1*sin(p1);
	b = r2*cos(p2);
	bi = r2*sin(p2);
	resR = a*b - ai*bi;
	resP = a*bi + ai*b;
	if(abs(resR) < MIN){
		resR = 0;
	}
	if(abs(resP) < MIN){
		resP = 0;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<resR<<resP<<'i';
	return 0; 
}
