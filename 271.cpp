class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (string& str : strs) {
            string en_str = "";
            for (char c : str) {
                en_str += c;
                if (c == '$') {
                    en_str += c;
                }
            }
            encoded_string += en_str + "/$/";
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s.length() == 0) {
            return {""};
        }
        vector<string> decoded_strings = {};
        int si = 0, i = 0, j = 1, k = 2;
        while (k < s.length()) {
            string de_str = "";
            if (s[i] == '/' && s[j] == '$' && s[k] == '/') {
                while (si != i) {
                    de_str += s[si];
                    if (s[si] == '$') si ++;
                    si ++;
                }
                si = k + 1;
                decoded_strings.push_back(move(de_str));
                i = k + 1; j = k + 2; k = k + 3;
                continue;
            }
            i ++; j ++; k ++;
        }
        return decoded_strings;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));