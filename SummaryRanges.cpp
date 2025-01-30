/*

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, 
each element of nums is covered by exactly one of the ranges, and there is no integer x such that x 
is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    
    // Handle empty array case
    if (nums.empty()) {
        return result;
    }

    int start = nums[0];  // The start of the current range

    // Iterate through the array to find ranges
    for (int i = 1; i <= nums.size(); ++i) {
        // Check if we're at the end of the array or if the current number isn't consecutive
        if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
            // If the range has only one number
            if (start == nums[i - 1]) {
                result.push_back(to_string(start));
            }
            // If the range has more than one number
            else {
                result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
            }
            
            // Update the start for the next range
            if (i < nums.size()) {
                start = nums[i];
            }
        }
    }
    
    return result;
}


int main(){

    int n;
    cin>>n;

    vector<int> arr;

    for(int i =0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    vector<string> finalResult = summaryRanges(arr);

    for(int i=0; i<finalResult.size(); i++){
        cout<< finalResult[i]<< " ";
    }

    return 0;
}