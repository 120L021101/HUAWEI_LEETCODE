#pragma GCC optimize("-O2")

#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i != n; ++i)
        cin >> a[i];
    
    vector<ll> modify_idx;
    set<ll> occured;
    for (ll i = 0; i != n; ++i) {
        if (occured.count(a[i]) || a[i] > n) {
            modify_idx.push_back(i);
        } else {
            occured.insert(a[i]);
        }
    }

    vector<ll> not_occured;
    for (ll i = 1; i <= n; ++i) {
        if (!occured.count(i)) {
            not_occured.push_back(i);
        }
    }

    cout << modify_idx.size() << endl;

    ll n_idx = 0;
    for (ll idx : modify_idx) {
        cout << (idx + 1) << ' ' << not_occured[n_idx ++] << endl;
    }

    return 0;
}