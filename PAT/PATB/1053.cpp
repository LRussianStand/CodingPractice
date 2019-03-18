#include<iostream>
#include<vector>
using namespace std;

int main(){
	freopen("1053.txt", "r", stdin);
	int N,D , len;
	int possible=0 , yes=0;
	double e;
	scanf("%d %lf %d", &N, &e, &D);
	while(scanf("%d", &len) != EOF){
		vector<double> electricity(len);
		int count=0,flag=0;
		if(len>D) flag = 1;
		for(int i=0 ; i<len ; i++){
			scanf("%lf" , &electricity[i]);
			if(electricity[i] < e){
				count++;
			}
		}
		if(count >= (len/2)+1){
			if(flag) yes++;
			else possible++;
		}
	}
	
	printf("%.1lf%% %.1lf%%",(double)possible*100/N , (double)yes*100/N);
	return 0;
}
