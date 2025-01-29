/*Given an array of integers nums and an integer target, return indices of the two numbers such that 
they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element 
twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]*/

// Using HashMap

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int>twoSum(vector<int>&nums, int target){
    unordered_map<int, int> hashTable; 
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in the hashmap
        if (hashTable.find(complement) != hashTable.end()) {
            return {hashTable[complement], i}; // Return the indices of the two numbers
        }
        
        // Store the current number with its index in the hashmap
        hashTable[nums[i]] = i;
    }

    return {}; 
}

int main(){

    int numberOfElements;
    int target;

    cin>>numberOfElements;
    cin>>target;

    vector<int>vec;

    for(int i=0; i<numberOfElements; i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }

    vector<int>result = twoSum(vec, target);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }

    return 0;
}