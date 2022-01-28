#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll max_reward(vector<int> &v, vector < ll > &v1, int n, int m)
{
    if(n <= 0)
    {
        return 0;
    }

    
}

int main()
{
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int> >v;

    v.push_back({{0,0}, 0});
    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v.push_back({{b, a}, c});
    }

    sort(v.begin(), v.end());

    vector<ll> v1(n + 1);
}