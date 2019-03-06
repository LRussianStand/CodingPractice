#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
	freopen("1044.txt" , "r" , stdin);
	string marNumber[] = {"tret","jan","feb","mar","apr","may","jun" , 
	"jly" ,"aug" , "sep" ,"oct"  ,"nov"  ,"dec"};
	string highMarNumber[] = {"tret","tam","hel","maa","huh","tou","kes",
	"hei","elo","syy","lok","mer","jou"} ;
	int N , sum=0;
	string number;
	cin>>N;
	getchar(); 
	while(N){
		N--;
		getline(cin, number);
		// 
		if (isdigit(number[0])) {        //µØÇò->»ğĞÇ
			int res = atoi(number.c_str());	
			if (res/13)
				cout << highMarNumber[res/13];
			if (res / 13 && res % 13)
				cout << " "<< marNumber[res % 13];
			if (!(res/13))
				cout << marNumber[res % 13];
			cout << endl;
		}else{
			for(int i=0 ; i<13 ; i++){
				if(number.substr(number.length()-3 , number.length()) == highMarNumber[i]){
					sum += i*13;
					break;
				}
				if(number.substr(number.length()-3 , number.length()) == marNumber[i]){
					sum += i;
					break;
				}
			}
			if(number.length() > 3){
				for(int i=0 ; i<13 ; i++){
					if(number.substr(0,3) == highMarNumber[i]){
						sum += i*13;
					}
				}
			}
			cout<<sum<<endl;
			sum=0;
		}
	}
	return 0;
}
