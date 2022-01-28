#include <bits/stdc++.h>
using namespace std;

void bfs(queue<pair<int, int> > &q, vector<vector<char> > &s1, vector<vector<char> > &s,  int ax, int ay, int n, int m)
{
    q.push({ax, ay});
    s[ax][ay] = '#';

    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        
        if(p.first - 1 >= 0 &&  s[p.first - 1][p.second] != '#')
        {
            s[p.first - 1][p.second] = '#';
            s1[p.first - 1][p.second] = 'U';
            q.push({p.first - 1, p.second});
        }

        if(p.first + 1 < n &&  s[p.first + 1][p.second] != '#')
        {
            s[p.first + 1][p.second] = '#';
            s1[p.first + 1][p.second] = 'D';
            q.push({p.first + 1, p.second});
        }

        if(p.second - 1 >= 0 &&  s[p.first][p.second - 1] != '#')
        {
            s[p.first][p.second - 1] = '#';
            s1[p.first][p.second - 1] = 'L';
            q.push({p.first, p.second - 1});
        }

        if(p.second + 1 < m &&  s[p.first][p.second + 1] != '#')
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

    queue<pair<int, int> >q;

    vector<vector<char> > s, s2;
    int ax, ay, bx, by; 

    for(int i = 0; i < n; i++)
    {
        vector<char> s1;
        for(int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            s1.push_back(ch);

            if(ch == 'A')
            {
                ax = i;
                ay = j;
            }

            if(ch == 'B')
            {
                bx = i;
                by = j;
            }
        }

        s.push_back(s1);
        s2.push_back(s1);
    }

    vector<char> v;

    bfs(q, s2, s, ax, ay, n, m);

    if(s[bx][by] == 'B')
    {
        cout <<"NO" << endl;
    }
    else
    {
        while(bx != ax || by != ay)
        {
            v.push_back(s2[bx][by]);
            if(s2[bx][by] == 'L')
            {
                by++;
            }
            else if(s2[bx][by] == 'R')
            {
                by--;
            }
            else if(s2[bx][by] == 'U')
            {
                bx++;
            }
            else if(s2[bx][by] == 'D')
            {
                bx--;
            }
        }

        cout <<"YES" << endl <<  v.size() << endl;

        for(int i = v.size() - 1; i >= 0; i--)
        {
            cout << v[i];
        }

        cout << endl;
    }


/*for(int i = 0; i < n; i++)
{
    for(int j = 0; j < m; j++)
    {
        cout << s[i][j] << " ";
    }

    cout << endl;
}*/

    return 0;
}