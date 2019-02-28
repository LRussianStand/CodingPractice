#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
 	freopen("1018.txt" , "r" , stdin);
	int num , victory=0 , flat=0 , lose=0;
	char results[3] = {'B' , 'C' , 'J'};
	int jiaRes[3] ={0} , yiRes[3] = {0};
	cin>>num;
	char jia,yi;
	while(num){
		cin>>jia>>yi;
		if(jia=='C'){
			if(yi == 'C')flat++;
			if(yi == 'J'){
				jiaRes[1]++;
				victory++;
			}
			if(yi == 'B'){
				yiRes[0]++;
				lose++;
			}
		}else if(jia=='J'){
			if(yi == 'C'){
				yiRes[1]++;
				lose++;
			}
			if(yi == 'J')flat++;
			if(yi == 'B'){
				jiaRes[2]++;
				victory++;
			}
		}else{
			if(yi == 'C'){
				jiaRes[0]++;
				victory++;
			}
			if(yi == 'J'){
				yiRes[2]++;
				lose++;
			}
			if(yi == 'B')flat++;	
		}
		num--;
	}
	cout<<victory<<" "<<flat<<" "<<lose<<endl<<lose<<" "<<flat<<" "<<victory<<endl;
	//输出每个人赢得最多的操作 
	int Jmax = 0 , yiMax = 0;
	for(int i=1 ; i<3 ; i++){
		if(jiaRes[i] > jiaRes[Jmax]){
			Jmax = i;
		}
		if(yiRes[i] > yiRes[yiMax]){
			Jmax = i;
		}
	} 
	cout<<results[Jmax]<<" "<<results[yiMax];
	return 0;
}
