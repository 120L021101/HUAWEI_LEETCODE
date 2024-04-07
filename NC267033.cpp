#pragma GCC optimize("-O2")
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll barr[n];
    memset(barr, 0, sizeof(ll) * n);
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1])
            continue;
        barr[i] = arr[i - 1] - arr[i];
        arr[i] = arr[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << barr[i] << ' ';
    }
    cout << endl;

    return 0;
}