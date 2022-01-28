#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int n, x;
    cin >> n >> x;

    vector< pair<int, int> >v(n + 1);
    vector<int> v1(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i+1] = {v1[i],a};
    }

   vector< vector<int> >dp;

   for(int i = 0; i <= n; i++)
   {
       vector<int>v2(x + 1);
       dp.push_back(v2);
   }

   for(int i = 0; i <= n; i++)
   {
       for(int j = 0; j <= x; j++)
       {
           if(j == 0 || i == 0)
           {
               dp[i][j] = 0;
           }
           else
           {
               int a1 = (j >= v[i].first)? v[i].second + dp[i - 1][j - v[i].first] : 0;
               int a2 = (i == 1)? 0: dp[i - 1][j]; 
               dp[i][j] = max(a1,a2);
           }
       }
   }

   cout << dp[n][x];

   
    return 0;
}
