#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long int a, b;

        cin >> b >> a;

        if(a >= b && a%2 == 0)
        {
            cout << (a - 1)*(a - 1) + b << endl;
        }
        else if(a >= b && a%2 == 1)
        {
            cout << (a)*(a) - b + 1 << endl;
        }
        else if( b > a && b%2 == 0)
        {
            cout << (b)*(b) - a + 1 << endl;
        }
        else
        {
            cout << (b - 1)*(b - 1) + a << endl;
        }
    }
    
    return 0;
}