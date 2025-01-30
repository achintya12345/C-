/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays 
and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> countMap;
    vector<int> result;

    // Step 1: Count the frequency of each element in nums1
    for (int num : nums1) {
        countMap[num]++;
    }

    // Step 2: Iterate through nums2 and find common elements
    for (int num : nums2) {
        // If the element exists in countMap and its count is greater than 0
        if (countMap.find(num) != countMap.end() && countMap[num] > 0) {
            result.push_back(num);  // Add to the result
            countMap[num]--;  // Decrease the count of that element
        }
    }

    return result;
}

int main(){

    int n1;
    int n2;
    cin>>n1;
    cin>>n2;

    vector<int> arr1;
    vector<int> arr2;

    for(int i=0; i<n1; i++){
        int x;
        cin>>x;
        arr1.push_back(x);
    }

    for(int i=0; i<n2; i++){
        int x;
        cin>>x;
        arr2.push_back(x);
    }

    vector<int> finalResult = intersect(arr1, arr2);

    cout<<"FinalResult: "<<endl;

    for(int i=0; i<finalResult.size(); i++){
        cout<<finalResult[i]<<" ";
    }

    return 0;
}