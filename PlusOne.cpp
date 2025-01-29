/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith 
digit of the integer. The digits are ordered from most significant to least significant in left-to-right 
order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    for(int i = n-1; i>=0; i--){
        if(digits[i] < 9){ // If digit is less than 9 then just increase the digit by 1 and return digit
            digits[i]++;
            return digits;
        }

        digits[i] = 0; // if digit was 9 then replace that by 0
    }

    digits.insert(digits.begin(),1); // this is the case when all digits are 9, eg: 999 hence we add 1 at start
    return digits;
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

    vector<int>result = plusOne(arr);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<< " ";
    }

    return 0;
}