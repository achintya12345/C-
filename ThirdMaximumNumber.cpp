/*
Given an integer array nums, return the third distinct maximum number in this array. If 
the third maximum does not exist, return the maximum number.

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.

*/

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>

using namespace std;

int thirdMax(vector<int>& nums) {
    unordered_set<int> distinct_nums;
    
    // Add all distinct elements from the array into the set
    for (int num : nums) {
        distinct_nums.insert(num);
    }
    
    // If there are less than 3 distinct elements, return the maximum
    if (distinct_nums.size() < 3) {
        return *max_element(nums.begin(), nums.end()); // Return the maximum number in the array
    }
    
    // Convert the set to a vector and sort in descending order
    vector<int> sorted_nums(distinct_nums.begin(), distinct_nums.end());
    sort(sorted_nums.begin(), sorted_nums.end(), greater<int>());
    
    // Return the third distinct element
    return sorted_nums[2];
}

int main(){

    int n;
    cin>>n;

    vector<int> arr;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int result = thirdMax(arr);

    cout<<"FinalResult: "<<result;

    return 0;
}