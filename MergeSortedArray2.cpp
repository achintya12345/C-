/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two 
integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside 
the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements 
denote the elements that should be merged, and the last n elements are set to 0 and should be 
ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the 
merge result can fit in nums1.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    // optimised solution using 3 pointers
    // Pointers for the last elements of nums1, nums2, and the last position of nums1
    int i = m - 1; // Pointer to the last element in the valid portion of nums1
    int j = n - 1; // Pointer to the last element in nums2
    int k = m + n - 1; // Pointer to the last position in nums1

    // Merge the two arrays from the back
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If there are remaining elements in nums2, copy them over
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    // No need to handle nums1 since it is already in place

}

int main(){

    int m,n;
    cin>>m;
    cin>>n;

    vector<int>firstArray;
    vector<int>secondArray;

    for(int i=0; i<m+n; i++){
        int x;
        cin>>x;
        firstArray.push_back(x);
    }

    cout<<"Enter the second array"<<endl;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        secondArray.push_back(x);
    }

    merge(firstArray, m, secondArray, n);

    return 0;
}