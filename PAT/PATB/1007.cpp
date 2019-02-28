#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int number){
	if(number == 1){
		return false;
	}
	for(int i=2 ; i<=sqrt(number) ; i++){
		if(number % i == 0){
			return false;
		}
	}
	return true;
}

int countPrimePair(int prime[9592] , int index){
	if(index == 1){
		return 0;
	}
	int count = 0;
	for(int i=0 ; i<index ; i++){
		if(i+1 == 1){
			if(prime[i+1] - prime[i] == 1){
				count++;
			}
		}
		if(prime[i+1] - prime[i] == 2){
			count++;
		}
	}
	return count;
}
int main(){
	freopen("1007.txt" , "r" , stdin);
	int number , index = 0;
	int prime[9592];
	cin>>number;
	while(number > 100000){
		cin>>number;
	}
	for(int i=1 ; i<= number ; i+=2){
		if(isPrime(i)){
			prime[index++] = i;
		}
	}
	cout<<countPrimePair(prime , index);
	return 0;
} 
