#include<iostream>
using namespace std;

int main(){
	freopen("1046.txt" , "r" , stdin);
	int jiaRes=0, yiRes=0, num, a, b, c, d , current;
	cin>>num;
	while(num){
		cin>>a>>b>>c>>d;
		current = a+c;//正确的结果 
		num--;
		if(b == current){
			if(d == current) 
				continue;
			else
				yiRes++;
		}else{
			if(d == current){
				jiaRes++;
			}
		}
	}
	cout<<jiaRes<<" "<<yiRes; 
	return 0;
}
