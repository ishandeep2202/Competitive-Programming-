int function(const vector<int>& arr, int k) {
    int maxDistinct = 0;

    for (int i = 0; i <= arr.size() - k; ++i) {
        set<int> s;
        for (int j = i; j < i + k; ++j) {
            s.insert(arr[j]);
        }
        maxDistinct = max(maxDistinct, (int)s.size());
    }

    return maxDistinct;
}
