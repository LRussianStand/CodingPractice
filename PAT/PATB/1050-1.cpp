#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool comp(int a, int b){
	return a > b;
}
int main(){
	freopen("1050.txt", "r", stdin);
	int N,m,n;
	cin>>N;
	for(int i=sqrt(N); i>=0 ; i--){
		if(N%i == 0){
			n=i;
			break;
		}
	}
	m = N/n;
	vector<int> number(N);
	for(int i=0 ; i<N ; i++){
		scanf("%d", &number[i]);
	}
	sort(number.begin(), number.end(), comp);
	int level = m/2+m%2 , index=0;
	for(int i=0 ; i<N ; i++){
		cout<<number[i]<<endl;
	}
	vector<vector<int> > result(m , vector<int>(n));
	for(int i=0 ; i<level ; i++){
		for(int j=i ; j<=n-1-i && index<N; j++){//һ
			result[i][j] = number[index++];
		}
		for(int j=i+1 ; j<=m-1-i && index<N ; j++){//Shu
			result[j][n-1-i] = number[index++];
		}
		for(int j=n-2-i; j>=i && index<N ; j--){
			result[m-1-i][j] = number[index++];
		}
		for(int j=m-2-i ; j>i && level<N ; j--){
			result[j][i] = number[index++];
		}
        for (int j = i + 1; j <= m - 2 - i && index <= N - 1; j++)
                result[j][n - 1 - i] = number[index++];
        for (int j = n - i - 1; j >= i && index <= N - 1; j--)
                result[m - 1 - i][j] = number[index++];
        for (int j = m - 2 - i; j >= i + 1 && index <= N - 1; j--)
                result[j][i] = number[index++];
	}

	for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            printf("%d", result[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
	return 0;
} 
