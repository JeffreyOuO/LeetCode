/*
 * LeetCode 88. Merge Sorted Array 
 * Language: C++
 * Time Complexity: O(m+n)
 * Space Complexity: O(1)
 * Approach:
 *   Describe your key idea in 1-3 lines (semantic, not step-by-step).
 * Compare nums1[idx1] and nums2[idx2], place the larger value at nums1[writeIdx],
 *   and move pointers backward. Continue until nums2 is exhausted. 
 *   (Remaining elements in nums1 are already in place.)
 */

#include <vector>
using namespace std;
 class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {  
        int idx1=m-1; // last valid in nums1
        int idx2=n-1; // last in nums2
        int writeIdx =m+n-1; // write cursor (from back)

        // 1) fill from the back while both have elements
        while(idx1>=0&&idx2>=0){
            if(nums1[idx1]>nums2[idx2])
                nums1[writeIdx--]=nums1[idx1--];
            else
                nums1[writeIdx--]=nums2[idx2--];
        }
         // 2) copy the rest of nums2 (if any). nums1's remainder is already in place.
        while(idx2>=0){
            nums1[writeIdx--]=nums2[idx2--];
        }       
    }
};