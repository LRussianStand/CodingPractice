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
        while (str[T] != 'T' && str[T])++T;//找到尚未利用的T；
        if (!(str[T] == 'T'))
            break;
        for(;A < T && str[T];++A)
        {

            while (A < T && str[A] != 'A')++A;//掠过不是A的字符
            if (!(str[A] == 'A'))
                break;
            for (;P < A;++P)
            {
                if (str[P] == 'P')
                    ++CP; // 当前字母是P，可以组成PAT，P的数量加1
            }
            CA = CP % Mod;//此处为当前所指的A左边有多少个P，即有CP总组成方式
            CT += CA;//当前T有所有A的组成方法之和总组成方式
        }
        CT %= Mod;
        C = (CT + C) % Mod;//当前T加上之前的组成方法即为总的组成方式
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
