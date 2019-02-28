// 1012.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<iomanip>
#include<typeinfo>

using namespace std;

int main()
{	
	freopen("1012.txt" , "r" , stdin);
    int N, A[5] = { 0 }, j = 1, num = 0, max = 0, dig[5] = { 0 };

    cin >> N;

    int *p = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> p[i];

        switch (p[i] % 5)
        {
        case 0:
            if ((p[i] & 1) == 0)
            {
                A[0] += p[i];
                dig[0] = 1;
            }
            break;
        case 1:
            A[1] += p[i] * j;
            j = -j;
            dig[1] = 1;
            break;
        case 2:
            A[2]++;
            dig[2] = 1;
            break;
        case 3:
            A[3] += p[i];
            num++;
            dig[3] = 1;
            break;
        case 4:
            if (p[i] > max)
                max = p[i];
            dig[4] = 1;
            break;
        default:break;
        }
    }

						    A[4] = max;


    for (int i = 0; i < 5; i++)
    {
        if (dig[i])
        {
            if (i != 3)
                cout << A[i];
            else
                cout << fixed << setprecision(1) << static_cast<double>(A[3]) / num;
        }
        else
            cout << "N";

        if (i != 4)
            cout << " ";
    }

    delete[] p;

    return 0;
}
