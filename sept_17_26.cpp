// Given an array arr[] consisting of n integers, find all the array elements which occurs more than floor(n/3) times. Return the resulting array in strictly increasing order. If no such elements exist, return an empty array
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        vector<int> ans;

        // Count frequency
        for (int x : arr) {
            mp[x]++;
        }

        // Check frequency
        for (auto it : mp) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};