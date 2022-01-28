#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
void bfs(vector<vector<pair<int, int>>> &v, queue<pair<int, int>> &q, vector<ll> &length, int num)
{
    q.push({1, 0});
    length[1] = 0;
 
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
 
        for(int i = 0; i < v[p.first].size(); i++)
        {
            /*if(length[v[p.first][i].first] == 0)
            {
                length[v[p.first][i].first] = length[p.first] + v[p.first][i].second;
                q.push(v[p.first][i]);
            }
            else*/ if(length[p.first] + v[p.first][i].second > length[v[p.first][i].first] && v[p.first][i].first != 1)
            {
                length[v[p.first][i].first] = length[p.first] + v[p.first][i].second;
                q.push(v[p.first][i]);
            }
        }
    }
}
 
int main()
{
    int n, m;
    //cin >> n >> m;
    scanf("%d %d", &n, &m);
 
    vector<vector<pair<int, int> > > v(n + 1);
    queue<pair<int, int>> q;
 
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        //cin >> a >> b >> c;
        scanf("%d %d %d", &a, &b, &c);
 
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
 
    vector<ll> length(n + 1);
 
    for(int i = 2; i <= n; i++)
    {
        length[i] = -1000000000000000000;
    }
 
    bfs(v, q, length, 1);
 
    /*for(int i = 1; i <= n; i++)
    {
        //cout << length[i] - 1 << " ";
        printf("%lld ", length[i] - 1);
    }
    //cout << endl;*/

    printf("%lld\n", length[n]);
   //printf("\n");
 
    return 0;
}