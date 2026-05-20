class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left<=right){
            int mid = (right - left)/2 + left;
            if(nums[mid] == target) return mid;
            else if (nums[mid]< target) left = mid +1;
            else right = mid - 1;
        }
        return -1;
    }
};


// to avoid the mid giving values that may cause time exceed in the mid = (right - left)/2 we use +left in the formation above