class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i])
                    st.insert(arr[j]);
            }
            ans[i] = st.size() + 1;
        }

        return ans;
    }
};