#include<stdio.h>
#include<iostream>
using namespace std;
const int N = 54;
char mp[5] = { 'S', 'H', 'C', 'D', 'J'};
int start[N+1], end[N+1], next[N+1];
int main()
{
	freopen("1042.txt" , "r" ,stdin);
    int K;
    scanf("%d", &K);
    for(int i = 1; i <= N; i++)
    {
        start[i] = i;//��ʼ���Ƶı��
    }
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &next[i]);//�������Ƶ�λ��
    }
    for(int step = 0; step < K; step++)
    {
        for(int i = 1; i <=N; i++)
        {
            end[next[i]] = start[i];//iλ�õ��ƴ���next[i]
        }
        for(int i = 1; i <= N; i++)
        {
            start[i] = end[i];//�ǳ����õ�һ��
        }
    }
    for(int i = 1; i<= N; i++)
    {
        if(i != 1) printf(" ");//���Ƹ�ʽ
        start[i]--;
        printf("%c%d",mp[start[i] / 13] , start[i] % 13 + 1);
    }
    return 0;
}
