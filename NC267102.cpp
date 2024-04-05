#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int main() {
    lli n;
    cin >> n;
    lli arr[n];
    for (lli i = 0; i < n; ++i)
        cin >> arr[i];
    lli prefix[n];
    prefix[0] = arr[0];
    for (lli i = 1; i < n - 2; ++i)
        prefix[i] = prefix[i - 1] ^ arr[i];
    lli cMax = prefix[n - 3] + arr[n - 2];
    lli curVal = arr[n - 2];
    for (lli i = n - 3; i > 0; --i) {
        curVal |= arr[i];
        cMax = fmax(cMax, curVal + prefix[i - 1]);
    }
    cout << cMax + arr[n - 1] << endl;
    return 0;
}