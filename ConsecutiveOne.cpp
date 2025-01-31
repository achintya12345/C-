/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum 
number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int max = 0;
    int size = nums.size();

    for(int i=0; i<size-1; i++){
        if(nums[i] == 1 && nums[i+1] == 1){
            count++;
        } else {
            if(count > max){
                max = count;
            }
            count = 0;
        }
    }

    if(count > max){
        max = count;
    }

    if(max == 0 && find(nums.begin(), nums.end(), 1) == nums.end()){
        return 0;
    } else if(max == 0 && find(nums.begin(), nums.end(), 1) != nums.end()) {
        return 1;
    }

    return max + 1;
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

    int finalAnswer = findMaxConsecutiveOnes(arr);

    cout<<"Final Answer: "<<finalAnswer;

    return 0;
}