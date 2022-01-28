#include <bits/stdc++.h>
using namespace std;

void func(vector<pair<int, pair<int,int>>> v, vector <pair<int,int>> c, int n)
{
    int j = 1;
    c.push_back(make_pair(v[0].second.first, j));
    v[0].second.second = 1;

    for(int i = 1; i < n; i++)
    {
       sort(c.begin(), c.end());

        int k =0;
        while(k < j)
        {
            if(c[k].first < v[i].first)
            {   
                c[k].first = v[i].second.first;
                v[i].second.second = c[k].second;
                break;
            }

            k++;
        }

        if(k == j)
        {
            j++;
            c.push_back(make_pair(v[i].second.first, j));
            v[i].second.second = j;
        }
    } 

    cout << j << endl;

    for(int i = 0; i < n; i++)
    {
        cout << v[i].second.second << " ";
    }
}

int main()
{
    int n, a, b;
    cin >> n;

    vector<pair<int , pair<int, int> > > v;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, make_pair(b, 0)));
    }

    //sort(v.begin(), v.end());

    vector<pair<int, int>> c;

    func(v, c, n);

    return 0;
}