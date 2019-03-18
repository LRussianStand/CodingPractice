#include<iostream>
#include<cstring>
using namespace std;

int main(){
	freopen("1048.txt", "r", stdin);
	string A,tB;
	char ch[] = {'J', 'Q', 'K'};
	int flag,minLength;
	cin>>A>>tB;
	string B="";
	if(A.length() >= tB.length()){
		flag = 0;
		for(int i=0;i<A.length() - tB.length();i++)
            B+='0';
	}else{
		flag=1;
	}
	B+=tB;
	minLength = A.length();
	char *result = new char[B.length()];;
	int aNumber,bNumber,sum;
	for(int j=1; j<=minLength ; j++){
		aNumber = A[A.length()-j]-'0';
		bNumber = B[B.length()-j]-'0';
		if(j % 2 !=0){
			sum = aNumber+bNumber;
			if(sum - 10 >=0){
				if(sum >= 13){
					result[B.length()-j] = sum%13+'0';
				}else{
					result[B.length()-j] = ch[sum-10];
				}
			}else{
				result[B.length()-j] = sum+'0';
			}
		}else{
			sum = bNumber - aNumber;
			if(sum >= 0){
				result[B.length()-j] = sum+'0';
			}else{
				sum+=10;
				result[B.length()-j] = sum+'0';
			}
		}
	}
	if(flag){
		for(int i=0 ; i<B.length()-minLength ; i++){
			result[i] = B[i];
		}
	}
	for(int i=0 ; i<B.length() ; i++){
		cout<<result[i];
	}
	delete[] result;
	return 0;
}
