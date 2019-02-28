#include<iostream>
#include<algorithm> 
using namespace std;
double list[10000];

int main(){
	freopen("1020.txt" , "r" , stdin);
	int N , D ;
	double a;
	cin>>N>>D;
	double inventory[1000] , totalPrice[1000];
	for (int i = 0; i < N; i++){
		cin>>a;
		inventory[i]=a;
	}
	for (int i = 0; i < N; i++){
		cin>>a;
		totalPrice[i]=a;
	}
	int count = 0;
	for (int i = 0; i < N; i++){
		for(int j=0 ; j<inventory[i] ; j++){
			list[count++] =totalPrice[i]/ inventory[i];
		}
	}
	sort(list ,list+count , greater<double>());
	double sum=0;
	for (int i = 0; i < D; i++){
		sum += list[i];
	}
	printf("%0.2lf", sum);
	return 0;
}

