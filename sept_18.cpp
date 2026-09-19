// You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int total = 0;
        int maxSum = arr[0];
        int minSum = arr[0];

        int currentMax = 0;
        int currentMin = 0;

        for (int x : arr) {
            currentMax = max(x, currentMax + x);
            maxSum = max(maxSum, currentMax);

            currentMin = min(x, currentMin + x);
            minSum = min(minSum, currentMin);

            total += x;
        }

        // If all elements are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};