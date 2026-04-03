class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    unordered_map<char,int> og;
    int l = 0;
    int count = 0;

    for (int i = 0; i < s1.size(); i++) {
        og[s1[i]]++;
    }

    for (int r = 0; r < s2.size(); r++) {

        if (og.find(s2[r]) == og.end()) {
            while (l < r) {
                og[s2[l]]++;
                l++;
            }
            count = 0;
            l = r + 1;
            continue;
        }

        if (og[s2[r]] == 0) {
            while (s2[l] != s2[r]) {
                og[s2[l]]++;
                l++;
                count--;
            }
            // move past the duplicate
            og[s2[l]]++;
            l++;
            count--;
        }

        og[s2[r]]--;
        count++;

        if (count == s1.length()) {
            return true;
        }
    }

    return false;
}
};
