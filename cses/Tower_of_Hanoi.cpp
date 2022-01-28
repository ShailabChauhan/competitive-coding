#include <bits/stdc++.h>
using namespace std;

vector <pair <int , int > > v;

void tower(int n, int p1, int p2, int p3)
{
    if( n > 0)
    {
        if(n == 1)
        {
            //cout << p1 << " " << p3 << endl;
            v.push_back({p1, p3});
        }
        else
        {
            tower(n-1, p1, p3, p2);
            //cout << p1 << " " << p3 << endl;
            v.push_back({p1, p3});
            tower(n-1, p2, p1, p3);
        }
    }
    
}

int main()
{
    int n;
    cin >> n;

    tower(n, 1,2,3);

    cout << v.size() << endl;

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0; 
}