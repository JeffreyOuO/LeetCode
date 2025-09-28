/*
 * LeetCode 274. H-Index
 * Language: C++
 * Time Complexity: O(n log n)
 * Space Complexity: O(log n) from std::sort recursion stack
 * 
 * Approach:
 *   Sort citations in descending order. The h-index is the largest h such that
 *   the h-th paper has at least h citations. Scan from the most cited paper
 *   until the condition breaks.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());

        int hIndex = 0;
        for (int i = 0; i < n; i++) {
            if (citations[i] >= i + 1) {
                hIndex++;
            } else {
                break;
            }
        }
        return hIndex;
    }
};

/*
 * LeetCode 274. H-Index
 * Language: C++
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Approach:
 *   Use counting (bucket sort idea). Since h-index is at most n, 
 *   we only need a bucket of size n+1. Any paper with citations >= n 
 *   goes into bucket[n]. Then accumulate from high to low until total >= i, 
 *   at which point i is the h-index.
 */

#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n + 1, 0);  
        // bucket[i] = number of papers with exactly i citations
        // bucket[n] = number of papers with citations >= n

        for (int c : citations) {
            if (c >= n) {
                bucket[n]++;
            } else {
                bucket[c]++;
            }
        }

        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += bucket[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};
