#include <bits/stdc++.h>
using namespace std;

int max_page(vector<pair<int, int> > &v,int i, int x, int n, vector<pair<int, int> > &v1, int* visit)
{
    int pages = 0;
    if(v1[x].second == 1)
    {
        return v1[x].first;
    }
    else if(i < n)
    {
        if(x < v[i].first)
        {
            pages = max_page(v, i+1,x,n,v1);
            v1[x].first = max_page(v, i + 1, x, n, v1);
            v1[x].second = 1;
            return pages;
        }
        else if( (v[i].second + max_page(v, i + 1, x - v[i].first, n, v1)) > max_page(v, i + 1, x, n, v1))
        {
            //cout << v[i].first << " " <<v[i].second << endl;
            pages = v[i].second + max_page(v, i + 1, x - v[i].first, n, v1);
            v1[x].first = pages;
            v1[x].second = 1;
            return pages;
        }
        else
        {
            pages = max_page(v, i + 1, x, n, v1);
            v1[x].first = pages;
            v1[x].second = 1;
            return pages;
        }
    }
    else
    {
        v1[x].first = pages;
        v1[x].second = 1;
        return pages;
    }
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int > v2;
    vector<pair<int, int> > v, v1;
    int visit[n];

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v2.push_back(a);
        visit[i] = 0;
        
    }

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({v2[i], a});
        v1.push_back({0, 0});
    }

    v1.push_back({0, 1});

    for(int i = 1; i <= x; i++)
    {
        v1.push_back({0, 0});
    }


    cout << max_page(v, 0, x, n, v1) << endl;

    return 0;
}