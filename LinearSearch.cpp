#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int target){
    for(int i=0; i<size;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int nums[5]={2,4,6,8,10};
    int index = linearSearch(nums, 5, 6);
    cout<<index; // print 2
    return 0;
}