class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i =0 , j =0;
         vector<int> temp;
        while (i < n || j < m) {
            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                temp.push_back(nums1[i++]);
            } else if (j < m) {
                temp.push_back(nums2[j++]);
            }
        }

        int size = m+n;
        if(size%2 == 0) {
            return (temp[size/2] + temp[(size/2) -1] )/2.0;
        }
        else {
            return temp[size/2];
        }
    }
};