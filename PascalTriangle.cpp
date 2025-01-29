/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> triangle;  // To store the rows of the triangle
    
    // Loop to generate each row
    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1);  // Initialize each row with '1's
        
        // Fill the inner elements of the row (if any)
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];  // Sum of two elements from the previous row
        }
        
        triangle.push_back(row);  // Add the current row to the triangle
    }
    
    return triangle;
}

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> finalResult = generate(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << finalResult[i][j] << " ";
        }
        cout << " " << endl;
    }

    return 0;
}