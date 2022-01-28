#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int a, b;

        cin >> a >> b;

        if(a < b)
        {
            swap(a,b);
        }

        if(a%2 == 1 && (a+1)/2 <= b && (a+b)%3 == 0)
        {
            cout << "YES" << endl;
        }
        else if(a%2 == 0 && a/2 <= b && (a + b)%3 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}