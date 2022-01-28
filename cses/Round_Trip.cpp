#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &v, vector<int> &prev, int num)
{
    for(int i = 0; i < v[num].size(); i++)
    {
        if(prev[v[num][i]] == 0)
        {
            prev[v[num][i]] =num;
            dfs(v, prev, v[num][i]);
        }
    }
}

int k = 0, j = 0;
void bfs(queue<int> &q,vector<vector<int>> &v, vector<int> &prev, int num)
{
    q.push(num);

    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        for(int i = 0; i < v[p].size(); i++)
        {
            if(prev[v[p][i]] == 0)
            {
                prev[v[p][i]] = p;
                q.push(v[p][i]);
            }
            else if(prev[v[p][i]] != p && prev[p] != v[p][i])
            {
                k = v[p][i];
                j = p;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1);
    vector<int> prev(n + 1);
    queue<int> q;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(prev[i] == 0)
        {
            prev[i] = -1;
            bfs(q,v,prev,i);
        }
    }
    
    /*prev[4] = -1;
    bfs(q,v,prev,4);
    
    if(prev[5] == 0)
    {
        bfs(q,v,prev,5);
    }*/
    
    
    //cout << k << " " << j << " " << prev[5]<< " " << prev[4] ;
    
    //cout << v[4][0];

    if(k == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> prev1(n + 1);
        int num1 = k, num2 = j;

        int j = 0;

        while(v[num2][j] != num1)
        {
            j++;
        }

        v[num2][j] = 0;
        prev1[0] = -1;
        prev1[num2] = num1;
        
        dfs(v, prev1, num2);

        vector<int> v1;
        
        int l = prev1[num1];
        v1.push_back(num1);


        while(l != num1)
        {
            v1.push_back(l);
            l = prev1[l];
        }

        v1.push_back(l);

        cout << v1.size() << endl;

        for(int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }

        cout << endl;
    }

    return 0;
}