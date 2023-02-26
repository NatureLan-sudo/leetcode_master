#include "common_include.h"
// 有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        int ans[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            ans[s[i] - 'a']++;
        }
        for (int j = 0; j < t.length(); j++) {
            ans[t[j] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (ans[i] != 0) return false;
        }
        return true;
    } 
};
// 两个数组的交集,实际上就是返回两个数组中都存在的数值
// 要保证输出的结果唯一，注意利用set中元素都不能重复，能够去重的特性
// set 和 vector之间的相互初始化
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> key(nums1.begin(),nums1.end());
        unordered_set<int> ans;
        for (int j = 0; j < nums2.size(); j++) {
            if (key.find(nums2[j]) != key.end()) ans.insert(nums2[j]);
        }
        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};

// happy number
class Solution {
public:
    int getsum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10)*(n % 10);
            n = n / 10;
        }
        return sum;
    } //利用unorderset不重复的特点，判断是否出现了循环
    bool isHappy(int n) {
        unordered_set<int> key;
        while (1) {
            int sum = getsum(n);
            if (sum == 1) return true;
            if (key.find(sum) != key.end()) return false;
            key.insert(sum);
            n = sum;
        }
        return false;
    }
};


// sum of two number return ans index
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (ans.find(target - nums[i]) == ans.end()) {
                ans.insert(make_pair(nums[i], i));
            } else {
                return {i, ans[target - nums[i]]};
            }
        }
        return {0};
    }
};

// sum of four number, same length, return num
// O(N^2)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int, int> key; // (sum, count)
        // sum of 1 and 2
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                if (key.find(sum) != key.end()) {
                    key[sum]++;
                } else {
                    key.insert(make_pair(sum, 1));
                }
            }
        }
        // sum of 3 and 4
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                int sum = nums3[i] + nums4[j];
                if (key.find(-sum) != key.end()) {
                    ans += key[-sum];
                }
            }
        }
        return ans;
    }
};

//shujinxin  diyige nengbuneng you diergezucheng bukechongfushiyong
// O(n)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> key;
        for (auto i : magazine) {
            if (key.find(i) != key.end( )) {
                key[i]++;
            } else {
                key.insert(make_pair(i, 1));
            }
        }
        for (auto i : ransomNote) {
            if (key.find(i) != key.end()) {
                key[i]--;
                if (key[i] < 0) return false;
            } else return false;
        }
        return true;
    }
};

string str1= "hello world";
char ch1 = str1[1];
char ch2[] = "asdasd";
char sd = 'a';

// the sum of tree number bukeyichongfu
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};