#include "common_include.h"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 涉及到原地移除，使用双指针
        int i = 0 ;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;
        vector<int> ans(nums);
        while (i <= j) {
            if (nums[i]*nums[i] > nums[j]*nums[j]) {
               ans[k] = nums[i] * nums[i];
                i++;
                k--;
            } else {
                ans[k] = nums[j] * nums[j];
                j--;
                k--;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口
        int i, j = 0;
        int sum = 0;
        int length = -1;
        for (j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                if (length == -1 || length > j - i + 1) length = j - i + 1;
                sum -= nums[i];
                i++;
            }
        }
        return length == -1 ? 0 : length;
    }
};