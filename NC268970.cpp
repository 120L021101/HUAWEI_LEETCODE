#include <iostream>
#include <math.h>

using namespace std;
using lli = long long int;

int main(void) {
    lli n;
    cin >> n;
    lli arr[n];
    for (lli i = 0; i != n; ++i) {
        cin >> arr[i];
    }

    lli idx = 0;
    while (idx != n && arr[idx] == 0)
        idx ++;
    if (idx == n) {
        cout << "2 ";
        for (lli i = 1; i != n; ++i) {
            cout << "1 ";
        }
        cout << endl;
        return 0;
    }
    lli before_val = arr[idx];
    bool find_0 = false;
    bool end_0 = arr[n - 1] == 0;
    if (idx) {
        find_0 = true;
        for (lli i = 0; i != idx; ++i) {
            arr[i] = before_val;
        }
    }
    while (++idx != n) {
        if (arr[idx] == 0) {
            arr[idx] = before_val;
        } else {
            before_val = arr[idx];
        }
    }
    lli diff = 0;
    for (lli i = 1; i != n; ++i) {
        diff += abs(arr[i] - arr[i - 1]);
        if (diff > 1) break;
    }
    char * failed_msg = "-1";
    if (diff > 1 || (diff == 0 && !find_0 && !end_0)) {
        cout << failed_msg << endl;
        return 0;
    }
    if (diff == 0 && find_0) {
        arr[0]++;
    } else if (diff == 0 && end_0) {
        arr[n - 1] ++;
    }
    for (lli i = 0; i != n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}