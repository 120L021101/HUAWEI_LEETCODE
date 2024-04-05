#pragma GCC optimize("-O3")

#include <bits/stdc++.h>

using namespace std;

using lli = long long int;

int main() {
    lli n;
    char chr;
    cin >> n >> chr;

    char buf[n + 1];
    cin >> buf;

    lli left = 0, right = n - 1;
    lli count = 0;
    for (lli i = 0; i != n; ++i) {
        if (buf[i] != chr)
            continue;
        lli dis = fmin(i - left, right - i);
        count += dis + 1;
    }
    cout << count << endl;

    return 0;
}