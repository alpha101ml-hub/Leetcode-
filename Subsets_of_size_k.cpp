class Solution {
public:
    void getKSubsets(vector<int>& arr, int idx, int k, vector<vector<int>>& ans, vector<int>& combin) {
        // Base Case 1: If the subset reaches size k, we found a valid combination!
        if (combin.size() == k) {
            ans.push_back(combin);
            return; // Stop searching deeper down this path
        }

        // Base Case 2: Out of elements to pick from
        if (idx == arr.size()) {
            return;
        }

        // CHOICE 1: Include the current element
        combin.push_back(arr[idx]);
        getKSubsets(arr, idx + 1, k, ans, combin);
        combin.pop_back(); // Backtrack! Undo the choice

        // CHOICE 2: Exclude the current element
        getKSubsets(arr, idx + 1, k, ans, combin);
    }

    vector<vector<int>> combine(vector<int>& arr, int k) {
        vector<vector<int>> ans;
        vector<int> combin;
        
        getKSubsets(arr, 0, k, ans, combin);
        
        return ans;
    }
};