#pragma GCC optimize("-O2")

#include <bits/stdc++.h>

using namespace std;

using lli = long long int;

int main() {
    lli n;
    cin >> n;
    lli arr[n];
    lli arr2[n];
    for (lli i = 0; i != n; ++i) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    
    unordered_map<lli, double> res;
    sort(arr, arr + n);
    lli mid_idx = n >> 1;
    if (n % 2) {
        for (lli i = 0; i < n / 2; ++i) {
            res[arr[i]] = (1.0 * arr[mid_idx] + arr[mid_idx + 1]) / 2;
        }
        res[arr[mid_idx]] = (1.0 * arr[mid_idx - 1] + arr[mid_idx + 1]) / 2;
        for (lli i = n / 2 + 1; i < n; ++i) {
            res[arr[i]] = (1.0 * arr[mid_idx] + arr[mid_idx - 1]) / 2;
        }
    } else {
        for (lli i = 0; i < n / 2; ++i) {
            res[arr[i]] = (1.0 * arr[mid_idx]);
        }
        for (lli i = n / 2; i < n; ++i) {
            res[arr[i]] = (1.0 * arr[mid_idx - 1]);
        }
    }
    for (lli i = 0; i < n; ++i) {
        cout << setprecision(1) << fixed << res[arr2[i]] << endl;
    }

    return 0;
}