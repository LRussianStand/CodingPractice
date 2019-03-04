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
cout<<"�������ļ�����"<<endl;
cin>>fileName;
cin.clear();
ofstream out(fileName,ios::app);
cout<<"������ѧ��ѧ�������ɼ���"<<endl;
vector<Student>::iterator iter;
while (cin>>s.id>>s.name>>s.score)
{
iter=student.begin();
while (iter!=student.end())
{
if (s.id==iter->id)
{
cout<<s.id<<"�Ѿ����ڡ�"<<endl;
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
cout<<"ѧ��\t����\t �ɼ�\t"<<endl<<endl;
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
cout<<"�������ļ�����"<<endl;
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
cout<<"������Ҫ���ҵķ�����:"<<endl;
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
cout<<"������"<<low<<"~"<<up<<"��������"<<cnt<<endl;
return cnt;
}
void Student::deleteStudent()
{
Student s;
cout<<"������Ҫɾ����ѧ��ѧ��:"<<endl;
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
cout<<"OK,"<<s.id<<"��Ϣɾ����ϡ�"<<endl;
}
else
{
cout<<"û�ҵ�ѧ��Ϊ��"<<s.id<<"��ѧ����Ϣ��ɾ��ʧ�ܡ�"<<endl;
}
}
}
int main()
{
Student s;
int choice;
cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-��ӭʹ��ѧ����Ϣ����ϵͳ-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
begin:
cout<<"1->����ѧ����Ϣ 2->��ʾѧ����Ϣ 3->ɾ��ѧ����Ϣ "<<endl<<endl;
cout<<" 0-> �˳� "<<endl<<endl;
cout<<"4->���ļ����� 5->���ɼ����� 6->��������Ϣ��ѯ"<<endl<<endl;
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
cout<<"����Ƿ�������"<<endl;
system("pause");
goto begin;
}
return 0;
}