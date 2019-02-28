#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
bool comp(char m, char n)
{
    if (m > n)
        return true;
    else
        return false;
}
int main()
{
    string a, b, c;
    cin >> c;
    c.insert(0, 4 - c.length(), '0');
    while (true)
    {
        a = c;
        b = c;
        sort(a.begin(), a.end(), comp);
        sort(b.begin(), b.end());
        int x = stoi(a);
        int y = stoi(b);
        int z = x - y;
        c = to_string(z);
        c.insert(0, 4 - c.length(), '0');
        cout << a << " - " << b << " = " << c << endl;
        if (z == 0 || z == 6174)
            break;
    }
    system("pause");
    return 0;
}
