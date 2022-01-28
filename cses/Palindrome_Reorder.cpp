#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <char> v;

    char s[1000000];
    //cin >> ch;
    scanf("%s", s);
    int n = strlen(s);

    for(int i = 0; i < n; i++)
    {
        v.push_back(s[i]);
    }

    sort(v.begin(), v.end());

    int count = 0;

    char v1[n];
    int i = 0, j = n - 1;

    int k = 0;
    char ch;

    while(k < n && count <= 1)
    {
        if(k == n - 1)
        {
           ch = v[k];
            count++;
            k++;
            break;
        }
        if(v[k] == v[k + 1])
        {
            v1[i] = v[k];
            v1[j] = v[k];
            k = k + 2;
            i++;
            j--;
        }
        else
        {
            count++;
            ch = v[k];
            k++;
        }
    }

    if(count > 1)
    {
        cout << "NO SOLUTION";
    }
    else if(count == 0)
    {
        for(int i = 0; i < n; i++)
        {
            cout << v1[i];
        }
        cout << endl;
        //printf("%s\n", v1);
    }
    else
    {
        v1[i] = ch;
        for(int i = 0; i < n; i++)
        {
            cout << v1[i];
        }
        cout << endl;
        //printf("%s\n", v1);
    }

    return 0; 
}