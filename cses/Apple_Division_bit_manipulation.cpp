#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void decimal_to_binary(vector <int> &v, int num, int n)
{
    while(num)
    {
        v.push_back(num%2);
        num = num/2;
    }

    while(v.size() < n)
    {
        v.push_back(0);
    }

    vector<int> v1;

    for(int i = n - 1; i >= 0; i--)
    {
        v1.push_back(v[i]);
    }

    v = v1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        sum = sum + a;
    }

    int num = pow(2,n);

    ll small = sum;
    for(int i = 0; i < num; i++)
    {   
        ll sum1 = 0;
        vector<int> v1;
        decimal_to_binary(v1, i, n);

        for(int i = 0; i < n; i++)
        {
            sum1 = sum1 + v[i]*v1[i];
        }

        ll k = sum - 2*sum1;
        if(k >= 0 && k < small)
        {
            small =  k;
        }
    }

    cout << small << endl;

    return 0;
}