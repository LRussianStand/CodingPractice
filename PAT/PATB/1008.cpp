#include<iostream>
using namespace std;

int main(){
	freopen("1008.txt" , "r" , stdin);
	int m , n;
	cin>>n>>m;
	int number[100] ;
	for(int i=0 ; i<n ; i++){
		cin>>number[i];
	}
	
	int temp[100];
	for(int i=0 ; i<n ; i++){
		if(i+m < n){
			temp[i+m] = number[i]; 
		}else{
			temp[(i+m)% n] = number[i];
		}
	}
	for(int i=0 ; i<n ; i++){
		cout<<temp[i]<<" "; 
	} 
}
