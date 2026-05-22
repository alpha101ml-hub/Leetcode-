class Solution {
public:
    int search(vector<int>& A, int tar) {
        int n = A.size();
        int low = 0, high = n-1;

        while(low<=high){
            int mid = (low + high)/2;
            if(A[mid] == tar){
                return mid;
            }

            if(A[low] <= A[mid]){ // left sorted
                if(A[low] <= tar && tar <= A[mid]){
                    high = mid -1;
                }else{
                    low = mid +1;
                }
            }else{ //right sorted
                if(A[mid] <= tar && tar <= A[high]){
                        low = mid + 1;
                } else {
                        high = mid - 1;
                }
            }
        }
        return -1;
    }
};