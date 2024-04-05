#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using lli = long long int;
using namespace std;

int main(void) {
    lli n;
    cin >> n;
    map<lli, lli> counter;
    vector<lli> occured;
    for (lli i = 0; i != n; ++i) {
        lli val;
        cin >> val;
        if (!counter.count(val)) {
            counter[val] = 0;
            occured.push_back(val);
        }
        counter[val] ++;
    }
    sort(occured.begin(), occured.end());

    lli cost = 0;
    for (lli i = 0; i != occured.size(); ++i) {
        lli val = occured[i];
        if (!counter.count(val) or counter[val] == 0)
            continue;
        cost += counter[val];
        while (counter[val] --) {
            lli cVal = val + 1;
            while (counter.count(cVal) && counter[cVal] != 0) {
                counter[cVal] --;
                cVal ++;
            }
        }
    }
    cout << cost << endl;
    return 0;
}