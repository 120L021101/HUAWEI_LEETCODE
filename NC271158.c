#include <stdio.h>


int main(void) {
    long long int n; long long int k;
    scanf("%lld %lld", &n, &k);
    long long int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld", arr + i);
    }
    long long op = 0; long long int maxDiff = 0;
    for (long long i = 0; i < n - 1; ++i) {
        long long int diff = abs(arr[i + 1] - arr[i]);
        maxDiff = fmax(maxDiff, diff);
        op += diff / k;
        if (diff && diff % k == 0) op --;
    }
    if (maxDiff < k) {
        printf("1");
    }
    if (maxDiff == k) {
        printf("0");
    }
    if (maxDiff > k) {
        printf("%lld", op);
    }
    return 0;
}