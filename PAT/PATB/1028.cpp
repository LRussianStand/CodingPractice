#include <iostream>
#include<set>
using namespace std;
struct people {
	char name[7];
	int y, m, d;
	bool operator <(const people &a)const {   //����ṹ��ıȽϷ�ʽ
		if (a.y == y) 
			if (a.m == m)
				return a.d >= d;
			else
				return a.m > m;
		else
			return a.y > y;
	}
};
int main() {
	set < people> myset;
	people temp;
	int n;
	cin >> n;
	while (n--) {
		scanf("%s %d/%d/%d", temp.name, &temp.y, &temp.m, &temp.d);
		if (temp < people{ "",2014,9,6 }&&people{ "",1814,9,6 } < temp)    //�ж��Ƿ����
			myset.insert(temp);   //�Ž�set������
	}
	cout << myset.size();
	if (myset.size())      //ע�⵱size=0ʱ���ܷ���begin
		cout << " " << myset.begin()->name << " " << myset.rbegin()->name;
	return 0;
}
