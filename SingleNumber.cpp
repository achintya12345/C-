/*Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <unordered_map>
using namespace std;

    // BEST APPROACH
    
    //optimal---XOR approach--O(n)
    // int ans=0;
    // for(int i=0; i<nums.size(); i++)
    // {
    //     ans=ans^nums[i];
    // }
    // return ans;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> countMap;

    for(int num : nums){
        countMap[num]++;
    }

    for(const auto&element : countMap){
        if(element.second == 1){
            return element.first;
        }
    }

    return 0;
    
}

int main(){

    int n;
    cin>>n;

    vector<int>arr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int finalResult = singleNumber(arr);

    cout<<"Result: "<< finalResult;

    return 0;
}