#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int digit(ll num, int n)
{
    vector<int>v;

    while(num)
    {
        v.push_back(num%10);
        num = num/10;
    }

    int m = v.size();
    return v[m - n];
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        ll num;
        cin >> num;

        ll n = 1;
        ll d1 = 0;
        ll d2 = 9;

        if(num <= 9)
        {
            cout << num << endl;
        }
        else
        {
            while(num >= (d2 - d1)*n)
            {
                num = num - (d2 - d1)*n;
                d2 = d2*10 + 9;
                d1 = d1*10 + 9;
                n++;
            }

            d1 = d1 + num/n;
            num = num%n;
            
            if(num == 0)
            {
                cout << d1%10 << endl;
            }
            else
            {
                cout << digit(d1 + 1, num) << endl;
            }
            
        }
    }

    return 0;
}