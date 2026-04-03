class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> og;
    int l = 0, count = 0;
    int minn = INT_MAX;
    int start = 0;  // to store starting index of best window

    for (int i = 0; i < t.size(); i++) {
        og[t[i]]++;
    }

    for (int r = 0; r < s.size(); r++) {

        if (og.find(s[r]) != og.end()) {
            if (og[s[r]] > 0) {
                count++;
            }
            og[s[r]]--;
        }

        while (count == t.length()) {

            if (r - l + 1 < minn) {
                minn = r - l + 1;
                start = l;   // store start index
            }

            if (og.find(s[l]) != og.end()) {
                og[s[l]]++;
                if (og[s[l]] > 0) {
                    count--;
                }
            }
            l++;
        }
    }

    return minn == INT_MAX ? "" : s.substr(start, minn);

    }
};
