#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll max_score(vector<int> &v, vector<vector<ll>> &dp, int i, int j)
{
    if(i == j)
    {
        return v[i];
    }
    else if( i > j)
    {
        return 0;
    }

    if(dp[i][j] != 0)
    {
        return dp[i][j];
    }

    ll s = 0, s1 = 0, s2 = 0, s3 = 0;

    s = v[i] + max_score(v, dp, i + 1, j - 1);
    s1 = v[i]+ max_score(v, dp, i + 2, j);
    s2 = v[j] + max_score(v, dp, i + 1, j - 1);
    s3 = v[j] + max_score(v, dp, i, j - 2);

    if(s > s1)
    {
        swap(s, s1);
    }

    if(s2 > s3)
    {
        swap(s2, s3);
    }

    if(s < s2)
    {
        swap(s, s2);
    }

    dp[i][j] = s;

    return s;
}

int main()
{
    int n;
    cin >> n;
    ll sum = 0;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum = sum + v[i];
    }

    //ll dp[n + 1][n + 1];

    vector<vector<ll>> dp;

    for(int i = 0; i <= n; i++)
    {
        vector<ll> v2(n + 1);
        dp.push_back(v2);
    }

    cout << max_score(v, dp, 0, n - 1) << endl;

    return 0;
}