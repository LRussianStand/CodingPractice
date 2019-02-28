#include<iostream>
using namespace std;
#include<cstring> 
#include<string>
#include<cctype>
#include<cmath>
#include<vector>
#include<algorithm> 
struct student{
	long long int num;
	int d,c;
	int group;        //记录类别
}stu;
vector<student> s;
//多关键字排序，返回true 和 false
bool cmp(student s1,student s2) //s1 在s2前 
{
	if(s1.group<s2.group)	return true;
	else if(s1.group>s2.group)	return false;
	else
	{
		if(s1.d+s1.c==s2.d+s2.c)
		{
			if(s1.d==s2.d)	
				return s1.num<s2.num;
			return s1.d>s2.d;
		}
		return s1.d+s1.c>s2.d+s2.c;
	}
}
 
int main()
{
	int n,l,h;
	scanf("%d %d %d",&n,&l,&h);
	for(int i=0;i<n;++i)
	{
		scanf("%lld %d %d",&stu.num,&stu.d,&stu.c);
		if(stu.c<l||stu.d<l)	continue;            //判断类别
		else if(stu.d>=h&&stu.c>=h)	stu.group=1;
		else if(stu.d>=h)	stu.group=2;
		else if(stu.d<h&&stu.c<h&&stu.d>=stu.c)	stu.group=3;
		else	stu.group=4;
		s.push_back(stu); 
	} 
	sort(s.begin(),s.end(),cmp);
	n=s.size();
	cout<<n<<endl;
	for(int i=0;i<n;++i)
		printf("%lld %d %d\n",s[i].num,s[i].d,s[i].c);
		return 0;
 } 
