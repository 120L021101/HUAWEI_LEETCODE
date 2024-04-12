#pragma GCC optimize("-O2")

#include <stdio.h>
#include <math.h>

typedef long long int ll;

int main(void) {

    ll n, q;
    scanf("%lld %lld", &n, &q);
    ll arr[n];
    ll p[3];
    p[0] = p[1] = p[2] = 0;
    for (ll i = 0; i != n; ++i) {
        scanf("%lld", arr + i);
        arr[i] = arr[i] % q;
        p[arr[i]] ++;
    }

    if (p[0]) {
        printf("1");
    } else if (p[1] && p[2]) {
        printf("2");
    } else {
        printf("3");
    }

    return 0;
}