#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int k = 0;

    for(int i = 0; i < n; i++)
    {
        int b = x - v[i];
        if(b == v[i])
        {
            v[i]++;
            k = 2;
        }

        auto it = find(v.begin(), v.end(), b);

        if(it != v.end())
        {
            cout << i+1 << " " << it - v.begin() + 1 << endl;
            k = 1;
            break;
        }

        if(k == 2)
        {
            v[i]--;
            k = 0;
        }
        
    }

    if(k == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}