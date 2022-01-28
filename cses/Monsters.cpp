#include <bits/stdc++.h>
using namespace std;

void bfs(vector< vector<char>> &v,vector<vector<int> > &v1, queue<pair<int,int>> &q, int x, int y, int n, int m)
{
    q.push({x, y});
    int i = 1;
    v1[x][y] = 1;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if(p.first - 1 >= 0 &&  v[p.first - 1][p.second] == '.')
        {
            v[p.first - 1][p.second] = '#';
            v1[p.first - 1][p.second] = v[x][y] + 1;
            q.push({p.first - 1, p.second});
        }
 
        if(p.first + 1 < n &&  v[p.first + 1][p.second] == '.')
        {
            v[p.first + 1][p.second] = '#';
            v1[p.first + 1][p.second] = v[x][y] + 1;
            q.push({p.first + 1, p.second});
        }
 
        if(p.second - 1 >= 0 &&  v[p.first][p.second - 1] == '.')
        {
            v[p.first][p.second - 1] = '#';
            v1[p.first][p.second - 1] = v[x][y] + 1;
            q.push({p.first, p.second - 1});
        }
 
        if(p.second + 1 < m &&  v[p.first][p.second + 1] == '.')
        {
            v[p.first][p.second + 1] = '#';
            v1[p.first][p.second + 1] = v[x][y] + 1;
            q.push({p.first, p.second + 1});
        }
    }
}

void bfs1(queue<pair<int, int> > &q, vector<vector<char> > &s1, vector<vector<char> > &s,  int ax, int ay, int n, int m)
{
    q.push({ax, ay});
    s[ax][ay] = '#';
 
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        if(p.first - 1 >= 0 &&  s[p.first - 1][p.second] == '.')
        {
            s[p.first - 1][p.second] = '#';
            s1[p.first - 1][p.second] = 'U';
            q.push({p.first - 1, p.second});
        }
 
        if(p.first + 1 < n &&  s[p.first + 1][p.second] == '.')
        {
            s[p.first + 1][p.second] = '#';
            s1[p.first + 1][p.second] = 'D';
            q.push({p.first + 1, p.second});
        }
 
        if(p.second - 1 >= 0 &&  s[p.first][p.second - 1] == '.')
        {
            s[p.first][p.second - 1] = '#';
            s1[p.first][p.second - 1] = 'L';
            q.push({p.first, p.second - 1});
        }
 
        if(p.second + 1 < m &&  s[p.first][p.second + 1] == '.')
        {
            s[p.first][p.second + 1] = '#';
            s1[p.first][p.second + 1] = 'R';
            q.push({p.first, p.second + 1});
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector< vector<char>> v;
    vector<vector<int> > v1;

    vector<pair<int,int> > M;
    int x, y;
    vector<pair<int,int> > side;
    
    queue<pair<int,int>>q;

    for(int i = 0; i < n; i++)
    {
        vector<char> v2;
        vector<int> v3(m);
        for(int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            if(a == 'M')
            {
                M.push_back({i,j});
            }
            else if(a == 'A')
            {
                x = i;
                y = j;
            }
            else if(a == '.' && (i == n - 1 || i == 0 || j == m - 1 || j == 0))
            {
                side.push_back({i,j});
            }

            v2.push_back(a);
        }

        v.push_back(v2);
        v1.push_back(v3);
    }

    vector<int> count(side.size());

    for(int i = 0; i < count.size(); i++)
    {
        count[i] == 2000000;
    }

    vector<vector<int>> u1;
    vector<vector<char>> u;

    for(int i = 0; i < M.size(); i++)
    {
        u = v;
        u1 = v1;

        bfs(u, u1, q,  M[i].first, M[i].second, n, m);

        for(int j = 0; j < side.size(); j++)
        {
            if(u1[side[j].first][side[j].second] != 0 && u1[side[j].first][side[j].second] < count[j])
            {
                count[j] = u1[side[j].first][side[j].second];
            }
        }
    }

    u = v;
    u1 = v1;

    bfs(u, u1, q,  x, y, n, m);

    int x1 = -1, y1 = -1, size = 0;

    for(int j = 0; j < side.size(); j++)
    {
        if(u1[side[j].first][side[j].second] != 0 && u1[side[j].first][side[j].second] < count[j])
        {
            size = u1[side[j].first][side[j].second];
            x1 = side[j].first;
            y1 = side[j].second;

        }
    }

    if(x1 == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        u = v;

        bfs1(q, u, v, x, y,n, m);

        vector<char> path;
        while(x1 != x || y1 != y)
        {
            path.push_back(u[x1][y1]);
            if(u[x1][y1] == 'L')
            {
                y1++;
            }
            else if(u[x1][y1] == 'R')
            {
                y1--;
            }
            else if(u[x1][y1] == 'U')
            {
                x1++;
            }
            else if(u[x1][y1] == 'D')
            {
                x1--;
            }
        }
 
        cout <<"YES" << endl <<  v.size() << endl;
 
        for(int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i];
        }
 
        cout << endl;
    }

    return 0;
}