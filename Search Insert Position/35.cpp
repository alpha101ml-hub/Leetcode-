class Solution{
    public:
    int search(vector<int>& nums, int target){
        int n = nums.size();
        int left = 0, right = n-1;
        while(left<=right){
            int mid = (right - left)/2 + left;
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
     return left; // it will cross right with l = + 1 and r = - 1 
    }             // and it return value of it the l
};



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l<=r){
            int mid = (r-l)/2 + l;
            if (nums[mid]==target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};