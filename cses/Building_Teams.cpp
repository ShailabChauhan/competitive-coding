#include <bits/stdc++.h>
using  namespace std;

int p = 0;

void dfs(vector<vector<int> > &v, vector<int>&colour, int num, int k)
{
    for(int i = 0; i < v[num].size(); i++)
    {
        if(colour[v[num][i]] == 0)
        {
            colour[v[num][i]] = k;
            if(k == 1)
            {
                dfs(v, colour,v[num][i], 2);
            }
            else
            {
                dfs(v, colour,v[num][i], 1);
            }
        }
        else if(colour[num] == colour[v[num][i]])
        {
            p = 1;
            return ;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector< int > > v(n + 1);

    vector<int> colour(n + 1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(colour[i] == 0)
        {
            colour[i] = 1;
            dfs(v, colour, i, 2);
        }
    }

    if(p == 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            cout << colour[i] << " ";
        }
        cout << endl;
    }

    return 0;
}