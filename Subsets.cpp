class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        magic(v, temp, nums, 0);
        return v;
    }

    void magic(vector<vector<int>>&v, vector<int>&temp, vector<int>&nums, int index){
        v.push_back(temp);

        for(int i = index; i<nums.size(); i++){
            temp.push_back(nums[i]);
            magic(v, temp, nums, i+1);
            temp.pop_back();
        }
    }
};