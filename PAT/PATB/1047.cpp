#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("1047.txt", "r", stdin);
	int score[10000];
	fill(score, score+10000, 0);
	int num, a, b, c;
	scanf("%d", &num);
	while(num){
		num--;
		scanf("%d-%d %d", &a, &b, &c);
		score[a] += c;
	}
	int maxIndex=0;
	for(int i=1 ; i<10000 ; i++){
		if(score[i] != 0){
			if(score[i] > score[maxIndex]){
				maxIndex = i;
			}
		} 
	}
	printf("%d %d", maxIndex, score[maxIndex]);
	return 0;
}
