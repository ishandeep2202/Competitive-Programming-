/*
https://leetcode.com/problems/nth-magical-number/
Nth Magical Number

Given 2 numbers we want to find nth number divisible by both a or b
For mid, find numbers <= mid satisfying these conditions and if count is less than n then search to the right - Binary Search
*/


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

using ll = long long;

class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    ll lcm(int a, int b) {
        return 1LL * a * b / gcd(a, b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        ll LCM = lcm(a, b);
        ll left = 1, right = 1LL * n * min(a, b);

        while (left < right) {
            ll mid = left + (right - left) / 2;
            ll count = mid / a + mid / b - mid / LCM;

            if (count < n)
                left = mid + 1;
            else
                right = mid;
        }

        return left % MOD;
    }
};
