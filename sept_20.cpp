
// You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int total=0;
        int maxSum=arr[0],curMax=0;
        int minSum=arr[0],curMin=0;
        for(int x: arr){
            curMax=max(x,curMax+x);
            maxSum=max(maxSum,curMax);
            curMin=min(x,curMin+x);
            minSum=min(minSum,curMin);
        total+=x;

        }
        if(maxSum<0)
        return maxSum;
        return max(maxSum,total-minSum);

        
        
    }
};