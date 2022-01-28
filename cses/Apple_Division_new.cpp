#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long int sum = 0;

    vector<int> v, v1;
    
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        v.push_back(a);
        sum = sum + a;
    }

    v1 = v;
    long long int small = sum;
    long long int l = 0;

    int i = 0;
    while(sum - 2*l >= 0)
    {
        if(sum - 2*l < small)
        {
            small = sum - 2*l;
        }
        l = l + v1[i];
        i++;
    }
    next_permutation(v1.begin(), v1.end());

    while(v != v1)
    {
        int i = 0;
        l = 0;
        while(sum - 2*l >= 0)
        {
            if(sum - 2*l < small)
            {
                small = sum - 2*l;
            }
            l = l + v1[i];
            i++;
        }

        next_permutation(v1.begin(), v1.end());
    }

    
    cout << small << endl;
    
    return 0;
}