/*
For any element that comes, if it is smaller than previous elements upto k then pop all elements 
and add the current element

Otherwise only add the element. This results in deque always sorted
Time complexity: O(n)
*/

vector<int> function(int n, vector<int>& a, int k) {
    vector<int> ans;
    deque<int> deq;

    for (int i=0; i<n; i++) {
        while (!deq.empty() && a[deq.back()] >= a[i])
            deq.pop_back();
        deq.push_back(i);

        if (deq.front() == i - k)
            deq.pop_front();

        if (i >= k - 1)
            ans.push_back(a[deq.front()]);
    }

    return ans;
}
