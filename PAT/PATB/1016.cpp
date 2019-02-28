#include<iostream>
#include<stack>
using namespace std;

int main(){
	freopen("1016.txt" , "r" , stdin);
	long a ,b;
	int A , B;
	int remainder;
	cin>>a>>A>>b>>B;
//	stack<int> Anum , Bnum;//
	int aSum=0 , bSum=0;
	while(a!=0){
		remainder = a%10;
		if(remainder == A){
			aSum = aSum*10+a%10;
		}
		
		a = a/10;
	}
	
	while(b!=0){
		remainder = b%10;
		if(remainder == B){
			bSum = bSum*10+b%10;
		}
		b = b/10;
	}
	cout<<aSum+bSum; 
	return 0;
} 
