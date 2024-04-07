#pragma GCC optimize("-O2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
static ll LOG = (ll)(1e9 + 7);
int main() {

    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    ll remaining = n - k;
    ll dp[n][remaining + 1];
    memset(dp, 0, sizeof(ll) * (n * remaining + n));
    for (ll i = 0; i < n; ++i) {
        dp[i][1] = 1;
        for (ll j = 0; j < i; ++j) {
            if (arr[i] % arr[j])
                continue;
            for (ll p = 2; p <= remaining; ++p) {
                dp[i][p] += dp[j][p - 1];
                dp[i][p] %= LOG;
            }
        }
    }
    ll sumVal = 0;
    for (ll i = 0; i < n; ++i) {
        sumVal += dp[i][remaining];
        sumVal %= LOG;
    }
    cout << sumVal;
    return 0;
}