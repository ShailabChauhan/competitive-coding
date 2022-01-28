#include <bits/stdc++.h>
using namespace std;

void dfs(vector <char> *v, int n, int m, int i, int j)
{
     v[i][j] = '#';

        if(i + 1 < n && v[i + 1][j] == '.')
        {
            dfs(v, n, m, i + 1, j);
        }

        if(j + 1 < m && v[i][j + 1] == '.')
        {
            dfs(v, n, m, i, j + 1);
        }


        if(i - 1 >= 0 && v[i - 1][j] == '.')
        {
            dfs(v, n, m, i - 1, j);
        }

        if(j - 1 >= 0 && v[i][j - 1] == '.')
        {
            dfs(v, n, m, i, j - 1);
        }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector< char > v[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            v[i].push_back(ch);
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == '.')
            {
                count++;
                dfs(v, n, m, i, j);
            }
        }
    }

    cout << count << endl;

    return 0;
}