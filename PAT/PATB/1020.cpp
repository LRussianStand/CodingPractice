#include<iostream>
#include<iomanip> 
using namespace std;

int main(){
	freopen("1020.txt" , "r" , stdin);
	int N , D;
	cin>>N>>D;
	double price[1000],inventory[1000] , totalPrice[1000];
	double a , n=N;
	int index=0;
	while(n){
		cin>>a;
		inventory[index++]=a;
		n--;
	}
	index = 0;
	while(N){
		cin>>a;
		totalPrice[index++]=a;
		N--;
	}
	for(int i=0 ; i<index ; i++){
		price[i]=totalPrice[i]/inventory[i];
	}
	double sum = 0;
	for(int i= 0 ; i<index ; i++){
		int maxPriceInd = i;
		for(int j=i+1 ; j<index ; j++){
			if(price[maxPriceInd] < price[j]){
				maxPriceInd = j;
			}
		}
		if(inventory[maxPriceInd] <= D){
			sum = sum + totalPrice[maxPriceInd];
			D=D-inventory[maxPriceInd];
		}else{
			sum += price[maxPriceInd]*D;
			D = 0;
		}
		if(D<=0){
			break;
		}
		double temp = price[maxPriceInd];
		price[maxPriceInd] = price[i];
		price[i] = temp;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum;
//	cout<<sum;
	
}
