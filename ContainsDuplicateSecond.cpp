/*Given an integer array nums and an integer k, return true if there are two distinct 
indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>

using namespace std;

// Optimised Code

//  unordered_map<int, int> indexMap;  // Map to store the index of each element
    
//     for (int i = 0; i < nums.size(); i++) {
//         // If element already exists in the map and the index difference is <= k
//         if (indexMap.find(nums[i]) != indexMap.end() && abs(i - indexMap[nums[i]]) <= k) {
//             return true;
//         }
//         // Update the map with the current index of the element
//         indexMap[nums[i]] = i;
//     }
    
//     return false;  // No valid pair found

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> hashMap;

        for(int i=0; i<nums.size(); i++){
            hashMap[nums[i]].push_back(i);
        }

        for(const auto&element: hashMap){
            if(element.second.size() > 1){
                for(int i=0; i<element.second.size()-1; i++){
                    if(abs(element.second[i] - element.second[i+1]) <= k){
                        return true;
                    }
                }
            }
        }

    return false;

}

int main(){
    
    int n;
    cin>>n;
    int target;
    cin>>target;

    vector<int> arr;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    bool finalResult = containsNearbyDuplicate(arr, target);

    cout<<"FinalResult: "<<finalResult;

    return 0;
}