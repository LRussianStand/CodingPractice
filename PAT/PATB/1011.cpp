#include<iostream>
using namespace std;

int  main(){
	freopen("1011.txt" , "r" , stdin);
	int num;
	cin>>num;
	int count=1;
	long a , b , c;
	while(1){
		cin>>a>>b>>c;
		if( a+b > c){
			cout<<"Case #"<<count<<": true";
		}else{
			cout<<"Case #"<<count<<": false";
		}
		count++; 
		if(count && count !=num+1){
			cout<<endl;
		}else{
			break;
		}
	}
	return 0;
}
