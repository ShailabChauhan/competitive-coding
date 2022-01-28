#include <bits/stdc++.h>

using namespace std;

void dfs(vector< vector<int> > &v, vector <int> &visit, int num)
{
    visit[num] = 1;

    for(int i = 0; i < v[num].size(); i++)
    {
        if(visit[v[num][i]] == 0)
        {
            dfs(v, visit, v[num][i]);
        }
    }
}

int main()
{
    int n, m, p, q;
    cin >> n >> m;

   vector<vector <int> > v(n + 1);

    for(int i = 0; i < m; i++)
    {
        cin >> p >> q;

       v[p].push_back(q);
       v[q].push_back(p);
    }

    int count = 0;

    vector<int> visit(n+1);

    dfs(v, visit, 1);

    vector<pair<int, int> > v1;
    int p1 = 1;

    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == 0)
        {
            v1.push_back({p1, i});
            p1 = 1;
            dfs(v, visit, i);
        }
    }

    cout << v1.size() << endl;

    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i].first << " " << v1[i].second << endl;
    }

    return 0;

}