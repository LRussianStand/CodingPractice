#include<iostream>
using namespace std;

int main(){
	freopen("1027.txt" , "r" , stdin);
	int remain = 0;
	int num , eachLevelNumber[1000] , index=0 , LevelNumber=1;
	char ch;
	cin>>num>>ch;
	if(num % 2 == 0){
		num -= 1;
		remain++;
	}
	eachLevelNumber[index++] = LevelNumber;
	num -=1; 
	while(true){
		//Ã¿Ò»²ãµÄ	
		LevelNumber += 2;
		if(num >= 2 * LevelNumber){
			eachLevelNumber[index++] = LevelNumber;
			num = num - 2*LevelNumber;
		}else{
			remain += num;
			break;
		}
	}
//	for(int i=0 ; i<index ; i++){
//		cout<<eachLevelNumber[i]<<" "; 
//	}
	for(int i = index-1 ; i>=0 ; i--){
		if(eachLevelNumber[index-1] > eachLevelNumber[i]){
			for(int k = 1 ; k <= (eachLevelNumber[index-1] -eachLevelNumber[i])/2 ; k++ )
				cout<<" ";
		}
		for(int j=1 ; j<=eachLevelNumber[i] ; j++){
			cout<<ch;
		}
		cout<<endl;
	}
	for(int i = 1 ; i<index ; i++){
		if(eachLevelNumber[index-1] > eachLevelNumber[i]){
			for(int k = 1 ; k <= (eachLevelNumber[index-1] -eachLevelNumber[i])/2 ; k++ )
				cout<<" ";
		}
		for(int j=1 ; j<=eachLevelNumber[i] ; j++){
			cout<<ch;
		}
		cout<<endl;
	}
	cout<<remain;
 	return 0;
}
