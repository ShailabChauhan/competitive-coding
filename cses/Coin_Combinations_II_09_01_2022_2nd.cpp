#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector <int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp;

    for(int i = 0; i <= n; i++)
   {
       vector<int>v2(x + 1);
       dp.push_back(v2);
   }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= x; j++)
        {
            if(j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int a1 = (v[i] > j)? 0: dp[i][j - v[i]];
                int a2 = (i == 0)? 0: dp[i - 1][j];

                dp[i][j] = (a1 + a2)%1000000007;
            }
        }
    }

    cout << dp[n - 1][x];

    return 0;
}