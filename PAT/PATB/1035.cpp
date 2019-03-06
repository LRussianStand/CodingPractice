#include<iostream>
#include<algorithm>
using namespace std;
int n;
void insort(int a[], int b[]) {
	int key = 0;          //当匹配到中间序列时，key置1，下次排序后输出，结束程序就行
	for (int i = 2; i <= n; i++) {		//插入排序起始为2，结束为n，否则测试点2不通过
		sort(a, a + i);
		if (key) {
			cout << "Insertion Sort" << endl;
			cout << a[0];
			for (int j = 1; j < n; j++)
				cout << " " << a[j];
			return;
		}
		if (equal(a, a + n, b))  //equal是一个比较数组的函数
			key = 1;
	}
}
void mesort(int a[], int b[]) {
	int key = 0;
	for (int i = 2;; i *= 2) {   //这里不给结束条件，是因为当i>n时还要进行一次排序
		for (int j = 0; j < n; j += i) {
			sort(a + j, a + (j + i < n ? j + i : n));  //注意确定边界
		}
		if (key) {
			cout << "Merge Sort" << endl;
			cout << a[0];
			for (int j = 1; j < n; j++)
				cout << " " << a[j];
			return;
		}
		if (equal(a, a + n, b))
			key = 1;
		if (i > n)
			break;
 
	}
}
int main() {
	cin >> n;
	int a1[100], a2[100], b[100];
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
		a2[i] = a1[i];
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];
	insort(a2, b);
	mesort(a1, b);
	return 0;
}
