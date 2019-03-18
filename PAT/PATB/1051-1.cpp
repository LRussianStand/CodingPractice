#include<iostream>
#include<cmath>
using namespace std;
#define max 1001
#define min 0.01
int main(){
	freopen("1051.txt", "r", stdin);
	double A = 0, B = 0;
	double R1, P1, R2, P2;
	double a, ai, b, bi;
	cin >> R1 >> P1 >> R2 >> P2;
	a = R1 * cos(P1);
	ai = R1 * sin(P1);
	b = R2 * cos(P2);
	bi = R2 * sin(P2);
	A = a * b - ai * bi;
	B = a * bi + ai * b;
	if (abs(A) < min)
		A = 0;
	if (abs(B) < min)
		B = 0;
	printf("%0.2lf", A);
	if (B >= 0) {
		printf("+%0.2lfi", B);
	}
	else
		printf("%0.2lfi", B);
	return 0;
}
