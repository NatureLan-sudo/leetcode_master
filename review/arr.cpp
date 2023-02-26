#include "common_include.h"
//704. 二分查找, 升序数组查找目标值，二分法的时间复杂度是O(logn)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else return mid;
        }
        return -1;
    }
};
// 35. 搜索插入位置 
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 请必须使用时间复杂度为 O(log n) 的算法。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else return mid;
        } // 如果不存在，跳出循环的时候一定是left+1
        return left;
    }
};
//34. 在排序数组中查找元素的第一个和最后一个位置

//27、移除元素
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
// 改变元素顺序的方法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {  // 这地方需要注意 要一直到等于，因为我们的right 其实是一直没被判断的
            if (nums[left] == val) {
                swap(nums[left], nums[right]);
                right --;
            }else {
                left++;
            }
        }
        return left;
    }
};
// 不改变元素顺序的方法，递推
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int left = 0;
      int right = 0;
      // 相当于用left和right之间包围了不满足要求的数量
      while (right < nums.size()) {
        if (nums[right] == val) {
            right++;
        }else {
            nums[left] = nums[right];
            left ++;
            right ++;
        }
      }
        return left;  // 最后输出的是0到left-1
    }
};
// 有序数组的平方
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    // 非递减数列，原地依然输出非递减
     int left = 0;
     int right = nums.size() - 1;
     vector<int> res(nums.size(), 0); // 必须要对vec进行初始化
     int m = right;
     while (m > 0) {
        if (nums[left] * nums[left] > nums[right] * nums[right]) {
            res[m] = nums[left] * nums[left];
            m--;
            left ++;
        } else {
            res[m] = nums[right] * nums[right];
            m--;
            right--;
        }
     }
    return  res;
    }
};
// 209 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口
        int sum = 0;
        int mindex = -1;
        int dex = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
                sum+=nums[right];
                while (sum >= target) {
                    if (mindex == -1) mindex = right - left + 1;
                    else {
                        dex = right - left + 1;
                        if (dex < mindex) mindex = dex;
                    }
                    sum -= nums[left];
                    left ++;
                }
                right ++;
            }
        if (mindex == -1) return 0;
        return mindex;
    }
};
// 螺旋矩阵
