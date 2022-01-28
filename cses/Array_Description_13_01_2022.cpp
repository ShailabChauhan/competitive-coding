#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll no_of_ways(int start, int end, int size, int n)
{
    if(size == 0 && start == end)
    {
        return 1;
    }
    else if(size <= 0)
    {
        return 0;
    }
    
    if(end == 1)
    {
        return (no_of_ways(start, end, size - 1, n) + no_of_ways(start, end + 1, size - 1, n))%1000000007;
    }
    else if(end == n)
    {
        return (no_of_ways(start, end, size - 1, n) + no_of_ways(start, end - 1, size - 1, n)%1000000007) ;
    }
    else
    {
       return  (no_of_ways(start, end - 1, size - 1, n) + no_of_ways(start, end, size - 1, n) + no_of_ways(start, end + 1, size - 1, n))%1000000007;
    }

}


int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> >v;

    vector<int> v1;
    int s, e;

    for(int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        v1.push_back(a);
    }

    for(int i = 0; i < n; i++)
    {
        if(v1[i] == 0 && )
    }

}