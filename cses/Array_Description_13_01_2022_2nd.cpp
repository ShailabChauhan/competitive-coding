#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector< int > v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector< vector<int> > dp;

    for(int i = 0;i <= n; i++)
    {
        vector<int>v1(m + 1);
        dp.push_back(v1);
    }

    if(v[0] == 0)
    {
        for(int i = 1; i <= m; i++)
        {
            dp[1][i] = 1;
        }
    }
    else if(v[0] != 0)
    {
        dp[1][v[0]] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(v[i  - 1] != 0 && v[i - 1] != j)
            {
                dp[i][j] == 0;
            }
            else
            {
                if(j == m)
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%1000000007;
                }
                else
                {
                    //dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j+1])%1000000007;
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%1000000007;
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1])%1000000007;
                } 
            }
        }
    }
    int sum = 0;
    if(v[n - 1] == 0)
    {
        for(int i = 1; i <= m; i++)
        {
            sum = (sum + dp[n][i])%1000000007;
        }
    }
    else
    {
        sum = dp[n][v[n - 1]];
    }

    cout << sum << endl;
    
    return 0;
}