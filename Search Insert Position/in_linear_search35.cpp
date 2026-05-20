class Solution{
    int searchInsert(vector<int>& nums, int target){
        int n = nums.size();
        int left = 0, right = n-1; 
        int idx = n;
        for(int i = 0; i<n; i++){
            if (nums[i] >= target){
                idx = i;
                break;
            }
        }
        return idx;
    }
};

// this is for linear search for search insert position