#include<iostream>
#include<iomanip>
using namespace std;

int main(){
 	freopen("1012.txt" , "r" , stdin);
	int result[5] = {0} , dig[5] = {0};
 	int number[1000];
	int num,sum, index=0 , countNumber = 0 ;
	cin>>sum;
	double threeNum = 0;
	while(sum){
		cin>>num;
		sum--;
		switch(num%5){
			case 0:
				if(num % 2 == 0){
					result[0] += num;
					dig[0]  = 1;
				}
				break;
			case 1:
				countNumber++;
				if(countNumber % 2 ==0){
					result[1] -= num;
				}else{
					result[1] += num;
				}
				dig[1]  = 1;
				break;
			case 2:
				result[2]++;
				dig[2]  = 1;
				break;
			case 3:
				result[3] += num;
				threeNum++;
				dig[3]  = 1;
				break;
			case 4:
				if(num > result[4]){
					result[4] = num;
				}
				dig[4]  = 1;
				break;
			}
	}

	for(int i=0 ; i<5 ; i++){
		if(!dig[i]){
			cout<<"N";
		}else{
			if(i == 3){
				cout<<setiosflags(ios::fixed)<<setprecision(1)<<result[i]/threeNum;
			}else{
				cout<<result[i];	
			}
		}
		if(i != 4){
			cout<<" ";
		} 
	}
	return 0;
}

