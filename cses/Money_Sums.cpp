#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    v.push_back(0);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum = sum + v[i];
    }

    //int dp[n + 1][sum + 1] = {0};
    int dp[n + 1][sum + 1];
    
    memset(dp, 0, sizeof dp);

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    set < int > s;

    sort(v.begin(), v.end());

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            dp[i][j] = (j >= v[i])? dp[i - 1][j - v[i]] + dp[i - 1][j] : dp[i - 1][j];
            if(dp[i][j] != 0)
            {
                s.insert(j);
            }
        }
    }

    cout << s.size() << endl;
    
    for(auto it : s)
    {
        cout << it << " ";
    }

    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }*/

    return 0;
}