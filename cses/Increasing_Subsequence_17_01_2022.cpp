#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a,1});
    }

    int i = 0, j = 1, k = 0;


    while(j < n)
    {
        while(i < j)
        {
            if(v[i].first < v[j].first && v[i].second > k)
            {
                k = v[i].second;
            }
            i++;
        }

        v[j].second += k;
        k = 0;
        j++;
        i = 0; 
    }

    for(int i = 0; i < n; i++)
    {
        if(v[i].second > k)
        {
            k = v[i].second;
        }
    }

    cout << k << endl;

    return 0;
}