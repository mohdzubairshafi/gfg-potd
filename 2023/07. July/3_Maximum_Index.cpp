/*
Author: Mohd Zubair
Date: 3 July 2023
Problem : Maximum Index
Difficulty : Medium

Problem Link:https://practice.geeksforgeeks.org/problems/maximum-index3307/1

Problem Statement:
Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].

Example 1:

Input:
n = 9
arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array arr[1] < arr[7]  satisfying
the required condition (arr[i] <= arr[j])  thus
giving the maximum difference of j - i which is
6(7-1).
Example 2:

Input:
N = 2
arr[] = {18, 17}
Output:
0
Explanation:
We can either take i and j as 0 and 0
or we can take 1 and 1 both give the same result 0.
Your Task:
Complete the function maxIndexDiff() which takes array arr and size n, as input parameters and returns an integer representing the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 106
0 ≤ Arr[i] ≤ 109



*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxIndexDiff(int arr[], int n)
    {

        // method 1: we will use trapping rain problem logic
        //           where we store min from left side and
        //           max element from right size till that index
        //           then we just apply condition to get our answer

        int left_min[n];
        int right_max[n];
        left_min[0] = arr[0];
        right_max[n - 1] = arr[n - 1];

        /* Construct LMin[] such that
            LMin[i] stores the minimum value
            from (arr[0], arr[1], ... arr[i]) */
        for (int i = 1; i < n; i++)
        {
            left_min[i] = min(arr[i], left_min[i - 1]);
        }

        /* Construct RMax[] such that
           RMax[j] stores the maximum value from
           (arr[j], arr[j+1], ..arr[n-1]) */
        for (int i = n - 2; i >= 0; i--)
        {
            right_max[i] = max(arr[i], right_max[i + 1]);
        }

        // Merging Two Loop in One
        // for (int i = 1; i < n; i++)
        // {
        //     left_min[i] = min(arr[i], left_min[i - 1]);                   // left_min will store the min till date
        //     right_max[n - 1 - i] = max(arr[n - 1 - i], right_max[n - i]); // right_max will store the maximum from end till date
        // }

        /* Traverse both arrays from left to right
            to find optimum j - i.*/
        int i(0), j(0);
        int ans = -1;
        while (i < n && j < n)
        {
            // check given condition
            if (left_min[i] <= right_max[j])
            {
                ans = max(ans, j - i);
                j++; // now check for next value of j in right_max
                // in search of possible best case and expanding the window in right
            }
            else
            {
                i++;
                // if left_min(i) is greater then check for next i value
                // in search of possible best case and contracting the window from left
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends