#include "common_include.h"
void fanzhuan (vector<int>& ans) {
    int i = 0;
    int j = ans.size() - 1;
    while (i <= j) {
        swap(ans[i],ans[j]);
        i++;
        j--;
    }
}
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
int main () {

}