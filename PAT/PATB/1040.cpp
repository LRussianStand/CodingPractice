#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
#ifdef _DEBUG
    freopen("data.txt", "r+", stdin);
    //fstream cin("data.txt");
#endif // _DEBUG

    const int MaxN = 100010;
    char str[MaxN];
    int P = 0, A = 0, T = 0;
    unsigned long long C = 0, Mod = 1000000007, CP = 0,CA = 0, CT = 0;;
    scanf("%s", str);
    for (; str[T]; ++T)
    {
        while (str[T] != 'T' && str[T])++T;//�ҵ���δ���õ�T��
        if (!(str[T] == 'T'))
            break;
        for(;A < T && str[T];++A)
        {

            while (A < T && str[A] != 'A')++A;//�ӹ�����A���ַ�
            if (!(str[A] == 'A'))
                break;
            for (;P < A;++P)
            {
                if (str[P] == 'P')
                    ++CP; // ��ǰ��ĸ��P���������PAT��P��������1
            }
            CA = CP % Mod;//�˴�Ϊ��ǰ��ָ��A����ж��ٸ�P������CP����ɷ�ʽ
            CT += CA;//��ǰT������A����ɷ���֮������ɷ�ʽ
        }
        CT %= Mod;
        C = (CT + C) % Mod;//��ǰT����֮ǰ����ɷ�����Ϊ�ܵ���ɷ�ʽ
    }

    printf("%lld", C);


#ifdef _DEBUG
    //cin.close();
#ifndef _CODEBLOCKS
    system("pause");
#endif // !_CODEBLOCKS
#endif // _DEBUG

    return 0;
}
