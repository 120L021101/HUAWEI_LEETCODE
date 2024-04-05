#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string> 

using namespace std;

using lli = long long int;

void o(const vector<vector<lli>>& outputs) {
    for (const vector<lli>& item : outputs) {
        cout << item[0] << ' ' << item[1] << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    lli n, m, max_depth = 0;
    char * failed_message = "-1";
    cin >> n >> m;
    if (m < n - 1) {
        cout << failed_message << endl;
        return 0;
    }
    vector<vector<lli>> dis;
    for (lli i = 0; i != n; ++i) {
        lli val;
        cin >> val;
        dis.push_back({i + 1, val});
        max_depth = fmax(val, max_depth);
    }    

    sort(dis.begin(), dis.end(), [](const vector<lli>& a, const vector<lli>& b) {
        return a[1] < b[1];
    });
    map<lli, vector<vector<lli>>> level_map;
    for (vector<lli>& item : dis) {
        lli depth = item[1], node = item[0];
        if (!level_map.count(depth))
            level_map[depth] = {};
        level_map[depth].push_back(item);
    }
    
    vector<vector<lli>> final_output;
    // output
    lli output_num = 0;
    for (lli depth = 0; depth != max_depth; ++depth) {
        vector<vector<lli>>& this_level = level_map[depth];
        vector<vector<lli>>& next_level = level_map[depth + 1];
        vector<lli>& first_node = this_level[0];
        for (vector<lli>& next_node : next_level) {
            final_output.push_back({first_node[0], next_node[0]});
            output_num ++;
        }
    }
    if (output_num == m) {
        o(final_output);
        return 0;
    }
    for (lli depth = 1; depth <= max_depth; ++depth) {
        vector<vector<lli>>& level = level_map[depth];
        for (lli i = 0; i < level.size() - 1; ++i) {
            for (lli j = i + 1; j < level.size(); ++j) {
                final_output.push_back({level[i][0], level[j][0]});
                output_num ++;
                if (output_num == m) {
                    o(final_output);
                    return 0;
                }
            } 
        }
    }

    for (lli depth = 0; depth != max_depth; ++depth) {
        vector<vector<lli>>& this_level = level_map[depth];
        vector<vector<lli>>& next_level = level_map[depth + 1];
        for (lli i = 1; i < this_level.size(); ++i) {
            vector<lli> this_node = this_level[i];
            for (lli j = 0; j < next_level.size(); ++j) {
                final_output.push_back({this_node[0], next_level[j][0]});
                output_num ++;
                if (output_num == m) {
                    o(final_output);
                    return 0;
                }
            }
        } 
    }
    cout << failed_message << endl;
    return 0;
}