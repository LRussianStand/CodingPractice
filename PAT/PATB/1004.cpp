#include<iostream>
#include<stdio.h>
#include<string.h>
#include <malloc.h>
using namespace std;
int length = 0;
struct student {
	char name[11];
	char courseName[11];
	int score;
};
void findInfo(student *students){
	int minIndex = 0 , maxIndex = 0;
	
	if(length != 0){
		for(int i=1 ; i<length ; i++){
			if(students[i].score > students[maxIndex].score){
				maxIndex = i;
			}
		}
		
		for(int i=1 ; i<length ; i++){
			if(students[i].score < students[minIndex].score){
				minIndex = i;
			}
		}
	}
	cout<<students[maxIndex].name<<" "<<students[maxIndex].courseName<<endl;
	cout<<students[minIndex].name<<" "<<students[minIndex].courseName<<endl;
	
	
}
int main(){
	freopen("1004.txt" , "r" , stdin);
	int num;
	cin>>num;
	length = num;
//	struct student students[100];
	struct student *stu;
	stu=(struct student *)malloc(num*sizeof(struct student));
	int i=0;
	while(num != 0){
		num--;
		cin>>stu[i].name>>stu[i].courseName>>stu[i].score;
		i++;
	}
	findInfo(stu);
	
	return 0;
}
