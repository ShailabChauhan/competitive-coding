#include <bits/stdc++.h>
using namespace std;

vector <char> f;
int shortest_path(vector <vector<char>> v, int x1,int y1, int x2, int y2, int n, int m)
{
    v[x1][y1] = '#';
    if(x1 == x2 && y1 == y2)
    {
        return 1;
    }
    else if(x1 < n && y1 < m && x1 >= 0 && y1 >= 0)
    {
        int a[4];
        if(v[x1 + 1][y1] != '#')
        {
            v[x1 + 1][y1] = '#';
            a[0] = 1//shortest_path(v, x1 + 1, y1, x2, y2, n, m);
            /*if(a == 1)
            {
                f.push_back('D');
                return a;
            }*/
        }

        if(v[x1][y1 + 1] != '#')
        {
            v[x1][y1 + 1] = '#';
            a[1] = 1//shortest_path(v, x1, y1 + 1, x2, y2, n, m);
            /*if(a == 1)
            {
                f.push_back('R');
                return a;
            }*/
            
        }

        if(v[x1 - 1][y1] != '#')
        {
            v[x1 - 1][y1] = '#';
            a[2] =  shortest_path(v, x1 - 1, y1, x2, y2, n, m);
            /*if(a == 1)
            {
                f.push_back('U');
                return a;
            }*/
        }

        if(v[x1][y1 - 1] != '#')
        {
            v[x1][y1 - 1] = '#';
            a[3] = shortest_path(v, x1, y1 - 1, x2, y2, n, m);
            /*if(a == 1)
            {
                f.push_back('L');
                return a;
            }*/
        }
    }
    else
    {
        return 0;
    }
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    int x1,y1,x2,y2;

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
                y1 = j;
                x1 = i;
            }

            if(ch == 'B')
            {
                y1 = j;
                x1 = i;
            }
        }

        v.push_back(v1);
    }

    int a = shortest_path(v, x1, y1, x2, y2, n, m);

    if(a == 0)
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