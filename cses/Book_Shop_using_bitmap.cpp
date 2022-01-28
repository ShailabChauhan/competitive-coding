#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void decimal_to_binary(vector <int> &v, int num, int n)
{
    while(num)
    {
        v.push_back(num%2);
        num = num/2;
    }

    while(v.size() < n)
    {
        v.push_back(0);
    }

    vector<int> v1;

    for(int i = n - 1; i >= 0; i--)
    {
        v1.push_back(v[i]);
    }

    v = v1;
}

int main()
{
    int n, x;
    cin >> n >> x;

    int num = pow(2,n);

    vector<int> v1(n), v2(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }

    ll dp[n][n];

    ll l = 0;

    for(int i = 0; i < num; i++)
    {
        vector<int> v;
        ll l1 = 0, c1 = 0;

        decimal_to_binary(v, i, n);

        for(int j = 0; j < n; j++)
        {
            c1 = c1 + v1[j]*v[j];
            l1 = l1 + v2[j]*v[j];

            if(c1 > x)
            {
                break;
            }
        }

        if(l1 > l && c1 <= x)
        {
            l = l1;
        }
    }

    cout << l << endl;

    return 0;
}