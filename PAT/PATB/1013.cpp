#include<iostream>
#include<cmath>
using namespace std;
int prime[10000];

bool isPrime(int number){
	if(number == 2 || number == 3){
		return true;
	}
	for(int i=2 ; i<=sqrt(number) ; i++){
		if(number % i ==0){
			return false;
		}
	}
	return true;
} 

int main(){
//	freopen("1013.txt" , "r" , stdin);
	int M , N;
	cin>>M>>N;
	int index = 0;
	prime[index++] = 2;
	prime[index++] = 3;
	long i=5;
	while(index < 10000){ 
		if(isPrime(i)){
			prime[index++] = i;
		}
		i+=2;
	}
	int count = 0;
	for(i=M-1 ; i<N ; i++){
		cout<<prime[i];
		count++;
		if(count % 10 ==0){
			cout<<endl;
		}
		if(i != N-1 && count % 10 != 0){
			cout<<" ";
		}
	}
	return 0;	
}
