#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector < pair<int, int> > v;
    stack< pair<int, int> >s;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v.push_back({a, i});
    }

    sort(v.rbegin(), v.rend());

    int i = 0, count = 1;
    int k = v[0].second; 

    while(i < n)
    {
        while(v[i - 1].first == v[i].first)
        {
            s.push(v[i]);
            count++;
            i++;
        }

        if(v[i].second > k)
        {
            i++;
        }
        else if(s.empty() != 1)
        {
            pair<int, int> p;
            p = s.top();
            //s.pop();

            if(p.second > v[i].second)
            {
                k = p.second;
                i++;
                s.pop();
            }
            else
            {
                k = v[i].second;
                count++;
                i++;
            } 
        }
        else
        {
                k = v[i].second;
                count++;
                i++;
        }
    }

    cout << count << endl;

    return 0;
}