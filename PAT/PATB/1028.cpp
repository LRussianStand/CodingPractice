#include <iostream>
#include<set>
using namespace std;
struct people {
	char name[7];
	int y, m, d;
	bool operator <(const people &a)const {   //定义结构体的比较方式
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
		if (temp < people{ "",2014,9,6 }&&people{ "",1814,9,6 } < temp)    //判断是否合理
			myset.insert(temp);   //放进set容器中
	}
	cout << myset.size();
	if (myset.size())      //注意当size=0时不能访问begin
		cout << " " << myset.begin()->name << " " << myset.rbegin()->name;
	return 0;
}
