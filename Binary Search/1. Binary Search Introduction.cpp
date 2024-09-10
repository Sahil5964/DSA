#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& arr, int target)
{
    int start = 0, end = arr.size() - 1;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }

    return -1;
}

// int main()
// {
//     vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
//     int target = 15;

//     int result = binary_search(arr, target);
//     if (result == -1)
//         cout << "Element not found in the array." << endl;
//     else
//         cout << "Element found at index " << result << "." << endl;

//     return 0;
// }