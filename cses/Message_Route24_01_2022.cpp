#include <bits/stdc++.h>

using namespace std;

void bfs(queue<int> &q, vector < vector < int > > &v, vector<int> &prev)
{
    prev[1] = -1;
    prev[0] = -1;

    q.push(1);

    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        for(int i = 0; i < v[p].size(); i++)
        {
            if(prev[v[p][i]] == 0)
            {
                q.push(v[p][i]);
                prev[v[p][i]] = p;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector < vector<int> > v(n + 1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> prev(n + 1);

    queue <int> q;

    bfs(q, v, prev);

    vector<int> v1;

    if(prev[n] == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        v1.push_back(n);
        while(prev[n] != -1)
        {
            v1.push_back(prev[n]);
            n = prev[n];
        }

        cout << v1.size() << endl;

        for(int i = v1.size() - 1; i >= 0; i--)
        {
            cout << v1[i] << " ";
        }
    }

    return 0;
}