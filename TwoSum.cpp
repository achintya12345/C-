/*Given an array of integers nums and an integer target, return indices of the two numbers such that 
they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element 
twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]*/


#include<iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        int flag = 0, sum = 0, firstIndex, secondIndex;

        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                
                sum = nums[i] + nums[j];

                if(sum == target){
                    firstIndex = i;
                    secondIndex = j;
                    flag = 1;
                    break;
                }

            }

            if(flag == 1){
                break;
            }
        }

        vector<int> result;
        result.push_back(firstIndex);
        result.push_back(secondIndex);

        return result;
}

int main(){

    int n;
    int target;

    cin>>n;
    cin>>target;

    vector<int>vec;

    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }

    vector<int> result = twoSum(vec, target);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<< endl;
    }

    return 0;

}