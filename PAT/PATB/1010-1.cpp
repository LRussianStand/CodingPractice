#include<iostream>
using namespace std;

int main(){
	freopen("1010.txt" , "r" , stdin);
	
	int coef , index ,count=0;
	while(cin>>coef>>index){
		if(index){
			if(count++){
				cout<<" ";
			}
			cout<<coef*index <<" "<<index-1;	
		}
	}
	
	if(count==0){
		cout<<0<<" "<<0<<count;
	}
	return 0;
}
