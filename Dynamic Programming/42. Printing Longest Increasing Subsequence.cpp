#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    vector<int> indexing(arr.size(), -1);
    vector<int> longest(arr.size(), 0);
    for (int i = 1; i < arr.size(); i++)
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && longest[i] < (longest[j] + 1)) {
                longest[i] = longest[j] + 1;
                indexing[i] = j;
            }
        }
    
    int maxValue = INT_MIN, maxIdx = -1;
    for (int i = 0; i < arr.size(); i++)
        if (maxValue < longest[i]) {
            maxValue = longest[i];
            maxIdx = i;
        }
    
    vector<int> ans;
    while (maxIdx != -1) {
        ans.push_back(arr[maxIdx]);
        maxIdx = indexing[maxIdx];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}