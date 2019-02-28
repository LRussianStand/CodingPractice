#include<iostream>
using namespace std;
#include<cstring> 
#include<string>
#include<cctype>
#include<cmath>
#include<vector>
#include<algorithm> 
#include<stdio.h>


struct Student{
	long long int  id;
	int virtueScore;
	int score; 
	bool operator < (const Student &s) const {//符号重载
        if((virtueScore+score) == (s.score+s.virtueScore)){
        	if(score != s.score){
        		return score<s.score;
			}else{
				return id < s.id;
			}
        }else{
            return (virtueScore+score) > (s.score+s.virtueScore);
        }
    }
};
bool cmp(Student s1 , Student s2){ //s1 > s2
	int sum1 = s1.virtueScore + s1.score;
	int sum2 = s2.virtueScore + s2.score;
	if(sum1 == sum2){
		if(s1.virtueScore == s2.virtueScore){
			if(s1.score == s2.score){
				return s1.id < s2.id;
			}else{
				return s1.score > s2.score;
			}
		}else{
			return s1.virtueScore>s2.virtueScore; 
		}
		
	}else{
		return sum1 > sum2;
	}
}
int main(){
 	freopen("1015.txt" , "r" , stdin);
	int num , min , best;
	cin>>num>>min>>best;
	vector<Student> oneStudent , twoStudent , threeStudent , fourStudent;
	
	Student student;
	int index = 0;
	while(num){
		// cin>>student.id>>student.virtueScore>>student.score;
		scanf("%ld %d %d", &student.id,&student.virtueScore,&student.score);
		if(student.score >= min && student.virtueScore >= min){
			if(student.score >= best && student.virtueScore >= best){ // 德才兼备 1类 
				oneStudent.push_back(student);
			}else if(student.virtueScore >= best){ //德分80+ 才分低于80二类 
				twoStudent.push_back(student);
			}else if(student.virtueScore >= student.score){ //德大于才   三类 
				threeStudent.push_back(student);
			}else{ //按总分排 但过线 四类 
				fourStudent.push_back(student);
			} 
		}
		num--;
	}

	sort(oneStudent.begin() , oneStudent.end(),cmp );
	sort(twoStudent.begin() , twoStudent.end(),cmp );
	sort(threeStudent.begin() , threeStudent.end(),cmp );
	sort(fourStudent.begin() , fourStudent.end(),cmp );
	
//	sort(oneStudent.begin() , oneStudent.end() );
//	sort(twoStudent.begin() , twoStudent.end() );
//	sort(threeStudent.begin() , threeStudent.end() );
//	sort(fourStudent.begin() , fourStudent.end() );

	cout<<oneStudent.size() + twoStudent.size() + threeStudent.size() + fourStudent.size()<<endl;
	vector<Student>::iterator itr; 
	for(itr=oneStudent.begin() ; itr!=oneStudent.end() ; itr++){
		cout<<itr->id<<" "<<itr->virtueScore<<" "<<itr->score<<endl; 
	}
	for(itr=twoStudent.begin() ; itr!=twoStudent.end() ; itr++){
		cout<<itr->id<<" "<<itr->virtueScore<<" "<<itr->score<<endl; 
	}
	for(itr=threeStudent.begin() ; itr!=threeStudent.end() ; itr++){
		cout<<itr->id<<" "<<itr->virtueScore<<" "<<itr->score<<endl; 
	}
	for(itr=fourStudent.begin() ; itr!=fourStudent.end() ; itr++){
		cout<<itr->id<<" "<<itr->virtueScore<<" "<<itr->score;
		if(itr+1 != fourStudent.end()){
		  cout<<endl;
		} 
	}
	return 0;
}
