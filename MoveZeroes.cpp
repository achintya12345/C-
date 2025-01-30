/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative 
order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> moveZeroes(vector<int>& nums) {
    int target = 0;
    int size = nums.size();

    auto iterator = remove(nums.begin(), nums.end(), target);

    nums.erase(iterator, nums.end());

    // Step 3: Add the zeros at the end
    int zeros_to_add = size - nums.size(); // How many zeros to add
    nums.resize(nums.size() + zeros_to_add, 0);

    return nums;    
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

    vector<int> finalResult = moveZeroes(arr);

    for(int i=0; i<finalResult.size(); i++){
        cout<<finalResult[i]<<" ";
    }

    return 0;
}