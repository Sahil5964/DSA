#include <vector>
using namespace std;

int lower(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    int mid;
    
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    
    return end;
}

int upper(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    int mid;
    
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] <= target) start = mid + 1;
        else end = mid - 1;
    }

    return start;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) return { -1, -1 };
    int start = lower(nums, target);
    int end = upper(nums, target);
    if (start == nums.size() - 1) return { -1, -1 };

    return (nums[start + 1] != target) ? vector<int> { -1, -1 } : vector<int> {start + 1, end - 1};
}