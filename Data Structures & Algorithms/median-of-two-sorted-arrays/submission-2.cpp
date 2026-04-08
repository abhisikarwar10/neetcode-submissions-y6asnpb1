class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    

        int i = 0;
        int j = 0;
        int m1 = 0, m2 = 0;

        int count = (nums1.size() + nums2.size()) / 2 + 1;

        while (count--) {
            m1 = m2;

            if (j < nums2.size() && (i >= nums1.size() || nums2[j] < nums1[i])) {
                m2 = nums2[j++];
            } else {
                m2 = nums1[i++];
            }
        }

        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return (double)m2;
        } else {
            return (m1 + m2) / 2.0;
        }
    }
};
