class Solution {
public:
    int maxArea(vector<int>& height) { // O(n)
        int maxArea = 0; // ans
        int left = 0, right = height.size() - 1;
        while(left < right){
            int area = min(height[left], height[right]) * (right - left);

            maxArea = max(area, maxArea);

            if(height[left] < height[right])
                left++;
            else
                right--;

        } 
        return maxArea;
    }
};