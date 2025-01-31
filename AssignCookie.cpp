/*
Assume you are an awesome parent and want to give your children some cookies. 
But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the 
child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can 
assign the cookie j to the child i, and the child i will be content. Your goal is to 
maximize the number of your content children and output the maximum number.

 

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child 
whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {

    // Sort both greed factors and cookie sizes in ascending order
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int childIndex = 0;  // Pointer to the current child
    int cookieIndex = 0; // Pointer to the current cookie
    int satisfiedChildren = 0;

    // While there are still children and cookies left
    while (childIndex < g.size() && cookieIndex < s.size()) {
        if (s[cookieIndex] >= g[childIndex]) {
            // If the current cookie can satisfy the child
            satisfiedChildren++;
            childIndex++;  // Move to the next child
        }
        cookieIndex++;  // Move to the next cookie, either way
    }

    return satisfiedChildren;
}

int main(){

    int n1, n2;
    cin>>n1;
    cin>>n2;

    vector<int> g;
    vector<int> s;

    for(int i=0; i<n1; i++){
        int x;
        cin>>x;
        g.push_back(x);
    }

    for(int i=0; i<n2; i++){
        int x;
        cin>>x;
        s.push_back(x);
    }

    int finalResult = findContentChildren(g, s);

    cout<<"FinalResult: "<<finalResult;

    return 0;
}