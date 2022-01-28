#include <bits/stdc++.h>
using namespace std;

int max_way(int n,int start, int x, vector <int>a, int* count)
{
    for(int i = 1; i <= x; i++)
    {
        for(int j = start; j < n; j++)
        {
            if(i - a[j] >= 0)
            {
                count[i] = count[i] + count[i - a[j]];
                count[i] = count[i]%1000000007;
            }
        }
    }
 
    return count[x];
}

int main()
{
    int n, x,a;
    cin >> n >> x;
    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        //sum = (sum + max_way(n, x - v[i], i, v, count));
        //sum = sum%1000000007;
        
        int count[x - v[i] + 1];
 
        count[0] = 1;
    
        for(int j = 1; j <=x - v[j]; j++)
        {
            count[j] = 0;
        }
        
        cout << max_way(n, x - v[i], i, v, count) << " ";
    }
 
    //cout << sum << endl;

    return 0;

}