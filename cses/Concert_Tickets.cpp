#include <bits/stdc++.h>
using namespace std;

void consert_ticket(multiset<int,greater<int> > &v, vector<int> &v1, int m)
{
    for(int i = 0; i < m; i++)
    {
        auto it = v.lower_bound(v1[i]);

        if(it != v.end() && *it <= v1[i])
        {
            cout << *it << endl;
            v.erase(it);
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}

int main()
{
    int n, m, a;
    cin >> n >> m;

    vector <int> v1;
    multiset< int, greater<int> > v;

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        //v.push_back(a);
        v.insert(a);
    }

    for(int i = 0; i < m; i++)
    {
        cin >> a;
       v1.push_back(a);
    }

    //sort(v.begin(), v.end());

    /*for(int i = 0; i < m; i++)
    {
        k = -1;
        k = binary_search(v, 0, v.size()-1, v1[i]);
        
        if(k != -1)
        {
            cout << v[k] << endl;
            v.erase(v.begin() + k);
        }
        else
        {
            cout << k << endl;
        }
    }*/

    consert_ticket(v, v1, m);

    return 0;
}