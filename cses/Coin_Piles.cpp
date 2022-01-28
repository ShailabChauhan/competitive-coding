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
        long long int num = 3;

        while(num < a && num < b)
        {
            num = num*3;
        }

        if(num != 3 )
        {
            a = a - num/3;
            b = b - num/3;
        }

        

        while(a != 0 && b != 0)
        {
            if(a >= b && b >= 3)
            {
                a = a - 3;
                b = b - 3;
            }
            else if(a > b)
            {
                a = a - 2;
                b = b - 1;
            }
            else
            {
                a = a - 1;
                b = b - 2;
            }
        }

        if(a == 0 && b == 0)
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