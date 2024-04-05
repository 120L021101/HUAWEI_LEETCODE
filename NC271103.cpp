#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 10;
 
int a[N];
int l[N];
map<int, int> mp;
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
        if (!mp[a[i]]) mp[a[i]] = i;
        if (mp[a[i]] and mp[a[i]] < i - 1) l[i] = mp[a[i]]; 
        l[i] = max(l[i],l[i - 1]);
        if (i > 2 and a[i] == a[i-2]) l[i] = i - 2; // 防止连续元素被覆盖的特判
        mp[a[i]] = i;
    }
    while(q --)
    {
        int a, b;
        cin >> a >> b;
        if (l[b] >= a) cout << "YES" << endl;
        else cout <<"NO" << endl;
    }
    return 0;
}