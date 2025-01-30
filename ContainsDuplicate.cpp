/*Given an integer array nums, return true if any value appears at least twice in the 
array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false*/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> hashMap;

    for(int element: nums){
        hashMap[element]++;
    }

    for(const auto&element: hashMap){
        if(element.second > 1){
            return true;
        }
    }

    return false;

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

    bool finalResult = containsDuplicate(arr);

    cout<<"Final Result: "<< finalResult;

    return 0;
}