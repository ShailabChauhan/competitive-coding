#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;
    int n = s.size();

    int count = 1, max_count = 0;

    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            count++;
        }
        else
        {
            if(max_count < count)
            {
                max_count = count;
            }

            count = 1;
        }
    }

    if(max_count < count)
    {
        max_count = count;
    }

    cout << max_count << endl;

    return 0;
}