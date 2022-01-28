#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll max_way(int n, int x, vector<int> &v, ll count[], int st)
{
    for(int i = 1; i <= x; i++)
    {
        for(int j = st; j < n; j++)
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


int main()
{
    int n, x;
    cin >> n >>x;

    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v.push_back(a);
    }

    sort(v.begin(), v.end());

    ll sum = 0;

    for(int i = 0; i < n; i++)
    {
        ll count[x + 1];

        count[0] = 1;

        for(int i = 1; i <= x; i++)
        {
            count[i] = 0;
        }

        sum = (sum + max_way(n, x - v[i], v, count, i))%1000000007;
    }

    cout << sum;

    return 0;
}