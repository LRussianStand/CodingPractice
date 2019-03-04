#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("1032.txt" , "r" , stdin);
	int num;
	int score[100000];
	int id , scores;
	cin>>num;
	for(int i=0 ; i<num ; i++){
		score[i]=0;
	}
	while( cin>>id>>scores){
		score[id] +=scores;
	}
	int maxIndex=1;
	for(int i=2 ; i<num ; i++){
		if(score[maxIndex] < score[i]){
			maxIndex = i;
		}
	}
	cout<<maxIndex<<" "<<score[maxIndex];
	return 0;
}
