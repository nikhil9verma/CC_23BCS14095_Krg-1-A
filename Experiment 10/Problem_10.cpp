#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        
        // Offset to handle negative numbers (-10000 to 10000 -> 1 to 20001)
        int offset = 10001;
        int maxVal = 20005; 
        vector<int> bit(maxVal, 0);

        auto update = [&](int idx, int val) {
            while (idx < maxVal) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        };

        auto query = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        };

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int shifted_val = nums[i] + offset;
            // Count elements strictly smaller than the current element
            counts[i] = query(shifted_val - 1);
            // Add the current element to the BIT
            update(shifted_val, 1);
        }

        return counts;
    }
};