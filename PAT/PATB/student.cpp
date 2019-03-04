#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
class Student
{
public:
Student(){}
void write();
void red();
void show();
void sortScore();
int operator<(const Student&);
int a_bScore();
void deleteStudent();
private:
int id;
string name;
double score;
};
vector<Student> student;
void Student::write()
{
Student s;
char fileName[20];
cout<<"请输入文件名："<<endl;
cin>>fileName;
cin.clear();
ofstream out(fileName,ios::app);
cout<<"请输入学生学号姓名成绩："<<endl;
vector<Student>::iterator iter;
while (cin>>s.id>>s.name>>s.score)
{
iter=student.begin();
while (iter!=student.end())
{
if (s.id==iter->id)
{
cout<<s.id<<"已经存在。"<<endl;
cout<<iter->id<<"\t"<<iter->name<<" \t"<<iter->score<<endl;
break;
}
else
iter++;
}
if (iter==student.end())
{
out<<s.id<<" "<<s.name<<" "<<s.score<<" ";
student.push_back(s);
}
}
cin.clear();
}
void Student::show()
{
vector<Student>::const_iterator iter=student.begin();
cout<<"学号\t姓名\t 成绩\t"<<endl<<endl;
while (iter!=student.end())
{
cout<<iter->id<<"\t"<<iter->name<<" \t"<<iter->score<<endl;
iter++;
}
}
void Student::red()
{
Student s;
char fileName[20];
cout<<"请输入文件名："<<endl;
cin>>fileName;
ifstream in(fileName);
vector<Student>::iterator iter;
while (in>>s.id>>s.name>>s.score)
{
iter=student.begin();
while (iter!=student.end())
{
if (s.id==iter->id)
{
break;
}
else
iter++;
}
if (iter==student.end())
{
student.push_back(s);
}
}
cin.clear();
}
int Student::operator<(const Student&s)
{
return score>s.score?1:0;
}
void Student::sortScore()
{
sort(student.begin(),student.end());
}
int Student::a_bScore()
{
int a,b,low,up,cnt=0;
cout<<"请输入要查找的分数段:"<<endl;
cin>>a>>b;
if (a>b)
{
up=a;
low=b;
}
else
{
low=a;
up=b;
}
vector<Student>::const_iterator iter=student.begin();
while (iter!=student.end())
{
if (iter->score>=low&&iter->score<=up)
{
cout<<iter->id<<"\t"<<iter->name<<" \t"<<iter->score<<endl;
cnt++;
}
iter++;
}
cout<<"分数段"<<low<<"~"<<up<<"总人数："<<cnt<<endl;
return cnt;
}
void Student::deleteStudent()
{
Student s;
cout<<"请输入要删除的学生学号:"<<endl;
cin>>s.id;
vector<Student>::iterator iter=student.begin();
while (iter!=student.end())
{
if (iter->id==s.id)
{
break;
}
else
iter++;
if (iter!=student.end())
{
student.erase(iter);
cout<<"OK,"<<s.id<<"信息删除完毕。"<<endl;
}
else
{
cout<<"没找到学号为："<<s.id<<"的学生信息，删除失败。"<<endl;
}
}
}
int main()
{
Student s;
int choice;
cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-欢迎使用学生信息管理系统-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
begin:
cout<<"1->添加学生信息 2->显示学生信息 3->删除学生信息 "<<endl<<endl;
cout<<" 0-> 退出 "<<endl<<endl;
cout<<"4->从文件添加 5->按成绩排序 6->分数段信息查询"<<endl<<endl;
cin>>choice;
if (choice==1)
{
s.write();
system("cls");
goto begin;
}
else if (choice==2)
{
s.show();
system("pause");
system("cls");
goto begin;
}
else if (choice==3)
{
s.deleteStudent();
system("pause");
system("cls");
goto begin;
}
else if (choice==4)
{
s.red();
system("pause");
system("cls");
goto begin;
}
else if (choice==5)
{
s.sortScore();
system("pause");
system("cls");
goto begin;
}
else if (choice==6)
{
s.a_bScore();
system("pause");
system("cls");
goto begin;
}
else if (choice==0)
{
exit(0);
}
else
{
cout<<"输入非法！！！"<<endl;
system("pause");
goto begin;
}
return 0;
}
