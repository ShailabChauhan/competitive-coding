#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<tuple <int, int, int> > v;

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
       
        v.push_back(make_tuple(a,b,c));
    }

    vector<ll> dis(n + 1);

    for(int i = 0; i <= n; i++)
    {
        dis[i] = 5000000000000000000;
    }

    dis[1] = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ll a = get<0>(v[j]), b = get<1>(v[j]), c = get<2>(v[j]);

            //tie(a, b, c) = v[i];

           dis[b] = min(dis[b], dis[a] + c);
           //cout << a << " " << b << " " << c << endl;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }

    /*int a = min(2,5)

    cout <<a<< endl;*/

    return 0;
}