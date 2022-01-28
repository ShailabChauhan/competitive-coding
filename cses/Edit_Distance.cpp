#include<bits/stdc++.h>
using namespace std;

int edit_distance(vector < vector < int > >&v, vector<char> &v1, vector<char> &v2, int n1, int n2)
{
    int x = 1;
    if(v1[n1-1] == v2[n2 - 1])
    {
        x = 0;
    }

    if(n1 == 1 && n2 == 1 && v1[n1 - 1] == v2[n2 - 1])
    {
        return 0;
    }
    else if(n1 == 1 && n2 == 1)
    {
        return 1;
    }
    else if(v[n1][n2] != - 1)
    {
        return v[n1][n2];
    }

    int s = 50000000;
    int k;
    if(n1 > 1)
    {
        k = edit_distance(v, v1, v2, n1 - 1, n2) + 1;
        
        if(s > k)
        {
            s = k;
        }
    }

    if(n2 > 1)
    {
        k = edit_distance(v, v1, v2, n1, n2 - 1) + 1;
        if(s > k)
        {
            s = k;
        }
    }

    if(n1 > 1 && n2 > 1)
    {
        k = edit_distance(v, v1, v2, n1 - 1, n2 - 1) + x;
        if(s > k)
        {
            s = k;
        }
    }

    v[n1][n2] = s;

    return s;
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<char> v1, v2;
    vector< vector<int> > v;

    for(int i =0; i <= n1; i++)
    {
        vector<int> v3;
        for(int j = 0; j <= n2; j++)
        {
            v3.push_back(-1);
        }
        v.push_back(v3);
    }

    for(int i = 0; i < n1; i++)
    {
        v1.push_back(s1[i]);
    }

    for(int i = 0; i < n2; i++)
    {
        v2.push_back(s2[i]);
    }


    cout << edit_distance(v, v2, v1, n2, n1) << endl;

    return 0;
}