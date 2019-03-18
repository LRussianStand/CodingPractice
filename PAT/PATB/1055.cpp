#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct people{
	string name;
	int high;
};

bool comp(people a , people b){
	if(a.high != b.high){
		return a.high > b.high;
	}else{
		return a.name.compare(b.name);
	}
}

int main(){
	freopen("1055.txt" , "r" , stdin);
	int N ,K;
	cin>>N>>K;
	vector<people> allPeople(N);
	for(int i=0 ; i<N ; i++){
		cin>>allPeople[i].name>>allPeople[i].high;
	}
	sort(allPeople.begin() , allPeople.end() , comp);
	int index = 0;
	for(int i=K-1 ; i>=0 ; i--){
		int len=0;
		if(i == K-1){
			len = N - i*(N/K);
		}else{
			len = N/K;
		}
		
		vector<string> result(len);
		int flag = 0;
		
		for(int j=0 ; j<len && index<N ; j++){
			if(j==0){
				result[len/2] = allPeople[index++].name;
				flag = 1;//ÂÖµ½×ó²à 
			}else{
				if(flag){
					if(len/2-j >= 0) 
						result[len/2-j] = allPeople[index++].name;
					if(len/2+j < len) 
						result[len/2+j] = allPeople[index++].name;
					flag = 0;//ÂÖµ½ÏÈÓÒºó×ó²à 
				}else{
					if(len/2+j < len) 
						result[len/2+j] = allPeople[index++].name;
					if(len/2-j >= 0) 
						result[len/2-j] = allPeople[index++].name;
					flag = 1;//ÂÖµ½×ó²à 
				}
			}
		}
		for(int k =0 ; k<len ; k++){
			cout<<result[k];
			if(k+1 != len) cout<<" ";
		} 
		if(i!=0){
			cout<<endl;	
		}
	}
	return 0;
}
