class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    map<int, vector<int>> m;
    int l = 0;
    int r = 0;
    int t = k;
    vector<int> out;

    // build first window
    while (t--) {
        m[nums[r]].push_back(r++);
    }

    // max element = last key in map
    out.push_back(m.rbegin()->first);

    r = k - 1;

    while (r < (int)nums.size() - 1) {
        r++;

        // remove left element
        int val = nums[l];
        m[val].erase(m[val].begin());

        // if no indices left → remove key
        if (m[val].empty()) {
            m.erase(val);
        }

        l++;

        // add new element
        m[nums[r]].push_back(r);

        // get max
        out.push_back(m.rbegin()->first);
    }

    return out;
}
};
