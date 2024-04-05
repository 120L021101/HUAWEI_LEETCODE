#include <unordered_map>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
using lli = long long int;

int main() {
    char buf[int(1e5) + 10];
    cin >> buf;
    lli len = strlen(buf);

    unordered_map<char, lli> counter;
    for (lli i = 0; i < len; ++i) {
        if (!counter.count(buf[i])) {
            counter[buf[i]] = 0;
        }
        counter[buf[i]] ++;
    }
    char contains[] = "xiaohong";
    for (lli i = 0; i < 8; ++i) {
        buf[i] = contains[i];
        counter[contains[i]] --;
    }
    lli pointer = 8;
    for (decltype(counter.begin()) itr = counter.begin(), end = counter.end(); itr != end; itr ++) {
        for (lli i = 0; i < itr->second; ++i) {
            buf[pointer ++] = itr->first;
        }
    } 
    buf[pointer] = '\0';
    cout << buf << endl;
    return 0;
}