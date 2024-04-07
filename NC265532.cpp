#pragma GCC optimize("-O2")

#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main(void) {
    ll T;
    cin >> T;
    char success_msg[] = "Yes";
    char failed_msg[] = "No";
    while (T--) {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (ll i = 0; i != n; ++i) {
            cin >> a[i];
        }
        ll prev_val = a[0] - k;
        bool if_failed = false;
        for (ll i = 1; i != n && !if_failed; ++i) {
            ll p_min = a[i] - k;
            ll p_max = a[i] + k;
            if (prev_val > p_max) {
                if_failed = true;
                break;
            }
            prev_val = fmax(p_min, prev_val);
        }
        if (if_failed) {
            cout << failed_msg << endl;
        } else {
            cout << success_msg << endl;
        }
    }
}