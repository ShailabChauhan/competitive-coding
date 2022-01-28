#include <bits/stdc++.h>
 
using namespace std;
 


int max_way(int n, int x, int*a, int* count)
{
    int prev = 0;
    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i - a[j] >= 0 && (a[j] > prev))
            {
                prev = a[j];
                count[i] = count[i] + count[i - a[j]];
                count[i] = count[i]%1000000007;
            }
        }
    }
 
    return count[x];
}
 
int main()
{
    int n, x;
    cin >> n >> x;
 
    int a[n];
 
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
 
    int count[x + 1];
 
    count[0] = 1;
 
    for(int i = 1; i <=x; i++)
    {
        count[i] = 0;
    }
 
    cout << max_way(n, x, a, count);
 
    return 0;
}