#include <bits/stdc++.h>

using namespace std;

void bfs(vector< vector<int> > &v, vector <int> &visit, int num1, int num, queue <int> &q, vector<int> prev)
{
    q.push(num1);
    visit[num1] = 1;

    prev[1] = -1;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        for(int i = 0; i < v[p].size(); i++)
        {
            if(visit[v[p][i]] == 0)
            {
                q.push(v[p][i]);
                visit[v[p][i]] == 1;
                prev[v[p][i]] = p;
            }
        }
    }
}

int main()
{
    int n, m, p, q;
    cin >> n >> m;

   vector< vector<int> > v;

   vector <int > prev(n + 1);

   queue <int> q;

    for(int i = 0; i < m; i++)
    {
        cin >> p >> q;

       v[p].push_back(q);
       v[q].push_back(p);
    }

   
    return 0;
}