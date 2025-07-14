int function(vector<int>& arr, int k) {
    int maxD = 0;
    for (int i=0; i<=arr.size()-k; i++) {
        set<int> s;
        for (int j=i; j<i+k; j++) {
            s.insert(arr[j]);
        maxD = max(maxD, s.size());
    }
    return maxD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i=0; i<n; i++) 
        cin >> a[i];
    map <int, int> mp;
    for (int i=0; i<k; i++) 
        mp[a[i]]++;
    int ans = mp.size();
    for (int i=k; i<n; i++) {
        mp[a[i]]++;
        mp[a[i-k]]--;
        if (mp[a[i-k]] == 0) 
            mp.erase(a[i-k]);
        ans = max(ans mp.size());
    }
    cout << ans << endl;
}
