/*
 * LeetCode 55. Jump Game 
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Approach:
 *   Greedy: iterate while maintaining the farthest index we can reach so far.
 *   If at any point the current index exceeds this maximum reach, we cannot proceed.
 *   Otherwise, keep updating maxReach. If we finish the loop, the last index is reachable.
 */

#include <vector>
#include <algorithm> // for max
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int maxReach = 0;

        for (int i = 0; i < size; i++) {
            if (i > maxReach) return false;   // cannot even reach this position
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
