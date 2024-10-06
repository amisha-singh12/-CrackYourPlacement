class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i =0 , j =0 , k =0 ;
        int size = m+n;
        int index1 = size/2 -1;
        int index2 = size/2;
        int element1 = -1, element2 = -1; // Declare the elements here
         vector<int> temp;
        while (i < n && j < m) {
            if ( nums1[i] < nums2[j]) {
                if(k == index1) {
                    element1 = nums1[i];
                } 
                if(k == index2) {
                    element2 = nums1[i];
                }
               i++;
            } 
            else {
                 if(k == index1) {
                    element1 = nums2[j];
                } 
                else if(k == index2) {
                    element2 = nums2[j];
                }
                j++;
            }
            k++;
        }

        while(i<n){
             if(k == index1) {
                    element1 = nums1[i];
                } 
                if(k == index2) {
                    element2 = nums1[i];
                }
               i++;
               k++;
        }
        while(j<m){
              if(k == index1) {
                    element1 = nums2[j];
                } 
                else if(k == index2) {
                    element2 = nums2[j];
                }
                j++;
                k++;
        }

        if(size%2 == 1) {
            return element2;
        }
        else {
            return (element2 +element1)/2.0;
        }
    }
};