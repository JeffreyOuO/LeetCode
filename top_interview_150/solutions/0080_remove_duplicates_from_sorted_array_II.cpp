/*
 * LeetCode 0080. Remove Duplicates from Sorted Array II
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Approach:
 *   Since the array is sorted, duplicates are adjacent. 
 *   Track the count of each element, and copy it to the array at most twice. 
 *   Use a write pointer to maintain the position of the next valid element.
 */

#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int writeIdx=0;
        int readIdx=0;

        while(readIdx<size){
            int duplicateCount=1;
            // Count duplicates for current number
            while(readIdx+1<size&&nums[readIdx+1]==nums[readIdx]){
                readIdx++;
                duplicateCount++;
            }
            // Copy at most 2 occurrences
            for(int i=0;i<min(2,duplicateCount);i++){
                nums[writeIdx]=nums[readIdx];
                writeIdx++;
            }
            readIdx++;

        }
        return writeIdx;

    }
};