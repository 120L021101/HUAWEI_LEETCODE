class Solution {
private:
    using FATHER_MAP = unordered_map<string, string>;
    using FREQ_CTR = unordered_map<string, int>;

    inline void getNamePair(const string& synonym, string &name1, string &name2) {
        decltype(synonym.find(',')) lpos = synonym.find(',');
        name1 = synonym.substr(1, lpos - 1);
        name2 = synonym.substr(lpos + 1, synonym.length() - lpos - 2);
    }

    inline void getNameFreq(string& name, string& pureName, int& frequency) {
        decltype(name.find('(')) lpos = name.find('(');
        pureName = name.substr(0, lpos);
        frequency = stoi(name.substr(lpos + 1, name.length() - lpos - 2));
    }

    inline void addNameFreq(FREQ_CTR& merge_name_frequency, const string& root, int& frequency) {
        if (merge_name_frequency.count(root) == 0)
            merge_name_frequency[root] = frequency;
        else
            merge_name_frequency[root] += frequency;
    }

    inline string constructName(const string& name, int frequency) {
        return name + "(" + to_string(frequency) + ")";
    }

    const string& find_father(FATHER_MAP& father_map, const string& child) {
        if (father_map.count(child) == 0) {
            return father_map[child] = child;
        }
        const string& father = father_map[child];
        if (father == child) 
            return father;
        return father_map[child] = find_father(father_map, father);
    }

    void merge(FATHER_MAP& father_map, const string& name1, const string& name2) {
        const string& root1 = find_father(father_map, name1);
        const string& root2 = find_father(father_map, name2);
        if (root1 < root2)
            father_map[root2] = root1;
        else 
            father_map[root1] = root2;
    }    


public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        FATHER_MAP father_map;

        string name1, name2;
        for (string& synonym : synonyms) {
            getNamePair(synonym, name1, name2);
            merge(father_map, name1, name2);
        }

        FREQ_CTR merge_name_frequency;

        string pure_name;
        int frequency;
        for (string& name : names) {
            getNameFreq(name, pure_name, frequency);
            const string& root = find_father(father_map, pure_name);
            addNameFreq(merge_name_frequency, root, frequency);
        }

        vector<string> answer;
        for (FREQ_CTR::iterator itr = merge_name_frequency.begin(), end = merge_name_frequency.end();
                    itr != end; ++itr) {
            string item = constructName(itr->first, itr->second);
            answer.push_back(move(item));
        }
    
        return answer;
    }
};