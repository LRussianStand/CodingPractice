#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
//�ҵ�p �� T ��λ�� Ȼ������p ǰ����ַ��� T������ַ��� p��T֮����ַ��� 
void isPat(string inputString){
	int countP = 0 , countT = 0 , indexP =0 , indexT = 0 , flag = 1;
	 
	for(int i=0 ; i<inputString.length() ; i++){
		if(inputString[i] != 'A' && inputString[i] != 'P' && inputString[i] != 'T'){
			flag = 0;
			break;
		}
		
		if(inputString[i] == 'P'){
			countP++;
			indexP = i;
		}
		
		if(inputString[i] == 'T'){
			countT++;
			indexT = i;
		}
	}
//	cout<<countP << " "<<countT<<" "<<indexP<<" "<<indexT<<" "<<inputString.length()<<indexP * (indexT-indexP-1)
//	<<endl;
//	cout<<flag<<endl;

	if(countP == 1 && countT == 1 && indexP+1 != indexT && (indexP * (indexT-indexP-1) == (inputString.length()-1 - indexT)) && flag){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}

int main(){
	freopen("1003.txt" , "r" , stdin);
	int num;
	string inputString;
	cin>>num;
	while(num != 0){
		num--;
		cin>>inputString;
		//determines whether the string meets the requirements
		isPat(inputString);
	} 
	fclose(stdin);
	return 0;
} 

//#include <iostream>
//#include <string>
//using namespace std; 
// 
//void isPAT(string str);
//int main() {
//	
//	int n(0); // �ַ�������
//	cin >>n;
//	for(int i=0;i<n;i++){
//		string temp;
//		cin >> temp;
//		isPAT(temp); 
//	} 
//	return 0;
//}
// 
//void isPAT(string str){
//	 
//	int P_j(0),T_j(0);  //��¼P,T��λ�� 
//	int countP(0), countT(0);  //��¼P,T�ĸ��� 
//	bool status= true;  // ���в��Ϸ����ַ�����ʱ��Ϊfalse 
//	for(int i=0;i<str.length();i++){
//		//�в���P,A,T�����ַ������NO
//		if(str[i]!='P' && str[i]!='A'&& str[i]!='T'){ 
//			status = false;
//		} 
//		if(str[i]=='P'){
//			P_j=i;
//			countP++;
//		} 
//		if(str[i]=='T'){
//			T_j=i;
//			countT++;
//			break;
//		}
//		
//	}
//	
//	if((T_j-1-P_j)>=1 && P_j*(T_j-1-P_j)==(str.length()-1-T_j) && countP==1 && countT==1 && status){
//		cout << "YES" << endl;
//	}
//	else{
//		cout << "NO" << endl;
//	}
//	 
//}
