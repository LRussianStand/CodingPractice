#include<iostream>

using namespace std;

int main(){
//	freopen("1010.txt", "r" , stdin);
	int numbers[1000] , index = 0 , number;
	for(;index < 1000 ; index++){
		cin>>number;
		if(index > 0){
			if(number == 0 && numbers[index-1] == 0){
				break;
			}else{
				numbers[index] = number;
			} 
		}else{
			numbers[index] = number;
		}
	
		
	}
	if(numbers[0] == 0){
		cout<<0;
	}else{
		for(int i=0 ; i<index ; i+=2){
			if(numbers[i+1]-1 >= 0){
				if(numbers[i+1] - 1 != 0){
					cout<<numbers[i]*numbers[i+1]<<" "<<numbers[i+1]-1<<" ";
				}else{
					cout<<numbers[i]*numbers[i+1]<<" "<<numbers[i+1]-1;
				}
				
			}else{
				break;
			}
		}
	}
	
	
	return 0;
}

			
