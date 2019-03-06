#include<iostream>
using namespace std;

int main(){
	freopen("1043.txt" , "r" , stdin);
	int P,A,T,e,s,t;
	P=A=T=e=s=t=0;
	char c;
	while((c=getchar())!=EOF){
		switch (c){
			case 'P':
				P++;break;
			case 'A':
				A++;break;
			case 'T':
				T++;break;
			case 'e':
				e++;break;
			case 's':
				s++;break;
			case 't':
				t++;break;
			default:
				break;
		}
	}
	while(true){
		if(P){
			cout<<'P';
			P--;
		}
		if(A){
			cout<<'A';
			A--;
		}
		if(T){
			cout<<'T';
			T--; 
		}
		if(e){
			cout<<'e';
			e--;
		}
		if(s){
			cout<<'s';
			s--;
		} 
		if(t){
			cout<<'t';
			t--;
		}
		if(P==0 && A==0 && T==0 && e==0 && s==0 && t==0){
			break;
		}
	}
	return 0; 
} 
