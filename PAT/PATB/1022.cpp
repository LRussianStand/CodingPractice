#include<iostream>
using namespace std;

int main(){
//	freopen("1022.txt" , "r" , stdin);
	int  A , B , result , index=0;
	char res[33]; 
	int D;
	cin>>A>>B>>D;
	result = A + B;
	if(result != 0){
		while(result != 0){
			res[index++] = (result % D) + '0';
			result = result / D;
		} 
		for(int i=index-1 ; i>=0 ; i--){
			cout<<res[i];
		}
	}else{
		cout<<0;
	} 

	return 0;
}
