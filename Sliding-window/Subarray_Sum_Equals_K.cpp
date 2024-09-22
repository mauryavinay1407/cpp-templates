// problem:  https://leetcode.com/problems/subarray-sum-equals-k/description/

/* 
Approach-1: Brute Force
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};



/* 
Approach-2: Optimal using prefix sum
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.count(sum-k))
             count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};
