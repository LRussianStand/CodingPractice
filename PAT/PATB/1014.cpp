#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
	freopen("1014.txt" , "r" , stdin);
	string a , b ,c ,d;
	cin>>a>>b>>c>>d;
	string week[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int we = 0 , hour = 0;
	for(int i=0 ; i<a.length() && i<b.length() ; i++){
		if(a[i] == b[i]){
			if(we == 0 && a[i] >= 'A' && a[i] <= 'G'){
				cout<<week[a[i] - 'A']<<" ";
				we = 1;	
			}else if (we == 1){
				if(a[i] >= '0' && a[i] <= '9'){
					cout<<a[i]<<":";
					break;
				}else if (a[i] >= 'A' && a[i] <= 'N'){
					cout<<(a[i] - 'A')+10<<":";
					break;
				}
			}
					
		}
	
	}
	
	for(int i=0 ; i<c.length() && i<d.length() ; i++){
		if(c[i] == d[i] && isalpha(c[i])){
			if(i < 10){
				cout<<"0"<<i;
			}else{
				cout<<i;
			}
		}
	}
	
	
}
