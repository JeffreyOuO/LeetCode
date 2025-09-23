/*
 * LeetCode 169. Majority Element
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Approach:
 *   Boyer–Moore Voting:
 *   Maintain a candidate and a vote count. When the count drops to zero,
 *   reset the candidate to the current number. For each element, add a vote
 *   if it equals the candidate, otherwise subtract a vote. Since the majority
 *   element appears > n/2 times, it survives as the final candidate.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int voteCount = 0;

        for (int x : nums) {
            if (voteCount == 0) {
                candidate = x;
                voteCount = 1;
            } else {
                voteCount += (x == candidate) ? 1 : -1;
            }
        }
        return candidate; 
    }
};
