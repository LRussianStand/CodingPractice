#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
//a>b
bool cmp1(int a , int b){
	return a>b;
}
//b>a
bool cmp2(int a , int b){
	return b>a;
}

int main(){
//	freopen("1019.txt" , "r" , stdin);
	int num,index=0 , num1 , num2;

	cin>>num;
	int number[4] = {0 , 0 , 0, 0};
	
	if(num % 1111 == 0){
		cout<<num<<" - "<<num<<" = ";
		cout<<setw(4)<<setfill('0')<<num-num;
	}else{
		while(1){
			index =0;
			//取出每个数字存到数组中 
			while(num){
				number[index++] = num%10;
				num = num/10;
			}
			//对数组中每个元素进行排序 
			num1=0,num2=0;
			sort(number , number+ 4 , cmp1);
			index = 0;
			while(index < 4){
				num1 = num1*10 + number[index];
				index++;
			} 
			
			sort(number , number+4 , cmp2);
			index = 0;
			while(index < 4){
				num2 = num2*10 + number[index];
				index++;
			} 
		
			cout<<num1<<" - ";
			cout<<setw(4)<<setfill('0')<<num2<<" = ";
			cout<<setw(4)<<setfill('0')<<num1-num2;
			num = num1-num2;
			if(num != 6174){
				cout<<endl;
			}else{
				break;
			}
		}	
	}
	return 0;
}
