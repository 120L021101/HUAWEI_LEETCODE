#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using lli = long long int;
using namespace std;

int main(void) {
    lli n;
    cin >> n;
    char str[n + 2];
    str[n + 1] = '\0';
    cin >> str + 1;
    map<lli, vector<lli>> edge_map;
    for (lli i = 0; i != n; ++i) {
        lli n1, n2;
        cin >> n1 >> n2;
        if (!edge_map.count(n1))
            edge_map[n1] = {};
        edge_map[n1].push_back(n2);
        edge_map[n2].push_back(n1);
    }    

    vector<lli> level;
    bool visited[n + 1];
    for (lli i = 0; i <= n; ++i)
        visited[i] = false;
    for (lli i = 1; i <= n; ++i) {
        if (str[i] != '?') {
            level.push_back(i);
            visited[i] = true;
        }
    }
    if (level.size() == 0) {
        str[1] = 'd';
        level.push_back(1);
        visited[1] = true;
    }
    while(level.size()) {
        vector<lli> next_level;
        lli size = level.size();
        for (lli i = 0; i != size; ++i) {
            lli n = level[i];
            for (lli ln : edge_map[n]) {
                if (str[n] == str[ln]) {
                    cout << "-1" << endl;
                    return 0;
                }
                if (visited[ln])
                    continue;
                visited[ln] = true;
                if (str[ln] == '?') {
                    if (str[n] == 'd') str[ln] = 'p';
                    if (str[n] == 'p') str[ln] = 'd';
                }
                next_level.push_back(ln);
            }
        }
        level.clear();
        level.resize(next_level.size());
        copy(next_level.begin(), next_level.end(), level.begin());
    }
    cout << str + 1 << endl;
    return 0;
}