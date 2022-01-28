#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector< vector <ll> > a;

ll max_way(vector <int> &v, int n, int x)
{
    if(x == 0)
    {
        return 1;
    }
    else if(x < 0)
    {
        return 0;
    }

    if(a[n][x] == -1)
    {
        if(n = 0)
        {
            a[n][x] == max_way(v, n, x - v[n]);
        }
        else if(n > 0)
        {
            a[n][x] == max_way(v, n, x - v[n]) + max_way(v, n - 1, x);
        }
    }

    return a[n][x];
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;

        v.push_back(b);
    }

    for(int i = 0; i <= n; i++)
    {
        vector<ll> b1;
        for(int j = 0; j <= x; j++)
        {
            b1.push_back(-1);
        }
        a.push_back(b1);
    }

    cout << max_way(v, n - 1, x) << endl;

    return 0;
}