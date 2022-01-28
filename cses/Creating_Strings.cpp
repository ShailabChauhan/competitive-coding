#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <char> v, v1;
 
    char s[8];
    //cin >> ch;
    scanf("%s", s);
    int n = strlen(s);
 
    for(int i = 0; i < n; i++)
    {
        v.push_back(s[i]);
    }
 
    sort(v.begin(), v.end());

    v1 = v;
    if(v.size() == 1)
    {
        cout << "1" << v1[0] << endl;
    }
    else
    {
        long long int count = 1;
        vector <vector <char> > v2;

        v2.push_back(v);
        next_permutation(v.begin(), v.end());

        while(v != v1)
        {
            v2.push_back(v);
            count++;
            next_permutation(v.begin(), v.end());
        }

        cout << count << endl;

        for(int i = 0; i < v2.size(); i++)
        {
            for(int j = 0; j < v2[i].size(); j++)
            {
                cout << v2[i][j];
            }

            cout << endl;
        }
    }

    return 0; 
}