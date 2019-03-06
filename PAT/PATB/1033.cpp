#include<iostream>
#include<algorithm>
//#include<stdio.h>
using namespace std;

int main(){
	freopen("1033.txt" , "r" , stdin);
	int flag[128]; 
	fill(flag , flag+128 , 0);
	char c;
	while((c=getchar())!='\n'){
		flag[toupper(c)]=1;
	}
	while((c=getchar())!= '\n'){
		//是不是在坏掉的字符组中 是不是有‘+' 且是c是字母 
		if(!flag[toupper(c)] && !(isupper(c) && flag['+'])){
			putchar(c);
		}
	}
	return 0;
}
