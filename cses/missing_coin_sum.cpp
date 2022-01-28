#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <long long int > v;
    long long int missing = 1;

    for(int i =0; i < n; i++)
    {   
        int a;
        cin >> a;
        v.push_back(a);
    } 

    sort(v.begin(), v.end());

    for(int i = 0; i< n; i ++)
    {
        if(v[i] <= missing)
        {
            missing += v[i];
        }
    }

    cout << missing << endl;

    return 0;
}