/*
https://leetcode.com/problems/find-the-duplicate-number/
Find the Duplicate Number

For array of n integers [1, n], it contains 1 duplicate number, find that without sorting the array
1. Store the count of numbers and then take prefix sum of that array - It stores the number of elements <= i.
2. Now apply binary search.
*/



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size() - 1;
        
        vector <int> freq(n+1, 0);
        
        for (int i=0; i<=n; i++) 
            freq[nums[i]]++;
        
        vector <int> cnt(n+1, 0);
        for (int i=1; i<=n; i++) 
            cnt[i] = cnt[i-1] + freq[i];
        
        int left = 1, right = n, ans = 0;
        while (left <= right) {
        
            int mid = (left + right) / 2;
        
            if (cnt[mid] > mid) {
                ans = mid;
                right = mid - 1;
            }
        
            else left = mid + 1;
        }
        
        return ans;
    }
};
