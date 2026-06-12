class Solution {
public:
    set<vector<int>> s;
    
    void getAllCombinations(vector<int>& arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &combin){
        // FIX 1: Check target success first so you don't miss combinations at the array boundary
        if(tar == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin); // FIX 3: Removed extra wrapping braces
                s.insert(combin);
            }
            return;
        }

        // Now safe to exit if out of bounds or target goes negative
        if(idx == arr.size() || tar < 0){
            return;
        }

        // Branch 1: Single inclusion (Take it once, then force move to next index)
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combin);
        combin.pop_back(); // Clean up!

        // Branch 2: Multiple inclusion (Take it, and stay at the same index)
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx, tar - arr[idx], ans, combin);
        combin.pop_back(); // Clean up!

        // Branch 3: Exclusion (Don't take it at all, move to next index)
        getAllCombinations(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target){
        vector<vector<int>> ans;
        vector<int> combin;
        s.clear(); // Clear the set for fresh test cases

        // FIX 2: Fixed case-sensitivity typo (capital A)
        getAllCombinations(arr, 0, target, ans, combin);

        return ans;
    }
};