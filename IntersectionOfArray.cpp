/*
Given two integer arrays nums1 and nums2, return an array of their 
intersection
Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

*/

#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    auto iterator1 = unique(nums1.begin(), nums1.end());
    auto iterator2 = unique(nums2.begin(), nums2.end());

    nums1.erase(iterator1, nums1.end());
    nums2.erase(iterator2, nums2.end());

    int size1 = nums1.size();
    int size2 = nums2.size();

    nums1.resize(nums1.size()+size2, 0);

    for(int i=size1, j=0; i<nums1.size(); i++, j++){
        nums1[i] = nums2[j];
    }

    vector<int> finalResult;
    map<int, int> hashMap;

    for(int num: nums1){
        hashMap[num]++;
    }

    for(const auto& element : hashMap){
        if(element.second > 1){
            finalResult.push_back(element.first);
        }
    }

    return finalResult;
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

    vector<int> finalResult = intersection(arr1, arr2);

    cout<<"FinalResult"<<endl;

    for(int i=0; i<finalResult.size(); i++){
        cout<<finalResult[i]<<" ";
    }

    return 0;
}