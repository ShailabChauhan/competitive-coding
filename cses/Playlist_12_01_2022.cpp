#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<int, int> m;

    set <int> s;

    int max = 0,  global_max = 0, small_index = 0;

    for(int i = 0; i < n; i++)
    {
        int k = s.size();
        s.insert(v[i]);
        max++;

        if(s.size() == k)
        {
            if(small_index <= m[v[i]])
            {
                max = i - m[v[i]];
                small_index = m[v[i]];
            }
            m[v[i]] = i;
        }
        else
        {
            m[v[i]] = i;
        }

        if(max > global_max)
        {
            global_max = max;
        }

    }

    cout << global_max << endl;

    return 0;
}