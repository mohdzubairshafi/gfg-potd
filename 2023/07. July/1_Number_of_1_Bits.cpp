/*

Author: Mohd Zubair
Date: 1 july 2023
Problem : Number of 1 Bits
Difficulty: Easy
GFG Problem Link: https://practice.geeksforgeeks.org/problems/set-bits0143/1

Problem Statement:
Given a positive integer N, print count of set bits in it.

Example 1:

Input:
N = 6
Output:
2
Explanation:
Binary representation is '110'
So the count of the set bit is 2.
Example 2:

Input:
8
Output:
1
Explanation:
Binary representation is '1000'
So the count of the set bit is 1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function setBits() which takes an Integer N and returns the count of number of set bits.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 109

*/

// Solution :

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int N)
    {
        // // method 1: check least significant bit if it 0 or 1 and right shift the number
        // int ans=0;
        // while(N>0){
        //     if(N&1){
        //         ans++;
        //     }
        //     N=N>>1;
        // }
        // return ans;
        //----------------------------
        // method 2: we have 32 bit int so run loop from 0 to 31 and use above logic
        //           here we dont modify the Real input number
        // int ans=0;
        // for(int i =0;i<32;i++){
        //     if((N>>i)&1){
        //         ans++;
        //     }
        // }
        // return ans;
        //--------------
        // method 3: in this we remove right most set bit from N and count it
        //           this will run the loop only for No of set bit time
        //       N = 1010 ,N-1=1001 ; N-> N&(N-1)=1000
        //       N = 1000 ,N-1=0111 ; N-> N&(N-1)=0000

        int ans = 0;
        while (N > 0)
        {
            ans++;
            N &= N - 1;
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
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends