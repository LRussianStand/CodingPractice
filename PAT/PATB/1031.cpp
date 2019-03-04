#include<iostream>
#include<string.h>
using namespace std;

int main(){
#ifdef OLINE_JUDGE
#else
	freopen("1031.txt" , "r" , stdin);
#endif

	int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char checkCode[] = {'1','0','X','9','8','7','6','5','4','3','2'};
	int num , count=0;
	cin>>num;
	string identityCard;
	while(num){
		cin>>identityCard;
		num--;
		int check=0;
		bool flag = false;
		for(int i=0 ; i<identityCard.length()-1 ; i++){
			if(identityCard[i] >='0' && identityCard[i] <= '9'){
				check = weight[i] * (identityCard[i]-'0') + check;
			}else{
				flag = true;
				break;
			}
		}
		if(flag || checkCode[check%11] != identityCard[17]){
			cout<<identityCard<<endl;
			count++;
		}
		
	}
	if(count==0){
		cout<<"All passed";
	}
	return 0;
}
