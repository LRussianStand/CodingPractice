#include<iostream>
#include<algorithm> 
#include<cstring>
using namespace std;

struct Student{
	string id;
	int virtueScore;
	int score; 
	 bool operator < (const Student &s) const {//符号重载
        if((virtueScore+score) == (s.score+s.virtueScore)){
        	if(score != s.score){
        		return score<s.score;
			}else{
				return s.id.compare(id);
			}
        }else{
            return (virtueScore+score) > (s.score+s.virtueScore);
        }
    }

};

int main(){
 	freopen("1015.txt" , "r" , stdin);
	int num , min , best;
	struct Student student;
	cin>>num>>min>>best;
	struct Student oneStudent[10000];
	struct Student twoStudent[1000];
	struct Student threeStudent[1000];
	struct Student fourStudent[1000];
	
	int one = 0 , two = 0 , three = 0 , four = 0;
	while(num){
		cin>>student.id>>student.virtueScore>>student.score;
		stu->id = student.id;
		stu->virtueScore = student.virtueScore;
		stu->score = student.score;
		stu++; 
		if(student.score >= min && student.virtueScore >= min){
			if(student.score >= best && student.virtueScore >= best){ // 德才兼备 1类 
				oneStudent[one++] = student;
			}else if(student.virtueScore >= best){ //德分80+ 才分低于80二类 
				twoStudent[two++] = student;
			}else if(student.virtueScore >= student.score){ //德大于才   三类 
				threeStudent[three++] = student;
			}else{ //按总分排 但过线 四类 
				fourStudent[four++] = student;
			} 
		}
		num--;
	}

	sort(oneStudent , oneStudent+one);
	sort(twoStudent , twoStudent+two);
	sort(threeStudent , threeStudent+three);
	sort(fourStudent ,fourStudent+four);
	cout<<one+two+three+four<<endl;
	for(int i=0 ; i<one ; i++){
		cout<<oneStudent[i].id<<" "<<oneStudent[i].virtueScore<<" "<<oneStudent[i].score<<endl; 
	}
	for(int i=0 ; i<two ; i++){
		cout<<twoStudent[i].id<<" "<<twoStudent[i].virtueScore<<" "<<twoStudent[i].score<<endl; 
	}
	for(int i=0 ; i<three ; i++){
		cout<<threeStudent[i].id<<" "<<threeStudent[i].virtueScore<<" "<<threeStudent[i].score<<endl; 
	}
	for(int i=0 ; i<four ; i++){
		cout<<fourStudent[i].id<<" "<<fourStudent[i].virtueScore<<" "<<fourStudent[i].score; 
		if(i+1 != four){
		  cout<<endl;
		}
	
	}
	return 0;
}
