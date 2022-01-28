#include <bits/stdc++.h>
using namespace std;

char a[1001][1001];

void bfs(vector < vector < char > > v, int x1, int y1, int x2, int y2, int n, int m)
{
    queue< pair < int, int> > q;

    vector<pair <pair<int, int>, char > > p;

    p.push_back({{1,0}, 'D'});
    p.push_back({{-1,0}, 'U'});
    p.push_back({{0,1}, 'R'});
    p.push_back({{0,-1}, 'L'});

    q.push({x1, y1});
    v[x1][y1] == '#';

    while(!q.empty() && v[x2][y2] == 'B')
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            if(x +p[i].first.first < n && y +p[i].first.second < m && v[x +p[i].first.first][y +p[i].first.second] != '#')
            v[x +p[i].first.first][y +p[i].first.second] = '#';
            q.push({x +p[i].first.first, y +p[i].first.second});
            a[x + p[i].first.first][y + p[i].first.second] = p[i].second;
        }
    }
}

vector <char> f;

int dfs(int x1, int y1, int x2, int y2, int n, int m)
{
    if(a[x2][y2] == 0)
    {
        return 0;
    }

    vector<pair<int, int>> p;

    p.push_back({1,0});
    p.push_back({-1,0});
    p.push_back({0,1});
    p.push_back({0,-1});

    if(x1 == x2 && y1 == y2)
    {
        f.push_back(a[x2][y2]);
        return 1;
    }
    else if(x1 < n && y1 < m && x1 >= 0 && y1 >= 0)
    {
        int b;

        for(int i = 0; i < 4; i++)
        {
            if(x1 + p[i].first < n && y1 + p[i].second < m &&y1 + p[i].second >= 0 && x1 + p[i].first >= 0 &&a[x1 + p[i].first][y1 + p[i].second] != 0)
            {
                b = dfs(x1 + p[i].first, y1 + p[i].second, x2, y2, n, m);
                if(b == 1)
                {
                    f.push_back(a[x1 + p[i].first][y1 + p[i].second]);
                    return b;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;

    vector<vector<char> > v;

    for(int i = 0; i < n; i++)
    {
        vector<char > v1;

        for(int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            v1.push_back(ch);

            if(ch == 'A')
            {
                x1 = i;
                y1 = j;
            }

            if(ch == 'B')
            {
                x1 = i;
                y1 = j;
            }
            a[i][j] = 0;
        }

        v.push_back(v1);
    }

    bfs(v, x1, y1, x2, y2,n,m);

    int x = dfs(x1, y1, x2, y2, n, m);

    if(x == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << f.size() << endl;
        for(int i = f.size(); i >= 0 ; i--)
        {
            cout << f[i];
        }

        cout << endl;
    }

    return 0;
}