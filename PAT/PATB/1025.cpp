#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;


struct Node{
	int pre;
	int value;
	int next;
};

bool cmp(Node a, Node b){ // ½µÐò a>b ·´ÕýÉýÐò 
	return a.value < b.value;
} 

bool cmpShengxu(Node a, Node b){ // ½µÐò a>b ·´ÕýÉýÐò 
	return a.value > b.value;
} 
int main(){
	freopen("1025.txt" , "r" , stdin);
	string first;
	int num , k;
	cin>>first>>num>>k;
	Node *node = new Node[num];
	int index=0;
	while(index < num){
		scanf("%d %d %d" , &node[index].pre , &node[index].value , &node[index].next);
		index++;
	}
	
	sort(node , node+num , cmp);
	for(int i=0 ; i<index ; i++){
//		cout<<node[i].pre<<" "<<node[i].value<<" "<<node[i].next<<endl;
		if(node[i].next == -1){
			index = i+1;
			break;
		}
	}
	
	
	while(num > k ){
		sort(node , node+k , cmpShengxu);
		num = num-k;
	}
	for(int i=0 ; i<index ; i++){
		printf("%05d %d " , node[i].pre,node[i].value);
		if(i+1 < index){
			printf("%05d\n" , node[i+1].pre);
		}else{
			cout<<-1;
			break;
		}
	}
	return 0;
}
