/*
 * LeetCode 26. Remove Duplicates from Sorted Array
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Approach:
 *   Since the array is sorted, duplicates are adjacent. 
 *   Use a write pointer to place unique elements in order while scanning once. 
 *   The write index gives the new length of the deduplicated array.
 */

 #include<vector>
 using namespace std;

 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int writeIdx=1;
        
        //check empty array
        if(size==0)
            return 0;
        
        for(int readIdx=1;readIdx<size;readIdx++){
            if(nums[readIdx]!=nums[readIdx-1]){
                nums[writeIdx]=nums[readIdx];
                writeIdx++;
            }
        }
        return writeIdx;
    }
};