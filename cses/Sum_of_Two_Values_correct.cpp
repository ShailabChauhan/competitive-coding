#include <bits/stdc++.h>

using namespace std;

void is_sum_available(vector < pair < int, int> > &v, int x, int n)
{
    int i = 0, j = n - 1, k = 0;

    while(i < j)
    {
        int sum = v[i].first + v[j].first;

        if(sum < x)
        {
            i++;
        }
        else if(sum > x)
        {
            j--;
        }
        else
        {
            k = 1;
            break;
        }
    } 

    if(k == 1)
    {
        if(v[i].second > v[j].second)
        {
            cout << v[j].second << " " << v[i].second << endl;
        }
        else
        {
            cout << v[i].second << " " << v[j].second << endl;
        }
        
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector< pair<int, int> > v;

    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a, i});
    }

    sort(v.begin(), v.end());

    is_sum_available(v, x, n);

    return 0;
}