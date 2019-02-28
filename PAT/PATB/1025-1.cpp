#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
struct Node {
	int ads, data, next;
}node[100000];
int main() {
	freopen("1025.txt" , "r" , stdin);
	int n, k, str, start;
	map<int, Node> m;
	cin >> start >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &str);         //输入结点数据
		scanf("%d %d", &m[str].data, &m[str].next);
	}
	for (int i = 0; i < n; i++) {
		node[i] = { start,m[start].data ,0 };    //通过map直接索引start将链表按顺序转到node数组里面
		start = m[start].next;
		if (start == -1)     //当start被赋值为-1的时候，链表就结束了，更新n的值，测试点6
			n = i + 1;
		if ((i + 1) % k == 0)
			reverse(node + i + 1 - k, node + i + 1);   //反转
	}
	for (int i = 0; i < n; i++) {   //输出
		printf("%05d %d ", node[i].ads, node[i].data);
		if (i != n - 1)
			printf("%05d\n", node[i + 1].ads);
		else
			printf("-1");  //最后一个结点next为-1
	}
	return 0;
}
