#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("1048.txt", "r", stdin);
    string A,tB;
    cin>>A>>tB;
    int len1=A.size();
    int len2=tB.size();
    int max=len1>len2?len1:len2;
    char C[max];
    string B="";
    if(len1>len2){  //如果A比B长，长多少则补几个0
        for(int i=0;i<len1-len2;i++)
            B+='0';
    }
    B+=tB;//补在左边
    for(int i=B.size()-1,j=A.size()-1;i>=0&&j>=0;i--,j--){
        if((B.size()-i)%2==0){                  //从右边起如果是偶数位
            if(B[i]-A[j]<0){//B的数字减去A的数字也就是字符相减
                    C[i]=(B[i]-A[j])+10+'0';//判断完是否小于0之后转换成字符
            }else{
                C[i]=B[i]-A[j]+'0';//大于0则直接转换成字符
            }
        }else{  //如果是奇数位
            if((B[i]-'0'+A[j]-'0')%13==10)//先将对应位转换成数字再对13取余
            C[i]='J';   
            else if((B[i]-'0'+A[j]-'0')%13==11)
            C[i]='Q';   
            else if((B[i]-'0'+A[j]-'0')%13==12)
            C[i]='K';
            else {
                C[i]=(B[i]-'0'+A[j]-'0')%13+'0';
            }
        }   
    }
    for(int i=0;i<len2-len1;i++)//若A>B,将不变的元素赋值过来
        C[i]=B[i];
    for(int i=0;i<max;i++){
        cout<<C[i];
    }   
    return 0;
}

