#include <stdio.h>

int main(void) {
    typedef long long int lli;
    lli n, m, target;
    scanf("%lld %lld %lld", &n, &m, &target);
    lli arr[n][m];
    for (lli i = 0; i != n; ++i) {
        for (lli j = 0; j != m; ++j) {
            scanf("%lld", &arr[i][j]);
        }
    }
    lli sum_val = 0;
    for (lli i = 0; i != n; ++i) {
        for (lli j = 0; j != m; ++j) {
            sum_val += arr[i][j];
        }
    }
    if (sum_val != target) {
        printf("wrong answer");
        return 0;
    }
    lli row = 0, col = 0;
    lli this_row = 0, this_col = 0;
    for (lli i = 0; i != n; ++i) {
        for (lli j = 0; j != m; ++j) {
            this_row ^= arr[i][j];
        }
        if (!i) row = this_row;
        else if (this_row != row) {
            printf("wrong answer");
            return 0;
        }
        this_row = 0;
    }
    for (lli j = 0; j != m; ++j) {
        for (lli i = 0; i != n; ++i) {
            this_col ^= arr[i][j];
        }
        if (!j) col = this_col;
        else if (this_col != col) {
            printf("wrong answer");
            return 0;
        }
        this_col = 0;
    }
    if(row == col)
        printf("accepted");
    else
        printf("wrong answer");
    return 0;
}