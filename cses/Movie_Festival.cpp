#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    m = n;
    vector< pair < int, int > > v;

    while(m--)
    {
        int a, b;
        cin >> a >> b;

        v.push_back({b,a});
    }

    sort(v.begin(), v.end());

    int current  = v[0].first;
    int count = 1;

    for(int i = 1; i < n; i++)
    {
        if(v[i].second >= current)
        {
            current = v[i].first;
            count++;
        }
    }

    cout << count << endl;

    return 0;

}