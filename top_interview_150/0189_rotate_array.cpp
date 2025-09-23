/*
 * LeetCode 189. Rotate Array 
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Approach:
 *   Juggling / cycle decomposition:
 *   Rotating by k partitions the indices into gcd(n, k) cycles. For each cycle,
 *   carry the value along the cycle by step = k % n, placing each element into
 *   its rotated position in-place.
 */

#include <vector>
#include <numeric>    
#include <algorithm>  
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) return;

        int step = k % size;
        if (step == 0) return;

        int cycles = gcd(size, step);
        for (int start = 0; start < cycles; ++start) {
            int current = start;
            int prevVal = nums[current];

            while (true) {
                int nextIdx = (current + step) % size;
                swap(nums[nextIdx], prevVal); 
                current = nextIdx;
                if (current == start) break;
            }
        }
    }
};
