// true for only non negative elements in array

int maxSubarraySumOfSizeK(int n, vector<int>& a, int k) {
    int sum = 0, ans = 0;

    // merged both loops into one loop
    for (int i = 0; i < n; i++) {
        // add the new element to the window
        sum += a[i];

        // remove the first element from the window if i ≥ k
        if (i >= k) {
            sum -= a[i - k];
        }

        // update the answer if i ≥ k - 1
        if (i >= k - 1) {
            ans = max(ans, sum);
        }
    }

    return ans;
}
