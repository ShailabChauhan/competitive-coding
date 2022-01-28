#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k, b;
    cin >> n >> m >>k;

    vector<int > a, v;

    for(int i = 0; i < n; i++)
    {
        cin >> b;
        v.push_back(b);
    }

    for(int i = 0; i < m; i++)
    {
        cin >> b;
        a.push_back(b);
    }

    sort(a.begin(), a.end());
    sort(v.begin(), v.end());

    int i = 0, j = 0, count = 0;

    while(i < n && j < m)
    {
        if(v[i] - k <= a[j] && v[i] + k >= a[j])
        {
            count++;
            i++;
            j++;
        }
        else if(a[j] < v[i] - k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    cout << count << endl;

    return 0;
}