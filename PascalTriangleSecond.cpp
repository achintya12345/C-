/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> getRow(int rowIndex) {

    vector<vector<int>>pascalTriangle; // Creating the pascal triangle

    for(int i=0; i<=rowIndex; i++){ // iterating over each row to be created for pascal triangle
        vector<int>innerTriangle(i+1, 1); // creating each row array

        for(int j=1; j<i; j++){ // for inner element (if any) that is from 3 element onwards
            innerTriangle[j] = pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j]; // creating inner element
        }

        pascalTriangle.push_back(innerTriangle); // adding that row to the finalRows
    }

    return pascalTriangle[rowIndex];        
    
}


int main()
{

    int n;
    cin >> n;

    vector<int>finalResult = getRow(n);

    for(int i=0; i<finalResult.size(); i++){
        cout<<finalResult[i]<< " ";
    }

    return 0;
}