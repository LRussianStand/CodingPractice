#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("1042.txt" , "r" , stdin);
	int times[128];
	fill(times , times+128 , 0);
	char c;
	while((c=getchar()) != EOF){
		if((c>='a' && c<='z') || (c>='A'&&c<='Z'))
			times[tolower(c)]++;
	}
	int maxIndex = 0;
	for(int i=1 ; i<128 ; i++){
		if(times[i] > times[maxIndex]){
			maxIndex = i;
		}
	}
	cout<<(char)maxIndex<<" "<<times[maxIndex]<<endl;
	return 0;
}
