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

int main(){
	freopen("1007.txt" , "r" , stdin);
	int number , x=2, y=3 , count=0;
	cin>>number;
	while(number > 100000){
		cin>>number;
	}
	for(int i=3 ; i<= number ; i+=2){
		if(isPrime(i)){
			x = y;
			y = i;
			if(y - x ==2){
				count++;
			}
		}
	}
	cout<<count;
	return 0;
} 
