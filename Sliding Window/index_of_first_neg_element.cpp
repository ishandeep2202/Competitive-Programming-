vector <int> function(int n, vector<int>& a, int k) {
    deque<int> dq; // store indices of negative numbers
    vector<int> result;

    for (int i=0; i<n; i++) {
        // If current element is negative, add its index
        if (a[i] < 0)
            dq.push_back(i);

        // Remove elements out of current window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // If window has formed
        if (i >= k - 1) {
            if (!dq.empty())
                result.push_back(dq.front()+1); // first negative
            else
                result.push_back(-1); // no negative in window
        }
    }

    return result;
}
