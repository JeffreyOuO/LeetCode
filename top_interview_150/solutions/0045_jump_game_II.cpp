/*
 * LeetCode 45. Jump Game II
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Approach:
 *   Greedy level expansion: maintain the current range [curStart, curEnd] reachable
 *   within the current number of jumps. As we scan this range, track the farthest
 *   index reachable in the next step. When finishing the current range, increment
 *   jumps and move to the next range. Continue until reaching the last index.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int jumps = 0;
        int curStart = 0, curEnd = 0;

        while (curEnd < size - 1) {
            int farthest = curEnd;
            for (int i = curStart; i <= curEnd; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            curStart = curEnd + 1;
            curEnd = farthest;
            jumps++;
        }
        return jumps;
    }
};
