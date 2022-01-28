#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int n, x;
    cin >> n >> x;

    vector< pair<int, int>>v(n);
    vector<int> v1(n),v2(n);
    vector< set<int> > s(x + 1);

    for(int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> v2[i];
        v[i] = {v1[i],v2[i]};
    }

    ll dp[x + 1];

    sort(v.begin(), v.end());

    for(int i = 0; i <= x; i++)
    {
        ll a1 = 0, k1 = -1;
        for(int j = 0; j < n; j++)
        {
            if(i >= v[j].first)
            {
                int k = s[i - v[j].first].size();
                s[i - v[j].first].insert(j);

                if(k < s[i - v[j].first].size())
                {   
                    ll a2 = v[j].second + dp[i - v[j].first];
                    if(a1 < a2)
                    {
                        s[i] = s[i - v[j].first];
                        a1 = a2;
                        k = j;
                    }
                    s[i - v[j].first].erase(j);
                }

                k1 = j;
                
            }
        }

        if(a1 == 0 && k1 != -1)
        {
            dp[i] = dp[i - v[k1].first];
            s[i] = s[i - v[k1].first];
        }
        else
        {
             dp[i] = a1;;
        }
    }

    cout << dp[x] << endl;

    return 0;
}