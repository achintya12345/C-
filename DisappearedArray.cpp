/*Given an array nums of n integers where nums[i] is in the range [1, n], return an 
array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]*/

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    
    // Step 1: Mark the numbers as negative at the corresponding index
    for (int i = 0; i < nums.size(); i++) {
        int num = abs(nums[i]);
        if (nums[num - 1] > 0) {
            nums[num - 1] = -nums[num - 1];  // Mark as visited
        }
    }
    
    // Step 2: Find the indices that are still positive and add corresponding number to the result
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);  // The missing number is i+1
        }
    }
    
    return result;
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

    vector<int> finalResult = findDisappearedNumbers(arr);

    for(int i=0; i< finalResult.size(); i++){
        cout<<finalResult[i]<<" ";
    }

    return 0;
}