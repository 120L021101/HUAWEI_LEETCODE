#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
using lli = long long int;

int main(void) {
    lli n, k;
    cin >> n >> k;
    lli pos[n];
    for (lli i = 0; i != n; ++i)
        cin >> pos[i];
    sort(pos, pos + n);
    lli cWin = 0;
    lli l = 0, r = 0;
    lli maxCh = 0;
    while (1) {
        r ++;
        if (r == n) break;
        while ((cWin = pos[r] - pos[l]) > k) l ++;
        maxCh = fmax(maxCh, r - l + 1);
    }
    cout << double(maxCh) / n << endl;
    return 0;
}