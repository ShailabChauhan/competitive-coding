#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;

    vector <string> v;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        v.push_back(s);
    }

    ll dp[n][n];

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = n-1; j >= 0; j--)
        {   
            if(v[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else if(i == n - 1 && j == n - 1)
            {
                dp[i][j] = 1;
            }
            else 
            {
                ll a1 = (j == n - 1)? 0: dp[i][j + 1];
                ll a2 = (i == n - 1)? 0: dp[i+ 1][j];
                dp[i][j] = (a1 + a2)%1000000007;
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}