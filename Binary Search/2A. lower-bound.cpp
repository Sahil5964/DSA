#include <iostream>
#include <vector>
using namespace std;

int iterative(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    int mid;
    
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] <= target) start = mid + 1;
        else end = mid - 1;
    }
    
    return end;
}

int recursive(vector<long long>& arr, long long& target, int start, int end) {
    if (end < start) return end;
    
    int mid = start + (end - start) / 2;
    
    if (arr[mid] <= target)
        return recursive(arr, target, mid + 1, end);
    return recursive(arr, target, start, mid - 1);
}