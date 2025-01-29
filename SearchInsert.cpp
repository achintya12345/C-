/*Given a sorted array of distinct integers and a target value, return the index if the target is 
found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(target<nums[i]){
                nums.insert(nums.begin()+i, target);
                return i;
            }
        }

        return nums.size();
}

int main(){

    int n, target;
    cin>>n;
    cin>>target;

    vector<int> arr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int result = searchInsert(arr, target);

    cout<<result<<endl;

    return 0;   
}