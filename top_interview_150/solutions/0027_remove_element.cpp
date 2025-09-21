/*
 * LeetCode 27. Remove Element
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Approach:
 *   Use a single write pointer. Iterate through nums, and whenever we see an
 *   element not equal to val, write it at the current write position and move
 *   the pointer forward. The final pointer index gives the new array length.


 * The judge will test your solution with the following code:
 *   int[] nums = [...]; // Input array
 *   int val = ...; // Value to remove
 *   int[] expectedNums = [...]; // The expected answer with correct length.
 *                             // It is sorted with no values equaling val.
 *   int k = removeElement(nums, val); // Calls your implementation
 *   assert k == expectedNums.length;
 *   sort(nums, 0, k); // Sort the first k elements of nums
 *   for (int i = 0; i < actualLength; i++) {
 *       assert nums[i] == expectedNums[i];
 *   }

 * If all assertions pass, then your solution will be accepted.
 */
#include<vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int writeIdx = 0;
        for (int readIdx = 0; readIdx < nums.size(); readIdx++) {
            if (nums[readIdx] != val) {
                nums[writeIdx] = nums[readIdx];
                writeIdx++;
            }
        }
        return writeIdx;
    }
};