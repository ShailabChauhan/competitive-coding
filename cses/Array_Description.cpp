#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v;

    for(int  i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    vector< vector<int> > dp;

    for(int i = 0; i <= n; i++)
    {   
        vector <int> v1;
        for(int j = 0; j <= m; j++)
        {
            if(i == 0)
            {
                v1.push_back(1);
            }
            else
            {
                v1.push_back(0);
            }
        }

        dp.push_back(v1);
    }

    for(int i = 0; i <= n; i++)
    {   
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = (i == 0) ? 1 : dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] = (j < m)? dp[i][j] + dp[i - 1][j + 1] : dp[i][j];
        }
    }
}