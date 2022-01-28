#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;

    int m = (n*(n+1))/2;
    ll mod = 1000000007;

    if(m%2 == 1)
    {
        cout << '0' << endl;
    }
    else
    {
        m = m/2;
        int dp[n+1][m + 1];

        memset(dp, 0, sizeof dp);

        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = (j >= i)? (dp[i - 1][j - i] + dp[i - 1][j])%mod : (dp[i - 1][j])%mod;
            }
        } 

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                cout << dp[i][j] << " ";
            }

            cout << endl;
        } 

        cout << dp[n][m]/2 << endl;
    }

return 0;
}