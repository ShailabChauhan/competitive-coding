#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <pair<int , int> > v;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v.push_back({a, i});
    }

    sort(v.begin(), v.end());

    int count =1;

    for(int i = 1; i < n; i++)
    {
        if(v[i].second < v[i - 1].second)
        {
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}