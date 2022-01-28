#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll b[21];

ll min_difference(vector <ll> &v, int n, ll small, ll sum, int i, ll l)
{
    if(i >= n)
    {
        b[i] = small;
        return small;
    }

    if(b[i] != -1)
    {
        return b[i];
    }

    ll k = sum - 2*l;
    if(k >= 0 && k <= small)
    {
        small = k;
        cout << small << endl;
    }

    ll s = small;
    if( min_difference(v, n, small, sum, i + 1, l)  < s)
    {
        s =  min_difference(v, n, small, sum, i + 1, l);
    }
    if(min_difference(v, n, small, sum, i + 1, l + v[i]) < s)
    {
       s =  min_difference(v, n, small, sum, i + 1, l + v[i]);
    }
        b[i] = s;
        small = s;
    return small;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < 21; i++)
    {
        b[i] = -1;
    }

    ll sum = 0;

    vector<ll> v;
    
    for(int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;

        v.push_back(a);
        sum = sum + a;
    }

    cout << min_difference(v, n, sum,sum, 0, 0) << endl;
    
    return 0;
}