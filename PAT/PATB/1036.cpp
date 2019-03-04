#include<iostream>
using namespace std;

int main(){
	freopen("1036.txt" , "r" , stdin);
	int num;
	char ch;
	cin>>num>>ch;
	int col = (num+1)/2;
	for(int i=1 ; i<=col ; i++){
		if(i==1 || i==col){
			for(int j=0 ; j<num ; j++){
				cout<<ch;
			}
			if(i!=num)
				cout<<endl; 	
		}else{
			for(int j=0 ; j<num ; j++){
				if(j==0 || j==num-1) cout<<ch;
				else cout<<" ";	
			}
			cout<<endl;
		}
		
	}
	return 0;
}
