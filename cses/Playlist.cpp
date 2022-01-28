#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a, i});
    }

    sort(v.begin(), v.end());

    int l_index = 0, r_index = 0, count = 1, max_count = 1;

    for(int i = 1; i < n; i++)
    {
        if(v[i].first == v[i - 1].first && l_index == 0 && r_index == 0)
        {
            if(v[i].second -v[i - 1].second >= max_count)
            {
                max_count = v[i].second -v[i - 1].second;
                l_index = v[i - 1].second;
                r_index = v[i].second;
            }
            count = 1;
        }
        else if(v[i].first == v[i - 1].first)
        {
            if(v[i-1].second > l_index && v[i].second < r_index)
            {
                max_count = v[i].second -v[i - 1].second;
                l_index = v[i - 1].second;
                r_index = v[i].second;
            } 

            count = 1;
        }
        else if(v[i].second > l_index)
        {
            count++;
        }
    }

    if(count > max_count)
    {
        cout << max_count << endl;
    }
    else
    {
        cout << count << endl;
    }

    return 0;
}