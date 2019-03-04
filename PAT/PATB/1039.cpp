#include<iostream>
#include<string.h>
using namespace std;

int main(){
	freopen("1039.txt" , "r" , stdin);
	int shop[130],customer[130];
	string shopS , customerS;
	cin>>shopS>>customerS;
	for(int i=0; i <130 ; i++){
		shop[i] = 0;
		customer[i] = 0;
	}
	for(int i=0 ; i<shopS.length() ; i++){
		shop[shopS[i]]++;
	}
	for(int i=0 ; i<customerS.length() ; i++){
		customer[customerS[i]]++;
	}
	int count=0;
	for(int i=0 ; i<130 ; i++){
		if(shop[i]!=customer[i] && customer[i] > 0 && customer[i] > shop[i]){
//			cout<<(char)i<<customer[i]<<" "<<shop[i]<<endl;
			count += customer[i] - shop[i];
		}
	}
	if(count){
		cout<<"No"<<" "<<count;
	}else{
		cout<<"Yes"<<" "<<shopS.length()-customerS.length();
	}
	
	return 0;
}
