#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main(){
	freopen("1038.txt" , "r" , stdin);
	int N ,K,score;
	int studentScore[101];
	for(int i=0 ; i<=100 ; i++){
		studentScore[i] = 0;
	}
	scanf("%d" , &N);
	while(N){
		N--;
		scanf("%d" , &score);
		studentScore[score]++;
	}	
	scanf("%d" , &K);
	while(K){
		K--;
		scanf("%d" , &score);
		cout<<studentScore[score];
		if(K != 0){
			cout<<" ";
		}
	}
	return 0;
}
