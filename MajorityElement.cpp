/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the 
majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {

    unordered_map<int, int> hashMap;

    for(int num: nums){
        hashMap[num]++;
    }

    int max = -9999;
    int maximumElement = -9999;

    for(const auto&element : hashMap){
        if(element.second > max){
            max = element.second;
            maximumElement = element.first;
        }
    }

    return maximumElement;

}

int main(){

    int n;
    cin>>n;

    vector<int>arr;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int finalResult = majorityElement(arr);

    cout<<"Final Result: "<<finalResult;

    return 0;
}