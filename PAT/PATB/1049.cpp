#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	freopen("1049.txt", "r", stdin);
	int num, index=0;
	double number[100000],temp;
	cin>>num;
	while(num){
		num--;
		cin>>temp;
		number[index++] = temp;
	}
	double sum=0;
	double left , right;
	for(int i=0 ; i<index ; i++){
		right = index - i;//自身可以
		left = i*(index-i); 
//		sum += number[i]*(left+right);
		sum += right*number[i]*left;	
//		sum += (i+1)*number[i]*(index-i);
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum; 
	return 0;
}
