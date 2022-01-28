#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll counting(int start, int end, vector<ll> v, int x, ll* count)
{ 
    for(int i = 1; i <= x; i++)
    {
        for(int j = start; j < end; j++)
        {
            if(i - v[j] >= 0)
            {
                count[i] = count[i] + count[i - v[j]];
                count[i] = count[i]%1000000007;
            }
        }
    }

    return count[x];
}

/*int max_way(int n, int x, int*a, int* count)
{
    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i - a[j] >= 0)
            {
                count[i] = count[i] + count[i - a[j]];
                count[i] = count[i]%1000000007;
            }
        }
    }
 
    return count[x];
}*/

int main()
{
    int n, x, a;
    cin >> n >> x;
    ll count[x + 1];
    count[0] = 1;

    for(int i = 0; i < x + 1; i++)
    {
        count[i] = 0; 
    }

    vector <ll> v;

    for(int i = 0; i < n;i++)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    ll sum = 0;

    for(int i = 0; i < n; i++)
    {
        ll b = counting(i, n, v, x - v[i], count);
        
        sum = sum + b;
        //cout << sum << " ";
        sum = sum%1000000007;
        
        //cout << counting(i, n, v, x - v[i], count) << " ";

        count[0] = 1;

        for(int j = 1; j < x + 1; j++)
        {
            count[j] = 0; 
        }
    }

    cout << sum << endl;

    return 0;
}