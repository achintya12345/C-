/*
Given an array nums containing n distinct numbers in the range [0, n], return the only 
number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]

Output: 2
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<map>
using namespace std;

// sort(nums.begin(), nums.end());

//     for(int i=0; i<nums.size(); i++){
//         if(i != nums[i]){
//             return i;
//         }
//     }

//  return nums.size();

int missingNumber(vector<int>& nums) {
    
    map<int , int>hashMap;

    for(int num : nums){
        hashMap[num]++;
    }

    int index = 0;

    for(const auto&element : hashMap){
        if(index != element.first){
            return index;
        }
        index++;
    }

    return nums.size();
    
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

    int finalResult = missingNumber(arr);

    cout<<"FinalResult: "<<finalResult;

    return 0;
}