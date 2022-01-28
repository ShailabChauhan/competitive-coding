#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int > v, v1;

    if(n%2 == 0)
    {
        if(n%4 == 0)
        {
            cout << "YES" << endl;

            cout << n/2 << endl;

            int i = 1, j = n;

            while(i < j)
            {
                v.push_back(i);
                v.push_back(j);
                i = i + 2;
                j = j - 2;
            }

            sort(v.begin(), v.end());

            for(int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }

            cout << endl;
            cout << n/2 << endl;

            i = 2, j = n - 1;

            while(i < j)
            {
                v1.push_back(i);
                v1.push_back(j);
                i = i + 2;
                j = j - 2;
            }

            sort(v1.begin(), v1.end());

            for(int i = 0; i < v1.size(); i++)
            {
                cout << v1[i] << " ";
            }

            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }   
    }
    else
    {
        if((n + 1)%4 == 0)
        {
            cout << "YES" << endl;

            cout << n/2 << endl;

            int i = 0, j = n;

            while(i < j)
            {
                v.push_back(i);
                v.push_back(j);
                i = i + 2;
                j = j - 2;
            }

            sort(v.begin(), v.end());

            for(int i = 1; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }

            cout << endl;
            cout << n/2 + 1 << endl;

            i = 1, j = n - 1;

            while(i < j)
            {
                v1.push_back(i);
                v1.push_back(j);
                i = i + 2;
                j = j - 2;
            }

            sort(v1.begin(), v1.end());

            for(int i = 0; i < v1.size(); i++)
            {
                cout << v1[i] << " ";
            }

            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }   
    }

    return 0;
}